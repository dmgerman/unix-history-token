begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  * %sccs.include.redist.c%  */
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
literal|"@(#)cmp.c	5.2 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"ls.h"
end_include

begin_macro
name|namecmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|strcmp
argument_list|(
name|a
operator|->
name|name
argument_list|,
name|b
operator|->
name|name
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|revnamecmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|strcmp
argument_list|(
name|b
operator|->
name|name
argument_list|,
name|a
operator|->
name|name
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|modcmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|->
name|lstat
operator|.
name|st_mtime
operator|<
name|b
operator|->
name|lstat
operator|.
name|st_mtime
operator|)
return|;
block|}
end_block

begin_macro
name|revmodcmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|b
operator|->
name|lstat
operator|.
name|st_mtime
operator|<
name|a
operator|->
name|lstat
operator|.
name|st_mtime
operator|)
return|;
block|}
end_block

begin_macro
name|acccmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|->
name|lstat
operator|.
name|st_atime
operator|<
name|b
operator|->
name|lstat
operator|.
name|st_atime
operator|)
return|;
block|}
end_block

begin_macro
name|revacccmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|b
operator|->
name|lstat
operator|.
name|st_atime
operator|<
name|a
operator|->
name|lstat
operator|.
name|st_atime
operator|)
return|;
block|}
end_block

begin_macro
name|statcmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|->
name|lstat
operator|.
name|st_ctime
operator|<
name|b
operator|->
name|lstat
operator|.
name|st_ctime
operator|)
return|;
block|}
end_block

begin_macro
name|revstatcmp
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|LS
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|b
operator|->
name|lstat
operator|.
name|st_ctime
operator|<
name|a
operator|->
name|lstat
operator|.
name|st_ctime
operator|)
return|;
block|}
end_block

end_unit

