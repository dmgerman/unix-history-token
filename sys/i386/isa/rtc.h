begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)rtc.h	7.1 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_RTC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_RTC_H_
value|1
end_define

begin_comment
comment|/*  * MC146818 RTC Register locations  */
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
name|RTCSA_RESET
value|0x70
end_define

begin_comment
comment|/* reset divider */
end_comment

begin_define
define|#
directive|define
name|RTCSA_DIVIDER
value|0x20
end_define

begin_comment
comment|/* divider correct for 32768 Hz */
end_comment

begin_define
define|#
directive|define
name|RTCSA_8192
value|0x03
end_define

begin_comment
comment|/* 8192 Hz interrupt */
end_comment

begin_define
define|#
directive|define
name|RTCSA_4096
value|0x04
end_define

begin_define
define|#
directive|define
name|RTCSA_2048
value|0x05
end_define

begin_define
define|#
directive|define
name|RTCSA_1024
value|0x06
end_define

begin_comment
comment|/* default for profiling */
end_comment

begin_define
define|#
directive|define
name|RTCSA_PROF
value|RTCSA_1024
end_define

begin_define
define|#
directive|define
name|RTC_PROFRATE
value|1024
end_define

begin_define
define|#
directive|define
name|RTCSA_512
value|0x07
end_define

begin_define
define|#
directive|define
name|RTCSA_256
value|0x08
end_define

begin_define
define|#
directive|define
name|RTCSA_128
value|0x09
end_define

begin_define
define|#
directive|define
name|RTCSA_NOPROF
value|RTCSA_128
end_define

begin_define
define|#
directive|define
name|RTC_NOPROFRATE
value|128
end_define

begin_define
define|#
directive|define
name|RTCSA_64
value|0x0a
end_define

begin_define
define|#
directive|define
name|RTCSA_32
value|0x0b
end_define

begin_comment
comment|/* 32 Hz interrupt */
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
name|RTCSB_DST
value|0x01
end_define

begin_comment
comment|/* USA Daylight Savings Time enable */
end_comment

begin_define
define|#
directive|define
name|RTCSB_24HR
value|0x02
end_define

begin_comment
comment|/* 0 = 12 hours, 1 = 24	hours */
end_comment

begin_define
define|#
directive|define
name|RTCSB_BCD
value|0x04
end_define

begin_comment
comment|/* 0 = BCD, 1 =	Binary coded time */
end_comment

begin_define
define|#
directive|define
name|RTCSB_SQWE
value|0x08
end_define

begin_comment
comment|/* 1 = output sqare wave at SQW	pin */
end_comment

begin_define
define|#
directive|define
name|RTCSB_UINTR
value|0x10
end_define

begin_comment
comment|/* 1 = enable update-ended interrupt */
end_comment

begin_define
define|#
directive|define
name|RTCSB_AINTR
value|0x20
end_define

begin_comment
comment|/* 1 = enable alarm interrupt */
end_comment

begin_define
define|#
directive|define
name|RTCSB_PINTR
value|0x40
end_define

begin_comment
comment|/* 1 = enable periodic clock interrupt */
end_comment

begin_define
define|#
directive|define
name|RTCSB_HALT
value|0x80
end_define

begin_comment
comment|/* stop clock updates */
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
comment|/* clock power OK */
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
name|RTC_FDISKETTE
value|0x10
end_define

begin_comment
comment|/* diskette drive type in upper/lower nibble */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_NONE
value|0
end_define

begin_comment
comment|/* none present */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_360K
value|0x10
end_define

begin_comment
comment|/* 360K */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_12M
value|0x20
end_define

begin_comment
comment|/* 1.2M */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_720K
value|0x30
end_define

begin_comment
comment|/* 720K */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_144M
value|0x40
end_define

begin_comment
comment|/* 1.44M */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_288M_1
value|0x50
end_define

begin_comment
comment|/* 2.88M, some BIOSes */
end_comment

begin_define
define|#
directive|define
name|RTCFDT_288M
value|0x60
end_define

begin_comment
comment|/* 2.88M */
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
comment|/* current century */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_RTC_H_ */
end_comment

end_unit

