begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | not grep keyXXXX
end_comment

begin_comment
comment|// This should not show keyXXXX in the caret diag output.  This once
end_comment

begin_comment
comment|// happened because the two tokens ended up in the scratch buffer and
end_comment

begin_comment
comment|// the caret diag from the scratch buffer included the previous token.
end_comment

begin_define
define|#
directive|define
name|M
parameter_list|(
name|name
parameter_list|)
define|\
value|if (name ## XXXX != name ## _sb);
end_define

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|keyXXXX
decl_stmt|;
name|M
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

