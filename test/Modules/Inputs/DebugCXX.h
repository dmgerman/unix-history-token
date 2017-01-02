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
comment|// Explicit template instantiation.
extern|extern template class Template<int>;
extern|extern template struct traits<float>;
typedef|typedef
name|class
name|Template
operator|<
name|float
operator|>
name|FloatInstantiation
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
comment|// Anchored by a function parameter.
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

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|i
decl_stmt|;
block|}
name|TypedefUnion
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e0
init|=
literal|0
block|}
name|TypedefEnum
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|TypedefStruct
typedef|;
end_typedef

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
block|}
name|GlobalUnion
union|;
end_union

begin_struct
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|GlobalStruct
struct|;
end_struct

begin_enum
enum|enum
block|{
name|e5
init|=
literal|5
block|}
name|GlobalEnum
enum|;
end_enum

begin_macro
name|namespace
end_macro

begin_block
block|{
name|namespace
block|{
struct|struct
name|InAnonymousNamespace
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
block|}
block|}
end_block

begin_decl_stmt
name|class
name|Base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|A
block|{
name|virtual
name|Base
operator|*
name|getParent
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Base
block|{}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Derived
range|:
name|Base
block|{
name|class
name|B
operator|:
name|A
block|{
name|Derived
operator|*
name|getParent
argument_list|()
specifier|const
name|override
block|;   }
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|Template1
block|{
name|T
name|t
block|; }
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Template1
operator|<
name|void
operator|*
operator|>
name|TypedefTemplate
expr_stmt|;
end_typedef

begin_extern
extern|extern template class Template1<int>;
end_extern

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FwdDeclTemplate
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|FwdDeclTemplate
operator|<
name|int
operator|>
name|TypedefFwdDeclTemplate
expr_stmt|;
end_typedef

begin_comment
comment|// Member classes of class template specializations.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Specialized
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|Specialized
operator|<
name|int
operator|>
block|{   struct
name|Member
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|FwdDeclTemplateMember
block|{ struct
name|Member
block|; }
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|FwdDeclTemplateMember
operator|<
name|int
operator|>
operator|::
name|Member
name|TypedefFwdDeclTemplateMember
expr_stmt|;
end_typedef

begin_comment
comment|// Base class specialized on the class itself.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|class
name|BaseTemplate
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|WithSpecializedBase
operator|:
name|public
name|BaseTemplate
operator|<
name|WithSpecializedBase
operator|<
name|T
operator|>>
block|{}
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|WithSpecializedBase
operator|<
name|float
operator|>
name|SpecializedBase
expr_stmt|;
end_typedef

end_unit

