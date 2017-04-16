begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|USE_PRAGMA
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Wshorten-64-to-32"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|int
name|convert
argument_list|(
argument|T V
argument_list|)
block|{
return|return
name|V
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PRAGMA
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

