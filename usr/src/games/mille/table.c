begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1982, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
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
literal|"@(#)table.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/*  * @(#)table.c	1.1 (Berkeley) 4/1/82  */
end_comment

begin_include
include|#
directive|include
file|"mille.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|reg
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|count
decl_stmt|;
name|printf
argument_list|(
literal|"   %16s -> %5s %5s %4s %s\n"
argument_list|,
literal|"Card"
argument_list|,
literal|"cards"
argument_list|,
literal|"count"
argument_list|,
literal|"need"
argument_list|,
literal|"opposite"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_CARDS
operator|-
literal|1
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|j
operator|=
literal|0
operator|,
name|count
operator|=
literal|0
init|;
name|j
operator|<
name|DECK_SZ
condition|;
name|j
operator|++
control|)
if|if
condition|(
name|Deck
index|[
name|j
index|]
operator|==
name|i
condition|)
name|count
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"%2d %16s -> %5d %5d %4d %s\n"
argument_list|,
name|i
argument_list|,
name|C_name
index|[
name|i
index|]
argument_list|,
name|Numcards
index|[
name|i
index|]
argument_list|,
name|count
argument_list|,
name|Numneed
index|[
name|i
index|]
argument_list|,
name|C_name
index|[
name|opposite
argument_list|(
name|i
argument_list|)
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

