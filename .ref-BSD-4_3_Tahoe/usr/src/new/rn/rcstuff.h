begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: rcstuff.h,v 4.3 85/05/01 11:46:49 lwall Exp $  *  * $Log:	rcstuff.h,v $  * Revision 4.3  85/05/01  11:46:49  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|rcline
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to lines of .newsrc */
end_comment

begin_decl_stmt
name|EXT
name|ART_UNREAD
name|toread
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|EXT
name|char
name|rcchar
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds the character : or ! while spot is \0 */
end_comment

begin_decl_stmt
name|EXT
name|char
name|rcnums
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset from rcline to numbers on line */
end_comment

begin_decl_stmt
name|EXT
name|ACT_POS
name|softptr
index|[
name|MAXRCLINE
index|]
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|bool
name|rcstuff_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|get_ng
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return TRUE if newsgroup can be found or added */
end_comment

begin_function_decl
name|NG_NUM
name|add_newsgroup
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RELOCATE
end_ifdef

begin_function_decl
name|NG_NUM
name|relocate_newsgroup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* move newsgroup around */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|list_newsgroups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|NG_NUM
name|find_ng
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return index of newsgroup */
end_comment

begin_function_decl
name|void
name|cleanup_rc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sethash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newsrc_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_rc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_old_rc
parameter_list|()
function_decl|;
end_function_decl

end_unit

