begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch -x c-header %S/Inputs/a.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 5 all -I%S/Inputs -include %t.h %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_decl_stmt
name|A
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|B
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: a.h:3:13: TypedefDecl=A:3:13 (Definition) Extent=[3:13 - 3:14]
end_comment

begin_comment
comment|// CHECK: b.h:1:15: TypedefDecl=B:1:15 (Definition) Extent=[1:15 - 1:16]
end_comment

end_unit

