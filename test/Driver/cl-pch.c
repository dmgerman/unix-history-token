begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-windows
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: %s and %S must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// The main test for clang-cl pch handling is cl-pch.cpp.  This file only checks
end_comment

begin_comment
comment|// a few things for .c inputs.
end_comment

begin_comment
comment|// /Yc with a .c file should build a c pch file.
end_comment

begin_comment
comment|// RUN: %clang_cl -Werror /Yc%S/Inputs/pchfile.h /FI%S/Inputs/pchfile.h /c /Fo%t/pchfile.obj /Fp%t/pchfile.pch -v -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YC %s
end_comment

begin_comment
comment|// CHECK-YC: cc1{{.* .*}}-emit-pch
end_comment

begin_comment
comment|// CHECK-YC-SAME: -o
end_comment

begin_comment
comment|// CHECK-YC-SAME: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YC-SAME: -x
end_comment

begin_comment
comment|// CHECK-YC-SAME: c-header
end_comment

begin_comment
comment|// But not if /TP changes the input language to C++.
end_comment

begin_comment
comment|// RUN: %clang_cl /TP -Werror /Yc%S/Inputs/pchfile.h /FI%S/Inputs/pchfile.h /c /Fo%t/pchfile.obj /Fp%t/pchfile.pch -v -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTP %s
end_comment

begin_comment
comment|// CHECK-YCTP: cc1{{.* .*}}-emit-pch
end_comment

begin_comment
comment|// CHECK-YCTP-SAME: -o
end_comment

begin_comment
comment|// CHECK-YCTP-SAME: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTP-SAME: -x
end_comment

begin_comment
comment|// CHECK-YCTP-SAME: c++-header
end_comment

begin_comment
comment|// Except if a later /TC changes it back.
end_comment

begin_comment
comment|// RUN: %clang_cl -Werror /Yc%S/Inputs/pchfile.h /FI%S/Inputs/pchfile.h /c /Fo%t/pchfile.obj /Fp%t/pchfile.pch -v -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTPTC %s
end_comment

begin_comment
comment|// CHECK-YCTPTC: cc1{{.* .*}}-emit-pch
end_comment

begin_comment
comment|// CHECK-YCTPTC-SAME: -o
end_comment

begin_comment
comment|// CHECK-YCTPTC-SAME: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTPTC-SAME: -x
end_comment

begin_comment
comment|// CHECK-YCTPTC-SAME: c-header
end_comment

begin_comment
comment|// Also check lower-case /Tp flag.
end_comment

begin_comment
comment|// RUN: %clang_cl -Werror /Tp%s /Yc%S/Inputs/pchfile.h /FI%S/Inputs/pchfile.h /c /Fo%t/pchfile.obj /Fp%t/pchfile.pch -v 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTp %s
end_comment

begin_comment
comment|// CHECK-YCTp: cc1{{.* .*}}-emit-pch
end_comment

begin_comment
comment|// CHECK-YCTp-SAME: -o
end_comment

begin_comment
comment|// CHECK-YCTp-SAME: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTp-SAME: -x
end_comment

begin_comment
comment|// CHECK-YCTp-SAME: c++-header
end_comment

end_unit

