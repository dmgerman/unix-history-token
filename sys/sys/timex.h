begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *                                                                            *  * Copyright (c) David L. Mills 1993, 1994                                    *  *                                                                            *  * Permission to use, copy, modify, and distribute this software and its      *  * documentation for any purpose and without fee is hereby granted, provided  *  * that the above copyright notice appears in all copies and that both the    *  * copyright notice and this permission notice appear in supporting           *  * documentation, and that the name University of Delaware not be used in     *  * advertising or publicity pertaining to distribution of the software        *  * without specific, written prior permission.  The University of Delaware    *  * makes no representations about the suitability this software for any       *  * purpose.  It is provided "as is" without express or implied warranty.      *  *                                                                            *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Modification history timex.h  *  * 26 Sep 94	David L. Mills  *	Added defines for hybrid phase/frequency-lock loop.  *  * 19 Mar 94	David L. Mills  *	Moved defines from kernel routines to header file and added new  *	defines for PPS phase-lock loop.  *  * 20 Feb 94	David L. Mills  *	Revised status codes and structures for external clock and PPS  *	signal discipline.  *  * 28 Nov 93	David L. Mills  *	Adjusted parameters to improve stability and increase poll  *	interval.  *  * 17 Sep 93    David L. Mills  *      Created file  */
end_comment

begin_comment
comment|/*  * This header file defines the Network Time Protocol (NTP) interfaces  * for user and daemon application programs. These are implemented using  * private syscalls and data structures and require specific kernel  * support.  *  * NAME  *	ntp_gettime - NTP user application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *  *	int syscall(SYS_ntp_gettime, tptr)  *  *	int SYS_ntp_gettime		defined in syscall.h header file  *	struct ntptimeval *tptr		pointer to ntptimeval structure  *  * NAME  *	ntp_adjtime - NTP daemon application interface  *  * SYNOPSIS  *	#include<sys/timex.h>  *  *	int syscall(SYS_ntp_adjtime, mode, tptr)  *  *	int SYS_ntp_adjtime		defined in syscall.h header file  *	struct timex *tptr		pointer to timex structure  *  */
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
comment|/*  * The following defines establish the engineering parameters of the  * phase-lock loop (PLL) model used in the kernel implementation. These  * parameters have been carefully chosen by analysis for good stability  * and wide dynamic range.  *  * The hz variable is defined in the kernel build environment. It  * establishes the timer interrupt frequency, 100 Hz for the SunOS  * kernel, 256 Hz for the Ultrix kernel and 1024 Hz for the OSF/1  * kernel. SHIFT_HZ expresses the same value as the nearest power of two  * in order to avoid hardware multiply operations.  *  * SHIFT_KG and SHIFT_KF establish the damping of the PLL and are chosen  * for a slightly underdamped convergence characteristic. SHIFT_KH  * establishes the damping of the FLL and is chosen by wisdom and black  * art.  *  * MAXTC establishes the maximum time constant of the PLL. With the  * SHIFT_KG and SHIFT_KF values given and a time constant range from  * zero to MAXTC, the PLL will converge in 15 minutes to 16 hours,  * respectively.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_HZ
value|7
end_define

begin_comment
comment|/* log2(hz) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_KG
value|6
end_define

begin_comment
comment|/* phase factor (shift) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_KF
value|16
end_define

begin_comment
comment|/* PLL frequency factor (shift) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_KH
value|2
end_define

begin_comment
comment|/* FLL frequency factor (shift) */
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
comment|/*  * The following defines establish the scaling of the various variables  * used by the PLL. They are chosen to allow the greatest precision  * possible without overflow of a 32-bit word.  *  * SHIFT_SCALE defines the scaling (shift) of the time_phase variable,  * which serves as a an extension to the low-order bits of the system  * clock variable time.tv_usec.  *  * SHIFT_UPDATE defines the scaling (shift) of the time_offset variable,  * which represents the current time offset with respect to standard  * time.  *  * SHIFT_USEC defines the scaling (shift) of the time_freq and  * time_tolerance variables, which represent the current frequency  * offset and maximum frequency tolerance.  *  * FINEUSEC is 1 us in SHIFT_UPDATE units of the time_phase variable.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_SCALE
value|22
end_define

begin_comment
comment|/* phase scale (shift) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_UPDATE
value|(SHIFT_KG + MAXTC)
end_define

begin_comment
comment|/* time offset scale (shift) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_USEC
value|16
end_define

begin_comment
comment|/* frequency offset scale (shift) */
end_comment

