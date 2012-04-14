begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"targeted-top.h"
end_include

begin_include
include|#
directive|include
file|"targeted-preamble.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|LocalVar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LocalVar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %S/targeted-top.h -Xclang -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -file-refs-at=%s:5:17 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -file-refs-at=%s:5:17 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=PreambleVar  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// LOCAL: VarDecl=LocalVar:5:12
end_comment

begin_comment
comment|// LOCAL: VarDecl=LocalVar:5:12 =[5:12 - 5:20]
end_comment

begin_comment
comment|// LOCAL: VarDecl=LocalVar:6:5 =[6:5 - 6:13]
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -file-refs-at=%S/targeted-top.h:14:7 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -file-refs-at=%S/targeted-top.h:14:7 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=PreambleVar  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// TOP: FieldDecl=x:14:7 (Definition)
end_comment

begin_comment
comment|// TOP: FieldDecl=x:14:7 (Definition) =[14:7 - 14:8]
end_comment

begin_comment
comment|// TOP: MemberRefExpr=x:14:7 SingleRefName=[20:13 - 20:14] RefName=[20:13 - 20:14] =[20:13 - 20:14]
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -file-refs-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=NESTED
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -file-refs-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=PreambleVar  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=NESTED
end_comment

begin_comment
comment|// NESTED: VarDecl=NestedVar1:2:12
end_comment

begin_comment
comment|// NESTED: VarDecl=NestedVar1:2:12 =[2:12 - 2:22]
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -file-refs-at=%S/targeted-preamble.h:2:15 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=PREAMBLE
end_comment

begin_comment
comment|// PREAMBLE: VarDecl=PreambleVar:2:12
end_comment

begin_comment
comment|// PREAMBLE: VarDecl=PreambleVar:2:12 =[2:12 - 2:23]
end_comment

end_unit

