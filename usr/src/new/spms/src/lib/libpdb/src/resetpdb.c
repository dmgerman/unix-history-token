begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * resetpdb() resets the current database stream CURPDB to pdbp. Also  * resets buffer pointers.  */
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CURPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next non-key field */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next key field */
end_comment

begin_decl_stmt
specifier|extern
name|PDB
modifier|*
name|CURPDB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database stream */
end_comment

begin_function
name|void
name|resetpdb
parameter_list|(
name|pdbp
parameter_list|)
name|PDB
modifier|*
name|pdbp
decl_stmt|;
comment|/* database stream */
block|{
name|CURPDB
operator|=
name|pdbp
expr_stmt|;
name|CURPBUF
operator|=
name|FP
operator|=
name|KP
operator|=
name|pdbp
operator|->
name|pbuf
expr_stmt|;
block|}
end_function

end_unit

