begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)hertz.c	5.4 (Berkeley) 6/1/90"
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
file|<sys/time.h>
end_include

begin_comment
comment|/*      *	discover the tick frequency of the machine      *	if something goes wrong, we return 0, an impossible hertz.      */
end_comment

begin_define
define|#
directive|define
name|HZ_WRONG
value|0
end_define

begin_macro
name|hertz
argument_list|()
end_macro

begin_block
block|{
name|struct
name|itimerval
name|tim
decl_stmt|;
name|tim
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|tim
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|1
expr_stmt|;
name|tim
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|tim
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|tim
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
literal|0
argument_list|,
operator|&
name|tim
argument_list|)
expr_stmt|;
if|if
condition|(
name|tim
operator|.
name|it_interval
operator|.
name|tv_usec
operator|<
literal|2
condition|)
return|return
operator|(
name|HZ_WRONG
operator|)
return|;
return|return
operator|(
literal|1000000
operator|/
name|tim
operator|.
name|it_interval
operator|.
name|tv_usec
operator|)
return|;
block|}
end_block

end_unit

