begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rlreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_struct
struct|struct
name|rldevice
block|{
name|short
name|rlcs
decl_stmt|;
comment|/* control status */
name|u_short
name|rlba
decl_stmt|;
comment|/* bus address */
union|union
block|{
comment|/* disk address */
name|u_short
name|seek
decl_stmt|;
comment|/* disk seek address */
name|u_short
name|rw
decl_stmt|;
comment|/* disk read/write address */
name|u_short
name|getstat
decl_stmt|;
comment|/* get disk status command */
block|}
name|rlda
union|;
union|union
block|{
comment|/* multi-purpose register */
name|u_short
name|getstat
decl_stmt|;
comment|/* get status */
name|u_short
name|readhdr
decl_stmt|;
comment|/* read header */
name|u_short
name|rw
decl_stmt|;
comment|/* read/write word count */
block|}
name|rlmp
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NRLCYLN
value|512
end_define

begin_comment
comment|/* number of cylinders per disk */
end_comment

begin_define
define|#
directive|define
name|NRLTRKS
value|2
end_define

begin_comment
comment|/* number of tracks per cylinder */
end_comment

begin_define
define|#
directive|define
name|NRLSECT
value|40
end_define

begin_comment
comment|/* number of sectors per track */
end_comment

begin_define
define|#
directive|define
name|NRLBPSC
value|256
end_define

begin_comment
comment|/* bytes per sector */
end_comment

begin_comment
comment|/* rlcs */
end_comment

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|RL_NOOP
value|0000000
end_define

begin_comment
comment|/* no-operation */
end_comment

begin_define
define|#
directive|define
name|RL_WCHECK
value|0000002
end_define

begin_comment
comment|/* write check */
end_comment

begin_define
define|#
directive|define
name|RL_GETSTAT
value|0000004
end_define

begin_comment
comment|/* get status */
end_comment

begin_define
define|#
directive|define
name|RL_SEEK
value|0000006
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|RL_RHDR
value|0000010
end_define

begin_comment
comment|/* read header */
end_comment

begin_define
define|#
directive|define
name|RL_WRITE
value|0000012
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|RL_READ
value|0000014
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|RL_RDNCK
value|0000016
end_define

begin_comment
comment|/* read data without hdr check */
end_comment

begin_define
define|#
directive|define
name|RL_DRDY
value|0000001
end_define

begin_comment
comment|/* When set indicates drive ready */
end_comment

begin_define
define|#
directive|define
name|RL_BAE
value|0000060
end_define

begin_comment
comment|/* UNIBUS address bits 16& 17 */
end_comment

begin_define
define|#
directive|define
name|RL_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RL_CRDY
value|0000200
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|RL_DS0
value|0000400
end_define

begin_comment
comment|/* drive select 0 */
end_comment

begin_define
define|#
directive|define
name|RL_DS1
value|0001000
end_define

begin_comment
comment|/* drive select 1 */
end_comment

begin_define
define|#
directive|define
name|RL_OPI
value|0002000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|RL_DCRC
value|0004000
end_define

begin_comment
comment|/* CRC error occurred */
end_comment

begin_define
define|#
directive|define
name|RL_DLT
value|0010000
end_define

begin_comment
comment|/* data late or header not found */
end_comment

begin_define
define|#
directive|define
name|RL_NXM
value|0020000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|RL_DE
value|0040000
end_define

begin_comment
comment|/* selected drive flagged an error */
end_comment

begin_define
define|#
directive|define
name|RL_ERR
value|0100000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|RL_DCRDY
value|(RL_DRDY | RL_CRDY)
end_define

begin_define
define|#
directive|define
name|RLCS_BITS
define|\
value|"\10\20ERR\17DE\16NXM\15DLT\14DCRC\13OPI\1DRDY"
end_define

begin_comment
comment|/* da_seek */
end_comment

begin_define
define|#
directive|define
name|RLDA_LOW
value|0000001
end_define

begin_comment
comment|/* lower cylinder seek */
end_comment

begin_define
define|#
directive|define
name|RLDA_HGH
value|0000005
end_define

begin_comment
comment|/* higher cylinder seek */
end_comment

begin_define
define|#
directive|define
name|RLDA_HSU
value|0000000
end_define

begin_comment
comment|/* upper head select */
end_comment

begin_define
define|#
directive|define
name|RLDA_HSL
value|0000020
end_define

begin_comment
comment|/* lower head select */
end_comment

begin_define
define|#
directive|define
name|RLDA_CA
value|0177600
end_define

begin_comment
comment|/* cylinder address */
end_comment

begin_comment
comment|/* da_rw */
end_comment

begin_define
define|#
directive|define
name|RLDA_SA
value|0000077
end_define

begin_comment
comment|/* sector address */
end_comment

begin_define
define|#
directive|define
name|RLDA_HST
value|0000000
end_define

begin_comment
comment|/* upper head select */
end_comment

begin_define
define|#
directive|define
name|RLDA_HSB
value|0000100
end_define

begin_comment
comment|/* lower head select */
end_comment

begin_comment
comment|/* da_getstat */
end_comment

begin_define
define|#
directive|define
name|RL_GSTAT
value|0000003
end_define

begin_comment
comment|/* Get status */
end_comment

begin_define
define|#
directive|define
name|RL_RESET
value|0000013
end_define

begin_comment
comment|/* get status with reset */
end_comment

begin_comment
comment|/* mp_getstat */
end_comment

begin_define
define|#
directive|define
name|RLMP_STA
value|0000001
end_define

begin_comment
comment|/* drive state: load cartridge */
end_comment

begin_define
define|#
directive|define
name|RLMP_STB
value|0000002
end_define

begin_comment
comment|/* drive state: brush cycle */
end_comment

begin_define
define|#
directive|define
name|RLMP_STC
value|0000004
end_define

begin_comment
comment|/* drive state: seek */
end_comment

begin_define
define|#
directive|define
name|RLMP_BH
value|0000010
end_define

begin_comment
comment|/* set when brushes are home */
end_comment

begin_define
define|#
directive|define
name|RLMP_HO
value|0000020
end_define

begin_comment
comment|/* set when brushes over the disk */
end_comment

begin_define
define|#
directive|define
name|RLMP_CO
value|0000040
end_define

begin_comment
comment|/* set when cover open */
end_comment

begin_define
define|#
directive|define
name|RLMP_HS
value|0000100
end_define

begin_comment
comment|/* indicates selected head: 						0 upper head 						1 lower head */
end_comment

begin_define
define|#
directive|define
name|RLMP_DT
value|0000200
end_define

begin_comment
comment|/* indicates drive type: 						0 RL01 						1 RL02 */
end_comment

begin_define
define|#
directive|define
name|RLMP_DSE
value|0000400
end_define

begin_comment
comment|/* set on multiple drive selection */
end_comment

begin_define
define|#
directive|define
name|RLMP_VC
value|0001000
end_define

begin_comment
comment|/* set on pack mounted and spining */
end_comment

begin_define
define|#
directive|define
name|RLMP_WGE
value|0002000
end_define

begin_comment
comment|/* write gate error */
end_comment

begin_define
define|#
directive|define
name|RLMP_SPE
value|0004000
end_define

begin_comment
comment|/* spin speed error */
end_comment

begin_define
define|#
directive|define
name|RLMP_SKTO
value|0010000
end_define

begin_comment
comment|/*\
comment|* seek time out error */
end_comment

begin_define
define|#
directive|define
name|RLMP_WL
value|0020000
end_define

begin_comment
comment|/* set on protected drive */
end_comment

begin_define
define|#
directive|define
name|RLMP_CHE
value|0040000
end_define

begin_comment
comment|/* current head error */
end_comment

begin_define
define|#
directive|define
name|RLMP_WDE
value|0100000
end_define

begin_comment
comment|/* write data error */
end_comment

begin_comment
comment|/* mp_rhc */
end_comment

begin_define
define|#
directive|define
name|RLMP_SA
value|0000077
end_define

begin_comment
comment|/* sector address */
end_comment

begin_define
define|#
directive|define
name|RLMP_CA
value|0177600
end_define

begin_comment
comment|/* cylinder address */
end_comment

begin_comment
comment|/* check these bits after a get status and reset */
end_comment

begin_define
define|#
directive|define
name|RLMP_STATUS
value|(RLMP_WDE|RLMP_CHE|RLMP_SKTO|RLMP_SPE|RLMP_WGE \ 	|RLMP_VC|RLMP_DSE|RLMP_CO|RLMP_HO|RLMP_BH|RLMP_STC|RLMP_STB|RLMP_STA)
end_define

begin_comment
comment|/* these are the bits that should be on in the above check */
end_comment

begin_define
define|#
directive|define
name|RLMP_STATOK
value|(RLMP_HO|RLMP_BH|RLMP_STC|RLMP_STA)
end_define

begin_comment
comment|/* mp_rw */
end_comment

begin_define
define|#
directive|define
name|RLMP_WC
value|0017777
end_define

begin_comment
comment|/* word count 2's complement */
end_comment

begin_define
define|#
directive|define
name|RLER_BITS
define|\
value|"\10\20WDE\17CHE\16WL\15SKTO\14SPE\13WGE\12VC\11DSE\ \10DT\7HS\6CO\5HO\4BH\3STC\2STB\1STA"
end_define

end_unit

