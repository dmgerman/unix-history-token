begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)label.c	5.1 (Berkeley) 9/21/85"
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
file|"imPcodes.h"
end_include

begin_include
include|#
directive|include
file|"imp.h"
end_include

begin_extern
extern|extern imPcsize;
end_extern

begin_macro
name|label
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|i
operator|,
name|c
expr_stmt|;
name|putch
argument_list|(
name|imP_SET_ABS_H
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|imPx
operator|-
name|obotx
operator|)
operator|*
name|scalex
operator|+
name|botx
argument_list|)
operator|-
name|imPcsize
operator|/
literal|2
argument_list|)
expr_stmt|;
name|putch
argument_list|(
name|imP_SET_ABS_V
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|imPy
operator|-
name|oboty
operator|)
operator|*
name|scaley
operator|+
name|boty
operator|-
operator|(
name|imPcsize
operator|/
literal|1.6
operator|)
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|c
operator|=
name|s
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{
name|imPx
operator|+=
name|imPcsize
operator|/
name|scalex
expr_stmt|;
name|putch
argument_list|(
operator|(
name|c
operator|==
literal|' '
operator|)
condition|?
name|imP_SP
else|:
name|c
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

