begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_USERSDB_H
end_ifndef

begin_define
define|#
directive|define
name|_PAM_USERSDB_H
end_define

begin_comment
comment|/* $Id: pam_userdb.h,v 1.1.1.1 2000/06/20 22:12:09 agmorgan Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Header files */
end_comment

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_comment
comment|/* argument parsing */
end_comment

begin_define
define|#
directive|define
name|PAM_DEBUG_ARG
value|0x0001
end_define

begin_define
define|#
directive|define
name|PAM_ICASE_ARG
value|0x0002
end_define

begin_define
define|#
directive|define
name|PAM_DUMP_ARG
value|0x0004
end_define

begin_comment
comment|/* Useful macros */
end_comment

begin_define
define|#
directive|define
name|x_strdup
parameter_list|(
name|s
parameter_list|)
value|( (s) ? strdup(s):NULL )
end_define

begin_comment
comment|/* The name of the module we are compiling */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODULE_NAME
end_ifndef

begin_define
define|#
directive|define
name|MODULE_NAME
value|"pam_userdb"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MODULE_NAME */
end_comment

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|int
name|conversation
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAM_USERSDB_H */
end_comment

begin_comment
comment|/*  * Copyright (c) Cristian Gafton<gafton@redhat.com>, 1999  *                                              All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *  * THIS SOFTWARE IS PROVIDED `AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

end_unit

