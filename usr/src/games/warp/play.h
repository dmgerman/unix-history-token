begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: play.h,v 7.0 86/10/08 15:13:12 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	play.h,v $  * Revision 7.0  86/10/08  15:13:12  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_decl_stmt
name|EXT
name|int
name|finish
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|timer
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|play
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|play_init
parameter_list|()
function_decl|;
end_function_decl

end_unit

