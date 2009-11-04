begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm  %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: w = global %0 { i32 2, [4 x i8] undef }
end_comment

begin_comment
comment|// CHECK: y = global %union.u { double 7.300000e+0{{[0]*}}1 }
end_comment

begin_comment
comment|// CHECK: store i32 351, i32
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
name|union
name|u
name|olb
init|=
operator|(
expr|union
name|u
operator|)
literal|1.0
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

