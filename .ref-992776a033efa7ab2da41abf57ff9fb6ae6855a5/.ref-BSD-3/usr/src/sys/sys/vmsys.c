begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmsys.c	2.1	1/5/80	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/proc.h"
end_include

begin_include
include|#
directive|include
file|"../h/reg.h"
end_include

begin_include
include|#
directive|include
file|"../h/file.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/vm.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/pte.h"
end_include

begin_macro
name|vfork
argument_list|()
end_macro

begin_block
block|{
name|fork1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|vread
argument_list|()
end_macro

begin_block
block|{
name|rdwr
argument_list|(
name|FREAD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|vwrite
argument_list|()
end_macro

begin_block
block|{
name|rdwr
argument_list|(
name|FWRITE
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

