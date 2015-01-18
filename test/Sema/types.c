begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fblocks -pedantic -verify -triple=x86_64-apple-darwin9
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fblocks -pedantic -verify -triple=mips64-linux-gnu
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fblocks -pedantic -verify -triple=x86_64-unknown-linux
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fblocks -pedantic -verify -triple=x86_64-unknown-linux-gnux32
end_comment

begin_comment
comment|// rdar://6097662
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
name|T
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|restrict
name|T
name|x
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
modifier|*
name|S
index|[
literal|2
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|restrict
name|S
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{restrict requires a pointer or reference ('S' (aka 'int *[2]') is invalid)}}
end_comment

begin_comment
comment|// int128_t is available.
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|__int128_t
name|s
decl_stmt|;
name|__uint128_t
name|t
decl_stmt|;
block|}
end_function

begin_comment
comment|// but not a keyword
end_comment

begin_function
name|int
name|b
parameter_list|()
block|{
name|int
name|__int128_t
decl_stmt|;
name|int
name|__uint128_t
decl_stmt|;
block|}
end_function

begin_comment
comment|// __int128 is a keyword
end_comment

begin_function
name|int
name|c
parameter_list|()
block|{
name|__int128
name|i
decl_stmt|;
name|unsigned
name|__int128
name|j
decl_stmt|;
name|long
name|unsigned
name|__int128
name|k
decl_stmt|;
comment|// expected-error {{'long __int128' is invalid}}
name|int
name|__int128
decl_stmt|;
comment|// expected-error {{cannot combine with previous}} expected-warning {{does not declare anything}}
block|}
end_function

begin_comment
comment|// __int128_t is __int128; __uint128_t is unsigned __int128.
end_comment

begin_typedef
typedef|typedef
name|__int128
name|check_int_128
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int128_t
name|check_int_128
typedef|;
end_typedef

begin_comment
comment|// expected-note {{here}}
end_comment

begin_typedef
typedef|typedef
name|int
name|check_int_128
typedef|;
end_typedef

begin_comment
comment|// expected-error {{different types ('int' vs '__int128_t' (aka '__int128'))}}
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int128
name|check_uint_128
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint128_t
name|check_uint_128
typedef|;
end_typedef

begin_comment
comment|// expected-note {{here}}
end_comment

begin_typedef
typedef|typedef
name|int
name|check_uint_128
typedef|;
end_typedef

begin_comment
comment|// expected-error {{different types ('int' vs '__uint128_t' (aka 'unsigned __int128'))}}
end_comment

begin_comment
comment|// Array type merging should convert array size to whatever matches the target
end_comment

begin_comment
comment|// pointer size.
end_comment

begin_comment
comment|// rdar://6880874
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i
index|[
literal|1LL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
index|[
operator|(
name|short
operator|)
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|e
block|{
name|e_1
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|j
index|[
sizeof|sizeof
argument_list|(
expr|enum
name|e
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_decl_stmt
name|int
name|j
index|[
literal|42
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'j' with a different type: 'int [42]' vs 'int [4]'}}
end_comment

begin_comment
comment|// rdar://6880104
end_comment

begin_decl_stmt
name|_Decimal32
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{GNU decimal type extension not supported}}
end_comment

begin_comment
comment|// rdar://6880951
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|,
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|v
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid vector element type}}
end_comment

begin_function
name|void
name|test
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|char
name|c
init|=
operator|(
name|char
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
operator|)
name|i
decl_stmt|;
comment|// expected-warning {{'aligned' attribute ignored when parsing type}}
block|}
end_function

begin_comment
comment|// http://llvm.org/PR11082
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This may or may not be the correct approach (no warning or error),
end_comment

begin_comment
comment|// but large amounts of Linux and FreeBSD code need this attribute to not be
end_comment

begin_comment
comment|// a hard error in order to work correctly.
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|char
name|c
init|=
operator|(
name|char
name|__attribute__
argument_list|(
operator|(
name|may_alias
operator|)
argument_list|)
operator|)
name|i
decl_stmt|;
block|}
end_function

begin_comment
comment|// vector size too large
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8192
argument_list|)
operator|)
argument_list|)
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{vector size too large}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|ext_vector_type
argument_list|(
literal|8192
argument_list|)
operator|)
argument_list|)
name|x2
typedef|;
end_typedef

begin_comment
comment|// expected-error {{vector size too large}}
end_comment

begin_comment
comment|// no support for vector enum type
end_comment

begin_enum
enum|enum
block|{
name|e_2
block|}
name|x3
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
enum|;
end_enum

begin_comment
comment|// expected-error {{invalid vector element type}}
end_comment

begin_decl_stmt
name|int
name|x4
name|__attribute__
argument_list|(
operator|(
name|ext_vector_type
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'ext_vector_type' attribute only applies to types}}
end_comment

begin_comment
comment|// rdar://16492792
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|32
argument|),__aligned__(
literal|32
argument|))
argument_list|)
name|unsigned
name|char
name|uchar32
typedef|;
end_typedef

begin_function
name|void
name|convert
parameter_list|()
block|{
name|uchar32
name|r
init|=
literal|0
decl_stmt|;
name|r
operator|.
name|s
index|[
literal|1234
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-error {{illegal vector component name 's'}}
block|}
end_function

begin_decl_stmt
name|int
modifier|&
modifier|*
specifier|_Atomic
name|null_type_0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected identifier or '('}}
end_comment

begin_decl_stmt
name|int
modifier|&
modifier|*
name|__restrict__
name|null_type_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected identifier or '('}}
end_comment

begin_decl_stmt
name|int
modifier|^
specifier|_Atomic
name|null_type_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{block pointer to non-function type is invalid}}
end_comment

end_unit

