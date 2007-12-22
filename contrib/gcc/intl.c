begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Message translation utilities.    Copyright (C) 2001, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"intl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LANGINFO_CODESET
end_ifdef

begin_include
include|#
directive|include
file|<langinfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Opening quotation mark for diagnostics.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|open_quote
init|=
literal|"'"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Closing quotation mark for diagnostics.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|close_quote
init|=
literal|"'"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_comment
comment|/* Initialize the translation library for GCC.  This performs the    appropriate sequence of calls - setlocale, bindtextdomain,    textdomain.  LC_CTYPE determines the character set used by the    terminal, so it has be set to output messages correctly.  */
end_comment

begin_function
name|void
name|gcc_init_libintl
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_LC_MESSAGES
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|setlocale
argument_list|(
name|LC_MESSAGES
argument_list|,
literal|""
argument_list|)
expr_stmt|;
else|#
directive|else
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|bindtextdomain
argument_list|(
literal|"gcc"
argument_list|,
name|LOCALEDIR
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|textdomain
argument_list|(
literal|"gcc"
argument_list|)
expr_stmt|;
comment|/* Opening quotation mark.  */
name|open_quote
operator|=
name|_
argument_list|(
literal|"`"
argument_list|)
expr_stmt|;
comment|/* Closing quotation mark.  */
name|close_quote
operator|=
name|_
argument_list|(
literal|"'"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|open_quote
argument_list|,
literal|"`"
argument_list|)
operator|&&
operator|!
name|strcmp
argument_list|(
name|close_quote
argument_list|,
literal|"'"
argument_list|)
condition|)
block|{
if|#
directive|if
name|defined
name|HAVE_LANGINFO_CODESET
specifier|const
name|char
modifier|*
name|encoding
decl_stmt|;
endif|#
directive|endif
comment|/* Untranslated quotes that it may be possible to replace with 	 U+2018 and U+2019; but otherwise use "'" instead of "`" as 	 opening quote.  */
name|open_quote
operator|=
literal|"'"
expr_stmt|;
if|#
directive|if
name|defined
name|HAVE_LANGINFO_CODESET
name|encoding
operator|=
name|nl_langinfo
argument_list|(
name|CODESET
argument_list|)
expr_stmt|;
if|if
condition|(
name|encoding
operator|!=
name|NULL
operator|&&
operator|(
operator|!
name|strcasecmp
argument_list|(
name|encoding
argument_list|,
literal|"utf-8"
argument_list|)
operator|||
operator|!
name|strcasecmp
argument_list|(
name|encoding
argument_list|,
literal|"utf8"
argument_list|)
operator|)
condition|)
block|{
name|open_quote
operator|=
literal|"\xe2\x80\x98"
expr_stmt|;
name|close_quote
operator|=
literal|"\xe2\x80\x99"
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
end_function

begin_if
if|#
directive|if
name|defined
name|HAVE_WCHAR_H
operator|&&
name|defined
name|HAVE_WORKING_MBSTOWCS
operator|&&
name|defined
name|HAVE_WCSWIDTH
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_comment
comment|/* Returns the width in columns of MSGSTR, which came from gettext.    This is for indenting subsequent output.  */
end_comment

begin_function
name|size_t
name|gcc_gettext_width
parameter_list|(
specifier|const
name|char
modifier|*
name|msgstr
parameter_list|)
block|{
name|size_t
name|nwcs
init|=
name|mbstowcs
argument_list|(
literal|0
argument_list|,
name|msgstr
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|wchar_t
modifier|*
name|wmsgstr
init|=
name|alloca
argument_list|(
operator|(
name|nwcs
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
decl_stmt|;
name|mbstowcs
argument_list|(
name|wmsgstr
argument_list|,
name|msgstr
argument_list|,
name|nwcs
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|wcswidth
argument_list|(
name|wmsgstr
argument_list|,
name|nwcs
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no wcswidth */
end_comment

begin_comment
comment|/* We don't have any way of knowing how wide the string is.  Guess    the length of the string.  */
end_comment

begin_function
name|size_t
name|gcc_gettext_width
parameter_list|(
specifier|const
name|char
modifier|*
name|msgstr
parameter_list|)
block|{
return|return
name|strlen
argument_list|(
name|msgstr
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_NLS */
end_comment

end_unit

