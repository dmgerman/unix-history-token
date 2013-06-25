begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Android driver interface  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_DRV_H
end_ifndef

begin_define
define|#
directive|define
name|ANDROID_DRV_H
end_define

begin_define
define|#
directive|define
name|WPA_EVENT_DRIVER_STATE
value|"CTRL-EVENT-DRIVER-STATE "
end_define

begin_define
define|#
directive|define
name|MAX_SSID_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MAX_DRV_CMD_SIZE
value|248
end_define

begin_define
define|#
directive|define
name|DRV_NUMBER_SEQUENTIAL_ERRORS
value|4
end_define

begin_define
define|#
directive|define
name|WEXT_PNOSETUP_HEADER
value|"PNOSETUP "
end_define

begin_define
define|#
directive|define
name|WEXT_PNOSETUP_HEADER_SIZE
value|9
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_TLV_PREFIX
value|'S'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_TLV_VERSION
value|'1'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_TLV_SUBVERSION
value|'2'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_TLV_RESERVED
value|'0'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_VERSION_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_AMOUNT
value|16
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_SSID_SECTION
value|'S'
end_define

begin_comment
comment|/* SSID header size is SSID section type above + SSID length */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_SSID_HEADER_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_SCAN_INTERVAL_SECTION
value|'T'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_SCAN_INTERVAL_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_SCAN_INTERVAL
value|30
end_define

begin_comment
comment|/* Scan interval size is scan interval section type + scan interval length  * above */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_SCAN_INTERVAL_SIZE
value|(1 + WEXT_PNO_SCAN_INTERVAL_LENGTH)
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_REPEAT_SECTION
value|'R'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_REPEAT_LENGTH
value|1
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_REPEAT
value|4
end_define

begin_comment
comment|/* Repeat section size is Repeat section type + Repeat value length above */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_REPEAT_SIZE
value|(1 + WEXT_PNO_REPEAT_LENGTH)
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_MAX_REPEAT_SECTION
value|'M'
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_MAX_REPEAT_LENGTH
value|1
end_define

begin_define
define|#
directive|define
name|WEXT_PNO_MAX_REPEAT
value|3
end_define

begin_comment
comment|/* Max Repeat section size is Max Repeat section type + Max Repeat value length  * above */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_MAX_REPEAT_SIZE
value|(1 + WEXT_PNO_MAX_REPEAT_LENGTH)
end_define

begin_comment
comment|/* This corresponds to the size of all sections expect SSIDs */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_NONSSID_SECTIONS_SIZE
define|\
value|(WEXT_PNO_SCAN_INTERVAL_SIZE + WEXT_PNO_REPEAT_SIZE + WEXT_PNO_MAX_REPEAT_SIZE)
end_define

begin_comment
comment|/* PNO Max command size is total of header, version, ssid and other sections +  * Null termination */
end_comment

begin_define
define|#
directive|define
name|WEXT_PNO_MAX_COMMAND_SIZE
define|\
value|(WEXT_PNOSETUP_HEADER_SIZE + WEXT_PNO_VERSION_SIZE \ 	 + WEXT_PNO_AMOUNT * (WEXT_PNO_SSID_HEADER_SIZE + MAX_SSID_LEN) \ 	 + WEXT_PNO_NONSSID_SECTIONS_SIZE + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANDROID_DRV_H */
end_comment

end_unit

