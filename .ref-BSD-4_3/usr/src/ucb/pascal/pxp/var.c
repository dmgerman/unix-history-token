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
literal|"@(#)var.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_decl_stmt
name|STATIC
name|int
name|varcnt
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Var declaration part  */
end_comment

begin_macro
name|varbeg
argument_list|(
argument|l
argument_list|,
argument|vline
argument_list|)
end_macro

begin_decl_stmt
name|int
name|l
decl_stmt|,
name|vline
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|line
operator|=
name|l
expr_stmt|;
if|if
condition|(
name|nodecl
condition|)
name|printoff
argument_list|()
expr_stmt|;
name|puthedr
argument_list|()
expr_stmt|;
name|putcm
argument_list|()
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppkw
argument_list|(
literal|"var"
argument_list|)
expr_stmt|;
name|ppgoin
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|varcnt
operator|=
literal|0
expr_stmt|;
name|setline
argument_list|(
name|vline
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|var
argument_list|(
argument|vline
argument_list|,
argument|vidl
argument_list|,
argument|vtype
argument_list|)
end_macro

begin_decl_stmt
name|int
name|vline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
modifier|*
name|vidl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|vtype
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|varcnt
condition|)
name|putcm
argument_list|()
expr_stmt|;
name|setline
argument_list|(
name|vline
argument_list|)
expr_stmt|;
name|ppitem
argument_list|()
expr_stmt|;
if|if
condition|(
name|vidl
operator|!=
name|NIL
condition|)
for|for
control|(
init|;
condition|;
control|)
block|{
name|ppid
argument_list|(
name|vidl
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|vidl
operator|=
name|vidl
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|vidl
operator|==
name|NIL
condition|)
break|break;
name|ppsep
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
else|else
name|ppid
argument_list|(
literal|"{identifier list}"
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
name|gtype
argument_list|(
name|vtype
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|";"
argument_list|)
expr_stmt|;
name|setinfo
argument_list|(
name|vline
argument_list|)
expr_stmt|;
name|putcml
argument_list|()
expr_stmt|;
name|varcnt
operator|++
expr_stmt|;
block|}
end_block

begin_macro
name|varend
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|varcnt
operator|==
operator|-
literal|1
condition|)
return|return;
if|if
condition|(
name|varcnt
operator|==
literal|0
condition|)
name|ppid
argument_list|(
literal|"{variable decls}"
argument_list|)
expr_stmt|;
name|ppgoout
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|varcnt
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_block

end_unit

