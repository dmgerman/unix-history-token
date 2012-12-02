begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --analyze %s -o /dev/null -Xclang -analyzer-checker=debug.ConfigDumper> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: [config]
end_comment

begin_comment
comment|// CHECK-NEXT: cfg-temporary-dtors = false
end_comment

begin_comment
comment|// CHECK-NEXT: faux-bodies = true
end_comment

begin_comment
comment|// CHECK-NEXT: graph-trim-interval = 1000
end_comment

begin_comment
comment|// CHECK-NEXT: ipa-always-inline-size = 3
end_comment

begin_comment
comment|// CHECK-NEXT: [stats]
end_comment

begin_comment
comment|// CHECK-NEXT: num-entries = 4
end_comment

end_unit

