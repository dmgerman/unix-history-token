begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)CATCHERR.c	1.3 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_macro
name|CATCHERR
argument_list|(
argument|err
argument_list|,
argument|todo
argument_list|)
end_macro

begin_decl_stmt
name|long
name|err
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error to be caught */
end_comment

begin_decl_stmt
name|struct
name|formalrtn
name|todo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedure to call to catch error */
end_comment

begin_block
block|{
if|if
condition|(
name|todo
operator|.
name|fbn
operator|==
literal|1
condition|)
name|_entry
index|[
name|err
index|]
operator|.
name|fentryaddr
operator|=
name|todo
operator|.
name|fentryaddr
expr_stmt|;
else|else
name|fputs
argument_list|(
literal|"procedure not at level 1"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

