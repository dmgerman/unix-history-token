begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@r = common global \[1 x .*\] zeroinitializer' %t
end_comment

begin_decl_stmt
name|int
name|r
index|[]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|a
argument_list|)
index|[]
operator|=
operator|&
name|r
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|s0
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|s0
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep '@x = common global .struct.s0 zeroinitializer' %t
end_comment

begin_decl_stmt
name|struct
name|s0
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep '@y = common global .struct.s0 zeroinitializer' %t
end_comment

begin_function
name|struct
name|s0
modifier|*
name|f0
parameter_list|()
block|{
return|return
operator|&
name|y
return|;
block|}
end_function

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// RUN: grep '@b = common global \[1 x .*\] zeroinitializer' %t
end_comment

begin_decl_stmt
name|int
name|b
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f1
parameter_list|()
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// Check that the most recent tentative definition wins.
end_comment

begin_comment
comment|// RUN: grep '@c = common global \[4 x .*\] zeroinitializer' %t
end_comment

begin_decl_stmt
name|int
name|c
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check that we emit static tentative definitions
end_comment

begin_comment
comment|// RUN: grep '@c5 = internal global \[1 x .*\] zeroinitializer' %t
end_comment

begin_decl_stmt
specifier|static
name|int
name|c5
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|func
parameter_list|()
block|{
return|return
name|c5
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|callfunc
parameter_list|()
block|{
return|return
name|func
argument_list|()
return|;
block|}
end_function

end_unit

