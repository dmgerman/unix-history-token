begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -std=c11 -Wno-unused-value
end_comment

begin_enum_decl
enum_decl|enum
name|e0
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-note{{forward declaration of 'enum e0'}}
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|a
range|:
operator|-
literal|1
decl_stmt|;
comment|// expected-error{{bit-field 'a' has negative width}}
comment|// rdar://6081627
name|int
name|b
range|:
literal|33
decl_stmt|;
comment|// expected-error{{size of bit-field 'b' (33 bits) exceeds size of its type (32 bits)}}
name|int
name|c
range|:
operator|(
literal|1
operator|+
literal|0.25
operator|)
decl_stmt|;
comment|// expected-error{{expression is not an integer constant expression}}
name|int
name|d
range|:
call|(
name|int
call|)
argument_list|(
literal|1
operator|+
literal|0.25
argument_list|)
decl_stmt|;
comment|// rdar://6138816
name|int
name|e
range|:
literal|0
decl_stmt|;
comment|// expected-error {{bit-field 'e' has zero width}}
name|float
name|xx
range|:
literal|4
decl_stmt|;
comment|// expected-error {{bit-field 'xx' has non-integral type}}
comment|// PR3607
name|enum
name|e0
name|f
range|:
literal|1
decl_stmt|;
comment|// expected-error {{field has incomplete type 'enum e0'}}
name|int
name|g
range|:
operator|(
name|_Bool
operator|)
literal|1
decl_stmt|;
comment|// PR4017
name|char
label|:
literal|10
expr_stmt|;
comment|// expected-error {{size of anonymous bit-field (10 bits) exceeds size of its type (8 bits)}}
name|unsigned
label|:
operator|-
literal|2
expr_stmt|;
comment|// expected-error {{anonymous bit-field has negative width (-2)}}
name|float
label|:
literal|12
expr_stmt|;
comment|// expected-error {{anonymous bit-field has non-integral type 'float'}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b
block|{
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
block|}
name|x
struct|;
end_struct

begin_macro
name|__typeof__
argument_list|(
argument|x.x+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
block|}
name|x2
struct|;
end_struct

begin_macro
name|__typeof__
argument_list|(
argument|(x.x+=
literal|1
argument|)+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_macro
name|__typeof__
argument_list|(
argument|(
literal|0
argument|,x.x)+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_macro
name|__typeof__
argument_list|(
argument|x.x<<
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|PR8025
block|{
name|double
label|:
literal|2
expr_stmt|;
comment|// expected-error{{anonymous bit-field has non-integral type 'double'}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Test4
block|{
name|unsigned
name|bitX
range|:
literal|4
decl_stmt|;
name|unsigned
name|bitY
range|:
literal|4
decl_stmt|;
name|unsigned
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test4
parameter_list|(
name|struct
name|Test4
modifier|*
name|t
parameter_list|)
block|{
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|t
operator|->
name|bitX
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to bit-field}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|(
name|t
operator|->
name|bitY
operator|)
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to bit-field}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|t
operator|->
name|bitX
operator|=
literal|4
argument_list|)
expr_stmt|;
comment|// not a bitfield designator in C
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|t
operator|->
name|bitX
operator|+=
literal|4
argument_list|)
expr_stmt|;
comment|// not a bitfield designator in C
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|(
name|void
operator|)
literal|0
argument_list|,
name|t
operator|->
name|bitX
argument_list|)
expr_stmt|;
comment|// not a bitfield designator in C
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|t
operator|->
name|var
condition|?
name|t
operator|->
name|bitX
else|:
name|t
operator|->
name|bitY
argument_list|)
expr_stmt|;
comment|// not a bitfield designator in C
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|t
operator|->
name|var
condition|?
name|t
operator|->
name|bitX
else|:
name|t
operator|->
name|bitX
argument_list|)
expr_stmt|;
comment|// not a bitfield designator in C
block|}
end_function

begin_typedef
typedef|typedef
name|unsigned
name|Unsigned
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|Signed
typedef|;
end_typedef

begin_struct
struct|struct
name|Test5
block|{
name|unsigned
name|n
range|:
literal|2
decl_stmt|;
block|}
name|t5
struct|;
end_struct

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|t5.n
argument_list|)
name|Unsigned
expr_stmt|;
end_typedef

begin_comment
comment|// Bitfield is unsigned
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+t5.n
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// ... but promotes to signed.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|t5.n +
literal|0
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// Arithmetic promotes.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(t5.n =
literal|0
argument|)
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// FIXME: Assignment should not; the result
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(t5.n +=
literal|0
argument|)
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// is a non-bit-field lvalue of type unsigned.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(t5.n *=
literal|0
argument|)
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(++t5.n)
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// FIXME: Increment is equivalent to compound-assignment.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(--t5.n)
argument_list|)
name|Signed
expr_stmt|;
end_typedef

begin_comment
comment|// This should not promote to signed.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(t5.n++)
argument_list|)
name|Unsigned
expr_stmt|;
end_typedef

begin_comment
comment|// Post-increment is underspecified, but seems to
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|+(t5.n--)
argument_list|)
name|Unsigned
expr_stmt|;
end_typedef

begin_comment
comment|// also act like compound-assignment.
end_comment

end_unit

