begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1985  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)print.c	5.1 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
specifier|extern
name|FILE
modifier|*
name|debugout
decl_stmt|;
name|fprintf
argument_list|(
name|debugout
argument_list|,
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
name|fprintf
argument_list|(
name|debugout
argument_list|,
literal|"		id = %d\n"
argument_list|,
name|request
operator|->
name|id_num
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|debugout
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
specifier|extern
name|FILE
modifier|*
name|debugout
decl_stmt|;
name|fprintf
argument_list|(
name|debugout
argument_list|,
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
name|debugout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

