begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: sig.h,v 7.0 86/10/08 15:13:32 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	sig.h,v $  * Revision 7.0  86/10/08  15:13:32  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_function_decl
name|void
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
name|void
name|cont_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stop_catcher
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|mytstp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sig_init
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

