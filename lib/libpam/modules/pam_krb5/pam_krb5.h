begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pam_krb5.h  *  * $Id: pam_krb5.h,v 1.5 1999/01/19 23:43:10 fcusack Exp $  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|get_user_info
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify_krb_v5_tgt
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup_cache
parameter_list|(
name|pam_handle_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|krb5_prompter_fct
name|pam_prompter
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|compat_princ_component
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_principal
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compat_free_data_contents
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ENCTYPE_DES_CBC_MD5
end_ifndef

begin_define
define|#
directive|define
name|ENCTYPE_DES_CBC_MD5
value|ETYPE_DES_CBC_MD5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

