begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: rt-util.h,v 3.0 1992/12/14 00:14:15 davison Trn $ */
end_comment

begin_decl_stmt
name|char
modifier|*
name|extract_name
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|compress_from
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|compress_name
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|compress_subj
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_subject_start
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_STRCASECMP
end_ifndef

begin_decl_stmt
name|int
name|strCASEcmp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strnCASEcmp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
name|spin_char
name|INIT
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* char to put back when we're done spinning */
end_comment

begin_define
define|#
directive|define
name|SPIN_OFF
value|0
end_define

begin_define
define|#
directive|define
name|SPIN_POP
value|1
end_define

begin_define
define|#
directive|define
name|SPIN_FOREGROUND
value|2
end_define

begin_define
define|#
directive|define
name|SPIN_BACKGROUND
value|3
end_define

begin_decl_stmt
name|void
name|setspin
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spin
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

