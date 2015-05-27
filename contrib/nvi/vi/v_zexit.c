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
literal|"$Id: v_zexit.c,v 10.7 2001/06/25 15:19:37 skimo Exp $"
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
file|<sys/time.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/*  * v_zexit -- ZZ  *	Save the file and exit.  *  * PUBLIC: int v_zexit(SCR *, VICMD *);  */
end_comment

begin_function
name|int
name|v_zexit
parameter_list|(
name|SCR
modifier|*
name|sp
parameter_list|,
name|VICMD
modifier|*
name|vp
parameter_list|)
block|{
comment|/* Write back any modifications. */
if|if
condition|(
name|F_ISSET
argument_list|(
name|sp
operator|->
name|ep
argument_list|,
name|F_MODIFIED
argument_list|)
operator|&&
name|file_write
argument_list|(
name|sp
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FS_ALL
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Check to make sure it's not a temporary file. */
if|if
condition|(
name|file_m3
argument_list|(
name|sp
argument_list|,
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Check for more files to edit. */
if|if
condition|(
name|ex_ncheck
argument_list|(
name|sp
argument_list|,
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|F_SET
argument_list|(
name|sp
argument_list|,
name|SC_EXIT
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

