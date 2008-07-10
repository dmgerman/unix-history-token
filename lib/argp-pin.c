begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Full and short program names for argp module    Copyright (C) 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PROGRAM_INVOCATION_SHORT_NAME
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|program_invocation_short_name
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PROGRAM_INVOCATION_NAME
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|program_invocation_name
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

