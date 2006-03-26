begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2006, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PMCLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PMCLOG_H_
end_define

begin_include
include|#
directive|include
file|<sys/pmc.h>
end_include

begin_enum
enum|enum
name|pmclog_type
block|{
comment|/* V1 ABI */
name|PMCLOG_TYPE_CLOSELOG
block|,
name|PMCLOG_TYPE_DROPNOTIFY
block|,
name|PMCLOG_TYPE_INITIALIZE
block|,
name|PMCLOG_TYPE_MAPPINGCHANGE
block|,
comment|/* unused in v1 */
name|PMCLOG_TYPE_PCSAMPLE
block|,
name|PMCLOG_TYPE_PMCALLOCATE
block|,
name|PMCLOG_TYPE_PMCATTACH
block|,
name|PMCLOG_TYPE_PMCDETACH
block|,
name|PMCLOG_TYPE_PROCCSW
block|,
name|PMCLOG_TYPE_PROCEXEC
block|,
name|PMCLOG_TYPE_PROCEXIT
block|,
name|PMCLOG_TYPE_PROCFORK
block|,
name|PMCLOG_TYPE_SYSEXIT
block|,
name|PMCLOG_TYPE_USERDATA
block|,
comment|/* 	 * V2 ABI 	 * 	 * The MAP_{IN,OUT} event types obsolete the MAPPING_CHANGE 	 * event type of the older (V1) ABI. 	 */
name|PMCLOG_TYPE_MAP_IN
block|,
name|PMCLOG_TYPE_MAP_OUT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMCLOG_MAPPING_INSERT
value|0x01
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|PMCLOG_MAPPING_DELETE
value|0x02
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/*  * A log entry descriptor comprises of a 32 bit header and a 64 bit  * time stamp followed by as many 32 bit words are required to record  * the event.  *  * Header field format:  *  *  31           24           16                                   0  *   +------------+------------+-----------------------------------+  *   |    MAGIC   |    TYPE    |               LENGTH              |  *   +------------+------------+-----------------------------------+  *  * MAGIC 	is the constant PMCLOG_HEADER_MAGIC.  * TYPE  	contains a value of type enum pmclog_type.  * LENGTH	contains the length of the event record, in bytes.  */
end_comment

begin_define
define|#
directive|define
name|PMCLOG_ENTRY_HEADER
define|\
value|uint32_t		pl_header;		\ 	uint32_t		pl_ts_sec;		\ 	uint32_t		pl_ts_nsec;
end_define

begin_comment
comment|/*  * The following structures are used to describe the size of each kind  * of log entry to sizeof().  To keep the compiler from adding  * padding, the fields of each structure are aligned to their natural  * boundaries, and the structures are marked as 'packed'.  *  * The actual reading and writing of the log file is always in terms  * of 4 byte quantities.  */
end_comment

begin_struct
struct|struct
name|pmclog_closelog
block|{
name|PMCLOG_ENTRY_HEADER
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_dropnotify
block|{
name|PMCLOG_ENTRY_HEADER
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_initialize
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_version
decl_stmt|;
comment|/* driver version */
name|uint32_t
name|pl_cpu
decl_stmt|;
comment|/* enum pmc_cputype */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_map_in
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pid
decl_stmt|;
name|uintfptr_t
name|pl_start
decl_stmt|;
comment|/* 8 byte aligned */
name|char
name|pl_pathname
index|[
name|PATH_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_map_out
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pid
decl_stmt|;
name|uintfptr_t
name|pl_start
decl_stmt|;
comment|/* 8 byte aligned */
name|uintfptr_t
name|pl_end
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_pcsample
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pid
decl_stmt|;
name|uintfptr_t
name|pl_pc
decl_stmt|;
comment|/* 8 byte aligned */
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint32_t
name|pl_usermode
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_pmcallocate
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint32_t
name|pl_event
decl_stmt|;
name|uint32_t
name|pl_flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_pmcattach
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint32_t
name|pl_pid
decl_stmt|;
name|char
name|pl_pathname
index|[
name|PATH_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_pmcdetach
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint32_t
name|pl_pid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_proccsw
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint64_t
name|pl_value
decl_stmt|;
comment|/* keep 8 byte aligned */
name|uint32_t
name|pl_pid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_procexec
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pid
decl_stmt|;
name|uintfptr_t
name|pl_start
decl_stmt|;
comment|/* keep 8 byte aligned */
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|char
name|pl_pathname
index|[
name|PATH_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_procexit
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pmcid
decl_stmt|;
name|uint64_t
name|pl_value
decl_stmt|;
comment|/* keep 8 byte aligned */
name|uint32_t
name|pl_pid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_procfork
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_oldpid
decl_stmt|;
name|uint32_t
name|pl_newpid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_sysexit
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_pid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pmclog_userdata
block|{
name|PMCLOG_ENTRY_HEADER
name|uint32_t
name|pl_userdata
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|pmclog_entry
block|{
comment|/* only used to size scratch areas */
name|struct
name|pmclog_closelog
name|pl_cl
decl_stmt|;
name|struct
name|pmclog_dropnotify
name|pl_dn
decl_stmt|;
name|struct
name|pmclog_initialize
name|pl_i
decl_stmt|;
name|struct
name|pmclog_map_in
name|pl_mi
decl_stmt|;
name|struct
name|pmclog_map_out
name|pl_mo
decl_stmt|;
name|struct
name|pmclog_pcsample
name|pl_s
decl_stmt|;
name|struct
name|pmclog_pmcallocate
name|pl_a
decl_stmt|;
name|struct
name|pmclog_pmcattach
name|pl_t
decl_stmt|;
name|struct
name|pmclog_pmcdetach
name|pl_d
decl_stmt|;
name|struct
name|pmclog_proccsw
name|pl_c
decl_stmt|;
name|struct
name|pmclog_procexec
name|pl_x
decl_stmt|;
name|struct
name|pmclog_procexit
name|pl_e
decl_stmt|;
name|struct
name|pmclog_procfork
name|pl_f
decl_stmt|;
name|struct
name|pmclog_sysexit
name|pl_se
decl_stmt|;
name|struct
name|pmclog_userdata
name|pl_u
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|PMCLOG_HEADER_MAGIC
value|0xEEU
end_define

begin_define
define|#
directive|define
name|PMCLOG_HEADER_TO_LENGTH
parameter_list|(
name|H
parameter_list|)
define|\
value|((H)& 0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|PMCLOG_HEADER_TO_TYPE
parameter_list|(
name|H
parameter_list|)
define|\
value|(((H)& 0x00FF0000)>> 16)
end_define

begin_define
define|#
directive|define
name|PMCLOG_HEADER_TO_MAGIC
parameter_list|(
name|H
parameter_list|)
define|\
value|(((H)& 0xFF000000)>> 24)
end_define

begin_define
define|#
directive|define
name|PMCLOG_HEADER_CHECK_MAGIC
parameter_list|(
name|H
parameter_list|)
define|\
value|(PMCLOG_HEADER_TO_MAGIC(H) == PMCLOG_HEADER_MAGIC)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|int
name|pmclog_configure_log
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|,
name|int
name|_logfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmclog_deconfigure_log
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmclog_flush
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_closelog
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|po
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_dropnotify
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|po
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_map_in
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|po
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|uintfptr_t
name|start
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_map_out
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|po
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|uintfptr_t
name|start
parameter_list|,
name|uintfptr_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_pcsample
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|struct
name|pmc_sample
modifier|*
name|_ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_pmcallocate
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_pmcattach
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|pid_t
name|_pid
parameter_list|,
name|char
modifier|*
name|_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_pmcdetach
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_proccsw
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|,
name|pmc_value_t
name|_v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_procexec
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|,
name|pmc_id_t
name|_pmid
parameter_list|,
name|pid_t
name|_pid
parameter_list|,
name|uintfptr_t
name|_startaddr
parameter_list|,
name|char
modifier|*
name|_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_procexit
parameter_list|(
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_procfork
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|,
name|pid_t
name|_oldpid
parameter_list|,
name|pid_t
name|_newpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_process_sysexit
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|,
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmclog_process_userlog
parameter_list|(
name|struct
name|pmc_owner
modifier|*
name|_po
parameter_list|,
name|struct
name|pmc_op_writelog
modifier|*
name|_wl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmclog_shutdown
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
comment|/* _SYS_PMCLOG_H_ */
end_comment

end_unit

