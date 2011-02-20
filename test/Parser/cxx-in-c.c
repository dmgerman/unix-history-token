begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR9137
end_comment

begin_macro
name|void
end_macro

begin_macro
name|f0
argument_list|(
argument|int x
argument_list|)
end_macro

begin_block
unit|:
block|{}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{expected function body after function declarator}}
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
function|try
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{expected function body after function declarator}}
end_comment

end_unit

