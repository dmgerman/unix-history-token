begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// rdar://9309454
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|v
decl_stmt|;
block|}
name|RetType
typedef|;
end_typedef

begin_function_decl
name|RetType
name|func
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|__attribute__
argument_list|(
argument|(__blocks__(byref))
argument_list|)
name|RetType
name|a
init|=
block|{
literal|100
block|}
decl_stmt|;
name|a
operator|=
name|func
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: [[C1:%.*]] = call i32 (...)* @func()
end_comment

begin_comment
comment|// CHECK-NEXT: [[CO:%.*]] = getelementptr
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 [[C1]], i32* [[CO]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[FORWARDING:%.*]] = getelementptr inbounds [[BR:%.*]]* [[A:%.*]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK-NEXT: [[O:%.*]] = load [[BR]]** [[FORWARDING]]
end_comment

end_unit

