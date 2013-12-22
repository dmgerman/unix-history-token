begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test exprs.c
end_comment

begin_comment
comment|// DeclRefExpr
end_comment

begin_decl_stmt
name|int
name|i
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|Enum
block|{
name|Enumerator
init|=
literal|18
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|i
argument_list|)
name|int_decl_ref
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|Enumerator
argument_list|)
name|enum_decl_ref
expr_stmt|;
end_typedef

begin_comment
comment|// IntegerLiteral
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
literal|17
argument_list|)
name|integer_literal
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
literal|17l
argument_list|)
name|long_literal
expr_stmt|;
end_typedef

begin_comment
comment|// FloatingLiteral and ParenExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|(
literal|42.5
argument|)
argument_list|)
name|floating_literal
expr_stmt|;
end_typedef

begin_comment
comment|// ImaginaryLiteral
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
literal|17.0i
argument_list|)
name|imaginary_literal
expr_stmt|;
end_typedef

begin_comment
comment|// StringLiteral
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|hello
init|=
literal|"Hello"
literal|"PCH"
literal|"World"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CharacterLiteral
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
literal|'a'
argument_list|)
name|char_literal
expr_stmt|;
end_typedef

begin_comment
comment|// UnaryOperator
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|-Enumerator
argument_list|)
name|negate_enum
expr_stmt|;
end_typedef

begin_comment
comment|// OffsetOfExpr
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|struct
name|X
name|array
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Z
block|{
name|struct
name|Y
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|__builtin_offsetof(struct Z, y.array[
literal|1
argument|+
literal|2
argument|].member)
argument_list|)
name|offsetof_type
expr_stmt|;
end_typedef

begin_comment
comment|// UnaryExprOrTypeTraitExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|typeof_sizeof
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|sizeof(Enumerator)
argument_list|)
name|typeof_sizeof2
expr_stmt|;
end_typedef

begin_comment
comment|// ArraySubscriptExpr
end_comment

begin_decl_stmt
specifier|extern
name|double
name|values
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|values[
literal|2
argument|]
argument_list|)
name|array_subscript
expr_stmt|;
end_typedef

begin_comment
comment|// CallExpr
end_comment

begin_function_decl
name|double
name|dplus
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|d0
decl_stmt|,
name|d1
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|(&dplus)(d0, d1)
argument_list|)
name|call_returning_double
expr_stmt|;
end_typedef

begin_comment
comment|// MemberExpr
end_comment

begin_struct
struct|struct
name|S
block|{
name|double
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|((struct S*)
literal|0
argument|)->x
argument_list|)
name|member_ref_double
expr_stmt|;
end_typedef

begin_comment
comment|// BinaryOperator
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|i + Enumerator
argument_list|)
name|add_result
expr_stmt|;
end_typedef

begin_comment
comment|// CompoundAssignOperator
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|i += Enumerator
argument_list|)
name|addeq_result
expr_stmt|;
end_typedef

begin_comment
comment|// ConditionalOperator
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|i? : d0
argument_list|)
name|conditional_operator
expr_stmt|;
end_typedef

begin_comment
comment|// CStyleCastExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|(void *)
literal|0
argument_list|)
name|void_ptr
expr_stmt|;
end_typedef

begin_comment
comment|// CompoundLiteral
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|(struct S){.x =
literal|3.5
argument|}
argument_list|)
name|compound_literal
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|i + sizeof(int[i + Enumerator])
argument_list|)
name|add_result_with_typeinfo
expr_stmt|;
end_typedef

begin_comment
comment|// ExtVectorElementExpr
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|double
name|double2
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|double2
name|vec2
decl_stmt|,
name|vec2b
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|vec2.x
argument_list|)
name|ext_vector_element
expr_stmt|;
end_typedef

begin_comment
comment|// InitListExpr
end_comment

begin_decl_stmt
name|double
name|double_array
index|[
literal|3
index|]
init|=
block|{
literal|1.0
block|,
literal|2.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DesignatedInitExpr
end_comment

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
name|designated_inits
index|[
literal|3
index|]
init|=
block|{
index|[
literal|0
index|]
operator|.
name|y
operator|=
literal|17
block|,
index|[
literal|2
index|]
operator|.
name|x
operator|=
literal|12.3
block|,
comment|// expected-warning {{implicit conversion from 'double' to 'int' changes value from 12.3 to 12}}
literal|3.5
block|}
struct|;
end_struct

begin_comment
comment|// TypesCompatibleExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|__builtin_types_compatible_p(float, double)
argument_list|)
name|types_compatible
expr_stmt|;
end_typedef

begin_comment
comment|// ChooseExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|__builtin_choose_expr(
literal|17
argument|>
literal|19
argument|, d0,
literal|1
argument|)
argument_list|)
name|choose_expr
expr_stmt|;
end_typedef

begin_comment
comment|// GNUNullExpr FIXME: needs C++
end_comment

begin_comment
comment|// typedef typeof(__null) null_type;
end_comment

begin_comment
comment|// ShuffleVectorExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|__builtin_shufflevector(vec2, vec2b,
literal|2
argument|,
literal|1
argument|)
argument_list|)
name|shuffle_expr
expr_stmt|;
end_typedef

begin_comment
comment|// ConvertVectorExpr
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float
name|float2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|__builtin_convertvector(vec2, float2)
argument_list|)
name|convert_expr
expr_stmt|;
end_typedef

begin_comment
comment|// GenericSelectionExpr
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|_Generic(i, char*:
literal|0
argument|, int:
literal|0.
argument|, default: hello)
argument_list|)
name|generic_selection_expr
expr_stmt|;
end_typedef

end_unit

