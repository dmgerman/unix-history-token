begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64le-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-feature +crypto -target-feature +power8-vector \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-feature +crypto -target-feature +power8-vector \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_define
define|#
directive|define
name|B_INIT1
value|{ 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \                   0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10 };
end_define

begin_define
define|#
directive|define
name|B_INIT2
value|{ 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, \                   0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x70 };
end_define

begin_define
define|#
directive|define
name|H_INIT1
value|{ 0x0102, 0x0304, 0x0506, 0x0708, \                   0x090A, 0x0B0C, 0x0D0E, 0x0F10 };
end_define

begin_define
define|#
directive|define
name|H_INIT2
value|{ 0x7172, 0x7374, 0x7576, 0x7778, \                   0x797A, 0x7B7C, 0x7D7E, 0x7F70 };
end_define

begin_define
define|#
directive|define
name|W_INIT1
value|{ 0x01020304, 0x05060708, \                   0x090A0B0C, 0x0D0E0F10 };
end_define

begin_define
define|#
directive|define
name|W_INIT2
value|{ 0x71727374, 0x75767778, \                   0x797A7B7C, 0x7D7E7F70 };
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
comment|// CHECK-LABEL: define<16 x i8> @test_vpmsumb
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vpmsumb
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|__builtin_altivec_crypto_vpmsumb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumb
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vpmsumh
end_comment

begin_function
name|vector
name|unsigned
name|short
name|test_vpmsumh
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|short
name|a
init|=
name|H_INIT1
name|vector
name|unsigned
name|short
name|b
operator|=
name|H_INIT2
return|return
name|__builtin_altivec_crypto_vpmsumh
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumh
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vpmsumw
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vpmsumw
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
name|vector
name|unsigned
name|int
name|b
operator|=
name|W_INIT2
return|return
name|__builtin_altivec_crypto_vpmsumw
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vpmsumd
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vpmsumd
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vpmsumd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumd
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsbox
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vsbox
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
return|return
name|__builtin_altivec_crypto_vsbox
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vsbox
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vpermxorb
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vpermxorb
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
name|vector
name|unsigned
name|char
name|c
operator|=
name|B_INIT2
return|return
name|__builtin_altivec_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vpermxorh
end_comment

begin_function
name|vector
name|unsigned
name|short
name|test_vpermxorh
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|short
name|a
init|=
name|H_INIT1
name|vector
name|unsigned
name|short
name|b
operator|=
name|H_INIT2
name|vector
name|unsigned
name|short
name|c
operator|=
name|H_INIT2
return|return
name|__builtin_altivec_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vpermxorw
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vpermxorw
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
name|vector
name|unsigned
name|int
name|b
operator|=
name|W_INIT2
name|vector
name|unsigned
name|int
name|c
operator|=
name|W_INIT2
return|return
name|__builtin_altivec_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vpermxord
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vpermxord
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
name|vector
name|unsigned
name|long
name|long
name|c
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpermxorbc
end_comment

