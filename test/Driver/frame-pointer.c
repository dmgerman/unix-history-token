begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-pc-linux -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux -### -S -O2 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK2-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux -### -S -O3 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK3-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-linux -### -S -Os %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECKs-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -O2 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK2-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -O3 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK3-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -Os %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECKs-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-win32-macho -### -S -O3 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-MACHO-64 %s
end_comment

begin_comment
comment|// Trust the above to get the optimizations right, and just test other targets
end_comment

begin_comment
comment|// that want this by default.
end_comment

begin_comment
comment|// RUN: %clang -target s390x-pc-linux -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target s390x-pc-linux -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-64 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -### -S -O0 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK0-32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -### -S -O1 %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK1-32 %s
end_comment

begin_comment
comment|// CHECK0-32: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK1-32-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK2-32-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK3-32-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECKs-32-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK0-64: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK1-64-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK2-64-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK3-64-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECKs-64-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// CHECK-MACHO-64: -mdisable-fp-elim
end_comment

end_unit

