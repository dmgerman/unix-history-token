begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: nntp.h,v 3.0 1992/12/14 00:14:55 davison Trn $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NNTP
end_ifdef

begin_decl_stmt
name|bool
name|nntp_group
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
name|bool
name|nntp_stat
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
name|nntp_header
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|nntp_body
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|nntp_time
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
name|nntp_newgroups
name|_
argument_list|(
operator|(
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|nntp_listgroup
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nntp_get_a_line
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
name|nntp_artname
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nntp_cleanup
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_XTHREAD
end_ifdef

begin_decl_stmt
name|long
name|nntp_readcheck
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|nntp_read
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nntpclient.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_NNTP */
end_comment

end_unit

