begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	from: NetBSD: mc146818reg.h,v 1.5 2003/11/02 11:07:45 wiz Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the Motorola MC146818A Real Time Clock.  * They also apply for the (compatible) Dallas Semiconductor DS1287A RTC.  *  * Though there are undoubtedly other (better) sources, this material was  * culled from the DEC "KN121 System Module Programmer's Reference  * Information."  *  * The MC146818A has 16 registers.  The first 10 contain time-of-year  * and alarm data.  The rest contain various control and status bits.  *  * To read or write the registers, one writes the register number to  * the RTC's control port, then either reads from or writes the new  * data to the RTC's data port.  Since the locations of these ports  * and the method used to access them can be machine-dependent, the  * low-level details of reading and writing the RTC's registers are  * handled by machine-specific functions.  *  * The time-of-year and alarm data can be expressed in either binary  * or BCD, and they are selected by a bit in register B.  *  * The "hour" time-of-year and alarm fields can either be expressed in  * AM/PM format, or in 24-hour format.  If AM/PM format is chosen, the  * hour fields can have the values: 1-12 and 81-92 (the latter being  * PM).  If the 24-hour format is chosen, they can have the values  * 0-24.  The hour format is selectable by a bit in register B.  * (XXX IS AM/PM MODE DESCRIPTION CORRECT?)  *  * It is assumed the if systems are going to use BCD (rather than  * binary) mode, or AM/PM hour format, they'll do the appropriate  * conversions in machine-dependent code.  Also, if the clock is  * switched between BCD and binary mode, or between AM/PM mode and  * 24-hour mode, the time-of-day and alarm registers are NOT  * automatically reset; they must be reprogrammed with correct values.  */
end_comment

begin_comment
comment|/*  * The registers, and the bits within each register.  */
end_comment

begin_define
define|#
directive|define
name|MC_SEC
value|0x0
end_define

begin_comment
comment|/* Time of year: seconds (0-59) */
end_comment

begin_define
define|#
directive|define
name|MC_ASEC
value|0x1
end_define

begin_comment
comment|/* Alarm: seconds */
end_comment

begin_define
define|#
directive|define
name|MC_MIN
value|0x2
end_define

begin_comment
comment|/* Time of year: minutes (0-59) */
end_comment

begin_define
define|#
directive|define
name|MC_AMIN
value|0x3
end_define

begin_comment
comment|/* Alarm: minutes */
end_comment

begin_define
define|#
directive|define
name|MC_HOUR
value|0x4
end_define

begin_comment
comment|/* Time of year: hour (see above) */
end_comment

begin_define
define|#
directive|define
name|MC_AHOUR
value|0x5
end_define

begin_comment
comment|/* Alarm: hour */
end_comment

begin_define
define|#
directive|define
name|MC_DOW
value|0x6
end_define

begin_comment
comment|/* Time of year: day of week (1-7) */
end_comment

begin_define
define|#
directive|define
name|MC_DOM
value|0x7
end_define

begin_comment
comment|/* Time of year: day of month (1-31) */
end_comment

begin_define
define|#
directive|define
name|MC_MONTH
value|0x8
end_define

begin_comment
comment|/* Time of year: month (1-12) */
end_comment

begin_define
define|#
directive|define
name|MC_YEAR
value|0x9
end_define

begin_comment
comment|/* Time of year: year in century (0-99) */
end_comment

begin_define
define|#
directive|define
name|MC_REGA
value|0xa
end_define

begin_comment
comment|/* Control register A */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_RSMASK
value|0x0f
end_define

begin_comment
comment|/* Interrupt rate select mask (see below) */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_DVMASK
value|0x70
end_define

begin_comment
comment|/* Divisor select mask (see below) */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_DV0
value|0x10
end_define

begin_comment
comment|/* Divisor 0 */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_DV1
value|0x20
end_define

begin_comment
comment|/* Divisor 1 */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_DV2
value|0x40
end_define

begin_comment
comment|/* Divisor 2 */
end_comment

begin_define
define|#
directive|define
name|MC_REGA_UIP
value|0x80
end_define

begin_comment
comment|/* Update in progress; read only. */
end_comment

begin_define
define|#
directive|define
name|MC_REGB
value|0xb
end_define

begin_comment
comment|/* Control register B */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_DSE
value|0x01
end_define

begin_comment
comment|/* Daylight Savings Enable */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_24HR
value|0x02
end_define

begin_comment
comment|/* 24-hour mode (AM/PM mode when clear) */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_BINARY
value|0x04
end_define

begin_comment
comment|/* Binary mode (BCD mode when clear) */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_SQWE
value|0x08
end_define

begin_comment
comment|/* Square Wave Enable */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_UIE
value|0x10
end_define

