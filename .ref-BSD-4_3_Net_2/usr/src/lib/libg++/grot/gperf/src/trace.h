begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_define
define|#
directive|define
name|T
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|T
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|Trace
block|{
name|private
label|:
specifier|static
name|int
name|nesting
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|public
label|:
name|Trace
argument_list|(
argument|char *n
argument_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%*scalling %s\n"
argument_list|,
literal|3
operator|*
name|nesting
operator|++
argument_list|,
literal|""
argument_list|,
name|name
operator|=
name|n
argument_list|)
expr_stmt|;
block|}
operator|~
name|Trace
argument_list|(
argument|void
argument_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%*sleaving %s\n"
argument_list|,
literal|3
operator|*
operator|--
name|nesting
argument_list|,
literal|""
argument_list|,
name|name
argument_list|)
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

