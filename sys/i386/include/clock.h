begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

begin_comment
comment|/* 	 * This resets the CPU cycle counter to zero, to make our 	 * job easier in microtime().  Some fancy ifdefs could speed 	 * this up for Pentium-only kernels. 	 * We want this to be done as close as possible to the actual 	 * timer incrementing in hardclock(), because there is a window 	 * between the two where the value is no longer valid.  Experimentation 	 * may reveal a good precompensation to apply in microtime(). 	 */
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
value|do { \ 	if(pentium_mhz) { \ 		__asm __volatile("cli\n" \ 				 "movl (%2),%%eax\n" \ 				 "movl %%eax,(%1)\n" \ 				 "movl 4(%2),%%eax\n" \ 				 "movl %%eax,4(%1)\n" \ 				 "movl $0x10,%%ecx\n" \ 				 "xorl %%eax,%%eax\n" \ 				 "movl %%eax,%%edx\n" \ 				 ".byte 0x0f, 0x30\n" \ 				 "sti\n" \ 				 "#%0%1%2" \ 				 : "=m"(*otime)
comment|/* no outputs */
value|\ 				 : "c"(otime), "b"(ntime)
comment|/* fake input */
value|\ 				 : "ax", "cx", "dx"); \ 	} else { \ 		*(otime) = *(ntime); \ 	} \ 	} while(0)
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

begin_endif
endif|#
directive|endif
end_endif

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
name|statclock_disable
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|pentium_mhz
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

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

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

begin_decl_stmt
name|void
name|clkintr
name|__P
argument_list|(
operator|(
expr|struct
name|clockframe
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rtcintr
name|__P
argument_list|(
operator|(
expr|struct
name|clockframe
name|frame
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

