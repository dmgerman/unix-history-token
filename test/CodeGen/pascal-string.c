begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -fpascal-strings | grep "05Hello"
end_comment

begin_function
name|unsigned
name|char
modifier|*
name|Foo
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|unsigned
name|char
name|s
index|[
literal|256
index|]
init|=
literal|"\pHello"
decl_stmt|;
return|return
name|s
return|;
block|}
end_function

end_unit

