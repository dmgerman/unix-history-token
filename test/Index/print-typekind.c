begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|FooType
typedef|;
end_typedef

begin_decl_stmt
name|int
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f
parameter_list|(
name|int
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|x
parameter_list|,
name|FooType
name|z
parameter_list|)
block|{
specifier|const
name|FooType
name|w
init|=
name|z
decl_stmt|;
return|return
name|p
operator|+
name|z
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|double
name|OtherType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ArrayType
index|[
literal|5
index|]
typedef|;
end_typedef

begin_comment
comment|// RUN: c-index-test -test-print-typekind %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: TypedefDecl=FooType:1:13 (Definition) typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: VarDecl=p:2:6 typekind=Pointer [isPOD=1]
end_comment

begin_comment
comment|// CHECK: FunctionDecl=f:3:6 (Definition) typekind=FunctionProto [canonical=FunctionProto] [result=Pointer] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: ParmDecl=p:3:13 (Definition) typekind=Pointer [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ParmDecl=x:3:22 (Definition) typekind=Pointer [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ParmDecl=z:3:33 (Definition) typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypeRef=FooType:1:13 typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: CompoundStmt= typekind=Invalid [isPOD=0]
end_comment

begin_comment
comment|// CHECK: DeclStmt= typekind=Invalid [isPOD=0]
end_comment

begin_comment
comment|// CHECK: VarDecl=w:4:17 (Definition) typekind=Typedef const [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypeRef=FooType:1:13 typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=z:3:33 typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ReturnStmt= typekind=Invalid [isPOD=0]
end_comment

begin_comment
comment|// CHECK: BinaryOperator= typekind=Pointer [isPOD=1]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=p:3:13 typekind=Pointer [isPOD=1]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=z:3:33 typekind=Typedef [canonical=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=OtherType:7:16 (Definition) typekind=Typedef [canonical=Double] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=ArrayType:8:13 (Definition) typekind=Typedef [canonical=ConstantArray] [isPOD=1]
end_comment

end_unit

