begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003,2004 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMC_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMC_H_
end_define

begin_include
include|#
directive|include
file|<sys/pmc.h>
end_include

begin_comment
comment|/*  * Driver statistics.  */
end_comment

begin_struct
struct|struct
name|pmc_driverstats
block|{
name|int
name|pm_intr_ignored
decl_stmt|;
comment|/* #interrupts ignored */
name|int
name|pm_intr_processed
decl_stmt|;
comment|/* #interrupts processed */
name|int
name|pm_intr_bufferfull
decl_stmt|;
comment|/* #interrupts with ENOSPC */
name|int
name|pm_syscalls
decl_stmt|;
comment|/* #syscalls */
name|int
name|pm_syscall_errors
decl_stmt|;
comment|/* #syscalls with errors */
name|int
name|pm_buffer_requests
decl_stmt|;
comment|/* #buffer requests */
name|int
name|pm_buffer_requests_failed
decl_stmt|;
comment|/* #failed buffer requests */
name|int
name|pm_log_sweeps
decl_stmt|;
comment|/* #sample buffer processing passes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * CPU information.  */
end_comment

begin_struct
struct|struct
name|pmc_cpuinfo
block|{
name|enum
name|pmc_cputype
name|pm_cputype
decl_stmt|;
comment|/* the kind of CPU */
name|uint32_t
name|pm_ncpu
decl_stmt|;
comment|/* number of CPUs */
name|uint32_t
name|pm_npmc
decl_stmt|;
comment|/* #PMCs per CPU */
name|uint32_t
name|pm_nclass
decl_stmt|;
comment|/* #classes of PMCs */
name|struct
name|pmc_classinfo
name|pm_classes
index|[
name|PMC_CLASS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Current PMC state.  */
end_comment

begin_struct
struct|struct
name|pmc_pmcinfo
block|{
name|int32_t
name|pm_cpu
decl_stmt|;
comment|/* CPU number */
name|struct
name|pmc_info
name|pm_pmcs
index|[]
decl_stmt|;
comment|/* NPMC structs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|int
name|pmc_allocate
parameter_list|(
specifier|const
name|char
modifier|*
name|_ctrspec
parameter_list|,
name|enum
name|pmc_mode
name|_mode
parameter_list|,
name|uint32_t
name|_flags
parameter_list|,
name|int
name|_cpu
parameter_list|,
name|pmc_id_t
modifier|*
name|_pmcid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_attach
parameter_list|(
name|pmc_id_t
name|_pmcid
parameter_list|,
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_capabilities
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|uint32_t
modifier|*
name|_caps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_configure_logfile
parameter_list|(
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_flush_logfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_detach
parameter_list|(
name|pmc_id_t
name|_pmcid
parameter_list|,
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_disable
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_enable
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_get_driver_stats
parameter_list|(
name|struct
name|pmc_driverstats
modifier|*
name|_gms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_get_msr
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|uint32_t
modifier|*
name|_msr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_read
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|pmc_value_t
modifier|*
name|_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_release
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_rw
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|pmc_value_t
name|_newvalue
parameter_list|,
name|pmc_value_t
modifier|*
name|_oldvalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_set
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|pmc_value_t
name|_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_start
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_stop
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_width
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|uint32_t
modifier|*
name|_width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_write
parameter_list|(
name|pmc_id_t
name|_pmc
parameter_list|,
name|pmc_value_t
name|_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_writelog
parameter_list|(
name|uint32_t
name|_udata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_ncpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_npmc
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_cpuinfo
parameter_list|(
specifier|const
name|struct
name|pmc_cpuinfo
modifier|*
modifier|*
name|_cpu_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_pmcinfo
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|struct
name|pmc_pmcinfo
modifier|*
modifier|*
name|_pmc_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_capability
parameter_list|(
name|uint32_t
name|_c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_class
parameter_list|(
name|enum
name|pmc_class
name|_pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_cputype
parameter_list|(
name|enum
name|pmc_cputype
name|_cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_disposition
parameter_list|(
name|enum
name|pmc_disp
name|_pd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_event
parameter_list|(
name|enum
name|pmc_event
name|_pe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_mode
parameter_list|(
name|enum
name|pmc_mode
name|_pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmc_name_of_state
parameter_list|(
name|enum
name|pmc_state
name|_ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_event_names_of_class
parameter_list|(
name|enum
name|pmc_class
name|_cl
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
modifier|*
name|_eventnames
parameter_list|,
name|int
modifier|*
name|_nevents
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

