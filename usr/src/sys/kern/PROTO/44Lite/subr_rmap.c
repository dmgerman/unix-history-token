begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)subr_rmap.c	7.9 (Berkeley) 5/11/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"dmap.h"
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_comment
comment|/*  * Resource map handling routines.  */
end_comment

begin_comment
comment|/*  * Initialize map mp to have (mapsize-2) segments  * and to be called ``name'', which we print if  * the slots become so fragmented that we lose space.  * The map itself is initialized with size elements free  * starting at addr.  */
end_comment

begin_expr_stmt
name|rminit
argument_list|(
name|mp
argument_list|,
name|size
argument_list|,
name|addr
argument_list|,
name|name
argument_list|,
name|mapsize
argument_list|)
specifier|register
expr|struct
name|map
operator|*
name|mp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|size
decl_stmt|,
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mapsize
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_function
name|long
name|rmalloc
parameter_list|(
name|mp
parameter_list|,
name|size
parameter_list|)
specifier|register
name|struct
name|map
modifier|*
name|mp
decl_stmt|;
name|long
name|size
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|rmfree
argument_list|(
argument|mp
argument_list|,
argument|size
argument_list|,
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|map
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|size
decl_stmt|,
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

end_unit

