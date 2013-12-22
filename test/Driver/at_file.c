begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -E %s @%s.args -o %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.log %s
end_comment

begin_comment
comment|// RUN: %clang -E %s @%s.args.utf16le -o %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.log %s
end_comment

begin_comment
comment|// CHECK: bar1
end_comment

begin_comment
comment|// CHECK-NEXT: bar2 zed2
end_comment

begin_comment
comment|// CHECK-NEXT: bar3 zed3
end_comment

begin_comment
comment|// CHECK-NEXT: bar4 zed4
end_comment

begin_comment
comment|// CHECK-NEXT: bar5 zed5
end_comment

begin_comment
comment|// CHECK-NEXT: 'bar6 zed6'
end_comment

begin_comment
comment|// CHECK-NEXT: "bar7 zed7"
end_comment

begin_comment
comment|// CHECK-NEXT: foo8bar8zed8
end_comment

begin_comment
comment|// CHECK-NEXT: foo9'bar9'zed9
end_comment

begin_comment
comment|// CHECK-NEXT: foo10"bar10"zed10
end_comment

begin_comment
comment|// CHECK: bar
end_comment

begin_comment
comment|// CHECK: zed12
end_comment

begin_comment
comment|// CHECK: one\two
end_comment

begin_comment
comment|// CHECK: c:\foo\bar.c
end_comment

begin_expr_stmt
name|foo1
name|foo2
name|foo3
name|foo4
name|foo5
name|foo6
name|foo7
name|foo8
name|foo9
name|foo10
ifdef|#
directive|ifdef
name|foo11
name|bar
endif|#
directive|endif
name|foo12
name|foo13
name|foo14
end_expr_stmt

end_unit

