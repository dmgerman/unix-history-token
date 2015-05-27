begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR15642
end_comment

begin_comment
comment|// RUN: %clang -M -MG -fno-ms-compatibility %s | FileCheck -strict-whitespace %s --check-prefix=CHECK --check-prefix=SEP2F
end_comment

begin_comment
comment|// RUN: %clang -M -MG -fms-compatibility %s | FileCheck -strict-whitespace %s --check-prefix=CHECK --check-prefix=SEP5C
end_comment

begin_comment
comment|// RUN: %clang -M -MG -MV %s | FileCheck -strict-whitespace %s --check-prefix=NMAKE
end_comment

begin_comment
comment|// CHECK: \ \ \ \ .h
end_comment

begin_comment
comment|// CHECK: $$$$.h
end_comment

begin_comment
comment|// CHECK: \#\#.h
end_comment

begin_comment
comment|// NMAKE: "    .h"
end_comment

begin_comment
comment|// NMAKE: "$$.h"
end_comment

begin_comment
comment|// NMAKE: "##.h"
end_comment

begin_comment
comment|// NMAKE-NOT: "
end_comment

begin_comment
comment|// NMAKE: normal.h
end_comment

begin_comment
comment|// NMAKE-NOT: "
end_comment

begin_include
include|#
directive|include
file|"    .h"
end_include

begin_include
include|#
directive|include
file|"$$.h"
end_include

begin_include
include|#
directive|include
file|"##.h"
end_include

begin_include
include|#
directive|include
file|"normal.h"
end_include

begin_comment
comment|// Backslash followed by # or space should escape both characters, because
end_comment

begin_comment
comment|// that's what GNU Make wants.  GCC does the right thing with space, but not
end_comment

begin_comment
comment|// #, so Clang does too. (There should be 3 backslashes before the #.)
end_comment

begin_comment
comment|// SEP2F: a\b\\#c\\\ d.h
end_comment

begin_comment
comment|// With -fms-compatibility, Backslashes in #include are treated as path separators.
end_comment

begin_comment
comment|// Backslashes are given in the emission for special characters, like 0x20 or 0x23.
end_comment

begin_comment
comment|// SEP5C: a{{[/\\]}}b{{[/\\]}}\#c{{/|\\\\}}\ d.h
end_comment

begin_comment
comment|// These combinations are just another case for NMAKE.
end_comment

begin_comment
comment|// NMAKE: "a{{[/\\]}}b{{[/\\]}}#c{{[/\\]}} d.h"
end_comment

begin_include
include|#
directive|include
file|"a\b\#c\ d.h"
end_include

end_unit

