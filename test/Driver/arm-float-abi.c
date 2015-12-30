begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang %s -target armv7-apple-ios -mfloat-abi=hard 2>&1 | FileCheck -check-prefix=ARMV7-ERROR %s
end_comment

begin_comment
comment|// RUN: %clang %s -target armv7-apple-ios -mfloat-abi=softfp -### 2>&1 | FileCheck -check-prefix=NOERROR %s
end_comment

begin_comment
comment|// RUN: %clang %s -arch armv7 -target thumbv7-apple-darwin-eabi -mfloat-abi=hard -### 2>&1 | FileCheck -check-prefix=NOERROR %s
end_comment

begin_comment
comment|// ARMV7-ERROR: unsupported option '-mfloat-abi=hard' for target 'thumbv7'
end_comment

begin_comment
comment|// NOERROR-NOT: unsupported option
end_comment

end_unit

