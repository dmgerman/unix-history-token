begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *                                                                            *  * Copyright (c) David L. Mills 1993                                          *  *                                                                            *  * Permission to use, copy, modify, and distribute this software and its      *  * documentation for any purpose and without fee is hereby granted, provided  *  * that the above copyright notice appears in all copies and that both the    *  * copyright notice and this permission notice appear in supporting           *  * documentation, and that the name University of Delaware not be used in     *  * advertising or publicity pertaining to distribution of the software        *  * without specific, written prior permission.  The University of Delaware    *  * makes no representations about the suitability this software for any       *  * purpose.  It is provided "as is" without express or implied warranty.      *  *                                                                            *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Modification history timex.h  *  * 28 Nov 93	David L. Mills  *	Adjusted parameters to improve stability and increase poll interval  *  * 10 Oct 93	Torsten Duwe  *	Changed to ntp_timex.h (#ifdef'd HAVE_SYS_TIMEX_H)  *   * 17 Sep 93    David L. Mills  *      Created file  */
end_comment

begin_comment
comment|/*  * This header file defines the Network Time Protocol (NTP) interfaces  * for user and daemon application programs. These are implemented using  * private syscalls and data structures and require specific kernel  * support.  *  * NAME  *	ntp_gettime - NTP user application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *  *	int syscall(SYS_ntp_gettime, tptr)  *  *	int SYS_ntp_gettime		defined in syscall.h header file  *	struct ntptimeval *tptr	pointer to ntptimeval structure  *  * NAME  *	ntp_adjtime - NTP daemon application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *  *	int syscall(SYS_ntp_adjtime, mode, tptr)  *  *	int SYS_ntp_adjtime		defined in syscall.h header file  *	struct timex *tptr		pointer to timex structure  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTP_TIMEX_H
end_ifndef

begin_define
define|#
directive|define
name|_NTP_TIMEX_H
end_define

begin_comment
comment|/*  * Include system timex.h (if appropriate)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMEX_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timex.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* provide definitions */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|syscall
name|P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ntp_gettime
parameter_list|(
name|t
parameter_list|)
value|syscall(SYS_ntp_gettime, (t))
end_define

begin_define
define|#
directive|define
name|ntp_adjtime
parameter_list|(
name|t
parameter_list|)
value|syscall(SYS_ntp_adjtime, (t))
end_define

begin_comment
comment|/*  * The following defines establish the engineering parameters of the PLL  * model. The HZ variable establishes the timer interrupt frequency, 100 Hz   * for the SunOS kernel, 256 Hz for the Ultrix kernel and 1024 Hz for the  * OSF/1 kernel. The SHIFT_HZ define expresses the same value as the  * nearest power of two in order to avoid hardware multiply operations.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_HZ
value|7
end_define

begin_comment
comment|/* log2(HZ) */
end_comment

begin_comment
comment|/*  * The SHIFT_KG and SHIFT_KF defines establish the damping of the PLL  * and are chosen by analysis for a slightly underdamped convergence  * characteristic. The MAXTC define establishes the maximum time constant  * of the PLL. With the parameters given and the default time constant of  * zero, the PLL will converge in about 15 minutes.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_KG
value|6
end_define

begin_comment
comment|/* shift for phase increment */
end_comment

begin_define
define|#
directive|define
name|SHIFT_KF
value|16
end_define

begin_comment
comment|/* shift for frequency increment */
end_comment

begin_define
define|#
directive|define
name|MAXTC
value|6
end_define

begin_comment
comment|/* maximum time constant (shift) */
end_comment

begin_comment
comment|/*  * The SHIFT_SCALE define establishes the decimal point of the time_phase  * variable which serves as a an extension to the low-order bits of the  * system clock variable. The SHIFT_UPDATE define establishes the decimal  * point of the time_offset variable which represents the current offset  * with respect to standard time. The SHIFT_USEC define represents 1 us in  * external units (shift), while the FINEUSEC define represents 1 us in  * internal units.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_SCALE
value|23
end_define

begin_comment
comment|/* shift for phase scale factor */
end_comment

begin_define
define|#
directive|define
name|SHIFT_UPDATE
value|(SHIFT_KG + MAXTC)
end_define

begin_comment
comment|/* shift for offset scale factor */
end_comment

begin_define
define|#
directive|define
name|SHIFT_USEC
value|16
end_define

begin_comment
comment|/* shift for 1 us in external units */
end_comment

begin_define
define|#
directive|define
name|FINEUSEC
value|(1<< SHIFT_SCALE)
end_define

begin_comment
comment|/* 1 us in internal units */
end_comment

begin_comment
comment|/*  * Mode codes (timex.mode)   */
end_comment

begin_define
define|#
directive|define
name|ADJ_OFFSET
value|0x0001
end_define

begin_comment
comment|/* time offset */
end_comment

begin_define
define|#
directive|define
name|ADJ_FREQUENCY
value|0x0002
end_define

begin_comment
comment|/* frequency offset */
end_comment

begin_define
define|#
directive|define
name|ADJ_MAXERROR
value|0x0004
end_define

begin_comment
comment|/* maximum time error */
end_comment

begin_define
define|#
directive|define
name|ADJ_ESTERROR
value|0x0008
end_define

begin_comment
comment|/* estimated time error */
end_comment

begin_define
define|#
directive|define
name|ADJ_STATUS
value|0x0010
end_define

begin_comment
comment|/* clock status */
end_comment

begin_define
define|#
directive|define
name|ADJ_TIMECONST
value|0x0020
end_define

begin_comment
comment|/* pll time constant */
end_comment

begin_comment
comment|/*  * Clock command/status codes (timex.status)  */
end_comment

begin_define
define|#
directive|define
name|TIME_OK
value|0
end_define

begin_comment
comment|/* clock synchronized */
end_comment

begin_define
define|#
directive|define
name|TIME_INS
value|1
end_define

begin_comment
comment|/* insert leap second */
end_comment

begin_define
define|#
directive|define
name|TIME_DEL
value|2
end_define

begin_comment
comment|/* delete leap second */
end_comment

begin_define
define|#
directive|define
name|TIME_OOP
value|3
end_define

begin_comment
comment|/* leap second in progress */
end_comment

begin_define
define|#
directive|define
name|TIME_BAD
value|4
end_define

begin_comment
comment|/* clock not synchronized */
end_comment

begin_comment
comment|/*  * NTP user interface - used to read kernel clock values  * Note: maximum error = NTP synch distance = dispersion + delay / 2;  * estimated error = NTP dispersion.  */
end_comment

begin_struct
struct|struct
name|ntptimeval
block|{
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* current time */
name|long
name|maxerror
decl_stmt|;
comment|/* maximum error (usec) */
name|long
name|esterror
decl_stmt|;
comment|/* estimated error (usec) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NTP daemon interface - used to discipline kernel clock oscillator  */
end_comment

begin_struct
struct|struct
name|timex
block|{
name|int
name|mode
decl_stmt|;
comment|/* mode selector */
name|long
name|offset
decl_stmt|;
comment|/* time offset (usec) */
name|long
name|frequency
decl_stmt|;
comment|/* frequency offset (scaled ppm) */
name|long
name|maxerror
decl_stmt|;
comment|/* maximum error (usec) */
name|long
name|esterror
decl_stmt|;
comment|/* estimated error (usec) */
name|int
name|status
decl_stmt|;
comment|/* clock command/status */
name|long
name|time_constant
decl_stmt|;
comment|/* pll time constant */
name|long
name|precision
decl_stmt|;
comment|/* clock precision (usec) (read only) */
name|long
name|tolerance
decl_stmt|;
comment|/* clock frequency tolerance (ppm) 				 * (read only) 				 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TIMEX_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTP_TIMEX_H */
end_comment

end_unit

