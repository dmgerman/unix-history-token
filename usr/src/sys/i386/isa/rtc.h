begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)rtc.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * RTC Register locations  */
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
name|RTCSA_TUP
value|0x80
end_define

begin_comment
comment|/* time update, don't look now */
end_comment

begin_define
define|#
directive|define
name|RTC_STATUSB
value|0x0b
end_define

begin_comment
comment|/* status register B */
end_comment

begin_define
define|#
directive|define
name|RTC_INTR
value|0x0c
end_define

begin_comment
comment|/* status register C (R) interrupt source */
end_comment

begin_define
define|#
directive|define
name|RTCIR_UPDATE
value|0x10
end_define

begin_comment
comment|/* update intr */
end_comment

begin_define
define|#
directive|define
name|RTCIR_ALARM
value|0x20
end_define

begin_comment
comment|/* alarm intr */
end_comment

begin_define
define|#
directive|define
name|RTCIR_PERIOD
value|0x40
end_define

begin_comment
comment|/* periodic intr */
end_comment

begin_define
define|#
directive|define
name|RTCIR_INT
value|0x80
end_define

begin_comment
comment|/* interrupt output signal */
end_comment

begin_define
define|#
directive|define
name|RTC_STATUSD
value|0x0d
end_define

begin_comment
comment|/* status register D (R) Lost Power */
end_comment

begin_define
define|#
directive|define
name|RTCSD_PWR
value|0x80
end_define

begin_comment
comment|/* clock lost power */
end_comment

begin_define
define|#
directive|define
name|RTC_DIAG
value|0x0e
end_define

begin_comment
comment|/* status register E - bios diagnostic */
end_comment

begin_define
define|#
directive|define
name|RTCDG_BITS
value|"\020\010clock_battery\007ROM_cksum\006config_unit\005memory_size\004fixed_disk\003invalid_time"
end_define

begin_define
define|#
directive|define
name|RTC_RESET
value|0x0f
end_define

begin_comment
comment|/* status register F - reset code byte */
end_comment

begin_define
define|#
directive|define
name|RTCRS_RST
value|0x00
end_define

begin_comment
comment|/* normal reset */
end_comment

begin_define
define|#
directive|define
name|RTCRS_LOAD
value|0x04
end_define

begin_comment
comment|/* load system */
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

begin_define
define|#
directive|define
name|RTC_CENTURY
value|0x32
end_define

begin_comment
comment|/* current century - please increment in Dec99*/
end_comment

end_unit

