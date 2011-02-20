begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin10 -target-cpu cortex-a8 -fsyntax-only -Wvector-conversions -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin10 -target-cpu cortex-a8 -fsyntax-only -fno-lax-vector-conversions -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple thumbv7-apple-darwin10 -target-cpu cortex-a8 -fsyntax-only -Wvector-conversions -ffreestanding %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

end_unit

