begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bsm/audit_filter.h#2 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_FILTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_FILTER_H_
end_define

begin_comment
comment|/*  * Module interface for audit filter modules.  *  * audit_filter_attach_t - filter module is being attached with arguments  * audit_filter_reinit_t - arguments to module have changed  * audit_filter_record_t - present parsed record to filter module, with  *                         receipt time  * audit_filter_bsmrecord_t - present bsm format record to filter module,  *                            with receipt time  * audit_filter_destach_t - filter module is being detached  *  * There may be many instances of the same filter, identified by the instance  * void pointer maintained by the filter instance.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|audit_filter_attach_t
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|instance
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|audit_filter_reinit_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|instance
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|audit_filter_record_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|instance
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|,
name|int
name|token_count
parameter_list|,
specifier|const
name|tokenstr_t
name|tok
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|audit_filter_bsmrecord_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|instance
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|audit_filter_detach_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|instance
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Values to be returned by audit_filter_init_t.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_FILTER_SUCCESS
value|(0)
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_FAILURE
value|(-1)
end_define

begin_comment
comment|/*  * Standard name for filter module initialization functions, which will be  * found using dlsym().  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_FILTER_ATTACH
value|audit_filter_attach
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_REINIT
value|audit_filter_reinit
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_RECORD
value|audit_filter_record
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_BSMRECORD
value|audit_filter_bsmrecord
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_DETACH
value|audit_filter_detach
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_ATTACH_STRING
value|"audit_filter_attach"
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_REINIT_STRING
value|"audit_filter_reinit"
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_RECORD_STRING
value|"audit_filter_record"
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_BSMRECORD_STRING
value|"audit_filter_bsmrecord"
end_define

begin_define
define|#
directive|define
name|AUDIT_FILTER_DETACH_STRING
value|"audit_filter_detach"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_FILTER_H_ */
end_comment

end_unit

