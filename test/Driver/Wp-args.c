begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we extract -MD from '-Wp,-MD,FOO', which is used by a number of
end_comment

begin_comment
comment|// major projects (e.g., FireFox and the Linux Kernel).
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -Wp,-MD,FOO.d -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK-NOT: -MD
end_comment

begin_comment
comment|// CHECK: "-dependency-file" "FOO.d"
end_comment

begin_comment
comment|// CHECK: "-MT"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PR4062
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -Wp,-MMD -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix MMD< %t %s
end_comment

begin_comment
comment|// MMD: "-cc1"
end_comment

begin_comment
comment|// MMD-NOT: -MMD
end_comment

begin_comment
comment|// MMD: "-dependency-file" "Wp-args.d"
end_comment

end_unit

