begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* long-options.h -- declaration for --help- and --version-handling function.    Copyright (C) 1993, 1994, 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Jim Meyering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|parse_long_options
name|PARAMS
argument_list|(
operator|(
name|int
name|_argc
operator|,
name|char
operator|*
operator|*
name|_argv
operator|,
specifier|const
name|char
operator|*
name|_command_name
operator|,
specifier|const
name|char
operator|*
name|_package
operator|,
specifier|const
name|char
operator|*
name|_version
operator|,
specifier|const
name|char
operator|*
name|_authors
operator|,
name|void
argument_list|(
operator|*
name|_usage
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