begin_define
define|#
directive|define
name|FINEUSEC
value|(1L<< SHIFT_SCALE)
end_define

begin_comment
comment|/* 1 us in phase units */
end_comment

begin_comment
comment|/*  * The following defines establish the performance envelope of the PLL.  * They insure it operates within predefined limits, in order to satisfy  * correctness assertions. An excursion which exceeds these bounds is  * clamped to the bound and operation proceeds accordingly. In practice,  * this can occur only if something has failed or is operating out of  * tolerance, but otherwise the PLL continues to operate in a stable  * mode.  *  * MAXPHASE must be set greater than or equal to CLOCK.MAX (128 ms), as  * defined in the NTP specification. CLOCK.MAX establishes the maximum  * time offset allowed before the system time is reset, rather than  * incrementally adjusted. Here, the maximum offset is clamped to  * MAXPHASE only in order to prevent overflow errors due to defective  * protocol implementations.  *  * MAXFREQ is the maximum frequency tolerance of the CPU clock  * oscillator plus the maximum slew rate allowed by the protocol. It  * should be set to at least the frequency tolerance of the oscillator  * plus 100 ppm for vernier frequency adjustments. If the kernel  * PPS discipline code is configured (PPS_SYNC), the oscillator time and  * frequency are disciplined to an external source, presumably with  * negligible time and frequency error relative to UTC, and MAXFREQ can  * be reduced.  *  * MAXTIME is the maximum jitter tolerance of the PPS signal if the  * kernel PPS discipline code is configured (PPS_SYNC).  *  * MINSEC and MAXSEC define the lower and upper bounds on the interval  * between protocol updates.  */
end_comment

begin_define
define|#
directive|define
name|MAXPHASE
value|512000L
end_define

begin_comment
comment|/* max phase error (us) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPS_SYNC
end_ifdef

begin_define
define|#
directive|define
name|MAXFREQ
value|(512L<< SHIFT_USEC)
end_define

begin_comment
comment|/* max freq error (100 ppm) */
end_comment

begin_define
define|#
directive|define
name|MAXTIME
value|(200L<< PPS_AVG)
end_define

begin_comment
comment|/* max PPS error (jitter) (200 us) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXFREQ
value|(512L<< SHIFT_USEC)
end_define

begin_comment
comment|/* max freq error (200 ppm) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS_SYNC */
end_comment

begin_define
define|#
directive|define
name|MINSEC
value|16L
end_define

begin_comment
comment|/* min interval between updates (s) */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|1200L
end_define

begin_comment
comment|/* max interval between updates (s) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPS_SYNC
end_ifdef

begin_comment
comment|/*  * The following defines are used only if a pulse-per-second (PPS)  * signal is available and connected via a modem control lead, such as  * produced by the optional ppsclock feature incorporated in the Sun  * asynch driver. They establish the design parameters of the frequency-  * lock loop used to discipline the CPU clock oscillator to the PPS  * signal.  *  * PPS_AVG is the averaging factor for the frequency loop, as well as  * the time and frequency dispersion.  *  * PPS_SHIFT and PPS_SHIFTMAX specify the minimum and maximum  * calibration intervals, respectively, in seconds as a power of two.  *  * PPS_VALID is the maximum interval before the PPS signal is considered  * invalid and protocol updates used directly instead.  *  * MAXGLITCH is the maximum interval before a time offset of more than  * MAXTIME is believed.  */
end_comment

begin_define
define|#
directive|define
name|PPS_AVG
value|2
end_define

begin_comment
comment|/* pps averaging constant (shift) */
end_comment

begin_define
define|#
directive|define
name|PPS_SHIFT
value|2
end_define

