begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)saio.h	7.19 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<stand/saioctl.h>
end_include

begin_include
include|#
directive|include
file|<stand/saerrno.h>
end_include

begin_define
define|#
directive|define
name|UNIX
value|"/vmunix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I/O block */
end_comment

begin_struct
struct|struct
name|iob
block|{
name|int
name|i_flgs
decl_stmt|;
comment|/* flags (see F_*) */
name|int
name|i_adapt
decl_stmt|;
comment|/* adapter or bus */
name|int
name|i_ctlr
decl_stmt|;
comment|/* controller */
name|int
name|i_unit
decl_stmt|;
comment|/* pseudo device unit */
name|int
name|i_part
decl_stmt|;
comment|/* disk partition */
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
comment|/* memory address of I/O buffer */
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
comment|/* I/O buffer */
name|struct
name|dinode
name|i_ino
decl_stmt|;
comment|/* dinode, if file */
union|union
block|{
comment|/* file system super block info */
name|struct
name|fs
name|ui_fs
decl_stmt|;
name|char
name|dummy
index|[
name|SBSIZE
index|]
decl_stmt|;
block|}
name|i_un
union|;
define|#
directive|define
name|i_fs
value|i_un.ui_fs
define|#
directive|define
name|i_bus
value|i_adapt
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SOPEN_MAX
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|iob
name|iob
index|[
name|SOPEN_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Codes for sector header word 1 */
end_comment

begin_define
define|#
directive|define
name|HDR1_FMT22
value|0x1000
end_define

begin_comment
comment|/* standard 16 bit format */
end_comment

begin_define
define|#
directive|define
name|HDR1_OKSCT
value|0xc000
end_define

begin_comment
comment|/* sector ok */
end_comment

begin_define
define|#
directive|define
name|HDR1_SSF
value|0x2000
end_define

begin_comment
comment|/* skip sector flag */
end_comment

begin_comment
comment|/* I/O flag values */
end_comment

begin_define
define|#
directive|define
name|F_READ
value|0x0001
end_define

begin_comment
comment|/* file opened for reading */
end_comment

begin_define
define|#
directive|define
name|F_WRITE
value|0x0002
end_define

begin_comment
comment|/* file opened for writing */
end_comment

begin_define
define|#
directive|define
name|F_ALLOC
value|0x0004
end_define

begin_comment
comment|/* buffer allocated */
end_comment

begin_define
define|#
directive|define
name|F_FILE
value|0x0008
end_define

begin_comment
comment|/* file instead of device */
end_comment

begin_define
define|#
directive|define
name|F_NBSF
value|0x0010
end_define

begin_comment
comment|/* no bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|F_ECCLM
value|0x0020
end_define

begin_comment
comment|/* limit # of bits in ecc correction */
end_comment

begin_define
define|#
directive|define
name|F_SSI
value|0x0040
end_define

begin_comment
comment|/* set skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|F_SEVRE
value|0x0080
end_define

begin_comment
comment|/* Severe burnin (no retries, no ECC) */
end_comment

begin_comment
comment|/* I/O types */
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
comment|/* I/O type mask */
end_comment

begin_comment
comment|/* Lseek values */
end_comment

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_comment
comment|/* absolute offset */
end_comment

begin_comment
comment|/* Device switch */
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
specifier|extern
name|struct
name|devsw
name|devsw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ndevs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of elements in devsw[] */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_42
end_ifdef

begin_comment
comment|/*  * Old drive description table.  * still used by some drivers for now.  */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

