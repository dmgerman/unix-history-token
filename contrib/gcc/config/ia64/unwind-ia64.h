begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Andrew MacLeod<amacleod@cygnus.com>                   Andrew Haley<aph@cygnus.com>     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* On FreeBSD, _Unwind_FindTableEntry is in libc, and must not be hidden here. */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_HIDDEN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_HIDDEN
value|__attribute__ ((__visibility__ ("hidden")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|unw_table_entry
block|{
name|unsigned
name|long
name|start_offset
decl_stmt|;
name|unsigned
name|long
name|end_offset
decl_stmt|;
name|unsigned
name|long
name|info_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|unw_table_entry
modifier|*
name|_Unwind_FindTableEntry
argument_list|(
name|void
operator|*
name|pc
argument_list|,
name|unsigned
name|long
operator|*
name|segment_base
argument_list|,
name|unsigned
name|long
operator|*
name|gp
argument_list|)
name|ATTRIBUTE_HIDDEN
decl_stmt|;
end_decl_stmt

end_unit

