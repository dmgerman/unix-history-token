begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prototypes for quote.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
specifier|const
modifier|*
name|quote_n
name|PARAMS
argument_list|(
operator|(
name|int
name|n
operator|,
name|char
specifier|const
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|quote
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

