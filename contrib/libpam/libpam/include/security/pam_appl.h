begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *<security/pam_appl.h>  *   * This header file collects definitions for the PAM API --- that is,  * public interface between the PAM library and an application program  * that wishes to use it.  *  * Note, the copyright information is at end of file.  * $FreeBSD$  *  * Created: 15-Jan-96 by TYT  * Last modified: 1996/3/5 by AGM  *  * $Log: pam_appl.h,v $  * Revision 1.5  1996/11/10 19:56:11  morgan  * minor prototype change  *  * Revision 1.4  1996/03/16 22:38:17  morgan  * made all of the pam_start input arguments constant  *  * Revision 1.3  1996/03/16 20:22:59  morgan  * changed name comment at top of file.  *  * Revision 1.2  1996/03/09 20:39:06  morgan  * added RCS information  *  *  * $Id: pam_appl.h,v 1.5 1996/11/10 19:56:11 morgan Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_PAM_APPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_PAM_APPL_H
end_define

begin_include
include|#
directive|include
file|<security/_pam_types.h>
end_include

begin_comment
comment|/* Linux-PAM common defined types */
end_comment

begin_comment
comment|/* -------------- The Linux-PAM Framework layer API ------------- */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_start
parameter_list|(
specifier|const
name|char
modifier|*
name|service_name
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|struct
name|pam_conv
modifier|*
name|pam_conversation
parameter_list|,
name|pam_handle_t
modifier|*
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_end
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|pam_status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Authentication API's */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_authenticate
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Account Management API's */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_acct_mgmt
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Session Management API's */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_open_session
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_close_session
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Password Management API's */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_chauthtok
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* take care of any compatibility issues */
end_comment

begin_include
include|#
directive|include
file|<security/_pam_compat.h>
end_include

begin_comment
comment|/*  * Copyright Theodore Ts'o, 1996.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SECURITY_PAM_APPL_H */
end_comment

end_unit

