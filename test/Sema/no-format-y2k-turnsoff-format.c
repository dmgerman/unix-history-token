begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -Wformat -Wno-format-y2k
end_comment

begin_comment
comment|// rdar://9504680
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|bar
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
name|foo
argument_list|(
literal|"%s"
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{conversion specifies type 'char *' but the argument has type 'unsigned int'}}
block|}
end_function

end_unit

