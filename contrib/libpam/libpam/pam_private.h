begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pam_private.h  *  * $Id: pam_private.h,v 1.12 1997/04/05 06:57:37 morgan Exp morgan $  * $FreeBSD$  *  * This is the Linux-PAM Library Private Header. It contains things  * internal to the Linux-PAM library. Things not needed by either an  * application or module.  *  * Please see end of file for copyright.  *  * Creator: Marc Ewing.  * Maintained: AGM  *   * $Log: pam_private.h,v $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_PAM_PRIVATE_H
end_define

begin_comment
comment|/* this is not used at the moment --- AGM */
end_comment

begin_define
define|#
directive|define
name|LIBPAM_VERSION
value|65
end_define

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

begin_comment
comment|/* the Linux-PAM configuration file */
end_comment

begin_define
define|#
directive|define
name|PAM_CONFIG
value|"/etc/pam.conf"
end_define

begin_define
define|#
directive|define
name|PAM_CONFIG_D
value|"/etc/pam.d"
end_define

begin_define
define|#
directive|define
name|PAM_CONFIG_DF
value|"/etc/pam.d/%s"
end_define

begin_define
define|#
directive|define
name|PAM_DEFAULT_SERVICE
value|"other"
end_define

begin_comment
comment|/* lower case */
end_comment

begin_define
define|#
directive|define
name|PAM_DEFAULT_SERVICE_FILE
value|PAM_CONFIG_D "/" PAM_DEFAULT_SERVICE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_LOCKING
end_ifdef

begin_comment
comment|/*  * the Linux-PAM lock file. If it exists Linux-PAM will abort. Use it  * to block access to libpam  */
end_comment

begin_define
define|#
directive|define
name|PAM_LOCK_FILE
value|"/var/lock/subsys/PAM"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* components of the pam_handle structure */
end_comment

