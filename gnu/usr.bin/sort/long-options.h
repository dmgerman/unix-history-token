begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_undef
undef|#
directive|undef
name|__P
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
end_if

begin_define
define|#
directive|define
name|__P
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
name|__P
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
name|void
name|parse_long_options
name|__P
argument_list|(
operator|(
name|int
name|_argc
operator|,
name|char
operator|*
operator|*
name|_argv
operator|,
specifier|const
name|char
operator|*
name|_command_name
operator|,
specifier|const
name|char
operator|*
name|_version_string
operator|,
name|void
argument_list|(
operator|*
name|_usage
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

