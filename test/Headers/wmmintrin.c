begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that wmmintrin.h is includable with just -maes.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown \
end_comment

begin_comment
comment|// RUN:   -verify %s -ffreestanding -target-feature +aes
end_comment

begin_include
include|#
directive|include
file|<wmmintrin.h>
end_include

end_unit

