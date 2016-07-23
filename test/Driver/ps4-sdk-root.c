begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// Check that PS4 clang doesn't report a warning message when locating
end_comment

begin_comment
comment|// system header files (either by looking at the value of SCE_ORBIS_SDK_DIR
end_comment

begin_comment
comment|// or relative to the location of the compiler driver), if "-nostdinc",
end_comment

begin_comment
comment|// "--sysroot" or "-isysroot" option is specified on the command line.
end_comment

begin_comment
comment|// Otherwise, check that PS4 clang reports a warning.
end_comment

begin_comment
comment|// Check that PS4 clang doesn't report a warning message when locating
end_comment

begin_comment
comment|// system libraries (either by looking at the value of SCE_ORBIS_SDK_DIR
end_comment

begin_comment
comment|// or relative to the location of the compiler driver), if "-c", "-S", "-E",
end_comment

begin_comment
comment|// "--sysroot", "-nostdlib" or "-nodefaultlibs" option is specified on
end_comment

begin_comment
comment|// the command line.
end_comment

begin_comment
comment|// Otherwise, check that PS4 clang reports a warning.
end_comment

begin_comment
comment|// Setting up SCE_ORBIS_SDK_DIR to existing location, which is not a PS4 SDK.
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=WARN-SYS-LIBS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -c -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -S -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -E -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -emit-ast -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=WARN-SYS-LIBS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -c -nostdinc -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -S -nostdinc -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -E -nostdinc -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -emit-ast -nostdinc -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -c --sysroot=foo/ -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -S --sysroot=foo/ -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -E --sysroot=foo/ -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -emit-ast --sysroot=foo/ -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -c -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -S -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -E -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -emit-ast -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### --sysroot=foo/ -isysroot foo -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-ISYSROOT -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -nostdlib -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=.. %clang -Winvalid-or-nonexistent-directory -### -nodefaultlibs -target x86_64-scei-ps4 %s 2>&1 | FileCheck -check-prefix=WARN-SYS-HEADERS -check-prefix=NO-WARN %s
end_comment

begin_comment
comment|// NO-WARN-NOT: {{warning:|error:}}
end_comment

begin_comment
comment|// WARN-SYS-HEADERS: warning: unable to find PS4 system headers directory
end_comment

begin_comment
comment|// WARN-ISYSROOT: warning: no such sysroot directory: 'foo'
end_comment

begin_comment
comment|// WARN-SYS-LIBS: warning: unable to find PS4 system libraries directory
end_comment

begin_comment
comment|// NO-WARN-NOT: {{warning:|error:}}
end_comment

end_unit

