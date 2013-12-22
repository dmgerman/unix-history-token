begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fcolor-diagnostics -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-CD %s
end_comment

begin_comment
comment|// CHECK-CD: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fno-color-diagnostics -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-NCD %s
end_comment

begin_comment
comment|// CHECK-NCD-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DC %s
end_comment

begin_comment
comment|// CHECK-DC: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fno-diagnostics-color -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-NDC %s
end_comment

begin_comment
comment|// CHECK-NDC-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color=always -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DCE_A %s
end_comment

begin_comment
comment|// CHECK-DCE_A: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color=never -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DCE_N %s
end_comment

begin_comment
comment|// CHECK-DCE_N-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// The test doesn't run in a PTY, so "auto" defaults to off.
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color=auto -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DCE_AUTO %s
end_comment

begin_comment
comment|// CHECK-DCE_AUTO-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color=foo -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DCE_FOO %s
end_comment

begin_comment
comment|// CHECK-DCE_FOO: error: the clang compiler does not support '-fdiagnostics-color=foo'
end_comment

begin_comment
comment|// Check that the last flag wins.
end_comment

begin_comment
comment|// RUN: %clang -fno-color-diagnostics -fdiagnostics-color -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-NCD_DC_S %s
end_comment

begin_comment
comment|// CHECK-NCD_DC_S: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fcolor-diagnostics -fno-diagnostics-color -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-CD_NDC_S %s
end_comment

begin_comment
comment|// CHECK-CD_NDC_S-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fdiagnostics-color -fno-color-diagnostics -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-DC_NCD_S %s
end_comment

begin_comment
comment|// CHECK-DC_NCD_S-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fno-diagnostics-color -fcolor-diagnostics -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-NDC_CD_S %s
end_comment

begin_comment
comment|// CHECK-NDC_CD_S: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fcolor-diagnostics -fdiagnostics-color=auto -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-CD_DCE_AUTO_S %s
end_comment

begin_comment
comment|// CHECK-CD_DCE_AUTO_S-NOT: clang{{.*}}" "-fcolor-diagnostics"
end_comment

begin_comment
comment|// RUN: %clang -fansi-escape-codes -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=CHECK-AEC %s
end_comment

begin_comment
comment|// CHECK-AEC: clang{{.*}}" "-fansi-escape-codes"
end_comment

end_unit

