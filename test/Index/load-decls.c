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

end_unit

