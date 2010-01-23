begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -cursor-at=%s:1:15 -cursor-at=%s:2:21 -remap-file="%s;%S/Inputs/remap-load-to.c" %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: CINDEXTEST_USE_EXTERNAL_AST_GENERATION=1 c-index-test -cursor-at=%s:1:15 -cursor-at=%s:2:21 -remap-file="%s;%S/Inputs/remap-load-to.c" %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: ParmDecl=parm1:1:13 (Definition)
end_comment

begin_comment
comment|// CHECK: DeclRefExpr=parm2:1:26
end_comment

end_unit

