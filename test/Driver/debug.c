begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cd %S&& %clang -### -g %s -c 2>&1 | FileCheck -check-prefix=CHECK-PWD %s
end_comment

begin_comment
comment|// CHECK-PWD: {{"-fdebug-compilation-dir" ".*Driver.*"}}
end_comment

begin_comment
comment|// "PWD=/foo gcc" wouldn't necessarily work. You would need to pick a different
end_comment

begin_comment
comment|// path to the same directory (try a symlink).
end_comment

begin_comment
comment|// This depends on host's behavior how $PWD would be set.
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

end_unit

