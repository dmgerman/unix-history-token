begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)saio.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Header file for standalone package  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"ufs/ufs/dinode.h"
end_include

begin_include
include|#
directive|include
file|"ufs/ffs/fs.h"
end_include

begin_comment
comment|/*  * Io block: includes a  * dinode, cells for the use of seek, etc,  * and a buffer.  */
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
name|dinode
name|i_ino
decl_stmt|;
comment|/* dinode, if file */
name|int
name|i_unit
decl_stmt|;
comment|/* pseudo device unit */
name|daddr_t
name|i_boff
decl_stmt|;
comment|/* block offset on device */
name|daddr_t
name|i_cyloff
decl_stmt|;
comment|/* cylinder offset on device */
name|off_t
name|i_offset
decl_stmt|;
comment|/* seek offset in file */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* associated device */
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
name|char
name|i_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
comment|/* i/o buffer */
union|union
block|{
name|struct
name|fs
name|ui_fs
decl_stmt|;
comment|/* file system super block info */
name|char
name|dummy
index|[
name|SBSIZE
index|]
decl_stmt|;
block|}
name|i_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_fs
value|i_un.ui_fs
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
name|F_SSI
value|0x40
end_define

begin_comment
comment|/* set skip sector inhibit */
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
name|NBUFS
value|4
end_define

begin_decl_stmt
name|char
name|b
index|[
name|NBUFS
index|]
index|[
name|MAXBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|blknos
index|[
name|NBUFS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFILES
value|4
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

begin_comment
comment|/* #define	EBADF	101	/* bad file descriptor */
end_comment

begin_define
define|#
directive|define
name|EOFFSET
value|102
end_define

begin_comment
comment|/* relative seek not supported */
end_comment

begin_define
define|#
directive|define
name|EDEV
value|103
end_define

begin_comment
comment|/* improper device specification on open */
end_comment

begin_comment
comment|/* #define	ENXIO	104	/* unknown device specified */
end_comment

begin_define
define|#
directive|define
name|EUNIT
value|105
end_define

begin_comment
comment|/* improper unit specification */
end_comment

begin_comment
comment|/* #define	ESRCH	106	/* directory search for file failed */
end_comment

begin_comment
comment|/* #define	EIO	107	/* generic error */
end_comment

begin_define
define|#
directive|define
name|ECMD
value|110
end_define

begin_comment
comment|/* undefined driver command */
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
comment|/* set limit to ecc correction, bits */
end_comment

begin_define
define|#
directive|define
name|SAIORETRIES
value|(('d'<<8)|7)
end_define

begin_comment
comment|/* set retry count for unit */
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
name|SAIOGBADINFO
value|(('d'<<8)|13)
end_define

begin_comment
comment|/* get bad-sector table */
end_comment

end_unit

