begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: rt-select.h,v 3.0 1992/12/14 00:14:15 davison Trn $ */
end_comment

begin_define
define|#
directive|define
name|MAX_SEL
value|64
end_define

begin_decl_stmt
name|EXT
name|bool
name|sel_rereading
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_mode
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_threadmode
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_THREAD
value|0
end_define

begin_define
define|#
directive|define
name|SM_SUBJECT
value|1
end_define

begin_define
define|#
directive|define
name|SM_ARTICLE
value|2
end_define

begin_decl_stmt
name|EXT
name|char
modifier|*
name|sel_mode_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_sort
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_artsort
name|INIT
argument_list|(
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_threadsort
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SS_DATE
value|0
end_define

begin_define
define|#
directive|define
name|SS_SUBJECT
value|1
end_define

begin_define
define|#
directive|define
name|SS_AUTHOR
value|2
end_define

begin_define
define|#
directive|define
name|SS_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|SS_GROUPS
value|4
end_define

begin_decl_stmt
name|EXT
name|char
modifier|*
name|sel_sort_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_direction
name|INIT
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|sel_exclusive
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|sel_mask
name|INIT
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|selected_only
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|ART_UNREAD
name|selected_count
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|selected_subj_cnt
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|added_articles
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sel_item
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|line
decl_stmt|;
name|int
name|sel
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|EXT
name|char
modifier|*
name|sel_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|sel_item
name|sel_items
index|[
name|MAX_SEL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_item_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_item_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_total_arts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_prior_arts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_page_arts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_page_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_max_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sel_last_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|sel_at_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
modifier|*
name|sel_page_app
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SUBJECT
modifier|*
name|sel_page_sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
modifier|*
name|sel_next_app
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SUBJECT
modifier|*
name|sel_next_sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|ARTICLE
modifier|*
name|sel_last_ap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SUBJECT
modifier|*
name|sel_last_sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|do_selector
name|_
argument_list|(
operator|(
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DS_POS
value|0
end_define

begin_define
define|#
directive|define
name|DS_ASK
value|1
end_define

begin_define
define|#
directive|define
name|DS_UPDATE
value|2
end_define

begin_define
define|#
directive|define
name|DS_DISPLAY
value|3
end_define

begin_define
define|#
directive|define
name|DS_RESTART
value|4
end_define

begin_define
define|#
directive|define
name|DS_STATUS
value|5
end_define

begin_define
define|#
directive|define
name|DS_QUIT
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|empty_complaint
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sel_cleanup
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|sel_command
name|_
argument_list|(
operator|(
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

