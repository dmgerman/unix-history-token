begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* winduni.h -- header file for unicode support for windres program.    Copyright 1997, 1998, 2002, 2007    Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.    Rewritten by Kai Tietz, Onevision.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINDUNI_H
end_ifndef

begin_define
define|#
directive|define
name|WINDUNI_H
end_define

begin_comment
comment|/* This header file declares the types and functions we use for    unicode support in windres.  Our unicode support is very limited at    present.     We don't put this stuff in windres.h so that winduni.c doesn't have    to include windres.h.  winduni.c needs to includes windows.h, and    that would conflict with the definitions of Windows macros we    already have in windres.h.  */
end_comment

begin_comment
comment|/* Use bfd_size_type to ensure a sufficient number of bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFINED_RC_UINT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|DEFINED_RC_UINT_TYPE
end_define

begin_typedef
typedef|typedef
name|bfd_size_type
name|rc_uint_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
value|007
end_define

begin_define
define|#
directive|define
name|ESCAPE_B
value|010
end_define

begin_define
define|#
directive|define
name|ESCAPE_F
value|014
end_define

begin_define
define|#
directive|define
name|ESCAPE_N
value|012
end_define

begin_define
define|#
directive|define
name|ESCAPE_R
value|015
end_define

begin_define
define|#
directive|define
name|ESCAPE_T
value|011
end_define

begin_define
define|#
directive|define
name|ESCAPE_V
value|013
end_define

begin_comment
comment|/* Convert an ASCII string to a unicode string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unicode_from_ascii
parameter_list|(
name|rc_uint_type
modifier|*
parameter_list|,
name|unichar
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an unicode string to an ASCII string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ascii_from_unicode
parameter_list|(
name|rc_uint_type
modifier|*
parameter_list|,
specifier|const
name|unichar
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Duplicate a unicode string by using res_alloc.  */
end_comment

begin_function_decl
specifier|extern
name|unichar
modifier|*
name|unichar_dup
parameter_list|(
specifier|const
name|unichar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Duplicate a unicode string by using res_alloc and make it uppercase.  */
end_comment

begin_function_decl
specifier|extern
name|unichar
modifier|*
name|unichar_dup_uppercase
parameter_list|(
specifier|const
name|unichar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The count of unichar elements.  */
end_comment

begin_function_decl
specifier|extern
name|rc_uint_type
name|unichar_len
parameter_list|(
specifier|const
name|unichar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a unicode string to a file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unicode_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|unichar
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a ascii string to a file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ascii_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a quoted unicode string to a file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unicode_print_quoted
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|unichar
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|CP_UTF8
end_ifndef

begin_define
define|#
directive|define
name|CP_UTF7
value|65000
end_define

begin_comment
comment|/* UTF-7 translation.  */
end_comment

begin_define
define|#
directive|define
name|CP_UTF8
value|65001
end_define

begin_comment
comment|/* UTF-8 translation.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CP_UTF16
end_ifndef

begin_define
define|#
directive|define
name|CP_UTF16
value|65002
end_define

begin_comment
comment|/* UTF-16 translation.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CP_ACP
end_ifndef

begin_define
define|#
directive|define
name|CP_ACP
value|0
end_define

begin_comment
comment|/* Default to ANSI code page.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CP_OEM
end_ifndef

begin_define
define|#
directive|define
name|CP_OEM
value|1
end_define

begin_comment
comment|/* Default OEM code page. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specifies the default codepage to be used for unicode    transformations.  By default this is CP_ACP.  */
end_comment

begin_decl_stmt
specifier|extern
name|rc_uint_type
name|wind_default_codepage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specifies the currently used codepage for unicode    transformations.  By default this is CP_ACP.  */
end_comment

begin_decl_stmt
specifier|extern
name|rc_uint_type
name|wind_current_codepage
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|wind_language_t
block|{
name|unsigned
name|id
decl_stmt|;
name|unsigned
name|doscp
decl_stmt|;
name|unsigned
name|wincp
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|country
decl_stmt|;
block|}
name|wind_language_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|wind_language_t
modifier|*
name|wind_find_language_by_id
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unicode_is_valid_codepage
parameter_list|(
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|local_iconv_map
block|{
name|rc_uint_type
name|codepage
decl_stmt|;
specifier|const
name|char
modifier|*
name|iconv_name
decl_stmt|;
block|}
name|local_iconv_map
typedef|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|local_iconv_map
modifier|*
name|wind_find_codepage_info
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an Codepage string to a unicode string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unicode_from_codepage
parameter_list|(
name|rc_uint_type
modifier|*
parameter_list|,
name|unichar
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an unicode string to an codepage string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|codepage_from_unicode
parameter_list|(
name|rc_uint_type
modifier|*
parameter_list|,
specifier|const
name|unichar
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Windres support routine called by unicode_from_ascii.  This is both    here and in windres.h.  It should probably be in a separate header    file, but it hardly seems worth it for one function.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|res_alloc
parameter_list|(
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

