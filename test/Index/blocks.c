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
specifier|__block
name|i
operator|=
literal|0
expr_stmt|;
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
operator|+
name|i
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
comment|// CHECK: blocks.c:6:6: FunctionDecl=test:6:6 (Definition) Extent=[6:6 - 10:2]
end_comment

begin_comment
comment|// CHECK: blocks.c:6:13: UnexposedStmt= Extent=[6:13 - 10:2]
end_comment

begin_comment
comment|// CHECK: blocks.c:7:3: UnexposedStmt= Extent=[7:3 - 7:26]
end_comment

begin_comment
comment|// CHECK: blocks.c:7:21: VarDecl=_foo:7:21 (Definition) Extent=[7:17 - 7:25]
end_comment

begin_comment
comment|// CHECK: blocks.c:7:17: TypeRef=struct foo:4:8 Extent=[7:17 - 7:20]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:11: VarDecl=i:8:11 (Definition) Extent=[8:11 - 8:16]
end_comment

begin_comment
comment|// CHECK: blocks.c:8:15: UnexposedExpr= Extent=[8:15 - 8:16]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:3: CallExpr= Extent=[9:3 - 9:65]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:3: UnexposedExpr= Extent=[9:3 - 9:58]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:5: TypeRef=int_t:3:13 Extent=[9:5 - 9:10]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:23: ParmDecl=foo:9:23 (Definition) Extent=[9:18 - 9:26]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:18: TypeRef=struct foo:4:8 Extent=[9:18 - 9:21]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:28: UnexposedStmt= Extent=[9:28 - 9:58]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:30: UnexposedStmt= Extent=[9:30 - 9:55]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:37: UnexposedExpr= Extent=[9:37 - 9:55]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:37: UnexposedExpr=x:4:19 Extent=[9:37 - 9:51]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:38: TypeRef=int_t:3:13 Extent=[9:38 - 9:43]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:50: MemberRefExpr=x:4:19 Extent=[9:45 - 9:51]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:45: DeclRefExpr=foo:9:23 Extent=[9:45 - 9:48]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:54: DeclRefExpr=i:8:11 Extent=[9:54 - 9:55]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:59: UnexposedExpr= Extent=[9:59 - 9:64]
end_comment

begin_comment
comment|// CHECK: blocks.c:9:60: DeclRefExpr=_foo:7:21 Extent=[9:60 - 9:64]
end_comment

end_unit

