begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *                                                                            *  * Copyright (c) David L. Mills 1993, 1994                                    *  *                                                                            *  * Permission to use, copy, modify, and distribute this software and its      *  * documentation for any purpose and without fee is hereby granted, provided  *  * that the above copyright notice appears in all copies and that both the    *  * copyright notice and this permission notice appear in supporting           *  * documentation, and that the name University of Delaware not be used in     *  * advertising or publicity pertaining to distribution of the software        *  * without specific, written prior permission.  The University of Delaware    *  * makes no representations about the suitability this software for any       *  * purpose.  It is provided "as is" without express or implied warranty.      *  *                                                                            *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Modification history kern_ntptime.c  *  * 14 Feb 94	David L. Mills  *	Added code for external clock  *  * 28 Nov 93	David L. Mills  *	Revised frequency scaling to conform with adjusted parameters  *  * 17 Sep 93	David L. Mills  *	Created file  */
end_comment

begin_comment
comment|/*  * ntp_gettime(), ntp_adjtime() - precision time interface  *  * These routines consitute the Network Time Protocol (NTP) interfaces  * for user and daemon application programs. The ntp_gettime() routine  * provides the time, maximum error (synch distance) and estimated error  * (dispersion) to client user application programs. The ntp_adjtime()  * routine is used by the NTP daemon to adjust the system clock to an  * externally derived time. The time offset and related variables set by  * this routine are used by hardclock() to adjust the phase and  * frequency of the phase-lock loop which controls the system clock.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/timex.h>
end_include

begin_comment
comment|/*  * The following variables are used by the hardclock() routine in the  * kern_clock.c module and are described in that module.   */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time adjustment (us) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_freq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency offset (scaled ppm) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_maxerror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum error (us) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_esterror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimated error (us) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|time_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock synchronization status */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_constant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pll time constant */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock precision (us) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_tolerance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency tolerance (scaled ppm) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPS_SYNC
end_ifdef

begin_comment
comment|/*  * The following variables are used only if the PPS signal discipline  * is configured in the kernel.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pps_ybar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency estimate (scaled ppm) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pps_disp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion estimate (scaled ppm) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pps_shift
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interval duration (s) (shift) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pps_calcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calibration intervals */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pps_jitcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* jitter limit exceeded */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pps_discnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion limit exceeded */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS_SYNC */
end_comment

begin_comment
comment|/*  * ntp_gettime() - NTP user application interface  */
end_comment

begin_macro
name|ntp_gettime
argument_list|()
end_macro

