begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: zlib
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -Wa,-compress-debug-sections -c %s 2>&1 | FileCheck -check-prefix CHECK-_COMPRESS_DEBUG_SECTIONS %s
end_comment

begin_comment
comment|// CHECK-_COMPRESS_DEBUG_SECTIONS: "-compress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -Wa,--compress-debug-sections -c %s 2>&1 | FileCheck -check-prefix CHECK-__COMPRESS_DEBUG_SECTIONS %s
end_comment

begin_comment
comment|// CHECK-__COMPRESS_DEBUG_SECTIONS: "--compress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -Wa,--compress-debug-sections -Wa,--nocompress-debug-sections -c %s 2>&1 | FileCheck -check-prefix CHECK-POSNEG %s
end_comment

begin_comment
comment|// CHECK-POSNEG: "--compress-debug-sections"
end_comment

begin_comment
comment|// CHECK-POSNEG: "--nocompress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -Wa,-compress-debug-sections -Wa,--compress-debug-sections -c %s 2>&1 | FileCheck -check-prefix CHECK-MULTIPLE %s
end_comment

begin_comment
comment|// CHECK-MULTIPLE: "-compress-debug-sections"
end_comment

begin_comment
comment|// CHECK-MULTIPLE: "--compress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz -x assembler -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ %s
end_comment

begin_comment
comment|// CHECK-OPT_GZ: "-compress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=none -x assembler -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_NONE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=none -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_NONE %s
end_comment

begin_comment
comment|// CHECK-OPT_GZ_EQ_NONE: "-compress-debug-sections=none"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=zlib -x assembler -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_ZLIB %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=zlib -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_ZLIB %s
end_comment

begin_comment
comment|// CHECK-OPT_GZ_EQ_ZLIB: "-compress-debug-sections=zlib"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=zlib-gnu -x assembler -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_ZLIB_GNU %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=zlib-gnu -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_ZLIB_GNU %s
end_comment

begin_comment
comment|// CHECK-OPT_GZ_EQ_ZLIB_GNU: "-compress-debug-sections=zlib-gnu"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=invalid -x assembler -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_INVALID %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux-gnu -fno-integrated-as -gz=invalid -c %s 2>&1 | FileCheck -check-prefix CHECK-OPT_GZ_EQ_INVALID %s
end_comment

begin_comment
comment|// CHECK-OPT_GZ_EQ_INVALID: error: unsupported argument 'invalid' to option 'gz='
end_comment

end_unit

