begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)device.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This structure is used to encapsulate the routines for a device driver.  * This allows an "object oriented" approach so a controller device driver  * can support multiple attached devices or a device can be attached to  * different types of controllers.  */
end_comment

begin_struct
struct|struct
name|driver
block|{
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* device driver name (e.g., "rz") */
name|int
function_decl|(
modifier|*
name|d_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to probe& initialize device */
name|void
function_decl|(
modifier|*
name|d_start
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to start operation */
name|void
function_decl|(
modifier|*
name|d_done
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when operation complete */
name|void
function_decl|(
modifier|*
name|d_intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when interrupt is seen */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure describes controllers directly connected to CPU  * and is partially initialized in "ioconf.c" by the 'config' program.  */
end_comment

begin_struct
struct|struct
name|pmax_ctlr
block|{
name|struct
name|driver
modifier|*
name|pmax_driver
decl_stmt|;
comment|/* controller driver routines */
name|int
name|pmax_unit
decl_stmt|;
comment|/* controller number */
name|char
modifier|*
name|pmax_addr
decl_stmt|;
comment|/* address of controller */
name|int
name|pmax_pri
decl_stmt|;
comment|/* interrupt priority */
name|int
name|pmax_flags
decl_stmt|;
comment|/* flags */
name|int
name|pmax_alive
decl_stmt|;
comment|/* true if init routine succeeded */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure describes devices connected to a SCSI interface  * and is partially initialized in "ioconf.c" by the 'config' program.  */
end_comment

begin_struct
struct|struct
name|scsi_device
block|{
name|struct
name|driver
modifier|*
name|sd_driver
decl_stmt|;
comment|/* SCSI device driver routines */
name|struct
name|driver
modifier|*
name|sd_cdriver
decl_stmt|;
comment|/* SCSI interface driver routines */
name|int
name|sd_unit
decl_stmt|;
comment|/* device unit number */
name|int
name|sd_ctlr
decl_stmt|;
comment|/* SCSI interface number */
name|int
name|sd_drive
decl_stmt|;
comment|/* SCSI address number */
name|int
name|sd_slave
decl_stmt|;
comment|/* LUN if device has multiple units */
name|int
name|sd_dk
decl_stmt|;
comment|/* used for disk statistics */
name|int
name|sd_flags
decl_stmt|;
comment|/* flags */
name|int
name|sd_alive
decl_stmt|;
comment|/* true if init routine succeeded */
block|}
struct|;
end_struct

begin_comment
comment|/* Define special unit types used by the config program */
end_comment

begin_define
define|#
directive|define
name|QUES
value|-1
end_define

begin_comment
comment|/* -1 means '?' */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|-2
end_define

begin_comment
comment|/* -2 means not set yet */
end_comment

begin_comment
comment|/*  * This structure contains information that a SCSI interface controller   * needs to execute a SCSI command.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiCmd
block|{
name|struct
name|scsi_device
modifier|*
name|sd
decl_stmt|;
comment|/* device requesting the command */
name|int
name|unit
decl_stmt|;
comment|/* unit number passed to device done routine */
name|int
name|flags
decl_stmt|;
comment|/* control flags for this command (see below) */
name|int
name|buflen
decl_stmt|;
comment|/* length of the data buffer in bytes */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to data buffer for this command */
name|int
name|cmdlen
decl_stmt|;
comment|/* length of data in cmdbuf */
name|u_char
modifier|*
name|cmd
decl_stmt|;
comment|/* buffer for the SCSI command */
block|}
name|ScsiCmd
typedef|;
end_typedef

begin_comment
comment|/*  * Define flags for controlling the SCSI command.  *  * SCSICMD_DATA_TO_DEVICE  *	TRUE -> data is to be transferred to the device.  *	FALSE -> data is to be transferred from the device.  *	meaningless if buflen is 0.  * SCSICMD_USE_SYNC  *	Attempt to negotiate for a synchronous data transfer.  */
end_comment

begin_define
define|#
directive|define
name|SCSICMD_DATA_TO_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSICMD_USE_SYNC
value|0x02
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pmax_ctlr
name|pmax_cinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|scsi_device
name|scsi_dinit
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

