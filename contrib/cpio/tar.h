begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extended tar format from POSIX.1.    Copyright (C) 1992 Free Software Foundation, Inc.    Written by David J. MacKenzie.  This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TAR_H
end_ifndef

begin_define
define|#
directive|define
name|_TAR_H
value|1
end_define

begin_comment
comment|/* A tar archive consists of 512-byte blocks.    Each file in the archive has a header block followed by 0+ data blocks.    Two blocks of NUL bytes indicate the end of the archive.  */
end_comment

begin_comment
comment|/* The fields of header blocks:    All strings are stored as ISO 646 (approximately ASCII) strings.     Fields are numeric unless otherwise noted below; numbers are ISO 646    representations of octal numbers, with leading zeros as needed.     linkname is only valid when typeflag==LNKTYPE.  It doesn't use prefix;    files that are links to pathnames>100 chars long can not be stored    in a tar archive.     If typeflag=={LNKTYPE,SYMTYPE,DIRTYPE} then size must be 0.     devmajor and devminor are only valid for typeflag=={BLKTYPE,CHRTYPE}.     chksum contains the sum of all 512 bytes in the header block,    treating each byte as an 8-bit unsigned value and treating the    8 bytes of chksum as blank characters.     uname and gname are used in preference to uid and gid, if those    names exist locally.     Field Name	Byte Offset	Length in Bytes	Field Type    name		0		100		NUL-terminated if NUL fits    mode		100		8    uid		108		8    gid		116		8    size		124		12    mtime	136		12    chksum	148		8    typeflag	156		1		see below    linkname	157		100		NUL-terminated if NUL fits    magic	257		6		must be TMAGIC (NUL term.)    version	263		2		must be TVERSION    uname	265		32		NUL-terminated    gname	297		32		NUL-terminated    devmajor	329		8    devminor	337		8    prefix	345		155		NUL-terminated if NUL fits     If the first character of prefix is '\0', the file name is name;    otherwise, it is prefix/name.  Files whose pathnames don't fit in that    length can not be stored in a tar archive.  */
end_comment

begin_comment
comment|/* The bits in mode: */
end_comment

begin_define
define|#
directive|define
name|TSUID
value|04000
end_define

begin_define
define|#
directive|define
name|TSGID
value|02000
end_define

begin_define
define|#
directive|define
name|TSVTX
value|01000
end_define

begin_define
define|#
directive|define
name|TUREAD
value|00400
end_define

begin_define
define|#
directive|define
name|TUWRITE
value|00200
end_define

begin_define
define|#
directive|define
name|TUEXEC
value|00100
end_define

begin_define
define|#
directive|define
name|TGREAD
value|00040
end_define

begin_define
define|#
directive|define
name|TGWRITE
value|00020
end_define

begin_define
define|#
directive|define
name|TGEXEC
value|00010
end_define

begin_define
define|#
directive|define
name|TOREAD
value|00004
end_define

begin_define
define|#
directive|define
name|TOWRITE
value|00002
end_define

begin_define
define|#
directive|define
name|TOEXEC
value|00001
end_define

begin_comment
comment|/* The values for typeflag:    Values 'A'-'Z' are reserved for custom implementations.    All other values are reserved for future POSIX.1 revisions.  */
end_comment

begin_define
define|#
directive|define
name|REGTYPE
value|'0'
end_define

begin_comment
comment|/* Regular file (preferred code).  */
end_comment

begin_define
define|#
directive|define
name|AREGTYPE
value|'\0'
end_define

begin_comment
comment|/* Regular file (alternate code).  */
end_comment

begin_define
define|#
directive|define
name|LNKTYPE
value|'1'
end_define

begin_comment
comment|/* Hard link.  */
end_comment

begin_define
define|#
directive|define
name|SYMTYPE
value|'2'
end_define

begin_comment
comment|/* Symbolic link (hard if not supported).  */
end_comment

begin_define
define|#
directive|define
name|CHRTYPE
value|'3'
end_define

begin_comment
comment|/* Character special.  */
end_comment

begin_define
define|#
directive|define
name|BLKTYPE
value|'4'
end_define

begin_comment
comment|/* Block special.  */
end_comment

begin_define
define|#
directive|define
name|DIRTYPE
value|'5'
end_define

begin_comment
comment|/* Directory.  */
end_comment

begin_define
define|#
directive|define
name|FIFOTYPE
value|'6'
end_define

begin_comment
comment|/* Named pipe.  */
end_comment

begin_define
define|#
directive|define
name|CONTTYPE
value|'7'
end_define

begin_comment
comment|/* Contiguous file */
end_comment

begin_comment
comment|/* (regular file if not supported).  */
end_comment

begin_comment
comment|/* Contents of magic field and its length.  */
end_comment

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar"
end_define

begin_define
define|#
directive|define
name|TMAGLEN
value|6
end_define

begin_comment
comment|/* Contents of the version field and its length.  */
end_comment

begin_define
define|#
directive|define
name|TVERSION
value|"00"
end_define

begin_define
define|#
directive|define
name|TVERSLEN
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tar.h */
end_comment

end_unit

