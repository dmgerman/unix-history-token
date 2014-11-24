begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
unit|}
comment|// expected-error {{extraneous closing brace ('}')}}
end_comment

begin_expr_stmt
unit|int
name|not_in_extern_c
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern
literal|"C"
block|{
end_extern

begin_comment
comment|// expected-note {{to match this '{'}}
end_comment

begin_comment
comment|// expected-error {{expected '}'}}
end_comment

end_unit

