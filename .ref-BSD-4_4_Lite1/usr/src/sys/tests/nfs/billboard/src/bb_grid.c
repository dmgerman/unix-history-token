begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ******************************************************************************  *  * Module: bb_grid.c  *  * Functions:   *	    bb_grid_1()	- Return the information on successful testing.  *  *  ******************************************************************************  */
end_comment

begin_comment
comment|/*  ******************************************************************************  * Include Files  ******************************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_grid_1() - Return a list of all of the test results.  This is	** **  just an indication of how the tests are coming in general, no info	** **  on which companies have done what tests will be revield.		** **									** *************************************************************************/
end_comment

begin_function
name|BB_grid
modifier|*
name|bb_grid_1
parameter_list|()
block|{
specifier|static
name|BB_grid
name|grid
decl_stmt|;
comment|/* The output grid structure.	*/
comment|/*     **  XXXX-This will be filled in later.     */
name|grid
operator|.
name|status
operator|==
name|BB_SUCCESS
expr_stmt|;
return|return
operator|&
name|grid
return|;
block|}
end_function

end_unit