begin_struct
struct|struct
name|handler
block|{
name|int
name|must_fail
decl_stmt|;
name|int
function_decl|(
modifier|*
name|func
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
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|int
name|actions
index|[
name|_PAM_RETURN_VALUES
index|]
decl_stmt|;
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|struct
name|handler
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|loaded_module
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* PAM_STATIC_MOD or PAM_DYNAMIC_MOD */
name|void
modifier|*
name|dl_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PAM_MT_DYNAMIC_MOD
value|0
end_define

begin_define
define|#
directive|define
name|PAM_MT_STATIC_MOD
value|1
end_define

begin_define
define|#
directive|define
name|PAM_MT_FAULTY_MOD
value|2
end_define

begin_struct
struct|struct
name|handlers
block|{
name|struct
name|handler
modifier|*
name|authenticate
decl_stmt|;
name|struct
name|handler
modifier|*
name|setcred
decl_stmt|;
name|struct
name|handler
modifier|*
name|acct_mgmt
decl_stmt|;
name|struct
name|handler
modifier|*
name|open_session
decl_stmt|;
name|struct
name|handler
modifier|*
name|close_session
decl_stmt|;
name|struct
name|handler
modifier|*
name|chauthtok
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|service
block|{
name|struct
name|loaded_module
modifier|*
name|module
decl_stmt|;
comment|/* Only used for dynamic loading */
name|int
name|modules_allocated
decl_stmt|;
name|int
name|modules_used
decl_stmt|;
name|int
name|handlers_loaded
decl_stmt|;
name|struct
name|handlers
name|conf
decl_stmt|;
comment|/* the configured handlers */
name|struct
name|handlers
name|other
decl_stmt|;
comment|/* the default handlers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Environment helper functions  */
end_comment

begin_define
define|#
directive|define
name|PAM_ENV_CHUNK
value|10
end_define

begin_comment
comment|/* chunks of memory calloc()'d      * 				  * at once                          */
end_comment

begin_struct
struct|struct
name|pam_environ
block|{
name|int
name|entries
decl_stmt|;
comment|/* the number of pointers available */
name|int
name|requested
decl_stmt|;
comment|/* the number of pointers used:     * 				  *     1<= requested<= entries    */
name|char
modifier|*
modifier|*
name|list
decl_stmt|;
comment|/* the environment storage (a list  * 				  * of pointers to malloc() memory)  */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAM_FALSE
block|,
name|PAM_TRUE
block|}
name|_pam_boolean
typedef|;
end_typedef

begin_struct
struct|struct
name|_pam_fail_delay
block|{
name|_pam_boolean
name|set
decl_stmt|;
name|unsigned
name|int
name|delay
decl_stmt|;
name|time_t
name|begin
decl_stmt|;
specifier|const
name|void
modifier|*
name|delay_fn_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_pam_former_state
block|{
comment|/* this is known and set by _pam_dispatch() */
name|int
name|choice
decl_stmt|;
comment|/* which flavor of module function did we call? */
comment|/* state info for the _pam_dispatch_aux() function */
name|int
name|depth
decl_stmt|;
comment|/* how deep in the stack were we? */
name|int
name|impression
decl_stmt|;
comment|/* the impression at that time */
name|int
name|status
decl_stmt|;
comment|/* the status before returning incomplete */
comment|/* state info used by pam_get_user() function */
name|int
name|want_user
decl_stmt|;
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* saved prompt information */
comment|/* state info for the pam_chauthtok() function */
name|_pam_boolean
name|update
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pam_handle
block|{
name|char
modifier|*
name|authtok
decl_stmt|;
name|struct
name|pam_conv
modifier|*
name|pam_conversation
decl_stmt|;
name|char
modifier|*
name|oldauthtok
decl_stmt|;
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* for use by pam_get_user() */
name|char
modifier|*
name|service_name
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|rhost
decl_stmt|;
name|char
modifier|*
name|ruser
decl_stmt|;
name|char
modifier|*
name|tty
decl_stmt|;
name|struct
name|pam_log_state
name|pam_default_log
decl_stmt|;
comment|/* for ident etc., log state */
name|struct
name|pam_data
modifier|*
name|data
decl_stmt|;
name|struct
name|pam_environ
modifier|*
name|env
decl_stmt|;
comment|/* structure to maintain environment list */
name|struct
name|_pam_fail_delay
name|fail_delay
decl_stmt|;
comment|/* helper function for easy delays */
name|struct
name|service
name|handlers
decl_stmt|;
name|struct
name|_pam_former_state
name|former
decl_stmt|;
comment|/* library state - support for 					 event driven applications */
block|}
struct|;
end_struct

begin_comment
comment|/* Values for select arg to _pam_dispatch() */
end_comment

begin_define
define|#
directive|define
name|PAM_NOT_STACKED
value|0
end_define

begin_define
define|#
directive|define
name|PAM_AUTHENTICATE
value|1
end_define

begin_define
define|#
directive|define
name|PAM_SETCRED
value|2
end_define

begin_define
define|#
directive|define
name|PAM_ACCOUNT
value|3
end_define

begin_define
define|#
directive|define
name|PAM_OPEN_SESSION
value|4
end_define

begin_define
define|#
directive|define
name|PAM_CLOSE_SESSION
value|5
end_define

begin_define
define|#
directive|define
name|PAM_CHAUTHTOK
value|6
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_IS_JUMP
parameter_list|(
name|x
parameter_list|)
value|((x)> 0)
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_OK
value|-1
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_DONE
value|-2
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_BAD
value|-3
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_DIE
value|-4
end_define

begin_define
define|#
directive|define
name|_PAM_ACTION_RESET
value|-5
end_define

begin_comment
comment|/* Add any new entries here.  Will need to change ..._UNDEF and then  * need to change pam_tokens.h */
end_comment

begin_define
define|#
directive|define
name|_PAM_ACTION_UNDEF
value|-6
end_define

begin_comment
comment|/* this is treated as an error 				       ( = _PAM_ACTION_BAD) */
end_comment

begin_comment
comment|/* character tables for parsing config files */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|_pam_token_actions
index|[
operator|-
name|_PAM_ACTION_UNDEF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|_pam_token_returns
index|[
name|_PAM_RETURN_VALUES
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * internally defined functions --- these should not be directly  * called by applications or modules  */
end_comment

begin_function_decl
name|int
name|_pam_dispatch
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|choice
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free various allocated structures and dlclose() the libs */
end_comment

begin_function_decl
name|int
name|_pam_free_handlers
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse config file, allocate handler structures, dlopen() */
end_comment

begin_function_decl
name|int
name|_pam_init_handlers
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set all hander stuff to 0/NULL - called once from pam_start() */
end_comment

begin_function_decl
name|void
name|_pam_start_handlers
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* environment helper functions */
end_comment

begin_comment
comment|/* create the environment structure */
end_comment

begin_function_decl
name|int
name|_pam_make_env
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* delete the environment structure */
end_comment

begin_function_decl
name|void
name|_pam_drop_env
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LINUX_PAM
end_ifdef

begin_comment
comment|/* these functions deal with failure delays as required by the    authentication modules and application. Their *interface* is likely    to remain the same although their function is hopefully going to    improve */
end_comment

begin_comment
comment|/* reset the timer to no-delay */
end_comment

begin_function_decl
name|void
name|_pam_reset_timer
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* this sets the clock ticking */
end_comment

begin_function_decl
name|void
name|_pam_start_timer
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* this waits for the clock to stop ticking if status != PAM_SUCCESS */
end_comment

begin_function_decl
name|void
name|_pam_await_timer
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_PAM */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
operator|*
name|voidfunc
argument_list|(
name|void
argument_list|)
argument_list|)
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_STATIC
end_ifdef

begin_comment
comment|/* The next two in ../modules/_pam_static/pam_static.c */
end_comment

begin_comment
comment|/* Return pointer to data structure used to define a static module */
end_comment

begin_function_decl
name|struct
name|pam_module
modifier|*
name|_pam_open_static_handler
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return pointer to function requested from static module */
end_comment

begin_function_decl
name|voidfunc
modifier|*
name|_pam_get_static_sym
parameter_list|(
name|struct
name|pam_module
modifier|*
name|mod
parameter_list|,
specifier|const
name|char
modifier|*
name|symname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For now we just use a stack and linear search for module data. */
end_comment

begin_comment
comment|/* If it becomes apparent that there is a lot of data, it should  */
end_comment

begin_comment
comment|/* changed to either a sorted list or a hash table.               */
end_comment

begin_struct
struct|struct
name|pam_data
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
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
function_decl|;
name|struct
name|pam_data
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|_pam_free_data
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pam_strCMP
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_pam_StrTok
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|char
modifier|*
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_pam_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_pam_mkargv
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
modifier|*
name|argc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pam_sanitize
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pam_set_default_control
parameter_list|(
name|int
modifier|*
name|control_array
parameter_list|,
name|int
name|default_action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_pam_parse_control
parameter_list|(
name|int
modifier|*
name|control_array
parameter_list|,
name|char
modifier|*
name|tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX - Take care with this. It could confuse the logic of a trailing  *       else  */
end_comment

begin_define
define|#
directive|define
name|IF_NO_PAMH
parameter_list|(
name|X
parameter_list|,
name|pamh
parameter_list|,
name|ERR
parameter_list|)
define|\
value|if ((pamh) == NULL) {                             \     pam_system_log(NULL, NULL, LOG_ERR, X ": NULL pam handle passed"); \     return ERR;                                   \ }
end_define

begin_comment
comment|/* Definition for the default username prompt used by pam_get_user() */
end_comment

begin_define
define|#
directive|define
name|PAM_DEFAULT_PROMPT
value|"Please enter username: "
end_define

begin_comment
comment|/*  * pam_system_log default ident/facility..  */
end_comment

begin_define
define|#
directive|define
name|PAM_LOG_STATE_DEFAULT
value|{      \     PAM_LOG_STATE_IDENT,     \     PAM_LOG_STATE_OPTION,    \     PAM_LOG_STATE_FACILITY   \ }
end_define

begin_comment
comment|/*  * include some helpful macros  */
end_comment

begin_include
include|#
directive|include
file|<security/_pam_macros.h>
end_include

begin_comment
comment|/*  * Copyright (C) 1995 by Red Hat Software, Marc Ewing  * Copyright (c) 1996-8, Andrew G. Morgan<morgan@linux.kernel.org>  *  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAM_PRIVATE_H_ */
end_comment

end_unit

