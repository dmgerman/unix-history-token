begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  *	$Id: scsiconf.h,v 1.8 1993/12/19 00:54:55 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_SCSICONF_H
end_ifndef

begin_define
define|#
directive|define
name|SCSI_SCSICONF_H
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|errval
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int
name|int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|u_int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<scsi/scsi_debug.h>
end_include

begin_comment
comment|/*  * The following documentation tries to describe the relationship between the  * various structures defined in this file:  *  * each adapter type has a scsi_adapter struct. This describes the adapter and  *    identifies routines that can be called to use the adapter.  * each device type has a scsi_device struct. This describes the device and  *    identifies routines that can be called to use the device.  * each existing device position (scsibus + target + lun)  *    can be described by a scsi_link struct.  *    Only scsi positions that actually have devices, have a scsi_link  *    structure assigned. so in effect each device has scsi_link struct.  *    The scsi_link structure contains information identifying both the  *    device driver and the adapter driver for that position on that scsi bus,  *    and can be said to 'link' the two.  * each individual scsi bus has an array that points to all the scsi_link  *    structs associated with that scsi bus. Slots with no device have  *    a NULL pointer.  * each individual device also knows the address of it's own scsi_link  *    structure.  *  *				-------------  *  * The key to all this is the scsi_link structure which associates all the   * other structures with each other in the correct configuration.  The  * scsi_link is the connecting information that allows each part of the   * scsi system to find the associated other parts.  */
end_comment

begin_comment
comment|/*  * These entrypoints are called by the high-end drivers to get services from  * whatever low-end drivers they are attached to each adapter type has one of  * these statically allocated.  */
end_comment

