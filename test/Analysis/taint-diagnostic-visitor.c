begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=alpha.security.taint,core -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// This file is for testing enhanced diagnostics produced by the GenericTaintChecker
end_comment

begin_function_decl
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|system
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|taintDiagnostic
parameter_list|()
block|{
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|scanf
argument_list|(
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
comment|// expected-note {{Taint originated here}}
name|system
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{Untrusted data is passed to a system call}} // expected-note {{Untrusted data is passed to a system call (CERT/STR02-C. Sanitize data passed to complex subsystems)}}
block|}
end_function

end_unit

