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

begin_define
define|#
directive|define
name|CLOCK_VECTOR
value|254
end_define

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

begin_decl_stmt
specifier|extern
name|uint64_t
name|ia64_clock_reload
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|itc_frequency
decl_stmt|;
end_decl_stmt

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

