begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx_exprs.cpp
end_comment

begin_comment
comment|// CXXStaticCastExpr
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|static_cast<void *>(
literal|0
argument|)
argument_list|)
name|static_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXDynamicCastExpr
end_comment

begin_struct
struct|struct
name|Base
block|{
name|Base
argument_list|(
name|int
argument_list|)
expr_stmt|;
name|virtual
name|void
name|f
parameter_list|(
name|int
name|x
init|=
literal|492
parameter_list|)
function_decl|;
operator|~
name|Base
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Derived
range|:
name|Base
block|{
name|Derived
argument_list|()
block|;
name|void
name|g
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Base
modifier|*
name|base_ptr
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|dynamic_cast<Derived *>(base_ptr)
argument_list|)
name|dynamic_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXReinterpretCastExpr
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|reinterpret_cast<void *>(
literal|0
argument|)
argument_list|)
name|reinterpret_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXConstCastExpr
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|const_char_ptr_value
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|const_cast<char *>(const_char_ptr_value)
argument_list|)
name|const_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXFunctionalCastExpr
end_comment

begin_decl_stmt
name|int
name|int_value
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|double(int_value)
argument_list|)
name|functional_cast_result
expr_stmt|;
end_typedef

begin_comment
comment|// CXXBoolLiteralExpr
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|true
argument_list|)
name|bool_literal_result
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|bool
name|true_value
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|false_value
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CXXNullPtrLiteralExpr
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|nullptr
argument_list|)
name|cxx_null_ptr_result
expr_stmt|;
end_typedef

begin_function
name|void
name|foo
parameter_list|(
name|Derived
modifier|*
name|P
parameter_list|)
block|{
comment|// CXXMemberCallExpr
name|P
operator|->
name|f
argument_list|(
literal|12
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// FIXME: This is a hack until<typeinfo> works completely.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|class
name|type_info
block|{}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CXXTypeidExpr - Both expr and type forms.
end_comment

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
name|typeid
argument_list|(
name|int
argument_list|)
argument_list|)
operator|*
name|typeid_result1
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
name|typeid
argument_list|(
literal|2
argument_list|)
argument_list|)
operator|*
name|typeid_result2
expr_stmt|;
end_typedef

begin_function_decl
name|Derived
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|Derived
operator|::
name|Derived
argument_list|()
operator|:
name|Base
argument_list|(
literal|4
argument_list|)
block|{ }
name|void
name|Derived
operator|::
name|g
argument_list|()
block|{
comment|// CXXThisExpr
name|f
argument_list|(
literal|2
argument_list|)
block|;
comment|// Implicit
name|this
operator|->
name|f
argument_list|(
literal|1
argument_list|)
block|;
comment|// Explicit
comment|// CXXThrowExpr
name|throw
block|;
name|throw
literal|42
block|;
comment|// CXXDefaultArgExpr
name|f
argument_list|()
block|;
specifier|const
name|Derived
operator|&
name|X
operator|=
name|foo
argument_list|()
block|;
comment|// FIXME: How do I make a CXXBindReferenceExpr, CXXConstructExpr?
name|int
name|A
operator|=
name|int
argument_list|(
literal|0.5
argument_list|)
block|;
comment|// CXXFunctionalCastExpr
name|A
operator|=
name|int
argument_list|()
block|;
comment|// CXXZeroInitValueExpr
name|new
name|Base
argument_list|(
literal|4
argument_list|)
block|;
comment|// CXXNewExpr
block|}
comment|// FIXME: The comment on CXXTemporaryObjectExpr is broken, this doesn't make
comment|// one.
expr|struct
name|CtorStruct
block|{
name|CtorStruct
argument_list|(
name|int
argument_list|,
name|float
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_function
name|CtorStruct
name|create_CtorStruct
parameter_list|()
block|{
return|return
name|CtorStruct
argument_list|(
literal|1
argument_list|,
literal|3.14f
argument_list|)
return|;
comment|// CXXTemporaryObjectExpr
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

