begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: rt-ov.h,v 3.0 1992/12/14 00:14:15 davison Trn $ */
end_comment

begin_decl_stmt
name|bool
name|ov_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ov_data
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|ART_NUM
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ov_close
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stuff internal to rt-ov.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
specifier|static
name|ARTICLE
modifier|*
name|ov_parse
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|USE_XOVER
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ov_name
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

