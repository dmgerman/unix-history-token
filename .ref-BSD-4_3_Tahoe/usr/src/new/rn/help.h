begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: help.h,v 4.3 85/05/01 11:39:19 lwall Exp $  *  * $Log:	help.h,v $  * Revision 4.3  85/05/01  11:39:19  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|void
name|help_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|help_ng
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|help_art
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|help_page
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ESCSUBS
end_ifdef

begin_function_decl
name|int
name|help_subs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

