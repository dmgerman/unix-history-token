begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for functions found in mbchar.c    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_MBCHAR_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_MBCHAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIBYTE_CHARS
end_ifdef

begin_comment
comment|/* Escape character used for JIS encoding */
end_comment

begin_define
define|#
directive|define
name|JIS_ESC_CHAR
value|0x1b
end_define

begin_define
define|#
directive|define
name|ISSJIS1
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x81&& (c)<= 0x9f) || ((c)>= 0xe0&& (c)<= 0xef))
end_define

begin_define
define|#
directive|define
name|ISSJIS2
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x40&& (c)<= 0x7e) || ((c)>= 0x80&& (c)<= 0xfc))
end_define

begin_define
define|#
directive|define
name|ISEUCJP
parameter_list|(
name|c
parameter_list|)
value|((c)>= 0xa1&& (c)<= 0xfe)
end_define

begin_define
define|#
directive|define
name|ISJIS
parameter_list|(
name|c
parameter_list|)
value|((c)>= 0x21&& (c)<= 0x7e)
end_define

begin_decl_stmt
specifier|extern
name|int
name|local_mbtowc
name|PARAMS
argument_list|(
operator|(
name|wchar_t
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|local_mblen
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|local_mb_cur_max
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The locale being used for multibyte characters in string/char literals.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|literal_codeset
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIBYTE_CHARS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_MBCHAR_H */
end_comment

end_unit

