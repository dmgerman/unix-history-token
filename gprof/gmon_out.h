begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gmon_out.h     Copyright 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* A gmon.out file consists of a header (defined by gmon_hdr) followed    by a sequence of records.  Each record starts with a one-byte tag    identifying the type of records, followed by records specific data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gmon_out_h
end_ifndef

begin_define
define|#
directive|define
name|gmon_out_h
end_define

begin_define
define|#
directive|define
name|GMON_MAGIC
value|"gmon"
end_define

begin_comment
comment|/* magic cookie */
end_comment

begin_define
define|#
directive|define
name|GMON_VERSION
value|1
end_define

begin_comment
comment|/* version number */
end_comment

begin_comment
comment|/* Raw header as it appears on file (without padding).  */
end_comment

begin_struct
struct|struct
name|gmon_hdr
block|{
name|char
name|cookie
index|[
literal|4
index|]
decl_stmt|;
name|char
name|version
index|[
literal|4
index|]
decl_stmt|;
name|char
name|spare
index|[
literal|3
operator|*
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Types of records in this file.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|GMON_TAG_TIME_HIST
init|=
literal|0
block|,
name|GMON_TAG_CG_ARC
init|=
literal|1
block|,
name|GMON_TAG_BB_COUNT
init|=
literal|2
block|}
name|GMON_Record_Tag
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gmon_out_h */
end_comment

end_unit

