begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -target-cpu power8 \
end_comment

begin_comment
comment|// RUN:     -target-feature +altivec -verify %s
end_comment

begin_comment
comment|// Test special behavior of Altivec intrinsics in this file.
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_macro
name|__attribute__
argument_list|(
argument|(__aligned__(
literal|16
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|float
name|x
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|vector
name|unsigned
name|char
name|l
init|=
name|vec_lvsl
argument_list|(
literal|0
argument_list|,
operator|&
name|x
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
comment|// expected-warning {{is deprecated: use assignment for unaligned little endian loads/stores}}
name|vector
name|unsigned
name|char
name|r
init|=
name|vec_lvsr
argument_list|(
literal|0
argument_list|,
operator|&
name|x
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
comment|// expected-warning {{is deprecated: use assignment for unaligned little endian loads/stores}}
block|}
end_function

begin_comment
comment|// FIXME: As noted in ms-intrin.cpp, it would be nice if we didn't have to
end_comment

begin_comment
comment|// hard-code the line number from altivec.h here.
end_comment

begin_comment
comment|// expected-note@altivec.h:* {{deprecated here}}
end_comment

begin_comment
comment|// expected-note@altivec.h:* {{deprecated here}}
end_comment

end_unit

