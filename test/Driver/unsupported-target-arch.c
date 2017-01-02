begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Tests that clang does not crash with invalid architectures in target triples.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-linux -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-LINUX %s
end_comment

begin_comment
comment|// CHECK-NOARCH-LINUX: error: unknown target triple 'noarch-unknown-linux', please use -triple or -arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-darwin -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-DARWIN %s
end_comment

begin_comment
comment|// CHECK-NOARCH-DARWIN: error: unknown target triple 'unknown-unknown-macosx{{.+}}', please use -triple or -arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-windows -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-WINDOWS %s
end_comment

begin_comment
comment|// CHECK-NOARCH-WINDOWS: error: unknown target triple 'noarch-unknown-windows-{{.+}}', please use -triple or -arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-freebsd -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-FREEBSD %s
end_comment

begin_comment
comment|// CHECK-NOARCH-FREEBSD: error: unknown target triple 'noarch-unknown-freebsd', please use -triple or -arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-netbsd -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-NETBSD %s
end_comment

begin_comment
comment|// CHECK-NOARCH-NETBSD: error: unknown target triple 'noarch-unknown-netbsd', please use -triple or -arch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang --target=noarch-unknown-nacl -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOARCH-NACL %s
end_comment

begin_comment
comment|// CHECK-NOARCH-NACL:  error: the target architecture 'noarch' is not supported by the target 'Native Client'
end_comment

end_unit

