begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|"globs.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)error.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_macro
name|derror
argument_list|(
argument|eno
argument_list|)
end_macro

begin_block
block|{
name|endovqp
argument_list|(
name|NOACK
argument_list|)
expr_stmt|;
name|reinit
argument_list|()
expr_stmt|;
name|error
argument_list|(
name|eno
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

