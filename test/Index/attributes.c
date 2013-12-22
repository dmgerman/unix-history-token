begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|Test2
block|{
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: attributes.c:3:32: StructDecl=Test2:3:32 (Definition) Extent=[3:1 - 5:2]
end_comment

begin_comment
comment|// CHECK: attributes.c:3:23: attribute(packed)=packed Extent=[3:23 - 3:29]
end_comment

begin_comment
comment|// CHECK: attributes.c:4:8: FieldDecl=a:4:8 (Definition) Extent=[4:3 - 4:9] [access=public]
end_comment

end_unit

