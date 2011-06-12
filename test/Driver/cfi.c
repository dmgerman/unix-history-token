begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin10  -static -### %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:  FileCheck --check-prefix=CHECK-DARWIN %s
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-pc-linux-gnu  -static -### %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LINUX %s
end_comment

begin_comment
comment|// CHECK-DARWIN: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-NOT: -fno-dwarf2-cfi-asm
end_comment

end_unit

