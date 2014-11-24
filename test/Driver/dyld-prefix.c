begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux --dyld-prefix /foo -### %t.o 2>&1 | FileCheck --check-prefix=CHECK-32 %s
end_comment

begin_comment
comment|// CHECK-32: "-dynamic-linker" "/foo/lib/ld-linux.so.2"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux --dyld-prefix /foo -### %t.o 2>&1 | FileCheck --check-prefix=CHECK-64 %s
end_comment

begin_comment
comment|// CHECK-64: "-dynamic-linker" "/foo/lib64/ld-linux-x86-64.so.2"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnux32 --dyld-prefix /foo -### %t.o 2>&1 | FileCheck --check-prefix=CHECK-X32 %s
end_comment

begin_comment
comment|// CHECK-X32: "-dynamic-linker" "/foo/libx32/ld-linux-x32.so.2"
end_comment

end_unit

