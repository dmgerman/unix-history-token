begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mjs copyright  */
end_comment

begin_comment
comment|/*  * Obtain memory configuration information from the BIOS  *  * Note that we don't try too hard here; knowing the size of  * base memory and extended memory out to 16 or 64M is enough for  * the requirements of the bootstrap.  *  * We also maintain a pointer to the top of physical memory  * once called to allow rangechecking of load/copy requests.  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"btxv86.h"
end_include

begin_decl_stmt
name|vm_offset_t
name|memtop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return base memory size in kB.  */
end_comment

begin_function
name|int
name|getbasemem
parameter_list|(
name|void
parameter_list|)
block|{
name|v86
operator|.
name|ctl
operator|=
literal|0
expr_stmt|;
name|v86
operator|.
name|addr
operator|=
literal|0x1a
expr_stmt|;
comment|/* int 0x12 */
name|v86int
argument_list|()
expr_stmt|;
return|return
operator|(
name|v86
operator|.
name|eax
operator|&
literal|0xffff
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return extended memory size in kB  */
end_comment

begin_function
name|int
name|getextmem
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|extkb
decl_stmt|;
name|v86
operator|.
name|ctl
operator|=
literal|0
expr_stmt|;
name|v86
operator|.
name|addr
operator|=
literal|0x15
expr_stmt|;
comment|/* int 0x12 function 0x88*/
name|v86
operator|.
name|eax
operator|=
literal|0x8800
expr_stmt|;
name|v86int
argument_list|()
expr_stmt|;
name|extkb
operator|=
name|v86
operator|.
name|eax
operator|&
literal|0xffff
expr_stmt|;
comment|/* Set memtop to actual top or 16M, whicheve is less */
name|memtop
operator|=
name|min
argument_list|(
operator|(
literal|0x100000
operator|+
operator|(
name|extkb
operator|+
literal|1024
operator|)
operator|)
argument_list|,
operator|(
literal|16
operator|*
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|extkb
operator|)
return|;
block|}
end_function

end_unit

