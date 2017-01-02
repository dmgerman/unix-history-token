begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S %s        2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G %s
end_comment

begin_comment
comment|// Assert that the toolchains which should default to a lower Dwarf version do so.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// 'g0' is the default. Just sanity-test that it does nothing
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0    2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// And check that the last of -g or -g0 wins.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -g0 2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// These should be semantically the same as not having given 'g0' at all,
end_comment

begin_comment
comment|// as the last 'g' option wins.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-STANDALONE %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target i386-pc-solaris 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// CHECK-WITHOUT-G-NOT: -debug-info-kind
end_comment

begin_comment
comment|// CHECK-WITH-G: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// CHECK-WITH-G: "-dwarf-version=4"
end_comment

begin_comment
comment|// CHECK-WITH-G-DWARF2: "-dwarf-version=2"
end_comment

begin_comment
comment|// CHECK-WITH-G-STANDALONE: "-debug-info-kind=standalone"
end_comment

begin_comment
comment|// CHECK-WITH-G-STANDALONE: "-dwarf-version=2"
end_comment

end_unit

