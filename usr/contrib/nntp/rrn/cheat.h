begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: cheat.h,v 4.3 85/05/01 11:36:58 lwall Exp $  *  * $Log:	cheat.h,v $  * Revision 4.3  85/05/01  11:36:58  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|PENDING
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|CACHESUBJ
end_ifdef

begin_decl_stmt
name|EXT
name|ART_NUM
name|subj_to_get
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|cheat_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|look_ahead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|collect_subjects
parameter_list|()
function_decl|;
end_function_decl

end_unit

