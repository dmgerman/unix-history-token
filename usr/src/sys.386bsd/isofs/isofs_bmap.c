begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"param.h"
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

begin_macro
name|iso_bmap
argument_list|(
argument|ip
argument_list|,
argument|lblkno
argument_list|,
argument|result
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iso_node
modifier|*
name|ip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lblkno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|result
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

end_unit

