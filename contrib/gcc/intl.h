begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* intl.h - internationalization    Copyright 1998, 2001, 2003, 2004 Free Software Foundation, Inc.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_INTL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_INTL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|category
parameter_list|,
name|locale
parameter_list|)
value|(locale)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_function_decl
specifier|extern
name|void
name|gcc_init_libintl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|gcc_gettext_width
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Stubs.  */
end_comment

begin_undef
undef|#
directive|undef
name|textdomain
end_undef

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|domain
parameter_list|)
value|(domain)
end_define

begin_undef
undef|#
directive|undef
name|bindtextdomain
end_undef

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|domain
parameter_list|,
name|directory
parameter_list|)
value|(domain)
end_define

begin_undef
undef|#
directive|undef
name|gettext
end_undef

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|msgid
parameter_list|)
value|(msgid)
end_define

begin_define
define|#
directive|define
name|gcc_init_libintl
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|gcc_gettext_width
parameter_list|(
name|s
parameter_list|)
value|strlen(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_
end_ifndef

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_
end_ifndef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|G_
end_ifndef

begin_define
define|#
directive|define
name|G_
parameter_list|(
name|gmsgid
parameter_list|)
value|gmsgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|open_quote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|close_quote
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* intl.h */
end_comment

end_unit

