begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: rn.h,v 4.3 85/05/01 11:48:19 lwall Exp $  *  * $Log:	rn.h,v $  * Revision 4.3  85/05/01  11:48:19  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|ngname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* name of current newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|int
name|ngnlen
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current malloced size of ngname */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|ngdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* same thing in directory name form */
end_comment

begin_decl_stmt
name|EXT
name|int
name|ngdlen
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current malloced size of ngdir */
end_comment

begin_decl_stmt
name|EXT
name|NG_NUM
name|ng
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current newsgroup index into rcline and toread */
end_comment

begin_decl_stmt
name|EXT
name|NG_NUM
name|current_ng
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stable current newsgroup so we can ditz with ng */
end_comment

begin_decl_stmt
name|EXT
name|NG_NUM
name|starthere
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to the first newsgroup with unread news on startup */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|spool
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* public news spool directory */
end_comment

begin_function_decl
name|void
name|rn_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_ngname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getngdir
parameter_list|()
function_decl|;
end_function_decl

end_unit

