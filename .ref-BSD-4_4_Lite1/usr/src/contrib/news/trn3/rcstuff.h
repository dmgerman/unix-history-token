begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: rcstuff.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
modifier|*
name|rcline
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pointers to lines of .newsrc */
end_comment

begin_function_decl
name|EXT
name|ART_UNREAD
modifier|*
name|toread
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* number of articles to be read in newsgroup */
end_comment

begin_comment
comment|/*<0 => invalid or unsubscribed newsgroup */
end_comment

begin_define
define|#
directive|define
name|TR_ONE
value|((ART_UNREAD) 1)
end_define

begin_define
define|#
directive|define
name|TR_NONE
value|((ART_UNREAD) 0)
end_define

begin_define
define|#
directive|define
name|TR_UNSUB
value|((ART_UNREAD) -1)
end_define

begin_comment
comment|/* keep this one as -1, some tests use>= TR_UNSUB */
end_comment

begin_define
define|#
directive|define
name|TR_BOGUS
value|((ART_UNREAD) -2)
end_define

begin_define
define|#
directive|define
name|TR_JUNK
value|((ART_UNREAD) -3)
end_define

begin_define
define|#
directive|define
name|RCCHAR
parameter_list|(
name|ch
parameter_list|)
value|((ch) == '0' ? ':' : (ch))
end_define

begin_define
define|#
directive|define
name|ADDNEW_SUB
value|':'
end_define

begin_define
define|#
directive|define
name|ADDNEW_UNSUB
value|'!'
end_define

begin_define
define|#
directive|define
name|GNG_RELOC
value|0x0001
end_define

begin_define
define|#
directive|define
name|GNG_FUZZY
value|0x0002
end_define

begin_function_decl
name|EXT
name|char
modifier|*
name|rcchar
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* holds the character : or ! while spot is \0 */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|rcnums
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* offset from rcline to numbers on line */
end_comment

begin_function_decl
name|EXT
name|ACT_POS
modifier|*
name|softptr
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* likely ptr to active file entry for newsgroup */
end_comment

begin_function_decl
name|EXT
name|bool
name|paranoid
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* did we detect some inconsistency in .newsrc? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|maxrcline
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current maximum # of lines in .newsrc */
end_comment

begin_decl_stmt
name|EXT
name|int
name|addnewbydefault
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|rcstuff_init
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
name|abandon_ng
name|_
argument_list|(
operator|(
name|NG_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|get_ng
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

begin_comment
comment|/* return TRUE if newsgroup is found or added */
end_comment

begin_decl_stmt
name|NG_NUM
name|add_newsgroup
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RELOCATE
end_ifdef

begin_decl_stmt
name|NG_NUM
name|relocate_newsgroup
name|_
argument_list|(
operator|(
name|NG_NUM
operator|,
name|NG_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* move newsgroup around */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|list_newsgroups
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NG_NUM
name|find_ng
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return index of newsgroup */
end_comment

begin_decl_stmt
name|void
name|cleanup_rc
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
name|sethash
name|_
argument_list|(
operator|(
name|NG_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hash
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
name|newsrc_check
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
name|checkpoint_rc
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
name|write_rc
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
name|get_old_rc
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

