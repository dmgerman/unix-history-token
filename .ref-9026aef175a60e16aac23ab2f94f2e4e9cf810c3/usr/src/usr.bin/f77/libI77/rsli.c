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
literal|"@(#)rsli.c	5.2 (Berkeley) %G%"
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
comment|/*  * internal (character array) i/o: read sequential list  */
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
name|l_read
argument_list|()
decl_stmt|,
name|z_getc
argument_list|()
decl_stmt|,
name|z_ungetc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_macro
name|s_rsli
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
name|YES
expr_stmt|;
name|lioproc
operator|=
name|l_read
expr_stmt|;
name|getn
operator|=
name|z_getc
expr_stmt|;
name|ungetn
operator|=
name|z_ungetc
expr_stmt|;
name|l_first
operator|=
name|YES
expr_stmt|;
name|lcount
operator|=
literal|0
expr_stmt|;
name|lquit
operator|=
name|NO
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
name|e_rsli
argument_list|()
end_macro

begin_block
block|{
name|fmtbuf
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

end_unit

