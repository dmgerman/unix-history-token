begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *<security/pam_modules.h>  *   * $Id: pam_modules.h,v 1.8 1997/01/04 20:14:42 morgan Exp morgan $  * $FreeBSD$  *  * This header file documents the PAM SPI --- that is, interface  * between the PAM library and a PAM service library which is called  * by the PAM library.  *  * Note, the copyright information is at end of file.  *  * $Log: pam_modules.h,v $  * Revision 1.8  1997/01/04 20:14:42  morgan  * moved PAM_DATA_SILENT to _pam_types.h so applications can use it too  *  * Revision 1.7  1996/11/10 19:57:08  morgan  * pam_get_user prototype.  *  * Revision 1.6  1996/09/05 06:18:45  morgan  * added some data error_status masks, changed prototype for cleanup()  *  * Revision 1.5  1996/06/02 07:58:37  morgan  * altered the way in which modules obtain static prototypes for  * functions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_PAM_MODULES_H
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_PAM_MODULES_H
end_define

begin_comment
comment|/*  * Define either PAM_STATIC or PAM_DYNAMIC, based on whether PIC  * compilation is being used.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PIC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PAM_STATIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_STATIC
end_ifndef

begin_define
define|#
directive|define
name|PAM_DYNAMIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_STATIC
end_ifdef

begin_include
include|#
directive|include
file|<linker_set.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<security/_pam_types.h>
end_include

begin_comment
comment|/* Linux-PAM common defined types */
end_comment

begin_comment
comment|/* these defines are used by pam_set_item() and pam_get_item() and are  * in addition to those found in<security/_pam_types.h> */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK
value|6
end_define

begin_comment
comment|/* The authentication token (password) */
end_comment

begin_define
define|#
directive|define
name|PAM_OLDAUTHTOK
value|7
end_define

begin_comment
comment|/* The old authentication token */
end_comment

begin_comment
comment|/* -------------- The Linux-PAM Module PI ------------- */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_set_data
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|module_data_name
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|error_status
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_get_data
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|module_data_name
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_get_user
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_STATIC
end_ifdef

begin_define
define|#
directive|define
name|PAM_EXTERN
value|static
end_define

begin_struct
struct|struct
name|pam_module
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the module */
comment|/* These are function pointers to the module's key functions.  */
name|int
function_decl|(
modifier|*
name|pam_sm_authenticate
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pam_sm_setcred
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pam_sm_acct_mgmt
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pam_sm_open_session
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pam_sm_close_session
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pam_sm_chauthtok
function_decl|)
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_SM_AUTH
end_ifdef

begin_define
define|#
directive|define
name|PAM_SM_AUTH_ENTRY
value|pam_sm_authenticate
end_define

begin_define
define|#
directive|define
name|PAM_SM_SETCRED_ENTRY
value|pam_sm_setcred
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAM_SM_AUTH_ENTRY
value|NULL
end_define

begin_define
define|#
directive|define
name|PAM_SM_SETCRED_ENTRY
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_SM_ACCOUNT
end_ifdef

begin_define
define|#
directive|define
name|PAM_SM_ACCOUNT_ENTRY
value|pam_sm_acct_mgmt
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAM_SM_ACCOUNT_ENTRY
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_SM_SESSION
end_ifdef

begin_define
define|#
directive|define
name|PAM_SM_OPEN_SESSION_ENTRY
value|pam_sm_open_session
end_define

begin_define
define|#
directive|define
name|PAM_SM_CLOSE_SESSION_ENTRY
value|pam_sm_close_session
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAM_SM_OPEN_SESSION_ENTRY
value|NULL
end_define

begin_define
define|#
directive|define
name|PAM_SM_CLOSE_SESSION_ENTRY
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_SM_PASSWORD
end_ifdef

