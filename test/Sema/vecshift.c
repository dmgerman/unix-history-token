begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -DERR -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wno-error-vec-elem-size -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -DEXT -DERR -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -DEXT -Wno-error-vec-elem-size -verify %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXT
end_ifdef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|char
name|vector_char8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|short
name|vector_short8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|int
name|vector_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|char
name|vector_char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|short
name|vector_short4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|int
name|vector_int4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint4
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|char
name|vector_char8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|short
name|vector_short8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|32
argument|))
argument_list|)
name|int
name|vector_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|32
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|char
name|vector_char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|short
name|vector_short4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|int
name|vector_int4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint4
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_char8
name|vc8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_short8
name|vs8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_int8
name|vi8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uchar8
name|vuc8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_ushort8
name|vus8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uint8
name|vui8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_char4
name|vc4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_short4
name|vs4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_int4
name|vi4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uchar4
name|vuc4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_ushort4
name|vus4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uint4
name|vui4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|vc8
operator|=
literal|1
operator|<<
name|vc8
expr_stmt|;
name|vuc8
operator|=
literal|1
operator|<<
name|vuc8
expr_stmt|;
name|vi8
operator|=
literal|1
operator|<<
name|vi8
expr_stmt|;
name|vui8
operator|=
literal|1
operator|<<
name|vui8
expr_stmt|;
name|vs8
operator|=
literal|1
operator|<<
name|vs8
expr_stmt|;
name|vus8
operator|=
literal|1
operator|<<
name|vus8
expr_stmt|;
name|vc8
operator|=
name|c
operator|<<
name|vc8
expr_stmt|;
name|vuc8
operator|=
name|i
operator|<<
name|vuc8
expr_stmt|;
name|vi8
operator|=
name|uc
operator|<<
name|vi8
expr_stmt|;
name|vui8
operator|=
name|us
operator|<<
name|vui8
expr_stmt|;
name|vs8
operator|=
name|ui
operator|<<
name|vs8
expr_stmt|;
name|vus8
operator|=
literal|1
operator|<<
name|vus8
expr_stmt|;
name|vc8
operator|=
name|vc8
operator|<<
name|vc8
expr_stmt|;
ifdef|#
directive|ifdef
name|ERR
name|vi8
operator|=
name|vi8
operator|<<
name|vuc8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vuc8
operator|=
name|vuc8
operator|<<
name|vi8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vus8
operator|=
name|vus8
operator|<<
name|vui8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vui8
operator|=
name|vui8
operator|<<
name|vs8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
else|#
directive|else
name|vi8
operator|=
name|vi8
operator|<<
name|vuc8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vuc8
operator|=
name|vuc8
operator|<<
name|vi8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vus8
operator|=
name|vus8
operator|<<
name|vui8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vui8
operator|=
name|vui8
operator|<<
name|vs8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
endif|#
directive|endif
name|vc8
operator|<<=
name|vc8
expr_stmt|;
ifdef|#
directive|ifdef
name|ERR
name|vi8
operator|<<=
name|vuc8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vuc8
operator|<<=
name|vi8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vus8
operator|<<=
name|vui8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
name|vui8
operator|<<=
name|vs8
expr_stmt|;
comment|// expected-error {{vector operands do not have the same elements sizes}}
else|#
directive|else
name|vi8
operator|<<=
name|vuc8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vuc8
operator|<<=
name|vi8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vus8
operator|<<=
name|vui8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
name|vui8
operator|<<=
name|vs8
expr_stmt|;
comment|// expected-warning {{vector operands do not have the same elements sizes}}
endif|#
directive|endif
name|c
operator|<<=
name|vc8
expr_stmt|;
comment|// expected-error {{assigning to 'char' from incompatible type}}
name|i
operator|<<=
name|vuc8
expr_stmt|;
comment|// expected-error {{assigning to 'int' from incompatible type}}
name|uc
operator|<<=
name|vi8
expr_stmt|;
comment|// expected-error {{assigning to 'unsigned char' from incompatible type}}
name|us
operator|<<=
name|vui8
expr_stmt|;
comment|// expected-error {{assigning to 'unsigned short' from incompatible type}}
name|ui
operator|<<=
name|vs8
expr_stmt|;
comment|// expected-error {{assigning to 'unsigned int' from incompatible type}}
block|}
end_function

end_unit

