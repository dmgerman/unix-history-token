begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- C++ -*- */
end_comment

begin_decl_stmt
name|namespace
name|DebugCXX
block|{
comment|// Records.
struct|struct
name|Struct
block|{
name|int
name|i
decl_stmt|;
specifier|static
name|int
name|static_member
decl_stmt|;
block|}
struct|;
comment|// Enums.
enum|enum
name|Enum
block|{
name|Enumerator
block|}
enum|;
enum|enum
block|{
name|e1
init|=
literal|'1'
block|}
enum|;
enum|enum
block|{
name|e2
init|=
literal|'2'
block|}
enum|;
comment|// Templates (instantiations).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|traits
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Traits
operator|=
name|traits
operator|<
name|T
operator|>
expr|>
name|class
name|Template
block|{
name|T
name|member
block|;   }
expr_stmt|;
extern|extern template class Template<int>;
extern|extern template struct traits<float>;
typedef|typedef
name|class
name|Template
operator|<
name|float
operator|>
name|FloatInstatiation
expr_stmt|;
specifier|inline
name|void
name|fn
parameter_list|()
block|{
name|Template
operator|<
name|long
operator|>
name|invisible
expr_stmt|;
block|}
comment|// Non-template inside a template.
name|template
operator|<
name|class
operator|>
expr|struct
name|Outer
block|{
name|Outer
argument_list|()
block|;     struct
name|Inner
block|{
name|Inner
argument_list|(
argument|Outer
argument_list|)
block|{}
block|}
block|;   }
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|Outer
operator|<
name|T
operator|>
operator|::
name|Outer
argument_list|()
block|{
name|Inner
name|a
argument_list|(
operator|*
name|this
argument_list|)
block|;   }
expr_stmt|;
comment|// Partial template specialization.
name|template
operator|<
name|typename
operator|...
operator|>
name|class
name|A
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|A
operator|<
name|T
operator|>
block|{}
expr_stmt|;
typedef|typedef
name|A
operator|<
name|void
operator|>
name|B
expr_stmt|;
name|void
name|foo
parameter_list|(
name|B
parameter_list|)
block|{}
block|}
end_decl_stmt

begin_comment
comment|// Virtual class with a forward declaration.
end_comment

begin_decl_stmt
name|class
name|FwdVirtual
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|FwdVirtual
block|{
name|virtual
operator|~
name|FwdVirtual
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct_decl
struct_decl|struct
name|PureForwardDecl
struct_decl|;
end_struct_decl

end_unit

