begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)romcons.c	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* romcons.c   OCT-21-1991 */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/luna68k/cons.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/romvec.h>
end_include

begin_macro
name|romcnprobe
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|consdev
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|cp
operator|->
name|cn_tp
operator|=
literal|0
expr_stmt|;
name|cp
operator|->
name|cn_dev
operator|=
literal|0
expr_stmt|;
name|cp
operator|->
name|cn_pri
operator|=
name|CN_NORMAL
expr_stmt|;
block|}
end_block

begin_macro
name|romcninit
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|consdev
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|romcngetc
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|c
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
if|if
condition|(
operator|(
name|c
operator|=
name|ROM_getchar
argument_list|()
operator|)
operator|!=
operator|-
literal|1
condition|)
break|break;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

begin_macro
name|romcnputc
argument_list|(
argument|dev
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ROM_putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

