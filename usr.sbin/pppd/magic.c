begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * magic.c - PPP Magic Number routines.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"magic.h"
end_include

begin_decl_stmt
specifier|static
name|u_long
name|next
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next value to return */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|gethostid
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|random
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|srandom
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * magic_init - Initialize the magic number generator.  *  * Computes first magic number and seed for random number generator.  * Attempts to compute a random number seed which will not repeat.  * The current method uses the current hostid and current time.  */
end_comment

begin_function
name|void
name|magic_init
parameter_list|()
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|next
operator|=
name|gethostid
argument_list|()
expr_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"gettimeofday"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|next
operator|^=
operator|(
name|u_long
operator|)
name|tv
operator|.
name|tv_sec
operator|^
operator|(
name|u_long
operator|)
name|tv
operator|.
name|tv_usec
expr_stmt|;
name|srandom
argument_list|(
operator|(
name|int
operator|)
name|next
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * magic - Returns the next magic number.  */
end_comment

begin_function
name|u_long
name|magic
parameter_list|()
block|{
name|u_long
name|m
decl_stmt|;
name|m
operator|=
name|next
expr_stmt|;
name|next
operator|=
operator|(
name|u_long
operator|)
name|random
argument_list|()
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

end_unit

