begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  *								       *  * Copyright (c) David L. Mills 1993-2001			       *  *								       *  * Permission to use, copy, modify, and distribute this software and   *  * its documentation for any purpose and without fee is hereby	       *  * granted, provided that the above copyright notice appears in all    *  * copies and that both the copyright notice and this permission       *  * notice appear in supporting documentation, and that the name        *  * University of Delaware not be used in advertising or publicity      *  * pertaining to distribution of the software without specific,	       *  * written prior permission. The University of Delaware makes no       *  * representations about the suitability this software for any	       *  * purpose. It is provided "as is" without express or implied	       *  * warranty.							       *  *								       *  **********************************************************************/
end_comment

begin_comment
comment|/*  * Modification history timex.h  *  * 16 Aug 00	David L. Mills  *	API Version 4. Added MOD_TAI and tai member of ntptimeval  *	structure.  *  * 17 Nov 98	David L. Mills  *	Revised for nanosecond kernel and user interface.  *  * 26 Sep 94	David L. Mills  *	Added defines for hybrid phase/frequency-lock loop.  *  * 19 Mar 94	David L. Mills  *	Moved defines from kernel routines to header file and added new  *	defines for PPS phase-lock loop.  *  * 20 Feb 94	David L. Mills  *	Revised status codes and structures for external clock and PPS  *	signal discipline.  *  * 28 Nov 93	David L. Mills  *	Adjusted parameters to improve stability and increase poll  *	interval.  *  * 17 Sep 93    David L. Mills  *      Created file  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header file defines the Network Time Protocol (NTP) interfaces  * for user and daemon application programs. These are implemented using  * defined syscalls and data structures and require specific kernel  * support.  *  * The original precision time kernels developed from 1993 have an  * ultimate resolution of one microsecond; however, the most recent  * kernels have an ultimate resolution of one nanosecond. In these  * kernels, a ntp_adjtime() syscalls can be used to determine which  * resolution is in use and to select either one at any time. The  * resolution selected affects the scaling of certain fields in the  * ntp_gettime() and ntp_adjtime() syscalls, as described below.  *  * NAME  *	ntp_gettime - NTP user application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *  *	int ntp_gettime(struct ntptimeval *ntv);  *  * DESCRIPTION  *	The time returned by ntp_gettime() is in a timespec structure,  *	but may be in either microsecond (seconds and microseconds) or  *	nanosecond (seconds and nanoseconds) format. The particular  *	format in use is determined by the STA_NANO bit of the status  *	word returned by the ntp_adjtime() syscall.  *  * NAME  *	ntp_adjtime - NTP daemon application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *	#include<sys/syscall.h>  *  *	int syscall(SYS_ntp_adjtime, tptr);  *	int SYS_ntp_adjtime;  *	struct timex *tptr;  *  * DESCRIPTION  *	Certain fields of the timex structure are interpreted in either  *	microseconds or nanoseconds according to the state of the  *	STA_NANO bit in the status word. See the description below for  *	further information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMEX_H_
value|1
end_define

begin_define
define|#
directive|define
name|NTP_API
value|4
end_define

begin_comment
comment|/* NTP API version */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_comment
comment|/* Microsoft specific */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_comment
comment|/*  * The following defines establish the performance envelope of the  * kernel discipline loop. Phase or frequency errors greater than  * NAXPHASE or MAXFREQ are clamped to these maxima. For update intervals  * less than MINSEC, the loop always operates in PLL mode; while, for  * update intervals greater than MAXSEC, the loop always operates in FLL  * mode. Between these two limits the operating mode is selected by the  * STA_FLL bit in the status word.  */
end_comment

begin_define
define|#
directive|define
name|MAXPHASE
value|500000000L
end_define

begin_comment
comment|/* max phase error (ns) */
end_comment

begin_define
define|#
directive|define
name|MAXFREQ
value|500000L
end_define

begin_comment
comment|/* max freq error (ns/s) */
end_comment

begin_define
define|#
directive|define
name|MINSEC
value|256
end_define

begin_comment
comment|/* min FLL update interval (s) */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|2048
end_define

begin_comment
comment|/* max PLL update interval (s) */
end_comment

begin_define
define|#
directive|define
name|NANOSECOND
value|1000000000L
end_define

