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

begin_function_decl
name|void
name|pure_fn
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|const_fn
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|noduplicate_fn
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noduplicate
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: attributes.c:3:32: StructDecl=Test2:3:32 (Definition) Extent=[3:1 - 5:2]
end_comment

begin_comment
comment|// CHECK: attributes.c:3:23: attribute(packed)=packed Extent=[3:23 - 3:29]
end_comment

begin_comment
comment|// CHECK: attributes.c:4:8: FieldDecl=a:4:8 (Definition) Extent=[4:3 - 4:9] [access=public]
end_comment

begin_comment
comment|// CHECK: attributes.c:7:6: FunctionDecl=pure_fn:7:6 Extent=[7:1 - 7:37]
end_comment

begin_comment
comment|// CHECK: attributes.c:7:31: attribute(pure)= Extent=[7:31 - 7:35]
end_comment

begin_comment
comment|// CHECK: attributes.c:8:6: FunctionDecl=const_fn:8:6 Extent=[8:1 - 8:39]
end_comment

begin_comment
comment|// CHECK: attributes.c:8:32: attribute(const)= Extent=[8:32 - 8:37]
end_comment

begin_comment
comment|// CHECK: attributes.c:9:6: FunctionDecl=noduplicate_fn:9:6 Extent=[9:1 - 9:51]
end_comment

begin_comment
comment|// CHECK: attributes.c:9:38: attribute(noduplicate)= Extent=[9:38 - 9:49]
end_comment

end_unit

