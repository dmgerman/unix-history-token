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
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

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

end_unit

