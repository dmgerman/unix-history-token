begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: head.h,v 4.3 85/05/01 11:38:31 lwall Exp $  *  * $Log:	head.h,v $  * Revision 4.3  85/05/01  11:38:31  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_define
define|#
directive|define
name|HEAD_FIRST
value|1
end_define

begin_comment
comment|/* types of header lines (if only C really believed in enums)  * (These must stay in alphabetic order at least in the first letter.  * Within each letter it helps to arrange in increasing likelihood.)  */
end_comment

begin_define
define|#
directive|define
name|PAST_HEADER
value|0
end_define

begin_comment
comment|/* body */
end_comment

begin_define
define|#
directive|define
name|SOME_LINE
value|1
end_define

begin_comment
comment|/* unrecognized */
end_comment

begin_define
define|#
directive|define
name|ARTID_LINE
value|2
end_define

begin_comment
comment|/* article-i.d. */
end_comment

begin_define
define|#
directive|define
name|APPR_LINE
value|3
end_define

begin_comment
comment|/* approved */
end_comment

begin_define
define|#
directive|define
name|DIST_LINE
value|4
end_define

begin_comment
comment|/* distribution */
end_comment

begin_define
define|#
directive|define
name|DATE_LINE
value|5
end_define

begin_comment
comment|/* date */
end_comment

begin_define
define|#
directive|define
name|RECEIVED_LINE
value|6
end_define

begin_comment
comment|/* date-received */
end_comment

begin_define
define|#
directive|define
name|EXPIR_LINE
value|7
end_define

begin_comment
comment|/* expires */
end_comment

begin_define
define|#
directive|define
name|FOLLOW_LINE
value|8
end_define

begin_comment
comment|/* followup-to */
end_comment

begin_define
define|#
directive|define
name|FROM_LINE
value|9
end_define

begin_comment
comment|/* from */
end_comment

begin_define
define|#
directive|define
name|KEYW_LINE
value|10
end_define

begin_comment
comment|/* keywords */
end_comment

begin_define
define|#
directive|define
name|LINES_LINE
value|11
end_define

begin_comment
comment|/* lines */
end_comment

begin_define
define|#
directive|define
name|MESSID_LINE
value|12
end_define

begin_comment
comment|/* message-id */
end_comment

begin_define
define|#
directive|define
name|NFFR_LINE
value|13
end_define

begin_comment
comment|/* nf-from */
end_comment

begin_define
define|#
directive|define
name|NFID_LINE
value|14
end_define

begin_comment
comment|/* nf-id */
end_comment

begin_define
define|#
directive|define
name|NGS_LINE
value|15
end_define

begin_comment
comment|/* newsgroups */
end_comment

begin_define
define|#
directive|define
name|ORG_LINE
value|16
end_define

begin_comment
comment|/* organization */
end_comment

begin_define
define|#
directive|define
name|PATH_LINE
value|17
end_define

begin_comment
comment|/* path */
end_comment

begin_define
define|#
directive|define
name|POSTED_LINE
value|18
end_define

begin_comment
comment|/* posted */
end_comment

begin_define
define|#
directive|define
name|PVER_LINE
value|19
end_define

begin_comment
comment|/* posting-version */
end_comment

begin_define
define|#
directive|define
name|REPLY_LINE
value|20
end_define

begin_comment
comment|/* reply-to */
end_comment

begin_define
define|#
directive|define
name|REFS_LINE
value|21
end_define

begin_comment
comment|/* references */
end_comment

begin_define
define|#
directive|define
name|RVER_LINE
value|22
end_define

begin_comment
comment|/* relay-version */
end_comment

begin_define
define|#
directive|define
name|SENDER_LINE
value|23
end_define

begin_comment
comment|/* sender */
end_comment

begin_define
define|#
directive|define
name|SUMRY_LINE
value|24
end_define

begin_comment
comment|/* summary */
end_comment

begin_define
define|#
directive|define
name|SUBJ_LINE
value|25
end_define

begin_comment
comment|/* subject */
end_comment

begin_define
define|#
directive|define
name|XREF_LINE
value|26
end_define

begin_comment
comment|/* xref */
end_comment

begin_define
define|#
directive|define
name|HEAD_LAST
value|27
end_define

