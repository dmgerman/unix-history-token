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
name|int
name|LocalVar1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LocalVar2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %S/targeted-top.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -cursor-at=%s:5:10 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=LOCAL-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -cursor-at=%S/targeted-top.h:11:15 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=vector_get_x  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=TOP-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -cursor-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=NESTED-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -cursor-at=%S/targeted-fields.h:2:7 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=FIELD-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -cursor-at=%S/targeted-fields.h:1:1 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=FIELD-CURSOR2
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -cursor-at=%s:5:10 %s -include %t.h \
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
comment|// RUN:  | FileCheck %s -check-prefix=LOCAL-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -cursor-at=%S/targeted-top.h:11:15 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=PreambleVar  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=vector_get_x  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=TOP-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -cursor-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=PreambleVar  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=NESTED-CURSOR1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -cursor-at=%S/targeted-preamble.h:2:15 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=PREAMBLE-CURSOR1
end_comment

begin_comment
comment|// LOCAL-CURSOR1: VarDecl=LocalVar1:5:5
end_comment

begin_comment
comment|// TOP-CURSOR1: VarDecl=TopVar:11:12
end_comment

begin_comment
comment|// NESTED-CURSOR1: VarDecl=NestedVar1:2:12
end_comment

begin_comment
comment|// PREAMBLE-CURSOR1: VarDecl=PreambleVar:2:12
end_comment

begin_comment
comment|// FIELD-CURSOR1: FieldDecl=z:2:7 (Definition)
end_comment

begin_comment
comment|// FIELD-CURSOR2: StructDecl=:13:9 (Definition)
end_comment

end_unit

