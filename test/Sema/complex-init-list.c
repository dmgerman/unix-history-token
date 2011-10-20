begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_comment
comment|// This file tests the clang extension which allows initializing the components
end_comment

begin_comment
comment|// of a complex number individually using an initialization list. Basically,
end_comment

begin_comment
comment|// if you have an explicit init list for a complex number that contains two
end_comment

begin_comment
comment|// initializers, this extension kicks in to turn it into component-wise
end_comment

begin_comment
comment|// initialization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This extension is useful because there isn't any way to accurately build
end_comment

begin_comment
comment|// a complex number at the moment besides setting the components with
end_comment

begin_comment
comment|// __real__ and __imag__, which is inconvenient and not usable for constants.
end_comment

begin_comment
comment|// (Of course, there are other extensions we could implement that would
end_comment

begin_comment
comment|// allow this, like some sort of __builtin_build_complex.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: It would be a good idea to have a warnings for implicit
end_comment

begin_comment
comment|// real->complex and complex->real conversions; as-is, it's way too easy
end_comment

begin_comment
comment|// to get implicit conversions when they are not intended.
end_comment

begin_comment
comment|// Basic testcase
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|valid1
init|=
block|{
literal|1.0f
block|,
literal|2.0f
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{specifying real and imaginary components is an extension}}
end_comment

begin_comment
comment|// Struct for nesting tests
end_comment

begin_struct
struct|struct
name|teststruct
block|{
specifier|_Complex
name|float
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Random other valid stuff
end_comment

begin_decl_stmt
specifier|_Complex
name|int
name|valid2
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{complex integer}} expected-warning {{specifying real and imaginary components is an extension}}
end_comment

begin_decl_stmt
name|struct
name|teststruct
name|valid3
init|=
block|{
block|{
literal|1.0f
block|,
literal|2.0f
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{specifying real and imaginary components is an extension}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|valid4
index|[
literal|2
index|]
init|=
block|{
block|{
literal|1.0f
block|,
literal|1.0f
block|}
block|,
block|{
literal|1.0f
block|,
literal|1.0f
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning 2 {{specifying real and imaginary components is an extension}}
end_comment

begin_comment
comment|// FIXME: We need some sort of warning for valid5
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|valid5
init|=
block|{
literal|1.0f
block|,
literal|1.0fi
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{imaginary constants}} expected-warning {{specifying real and imaginary components is an extension}}
end_comment

begin_comment
comment|// Random invalid stuff
end_comment

begin_decl_stmt
name|struct
name|teststruct
name|invalid1
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{excess elements}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|invalid2
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{excess elements}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|invalid3
init|=
block|{}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{scalar initializer cannot be empty}} expected-warning {{GNU empty initializer}}
end_comment

begin_comment
comment|// Check incomplete array sizing
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|sizetest1
index|[]
init|=
block|{
block|{
literal|1.0f
block|,
literal|1.0f
block|}
block|,
block|{
literal|1.0f
block|,
literal|1.0f
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning 2 {{specifying real and imaginary components is an extension}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|sizecheck1
index|[
operator|(
sizeof|sizeof
argument_list|(
name|sizetest1
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
operator|*
name|sizetest1
argument_list|)
operator|*
literal|2
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|float
name|sizetest2
index|[]
init|=
block|{
literal|1.0f
block|,
literal|1.0f
block|,
block|{
literal|1.0f
block|,
literal|1.0f
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{specifying real and imaginary components is an extension}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|sizecheck2
index|[
operator|(
sizeof|sizeof
argument_list|(
name|sizetest2
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
operator|*
name|sizetest2
argument_list|)
operator|*
literal|3
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

