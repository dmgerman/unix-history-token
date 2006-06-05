begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/auditfilterd/auditfilterd.h#3 $  */
end_comment

begin_define
define|#
directive|define
name|AUDITFILTERD_CONFFILE
value|"/etc/security/audit_filter"
end_define

begin_define
define|#
directive|define
name|AUDITFILTERD_PIPEFILE
value|"/dev/auditpipe"
end_define

begin_comment
comment|/*  * Limit on the number of arguments that can appear in an audit_filterd  * configuration line.  */
end_comment

begin_define
define|#
directive|define
name|AUDITFILTERD_CONF_MAXARGS
value|256
end_define

begin_comment
comment|/*  * Data structure description each instantiated module.  */
end_comment

begin_struct
struct|struct
name|auditfilter_module
block|{
comment|/* 	 * Fields from configuration file and dynamic linker. 	 */
name|char
modifier|*
name|am_modulename
decl_stmt|;
name|char
modifier|*
name|am_arg_buffer
decl_stmt|;
name|int
name|am_argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|am_argv
decl_stmt|;
name|void
modifier|*
name|am_dlhandle
decl_stmt|;
comment|/* 	 * Fields provided by or extracted from the module. 	 */
name|void
modifier|*
name|am_instance
decl_stmt|;
name|audit_filter_attach_t
name|am_attach
decl_stmt|;
name|audit_filter_reinit_t
name|am_reinit
decl_stmt|;
name|audit_filter_record_t
name|am_record
decl_stmt|;
name|audit_filter_bsmrecord_t
name|am_bsmrecord
decl_stmt|;
name|audit_filter_detach_t
name|am_detach
decl_stmt|;
comment|/* 	 * Fields for maintaining the list of modules. 	 */
name|TAILQ_ENTRY
argument_list|(
argument|auditfilter_module
argument_list|)
name|am_list
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|auditfilter_module_list
argument_list|,
name|auditfilter_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * List of currently registered modules.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|auditfilter_module_list
name|filter_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function definitions.  */
end_comment

begin_function_decl
name|int
name|auditfilterd_conf
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auditfilterd_conf_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

