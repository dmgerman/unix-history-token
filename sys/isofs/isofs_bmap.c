begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	$Id: isofs_bmap.c,v 1.3 1993/11/25 01:32:21 wollman Exp $  */
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
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_include
include|#
directive|include
file|"isofs_node.h"
end_include

begin_function
name|int
name|iso_bmap
parameter_list|(
name|ip
parameter_list|,
name|lblkno
parameter_list|,
name|result
parameter_list|)
name|struct
name|iso_node
modifier|*
name|ip
decl_stmt|;
name|int
name|lblkno
decl_stmt|;
name|int
modifier|*
name|result
decl_stmt|;
block|{
operator|*
name|result
operator|=
operator|(
name|ip
operator|->
name|iso_extent
operator|+
name|lblkno
operator|)
operator|*
operator|(
name|ip
operator|->
name|i_mnt
operator|->
name|im_bsize
operator|/
name|DEV_BSIZE
operator|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

