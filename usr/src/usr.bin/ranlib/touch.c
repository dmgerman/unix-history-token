begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)touch.c	5.3 (Berkeley) %G%"
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
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<ranlib.h>
end_include

begin_include
include|#
directive|include
file|<ar.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<archive.h>
end_include

begin_decl_stmt
specifier|extern
name|CHDR
name|chdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* converted header */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive name */
end_comment

begin_macro
name|touch
argument_list|()
end_macro

begin_block
block|{
name|int
name|afd
decl_stmt|;
name|afd
operator|=
name|open_archive
argument_list|(
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|get_arobj
argument_list|(
name|afd
argument_list|)
operator|||
name|strncmp
argument_list|(
name|RANLIBMAG
argument_list|,
name|chdr
operator|.
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|RANLIBMAG
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ranlib: %s: no symbol table.\n"
argument_list|,
name|archive
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|settime
argument_list|(
name|afd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|settime
argument_list|(
argument|afd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|afd
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|ar_hdr
modifier|*
name|hdr
decl_stmt|;
name|off_t
name|size
decl_stmt|;
name|char
name|buf
index|[
literal|50
index|]
decl_stmt|;
name|size
operator|=
name|SARMAG
operator|+
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|afd
argument_list|,
name|size
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
name|error
argument_list|(
name|archive
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%-12ld"
argument_list|,
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
name|NULL
argument_list|)
operator|+
name|RANLIBSKEW
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|afd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_date
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|ar_date
argument_list|)
condition|)
name|error
argument_list|(
name|archive
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