begin_function
name|vector
name|bool
name|char
name|test_vpermxorbc
parameter_list|(
name|vector
name|bool
name|char
name|a
parameter_list|,
name|vector
name|bool
name|char
name|b
parameter_list|,
name|vector
name|bool
name|char
name|c
parameter_list|)
block|{
return|return
name|vec_permxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpermxorsc
end_comment

begin_function
name|vector
name|signed
name|char
name|test_vpermxorsc
parameter_list|(
name|vector
name|signed
name|char
name|a
parameter_list|,
name|vector
name|signed
name|char
name|b
parameter_list|,
name|vector
name|signed
name|char
name|c
parameter_list|)
block|{
return|return
name|vec_permxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpermxoruc
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vpermxoruc
parameter_list|(
name|vector
name|unsigned
name|char
name|a
parameter_list|,
name|vector
name|unsigned
name|char
name|b
parameter_list|,
name|vector
name|unsigned
name|char
name|c
parameter_list|)
block|{
return|return
name|vec_permxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcipher
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vcipher
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vcipher
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcipherlast
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vcipherlast
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vcipherlast
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vncipher
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vncipher
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vncipher
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vncipherlast
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vncipherlast
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vncipherlast
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vshasigmaw
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vshasigmaw
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
return|return
name|__builtin_altivec_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmaw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vshasigmad
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vshasigmad
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT2
return|return
name|__builtin_altivec_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmad
block|}
end_function

begin_comment
comment|// Test cases for the builtins the way they are exposed to
end_comment

begin_comment
comment|// users through altivec.h
end_comment

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vpmsumb_e
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vpmsumb_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|__builtin_crypto_vpmsumb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumb
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vpmsumh_e
end_comment

begin_function
name|vector
name|unsigned
name|short
name|test_vpmsumh_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|short
name|a
init|=
name|H_INIT1
name|vector
name|unsigned
name|short
name|b
operator|=
name|H_INIT2
return|return
name|__builtin_crypto_vpmsumb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumh
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vpmsumw_e
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vpmsumw_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
name|vector
name|unsigned
name|int
name|b
operator|=
name|W_INIT2
return|return
name|__builtin_crypto_vpmsumb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vpmsumd_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vpmsumd_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vpmsumb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumd
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsbox_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vsbox_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
return|return
name|__builtin_crypto_vsbox
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vsbox
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vpermxorb_e
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vpermxorb_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
name|vector
name|unsigned
name|char
name|c
operator|=
name|B_INIT2
return|return
name|__builtin_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vpermxorh_e
end_comment

begin_function
name|vector
name|unsigned
name|short
name|test_vpermxorh_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|short
name|a
init|=
name|H_INIT1
name|vector
name|unsigned
name|short
name|b
operator|=
name|H_INIT2
name|vector
name|unsigned
name|short
name|c
operator|=
name|H_INIT2
return|return
name|__builtin_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vpermxorw_e
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vpermxorw_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
name|vector
name|unsigned
name|int
name|b
operator|=
name|W_INIT2
name|vector
name|unsigned
name|int
name|c
operator|=
name|W_INIT2
return|return
name|__builtin_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vpermxord_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vpermxord_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
name|vector
name|unsigned
name|long
name|long
name|c
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vpermxor
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpermxor
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcipher_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vcipher_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vcipher
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcipherlast_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vcipherlast_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vcipherlast
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vncipher_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vncipher_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vncipher
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vncipherlast_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vncipherlast_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|__builtin_crypto_vncipherlast
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vshasigmaw_e
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vshasigmaw_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
return|return
name|__builtin_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmaw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vshasigmad_e
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vshasigmad_e
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT2
return|return
name|__builtin_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmad
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_sbox_be
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vec_sbox_be
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
return|return
name|vec_sbox_be
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vsbox
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_cipher_be
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vec_cipher_be
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|vec_cipher_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_cipherlast_be
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vec_cipherlast_be
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|vec_cipherlast_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vcipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_ncipher_be
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vec_ncipher_be
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|vec_ncipher_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipher
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_ncipherlast_be
end_comment

begin_function
name|vector
name|unsigned
name|char
name|test_vec_ncipherlast_be
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|vec_ncipherlast_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vncipherlast
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_shasigma_bew
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vec_shasigma_bew
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
return|return
name|vec_shasigma_be
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmaw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_shasigma_bed
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vec_shasigma_bed
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT2
return|return
name|vec_shasigma_be
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vshasigmad
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_pmsum_beb
end_comment

begin_function
name|vector
name|unsigned
name|short
name|test_vec_pmsum_beb
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|char
name|a
init|=
name|B_INIT1
name|vector
name|unsigned
name|char
name|b
operator|=
name|B_INIT2
return|return
name|vec_pmsum_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumb
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_pmsum_beh
end_comment

begin_function
name|vector
name|unsigned
name|int
name|test_vec_pmsum_beh
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|short
name|a
init|=
name|H_INIT1
name|vector
name|unsigned
name|short
name|b
operator|=
name|H_INIT2
return|return
name|vec_pmsum_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumh
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_pmsum_bew
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vec_pmsum_bew
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT1
name|vector
name|unsigned
name|int
name|b
operator|=
name|W_INIT2
return|return
name|vec_pmsum_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumw
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vec_pmsum_bed
end_comment

begin_function
name|vector
name|unsigned
name|__int128
name|test_vec_pmsum_bed
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|long
name|long
name|a
init|=
name|D_INIT1
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|D_INIT2
return|return
name|vec_pmsum_be
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.altivec.crypto.vpmsumd
block|}
end_function

end_unit

