#ifndef tAction_h
#define tAction_h

#define ACTION_NAME_LENGHT 128

//������������������������������������������������������������������������������   
//DATA
//������������������������������������������������������������������������������

typedef struct tAction {
    
    int             requestId;
    char*           cmds;
    char*           attrs;
    int				unLimitSize;
} tAction ;

typedef struct tCmdRes {
    
    char            *base       ;   //search base DN                
    char            *filter     ;   //search filter 

} tCmdRes ;

tCmdRes*    tAction_mallocCmdRes()                  ;
void        tAction_freeCmdRes( tCmdRes **cmd_res)   ;

//������������������������������������������������������������������������������
//INIT
//������������������������������������������������������������������������������
int         tActionInit ()                          ;

#endif
