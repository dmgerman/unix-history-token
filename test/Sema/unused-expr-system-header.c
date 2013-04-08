begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -isystem %S/Inputs -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<unused-expr-system-header.h>
end_include

begin_function
name|void
name|f
parameter_list|(
name|int
name|i1
parameter_list|,
name|int
name|i2
parameter_list|)
block|{
name|POSSIBLY_BAD_MACRO
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|STATEMENT_EXPR_MACRO
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|COMMA_MACRO_1
argument_list|(
name|i1
operator|==
name|i2
argument_list|,
name|f
argument_list|(
name|i1
argument_list|,
name|i2
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{comparison result unused}} \
comment|// expected-note {{equality comparison}}
name|COMMA_MACRO_2
argument_list|(
name|i1
operator|==
name|i2
argument_list|,
name|f
argument_list|(
name|i1
argument_list|,
name|i2
argument_list|)
argument_list|)
expr_stmt|;
name|COMMA_MACRO_3
argument_list|(
name|i1
operator|==
name|i2
argument_list|,
name|f
argument_list|(
name|i1
argument_list|,
name|i2
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{comparison result unused}} \
comment|// expected-note {{equality comparison}}
name|COMMA_MACRO_4
argument_list|(
name|i1
operator|==
name|i2
argument_list|,
name|f
argument_list|(
name|i1
argument_list|,
name|i2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

