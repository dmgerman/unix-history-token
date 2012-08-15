begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_MD_Open64
function_decl|)
parameter_list|(
name|int
name|oflag
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|_MD_Open64
name|_open64
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|PR_OpenFile
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
name|_open64
argument_list|(
literal|0
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

