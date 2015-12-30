begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -mios-simulator-version-min=7 -fsyntax-only %s -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch arm64 -target x86_64-apple-darwin -mios-version-min=7 -fsyntax-only %s -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang -target armv7k-apple-watchos -arch armv7k -target armv7k-apple-watchos -fsyntax-only %s -Xclang -verify
end_comment

begin_comment
comment|// For 64-bit iOS, automatically promote -Wimplicit-function-declaration
end_comment

begin_comment
comment|// to an error.
end_comment

begin_function
name|void
name|radar_10894044
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Hi\n"
argument_list|)
expr_stmt|;
comment|// expected-error {{implicitly declaring library function 'printf' with type 'int (const char *, ...)'}} expected-note {{include the header<stdio.h> or explicitly provide a declaration for 'printf'}}
name|radar_10894044_not_declared
argument_list|()
expr_stmt|;
comment|// expected-error {{implicit declaration of function 'radar_10894044_not_declared' is invalid in C99}}
block|}
end_function

end_unit

