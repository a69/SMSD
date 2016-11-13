//
// Created by h37 on 11/11/16.
//

#include <gammu.h>
#include "sms.h"
#include "error.h"

SMSD_Error is_exist_folder(GSM_StateMachine *stateMachine, unsigned char *name) {
    GSM_SMSFolders smsFolders;
    GSM_Error gsm_error;
    int i;

    gsm_error = GSM_GetSMSFolders(stateMachine,&smsFolders);
    gsm_error_handler(stateMachine,gsm_error,NULL);

    for(i=0;i<smsFolders.Number;i++){
        printf("####%d) %s %d %d  %d\n",i,smsFolders.Folder[i].Name,smsFolders.Folder[i].InboxFolder,smsFolders.Folder[i].OutboxFolder,smsFolders.Folder[i].Memory);
    }

    return SMSD_ERR_UNKNOWN;
}
