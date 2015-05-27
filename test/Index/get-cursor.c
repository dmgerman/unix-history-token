begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|_MyS
block|{
name|int
name|foo
decl_stmt|;
block|}
name|MyS
struct|;
end_struct

begin_decl_stmt
name|struct
name|_MyS
name|ww
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|int
name|field
range|:
literal|16
decl_stmt|;
block|}
struct|;
block|}
name|r_t
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|()
block|{
name|r_t
name|reg
decl_stmt|;
name|reg
operator|.
name|field
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:1:9 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:2:9 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:5:9 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:7:5 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:7:8 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:17:8 \
end_comment

begin_comment
comment|// RUN:       %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: StructDecl=_MyS:1:8 (Definition)
end_comment

begin_comment
comment|// CHECK: FieldDecl=foo:2:7 (Definition)
end_comment

begin_comment
comment|// CHECK: TypeRef=struct _MyS:1:8
end_comment

begin_comment
comment|// CHECK: VarDecl=x:7:5
end_comment

begin_comment
comment|// CHECK: VarDecl=y:7:8
end_comment

begin_comment
comment|// CHECK: 17:7 MemberRefExpr=field:11:9
end_comment

end_unit

