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
name|int
name|adjkerntz
decl_stmt|;
end_decl_stmt

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
name|release_timer2
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CLOCK_H_ */
end_comment

end_unit

