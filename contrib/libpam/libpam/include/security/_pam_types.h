begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *<security/_pam_types.h>  *  * $Id: _pam_types.h,v 1.10 1997/04/05 06:52:50 morgan Exp morgan $  * $FreeBSD$  *  * This file defines all of the types common to the Linux-PAM library  * applications and modules.  *  * Note, the copyright+license information is at end of file.  *  * Created: 1996/3/5 by AGM  *  * $Log$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY__PAM_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY__PAM_TYPES_H
end_define

begin_comment
comment|/*  * include local definition for POSIX - NULL  */
end_comment

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_comment
comment|/* This is a blind structure; users aren't allowed to see inside a  * pam_handle_t, so we don't define struct pam_handle here.  This is  * defined in a file private to the PAM library.  (i.e., it's private  * to PAM service modules, too!)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pam_handle
name|pam_handle_t
typedef|;
end_typedef

begin_comment
comment|/* ----------------- The Linux-PAM return values ------------------ */
end_comment

begin_define
define|#
directive|define
name|PAM_SUCCESS
value|0
end_define

begin_comment
comment|/* Successful function return */
end_comment

begin_define
define|#
directive|define
name|PAM_OPEN_ERR
value|1
end_define

begin_comment
comment|/* dlopen() failure when dynamically */
end_comment

begin_comment
comment|/* loading a service module */
end_comment

begin_define
define|#
directive|define
name|PAM_SYMBOL_ERR
value|2
end_define

begin_comment
comment|/* Symbol not found */
end_comment

begin_define
define|#
directive|define
name|PAM_SERVICE_ERR
value|3
end_define

begin_comment
comment|/* Error in service module */
end_comment

begin_define
define|#
directive|define
name|PAM_SYSTEM_ERR
value|4
end_define

begin_comment
comment|/* System error */
end_comment

begin_define
define|#
directive|define
name|PAM_BUF_ERR
value|5
end_define

begin_comment
comment|/* Memory buffer error */
end_comment

begin_define
define|#
directive|define
name|PAM_PERM_DENIED
value|6
end_define

begin_comment
comment|/* Permission denied */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTH_ERR
value|7
end_define

begin_comment
comment|/* Authentication failure */
end_comment

begin_define
define|#
directive|define
name|PAM_CRED_INSUFFICIENT
value|8
end_define

begin_comment
comment|/* Can not access authentication data */
end_comment

begin_comment
comment|/* due to insufficient credentials */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHINFO_UNAVAIL
value|9
end_define

begin_comment
comment|/* Underlying authentication service */
end_comment

begin_comment
comment|/* can not retrieve authenticaiton */
end_comment

begin_comment
comment|/* information  */
end_comment

begin_define
define|#
directive|define
name|PAM_USER_UNKNOWN
value|10
end_define

begin_comment
comment|/* User not known to the underlying */
end_comment

begin_comment
comment|/* authenticaiton module */
end_comment

begin_define
define|#
directive|define
name|PAM_MAXTRIES
value|11
end_define

begin_comment
comment|/* An authentication service has */
end_comment

begin_comment
comment|/* maintained a retry count which has */
end_comment

begin_comment
comment|/* been reached.  No further retries */
end_comment

begin_comment
comment|/* should be attempted */
end_comment

begin_define
define|#
directive|define
name|PAM_NEW_AUTHTOK_REQD
value|12
end_define

begin_comment
comment|/* New authentication token required. */
end_comment

begin_comment
comment|/* This is normally returned if the */
end_comment

begin_comment
comment|/* machine security policies require */
end_comment

begin_comment
comment|/* that the password should be changed */
end_comment

begin_comment
comment|/* beccause the password is NULL or it */
end_comment

begin_comment
comment|/* has aged */
end_comment

begin_define
define|#
directive|define
name|PAM_ACCT_EXPIRED
value|13
end_define

begin_comment
comment|/* User account has expired */
end_comment

begin_define
define|#
directive|define
name|PAM_SESSION_ERR
value|14
end_define

begin_comment
comment|/* Can not make/remove an entry for */
end_comment

begin_comment
comment|/* the specified session */
end_comment

begin_define
define|#
directive|define
name|PAM_CRED_UNAVAIL
value|15
end_define

begin_comment
comment|/* Underlying authentication service */
end_comment

begin_comment
comment|/* can not retrieve user credentials */
end_comment

begin_comment
comment|/* unavailable */
end_comment

begin_define
define|#
directive|define
name|PAM_CRED_EXPIRED
value|16
end_define

