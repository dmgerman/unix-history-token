begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1  %s -emit-llvm -o - | grep -v alloca | not grep bitcast  */
end_comment

begin_function
name|void
name|test
parameter_list|(
name|int
modifier|*
name|array
parameter_list|,
name|long
name|long
name|N
parameter_list|)
block|{
name|array
index|[
name|N
index|]
operator|=
name|N
index|[
name|array
index|]
operator|=
literal|33
expr_stmt|;
block|}
end_function

end_unit

