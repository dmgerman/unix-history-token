begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to help print --version output in a consistent format.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"unlocked-io.h"
end_include

begin_include
include|#
directive|include
file|"version-etc.h"
end_include

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|gettext (Text)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default copyright goes to the FSF. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|version_etc_copyright
init|=
comment|/* Do *not* mark this string for translation.  */
literal|"Copyright (C) 2002 Free Software Foundation, Inc."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display the --version information the standard way.     If COMMAND_NAME is NULL, the PACKAGE is asumed to be the name of    the program.  The formats are therefore:     PACKAGE VERSION     or     COMMAND_NAME (PACKAGE) VERSION.  */
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
specifier|const
name|char
modifier|*
name|authors
parameter_list|)
block|{
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
name|fprintf
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

end_unit

