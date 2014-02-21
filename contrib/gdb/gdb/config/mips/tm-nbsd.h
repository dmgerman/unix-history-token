begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for NetBSD/mips.    Copyright 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_NBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_NBSD_H
end_define

begin_include
include|#
directive|include
file|"mips/tm-mips.h"
end_include

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* We don't want to inherit tm-mips.h's shared library trampoline code.  */
end_comment

begin_undef
undef|#
directive|undef
name|IN_SOLIB_CALL_TRAMPOLINE
end_undef

begin_undef
undef|#
directive|undef
name|IN_SOLIB_RETURN_TRAMPOLINE
end_undef

begin_undef
undef|#
directive|undef
name|SKIP_TRAMPOLINE_CODE
end_undef

begin_undef
undef|#
directive|undef
name|IGNORE_HELPER_CALL
end_undef

begin_comment
comment|/* XXX undef a bunch of stuff we want to use multi-arch */
end_comment

begin_undef
undef|#
directive|undef
name|IN_SIGTRAMP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_NBSD_H */
end_comment

end_unit

