begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: head.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
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
value|(PAST_HEADER+1)
end_define

begin_comment
comment|/* unrecognized */
end_comment

begin_define
define|#
directive|define
name|ARTID_LINE
value|(SOME_LINE+1)
end_define

begin_comment
comment|/* article-i.d. */
end_comment

begin_define
define|#
directive|define
name|APPR_LINE
value|(ARTID_LINE+1)
end_define

begin_comment
comment|/* approved */
end_comment

begin_define
define|#
directive|define
name|ACAT_LINE
value|(APPR_LINE+1)
end_define

begin_comment
comment|/* ACategory (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|ANPA_LINE
value|(ACAT_LINE+1)
end_define

begin_comment
comment|/* ANPA (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|CODES_LINE
value|(ANPA_LINE+1)
end_define

begin_comment
comment|/* Codes (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|CONTENT_LINE
value|(CODES_LINE+1)
end_define

begin_comment
comment|/* MIME */
end_comment

begin_define
define|#
directive|define
name|CANCEL_LINE
value|(CONTENT_LINE+1)
end_define

begin_comment
comment|/* cancel */
end_comment

begin_define
define|#
directive|define
name|DIST_LINE
value|(CANCEL_LINE+1)
end_define

begin_comment
comment|/* distribution */
end_comment

begin_define
define|#
directive|define
name|DATE_LINE
value|(DIST_LINE+1)
end_define

begin_comment
comment|/* date */
end_comment

begin_define
define|#
directive|define
name|RECEIVED_LINE
value|(DATE_LINE+1)
end_define

begin_comment
comment|/* date-received */
end_comment

begin_define
define|#
directive|define
name|EXPIR_LINE
value|(RECEIVED_LINE+1)
end_define

begin_comment
comment|/* expires */
end_comment

begin_define
define|#
directive|define
name|FOLLOW_LINE
value|(EXPIR_LINE+1)
end_define

begin_comment
comment|/* followup-to */
end_comment

begin_define
define|#
directive|define
name|FROM_LINE
value|(FOLLOW_LINE+1)
end_define

begin_comment
comment|/* from */
end_comment

begin_define
define|#
directive|define
name|FORM_LINE
value|(FROM_LINE+1)
end_define

begin_comment
comment|/* Format (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|KEYW_LINE
value|(FORM_LINE+1)
end_define

begin_comment
comment|/* keywords */
end_comment

begin_define
define|#
directive|define
name|LINES_LINE
value|(KEYW_LINE+1)
end_define

begin_comment
comment|/* lines */
end_comment

begin_define
define|#
directive|define
name|MESSID_LINE
value|(LINES_LINE+1)
end_define

begin_comment
comment|/* message-id */
end_comment

begin_define
define|#
directive|define
name|NFFR_LINE
value|(MESSID_LINE+1)
end_define

begin_comment
comment|/* nf-from */
end_comment

begin_define
define|#
directive|define
name|NFID_LINE
value|(NFFR_LINE+1)
end_define

begin_comment
comment|/* nf-id */
end_comment

begin_define
define|#
directive|define
name|NGS_LINE
value|(NFID_LINE+1)
end_define

begin_comment
comment|/* newsgroups */
end_comment

begin_define
define|#
directive|define
name|NNTPHOST_LINE
value|(NGS_LINE+1)
end_define

begin_comment
comment|/* nntp-posting-host */
end_comment

begin_define
define|#
directive|define
name|NOTE_LINE
value|(NNTPHOST_LINE+1)
end_define

begin_comment
comment|/* Note (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|ORG_LINE
value|(NOTE_LINE+1)
end_define

begin_comment
comment|/* organization */
end_comment

begin_define
define|#
directive|define
name|PATH_LINE
value|(ORG_LINE+1)
end_define

begin_comment
comment|/* path */
end_comment

begin_define
define|#
directive|define
name|POSTED_LINE
value|(PATH_LINE+1)
end_define

begin_comment
comment|/* posted */
end_comment

begin_define
define|#
directive|define
name|PVER_LINE
value|(POSTED_LINE+1)
end_define

begin_comment
comment|/* posting-version */
end_comment

begin_define
define|#
directive|define
name|PRI_LINE
value|(PVER_LINE+1)
end_define

begin_comment
comment|/* Priority (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|REPLY_LINE
value|(PRI_LINE+1)
end_define

begin_comment
comment|/* reply-to */
end_comment

begin_define
define|#
directive|define
name|REFS_LINE
value|(REPLY_LINE+1)
end_define

begin_comment
comment|/* references */
end_comment

begin_define
define|#
directive|define
name|RVER_LINE
value|(REFS_LINE+1)
end_define

begin_comment
comment|/* relay-version */
end_comment

