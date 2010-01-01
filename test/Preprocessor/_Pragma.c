begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -Wall
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"GCC system_header"
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{system_header ignored in main file}}
end_comment

begin_comment
comment|// rdar://6880630
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"#define macro"
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{unknown pragma ignored}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|macro
end_ifdef

begin_error
error|#
directive|error
error|#define invalid
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

