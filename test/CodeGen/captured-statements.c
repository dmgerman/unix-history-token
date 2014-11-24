begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple %itanium_abi_triple -emit-llvm %s -o %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK-GLOBALS
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK-1
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK-2
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK-3
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Single statement
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|i
operator|++
expr_stmt|;
block|}
comment|// CHECK-1: %struct.anon = type { i32* }
comment|//
comment|// CHECK-1: test1
comment|// CHECK-1: alloca %struct.anon
comment|// CHECK-1: getelementptr inbounds %struct.anon*
comment|// CHECK-1: store i32* %i
comment|// CHECK-1: call void @[[HelperName:__captured_stmt[0-9]+]]
block|}
end_function

begin_comment
comment|// CHECK-1: define internal void @[[HelperName]](%struct.anon
end_comment

begin_comment
comment|// CHECK-1:   getelementptr inbounds %struct.anon{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-1:   load i32**
end_comment

begin_comment
comment|// CHECK-1:   load i32*
end_comment

begin_comment
comment|// CHECK-1:   add nsw i32
end_comment

begin_comment
comment|// CHECK-1:   store i32
end_comment

begin_comment
comment|// Compound statement with local variable
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|x
condition|;
name|i
operator|++
control|)
name|foo
argument_list|()
expr_stmt|;
block|}
comment|// CHECK-2: test2
comment|// CHECK-2-NOT: %i
comment|// CHECK-2: call void @[[HelperName:__captured_stmt[0-9]+]]
block|}
end_function

begin_comment
comment|// CHECK-2: define internal void @[[HelperName]]
end_comment

begin_comment
comment|// CHECK-2-NOT: }
end_comment

begin_comment
comment|// CHECK-2:   %i = alloca i32
end_comment

begin_comment
comment|// Capture array
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|int
name|arr
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
literal|5
block|}
decl_stmt|;
name|int
name|vla_arr
index|[
name|size
index|]
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|arr
index|[
literal|2
index|]
operator|=
name|vla_arr
index|[
name|size
operator|-
literal|1
index|]
expr_stmt|;
block|}
comment|// CHECK-3: test3
comment|// CHECK-3: alloca [5 x i32]
comment|// CHECK-3: call void @__captured_stmt
block|}
end_function

begin_comment
comment|// Capture VLA array
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|vla_arr
index|[
name|size
index|]
parameter_list|)
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|vla_arr
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
block|}
comment|// CHECK-3: test4([[INT:i.+]] {{.*}}[[SIZE:%.+]], [[INT]]*
comment|// CHECK-3: store [[INT]] {{.*}}[[SIZE]], [[INT]]* [[SIZE_ADDR:%.+]],
comment|// CHECK-3: [[REF:%.+]] = getelementptr inbounds
comment|// CHECK-3: store [[INT]]* [[SIZE_ADDR]], [[INT]]** [[REF]]
comment|// CHECK-3: call void @__captured_stmt
block|}
end_function

begin_function
name|void
name|dont_capture_global
parameter_list|()
block|{
specifier|static
name|int
name|s
decl_stmt|;
specifier|extern
name|int
name|e
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|global
operator|++
expr_stmt|;
name|s
operator|++
expr_stmt|;
name|e
operator|++
expr_stmt|;
block|}
comment|// CHECK-GLOBALS: %[[Capture:struct\.anon[\.0-9]*]] = type {}
comment|// CHECK-GLOBALS: call void @__captured_stmt[[HelperName:[0-9]+]](%[[Capture]]
block|}
end_function

begin_comment
comment|// CHECK-GLOBALS: define internal void @__captured_stmt[[HelperName]]
end_comment

begin_comment
comment|// CHECK-GLOBALS-NOT: ret
end_comment

begin_comment
comment|// CHECK-GLOBALS:   load i32* @global
end_comment

begin_comment
comment|// CHECK-GLOBALS:   load i32* @
end_comment

begin_comment
comment|// CHECK-GLOBALS:   load i32* @e
end_comment

end_unit

