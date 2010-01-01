begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify %s
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

end_unit

