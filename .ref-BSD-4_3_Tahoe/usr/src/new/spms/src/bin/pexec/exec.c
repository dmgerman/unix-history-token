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
file|"macro.h"
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
file|"pdlist.h"
end_include

begin_include
include|#
directive|include
file|"pld.h"
end_include

begin_include
include|#
directive|include
file|"slslist.h"
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

begin_comment
comment|/*  * execlist() executes a project directory list. Returns non-zero error  * status if error.  */
end_comment

begin_macro
name|execlist
argument_list|(
argument|pdlist
argument_list|)
end_macro

begin_decl_stmt
name|PDLIST
modifier|*
name|pdlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project directory list */
end_comment

begin_block
block|{
specifier|extern
name|int
name|ERRSTATUS
decl_stmt|;
comment|/* pexec error status */
specifier|extern
name|int
name|EXECUTE
decl_stmt|;
comment|/* execute command? */
specifier|extern
name|int
name|PRINT_HEADING
decl_stmt|;
comment|/* print headings for project dirs */
name|int
name|ch_dir
parameter_list|()
function_decl|;
comment|/* change current working directory */
name|int
name|execcmd
parameter_list|()
function_decl|;
comment|/* execute command in directory */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* return status */
name|PDBLK
modifier|*
name|pdblk
decl_stmt|;
comment|/* project directory list block */
name|void
name|print_title
parameter_list|()
function_decl|;
comment|/* print project directory title */
for|for
control|(
name|pdblk
operator|=
name|pdlist
operator|->
name|head
init|;
name|pdblk
operator|!=
name|NULL
condition|;
name|pdblk
operator|=
name|pdblk
operator|->
name|next
control|)
block|{
if|if
condition|(
name|PRINT_HEADING
operator|==
name|YES
condition|)
name|print_title
argument_list|(
name|pdblk
operator|->
name|ppath
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch_dir
argument_list|(
name|pdblk
operator|->
name|rpath
argument_list|)
operator|==
name|NO
condition|)
name|status
operator|=
name|ERRSTATUS
expr_stmt|;
elseif|else
if|if
condition|(
name|EXECUTE
operator|==
name|YES
condition|)
name|status
operator||=
name|execcmd
argument_list|(
name|pdblk
operator|->
name|project
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * execproject() builds a project directory list and executes commands  * within directories on that list.  */
end_comment

begin_macro
name|execproject
argument_list|(
argument|ppathname
argument_list|,
argument|pathname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ppathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project root dir project pathname */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular project root dir pathname */
end_comment

begin_block
block|{
specifier|extern
name|int
name|ERRSTATUS
decl_stmt|;
comment|/* pexec error status */
name|char
name|ppathbuf
index|[
name|PPATHSIZE
index|]
decl_stmt|;
comment|/* project pathname buffer */
name|char
modifier|*
name|pdprepend
parameter_list|()
function_decl|;
comment|/* prepend project directory */
name|char
modifier|*
name|ppathcat
parameter_list|()
function_decl|;
comment|/* project pathname concatenation */
name|char
modifier|*
name|slsprepend
parameter_list|()
function_decl|;
comment|/* prepend key+string */
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
name|execlist
parameter_list|()
function_decl|;
comment|/* execute project directory list */
name|int
name|slssort
parameter_list|()
function_decl|;
comment|/* sort list */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* return status */
name|int
name|strcmp
parameter_list|()
function_decl|;
comment|/* string comparison */
name|PATH
modifier|*
name|pd
decl_stmt|;
comment|/* pathname struct pointer */
name|PATH
modifier|*
name|readpld
parameter_list|()
function_decl|;
comment|/* read project link directory entry */
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
name|PDLIST
modifier|*
name|pdinit
parameter_list|()
function_decl|;
comment|/* initialize project directory list */
name|PDLIST
modifier|*
name|pdlist
decl_stmt|;
comment|/* project directory list */
name|SLSBLK
modifier|*
name|pblk
decl_stmt|;
comment|/* project list block */
name|SLSLIST
modifier|*
name|plist
decl_stmt|;
comment|/* project list */
name|SLSLIST
modifier|*
name|slsinit
parameter_list|()
function_decl|;
comment|/* initialize list */
name|void
name|pdrm
parameter_list|()
function_decl|;
comment|/* remove project directory list */
name|void
name|pdsort
parameter_list|()
function_decl|;
comment|/* sort project directory list */
name|void
name|slsrm
parameter_list|()
function_decl|;
comment|/* remove list item */
name|pdlist
operator|=
name|pdinit
argument_list|()
expr_stmt|;
name|plist
operator|=
name|slsinit
argument_list|()
expr_stmt|;
comment|/* read PLDNAME project link directory */
if|if
condition|(
operator|(
name|pldp
operator|=
name|openpdb
argument_list|(
name|PLDNAME
argument_list|,
name|pathname
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|errpdb
argument_list|(
operator|(
name|PDB
operator|*
operator|)
name|NULL
argument_list|)
operator|)
return|;
while|while
condition|(
operator|(
name|pd
operator|=
name|readpld
argument_list|(
name|pldp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|EQUAL
argument_list|(
name|pd
operator|->
name|p_alias
argument_list|,
name|PARENTPROJECT
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|EQUAL
argument_list|(
name|pd
operator|->
name|p_alias
argument_list|,
name|CURPROJECT
argument_list|)
condition|)
block|{
name|pdprepend
argument_list|(
name|ppathname
argument_list|,
name|pd
operator|->
name|p_path
argument_list|,
name|pathname
argument_list|,
name|pdlist
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pd
operator|->
name|p_mode
operator|==
name|P_IFPROOT
condition|)
block|{
if|if
condition|(
name|slsprepend
argument_list|(
name|pd
operator|->
name|p_alias
argument_list|,
name|pd
operator|->
name|p_path
argument_list|,
name|plist
argument_list|)
operator|==
name|NULL
condition|)
name|pxexit
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|ppathcat
argument_list|(
name|ppathbuf
argument_list|,
name|ppathname
argument_list|,
name|pd
operator|->
name|p_alias
argument_list|)
expr_stmt|;
name|pdprepend
argument_list|(
name|ppathbuf
argument_list|,
name|pd
operator|->
name|p_path
argument_list|,
name|pathname
argument_list|,
name|pdlist
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|closepdb
argument_list|(
name|pldp
argument_list|)
operator|!=
literal|0
condition|)
name|status
operator|=
name|ERRSTATUS
expr_stmt|;
comment|/* sort and execute project directories */
name|pdsort
argument_list|(
name|strcmp
argument_list|,
name|pdlist
argument_list|)
expr_stmt|;
name|status
operator||=
name|execlist
argument_list|(
name|pdlist
argument_list|)
expr_stmt|;
name|pdrm
argument_list|(
name|pdlist
argument_list|)
expr_stmt|;
comment|/* execute subprojects */
if|if
condition|(
name|slssort
argument_list|(
name|strcmp
argument_list|,
name|plist
argument_list|)
operator|==
name|NO
condition|)
name|pxexit
argument_list|()
expr_stmt|;
for|for
control|(
name|pblk
operator|=
name|plist
operator|->
name|head
init|;
name|pblk
operator|!=
name|NULL
condition|;
name|pblk
operator|=
name|pblk
operator|->
name|next
control|)
block|{
name|ppathcat
argument_list|(
name|ppathbuf
argument_list|,
name|ppathname
argument_list|,
name|pblk
operator|->
name|key
argument_list|)
expr_stmt|;
name|status
operator||=
name|execproject
argument_list|(
name|ppathbuf
argument_list|,
name|pblk
operator|->
name|string
argument_list|)
expr_stmt|;
block|}
name|slsrm
argument_list|(
name|CNULL
argument_list|,
name|plist
argument_list|)
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

end_unit