begin_comment
comment|/* User credentials expired */
end_comment

begin_define
define|#
directive|define
name|PAM_CRED_ERR
value|17
end_define

begin_comment
comment|/* Failure setting user credentials */
end_comment

begin_define
define|#
directive|define
name|PAM_NO_MODULE_DATA
value|18
end_define

begin_comment
comment|/* No module specific data is present */
end_comment

begin_define
define|#
directive|define
name|PAM_CONV_ERR
value|19
end_define

begin_comment
comment|/* Conversation error */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK_ERR
value|20
end_define

begin_comment
comment|/* Authentication token manipulation error */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK_RECOVER_ERR
value|21
end_define

begin_comment
comment|/* Authentication information */
end_comment

begin_comment
comment|/* cannot be recovered */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK_LOCK_BUSY
value|22
end_define

begin_comment
comment|/* Authentication token lock busy */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK_DISABLE_AGING
value|23
end_define

begin_comment
comment|/* Authentication token aging disabled */
end_comment

begin_define
define|#
directive|define
name|PAM_TRY_AGAIN
value|24
end_define

begin_comment
comment|/* Preliminary check by password service */
end_comment

begin_define
define|#
directive|define
name|PAM_IGNORE
value|25
end_define

begin_comment
comment|/* Ingore underlying account module */
end_comment

begin_comment
comment|/* regardless of whether the control */
end_comment

begin_comment
comment|/* flag is required, optional, or sufficient */
end_comment

begin_define
define|#
directive|define
name|PAM_ABORT
value|26
end_define

begin_comment
comment|/* Critical error (?module fail now request) */
end_comment

begin_define
define|#
directive|define
name|PAM_AUTHTOK_EXPIRED
value|27
end_define

begin_comment
comment|/* user's authentication token has expired */
end_comment

begin_define
define|#
directive|define
name|PAM_MODULE_UNKNOWN
value|28
end_define

begin_comment
comment|/* module is not known */
end_comment

begin_define
define|#
directive|define
name|PAM_BAD_ITEM
value|29
end_define

begin_comment
comment|/* Bad item passed to pam_*_item() */
end_comment

begin_define
define|#
directive|define
name|PAM_CONV_AGAIN
value|30
end_define

begin_comment
comment|/* conversation function is event driven 				     and data is not available yet */
end_comment

begin_define
define|#
directive|define
name|PAM_INCOMPLETE
value|31
end_define

begin_comment
comment|/* please call this function again to 				   complete authentication stack. Before 				   calling again, verify that conversation 				   is completed */
end_comment

begin_comment
comment|/* Add new #define's here */
end_comment

begin_define
define|#
directive|define
name|_PAM_RETURN_VALUES
value|32
end_define

begin_comment
comment|/* this is the number of return values */
end_comment

begin_comment
comment|/* ---------------------- The Linux-PAM flags -------------------- */
end_comment

begin_comment
comment|/* Authentication service should not generate any messages */
end_comment

begin_define
define|#
directive|define
name|PAM_SILENT
value|0x8000U
end_define

begin_comment
comment|/* Note: these flags are used by pam_authenticate{,_secondary}() */
end_comment

begin_comment
comment|/* The authentication service should return PAM_AUTH_ERROR if the  * user has a null authentication token */
end_comment

begin_define
define|#
directive|define
name|PAM_DISALLOW_NULL_AUTHTOK
value|0x0001U
end_define

begin_comment
comment|/* Note: these flags are used for pam_setcred() */
end_comment

begin_comment
comment|/* Set user credentials for an authentication service */
end_comment

begin_define
define|#
directive|define
name|PAM_ESTABLISH_CRED
value|0x0002U
end_define

begin_comment
comment|/* Delete user credentials associated with an authentication service */
end_comment

begin_define
define|#
directive|define
name|PAM_DELETE_CRED
value|0x0004U
end_define

begin_comment
comment|/* Reinitialize user credentials */
end_comment

begin_define
define|#
directive|define
name|PAM_REINITIALIZE_CRED
value|0x0008U
end_define

begin_comment
comment|/* Extend lifetime of user credentials */
end_comment

begin_define
define|#
directive|define
name|PAM_REFRESH_CRED
value|0x0010U
end_define

begin_comment
comment|/* Note: these flags are used by pam_chauthtok */
end_comment

begin_comment
comment|/* The password service should only update those passwords that have  * aged.  If this flag is not passed, the password service should  * update all passwords. */
end_comment

