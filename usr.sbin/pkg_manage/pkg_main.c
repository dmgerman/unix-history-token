begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************  *  * Program:	pkg_main.c  * Author:	Marc van Kempen  * Desc:	main routine for pkg_manage  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  ***************************************************************/
end_comment

begin_include
include|#
directive|include
file|"pkg_manage.h"
end_include

begin_include
include|#
directive|include
file|"ui_objects.h"
end_include

begin_decl_stmt
specifier|extern
name|PKG_info
name|p_inf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|StartDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Main  */
end_comment

begin_function
name|void
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|init_dialog
argument_list|()
expr_stmt|;
name|p_inf
operator|.
name|Nitems
operator|=
literal|0
expr_stmt|;
comment|/* Initialize p_inf */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|StartDir
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
else|else
name|StartDir
operator|=
name|NULL
expr_stmt|;
name|get_pkginfo
argument_list|()
expr_stmt|;
name|run_menu
argument_list|()
expr_stmt|;
if|if
condition|(
name|p_inf
operator|.
name|Nitems
operator|>
literal|0
condition|)
block|{
name|FreeInfo
argument_list|()
expr_stmt|;
block|}
name|clear
argument_list|()
expr_stmt|;
name|dialog_update
argument_list|()
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* main() */
end_comment

end_unit

