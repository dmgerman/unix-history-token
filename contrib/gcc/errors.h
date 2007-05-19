begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic error reporting routines.    Copyright (C) 1999, 2000, 2001, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* warning, error, and fatal.  These definitions are suitable for use    in the generator programs; eventually we would like to use them in    cc1 too, but that's a longer term project.     N.B. We cannot presently use ATTRIBUTE_PRINTF with these functions,    because they can be extended with additional format specifiers which    GCC does not know about.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_ERRORS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_ERRORS_H
end_define

begin_comment
comment|/* The first parameter is for compatibility with the non-generator    version of warning().  For those, you'd pass an OPT_W* value from    options.h, but in generator programs it has no effect, so it's OK    to just pass zero for calls from generator-only files.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|warning
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|error
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_NORETURN
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|internal_error
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_NORETURN
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|trim_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|have_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_ERRORS_H */
end_comment

end_unit

