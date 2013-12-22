begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-pc-win32 -### -no-integrated-as %s -c 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: there is no external assembler that can be used on this platform
end_comment

begin_comment
comment|// But there is for mingw.  The source file should only be mentioned once for
end_comment

begin_comment
comment|// the compile step.
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-mingw32 -### -no-integrated-as %s -c 2>&1 | FileCheck -check-prefix=MINGW %s
end_comment

begin_comment
comment|// MINGW: "-cc1"
end_comment

begin_comment
comment|// MINGW: "-main-file-name" "no-integrated-as-win.c"
end_comment

begin_comment
comment|// MINGW: "-x" "c" "{{.*}}no-integrated-as-win.c"
end_comment

begin_comment
comment|// The assembler goes here, but its name depends on PATH.
end_comment

begin_comment
comment|// MINGW-NOT: no-integrated-as-win.c
end_comment

end_unit

