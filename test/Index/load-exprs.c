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
block|}
end_function

begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: load-exprs.c:4:15: TypeRef=T:1:13 [Extent=4:15:4:15]
end_comment

begin_comment
comment|// CHECK: load-exprs.c:5:16: TypeRef=T:1:13 [Extent=5:16:5:16]
end_comment

begin_comment
comment|// FIXME: the source location for "struct X" points at "struct", not "X"
end_comment

end_unit

