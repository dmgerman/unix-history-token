begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * manpath.h  *  * Copyright (c) 1990, 1991, John W. Eaton.  *  * You may distribute under the terms of the GNU General Public  * License as specified in the file COPYING that comes with the man  * distribution.    *  * John W. Eaton  * jwe@che.utexas.edu  * Department of Chemical Engineering  * The University of Texas at Austin  * Austin, Texas  78712  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|mandir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|bin
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|mandatory
decl_stmt|;
block|}
name|DIRLIST
typedef|;
end_typedef

begin_decl_stmt
name|DIRLIST
name|list
index|[
name|MAXDIRS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tmplist
index|[
name|MAXDIRS
index|]
decl_stmt|;
end_decl_stmt

end_unit

