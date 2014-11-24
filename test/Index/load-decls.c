begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Green
block|,
name|Blue
block|,
name|Rouge
init|=
name|Red
block|}
enum|;
end_enum

begin_function_decl
name|void
name|PR17970
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: load-decls.c:1:6: EnumDecl=Color:1:6 (Definition) Extent=[1:1 - 7:2]
end_comment

begin_comment
comment|// CHECK: load-decls.c:2:3: EnumConstantDecl=Red:2:3 (Definition) Extent=[2:3 - 2:6]
end_comment

begin_comment
comment|// CHECK: load-decls.c:3:3: EnumConstantDecl=Green:3:3 (Definition) Extent=[3:3 - 3:8]
end_comment

begin_comment
comment|// CHECK: load-decls.c:4:3: EnumConstantDecl=Blue:4:3 (Definition) Extent=[4:3 - 4:7]
end_comment

begin_comment
comment|// CHECK: load-decls.c:6:3: EnumConstantDecl=Rouge:6:3 (Definition) Extent=[6:3 - 6:14]
end_comment

begin_comment
comment|// CHECK: load-decls.c:6:11: DeclRefExpr=Red:2:3 Extent=[6:11 - 6:14]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: load-decls.c:9:6: FunctionDecl=PR17970:9:6 Extent=[9:1 - 9:35]
end_comment

begin_comment
comment|// CHECK: load-decls.c:9:21: ParmDecl=:9:21 (Definition) Extent=[9:14 - 9:27]
end_comment

begin_comment
comment|// CHECK: load-decls.c:9:26: ParmDecl=:9:26 (Definition) Extent=[9:23 - 9:26]
end_comment

begin_comment
comment|// CHECK: load-decls.c:9:34: ParmDecl=:9:34 (Definition) Extent=[9:29 - 9:34]
end_comment

end_unit

