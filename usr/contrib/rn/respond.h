begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: respond.h,v 4.3 85/05/01 11:47:50 lwall Exp $  *  * $Log:	respond.h,v $  * Revision 4.3  85/05/01  11:47:50  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|savedest
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* value of %b */
end_comment

begin_decl_stmt
name|EXT
name|ART_POS
name|savefrom
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of %B */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|headname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SAVE_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|SAVE_DONE
value|1
end_define

begin_function_decl
name|void
name|respond_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save_article
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cancel_article
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|followup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invoke
parameter_list|()
function_decl|;
end_function_decl

end_unit