begin_comment
comment|/* min interval duration (s) (shift) */
end_comment

begin_define
define|#
directive|define
name|PPS_SHIFTMAX
value|8
end_define

begin_comment
comment|/* max interval duration (s) (shift) */
end_comment

begin_define
define|#
directive|define
name|PPS_VALID
value|120
end_define

begin_comment
comment|/* pps signal watchdog max (s) */
end_comment

begin_define
define|#
directive|define
name|MAXGLITCH
value|30
end_define

begin_comment
comment|/* pps signal glitch max (s) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS_SYNC */
end_comment

begin_comment
comment|/*  * The following defines and structures define the user interface for  * the ntp_gettime() and ntp_adjtime() system calls.  *  * Control mode codes (timex.modes)  */
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
comment|/* set pll time constant */
end_comment

begin_define
define|#
directive|define
name|MOD_CLKB
value|0x4000
end_define

begin_comment
comment|/* set clock B */
end_comment

begin_define
define|#
directive|define
name|MOD_CLKA
value|0x8000
end_define

begin_comment
comment|/* set clock A */
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
comment|/* select frequency-lock mode (rw) */
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
name|STA_RONLY
value|(STA_PPSSIGNAL | STA_PPSJITTER | STA_PPSWANDER | \     STA_PPSERROR | STA_CLOCKERR)
end_define

begin_comment
comment|/* read-only bits */
end_comment

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
comment|/* clock not synchronized */
end_comment

begin_comment
comment|/*  * NTP user interface (ntp_gettime()) - used to read kernel clock values  *  * Note: maximum error = NTP synch distance = dispersion + delay / 2;  * estimated error = NTP dispersion.  */
end_comment

begin_struct
struct|struct
name|ntptimeval
block|{
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* current time (ro) */
name|long
name|maxerror
decl_stmt|;
comment|/* maximum error (us) (ro) */
name|long
name|esterror
decl_stmt|;
comment|/* estimated error (us) (ro) */
name|int
name|time_state
decl_stmt|;
comment|/* what ntp_gettime returns */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NTP daemon interface - (ntp_adjtime()) used to discipline CPU clock  * oscillator  */
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
comment|/* time offset (us) (rw) */
name|long
name|freq
decl_stmt|;
comment|/* frequency offset (scaled ppm) (rw) */
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
comment|/* pll time constant (rw) */
name|long
name|precision
decl_stmt|;
comment|/* clock precision (us) (ro) */
name|long
name|tolerance
decl_stmt|;
comment|/* clock frequency tolerance (scaled 				 * ppm) (ro) */
comment|/* 	 * The following read-only structure members are implemented 	 * only if the PPS signal discipline is configured in the 	 * kernel. 	 */
name|long
name|ppsfreq
decl_stmt|;
comment|/* pps frequency (scaled ppm) (ro) */
name|long
name|jitter
decl_stmt|;
comment|/* pps jitter (us) (ro) */
name|int
name|shift
decl_stmt|;
comment|/* interval duration (s) (shift) (ro) */
name|long
name|stabil
decl_stmt|;
comment|/* pps stability (scaled ppm) (ro) */
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

begin_comment
comment|/*  * sysctl identifiers underneath kern.ntp_pll  */
end_comment

begin_define
define|#
directive|define
name|NTP_PLL_GETTIME
value|1
end_define

begin_comment
comment|/* used by ntp_gettime() */
end_comment

begin_define
define|#
directive|define
name|NTP_PLL_MAXID
value|2
end_define

begin_comment
comment|/* number of valid ids */
end_comment

begin_define
define|#
directive|define
name|NTP_PLL_NAMES
value|{ \ 			  { 0, 0 }, \ 			  { "gettime", CTLTYPE_STRUCT }, \ 		      }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|ntp_update_second
name|__P
argument_list|(
operator|(
name|long
operator|*
name|newsec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|time_phase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|time_adj
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
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

begin_decl_stmt
specifier|extern
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not KERNEL */
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
comment|/* _SYS_TIMEX_H_ */
end_comment

end_unit

