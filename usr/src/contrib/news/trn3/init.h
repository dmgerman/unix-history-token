begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: init.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|lockname
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|long
name|our_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|initialize
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
name|lock_check
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
name|newsnews_check
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

