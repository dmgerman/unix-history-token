begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  *   * (c)Copyright 1992 Hewlett-Packard Co.,  All Rights Reserved.  *   *                          RESTRICTED RIGHTS LEGEND  * Use, duplication, or disclosure by the U.S. Government is subject to  * restrictions as set forth in sub-paragraph (c)(1)(ii) of the Rights in  * Technical Data and Computer Software clause in DFARS 252.227-7013.  *   *                          Hewlett-Packard Company  *                          3000 Hanover Street  *                          Palo Alto, CA 94304 U.S.A.  *   * Rights for non-DOD U.S. Government Departments and Agencies are as set  * forth in FAR 52.227-19(c)(1,2).  *  *************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XHPPROTO_H
end_ifndef

begin_define
define|#
directive|define
name|XHPPROTO_H
end_define

begin_comment
comment|/* Definitions for HP extensions used by the server and C bindings*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMD_H
end_ifndef

begin_include
include|#
directive|include
file|"Xmd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* detailed device information */
end_comment

begin_define
define|#
directive|define
name|NO_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|HP_ITF_KBD
value|0x01
end_define

begin_define
define|#
directive|define
name|PC101_KBD
value|0x02
end_define

begin_define
define|#
directive|define
name|IBM3270_KBD
value|0x03
end_define

begin_define
define|#
directive|define
name|LK201_KBD
value|0x04
end_define

begin_define
define|#
directive|define
name|LK401_KBD
value|0x05
end_define

begin_define
define|#
directive|define
name|UNIX_KBD
value|0x06
end_define

begin_define
define|#
directive|define
name|SUN3_KBD
value|0x07
end_define

begin_define
define|#
directive|define
name|SUN4_KBD
value|0x08
end_define

begin_define
define|#
directive|define
name|HP_HIL
value|0x40
end_define

begin_define
define|#
directive|define
name|PS2
value|0x80
end_define

begin_define
define|#
directive|define
name|SERIAL
value|0xC0
end_define

begin_define
define|#
directive|define
name|ALLWINDOWS
value|-1
end_define

begin_define
define|#
directive|define
name|STDEVENTS
value|-1
end_define

begin_define
define|#
directive|define
name|EXTEVENTS
value|0
end_define

begin_define
define|#
directive|define
name|CORE_EVENTS
value|64
end_define

begin_define
define|#
directive|define
name|REPEAT_30
value|0
end_define

begin_define
define|#
directive|define
name|REPEAT_60
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|(0L<< 0)
end_define

begin_define
define|#
directive|define
name|ON
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|RELATIVE
value|(0L<< 1)
end_define

begin_define
define|#
directive|define
name|ABSOLUTE
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|SYSTEM_EVENTS
value|(0L<< 2)
end_define

begin_define
define|#
directive|define
name|DEVICE_EVENTS
value|(1L<< 2)
end_define

begin_comment
comment|/* HP devices */
end_comment

begin_define
define|#
directive|define
name|XPOINTER
value|0
end_define

begin_define
define|#
directive|define
name|XKEYBOARD
value|1
end_define

begin_define
define|#
directive|define
name|XOTHER
value|2
end_define

