begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pld.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_define
define|#
directive|define
name|PMODE
value|0644
end_define

begin_comment
comment|/* file access mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|FORCE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* brute force approach */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tpld
init|=
literal|"/tmp/...XXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary project link directory */
end_comment

begin_comment
comment|/*  * restorpld() moves a project link directory from /tmp to pathname.  */
end_comment

begin_function
name|void
name|restorpld
parameter_list|(
name|pathname
parameter_list|)
name|char
modifier|*
name|pathname
decl_stmt|;
comment|/* project link directory pathname */
block|{
name|char
modifier|*
name|pathcat
parameter_list|()
function_decl|;
comment|/* pathname concatenation */
name|char
name|pldpathname
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* project link directory pathname */
name|int
name|fastcopy
parameter_list|()
function_decl|;
comment|/* fast file copy */
name|pathcat
argument_list|(
name|pldpathname
argument_list|,
name|pathname
argument_list|,
name|PLDNAME
argument_list|)
expr_stmt|;
name|fastcopy
argument_list|(
name|tpld
argument_list|,
name|pldpathname
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|tpld
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * savepld() copies a project link directory from pathname to /tmp.  * Returns 0 if successful, otherwise -1.  */
end_comment

begin_macro
name|savepld
argument_list|(
argument|pathname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project link directory pathname */
end_comment

begin_block
block|{
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
comment|/* make temporary file name */
name|char
modifier|*
name|pathcat
parameter_list|()
function_decl|;
comment|/* pathname concatenation */
name|char
name|pldpathname
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* project link directory pathname */
name|pathcat
argument_list|(
name|pldpathname
argument_list|,
name|pathname
argument_list|,
name|PLDNAME
argument_list|)
expr_stmt|;
return|return
operator|(
name|fastcopy
argument_list|(
name|pldpathname
argument_list|,
name|mktemp
argument_list|(
name|tpld
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * unsavepld() removes the saved project link directory from /tmp.  */
end_comment

begin_function
name|void
name|unsavepld
parameter_list|()
block|{
name|unlink
argument_list|(
name|tpld
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * fastcopy() copies f1 to f2. Returns 0 if successful, otherwise -1.  */
end_comment

begin_macro
name|fastcopy
argument_list|(
argument|f1
argument_list|,
argument|f2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|f1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|f2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to file */
end_comment

begin_block
block|{
specifier|register
name|int
name|ifd
decl_stmt|;
comment|/* input file descriptor */
specifier|register
name|int
name|ofd
decl_stmt|;
comment|/* output file descriptor */
specifier|register
name|int
name|n
decl_stmt|;
comment|/* byte count */
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* I/O buffer */
if|if
condition|(
operator|(
name|ifd
operator|=
name|OPEN
argument_list|(
name|f1
argument_list|,
name|O_RDONLY
argument_list|,
name|PMODE
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
if|if
condition|(
name|FORCE
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
block|{
name|pperror
argument_list|(
name|f1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|ofd
operator|=
name|CREATE
argument_list|(
name|f2
argument_list|,
name|O_WRONLY
argument_list|,
name|PMODE
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
if|if
condition|(
name|FORCE
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
block|{
name|pperror
argument_list|(
name|f2
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
while|while
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|ifd
argument_list|,
name|buf
argument_list|,
name|BUFSIZ
argument_list|)
operator|)
operator|>
literal|0
condition|)
if|if
condition|(
name|write
argument_list|(
name|ofd
argument_list|,
name|buf
argument_list|,
name|n
argument_list|)
operator|!=
name|n
condition|)
if|if
condition|(
name|FORCE
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
block|{
name|pperror
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|close
argument_list|(
name|ifd
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ofd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

