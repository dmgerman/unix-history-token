begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Driver for a device we can't identify.  * by Julian Elischer (julian@tfs.com)  *  * $FreeBSD$  *  * If you find that you are adding any code to this file look closely  * at putting it in "scsi_driver.c" instead.  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/devfsext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEVFS*/
end_comment

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_decl_stmt
specifier|static
name|d_open_t
name|ukopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|ukclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|ukioctl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|31
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|uk_cdevsw
init|=
block|{
name|ukopen
block|,
name|ukclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*31*/
name|ukioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* unknown */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|,
literal|"uk"
block|,
name|NULL
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|SCSI_DEVICE_ENTRIES
argument_list|(
argument|uk
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|scsi_device
name|uk_switch
init|=
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|"uk"
block|,
literal|0
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
name|SDEV_ONCE_ONLY
operator||
name|SDEV_UK
block|,
comment|/* Only one open allowed */
literal|0
block|,
literal|"Unknown"
block|,
name|ukopen
block|,
literal|0
block|,
name|T_UNKNOWN
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|uk_devsw_installed
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|uk_drvinit
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|dev_t
name|dev
decl_stmt|;
if|if
condition|(
operator|!
name|uk_devsw_installed
condition|)
block|{
name|dev
operator|=
name|makedev
argument_list|(
name|CDEV_MAJOR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cdevsw_add
argument_list|(
operator|&
name|dev
argument_list|,
operator|&
name|uk_cdevsw
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|uk_devsw_installed
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|ukdev
argument_list|,
argument|SI_SUB_DRIVERS
argument_list|,
argument|SI_ORDER_MIDDLE+CDEV_MAJOR
argument_list|,
argument|uk_drvinit
argument_list|,
argument|NULL
argument_list|)
end_macro

end_unit

