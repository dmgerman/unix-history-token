begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  */
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
literal|"@(#) Copyright (c) 1990 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)cat.c	7.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|int
name|c
decl_stmt|,
name|i
decl_stmt|;
name|char
name|buf
index|[
literal|50
index|]
decl_stmt|;
do|do
block|{
name|printf
argument_list|(
literal|"File: "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|i
operator|=
name|open
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|i
operator|<=
literal|0
condition|)
do|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|i
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|putchar
argument_list|(
name|c
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

