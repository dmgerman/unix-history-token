begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation %s
end_comment

begin_comment
comment|// The run line does not have '-verify' because we were crashing while printing
end_comment

begin_comment
comment|// the diagnostic.
end_comment

begin_comment
comment|// This file has DOS-style line endings (CR LF).  Please don't change it to
end_comment

begin_comment
comment|// Unix-style LF!
end_comment

begin_comment
comment|// PR14591.  Check that we don't crash on this.
end_comment

begin_comment
comment|/**  * @param abc  */
end_comment

begin_function_decl
name|void
name|nocrash1
parameter_list|(
name|int
name|qwerty
parameter_list|)
function_decl|;
end_function_decl

end_unit

