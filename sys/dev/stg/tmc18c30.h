begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|stg_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|stg_alloc_resource
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stg_release_resource
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stg_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stg_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stg_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stg_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

