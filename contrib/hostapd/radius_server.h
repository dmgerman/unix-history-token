begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_SERVER_H
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_SERVER_H
end_define

begin_struct_decl
struct_decl|struct
name|radius_server_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|radius_server_conf
block|{
name|int
name|auth_port
decl_stmt|;
name|char
modifier|*
name|client_file
decl_stmt|;
name|void
modifier|*
name|hostapd_conf
decl_stmt|;
name|void
modifier|*
name|eap_sim_db_priv
decl_stmt|;
name|void
modifier|*
name|ssl_ctx
decl_stmt|;
name|int
name|ipv6
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|RADIUS_SERVER
end_ifdef

begin_function_decl
name|struct
name|radius_server_data
modifier|*
name|radius_server_init
parameter_list|(
name|struct
name|radius_server_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_server_deinit
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radius_server_get_mib
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* RADIUS_SERVER */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|radius_server_data
modifier|*
name|radius_server_init
parameter_list|(
name|struct
name|radius_server_conf
modifier|*
name|conf
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|radius_server_deinit
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|radius_server_get_mib
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RADIUS_SERVER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RADIUS_SERVER_H */
end_comment

end_unit

