begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -E -verify %s  */
end_comment

begin_comment
comment|/* expected-error@+1 {{macro name missing}} */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* expected-error@+1 {{macro name must be an identifier}} */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|!
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* expected-error@+1 {{macro name missing}} */
end_comment

begin_if
if|#
directive|if
name|defined
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PR1936 */
end_comment

begin_comment
comment|/* expected-error@+2 {{unterminated function-like macro invocation}} expected-error@+2 {{expected value in expression}} expected-note@+1 {{macro 'f' defined here}} */
end_comment

begin_define
define|#
directive|define
name|f
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_if
if|#
directive|if
name|f
argument_list|(
literal|2
argument|#endif  int x;
end_if

end_unit

