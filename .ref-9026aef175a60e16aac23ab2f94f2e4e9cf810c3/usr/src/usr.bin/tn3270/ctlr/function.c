begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)function.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * This file, which never produces a function.o, is used solely to  * be run through the preprocessor.  *  * On a 4.3 system (or even msdos), "cc -E function.h" would produce  * the correct output.  Unfortunately, 4.2 compilers aren't quite that  * useful.  */
end_comment

begin_include
include|#
directive|include
file|"function.h"
end_include

end_unit

