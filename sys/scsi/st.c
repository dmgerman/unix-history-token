begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)(now julian@DIALix.oz.au)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * $Id: st.c,v 1.38 1995/07/16 09:13:14 gibbs Exp $  */
end_comment

begin_comment
comment|/*  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  * major changes by Julian Elischer (julian@jules.dialix.oz.au) May 1993  */
end_comment

begin_comment
comment|/*  * To do:  * work out some better way of guessing what a good timeout is going  * to be depending on whether we expect to retension or not.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/mtio.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_tape.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<sys/devconf.h>
end_include

begin_decl_stmt
name|u_int32
name|ststrats
decl_stmt|,
name|stqueues
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defines for device specific stuff */
end_comment

begin_define
define|#
directive|define
name|PAGE_0_SENSE_DATA_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|DEF_FIXED_BSIZE
value|512
end_define

begin_define
define|#
directive|define
name|ST_RETRIES
value|4
end_define

begin_comment
comment|/* only on non IO commands */
end_comment

begin_define
define|#
directive|define
name|STUNIT
parameter_list|(
name|DEV
parameter_list|)
value|((minor(DEV)&0xF0)>> 4)
end_define

begin_comment
comment|/* 4 bit unit.  */
end_comment

begin_define
define|#
directive|define
name|STSETUNIT
parameter_list|(
name|DEV
parameter_list|,
name|U
parameter_list|)
value|makedev(major(DEV), ((U)<< 4))
end_define

begin_define
define|#
directive|define
name|MODE
parameter_list|(
name|z
parameter_list|)
value|(  (minor(z)& 0x03) )
end_define

begin_define
define|#
directive|define
name|DSTY
parameter_list|(
name|z
parameter_list|)
value|( ((minor(z)>> 2)& 0x03) )
end_define

begin_define
define|#
directive|define
name|CTLMODE
value|3
end_define

begin_define
define|#
directive|define
name|IS_CTLMODE
parameter_list|(
name|DEV
parameter_list|)
value|(MODE(DEV) == CTLMODE)
end_define

begin_define
define|#
directive|define
name|SCSI_2_MAX_DENSITY_CODE
value|0x17
end_define

begin_comment
comment|/* maximum density code specified 					 * in SCSI II spec. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_SCSICONF
end_ifndef

begin_comment
comment|/*  * Define various devices that we know mis-behave in some way,  * and note how they are bad, so we can correct for them  */
end_comment

