begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/ncvs/src/gnu/usr.bin/patch/version.c,v 1.2 1995/05/30 05:02:39 rgrimes Exp $  *  * $Log: version.c,v $  * Revision 1.2  1995/05/30 05:02:39  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1993/06/19  14:21:52  paul  * b-maked patch-2.10  *  * Revision 2.0  86/09/17  15:40:11  lwall  * Baseline for netwide release.  *  */
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_function_decl
name|void
name|my_exit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Print out the version number and die. */
end_comment

begin_function
name|void
name|version
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Patch version %s\n"
argument_list|,
name|PATCH_VERSION
argument_list|)
expr_stmt|;
name|my_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

