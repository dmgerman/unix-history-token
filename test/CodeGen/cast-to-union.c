begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s -o %t&&
end_comment

begin_comment
comment|// RUN: grep "store i32 351, i32*" %t&&
end_comment

begin_comment
comment|// RUN: grep "w = global %0<{ i32 2, i8 0, i8 0, i8 0, i8 0 }>" %t&&
end_comment

begin_comment
comment|// RUN: grep "y = global %1<{ double 7.300000e+01 }>" %t
end_comment

begin_union
union|union
name|u
block|{
name|int
name|i
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|foo
parameter_list|()
block|{
name|union
name|u
name|ola
init|=
operator|(
expr|union
name|u
operator|)
literal|351
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|union
name|u
name|w
init|=
operator|(
expr|union
name|u
operator|)
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|u
name|y
init|=
operator|(
expr|union
name|u
operator|)
literal|73.0
decl_stmt|;
end_decl_stmt

end_unit

