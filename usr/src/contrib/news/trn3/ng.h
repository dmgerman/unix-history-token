begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ng.h,v 3.0 1991/09/09 20:23:31 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|art
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current or prospective article # */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|recent_art
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous article # for '-' command */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|curr_art
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current article # */
end_comment

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
name|recent_artp
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* article_ptr equivilents */
end_comment

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
name|curr_artp
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
name|artp
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the article ptr we use when art is 0 */
end_comment

begin_decl_stmt
name|EXT
name|int
name|checkcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many articles have we read */
end_comment

begin_comment
comment|/*   in the current newsgroup since */
end_comment

begin_comment
comment|/*   the last checkpoint? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|docheckwhen
name|INIT
argument_list|(
literal|20
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how often to do checkpoint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAILCALL
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|mailcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check for mail when 0 mod 10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|char
modifier|*
name|mailcall
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|forcelast
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ought we show "End of newsgroup"? */
end_comment

begin_function_decl
name|EXT
name|bool
name|forcegrow
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do we want to recalculate size */
end_comment

begin_comment
comment|/* of newsgroup, e.g. after posting? */
end_comment

begin_define
define|#
directive|define
name|NG_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|NG_NORM
value|0
end_define

begin_define
define|#
directive|define
name|NG_ASK
value|1
end_define

begin_define
define|#
directive|define
name|NG_MINUS
value|2
end_define

begin_define
define|#
directive|define
name|NG_SELPRIOR
value|3
end_define

begin_define
define|#
directive|define
name|NG_SELNEXT
value|4
end_define

begin_decl_stmt
name|void
name|ng_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_newsgroup
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
name|int
name|art_switch
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
name|MAILCALL
end_ifdef

begin_decl_stmt
name|void
name|setmail
name|_
argument_list|(
operator|(
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|setdfltcmd
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
name|ask_catchup
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
name|ask_memorize
name|_
argument_list|(
operator|(
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

