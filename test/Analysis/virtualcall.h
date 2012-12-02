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
comment|// expected-warning{{Call virtual functions during construction or destruction will never go to a more derived class}}
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