begin_comment
comment|/* nanoseconds in one second */
end_comment

begin_define
define|#
directive|define
name|SCALE_PPM
value|(65536 / 1000)
end_define

begin_comment
comment|/* crude ns/s to scaled PPM */
end_comment

begin_define
define|#
directive|define
name|MAXTC
value|10
end_define

begin_comment
comment|/* max time constant */
end_comment

begin_comment
comment|/*  * The following defines and structures define the user interface for  * the ntp_gettime() and ntp_adjtime() syscalls.  *  * Control mode codes (timex.modes)  */
end_comment

begin_define
define|#
directive|define
name|MOD_OFFSET
value|0x0001
end_define

begin_comment
comment|/* set time offset */
end_comment

begin_define
define|#
directive|define
name|MOD_FREQUENCY
value|0x0002
end_define

begin_comment
comment|/* set frequency offset */
end_comment

begin_define
define|#
directive|define
name|MOD_MAXERROR
value|0x0004
end_define

begin_comment
comment|/* set maximum time error */
end_comment

begin_define
define|#
directive|define
name|MOD_ESTERROR
value|0x0008
end_define

begin_comment
comment|/* set estimated time error */
end_comment

begin_define
define|#
directive|define
name|MOD_STATUS
value|0x0010
end_define

begin_comment
comment|/* set clock status bits */
end_comment

begin_define
define|#
directive|define
name|MOD_TIMECONST
value|0x0020
end_define

begin_comment
comment|/* set PLL time constant */
end_comment

begin_define
define|#
directive|define
name|MOD_PPSMAX
value|0x0040
end_define

begin_comment
comment|/* set PPS maximum averaging time */
end_comment

begin_define
define|#
directive|define
name|MOD_TAI
value|0x0080
end_define

begin_comment
comment|/* set TAI offset */
end_comment

begin_define
define|#
directive|define
name|MOD_MICRO
value|0x1000
end_define

begin_comment
comment|/* select microsecond resolution */
end_comment

begin_define
define|#
directive|define
name|MOD_NANO
value|0x2000
end_define

begin_comment
comment|/* select nanosecond resolution */
end_comment

begin_define
define|#
directive|define
name|MOD_CLKB
value|0x4000
end_define

begin_comment
comment|/* select clock B */
end_comment

begin_define
define|#
directive|define
name|MOD_CLKA
value|0x8000
end_define

begin_comment
comment|/* select clock A */
end_comment

begin_comment
comment|/*  * Status codes (timex.status)  */
end_comment

begin_define
define|#
directive|define
name|STA_PLL
value|0x0001
end_define

begin_comment
comment|/* enable PLL updates (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSFREQ
value|0x0002
end_define

begin_comment
comment|/* enable PPS freq discipline (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSTIME
value|0x0004
end_define

begin_comment
comment|/* enable PPS time discipline (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_FLL
value|0x0008
end_define

begin_comment
comment|/* enable FLL mode (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_INS
value|0x0010
end_define

begin_comment
comment|/* insert leap (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_DEL
value|0x0020
end_define

begin_comment
comment|/* delete leap (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_UNSYNC
value|0x0040
end_define

begin_comment
comment|/* clock unsynchronized (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_FREQHOLD
value|0x0080
end_define

begin_comment
comment|/* hold frequency (rw) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSSIGNAL
value|0x0100
end_define

begin_comment
comment|/* PPS signal present (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSJITTER
value|0x0200
end_define

begin_comment
comment|/* PPS signal jitter exceeded (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSWANDER
value|0x0400
end_define

begin_comment
comment|/* PPS signal wander exceeded (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_PPSERROR
value|0x0800
end_define

begin_comment
comment|/* PPS signal calibration error (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_CLOCKERR
value|0x1000
end_define

begin_comment
comment|/* clock hardware fault (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_NANO
value|0x2000
end_define

begin_comment
comment|/* resolution (0 = us, 1 = ns) (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_MODE
value|0x4000
end_define

begin_comment
comment|/* mode (0 = PLL, 1 = FLL) (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_CLK
value|0x8000
end_define

begin_comment
comment|/* clock source (0 = A, 1 = B) (ro) */
end_comment

