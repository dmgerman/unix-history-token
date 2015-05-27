begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -flto -S -g %s -o - | FileCheck %s
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
comment|// CHECK: !DIGlobalVariable(name: "localstatic"
end_comment

begin_comment
comment|// CHECK-NOT:               linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:              line: 5,
end_comment

begin_comment
comment|// CHECK-SAME:              variable: i32* @main.localstatic
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariable(name: "global"
end_comment

begin_comment
comment|// CHECK-NOT:               linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:              line: 3,
end_comment

begin_comment
comment|// CHECK-SAME:              variable: i32* @global
end_comment

end_unit