begin_define
define|#
directive|define
name|SENDER_LINE
value|(RVER_LINE+1)
end_define

begin_comment
comment|/* sender */
end_comment

begin_define
define|#
directive|define
name|SUMRY_LINE
value|(SENDER_LINE+1)
end_define

begin_comment
comment|/* summary */
end_comment

begin_define
define|#
directive|define
name|SUBJ_LINE
value|(SUMRY_LINE+1)
end_define

begin_comment
comment|/* subject */
end_comment

begin_define
define|#
directive|define
name|SUPR_LINE
value|(SUBJ_LINE+1)
end_define

begin_comment
comment|/* supersedes */
end_comment

begin_define
define|#
directive|define
name|SLUG_LINE
value|(SUPR_LINE+1)
end_define

begin_comment
comment|/* Slugword (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|XREF_LINE
value|(SLUG_LINE+1)
end_define

begin_comment
comment|/* xref */
end_comment

begin_define
define|#
directive|define
name|XSUP_LINE
value|(XREF_LINE+1)
end_define

begin_comment
comment|/* X-Supersedes (ClariNet) */
end_comment

begin_define
define|#
directive|define
name|HEAD_LAST
value|(XSUP_LINE+1)
end_define

begin_comment
comment|/* total # of headers */
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
name|ART_POS
name|ht_minpos
decl_stmt|;
comment|/* pointer to beginning of line in article */
name|ART_POS
name|ht_maxpos
decl_stmt|;
comment|/* pointer to end of line in article */
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

begin_define
define|#
directive|define
name|HT_CACHED
value|4
end_define

begin_comment
comment|/* this information is cached in the article data */
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
literal|"acategory"
block|,
literal|0
block|,
literal|0
block|,
literal|9
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"anpa"
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
literal|"codes"
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
ifdef|#
directive|ifdef
name|METAMAIL
block|{
literal|"content-type"
block|,
literal|0
block|,
literal|0
block|,
literal|12
block|,
name|HT_MAGIC
block|}
block|,
else|#
directive|else
block|{
literal|"content-type"
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
endif|#
directive|endif
block|{
literal|"control"
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
name|HT_MAGIC
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
name|HT_CACHED
block|}
block|,
block|{
literal|"format"
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
name|HT_HIDE
operator||
name|HT_CACHED
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
ifdef|#
directive|ifdef
name|DBM_XREFS
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
operator||
name|HT_CACHED
block|}
block|,
else|#
directive|else
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
endif|#
directive|endif
block|{
literal|"nntp-posting-host"
block|,
literal|0
block|,
literal|0
block|,
literal|17
block|,
name|HT_HIDE
block|}
block|,
block|{
literal|"note"
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|,		}
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
literal|"priority"
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
literal|"reply-to"
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
literal|"references"
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|,
name|HT_HIDE
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
name|HT_HIDE
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
operator||
name|HT_CACHED
block|}
block|,
block|{
literal|"supersedes"
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
literal|"slugword"
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
ifdef|#
directive|ifdef
name|DBM_XREFS
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
block|,
else|#
directive|else
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
operator||
name|HT_CACHED
block|}
block|,
endif|#
directive|endif
block|{
literal|"x-supersedes"
block|,
literal|0
block|,
literal|0
block|,
literal|12
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

begin_comment
comment|/* the article number we've parsed */
end_comment

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

begin_decl_stmt
name|EXT
name|char
modifier|*
name|headbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|headbuf_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|head_init
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
name|set_line_type
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
name|void
name|start_header
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
name|end_header_line
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
name|end_header
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
name|parseline
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|parseheader
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fetchlines
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns a malloc'ed string */
end_comment

begin_decl_stmt
name|char
modifier|*
name|prefetchlines
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|int
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|dumpheader
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NNTP
end_ifdef

begin_define
define|#
directive|define
name|PREFETCH_SIZE
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fetchsubj
parameter_list|(
name|artnum
parameter_list|,
name|copy
parameter_list|)
value|prefetchlines(artnum,SUBJ_LINE,copy)
end_define

begin_define
define|#
directive|define
name|fetchfrom
parameter_list|(
name|artnum
parameter_list|,
name|copy
parameter_list|)
value|prefetchlines(artnum,FROM_LINE,copy)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DBM_XREFS
end_ifdef

begin_define
define|#
directive|define
name|fetchxref
parameter_list|(
name|artnum
parameter_list|,
name|copy
parameter_list|)
value|prefetchlines(artnum,NGS_LINE,copy)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fetchxref
parameter_list|(
name|artnum
parameter_list|,
name|copy
parameter_list|)
value|prefetchlines(artnum,XREF_LINE,copy)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

