begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: print.c 1.4 83/03/28 00:34:25 moore Exp $ */
end_comment

begin_comment
comment|/* debug print routines */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ctl.h"
end_include

begin_macro
name|print_request
argument_list|(
argument|request
argument_list|)
end_macro

begin_decl_stmt
name|CTL_MSG
modifier|*
name|request
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"type is %d, l_user %s, r_user %s, r_tty %s\n"
argument_list|,
name|request
operator|->
name|type
argument_list|,
name|request
operator|->
name|l_name
argument_list|,
name|request
operator|->
name|r_name
argument_list|,
name|request
operator|->
name|r_tty
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"        id = %d\n"
argument_list|,
name|request
operator|->
name|id_num
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|print_response
argument_list|(
argument|response
argument_list|)
end_macro

begin_decl_stmt
name|CTL_RESPONSE
modifier|*
name|response
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"type is %d, answer is %d, id = %d\n\n"
argument_list|,
name|response
operator|->
name|type
argument_list|,
name|response
operator|->
name|answer
argument_list|,
name|response
operator|->
name|id_num
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

