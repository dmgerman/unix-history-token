begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)cons.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/luna68k/cons.h>
end_include

begin_define
define|#
directive|define
name|NBMC
value|1
end_define

begin_define
define|#
directive|define
name|NSIO
value|1
end_define

begin_define
define|#
directive|define
name|NROM
value|1
end_define

begin_comment
comment|/* XXX - all this could be autoconfig()ed */
end_comment

begin_include
include|#
directive|include
file|"romvec.h"
end_include

begin_if
if|#
directive|if
name|NBMC
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|bmccnprobe
argument_list|()
decl_stmt|,
name|bmccninit
argument_list|()
decl_stmt|,
name|bmccngetc
argument_list|()
decl_stmt|,
name|bmccnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NSIO
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|siocnprobe
argument_list|()
decl_stmt|,
name|siocninit
argument_list|()
decl_stmt|,
name|siocngetc
argument_list|()
decl_stmt|,
name|siocnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NROM
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|romcnprobe
argument_list|()
decl_stmt|,
name|romcninit
argument_list|()
decl_stmt|,
name|romcngetc
argument_list|()
decl_stmt|,
name|romcnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|consdev
name|constab
index|[]
init|=
block|{
if|#
directive|if
name|NBMC
operator|>
literal|0
block|{
name|bmccnprobe
block|,
name|bmccninit
block|,
name|bmccngetc
block|,
name|bmccnputc
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|NSIO
operator|>
literal|0
block|{
name|siocnprobe
block|,
name|siocninit
block|,
name|siocngetc
block|,
name|siocnputc
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|NROM
operator|>
literal|0
block|{
name|romcnprobe
block|,
name|romcninit
block|,
name|romcngetc
block|,
name|romcnputc
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end XXX */
end_comment

begin_decl_stmt
name|struct
name|tty
modifier|*
name|constty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual console output device */
end_comment

begin_decl_stmt
name|struct
name|consdev
modifier|*
name|cn_tab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical console device info */
end_comment

begin_decl_stmt
name|struct
name|tty
modifier|*
name|cn_tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: console tty struct for tprintf */
end_comment

begin_macro
name|cninit
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|consdev
modifier|*
name|cp
decl_stmt|;
comment|/* 	 * Collect information about all possible consoles 	 * and find the one with highest priority 	 */
for|for
control|(
name|cp
operator|=
name|constab
init|;
name|cp
operator|->
name|cn_probe
condition|;
name|cp
operator|++
control|)
block|{
call|(
modifier|*
name|cp
operator|->
name|cn_probe
call|)
argument_list|(
name|cp
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|->
name|cn_pri
operator|>
name|CN_DEAD
operator|&&
operator|(
name|cn_tab
operator|==
name|NULL
operator|||
name|cp
operator|->
name|cn_pri
operator|>
name|cn_tab
operator|->
name|cn_pri
operator|)
condition|)
name|cn_tab
operator|=
name|cp
expr_stmt|;
block|}
comment|/* 	 * No console, we can handle it 	 */
if|if
condition|(
operator|(
name|cp
operator|=
name|cn_tab
operator|)
operator|==
name|NULL
condition|)
return|return;
comment|/* 	 * Turn on console 	 */
name|cn_tty
operator|=
name|cp
operator|->
name|cn_tp
expr_stmt|;
call|(
modifier|*
name|cp
operator|->
name|cn_init
call|)
argument_list|(
name|cp
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cngetc
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cn_tab
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
call|(
modifier|*
name|cn_tab
operator|->
name|cn_getc
call|)
argument_list|(
name|cn_tab
operator|->
name|cn_dev
argument_list|)
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|cnputc
argument_list|(
name|c
argument_list|)
specifier|register
name|int
name|c
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|cn_tab
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|c
condition|)
block|{
call|(
modifier|*
name|cn_tab
operator|->
name|cn_putc
call|)
argument_list|(
name|cn_tab
operator|->
name|cn_dev
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
call|(
modifier|*
name|cn_tab
operator|->
name|cn_putc
call|)
argument_list|(
name|cn_tab
operator|->
name|cn_dev
argument_list|,
literal|'\r'
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

