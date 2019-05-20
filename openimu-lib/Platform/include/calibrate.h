/** ***************************************************************************
 * @file calibrate.h DMU380 sensor calibration algorithms.
 * @Author
 * @date   September, 2008
 * @brief  Copyright (c) 2013, 2014 All Rights Reserved.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 *****************************************************************************/
#include "algorithm.h"

void CalibrateInit(void);
void CalibrateFilter(void);
void CalibrateApply( void );

void orientSensors( double *scaledSensors );
void orientSensors_q27( int32_t *scaledSensors_q27 );
void LimitSensorValues( double *scaledSensors );
uint32_t GetPreFilter(uint32_t counts);

#define CONVERT_XBOW_TO_380(x) ( (int32_t)( (int32_t)( (x) >> 16 ) +  MININT16 ) ) ///< going to signed int 32
#define CONVERT_380_TO_XBOW(x) (( (uint32_t)( (x) - MININT16 ) ) << 16 ) ///< going to unsigned int 32
