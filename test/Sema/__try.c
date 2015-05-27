begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fborland-extensions -DBORLAND -fsyntax-only -verify -fblocks %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fms-extensions -fsyntax-only -verify -fblocks %s
end_comment

begin_define
define|#
directive|define
name|JOIN2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|JOIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|JOIN2(x,y)
end_define

begin_define
define|#
directive|define
name|TEST2
parameter_list|(
name|name
parameter_list|)
value|JOIN(name,__LINE__)
end_define

begin_define
define|#
directive|define
name|TEST
value|TEST2(test)
end_define

begin_typedef
typedef|typedef
name|int
name|DWORD
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|sysheader
name|begin
end_pragma

begin_struct
struct|struct
name|EXCEPTION_INFO
block|{}
struct|;
end_struct

begin_function_decl
name|unsigned
name|long
name|__exception_code
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BORLAND
end_ifdef

begin_function_decl
name|struct
name|EXCEPTION_INFO
modifier|*
name|__exception_info
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|__abnormal_termination
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GetExceptionCode
value|__exception_code
end_define

begin_define
define|#
directive|define
name|GetExceptionInformation
value|__exception_info
end_define

begin_define
define|#
directive|define
name|AbnormalTermination
value|__abnormal_termination
end_define

begin_pragma
pragma|#
directive|pragma
name|sysheader
name|end
end_pragma

begin_function_decl
name|DWORD
name|FilterExpression
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{declared here}}
end_comment

begin_function_decl
name|DWORD
name|FilterExceptionInformation
parameter_list|(
name|struct
name|EXCEPTION_INFO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|NotFilterExpression
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{
name|__try
block|{
name|__try
block|{       }
name|__finally
block|{       }
block|}
name|__finally
block|{     }
block|}
name|__finally
block|{   }
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{    }
block|}
end_function

begin_comment
comment|// expected-error{{expected '__except' or '__finally' block}}
end_comment

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__except
argument_list|(
argument|FilterExpression()
argument_list|)
block|{
comment|// expected-warning{{implicit declaration of function '__except' is invalid in C99}} \
comment|// expected-error{{too few arguments to function call, expected 1, have 0}}
block|}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__finally
block|{ }
comment|// expected-error{{}}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{
name|int
name|try_scope
init|=
literal|0
decl_stmt|;
block|}
comment|// TODO: expected expression is an extra error
name|__except
argument_list|(
argument|try_scope ?
literal|1
argument|: -
literal|1
argument_list|)
comment|// expected-error{{undeclared identifier 'try_scope'}} expected-error{{expected expression}}
block|{}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{    }
comment|// TODO: Why are there two errors?
name|__except
argument_list|( )
block|{
comment|// expected-error{{expected expression}} expected-error{{expected expression}}
block|}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{    }
name|__except
argument_list|(
argument|FilterExpression(GetExceptionCode())
argument_list|)
block|{    }
name|__try
block|{    }
name|__except
argument_list|(
argument|FilterExpression(__exception_code())
argument_list|)
block|{    }
name|__try
block|{    }
name|__except
argument_list|(
argument|FilterExceptionInformation(__exception_info())
argument_list|)
block|{    }
name|__try
block|{    }
name|__except
argument_list|(
argument|FilterExceptionInformation( GetExceptionInformation() )
argument_list|)
block|{    }
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{    }
name|__except
argument_list|(
argument|NotFilterExpression()
argument_list|)
block|{
comment|// expected-error{{filter expression type should be an integral value not 'const char *'}}
block|}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|int
name|function_scope
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|int
name|try_scope
init|=
literal|0
decl_stmt|;
block|}
name|__except
argument_list|(
argument|FilterExpression(GetExceptionCode())
argument_list|)
block|{
operator|(
name|void
operator|)
name|function_scope
expr_stmt|;
operator|(
name|void
operator|)
name|try_scope
expr_stmt|;
comment|// expected-error{{undeclared identifier}}
block|}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|int
name|function_scope
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|int
name|try_scope
init|=
literal|0
decl_stmt|;
block|}
name|__finally
block|{
operator|(
name|void
operator|)
name|function_scope
expr_stmt|;
operator|(
name|void
operator|)
name|try_scope
expr_stmt|;
comment|// expected-error{{undeclared identifier}}
block|}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|int
name|function_scope
init|=
literal|0
decl_stmt|;
name|__try
block|{    }
name|__except
argument_list|(
argument|function_scope ?
literal|1
argument|: -
literal|1
argument_list|)
block|{}
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|BORLAND
end_ifdef

