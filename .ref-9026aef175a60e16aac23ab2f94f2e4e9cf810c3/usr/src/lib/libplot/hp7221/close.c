begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)close.c	8.1 (Berkeley) %G%"
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"hp7221.h"
end_include

begin_function
name|void
name|closepl
parameter_list|()
block|{
comment|/* receive interupts */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"v@}"
argument_list|)
expr_stmt|;
comment|/* Put pen away. */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

