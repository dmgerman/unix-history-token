begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fborland-extensions -fsyntax-only -verify %s
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
name|int
name|__exception_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|EXCEPTION_INFO
modifier|*
name|__exception_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
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

begin_function
name|void
name|TEST
parameter_list|()
block|{
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

begin_function
name|void
name|TEST
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__exception_code
expr_stmt|;
comment|// expected-error{{only allowed in __except block}}
operator|(
name|void
operator|)
name|__exception_info
expr_stmt|;
comment|// expected-error{{only allowed in __except filter expression}}
operator|(
name|void
operator|)
name|__abnormal_termination
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
operator|(
name|void
operator|)
name|GetExceptionCode
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except block}}
operator|(
name|void
operator|)
name|GetExceptionInformation
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __except filter expression}}
operator|(
name|void
operator|)
name|AbnormalTermination
argument_list|()
expr_stmt|;
comment|// expected-error{{only allowed in __finally block}}
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

end_unit

