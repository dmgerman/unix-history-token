begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that ld gets arch_multiple.
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -arch i386 -arch x86_64 %s -### -o foo 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '".*ld.*" .*"-arch_multiple" "-final_output" "foo"' %t.log
end_comment

begin_comment
comment|// Make sure we run dsymutil on source input files.
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -g %s -o BAR 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '".*dsymutil" "-o" "BAR.dSYM" "BAR"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -g -filelist FOO %s -o BAR 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '".*dsymutil" "-o" "BAR.dSYM" "BAR"' %t.log
end_comment

begin_comment
comment|// Check linker changes that came with new linkedit format.
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv6 -miphoneos-version-min=3.0 %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv6 -miphoneos-version-min=3.0 -dynamiclib %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv6 -miphoneos-version-min=3.0 -bundle %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IPHONE_3_0 %s< %t.log
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -iphoneos_version_min
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: 3.0.0
end_comment

begin_comment
comment|// LINK_IPHONE_3_0-NOT: -lcrt1.3.1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -lcrt1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -lSystem
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -dylib
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -ldylib1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -lSystem
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -lbundle1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_0: -lSystem
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv7 -miphoneos-version-min=3.1 %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv7 -miphoneos-version-min=3.1 -dynamiclib %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch armv7 -miphoneos-version-min=3.1 -bundle %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IPHONE_3_1 %s< %t.log
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -iphoneos_version_min
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: 3.1.0
end_comment

begin_comment
comment|// LINK_IPHONE_3_1-NOT: -lcrt1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -lcrt1.3.1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -lSystem
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -dylib
end_comment

begin_comment
comment|// LINK_IPHONE_3_1-NOT: -ldylib1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -lSystem
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IPHONE_3_1-NOT: -lbundle1.o
end_comment

begin_comment
comment|// LINK_IPHONE_3_1: -lSystem
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch i386 -mios-simulator-version-min=3.0 %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch i386 -mios-simulator-version-min=3.0 -dynamiclib %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -arch i386 -mios-simulator-version-min=3.0 -bundle %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IOSSIM_3_0 %s< %t.log
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: -ios_simulator_version_min
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: 3.0.0
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0-NOT: -lcrt1.o
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: -lSystem
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: -dylib
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0-NOT: -ldylib1.o
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: -lSystem
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0-NOT: -lbundle1.o
end_comment

begin_comment
comment|// LINK_IOSSIM_3_0: -lSystem
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -fpie %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_EXPLICIT_PIE %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_EXPLICIT_PIE: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_EXPLICIT_PIE: "-pie"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -fno-pie %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_EXPLICIT_NO_PIE %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_EXPLICIT_NO_PIE: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_EXPLICIT_NO_PIE: "-no_pie"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=100 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NEWER_DEMANGLE %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_NEWER_DEMANGLE: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_NEWER_DEMANGLE: "-demangle"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=100 -Wl,--no-demangle 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NEWER_NODEMANGLE %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_NEWER_NODEMANGLE: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_NEWER_NODEMANGLE-NOT: "-demangle"
end_comment

begin_comment
comment|// LINK_NEWER_NODEMANGLE: "-lSystem"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=95 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_OLDER_NODEMANGLE %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_OLDER_NODEMANGLE: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_OLDER_NODEMANGLE-NOT: "-demangle"
end_comment

begin_comment
comment|// LINK_OLDER_NODEMANGLE: "-lSystem"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=117 -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: cat %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_OBJECT_LTO_PATH %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_OBJECT_LTO_PATH: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_OBJECT_LTO_PATH: "-object_path_lto"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -force_load a -force_load b 2> %t.log
end_comment

begin_comment
comment|// RUN: cat %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=FORCE_LOAD %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FORCE_LOAD: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// FORCE_LOAD: "-force_load" "a" "-force_load" "b"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -lazy_framework Framework 2> %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LAZY_FRAMEWORK %s< %t.log
end_comment

