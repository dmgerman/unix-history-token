begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ngstuff.h,v 4.3 85/05/01 11:45:12 lwall Exp $  *  * $Log:	ngstuff.h,v $  * Revision 4.3  85/05/01  11:45:12  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_define
define|#
directive|define
name|NN_NORM
value|0
end_define

begin_define
define|#
directive|define
name|NN_INP
value|1
end_define

begin_define
define|#
directive|define
name|NN_REREAD
value|2
end_define

begin_define
define|#
directive|define
name|NN_ASK
value|3
end_define

begin_function_decl
name|void
name|ngstuff_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|escapade
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|switcheroo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|numnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perform
parameter_list|()
function_decl|;
end_function_decl

end_unit

