begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * readpath() loads a PATH struct, given a regular or project pathname.  * Returns -1 if bad pathname, otherwise 0.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|"pdbuf.h"
end_include

begin_include
include|#
directive|include
file|"pld.h"
end_include

begin_include
include|#
directive|include
file|"spms.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PATHERR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current pathname error condition */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PDBERR
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project database error message */
end_comment

begin_macro
name|readpath
argument_list|(
argument|pathname
argument_list|,
argument|pb
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular or project pathname */
end_comment

begin_decl_stmt
name|PATH
modifier|*
name|pb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project directory struct buffer */
end_comment

begin_block
block|{
name|char
modifier|*
name|pbgetstring
parameter_list|()
function_decl|;
comment|/* get specified string field */
name|int
name|closepdb
parameter_list|()
function_decl|;
comment|/* close database */
name|int
name|errpdb
parameter_list|()
function_decl|;
comment|/* print database error message */
name|int
name|pfndent
parameter_list|()
function_decl|;
comment|/* find and load database entry */
name|int
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
name|int
name|xppath
parameter_list|()
function_decl|;
comment|/* expand project pathname */
name|PDB
modifier|*
name|openpdb
parameter_list|()
function_decl|;
comment|/* open database */
name|PDB
modifier|*
name|pldp
decl_stmt|;
comment|/* project link directory stream */
if|if
condition|(
name|xppath
argument_list|(
name|pathname
argument_list|,
name|pb
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
switch|switch
condition|(
name|pb
operator|->
name|p_mode
operator|&
name|P_IFMT
condition|)
block|{
case|case
name|P_IFNEW
case|:
case|case
name|P_IFREG
case|:
return|return
operator|(
literal|0
operator|)
return|;
break|break;
case|case
name|P_IFPDIR
case|:
if|if
condition|(
operator|(
name|pldp
operator|=
name|openpdb
argument_list|(
name|PLDNAME
argument_list|,
name|pb
operator|->
name|p_project
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|PATHERR
operator|=
name|PDBERR
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|pfndent
argument_list|(
name|pb
operator|->
name|p_alias
argument_list|,
name|pldp
argument_list|)
expr_stmt|;
break|break;
case|case
name|P_IFHOME
case|:
case|case
name|P_IFPROOT
case|:
if|if
condition|(
operator|(
name|pldp
operator|=
name|openpdb
argument_list|(
name|PLDNAME
argument_list|,
name|pb
operator|->
name|p_project
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|PATHERR
operator|=
name|PDBERR
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|pfndent
argument_list|(
name|CURPROJECT
argument_list|,
name|pldp
argument_list|)
expr_stmt|;
break|break;
block|}
name|pbgetstring
argument_list|(
name|PDIRTYPE
argument_list|,
name|pb
operator|->
name|p_type
argument_list|)
expr_stmt|;
name|pb
operator|->
name|p_desc
operator|=
name|pb
operator|->
name|p_type
operator|+
name|strlen
argument_list|(
name|pb
operator|->
name|p_type
argument_list|)
operator|+
literal|1
expr_stmt|;
name|pbgetstring
argument_list|(
name|PDIRDESC
argument_list|,
name|pb
operator|->
name|p_desc
argument_list|)
expr_stmt|;
name|closepdb
argument_list|(
name|pldp
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