begin_define
define|#
directive|define
name|NUM_DEV_TYPES
value|19
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s300
argument_list|)
operator|||
name|defined
argument_list|(
name|__hp9000s700
argument_list|)
operator|||
name|defined
argument_list|(
name|hp300
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAX_POSITIONS
value|7
end_define

begin_define
define|#
directive|define
name|MAX_LOGICAL_DEVS
value|9
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_POSITIONS
value|28
end_define

begin_define
define|#
directive|define
name|MAX_LOGICAL_DEVS
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE
value|1
end_define

begin_define
define|#
directive|define
name|TABLET
value|2
end_define

begin_define
define|#
directive|define
name|KEYBOARD
value|3
end_define

begin_define
define|#
directive|define
name|QUADRATURE
value|4
end_define

begin_define
define|#
directive|define
name|TOUCHSCREEN
value|5
end_define

begin_define
define|#
directive|define
name|TOUCHPAD
value|6
end_define

begin_define
define|#
directive|define
name|BUTTONBOX
value|7
end_define

begin_define
define|#
directive|define
name|BARCODE
value|8
end_define

begin_define
define|#
directive|define
name|ONE_KNOB
value|9
end_define

begin_define
define|#
directive|define
name|TRACKBALL
value|10
end_define

begin_define
define|#
directive|define
name|KEYPAD
value|11
end_define

begin_define
define|#
directive|define
name|NINE_KNOB
value|12
end_define

begin_define
define|#
directive|define
name|ID_MODULE
value|13
end_define

begin_define
define|#
directive|define
name|VCD_8_DIALBOX
value|14
end_define

begin_define
define|#
directive|define
name|MMII_1812_TABLET
value|15
end_define

begin_define
define|#
directive|define
name|SS_SPACEBALL
value|16
end_define

begin_define
define|#
directive|define
name|APOLLO_LPFK
value|17
end_define

begin_define
define|#
directive|define
name|MMII_1201_TABLET
value|18
end_define

begin_define
define|#
directive|define
name|DVKeyClickPercent
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|DVBellPercent
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|DVBellPitch
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|DVBellDuration
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|DVLed
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|DVLedMode
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|DVKey
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|DVAutoRepeatMode
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|DVAccelNum
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|DVAccelDenom
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|DVThreshold
value|(1L<<10)
end_define

begin_comment
comment|/*  * Display modes, needed by both server and clients.  *   *   */
end_comment

begin_define
define|#
directive|define
name|OVERLAY_MODE
value|0x1
end_define

begin_define
define|#
directive|define
name|IMAGE_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|STACKED_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|STACKED_MODE_FIRST_SCREEN
value|0x3
end_define

begin_define
define|#
directive|define
name|STACKED_MODE_SECOND_SCREEN
value|0x33
end_define

begin_define
define|#
directive|define
name|COMBINED_MODE
value|0x4
end_define

begin_define
define|#
directive|define
name|XHPOVERLAY_MODE
value|OVERLAY_MODE
end_define

begin_define
define|#
directive|define
name|XHPIMAGE_MODE
value|IMAGE_MODE
end_define

begin_define
define|#
directive|define
name|XHPSTACKED_SCREENS_MODE
value|STACKED_MODE
end_define

begin_define
define|#
directive|define
name|XHPCOMBINED_MODE
value|COMBINED_MODE
end_define

begin_comment
comment|/*  * Server exit error codes  *  */
end_comment

begin_define
define|#
directive|define
name|NORMAL_TERMINATION
value|0
end_define

begin_define
define|#
directive|define
name|UNABLE_TO_INITIALIZE_THE_DISPLAY
value|1
end_define

begin_define
define|#
directive|define
name|INCORRECT_SB_DISPLAY_ADDR_ENVIRONMENT_VAR
value|2
end_define

begin_define
define|#
directive|define
name|INCORRECT_GRM_SIZE_ENVIRONMENT_VAR
value|3
end_define

begin_define
define|#
directive|define
name|UNABLE_TO_STARTUP_OR_CONNECT_TO_THE_GRM
value|4
end_define

begin_define
define|#
directive|define
name|DISPLAY_TYPE_UNKNOWN_TO_SERVER
value|5
end_define

begin_define
define|#
directive|define
name|DOUBLE_BUFFERING_NOT_SUPPORTED
value|6
end_define

begin_define
define|#
directive|define
name|DOUBLE_BUFFERING_HARDWARE_NOT_PRESENT
value|7
end_define

begin_define
define|#
directive|define
name|CANNOT_SUPPORT_DEPTHS_OPTION_ON_THIS_DISPLAY
value|8
end_define

begin_define
define|#
directive|define
name|UNSUPPORTED_DEPTH_SPECIFIED
value|9
end_define

begin_define
define|#
directive|define
name|HARDWARE_AT_THIS_DEPTH_NOT_PRESENT
value|10
end_define

begin_define
define|#
directive|define
name|DUPLICATE_DEVICE_ENTRY_IN_FILE
value|11
end_define

begin_define
define|#
directive|define
name|CANNOT_GET_DRIVER_INFO
value|12
end_define

begin_define
define|#
directive|define
name|COMBINED_MODE_NOT_STACKED_SCREENS_MODE
value|13
end_define

begin_define
define|#
directive|define
name|TWO_TIMES_COMBINED_MODE
value|14
end_define

begin_define
define|#
directive|define
name|SECONDARY_DIFFERENT_FROM_PRIMARY
value|15
end_define

begin_define
define|#
directive|define
name|NEXTTRACK_SERVER
value|0
end_define

begin_comment
comment|/* HP-UX 6.2 */
end_comment

begin_define
define|#
directive|define
name|MERGE_SERVER
value|1
end_define

begin_comment
comment|/* HP-UX 6.5 */
end_comment

begin_define
define|#
directive|define
name|REL_70_SERVER
value|2
end_define

begin_comment
comment|/* HP-UX 7.0 */
end_comment

begin_define
define|#
directive|define
name|REL_701_SERVER
value|3
end_define

begin_comment
comment|/* HP-UX 7.05 */
end_comment

begin_define
define|#
directive|define
name|REL_80_SERVER
value|4
end_define

begin_comment
comment|/* HP-UX 8.0 */
end_comment

begin_define
define|#
directive|define
name|REL_807_SERVER
value|5
end_define

begin_comment
comment|/* HP-UX 8.07 (IF2) */
end_comment

begin_define
define|#
directive|define
name|REL_90_SERVER
value|6
end_define

begin_comment
comment|/* HP-UX 9.0 R5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

