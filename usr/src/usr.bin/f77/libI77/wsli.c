begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)wsli.c	5.2 (Berkeley) %G%"
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
comment|/*  * internal (character array) i/o: write sequential list  */
end_comment

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_include
include|#
directive|include
file|"lio.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|l_write
argument_list|()
decl_stmt|,
name|z_putc
argument_list|()
decl_stmt|,
name|z_wnew
argument_list|()
decl_stmt|;
end_decl_stmt

begin_macro
name|s_wsli
argument_list|(
argument|a
argument_list|)
end_macro

begin_decl_stmt
name|icilist
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reading
operator|=
name|NO
expr_stmt|;
name|putn
operator|=
name|z_putc
expr_stmt|;
name|lioproc
operator|=
name|l_write
expr_stmt|;
name|line_len
operator|=
name|a
operator|->
name|icirlen
expr_stmt|;
return|return
operator|(
name|c_li
argument_list|(
name|a
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|e_wsli
argument_list|()
end_macro

begin_block
block|{
name|fmtbuf
operator|=
name|NULL
expr_stmt|;
name|reclen
operator|=
name|recpos
expr_stmt|;
return|return
operator|(
name|z_wnew
argument_list|()
operator|)
return|;
block|}
end_block

end_unit

