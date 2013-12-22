begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -target-feature -sse  %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -target-feature -sse -mfpmath 387 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -target-feature +sse %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -target-feature +sse -mfpmath sse %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-linux -target-feature +sse \
end_comment

begin_comment
comment|// RUN: -mfpmath xyz %s 2>&1 | FileCheck --check-prefix=CHECK-XYZ %s
end_comment

begin_comment
comment|// CHECK-XYZ: error: unknown FP unit 'xyz'
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-linux -target-feature +sse \
end_comment

begin_comment
comment|// RUN: -mfpmath 387 %s 2>&1 | FileCheck --check-prefix=CHECK-NO-387 %s
end_comment

begin_comment
comment|// CHECK-NO-387: error: the '387' unit is not supported with this instruction set
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-linux -target-feature -sse \
end_comment

begin_comment
comment|// RUN: -mfpmath sse %s 2>&1 | FileCheck --check-prefix=CHECK-NO-SSE %s
end_comment

begin_comment
comment|// CHECK-NO-SSE: error: the 'sse' unit is not supported with this instruction set
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin10 -mfpmath vfp %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin10 -mfpmath vfp2 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin10 -mfpmath vfp3 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin10 -mfpmath vfp4 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin10 -target-cpu cortex-a9 \
end_comment

begin_comment
comment|// RUN: -mfpmath neon %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple arm-apple-darwin10 -mfpmath foo %s 2>&1 \
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-FOO %s
end_comment

begin_comment
comment|// CHECK-FOO: unknown FP unit 'foo'
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple arm-apple-darwin10 -target-cpu arm1136j-s \
end_comment

begin_comment
comment|// RUN: -mfpmath neon %s 2>&1 | FileCheck --check-prefix=CHECK-NO-NEON %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple arm-apple-darwin10 -target-cpu cortex-a9 \
end_comment

begin_comment
comment|// RUN: -target-feature -neon -mfpmath neon %s 2>&1 | FileCheck --check-prefix=CHECK-NO-NEON %s
end_comment

begin_comment
comment|// CHECK-NO-NEON: error: the 'neon' unit is not supported with this instruction set
end_comment

end_unit

