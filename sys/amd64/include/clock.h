begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  *  *	$Id: clock.h,v 1.27 1997/05/05 09:34:33 peter Exp $  */
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
operator|(
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|CPU_CLOCKUPDATE
parameter_list|(
name|otime
parameter_list|,
name|ntime
parameter_list|)
value|cpu_clockupdate((otime), (ntime))
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
value|(*(otime) = *(ntime))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPU_THISTICKLEN
parameter_list|(
name|dflt
parameter_list|)
value|dflt
end_define

begin_define
define|#
directive|define
name|TSC_COMULTIPLIER_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|TSC_MULTIPLIER_SHIFT
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_decl_stmt
specifier|extern
name|u_int
name|tsc_bias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|tsc_comultiplier
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|u_int
name|tsc_freq
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_decl_stmt
specifier|extern
name|u_int
name|tsc_multiplier
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

begin_decl_stmt
specifier|extern
name|int
name|statclock_disable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|timer_freq
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|wall_cmos_clock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Driver to clock driver interface.  */
end_comment

begin_struct_decl
struct_decl|struct
name|clockframe
struct_decl|;
end_struct_decl

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

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|acquire_timer1
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
name|release_timer1
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_HAIR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i386/isa/timerreg.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_function
specifier|static
name|__inline
name|u_int
name|clock_latency
parameter_list|(
name|void
parameter_list|)
block|{
name|u_char
name|high
decl_stmt|,
name|low
decl_stmt|;
name|outb
argument_list|(
name|TIMER_MODE
argument_list|,
name|TIMER_SEL0
operator||
name|TIMER_LATCH
argument_list|)
expr_stmt|;
name|low
operator|=
name|inb
argument_list|(
name|TIMER_CNTR0
argument_list|)
expr_stmt|;
name|high
operator|=
name|inb
argument_list|(
name|TIMER_CNTR0
argument_list|)
expr_stmt|;
return|return
operator|(
name|timer0_prescaler_count
operator|+
name|timer0_max_count
operator|-
operator|(
operator|(
name|high
operator|<<
literal|8
operator|)
operator||
name|low
operator|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_comment
comment|/*  * When we update `time', on i586's we also update `tsc_bias'  * atomically.  `tsc_bias' is the best available approximation to  * the value of the i586 counter (mod 2^32) at the time of the i8254  * counter transition that caused the clock interrupt that caused the  * update.  clock_latency() gives the time between the transition and  * the update to within a few usec provided another such transition  * hasn't occurred.  We don't bother checking for counter overflow as  * in microtime(), since if it occurs then we're close to losing clock  * interrupts.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|cpu_clockupdate
parameter_list|(
specifier|volatile
name|struct
name|timeval
modifier|*
name|otime
parameter_list|,
name|struct
name|timeval
modifier|*
name|ntime
parameter_list|)
block|{
if|if
condition|(
name|tsc_freq
operator|!=
literal|0
condition|)
block|{
name|u_int
name|i586_count
decl_stmt|;
comment|/* truncated */
name|u_int
name|i8254_count
decl_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|i8254_count
operator|=
name|clock_latency
argument_list|()
expr_stmt|;
name|i586_count
operator|=
name|rdtsc
argument_list|()
expr_stmt|;
name|tsc_bias
operator|=
name|i586_count
operator|-
call|(
name|u_int
call|)
argument_list|(
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|tsc_comultiplier
operator|*
name|i8254_count
operator|)
operator|>>
name|TSC_COMULTIPLIER_SHIFT
argument_list|)
expr_stmt|;
operator|*
name|otime
operator|=
operator|*
name|ntime
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
block|}
else|else
operator|*
name|otime
operator|=
operator|*
name|ntime
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I586_CPU || I686_CPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLOCK_HAIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CLOCK_H_ */
end_comment

end_unit

