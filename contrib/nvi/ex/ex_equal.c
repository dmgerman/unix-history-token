begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ex_equal.c	10.10 (Berkeley) 3/6/96"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_equal -- :address =  *  * PUBLIC: int ex_equal __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_equal
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXCMD
modifier|*
name|cmdp
decl_stmt|;
block|{
name|recno_t
name|lno
decl_stmt|;
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
comment|/* 	 * Print out the line number matching the specified address, 	 * or the number of the last line in the file if no address 	 * specified. 	 * 	 * !!! 	 * Historically, ":0=" displayed 0, and ":=" or ":1=" in an 	 * empty file displayed 1.  Until somebody complains loudly, 	 * we're going to do it right.  The tables in excmd.c permit 	 * lno to get away with any address from 0 to the end of the 	 * file, which, in an empty file, is 0. 	 */
if|if
condition|(
name|F_ISSET
argument_list|(
name|cmdp
argument_list|,
name|E_ADDR_DEF
argument_list|)
condition|)
block|{
if|if
condition|(
name|db_last
argument_list|(
name|sp
argument_list|,
operator|&
name|lno
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
name|lno
operator|=
name|cmdp
operator|->
name|addr1
operator|.
name|lno
expr_stmt|;
operator|(
name|void
operator|)
name|ex_printf
argument_list|(
name|sp
argument_list|,
literal|"%ld\n"
argument_list|,
name|lno
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

