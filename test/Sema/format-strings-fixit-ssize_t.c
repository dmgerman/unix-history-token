begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -pedantic -Wall -fixit %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only -pedantic -Wall -Werror %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -E -o - %t | FileCheck %s
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
typedef|typedef
name|signed
name|long
name|int
name|ssize_t
typedef|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|ssize_t
operator|)
literal|42
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: printf("%zd", (ssize_t) 42);
end_comment

end_unit

