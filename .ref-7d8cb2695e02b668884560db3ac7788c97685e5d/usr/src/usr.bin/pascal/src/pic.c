begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)pic.c	5.2 (Berkeley) %G%"
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
file|"OPnames.h"
end_include

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|int
name|j
decl_stmt|,
name|k
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
literal|32
condition|;
name|j
operator|++
control|)
block|{
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
literal|256
condition|;
name|k
operator|+=
literal|32
control|)
if|if
condition|(
name|otext
index|[
name|j
operator|+
name|k
index|]
condition|)
name|printf
argument_list|(
literal|"%03o%cO_%s\t"
argument_list|,
name|j
operator|+
name|k
argument_list|,
operator|*
name|otext
index|[
name|j
operator|+
name|k
index|]
argument_list|,
name|otext
index|[
name|j
operator|+
name|k
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%03o\t\t"
argument_list|,
name|j
operator|+
name|k
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|j
operator|+
literal|1
operator|)
operator|%
literal|8
operator|==
literal|0
condition|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Starred opcodes are used internally in Pi and are never generated.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

