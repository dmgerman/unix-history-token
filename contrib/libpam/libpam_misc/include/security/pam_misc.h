begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: pam_misc.h,v 1.3 2001/01/20 22:29:47 agmorgan Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAMMISC_H
end_ifndef

begin_define
define|#
directive|define
name|__PAMMISC_H
end_define

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_client.h>
end_include

begin_comment
comment|/* include some useful macros */
end_comment

begin_include
include|#
directive|include
file|<security/_pam_macros.h>
end_include

begin_comment
comment|/* functions defined in pam_misc.* libraries */
end_comment

begin_function_decl
specifier|extern
name|int
name|misc_conv
parameter_list|(
name|int
name|num_msg
parameter_list|,
specifier|const
name|struct
name|pam_message
modifier|*
modifier|*
name|msgm
parameter_list|,
name|struct
name|pam_response
modifier|*
modifier|*
name|response
parameter_list|,
name|void
modifier|*
name|appdata_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
specifier|extern
name|time_t
name|pam_misc_conv_warn_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time that we should warn user */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|pam_misc_conv_die_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cut-off time for input */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|pam_misc_conv_warn_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* warning notice */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|pam_misc_conv_die_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cut-off remark */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pam_misc_conv_died
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 = cut-off time reached (0 not) */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|pam_binary_handler_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|appdata
parameter_list|,
name|pamc_bp_t
modifier|*
name|prompt_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|pam_binary_handler_free
function_decl|)
parameter_list|(
name|void
modifier|*
name|appdata
parameter_list|,
name|pamc_bp_t
modifier|*
name|prompt_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Environment helper functions  */
end_comment

begin_comment
comment|/* transcribe given environment (to pam) */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_misc_paste_env
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|user_env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* char **pam_misc_copy_env(pam_handle_t *pamh);     This is no longer defined as a prototype because the X/Open XSSO    spec makes it clear that PAM's pam_getenvlist() does exactly    what this was needed for.     A wrapper is still provided in the pam_misc library - so that    legacy applications will still work.  But _BE_WARNED_ it will    disappear by the release of libpam 1.0 . */
end_comment

begin_comment
comment|/* delete environment as obtained from (pam_getenvlist) */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|pam_misc_drop_env
parameter_list|(
name|char
modifier|*
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* provide something like the POSIX setenv function for the (Linux-)PAM  * environment. */
end_comment

begin_function_decl
specifier|extern
name|int
name|pam_misc_setenv
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|readonly
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

