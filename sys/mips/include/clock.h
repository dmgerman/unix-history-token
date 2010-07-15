begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Garrett Wollman, September 1994.  * This file is in the public domain.  * Kernel interface to machine-dependent clock driver.  *  *	JNPR: clock.h,v 1.6.2.1 2007/08/29 09:36:05 girish  *	from: src/sys/alpha/include/clock.h,v 1.5 1999/12/29 04:27:55 peter  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cpu_clock
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|uint32_t
name|clockintr
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wall_cmos_clock
value|0
end_define

begin_define
define|#
directive|define
name|adjkerntz
value|0
end_define

begin_comment
comment|/*  * Default is to assume a CPU pipeline clock of 100Mhz, and  * that CP0_COUNT increments every 2 cycles.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_DEFAULT_HZ
value|(100 * 1000 * 1000)
end_define

begin_function_decl
name|void
name|mips_timer_early_init
parameter_list|(
name|uint64_t
name|clock_hz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_timer_init_params
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint64_t
name|counter_freq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clocks_running
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The 'platform_timecounter' pointer may be used to register a  * platform-specific timecounter.  *  * A default timecounter based on the CP0 COUNT register is always registered.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timecounter
modifier|*
name|platform_timecounter
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

begin_comment
comment|/* !_MACHINE_CLOCK_H_ */
end_comment

end_unit

