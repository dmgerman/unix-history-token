begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_H
end_define

begin_function_decl
name|void
name|do_authentication
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_authentication2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|auth_get_user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|allowed_user
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|AUTH_FAIL_MAX
value|6
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_LOG
value|(AUTH_FAIL_MAX/2)
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_MSG
value|"Too many authentication failures for %.100s"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

