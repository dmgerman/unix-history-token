begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: rt-process.h,v 3.0 1992/12/14 00:14:15 davison Trn $ */
end_comment

begin_decl_stmt
name|int
name|msgid_cmp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|HASHDATUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARTICLE
modifier|*
name|allocate_article
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|valid_article
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARTICLE
modifier|*
name|get_article
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
name|void
name|thread_article
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

