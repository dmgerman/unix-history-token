begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g -triple x86_64-apple-darwin10 %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Check the line numbers for the ret instruction. We expect it to be
end_comment

begin_comment
comment|// at the closing of the lexical scope in this case. See the comments in
end_comment

begin_comment
comment|// CodeGenFunction::FinishFunction() for more details.
end_comment

begin_comment
comment|// CHECK: define {{.*}}foo
end_comment

begin_comment
comment|// CHECK: store {{.*}}, !dbg ![[CONV:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ret {{.*}}, !dbg ![[RET:[0-9]+]]
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|// CHECK: ![[CONV]] = metadata !{i32 [[@LINE+1]], i32 0, metadata !{{.*}}, null}
name|i
operator|=
name|c
expr_stmt|;
comment|// CHECK: ![[RET]] = metadata !{i32 [[@LINE+1]], i32 0, metadata !{{.*}}, null}
block|}
end_function

end_unit

