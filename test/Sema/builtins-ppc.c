begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +htm                       \
end_comment

begin_comment
comment|// RUN: -triple powerpc64-unknown-unknown -DTEST_HTM -fsyntax-only      \
end_comment

begin_comment
comment|// RUN: -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +crypto                    \
end_comment

begin_comment
comment|// RUN: -triple powerpc64le-unknown-unknown -DTEST_CRYPTO -fsyntax-only      \
end_comment

begin_comment
comment|// RUN: -verify %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_HTM
end_ifdef

begin_function
name|void
name|test_htm
parameter_list|()
block|{
name|__builtin_tbegin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|__builtin_tend
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|__builtin_tsr
argument_list|(
literal|55
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 7}}
name|__builtin_tabortwc
argument_list|(
operator|-
literal|5
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
name|__builtin_tabortdc
argument_list|(
literal|55
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
name|__builtin_tabortwci
argument_list|(
operator|-
literal|5
argument_list|,
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
name|__builtin_tabortwci
argument_list|(
literal|5
argument_list|,
literal|2
argument_list|,
literal|55
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
name|__builtin_tabortdci
argument_list|(
operator|-
literal|5
argument_list|,
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
name|__builtin_tabortdci
argument_list|(
literal|5
argument_list|,
literal|2
argument_list|,
literal|55
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 31}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_CRYPTO
end_ifdef

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_define
define|#
directive|define
name|W_INIT
value|{ 0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10 };
end_define

begin_define
define|#
directive|define
name|D_INIT
value|{ 0x0102030405060708, 0x090A0B0C0D0E0F10 };
end_define

begin_function
name|vector
name|unsigned
name|int
name|test_vshasigmaw_or
parameter_list|(
name|void
parameter_list|)
block|{
name|vector
name|unsigned
name|int
name|a
init|=
name|W_INIT
name|vector
name|unsigned
name|int
name|b
operator|=
name|__builtin_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
literal|2
argument_list|,
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|vector
name|unsigned
name|int
name|c
init|=
name|__builtin_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|,
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|vector
name|unsigned
name|int
name|d
init|=
name|__builtin_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|85
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|vector
name|unsigned
name|int
name|e
init|=
name|__builtin_crypto_vshasigmaw
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
operator|-
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
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
block|}
end_function

begin_function
name|vector
name|unsigned
name|long
name|long
name|test_vshasigmad_or
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
name|D_INIT
name|vector
name|unsigned
name|long
name|long
name|b
operator|=
name|__builtin_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
literal|2
argument_list|,
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|vector
name|unsigned
name|long
name|long
name|c
init|=
name|__builtin_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|,
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|vector
name|unsigned
name|long
name|long
name|d
init|=
name|__builtin_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|85
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|vector
name|unsigned
name|long
name|long
name|e
init|=
name|__builtin_crypto_vshasigmad
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
operator|-
literal|15
argument_list|)
decl_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
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
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

