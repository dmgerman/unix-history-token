begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mtio.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MTIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MTIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Structures and definitions for mag tape io control commands  */
end_comment

begin_comment
comment|/* structure for MTIOCTOP - mag tape op command */
end_comment

begin_struct
struct|struct
name|mtop
block|{
name|short
name|mt_op
decl_stmt|;
comment|/* operations defined below */
name|daddr_t
name|mt_count
decl_stmt|;
comment|/* how many of them */
block|}
struct|;
end_struct

begin_comment
comment|/* operations */
end_comment

begin_define
define|#
directive|define
name|MTWEOF
value|0
end_define

begin_comment
comment|/* write an end-of-file record */
end_comment

begin_define
define|#
directive|define
name|MTFSF
value|1
end_define

begin_comment
comment|/* forward space file */
end_comment

begin_define
define|#
directive|define
name|MTBSF
value|2
end_define

begin_comment
comment|/* backward space file */
end_comment

begin_define
define|#
directive|define
name|MTFSR
value|3
end_define

begin_comment
comment|/* forward space record */
end_comment

begin_define
define|#
directive|define
name|MTBSR
value|4
end_define

begin_comment
comment|/* backward space record */
end_comment

begin_define
define|#
directive|define
name|MTREW
value|5
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|MTOFFL
value|6
end_define

begin_comment
comment|/* rewind and put the drive offline */
end_comment

begin_define
define|#
directive|define
name|MTNOP
value|7
end_define

begin_comment
comment|/* no operation, sets status only */
end_comment

begin_define
define|#
directive|define
name|MTCACHE
value|8
end_define

begin_comment
comment|/* enable controller cache */
end_comment

begin_define
define|#
directive|define
name|MTNOCACHE
value|9
end_define

begin_comment
comment|/* disable controller cache */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_comment
comment|/* Set block size for device. If device is a variable size dev		*/
end_comment

begin_comment
comment|/* a non zero parameter will change the device to a fixed block size	*/
end_comment

begin_comment
comment|/* device with block size set to that of the parameter passed in.	*/
end_comment

begin_comment
comment|/* Resetting the block size to 0 will restore the device to a variable	*/
end_comment

begin_comment
comment|/* block size device. */
end_comment

begin_define
define|#
directive|define
name|MTSETBSIZ
value|10
end_define

begin_comment
comment|/* Set density values for device. Sets the value for the opened mode only. */
end_comment

begin_define
define|#
directive|define
name|MTSETDNSTY
value|11
end_define

begin_define
define|#
directive|define
name|MTERASE
value|12
end_define

begin_comment
comment|/* erase to EOM */
end_comment

begin_define
define|#
directive|define
name|MTEOD
value|13
end_define

begin_comment
comment|/* Space to EOM */
end_comment

begin_define
define|#
directive|define
name|MTCOMP
value|14
end_define

begin_comment
comment|/* select compression mode 0=off, 1=def */
end_comment

begin_define
define|#
directive|define
name|MTRETENS
value|15
end_define

begin_comment
comment|/* re-tension tape */
end_comment

begin_define
define|#
directive|define
name|MTWSS
value|16
end_define

begin_comment
comment|/* write setmark(s) */
end_comment

begin_define
define|#
directive|define
name|MTFSS
value|17
end_define

begin_comment
comment|/* forward space setmark */
end_comment

begin_define
define|#
directive|define
name|MTBSS
value|18
end_define

begin_comment
comment|/* backward space setmark */
end_comment

begin_define
define|#
directive|define
name|MT_COMP_ENABLE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MT_COMP_DISABLED
value|0xfffffffe
end_define

begin_define
define|#
directive|define
name|MT_COMP_UNSUPP
value|0xfffffffd
end_define

begin_comment
comment|/*  * Values in mt_dsreg that say what the device is doing  */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_NIL
value|0
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_REST
value|1
end_define

begin_comment
comment|/* Doing Nothing */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_RBSY
value|2
end_define

begin_comment
comment|/* Communicating with tape (but no motion) */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_WR
value|20
end_define

begin_comment
comment|/* Writing */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_FMK
value|21
end_define

begin_comment
comment|/* Writing Filemarks */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_ZER
value|22
end_define

