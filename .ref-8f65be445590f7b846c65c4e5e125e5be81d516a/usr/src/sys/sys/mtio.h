begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mtio.h	7.6 (Berkeley) %G%  */
end_comment

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
comment|/* the following two are not yet implemented */
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
value|"/dev/rmt12"
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

end_unit

