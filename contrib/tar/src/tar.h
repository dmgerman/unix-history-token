begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU tar Archive Format description.     Copyright (C) 1988, 1989, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any later    version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General    Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* If OLDGNU_COMPATIBILITY is not zero, tar produces archives which, by    default, are readable by older versions of GNU tar.  This can be    overriden by using --posix; in this case, POSIXLY_CORRECT in environment    may be set for enforcing stricter conformance.  If OLDGNU_COMPATIBILITY    is zero or undefined, tar will eventually produces archives which, by    default, POSIX compatible; then either using --posix or defining    POSIXLY_CORRECT enforces stricter conformance.     This #define will disappear in a few years.  FP, June 1995.  */
end_comment

begin_define
define|#
directive|define
name|OLDGNU_COMPATIBILITY
value|1
end_define

begin_comment
comment|/* tar Header Block, from POSIX 1003.1-1990.  */
end_comment

begin_comment
comment|/* POSIX header.  */
end_comment

begin_struct
struct|struct
name|posix_header
block|{
comment|/* byte offset */
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
comment|/*   0 */
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* 100 */
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
comment|/* 108 */
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
comment|/* 116 */
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
comment|/* 124 */
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
comment|/* 136 */
name|char
name|chksum
index|[
literal|8
index|]
decl_stmt|;
comment|/* 148 */
name|char
name|typeflag
decl_stmt|;
comment|/* 156 */
name|char
name|linkname
index|[
literal|100
index|]
decl_stmt|;
comment|/* 157 */
name|char
name|magic
index|[
literal|6
index|]
decl_stmt|;
comment|/* 257 */
name|char
name|version
index|[
literal|2
index|]
decl_stmt|;
comment|/* 263 */
name|char
name|uname
index|[
literal|32
index|]
decl_stmt|;
comment|/* 265 */
name|char
name|gname
index|[
literal|32
index|]
decl_stmt|;
comment|/* 297 */
name|char
name|devmajor
index|[
literal|8
index|]
decl_stmt|;
comment|/* 329 */
name|char
name|devminor
index|[
literal|8
index|]
decl_stmt|;
comment|/* 337 */
name|char
name|prefix
index|[
literal|155
index|]
decl_stmt|;
comment|/* 345 */
comment|/* 500 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar"
end_define

begin_comment
comment|/* ustar and a null */
end_comment

begin_define
define|#
directive|define
name|TMAGLEN
value|6
end_define

begin_define
define|#
directive|define
name|TVERSION
value|"00"
end_define

begin_comment
comment|/* 00 and no null */
end_comment

begin_define
define|#
directive|define
name|TVERSLEN
value|2
end_define

begin_comment
comment|/* Values used in typeflag field.  */
end_comment

begin_define
define|#
directive|define
name|REGTYPE
value|'0'
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|AREGTYPE
value|'\0'
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|LNKTYPE
value|'1'
end_define

begin_comment
comment|/* link */
end_comment

begin_define
define|#
directive|define
name|SYMTYPE
value|'2'
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CHRTYPE
value|'3'
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|BLKTYPE
value|'4'
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|DIRTYPE
value|'5'
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|FIFOTYPE
value|'6'
end_define

begin_comment
comment|/* FIFO special */
end_comment

begin_define
define|#
directive|define
name|CONTTYPE
value|'7'
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/* Bits used in the mode field, values in octal.  */
end_comment

begin_define
define|#
directive|define
name|TSUID
value|04000
end_define

begin_comment
comment|/* set UID on execution */
end_comment

begin_define
define|#
directive|define
name|TSGID
value|02000
end_define

begin_comment
comment|/* set GID on execution */
end_comment

begin_define
define|#
directive|define
name|TSVTX
value|01000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/* file permissions */
end_comment

begin_define
define|#
directive|define
name|TUREAD
value|00400
end_define

begin_comment
comment|/* read by owner */
end_comment

begin_define
define|#
directive|define
name|TUWRITE
value|00200
end_define

begin_comment
comment|/* write by owner */
end_comment

begin_define
define|#
directive|define
name|TUEXEC
value|00100
end_define

begin_comment
comment|/* execute/search by owner */
end_comment

begin_define
define|#
directive|define
name|TGREAD
value|00040
end_define

begin_comment
comment|/* read by group */
end_comment

begin_define
define|#
directive|define
name|TGWRITE
value|00020
end_define

begin_comment
comment|/* write by group */
end_comment

begin_define
define|#
directive|define
name|TGEXEC
value|00010
end_define

begin_comment
comment|/* execute/search by group */
end_comment

begin_define
define|#
directive|define
name|TOREAD
value|00004
end_define

begin_comment
comment|/* read by other */
end_comment

begin_define
define|#
directive|define
name|TOWRITE
value|00002
end_define

begin_comment
comment|/* write by other */
end_comment

begin_define
define|#
directive|define
name|TOEXEC
value|00001
end_define

begin_comment
comment|/* execute/search by other */
end_comment

begin_comment
comment|/* tar Header Block, GNU extensions.  */
end_comment

begin_comment
comment|/* In GNU tar, SYMTYPE is for to symbolic links, and CONTTYPE is for    contiguous files, so maybe disobeying the `reserved' comment in POSIX    header description.  I suspect these were meant to be used this way, and    should not have really been `reserved' in the published standards.  */
end_comment

begin_comment
comment|/* *BEWARE* *BEWARE* *BEWARE* that the following information is still    boiling, and may change.  Even if the OLDGNU format description should be    accurate, the so-called GNU format is not yet fully decided.  It is    surely meant to use only extensions allowed by POSIX, but the sketch    below repeats some ugliness from the OLDGNU format, which should rather    go away.  Sparse files should be saved in such a way that they do *not*    require two passes at archive creation time.  Huge files get some POSIX    fields to overflow, alternate solutions have to be sought for this.  */
end_comment

begin_comment
comment|/* Descriptor for a single file hole.  */
end_comment

begin_struct
struct|struct
name|sparse
block|{
comment|/* byte offset */
name|char
name|offset
index|[
literal|12
index|]
decl_stmt|;
comment|/*   0 */
name|char
name|numbytes
index|[
literal|12
index|]
decl_stmt|;
comment|/*  12 */
comment|/*  24 */
block|}
struct|;
end_struct

begin_comment
comment|/* Sparse files are not supported in POSIX ustar format.  For sparse files    with a POSIX header, a GNU extra header is provided which holds overall    sparse information and a few sparse descriptors.  When an old GNU header    replaces both the POSIX header and the GNU extra header, it holds some    sparse descriptors too.  Whether POSIX or not, if more sparse descriptors    are still needed, they are put into as many successive sparse headers as    necessary.  The following constants tell how many sparse descriptors fit    in each kind of header able to hold them.  */
end_comment

begin_define
define|#
directive|define
name|SPARSES_IN_EXTRA_HEADER
value|16
end_define

begin_define
define|#
directive|define
name|SPARSES_IN_OLDGNU_HEADER
value|4
end_define

begin_define
define|#
directive|define
name|SPARSES_IN_SPARSE_HEADER
value|21
end_define

begin_comment
comment|/* The GNU extra header contains some information GNU tar needs, but not    foreseen in POSIX header format.  It is only used after a POSIX header    (and never with old GNU headers), and immediately follows this POSIX    header, when typeflag is a letter rather than a digit, so signaling a GNU    extension.  */
end_comment

begin_struct
struct|struct
name|extra_header
block|{
comment|/* byte offset */
name|char
name|atime
index|[
literal|12
index|]
decl_stmt|;
comment|/*   0 */
name|char
name|ctime
index|[
literal|12
index|]
decl_stmt|;
comment|/*  12 */
name|char
name|offset
index|[
literal|12
index|]
decl_stmt|;
comment|/*  24 */
name|char
name|realsize
index|[
literal|12
index|]
decl_stmt|;
comment|/*  36 */
name|char
name|longnames
index|[
literal|4
index|]
decl_stmt|;
comment|/*  48 */
name|char
name|unused_pad1
index|[
literal|68
index|]
decl_stmt|;
comment|/*  52 */
name|struct
name|sparse
name|sp
index|[
name|SPARSES_IN_EXTRA_HEADER
index|]
decl_stmt|;
comment|/* 120 */
name|char
name|isextended
decl_stmt|;
comment|/* 504 */
comment|/* 505 */
block|}
struct|;
end_struct

begin_comment
comment|/* Extension header for sparse files, used immediately after the GNU extra    header, and used only if all sparse information cannot fit into that    extra header.  There might even be many such extension headers, one after    the other, until all sparse information has been recorded.  */
end_comment

begin_struct
struct|struct
name|sparse_header
block|{
comment|/* byte offset */
name|struct
name|sparse
name|sp
index|[
name|SPARSES_IN_SPARSE_HEADER
index|]
decl_stmt|;
comment|/*   0 */
name|char
name|isextended
decl_stmt|;
comment|/* 504 */
comment|/* 505 */
block|}
struct|;
end_struct

begin_comment
comment|/* The old GNU format header conflicts with POSIX format in such a way that    POSIX archives may fool old GNU tar's, and POSIX tar's might well be    fooled by old GNU tar archives.  An old GNU format header uses the space    used by the prefix field in a POSIX header, and cumulates information    normally found in a GNU extra header.  With an old GNU tar header, we    never see any POSIX header nor GNU extra header.  Supplementary sparse    headers are allowed, however.  */
end_comment

begin_struct
struct|struct
name|oldgnu_header
block|{
comment|/* byte offset */
name|char
name|unused_pad1
index|[
literal|345
index|]
decl_stmt|;
comment|/*   0 */
name|char
name|atime
index|[
literal|12
index|]
decl_stmt|;
comment|/* 345 */
name|char
name|ctime
index|[
literal|12
index|]
decl_stmt|;
comment|/* 357 */
name|char
name|offset
index|[
literal|12
index|]
decl_stmt|;
comment|/* 369 */
name|char
name|longnames
index|[
literal|4
index|]
decl_stmt|;
comment|/* 381 */
name|char
name|unused_pad2
decl_stmt|;
comment|/* 385 */
name|struct
name|sparse
name|sp
index|[
name|SPARSES_IN_OLDGNU_HEADER
index|]
decl_stmt|;
comment|/* 386 */
name|char
name|isextended
decl_stmt|;
comment|/* 482 */
name|char
name|realsize
index|[
literal|12
index|]
decl_stmt|;
comment|/* 483 */
comment|/* 495 */
block|}
struct|;
end_struct

begin_comment
comment|/* OLDGNU_MAGIC uses both magic and version fields, which are contiguous.    Found in an archive, it indicates an old GNU header format, which will be    hopefully become obsolescent.  With OLDGNU_MAGIC, uname and gname are    valid, though the header is not truly POSIX conforming.  */
end_comment

begin_define
define|#
directive|define
name|OLDGNU_MAGIC
value|"ustar  "
end_define

begin_comment
comment|/* 7 chars and a null */
end_comment

begin_comment
comment|/* The standards committee allows only capital A through capital Z for    user-defined expansion.  */
end_comment

begin_comment
comment|/* This is a dir entry that contains the names of files that were in the    dir at the time the dump was made.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_DUMPDIR
value|'D'
end_define

begin_comment
comment|/* Identifies the *next* file on the tape as having a long linkname.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_LONGLINK
value|'K'
end_define

begin_comment
comment|/* Identifies the *next* file on the tape as having a long name.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_LONGNAME
value|'L'
end_define

begin_comment
comment|/* This is the continuation of a file that began on another volume.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_MULTIVOL
value|'M'
end_define

begin_comment
comment|/* For storing filenames that do not fit into the main header.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_NAMES
value|'N'
end_define

begin_comment
comment|/* This is for sparse files.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_SPARSE
value|'S'
end_define

begin_comment
comment|/* This file is a tape/volume header.  Ignore it on extraction.  */
end_comment

begin_define
define|#
directive|define
name|GNUTYPE_VOLHDR
value|'V'
end_define

begin_comment
comment|/* tar Header Block, overall structure.  */
end_comment

begin_comment
comment|/* tar files are made in basic blocks of this size.  */
end_comment

begin_define
define|#
directive|define
name|BLOCKSIZE
value|512
end_define

begin_enum
enum|enum
name|archive_format
block|{
name|DEFAULT_FORMAT
block|,
comment|/* format to be decided later */
name|V7_FORMAT
block|,
comment|/* old V7 tar format */
name|OLDGNU_FORMAT
block|,
comment|/* GNU format as per before tar 1.12 */
name|POSIX_FORMAT
block|,
comment|/* restricted, pure POSIX format */
name|GNU_FORMAT
comment|/* POSIX format with GNU extensions */
block|}
enum|;
end_enum

begin_union
union|union
name|block
block|{
name|char
name|buffer
index|[
name|BLOCKSIZE
index|]
decl_stmt|;
name|struct
name|posix_header
name|header
decl_stmt|;
name|struct
name|extra_header
name|extra_header
decl_stmt|;
name|struct
name|oldgnu_header
name|oldgnu_header
decl_stmt|;
name|struct
name|sparse_header
name|sparse_header
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* End of Format description.  */
end_comment

end_unit