begin_comment
comment|/* Update End interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_AIE
value|0x20
end_define

begin_comment
comment|/* Alarm interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_PIE
value|0x40
end_define

begin_comment
comment|/* Periodic interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MC_REGB_SET
value|0x80
end_define

begin_comment
comment|/* Allow time to be set; stops updates */
end_comment

begin_define
define|#
directive|define
name|MC_REGC
value|0xc
end_define

begin_comment
comment|/* Control register C */
end_comment

begin_comment
comment|/*	 MC_REGC_UNUSED	0x0f	UNUSED */
end_comment

begin_define
define|#
directive|define
name|MC_REGC_UF
value|0x10
end_define

begin_comment
comment|/* Update End interrupt flag */
end_comment

begin_define
define|#
directive|define
name|MC_REGC_AF
value|0x20
end_define

begin_comment
comment|/* Alarm interrupt flag */
end_comment

begin_define
define|#
directive|define
name|MC_REGC_PF
value|0x40
end_define

begin_comment
comment|/* Periodic interrupt flag */
end_comment

begin_define
define|#
directive|define
name|MC_REGC_IRQF
value|0x80
end_define

begin_comment
comment|/* Interrupt request pending flag */
end_comment

begin_define
define|#
directive|define
name|MC_REGD
value|0xd
end_define

begin_comment
comment|/* Control register D */
end_comment

begin_comment
comment|/*	 MC_REGD_UNUSED	0x7f	UNUSED */
end_comment

begin_define
define|#
directive|define
name|MC_REGD_VRT
value|0x80
end_define

begin_comment
comment|/* Valid RAM and Time bit */
end_comment

begin_define
define|#
directive|define
name|MC_NREGS
value|0xe
end_define

begin_comment
comment|/* 14 registers; CMOS follows */
end_comment

begin_define
define|#
directive|define
name|MC_NTODREGS
value|0xa
end_define

begin_comment
comment|/* 10 of those regs are for TOD and alarm */
end_comment

begin_define
define|#
directive|define
name|MC_NVRAM_START
value|0xe
end_define

begin_comment
comment|/* start of NVRAM: offset 14 */
end_comment

begin_define
define|#
directive|define
name|MC_NVRAM_SIZE
value|50
end_define

begin_comment
comment|/* 50 bytes of NVRAM */
end_comment

begin_comment
comment|/*  * Periodic Interrupt Rate Select constants (Control register A)  */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_NONE
value|0x0
end_define

begin_comment
comment|/* No periodic interrupt */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_1
value|0x1
end_define

begin_comment
comment|/* 256 Hz if MC_BASE_32_KHz, else 32768 Hz */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_2
value|0x2
end_define

begin_comment
comment|/* 128 Hz if MC_BASE_32_KHz, else 16384 Hz */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_8192_Hz
value|0x3
end_define

begin_comment
comment|/* 122.070 us period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_4096_Hz
value|0x4
end_define

begin_comment
comment|/* 244.141 us period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_2048_Hz
value|0x5
end_define

begin_comment
comment|/* 488.281 us period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_1024_Hz
value|0x6
end_define

begin_comment
comment|/* 976.562 us period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_512_Hz
value|0x7
end_define

begin_comment
comment|/* 1.953125 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_256_Hz
value|0x8
end_define

begin_comment
comment|/* 3.90625 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_128_Hz
value|0x9
end_define

begin_comment
comment|/* 7.8125 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_64_Hz
value|0xa
end_define

begin_comment
comment|/* 15.625 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_32_Hz
value|0xb
end_define

begin_comment
comment|/* 31.25 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_16_Hz
value|0xc
end_define

begin_comment
comment|/* 62.5 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_8_Hz
value|0xd
end_define

begin_comment
comment|/* 125 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_4_Hz
value|0xe
end_define

begin_comment
comment|/* 250 ms period */
end_comment

begin_define
define|#
directive|define
name|MC_RATE_2_Hz
value|0xf
end_define

begin_comment
comment|/* 500 ms period */
end_comment

begin_comment
comment|/*  * Time base (divisor select) constants (Control register A)  */
end_comment

begin_define
define|#
directive|define
name|MC_BASE_4_MHz
value|0x00
end_define

begin_comment
comment|/* 4MHz crystal */
end_comment

begin_define
define|#
directive|define
name|MC_BASE_1_MHz
value|MC_REGA_DV0
end_define

begin_comment
comment|/* 1MHz crystal */
end_comment

begin_define
define|#
directive|define
name|MC_BASE_32_KHz
value|MC_REGA_DV1
end_define

begin_comment
comment|/* 32KHz crystal */
end_comment

begin_define
define|#
directive|define
name|MC_BASE_NONE
value|(MC_REGA_DV2 | MC_REGA_DV1)
end_define

begin_comment
comment|/* actually also resets */
end_comment

begin_define
define|#
directive|define
name|MC_BASE_RESET
value|(MC_REGA_DV2 | MC_REGA_DV1 | MC_REGA_DV0)
end_define

end_unit

