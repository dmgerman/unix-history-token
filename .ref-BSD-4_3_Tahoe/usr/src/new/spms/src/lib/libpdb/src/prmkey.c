begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * prmkey() removes each instance of key in a database.  */
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
file|"pdb.h"
end_include

begin_function
name|void
name|prmkey
parameter_list|(
name|key
parameter_list|,
name|pdbp
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key string */
name|PDB
modifier|*
name|pdbp
decl_stmt|;
comment|/* database stream */
block|{
name|int
name|pgetent
parameter_list|()
function_decl|;
comment|/* loasd next entry into buffer */
name|int
name|pputent
parameter_list|()
function_decl|;
comment|/* write buffer to database */
name|void
name|pbrmkey
parameter_list|()
function_decl|;
comment|/* remove key */
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
name|pbrmkey
argument_list|(
name|key
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

