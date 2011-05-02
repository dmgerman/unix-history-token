begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|T
typedef|;
end_typedef

begin_struct
struct|struct
name|X
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|T
modifier|*
name|t_ptr
init|=
operator|(
name|T
operator|*
operator|)
name|ptr
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|T
argument_list|)
expr_stmt|;
name|struct
name|X
name|x
init|=
operator|(
expr|struct
name|X
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
name|void
modifier|*
name|xx
init|=
name|ptr
condition|?
else|:
operator|&
name|x
decl_stmt|;
block|}
end_function

begin_function
name|int
name|test_blocks
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|__block
name|int
name|y
init|=
name|x
decl_stmt|;
lambda|^
block|{
specifier|static
name|int
name|z
init|=
literal|0
decl_stmt|;
name|y
operator|=
operator|(
operator|++
name|z
operator|)
operator|+
name|x
expr_stmt|;
lambda|^
block|{
operator|++
name|z
expr_stmt|;
operator|++
name|y
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_struct
struct|struct
name|Y
block|{
name|struct
name|X
name|array
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|StartIndex
init|=
literal|1
block|}
enum|;
end_enum

begin_function
name|void
name|test_members
parameter_list|(
name|int
name|aval
parameter_list|,
name|int
name|bval
parameter_list|)
block|{
name|struct
name|Y
name|y0
init|=
block|{
operator|.
name|array
index|[
name|StartIndex
index|]
operator|.
name|b
operator|=
name|bval
block|,
operator|.
name|array
index|[
name|StartIndex
index|]
operator|.
name|a
operator|=
name|aval
block|}
decl_stmt|;
name|__builtin_offsetof
argument_list|(
expr|struct
name|Y
argument_list|,
name|array
index|[
name|StartIndex
index|]
operator|.
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -test-load-source all %s -fblocks | FileCheck %s
end_comment

begin_comment
comment|// CHECK: macro definition=__clang__
end_comment

begin_comment
comment|// CHECK: load-exprs.c:1:13: TypedefDecl=T:1:13 (Definition) Extent=[1:1 - 1:14]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:2:8: StructDecl=X:2:8 (Definition) Extent=[2:1 - 2:23]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:2:16: FieldDecl=a:2:16 (Definition) Extent=[2:12 - 2:17]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:2:19: FieldDecl=b:2:19 (Definition) Extent=[2:12 - 2:20]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:3:6: FunctionDecl=f:3:6 (Definition) Extent=[3:1 - 8:2]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:3:14: ParmDecl=ptr:3:14 (Definition) Extent=[3:8 - 3:17]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:6: VarDecl=t_ptr:4:6 (Definition) Extent=[4:3 - 4:22]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:3: TypeRef=T:1:13 Extent=[4:3 - 4:4]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:15: TypeRef=T:1:13 Extent=[4:15 - 4:16]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:19: DeclRefExpr=ptr:3:14 Extent=[4:19 - 4:22]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:5:16: TypeRef=T:1:13 Extent=[5:16 - 5:17]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:6:12: VarDecl=x:6:12 (Definition) Extent=[6:3 - 6:32]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:6:10: TypeRef=struct X:2:8 Extent=[6:10 - 6:11]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:6:24: TypeRef=struct X:2:8 Extent=[6:24 - 6:25]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:7:9: VarDecl=xx:7:9 (Definition) Extent=[7:3 - 7:24]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:7:14: DeclRefExpr=ptr:3:14 Extent=[7:14 - 7:17]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:7:23: DeclRefExpr=x:6:12 Extent=[7:23 - 7:24]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:10:5: FunctionDecl=test_blocks:10:5 (Definition) Extent=[10:1 - 21:2]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:10:21: ParmDecl=x:10:21 (Definition) Extent=[10:17 - 10:22]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:11:15: VarDecl=y:11:15 (Definition) Extent=[11:3 - 11:20]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:11:19: DeclRefExpr=x:10:21 Extent=[11:19 - 11:20]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:12:3: CallExpr= Extent=[12:3 - 19:7]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:13:17: VarDecl=z:13:17 (Definition) Extent=[13:6 - 13:22]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:14:6: DeclRefExpr=y:11:15 Extent=[14:6 - 14:7]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:14:13: DeclRefExpr=z:13:17 Extent=[14:13 - 14:14]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:14:18: DeclRefExpr=x:10:21 Extent=[14:18 - 14:19]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:15:6: CallExpr= Extent=[15:6 - 18:9]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:16:10: DeclRefExpr=z:13:17 Extent=[16:10 - 16:11]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:17:10: DeclRefExpr=y:11:15 Extent=[17:10 - 17:11]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:20:10: DeclRefExpr=y:11:15 Extent=[20:10 - 20:11]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:29:6: FunctionDecl=test_members:29:6 (Definition)
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:12: VarDecl=y0:30:12 (Definition) Extent=[30:3 - 30:77]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:10: TypeRef=struct Y:23:8 Extent=[30:10 - 30:11]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:20: MemberRef=array:24:12 Extent=[30:20 - 30:25]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:26: DeclRefExpr=StartIndex:27:8 Extent=[30:26 - 30:36]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:38: MemberRef=b:2:19 Extent=[30:38 - 30:39]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:42: DeclRefExpr=bval:29:33 Extent=[30:42 - 30:46]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:49: MemberRef=array:24:12 Extent=[30:49 - 30:54]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:55: DeclRefExpr=StartIndex:27:8 Extent=[30:55 - 30:65]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:67: MemberRef=a:2:16 Extent=[30:67 - 30:68]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:30:71: DeclRefExpr=aval:29:23 Extent=[30:71 - 30:75]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:31:29: TypeRef=struct Y:23:8 Extent=[31:29 - 31:30]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:31:32: MemberRef=array:24:12 Extent=[31:32 - 31:37]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:31:38: DeclRefExpr=StartIndex:27:8 Extent=[31:38 - 31:48]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:31:50: MemberRef=b:2:19 Extent=[31:50 - 31:51]
end_comment

end_unit

