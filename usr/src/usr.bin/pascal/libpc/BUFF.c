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
literal|"@(#)BUFF.c	1.5 (Berkeley) %G%"
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
name|BUFF
argument_list|(
argument|amount
argument_list|)
end_macro

begin_decl_stmt
name|long
name|amount
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
specifier|static
name|char
name|sobuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|curfile
operator|=
name|OUTPUT
expr_stmt|;
if|if
condition|(
name|amount
operator|==
literal|0
condition|)
name|setbuf
argument_list|(
name|ACTFILE
argument_list|(
name|curfile
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|amount
operator|==
literal|2
condition|)
name|setbuf
argument_list|(
name|ACTFILE
argument_list|(
name|curfile
argument_list|)
argument_list|,
name|sobuf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