begin_define
define|#
directive|define
name|STA_RONLY
value|(STA_PPSSIGNAL | STA_PPSJITTER | STA_PPSWANDER | \     STA_PPSERROR | STA_CLOCKERR | STA_NANO | STA_MODE | STA_CLK)
end_define

begin_comment
comment|/*  * Clock states (time_state)  */
end_comment

begin_define
define|#
directive|define
name|TIME_OK
value|0
end_define

begin_comment
comment|/* no leap second warning */
end_comment

begin_define
define|#
directive|define
name|TIME_INS
value|1
end_define

begin_comment
comment|/* insert leap second warning */
end_comment

begin_define
define|#
directive|define
name|TIME_DEL
value|2
end_define

begin_comment
comment|/* delete leap second warning */
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
name|TIME_WAIT
value|4
end_define

begin_comment
comment|/* leap second has occured */
end_comment

begin_define
define|#
directive|define
name|TIME_ERROR
value|5
end_define

begin_comment
comment|/* error (see status word) */
end_comment

begin_comment
comment|/*  * NTP user interface (ntp_gettime()) - used to read kernel clock values  *  * Note: The time member is in microseconds if STA_NANO is zero and  * nanoseconds if not.  */
end_comment

begin_struct
struct|struct
name|ntptimeval
block|{
name|struct
name|timespec
name|time
decl_stmt|;
comment|/* current time (ns) (ro) */
name|long
name|maxerror
decl_stmt|;
comment|/* maximum error (us) (ro) */
name|long
name|esterror
decl_stmt|;
comment|/* estimated error (us) (ro) */
name|long
name|tai
decl_stmt|;
comment|/* TAI offset */
name|int
name|time_state
decl_stmt|;
comment|/* time status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NTP daemon interface (ntp_adjtime()) - used to discipline CPU clock  * oscillator and determine status.  *  * Note: The offset, precision and jitter members are in microseconds if  * STA_NANO is zero and nanoseconds if not.  */
end_comment

begin_struct
struct|struct
name|timex
block|{
name|unsigned
name|int
name|modes
decl_stmt|;
comment|/* clock mode bits (wo) */
name|long
name|offset
decl_stmt|;
comment|/* time offset (ns/us) (rw) */
name|long
name|freq
decl_stmt|;
comment|/* frequency offset (scaled PPM) (rw) */
name|long
name|maxerror
decl_stmt|;
comment|/* maximum error (us) (rw) */
name|long
name|esterror
decl_stmt|;
comment|/* estimated error (us) (rw) */
name|int
name|status
decl_stmt|;
comment|/* clock status bits (rw) */
name|long
name|constant
decl_stmt|;
comment|/* poll interval (log2 s) (rw) */
name|long
name|precision
decl_stmt|;
comment|/* clock precision (ns/us) (ro) */
name|long
name|tolerance
decl_stmt|;
comment|/* clock frequency tolerance (scaled 				 * PPM) (ro) */
comment|/* 	 * The following read-only structure members are implemented 	 * only if the PPS signal discipline is configured in the 	 * kernel. They are included in all configurations to insure 	 * portability. 	 */
name|long
name|ppsfreq
decl_stmt|;
comment|/* PPS frequency (scaled PPM) (ro) */
name|long
name|jitter
decl_stmt|;
comment|/* PPS jitter (ns/us) (ro) */
name|int
name|shift
decl_stmt|;
comment|/* interval duration (s) (shift) (ro) */
name|long
name|stabil
decl_stmt|;
comment|/* PPS stability (scaled PPM) (ro) */
name|long
name|jitcnt
decl_stmt|;
comment|/* jitter limit exceeded (ro) */
name|long
name|calcnt
decl_stmt|;
comment|/* calibration intervals (ro) */
name|long
name|errcnt
decl_stmt|;
comment|/* calibration errors (ro) */
name|long
name|stbcnt
decl_stmt|;
comment|/* stability limit exceeded (ro) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|timecounter
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|ntp_update_second
name|__P
argument_list|(
operator|(
expr|struct
name|timecounter
operator|*
name|tc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|ntp_adjtime
name|__P
argument_list|(
operator|(
expr|struct
name|timex
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntp_gettime
name|__P
argument_list|(
operator|(
expr|struct
name|ntptimeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TIMEX_H_ */
end_comment

end_unit

