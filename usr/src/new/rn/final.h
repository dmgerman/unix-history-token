begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: final.h,v 4.3 85/05/01 11:38:17 lwall Exp $  *   * $Log:	final.h,v $  * Revision 4.3  85/05/01  11:38:17  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_comment
comment|/* cleanup status for fast exits */
end_comment

begin_function_decl
name|EXT
name|bool
name|panic
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we got hung up or something-- */
end_comment

begin_comment
comment|/*  so leave tty alone */
end_comment

begin_function_decl
name|EXT
name|bool
name|rc_changed
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* need we rewrite .newsrc? */
end_comment

begin_function_decl
name|EXT
name|bool
name|doing_ng
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do we need to reconstitute */
end_comment

begin_comment
comment|/* current rc line? */
end_comment

begin_decl_stmt
name|EXT
name|char
name|int_count
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many interrupts we've had */
end_comment

begin_comment
comment|/* signal catching routines */
end_comment

begin_function_decl
name|int
name|int_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sig_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_function_decl
name|int
name|stop_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cont_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|final_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finalize
parameter_list|()
function_decl|;
end_function_decl

end_unit

