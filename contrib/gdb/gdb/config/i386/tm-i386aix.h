begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for IBM AIX PS/2 (i386).    Copyright 1986, 1987, 1989, 1992, 1993, 1994, 1995, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Changes for IBM AIX PS/2 by Minh Tran-Le (tranle@intellicorp.com).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386AIX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386AIX_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|I386
end_ifndef

begin_define
define|#
directive|define
name|I386
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX/i386 has FPU support.  However, the native configuration (which    is the only supported configuration) doesn't make the FPU control    registers available.  Override the appropriate symbols such that    only the normal FPU registers are included in GDB's register array.  */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_FPREGS
end_undef

begin_define
define|#
directive|define
name|NUM_FPREGS
value|(8)
end_define

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|(NUM_GREGS + NUM_FPREGS)
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(SIZEOF_GREGS + SIZEOF_FPU_REGS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_I386AIX_H */
end_comment

end_unit

