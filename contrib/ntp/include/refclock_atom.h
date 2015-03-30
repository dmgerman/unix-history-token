begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for the atom driver and its friends  */
end_comment

begin_undef
undef|#
directive|undef
name|NANOSECOND
end_undef

begin_comment
comment|/* some systems define it differently */
end_comment

begin_define
define|#
directive|define
name|NANOSECOND
value|1000000000
end_define

begin_comment
comment|/* one second (ns) */
end_comment

begin_struct
struct|struct
name|refclock_atom
block|{
name|pps_handle_t
name|handle
decl_stmt|;
name|pps_params_t
name|pps_params
decl_stmt|;
name|struct
name|timespec
name|ts
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|refclock_ppsapi
parameter_list|(
name|int
parameter_list|,
name|struct
name|refclock_atom
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_params
parameter_list|(
name|int
parameter_list|,
name|struct
name|refclock_atom
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_pps
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|struct
name|refclock_atom
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

