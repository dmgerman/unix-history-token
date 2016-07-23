begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- ObjC -*-
end_comment

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
name|ObjCClassWithPrivateIVars
block|{
name|int
name|public_ivar
block|; }
expr|@
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

begin_struct_decl
struct_decl|struct
name|FwdDeclared
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|FwdDeclared
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

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
name|e1
init|=
literal|1
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
name|e2
init|=
literal|2
block|}
name|GlobalEnum
enum|;
end_enum

end_unit