begin_struct
struct|struct
name|scsi_adapter
block|{
comment|/* 04*/
name|int32
function_decl|(
modifier|*
name|scsi_cmd
function_decl|)
parameter_list|()
function_decl|;
comment|/* 08*/
name|void
function_decl|(
modifier|*
name|scsi_minphys
function_decl|)
parameter_list|()
function_decl|;
comment|/* 12*/
name|int32
function_decl|(
modifier|*
name|open_target_lu
function_decl|)
parameter_list|()
function_decl|;
comment|/* 16*/
name|int32
function_decl|(
modifier|*
name|close_target_lu
function_decl|)
parameter_list|()
function_decl|;
comment|/* 20*/
name|u_int32
function_decl|(
modifier|*
name|adapter_info
function_decl|)
parameter_list|()
function_decl|;
comment|/* see definitions below */
comment|/* 24*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of scsi bus controller */
comment|/* 32*/
name|u_long
name|spare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * return values for scsi_cmd()  */
end_comment

begin_define
define|#
directive|define
name|SUCCESSFULLY_QUEUED
value|0
end_define

begin_define
define|#
directive|define
name|TRY_AGAIN_LATER
value|1
end_define

begin_define
define|#
directive|define
name|COMPLETE
value|2
end_define

begin_define
define|#
directive|define
name|HAD_ERROR
value|3
end_define

begin_comment
comment|/* do not use this, use COMPLETE */
end_comment

begin_define
define|#
directive|define
name|ESCAPE_NOT_SUPPORTED
value|4
end_define

begin_comment
comment|/*  * Format of adapter_info() response data  * e.g. maximum number of entries queuable to a device by the adapter  */
end_comment

begin_define
define|#
directive|define
name|AD_INF_MAX_CMDS
value|0x000000FF
end_define

begin_comment
comment|/* 24 bits of other adapter characteristics go here */
end_comment

begin_comment
comment|/*  * These entry points are called by the low-end drivers to get services from  * whatever high-end drivers they are attached to.  Each device type has one  * of these statically allocated.  */
end_comment

begin_struct
struct|struct
name|scsi_device
block|{
comment|/*  4*/
name|errval
function_decl|(
modifier|*
name|err_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* returns -1 to say err processing complete */
comment|/*  8*/
name|void
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|()
function_decl|;
comment|/* 12*/
name|int32
function_decl|(
modifier|*
name|async
function_decl|)
parameter_list|()
function_decl|;
comment|/* 16*/
name|int32
function_decl|(
modifier|*
name|done
function_decl|)
parameter_list|()
function_decl|;
comment|/* returns -1 to say done processing complete */
comment|/* 20*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of device type */
comment|/* 24*/
name|u_int32
name|flags
decl_stmt|;
comment|/* device type dependent flags */
comment|/* 32*/
name|int32
name|spare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure describes the connection between an adapter driver and  * a device driver, and is used by each to call services provided by  * the other, and to allow generic scsi glue code to call these services  * as well.  */
end_comment

begin_struct
struct|struct
name|scsi_link
block|{
comment|/*  1*/
name|u_int8
name|target
decl_stmt|;
comment|/* targ of this dev */
comment|/*  2*/
name|u_int8
name|lun
decl_stmt|;
comment|/* lun of this dev */
comment|/*  3*/
name|u_int8
name|adapter_targ
decl_stmt|;
comment|/* what are we on the scsi bus */
comment|/*  4*/
name|u_int8
name|adapter_unit
decl_stmt|;
comment|/* e.g. the 0 in aha0 */
comment|/*  5*/
name|u_int8
name|scsibus
decl_stmt|;
comment|/* the Nth scsibus	*/
comment|/*  6*/
name|u_int8
name|dev_unit
decl_stmt|;
comment|/* e.g. the 0 in sd0 */
comment|/*  7*/
name|u_int8
name|opennings
decl_stmt|;
comment|/* available operations */
comment|/*  8*/
name|u_int8
name|active
decl_stmt|;
comment|/* operations in progress */
comment|/* 10*/
name|u_int16
name|flags
decl_stmt|;
comment|/* flags that all devices have */
comment|/* 12*/
name|u_int8
name|spareb
index|[
literal|2
index|]
decl_stmt|;
comment|/* unused		*/
comment|/* 16*/
name|struct
name|scsi_adapter
modifier|*
name|adapter
decl_stmt|;
comment|/* adapter entry points etc. */
comment|/* 20*/
name|struct
name|scsi_device
modifier|*
name|device
decl_stmt|;
comment|/* device entry points etc. */
comment|/* 24*/
name|struct
name|scsi_xfer
modifier|*
name|active_xs
decl_stmt|;
comment|/* operations under way */
comment|/* 28*/
name|void
modifier|*
name|fordriver
decl_stmt|;
comment|/* for private use by the driver */
comment|/* 32*/
name|u_int32
name|spare
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDEV_MEDIA_LOADED
value|0x01
end_define

begin_comment
comment|/* device figures are still valid */
end_comment

begin_define
define|#
directive|define
name|SDEV_WAITING
value|0x02
end_define

begin_comment
comment|/* a process is waiting for this */
end_comment

begin_define
define|#
directive|define
name|SDEV_OPEN
value|0x04
end_define

begin_comment
comment|/* at least 1 open session */
end_comment

begin_define
define|#
directive|define
name|SDEV_BOUNCE
value|0x08
end_define

begin_comment
comment|/* unit requires DMA bounce buffer */
end_comment

begin_define
define|#
directive|define
name|SDEV_DBX
value|0xF0
end_define

begin_comment
comment|/* debuging flags (scsi_debug.h) */
end_comment

begin_comment
comment|/*  * One of these is allocated and filled in for each scsi bus.  * it holds pointers to allow the scsi bus to get to the driver  * That is running each LUN on the bus  * it also has a template entry which is the prototype struct  * supplied by the adapter driver, this is used to initialise  * the others, before they have the rest of the fields filled in  */
end_comment

begin_struct
struct|struct
name|scsibus_data
block|{
name|struct
name|scsi_link
modifier|*
name|adapter_link
decl_stmt|;
comment|/* prototype supplied by adapter */
name|struct
name|scsi_link
modifier|*
name|sc_link
index|[
literal|8
index|]
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each scsi transaction is fully described by one of these structures  * It includes information about the source of the command and also the  * device and adapter for which the command is destined.  * (via the scsi_link structure)						*  */
end_comment

begin_struct
struct|struct
name|scsi_xfer
block|{
comment|/*04*/
name|struct
name|scsi_xfer
modifier|*
name|next
decl_stmt|;
comment|/* when free */
comment|/*08*/
name|u_int32
name|flags
decl_stmt|;
comment|/*12*/
name|struct
name|scsi_link
modifier|*
name|sc_link
decl_stmt|;
comment|/* all about our device and adapter */
comment|/*13*/
name|u_int8
name|retries
decl_stmt|;
comment|/* the number of times to retry */
comment|/*16*/
name|u_int8
name|spare
index|[
literal|3
index|]
decl_stmt|;
comment|/*20*/
name|int32
name|timeout
decl_stmt|;
comment|/* in milliseconds */
comment|/*24*/
name|struct
name|scsi_generic
modifier|*
name|cmd
decl_stmt|;
comment|/* The scsi command to execute */
comment|/*28*/
name|int32
name|cmdlen
decl_stmt|;
comment|/* how long it is */
comment|/*32*/
name|u_char
modifier|*
name|data
decl_stmt|;
comment|/* dma address OR a uio address */
comment|/*36*/
name|int32
name|datalen
decl_stmt|;
comment|/* data len (blank if uio)    */
comment|/*40*/
name|int32
name|resid
decl_stmt|;
comment|/* how much buffer was not touched */
comment|/*44*/
name|int32
name|error
decl_stmt|;
comment|/* an error value	*/
comment|/*48*/
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* If we need to associate with a buf */
comment|/*80*/
name|struct
name|scsi_sense_data
name|sense
decl_stmt|;
comment|/* 32 bytes*/
comment|/* 	 * Believe it or not, Some targets fall on the ground with 	 * anything but a certain sense length. 	 */
comment|/*84*/
name|int32
name|req_sense_length
decl_stmt|;
comment|/* Explicit request sense length */
comment|/*88*/
name|int32
name|status
decl_stmt|;
comment|/* SCSI status */
comment|/*100*/
name|struct
name|scsi_generic
name|cmdstore
decl_stmt|;
comment|/* stash the command in here */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-request Flag values  */
end_comment

begin_define
define|#
directive|define
name|SCSI_NOSLEEP
value|0x01
end_define

begin_comment
comment|/* Not a user... don't sleep		*/
end_comment

begin_define
define|#
directive|define
name|SCSI_NOMASK
value|0x02
end_define

begin_comment
comment|/* dont allow interrupts.. booting	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_NOSTART
value|0x04
end_define

begin_comment
comment|/* left over from ancient history	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_USER
value|0x08
end_define

begin_comment
comment|/* Is a user cmd, call scsi_user_done	*/
end_comment

begin_define
define|#
directive|define
name|ITSDONE
value|0x10
end_define

begin_comment
comment|/* the transfer is as done as it gets	*/
end_comment

begin_define
define|#
directive|define
name|INUSE
value|0x20
end_define

begin_comment
comment|/* The scsi_xfer block is in use	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_SILENT
value|0x40
end_define

begin_comment
comment|/* Don't report errors to console	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_ERR_OK
value|0x80
end_define

begin_comment
comment|/* An error on this operation is OK.	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_RESET
value|0x100
end_define

begin_comment
comment|/* Reset the device in question		*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_UIO
value|0x200
end_define

begin_comment
comment|/* The data address refers to a UIO	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_IN
value|0x400
end_define

begin_comment
comment|/* expect data to come INTO memory	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_OUT
value|0x800
end_define

begin_comment
comment|/* expect data to flow OUT of memory	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_TARGET
value|0x1000
end_define

begin_comment
comment|/* This defines a TARGET mode op.	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_ESCAPE
value|0x2000
end_define

begin_comment
comment|/* Escape operation			*/
end_comment

begin_comment
comment|/*  * Escape op codes.  This provides an extensible setup for operations  * that are not scsi commands.  They are intended for modal operations.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_OP_TARGET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCSI_OP_RESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCSI_OP_BDINFO
value|0x0003
end_define

begin_comment
comment|/*  * Error values an adapter driver may return  */
end_comment

begin_define
define|#
directive|define
name|XS_NOERROR
value|0x0
end_define

begin_comment
comment|/* there is no error, (sense is invalid)  */
end_comment

begin_define
define|#
directive|define
name|XS_SENSE
value|0x1
end_define

begin_comment
comment|/* Check the returned sense for the error */
end_comment

begin_define
define|#
directive|define
name|XS_DRIVER_STUFFUP
value|0x2
end_define

begin_comment
comment|/* Driver failed to perform operation	  */
end_comment

begin_define
define|#
directive|define
name|XS_TIMEOUT
value|0x03
end_define

begin_comment
comment|/* The device timed out.. turned off?	  */
end_comment

begin_define
define|#
directive|define
name|XS_SWTIMEOUT
value|0x04
end_define

begin_comment
comment|/* The Timeout reported was caught by SW  */
end_comment

begin_define
define|#
directive|define
name|XS_BUSY
value|0x08
end_define

begin_comment
comment|/* The device busy, try again later?	  */
end_comment

begin_decl_stmt
name|void
name|scsi_attachdevs
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
name|sc_link_proto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|scsi_xfer
modifier|*
name|get_xs
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_xs
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|,
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32
name|scsi_size
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_test_unit_ready
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_change_def
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_inquire
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inqbuf
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_prevent
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|type
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_start_unit
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scsi_done
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_scsi_cmd
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|struct
name|scsi_generic
modifier|*
name|scsi_cmd
parameter_list|,
name|u_int32
name|cmdlen
parameter_list|,
name|u_char
modifier|*
name|data_addr
parameter_list|,
name|u_int32
name|datalen
parameter_list|,
name|u_int32
name|retries
parameter_list|,
name|u_int32
name|timeout
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|errval
name|scsi_do_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|addr
operator|,
name|int
name|f
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|show_scsi_xs
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_scsi_cmd
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_mem
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|lto3b
name|__P
argument_list|(
operator|(
name|int
name|val
operator|,
name|u_char
operator|*
name|bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_3btol
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|sc_print_addr
parameter_list|(
name|struct
name|scsi_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*SCSI_SCSICONF_H*/
end_comment

begin_comment
comment|/* END OF FILE */
end_comment

end_unit

