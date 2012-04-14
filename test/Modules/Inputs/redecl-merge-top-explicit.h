begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|class
name|Explicit
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
modifier|*
name|explicit_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|explicit_struct
block|{
name|int
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ONE
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|my_struct_type
modifier|*
name|my_struct_ref
typedef|;
end_typedef

end_unit

