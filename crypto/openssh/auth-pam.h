begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: auth-pam.h,v 1.12 2002/04/04 19:02:28 stevesk Exp $ */
end_comment

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
file|<pwd.h>
end_include

begin_comment
comment|/* For struct passwd */
end_comment

begin_function_decl
name|void
name|start_pam
parameter_list|(
specifier|const
name|char
modifier|*
name|user
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
name|do_pam_authenticate
parameter_list|(
name|int
name|flags
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
name|int
name|init
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
name|is_pam_password_change_required
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

begin_function_decl
name|void
name|do_pam_set_conv
parameter_list|(
name|struct
name|pam_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|message_cat
parameter_list|(
name|char
modifier|*
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|a
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

end_unit

