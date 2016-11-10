//
// Created by h37 on 11/3/16.
//

#ifndef SMSD_STRUCT_H
#define SMSD_STRUCT_H

#ifndef __cplusplus

typedef unsigned char bool;
#undef  false
#define false 	0
#undef  true
#define true	(!false)

#endif

typedef struct {
    bool have_power_en;
    bool have_power_pin;
    int power_en;
    int power_pin;
    char port[20];
} MODEM_CONF;

typedef enum  {
    SMSD_ERR_NONE = 0,
    SMSD_ERR_NOTWRIATE,
    SMSD_ERR_UNKNOWN
} SMSD_Error;

#endif //SMSD_STRUCT_H
