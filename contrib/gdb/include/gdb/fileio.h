begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hosted File I/O interface definitions, for GDB, the GNU Debugger.     Copyright 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_FILEIO_H_
end_ifndef

begin_define
define|#
directive|define
name|GDB_FILEIO_H_
end_define

begin_comment
comment|/* The following flags are defined to be independent of the host    as well as the target side implementation of these constants.    All constants are defined with a leading FILEIO_ in the name    to allow the usage of these constants together with the    corresponding implementation dependent constants in one module. */
end_comment

begin_comment
comment|/* open(2) flags */
end_comment

begin_define
define|#
directive|define
name|FILEIO_O_RDONLY
value|0x0
end_define

begin_define
define|#
directive|define
name|FILEIO_O_WRONLY
value|0x1
end_define

begin_define
define|#
directive|define
name|FILEIO_O_RDWR
value|0x2
end_define

begin_define
define|#
directive|define
name|FILEIO_O_APPEND
value|0x8
end_define

begin_define
define|#
directive|define
name|FILEIO_O_CREAT
value|0x200
end_define

begin_define
define|#
directive|define
name|FILEIO_O_TRUNC
value|0x400
end_define

begin_define
define|#
directive|define
name|FILEIO_O_EXCL
value|0x800
end_define

begin_define
define|#
directive|define
name|FILEIO_O_SUPPORTED
value|(FILEIO_O_RDONLY | FILEIO_O_WRONLY| \ 				 FILEIO_O_RDWR   | FILEIO_O_APPEND| \ 				 FILEIO_O_CREAT  | FILEIO_O_TRUNC| \ 				 FILEIO_O_EXCL)
end_define

begin_comment
comment|/* mode_t bits */
end_comment

begin_define
define|#
directive|define
name|FILEIO_S_IFREG
value|0100000
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IFDIR
value|040000
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IFCHR
value|020000
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IRUSR
value|0400
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IWUSR
value|0200
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IXUSR
value|0100
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IRWXU
value|0700
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IRGRP
value|040
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IWGRP
value|020
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IXGRP
value|010
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IRWXG
value|070
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IROTH
value|04
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IWOTH
value|02
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IXOTH
value|01
end_define

begin_define
define|#
directive|define
name|FILEIO_S_IRWXO
value|07
end_define

begin_define
define|#
directive|define
name|FILEIO_S_SUPPORTED
value|(FILEIO_S_IFREG|FILEIO_S_IFDIR|  \ 				    FILEIO_S_IRWXU|FILEIO_S_IRWXG|  \                                     FILEIO_S_IRWXO)
end_define

begin_comment
comment|/* lseek(2) flags */
end_comment

begin_define
define|#
directive|define
name|FILEIO_SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|FILEIO_SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|FILEIO_SEEK_END
value|2
end_define

begin_comment
comment|/* errno values */
end_comment

begin_define
define|#
directive|define
name|FILEIO_EPERM
value|1
end_define

begin_define
define|#
directive|define
name|FILEIO_ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|FILEIO_EINTR
value|4
end_define

begin_define
define|#
directive|define
name|FILEIO_EIO
value|5
end_define

begin_define
define|#
directive|define
name|FILEIO_EBADF
value|9
end_define

begin_define
define|#
directive|define
name|FILEIO_EACCES
value|13
end_define

begin_define
define|#
directive|define
name|FILEIO_EFAULT
value|14
end_define

begin_define
define|#
directive|define
name|FILEIO_EBUSY
value|16
end_define

begin_define
define|#
directive|define
name|FILEIO_EEXIST
value|17
end_define

begin_define
define|#
directive|define
name|FILEIO_ENODEV
value|19
end_define

begin_define
define|#
directive|define
name|FILEIO_ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|FILEIO_EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|FILEIO_EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|FILEIO_ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|FILEIO_EMFILE
value|24
end_define

begin_define
define|#
directive|define
name|FILEIO_EFBIG
value|27
end_define

begin_define
define|#
directive|define
name|FILEIO_ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|FILEIO_ESPIPE
value|29
end_define

begin_define
define|#
directive|define
name|FILEIO_EROFS
value|30
end_define

begin_define
define|#
directive|define
name|FILEIO_ENOSYS
value|88
end_define

begin_define
define|#
directive|define
name|FILEIO_ENAMETOOLONG
value|91
end_define

begin_define
define|#
directive|define
name|FILEIO_EUNKNOWN
value|9999
end_define

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|FILEIO_INT_MIN
value|-2147483648L
end_define

begin_define
define|#
directive|define
name|FILEIO_INT_MAX
value|2147483647L
end_define

begin_define
define|#
directive|define
name|FILEIO_UINT_MAX
value|4294967295UL
end_define

begin_define
define|#
directive|define
name|FILEIO_LONG_MIN
value|-9223372036854775808LL
end_define

begin_define
define|#
directive|define
name|FILEIO_LONG_MAX
value|9223372036854775807LL
end_define

begin_define
define|#
directive|define
name|FILEIO_ULONG_MAX
value|18446744073709551615ULL
end_define

begin_comment
comment|/* Integral types as used in protocol. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef __int32_t fio_int_t; typedef __uint32_t fio_uint_t, fio_mode_t, fio_time_t; typedef __int64_t fio_long_t; typedef __uint64_t fio_ulong_t;
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FIO_INT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|FIO_UINT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|FIO_MODE_LEN
value|4
end_define

begin_define
define|#
directive|define
name|FIO_TIME_LEN
value|4
end_define

begin_define
define|#
directive|define
name|FIO_LONG_LEN
value|8
end_define

begin_define
define|#
directive|define
name|FIO_ULONG_LEN
value|8
end_define

begin_typedef
typedef|typedef
name|char
name|fio_int_t
index|[
name|FIO_INT_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fio_uint_t
index|[
name|FIO_UINT_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fio_mode_t
index|[
name|FIO_MODE_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fio_time_t
index|[
name|FIO_TIME_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fio_long_t
index|[
name|FIO_LONG_LEN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fio_ulong_t
index|[
name|FIO_ULONG_LEN
index|]
typedef|;
end_typedef

begin_comment
comment|/* Struct stat as used in protocol.  For complete independence    of host/target systems, it's defined as an array with offsets    to the members. */
end_comment

begin_struct
struct|struct
name|fio_stat
block|{
name|fio_uint_t
name|fst_dev
decl_stmt|;
name|fio_uint_t
name|fst_ino
decl_stmt|;
name|fio_mode_t
name|fst_mode
decl_stmt|;
name|fio_uint_t
name|fst_nlink
decl_stmt|;
name|fio_uint_t
name|fst_uid
decl_stmt|;
name|fio_uint_t
name|fst_gid
decl_stmt|;
name|fio_uint_t
name|fst_rdev
decl_stmt|;
name|fio_ulong_t
name|fst_size
decl_stmt|;
name|fio_ulong_t
name|fst_blksize
decl_stmt|;
name|fio_ulong_t
name|fst_blocks
decl_stmt|;
name|fio_time_t
name|fst_atime
decl_stmt|;
name|fio_time_t
name|fst_mtime
decl_stmt|;
name|fio_time_t
name|fst_ctime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fio_timeval
block|{
name|fio_time_t
name|ftv_sec
decl_stmt|;
name|fio_long_t
name|ftv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_FILEIO_H_ */
end_comment

end_unit

