begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for NetBSD/sparc.     Copyright 1986, 1987, 1989, 1992, 1994, 1996, 1999, 2000, 2002,    2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_NBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_NBSD_H
end_define

begin_comment
comment|/* Get generic NetBSD native definitions.  */
end_comment

begin_include
include|#
directive|include
file|"config/nm-nbsd.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Support for StackGhost cookies.  */
end_comment

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Fool ARI.  */
end_comment

begin_define
define|#
directive|define
name|NATIVE_XFER_WCOOKIE
value|sparc_xfer_wcookie
end_define

begin_function_decl
specifier|extern
name|LONGEST
name|sparc_xfer_wcookie
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|enum
name|target_object
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-nbsd.h */
end_comment

end_unit

