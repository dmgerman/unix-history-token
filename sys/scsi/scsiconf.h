begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  *	$Id: scsiconf.h,v 1.46.2.2 1997/07/14 12:48:32 kato Exp $  */
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

begin_include
include|#
directive|include
file|<scsi/scsi_debug.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_driver.h>
end_include

begin_comment
comment|/*  * The following documentation tries to describe the relationship between the  * various structures defined in this file:  *  * each adapter type has a scsi_adapter struct. This describes the adapter and  *    identifies routines that can be called to use the adapter.  * each device type has a scsi_device struct. This describes the device and  *    identifies routines that can be called to use the device.  * each existing device position (scsibus + target + lun)  *    can be described by a scsi_link struct.  *    Only scsi positions that actually have devices, have a scsi_link  *    structure assigned. so in effect each device has scsi_link struct.  *    The scsi_link structure contains information identifying both the  *    device driver and the adapter driver for that position on that scsi bus,  *    and can be said to 'link' the two.  * each individual scsi bus has an array that points to all the scsi_link  *    structs associated with that scsi bus. Slots with no device have  *    a NULL pointer.  * each individual device also knows the address of it's own scsi_link  *    structure.  *  *				-------------  *  * The key to all this is the scsi_link structure which associates all the  * other structures with each other in the correct configuration.  The  * scsi_link is the connecting information that allows each part of the  * scsi system to find the associated other parts.  */
end_comment

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scsi_xfer
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_struct_decl
struct_decl|struct
name|cfdata
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't poke around inside of "scsi_data".  Each low level  * driver has its own definition for it.  */
end_comment

begin_struct_decl
struct_decl|struct
name|scsi_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scsi_link
struct_decl|;
end_struct_decl

begin_comment
comment|/* scsi_link refers to scsi_device and vice-versa */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * These entrypoints are called by the high-end drivers to get services from  * whatever low-end drivers they are attached to each adapter type has one of  * these statically allocated.  */
end_comment

