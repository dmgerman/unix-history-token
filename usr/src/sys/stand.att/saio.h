begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	saio.h	4.7	%G%	*/
end_comment

begin_comment
comment|/*  * header file for standalone package  */
end_comment

begin_comment
comment|/*  * io block: includes an  * inode, cells for the use of seek, etc,  * and a buffer.  */
end_comment

begin_struct
struct|struct
name|iob
block|{
name|int
name|i_flgs
decl_stmt|;
name|struct
name|inode
name|i_ino
decl_stmt|;
name|int
name|i_unit
decl_stmt|;
name|daddr_t
name|i_boff
decl_stmt|;
name|daddr_t
name|i_cyloff
decl_stmt|;
name|off_t
name|i_offset
decl_stmt|;
name|daddr_t
name|i_bn
decl_stmt|;
name|char
modifier|*
name|i_ma
decl_stmt|;
name|int
name|i_cc
decl_stmt|;
name|int
name|i_error
decl_stmt|;
name|int
name|i_errcnt
decl_stmt|;
name|int
name|i_active
decl_stmt|;
name|char
name|i_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
union|union
block|{
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
comment|/*  * dev switch  */
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
comment|/*  * request codes. Must be the same a F_XXX above  */
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

begin_define
define|#
directive|define
name|PHYSUBA0
value|0x20006000
end_define

begin_define
define|#
directive|define
name|PHYSMBA0
value|0x20010000
end_define

begin_define
define|#
directive|define
name|PHYSMBA1
value|0x20012000
end_define

begin_define
define|#
directive|define
name|PHYSUMEM
value|0x2013e000
end_define

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
name|EHER
value|13
end_define

begin_comment
comment|/* hard error */
end_comment

begin_define
define|#
directive|define
name|EECC
value|14
end_define

begin_comment
comment|/* severe ecc error, sector recorded as bad*/
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

end_unit

