/*
 * WPA Supplicant / EAP-OTP (RFC 3748)
 * Copyright (c) 2004-2005, Jouni Malinen <jkmaline@cc.hut.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "eap_i.h"
#include "wpa_supplicant.h"
#include "config_ssid.h"


static void * eap_otp_init(struct eap_sm *sm)
{
	return (void *) 1;
}


static void eap_otp_deinit(struct eap_sm *sm, void *priv)
{
}


static u8 * eap_otp_process(struct eap_sm *sm, void *priv,
			    struct eap_method_ret *ret,
			    const u8 *reqData, size_t reqDataLen,
			    size_t *respDataLen)
{
	struct wpa_ssid *config = eap_get_config(sm);
	const struct eap_hdr *req;
	struct eap_hdr *resp;
	const u8 *pos, *password;
	u8 *rpos;
	size_t password_len, len;

	pos = eap_hdr_validate(EAP_TYPE_OTP, reqData, reqDataLen, &len);
	if (pos == NULL) {
		ret->ignore = TRUE;
		return NULL;
	}
	req = (const struct eap_hdr *) reqData;
	wpa_hexdump_ascii(MSG_MSGDUMP, "EAP-OTP: Request message",
			  pos, len);

	if (config == NULL ||
	    (config->password == NULL && config->otp == NULL)) {
		wpa_printf(MSG_INFO, "EAP-OTP: Password not configured");
		eap_sm_request_otp(sm, config, (const char *) pos, len);
		ret->ignore = TRUE;
		return NULL;
	}

	if (config->otp) {
		password = config->otp;
		password_len = config->otp_len;
	} else {
		password = config->password;
		password_len = config->password_len;
	}

	ret->ignore = FALSE;

	ret->methodState = METHOD_DONE;
	ret->decision = DECISION_COND_SUCC;
	ret->allowNotifications = FALSE;

	*respDataLen = sizeof(struct eap_hdr) + 1 + password_len;
	resp = malloc(*respDataLen);
	if (resp == NULL)
		return NULL;
	resp->code = EAP_CODE_RESPONSE;
	resp->identifier = req->identifier;
	resp->length = host_to_be16(*respDataLen);
	rpos = (u8 *) (resp + 1);
	*rpos++ = EAP_TYPE_OTP;
	memcpy(rpos, password, password_len);
	wpa_hexdump_ascii_key(MSG_MSGDUMP, "EAP-OTP: Response",
			      password, password_len);

	if (config->otp) {
		wpa_printf(MSG_DEBUG, "EAP-OTP: Forgetting used password");
		memset(config->otp, 0, config->otp_len);
		free(config->otp);
		config->otp = NULL;
		config->otp_len = 0;
	}

	return (u8 *) resp;
}


const struct eap_method eap_method_otp =
{
	.method = EAP_TYPE_OTP,
	.name = "OTP",
	.init = eap_otp_init,
	.deinit = eap_otp_deinit,
	.process = eap_otp_process,
};
