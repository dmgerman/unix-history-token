begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2004 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amq.h,v 1.14.2.4 2004/01/06 03:15:16 ezk Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMQ_H
end_ifndef

begin_define
define|#
directive|define
name|_AMQ_H
end_define

begin_comment
comment|/*  * external definitions for building amq  */
end_comment

begin_function_decl
specifier|extern
name|voidp
name|amqproc_null_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_tree_p
modifier|*
name|amqproc_mnttree_1
parameter_list|(
name|amq_string
modifier|*
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|amqproc_umnt_1
parameter_list|(
name|amq_string
modifier|*
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_stats
modifier|*
name|amqproc_stats_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_tree_list
modifier|*
name|amqproc_export_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_setopt_1
parameter_list|(
name|amq_setopt
modifier|*
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_info_list
modifier|*
name|amqproc_getmntfs_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_mount_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_string
modifier|*
name|amqproc_getvers_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_getpid_1
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|CLIENT
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMQ_H */
end_comment

end_unit

