begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Print a copyright notice suitable for the current locale.    Copyright (C) 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"unicodeio.h"
end_include

begin_include
include|#
directive|include
file|"print-copyr.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|COPYRIGHT_SIGN
value|0x00A9
end_define

begin_comment
comment|/* Print "(C)".  */
end_comment

begin_function
specifier|static
name|int
name|print_parenthesized_c
parameter_list|(
name|unsigned
name|int
name|code
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
block|{
name|FILE
modifier|*
name|stream
init|=
name|callback_arg
decl_stmt|;
return|return
name|fputs
argument_list|(
literal|"(C)"
argument_list|,
name|stream
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Print "Copyright (C) " followed by NOTICE and then a newline,    transliterating "(C)" to an actual copyright sign (C-in-a-circle)    if possible.  */
end_comment

begin_function
name|void
name|print_copyright
parameter_list|(
name|char
specifier|const
modifier|*
name|notice
parameter_list|)
block|{
name|fputs
argument_list|(
literal|"Copyright "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|unicode_to_mb
argument_list|(
name|COPYRIGHT_SIGN
argument_list|,
name|print_unicode_success
argument_list|,
name|print_parenthesized_c
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|' '
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|notice
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

