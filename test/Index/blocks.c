begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source local -fblocks %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|int_t
typedef|;
end_typedef

begin_struct
struct|struct
name|foo
block|{
name|long
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|()
block|{
specifier|static
name|struct
name|foo
name|_foo
decl_stmt|;
lambda|^
name|int_t
parameter_list|(
name|struct
name|foo
modifier|*
name|foo
parameter_list|)
block|{
return|return
operator|(
name|int_t
operator|)
name|foo
operator|->
name|x
return|;
block|}
argument_list|(
operator|&
name|_foo
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// TODO: expose the BlockExpr, CastExpr, and UnaryOperatorExpr here
end_comment

begin_comment
comment|// CHECK: blocks.c:3:13: TypedefDecl=int_t:3:13 (Definition) Extent=[3:13 - 3:18]
end_comment

begin_comment
comment|// CHECK: blocks.c:4:8: StructDecl=foo:4:8 (Definition) Extent=[4:1 - 4:23]
end_comment

begin_comment
comment|// CHECK: blocks.c:4:19: FieldDecl=x:4:19 (Definition) Extent=[4:19 - 4:20]
end_comment

begin_comment
comment|// CHECK: blocks.c:6:6: FunctionDecl=test:6:6 (Definition) Extent=[6:6 - 9:2]
end_comment

begin_comment
comment|// CHECK: blocks.c:7:21: VarDecl=_foo:7:21 (Definition) Extent=[7:17 - 7:25]
end_comment

begin_comment
comment|// CHECK: blocks.c:7:17: TypeRef=struct foo:4:8 Extent=[7:17 - 7:20]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:3: CallExpr= Extent=[8:3 - 8:61]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:3: UnexposedExpr= Extent=[8:3 - 8:54]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:5: TypeRef=int_t:3:13 Extent=[8:5 - 8:10]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:23: ParmDecl=foo:8:23 (Definition) Extent=[8:18 - 8:26]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:18: TypeRef=struct foo:4:8 Extent=[8:18 - 8:21]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:37: UnexposedExpr=x:4:19 Extent=[8:37 - 8:51]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:38: TypeRef=int_t:3:13 Extent=[8:38 - 8:43]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:50: MemberRefExpr=x:4:19 Extent=[8:45 - 8:51]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:45: DeclRefExpr=foo:8:23 Extent=[8:45 - 8:48]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:55: UnexposedExpr= Extent=[8:55 - 8:60]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:56: DeclRefExpr=_foo:7:21 Extent=[8:56 - 8:60]
end_comment

end_unit

