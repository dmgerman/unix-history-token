begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test1.x = internal constant [12 x i32] [i32 1
end_comment

begin_comment
comment|// CHECK: @test2.x = internal constant [13 x i32] [i32 1,
end_comment

begin_comment
comment|// CHECK: @test5w = global %0 { i32 2, [4 x i8] undef }
end_comment

begin_comment
comment|// CHECK: @test5y = global %union.test5u { double 7.300000e+0{{[0]*}}1 }
end_comment

begin_comment
comment|// CHECK: @test6.x = internal constant %struct.SelectDest { i8 1, i8 2, i32 3, i32 0 }
end_comment

begin_comment
comment|// CHECK: @test7 = global [2 x %struct.test7s] [%struct.test7s { i32 1, i32 2 }, %struct.test7s { i32 4, i32 0 }]
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// This should codegen as a "@test1.x" global.
specifier|const
name|int
name|x
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|123
block|,
literal|231
block|,
literal|123
block|,
literal|23
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test1()
comment|// CHECK: {{call.*@foo.*@test1.x}}
block|}
end_function

begin_comment
comment|// rdar://7346691
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// This should codegen as a "@test2.x" global + memcpy.
name|int
name|x
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|123
block|,
literal|231
block|,
literal|123
block|,
literal|23
block|,
literal|24
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test2()
comment|// CHECK: %x = alloca [13 x i32]
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call{{.*}}@foo{{.*}}i32* %
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|// This should codegen as a memset.
name|int
name|x
index|[
literal|100
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test3()
comment|// CHECK: %x = alloca [100 x i32]
comment|// CHECK: call void @llvm.memset
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"asdf"
decl_stmt|;
name|char
name|b
index|[
literal|10
index|]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
comment|// CHECK: @test4()
comment|// CHECK: %a = alloca [10 x i8]
comment|// CHECK: %b = alloca [10 x i8]
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call void @llvm.memcpy
block|}
end_function

begin_union
union|union
name|test5u
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
name|test5
parameter_list|()
block|{
name|union
name|test5u
name|ola
init|=
operator|(
expr|union
name|test5u
operator|)
literal|351
decl_stmt|;
name|union
name|test5u
name|olb
init|=
operator|(
expr|union
name|test5u
operator|)
literal|1.0
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|union
name|test5u
name|test5w
init|=
operator|(
expr|union
name|test5u
operator|)
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|test5u
name|test5y
init|=
operator|(
expr|union
name|test5u
operator|)
literal|73.0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR6660 - sqlite miscompile
end_comment

begin_struct
struct|struct
name|SelectDest
block|{
name|unsigned
name|char
name|eDest
decl_stmt|;
name|unsigned
name|char
name|affinity
decl_stmt|;
name|int
name|iParm
decl_stmt|;
name|int
name|iMem
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test6
parameter_list|()
block|{
name|struct
name|SelectDest
name|x
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
name|test6f
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://7657600
end_comment

begin_struct
struct|struct
name|test7s
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|test7
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|4
block|}
block|, }
struct|;
end_struct

begin_comment
comment|// rdar://7872531
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_struct
struct|struct
name|test8s
block|{
name|int
name|f0
decl_stmt|;
name|char
name|f1
decl_stmt|;
block|}
name|test8g
init|=
block|{}
struct|;
end_struct

begin_comment
comment|// PR7519
end_comment

begin_struct
struct|struct
name|S
block|{
name|void
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|(
name|struct
name|S
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|S
modifier|*
name|global_dc
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cp_diagnostic_starter
parameter_list|(
name|struct
name|S
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|init_error
parameter_list|(
name|void
parameter_list|)
block|{
name|global_dc
operator|->
name|x
operator|=
name|cp_diagnostic_starter
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://8147692 - ABI crash in recursive struct-through-function-pointer.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x5a
decl_stmt|;
block|}
name|x5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|x2
modifier|*
name|x0
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
function_decl|(
modifier|*
name|x1
function_decl|)
parameter_list|(
name|x0
name|x0a
parameter_list|,
name|x5
name|x6
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|x2
block|{
name|x1
name|x4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|long
name|x3
parameter_list|(
name|x0
name|x0a
parameter_list|,
name|x5
name|a
parameter_list|)
block|{
return|return
name|x0a
operator|->
name|x4
argument_list|(
name|x0a
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

end_unit

