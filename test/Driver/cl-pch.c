begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// RUN: %clang_cl -Werror /Ycpchfile.h /FIpchfile.h /c -### -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YC %s
end_comment

begin_comment
comment|// CHECK-YC: cc1
end_comment

begin_comment
comment|// CHECK-YC: -emit-pch
end_comment

begin_comment
comment|// CHECK-YC: -o
end_comment

begin_comment
comment|// CHECK-YC: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YC: -x
end_comment

begin_comment
comment|// CHECK-YC: "c"
end_comment

begin_comment
comment|// But not if /TP changes the input language to C++.
end_comment

begin_comment
comment|// RUN: %clang_cl /TP -Werror /Ycpchfile.h /FIpchfile.h /c -### -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTP %s
end_comment

begin_comment
comment|// CHECK-YCTP: cc1
end_comment

begin_comment
comment|// CHECK-YCTP: -emit-pch
end_comment

begin_comment
comment|// CHECK-YCTP: -o
end_comment

begin_comment
comment|// CHECK-YCTP: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTP: -x
end_comment

begin_comment
comment|// CHECK-YCTP: "c++"
end_comment

begin_comment
comment|// Except if a later /TC changes it back.
end_comment

begin_comment
comment|// RUN: %clang_cl -Werror /Ycpchfile.h /FIpchfile.h /c -### -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTPTC %s
end_comment

begin_comment
comment|// CHECK-YCTPTC: cc1
end_comment

begin_comment
comment|// CHECK-YCTPTC: -emit-pch
end_comment

begin_comment
comment|// CHECK-YCTPTC: -o
end_comment

begin_comment
comment|// CHECK-YCTPTC: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTPTC: -x
end_comment

begin_comment
comment|// CHECK-YCTPTC: "c"
end_comment

begin_comment
comment|// Also check lower-case /Tp flag.
end_comment

begin_comment
comment|// RUN: %clang_cl -Werror /Tp%s /Ycpchfile.h /FIpchfile.h /c -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-YCTp %s
end_comment

begin_comment
comment|// CHECK-YCTp: cc1
end_comment

begin_comment
comment|// CHECK-YCTp: -emit-pch
end_comment

begin_comment
comment|// CHECK-YCTp: -o
end_comment

begin_comment
comment|// CHECK-YCTp: pchfile.pch
end_comment

begin_comment
comment|// CHECK-YCTp: -x
end_comment

begin_comment
comment|// CHECK-YCTp: "c++"
end_comment

end_unit

