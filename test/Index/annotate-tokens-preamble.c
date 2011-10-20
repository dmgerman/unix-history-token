begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// A comment line.
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{ }
end_function

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:1:1:5:1 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-annotate-tokens=%s:1:1:5:1 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Comment: "// A comment line." [1:1 - 1:19]
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [3:1 - 3:5] FunctionDecl=f:3:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "f" [3:6 - 3:7] FunctionDecl=f:3:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [3:7 - 3:8] FunctionDecl=f:3:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [3:8 - 3:12] ParmDecl=ptr:3:14 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [3:13 - 3:14] ParmDecl=ptr:3:14 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "ptr" [3:14 - 3:17] ParmDecl=ptr:3:14 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [3:17 - 3:18] FunctionDecl=f:3:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [3:19 - 3:20] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [4:1 - 4:2] CompoundStmt=
end_comment

end_unit

