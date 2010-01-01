begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_typedef
typedef|typedef
name|short
name|T
index|[
literal|4
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|s
block|{
name|T
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|(
name|struct
name|s
modifier|*
name|x
parameter_list|)
block|{
name|bar
argument_list|(
operator|(
name|long
operator|)
name|x
operator|->
name|f0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

