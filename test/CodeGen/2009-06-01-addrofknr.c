begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -o %t -emit-llvm -verify
end_comment

begin_comment
comment|// PR4289
end_comment

begin_struct
struct|struct
name|funcptr
block|{
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|func
parameter_list|(
name|f
parameter_list|)
name|void
modifier|*
name|f
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

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
name|struct
name|funcptr
name|fp
decl_stmt|;
name|fp
operator|.
name|func
operator|=
operator|&
name|func
expr_stmt|;
name|fp
operator|.
name|func
operator|=
name|func
expr_stmt|;
block|}
end_function

end_unit

