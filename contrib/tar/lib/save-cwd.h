begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SAVE_CWD_H
end_ifndef

begin_define
define|#
directive|define
name|SAVE_CWD_H
value|1
end_define

begin_struct
struct|struct
name|saved_cwd
block|{
name|int
name|desc
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

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
name|int
name|save_cwd
name|PARAMS
argument_list|(
operator|(
expr|struct
name|saved_cwd
operator|*
name|cwd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|restore_cwd
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|saved_cwd
operator|*
name|cwd
operator|,
specifier|const
name|char
operator|*
name|dest
operator|,
specifier|const
name|char
operator|*
name|from
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_cwd
name|PARAMS
argument_list|(
operator|(
expr|struct
name|saved_cwd
operator|*
name|cwd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SAVE_CWD_H */
end_comment

end_unit

