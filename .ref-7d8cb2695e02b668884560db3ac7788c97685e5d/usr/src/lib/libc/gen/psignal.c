begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)psignal.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * Print the name of the signal indicated  * along with the supplied message.  */
end_comment

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|void
name|psignal
parameter_list|(
name|sig
parameter_list|,
name|s
parameter_list|)
name|unsigned
name|int
name|sig
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|register
specifier|const
name|char
modifier|*
name|c
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
if|if
condition|(
name|sig
operator|<
name|NSIG
condition|)
name|c
operator|=
name|sys_siglist
index|[
name|sig
index|]
expr_stmt|;
else|else
name|c
operator|=
literal|"Unknown signal"
expr_stmt|;
name|n
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
condition|)
block|{
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
literal|": "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|c
argument_list|,
name|strlen
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

