begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
literal|"§Ã"
expr_stmt|;
comment|// ø
comment|// CHECK: {{^  "<A7><C3>"; //<F8>}}
comment|// CHECK: {{^  \^}}
comment|/* þ« */
specifier|const
name|char
modifier|*
name|d
init|=
literal|"¥"
decl_stmt|;
comment|// CHECK: {{^  /\*<FE><AB> \*/ const char \*d = "<A5>";}}
comment|// CHECK: {{^                                 \^}}
comment|// CHECK: {{^  "<A7><C3>"; //<F8>}}
comment|// CHECK: {{^  \^~~~~~~~~~}}
block|}
end_function

end_unit

