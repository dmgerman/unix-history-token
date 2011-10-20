begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | not grep {foo\\* sub}
end_comment

begin_comment
comment|// This should not produce a subtrace constantexpr of a pointer
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|Y
decl_stmt|;
name|char
name|X
index|[
literal|100
index|]
decl_stmt|;
block|}
name|F
struct|;
end_struct

begin_function
name|int
name|test
parameter_list|(
name|char
modifier|*
name|Y
parameter_list|)
block|{
return|return
name|Y
operator|-
name|F
operator|.
name|X
return|;
block|}
end_function

end_unit

