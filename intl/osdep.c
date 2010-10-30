begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OS dependent parts of libintl.    Copyright (C) 2001-2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|__EMX__
end_if

begin_include
include|#
directive|include
file|"os2compat.c"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Avoid AIX compiler warning.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|dummy
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

