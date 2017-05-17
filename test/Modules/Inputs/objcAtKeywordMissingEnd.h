begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|interface
name|MissingEnd
comment|// expected-note {{class started here}}
expr|@
end_expr_stmt

begin_comment
comment|// expected-error {{expected an Objective-C directive after '@'}} expected-error {{missing '@end'}}
end_comment

end_unit

