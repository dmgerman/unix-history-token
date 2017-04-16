begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
modifier|*
name|ip
decl_stmt|;
name|float
modifier|*
name|fp
decl_stmt|;
name|long
modifier|*
name|__restrict
name|rlp
decl_stmt|;
name|void
modifier|*
name|vpa
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TU
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_function_decl
name|void
name|f
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{passing argument to parameter here}}
end_comment

begin_function
name|void
name|g
parameter_list|(
name|int
modifier|*
name|ip
parameter_list|,
name|float
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|)
block|{
name|f
argument_list|(
name|ip
argument_list|)
expr_stmt|;
name|f
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|f
argument_list|(
name|cp
argument_list|)
expr_stmt|;
comment|// expected-error{{incompatible type}}
name|f
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|TU
name|tu_ip
init|=
name|ip
decl_stmt|;
comment|// expected-error{{incompatible type}}
name|TU
name|tu
decl_stmt|;
name|tu
operator|.
name|ip
operator|=
name|ip
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Test ability to redeclare a function taking a transparent_union arg    with various compatible and incompatible argument types. */
end_comment

begin_function_decl
name|void
name|fip
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|fip
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|ffp
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ffp
parameter_list|(
name|float
modifier|*
name|f
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|flp
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|flp
parameter_list|(
name|long
modifier|*
name|l
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|fvp
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|fvp
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{conflicting types}}
end_comment

begin_function_decl
name|void
name|fsp
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|fsp
parameter_list|(
name|short
modifier|*
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{conflicting types}}
end_comment

begin_function_decl
name|void
name|fi
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|fi
parameter_list|(
name|int
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{conflicting types}}
end_comment

begin_function_decl
name|void
name|fvpp
parameter_list|(
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|fvpp
parameter_list|(
name|void
modifier|*
modifier|*
name|v
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{conflicting types}}
end_comment

begin_comment
comment|/* FIXME: we'd like to just use an "int" here and align it differently    from the normal "int", but if we do so we lose the alignment    information from the typedef within the compiler. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|aligned
typedef|(8)))
name|aligned_struct8
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|aligned
typedef|(4)))
name|aligned_struct4
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|aligned_struct4
name|s4
decl_stmt|;
comment|// expected-note{{alignment of first field}}
name|aligned_struct8
name|s8
decl_stmt|;
comment|// expected-warning{{alignment of field}}
block|}
name|TU1
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|union
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
block|{
name|aligned_struct4
name|s4
block|;
comment|// expected-note{{alignment of first field}}
name|aligned_struct8
name|s8
block|;
comment|// expected-warning{{alignment of field}}
block|}
end_typedef

begin_expr_stmt
name|TU1b
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|c
decl_stmt|;
comment|// expected-note{{size of first field is 8 bits}}
name|int
name|i
decl_stmt|;
comment|// expected-warning{{size of field}}
block|}
name|TU2
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|union
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
block|{
name|char
name|c
block|;
comment|// expected-note{{size of first field is 8 bits}}
name|int
name|i
block|;
comment|// expected-warning{{size of field}}
block|}
end_typedef

begin_expr_stmt
name|TU2b
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f
decl_stmt|;
comment|// expected-warning{{floating}}
block|}
name|TU3
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{ }
name|TU4
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_comment
comment|// expected-warning{{field}}
end_comment

begin_typedef
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|int4
name|vec
decl_stmt|;
comment|// expected-warning{{first field of a transparent union cannot have vector type 'int4' (vector of 4 'int' values); transparent_union attribute ignored}}
block|}
name|TU5
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_union
union|union
name|pr15134
block|{
name|unsigned
name|int
name|u
decl_stmt|;
struct|struct
block|{
name|unsigned
name|int
name|expo
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|mant
range|:
literal|30
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
comment|// The packed attribute is acceptable because it defines a less strict
comment|// alignment than required by the first field of the transparent union.
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_union
union|union
name|pr15134v2
block|{
struct|struct
block|{
comment|// expected-note {{alignment of first field is 32 bits}}
name|unsigned
name|int
name|u1
decl_stmt|;
name|unsigned
name|int
name|u2
decl_stmt|;
block|}
struct|;
struct|struct
block|{
comment|// expected-warning {{alignment of field '' (64 bits) does not match the alignment of the first field in transparent union; transparent_union attribute ignored}}
name|unsigned
name|int
name|u3
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
struct|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_union
union|union
name|pr30520v
block|{
name|void
name|b
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_comment
comment|// expected-error {{field has incomplete type 'void'}}
end_comment

begin_union
union|union
name|pr30520a
block|{
name|int
name|b
index|[]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_comment
comment|// expected-error {{field has incomplete type 'int []'}}
end_comment

begin_comment
comment|// expected-note@+1 2 {{forward declaration of 'struct stb'}}
end_comment

begin_union
union|union
name|pr30520s
block|{
name|struct
name|stb
name|b
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_comment
comment|// expected-error {{field has incomplete type 'struct stb'}}
end_comment

begin_union
union|union
name|pr30520s2
block|{
name|int
modifier|*
name|v
decl_stmt|;
name|struct
name|stb
name|b
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_comment
comment|// expected-error {{field has incomplete type 'struct stb'}}
end_comment

begin_typedef
typedef|typedef
name|union
name|__attribute__
argument_list|(
operator|(
name|__transparent_union__
operator|)
argument_list|)
block|{
name|int
modifier|*
name|i
block|;
name|struct
name|st
modifier|*
name|s
block|; }
end_typedef

begin_expr_stmt
name|TU6
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|TU6
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo11
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
name|bar
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo2
parameter_list|(
name|struct
name|st
modifier|*
name|s
parameter_list|)
block|{
name|bar
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

