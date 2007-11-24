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
name|__PROTO
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
name|__PROTO
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

begin_decl_stmt
name|int
name|save_cwd
name|__PROTO
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
name|__PROTO
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_cwd
name|__PROTO
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

