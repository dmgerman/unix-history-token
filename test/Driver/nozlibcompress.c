begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -c %s -Wa,--compress-debug-sections 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -c %s -Wa,--compress-debug-sections -Wa,--nocompress-debug-sections 2>&1 | FileCheck --check-prefix=NOWARN %s
end_comment

begin_comment
comment|// REQUIRES: nozlib
end_comment

begin_comment
comment|// CHECK: warning: cannot compress debug sections (zlib not installed)
end_comment

begin_comment
comment|// NOWARN-NOT: warning: cannot compress debug sections (zlib not installed)
end_comment

end_unit

