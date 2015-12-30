begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|class
name|FwdDecl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|interface
name|ObjCClass
block|{
name|int
name|ivar
decl_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
operator|+
name|classMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|instanceMethodWithInt
operator|:
operator|(
name|int
operator|)
name|i
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
expr|struct
name|OpaqueData
operator|*
operator|)
name|getSomethingOpaque
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|property
name|int
name|property
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|ObjCClass
argument_list|(
name|Category
argument_list|)
operator|-
name|categoryMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|protocol
name|ObjCProtocol
end_expr_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|e0
init|=
literal|0
block|}
name|InnerEnum
typedef|;
end_typedef

begin_expr_stmt
operator|+
operator|(
name|InnerEnum
operator|)
name|protocolMethod
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

