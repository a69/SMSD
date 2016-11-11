//
// Created by h37 on 11/5/16.
//
#include <gammu.h>
#include "receive.h"
#include "error.h"

SMSD_Error receive_sms(GSM_StateMachine *stateMachine, redisContext *context) {
    GSM_Error gsm_error;
    gsm_error = ERR_NONE;
    gboolean start = true;
    GSM_MultiSMSMessage sms;
    int i;

    sms.Number = 0;
    sms.SMS[0].Location = 0;
    sms.SMS[0].Folder = 0;
    while (gsm_error == ERR_NONE) {
        gsm_error = GSM_GetNextSMS(stateMachine, &sms, start);
        if (gsm_error == ERR_EMPTY) break;
        gsm_error_handler(stateMachine, gsm_error, context);
        start = FALSE;

        /* Now we can do something with the message */
        for (i = 0; i < sms.Number; i++) {
            printf("Location: %d, Folder: %d\n", sms.SMS[i].Location, sms.SMS[i].Folder);
            printf("Number: \"%s\"\n", DecodeUnicodeConsole(sms.SMS[i].Number));
            /*
             * Decoding with GSM_DecodeMultiPartSMS is also an option here,
             * but for simplicity we use this approach which will handle only
             * text messages.
             */
            if (sms.SMS[i].Coding == SMS_Coding_8bit) {
                printf("8-bit message, can not display\n");
            } else {
                printf("Text: \"%s\"\n", DecodeUnicodeConsole(sms.SMS[i].Text));
            }
            printf("\n");
        }
    }
}
