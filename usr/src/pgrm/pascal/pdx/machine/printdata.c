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
literal|"@(#)printdata.c	5.2 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * print contents of data addresses in octal  *  * There are two entries:  one is given a range of addresses,  * the other is given a count and a starting address.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"process/process.rep"
end_include

begin_include
include|#
directive|include
file|"process/pxinfo.h"
end_include

begin_define
define|#
directive|define
name|WORDSPERLINE
value|4
end_define

begin_comment
comment|/*  * print words from lowaddr to highaddr  */
end_comment

begin_macro
name|printdata
argument_list|(
argument|lowaddr
argument_list|,
argument|highaddr
argument_list|)
end_macro

begin_decl_stmt
name|ADDRESS
name|lowaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|highaddr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|count
decl_stmt|;
specifier|register
name|ADDRESS
name|addr
decl_stmt|;
name|int
name|val
decl_stmt|;
if|if
condition|(
name|lowaddr
operator|>
name|highaddr
condition|)
block|{
name|error
argument_list|(
literal|"first address larger than second"
argument_list|)
expr_stmt|;
block|}
name|count
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|addr
operator|=
name|lowaddr
init|;
name|addr
operator|<=
name|highaddr
condition|;
name|addr
operator|+=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
control|)
block|{
if|if
condition|(
name|count
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%8x: "
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
name|dread
argument_list|(
operator|&
name|val
argument_list|,
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  %8x"
argument_list|,
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|count
operator|>=
name|WORDSPERLINE
condition|)
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|count
operator|!=
literal|0
condition|)
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

