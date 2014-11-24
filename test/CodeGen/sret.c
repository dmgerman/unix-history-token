begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep sret | count 5
end_comment

begin_struct
struct|struct
name|abc
block|{
name|long
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|long
name|c
decl_stmt|;
name|long
name|d
decl_stmt|;
name|long
name|e
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|abc
name|foo1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|abc
name|foo2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|()
block|{
name|struct
name|abc
name|dummy1
init|=
name|foo1
argument_list|()
decl_stmt|;
name|struct
name|abc
name|dummy2
init|=
name|foo2
argument_list|()
decl_stmt|;
block|}
end_function

end_unit

