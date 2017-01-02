begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -flto -S -g %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @main.localstatic = internal global i32 0, align 4, !dbg [[L:![0-9]+]]
end_comment

begin_comment
comment|// CHECK: @global = common global i32 0, align 4, !dbg [[G:![0-9]+]]
end_comment

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|static
name|int
name|localstatic
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: [[L]] = !DIGlobalVariableExpression(var: [[LV:.*]])
end_comment

begin_comment
comment|// CHECK: [[LV]] = distinct !DIGlobalVariable(name: "localstatic"
end_comment

begin_comment
comment|// CHECK-NOT:                                 linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:                                line: 9,
end_comment

begin_comment
comment|// CHECK: [[G]] = !DIGlobalVariableExpression(var: [[GV:.*]])
end_comment

begin_comment
comment|// CHECK: [[GV]] = distinct !DIGlobalVariable(name: "global"
end_comment

begin_comment
comment|// CHECK-NOT:                                 linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:                                line: 7,
end_comment

end_unit