begin_struct
struct|struct
name|scsi_adapter
block|{
comment|/* 04*/
name|int32_t
argument_list|(
argument|*scsi_cmd
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
name|xs
operator|)
argument_list|)
expr_stmt|;
comment|/* 08*/
name|void
argument_list|(
argument|*scsi_minphys
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PC98
comment|/* 12*/
name|int32_t
argument_list|(
argument|*open_target_lu
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|,
expr|struct
name|cfdata
operator|*
name|cf
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* 12*/
name|int32_t
argument_list|(
argument|*open_target_lu
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 16*/
name|int32_t
argument_list|(
argument|*close_target_lu
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 20*/
name|u_int32_t
argument_list|(
argument|*adapter_info
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
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
comment|/*  * Return value from sense handler.  IMHO, These ought to be merged  * in with the return codes above, all made negative to distinguish  * from valid errno values, and replace "try again later" with "do retry"  */
end_comment

begin_define
define|#
directive|define
name|SCSIRET_CONTINUE
value|-1
end_define

begin_comment
comment|/* Continue with standard sense processing */
end_comment

begin_define
define|#
directive|define
name|SCSIRET_DO_RETRY
value|-2
end_define

begin_comment
comment|/* Retry the command that got this sense */
end_comment

begin_comment
comment|/*  * Format of adapter_info() response data  * e.g. maximum number of entries queuable to a device by the adapter  */
end_comment

begin_comment
comment|/*  * These entry points are called by the low-end drivers to get services from  * whatever high-end drivers they are attached to.  Each device type has one  * of these statically allocated.  *  * XXX dufault@hda.com: Each adapter driver has a scsi_device structure  *     that I don't think should be there.  *     This structure should be rearranged and cleaned up once the  *     instance down in the adapter drivers is removed.  */
end_comment

begin_comment
comment|/*  * XXX this is so that everything that includes this bloated header doesn't  * also need to include<sys/conf.h>.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|yet_another_d_open_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|,
name|int
typedef|, struct
name|proc
modifier|*
typedef|));
end_typedef

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
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|)
function_decl|;
comment|/* return -1 to say 							 * err processing complete */
comment|/*  8*/
name|void
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|u_int32_t
name|unit
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
comment|/* 12*/
name|int32_t
argument_list|(
argument|*async
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 16*/
name|int32_t
argument_list|(
argument|*done
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
name|xs
operator|)
argument_list|)
expr_stmt|;
comment|/* returns -1 to say done processing complete */
comment|/* 20*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of device type */
comment|/* 24*/
name|u_int32_t
name|flags
decl_stmt|;
comment|/* device type dependent flags */
comment|/* 32*/
name|int32_t
name|spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* 36*/
name|int32_t
name|link_flags
decl_stmt|;
comment|/* Flags OR'd into sc_link at attach time */
comment|/* 40*/
name|errval
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
function_decl|;
comment|/* 44*/
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* Description of device */
comment|/* 48*/
name|yet_another_d_open_t
modifier|*
name|open
decl_stmt|;
comment|/* 52*/
name|int
name|sizeof_scsi_data
decl_stmt|;
comment|/* 56*/
name|int
name|type
decl_stmt|;
comment|/* Type of device this supports */
comment|/* 60*/
name|int
function_decl|(
modifier|*
name|getunit
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
comment|/* 64*/
name|dev_t
function_decl|(
modifier|*
name|setunit
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* 68*/
name|int
function_decl|(
modifier|*
name|dev_open
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fmt
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
function_decl|;
comment|/* 72*/
name|int
function_decl|(
modifier|*
name|dev_ioctl
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
function_decl|;
comment|/* 76*/
name|int
function_decl|(
modifier|*
name|dev_close
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|fmt
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
function_decl|;
comment|/* 80*/
name|void
function_decl|(
modifier|*
name|dev_strategy
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
function_decl|;
comment|/* Not initialized after this */
define|#
directive|define
name|SCSI_LINK
parameter_list|(
name|DEV
parameter_list|,
name|UNIT
parameter_list|)
value|( \ 	(struct scsi_link *)(extend_get((DEV)->links, (UNIT))) \ 	)
define|#
directive|define
name|SCSI_DATA
parameter_list|(
name|DEV
parameter_list|,
name|UNIT
parameter_list|)
value|( \ 	(SCSI_LINK((DEV), (UNIT)) ? \ 	(SCSI_LINK((DEV), (UNIT))->sd) : \ 	(struct scsi_data *)0) \ 	)
comment|/* 80*/
name|struct
name|extend_array
modifier|*
name|links
decl_stmt|;
comment|/* 84*/
name|int
name|free_unit
decl_stmt|;
comment|/* 88*/
name|struct
name|scsi_device
modifier|*
name|next
decl_stmt|;
comment|/* Next in list in the registry. */
block|}
struct|;
end_struct

begin_comment
comment|/* SCSI_DEVICE_ENTRIES: A macro to generate all the entry points from the  * name.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DEVICE_ENTRIES
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static errval NAME##attach(struct scsi_link *sc_link); \ extern struct scsi_device NAME##_switch;
comment|/* XXX actually static */
value|\ void NAME##init(void) { \ 	scsi_device_register(&NAME##_switch); \ } \ static int NAME##open(dev_t dev, int flags, int fmt, struct proc *p) { \ 	return scsi_open(dev, flags, fmt, p,&NAME##_switch); \ } \ static int NAME##ioctl(dev_t dev, int cmd, caddr_t addr, int flag, struct proc *p) { \ 	return scsi_ioctl(dev, cmd, addr, flag, p,&NAME##_switch); \ } \ static int NAME##close(dev_t dev, int flag, int fmt, struct proc *p) { \ 	return scsi_close(dev, flag, fmt, p,&NAME##_switch); \ } \ static void NAME##minphys(struct buf *bp) { \ 	scsi_minphys(bp,&NAME##_switch); \ }  \ static void NAME##strategy(struct buf *bp) { \ 	scsi_strategy(bp,&NAME##_switch); \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* Configuration tables for config.  */
end_comment

begin_comment
comment|/* A unit, type, etc can be SCCONF_ANY to indicate it is a '?'  *  in the config.  */
end_comment

begin_define
define|#
directive|define
name|SCCONF_UNSPEC
value|255
end_define

begin_define
define|#
directive|define
name|SCCONF_ANY
value|254
end_define

begin_struct_decl
struct_decl|struct
name|isa_driver
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|scsi_ctlr_config
block|{
name|int
name|scbus
decl_stmt|;
name|char
modifier|*
name|driver
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|int
name|bus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_device_config
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* SCSI device name (sd, st, etc) */
name|int
name|unit
decl_stmt|;
comment|/* desired device unit */
name|int
name|cunit
decl_stmt|;
comment|/* Controller unit */
name|int
name|target
decl_stmt|;
comment|/* SCSI ID (target) */
name|int
name|lun
decl_stmt|;
comment|/* SCSI lun */
name|int
name|flags
decl_stmt|;
comment|/* Flags from config */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|scsi_tinit
index|[]
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|scsi_ctlr_config
name|scsi_cinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|scsi_device_config
name|scsi_dinit
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define various devices that we know mis-behave in some way,  * and note how they are bad, so we can correct for them  */
end_comment

begin_struct
struct|struct
name|st_mode
block|{
comment|/*  4*/
name|u_int32_t
name|blksiz
decl_stmt|;
comment|/*  6*/
name|u_int16_t
name|quirks
decl_stmt|;
comment|/* same definitions as in XXX */
comment|/*  7*/
name|u_int8_t
name|density
decl_stmt|;
comment|/*  8*/
name|u_int8_t
name|spare
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|st_mode
name|st_modes
index|[
literal|4
index|]
typedef|;
end_typedef

begin_comment
comment|/* define behaviour codes (quirks) */
end_comment

begin_comment
comment|/* common to all SCSI devices */
end_comment

begin_define
define|#
directive|define
name|SCSI_Q_NO_SYNC
value|0x8000
end_define

begin_define
define|#
directive|define
name|SCSI_Q_NO_FAST
value|0x4000
end_define

begin_define
define|#
directive|define
name|SCSI_Q_NO_WIDE
value|0x2000
end_define

begin_comment
comment|/* tape specific ST_Q_* */
end_comment

begin_define
define|#
directive|define
name|ST_Q_NEEDS_PAGE_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|ST_Q_FORCE_FIXED_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ST_Q_FORCE_VAR_MODE
value|0x0004
end_define

begin_define
define|#
directive|define
name|ST_Q_SNS_HLP
value|0x0008
end_define

begin_comment
comment|/* must do READ for good MODE SENSE */
end_comment

begin_define
define|#
directive|define
name|ST_Q_IGNORE_LOADS
value|0x0010
end_define

begin_define
define|#
directive|define
name|ST_Q_BLKSIZ
value|0x0020
end_define

begin_comment
comment|/* variable-block media_blksiz> 0 */
end_comment

begin_define
define|#
directive|define
name|ST_Q_CC_NOMSG
value|0x0040
end_define

begin_comment
comment|/* no messages accepted in CC state */
end_comment

begin_define
define|#
directive|define
name|ST_Q_NO_1024
value|0x0080
end_define

begin_comment
comment|/* never ever use 1024-byte fix blk */
end_comment

begin_define
define|#
directive|define
name|ST_Q_NO_SYNC
value|SCSI_Q_NO_SYNC
end_define

begin_define
define|#
directive|define
name|ST_Q_NO_FAST
value|SCSI_Q_NO_FAST
end_define

begin_define
define|#
directive|define
name|ST_Q_NO_WIDE
value|SCSI_Q_NO_WIDE
end_define

begin_comment
comment|/* disk specific SD_Q_* */
end_comment

begin_define
define|#
directive|define
name|SD_Q_NO_TAGS
value|0x0001
end_define

begin_define
define|#
directive|define
name|SD_Q_NO_SYNC
value|SCSI_Q_NO_SYNC
end_define

begin_define
define|#
directive|define
name|SD_Q_NO_FAST
value|SCSI_Q_NO_FAST
end_define

begin_define
define|#
directive|define
name|SD_Q_NO_WIDE
value|SCSI_Q_NO_WIDE
end_define

begin_comment
comment|/* cd specific CD_Q_* */
end_comment

begin_define
define|#
directive|define
name|CD_Q_NO_TOUCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|CD_Q_BCD_TRACKS
value|0x0002
end_define

begin_comment
comment|/*  * This structure describes the connection between an adapter driver and  * a device driver, and is used by each to call services provided by  * the other, and to allow generic scsi glue code to call these services  * as well.  */
end_comment

begin_struct
struct|struct
name|scsi_link
block|{
name|u_int8_t
name|target
decl_stmt|;
comment|/* targ of this dev */
name|u_int8_t
name|lun
decl_stmt|;
comment|/* lun of this dev */
name|u_int8_t
name|adapter_targ
decl_stmt|;
comment|/* what are we on the scsi bus */
name|u_int8_t
name|adapter_unit
decl_stmt|;
comment|/* e.g. the 0 in aha0 */
name|u_int8_t
name|adapter_bus
decl_stmt|;
comment|/* e.g. the 0 in bus0 */
name|u_int8_t
name|scsibus
decl_stmt|;
comment|/* the Nth scsibus	*/
name|u_int8_t
name|dev_unit
decl_stmt|;
comment|/* e.g. the 0 in sd0 */
name|u_int8_t
name|opennings
decl_stmt|;
comment|/* available operations */
name|u_int8_t
name|active
decl_stmt|;
comment|/* operations in progress */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* flags that all devices have */
name|u_int16_t
name|quirks
decl_stmt|;
comment|/* device specific quirks */
name|struct
name|scsi_adapter
modifier|*
name|adapter
decl_stmt|;
comment|/* adapter entry points etc. */
name|struct
name|scsi_device
modifier|*
name|device
decl_stmt|;
comment|/* device entry points etc. */
name|struct
name|scsi_xfer
modifier|*
name|active_xs
decl_stmt|;
comment|/* operations under way */
name|void
modifier|*
name|fordriver
decl_stmt|;
comment|/* for private use by the driver */
name|void
modifier|*
name|devmodes
decl_stmt|;
comment|/* device specific mode tables */
name|dev_t
name|dev
decl_stmt|;
comment|/* Device major number (character) */
name|struct
name|scsi_data
modifier|*
name|sd
decl_stmt|;
comment|/* Device data structure */
name|struct
name|scsi_inquiry_data
name|inqbuf
decl_stmt|;
comment|/* Inquiry data */
name|void
modifier|*
name|adapter_softc
decl_stmt|;
comment|/* needed for call to foo_scsi_cmd */
block|}
struct|;
end_struct

begin_comment
comment|/* XXX-HA: dufault@hda.com: SDEV_BOUNCE is set down in the adapter drivers  * in an sc_link structure to indicate that this host adapter requires  * ISA DMA bounce buffers.  I think the link structure should  * be associated only with the type drive and not the adapter driver,  * and the bounce flag should be in something associated with the  * adapter driver.  * XXX-HA And I added the "supports residuals properly" flag that ALSO goes  * in an adapter structure.  I figure I'll fix both at once.  *  * XXX SDEV_OPEN is used for two things: To prevent more than one  * open and to make unit attentions errors be logged on the console.  * These should be split up; I'm adding SDEV_IS_OPEN to enforce one  * open only.  *  * XXX SDEV_UK is used to mark the "uk" device.  */
end_comment

begin_define
define|#
directive|define
name|SDEV_MEDIA_LOADED
value|0x0001
end_define

begin_comment
comment|/* device figures are still valid */
end_comment

begin_define
define|#
directive|define
name|SDEV_WAITING
value|0x0002
end_define

begin_comment
comment|/* a process is waiting for this */
end_comment

begin_define
define|#
directive|define
name|SDEV_OPEN
value|0x0004
end_define

begin_comment
comment|/* at least 1 open session */
end_comment

begin_define
define|#
directive|define
name|SDEV_BOUNCE
value|0x0008
end_define

begin_comment
comment|/* XXX-HA: unit needs DMA bounce buffer */
end_comment

begin_define
define|#
directive|define
name|SDEV_DBX
value|0x00F0
end_define

begin_comment
comment|/* debugging flags (scsi_debug.h) */
end_comment

begin_define
define|#
directive|define
name|SDEV_ONCE_ONLY
value|0x0100
end_define

begin_comment
comment|/* unit can only be opened once */
end_comment

begin_define
define|#
directive|define
name|SDEV_BOOTVERBOSE
value|0x0200
end_define

begin_comment
comment|/* be noisy during boot */
end_comment

begin_define
define|#
directive|define
name|SDEV_RESIDS_WORK
value|0x0400
end_define

begin_comment
comment|/* XXX-HA: Residuals work */
end_comment

begin_define
define|#
directive|define
name|SDEV_TARGET_OPS
value|0x0800
end_define

begin_comment
comment|/* XXX-HA: Supports target ops  */
end_comment

begin_define
define|#
directive|define
name|SDEV_IS_OPEN
value|0x1000
end_define

begin_comment
comment|/* at least 1 open session */
end_comment

begin_define
define|#
directive|define
name|SDEV_UK
value|0x2000
end_define

begin_comment
comment|/* this is the "uk" device */
end_comment

begin_comment
comment|/*  * One of these is allocated and filled in for each scsi bus.  * it holds pointers to allow the scsi bus to get to the driver  * That is running each LUN on the bus  * it also has a template entry which is the prototype struct  * supplied by the adapter driver, this is used to initialise  * the others, before they have the rest of the fields filled in  */
end_comment

begin_struct
struct|struct
name|scsibus_data
block|{
name|u_char
name|maxtarg
decl_stmt|;
name|u_char
name|maxlun
decl_stmt|;
name|struct
name|scsi_link
modifier|*
name|adapter_link
decl_stmt|;
comment|/* prototype supplied by adapter */
name|struct
name|scsi_link
modifier|*
argument_list|(
operator|*
name|sc_link
argument_list|)
decl|[][8]
decl_stmt|;
comment|/* dynamically allocated */
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
name|u_int32_t
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
name|u_int8_t
name|retries
decl_stmt|;
comment|/* the number of times to retry */
comment|/*16*/
name|u_int8_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
comment|/*20*/
name|int32_t
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
name|int32_t
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
name|int32_t
name|datalen
decl_stmt|;
comment|/* data len (blank if uio)    */
comment|/*40*/
name|int32_t
name|resid
decl_stmt|;
comment|/* how much buffer was not touched */
comment|/*44*/
name|int32_t
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
name|int32_t
name|req_sense_length
decl_stmt|;
comment|/* Explicit request sense length */
comment|/*88*/
name|int32_t
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
name|SCSI_ITSDONE
value|0x10
end_define

begin_comment
comment|/* the transfer is as done as it gets	*/
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
name|SCSI_INUSE
value|0x20
end_define

begin_comment
comment|/* The scsi_xfer block is in use	*/
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

begin_define
define|#
directive|define
name|SCSI_EOF
value|0x4000
end_define

begin_comment
comment|/* The operation should return EOF	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_RESID_VALID
value|0x8000
end_define

begin_comment
comment|/* The resid field contains valid data	*/
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

begin_define
define|#
directive|define
name|XS_LENGTH
value|0x09
end_define

begin_comment
comment|/* Illegal length (over/under run)	  */
end_comment

begin_define
define|#
directive|define
name|XS_SELTIMEOUT
value|0x10
end_define

begin_comment
comment|/* Device failed to respond to selection  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
modifier|*
name|extend_get
parameter_list|(
name|struct
name|extend_array
modifier|*
name|ea
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|scsi_attachdevs
name|__P
argument_list|(
operator|(
expr|struct
name|scsibus_data
operator|*
name|scbus
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|scsi_read_capacity
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|,
name|u_int32_t
operator|*
name|blk_size
operator|,
name|u_int32_t
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_test_unit_ready
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|,
name|u_int32_t
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_reset_target
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_target_mode
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|u_int32_t
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
name|u_int32_t
name|type
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|scsibus_data
modifier|*
name|scsi_alloc_bus
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_probe_bus
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_probe_busses
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|errval
name|scsi_start_unit
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|scsi_stop_unit
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32_t
name|eject
parameter_list|,
name|u_int32_t
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
name|void
name|scsi_user_done
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|errval
name|scsi_scsi_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|,
expr|struct
name|scsi_generic
operator|*
operator|,
name|u_int32_t
operator|,
name|u_char
operator|*
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|,
expr|struct
name|buf
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_do_ioctl
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|addr
operator|,
name|int
name|mode
operator|,
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|scsi_link
modifier|*
name|scsi_link_get
name|__P
argument_list|(
operator|(
name|int
name|bus
operator|,
name|int
name|targ
operator|,
name|int
name|lun
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|scsi_dev_lookup
name|__P
argument_list|(
operator|(
name|int
argument_list|(
argument|*opener
argument_list|)
operator|(
name|dev_t
name|dev
operator|,
name|int
name|flags
operator|,
name|int
name|fmt
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_opened_ok
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|flag
operator|,
name|int
name|type
operator|,
expr|struct
name|scsi_link
operator|*
name|sc_link
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|scsi_set_bus
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|scsi_link
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|scsi_sense_desc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_sense_print
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_scsi_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_uto3b
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|scsi_3btou
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int32_t
name|scsi_3btoi
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_uto4b
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|scsi_4btou
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_uto2b
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|scsi_2btou
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sc_print_addr
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sc_print_start
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sc_print_finish
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_device_register
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_device
operator|*
name|sd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_configure_start
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_configure_finish
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ukinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SCSI_2_DEF
end_ifdef

begin_function_decl
name|errval
name|scsi_change_def
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_define
define|#
directive|define
name|SCSI_EXTERNALLEN
value|(sizeof(struct scsi_link))
end_define

begin_comment
comment|/* XXX This belongs in a tape file.  */
end_comment

begin_comment
comment|/********************************************************************** 			from the scsi2 spec                 Value Tracks Density(bpi) Code Type  Reference     Note                 0x1     9       800       NRZI  R    X3.22-1983    2                 0x2     9      1600       PE    R    X3.39-1986    2                 0x3     9      6250       GCR   R    X3.54-1986    2                 0x5    4/9     8000       GCR   C    X3.136-1986   1                 0x6     9      3200       PE    R    X3.157-1987   2                 0x7     4      6400       IMFM  C    X3.116-1986   1                 0x8     4      8000       GCR   CS   X3.158-1986   1                 0x9    18     37871       GCR   C    X3B5/87-099   2                 0xA    22      6667       MFM   C    X3B5/86-199   1                 0xB     4      1600       PE    C    X3.56-1986    1                 0xC    24     12690       GCR   C    HI-TC1        1,5                 0xD    24     25380       GCR   C    HI-TC2        1,5                 0xF    15     10000       GCR   C    QIC-120       1,5                 0x10   18     10000       GCR   C    QIC-150       1,5                 0x11   26     16000       GCR   C    QIC-320(525?) 1,5                 0x12   30     51667       RLL   C    QIC-1350      1,5                 0x13    1     61000       DDS   CS    X3B5/88-185A 4                 0x14    1     43245       RLL   CS    X3.202-1991  4                 0x15    1     45434       RLL   CS    ECMA TC17    4                 0x16   48     10000       MFM   C     X3.193-1990  1                 0x17   48     42500       MFM   C     X3B5/91-174  1                  where Code means:                 NRZI Non Return to Zero, change on ones                 GCR  Group Code Recording                 PE   Phase Encoded                 IMFM Inverted Modified Frequency Modulation                 MFM  Modified Frequency Modulation                 DDS  Dat Data Storage                 RLL  Run Length Encoding                  where Type means:                 R    Real-to-Real                 C    Cartridge                 CS   cassette                  where Notes means:                 1    Serial Recorded                 2    Parallel Recorded                 3    Old format know as QIC-11                 4    Helical Scan                 5    Not ANSI standard, rather industry standard.  ********************************************************************/
end_comment

begin_define
define|#
directive|define
name|HALFINCH_800
value|0x01
end_define

begin_define
define|#
directive|define
name|HALFINCH_1600
value|0x02
end_define

begin_define
define|#
directive|define
name|HALFINCH_6250
value|0x03
end_define

begin_define
define|#
directive|define
name|QIC_11
value|0x04
end_define

begin_comment
comment|/* from Archive 150S Theory of Op. XXX	*/
end_comment

begin_define
define|#
directive|define
name|QIC_24
value|0x05
end_define

begin_comment
comment|/* may be bad, works for CIPHER ST150S XXX */
end_comment

begin_define
define|#
directive|define
name|QIC_120
value|0x0f
end_define

begin_define
define|#
directive|define
name|QIC_150
value|0x10
end_define

begin_define
define|#
directive|define
name|QIC_320
value|0x11
end_define

begin_define
define|#
directive|define
name|QIC_525
value|0x11
end_define

begin_define
define|#
directive|define
name|QIC_1320
value|0x12
end_define

begin_define
define|#
directive|define
name|DDS
value|0x13
end_define

begin_define
define|#
directive|define
name|DAT_1
value|0x13
end_define

begin_define
define|#
directive|define
name|QIC_3080
value|0x29
end_define

begin_comment
comment|/* XXX (dufault@hda.com) This is used only by "su" and "sctarg".  * The minor number field conflicts with the disk slice code,  * and so it is tough to access the disks through the "su" device.  */
end_comment

begin_comment
comment|/* Device number fields:  *  * NON-FIXED SCSI devices:  *  * ?FC? ???? ???? ???? MMMMMMMM mmmmmmmm  *  * F: Fixed device (nexus in number): must be 0.  * C: Control device; only user mode ioctl is supported.  * ?: Don't know; those bits didn't use to exist, currently always 0.  * M: Major device number.  * m: Old style minor device number.  *  * FIXED SCSI devices:  *  * XXX Conflicts with the slice code.  Maybe the slice code can be  * changed to respect the F bit?  *  * ?FC? ?BBB TTTT ?LLL MMMMMMMM mmmmmmmm  *  * F: Fixed device (nexus in number); must be 1.  * C: Control device; only user mode ioctl is supported.  * B: SCSI bus  * T: SCSI target ID  * L: Logical unit  * M: Major device number  * m: Old style minor device number.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_FIXED_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SCSI_FIXED
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& SCSI_FIXED_MASK))
end_define

begin_define
define|#
directive|define
name|SCSI_CONTROL_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SCSI_CONTROL
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& SCSI_CONTROL_MASK))
end_define

begin_define
define|#
directive|define
name|SCSI_BUS
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& 0x07000000)>> 24)
end_define

begin_define
define|#
directive|define
name|SCSI_ID
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& 0x00F00000)>> 20)
end_define

begin_define
define|#
directive|define
name|SCSI_LUN
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& 0x00070000)>> 16)
end_define

begin_define
define|#
directive|define
name|SCSI_MKFIXED
parameter_list|(
name|B
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|)
value|( \          ((B)<< 24) | \          ((T)<< 20) | \          ((L)<< 16) | \          (P) | \          SCSI_FIXED_MASK )
end_define

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

