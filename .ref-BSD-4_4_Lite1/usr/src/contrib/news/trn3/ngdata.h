begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ngdata.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|actfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the active file */
end_comment

begin_function_decl
name|EXT
name|bool
name|writesoft
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rewrite the soft pointer file? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|softtries
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|softmisses
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ART_NUM
name|absfirst
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1st real article in current newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|firstart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum unread article number in newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|lastart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum article number in newsgroup */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NNTP
end_ifdef

begin_decl_stmt
name|EXT
name|char
name|active_name
index|[
name|MAXFILENAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|time_t
name|lastactfetch
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MINFETCHTIME
value|(2 * 60 * 60)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|ART_NUM
modifier|*
name|abs1st
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 1st real article in newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|moderated
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|ThreadedGroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|activeitems
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of enties in active file */
end_comment

begin_decl_stmt
name|void
name|ngdata_init
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
name|access_ng
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
name|grow_ng
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ng_skip
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ART_NUM
name|getngsize
name|_
argument_list|(
operator|(
name|NG_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getngmissing
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACT_POS
name|findact
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
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ngdatansrv_init
name|_
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