begin_struct
struct|struct
name|modes
block|{
name|u_int32
name|blksiz
decl_stmt|;
name|u_int32
name|quirks
decl_stmt|;
comment|/* same definitions as in rogues */
name|char
name|density
decl_stmt|;
name|char
name|spare
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rogues
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|manu
decl_stmt|;
name|char
modifier|*
name|model
decl_stmt|;
name|char
modifier|*
name|version
decl_stmt|;
name|u_int32
name|quirks
decl_stmt|;
comment|/* valid for all modes */
name|struct
name|modes
name|modes
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* define behaviour codes (quirks) */
end_comment

begin_define
define|#
directive|define
name|ST_Q_NEEDS_PAGE_0
value|0x00001
end_define

begin_define
define|#
directive|define
name|ST_Q_FORCE_FIXED_MODE
value|0x00002
end_define

begin_define
define|#
directive|define
name|ST_Q_FORCE_VAR_MODE
value|0x00004
end_define

begin_define
define|#
directive|define
name|ST_Q_SNS_HLP
value|0x00008
end_define

begin_comment
comment|/* must do READ for good MODE SENSE */
end_comment

begin_define
define|#
directive|define
name|ST_Q_IGNORE_LOADS
value|0x00010
end_define

begin_define
define|#
directive|define
name|ST_Q_BLKSIZ
value|0x00020
end_define

begin_comment
comment|/* variable-block media_blksiz> 0 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|rogues
name|gallery
index|[]
init|=
comment|/* ends with an all-null entry */
block|{
block|{
literal|"Such an old device "
block|,
literal|"pre-scsi"
block|,
literal|" unknown model  "
block|,
literal|"????"
block|,
literal|0
block|,
block|{
block|{
literal|512
block|,
name|ST_Q_FORCE_FIXED_MODE
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|512
block|,
name|ST_Q_FORCE_FIXED_MODE
block|,
name|QIC_24
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|0
block|,
name|ST_Q_FORCE_VAR_MODE
block|,
name|HALFINCH_1600
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
name|ST_Q_FORCE_VAR_MODE
block|,
name|HALFINCH_6250
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
literal|"Tandberg tdc3600"
block|,
literal|"TANDBERG"
block|,
literal|" TDC 3600"
block|,
literal|"????"
block|,
name|ST_Q_NEEDS_PAGE_0
block|,
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|0
block|,
name|ST_Q_FORCE_VAR_MODE
block|,
name|QIC_525
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_150
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_120
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
literal|"Rev 5 of the Archive 2525"
block|,
literal|"ARCHIVE "
block|,
literal|"VIPER 2525 25462"
block|,
literal|"-005"
block|,
literal|0
block|,
block|{
block|{
literal|0
block|,
name|ST_Q_SNS_HLP
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|0
block|,
name|ST_Q_SNS_HLP
block|,
name|QIC_525
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_150
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_120
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
literal|"Archive  Viper 150"
block|,
literal|"ARCHIVE "
block|,
literal|"VIPER 150"
block|,
literal|"????"
block|,
name|ST_Q_NEEDS_PAGE_0
block|,
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_150
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_120
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_24
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
literal|"Wangtek 5525ES"
block|,
literal|"WANGTEK "
block|,
literal|"5525ES SCSI REV7"
block|,
literal|"????"
block|,
literal|0
block|,
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|0
block|,
name|ST_Q_BLKSIZ
block|,
name|QIC_525
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_150
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
literal|0
block|,
name|QIC_120
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
literal|"WangDAT model 1300"
block|,
literal|"WangDAT "
block|,
literal|"Model 1300"
block|,
literal|"????"
block|,
literal|0
block|,
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* minor  0,1,2,3 */
block|{
literal|512
block|,
name|ST_Q_FORCE_FIXED_MODE
block|,
literal|0x13
block|}
block|,
comment|/* minor  4,5,6,7 */
block|{
literal|1024
block|,
name|ST_Q_FORCE_FIXED_MODE
block|,
literal|0x13
block|}
block|,
comment|/* minor  8,9,10,11 */
block|{
literal|0
block|,
name|ST_Q_FORCE_VAR_MODE
block|,
literal|0x13
block|}
comment|/* minor  12,13,14,15 */
block|}
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_SCSICONF */
end_comment

begin_decl_stmt
name|errval
name|st_space
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|int32
name|number
operator|,
name|u_int32
name|what
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_rewind
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|boolean
name|immed
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_erase
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|boolean
name|immed
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|errval
name|st_mode_sense
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|u_int32
name|flags
operator|,
expr|\ 	struct
name|tape_pages
operator|*
name|page
operator|,
name|u_int32
name|pagelen
operator|,
name|u_int32
name|pagecode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_decide_mode
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|boolean
name|first_read
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_rd_blk_lim
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_touch_tape
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_write_filemarks
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|int32
name|number
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_load
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|u_int32
name|type
operator|,
name|u_int32
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_mode_select
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|u_int32
name|flags
operator|,
expr|\ 	struct
name|tape_pages
operator|*
name|page
operator|,
name|u_int32
name|pagelen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errval
name|st_comp
name|__P
argument_list|(
operator|(
name|u_int32
name|unit
operator|,
name|u_int32
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ststrategy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|st_chkeod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ststart
parameter_list|(
name|u_int32
name|unit
parameter_list|,
name|u_int32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_unmount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|errval
name|st_mount_tape
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_loadquirks
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_SCSICONF
end_ifndef

begin_function_decl
name|void
name|st_identify_drive
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|errval
name|st_interpret_sense
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ESUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|NOEJECT
value|0
end_define

begin_define
define|#
directive|define
name|EJECT
value|1
end_define

begin_struct
struct|struct
name|scsi_data
block|{
comment|/*--------------------present operating parameters, flags etc.----------------*/
name|u_int32
name|flags
decl_stmt|;
comment|/* see below                          */
name|u_int32
name|blksiz
decl_stmt|;
comment|/* blksiz we are using                */
name|u_int32
name|density
decl_stmt|;
comment|/* present density                    */
name|u_int32
name|comp
decl_stmt|;
comment|/* present compression mode           */
name|u_int32
name|quirks
decl_stmt|;
comment|/* quirks for the open mode           */
name|u_int32
name|last_dsty
decl_stmt|;
comment|/* last density openned               */
comment|/*--------------------parameters reported by the device ----------------------*/
name|u_int32
name|blkmin
decl_stmt|;
comment|/* min blk size                       */
name|u_int32
name|blkmax
decl_stmt|;
comment|/* max blk size                       */
ifndef|#
directive|ifndef
name|NEW_SCSICONF
name|struct
name|rogues
modifier|*
name|rogues
decl_stmt|;
comment|/* if we have a rogue entry           */
endif|#
directive|endif
comment|/*--------------------parameters reported by the device for this media--------*/
name|u_int32
name|numblks
decl_stmt|;
comment|/* nominal blocks capacity            */
name|u_int32
name|media_blksiz
decl_stmt|;
comment|/* 0 if not ST_FIXEDBLOCKS            */
name|u_int32
name|media_density
decl_stmt|;
comment|/* this is what it said when asked    */
comment|/*--------------------quirks for the whole drive------------------------------*/
name|u_int32
name|drive_quirks
decl_stmt|;
comment|/* quirks of this drive               */
comment|/*--------------------How we should set up when openning each minor device----*/
ifdef|#
directive|ifdef
name|NEW_SCSICONF
name|st_modes
name|modes
decl_stmt|;
comment|/* plus more for each mode            */
else|#
directive|else
name|struct
name|modes
name|modes
index|[
literal|4
index|]
decl_stmt|;
comment|/* plus more for each mode            */
endif|#
directive|endif
name|u_int8
name|modeflags
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags for the modes                */
define|#
directive|define
name|DENSITY_SET_BY_USER
value|0x01
define|#
directive|define
name|DENSITY_SET_BY_QUIRK
value|0x02
define|#
directive|define
name|BLKSIZE_SET_BY_USER
value|0x04
define|#
directive|define
name|BLKSIZE_SET_BY_QUIRK
value|0x08
define|#
directive|define
name|COMPRES_SET_BY_USER
value|0x10
define|#
directive|define
name|COMPRES_SET_BY_QUIRK
value|0x20
comment|/*--------------------storage for sense data returned by the drive------------*/
name|unsigned
name|char
name|saved_page0
index|[
name|PAGE_0_SENSE_DATA_SIZE
index|]
decl_stmt|;
comment|/* 					 * additional sense data needed 					 * for mode sense/select. 					 */
name|struct
name|buf
modifier|*
name|buf_queue
decl_stmt|;
comment|/* the queue of pending IO operations */
name|struct
name|scsi_xfer
name|scsi_xfer
decl_stmt|;
comment|/* scsi xfer struct for this drive */
name|u_int32
name|xfer_block_wait
decl_stmt|;
comment|/* is a process waiting? */
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|stunit
parameter_list|(
name|dev_t
name|dev
parameter_list|)
block|{
return|return
name|STUNIT
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|dev_t
name|stsetunit
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|unit
parameter_list|)
block|{
return|return
name|STSETUNIT
argument_list|(
name|dev
argument_list|,
name|unit
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|errval
name|st_open
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
end_function_decl

begin_function_decl
name|errval
name|st_ioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|flag
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
end_function_decl

begin_function_decl
name|errval
name|st_close
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
end_function_decl

begin_function_decl
name|void
name|st_strategy
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
end_function_decl

begin_macro
name|SCSI_DEVICE_ENTRIES
argument_list|(
argument|st
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|scsi_device
name|st_switch
init|=
block|{
name|st_interpret_sense
block|,
comment|/* check errors with us first */
name|ststart
block|,
comment|/* we have a queue, and this is how we service it */
name|NULL
block|,
name|NULL
block|,
comment|/* use the default 'done' routine */
literal|"st"
block|,
literal|0
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
literal|0
block|,
comment|/* Link flags */
name|stattach
block|,
literal|"Sequential-Access"
block|,
name|stopen
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|scsi_data
argument_list|)
block|,
name|T_SEQUENTIAL
block|,
name|stunit
block|,
name|stsetunit
block|,
name|st_open
block|,
name|st_ioctl
block|,
name|st_close
block|,
name|st_strategy
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ST_INITIALIZED
value|0x01
end_define

begin_define
define|#
directive|define
name|ST_INFO_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|ST_OPEN
value|0x04
end_define

begin_define
define|#
directive|define
name|ST_BLOCK_SET
value|0x08
end_define

begin_comment
comment|/* block size, mode set by ioctl      */
end_comment

begin_define
define|#
directive|define
name|ST_WRITTEN
value|0x10
end_define

begin_comment
comment|/* data have been written, EOD needed */
end_comment

begin_define
define|#
directive|define
name|ST_FIXEDBLOCKS
value|0x20
end_define

begin_define
define|#
directive|define
name|ST_AT_FILEMARK
value|0x40
end_define

begin_define
define|#
directive|define
name|ST_EIO_PENDING
value|0x80
end_define

begin_comment
comment|/* we couldn't report it then (had data) */
end_comment

begin_define
define|#
directive|define
name|ST_NEW_MOUNT
value|0x100
end_define

begin_comment
comment|/* still need to decide mode              */
end_comment

begin_define
define|#
directive|define
name|ST_READONLY
value|0x200
end_define

begin_comment
comment|/* st_mode_sense says write protected */
end_comment

begin_define
define|#
directive|define
name|ST_FM_WRITTEN
value|0x400
end_define

begin_comment
comment|/* 				 * EOF file mark written  -- used with 				 * ~ST_WRITTEN to indicate that multiple file 				 * marks have been written 				 */
end_comment

begin_define
define|#
directive|define
name|ST_BLANK_READ
value|0x800
end_define

begin_comment
comment|/* BLANK CHECK encountered already */
end_comment

begin_define
define|#
directive|define
name|ST_2FM_AT_EOD
value|0x1000
end_define

begin_comment
comment|/* write 2 file marks at EOD */
end_comment

begin_define
define|#
directive|define
name|ST_MOUNTED
value|0x2000
end_define

begin_comment
comment|/* Device is presently mounted */
end_comment

begin_define
define|#
directive|define
name|ST_SENSE_READ
value|0x4000
end_define

begin_comment
comment|/* mode sense read from drive */
end_comment

begin_define
define|#
directive|define
name|ST_PER_ACTION
value|(ST_AT_FILEMARK | ST_EIO_PENDING | ST_BLANK_READ)
end_define

begin_define
define|#
directive|define
name|ST_PER_MOUNT
value|(ST_INFO_VALID | ST_BLOCK_SET | ST_WRITTEN | \ 			ST_FIXEDBLOCKS | ST_READONLY | \ 			ST_FM_WRITTEN | ST_2FM_AT_EOD | ST_PER_ACTION)
end_define

begin_function
specifier|static
name|int
name|st_externalize
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|kern_devconf
modifier|*
name|kdc
parameter_list|,
name|void
modifier|*
name|userp
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
return|return
name|scsi_externalize
argument_list|(
name|SCSI_LINK
argument_list|(
operator|&
name|st_switch
argument_list|,
name|kdc
operator|->
name|kdc_unit
argument_list|)
argument_list|,
name|userp
argument_list|,
operator|&
name|len
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|kern_devconf
name|kdc_st_template
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* filled in by dev_attach */
literal|"st"
block|,
literal|0
block|,
name|MDDC_SCSI
block|,
name|st_externalize
block|,
literal|0
block|,
name|scsi_goaway
block|,
name|SCSI_EXTERNALLEN
block|,
operator|&
name|kdc_scbus0
block|,
comment|/* XXX parent */
literal|0
block|,
comment|/* parentdata */
name|DC_UNKNOWN
block|,
comment|/* not supported */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|st_registerdev
parameter_list|(
name|int
name|unit
parameter_list|)
block|{
name|struct
name|kern_devconf
modifier|*
name|kdc
decl_stmt|;
name|MALLOC
argument_list|(
name|kdc
argument_list|,
expr|struct
name|kern_devconf
operator|*
argument_list|,
sizeof|sizeof
expr|*
name|kdc
argument_list|,
name|M_TEMP
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|kdc
condition|)
return|return;
operator|*
name|kdc
operator|=
name|kdc_st_template
expr_stmt|;
name|kdc
operator|->
name|kdc_unit
operator|=
name|unit
expr_stmt|;
name|kdc
operator|->
name|kdc_description
operator|=
name|st_switch
operator|.
name|desc
expr_stmt|;
name|dev_attach
argument_list|(
name|kdc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * The routine called by the low level scsi routine when it discovers  * a device suitable for this driver  */
end_comment

begin_function
name|errval
name|stattach
parameter_list|(
name|struct
name|scsi_link
modifier|*
name|sc_link
parameter_list|)
block|{
name|u_int32
name|unit
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
init|=
name|sc_link
operator|->
name|sd
decl_stmt|;
name|unit
operator|=
name|sc_link
operator|->
name|dev_unit
expr_stmt|;
comment|/* 	 * Check if the drive is a known criminal and take 	 * Any steps needed to bring it into line 	 */
ifdef|#
directive|ifdef
name|NEW_SCSICONF
name|st_loadquirks
argument_list|(
name|sc_link
argument_list|)
expr_stmt|;
else|#
directive|else
name|st_identify_drive
argument_list|(
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Use the subdriver to request information regarding 	 * the drive. We cannot use interrupts yet, so the 	 * request must specify this. 	 */
if|if
condition|(
name|st_mode_sense
argument_list|(
name|unit
argument_list|,
name|SCSI_NOSLEEP
operator||
name|SCSI_NOMASK
operator||
name|SCSI_SILENT
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"drive offline"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"density code 0x%lx, "
argument_list|,
name|st
operator|->
name|media_density
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|scsi_test_unit_ready
argument_list|(
name|sc_link
argument_list|,
name|SCSI_NOSLEEP
operator||
name|SCSI_NOMASK
operator||
name|SCSI_SILENT
argument_list|)
condition|)
block|{
if|if
condition|(
name|st
operator|->
name|media_blksiz
condition|)
block|{
name|printf
argument_list|(
literal|"%ld-byte"
argument_list|,
name|st
operator|->
name|media_blksiz
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"variable"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" blocks, write-%s"
argument_list|,
operator|(
name|st
operator|->
name|flags
operator|&
name|ST_READONLY
operator|)
condition|?
literal|"protected"
else|:
literal|"enabled"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" drive empty"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Set up the buf queue for this device 	 */
name|st
operator|->
name|buf_queue
operator|=
literal|0
expr_stmt|;
name|st
operator|->
name|flags
operator||=
name|ST_INITIALIZED
expr_stmt|;
name|st_registerdev
argument_list|(
name|unit
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_SCSICONF
end_ifndef

begin_comment
comment|/*  * Use the inquiry routine in 'scsi_base' to get drive info so we can  * Further tailor our behaviour.  */
end_comment

begin_function
name|void
name|st_identify_drive
parameter_list|(
name|unit
parameter_list|)
name|u_int32
name|unit
decl_stmt|;
block|{
name|struct
name|scsi_link
modifier|*
name|sc_link
init|=
name|SCSI_LINK
argument_list|(
operator|&
name|st_switch
argument_list|,
name|unit
argument_list|)
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
init|=
name|sc_link
operator|->
name|sd
decl_stmt|;
name|struct
name|rogues
modifier|*
name|finger
decl_stmt|;
name|char
name|manu
index|[
literal|32
index|]
decl_stmt|;
name|char
name|model
index|[
literal|32
index|]
decl_stmt|;
name|char
name|model2
index|[
literal|32
index|]
decl_stmt|;
name|char
name|version
index|[
literal|32
index|]
decl_stmt|;
name|u_int32
name|model_len
decl_stmt|;
name|struct
name|scsi_inquiry_data
modifier|*
name|inqbuf
init|=
operator|&
name|sc_link
operator|->
name|inqbuf
decl_stmt|;
comment|/* 	 * Get the device type information 	 */
if|if
condition|(
name|scsi_inquire
argument_list|(
name|sc_link
argument_list|,
name|inqbuf
argument_list|,
name|SCSI_NOSLEEP
operator||
name|SCSI_NOMASK
operator||
name|SCSI_SILENT
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"st%ld: couldn't get device type, using default\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|inqbuf
operator|->
name|version
operator|&
name|SID_ANSII
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * If not advanced enough, use default values 		 */
name|strncpy
argument_list|(
name|manu
argument_list|,
literal|"pre-scsi"
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|manu
index|[
literal|8
index|]
operator|=
literal|0
expr_stmt|;
name|strncpy
argument_list|(
name|model
argument_list|,
literal|" unknown model  "
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|model
index|[
literal|16
index|]
operator|=
literal|0
expr_stmt|;
name|strncpy
argument_list|(
name|version
argument_list|,
literal|"????"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|version
index|[
literal|4
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|strncpy
argument_list|(
name|manu
argument_list|,
name|inqbuf
operator|->
name|vendor
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|manu
index|[
literal|8
index|]
operator|=
literal|0
expr_stmt|;
name|strncpy
argument_list|(
name|model
argument_list|,
name|inqbuf
operator|->
name|product
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|model
index|[
literal|16
index|]
operator|=
literal|0
expr_stmt|;
name|strncpy
argument_list|(
name|version
argument_list|,
name|inqbuf
operator|->
name|revision
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|version
index|[
literal|4
index|]
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 * Load the parameters for this kind of device, so we 	 * treat it as appropriate for each operating mode. 	 * Only check the number of characters in the array's 	 * model entry, not the entire model string returned. 	 */
name|finger
operator|=
name|gallery
expr_stmt|;
while|while
condition|(
name|finger
operator|->
name|name
condition|)
block|{
name|model_len
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|finger
operator|->
name|model
index|[
name|model_len
index|]
operator|&&
operator|(
name|model_len
operator|<
literal|32
operator|)
condition|)
block|{
name|model2
index|[
name|model_len
index|]
operator|=
name|model
index|[
name|model_len
index|]
expr_stmt|;
name|model_len
operator|++
expr_stmt|;
block|}
name|model2
index|[
name|model_len
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|strcmp
argument_list|(
name|manu
argument_list|,
name|finger
operator|->
name|manu
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|model2
argument_list|,
name|finger
operator|->
name|model
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
literal|"????????????????"
argument_list|,
name|finger
operator|->
name|model
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|version
argument_list|,
name|finger
operator|->
name|version
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
literal|"????"
argument_list|,
name|finger
operator|->
name|version
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"st%ld: %s is a known rogue\n"
argument_list|,
name|unit
argument_list|,
name|finger
operator|->
name|name
argument_list|)
expr_stmt|;
name|st
operator|->
name|rogues
operator|=
name|finger
expr_stmt|;
name|st
operator|->
name|drive_quirks
operator|=
name|finger
operator|->
name|quirks
expr_stmt|;
name|st
operator|->
name|quirks
operator|=
name|finger
operator|->
name|quirks
expr_stmt|;
comment|/*start value */
name|st_loadquirks
argument_list|(
name|sc_link
argument_list|)
expr_stmt|;
break|break;
block|}
else|else
block|{
name|finger
operator|++
expr_stmt|;
comment|/* go to next suspect */
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_SCSICONF */
end_comment

begin_comment
comment|/*  * initialise the subdevices to the default (QUIRK) state.  * this will remove any setting made by the system operator or previous  * operations.  */
end_comment

begin_function
name|void
name|st_loadquirks
parameter_list|(
name|sc_link
parameter_list|)
name|struct
name|scsi_link
modifier|*
name|sc_link
decl_stmt|;
block|{
name|struct
name|scsi_data
modifier|*
name|st
init|=
name|sc_link
operator|->
name|sd
decl_stmt|;
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|NEW_SCSICONF
name|struct
name|st_mode
modifier|*
name|mode
decl_stmt|;
name|struct
name|st_mode
modifier|*
name|mode2
decl_stmt|;
name|mode
operator|=
operator|(
expr|struct
name|st_mode
operator|*
operator|)
name|sc_link
operator|->
name|devmodes
expr_stmt|;
if|if
condition|(
operator|!
name|mode
condition|)
return|return;
name|st
operator|->
name|quirks
operator|=
name|st
operator|->
name|drive_quirks
operator|=
name|sc_link
operator|->
name|quirks
expr_stmt|;
else|#
directive|else
name|struct
name|modes
modifier|*
name|mode
decl_stmt|;
name|struct
name|modes
modifier|*
name|mode2
decl_stmt|;
if|if
condition|(
operator|!
name|st
operator|->
name|rogues
condition|)
return|return;
name|mode
operator|=
name|st
operator|->
name|rogues
operator|->
name|modes
expr_stmt|;
endif|#
directive|endif
name|mode2
operator|=
name|st
operator|->
name|modes
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
block|{
name|bzero
argument_list|(
name|mode2
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|mode2
argument_list|)
argument_list|)
expr_stmt|;
name|st
operator|->
name|modeflags
index|[
name|i
index|]
operator|&=
operator|~
operator|(
name|BLKSIZE_SET_BY_QUIRK
operator||
name|DENSITY_SET_BY_QUIRK
operator||
name|BLKSIZE_SET_BY_USER
operator||
name|DENSITY_SET_BY_USER
operator|)
expr_stmt|;
if|if
condition|(
name|mode
operator|->
name|blksiz
operator|&&
operator|(
operator|(
name|mode
operator|->
name|quirks
operator||
name|st
operator|->
name|drive_quirks
operator|)
operator|&
operator|(
name|ST_Q_FORCE_FIXED_MODE
operator|)
operator|)
condition|)
block|{
name|mode2
operator|->
name|blksiz
operator|=
name|mode
operator|->
name|blksiz
expr_stmt|;
name|st
operator|->
name|modeflags
index|[
name|i
index|]
operator||=
name|BLKSIZE_SET_BY_QUIRK
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|(
name|mode
operator|->
name|quirks
operator||
name|st
operator|->
name|drive_quirks
operator|)
operator|&
name|ST_Q_FORCE_VAR_MODE
condition|)
block|{
name|mode2
operator|->
name|blksiz
operator|=
literal|0
expr_stmt|;
name|st
operator|->
name|modeflags
index|[
name|i
index|]
operator||=
name|BLKSIZE_SET_BY_QUIRK
expr_stmt|;
block|}
block|}
if|if
condition|(
name|mode
operator|->
name|density
condition|)
block|{
name|mode2
operator|->
name|density
operator|=
name|mode
operator|->
name|density
expr_stmt|;
name|st
operator|->
name|modeflags
index|[
name|i
index|]
operator||=
name|DENSITY_SET_BY_QUIRK
expr_stmt|;
block|}
name|mode
operator|++
expr_stmt|;
name|mode2
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * open the device.  */
end_comment

begin_function
name|errval
name|st_open
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
block|{
name|u_int32
name|unit
decl_stmt|,
name|mode
decl_stmt|,
name|dsty
decl_stmt|;
name|errval
name|errno
init|=
literal|0
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
decl_stmt|;
name|unit
operator|=
name|STUNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|mode
operator|=
name|MODE
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|dsty
operator|=
name|DSTY
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|st
operator|=
name|sc_link
operator|->
name|sd
expr_stmt|;
comment|/* 	 * Make sure the device has been initialised 	 */
if|if
condition|(
operator|(
name|st
operator|==
name|NULL
operator|)
operator|||
operator|(
operator|!
operator|(
name|st
operator|->
name|flags
operator|&
name|ST_INITIALIZED
operator|)
operator|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* 	 * Only allow one at a time 	 */
if|if
condition|(
name|st
operator|->
name|flags
operator|&
name|ST_OPEN
condition|)
block|{
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
comment|/* 	 * Throw out a dummy instruction to catch 'Unit attention 	 * errors (the error handling will invalidate all our 	 * device info if we get one, but otherwise, ignore it) 	 */
name|scsi_test_unit_ready
argument_list|(
name|sc_link
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
name|sc_link
operator|->
name|flags
operator||=
name|SDEV_OPEN
expr_stmt|;
comment|/* unit attn are now errors */
comment|/* 	 * If the mode is 3 (e.g. minor = 3,7,11,15) 	 * then the device has been openned to set defaults 	 * This mode does NOT ALLOW I/O, only ioctls. 	 * XXX: Where do we lock out I/O? 	 */
if|if
condition|(
name|IS_CTLMODE
argument_list|(
name|dev
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* 	 * Check that the device is ready to use (media loaded?) 	 * This time take notice of the return result 	 */
if|if
condition|(
operator|(
name|errno
operator|=
name|scsi_test_unit_ready
argument_list|(
name|sc_link
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
name|uprintf
argument_list|(
literal|"st%d: not ready\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|st_unmount
argument_list|(
name|unit
argument_list|,
name|NOEJECT
argument_list|)
expr_stmt|;
return|return
operator|(
name|errno
operator|)
return|;
block|}
comment|/* 	 * if it's a different mode, or if the media has been 	 * invalidated, unmount the tape from the previous 	 * session but continue with open processing 	 */
if|if
condition|(
operator|(
name|st
operator|->
name|last_dsty
operator|!=
name|dsty
operator|)
operator|||
operator|(
operator|!
operator|(
name|sc_link
operator|->
name|flags
operator|&
name|SDEV_MEDIA_LOADED
operator|)
operator|)
condition|)
block|{
name|st_unmount
argument_list|(
name|unit
argument_list|,
name|NOEJECT
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * If we are not mounted, then we should start a new 	 * mount session. 	 */
if|if
condition|(
operator|!
operator|(
name|st
operator|->
name|flags
operator|&
name|ST_MOUNTED
operator|)
condition|)
block|{
name|st_mount_tape
argument_list|(
name|dev
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|st
operator|->
name|last_dsty
operator|=
name|dsty
expr_stmt|;
block|}
comment|/* 	 * Make sure that a tape opened in write-only mode will have 	 * file marks written on it when closed, even if not written to. 	 * This is for SUN compatibility 	 */
if|if
condition|(
operator|(
name|flags
operator|&
name|O_ACCMODE
operator|)
operator|==
name|FWRITE
condition|)
name|st
operator|->
name|flags
operator||=
name|ST_WRITTEN
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB2
argument_list|,
operator|(
literal|"Open complete\n"
operator|)
argument_list|)
expr_stmt|;
name|st
operator|->
name|flags
operator||=
name|ST_OPEN
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * close the device.. only called if we are the LAST  * occurence of an open device  */
end_comment

begin_function
name|errval
name|st_close
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
block|{
name|unsigned
name|char
name|unit
decl_stmt|,
name|mode
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
decl_stmt|;
name|unit
operator|=
name|STUNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|mode
operator|=
name|MODE
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|st
operator|=
name|sc_link
operator|->
name|sd
expr_stmt|;
if|if
condition|(
operator|(
name|st
operator|->
name|flags
operator|&
operator|(
name|ST_WRITTEN
operator||
name|ST_FM_WRITTEN
operator|)
operator|)
operator|==
name|ST_WRITTEN
condition|)
name|st_write_filemarks
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|mode
operator|&
literal|0x3
condition|)
block|{
case|case
literal|0
case|:
case|case
literal|3
case|:
comment|/* for now */
name|st_unmount
argument_list|(
name|unit
argument_list|,
name|NOEJECT
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/*leave mounted unless media seems to have been removed */
if|if
condition|(
operator|!
operator|(
name|sc_link
operator|->
name|flags
operator|&
name|SDEV_MEDIA_LOADED
operator|)
condition|)
block|{
name|st_unmount
argument_list|(
name|unit
argument_list|,
name|NOEJECT
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
name|st_unmount
argument_list|(
name|unit
argument_list|,
name|EJECT
argument_list|)
expr_stmt|;
break|break;
block|}
name|sc_link
operator|->
name|flags
operator|&=
operator|~
name|SDEV_OPEN
expr_stmt|;
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_OPEN
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Start a new mount session.  * Copy in all the default parameters from the selected device mode.  * and try guess any that seem to be defaulted.  */
end_comment

begin_function
name|errval
name|st_mount_tape
parameter_list|(
name|dev
parameter_list|,
name|flags
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|u_int32
name|flags
decl_stmt|;
block|{
name|u_int32
name|unit
decl_stmt|,
name|mode
decl_stmt|,
name|dsty
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
decl_stmt|;
name|struct
name|scsi_link
modifier|*
name|sc_link
decl_stmt|;
name|errval
name|errno
init|=
literal|0
decl_stmt|;
name|unit
operator|=
name|STUNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|mode
operator|=
name|MODE
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|dsty
operator|=
name|DSTY
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc_link
operator|=
name|SCSI_LINK
argument_list|(
operator|&
name|st_switch
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|st
operator|=
name|sc_link
operator|->
name|sd
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|flags
operator|&
name|ST_MOUNTED
condition|)
return|return
literal|0
return|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB1
argument_list|,
operator|(
literal|"mounting\n "
operator|)
argument_list|)
expr_stmt|;
name|st
operator|->
name|flags
operator||=
name|ST_NEW_MOUNT
expr_stmt|;
name|st
operator|->
name|quirks
operator|=
name|st
operator|->
name|drive_quirks
operator||
name|st
operator|->
name|modes
index|[
name|dsty
index|]
operator|.
name|quirks
expr_stmt|;
comment|/* 	 * If the media is new, then make sure we give it a chance to 	 * to do a 'load' instruction. ( We assume it is new) 	 */
if|if
condition|(
operator|(
name|errno
operator|=
name|st_load
argument_list|(
name|unit
argument_list|,
name|LD_LOAD
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
return|return
operator|(
name|errno
operator|)
return|;
block|}
comment|/* 	 * Throw another dummy instruction to catch 	 * 'Unit attention' errors. Some drives appear to give 	 * these after doing a Load instruction. 	 * (noteably some DAT drives) 	 */
name|scsi_test_unit_ready
argument_list|(
name|sc_link
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
comment|/* 	 * Some devices can't tell you much until they have been 	 * asked to look at the media. This quirk does this. 	 */
if|if
condition|(
name|st
operator|->
name|quirks
operator|&
name|ST_Q_SNS_HLP
condition|)
block|{
if|if
condition|(
operator|(
name|errno
operator|=
name|st_touch_tape
argument_list|(
name|unit
argument_list|)
operator|)
condition|)
return|return
name|errno
return|;
block|}
comment|/* 	 * Load the physical device parameters 	 * loads: blkmin, blkmax 	 */
if|if
condition|(
operator|(
name|errno
operator|=
name|st_rd_blk_lim
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
return|return
name|errno
return|;
block|}
comment|/* 	 * Load the media dependent parameters 	 * includes: media_blksiz,media_density,numblks 	 * As we have a tape in, it should be reflected here. 	 * If not you may need the "quirk" above. 	 */
if|if
condition|(
operator|(
name|errno
operator|=
name|st_mode_sense
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
return|return
name|errno
return|;
block|}
comment|/* 	 * If we have gained a permanent density from somewhere, 	 * then use it in preference to the one supplied by 	 * default by the driver. 	 */
if|if
condition|(
name|st
operator|->
name|modeflags
index|[
name|dsty
index|]
operator|&
operator|(
name|DENSITY_SET_BY_QUIRK
operator||
name|DENSITY_SET_BY_USER
operator|)
condition|)
block|{
name|st
operator|->
name|density
operator|=
name|st
operator|->
name|modes
index|[
name|dsty
index|]
operator|.
name|density
expr_stmt|;
block|}
else|else
block|{
name|st
operator|->
name|density
operator|=
name|st
operator|->
name|media_density
expr_stmt|;
block|}
comment|/* 	 * If we have gained a permanent blocksize 	 * then use it in preference to the one supplied by 	 * default by the driver. 	 */
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_FIXEDBLOCKS
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|modeflags
index|[
name|dsty
index|]
operator|&
operator|(
name|BLKSIZE_SET_BY_QUIRK
operator||
name|BLKSIZE_SET_BY_USER
operator|)
condition|)
block|{
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|modes
index|[
name|dsty
index|]
operator|.
name|blksiz
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|blksiz
condition|)
block|{
name|st
operator|->
name|flags
operator||=
name|ST_FIXEDBLOCKS
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
operator|(
name|errno
operator|=
name|st_decide_mode
argument_list|(
name|unit
argument_list|,
name|FALSE
argument_list|)
operator|)
condition|)
block|{
return|return
name|errno
return|;
block|}
block|}
if|if
condition|(
operator|(
name|errno
operator|=
name|st_mode_select
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"st%ld: Cannot set selected mode"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
name|errno
return|;
block|}
name|scsi_prevent
argument_list|(
name|sc_link
argument_list|,
name|PR_PREVENT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* who cares if it fails? */
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_NEW_MOUNT
expr_stmt|;
name|st
operator|->
name|flags
operator||=
name|ST_MOUNTED
expr_stmt|;
name|sc_link
operator|->
name|flags
operator||=
name|SDEV_MEDIA_LOADED
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * End the present mount session.  * Rewind, and optionally eject the tape.  * Reset various flags to indicate that all new  * operations require another mount operation  */
end_comment

begin_function
name|void
name|st_unmount
parameter_list|(
name|int
name|unit
parameter_list|,
name|boolean
name|eject
parameter_list|)
block|{
name|struct
name|scsi_link
modifier|*
name|sc_link
init|=
name|SCSI_LINK
argument_list|(
operator|&
name|st_switch
argument_list|,
name|unit
argument_list|)
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
init|=
name|sc_link
operator|->
name|sd
decl_stmt|;
name|int32
name|nmarks
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|st
operator|->
name|flags
operator|&
name|ST_MOUNTED
operator|)
condition|)
return|return;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB1
argument_list|,
operator|(
literal|"unmounting\n"
operator|)
argument_list|)
expr_stmt|;
name|st_chkeod
argument_list|(
name|unit
argument_list|,
name|FALSE
argument_list|,
operator|&
name|nmarks
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
name|st_rewind
argument_list|(
name|unit
argument_list|,
name|FALSE
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
name|scsi_prevent
argument_list|(
name|sc_link
argument_list|,
name|PR_ALLOW
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|eject
condition|)
block|{
name|st_load
argument_list|(
name|unit
argument_list|,
name|LD_UNLOAD
argument_list|,
name|SCSI_SILENT
argument_list|)
expr_stmt|;
block|}
name|st
operator|->
name|flags
operator|&=
operator|~
operator|(
name|ST_MOUNTED
operator||
name|ST_NEW_MOUNT
operator|)
expr_stmt|;
name|sc_link
operator|->
name|flags
operator|&=
operator|~
name|SDEV_MEDIA_LOADED
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Given all we know about the device, media, mode, 'quirks' and  * initial operation, make a decision as to how we should be set  * to run (regarding blocking and EOD marks)  */
end_comment

begin_function
name|errval
name|st_decide_mode
parameter_list|(
name|unit
parameter_list|,
name|first_read
parameter_list|)
name|u_int32
name|unit
decl_stmt|;
name|boolean
name|first_read
decl_stmt|;
block|{
name|struct
name|scsi_link
modifier|*
name|sc_link
init|=
name|SCSI_LINK
argument_list|(
operator|&
name|st_switch
argument_list|,
name|unit
argument_list|)
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
init|=
name|sc_link
operator|->
name|sd
decl_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB2
argument_list|,
operator|(
literal|"starting block mode decision\n"
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * If the user hasn't already specified fixed or variable-length 	 * blocks and the block size (zero if variable-length), we'll 	 * have to try to figure them out ourselves. 	 * 	 * Our first shot at a method is, "The quirks made me do it!" 	 */
switch|switch
condition|(
call|(
name|int
call|)
argument_list|(
name|st
operator|->
name|quirks
operator|&
operator|(
name|ST_Q_FORCE_FIXED_MODE
operator||
name|ST_Q_FORCE_VAR_MODE
operator|)
argument_list|)
condition|)
block|{
case|case
operator|(
name|ST_Q_FORCE_FIXED_MODE
operator||
name|ST_Q_FORCE_VAR_MODE
operator|)
case|:
name|printf
argument_list|(
literal|"st%ld: bad quirks\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
case|case
name|ST_Q_FORCE_FIXED_MODE
case|:
comment|/*specified fixed, but not what size */
name|st
operator|->
name|flags
operator||=
name|ST_FIXEDBLOCKS
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|blkmin
operator|&&
operator|(
name|st
operator|->
name|blkmin
operator|==
name|st
operator|->
name|blkmax
operator|)
condition|)
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|blkmin
expr_stmt|;
elseif|else
if|if
condition|(
name|st
operator|->
name|media_blksiz
operator|>
literal|0
condition|)
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|media_blksiz
expr_stmt|;
else|else
name|st
operator|->
name|blksiz
operator|=
name|DEF_FIXED_BSIZE
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"Quirks force fixed mode(%ld)\n"
operator|,
name|st
operator|->
name|blksiz
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
case|case
name|ST_Q_FORCE_VAR_MODE
case|:
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_FIXEDBLOCKS
expr_stmt|;
name|st
operator|->
name|blksiz
operator|=
literal|0
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"Quirks force variable mode\n"
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
block|}
comment|/* 		 * If the drive can only handle fixed-length blocks and only at 		 * one size, perhaps we should just do that. 		 */
if|if
condition|(
name|st
operator|->
name|blkmin
operator|&&
operator|(
name|st
operator|->
name|blkmin
operator|==
name|st
operator|->
name|blkmax
operator|)
condition|)
block|{
name|st
operator|->
name|flags
operator||=
name|ST_FIXEDBLOCKS
expr_stmt|;
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|blkmin
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"blkmin == blkmax of %ld\n"
operator|,
name|st
operator|->
name|blkmin
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
block|}
comment|/* 	 * If the tape density mandates (or even suggests) use of fixed 	 * or variable-length blocks, comply. 	 */
switch|switch
condition|(
operator|(
name|int
operator|)
name|st
operator|->
name|density
condition|)
block|{
case|case
name|HALFINCH_800
case|:
case|case
name|HALFINCH_1600
case|:
case|case
name|HALFINCH_6250
case|:
case|case
name|DDS
case|:
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_FIXEDBLOCKS
expr_stmt|;
name|st
operator|->
name|blksiz
operator|=
literal|0
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"density specified variable\n"
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
case|case
name|QIC_11
case|:
case|case
name|QIC_24
case|:
case|case
name|QIC_120
case|:
case|case
name|QIC_150
case|:
case|case
name|QIC_525
case|:
case|case
name|QIC_1320
case|:
name|st
operator|->
name|flags
operator||=
name|ST_FIXEDBLOCKS
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|media_blksiz
operator|>
literal|0
condition|)
block|{
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|media_blksiz
expr_stmt|;
block|}
else|else
block|{
name|st
operator|->
name|blksiz
operator|=
name|DEF_FIXED_BSIZE
expr_stmt|;
block|}
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"density specified fixed\n"
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
block|}
comment|/* 	 * If we're about to read the tape, perhaps we should choose 	 * fixed or variable-length blocks and block size according to 	 * what the drive found on the tape. 	 */
if|if
condition|(
name|first_read
operator|&&
operator|(
operator|!
operator|(
name|st
operator|->
name|quirks
operator|&
name|ST_Q_BLKSIZ
operator|)
operator|||
operator|(
name|st
operator|->
name|media_blksiz
operator|==
literal|0
operator|)
operator|||
operator|(
name|st
operator|->
name|media_blksiz
operator|==
name|DEF_FIXED_BSIZE
operator|)
operator|||
operator|(
name|st
operator|->
name|media_blksiz
operator|==
literal|1024
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|st
operator|->
name|media_blksiz
operator|==
literal|0
condition|)
block|{
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_FIXEDBLOCKS
expr_stmt|;
block|}
else|else
block|{
name|st
operator|->
name|flags
operator||=
name|ST_FIXEDBLOCKS
expr_stmt|;
block|}
name|st
operator|->
name|blksiz
operator|=
name|st
operator|->
name|media_blksiz
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"Used media_blksiz of %ld\n"
operator|,
name|st
operator|->
name|media_blksiz
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|done
goto|;
block|}
comment|/* 	 * We're getting no hints from any direction.  Choose variable- 	 * length blocks arbitrarily. 	 */
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_FIXEDBLOCKS
expr_stmt|;
name|st
operator|->
name|blksiz
operator|=
literal|0
expr_stmt|;
name|SC_DEBUG
argument_list|(
name|sc_link
argument_list|,
name|SDEV_DB3
argument_list|,
operator|(
literal|"Give up and default to variable mode\n"
operator|)
argument_list|)
expr_stmt|;
name|done
label|:
comment|/* 	 * Decide whether or not to write two file marks to signify end- 	 * of-data.  Make the decision as a function of density.  If 	 * the decision is not to use a second file mark, the SCSI BLANK 	 * CHECK condition code will be recognized as end-of-data when 	 * first read. 	 * (I think this should be a by-product of fixed/variable..julian) 	 */
switch|switch
condition|(
operator|(
name|int
operator|)
name|st
operator|->
name|density
condition|)
block|{
comment|/*      case    8 mm:   What is the SCSI density code for 8 mm, anyway? */
case|case
name|QIC_11
case|:
case|case
name|QIC_24
case|:
case|case
name|QIC_120
case|:
case|case
name|QIC_150
case|:
case|case
name|QIC_525
case|:
case|case
name|QIC_1320
case|:
name|st
operator|->
name|flags
operator|&=
operator|~
name|ST_2FM_AT_EOD
expr_stmt|;
break|break;
default|default:
name|st
operator|->
name|flags
operator||=
name|ST_2FM_AT_EOD
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Actually translate the requested transfer into  * one the physical driver can understand  * The transfer is described by a buf and will include  * only one physical transfer.  */
end_comment

begin_function
name|void
name|st_strategy
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
block|{
name|struct
name|buf
modifier|*
modifier|*
name|dp
decl_stmt|;
name|unsigned
name|char
name|unit
decl_stmt|;
comment|/* XXX Everywhere else unit is "u_int32". Please int? */
name|u_int32
name|opri
decl_stmt|;
name|struct
name|scsi_data
modifier|*
name|st
decl_stmt|;
name|int
name|len
decl_stmt|;
name|ststrats
operator|++
expr_stmt|;
name|unit
operator|=
name|STUNIT
argument_list|(
operator|(
name|bp
operator|->
name|b_dev
operator|)
argument_list|)
expr_stmt|;
name|st
operator|=
name|sc_link
operator|->
name|sd
expr_stmt|;
comment|/* 	 * If it's a null transfer, return immediatly 	 */
if|if
condition|(
operator|(
name|len
operator|=
name|bp
operator|->
name|b_bcount
operator|)
operator|==
literal|0
condition|)
block|{
goto|goto
name|done
goto|;
block|}
comment|/* 	 * Check the adapter can do it 	 */
name|scsi_minphys
argument_list|(
name|bp
argument_list|,
operator|&
name|st_switch
argument_list|)
expr_stmt|;
comment|/* 	 * Odd sized request on fixed drives are verboten 	 */
if|if
condition|(
name|st
operator|->
name|flags
operator|&
name|ST_FIXEDBLOCKS
condition|)
block|{
if|if
condition|(
name|bp
operator|->
name|b_bcount
operator|%
name|st
operator|->
name|blksiz
condition|)
block|{
name|printf
argument_list|(
literal|"st%d: bad request, must be multiple of %ld\n"
argument_list|,
name|unit
argument_list|,
name|st
operator|->
name|blksiz
argument_list|)
expr_stmt|;
name|bp
operator|->
name|b_error
operator|=
name|EIO
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
block|}
comment|/* 	 * as are out-of-range requests on variable drives. 	 * (or if we got chopped by minphys) 	 */
else|else
block|{
if|if
condition|(
operator|(
name|bp
operator|->
name|b_bcount
operator|<
name|st
operator|->
name|blkmin
operator|||
name|bp
operator|->
name|b_bcount
operator|>
name|st
operator|->
name|blkmax
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"st%d: bad request, must be between %ld and %ld\n"
argument_list|,
name|unit
argument_list|,
name|st
operator|->
name|blkmin
argument_list|,
name|st
operator|->
name|blkmax
argument_list|)
expr_stmt|;
name|bp
operator|->
name|b_error
operator|=
name|EIO
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
if|if
condition|(
name|len
operator|!=
name|bp
operator|->
name|b_bcount
condition|)
block|{
name|printf
argument_list|(
literal|"st%d: bad request, must be less than %ld bytes\n"
argument_list|,
argument|unit
argument_list|,
argument|bp->b_bcount +
literal|1
argument|bp->b_error = EIO; 			goto bad; 		} 	} 	opri = splbio();
comment|/* 	 * Use a bounce buffer if necessary 	 */
ifdef|#
directive|ifdef
name|BOUNCE_BUFFERS
argument|if (sc_link->flags& SDEV_BOUNCE) 		vm_bounce_alloc(bp);
endif|#
directive|endif
comment|/* 	 * Place it in the queue of activities for this tape 	 * at the end (a bit silly because we only have on user.. 	 * (but it could fork() )) 	 */
argument|dp =&(st->buf_queue); 	while (*dp) { 		dp =&((*dp)->b_actf); 	} 	*dp = bp; 	bp->b_actf = NULL;
comment|/* 	 * Tell the device to get going on the transfer if it's 	 * not doing anything, otherwise just wait for completion 	 * (All a bit silly if we're only allowing 1 open but..) 	 */
argument|ststart(unit,
literal|0
argument|);  	splx(opri); 	return; bad: 	bp->b_flags |= B_ERROR; done:
comment|/* 	 * Correctly set the buf to indicate a completed xfer 	 */
argument|biodone(bp); 	return; }
comment|/*  * ststart looks to see if there is a buf waiting for the device  * and that the device is not already busy. If both are true,  * It dequeues the buf and creates a scsi command to perform the  * transfer required. The transfer request will call scsi_done  * on completion, which will in turn call this routine again  * so that the next queued transfer is performed.  * The bufs are queued by the strategy routine (ststrategy)  *  * This routine is also called after other non-queued requests  * have been made of the scsi driver, to ensure that the queue  * continues to be drained.  * ststart() is called at splbio  */
argument|void ststart(unit, flags) 	u_int32	unit; 	u_int32 flags; { 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd; 	register struct buf *bp =
literal|0
argument|; 	struct scsi_rw_tape cmd;  	SC_DEBUG(sc_link, SDEV_DB2, (
literal|"ststart "
argument|));
comment|/* 	 * See if there is a buf to do and we are not already 	 * doing one 	 */
argument|while (sc_link->opennings !=
literal|0
argument|) {
comment|/* if a special awaits, let it proceed first */
argument|if (sc_link->flags& SDEV_WAITING) { 			sc_link->flags&= ~SDEV_WAITING; 			wakeup((caddr_t)sc_link); 			return; 		} 		if ((bp = st->buf_queue) == NULL) { 			return;
comment|/* no work to bother with */
argument|} 		st->buf_queue = bp->b_actf;
comment|/* 		 * if the device has been unmounted by the user 		 * then throw away all requests until done 		 */
argument|if ((!(st->flags& ST_MOUNTED)) 		    || (!(sc_link->flags& SDEV_MEDIA_LOADED))) {
comment|/* make sure that one implies the other.. */
argument|sc_link->flags&= ~SDEV_MEDIA_LOADED; 			goto badnews; 		}
comment|/* 		 * only FIXEDBLOCK devices have pending operations 		 */
argument|if (st->flags& ST_FIXEDBLOCKS) {
comment|/* 			 * If we are at a filemark but have not reported it yet 			 * then we should report it now 			 */
argument|if (st->flags& ST_AT_FILEMARK) { 				if ((bp->b_flags& B_READ) == B_WRITE) {
comment|/* 					 * Handling of ST_AT_FILEMARK in 					 * st_space will fill in the right file 					 * mark count. 					 * Back up over filemark 					 */
argument|if (st_space(unit,
literal|0
argument|, SP_FILEMARKS,
literal|0
argument|) != 					    ESUCCESS) 						goto badnews; 				} else { 					bp->b_resid = bp->b_bcount; 					bp->b_error =
literal|0
argument|; 					bp->b_flags&= ~B_ERROR; 					st->flags&= ~ST_AT_FILEMARK; 					biodone(bp); 					continue;
comment|/* seek more work */
argument|} 			}
comment|/* 			 * If we are at EIO (e.g. EOM) but have not reported it 			 * yet then we should report it now 			 */
argument|if (st->flags& ST_EIO_PENDING) { 				bp->b_resid = bp->b_bcount; 				bp->b_error = EIO; 				bp->b_flags |= B_ERROR; 				st->flags&= ~ST_EIO_PENDING; 				biodone(bp); 				continue;
comment|/* seek more work */
argument|} 		}
comment|/* 		 *  Fill out the scsi command 		 */
argument|bzero(&cmd, sizeof(cmd)); 		if ((bp->b_flags& B_READ) == B_WRITE) { 			cmd.op_code = WRITE_COMMAND_TAPE; 			st->flags&= ~ST_FM_WRITTEN; 			st->flags |= ST_WRITTEN; 			flags |= SCSI_DATA_OUT; 		} else { 			cmd.op_code = READ_COMMAND_TAPE; 			flags |= SCSI_DATA_IN; 		}
comment|/* 		 * Handle "fixed-block-mode" tape drives by using the 		 * block count instead of the length. 		 */
argument|if (st->flags& ST_FIXEDBLOCKS) { 			cmd.byte2 |= SRWT_FIXED; 			scsi_uto3b(bp->b_bcount / st->blksiz, cmd.len); 		} else { 			scsi_uto3b(bp->b_bcount, cmd.len); 		}
comment|/* 		 * go ask the adapter to do all this for us 		 */
argument|if (scsi_scsi_cmd(sc_link, 			(struct scsi_generic *)&cmd, 			sizeof(cmd), 			(u_char *) bp->b_un.b_addr, 			bp->b_bcount,
literal|0
argument|,
comment|/* can't retry a read on a tape really */
literal|100000
argument|, 			bp, 			flags) == SUCCESSFULLY_QUEUED) { 			stqueues++; 		} else { badnews: 			printf(
literal|"st%ld: oops not queued\n"
argument|, unit); 			bp->b_flags |= B_ERROR; 			bp->b_error = EIO; 			biodone(bp); 		} 	}
comment|/* go back and see if we can cram more work in.. */
argument|}
comment|/*  * Perform special action on behalf of the user;  * knows about the internals of this device  */
argument|errval st_ioctl(dev_t dev, int cmd, caddr_t arg, int	flag, struct proc *p, struct scsi_link *sc_link) { 	errval  errcode =
literal|0
argument|; 	unsigned char unit; 	u_int32 number
argument_list|,
argument|flags
argument_list|,
argument|dsty; 	struct scsi_data *st; 	u_int32 hold_blksiz; 	u_int32 hold_density; 	int32   nmarks; 	struct mtop *mt = (struct mtop *) arg;
comment|/* 	 * Find the device that the user is talking about 	 */
argument|flags =
literal|0
argument|;
comment|/* give error messages, act on errors etc. */
argument|unit = STUNIT(dev); 	dsty = DSTY(dev); 	st = sc_link->sd; 	hold_blksiz = st->blksiz; 	hold_density = st->density;  	switch (cmd) {  	case MTIOCGET: 		{ 			struct mtget *g = (struct mtget *) arg;  			SC_DEBUG(sc_link, SDEV_DB1, (
literal|"[ioctl: get status]\n"
argument|)); 			bzero(g, sizeof(struct mtget)); 			g->mt_type =
literal|0x7
argument|;
comment|/* Ultrix compat */
comment|/*? */
argument|g->mt_density = st->density; 			g->mt_blksiz = st->blksiz; 			g->mt_comp = st->comp; 			g->mt_density0 = st->modes[
literal|0
argument|].density; 			g->mt_density1 = st->modes[
literal|1
argument|].density; 			g->mt_density2 = st->modes[
literal|2
argument|].density; 			g->mt_density3 = st->modes[
literal|3
argument|].density; 			g->mt_blksiz0 = st->modes[
literal|0
argument|].blksiz; 			g->mt_blksiz1 = st->modes[
literal|1
argument|].blksiz; 			g->mt_blksiz2 = st->modes[
literal|2
argument|].blksiz; 			g->mt_blksiz3 = st->modes[
literal|3
argument|].blksiz; 			g->mt_comp0 =
literal|0
argument|; 			g->mt_comp1 =
literal|0
argument|; 			g->mt_comp2 =
literal|0
argument|; 			g->mt_comp3 =
literal|0
argument|; 			break; 		} 	case MTIOCTOP: 		{  			SC_DEBUG(sc_link, SDEV_DB1, (
literal|"[ioctl: op=0x%x count=0x%lx]\n"
argument|, 				mt->mt_op, mt->mt_count));
comment|/* compat: in U*x it is a short */
argument|number = mt->mt_count; 			switch ((short) (mt->mt_op)) { 			case MTWEOF:
comment|/* write an end-of-file record */
argument|errcode = st_write_filemarks(unit, number, flags); 				break; 			case MTBSF:
comment|/* backward space file */
argument|number = -number; 			case MTFSF:
comment|/* forward space file */
argument|errcode = st_chkeod(unit, FALSE,&nmarks, flags); 				if (errcode == ESUCCESS) 					errcode = st_space(unit, number - nmarks, 					    SP_FILEMARKS, flags); 				break; 			case MTBSR:
comment|/* backward space record */
argument|number = -number; 			case MTFSR:
comment|/* forward space record */
argument|errcode = st_chkeod(unit, TRUE,&nmarks, flags); 				if (errcode == ESUCCESS) 					errcode = st_space(unit, number, SP_BLKS, flags); 				break; 			case MTEOD:
comment|/* space to end of recorded medium */
argument|errcode = st_chkeod(unit, FALSE,&nmarks, flags); 				if (errcode == ESUCCESS) 					errcode = st_space(unit,
literal|0
argument|, SP_EOM, 							   flags); 				break; 			case MTREW:
comment|/* rewind */
argument|errcode = st_rewind(unit, FALSE, flags); 				break; 			case MTERASE:
comment|/* erase */
argument|errcode = st_erase(unit, FALSE, flags); 				break; 			case MTOFFL:
comment|/* rewind and put the drive offline */
argument|st_unmount(unit, EJECT); 				break; 			case MTNOP:
comment|/* no operation, sets status only */
argument|case MTCACHE:
comment|/* enable controller cache */
argument|case MTNOCACHE:
comment|/* disable controller cache */
argument|break; 			case MTSETBSIZ:
comment|/* Set block size for device */
ifdef|#
directive|ifdef
name|NOTYET
argument|if (!(st->flags& ST_NEW_MOUNT)) { 					uprintf(
literal|"re-mount tape before changing blocksize"
argument|); 					errcode = EINVAL; 					break; 				}
endif|#
directive|endif
argument|if (number ==
literal|0
argument|) { 					st->flags&= ~ST_FIXEDBLOCKS; 				} else { 					if ((st->blkmin || st->blkmax)
comment|/* they exist */
argument|&&((number< st->blkmin 						    || number> st->blkmax))) { 						errcode = EINVAL; 						break; 					} 					st->flags |= ST_FIXEDBLOCKS; 				} 				st->blksiz = number; 				st->flags |= ST_BLOCK_SET;
comment|/*XXX */
argument|goto try_new_value;  			case MTSETDNSTY:
comment|/* Set density for device and mode */
argument|if (number> SCSI_2_MAX_DENSITY_CODE) { 					errcode = EINVAL; 				} else { 					st->density = number; 				} 				goto try_new_value;  			case MTCOMP:
comment|/* enable default compression */
argument|errcode = st_comp(unit,number); 				break; 			default: 				errcode = EINVAL; 			} 			break; 		} 	case MTIOCIEOT: 	case MTIOCEEOT: 		break; 	default: 		if(IS_CTLMODE(dev)) 			errcode = scsi_do_ioctl(dev, cmd, arg, flag, p, sc_link); 		else 			errcode = ENOTTY; 		break; 	} 	return errcode;
comment|/*-----------------------------*/
argument|try_new_value:
comment|/* 	 * Check that the mode being asked for is aggreeable to the 	 * drive. If not, put it back the way it was. 	 */
argument|if ( (errcode = st_mode_select(unit,
literal|0
argument|, NULL,
literal|0
argument|)) ) {
comment|/* put back as it was */
argument|printf(
literal|"st%d: Cannot set selected mode"
argument|, unit); 		st->density = hold_density; 		st->blksiz = hold_blksiz; 		if (st->blksiz) { 			st->flags |= ST_FIXEDBLOCKS; 		} else { 			st->flags&= ~ST_FIXEDBLOCKS; 		} 		return (errcode); 	}
comment|/* 	 * As the drive liked it, if we are setting a new default, 	 * set it into the structures as such. 	 * 	 * The means for deciding this are not finalised yet 	 */
argument|if (IS_CTLMODE(dev)) {
comment|/* special mode */
comment|/* XXX */
argument|switch ((short) (mt->mt_op)) { 		case MTSETBSIZ: 			st->modes[dsty].blksiz = st->blksiz; 			st->modeflags[dsty] |= BLKSIZE_SET_BY_USER; 			break; 		case MTSETDNSTY: 			st->modes[dsty].density = st->density; 			st->modeflags[dsty] |= DENSITY_SET_BY_USER; 			break; 		} 	} 	return
literal|0
argument|; }
comment|/*  * Do a synchronous read.  */
argument|errval st_read(unit, buf, size, flags) 	u_int32 unit
argument_list|,
argument|size
argument_list|,
argument|flags; 	char   *buf; { 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd; 	struct scsi_rw_tape scsi_cmd;
comment|/* 	 * If it's a null transfer, return immediatly 	 */
argument|if (size ==
literal|0
argument|) { 		return (ESUCCESS); 	} 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = READ_COMMAND_TAPE; 	if (st->flags& ST_FIXEDBLOCKS) { 		scsi_cmd.byte2 |= SRWT_FIXED; 		scsi_uto3b(size / (st->blksiz ? st->blksiz : DEF_FIXED_BSIZE), 		    scsi_cmd.len); 	} else { 		scsi_uto3b(size, scsi_cmd.len); 	} 	return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd), 		(u_char *) buf, 		size,
literal|0
argument|,
comment|/* not on io commands */
literal|100000
argument|, 		NULL, 		flags | SCSI_DATA_IN)); }
ifdef|#
directive|ifdef
name|__STDC__
define|#
directive|define
name|b2tol
parameter_list|(
name|a
parameter_list|)
value|(((unsigned)(a##_1)<< 8) + (unsigned)a##_0 )
else|#
directive|else
define|#
directive|define
name|b2tol
parameter_list|(
name|a
parameter_list|)
value|(((unsigned)(a
comment|/**/
value|_1)<< 8) + (unsigned)a
comment|/**/
value|_0 )
endif|#
directive|endif
comment|/*  * Ask the drive what it's min and max blk sizes are.  */
argument|errval st_rd_blk_lim(unit, flags) 	u_int32 unit
argument_list|,
argument|flags; { 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd; 	struct scsi_blk_limits scsi_cmd; 	struct scsi_blk_limits_data scsi_blkl; 	errval  errno;
comment|/* 	 * First check if we have it all loaded 	 */
argument|if ((sc_link->flags& SDEV_MEDIA_LOADED)) 		return
literal|0
argument|;
comment|/* 	 * do a 'Read Block Limits' 	 */
argument|bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = READ_BLK_LIMITS;
comment|/* 	 * do the command, update the global values 	 */
argument|if ( (errno = scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd), 		(u_char *)& scsi_blkl, 		sizeof(scsi_blkl), 		ST_RETRIES,
literal|5000
argument|, 		NULL, 		flags | SCSI_DATA_IN)) ) { 		return errno; 	} 	st->blkmin = b2tol(scsi_blkl.min_length); 	st->blkmax = scsi_3btou(&scsi_blkl.max_length_2);  	SC_DEBUG(sc_link, SDEV_DB3, 	    (
literal|"(%ld<= blksiz<= %ld)\n"
argument|, st->blkmin, st->blkmax)); 	return
literal|0
argument|; }
comment|/*  * Get the scsi driver to send a full inquiry to the  * device and use the results to fill out the global  * parameter structure.  *  * called from:  * attach  * open  * ioctl (to reset original blksize)  */
argument|static errval st_mode_sense(unit, flags, page, pagelen, pagecode) 	u_int32 unit
argument_list|,
argument|flags; 	struct tape_pages *page; 	u_int32 pagelen
argument_list|,
argument|pagecode; { 	u_int32 dat_len; 	errval  errno; 	struct scsi_mode_sense scsi_cmd; 	struct { 		struct scsi_mode_header header; 		struct blk_desc blk_desc; 		struct tape_pages page; 	} dat;
comment|/* Tandberg tape drives returns page 00 	 * with the sense data, whether or not 	 * you want it( ie the don't like you 	 * saying you want anything less!!!!! 	 * They also expect page 00 	 * back when you issue a mode select 	 */
argument|struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;  	st->flags&= ~ST_SENSE_READ;
comment|/* 	 * Check if we need to use a default page.. 	 */
argument|if ((st->quirks& ST_Q_NEEDS_PAGE_0)&& (!page)) { 		pagelen = PAGE_0_SENSE_DATA_SIZE; 		page = (struct tape_pages *) st->saved_page0; 		pagecode =
literal|0
argument|; 	}
comment|/* 	 * Now work out the total dat size etc. 	 */
argument|dat_len = sizeof(struct scsi_mode_header) 		+ sizeof(struct blk_desc) 		+ (page ? pagelen :
literal|0
argument|);
comment|/* 	 * Set up a mode sense 	 */
argument|bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = MODE_SENSE; 	scsi_cmd.page = (u_char) pagecode; 	scsi_cmd.length = dat_len;
comment|/* 	 * do the command, 	 * use the results to set blksiz, numblks and density 	 * or if we need it as a template for the mode select 	 * store it away. 	 */
argument|if ( (errno = scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd), 		(u_char *)&dat, 		dat_len, 		ST_RETRIES,
literal|5000
argument|, 		NULL, 		flags | SCSI_DATA_IN)) ) { 		return errno; 	} 	st->numblks = scsi_3btou(dat.blk_desc.nblocks); 	st->media_blksiz = scsi_3btou(dat.blk_desc.blklen); 	st->media_density = dat.blk_desc.density; 	if (dat.header.dev_spec& SMH_DSP_WRITE_PROT) { 		st->flags |= ST_READONLY; 	} 	SC_DEBUG(sc_link, SDEV_DB3, 	    (
literal|"density code 0x%lx, %ld-byte blocks, write-%s, "
argument|, 		st->media_density, st->media_blksiz, 		st->flags& ST_READONLY ?
literal|"protected"
argument|:
literal|"enabled"
argument|)); 	SC_DEBUG(sc_link, SDEV_DB3, (
literal|"%sbuffered\n"
argument|, 		((dat.header.dev_spec& SMH_DSP_BUFF_MODE) ?
literal|""
argument|:
literal|"un"
argument|))); 	if (page) { 		bcopy(&dat.page, page, pagelen); 	} 	st->flags |= ST_SENSE_READ; 	return
literal|0
argument|; }
comment|/*  * Send a filled out parameter structure to the drive to  * set it into the desire modes etc.  */
argument|errval st_mode_select(unit, flags, page, pagelen) 	u_int32 unit
argument_list|,
argument|flags; 	struct tape_pages *page; 	u_int32 pagelen; { 	u_int32 dat_len; 	struct scsi_mode_select scsi_cmd; 	struct { 		struct scsi_mode_header header; 		struct blk_desc blk_desc; 		struct tape_pages page; 	} dat; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;
comment|/* 	 * Check if we need to use a default page.. 	 * Gee, hope we saved one before now........ 	 */
argument|if ((st->quirks& ST_Q_NEEDS_PAGE_0)&& (!page)) { 		pagelen = PAGE_0_SENSE_DATA_SIZE; 		page = (struct tape_pages *) st->saved_page0; 	}
comment|/* 	 * Now work out the total dat size etc. 	 */
argument|dat_len = sizeof(struct scsi_mode_header) 		+ sizeof(struct blk_desc) 		+ (page ? pagelen :
literal|0
argument|);
comment|/* 	 * Set up for a mode select 	 */
argument|bzero(&dat, dat_len); 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = MODE_SELECT; 	scsi_cmd.length = dat_len; 	dat.header.blk_desc_len = sizeof(struct blk_desc); 	dat.header.dev_spec |= SMH_DSP_BUFF_MODE_ON; 	dat.blk_desc.density = st->density; 	if (st->flags& ST_FIXEDBLOCKS) { 		scsi_uto3b(st->blksiz, dat.blk_desc.blklen); 	} 	if (page) { 		bcopy(page,&dat.page, pagelen);
comment|/* the Tandberg tapes need the block size to */
comment|/* be set on each mode sense/select. */
argument|}
comment|/* 	 * do the command 	 */
argument|return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd), 		(u_char *)&dat, 		dat_len, 		ST_RETRIES,
literal|5000
argument|, 		NULL, 		flags | SCSI_DATA_OUT)); }  int noisy_st =
literal|0
argument|;
comment|/***************************************************************\ * Set the compression mode of the drive to on (1) or off (0)	* 	still doesn't work! grrr! \***************************************************************/
argument|errval	st_comp(unit,mode) u_int32 unit
argument_list|,
argument|mode; { 	struct tape_pages       page; 	int	pagesize; 	int retval; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;  	bzero(&page, sizeof(page)); 	pagesize = sizeof(page.pages.configuration) + PAGE_HEADERLEN;  	if ( (retval = st_mode_sense(unit,
literal|0
argument|,&page, pagesize, ST_PAGE_CONFIGURATION)) ) 	{ 		printf(
literal|"sense returned an error of %d\n"
argument|,retval); 		return retval; 	} 	if ( noisy_st) 		printf(
literal|"drive reports value of %d, setting %ld\n"
argument|, 			page.pages.configuration.data_compress_alg,mode);  	page.pg_code&= ST_P_CODE; 	page.pg_length = sizeof(page.pages.configuration);  	switch(mode) 	{ 	case
literal|0
argument|: 		page.pages.configuration.data_compress_alg =
literal|0
argument|; 		break; 	case
literal|1
argument|: 		page.pages.configuration.data_compress_alg =
literal|1
argument|; 		break; 	default: 		printf(
literal|"st%ld: bad value for compression mode\n"
argument|,unit); 		return EINVAL; 	} 	if ( (retval = st_mode_select(unit,
literal|0
argument|,&page, pagesize)) ) 	{ 		printf(
literal|"select returned an error of %d\n"
argument|,retval); 		return retval; 	} 	st->comp = mode; 	return
literal|0
argument|; }
comment|/*  * skip N blocks/filemarks/seq filemarks/eom  */
argument|errval st_space(unit, number, what, flags) 	u_int32 unit
argument_list|,
argument|what
argument_list|,
argument|flags; 	int32   number; { 	errval  error; 	struct scsi_space scsi_cmd; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;  	switch ((int)what) { 	case SP_BLKS: 		if (st->flags& ST_PER_ACTION) { 			if (number>
literal|0
argument|) { 				st->flags&= ~ST_PER_ACTION; 				return (EIO); 			} else if (number<
literal|0
argument|) { 				if (st->flags& ST_AT_FILEMARK) {
comment|/* 					 * Handling of ST_AT_FILEMARK 					 * in st_space will fill in the 					 * right file mark count. 					 */
argument|error = st_space(unit,
literal|0
argument|, SP_FILEMARKS, 					    flags); 					if (error) 						return (error); 				} 				if (st->flags& ST_BLANK_READ) { 					st->flags&= ~ST_BLANK_READ; 					return (EIO); 				} 				st->flags&= ~ST_EIO_PENDING; 			} 		} 		break; 	case SP_FILEMARKS: 		if (st->flags& ST_EIO_PENDING) { 			if (number>
literal|0
argument|) {
comment|/* pretend we just discover the error */
argument|st->flags&= ~ST_EIO_PENDING; 				return (EIO); 			} else if (number<
literal|0
argument|) {
comment|/* back away from the error */
argument|st->flags&= ~ST_EIO_PENDING; 			} 		} 		if (st->flags& ST_AT_FILEMARK) { 			st->flags&= ~ST_AT_FILEMARK; 			number--; 		} 		if ((st->flags& ST_BLANK_READ)&& (number<
literal|0
argument|)) {
comment|/* back away from unwritten tape */
argument|st->flags&= ~ST_BLANK_READ; 			number++;
comment|/* dubious */
argument|} 		break; 	case	SP_EOM: 		if (st->flags& ST_EIO_PENDING) 		{
comment|/* we are already at EOM */
argument|st->flags&= ~ST_EIO_PENDING; 			return(ESUCCESS); 		} 		number =
literal|1
argument|;
comment|/* we have only one end-of-medium */
argument|break; 	} 	if (number ==
literal|0
argument|) { 		return (ESUCCESS); 	} 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = SPACE; 	scsi_cmd.byte2 = what& SS_CODE; 	scsi_uto3b(number, scsi_cmd.number); 	return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd),
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
comment|/* no retries please , just fail */
literal|600000
argument|,
comment|/* 10 mins enough? */
argument|NULL, 		flags)); }
comment|/*  * write N filemarks  */
argument|errval st_write_filemarks(unit, number, flags) 	u_int32 unit
argument_list|,
argument|flags; 	int32   number; { 	struct scsi_write_filemarks scsi_cmd; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;
comment|/* 	 * It's hard to write a negative number of file marks. 	 * Don't try. 	 */
argument|if (number<
literal|0
argument|) { 		return EINVAL; 	} 	switch ((int)number) { 	case
literal|0
argument|:
comment|/* really a command to sync the drive's buffers */
argument|break; 	case
literal|1
argument|: 		if (st->flags& ST_FM_WRITTEN) {
comment|/* already have one down */
argument|st->flags&= ~ST_WRITTEN; 		} else { 			st->flags |= ST_FM_WRITTEN; 		} 		st->flags&= ~ST_PER_ACTION; 		break; 	default: 		st->flags&= ~(ST_PER_ACTION | ST_WRITTEN); 	} 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = WRITE_FILEMARKS; 	scsi_uto3b(number, scsi_cmd.number); 	return scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd),
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
comment|/* no retries, just fail */
literal|100000
argument|,
comment|/* 10 secs.. (may need to repos head ) */
argument|NULL, 		flags); }
comment|/*  * Make sure the right number of file marks is on tape if the  * tape has been written.  If the position argument is true,  * leave the tape positioned where it was originally.  *  * nmarks returns the number of marks to skip (or, if position  * true, which were skipped) to get back original position.  */
argument|int32 st_chkeod(unit, position, nmarks, flags) 	u_int32 unit; 	boolean position; 	int32  *nmarks; 	u_int32 flags; { 	errval  error; 	struct scsi_data *st = SCSI_DATA(&st_switch, unit);  	switch ((int)(st->flags& (ST_WRITTEN | ST_FM_WRITTEN | ST_2FM_AT_EOD))) { 	default: 		*nmarks =
literal|0
argument|; 		return (ESUCCESS); 	case ST_WRITTEN: 	case ST_WRITTEN | ST_FM_WRITTEN | ST_2FM_AT_EOD: 		*nmarks =
literal|1
argument|; 		break; 	case ST_WRITTEN | ST_2FM_AT_EOD: 		*nmarks =
literal|2
argument|; 	} 	error = st_write_filemarks(unit, *nmarks, flags); 	if (position&& (error == ESUCCESS)) 		error = st_space(unit, -*nmarks, SP_FILEMARKS, flags); 	return (error); }
comment|/*  * load/unload (with retension if true)  */
argument|errval st_load(unit, type, flags) 	u_int32 unit
argument_list|,
argument|type
argument_list|,
argument|flags; { 	struct scsi_load scsi_cmd; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd;  	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	if (type != LD_LOAD) { 		errval  error; 		int32   nmarks;  		error = st_chkeod(unit, FALSE,&nmarks, flags); 		if (error != ESUCCESS) 			return (error); 		sc_link->flags&= ~SDEV_MEDIA_LOADED; 	} 	if (st->quirks& ST_Q_IGNORE_LOADS) 		return (
literal|0
argument|); 	scsi_cmd.op_code = LOAD_UNLOAD; 	scsi_cmd.how |= type; 	return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd),
literal|0
argument|,
literal|0
argument|, 		ST_RETRIES,
literal|300000
argument|,
comment|/* 5 min */
argument|NULL, 		flags)); }
comment|/*  *  Rewind the device  */
argument|errval st_rewind(unit, immed, flags) 	u_int32 unit
argument_list|,
argument|flags; 	boolean immed; { 	struct scsi_rewind scsi_cmd; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd; 	errval  error; 	int32   nmarks;  	error = st_chkeod(unit, FALSE,&nmarks, flags); 	if (error != ESUCCESS) 		return (error); 	st->flags&= ~ST_PER_ACTION; 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = REWIND; 	scsi_cmd.byte2 = immed ? SR_IMMED :
literal|0
argument|; 	return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd),
literal|0
argument|,
literal|0
argument|, 		ST_RETRIES, 		immed ?
literal|5000
argument|:
literal|300000
argument|,
comment|/* 5 sec or 5 min */
argument|NULL, 		flags)); }
comment|/* **  Erase the device */
argument|errval st_erase(unit, immed, flags) 	u_int32 unit
argument_list|,
argument|flags; 	boolean immed; { 	struct scsi_erase scsi_cmd; 	struct scsi_link *sc_link = SCSI_LINK(&st_switch, unit); 	struct scsi_data *st = sc_link->sd; 	errval  error; 	int32   nmarks;  	error = st_chkeod(unit, FALSE,&nmarks, flags); 	if (error != ESUCCESS) 		return (error);
comment|/* 	**      Archive Viper 2525 technical manual 5.7 (ERASE 19h): 	**	tape has to be positioned to BOT first before erase command 	**	is issued or command is rejected. So we rewind the tape first 	**	and exit with an error, if the tape can't be rewinded. 	*/
argument|error = st_rewind(unit, FALSE, SCSI_SILENT); 	if (error != ESUCCESS) 		return (error); 	st->flags&= ~ST_PER_ACTION; 	bzero(&scsi_cmd, sizeof(scsi_cmd)); 	scsi_cmd.op_code = ERASE; 	scsi_cmd.byte2 = SE_LONG;
comment|/* LONG_ERASE */
argument|scsi_cmd.byte2 += immed ? SE_IMMED :
literal|0
argument|;
comment|/* immed bit is here the 2nd! */
argument|return (scsi_scsi_cmd(sc_link, 		(struct scsi_generic *)&scsi_cmd, 		sizeof(scsi_cmd),
literal|0
argument|,
literal|0
argument|, 		ST_RETRIES, 		immed ?
literal|5000
argument|:
literal|300000
argument|,
comment|/* 5 sec or 5 min */
argument|NULL, 		flags)); }
comment|/*  * Look at the returned sense and act on the error and detirmine  * The unix error number to pass back... (0 = report no error)  *                            (SCSIRET_CONTINUE = continue processing)  */
argument|errval st_interpret_sense(xs) 	struct scsi_xfer *xs; { 	struct scsi_link *sc_link = xs->sc_link; 	struct scsi_sense_data *sense =&(xs->sense); 	boolean silent = xs->flags& SCSI_SILENT; 	u_int32 unit = sc_link->dev_unit; 	struct scsi_data *st = SCSI_DATA(&st_switch, unit); 	u_int32 key; 	int32   info;
comment|/* 	 * Get the sense fields and work out what code 	 */
argument|if (sense->error_code& SSD_ERRCODE_VALID) { 		info = ntohl(*((int32 *) sense->ext.extended.info)); 	} else { 		if (st->flags& ST_FIXEDBLOCKS) { 			info = xs->datalen / st->blksiz; 		} else { 			info = xs->datalen; 		} 	} 	if ((sense->error_code& SSD_ERRCODE) !=
literal|0x70
argument|) { 		return SCSIRET_CONTINUE;
comment|/* let the generic code handle it */
argument|} 	if(sense->ext.extended.flags& (SSD_EOM|SSD_FILEMARK|SSD_ILI)) { 		if (st->flags& ST_FIXEDBLOCKS) { 			xs->resid = info * st->blksiz; 			xs->flags |= SCSI_RESID_VALID; 			if (sense->ext.extended.flags& SSD_EOM) { 				st->flags |= ST_EIO_PENDING; 			} 			if (sense->ext.extended.flags& SSD_FILEMARK) { 				st->flags |= ST_AT_FILEMARK; 			} 			if (sense->ext.extended.flags& SSD_ILI) { 				st->flags |= ST_EIO_PENDING; 				if (sense->error_code& SSD_ERRCODE_VALID&& 			    	!silent) 					printf(
literal|"st%ld: block wrong size"
literal|", %ld blocks residual\n"
argument|, unit 				    	,info);
comment|/*XXX*/
comment|/* is this how it works ? */
comment|/* check def of ILI for fixed blk tapes */
comment|/* 			 	 * This quirk code helps the drive read 			 	 * the first tape block, regardless of 			 	 * format.  That is required for these 			 	 * drives to return proper MODE SENSE 			 	 * information. 			 	 */
argument|if ((st->quirks& ST_Q_SNS_HLP)&& 				    !(st->flags& ST_SENSE_READ)) { 					st->blksiz -=
literal|512
argument|; 				} 			}
comment|/* 			 * If no data was tranfered, do it immediatly 			 */
argument|if (xs->resid>= xs->datalen) { 				xs->flags&= ~SCSI_RESID_VALID; 				if (st->flags& ST_AT_FILEMARK) { 					xs->flags |= SCSI_EOF; 					st->flags&= ~ST_AT_FILEMARK; 					return
literal|0
argument|; 				} 				if (st->flags& ST_EIO_PENDING) { 					st->flags&= ~ST_EIO_PENDING; 					return EIO; 				} 			} 			return
literal|0
argument|; 		} else {
comment|/* must be variable mode */
argument|xs->resid = xs->datalen;
comment|/* to be sure */
argument|if (sense->ext.extended.flags& SSD_EOM) { 				return (EIO); 			} 			if (sense->ext.extended.flags& SSD_FILEMARK) { 				xs->flags |= SCSI_EOF; 			} 			if (sense->ext.extended.flags& SSD_ILI) { 				if (info<
literal|0
argument|) {
comment|/* 					 * the record was bigger than the read 					 */
argument|if (!silent) 						printf(
literal|"st%ld: %ld-byte record "
literal|"too big\n"
argument|, unit, 					    	xs->datalen - info); 					return (EIO); 				} 				xs->resid = info; 				xs->flags |= SCSI_RESID_VALID; 			} 		} 		return
literal|0
argument|; 	} 	key = sense->ext.extended.flags& SSD_KEY;  	if (key ==
literal|0x8
argument|) { 		xs->flags |= SCSI_EOF;
comment|/* some drives need this */
comment|/* 		 * This quirk code helps the drive read the 		 * first tape block, regardless of format.  That 		 * is required for these drives to return proper 		 * MODE SENSE information. 		 */
argument|if ((st->quirks& ST_Q_SNS_HLP)&& 		    !(st->flags& ST_SENSE_READ)) {
comment|/* still starting */
argument|st->blksiz -=
literal|512
argument|; 		} else if (!(st->flags& (ST_2FM_AT_EOD | ST_BLANK_READ))) { 			st->flags |= ST_BLANK_READ; 			xs->flags |= SCSI_EOF; 			return (ESUCCESS); 		} 	} 	return SCSIRET_CONTINUE;
comment|/* Use the the generic handler */
argument|}
comment|/*  * The quirk here is that the drive returns some value to st_mode_sense  * incorrectly until the tape has actually passed by the head.  *  * The method is to set the drive to large fixed-block state (user-specified  * density and 1024-byte blocks), then read and rewind to get it to sense the  * tape.  If that doesn't work, try 512-byte fixed blocks.  If that doesn't  * work, as a last resort, try variable- length blocks.  The result will be  * the ability to do an accurate st_mode_sense.  *  * We know we can do a rewind because we just did a load, which implies rewind.  * Rewind seems preferable to space backward if we have a virgin tape.  *  * The rest of the code for this quirk is in ILI processing and BLANK CHECK  * error processing, both part of st_interpret_sense.  */
argument|errval st_touch_tape(unit) 	u_int32	unit; { 	struct scsi_data *st = SCSI_DATA(&st_switch, unit); 	char   *buf; 	u_int32 readsiz; 	errval  errno;  	buf = malloc(
literal|1024
argument|, M_TEMP, M_NOWAIT); 	if (!buf) 		return (ENOMEM);  	if (( errno = st_mode_sense(unit,
literal|0
argument|, NULL,
literal|0
argument|,
literal|0
argument|)) ) { 		goto bad; 	} 	st->blksiz =
literal|1024
argument|; 	do { 		switch ((int)st->blksiz) { 		case
literal|512
argument|: 		case
literal|1024
argument|: 			readsiz = st->blksiz; 			st->flags |= ST_FIXEDBLOCKS; 			break; 		default: 			readsiz =
literal|1
argument|; 			st->flags&= ~ST_FIXEDBLOCKS; 		} if ( (errno = st_mode_select(unit,
literal|0
argument|, NULL,
literal|0
argument|)) ) { 			goto bad; 		} 		st_read(unit, buf, readsiz, SCSI_SILENT); 		if ( (errno = st_rewind(unit, FALSE,
literal|0
argument|)) ) { bad:			free(buf, M_TEMP); 			return (errno); 		} 	} while (readsiz !=
literal|1
argument|&& readsiz> st->blksiz); 	free(buf, M_TEMP); 	return
literal|0
argument|; }
end_function

end_unit

