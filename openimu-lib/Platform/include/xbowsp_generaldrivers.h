/** ***************************************************************************
 * @file   xbowsp_generaldrivers.h  Configuration and calibration data structure
 * @Author denglish
 * @date   February, 2011
 * @brief  Copyright (c) 2013, 2014 All Rights Reserved.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * per the latest design. Was drivers.h in 440 code
 ******************************************************************************/
#ifndef XBOWSP_DRIVERS_H
#define XBOWSP_DRIVERS_H

#include <stdint.h>
#include "xbowsp_version.h"

#define ACCEL_CAL_TABLE_OFFSET 0
#define ACCEL_CAL_TABLE_SIZE  54

#define RATE_CAL_TABLE_OFFSET (NUM_AXIS * ACCEL_CAL_TABLE_SIZE)
#define RATE_CAL_TABLE_SIZE   33

#define MAG_CAL_TABLE_OFFSET (RATE_CAL_TABLE_OFFSET + (NUM_AXIS * RATE_CAL_TABLE_SIZE))
#define MAG_CAL_TABLE_SIZE    33

#define TEMP_BIAS_OFFSET       0
#define TEMP_SCALE_OFFSET      6

#define TEMP_COUNT             0
#define BIAS_VALUE             1

#define SENSOR_COUNT           0
#define SCALE_VALUE            1

#include "xbow_configuration.h"


#define N_MISALIGN         18
#define N_RESERVED_CAL      6

#define N_TABLES_A    	   15   ///< 6 + 6 + 3
#define N_ROWS_TABLE_A    360 	///< 162 + 99 + 99
#define N_COLS_TABLE_A      2


struct productConfiguration_BITS  { /// bits   description
    uint16_t hasMags     :1;        /// 0 - lsb
    uint16_t hasGps      :1;        /// 1
    uint16_t rsvd1s      :1;        /// 1
    uint16_t algorithm   :1;        /// 2 - 380 only uses one algorithm
    uint16_t extAiding   :1;        /// 3
    uint16_t architecture:4;        /// 4-7 - 380 only has one architecture
    uint16_t rsvd        :7;        /// 8-14
    uint16_t isADAHRS    :1;        /// 15 - msb
};

union ProductConfiguration {
    uint16_t                         all;
    struct productConfiguration_BITS bit;
};


#pragma pack(1)
typedef struct {
    uint32_t serialNumber;
    char     versionString[N_VERSION_STR]; // [128]

    /// index of first element for each sensor (including 7th sensor)
    uint16_t calibrationTableIndexA[N_TABLES_A + 1]; // 15 + 1
    /// table order: (Temp Tables: xAccel, yAccel, zAccel, xRate, yRate, zRate),
    /// Inertial Tables: (same order), mag tables (x, y, z)
    uint32_t calibrationTablesA[N_ROWS_TABLE_A][N_COLS_TABLE_A]; // [360][2]
    int32_t  misalign[N_MISALIGN]; // [18]

    uint16_t calYear;           // YYYY calibration year    TBD
    uint16_t calMonth;          // MM   calibration month   TBD
    uint16_t calDay;            // DD   calibration day     TBD
    uint16_t calHour;           // HH   calibration hour    TBD
    uint16_t calMin;            // MM   calibration minute  TBD
    uint16_t calMinAndSec;      // SS   calibration second  TBD
    union    ProductConfiguration productConfiguration;

    /// added from the 440 - NAV-view may not program them
    float    AccelSensorRange;
    float    GyroSensorRange;
    float    MagSensorRange;

    uint16_t RollIncidenceLimit;
    uint16_t PitchIncidenceLimit;

    uint16_t HardIronLimit;
    uint16_t SoftIronLimit;
} CalibrationStruct;
#pragma pack()

extern CalibrationStruct gCalibration;

typedef struct {
    /// Input
    unsigned int  TableLength;	       ///< table size (starting with 0)
    uint8_t       firstColumnUnsigned; ///< TRUE: unsigned, FALSE, signed.
    unsigned int  bIndexLastSearch;    ///< index of the beginning row
                                       /// (where the last search ended)
    unsigned int  numberToBeSearched;  ///< search input--left column output
    unsigned int  bLeftValue;
    unsigned int  eLeftValue;  ///< search result: first row's columns(beginning and end)
    int           bRightValue;
    int           eRightValue; ///< search result:  second row's columns (beginning and end)
}LUTinOutStruct;


#endif

