begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_comment
comment|// PR1990
end_comment

begin_struct
struct|struct
name|test
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|b
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|struct
name|test
modifier|*
name|t
parameter_list|)
block|{
name|t
operator|->
name|b
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

