begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|h
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|t1
parameter_list|()
block|{
atomic|_Atomic
argument_list|(
name|typeof
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
name|f
argument_list|()
index|]
operator|)
name|h
argument_list|()
argument_list|)
argument_list|)
name|v
decl_stmt|;
comment|// CHECK:      [[N:%.*]] = alloca i32*, align 4
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @f to i32 ()*)()
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @h to i32 ()*)()
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
name|typeof
argument_list|(
argument|typeof((int (*)[f()]) h())
argument_list|)
name|v
expr_stmt|;
comment|// CHECK:      [[N:%.*]] = alloca i32*, align 4
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @f to i32 ()*)()
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @h to i32 ()*)()
block|}
end_function

begin_decl_stmt
name|void
name|t3
argument_list|(
name|typeof
argument_list|(
argument|(int (*)[f()]) h()
argument_list|)
name|v
argument_list|)
block|{
comment|// CHECK:      store i32* %v, i32** %{{[.0-9A-Za-z]+}}, align 4
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @f to i32 ()*)()
comment|// CHECK-NEXT: [[P:%.*]] = call i32 bitcast (i32 (...)* @h to i32 ()*)()
block|}
end_decl_stmt

end_unit

