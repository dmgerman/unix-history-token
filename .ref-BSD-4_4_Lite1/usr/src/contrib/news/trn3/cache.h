begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: cache.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_comment
comment|/* Subjects get their own structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rt_subj
block|{
name|struct
name|rt_subj
modifier|*
name|next
decl_stmt|;
name|struct
name|rt_subj
modifier|*
name|prev
decl_stmt|;
name|struct
name|rt_art
modifier|*
name|articles
decl_stmt|;
name|struct
name|rt_art
modifier|*
name|thread
decl_stmt|;
name|struct
name|rt_subj
modifier|*
name|thread_link
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
name|time_t
name|date
decl_stmt|;
name|short
name|flags
decl_stmt|;
name|short
name|misc
decl_stmt|;
comment|/* used for temporary totals and subject numbers */
block|}
name|SUBJECT
typedef|;
end_typedef

begin_comment
comment|/* subject flags */
end_comment

begin_define
define|#
directive|define
name|SF_SEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|SF_DEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|SF_DELSEL
value|0x0004
end_define

begin_define
define|#
directive|define
name|SF_OLDSEL
value|0x0008
end_define

begin_define
define|#
directive|define
name|SF_INCLUDED
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_THREAD
value|0x0100
end_define

begin_define
define|#
directive|define
name|SF_VISIT
value|0x0200
end_define

begin_define
define|#
directive|define
name|SF_WASSELECTED
value|0x0400
end_define

begin_define
define|#
directive|define
name|SF_AUTOSELECT
value|0x0800
end_define

begin_define
define|#
directive|define
name|SF_SUBJTRUNCED
value|0x1000
end_define

begin_comment
comment|/* This is our article-caching structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rt_art
block|{
name|time_t
name|date
decl_stmt|;
name|SUBJECT
modifier|*
name|subj
decl_stmt|;
name|char
modifier|*
name|from
decl_stmt|;
name|char
modifier|*
name|msgid
decl_stmt|;
name|char
modifier|*
name|xrefs
decl_stmt|;
name|struct
name|rt_art
modifier|*
name|parent
decl_stmt|;
comment|/* parent article */
name|struct
name|rt_art
modifier|*
name|child1
decl_stmt|;
comment|/* first child of a chain */
name|struct
name|rt_art
modifier|*
name|sibling
decl_stmt|;
comment|/* our next sibling */
name|struct
name|rt_art
modifier|*
name|subj_next
decl_stmt|;
comment|/* next article in subject order */
name|short
name|flags
decl_stmt|;
comment|/* user-settable flags */
name|short
name|padding
decl_stmt|;
block|}
name|ARTICLE
typedef|;
end_typedef

begin_comment
comment|/* article flags */
end_comment

begin_define
define|#
directive|define
name|AF_SEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|AF_DEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|AF_DELSEL
value|0x0004
end_define

begin_define
define|#
directive|define
name|AF_OLDSEL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AF_INCLUDED
value|0x0010
end_define

begin_define
define|#
directive|define
name|AF_READ
value|0x0020
end_define

begin_define
define|#
directive|define
name|AF_CACHED
value|0x0040
end_define

begin_define
define|#
directive|define
name|AF_THREADED
value|0x0080
end_define

begin_define
define|#
directive|define
name|AF_MISSING
value|0x0100
end_define

begin_define
define|#
directive|define
name|AF_AUTOKILL
value|0x0200
end_define

begin_define
define|#
directive|define
name|AF_AUTOKILLALL
value|0x0400
end_define

begin_define
define|#
directive|define
name|AF_AUTOSELECT
value|0x0800
end_define

begin_define
define|#
directive|define
name|AF_AUTOSELECTALL
value|0x1000
end_define

begin_define
define|#
directive|define
name|AF_AUTOFLAGS
value|(AF_AUTOKILL|AF_AUTOKILLALL|AF_AUTOSELECT|AF_AUTOSELECTALL)
end_define

begin_comment
comment|/* If AF_MISSING is NOT set the last 3 bits have the following meaning: */
end_comment

begin_define
define|#
directive|define
name|AF_HAS_RE
value|0x2000
end_define

begin_define
define|#
directive|define
name|AF_YANKBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|AF_FROMTRUNCED
value|0x8000
end_define

begin_comment
comment|/* These flags only have meaning when combined with AF_MISSING */
end_comment

begin_define
define|#
directive|define
name|AF_TMPMEM
value|(0x2000|AF_MISSING)
end_define

begin_define
define|#
directive|define
name|AF_FAKE
value|(0x4000|AF_MISSING)
end_define

begin_comment
comment|/* The following define is only valid as a flag to the select_article call */
end_comment

begin_define
define|#
directive|define
name|AF_ECHO
value|0x8000
end_define

begin_define
define|#
directive|define
name|Nullart
value|Null(ARTICLE*)
end_define

begin_define
define|#
directive|define
name|Nullsubj
value|Null(SUBJECT*)
end_define

begin_define
define|#
directive|define
name|was_read
parameter_list|(
name|a
parameter_list|)
value|(article_ptr(a)->flags& AF_READ)
end_define

begin_comment
comment|/* These must never use their args more than once in the definition */
end_comment

begin_define
define|#
directive|define
name|article_num
parameter_list|(
name|ap
parameter_list|)
value|(((ap)-article_list)+absfirst)
end_define

begin_define
define|#
directive|define
name|article_ptr
parameter_list|(
name|artnum
parameter_list|)
value|(article_list+((artnum)-absfirst))
end_define

begin_function_decl
name|EXT
name|ARTICLE
modifier|*
name|article_list
name|INIT
parameter_list|(
name|Nullart
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
modifier|*
name|artptr_list
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
modifier|*
name|artptr
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ARTSEARCH
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|srchahead
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we in subject scan mode? */
end_comment

begin_comment
comment|/* (if so, contains art # found or -1) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|ART_NUM
name|first_cached
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ART_NUM
name|last_cached
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|cached_all_in_range
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
name|sentinel_artp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|rt_subj
modifier|*
name|first_subject
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|rt_subj
modifier|*
name|last_subject
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|untrim_cache
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PENDING
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|subj_to_get
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ART_NUM
name|xref_to_get
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|cache_init
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
name|build_cache
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
name|grow_cache
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
name|close_cache
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
name|cache_article
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
name|void
name|check_poster
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
name|void
name|uncache_article
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fetchcache
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
comment|/* return actual cache ptr */
end_comment

begin_decl_stmt
name|char
modifier|*
name|get_cached_line
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|,
name|int
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_subj_line
name|_
argument_list|(
operator|(
name|ARTICLE
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

begin_decl_stmt
name|void
name|set_cached_line
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|look_ahead
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
name|cache_until_key
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
name|cache_subjects
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
name|cache_xrefs
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
name|cache_all_arts
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
name|cache_unread_arts
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
name|art_data
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|ART_NUM
operator|,
name|bool_int
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|cache_range
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clear_article
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
name|void
name|free_subject
name|_
argument_list|(
operator|(
name|SUBJECT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

