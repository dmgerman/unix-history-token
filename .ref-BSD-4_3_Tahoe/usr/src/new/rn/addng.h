begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: addng.h,v 4.3 85/05/01 11:34:48 lwall Exp $  *  * $Log:	addng.h,v $  * Revision 4.3  85/05/01  11:34:48  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|void
name|addng_init
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FINDNEWNG
end_ifdef

begin_function_decl
name|bool
name|newlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|birthof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|scanactive
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

