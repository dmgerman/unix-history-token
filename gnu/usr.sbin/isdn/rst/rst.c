begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  II - Version 0.1 $Revision: 1.1 $   $State: Exp $  *  * Copyright 1994 Dietmar Friede  *******************************************************************************  * Bug reports, patches, comments, suggestions should be sent to:  *  *	jkr@saarlink.de or jkrause@guug.de  *  *******************************************************************************  * $Log: rst.c,v $  *  ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|"../../../../sys/gnu/i386/isa/niccyreg.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|int
name|s
decl_stmt|,
name|f
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|=
name|open
argument_list|(
literal|"/dev/nic0"
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"open"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|f
argument_list|,
name|NICCY_RESET
argument_list|,
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"ioctl"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

