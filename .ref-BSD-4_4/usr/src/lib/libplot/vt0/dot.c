begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)dot.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_extern
extern|extern vti;
end_extern

begin_macro
name|dot
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|,
argument|dx
argument_list|,
argument|n
argument_list|,
argument|pat
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pat
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
struct|struct
block|{
name|char
name|pad
decl_stmt|,
name|c
decl_stmt|;
name|int
name|xi
decl_stmt|,
name|yi
decl_stmt|,
name|dx
decl_stmt|;
block|}
name|p
struct|;
name|p
operator|.
name|c
operator|=
literal|7
expr_stmt|;
name|p
operator|.
name|xi
operator|=
name|xsc
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|p
operator|.
name|yi
operator|=
name|ysc
argument_list|(
name|yi
argument_list|)
expr_stmt|;
name|p
operator|.
name|dx
operator|=
name|xsc
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|p
operator|.
name|c
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
name|pat
argument_list|,
name|n
condition|?
name|n
operator|&
literal|0377
else|:
literal|256
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

