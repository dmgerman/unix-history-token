begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<libpmcstat.h>
end_include

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
value|256
end_define

begin_comment
comment|/* file virtual height */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DISPLAY_WIDTH
value|1024
end_define

begin_comment
comment|/* file virtual width */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_BUFFER_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|DEFAULT_CALLGRAPH_DEPTH
value|16
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
name|PMCSTAT_LDD_COMMAND
value|"/usr/bin/ldd"
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PRINT_ENTRY
parameter_list|(
name|T
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 		(void) fprintf(args.pa_printfile, "%-9s", T);		\ 		(void) fprintf(args.pa_printfile, " "  __VA_ARGS__);	\ 		(void) fprintf(args.pa_printfile, "\n");		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_CALLGRAPH
value|1
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_GPROF
value|2
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_ANNOTATE
value|3
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_CALLTREE
value|4
end_define

begin_define
define|#
directive|define
name|PMCSTAT_PL_ANNOTATE_CG
value|5
end_define

begin_define
define|#
directive|define
name|PMCSTAT_TOP_DELTA
value|0
end_define

begin_define
define|#
directive|define
name|PMCSTAT_TOP_ACCUM
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_displayheight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current terminal height */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_displaywidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current terminal width */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmcstat_args
name|args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command line args */
end_comment

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
name|void
name|pmcstat_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_find_targets
parameter_list|(
specifier|const
name|char
modifier|*
name|_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_kill_process
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_headers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_print_pmcs
parameter_list|(
name|void
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
name|pmcstat_start_pmcs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_process_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_keypress_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_display_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_pluginconfigure_log
parameter_list|(
name|char
modifier|*
name|_opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_topexit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_log_shutdown_logging
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_log_initialize_logging
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
comment|/* _PMCSTAT_H_ */
end_comment

end_unit

