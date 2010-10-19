begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* winduni.h -- header file for unicode support for windres program.    Copyright 1997, 1998, 2002 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* This header file declares the types and functions we use for    unicode support in windres.  Our unicode support is very limited at    present.     We don't put this stuff in windres.h so that winduni.c doesn't have    to include windres.h.  winduni.c needs to includes windows.h, and    that would conflict with the definitions of Windows macros we    already have in windres.h.  */
end_comment

begin_comment
comment|/* We use this type to hold a unicode character.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|unichar
typedef|;
end_typedef

begin_comment
comment|/* Escape character translations.  */
end_comment

begin_define
define|#
directive|define
name|ESCAPE_A
value|(007)
end_define

begin_define
define|#
directive|define
name|ESCAPE_B
value|(010)
end_define

begin_define
define|#
directive|define
name|ESCAPE_F
value|(014)
end_define

begin_define
define|#
directive|define
name|ESCAPE_N
value|(012)
end_define

begin_define
define|#
directive|define
name|ESCAPE_R
value|(015)
end_define

begin_define
define|#
directive|define
name|ESCAPE_T
value|(011)
end_define

begin_define
define|#
directive|define
name|ESCAPE_V
value|(013)
end_define

begin_comment
comment|/* Convert an ASCII string to a unicode string.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|unicode_from_ascii
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
name|unichar
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a unicode string to a file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|unicode_print
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|unichar
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Windres support routine called by unicode_from_ascii.  This is both    here and in windres.h.  It should probably be in a separate header    file, but it hardly seems worth it for one function.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|res_alloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

