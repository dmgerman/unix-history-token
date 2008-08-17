begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MPE
end_ifdef

begin_comment
comment|/*  * MPE lacks adjtime(), so we define our own.  But note that time slewing has  * a sub-second accuracy bug documented in SR 5003462838 which prevents ntpd  * from being able to maintain clock synch.  Because of the bug, this adjtime()  * implementation as used by ntpd has a side-effect of screwing up the hardware  * PDC clock, which will need to be reset with a reboot.  *  * This problem affects all versions of MPE at the time of this writing (when  * MPE/iX 7.0 is the most current).  It only causes bad things to happen when  * doing continuous clock synchronization with ntpd; note that you CAN run ntpd  * with "disable ntp" in ntp.conf if you wish to provide a time server.  *  * The one-time clock adjustment functionality of ntpdate and ntp_timeset can  * be used without screwing up the PDC clock.  *   */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function_decl
name|int
name|adjtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|adjtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
block|{
comment|/* Documented, supported MPE system intrinsics. */
specifier|extern
name|void
name|GETPRIVMODE
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|GETUSERMODE
argument_list|(
name|void
argument_list|)
decl_stmt|;
comment|/* Undocumented, unsupported MPE internal functions. */
specifier|extern
name|long
name|long
name|current_correction_usecs
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|long
name|long
name|get_time
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|get_time_change_info
argument_list|(
name|long
name|long
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|long
name|long
name|pdc_time
argument_list|(
name|int
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|set_time_correction
argument_list|(
name|long
name|long
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|;
specifier|extern
name|long
name|long
name|ticks_to_micro
argument_list|(
name|long
name|long
argument_list|)
decl_stmt|;
name|long
name|long
name|big_sec
decl_stmt|,
name|big_usec
decl_stmt|,
name|new_correction
init|=
literal|0LL
decl_stmt|;
name|long
name|long
name|prev_correction
decl_stmt|;
if|if
condition|(
name|delta
operator|!=
name|NULL
condition|)
block|{
comment|/* Adjustment required.  Convert delta to 64-bit microseconds. */
name|big_sec
operator|=
operator|(
name|long
operator|)
name|delta
operator|->
name|tv_sec
expr_stmt|;
name|big_usec
operator|=
name|delta
operator|->
name|tv_usec
expr_stmt|;
name|new_correction
operator|=
operator|(
name|big_sec
operator|*
literal|1000000LL
operator|)
operator|+
name|big_usec
expr_stmt|;
block|}
name|GETPRIVMODE
argument_list|()
expr_stmt|;
comment|/* Determine how much of a previous correction (if any) we're interrupting. */
name|prev_correction
operator|=
name|current_correction_usecs
argument_list|()
expr_stmt|;
if|if
condition|(
name|delta
operator|!=
name|NULL
condition|)
block|{
comment|/* Adjustment required. */
if|#
directive|if
literal|0
comment|/* Speculative code disabled until bug SR 5003462838 is fixed.  This bug      prevents accurate time slewing, and indeed renders ntpd inoperable. */
block|if (prev_correction != 0LL) {
comment|/* A previous adjustment did not complete.  Since the PDC UTC clock was     immediately jumped at the start of the previous adjustment, we must     explicitly reset it to the value of the MPE local time clock minus the     time zone offset. */
block|char pwf_since_boot, recover_pwf_time;     long long offset_ticks, offset_usecs, pdc_usecs_current, pdc_usecs_wanted;     int hpe_status;      get_time_change_info(&offset_ticks,&pwf_since_boot,&recover_pwf_time);     offset_usecs = ticks_to_micro(offset_ticks);     pdc_usecs_wanted = get_time() - offset_usecs;     pdc_usecs_current = pdc_time(&hpe_status);     if (hpe_status == 0)
comment|/* Force new PDC time by starting an extra correction. */
block|set_time_correction(pdc_usecs_wanted - pdc_usecs_current,0,1);   }
endif|#
directive|endif
comment|/* 0 */
comment|/* Immediately jump the PDC time to the new value, and then initiate a       gradual MPE time correction slew. */
name|set_time_correction
argument_list|(
name|new_correction
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|GETUSERMODE
argument_list|()
expr_stmt|;
if|if
condition|(
name|olddelta
operator|!=
name|NULL
condition|)
block|{
comment|/* Caller wants to know remaining amount of previous correction. */
operator|(
name|long
operator|)
name|olddelta
operator|->
name|tv_sec
operator|=
name|prev_correction
operator|/
literal|1000000LL
expr_stmt|;
name|olddelta
operator|->
name|tv_usec
operator|=
name|prev_correction
operator|%
literal|1000000LL
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_HPUX_ADJTIME
end_ifdef

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/* (c) Copyright Tai Jin, 1988.  All Rights Reserved.                    */
end_comment

begin_comment
comment|/*     Hewlett-Packard Laboratories.                                     */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* Permission is hereby granted for unlimited modification, use, and     */
end_comment

begin_comment
comment|/* distribution.  This software is made available with no warranty of    */
end_comment

begin_comment
comment|/* any kind, express or implied.  This copyright notice must remain      */
end_comment

begin_comment
comment|/* intact in all versions of this software.                              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* The author would appreciate it if any bug fixes and enhancements were */
end_comment

begin_comment
comment|/* to be sent back to him for incorporation into future versions of this */
end_comment

begin_comment
comment|/* software.  Please send changes to tai@iag.hp.com or ken@sdd.hp.com.   */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*  * Revision history  *  * 9 Jul 94	David L. Mills, Unibergity of Delabunch  *		Implemented variable threshold to limit age of  *		corrections; reformatted code for readability.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|RCSid
index|[]
init|=
literal|"adjtime.c,v 3.1 1993/07/06 01:04:42 jbj Exp"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/msg.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"adjtime.h"
end_include

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_comment
comment|/*  * The following paramters are appropriate for an NTP adjustment  * interval of one second.  */
end_comment

begin_define
define|#
directive|define
name|ADJ_THRESH
value|200
end_define

begin_comment
comment|/* initial threshold */
end_comment

begin_define
define|#
directive|define
name|ADJ_DELTA
value|4
end_define

begin_comment
comment|/* threshold decrement */
end_comment

begin_decl_stmt
specifier|static
name|long
name|adjthresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adjustment threshold */
end_comment

begin_decl_stmt
specifier|static
name|long
name|saveup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* corrections accumulator */
end_comment

begin_comment
comment|/*  * clear_adjtime - reset accumulator and threshold variables  */
end_comment

begin_function
name|void
name|_clear_adjtime
parameter_list|(
name|void
parameter_list|)
block|{
name|saveup
operator|=
literal|0
expr_stmt|;
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * adjtime - hp-ux copout of the standard Unix adjtime() system call  */
end_comment

begin_function
name|int
name|adjtime
parameter_list|(
specifier|register
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
block|{
name|struct
name|timeval
name|newdelta
decl_stmt|;
comment|/* 	 * Corrections greater than one second are done immediately. 	 */
if|if
condition|(
name|delta
operator|->
name|tv_sec
condition|)
block|{
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
name|saveup
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|_adjtime
argument_list|(
name|delta
argument_list|,
name|olddelta
argument_list|)
operator|)
return|;
block|}
comment|/* 	 * Corrections less than one second are accumulated until 	 * tripping a threshold, which is initially set at ADJ_THESH and 	 * reduced in ADJ_DELTA steps to zero. The idea here is to 	 * introduce large corrections quickly, while making sure that 	 * small corrections are introduced without excessive delay. The 	 * idea comes from the ARPAnet routing update algorithm. 	 */
name|saveup
operator|+=
name|delta
operator|->
name|tv_usec
expr_stmt|;
if|if
condition|(
name|abs
argument_list|(
name|saveup
argument_list|)
operator|>=
name|adjthresh
condition|)
block|{
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
name|newdelta
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|newdelta
operator|.
name|tv_usec
operator|=
name|saveup
expr_stmt|;
name|saveup
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|_adjtime
argument_list|(
operator|&
name|newdelta
argument_list|,
name|olddelta
argument_list|)
operator|)
return|;
block|}
else|else
block|{
name|adjthresh
operator|-=
name|ADJ_DELTA
expr_stmt|;
block|}
comment|/* 	 * While nobody uses it, return the residual before correction, 	 * as per Unix convention. 	 */
if|if
condition|(
name|olddelta
condition|)
name|olddelta
operator|->
name|tv_sec
operator|=
name|olddelta
operator|->
name|tv_usec
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * _adjtime - does the actual work  */
end_comment

begin_function
name|int
name|_adjtime
parameter_list|(
specifier|register
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
block|{
specifier|register
name|int
name|mqid
decl_stmt|;
name|MsgBuf
name|msg
decl_stmt|;
specifier|register
name|MsgBuf
modifier|*
name|msgp
init|=
operator|&
name|msg
decl_stmt|;
comment|/* 	 * Get the key to the adjtime message queue (note that we must 	 * get it every time because the queue might have been removed 	 * and recreated) 	 */
if|if
condition|(
operator|(
name|mqid
operator|=
name|msgget
argument_list|(
name|KEY
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|msgp
operator|->
name|msgb
operator|.
name|mtype
operator|=
name|CLIENT
expr_stmt|;
name|msgp
operator|->
name|msgb
operator|.
name|tv
operator|=
operator|*
name|delta
expr_stmt|;
if|if
condition|(
name|olddelta
condition|)
name|msgp
operator|->
name|msgb
operator|.
name|code
operator|=
name|DELTA2
expr_stmt|;
else|else
name|msgp
operator|->
name|msgb
operator|.
name|code
operator|=
name|DELTA1
expr_stmt|;
comment|/* 	 * Tickle adjtimed and snatch residual, if indicated. Lots of 	 * fanatic error checking here. 	 */
if|if
condition|(
name|msgsnd
argument_list|(
name|mqid
argument_list|,
operator|&
name|msgp
operator|->
name|msgp
argument_list|,
name|MSGSIZE
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|olddelta
condition|)
block|{
if|if
condition|(
name|msgrcv
argument_list|(
name|mqid
argument_list|,
operator|&
name|msgp
operator|->
name|msgp
argument_list|,
name|MSGSIZE
argument_list|,
name|SERVER
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|olddelta
operator|=
name|msgp
operator|->
name|msgb
operator|.
name|tv
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NEED_QNX_ADJTIME
end_if

begin_comment
comment|/*  * Emulate adjtime() using QNX ClockAdjust().  * Chris Burghart<burghart@atd.ucar.edu>, 11/2001  *  * This is a *very* simple implementation of adjtime() for QNX.    * ClockAdjust() is used to tweak the system clock by about +- 1/10   * of its current clock period per tick until the desired delta is   * achieved.  */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/neutrino.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<ntp_stdlib.h>
end_include

begin_function
name|int
name|adjtime
parameter_list|(
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
block|{
name|double
name|delta_nsec
decl_stmt|;
name|double
name|delta_nsec_old
decl_stmt|;
name|struct
name|_clockadjust
name|adj
decl_stmt|;
name|struct
name|_clockadjust
name|oldadj
decl_stmt|;
comment|/*      * How many nanoseconds are we adjusting?      */
name|delta_nsec
operator|=
name|delta
operator|->
name|tv_sec
operator|*
literal|1e9
operator|+
name|delta
operator|->
name|tv_usec
operator|*
literal|1000
expr_stmt|;
comment|/*      * Build the adjust structure and call ClockAdjust()      */
if|if
condition|(
name|delta_nsec
operator|!=
literal|0
condition|)
block|{
name|struct
name|_clockperiod
name|period
decl_stmt|;
name|long
name|count
decl_stmt|;
name|long
name|increment
decl_stmt|;
comment|/* 	 * Get the current clock period (nanoseconds) 	 */
if|if
condition|(
name|ClockPeriod
argument_list|(
name|CLOCK_REALTIME
argument_list|,
literal|0
argument_list|,
operator|&
name|period
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* 	 * Set the adjust increment to approximately 1/10 timer period per  	 * clock tick. 	 */
name|count
operator|=
literal|1
operator|+
call|(
name|long
call|)
argument_list|(
name|fabs
argument_list|(
literal|10
operator|*
name|delta_nsec
operator|/
name|period
operator|.
name|nsec
argument_list|)
argument_list|)
expr_stmt|;
name|increment
operator|=
call|(
name|long
call|)
argument_list|(
name|delta_nsec
operator|/
name|count
argument_list|)
expr_stmt|;
name|adj
operator|.
name|tick_nsec_inc
operator|=
name|increment
expr_stmt|;
name|adj
operator|.
name|tick_count
operator|=
name|count
expr_stmt|;
block|}
else|else
block|{
name|adj
operator|.
name|tick_nsec_inc
operator|=
literal|0
expr_stmt|;
name|adj
operator|.
name|tick_count
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ClockAdjust
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|adj
argument_list|,
operator|&
name|oldadj
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/*      * Build olddelta      */
name|delta_nsec_old
operator|=
name|oldadj
operator|.
name|tick_count
operator|*
name|oldadj
operator|.
name|tick_nsec_inc
expr_stmt|;
name|olddelta
operator|->
name|tv_sec
operator|=
call|(
name|int
call|)
argument_list|(
name|delta_nsec_old
operator|/
literal|1e9
argument_list|)
expr_stmt|;
name|olddelta
operator|->
name|tv_usec
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
name|delta_nsec_old
operator|-
literal|1.0e9
operator|*
name|olddelta
operator|->
name|tv_sec
operator|)
operator|/
literal|1000
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no special adjtime() needed */
end_comment

begin_decl_stmt
name|int
name|adjtime_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

