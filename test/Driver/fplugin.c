begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that all -fplugin arguments are converted to -load
end_comment

begin_comment
comment|// RUN: %clang -c %s -fplugin=foo.so -### 2>&1                 | FileCheck %s --check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: %clang -c %s -fplugin=foo.so -fplugin=bar.so -### 2>&1 | FileCheck %s --check-prefix=CHECK2
end_comment

begin_comment
comment|// CHECK1: "-load" "foo.so"
end_comment

begin_comment
comment|// CHECK2: "-load" "foo.so" "-load" "bar.so"
end_comment

end_unit

