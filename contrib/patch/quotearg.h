begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quote.h -- declarations for quoting system arguments */
end_comment

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|__GNUC__
end_if

begin_define
define|#
directive|define
name|__QUOTEARG_P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__QUOTEARG_P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|size_t
name|quote_system_arg
name|__QUOTEARG_P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

