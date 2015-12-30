begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 --analyze %s -o /dev/null -Xclang -analyzer-checker=debug.ConfigDumper -Xclang -analyzer-max-loop -Xclang 34> %t 2>&1
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
comment|// Call bar 33 times so max-times-inline-large is met and
comment|// min-blocks-for-inline-large is checked
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|34
condition|;
operator|++
name|i
control|)
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK: [config]
end_comment

begin_comment
comment|// CHECK-NEXT: cfg-conditional-static-initializers = true
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
comment|// CHECK-NEXT: inline-lambdas = true
end_comment

begin_comment
comment|// CHECK-NEXT: ipa = dynamic-bifurcate
end_comment

begin_comment
comment|// CHECK-NEXT: ipa-always-inline-size = 3
end_comment

begin_comment
comment|// CHECK-NEXT: leak-diagnostics-reference-allocation = false
end_comment

begin_comment
comment|// CHECK-NEXT: max-inlinable-size = 50
end_comment

begin_comment
comment|// CHECK-NEXT: max-nodes = 150000
end_comment

begin_comment
comment|// CHECK-NEXT: max-times-inline-large = 32
end_comment

begin_comment
comment|// CHECK-NEXT: min-cfg-size-treat-functions-as-large = 14
end_comment

begin_comment
comment|// CHECK-NEXT: mode = deep
end_comment

begin_comment
comment|// CHECK-NEXT: region-store-small-struct-limit = 2
end_comment

begin_comment
comment|// CHECK-NEXT: widen-loops = false
end_comment

begin_comment
comment|// CHECK-NEXT: [stats]
end_comment

begin_comment
comment|// CHECK-NEXT: num-entries = 15
end_comment

end_unit

