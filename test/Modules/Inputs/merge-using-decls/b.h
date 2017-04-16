begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|X
block|{
name|int
name|v
decl_stmt|;
typedef|typedef
name|int
name|t
typedef|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|YB
block|{
typedef|typedef
name|YB
name|Y
typedef|;
name|int
name|value
decl_stmt|;
typedef|typedef
name|int
name|type
typedef|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|YBRev
block|{
typedef|typedef
name|int
name|value
typedef|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|C
operator|:
name|X
operator|,
name|T
block|{
name|using
name|T
operator|::
name|value
block|;
name|using
name|typename
name|T
operator|::
name|type
block|;
name|using
name|X
operator|::
name|v
block|;
name|using
name|typename
name|X
operator|::
name|t
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|D
operator|:
name|X
operator|,
name|T
block|{
comment|// Mismatch in type/non-type-ness.
name|using
name|typename
name|T
operator|::
name|value
block|;
name|using
name|T
operator|::
name|type
block|;
name|using
name|X
operator|::
name|v
block|;
name|using
name|typename
name|X
operator|::
name|t
block|; }
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__cplusplus
operator|<=
literal|199711L
end_if

begin_comment
comment|// C++11 does not allow access declarations
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|E
operator|:
name|X
operator|,
name|T
block|{
comment|// Mismatch in using/access-declaration-ness.
name|T
operator|::
name|value
block|;
name|X
operator|::
name|v
block|; }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|F
operator|:
name|X
operator|,
name|T
block|{
comment|// Mismatch in nested-name-specifier.
name|using
name|T
operator|::
name|Y
operator|::
name|value
block|;
name|using
name|typename
name|T
operator|::
name|Y
operator|::
name|type
block|;
name|using
operator|::
name|X
operator|::
name|v
block|;
name|using
name|typename
operator|::
name|X
operator|::
name|t
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Force instantiation.
end_comment

begin_typedef
typedef|typedef
name|C
operator|<
name|YB
operator|>
operator|::
name|type
name|I
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|D
operator|<
name|YBRev
operator|>
operator|::
name|t
name|I
expr_stmt|;
end_typedef

begin_if
if|#
directive|if
name|__cplusplus
operator|<=
literal|199711L
end_if

begin_comment
comment|// C++11 does not allow access declarations
end_comment

begin_typedef
typedef|typedef
name|E
operator|<
name|YB
operator|>
operator|::
name|type
name|I
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|F
operator|<
name|YB
operator|>
operator|::
name|type
name|I
expr_stmt|;
end_typedef

end_unit

