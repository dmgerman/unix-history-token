begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to help print --version output in a consistent format.    Copyright (C) 1999-2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Written by Jim Meyering. */
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

begin_comment
comment|/* Specification.  */
end_comment

begin_include
include|#
directive|include
file|"version-etc.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"unlocked-io.h"
end_include

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_comment
comment|/* Default copyright goes to the FSF. */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|version_etc_copyright
init|=
comment|/* Do *not* mark this string for translation.  */
literal|"Copyright (C) 2004 Free Software Foundation, Inc."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like version_etc, below, but with the NULL-terminated author list    provided via a variable of type va_list.  */
end_comment

begin_function
name|void
name|version_etc_va
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|command_name
parameter_list|,
specifier|const
name|char
modifier|*
name|package
parameter_list|,
specifier|const
name|char
modifier|*
name|version
parameter_list|,
name|va_list
name|authors
parameter_list|)
block|{
name|size_t
name|n_authors
decl_stmt|;
comment|/* Count the number of authors.  */
block|{
name|va_list
name|tmp_authors
decl_stmt|;
ifdef|#
directive|ifdef
name|va_copy
name|va_copy
argument_list|(
name|tmp_authors
argument_list|,
name|authors
argument_list|)
expr_stmt|;
else|#
directive|else
name|tmp_authors
operator|=
name|authors
expr_stmt|;
endif|#
directive|endif
name|n_authors
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|va_arg
argument_list|(
name|tmp_authors
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|!=
name|NULL
condition|)
operator|++
name|n_authors
expr_stmt|;
ifdef|#
directive|ifdef
name|va_copy
name|va_end
argument_list|(
name|tmp_authors
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|command_name
condition|)
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"%s (%s) %s\n"
argument_list|,
name|command_name
argument_list|,
name|package
argument_list|,
name|version
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"%s %s\n"
argument_list|,
name|package
argument_list|,
name|version
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|n_authors
condition|)
block|{
case|case
literal|0
case|:
comment|/* The caller must provide at least one author name.  */
name|abort
argument_list|()
expr_stmt|;
case|case
literal|1
case|:
comment|/* TRANSLATORS: %s denotes an author name.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* TRANSLATORS: Each %s denotes an author name.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* TRANSLATORS: Each %s denotes an author name.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s, %s, and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s, %s, %s,\nand %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|5
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s, %s, %s,\n%s, and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s, %s, %s,\n%s, %s, and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"Written by %s, %s, %s,\n%s, %s, %s, and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|8
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"\ Written by %s, %s, %s,\n%s, %s, %s, %s,\nand %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
case|case
literal|9
case|:
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"\ Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* 10 or more authors.  Use an abbreviation, since the human reader 	 will probably not want to read the entire list anyway.  */
comment|/* TRANSLATORS: Each %s denotes an author name. 	 You can use line breaks, estimating that each author name occupies 	 ca. 16 screen columns and that a screen line has ca. 80 columns.  */
name|vfprintf
argument_list|(
name|stream
argument_list|,
name|_
argument_list|(
literal|"\ Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n"
argument_list|)
argument_list|,
name|authors
argument_list|)
expr_stmt|;
break|break;
block|}
name|va_end
argument_list|(
name|authors
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stream
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|version_etc_copyright
argument_list|,
name|stream
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stream
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|_
argument_list|(
literal|"\ This is free software; see the source for copying conditions.  There is NO\n\ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
argument_list|)
argument_list|,
name|stream
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Display the --version information the standard way.     If COMMAND_NAME is NULL, the PACKAGE is asumed to be the name of    the program.  The formats are therefore:     PACKAGE VERSION     or     COMMAND_NAME (PACKAGE) VERSION.     The author names are passed as separate arguments, with an additional    NULL argument at the end.  */
end_comment

begin_function
name|void
name|version_etc
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|command_name
parameter_list|,
specifier|const
name|char
modifier|*
name|package
parameter_list|,
specifier|const
name|char
modifier|*
name|version
parameter_list|,
comment|/* const char *author1, ...*/
modifier|...
parameter_list|)
block|{
name|va_list
name|authors
decl_stmt|;
name|va_start
argument_list|(
name|authors
argument_list|,
name|version
argument_list|)
expr_stmt|;
name|version_etc_va
argument_list|(
name|stream
argument_list|,
name|command_name
argument_list|,
name|package
argument_list|,
name|version
argument_list|,
name|authors
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

