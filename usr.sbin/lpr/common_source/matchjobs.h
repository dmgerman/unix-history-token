begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ------+---------+---------+---------+---------+---------+---------+---------*  * Copyright (c) 2002  - Garance Alistair Drosehn<gad@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation  * are those of the authors and should not be interpreted as representing  * official policies, either expressed or implied, of the FreeBSD Project  * or FreeBSD, Inc.  *  * ------+---------+---------+---------+---------+---------+---------+---------*  * $FreeBSD$  * ------+---------+---------+---------+---------+---------+---------+---------*  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * The "matcheduser" field is *only* valid during the call to the  * given "doentry()" routine, and is only set if the specification  * included a userid.  */
end_comment

begin_struct
struct|struct
name|jobspec
block|{
name|STAILQ_ENTRY
argument_list|(
argument|jobspec
argument_list|)
name|nextjs
expr_stmt|;
name|char
modifier|*
name|wantedhost
decl_stmt|;
name|char
modifier|*
name|wanteduser
decl_stmt|;
name|char
modifier|*
name|matcheduser
decl_stmt|;
comment|/* only valid for "doentry()" */
name|char
modifier|*
name|fmtoutput
decl_stmt|;
comment|/* set by format_jobspec() */
name|long
name|startnum
decl_stmt|;
name|long
name|endrange
decl_stmt|;
name|int
name|pluralfmt
decl_stmt|;
comment|/* boolean set by format_jobspec() */
name|uint
name|matchcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|jobspec_hdr
argument_list|,
name|jobspec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Format options for format_jobspec.  */
end_comment

begin_define
define|#
directive|define
name|FMTJS_TERSE
value|1
end_define

begin_comment
comment|/* user:jobrange@host */
end_comment

begin_define
define|#
directive|define
name|FMTJS_VERBOSE
value|2
end_define

begin_comment
comment|/* jobrange from user@host */
end_comment

begin_comment
comment|/*  * Options for scanq_jobspec.  *  * The caller must choose the order that entries should be scanned:  * 1) JSORDER: Matched jobs are processed (by calling the "doentry()"  *    routine) in the order that the user specified those jobs.  * 2) QORDER: Matched jobs are processed in the order that the jobs are  *    listed the queue.  This guarantees that the "doentry()" routine  *    will be called only once per job.  *  * There is a "job_matched" variable in struct jobqueue, which is used  * to make sure that the "doentry()" will only be called once for any  * given job in JSORDER processing.  The "doentry()" routine can turn  * that off, if it does want to be called multiple times when the job  * is matched by multiple specifiers.  *  * The JSORDER processing will also call the "doentry()" routine once  * after each scan of the queue, with the jobqueue set to null.  This  * provides a way for the caller to print out a summary message for  * each jobspec that was given.  */
end_comment

begin_define
define|#
directive|define
name|SCQ_JSORDER
value|0x0001
end_define

begin_comment
comment|/* follow the user-specified order */
end_comment

begin_define
define|#
directive|define
name|SCQ_QORDER
value|0x0002
end_define

begin_comment
comment|/* the order of jobs in the queue */
end_comment

begin_include
include|#
directive|include
file|"lp.cdefs.h"
end_include

begin_comment
comment|/* A cross-platform version of<sys/cdefs.h> */
end_comment

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|jobqueue
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|process_jqe
parameter_list|(
name|void
modifier|*
name|_myinfo
parameter_list|,
name|struct
name|jobqueue
modifier|*
name|_jq
parameter_list|,
name|struct
name|jobspec
modifier|*
name|_jspec
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|format_jobspec
parameter_list|(
name|struct
name|jobspec
modifier|*
name|_jspec
parameter_list|,
name|int
name|_fmt_wanted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_jobspec
parameter_list|(
name|struct
name|jobspec_hdr
modifier|*
name|_js_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanq_jobspec
parameter_list|(
name|int
name|_qitems
parameter_list|,
name|struct
name|jobqueue
modifier|*
modifier|*
name|_squeue
parameter_list|,
name|int
name|_sopts
parameter_list|,
name|struct
name|jobspec_hdr
modifier|*
name|_js_hdr
parameter_list|,
name|process_jqe
name|_doentry
parameter_list|,
name|void
modifier|*
name|_doentryinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_jobspec
parameter_list|(
name|char
modifier|*
name|_jobstr
parameter_list|,
name|struct
name|jobspec_hdr
modifier|*
name|_js_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

