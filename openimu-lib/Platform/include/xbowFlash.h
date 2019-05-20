/** ***************************************************************************
 * @file xbowFlash.h definitions for flash partitions
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
#ifndef _XBOW_FLASH
#define _XBOW_FLASH

#define APP_UPDATE_FLAG_ADDR	    0x0801018C
#define APP_START_ADDR	            0x08010000
#define APP_XBOW_CONFIG_ADDR        0x08008000
#define APP_USER_CONFIG_ADDR        0x0800C000
#define APP_USER_CONFIG_SIZE        0x00004000
#define	ENTER_APP           	    0x55AA1234
#define	ENTER_BOOTLOADER_FLAG       0x50A01030
#define APP_START_SIGNATURE_ADDR	0x08010194

#endif