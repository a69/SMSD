#include <gammu.h>
#include <hiredis/hiredis.h>
#include "monitor.h"
#include "receive.h"
#include "sms.h"

GSM_StateMachine *s;
INI_Section *cfg;
GSM_Error error;
char buffer[100];

/* Function to handle errors */
void error_handler(void)
{
    if (error != ERR_NONE) {
        printf("ERROR: %s\n", GSM_ErrorString(error));
        if (GSM_IsConnected(s))
            GSM_TerminateConnection(s);
        exit(error);
    }
}

int main(int argc UNUSED, char **argv UNUSED)
{
    GSM_Debug_Info *debug_info;

    /*
     * We don't need gettext, but need to set locales so that
     * charset conversion works.
     */
    GSM_InitLocales(NULL);

    /* Enable global debugging to stderr */
    debug_info = GSM_GetGlobalDebug();
    GSM_SetDebugFileDescriptor(stderr, FALSE, debug_info);
    GSM_SetDebugLevel("textall", debug_info);

    /* Allocates state machine */
    s = GSM_AllocStateMachine();
    if (s == NULL)
        return 3;

    /*
     * Enable state machine debugging to stderr
     * Same could be achieved by just using global debug config.
     */
    debug_info = GSM_GetDebug(s);
    GSM_SetDebugGlobal(FALSE, debug_info);
    GSM_SetDebugFileDescriptor(stderr, FALSE, debug_info);
    //GSM_SetDebugLevel("textall", debug_info);
    GSM_SetDebugLevel("none", debug_info);

    /*
     * Find configuration file (first command line parameter or
     * defaults)
     */
    error = GSM_FindGammuRC(&cfg, argc == 2 ? argv[1] : NULL);
    error_handler();

    /* Read it */
    error = GSM_ReadConfig(cfg, GSM_GetConfig(s, 0), 0);
    error_handler();

    /* Free config file structures */
    INI_Free(cfg);

    /* We have one valid configuration */
    GSM_SetConfigNum(s, 1);

    /* Connect to phone */
    /* 1 means number of replies you want to wait for */
    error = GSM_InitConnection(s, 1);
    error_handler();

    /* Here you can do some stuff with phone... */

    /* As an example we read some information about phone: */

    /* Manufacturer name */
    error = GSM_GetManufacturer(s, buffer);
    printf("Manufacturer  : %s\n", buffer);

    set_monitors(s,NULL);
    receive_sms(s,NULL);

    is_exist_folder(s,"");
    /* Terminate connection */
    error = GSM_TerminateConnection(s);
    error_handler();

    /* Free up used memory */
    GSM_FreeStateMachine(s);

    return 0;
}