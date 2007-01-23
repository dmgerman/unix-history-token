begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  *  * $FreeBSD$  */
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
name|clkintr_pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pscnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|psdiv
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
name|uint64_t
name|tsc_freq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tsc_is_broken
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|i8254_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Driver to clock driver interface.  */
end_comment

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
name|release_timer2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtcin
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|init_TSC
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_TSC_tc
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