begin_comment
comment|/* Erasing */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_RD
value|30
end_define

begin_comment
comment|/* Reading */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_FWD
value|40
end_define

begin_comment
comment|/* Spacing Forward */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_REV
value|41
end_define

begin_comment
comment|/* Spacing Reverse */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_POS
value|42
end_define

begin_comment
comment|/* Hardware Positioning (direction unknown) */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_REW
value|43
end_define

begin_comment
comment|/* Rewinding */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_TEN
value|44
end_define

begin_comment
comment|/* Retensioning */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_UNL
value|45
end_define

begin_comment
comment|/* Unloading */
end_comment

begin_define
define|#
directive|define
name|MTIO_DSREG_LD
value|46
end_define

begin_comment
comment|/* Loading */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/* structure for MTIOCGET - mag tape get status command */
end_comment

begin_struct
struct|struct
name|mtget
block|{
name|short
name|mt_type
decl_stmt|;
comment|/* type of magtape device */
comment|/* the following two registers are grossly device dependent */
name|short
name|mt_dsreg
decl_stmt|;
comment|/* ``drive status'' register */
name|short
name|mt_erreg
decl_stmt|;
comment|/* ``error'' register */
comment|/* end device-dependent registers */
comment|/* 	 * Note that the residual count, while maintained, may be 	 * be nonsense because the size of the residual may (greatly) 	 * exceed 32 K-bytes. Use the MTIOCERRSTAT ioctl to get a 	 * more accurate count. 	 */
name|short
name|mt_resid
decl_stmt|;
comment|/* residual count */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|daddr_t
name|mt_blksiz
decl_stmt|;
comment|/* presently operating blocksize */
name|daddr_t
name|mt_density
decl_stmt|;
comment|/* presently operating density */
name|u_int32_t
name|mt_comp
decl_stmt|;
comment|/* presently operating compression */
name|daddr_t
name|mt_blksiz0
decl_stmt|;
comment|/* blocksize for mode 0 */
name|daddr_t
name|mt_blksiz1
decl_stmt|;
comment|/* blocksize for mode 1 */
name|daddr_t
name|mt_blksiz2
decl_stmt|;
comment|/* blocksize for mode 2 */
name|daddr_t
name|mt_blksiz3
decl_stmt|;
comment|/* blocksize for mode 3 */
name|daddr_t
name|mt_density0
decl_stmt|;
comment|/* density for mode 0 */
name|daddr_t
name|mt_density1
decl_stmt|;
comment|/* density for mode 1 */
name|daddr_t
name|mt_density2
decl_stmt|;
comment|/* density for mode 2 */
name|daddr_t
name|mt_density3
decl_stmt|;
comment|/* density for mode 3 */
comment|/* the following are not yet implemented */
name|u_int32_t
name|mt_comp0
decl_stmt|;
comment|/* compression type for mode 0 */
name|u_int32_t
name|mt_comp1
decl_stmt|;
comment|/* compression type for mode 1 */
name|u_int32_t
name|mt_comp2
decl_stmt|;
comment|/* compression type for mode 2 */
name|u_int32_t
name|mt_comp3
decl_stmt|;
comment|/* compression type for mode 3 */
comment|/* end not yet implemented */
endif|#
directive|endif
name|daddr_t
name|mt_fileno
decl_stmt|;
comment|/* relative file number of current position */
name|daddr_t
name|mt_blkno
decl_stmt|;
comment|/* relative block number of current position */
block|}
struct|;
end_struct

begin_comment
comment|/* structure for MTIOCERRSTAT - tape get error status command */
end_comment

begin_comment
comment|/* really only supported for SCSI tapes right now */
end_comment

