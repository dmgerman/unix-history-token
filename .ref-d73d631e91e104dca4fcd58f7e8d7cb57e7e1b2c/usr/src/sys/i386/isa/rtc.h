begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)rtc.h	1.1 (Berkeley) %G%  * RTC Register locations  */
end_comment

begin_define
define|#
directive|define
name|RTC_SEC
value|0x00
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|RTC_SECALRM
value|0x01
end_define

begin_comment
comment|/* seconds alarm */
end_comment

begin_define
define|#
directive|define
name|RTC_MIN
value|0x02
end_define

begin_comment
comment|/* minutes */
end_comment

begin_define
define|#
directive|define
name|RTC_MINALRM
value|0x03
end_define

begin_comment
comment|/* minutes alarm */
end_comment

begin_define
define|#
directive|define
name|RTC_HRS
value|0x04
end_define

begin_comment
comment|/* hours */
end_comment

begin_define
define|#
directive|define
name|RTC_HRSALRM
value|0x05
end_define

begin_comment
comment|/* hours alarm */
end_comment

begin_define
define|#
directive|define
name|RTC_WDAY
value|0x06
end_define

begin_comment
comment|/* week day */
end_comment

begin_define
define|#
directive|define
name|RTC_DAY
value|0x07
end_define

begin_comment
comment|/* day of month */
end_comment

begin_define
define|#
directive|define
name|RTC_MONTH
value|0x08
end_define

begin_comment
comment|/* month of year */
end_comment

begin_define
define|#
directive|define
name|RTC_YEAR
value|0x09
end_define

begin_comment
comment|/* month of year */
end_comment

begin_define
define|#
directive|define
name|RTC_STATUSA
value|0x0a
end_define

begin_comment
comment|/* status register A */
end_comment

begin_define
define|#
directive|define
name|RTC_BASELO
value|0x15
end_define

begin_comment
comment|/* low byte of basemem size */
end_comment

begin_define
define|#
directive|define
name|RTC_BASEHI
value|0x16
end_define

begin_comment
comment|/* high byte of basemem size */
end_comment

begin_define
define|#
directive|define
name|RTC_EXTLO
value|0x17
end_define

begin_comment
comment|/* low byte of extended mem size */
end_comment

begin_define
define|#
directive|define
name|RTC_EXTHI
value|0x18
end_define

begin_comment
comment|/* low byte of extended mem size */
end_comment

end_unit

