begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2006, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMCSTAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMCSTAT_H_
end_define

begin_define
define|#
directive|define
name|FLAG_HAS_PID
value|0x00000001
end_define

begin_comment
comment|/* explicit pid */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_WAIT_INTERVAL
value|0x00000002
end_define

begin_comment
comment|/* -w secs */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_OUTPUT_LOGFILE
value|0x00000004
end_define

begin_comment
comment|/* -O file or pipe */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_COMMANDLINE
value|0x00000008
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_SAMPLING_PMCS
value|0x00000010
end_define

begin_comment
comment|/* -S or -P */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_COUNTING_PMCS
value|0x00000020
end_define

begin_comment
comment|/* -s or -p */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_PROCESS_PMCS
value|0x00000040
end_define

begin_comment
comment|/* -P or -p */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_SYSTEM_PMCS
value|0x00000080
end_define

begin_comment
comment|/* -S or -s */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_PIPE
value|0x00000100
end_define

begin_comment
comment|/* implicit log */
end_comment

begin_define
define|#
directive|define
name|FLAG_READ_LOGFILE
value|0x00000200
end_define

begin_comment
comment|/* -R file */
end_comment

begin_define
define|#
directive|define
name|FLAG_DO_GPROF
value|0x00000400
end_define

begin_comment
comment|/* -g */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_SAMPLESDIR
value|0x00000800
end_define

begin_comment
comment|/* -D dir */
end_comment

begin_define
define|#
directive|define
name|FLAG_HAS_KERNELPATH
value|0x00001000
end_define

begin_comment
comment|/* -k kernel */
end_comment

begin_define
define|#
directive|define
name|FLAG_DO_PRINT
value|0x00002000
end_define

begin_comment
comment|/* -o */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SAMPLE_COUNT
value|65536
end_define

begin_define
define|#
directive|define
name|DEFAULT_WAIT_INTERVAL
value|5.0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISPLAY_HEIGHT
value|23
end_define

begin_define
define|#
directive|define
name|DEFAULT_BUFFER_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|PRINT_HEADER_PREFIX
value|"# "
end_define

begin_define
define|#
directive|define
name|READPIPEFD
value|0
end_define

begin_define
define|#
directive|define
name|WRITEPIPEFD
value|1
end_define

begin_define
define|#
directive|define
name|NPIPEFD
value|2
end_define

begin_define
define|#
directive|define
name|NSOCKPAIRFD
value|2
end_define

begin_define
define|#
directive|define
name|PARENTSOCKET
value|0
end_define

begin_define
define|#
directive|define
name|CHILDSOCKET
value|1
end_define

begin_define
define|#
directive|define
name|PMCSTAT_OPEN_FOR_READ
value|0
end_define

begin_define
define|#
directive|define
name|PMCSTAT_OPEN_FOR_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|PMCSTAT_DEFAULT_NW_HOST
value|"localhost"
end_define

begin_define
define|#
directive|define
name|PMCSTAT_DEFAULT_NW_PORT
value|"9000"
end_define

begin_define
define|#
directive|define
name|PMCSTAT_NHASH
value|256
end_define

begin_define
define|#
directive|define
name|PMCSTAT_HASH_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|PMCSTAT_LDD_COMMAND
value|"/usr/bin/ldd"
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PRINT_ENTRY
parameter_list|(
name|A
parameter_list|,
name|T
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 		fprintf((A)->pa_printfile, "%-8s", T);			\ 		fprintf((A)->pa_printfile, " "  __VA_ARGS__);		\ 		fprintf((A)->pa_printfile, "\n");			\ 	} while (0)
end_define

begin_enum
enum|enum
name|pmcstat_state
block|{
name|PMCSTAT_FINISHED
init|=
literal|0
block|,
name|PMCSTAT_EXITING
init|=
literal|1
block|,
name|PMCSTAT_RUNNING
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pmcstat_ev
block|{
name|STAILQ_ENTRY
argument_list|(
argument|pmcstat_ev
argument_list|)
name|ev_next
expr_stmt|;
name|int
name|ev_count
decl_stmt|;
comment|/* associated count if in sampling mode */
name|uint32_t
name|ev_cpu
decl_stmt|;
comment|/* cpus for this event */
name|int
name|ev_cumulative
decl_stmt|;
comment|/* show cumulative counts */
name|int
name|ev_flags
decl_stmt|;
comment|/* PMC_F_* */
name|int
name|ev_fieldskip
decl_stmt|;
comment|/* #leading spaces */
name|int
name|ev_fieldwidth
decl_stmt|;
comment|/* print width */
name|enum
name|pmc_mode
name|ev_mode
decl_stmt|;
comment|/* desired mode */
name|char
modifier|*
name|ev_name
decl_stmt|;
comment|/* (derived) event name */
name|pmc_id_t
name|ev_pmcid
decl_stmt|;
comment|/* allocated ID */
name|pmc_value_t
name|ev_saved
decl_stmt|;
comment|/* for incremental counts */
name|char
modifier|*
name|ev_spec
decl_stmt|;
comment|/* event specification */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmcstat_args
block|{
name|int
name|pa_flags
decl_stmt|;
comment|/* argument flags */
name|int
name|pa_required
decl_stmt|;
comment|/* required features */
name|int
name|pa_verbosity
decl_stmt|;
comment|/* verbosity level */
name|pid_t
name|pa_pid
decl_stmt|;
comment|/* attached to pid */
name|FILE
modifier|*
name|pa_printfile
decl_stmt|;
comment|/* where to send printed output */
name|int
name|pa_logfd
decl_stmt|;
comment|/* output log file */
name|char
modifier|*
name|pa_inputpath
decl_stmt|;
comment|/* path to input log */
name|char
modifier|*
name|pa_outputpath
decl_stmt|;
comment|/* path to output log */
name|void
modifier|*
name|pa_logparser
decl_stmt|;
comment|/* log file parser */
specifier|const
name|char
modifier|*
name|pa_fsroot
decl_stmt|;
comment|/* FS root where executables reside */
name|char
modifier|*
name|pa_kernel
decl_stmt|;
comment|/* pathname of the kernel */
specifier|const
name|char
modifier|*
name|pa_samplesdir
decl_stmt|;
comment|/* directory for profile files */
specifier|const
name|char
modifier|*
name|pa_mapfilename
decl_stmt|;
comment|/* mapfile name */
name|double
name|pa_interval
decl_stmt|;
comment|/* printing interval in seconds */
name|int
name|pa_argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|pa_argv
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pmcstat_ev
argument_list|)
name|pa_head
expr_stmt|;
block|}
name|args
struct|;
end_struct

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
name|void
name|pmcstat_attach_pmcs
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_cleanup
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_clone_event_descriptor
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|,
name|struct
name|pmcstat_ev
modifier|*
name|_ev
parameter_list|,
name|uint32_t
name|_cpumask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_close_log
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_create_process
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_initialize_logging
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_open_log
parameter_list|(
specifier|const
name|char
modifier|*
name|_p
parameter_list|,
name|int
name|_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_counters
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_headers
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_pmcs
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_show_usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_shutdown_logging
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_start_pmcs
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_start_process
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_process_log
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pmcstat_get_cpumask
parameter_list|(
specifier|const
name|char
modifier|*
name|_a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMCSTAT_H_ */
end_comment

end_unit

