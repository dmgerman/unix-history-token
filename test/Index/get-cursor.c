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

end_unit

