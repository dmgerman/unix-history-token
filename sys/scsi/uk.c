begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Driver for a device we can't identify.  * by Julian Elischer (julian@tfs.com)  *  *      $Id: uk.c,v 1.6 1995/01/08 13:38:38 dufault Exp $  */
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
block|,
comment|/* Only one open allowed */
name|ukattach
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

begin_comment
comment|/*  * The routine called by the low level scsi routine when it discovers  * a device suitable for this driver.  */
end_comment

begin_function
name|errval
name|ukattach
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
block|{
name|printf
argument_list|(
literal|"unknown device\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

