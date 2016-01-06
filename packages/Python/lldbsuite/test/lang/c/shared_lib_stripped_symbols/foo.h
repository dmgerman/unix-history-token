begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct_decl
struct_decl|struct
name|foo
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sub_foo
block|{
name|int
name|sub_1
decl_stmt|;
name|char
modifier|*
name|sub_2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|foo
modifier|*
name|GetMeAFoo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sub_foo
modifier|*
name|GetMeASubFoo
parameter_list|(
name|struct
name|foo
modifier|*
name|in_foo
parameter_list|)
function_decl|;
end_function_decl

end_unit

