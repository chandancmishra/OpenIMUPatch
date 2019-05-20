/** ****************************************************************************
 * @file  xbowsp_init.h
 *
 * @brief  Copyright (c) 2013, 2014 All Rights Reserved.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * $Rev: 17479 $
 * @date: 2011-02-09 22:02:39 -0800 (Wed, 09 Feb 2011) $
 * @author: by-dan $
 * @brief -header file of xbowsp_init.c
 ******************************************************************************/
#ifndef XBOWSP_INIT_H
#define XBOWSP_INIT_H

#include "GlobalConstants.h"
#include "xbow_configuration.h"
#include "algorithm.h"
#include "xbowsp_version.h"
//#include "sae_j1939.h"

#define ROLL_INCIDENCE_LIMIT  0x1000
#define PITCH_INCIDENCE_LIMIT 0x1000
#define HARD_IRON_LIMIT       8192 // 0.25 G
#define SOFT_IRON_LIMIT       6554 // 20%
#define DEFAULT_IMU381_MODEL  "IMU381ZA-400\x0\x0"

//extern void xbowInitConfigureUnit(void);
//extern BOOL ValidPortConfiguration(ConfigurationStruct *proposedConfiguration);
extern void initAlgStruct(void);

extern AlgorithmStruct       gAlgorithm;
extern softwareVersionStruct bootFMversion;
extern ConfigurationStruct   gConfiguration;
extern softwareVersionStruct dupFMversion;
extern softwareVersionStruct ioupFMversion;
extern void    SetAlgorithmUseDgps(BOOL d);

uint8_t getSensorRange();
void    SetIntVectorOffset(uint32_t offset);

// here is definition for packet rate divider
// considering that data acquisition task runs at 200 Hz 
typedef enum {
    PACKET_RATE_DIV_INVALID = -1,
    PACKET_RATE_DIV_QUIET = 0,      // quiet mode
    PACKET_RATE_DIV_200HZ = 200,    // packet rate 200 Hz
    PACKET_RATE_DIV_100HZ = 1,      // packet rate 100 Hz
    PACKET_RATE_DIV_50HZ  = 2,      // packet rate 50 Hz
    PACKET_RATE_DIV_25HZ  = 4,      // packet rate 25 Hz
    PACKET_RATE_DIV_20HZ  = 5,     // packet rate 20 Hz
    PACKET_RATE_DIV_10HZ  = 10,     // packet rate 10 Hz
    PACKET_RATE_DIV_5HZ   = 20,     // packet rate 5  Hz
    PACKET_RATE_DIV_2HZ   = 50,    // packet rate 2  Hz
    PACKET_RATE_DIV_1HZ   = 100,    // packet rate 1  Hz
}packet_rate_div_t;

#define FORWARD   0
#define RIGHT     1
#define DOWN      2


#define PLUS_X    0x582B
#define PLUS_Y    0x592B
#define PLUS_Z    0x5A2B
#define MINUS_X   0x582D
#define MINUS_Y   0x592D
#define MINUS_Z   0x5A2D


#define FWD_X_PLUS_MASK	   0x00000000
#define FWD_X_MINUS_MASK   0x00000001
#define FWD_Y_PLUS_MASK	   0x00000002
#define FWD_Y_MINUS_MASK   0x00000003
#define FWD_Z_PLUS_MASK	   0x00000004
#define FWD_Z_MINUS_MASK   0x00000005

#define RIGHT_X_PLUS_MASK  0x00000020
#define RIGHT_X_MINUS_MASK 0x00000028
#define RIGHT_Y_PLUS_MASK  0x00000000
#define RIGHT_Y_MINUS_MASK 0x00000008
#define RIGHT_Z_PLUS_MASK  0x00000010
#define RIGHT_Z_MINUS_MASK 0x00000018

#define DOWN_X_PLUS_MASK   0x00000080
#define DOWN_X_MINUS_MASK  0x000000C0
#define DOWN_Y_PLUS_MASK   0x00000100
#define DOWN_Y_MINUS_MASK  0x00000140
#define DOWN_Z_PLUS_MASK   0x00000000
#define DOWN_Z_MINUS_MASK  0x00000040



#endif
