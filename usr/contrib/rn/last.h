begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: last.h,v 4.3 85/05/01 11:42:22 lwall Exp $  *  * $Log:	last.h,v $  * Revision 4.3  85/05/01  11:42:22  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|lastngname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* last newsgroup read, from .rnlast file */
end_comment

begin_decl_stmt
name|EXT
name|long
name|lasttime
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time last rn was started up */
end_comment

begin_decl_stmt
name|EXT
name|long
name|lastactsiz
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of active file when rn last started up */
end_comment

begin_function_decl
name|void
name|last_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writelast
parameter_list|()
function_decl|;
end_function_decl

end_unit