begin_define
define|#
directive|define
name|PAM_CHANGE_EXPIRED_AUTHTOK
value|0x0020U
end_define

begin_comment
comment|/* ------------------ The Linux-PAM item types ------------------- */
end_comment

begin_comment
comment|/* these defines are used by pam_set_item() and pam_get_item() */
end_comment

begin_define
define|#
directive|define
name|PAM_SERVICE
value|1
end_define

begin_comment
comment|/* The service name */
end_comment

begin_define
define|#
directive|define
name|PAM_USER
value|2
end_define

begin_comment
comment|/* The user name */
end_comment

begin_define
define|#
directive|define
name|PAM_TTY
value|3
end_define

begin_comment
comment|/* The tty name */
end_comment

begin_define
define|#
directive|define
name|PAM_RHOST
value|4
end_define

begin_comment
comment|/* The remote host name */
end_comment

begin_define
define|#
directive|define
name|PAM_CONV
value|5
end_define

begin_comment
comment|/* The pam_conv structure */
end_comment

begin_comment
comment|/* missing entries found in<security/pam_modules.h> for modules only! */
end_comment

begin_define
define|#
directive|define
name|PAM_RUSER
value|8
end_define

begin_comment
comment|/* The remote user name */
end_comment

begin_define
define|#
directive|define
name|PAM_USER_PROMPT
value|9
end_define

begin_comment
comment|/* the prompt for getting a username */
end_comment

begin_define
define|#
directive|define
name|PAM_FAIL_DELAY
value|10
end_define

begin_comment
comment|/* app supplied function to override failure 				   delays */
end_comment

begin_define
define|#
directive|define
name|PAM_LOG_STATE
value|11
end_define

begin_comment
comment|/* ident, facility etc. logging info */
end_comment

begin_comment
comment|/* ---------- Common Linux-PAM application/module PI ----------- */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_set_item
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|item_type
parameter_list|,
specifier|const
name|void
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_get_item
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|item_type
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pam_strerror
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pam_putenv
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|name_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pam_getenv
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|pam_getenvlist
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------- Common Linux-PAM application/module PI ----------- */
end_comment

begin_comment
comment|/*  * here are some proposed error status definitions for the  * 'error_status' argument used by the cleanup function associated  * with data items they should be logically OR'd with the error_status  * of the latest return from libpam -- new with .52 and positive  * impression from Sun although not official as of 1996/9/4  * [generally the other flags are to be found in pam_modules.h]  */
end_comment

begin_define
define|#
directive|define
name|PAM_DATA_SILENT
value|0x40000000
end_define

begin_comment
comment|/* used to suppress messages... */
end_comment

begin_comment
comment|/*  * here we define an externally (by apps or modules) callable function  * that primes the libpam library to delay when a stacked set of  * modules results in a failure. In the case of PAM_SUCCESS this delay  * is ignored.  *  * Note, the pam_[gs]et_item(... PAM_FAIL_DELAY ...) can be used to set  * a function pointer which can override the default fail-delay behavior.  * This item was added to accommodate event driven programs that need to  * manage delays more carefully.  The function prototype for this data  * item is  *           void (*fail_delay)(int status, unsigned int delay);  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PAM_FAIL_DELAY
end_define

begin_function_decl
specifier|extern
name|int
name|pam_fail_delay
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|unsigned
name|int
name|musec_delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * the standard libc interface for syslog suffers from some problems.  * The first is that it is not thread safe.  It is also three functions  * where PAM only really needs a "log this" function.  It also does  * not provide modules and applications with information about whether  * the log is currently open or not etc...  All of these things mean  * that we need to centralize PAM's logging facility.  These two functions  * provide this centralization.  They are, however, just a gateway to  * libc's openlog/syslog/closelog functions.  Please note, your apps/modules  * will likely start to segfault if you do not use this function for  * system logging.  */
end_comment

