begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** */
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_comment
comment|/* **  Memory failure handler; print an error and exit. */
end_comment

begin_function
name|STATIC
name|int
name|xmemerr
parameter_list|(
name|what
parameter_list|,
name|i
parameter_list|)
name|char
modifier|*
name|what
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
block|{
comment|/* We want large values to show up as negative, hence %d. */
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't %s %d bytes, %s"
argument_list|,
name|what
argument_list|,
name|i
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_function_decl
name|int
function_decl|(
modifier|*
name|xmemfailure
function_decl|)
parameter_list|()
init|=
name|xmemerr
function_decl|;
end_function_decl

end_unit

