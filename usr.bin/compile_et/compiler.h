begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * definitions common to the source files of the error table compiler  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_comment
comment|/* loser */
end_comment

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|lang
block|{
name|lang_C
block|,
comment|/* ANSI C (default) */
name|lang_KRC
block|,
comment|/* C: ANSI + K&R */
name|lang_CPP
comment|/* C++ */
block|}
enum|;
end_enum

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump debugging info? */
end_comment

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error table source */
end_comment

begin_decl_stmt
name|enum
name|lang
name|language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|whoami
decl_stmt|;
end_decl_stmt

end_unit

