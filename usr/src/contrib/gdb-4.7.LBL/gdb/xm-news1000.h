begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for a Sony/NEWS series 1000 with News-OS version 3,    for GDB, the GNU debugger.    Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is required by Sony include files like<sys/user.h> so we    get the right offset into the u area.  Relying on the compiler    to define this only works for cc, not gcc.  */
end_comment

begin_undef
undef|#
directive|undef
name|mc68030
end_undef

begin_define
define|#
directive|define
name|mc68030
end_define

begin_include
include|#
directive|include
file|"xm-news.h"
end_include

end_unit