begin_define
define|#
directive|define
name|PAM_SM_PASSWORD_ENTRY
value|pam_sm_chauthtok
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAM_SM_PASSWORD_ENTRY
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAM_MODULE_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|static struct pam_module _pam_modstruct = {	\ 	name,					\ 	PAM_SM_AUTH_ENTRY,			\ 	PAM_SM_SETCRED_ENTRY,			\ 	PAM_SM_ACCOUNT_ENTRY,			\ 	PAM_SM_OPEN_SESSION_ENTRY,		\ 	PAM_SM_CLOSE_SESSION_ENTRY,		\ 	PAM_SM_PASSWORD_ENTRY			\     };						\     DATA_SET(_pam_static_modules, _pam_modstruct)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PAM_STATIC */
end_comment

begin_define
define|#
directive|define
name|PAM_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|PAM_MODULE_ENTRY
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_STATIC */
end_comment

begin_comment
comment|/* Lots of files include pam_modules.h that don't need these  * declared.  However, when they are declared static, they  * need to be defined later.  So we have to protect C files  * that include these without wanting these functions defined.. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|PAM_SM_AUTH
argument_list|)
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
end_if

begin_comment
comment|/* Authentication API's */
end_comment

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_authenticate
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*(defined(PAM_STATIC)&& defined(PAM_SM_AUTH)) 	 || !defined(PAM_STATIC)*/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|PAM_SM_ACCOUNT
argument_list|)
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
end_if

begin_comment
comment|/* Account Management API's */
end_comment

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_acct_mgmt
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*(defined(PAM_STATIC)&& defined(PAM_SM_ACCOUNT)) 	 || !defined(PAM_STATIC)*/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|PAM_SM_SESSION
argument_list|)
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
end_if

begin_comment
comment|/* Session Management API's */
end_comment

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_open_session
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_close_session
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*(defined(PAM_STATIC)&& defined(PAM_SM_SESSION)) 	 || !defined(PAM_STATIC)*/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|PAM_SM_PASSWORD
argument_list|)
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PAM_STATIC
argument_list|)
end_if

begin_comment
comment|/* Password Management API's */
end_comment

begin_function_decl
name|PAM_EXTERN
name|int
name|pam_sm_chauthtok
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*(defined(PAM_STATIC)&& defined(PAM_SM_PASSWORD)) 	 || !defined(PAM_STATIC)*/
end_comment

begin_comment
comment|/* The following two flags are for use across the Linux-PAM/module  * interface only. The Application is not permitted to use these  * tokens.  *  * The password service should only perform preliminary checks.  No  * passwords should be updated. */
end_comment

begin_define
define|#
directive|define
name|PAM_PRELIM_CHECK
value|0x4000
end_define

begin_comment
comment|/* The password service should update passwords Note: PAM_PRELIM_CHECK  * and PAM_UPDATE_AUTHTOK can not both be set simultaneously! */
end_comment

begin_define
define|#
directive|define
name|PAM_UPDATE_AUTHTOK
value|0x2000
end_define

begin_comment
comment|/*  * here are some proposed error status definitions for the  * 'error_status' argument used by the cleanup function associated  * with data items they should be logically OR'd with the error_status  * of the latest return from libpam -- new with .52 and positive  * impression from Sun although not official as of 1996/9/4 there are  * others in _pam_types.h -- they are for common module/app use.  */
end_comment

begin_define
define|#
directive|define
name|PAM_DATA_REPLACE
value|0x20000000
end_define

begin_comment
comment|/* used when replacing a data item */
end_comment

begin_comment
comment|/* take care of any compatibility issues */
end_comment

begin_include
include|#
directive|include
file|<security/_pam_compat.h>
end_include

begin_comment
comment|/* Copyright (C) Theodore Ts'o, 1996.  * Copyright (C) Andrew Morgan, 1996-8.  *                                                All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU General Public License, in which case the provisions of the  * GNU GPL are required INSTEAD OF the above restrictions.  (This  * clause is necessary due to a potential bad interaction between the  * GNU GPL and the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SECURITY_PAM_MODULES_H */
end_comment

end_unit