begin_struct
struct|struct
name|pam_log_state
block|{
name|char
modifier|*
name|ident
decl_stmt|;
name|int
name|option
decl_stmt|;
name|int
name|facility
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_ERR
end_ifndef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* this is a sad HACK. But we need LOG_CRIT etc.. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAM_LOG_STATE_IDENT
value|"PAM"
end_define

begin_define
define|#
directive|define
name|PAM_LOG_STATE_OPTION
value|LOG_PID
end_define

begin_define
define|#
directive|define
name|PAM_LOG_STATE_FACILITY
value|LOG_AUTHPRIV
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|va_start
end_ifndef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_PAM_SYSTEM_LOG
end_define

begin_function_decl
specifier|extern
name|void
name|pam_vsystem_log
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|struct
name|pam_log_state
modifier|*
name|log_state
parameter_list|,
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pam_system_log
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|struct
name|pam_log_state
modifier|*
name|log_state
parameter_list|,
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MEMORY_DEBUG
end_ifdef

begin_comment
comment|/*  * this defines some macros that keep track of what memory has been  * allocated and indicates leakage etc... It should not be included in  * production application/modules.  */
end_comment

begin_include
include|#
directive|include
file|<security/pam_malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------ The Linux-PAM conversation structures ------------ */
end_comment

begin_comment
comment|/* Message styles */
end_comment

begin_define
define|#
directive|define
name|PAM_PROMPT_ECHO_OFF
value|1
end_define

begin_define
define|#
directive|define
name|PAM_PROMPT_ECHO_ON
value|2
end_define

begin_define
define|#
directive|define
name|PAM_ERROR_MSG
value|3
end_define

begin_define
define|#
directive|define
name|PAM_TEXT_INFO
value|4
end_define

begin_comment
comment|/* Linux-PAM specific types */
end_comment

begin_define
define|#
directive|define
name|PAM_RADIO_TYPE
value|5
end_define

begin_comment
comment|/* yes/no/maybe conditionals */
end_comment

begin_comment
comment|/* This is for server client non-human interaction.. these are NOT    part of the X/Open PAM specification (yet although Vipin has hinted    that they may well be 1997/7/8) but are currently included for    exploritory reasons.  Basically, they are for the module to obtain a    binary chunk of data from the client (via the server).  Such data    is intercepted by the server and unpacked in preparation for the    module */
end_comment

begin_define
define|#
directive|define
name|PAM_BINARY_MSG
value|6
end_define

begin_define
define|#
directive|define
name|PAM_BINARY_PROMPT
value|7
end_define

begin_comment
comment|/* maximum size of messages/responses etc.. (these are mostly    arbitrary so Linux-PAM should handle longer values). */
end_comment

begin_define
define|#
directive|define
name|PAM_MAX_NUM_MSG
value|32
end_define

begin_define
define|#
directive|define
name|PAM_MAX_MSG_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|PAM_MAX_RESP_SIZE
value|512
end_define

begin_comment
comment|/* Used to pass prompting text, error messages, or other informatory  * text to the user.  This structure is allocated and freed by the PAM  * library (or loaded module).  */
end_comment

begin_struct
struct|struct
name|pam_message
block|{
name|int
name|msg_style
decl_stmt|;
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* if the pam_message.msg_style = PAM_BINARY_PROMPT    the 'pam_message.msg' is a pointer to a 'const *' for the following    pseudo-structure.  When used with a PAM_BINARY_PROMPT, the returned    pam_response.resp pointer points to an object with the following    structure:     struct {        u32 length;                         #  network byte order        unsigned char data[length];    };     The 'libpam_client' library is designed around this flavor of    message and should be used to handle this flavor of msg_style.    */
end_comment

begin_comment
comment|/* Used to return the user's response to the PAM library.  This    structure is allocated by the application program, and free()'d by    the Linux-PAM library (or calling module).  */
end_comment

begin_struct
struct|struct
name|pam_response
block|{
name|char
modifier|*
name|resp
decl_stmt|;
name|int
name|resp_retcode
decl_stmt|;
comment|/* currently un-used, zero expected */
block|}
struct|;
end_struct

begin_comment
comment|/* The actual conversation structure itself */
end_comment

begin_struct
struct|struct
name|pam_conv
block|{
name|int
function_decl|(
modifier|*
name|conv
function_decl|)
parameter_list|(
name|int
name|num_msg
parameter_list|,
specifier|const
name|struct
name|pam_message
modifier|*
modifier|*
name|msg
parameter_list|,
name|struct
name|pam_response
modifier|*
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|appdata_ptr
parameter_list|)
function_decl|;
name|void
modifier|*
name|appdata_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_PAM
end_ifndef

begin_comment
comment|/*  * the following few lines represent a hack.  They are there to make  * the Linux-PAM headers more compatible with the Sun ones, which have a  * less strictly separated notion of module specific and application  * specific definitions.  */
end_comment

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ... adapted from the pam_appl.h file created by Theodore Ts'o and  *  * Copyright Theodore Ts'o, 1996.  All rights reserved.  * Copyright (c) Andrew G. Morgan<morgan@linux.kernel.org>, 1996-8  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SECURITY__PAM_TYPES_H */
end_comment

end_unit

