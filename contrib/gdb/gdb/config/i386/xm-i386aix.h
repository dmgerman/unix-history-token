begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for AIX PS/2 (i386)    Copyright 1986, 1987, 1989, 1992, 1993 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * Changed for IBM AIX ps/2 by Minh Tran Le (tranle@intellicorp.com)  * Revision:    23-Oct-92 17:42:49  */
end_comment

begin_include
include|#
directive|include
file|"i386/xm-i386v.h"
end_include

begin_undef
undef|#
directive|undef
name|HAVE_TERMIO
end_undef

begin_define
define|#
directive|define
name|HAVE_SGTTY
end_define

end_unit

