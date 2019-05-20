/** ***************************************************************************
 * @file   xbowsp_configuration.h  Configuration and calibration data structure
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * per the latest design. Was drivers.h in 440 code
 ******************************************************************************/
/*******************************************************************************
Copyright 2018 ACEINNA, INC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#ifndef XBOWSP_CONFIGURATION_H
#define XBOWSP_CONFIGURATION_H

#include <stdint.h>
#include "GlobalConstants.h"

#define ROLL_INCIDENCE_LIMIT  0x1000
#define PITCH_INCIDENCE_LIMIT 0x1000
#define HARD_IRON_LIMIT       8192 // 0.25 G
#define SOFT_IRON_LIMIT       6554 // 20%
/// hard and soft iron resolution (2^16 / 2)
#define IRON_SCALE            32768





struct orientation_BITS  {      /// bits   description
    uint16_t forwardAxisSign:1; /// 0 is pos, 1 is neg
    uint16_t forwardAxis    :2; /// 0=X, 1=Y, 2=Z axes forward, 3=do not use
    uint16_t rightAxisSign  :1; /// 0 is pos, 1 is neg
    uint16_t rightAxis      :2; ///	0=Y, 1=Z, 2=X axes forward, 3=do not use
    uint16_t downAxisSign   :1; /// 0 is pos, 1 is neg
    uint16_t downAxis       :2; /// 0=Z, 1=X, 2=Y axes forward, 3=do not use
    uint16_t rsvd           :7; /// 9:15
};

union Orientation {
    uint16_t                all;
    struct orientation_BITS bit;
};

/// EEPROM Data Structure: configuration data (NOTE: Refer to the DMU Serial Interface
///                        spec before changing this structure).  All variables must
///                        fit in the space allocated.
#pragma pack(1)
typedef struct {
    uint16_t           calibrationCRC;    /// CRC on the calibration structure  0x0000
    uint16_t           packetRateDivider; /// continuous packet rate divider    0x0001
    uint16_t           baudRateUser;      /// user port                         0x0002
    uint16_t           packetCode;		  /// continuous packet code            0x0003

    uint16_t           analogFilterClocks[3];                               //  0x0004, 0x0005, 0x0006

    union Orientation  orientation; 	  /// user defined axis orientation     0x0007

    int16_t            hardIronBias[2];    ///< [-1,1) Gauss                    0x0009, 0x000a
    uint16_t           softIronScaleRatio; ///< [0,2), [0-200%)                 0x000b
    uint16_t           headingTrackOffset;                                  //  0x000c
    int16_t            softIronAngle;                                       //  0x000e
    uint16_t           rsvd;                                                //  0x000f

    uint16_t           hardwareStatusEnable;                                //  0x0010
    uint16_t           comStatusEnable;                                     //  0x0011
    uint16_t           softwareStatusEnable;                                //  0x0012
    uint16_t           sensorStatusEnable;                                  //  0x0013
    int16_t            baudRateGPS; // enum in driverGPS.h                      0x0014
    int16_t            protocolGPS; // enum enumGPSProtocol in driverGPS.h      0x0015
    int16_t            baroCorrection;                                      //  0x0016
    int16_t            OffsetAnglesExtMag[2];                               //  0x0017, 0x0018
    int16_t            OffsetAnglesAlign[3];                                //  0x0019, 0x001a, 0x001b
    int16_t            hardIronBiasExt[2];                                  //  0x001c, 0x001d
    uint16_t           softIronScaleRatioExt;                               //  0x001e
    int16_t            softIronAngleExt;                                    //  0x001f
    union Orientation  orientationExt; // uint16_t 32(128)?                     0x0020
    // 33 16-bit spaces used

    // The MTLT uses twelve 16-bit fields
    int16_t            portOneUsage;                                       // 0x0021
    int16_t            portTwoUsage;                                       // 0x0022
    int16_t            portThreeUsage;                                     // 0x0023
    int16_t            portFourUsage;                                      // 0x0024
    int16_t            portOneBaudRate;                                    // 0x0025
    int16_t            portTwoBaudRate;                                    // 0x0026
    int16_t            portThreeBaudRate;                                  // 0x0027
    int16_t            portFourBaudRate;                                   // 0x0028
    
    int16_t	           rollUpperAlarmLimit;                                // 0x0029
    int16_t	           rollLowerAlarmLimit;                                // 0x002a
    int16_t	           pitchUpperAlarmLimit;                               // 0x002b
    int16_t	           pitchLowerAlarmLimit;                               // 0x002c
    uint16_t 	       rollHysteresis; 		//Hysteresis for Roll alarm 0x002d
    uint16_t	       pitchHysteresis; 	//Hysteresis for Pitch alarm 0x002e    
    uint16_t	       alarmSelector;		//Cone/Independent axis alarm selector 0x002f
    uint16_t	       coneAngleLimit;		//angle = acos( cos( phi ) * cos( theta ) ) * 180/pi 0x0030
    uint16_t	       coneAngleHysteresis; //Hysteresis for cone angle alarm  0x0031
    
    uint16_t           ecuAddress;                                             // 0x0032
    uint16_t           ecuBaudRate;                                            // 0x0033
    uint16_t           algResetSaveCfgPs;                                       // 0x0034
    uint16_t           HardSoftBitPs;                                           // 0x0035
    uint16_t           statusPrPs;                                              // 0x0036
    uint16_t           PtDfPs;                                                  // 0x0037
    uint16_t           OrienUserBehvPs;                                         // 0x0038
    uint16_t           AngConeAlarmPs;                                          // 0x0039 
    int16_t            CanBaudRateDetectEnable;                                 // 0x003a
    int16_t            CanTermResistorEnable;                                   // 0x003b
    int16_t            CanOdr;                                                  // 0x003c
    uint16_t           canPacketType;                                           // 0x003d
//    uint16_t           AccelPs;                                                 // 0x003a


    uint16_t           userPacketFields[2][46]; // 2 * 47 = 94 <-- number of 16-bit slots used by this array 
    uint16_t           tmp0; // 2 * 47 = 94 <-- number of 16-bit slots used by this array 
    uint16_t           linAccelSwitchLimit; // 2 * 47 = 94 <-- number of 16-bit slots used by this array 
    uint16_t           tmp2;  // Previously unused 'filter' variable
} ConfigurationStruct;
#pragma pack()

extern ConfigurationStruct gConfiguration;

extern void  readUnitSerialNumber(uint32_t *serialNumber);
extern void  readProductConfigurationField(void *destination);
extern void  readUnitConfigurationField(uint16_t addr,  uint16_t num, void     *destination);
extern void  readUnitConfigurationMemory(uint16_t addr, uint16_t num, void     *destination);
extern BOOL  prepareToEnterBootloader(void);
extern BOOL  saveUnitConfigurationWords(uint16_t addr, uint16_t numWords, void  *source);
extern void  readUnitConfigurationStruct(void* destination);
extern BOOL  saveUnitConfigurationStruct(uint16_t *source);
extern BOOL  unitHasMag(void);
extern char *unitVersionString(void);
extern uint32_t unitSerialNumber(void);
extern float  unitGyroSensorRange(void);
extern uint16_t unitProductConfiguration(void);
extern uint16_t unitProductArchitecture(void);
extern uint8_t  getSensorRange();
extern uint8_t ReadUnitHwConfiguration( void );
extern BOOL ValidPortConfiguration (ConfigurationStruct *proposedConfiguration);
extern void magDetected(BOOL detected);

#endif

