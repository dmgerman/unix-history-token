begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -g -fblocks -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Assignment and block entry should point to the same line.
end_comment

begin_comment
comment|// rdar://problem/14039866
end_comment

begin_comment
comment|// CHECK: define{{.*}}@main()
end_comment

begin_comment
comment|// CHECK: store{{.*}}bitcast{{.*}}, !dbg ![[ASSIGNMENT:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: define {{.*}} @__main_block_invoke
end_comment

begin_comment
comment|// CHECK: dbg ![[BLOCK_ENTRY:[0-9]+]]
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: [[ASSIGNMENT]] = !MDLocation(line: [[@LINE+2]],
comment|// CHECK: [[BLOCK_ENTRY]] = !MDLocation(line: [[@LINE+1]],
name|int
function_decl|(
modifier|^
name|blockptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_return
return|return
name|blockptr
argument_list|()
return|;
end_return

unit|}
end_unit

