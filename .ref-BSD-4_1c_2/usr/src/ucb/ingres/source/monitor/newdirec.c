begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"monitor.h"
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)newdirec.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  CHANGE WORKING DIRECTORY */
end_comment

begin_macro
name|newdirec
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
name|direc
decl_stmt|;
specifier|extern
name|char
modifier|*
name|getfilenm
parameter_list|()
function_decl|;
name|direc
operator|=
name|getfilenm
argument_list|()
expr_stmt|;
if|if
condition|(
name|chdir
argument_list|(
name|direc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Cannot access directory \"%s\"\n"
argument_list|,
name|direc
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

