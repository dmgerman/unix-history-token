begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: last.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
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

begin_decl_stmt
name|EXT
name|long
name|lastnewtime
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time last new group was found */
end_comment

begin_decl_stmt
name|EXT
name|long
name|lastnewsize
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of active.times file when rn last started up */
end_comment

begin_decl_stmt
name|void
name|last_init
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
name|void
name|writelast
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

