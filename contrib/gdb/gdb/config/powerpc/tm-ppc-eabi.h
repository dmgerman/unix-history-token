begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for Power PC running embedded ABI.    Copyright 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_PPC_EABI_H
end_ifndef

begin_define
define|#
directive|define
name|TM_PPC_EABI_H
end_define

begin_comment
comment|/* Use generic RS6000 definitions. */
end_comment

begin_include
include|#
directive|include
file|"rs6000/tm-rs6000.h"
end_include

begin_undef
undef|#
directive|undef
name|PROCESS_LINENUMBER_HOOK
end_undef

begin_undef
undef|#
directive|undef
name|TEXT_SEGMENT_BASE
end_undef

begin_define
define|#
directive|define
name|TEXT_SEGMENT_BASE
value|1
end_define

begin_comment
comment|/* The value of symbols of type N_SO and N_FUN maybe null when     it shouldn't be. */
end_comment

begin_define
define|#
directive|define
name|SOFUN_ADDRESS_MAYBE_MISSING
end_define

begin_comment
comment|/* Use generic shared library machinery.  */
end_comment

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_PPC_EABI_H */
end_comment

end_unit

