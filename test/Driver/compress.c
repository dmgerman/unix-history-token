begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -integrated-as -Wa,-compress-debug-sections %s 2>&1 | FileCheck --check-prefix=COMPRESS_DEBUG %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -integrated-as -Wa,--compress-debug-sections %s 2>&1 | FileCheck --check-prefix=COMPRESS_DEBUG %s
end_comment

begin_comment
comment|// REQUIRES: zlib
end_comment

begin_comment
comment|// COMPRESS_DEBUG: "-compress-debug-sections"
end_comment

begin_comment
comment|// RUN: %clang -### -c -integrated-as -Wa,--compress-debug-sections -Wa,--nocompress-debug-sections %s 2>&1 | FileCheck --check-prefix=NOCOMPRESS_DEBUG %s
end_comment

begin_comment
comment|// NOCOMPRESS_DEBUG-NOT: "-compress-debug-sections"
end_comment

end_unit

