begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)space.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|botx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|boty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|obotx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|oboty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scaley
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scaleflag
decl_stmt|;
end_decl_stmt

begin_macro
name|space
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_block
block|{
name|botx
operator|=
literal|0.
expr_stmt|;
name|boty
operator|=
literal|0.
expr_stmt|;
name|obotx
operator|=
name|x0
expr_stmt|;
name|oboty
operator|=
name|y0
expr_stmt|;
if|if
condition|(
name|scaleflag
condition|)
return|return;
name|scalex
operator|=
literal|780.
operator|/
operator|(
name|x1
operator|-
name|x0
operator|)
expr_stmt|;
name|scaley
operator|=
literal|780.
operator|/
operator|(
name|y1
operator|-
name|y0
operator|)
expr_stmt|;
block|}
end_block

end_unit

