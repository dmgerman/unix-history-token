begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: art.h,v 4.3 85/05/01 11:35:29 lwall Exp $  *  * $Log:	art.h,v $  * Revision 4.3  85/05/01  11:35:29  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_comment
comment|/* do_article() return values */
end_comment

begin_define
define|#
directive|define
name|DA_NORM
value|0
end_define

begin_define
define|#
directive|define
name|DA_RAISE
value|1
end_define

begin_define
define|#
directive|define
name|DA_CLEAN
value|2
end_define

begin_define
define|#
directive|define
name|DA_TOEND
value|3
end_define

begin_function_decl
name|void
name|art_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_article
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|page_switch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|innermore
parameter_list|()
function_decl|;
end_function_decl

end_unit

