begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|AS_SYSTEM
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_decl_stmt
name|namespace
name|system
block|{
name|class
name|A
block|{
name|public
label|:
name|A
argument_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
name|virtual
name|int
name|foo
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|namespace
name|header
block|{
name|class
name|A
block|{
name|public
label|:
name|A
argument_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|PUREONLY
if|#
directive|if
name|INTERPROCEDURAL
comment|// expected-warning-re@-3 {{{{^}}Call Path : fooCall to virtual function during construction will not dispatch to derived class}}
else|#
directive|else
comment|// expected-warning-re@-5 {{{{^}}Call to virtual function during construction will not dispatch to derived class}}
endif|#
directive|endif
endif|#
directive|endif
block|}
name|virtual
name|int
name|foo
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

