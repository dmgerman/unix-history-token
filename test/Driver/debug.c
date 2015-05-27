begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cd %S&& %clang -### -g %s -c 2>&1 | FileCheck -check-prefix=CHECK-PWD %s
end_comment

begin_comment
comment|// CHECK-PWD: {{"-fdebug-compilation-dir" ".*Driver.*"}}
end_comment

end_unit

