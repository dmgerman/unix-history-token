begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Nate Lawson (SDG)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CPU_H_
end_define

begin_comment
comment|/*  * CPU device support.  */
end_comment

begin_define
define|#
directive|define
name|CPU_IVAR_PCPU
value|1
end_define

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|pcpu
operator|*
name|cpu_get_pcpu
argument_list|(
argument|device_t dev
argument_list|)
block|{
name|uintptr_t
name|v
operator|=
literal|0
block|;
name|BUS_READ_IVAR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|CPU_IVAR_PCPU
argument_list|,
operator|&
name|v
argument_list|)
block|;
return|return
operator|(
operator|(
expr|struct
name|pcpu
operator|*
operator|)
name|v
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * CPU frequency control interface.  */
end_comment

begin_comment
comment|/* Each driver's CPU frequency setting is exported in this format. */
end_comment

begin_struct
struct|struct
name|cf_setting
block|{
name|int
name|freq
decl_stmt|;
comment|/* Processor clock in Mhz or percent (in 100ths.) */
name|int
name|volts
decl_stmt|;
comment|/* Voltage in mV. */
name|int
name|power
decl_stmt|;
comment|/* Power consumed in mW. */
name|int
name|lat
decl_stmt|;
comment|/* Transition latency in us. */
name|device_t
name|dev
decl_stmt|;
comment|/* Driver providing this setting. */
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum number of settings a given driver can have. */
end_comment

begin_define
define|#
directive|define
name|MAX_SETTINGS
value|24
end_define

begin_comment
comment|/* A combination of settings is a level. */
end_comment

begin_struct
struct|struct
name|cf_level
block|{
name|struct
name|cf_setting
name|total_set
decl_stmt|;
name|struct
name|cf_setting
name|abs_set
decl_stmt|;
name|struct
name|cf_setting
name|rel_set
index|[
name|MAX_SETTINGS
index|]
decl_stmt|;
name|int
name|rel_count
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cf_level
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cf_level_lst
argument_list|,
name|cf_level
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Drivers should set all unknown values to this. */
end_comment

begin_define
define|#
directive|define
name|CPUFREQ_VAL_UNKNOWN
value|(-1)
end_define

begin_comment
comment|/*  * Every driver offers a type of CPU control.  Absolute levels are mutually  * exclusive while relative levels modify the current absolute level.  There  * may be multiple absolute and relative drivers available on a given  * system.  *  * For example, consider a system with two absolute drivers that provide  * frequency settings of 100, 200 and 300, 400 and a relative driver that  * provides settings of 50%, 100%.  The cpufreq core would export frequency  * levels of 50, 100, 150, 200, 300, 400.  */
end_comment

begin_define
define|#
directive|define
name|CPUFREQ_TYPE_RELATIVE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CPUFREQ_TYPE_ABSOLUTE
value|(1<<1)
end_define

begin_comment
comment|/*  * When setting a level, the caller indicates the priority of this request.  * Priorities determine, among other things, whether a level can be  * overridden by other callers.  For example, if the user sets a level but  * the system thermal driver needs to override it for emergency cooling,  * the driver would use a higher priority.  Once the event has passed, the  * driver would call cpufreq to resume any previous level.  */
end_comment

begin_define
define|#
directive|define
name|CPUFREQ_PRIO_HIGHEST
value|1000000
end_define

begin_define
define|#
directive|define
name|CPUFREQ_PRIO_KERN
value|1000
end_define

begin_define
define|#
directive|define
name|CPUFREQ_PRIO_USER
value|100
end_define

begin_define
define|#
directive|define
name|CPUFREQ_PRIO_LOWEST
value|0
end_define

begin_comment
comment|/*  * Register and unregister a driver with the cpufreq core.  Once a driver  * is registered, it must support calls to its CPUFREQ_GET, CPUFREQ_GET_LEVEL,  * and CPUFREQ_SET methods.  It must also unregister before returning from  * its DEVICE_DETACH method.  */
end_comment

begin_function_decl
name|int
name|cpufreq_register
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpufreq_unregister
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allow values to be +/- a bit since sometimes we have to estimate. */
end_comment

begin_define
define|#
directive|define
name|CPUFREQ_CMP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(abs((x) - (y))< 25)
end_define

begin_comment
comment|/*  * Machine-dependent functions.  */
end_comment

begin_comment
comment|/* Estimate the current clock rate for the given CPU id. */
end_comment

begin_function_decl
name|int
name|cpu_est_clockrate
parameter_list|(
name|int
name|cpu_id
parameter_list|,
name|uint64_t
modifier|*
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CPU_H_ */
end_comment

end_unit

