begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: final.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_comment
comment|/* cleanup status for fast exits */
end_comment

begin_function_decl
name|EXT
name|bool
name|panic
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we got hung up or something-- */
end_comment

begin_comment
comment|/*  so leave tty alone */
end_comment

begin_function_decl
name|EXT
name|bool
name|rc_changed
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* need we rewrite .newsrc? */
end_comment

begin_function_decl
name|EXT
name|bool
name|doing_ng
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do we need to reconstitute */
end_comment

begin_comment
comment|/* current rc line? */
end_comment

begin_decl_stmt
name|EXT
name|char
name|int_count
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many interrupts we've had */
end_comment

begin_function_decl
name|EXT
name|bool
name|clear_on_stop
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set when handling the stop signal */
end_comment

begin_comment
comment|/* would leave the screen a mess */
end_comment

begin_comment
comment|/* signal catching routines */
end_comment

begin_decl_stmt
name|Signal_t
name|int_catcher
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Signal_t
name|sig_catcher
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_decl_stmt
name|Signal_t
name|stop_catcher
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|final_init
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
name|finalize
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

