begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pfndent() loads a database entry corresponding to key into the current  * working buffer CURPBUF. Database must be open for reading only.  * Returns integer YES if key found, otherwise NO.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pdb.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_macro
name|pfndent
argument_list|(
argument|key
argument_list|,
argument|pdbp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key string */
end_comment

begin_decl_stmt
name|PDB
modifier|*
name|pdbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* database stream */
end_comment

begin_block
block|{
name|char
modifier|*
name|pbfndkey
parameter_list|()
function_decl|;
comment|/* find key */
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
comment|/* print output to string */
name|int
name|pgetent
parameter_list|()
function_decl|;
comment|/* load next entry into buffer */
name|void
name|rewindpdb
parameter_list|()
function_decl|;
comment|/* rewind database */
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
name|_PERR
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|NO
operator|)
return|;
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
operator|(
name|_PWRITE
operator||
name|_PAPPEND
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|pdbp
operator|->
name|perr
argument_list|,
literal|"%s must be read access only"
argument_list|,
name|pdbp
operator|->
name|path
argument_list|)
expr_stmt|;
name|pdbp
operator|->
name|flag
operator||=
name|_PERR
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
name|rewindpdb
argument_list|(
name|pdbp
argument_list|)
expr_stmt|;
while|while
condition|(
name|pgetent
argument_list|(
name|pdbp
argument_list|)
operator|!=
name|EOF
condition|)
if|if
condition|(
name|pbfndkey
argument_list|(
name|key
argument_list|)
operator|!=
name|NULL
condition|)
return|return
operator|(
name|YES
operator|)
return|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
end_block

end_unit

