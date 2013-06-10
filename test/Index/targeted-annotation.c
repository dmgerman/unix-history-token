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
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -test-annotate-tokens=%s:1:1:7:1 %s -include %t.h \
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
comment|// RUN:   c-index-test -test-annotate-tokens=%s:1:1:7:1 %s -include %t.h \
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
comment|// LOCAL: Punctuation: "#" [2:1 - 2:2] inclusion directive=targeted-top.h
end_comment

begin_comment
comment|// LOCAL: Identifier: "include" [2:2 - 2:9] inclusion directive=targeted-top.h
end_comment

begin_comment
comment|// LOCAL: Literal: ""targeted-top.h"" [2:10 - 2:26] inclusion directive=targeted-top.h
end_comment

begin_comment
comment|// LOCAL: Punctuation: "#" [3:1 - 3:2] inclusion directive=targeted-preamble.h
end_comment

begin_comment
comment|// LOCAL: Identifier: "include" [3:2 - 3:9] inclusion directive=targeted-preamble.h
end_comment

begin_comment
comment|// LOCAL: Literal: ""targeted-preamble.h"" [3:10 - 3:31] inclusion directive=targeted-preamble.h
end_comment

begin_comment
comment|// LOCAL: Keyword: "int" [5:1 - 5:4] VarDecl=LocalVar1:5:5
end_comment

begin_comment
comment|// LOCAL: Identifier: "LocalVar1" [5:5 - 5:14] VarDecl=LocalVar1:5:5
end_comment

begin_comment
comment|// LOCAL: Punctuation: ";" [5:14 - 5:15]
end_comment

begin_comment
comment|// LOCAL: Keyword: "int" [6:1 - 6:4] VarDecl=LocalVar2:6:5
end_comment

begin_comment
comment|// LOCAL: Identifier: "LocalVar2" [6:5 - 6:14] VarDecl=LocalVar2:6:5
end_comment

begin_comment
comment|// LOCAL: Punctuation: ";" [6:14 - 6:15]
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -test-annotate-tokens=%S/targeted-fields.h:1:1:4:1 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=TopVar  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=FIELD
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -test-annotate-tokens=%S/targeted-fields.h:1:1:4:1 %s -include %t.h \
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
comment|// RUN:  | FileCheck %s -check-prefix=FIELD
end_comment

begin_comment
comment|// FIELD: Keyword: "int" [2:3 - 2:6] FieldDecl=z:2:7 (Definition)
end_comment

begin_comment
comment|// FIELD: Identifier: "z" [2:7 - 2:8] FieldDecl=z:2:7 (Definition)
end_comment

begin_comment
comment|// FIELD: Punctuation: ";" [2:8 - 2:9] StructDecl=:13:9 (Definition)
end_comment

begin_comment
comment|// FIELD: Keyword: "int" [3:3 - 3:6] FieldDecl=w:3:7 (Definition)
end_comment

begin_comment
comment|// FIELD: Identifier: "w" [3:7 - 3:8] FieldDecl=w:3:7 (Definition)
end_comment

begin_comment
comment|// FIELD: Punctuation: ";" [3:8 - 3:9] StructDecl=:13:9 (Definition)
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -test-annotate-tokens=%S/targeted-nested1.h:1:1:3:1 %s -include %t.h \
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
comment|// RUN:   c-index-test -test-annotate-tokens=%S/targeted-nested1.h:1:1:3:1 %s -include %t.h \
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
comment|// NESTED: Keyword: "extern" [2:1 - 2:7]
end_comment

begin_comment
comment|// NESTED: Keyword: "int" [2:8 - 2:11] VarDecl=NestedVar1:2:12
end_comment

begin_comment
comment|// NESTED: Identifier: "NestedVar1" [2:12 - 2:22] VarDecl=NestedVar1:2:12
end_comment

begin_comment
comment|// NESTED: Punctuation: ";" [2:22 - 2:23]
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 c-index-test -test-annotate-tokens=%S/targeted-top.h:1:1:12:1 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1  \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=vector_get_x  \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_NO_CACHING=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -test-annotate-tokens=%S/targeted-top.h:1:1:12:1 %s -include %t.h \
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
comment|// RUN:  | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// TOP: Punctuation: "#" [2:1 - 2:2] preprocessing directive=
end_comment

begin_comment
comment|// TOP: Identifier: "ifndef" [2:2 - 2:8] preprocessing directive=
end_comment

begin_comment
comment|// TOP: Identifier: "TARGETED_TOP_H" [2:9 - 2:23] preprocessing directive=
end_comment

begin_comment
comment|// TOP: Punctuation: "#" [3:1 - 3:2] preprocessing directive=
end_comment

begin_comment
comment|// TOP: Identifier: "define" [3:2 - 3:8] preprocessing directive=
end_comment

begin_comment
comment|// TOP: Identifier: "TARGETED_TOP_H" [3:9 - 3:23] macro definition=TARGETED_TOP_H
end_comment

begin_comment
comment|// TOP: Punctuation: "#" [5:1 - 5:2] inclusion directive=targeted-nested1.h
end_comment

begin_comment
comment|// TOP: Identifier: "include" [5:2 - 5:9] inclusion directive=targeted-nested1.h
end_comment

begin_comment
comment|// TOP: Literal: ""targeted-nested1.h"" [5:10 - 5:30] inclusion directive=targeted-nested1.h
end_comment

begin_comment
comment|// TOP: Keyword: "enum" [7:1 - 7:5] EnumDecl=:7:1 (Definition)
end_comment

begin_comment
comment|// TOP: Punctuation: "{" [7:6 - 7:7] EnumDecl=:7:1 (Definition)
end_comment

begin_comment
comment|// TOP: Identifier: "VALUE" [8:3 - 8:8] EnumConstantDecl=VALUE:8:3 (Definition)
end_comment

begin_comment
comment|// TOP: Punctuation: "=" [8:9 - 8:10] EnumConstantDecl=VALUE:8:3 (Definition)
end_comment

begin_comment
comment|// TOP: Literal: "3" [8:11 - 8:12] IntegerLiteral=
end_comment

begin_comment
comment|// TOP: Punctuation: "}" [9:1 - 9:2] EnumDecl=:7:1 (Definition)
end_comment

begin_comment
comment|// TOP: Punctuation: ";" [9:2 - 9:3]
end_comment

begin_comment
comment|// TOP: Keyword: "extern" [11:1 - 11:7]
end_comment

begin_comment
comment|// TOP: Keyword: "int" [11:8 - 11:11] VarDecl=TopVar:11:12
end_comment

begin_comment
comment|// TOP: Identifier: "TopVar" [11:12 - 11:18] VarDecl=TopVar:11:12
end_comment

begin_comment
comment|// TOP: Punctuation: ";" [11:18 - 11:19]
end_comment

end_unit

