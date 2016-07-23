begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_comment
comment|// vim: set binary noeol:
end_comment

begin_comment
comment|// This file intentionally ends without a \n on the last line.  Make sure your
end_comment

begin_comment
comment|// editor doesn't add one.
end_comment

begin_expr_stmt
operator|>>>
operator|>
name|ORIGINAL
comment|// expected-error@-1 {{version control conflict marker in file}}
expr|<<<
operator|<
comment|// expected-error@-1 {{expected identifier or '('}}
expr|<<<
operator|<
end_expr_stmt

end_unit

