begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-freebsd -std=c11 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-freebsd -std=c11 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux -std=c11 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -std=c11 -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ABI64
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
expr|sizeof
operator|(
name|long
name|double
operator|)
operator|==
literal|8
argument_list|,
literal|"sizeof long double is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
expr|_Alignof
operator|(
name|long
name|double
operator|)
operator|==
literal|8
argument_list|,
literal|"alignof long double is wrong"
argument_list|)
assert|;
end_assert

begin_else
else|#
directive|else
end_else

begin_assert
assert|_Static_assert
argument_list|(
expr|sizeof
operator|(
name|long
name|double
operator|)
operator|==
literal|16
argument_list|,
literal|"sizeof long double is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
expr|_Alignof
operator|(
name|long
name|double
operator|)
operator|==
literal|16
argument_list|,
literal|"alignof long double is wrong"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_assert
assert|_Static_assert
argument_list|(
expr|sizeof
operator|(
name|long
name|double
operator|)
operator|==
literal|8
argument_list|,
literal|"sizeof long double is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
expr|_Alignof
operator|(
name|long
name|double
operator|)
operator|==
literal|8
argument_list|,
literal|"alignof long double is wrong"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

end_unit