begin_comment
comment|/* one more than the last one above */
end_comment

begin_struct
struct|struct
name|headtype
block|{
name|char
modifier|*
name|ht_name
decl_stmt|;
comment|/* header line identifier */
ifdef|#
directive|ifdef
name|pdp11
name|short
name|ht_minpos
decl_stmt|;
name|short
name|ht_maxpos
decl_stmt|;
else|#
directive|else
name|ART_POS
name|ht_minpos
decl_stmt|;
comment|/* pointer to beginning of line in article */
name|ART_POS
name|ht_maxpos
decl_stmt|;
comment|/* pointer to end of line in article */
endif|#
directive|endif
name|char
name|ht_length
decl_stmt|;
comment|/* could make these into nybbles but */
name|char
name|ht_flags
decl_stmt|;
comment|/* it wouldn't save space normally */
block|}
struct|;
end_struct

begin_comment
comment|/* due to alignment considerations */
end_comment

begin_define
define|#
directive|define
name|HT_HIDE
value|1
end_define

begin_comment
comment|/* -h on this line */
end_comment

begin_define
define|#
directive|define
name|HT_MAGIC
value|2
end_define

begin_comment
comment|/* do any special processing on this line */
end_comment

begin_comment
comment|/* This array must stay in the same order as the list above */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXT
name|struct
name|headtype
name|htype
index|[
name|HEAD_LAST
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|headtype
name|htype
index|[
name|HEAD_LAST
index|]
init|=
block|{
comment|/* name             minpos   maxpos  length   flag */
block|{
literal|"BODY"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|"unrecognized"
block|,
literal|0
block|,
literal|0
block|,
literal|12
block|,
literal|0
block|}
block|,
block|{
literal|"article-i.d."
block|,
literal|0
block|,
literal|0
block|,
literal|12
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"approved"
block|,
literal|0
block|,
literal|0
block|,
literal|8
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"distribution"
block|,
literal|0
block|,
literal|0
block|,
literal|12
block|,
literal|0
block|}
block|,
block|{
literal|"date"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|"date-received"
block|,
literal|0
block|,
literal|0
block|,
literal|13
block|,
literal|0
block|}
block|,
block|{
literal|"expires"
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
name|HT_HIDE
operator||
name|HT_MAGIC
block|}
block|,
block|{
literal|"followup-to"
block|,
literal|0
block|,
literal|0
block|,
literal|11
block|,
literal|0
block|}
block|,
block|{
literal|"from"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|"keywords"
block|,
literal|0
block|,
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|"lines"
block|,
literal|0
block|,
literal|0
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|"message-id"
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|,
literal|0
block|}
block|,
block|{
literal|"nf-from"
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"nf-id"
block|,
literal|0
block|,
literal|0
block|,
literal|5
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"newsgroups"
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|,
name|HT_MAGIC
operator||
name|HT_HIDE
block|}
block|,
block|{
literal|"organization"
block|,
literal|0
block|,
literal|0
block|,
literal|12
block|,
literal|0
block|}
block|,
block|{
literal|"path"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"posted"
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"posting-version"
block|,
literal|0
block|,
literal|0
block|,
literal|15
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"reply-to"
block|,
literal|0
block|,
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|"references"
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|,
literal|0
block|}
block|,
block|{
literal|"relay-version"
block|,
literal|0
block|,
literal|0
block|,
literal|13
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"sender"
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|"summary"
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
literal|0
block|}
block|,
block|{
literal|"subject"
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
name|HT_MAGIC
block|}
block|,
block|{
literal|"xref"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
name|HT_HIDE
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASYNC_PARSE
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|parsed_art
name|INIT
argument_list|(
literal|0
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
name|in_header
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we decoding the header? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CACHESUBJ
end_ifdef

begin_decl_stmt
name|EXT
name|char
modifier|*
modifier|*
name|subj_list
name|INIT
argument_list|(
name|Null
argument_list|(
name|char
operator|*
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|head_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_line_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_header
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|parseline
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ASYNC_PARSE
end_ifdef

begin_function_decl
name|int
name|parse_maybe
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|fetchsubj
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fetchlines
parameter_list|()
function_decl|;
end_function_decl

end_unit

