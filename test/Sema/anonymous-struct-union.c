begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|X
block|{
union|union
block|{
name|float
name|f3
decl_stmt|;
name|double
name|d2
decl_stmt|;
block|}
name|named
union|;
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
union|union
block|{
name|float
name|f2
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
union|;
block|}
union|;
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
struct|;
block|}
struct|;
end_struct

begin_function
name|void
name|test_unqual_references
parameter_list|(
name|struct
name|X
name|x
parameter_list|,
specifier|const
name|struct
name|X
name|xc
parameter_list|)
block|{
name|x
operator|.
name|i
operator|=
literal|0
expr_stmt|;
name|x
operator|.
name|f
operator|=
literal|0.0
expr_stmt|;
name|x
operator|.
name|f2
operator|=
name|x
operator|.
name|f
expr_stmt|;
name|x
operator|.
name|d
operator|=
name|x
operator|.
name|f
expr_stmt|;
name|x
operator|.
name|f3
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{no member named 'f3'}}
name|x
operator|.
name|a
operator|=
literal|0
expr_stmt|;
name|xc
operator|.
name|d
operator|=
literal|0.0
expr_stmt|;
comment|// expected-error{{read-only variable is not assignable}}
name|xc
operator|.
name|f
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{read-only variable is not assignable}}
name|xc
operator|.
name|a
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{read-only variable is not assignable}}
block|}
end_function

begin_struct
struct|struct
name|Redecl
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
struct|struct
name|y
block|{ }
struct|;
comment|// expected-warning{{declaration does not declare anything}}
union|union
block|{
name|int
name|x
decl_stmt|;
comment|// expected-error{{member of anonymous union redeclares 'x'}}
name|float
name|y
decl_stmt|;
name|double
name|z
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
name|double
name|zz
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
block|}
union|;
name|int
name|z
decl_stmt|;
comment|// expected-error{{duplicate member 'z'}}
name|void
name|zz
parameter_list|()
function_decl|;
comment|// expected-error{{duplicate member 'zz'}}
block|}
struct|;
end_struct

begin_union
union|union
block|{
comment|// expected-warning{{declaration does not declare anything}}
name|int
name|int_val
decl_stmt|;
name|float
name|float_val
decl_stmt|;
block|}
union|;
end_union

begin_union
specifier|static
union|union
block|{
comment|// expected-warning{{declaration does not declare anything}}
name|int
name|int_val2
decl_stmt|;
name|float
name|float_val2
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|f
parameter_list|()
block|{
name|int_val2
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{use of undeclared identifier}}
name|float_val2
operator|=
literal|0.0
expr_stmt|;
comment|// expected-error{{use of undeclared identifier}}
block|}
end_function

begin_function
name|void
name|g
parameter_list|()
block|{
union|union
block|{
comment|// expected-warning{{declaration does not declare anything}}
name|int
name|i
decl_stmt|;
name|float
name|f2
decl_stmt|;
block|}
union|;
name|i
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{use of undeclared identifier}}
name|f2
operator|=
literal|0.0
expr_stmt|;
comment|// expected-error{{use of undeclared identifier}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6483159>
end_comment

begin_struct
struct|struct
name|s0
block|{
union|union
block|{
name|int
name|f0
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|//<rdar://problem/6481130>
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
empty_stmt|;
end_typedef

begin_comment
comment|// expected-warning{{typedef requires a name}}
end_comment

begin_comment
comment|// PR3675
end_comment

begin_struct
struct|struct
name|s1
block|{
name|int
name|f0
decl_stmt|;
comment|// expected-note{{previous declaration is here}}
union|union
block|{
name|int
name|f0
decl_stmt|;
comment|// expected-error{{member of anonymous union redeclares 'f0'}}
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|// PR3680
end_comment

begin_struct
struct|struct
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning{{declaration does not declare anything}}
end_comment

begin_struct
struct|struct
name|s2
block|{
union|union
block|{
name|int
name|a
decl_stmt|;
block|}
comment|// expected-warning{{expected ';' at end of declaration list}}
block|}
struct|;
end_struct

begin_comment
comment|// expected-error{{expected member name or ';' after declaration specifiers}}
end_comment

begin_comment
comment|// Make sure we don't a.k.a. anonymous structs.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|a_struct
typedef|;
end_typedef

begin_decl_stmt
name|int
name|tmp
init|=
operator|(
name|a_struct
operator|)
block|{
operator|.
name|x
operator|=
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{initializing 'int' with an expression of incompatible type 'a_struct'}}
end_comment

begin_comment
comment|// This example comes out of the C11 standard; make sure we don't accidentally reject it.
end_comment

begin_struct
struct|struct
name|s
block|{
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
name|int
name|a
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PR20930
end_comment

begin_struct
struct|struct
name|s3
block|{
struct|struct
block|{
name|int
name|A
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
comment|// expected-note {{'A' has been explicitly marked deprecated here}}
block|}
struct|;
end_struct

begin_function
name|void
name|deprecated_anonymous_struct_member
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s3
name|s
decl_stmt|;
name|s
operator|.
name|A
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{'A' is deprecated}}
block|}
end_function

end_unit

