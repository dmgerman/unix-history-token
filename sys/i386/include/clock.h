begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  *  *	$Id: clock.h,v 1.33 1998/02/25 02:20:30 bde Exp $  */
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
name|KERNEL
end_ifdef

begin_comment
comment|/*  * i386 to clock driver interface.  * XXX large parts of the driver and its interface are misplaced.  */
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
name|tsc_freq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wall_cmos_clock
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|apic_8254_intr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

