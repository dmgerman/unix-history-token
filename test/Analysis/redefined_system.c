begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=unix,core,experimental.security.taint -w -verify %s
end_comment

begin_comment
comment|// Make sure we don't crash when someone redefines a system function we reason about.
end_comment

begin_function_decl
name|char
name|memmove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|system
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|stdin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|memccpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|atoi
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|memmove
argument_list|()
operator|+
name|malloc
argument_list|()
operator|+
name|system
operator|+
name|stdin
argument_list|()
operator|+
name|memccpy
argument_list|()
operator|+
name|free
argument_list|()
operator|+
name|strdup
argument_list|()
operator|+
name|atoi
argument_list|()
return|;
block|}
end_function

end_unit

