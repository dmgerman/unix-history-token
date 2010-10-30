begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Determine a canonical name for the current locale's character encoding.    Copyright (C) 2000-2003 Free Software Foundation, Inc.    This file is part of the GNU CHARSET Library.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCALCHARSET_H
end_ifndef

begin_define
define|#
directive|define
name|_LOCALCHARSET_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Determine the current locale's character encoding, and canonicalize it    into one of the canonical names listed in config.charset.    The result must not be freed; it is statically allocated.    If the canonical name cannot be determined, the result is a non-canonical    name.  */
specifier|extern
specifier|const
name|char
modifier|*
name|locale_charset
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCALCHARSET_H */
end_comment

end_unit

