begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* argmatch.h -- declarations for matching arguments against option lists */
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
name|__ARGMATCH_P
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
name|__ARGMATCH_P
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
name|int
name|argmatch
name|__ARGMATCH_P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|invalid_arg
name|__ARGMATCH_P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|program_name
index|[]
decl_stmt|;
end_decl_stmt

end_unit

