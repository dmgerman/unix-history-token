begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)out.c	5.1 (Berkeley) 5/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **  Announce Device Out */
end_comment

begin_macro
name|out
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|int
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|device
modifier|*
name|d
decl_stmt|;
name|d
operator|=
operator|&
name|Device
index|[
name|dev
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"%s reports %s "
argument_list|,
name|d
operator|->
name|person
argument_list|,
name|d
operator|->
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|name
index|[
name|length
argument_list|(
name|d
operator|->
name|name
argument_list|)
operator|-
literal|1
index|]
operator|==
literal|'s'
condition|)
name|printf
argument_list|(
literal|"are"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"is"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" damaged\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

