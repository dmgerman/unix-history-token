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

begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:15: TypeRef=T:1:13 Extent=[4:15 - 4:16]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:5:16: TypeRef=T:1:13 Extent=[5:16 - 5:17]
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

end_unit

