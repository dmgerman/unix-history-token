begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extended tar header from POSIX.1.    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TARHDR_H
end_ifndef

begin_define
define|#
directive|define
name|_TARHDR_H
value|1
end_define

begin_include
include|#
directive|include
file|<tar.h>
end_include

begin_comment
comment|/* Size of `name' field.  */
end_comment

begin_define
define|#
directive|define
name|TARNAMESIZE
value|100
end_define

begin_comment
comment|/* Size of `linkname' field.  */
end_comment

begin_define
define|#
directive|define
name|TARLINKNAMESIZE
value|100
end_define

begin_comment
comment|/* Size of `prefix' field.  */
end_comment

begin_define
define|#
directive|define
name|TARPREFIXSIZE
value|155
end_define

begin_comment
comment|/* Size of entire tar header.  */
end_comment

begin_define
define|#
directive|define
name|TARRECORDSIZE
value|512
end_define

begin_struct
struct|struct
name|tar_header
block|{
name|char
name|name
index|[
name|TARNAMESIZE
index|]
decl_stmt|;
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
name|char
name|chksum
index|[
literal|8
index|]
decl_stmt|;
name|char
name|typeflag
decl_stmt|;
name|char
name|linkname
index|[
name|TARLINKNAMESIZE
index|]
decl_stmt|;
name|char
name|magic
index|[
literal|6
index|]
decl_stmt|;
name|char
name|version
index|[
literal|2
index|]
decl_stmt|;
name|char
name|uname
index|[
literal|32
index|]
decl_stmt|;
name|char
name|gname
index|[
literal|32
index|]
decl_stmt|;
name|char
name|devmajor
index|[
literal|8
index|]
decl_stmt|;
name|char
name|devminor
index|[
literal|8
index|]
decl_stmt|;
name|char
name|prefix
index|[
name|TARPREFIXSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|tar_record
block|{
name|struct
name|tar_header
name|header
decl_stmt|;
name|char
name|buffer
index|[
name|TARRECORDSIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tarhdr.h */
end_comment

end_unit