begin_struct
struct|struct
name|scsi_tape_errors
block|{
comment|/* 	 * These are latched from the last command that had a SCSI 	 * Check Condition noted for these operations. The act 	 * of issuing an MTIOCERRSTAT unlatches and clears them. 	 */
name|u_int8_t
name|io_sense
index|[
literal|32
index|]
decl_stmt|;
comment|/* Last Sense Data For Data I/O */
name|int32_t
name|io_resid
decl_stmt|;
comment|/* residual count from last Data I/O */
name|u_int8_t
name|io_cdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* Command that Caused the Last Data Sense */
name|u_int8_t
name|ctl_sense
index|[
literal|32
index|]
decl_stmt|;
comment|/* Last Sense Data For Control I/O */
name|int32_t
name|ctl_resid
decl_stmt|;
comment|/* residual count from last Control I/O */
name|u_int8_t
name|ctl_cdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* Command that Caused the Last Control Sense */
comment|/* 	 * These are the read and write cumulative error counters. 	 * (how to reset cumulative error counters is not yet defined). 	 * (not implemented as yet but space is being reserved for them) 	 */
struct|struct
block|{
name|u_int32_t
name|retries
decl_stmt|;
comment|/* total # retries performed */
name|u_int32_t
name|corrected
decl_stmt|;
comment|/* total # corrections performed */
name|u_int32_t
name|processed
decl_stmt|;
comment|/* total # corrections succssful */
name|u_int32_t
name|failures
decl_stmt|;
comment|/* total # corrections/retries failed */
name|u_int64_t
name|nbytes
decl_stmt|;
comment|/* total # bytes processed */
block|}
name|wterr
struct|,
name|rderr
struct|;
block|}
struct|;
end_struct

