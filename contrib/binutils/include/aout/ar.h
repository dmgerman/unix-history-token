begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* archive file definition for GNU software     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* So far this is correct for BSDish archives.  Don't forget that    files must begin on an even byte boundary. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_AR_H__
end_ifndef

begin_define
define|#
directive|define
name|__GNU_AR_H__
end_define

begin_comment
comment|/* Note that the usual '\n' in magic strings may translate to different    characters, as allowed by ANSI.  '\012' has a fixed value, and remains    compatible with existing BSDish archives. */
end_comment

begin_define
define|#
directive|define
name|ARMAG
value|"!<arch>\012"
end_define

begin_comment
comment|/* For COFF and a.out archives */
end_comment

begin_define
define|#
directive|define
name|ARMAGB
value|"!<bout>\012"
end_define

begin_comment
comment|/* For b.out archives */
end_comment

begin_define
define|#
directive|define
name|SARMAG
value|8
end_define

begin_define
define|#
directive|define
name|ARFMAG
value|"`\012"
end_define

begin_comment
comment|/* The ar_date field of the armap (__.SYMDEF) member of an archive    must be greater than the modified date of the entire file, or     BSD-derived linkers complain.  We originally write the ar_date with    this offset from the real file's mod-time.  After finishing the    file, we rewrite ar_date if it's not still greater than the mod date.  */
end_comment

begin_define
define|#
directive|define
name|ARMAP_TIME_OFFSET
value|60
end_define

begin_struct
struct|struct
name|ar_hdr
block|{
name|char
name|ar_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* name of this member */
name|char
name|ar_date
index|[
literal|12
index|]
decl_stmt|;
comment|/* file mtime */
name|char
name|ar_uid
index|[
literal|6
index|]
decl_stmt|;
comment|/* owner uid; printed as decimal */
name|char
name|ar_gid
index|[
literal|6
index|]
decl_stmt|;
comment|/* owner gid; printed as decimal */
name|char
name|ar_mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* file mode, printed as octal   */
name|char
name|ar_size
index|[
literal|10
index|]
decl_stmt|;
comment|/* file size, printed as decimal */
name|char
name|ar_fmag
index|[
literal|2
index|]
decl_stmt|;
comment|/* should contain ARFMAG */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_AR_H__ */
end_comment

end_unit

