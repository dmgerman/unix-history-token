begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -xc++ -std=c++11 -fsyntax-only -verify %s
end_comment

begin_assert
assert|_Static_assert
argument_list|(
literal|"foo"
argument_list|,
literal|"string is nonzero"
argument_list|)
assert|;
end_assert

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|// expected-error@-2 {{static_assert expression is not an integral constant expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
literal|"1 is nonzero"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
literal|0
argument_list|,
literal|"0 is nonzero"
argument_list|)
assert|;
end_assert

begin_comment
comment|// expected-error {{static_assert failed "0 is nonzero"}}
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
literal|"1 is nonzero"
argument_list|)
assert|;
assert|_Static_assert
argument_list|(
literal|0
argument_list|,
literal|"0 is nonzero"
argument_list|)
assert|;
comment|// expected-error {{static_assert failed "0 is nonzero"}}
block|}
end_function

begin_assert
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
name|invalid
argument_list|)
assert|;
end_assert

begin_comment
comment|// expected-error {{expected string literal for diagnostic message in static_assert}}
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|a
decl_stmt|;
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
literal|"1 is nonzero"
argument_list|)
assert|;
assert|_Static_assert
argument_list|(
literal|0
argument_list|,
literal|"0 is nonzero"
argument_list|)
assert|;
comment|// expected-error {{static_assert failed "0 is nonzero"}}
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|ASSERT_IS_TYPE
parameter_list|(
name|T
parameter_list|)
value|__is_same(T, T)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_IS_TYPE
parameter_list|(
name|T
parameter_list|)
value|__builtin_types_compatible_p(T, T)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UNION
parameter_list|(
name|T1
parameter_list|,
name|T2
parameter_list|)
value|union { \     __typeof__(T1) one; \     __typeof__(T2) two; \     _Static_assert(ASSERT_IS_TYPE(T1), "T1 is not a type"); \     _Static_assert(ASSERT_IS_TYPE(T2), "T2 is not a type"); \     _Static_assert(sizeof(T1) == sizeof(T2), "type size mismatch"); \   }
end_define

begin_typedef
typedef|typedef
name|UNION
argument_list|(
argument|unsigned
argument_list|,
argument|struct A
argument_list|)
name|U1
expr_stmt|;
end_typedef

begin_macro
name|UNION
argument_list|(
argument|char[
literal|2
argument|]
argument_list|,
argument|short
argument_list|)
end_macro

begin_expr_stmt
name|u2
operator|=
block|{
operator|.
name|one
operator|=
block|{
literal|'a'
block|,
literal|'b'
block|}
block|}
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|UNION
argument_list|(
argument|char
argument_list|,
argument|short
argument_list|)
name|U3
expr_stmt|;
end_typedef

begin_comment
comment|// expected-error {{static_assert failed "type size mismatch"}}
end_comment

begin_typedef
typedef|typedef
name|UNION
argument_list|(
argument|float
argument_list|,
literal|0.5f
argument_list|)
name|U4
expr_stmt|;
end_typedef

begin_comment
comment|// expected-error {{expected a type}}
end_comment

end_unit

