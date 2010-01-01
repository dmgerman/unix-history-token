begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_comment
comment|// PR2910
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|unsigned
name|char
name|sun_len
decl_stmt|;
name|char
name|sun_path
index|[
literal|104
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test
parameter_list|(
name|int
name|len
parameter_list|)
block|{
return|return
name|__builtin_offsetof
argument_list|(
expr|struct
name|sockaddr_un
argument_list|,
name|sun_path
index|[
name|len
operator|+
literal|1
index|]
argument_list|)
return|;
block|}
end_function

end_unit

