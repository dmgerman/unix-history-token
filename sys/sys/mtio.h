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
name|KERNEL
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
comment|/* Set density values for device. They are defined in the SCSI II spec	*/
end_comment

begin_comment
comment|/* and range from 0 to 0x17. Sets the value for the opened mode only	*/
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

begin_endif
endif|#
directive|endif
end_endif

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
name|daddr_t
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
name|u_char
name|mt_comp0
decl_stmt|;
comment|/* compression type for mode 0 */
name|u_char
name|mt_comp1
decl_stmt|;
comment|/* compression type for mode 1 */
name|u_char
name|mt_comp2
decl_stmt|;
comment|/* compression type for mode 2 */
name|u_char
name|mt_comp3
decl_stmt|;
comment|/* compression type for mode 3 */
endif|#
directive|endif
name|daddr_t
name|mt_fileno
decl_stmt|;
comment|/* file number of current position */
name|daddr_t
name|mt_blkno
decl_stmt|;
comment|/* block number of current position */
comment|/* end not yet implemented */
block|}
struct|;
end_struct

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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|DEFTAPE
value|"/dev/nrst0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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

