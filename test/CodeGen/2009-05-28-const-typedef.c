begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR4281
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|something
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|something
name|const_something
typedef|;
end_typedef

begin_function_decl
name|something
name|fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|const_something
name|R
init|=
name|fail
argument_list|()
decl_stmt|;
block|}
end_function

end_unit

