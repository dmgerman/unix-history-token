begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct_decl
struct_decl|struct
name|test
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|my_func
function_decl|)
parameter_list|(
name|struct
name|test
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|my_func
name|handler
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|test
block|{
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|char
name|f
parameter_list|(
name|struct
name|test
modifier|*
name|t
parameter_list|)
block|{
return|return
name|t
operator|->
name|a
return|;
block|}
end_function

end_unit

