begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)saio.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Header file for standalone package  */
end_comment

begin_comment
comment|/*  * Io block: includes an  * inode, cells for the use of seek, etc,  * and a buffer.  */
end_comment

begin_struct
struct|struct
name|iob
block|{
name|int
name|i_flgs
decl_stmt|;
comment|/* see F_ below */
name|struct
name|inode
name|i_ino
decl_stmt|;
comment|/* inode, if file */
name|int
name|i_unit
decl_stmt|;
comment|/* pseudo device unit */
name|daddr_t
name|i_boff
decl_stmt|;
comment|/* block offset on device */
name|off_t
name|i_offset
decl_stmt|;
comment|/* seek offset in file */
name|daddr_t
name|i_bn
decl_stmt|;
comment|/* 1st block # of next read */
name|char
modifier|*
name|i_ma
decl_stmt|;
comment|/* memory address of i/o buffer */
name|int
name|i_cc
decl_stmt|;
comment|/* character count of transfer */
name|int
name|i_error
decl_stmt|;
comment|/* error # return */
name|int
name|i_errcnt
decl_stmt|;
comment|/* error count for driver retries */
name|int
name|i_errblk
decl_stmt|;
comment|/* block # in error for error reporting */
name|struct
name|fs
name|i_fs
decl_stmt|;
comment|/* file system super block info */
name|char
name|i_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
comment|/* i/o buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros to handle conversion from unit and partition to dev_t's.  */
end_comment

begin_define
define|#
directive|define
name|minor_partition
parameter_list|(
name|s
parameter_list|)
value|(s& 7)
end_define

begin_define
define|#
directive|define
name|minor_unit
parameter_list|(
name|s
parameter_list|)
value|((s>>3)& 31)
end_define

begin_define
define|#
directive|define
name|make_minor
parameter_list|(
name|u
parameter_list|,
name|p
parameter_list|)
value|((u<<3) | p)
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|F_READ
value|0x1
end_define

begin_comment
comment|/* file opened for reading */
end_comment

begin_define
define|#
directive|define
name|F_WRITE
value|0x2
end_define

begin_comment
comment|/* file opened for writing */
end_comment

begin_define
define|#
directive|define
name|F_ALLOC
value|0x4
end_define

begin_comment
comment|/* buffer allocated */
end_comment

begin_define
define|#
directive|define
name|F_FILE
value|0x8
end_define

begin_comment
comment|/* file instead of device */
end_comment

begin_define
define|#
directive|define
name|F_NBSF
value|0x10
end_define

begin_comment
comment|/* no bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|F_ECCLM
value|0x20
end_define

begin_comment
comment|/* limit # of bits in ecc correction */
end_comment

begin_define
define|#
directive|define
name|F_SSI
value|0x40
end_define

begin_comment
comment|/* set skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|F_SEVRE
value|0x80
end_define

begin_comment
comment|/* Severe burnin (no retries, no ECC) */
end_comment

begin_comment
comment|/* io types */
end_comment

begin_define
define|#
directive|define
name|F_RDDATA
value|0x0100
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|F_WRDATA
value|0x0200
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|F_HDR
value|0x0400
end_define

begin_comment
comment|/* include header on next i/o */
end_comment

begin_define
define|#
directive|define
name|F_CHECK
value|0x0800
end_define

begin_comment
comment|/* perform check of data read/write */
end_comment

begin_define
define|#
directive|define
name|F_HCHECK
value|0x1000
end_define

begin_comment
comment|/* perform check of header and data */
end_comment

begin_define
define|#
directive|define
name|F_TYPEMASK
value|0xff00
end_define

begin_comment
comment|/*  * Device switch.  */
end_comment

begin_struct
struct|struct
name|devsw
block|{
name|char
modifier|*
name|dv_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dv_strategy
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_ioctl
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Drive description table.  * Returned from SAIODEVDATA call.  */
end_comment

begin_struct
struct|struct
name|st
block|{
name|short
name|nsect
decl_stmt|;
comment|/* # sectors/track */
name|short
name|ntrak
decl_stmt|;
comment|/* # tracks/surfaces/heads */
name|short
name|nspc
decl_stmt|;
comment|/* # sectors/cylinder */
name|short
name|ncyl
decl_stmt|;
comment|/* # cylinders */
name|short
modifier|*
name|off
decl_stmt|;
comment|/* partition offset table (cylinders) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Request codes. Must be the same a F_XXX above  */
end_comment

begin_define
define|#
directive|define
name|READ
value|1
end_define

begin_define
define|#
directive|define
name|WRITE
value|2
end_define

begin_define
define|#
directive|define
name|NFILES
value|2
end_define

begin_decl_stmt
name|struct
name|iob
name|iob
index|[
name|NFILES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just like unix */
end_comment

begin_comment
comment|/* error codes */
end_comment

begin_define
define|#
directive|define
name|EBADF
value|1
end_define

begin_comment
comment|/* bad file descriptor */
end_comment

begin_define
define|#
directive|define
name|EOFFSET
value|2
end_define

begin_comment
comment|/* relative seek not supported */
end_comment

begin_define
define|#
directive|define
name|EDEV
value|3
end_define

begin_comment
comment|/* improper device specification on open */
end_comment

begin_define
define|#
directive|define
name|ENXIO
value|4
end_define

begin_comment
comment|/* unknown device specified */
end_comment

begin_define
define|#
directive|define
name|EUNIT
value|5
end_define

begin_comment
comment|/* improper unit specification */
end_comment

begin_define
define|#
directive|define
name|ESRCH
value|6
end_define

begin_comment
comment|/* directory search for file failed */
end_comment

begin_define
define|#
directive|define
name|EIO
value|7
end_define

begin_comment
comment|/* generic error */
end_comment

begin_define
define|#
directive|define
name|ECMD
value|10
end_define

begin_comment
comment|/* undefined driver command */
end_comment

begin_define
define|#
directive|define
name|EBSE
value|11
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|EWCK
value|12
end_define

begin_comment
comment|/* write check error */
end_comment

begin_define
define|#
directive|define
name|EECC
value|13
end_define

begin_comment
comment|/* uncorrectable ecc error */
end_comment

begin_define
define|#
directive|define
name|EHER
value|14
end_define

begin_comment
comment|/* hard error */
end_comment

begin_comment
comment|/* ioctl's -- for disks just now */
end_comment

begin_define
define|#
directive|define
name|SAIOHDR
value|(('d'<<8)|1)
end_define

begin_comment
comment|/* next i/o includes header */
end_comment

begin_define
define|#
directive|define
name|SAIOCHECK
value|(('d'<<8)|2)
end_define

begin_comment
comment|/* next i/o checks data */
end_comment

begin_define
define|#
directive|define
name|SAIOHCHECK
value|(('d'<<8)|3)
end_define

begin_comment
comment|/* next i/o checks header& data */
end_comment

begin_define
define|#
directive|define
name|SAIONOBAD
value|(('d'<<8)|4)
end_define

begin_comment
comment|/* inhibit bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIODOBAD
value|(('d'<<8)|5)
end_define

begin_comment
comment|/* enable bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIOECCLIM
value|(('d'<<8)|6)
end_define

begin_comment
comment|/* limit ecc correction to 5 bits */
end_comment

begin_define
define|#
directive|define
name|SAIOECCUNL
value|(('d'<<8)|7)
end_define

begin_comment
comment|/* use standard ecc procedures */
end_comment

begin_define
define|#
directive|define
name|SAIODEVDATA
value|(('d'<<8)|8)
end_define

begin_comment
comment|/* get device data */
end_comment

begin_define
define|#
directive|define
name|SAIOSSI
value|(('d'<<8)|9)
end_define

begin_comment
comment|/* set skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|SAIONOSSI
value|(('d'<<8)|10)
end_define

begin_comment
comment|/* inhibit skip sector handling */
end_comment

begin_define
define|#
directive|define
name|SAIOSSDEV
value|(('d'<<8)|11)
end_define

begin_comment
comment|/* is device skip sector type? */
end_comment

begin_define
define|#
directive|define
name|SAIODEBUG
value|(('d'<<8)|12)
end_define

begin_comment
comment|/* enable/disable debugging */
end_comment

begin_define
define|#
directive|define
name|SAIOSEVRE
value|(('d'<<8)|13)
end_define

begin_comment
comment|/* severe burnin, no ECC, no retries */
end_comment

begin_define
define|#
directive|define
name|SAIONSEVRE
value|(('d'<<8)|14)
end_define

begin_comment
comment|/* clear severe burnin */
end_comment

end_unit

