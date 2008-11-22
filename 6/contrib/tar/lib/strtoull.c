begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function to parse an `unsigned long long int' from text.    Copyright (C) 1995, 1996, 1997, 1999 Free Software Foundation, Inc.    NOTE: The canonical source of this file is maintained with the GNU C    Library.  Bugs can be reported to bug-glibc@gnu.org.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|QUAD
value|1
end_define

begin_include
include|#
directive|include
file|"strtoul.c"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_macro
name|strong_alias
argument_list|(
argument|__strtoull_internal
argument_list|,
argument|__strtouq_internal
argument_list|)
end_macro

begin_macro
name|weak_alias
argument_list|(
argument|strtoull
argument_list|,
argument|strtouq
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

