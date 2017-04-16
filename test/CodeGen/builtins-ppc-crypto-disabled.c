begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -target-feature +altivec -triple powerpc64le-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-cpu pwr8 -target-feature -crypto -emit-llvm %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-cpu pwr8 -target-feature -crypto -emit-llvm %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-cpu pwr8 -target-feature -power8-vector \
end_comment

begin_comment
comment|// RUN: -target-feature -crypto -emit-llvm %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=CHECK-P8V
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_define
define|#
directive|define
name|W_INIT1
value|{ 0x01020304, 0x05060708, \                   0x090A0B0C, 0x0D0E0F10 };
end_define

begin_define
define|#
directive|define
name|D_INIT1
value|{ 0x0102030405060708, \                   0x090A0B0C0D0E0F10 };
end_define

begin_define
define|#
directive|define
name|D_INIT2
value|{ 0x7172737475767778, \                   0x797A7B7C7D7E7F70 };
end_define

begin_comment
comment|// Test cases for the builtins the way they are exposed to
end_comment

begin_comment
comment|// users through altivec.h
end_comment

begin_function
name|void
name|call_crypto_intrinsics
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|aw
init|=
name|W_INIT1
name|vector
name|unsigned
name|long
name|long
name|ad
operator|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|bd
operator|=
name|D_INIT2
name|vector
name|unsigned
name|long
name|long
name|cd
operator|=
name|D_INIT2
name|vector
name|unsigned
name|long
name|long
name|r1
operator|=
name|__builtin_crypto_vsbox
argument_list|(
name|ad
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r2
init|=
name|__builtin_crypto_vcipher
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r3
init|=
name|__builtin_crypto_vcipherlast
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r4
init|=
name|__builtin_crypto_vncipher
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r5
init|=
name|__builtin_crypto_vncipherlast
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|int
name|r6
init|=
name|__builtin_crypto_vshasigmaw
argument_list|(
name|aw
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r7
init|=
name|__builtin_crypto_vshasigmad
argument_list|(
name|ad
argument_list|,
literal|0
argument_list|,
literal|15
argument_list|)
decl_stmt|;
comment|// The ones that do not require -mcrypto, but require -mpower8-vector
name|vector
name|unsigned
name|long
name|long
name|r8
init|=
name|__builtin_crypto_vpmsumb
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|)
decl_stmt|;
name|vector
name|unsigned
name|long
name|long
name|r9
init|=
name|__builtin_crypto_vpermxor
argument_list|(
name|ad
argument_list|,
name|bd
argument_list|,
name|cd
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vsbox'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vcipher'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vcipherlast'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vncipher'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vncipherlast'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vshasigmaw'
end_comment

begin_comment
comment|// CHECK: use of unknown builtin '__builtin_crypto_vshasigmad'
end_comment

begin_comment
comment|// CHECK-P8V: use of unknown builtin '__builtin_crypto_vpmsumb'
end_comment

begin_comment
comment|// CHECK-P8V: use of unknown builtin '__builtin_crypto_vpermxor'
end_comment

end_unit

