begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extended cpio format from POSIX.1.    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_CPIO_H
value|1
end_define

begin_comment
comment|/* A cpio archive consists of a sequence of files.    Each file has a 76 byte header,    a variable length, NUL terminated filename,    and variable length file data.    A header for a filename "TRAILER!!!" indicates the end of the archive.  */
end_comment

begin_comment
comment|/* All the fields in the header are ISO 646 (approximately ASCII) strings    of octal numbers, left padded, not NUL terminated.     Field Name	Length in Bytes	Notes    c_magic	6		must be "070707"    c_dev	6    c_ino	6    c_mode	6		see below for value    c_uid	6    c_gid	6    c_nlink	6    c_rdev	6		only valid for chr and blk special files    c_mtime	11    c_namesize	6		count includes terminating NUL in pathname    c_filesize	11		must be 0 for FIFOs and directories  */
end_comment

begin_comment
comment|/* Values for c_mode, OR'd together: */
end_comment

begin_define
define|#
directive|define
name|C_IRUSR
value|000400
end_define

begin_define
define|#
directive|define
name|C_IWUSR
value|000200
end_define

begin_define
define|#
directive|define
name|C_IXUSR
value|000100
end_define

begin_define
define|#
directive|define
name|C_IRGRP
value|000040
end_define

begin_define
define|#
directive|define
name|C_IWGRP
value|000020
end_define

begin_define
define|#
directive|define
name|C_IXGRP
value|000010
end_define

begin_define
define|#
directive|define
name|C_IROTH
value|000004
end_define

begin_define
define|#
directive|define
name|C_IWOTH
value|000002
end_define

begin_define
define|#
directive|define
name|C_IXOTH
value|000001
end_define

begin_define
define|#
directive|define
name|C_ISUID
value|004000
end_define

begin_define
define|#
directive|define
name|C_ISGID
value|002000
end_define

begin_define
define|#
directive|define
name|C_ISVTX
value|001000
end_define

begin_define
define|#
directive|define
name|C_ISBLK
value|060000
end_define

begin_define
define|#
directive|define
name|C_ISCHR
value|020000
end_define

begin_define
define|#
directive|define
name|C_ISDIR
value|040000
end_define

begin_define
define|#
directive|define
name|C_ISFIFO
value|010000
end_define

begin_define
define|#
directive|define
name|C_ISSOCK
value|0140000
end_define

begin_define
define|#
directive|define
name|C_ISLNK
value|0120000
end_define

begin_define
define|#
directive|define
name|C_ISCTG
value|0110000
end_define

begin_define
define|#
directive|define
name|C_ISREG
value|0100000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cpio.h */
end_comment

end_unit

