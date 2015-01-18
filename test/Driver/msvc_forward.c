begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-win32 -loldnames -lkernel32.lib -luser32.lib -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: "-loldnames.lib"
end_comment

begin_comment
comment|// CHECK-NOT: "-lkernel32.lib"
end_comment

begin_comment
comment|// CHECK-NOT: "-luser32.lib"
end_comment

begin_comment
comment|// CHECK: "oldnames.lib"
end_comment

begin_comment
comment|// CHECK: "kernel32.lib"
end_comment

begin_comment
comment|// CHECK: "user32.lib"
end_comment

end_unit