begin_union
union|union
name|mterrstat
block|{
name|struct
name|scsi_tape_errors
name|scsi_errstat
decl_stmt|;
name|char
name|_reserved_padding
index|[
literal|256
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Constants for mt_type byte.  These are the same  * for controllers compatible with the types listed.  */
end_comment

begin_define
define|#
directive|define
name|MT_ISTS
value|0x01
end_define

begin_comment
comment|/* TS-11 */
end_comment

begin_define
define|#
directive|define
name|MT_ISHT
value|0x02
end_define

begin_comment
comment|/* TM03 Massbus: TE16, TU45, TU77 */
end_comment

begin_define
define|#
directive|define
name|MT_ISTM
value|0x03
end_define

begin_comment
comment|/* TM11/TE10 Unibus */
end_comment

begin_define
define|#
directive|define
name|MT_ISMT
value|0x04
end_define

begin_comment
comment|/* TM78/TU78 Massbus */
end_comment

begin_define
define|#
directive|define
name|MT_ISUT
value|0x05
end_define

begin_comment
comment|/* SI TU-45 emulation on Unibus */
end_comment

begin_define
define|#
directive|define
name|MT_ISCPC
value|0x06
end_define

begin_comment
comment|/* SUN */
end_comment

begin_define
define|#
directive|define
name|MT_ISAR
value|0x07
end_define

begin_comment
comment|/* SUN */
end_comment

begin_define
define|#
directive|define
name|MT_ISTMSCP
value|0x08
end_define

begin_comment
comment|/* DEC TMSCP protocol (TU81, TK50) */
end_comment

begin_define
define|#
directive|define
name|MT_ISCY
value|0x09
end_define

begin_comment
comment|/* CCI Cipher */
end_comment

begin_define
define|#
directive|define
name|MT_ISCT
value|0x0a
end_define

begin_comment
comment|/* HP 1/4 tape */
end_comment

begin_define
define|#
directive|define
name|MT_ISFHP
value|0x0b
end_define

begin_comment
comment|/* HP 7980 1/2 tape */
end_comment

begin_define
define|#
directive|define
name|MT_ISEXABYTE
value|0x0c
end_define

begin_comment
comment|/* Exabyte */
end_comment

begin_define
define|#
directive|define
name|MT_ISEXA8200
value|0x0c
end_define

begin_comment
comment|/* Exabyte EXB-8200 */
end_comment

begin_define
define|#
directive|define
name|MT_ISEXA8500
value|0x0d
end_define

begin_comment
comment|/* Exabyte EXB-8500 */
end_comment

begin_define
define|#
directive|define
name|MT_ISVIPER1
value|0x0e
end_define

begin_comment
comment|/* Archive Viper-150 */
end_comment

begin_define
define|#
directive|define
name|MT_ISPYTHON
value|0x0f
end_define

begin_comment
comment|/* Archive Python (DAT) */
end_comment

begin_define
define|#
directive|define
name|MT_ISHPDAT
value|0x10
end_define

begin_comment
comment|/* HP 35450A DAT drive */
end_comment

begin_define
define|#
directive|define
name|MT_ISMFOUR
value|0x11
end_define

begin_comment
comment|/* M4 Data 1/2 9track drive */
end_comment

begin_define
define|#
directive|define
name|MT_ISTK50
value|0x12
end_define

begin_comment
comment|/* DEC SCSI TK50 */
end_comment

begin_define
define|#
directive|define
name|MT_ISMT02
value|0x13
end_define

begin_comment
comment|/* Emulex MT02 SCSI tape controller */
end_comment

begin_comment
comment|/* mag tape io control commands */
end_comment

begin_define
define|#
directive|define
name|MTIOCTOP
value|_IOW('m', 1, struct mtop)
end_define

begin_comment
comment|/* do a mag tape op */
end_comment

begin_define
define|#
directive|define
name|MTIOCGET
value|_IOR('m', 2, struct mtget)
end_define

begin_comment
comment|/* get tape status */
end_comment

begin_comment
comment|/* these two do not appear to be used anywhere */
end_comment

begin_define
define|#
directive|define
name|MTIOCIEOT
value|_IO('m', 3)
end_define

begin_comment
comment|/* ignore EOT error */
end_comment

begin_define
define|#
directive|define
name|MTIOCEEOT
value|_IO('m', 4)
end_define

begin_comment
comment|/* enable EOT error */
end_comment

begin_comment
comment|/*  * When more SCSI-3 SSC (streaming device) devices are out there  * that support the full 32 byte type 2 structure, we'll have to  * rethink these ioctls to support all the entities they haul into  * the picture (64 bit blocks, logical file record numbers, etc..).  */
end_comment

begin_define
define|#
directive|define
name|MTIOCRDSPOS
value|_IOR('m', 5, u_int32_t)
end_define

begin_comment
comment|/* get logical blk addr */
end_comment

begin_define
define|#
directive|define
name|MTIOCRDHPOS
value|_IOR('m', 6, u_int32_t)
end_define

begin_comment
comment|/* get hardware blk addr */
end_comment

begin_define
define|#
directive|define
name|MTIOCSLOCATE
value|_IOW('m', 5, u_int32_t)
end_define

begin_comment
comment|/* seek to logical blk addr */
end_comment

begin_define
define|#
directive|define
name|MTIOCHLOCATE
value|_IOW('m', 6, u_int32_t)
end_define

begin_comment
comment|/* seek to hardware blk addr */
end_comment

begin_define
define|#
directive|define
name|MTIOCERRSTAT
value|_IOR('m', 7, union mterrstat)
end_define

begin_comment
comment|/* get tape errors */
end_comment

begin_comment
comment|/*  * Set EOT model- argument is number of filemarks to end a tape with.  * Note that not all possible values will be accepted.  */
end_comment

begin_define
define|#
directive|define
name|MTIOCSETEOTMODEL
value|_IOW('m', 8, u_int32_t)
end_define

begin_comment
comment|/* Get current EOT model */
end_comment

begin_define
define|#
directive|define
name|MTIOCGETEOTMODEL
value|_IOR('m', 8, u_int32_t)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|DEFTAPE
value|"/dev/nsa0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * minor device number  */
end_comment

begin_define
define|#
directive|define
name|T_UNIT
value|003
end_define

begin_comment
comment|/* unit selection */
end_comment

begin_define
define|#
directive|define
name|T_NOREWIND
value|004
end_define

begin_comment
comment|/* no rewind on close */
end_comment

begin_define
define|#
directive|define
name|T_DENSEL
value|030
end_define

begin_comment
comment|/* density select */
end_comment

begin_define
define|#
directive|define
name|T_800BPI
value|000
end_define

begin_comment
comment|/* select  800 bpi */
end_comment

begin_define
define|#
directive|define
name|T_1600BPI
value|010
end_define

begin_comment
comment|/* select 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|T_6250BPI
value|020
end_define

begin_comment
comment|/* select 6250 bpi */
end_comment

begin_define
define|#
directive|define
name|T_BADBPI
value|030
end_define

begin_comment
comment|/* undefined selection */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MTIO_H_ */
end_comment

end_unit

