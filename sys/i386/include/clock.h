begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  *  *	$Id: clock.h,v 1.10 1996/03/31 04:05:17 bde Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CLOCK_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
end_if

begin_define
define|#
directive|define
name|I586_CYCLECTR
parameter_list|(
name|x
parameter_list|)
define|\
value|__asm __volatile(".byte 0x0f, 0x31" : "=A" (x))
end_define

begin_comment
comment|/*  * When we update the clock, we also update this bias value which is  * automatically subtracted in microtime().  We assume that CPU_THISTICKLEN()  * has been called at some point in the past, so that an appropriate value is  * set up in i586_last_tick.  (This works even if we are not being called  * from hardclock because hardclock will have run before and will made the  * call.)  */
end_comment

begin_define
define|#
directive|define
name|CPU_CLOCKUPDATE
parameter_list|(
name|otime
parameter_list|,
name|ntime
parameter_list|)
define|\
value|do { \ 	if(i586_ctr_rate) { \ 		disable_intr(); \ 		i586_ctr_bias = i586_last_tick; \ 		*(otime) = *(ntime); \ 		enable_intr(); \ 	} else { \ 		*(otime) = *(ntime); \ 	} \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CPU_THISTICKLEN
parameter_list|(
name|dflt
parameter_list|)
value|cpu_thisticklen(dflt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_CLOCKUPDATE
parameter_list|(
name|otime
parameter_list|,
name|ntime
parameter_list|)
define|\
value|(*(otime) = *(ntime))
end_define

begin_define
define|#
directive|define
name|CPU_THISTICKLEN
parameter_list|(
name|dflt
parameter_list|)
value|dflt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I586_CTR_RATE_SHIFT
value|8
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * i386 to clock driver interface.  * XXX almost all of it is misplaced.  i586 stuff is done in isa/clock.c  * and isa stuff is done in i386/microtime.s and i386/support.s.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adjkerntz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|disable_rtc_set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wall_cmos_clock
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|i586_ctr_rate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fixed point */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|long
name|i586_last_tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|long
name|i586_ctr_bias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|i586_avg_tick
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|timer0_max_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|timer0_overflow_threshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|timer0_prescaler_count
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
end_if

begin_decl_stmt
name|void
name|calibrate_cyclecounter
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|u_long
name|cpu_thisticklen
parameter_list|(
name|u_long
name|dflt
parameter_list|)
block|{
name|long
name|long
name|old
decl_stmt|;
name|long
name|len
decl_stmt|;
if|if
condition|(
name|i586_ctr_rate
condition|)
block|{
name|old
operator|=
name|i586_last_tick
expr_stmt|;
name|I586_CYCLECTR
argument_list|(
name|i586_last_tick
argument_list|)
expr_stmt|;
name|len
operator|=
operator|(
operator|(
name|i586_last_tick
operator|-
name|old
operator|)
operator|<<
name|I586_CTR_RATE_SHIFT
operator|)
operator|/
name|i586_ctr_rate
expr_stmt|;
name|i586_avg_tick
operator|=
name|i586_avg_tick
operator|*
literal|15
operator|/
literal|16
operator|+
name|len
operator|/
literal|16
expr_stmt|;
block|}
return|return
name|dflt
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Driver to clock driver interface.  */
end_comment

begin_decl_stmt
name|void
name|DELAY
name|__P
argument_list|(
operator|(
name|int
name|usec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acquire_timer0
name|__P
argument_list|(
operator|(
name|int
name|rate
operator|,
name|void
argument_list|(
operator|*
name|function
argument_list|)
argument_list|(
expr|struct
name|clockframe
operator|*
name|frame
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acquire_timer2
name|__P
argument_list|(
operator|(
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|release_timer0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|release_timer2
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rtcin
name|__P
argument_list|(
operator|(
name|int
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysbeep
name|__P
argument_list|(
operator|(
name|int
name|pitch
operator|,
name|int
name|period
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL&& !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CLOCK_H_ */
end_comment

end_unit