begin_comment
comment|// LINK_LAZY_FRAMEWORK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_LAZY_FRAMEWORK: "-lazy_framework" "Framework"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o \
end_comment

begin_comment
comment|// RUN:   -lazy_library Library 2> %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LAZY_LIBRARY %s< %t.log
end_comment

begin_comment
comment|// LINK_LAZY_LIBRARY: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_LAZY_LIBRARY: "-lazy_library" "Library"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.7 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_VERSION_MIN %s< %t.log
end_comment

begin_comment
comment|// LINK_VERSION_MIN: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_VERSION_MIN: "-macosx_version_min" "10.6.0"
end_comment

begin_comment
comment|// LINK_VERSION_MIN: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_VERSION_MIN: "-macosx_version_min" "10.7.0"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin12 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NO_CRT1 %s< %t.log
end_comment

begin_comment
comment|// LINK_NO_CRT1-NOT: crt
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios6.0 -miphoneos-version-min=6.0 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NO_IOS_CRT1 %s< %t.log
end_comment

begin_comment
comment|// LINK_NO_IOS_CRT1-NOT: crt
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios5.0 -miphoneos-version-min=5.0 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NO_IOS_ARM64_CRT1 %s< %t.log
end_comment

begin_comment
comment|// LINK_NO_IOS_ARM64_CRT1-NOT: crt
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin12 -pg -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_PG %s< %t.log
end_comment

begin_comment
comment|// LINK_PG: -lgcrt1.o
end_comment

begin_comment
comment|// LINK_PG: -no_new_main
end_comment

begin_comment
comment|// Check that clang links with libgcc_s.1 for iOS 4 and earlier, but not arm64.
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios4.0 -miphoneos-version-min=4.0 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IOS_LIBGCC_S %s< %t.log
end_comment

begin_comment
comment|// LINK_IOS_LIBGCC_S: lgcc_s.1
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios4.0 -miphoneos-version-min=4.0 -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NO_IOS_ARM64_LIBGCC_S %s< %t.log
end_comment

begin_comment
comment|// LINK_NO_IOS_ARM64_LIBGCC_S-NOT: lgcc_s.1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin12 -rdynamic -### %t.o \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=100 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_NO_EXPORT_DYNAMIC %s< %t.log
end_comment

begin_comment
comment|// LINK_NO_EXPORT_DYNAMIC: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_NO_EXPORT_DYNAMIC-NOT: "-export_dynamic"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin12 -rdynamic -### %t.o \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=137 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_EXPORT_DYNAMIC %s< %t.log
end_comment

begin_comment
comment|// LINK_EXPORT_DYNAMIC: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_EXPORT_DYNAMIC: "-export_dynamic"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64h-apple-darwin -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_X86_64H_ARCH %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_X86_64H_ARCH: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_X86_64H_ARCH: "x86_64h"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch x86_64 -arch x86_64h -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_X86_64H_MULTIARCH %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_X86_64H_MULTIARCH: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_X86_64H_MULTIARCH: "x86_64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_X86_64H_MULTIARCH: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_X86_64H_MULTIARCH: "x86_64h"
end_comment

begin_comment
comment|// Check for the linker options to specify the iOS version when the
end_comment

begin_comment
comment|// IPHONEOS_DEPLOYMENT_TARGET variable is used instead of the command-line
end_comment

begin_comment
comment|// deployment target options.
end_comment

begin_comment
comment|// RUN: env IPHONEOS_DEPLOYMENT_TARGET=7.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target arm64-apple-darwin -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IPHONEOS_VERSION_MIN %s< %t.log
end_comment

begin_comment
comment|// RUN: env IPHONEOS_DEPLOYMENT_TARGET=7.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target i386-apple-darwin -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_IOS_SIMULATOR_VERSION_MIN %s< %t.log
end_comment

begin_comment
comment|// LINK_IPHONEOS_VERSION_MIN: -iphoneos_version_min
end_comment

begin_comment
comment|// LINK_IOS_SIMULATOR_VERSION_MIN: -ios_simulator_version_min
end_comment

end_unit

