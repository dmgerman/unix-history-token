begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: trn.h,v 4.4 1991/09/09 20:27:37 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
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
name|EXT
name|char
modifier|*
name|threaddir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* directory for thread data */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|overviewdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* directory for overview data */
end_comment

begin_decl_stmt
name|void
name|rn_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
decl|main
name|_
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_ngname
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getngdir
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

