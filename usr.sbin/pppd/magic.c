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
file|<unistd.h>
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
file|"pppd.h"
end_include

begin_include
include|#
directive|include
file|"magic.h"
end_include

begin_decl_stmt
specifier|extern
name|long
name|mrand48
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
name|srand48
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * magic_init - Initialize the magic number generator.  *  * Attempts to compute a random number seed which will not repeat.  * The current method uses the current hostid, current process ID  * and current time, currently.  */
end_comment

begin_function
name|void
name|magic_init
parameter_list|()
block|{
name|long
name|seed
decl_stmt|;
name|struct
name|timeval
name|t
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|seed
operator|=
name|get_host_seed
argument_list|()
operator|^
name|t
operator|.
name|tv_sec
operator|^
name|t
operator|.
name|tv_usec
operator|^
name|getpid
argument_list|()
expr_stmt|;
name|srand48
argument_list|(
name|seed
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * magic - Returns the next magic number.  */
end_comment

begin_function
name|u_int32_t
name|magic
parameter_list|()
block|{
return|return
operator|(
name|u_int32_t
operator|)
name|mrand48
argument_list|()
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NO_DRAND48
end_ifdef

begin_comment
comment|/*  * Substitute procedures for those systems which don't have  * drand48 et al.  */
end_comment

begin_function
name|double
name|drand48
parameter_list|()
block|{
return|return
operator|(
name|double
operator|)
name|random
argument_list|()
operator|/
operator|(
name|double
operator|)
literal|0x7fffffffL
return|;
comment|/* 2**31-1 */
block|}
end_function

begin_function
name|long
name|mrand48
parameter_list|()
block|{
return|return
name|random
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|srand48
parameter_list|(
name|seedval
parameter_list|)
name|long
name|seedval
decl_stmt|;
block|{
name|srandom
argument_list|(
operator|(
name|int
operator|)
name|seedval
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

