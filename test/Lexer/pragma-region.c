begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Test pragma region directive from    http://msdn.microsoft.com/en-us/library/b6xkz944(v=vs.80).aspx */
end_comment

begin_comment
comment|// Editor-only pragma, just skipped by compiler.
end_comment

begin_comment
comment|// Syntax:
end_comment

begin_comment
comment|// #pragma region optional name
end_comment

begin_comment
comment|// #pragma endregion optional comment
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wall -fms-extensions %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|region
end_pragma

begin_comment
comment|/* inner space */
end_comment

begin_pragma
pragma|#
directive|pragma
name|endregion
end_pragma

begin_pragma
pragma|#
directive|pragma
name|region
name|long
name|name
end_pragma

begin_comment
comment|/* inner space */
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|endregion
name|long
name|comment
end_pragma

begin_function_decl
name|void
name|inner
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__pragma
argument_list|(
argument|region
argument_list|)
end_macro

begin_comment
comment|// no sense, but ignored
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"region"
argument_list|)
end_macro

begin_comment
comment|// ditto
end_comment

begin_pragma
pragma|#
directive|pragma
name|region2
end_pragma

begin_comment
comment|// expected-warning {{unknown pragma ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|region
name|one
end_pragma

begin_pragma
pragma|#
directive|pragma
name|region
name|inner
end_pragma

begin_comment
comment|//#pragma endregion inner
end_comment

begin_pragma
pragma|#
directive|pragma
name|endregion
name|end
end_pragma

begin_comment
comment|// {{unclosed pragma region}} - region mismatches is not detected yet
end_comment

end_unit

