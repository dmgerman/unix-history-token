begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * paddkey() adds a newkey to each entry corresponding to key. The entry  * is not changed if newkey already exists.  */
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

begin_function
name|void
name|paddkey
parameter_list|(
name|key
parameter_list|,
name|newkey
parameter_list|,
name|pdbp
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key string */
name|char
modifier|*
name|newkey
decl_stmt|;
comment|/* new key string */
name|PDB
modifier|*
name|pdbp
decl_stmt|;
comment|/* database stream */
block|{
name|char
modifier|*
name|pbfndkey
parameter_list|()
function_decl|;
comment|/* find key */
name|int
name|pbaddkey
parameter_list|()
function_decl|;
comment|/* add key */
name|int
name|pgetent
parameter_list|()
function_decl|;
comment|/* load next entry into buffer */
name|int
name|pputent
parameter_list|()
function_decl|;
comment|/* write buffer to database */
name|void
name|rewindpdb
parameter_list|()
function_decl|;
comment|/* rewind database */
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
block|{
if|if
condition|(
name|pbfndkey
argument_list|(
name|key
argument_list|)
operator|!=
name|NULL
condition|)
name|pbaddkey
argument_list|(
name|newkey
argument_list|)
expr_stmt|;
name|pputent
argument_list|(
name|pdbp
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

