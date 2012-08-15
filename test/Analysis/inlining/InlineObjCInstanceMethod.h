begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Define a public header for the ObjC methods that are "visible" externally
end_comment

begin_comment
comment|// and, thus, could be sub-classed. We should explore the path on which these
end_comment

begin_comment
comment|// are sub-classed with unknown class by not inlining them.
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|objc_class
modifier|*
name|Class
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|objc_object
block|{
name|Class
name|isa
decl_stmt|;
block|}
typedef|*
name|id
typedef|;
end_typedef

begin_expr_stmt
unit|@
name|protocol
name|NSObject
operator|-
operator|(
name|BOOL
operator|)
name|isEqual
operator|:
operator|(
name|id
operator|)
name|object
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSObject
operator|<
name|NSObject
operator|>
block|{}
operator|+
operator|(
name|id
operator|)
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|new
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|autorelease
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|Class
operator|)
name|class
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|retain
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|PublicClass
operator|:
name|NSObject
block|{
name|int
name|value3
block|; }
operator|-
operator|(
name|int
operator|)
name|getZeroPublic
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|value2
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|readonly
argument_list|)
end_macro

begin_decl_stmt
name|int
name|value1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
name|int
name|value3
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|value3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setValue3
operator|:
operator|(
name|int
operator|)
name|newValue
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|PublicSubClass
operator|:
name|PublicClass
expr|@
name|end
expr|@
name|interface
name|PublicParent
operator|:
name|NSObject
operator|-
operator|(
name|int
operator|)
name|getZeroOverridden
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|PublicSubClass2
operator|:
name|PublicParent
operator|-
operator|(
name|int
operator|)
name|getZeroOverridden
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

