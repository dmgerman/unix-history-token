begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify< %s
end_comment

begin_expr_stmt
operator|%
operator|:
name|include
operator|<
name|stdint
operator|.
name|h
operator|>
operator|%
operator|:
name|ifndef
name|BUFSIZE
operator|%
operator|:
name|define
name|BUFSIZE
literal|512
operator|%
operator|:
name|endif
name|void
name|copy
argument_list|(
argument|char d<::>
argument_list|,
argument|const char s<::>
argument_list|,
argument|int len
argument_list|)
operator|<
operator|%
end_expr_stmt

begin_while
while|while
condition|(
name|len
operator|--
operator|>=
literal|0
condition|)
operator|<
operator|%
name|d
operator|<
operator|:
name|len
operator|:
operator|>
operator|=
name|s
operator|<
operator|:
name|len
operator|:
operator|>
expr_stmt|;
end_while

begin_expr_stmt
operator|%
operator|>
operator|%
operator|>
end_expr_stmt

end_unit

