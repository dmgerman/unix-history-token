begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -emit-llvm -o - %s
end_comment

begin_comment
comment|// PR954, PR911
end_comment

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|S
block|{
name|short
name|f1
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|int
name|f2
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|bar
parameter_list|()
block|{
name|struct
name|S
modifier|*
name|A
decl_stmt|;
if|if
condition|(
name|A
operator|->
name|f2
condition|)
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

