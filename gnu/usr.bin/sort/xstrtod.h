begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|XSTRTOD_H
end_ifndef

begin_define
define|#
directive|define
name|XSTRTOD_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|)
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

begin_comment
comment|/* GCC.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not __P.  */
end_comment

begin_decl_stmt
name|int
name|xstrtod
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|str
operator|,
specifier|const
name|char
operator|*
operator|*
name|ptr
operator|,
name|double
operator|*
name|result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XSTRTOD_H */
end_comment

end_unit

