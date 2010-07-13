begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This is the first thing other than comments and preprocessor stuff in the
end_comment

begin_comment
comment|// file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -E %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"somelib"
name|)
end_pragma

end_unit

