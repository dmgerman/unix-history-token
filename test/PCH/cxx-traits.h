begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-traits.cpp
end_comment

begin_decl_stmt
name|namespace
name|n
block|{
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_pod
block|{
comment|// expected-warning {{keyword '__is_pod' will be made available as an identifier for the remainder of the translation unit}}
block|enum
block|{
name|__value
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_empty
block|{
comment|// expected-warning {{keyword '__is_empty' will be made available as an identifier for the remainder of the translation unit}}
block|enum
block|{
name|__value
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
operator|...
name|Args
operator|>
expr|struct
name|is_trivially_constructible
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|__is_trivially_constructible
argument_list|(
name|T
argument_list|,
name|Args
operator|...
argument_list|)
block|; }
expr_stmt|;
struct|struct
name|__is_abstract
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_aggregate
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_arithmetic
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_array
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_assignable
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_base_of
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_class
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_complete_type
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_compound
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_const
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_constructible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_convertible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_convertible_to
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_destructible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_enum
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_floating_point
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_final
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_function
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_fundamental
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_integral
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_interface_class
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_literal
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_lvalue_expr
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_lvalue_reference
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_member_function_pointer
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_member_object_pointer
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_member_pointer
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_nothrow_assignable
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_nothrow_constructible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_nothrow_destructible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_object
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_pointer
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_polymorphic
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_reference
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_rvalue_expr
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_rvalue_reference
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_same
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_scalar
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_sealed
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_signed
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_standard_layout
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_trivial
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_trivially_assignable
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_trivially_constructible
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_trivially_copyable
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_union
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_unsigned
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_void
block|{}
struct|;
comment|// expected-warning {{made available}}
struct|struct
name|__is_volatile
block|{}
struct|;
comment|// expected-warning {{made available}}
block|}
end_decl_stmt

end_unit