begin_function
name|void
name|TEST
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__abnormal_termination
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
operator|(
name|void
operator|)
name|AbnormalTermination
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
name|__try
block|{
operator|(
name|void
operator|)
name|AbnormalTermination
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
operator|(
name|void
operator|)
name|__abnormal_termination
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
operator|(
name|void
operator|)
name|AbnormalTermination
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
operator|(
name|void
operator|)
name|__abnormal_termination
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
block|}
name|__try
block|{   }
name|__finally
block|{
name|AbnormalTermination
argument_list|()
expr_stmt|;
name|__abnormal_termination
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|TEST
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__exception_info
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except filter expression}}
operator|(
name|void
operator|)
name|GetExceptionInformation
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except filter expression}}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|BORLAND
operator|(
name|void
operator|)
name|__exception_code
expr_stmt|;
comment|// expected-error{{builtin functions must be directly called}}
endif|#
directive|endif
operator|(
name|void
operator|)
name|__exception_code
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except block or filter expression}}
operator|(
name|void
operator|)
name|GetExceptionCode
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except block or filter expression}}
block|}
end_function

begin_function
name|void
name|TEST
parameter_list|()
block|{
name|__try
block|{   }
name|__except
argument_list|(
literal|1
argument_list|)
block|{
name|GetExceptionCode
argument_list|()
expr_stmt|;
comment|// valid
name|GetExceptionInformation
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except filter expression}}
block|}
block|}
end_function

begin_function
name|void
name|test_seh_leave_stmt
parameter_list|()
block|{
name|__leave
expr_stmt|;
comment|// expected-error{{'__leave' statement not in __try block}}
name|__try
block|{
name|__leave
expr_stmt|;
name|__leave
literal|4
expr_stmt|;
comment|// expected-error{{expected ';' after __leave statement}}
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
name|__leave
expr_stmt|;
comment|// expected-error{{'__leave' statement not in __try block}}
block|}
name|__try
block|{
name|__leave
expr_stmt|;
block|}
name|__finally
block|{
name|__leave
expr_stmt|;
comment|// expected-error{{'__leave' statement not in __try block}}
block|}
name|__leave
expr_stmt|;
comment|// expected-error{{'__leave' statement not in __try block}}
block|}
end_function

begin_function
name|void
name|test_jump_out_of___finally
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{
name|__try
block|{     }
name|__finally
block|{
continue|continue;
comment|// expected-warning{{jump out of __finally block has undefined behavior}}
block|}
block|}
name|__try
block|{   }
name|__finally
block|{
while|while
condition|(
literal|1
condition|)
block|{
continue|continue;
block|}
block|}
comment|// Check that a deep __finally containing a block with a shallow continue
comment|// doesn't trigger the warning.
while|while
condition|(
literal|1
condition|)
block|{
block|{
block|{
block|{
name|__try
block|{     }
name|__finally
block|{
lambda|^
block|{
while|while
condition|(
literal|1
condition|)
continue|continue;
block|}
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
while|while
condition|(
literal|1
condition|)
block|{
name|__try
block|{     }
name|__finally
block|{
break|break;
comment|// expected-warning{{jump out of __finally block has undefined behavior}}
block|}
block|}
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|1
case|:
name|__try
block|{     }
name|__finally
block|{
break|break;
comment|// expected-warning{{jump out of __finally block has undefined behavior}}
block|}
block|}
name|__try
block|{   }
name|__finally
block|{
while|while
condition|(
literal|1
condition|)
block|{
break|break;
block|}
block|}
name|__try
block|{
name|__try
block|{     }
name|__finally
block|{
name|__leave
expr_stmt|;
comment|// expected-warning{{jump out of __finally block has undefined behavior}}
block|}
block|}
name|__finally
block|{   }
name|__try
block|{   }
name|__finally
block|{
name|__try
block|{
name|__leave
expr_stmt|;
block|}
name|__finally
block|{     }
block|}
name|__try
block|{   }
name|__finally
block|{
return|return;
comment|// expected-warning{{jump out of __finally block has undefined behavior}}
block|}
name|__try
block|{   }
name|__finally
block|{
lambda|^
block|{
return|return;
block|}
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|test_typo_in_except
parameter_list|()
block|{
name|__try
block|{   }
name|__except
argument_list|(
argument|undeclared_identifier
argument_list|)
block|{
comment|// expected-error {{use of undeclared identifier 'undeclared_identifier'}} expected-error {{expected expression}}
block|}
block|}
end_function

end_unit

