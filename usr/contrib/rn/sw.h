begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: sw.h,v 4.3 85/05/01 11:51:07 lwall Exp $  *  * $Log:	sw.h,v $  * Revision 4.3  85/05/01  11:51:07  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INNERSEARCH
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|gline
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

begin_function_decl
name|void
name|sw_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sw_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sw_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_switch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pr_switches
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cwd_check
parameter_list|()
function_decl|;
end_function_decl

end_unit