begin_block
block|{
specifier|register
struct|struct
name|a
block|{
name|struct
name|ntptimeval
modifier|*
name|tp
decl_stmt|;
block|}
modifier|*
name|uap
init|=
operator|(
expr|struct
name|a
operator|*
operator|)
name|u
operator|.
name|u_ap
struct|;
name|struct
name|timeval
name|atv
decl_stmt|;
name|struct
name|ntptimeval
name|ntv
decl_stmt|;
name|int
name|s
decl_stmt|;
if|if
condition|(
name|uap
operator|->
name|tp
condition|)
block|{
name|s
operator|=
name|splclock
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|EXT_CLOCK
comment|/* 		 * The microtime() external clock routine returns a 		 * status code. If less than zero, we declare a bummer. 		 * While there are other places that call microtime(), 		 * this is the only place that matters from an 		 * application point of view. 		 */
if|if
condition|(
name|microtime
argument_list|(
operator|&
name|atv
argument_list|)
operator|<
literal|0
condition|)
name|time_status
operator|=
name|TIME_ERR
expr_stmt|;
elseif|else
if|if
condition|(
name|time_status
operator|==
name|TIME_ERR
condition|)
name|time_status
operator|=
name|TIME_BAD
expr_stmt|;
else|#
directive|else
comment|/* EXT_CLOCK */
name|microtime
argument_list|(
operator|&
name|atv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* EXT_CLOCK */
name|ntv
operator|.
name|time
operator|=
name|atv
expr_stmt|;
name|ntv
operator|.
name|maxerror
operator|=
name|time_maxerror
expr_stmt|;
name|ntv
operator|.
name|esterror
operator|=
name|time_esterror
expr_stmt|;
operator|(
name|void
operator|)
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|u
operator|.
name|u_error
operator|=
name|copyout
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|ntv
argument_list|,
operator|(
name|caddr_t
operator|)
name|uap
operator|->
name|tp
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|u
operator|.
name|u_error
condition|)
name|u
operator|.
name|u_r
operator|.
name|r_val1
operator|=
name|time_status
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * ntp_adjtime() - NTP daemon application interface  */
end_comment

begin_macro
name|ntp_adjtime
argument_list|()
end_macro

begin_block
block|{
specifier|register
struct|struct
name|a
block|{
name|struct
name|timex
modifier|*
name|tp
decl_stmt|;
block|}
modifier|*
name|uap
init|=
operator|(
expr|struct
name|a
operator|*
operator|)
name|u
operator|.
name|u_ap
struct|;
name|struct
name|timex
name|ntv
decl_stmt|;
name|int
name|s
decl_stmt|;
name|u
operator|.
name|u_error
operator|=
name|copyin
argument_list|(
operator|(
name|caddr_t
operator|)
name|uap
operator|->
name|tp
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ntv
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u_error
condition|)
return|return;
comment|/* 	 * Update selected clock variables - only the superuser can 	 * change anything. Note that there is no error checking here on 	 * the assumption the superuser should know what it is doing. 	 */
if|if
condition|(
operator|!
name|suser
argument_list|()
operator|&&
name|ntv
operator|.
name|mode
operator|!=
literal|0
condition|)
return|return;
name|s
operator|=
name|splclock
argument_list|()
expr_stmt|;
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_OFFSET
condition|)
name|hardupdate
argument_list|(
name|ntv
operator|.
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_FREQUENCY
condition|)
ifdef|#
directive|ifdef
name|PPS_SYNC
name|time_freq
operator|=
name|ntv
operator|.
name|frequency
operator|-
name|pps_ybar
expr_stmt|;
else|#
directive|else
comment|/* PPS_SYNC */
name|time_freq
operator|=
name|ntv
operator|.
name|frequency
expr_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_MAXERROR
condition|)
name|time_maxerror
operator|=
name|ntv
operator|.
name|maxerror
expr_stmt|;
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_ESTERROR
condition|)
name|time_esterror
operator|=
name|ntv
operator|.
name|esterror
expr_stmt|;
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_STATUS
condition|)
if|if
condition|(
name|time_status
operator|==
name|TIME_OK
operator|||
name|ntv
operator|.
name|status
operator|==
name|TIME_BAD
condition|)
name|time_status
operator|=
name|ntv
operator|.
name|status
expr_stmt|;
if|if
condition|(
name|ntv
operator|.
name|mode
operator|&
name|ADJ_TIMECONST
condition|)
name|time_constant
operator|=
name|ntv
operator|.
name|time_constant
expr_stmt|;
comment|/* 	 * Retrieve all clock variables 	 */
if|if
condition|(
name|time_offset
operator|<
literal|0
condition|)
name|ntv
operator|.
name|offset
operator|=
operator|-
operator|(
operator|-
name|time_offset
operator|>>
name|SHIFT_UPDATE
operator|)
expr_stmt|;
else|else
name|ntv
operator|.
name|offset
operator|=
name|time_offset
operator|>>
name|SHIFT_UPDATE
expr_stmt|;
ifdef|#
directive|ifdef
name|PPS_SYNC
name|ntv
operator|.
name|frequency
operator|=
name|time_freq
operator|+
name|pps_ybar
expr_stmt|;
else|#
directive|else
comment|/* PPS_SYNC */
name|ntv
operator|.
name|frequency
operator|=
name|time_freq
expr_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
name|ntv
operator|.
name|maxerror
operator|=
name|time_maxerror
expr_stmt|;
name|ntv
operator|.
name|esterror
operator|=
name|time_esterror
expr_stmt|;
name|ntv
operator|.
name|status
operator|=
name|time_status
expr_stmt|;
name|ntv
operator|.
name|time_constant
operator|=
name|time_constant
expr_stmt|;
name|ntv
operator|.
name|precision
operator|=
name|time_precision
expr_stmt|;
name|ntv
operator|.
name|tolerance
operator|=
name|time_tolerance
expr_stmt|;
ifdef|#
directive|ifdef
name|PPS_SYNC
name|ntv
operator|.
name|ybar
operator|=
name|pps_ybar
expr_stmt|;
name|ntv
operator|.
name|disp
operator|=
name|pps_disp
expr_stmt|;
name|ntv
operator|.
name|shift
operator|=
name|pps_shift
expr_stmt|;
name|ntv
operator|.
name|calcnt
operator|=
name|pps_calcnt
expr_stmt|;
name|ntv
operator|.
name|jitcnt
operator|=
name|pps_jitcnt
expr_stmt|;
name|ntv
operator|.
name|discnt
operator|=
name|pps_discnt
expr_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
operator|(
name|void
operator|)
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|u
operator|.
name|u_error
operator|=
name|copyout
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|ntv
argument_list|,
operator|(
name|caddr_t
operator|)
name|uap
operator|->
name|tp
argument_list|,
sizeof|sizeof
argument_list|(
name|ntv
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|u
operator|.
name|u_error
condition|)
name|u
operator|.
name|u_r
operator|.
name|r_val1
operator|=
name|time_status
expr_stmt|;
block|}
end_block

end_unit

