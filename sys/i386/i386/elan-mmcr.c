begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_comment
comment|/*  * Device driver initialization stuff  */
end_comment

begin_decl_stmt
specifier|static
name|d_open_t
name|elan_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|elan_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|elan_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_mmap_t
name|elan_mmap
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|100
end_define

begin_comment
comment|/* Share with xrpu */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|elan_cdevsw
init|=
block|{
comment|/* open */
name|elan_open
block|,
comment|/* close */
name|elan_close
block|,
comment|/* read */
name|noread
block|,
comment|/* write */
name|nowrite
block|,
comment|/* ioctl */
name|elan_ioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|elan_mmap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"elan"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|elan_open
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|elan_close
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|elan_mmap
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|int
name|nprot
parameter_list|)
block|{
if|if
condition|(
name|offset
operator|>=
literal|0x1000
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|i386_btop
argument_list|(
literal|0xfffef000
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|elan_ioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|tdr
parameter_list|)
block|{
return|return
operator|(
name|ENOENT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|elan_drvinit
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|elan_mmcr
operator|==
name|NULL
condition|)
return|return;
name|make_dev
argument_list|(
operator|&
name|elan_cdevsw
argument_list|,
literal|0
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0600
argument_list|,
literal|"elan-mmcr"
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|elan
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_MIDDLE
operator|+
name|CDEV_MAJOR
argument_list|,
name|elan_drvinit
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

