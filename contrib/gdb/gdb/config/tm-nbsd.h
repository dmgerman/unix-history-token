begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine sub-description for NetBSD.    This is included by other tm-*.h files to specify NetBSD-specific stuff.    Copyright 1993, 1994 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4_SHARED_LIBS
end_ifndef

begin_comment
comment|/* Return non-zero if we are in a shared library trampoline code stub. */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
define|\
value|(name&& !strcmp(name, "_DYNAMIC"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SVR4_SHARED_LIBS */
end_comment

end_unit

