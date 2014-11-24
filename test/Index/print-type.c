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
parameter_list|,
name|int
name|arr
index|[
literal|5
index|]
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
block|{
name|fn
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
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
operator|+
name|arr
index|[
literal|3
index|]
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

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|x
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|int4_t
typedef|;
end_typedef

begin_function_decl
name|int
name|f2
parameter_list|(
name|int
name|incompletearray
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test -test-print-type %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: FunctionDecl=f:3:6 (Definition) [type=int *(int *, char *, FooType, int *, void (*)(int))] [typekind=FunctionProto] [canonicaltype=int *(int *, char *, int, int *, void (*)(int))] [canonicaltypekind=FunctionProto] [resulttype=int *] [resulttypekind=Pointer] [args= [int *] [Pointer] [char *] [Pointer] [FooType] [Typedef] [int [5]] [ConstantArray] [void (*)(int)] [Pointer]] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: ParmDecl=p:3:13 (Definition) [type=int *] [typekind=Pointer] [isPOD=1] [pointeetype=int] [pointeekind=Int]
end_comment

begin_comment
comment|// CHECK: ParmDecl=x:3:22 (Definition) [type=char *] [typekind=Pointer] [isPOD=1] [pointeetype=char] [pointeekind=Char_{{[US]}}]
end_comment

begin_comment
comment|// CHECK: ParmDecl=z:3:33 (Definition) [type=FooType] [typekind=Typedef] [canonicaltype=int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypeRef=FooType:1:13 [type=FooType] [typekind=Typedef] [canonicaltype=int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ParmDecl=arr:3:40 (Definition) [type=int [5]] [typekind=ConstantArray] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: IntegerLiteral= [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ParmDecl=fn:3:55 (Definition) [type=void (*)(int)] [typekind=Pointer] [canonicaltype=void (*)(int)] [canonicaltypekind=Pointer] [isPOD=1] [pointeetype=void (int)] [pointeekind=Unexposed]
end_comment

begin_comment
comment|// CHECK: ParmDecl=:3:62 (Definition) [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: CompoundStmt= [type=] [typekind=Invalid] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: CallExpr=fn:3:55 [type=void] [typekind=Void] [args= [int] [Int]] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=fn:3:55 [type=void (*)(int)] [typekind=Pointer] [canonicaltype=void (*)(int)] [canonicaltypekind=Pointer] [isPOD=1] [pointeetype=void (int)] [pointeekind=Unexposed]
end_comment

begin_comment
comment|// CHECK: UnaryOperator= [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=p:3:13 [type=int *] [typekind=Pointer] [isPOD=1] [pointeetype=int] [pointeekind=Int]
end_comment

begin_comment
comment|// CHECK: DeclStmt= [type=] [typekind=Invalid] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: VarDecl=w:5:17 (Definition) [type=const FooType] [typekind=Typedef] const [canonicaltype=const int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypeRef=FooType:1:13 [type=FooType] [typekind=Typedef] [canonicaltype=int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=z:3:33 [type=FooType] [typekind=Typedef] [canonicaltype=int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ReturnStmt= [type=] [typekind=Invalid] [isPOD=0]
end_comment

begin_comment
comment|// CHECK: BinaryOperator= [type=int *] [typekind=Pointer] [isPOD=1] [pointeetype=int] [pointeekind=Int]
end_comment

begin_comment
comment|// CHECK: BinaryOperator= [type=int *] [typekind=Pointer] [isPOD=1] [pointeetype=int] [pointeekind=Int]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=p:3:13 [type=int *] [typekind=Pointer] [isPOD=1] [pointeetype=int] [pointeekind=Int]
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=z:3:33 [type=FooType] [typekind=Typedef] [canonicaltype=int] [canonicaltypekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ArraySubscriptExpr= [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: UnexposedExpr=arr:3:40 [type=int [5]] [typekind=ConstantArray] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: IntegerLiteral= [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=OtherType:8:16 (Definition) [type=OtherType] [typekind=Typedef] [canonicaltype=double] [canonicaltypekind=Double] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=ArrayType:9:13 (Definition) [type=ArrayType] [typekind=Typedef] [canonicaltype=int [5]] [canonicaltypekind=ConstantArray] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: IntegerLiteral= [type=int] [typekind=Int] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: VarDecl=x:10:38 [type=__attribute__((__vector_size__(4 * sizeof(int)))) int] [typekind=Vector] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=int4_t:11:46 (Definition) [type=int4_t] [typekind=Typedef] [canonicaltype=__attribute__((__vector_size__(4 * sizeof(int)))) int] [canonicaltypekind=Vector] [isPOD=1]
end_comment

begin_comment
comment|// CHECK: ParmDecl=incompletearray:13:12 (Definition) [type=int []] [typekind=IncompleteArray] [isPOD=1]
end_comment

end_unit

