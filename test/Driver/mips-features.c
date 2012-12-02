begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check handling MIPS specific features options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mips16
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-mips16 -mips16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-mips16
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mips16 -mno-mips16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMIPS16 %s
end_comment

begin_comment
comment|// CHECK-NOMIPS16: "-target-feature" "-mips16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mdsp
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-dsp -mdsp 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MDSP %s
end_comment

begin_comment
comment|// CHECK-MDSP: "-target-feature" "+dsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-dsp
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mdsp -mno-dsp 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMDSP %s
end_comment

begin_comment
comment|// CHECK-NOMDSP: "-target-feature" "-dsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mdspr2
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-dspr2 -mdspr2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MDSPR2 %s
end_comment

begin_comment
comment|// CHECK-MDSPR2: "-target-feature" "+dspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-dspr2
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mdspr2 -mno-dspr2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMDSPR2 %s
end_comment

begin_comment
comment|// CHECK-NOMDSPR2: "-target-feature" "-dspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -G
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -G 16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS-G %s
end_comment

begin_comment
comment|// CHECK-MIPS-G: "-mllvm" "-mips-ssection-threshold=16"
end_comment

end_unit

