begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | grep 'call.*llvm.memcpy'
end_comment

begin_struct
struct|struct
name|x
block|{
name|int
name|a
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|(
name|struct
name|x
modifier|*
name|P
parameter_list|,
name|struct
name|x
modifier|*
name|Q
parameter_list|)
block|{
operator|*
name|P
operator|=
operator|*
name|Q
expr_stmt|;
block|}
end_function

end_unit

