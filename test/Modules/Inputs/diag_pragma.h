begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|DIAG_PRAGMA_MACRO
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wparentheses"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|char
operator|*
name|f
argument_list|(
argument|T t
argument_list|)
block|{
return|return
literal|"foo"
operator|+
name|t
return|;
block|}
end_expr_stmt

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wstring-plus-int"
end_pragma

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|char
operator|*
name|g
argument_list|(
argument|T t
argument_list|)
block|{
return|return
literal|"foo"
operator|+
name|t
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

