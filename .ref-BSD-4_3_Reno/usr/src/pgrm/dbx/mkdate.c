begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)mkdate.c	5.5 (Berkeley) 6/1/90"
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
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IRIS
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|()
block|{
name|struct
name|tm
modifier|*
name|t
decl_stmt|;
name|long
name|clock
decl_stmt|;
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
name|int
name|namelen
decl_stmt|;
name|printf
argument_list|(
literal|"char *date = \""
argument_list|)
expr_stmt|;
name|clock
operator|=
name|time
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|t
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d/%d/%d "
argument_list|,
name|t
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|t
operator|->
name|tm_mday
argument_list|,
name|t
operator|->
name|tm_year
operator|%
literal|100
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d:%02d"
argument_list|,
name|t
operator|->
name|tm_hour
argument_list|,
name|t
operator|->
name|tm_min
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|IRIS
name|gethostname
argument_list|(
name|name
argument_list|,
operator|&
name|namelen
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" (%s)"
argument_list|,
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\";\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

