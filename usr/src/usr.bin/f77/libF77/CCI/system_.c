begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)system_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* f77 interface to system routine */
end_comment

begin_expr_stmt
name|system_
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buff
index|[
literal|1001
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|blast
decl_stmt|;
name|blast
operator|=
name|buff
operator|+
operator|(
name|n
operator|<
literal|1000
condition|?
name|n
else|:
literal|1000L
operator|)
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|buff
init|;
name|bp
operator|<
name|blast
operator|&&
operator|*
name|s
operator|!=
literal|'\0'
condition|;
control|)
operator|*
name|bp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
name|system
argument_list|(
name|buff
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

