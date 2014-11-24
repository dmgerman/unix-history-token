begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"prefix.h"
end_include

begin_include
include|#
directive|include
file|"preamble.h"
end_include

begin_include
include|#
directive|include
file|"preamble-with-error.h"
end_include

begin_define
define|#
directive|define
name|MACRO_UNUSED
value|1
end_define

begin_define
define|#
directive|define
name|MACRO_USED
value|2
end_define

begin_function_decl
name|int
name|wibble
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|x
operator|=
name|MACRO_USED
block|}
end_function

begin_comment
comment|// RUN: c-index-test -write-pch %t.pch -x c-header %S/Inputs/prefix.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 5 local -I %S/Inputs -include %t %s -Wunused-macros 2> %t.stderr.txt | FileCheck %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix CHECK-DIAG %s< %t.stderr.txt
end_comment

begin_comment
comment|// CHECK: preamble.h:1:12: FunctionDecl=bar:1:12 (Definition) Extent=[1:1 - 6:2]
end_comment

begin_comment
comment|// CHECK: preamble.h:4:3: BinaryOperator= Extent=[4:3 - 4:13]
end_comment

begin_comment
comment|// CHECK: preamble.h:4:3: DeclRefExpr=ptr:2:8 Extent=[4:3 - 4:6]
end_comment

begin_comment
comment|// CHECK: preamble.h:4:9: UnexposedExpr=ptr1:3:10 Extent=[4:9 - 4:13]
end_comment

begin_comment
comment|// CHECK: preamble.h:4:9: DeclRefExpr=ptr1:3:10 Extent=[4:9 - 4:13]
end_comment

begin_comment
comment|// CHECK: preamble.h:5:10: IntegerLiteral= Extent=[5:10 - 5:11]
end_comment

begin_comment
comment|// CHECK: preamble.c:8:5: FunctionDecl=wibble:8:5 Extent=[8:1 - 8:16]
end_comment

begin_comment
comment|// CHECK: preamble.c:8:15: ParmDecl=:8:15 (Definition) Extent=[8:12 - 8:15]
end_comment

begin_comment
comment|// CHECK-DIAG: preamble.h:4:7:{4:9-4:13}: warning: incompatible pointer types assigning to 'int *' from 'float *'
end_comment

begin_comment
comment|// FIXME: Should see:
end_comment

begin_comment
comment|//     preamble.c:5:9: warning: macro is not used
end_comment

begin_comment
comment|// CHECK-DIAG-NOT: preamble.c:6:9: warning: macro is not used
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -code-completion-at=%s:11:1 -I %S/Inputs -include %t %s 2> %t.stderr.txt | FileCheck -check-prefix CHECK-CC %s
end_comment

begin_comment
comment|// CHECK-CC: FunctionDecl:{ResultType int}{TypedText bar}{LeftParen (}{Placeholder int i}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC: FunctionDecl:{ResultType void}{TypedText f}{LeftParen (}{Placeholder int x}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC: FunctionDecl:{ResultType int}{TypedText foo}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC: FunctionDecl:{ResultType int}{TypedText wibble}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

end_unit

