begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  *  *	@(#)sys.c	7.20 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dir.h>
end_include

begin_include
include|#
directive|include
file|<stand.att/saio.h>
end_include

begin_decl_stmt
name|struct
name|iob
name|iob
index|[
name|SOPEN_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|i386
end_ifndef

begin_macro
name|exit
argument_list|()
end_macro

begin_block
block|{
name|_stop
argument_list|(
literal|"Exit called"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_stop
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
specifier|static
name|int
name|stopped
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|!
name|stopped
condition|)
block|{
name|stopped
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SOPEN_MAX
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|iob
index|[
name|i
index|]
operator|.
name|i_flgs
operator|!=
literal|0
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|_rtt
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * For gcc  */
end_comment

begin_macro
name|__main
argument_list|()
end_macro

begin_block
block|{
return|return;
block|}
end_block

end_unit

