begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  *  * $FreeBSD$  */
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
name|_KERNEL
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
name|tsc_is_broken
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

begin_function_decl
name|int
name|acquire_timer0
parameter_list|(
name|int
name|rate
parameter_list|,
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|struct
name|clockframe
modifier|*
name|frame
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acquire_timer2
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|release_timer0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|release_timer2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_function_decl
name|int
name|rtcin
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|acquire_timer1
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|release_timer1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|sysbeep
parameter_list|(
name|int
name|pitch
parameter_list|,
name|int
name|period
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timer_restore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_MACHINE_CLOCK_H_ */
end_comment

end_unit

