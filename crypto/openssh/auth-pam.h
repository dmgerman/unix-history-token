begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * OpenSSH PAM authentication support.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_PAM_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_PAM_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/* For struct passwd */
end_comment

begin_function_decl
name|void
name|start_pam
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_pam
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_pam_password
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|fetch_pam_environment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_pam_account
parameter_list|(
name|char
modifier|*
name|username
parameter_list|,
name|char
modifier|*
name|remote_user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_session
parameter_list|(
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_setcred
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_pam_messages
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pam_password_change_required
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_chauthtok
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|inverted_pam_cookie
block|{
name|int
name|state
decl_stmt|;
comment|/* Which state have we reached? */
name|pid_t
name|pid
decl_stmt|;
comment|/* PID of child process */
comment|/* Only valid in state STATE_CONV */
name|int
name|num_msg
decl_stmt|;
comment|/* Number of messages */
name|struct
name|pam_message
modifier|*
modifier|*
name|msg
decl_stmt|;
comment|/* Message structures */
name|struct
name|pam_response
modifier|*
modifier|*
name|resp
decl_stmt|;
comment|/* Response structures */
name|struct
name|inverted_pam_userdata
modifier|*
name|userdata
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ipam_free_cookie
parameter_list|(
name|struct
name|inverted_pam_cookie
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inverted_pam_cookie
modifier|*
name|ipam_start_auth
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PAM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_PAM_H */
end_comment

end_unit

