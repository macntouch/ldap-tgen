/*
 * other.c	
 *
 * Version:	$Id: other.c,v 1.2 2000/12/27 03:45:10 cmiller Exp $
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Copyright 2000  The FreeRADIUS server project
 * Copyright 2000  your name <your address>
 */

#include <stdio.h>

#include "other.h"

/*
 *  This is a sample C file which does nothing.
 *
 *  It's only purpose is to show how to set up the 'Makefile'
 *  for modules which have more than one C source file.
 */
void other_function(void)
{
  int i = 1;			/* do nothing */

  i++;
}
