begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: init.h,v 4.3 85/05/01 11:40:46 lwall Exp $  *  * $Log:	init.h,v $  * Revision 4.3  85/05/01  11:40:46  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|lockname
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|initialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newsnews_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|version_check
parameter_list|()
function_decl|;
end_function_decl

end_unit

