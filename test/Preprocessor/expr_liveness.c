begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -E %s -DNO_ERRORS -Werror -Wundef    RUN: not %clang_cc1 -E %s  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_ERRORS
end_ifdef

begin_comment
comment|/* None of these divisions by zero are in live parts of the expression, do not    emit any diagnostics. */
end_comment

begin_define
define|#
directive|define
name|MACRO_0
value|0
end_define

begin_define
define|#
directive|define
name|MACRO_1
value|1
end_define

begin_if
if|#
directive|if
name|MACRO_0
operator|&&
literal|10
operator|/
name|MACRO_0
end_if

begin_expr_stmt
name|foo
endif|#
directive|endif
if|#
directive|if
name|MACRO_1
operator|||
literal|10
operator|/
name|MACRO_0
name|bar
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
condition|?
literal|124
operator|/
literal|0
expr|:
literal|42
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR2279
end_comment

begin_if
if|#
directive|if
literal|0
condition|?
literal|1
operator|/
literal|0
expr|:
literal|2
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR2279
end_comment

begin_if
if|#
directive|if
literal|1
condition|?
literal|2
condition|?
literal|3
expr|:
literal|4
expr|:
literal|5
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR2284
end_comment

begin_if
if|#
directive|if
literal|1
condition|?
literal|0
expr|:
literal|1
condition|?
literal|1
operator|/
literal|0
expr|:
literal|1
operator|/
literal|0
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The 1/0 is live, it should error out. */
end_comment

begin_if
if|#
directive|if
literal|0
operator|&&
literal|1
condition|?
literal|4
expr|:
literal|1
operator|/
literal|0
end_if

begin_endif
unit|baz
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// rdar://6505352
end_comment

begin_comment
comment|// -Wundef should not warn about use of undefined identifier if not live.
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|XXX
argument_list|)
operator|||
name|XXX
operator|>
literal|42
operator|)
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

