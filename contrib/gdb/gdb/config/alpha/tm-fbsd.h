begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for FreeBSD/Alpha.    Copyright 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_FBSD_H
end_define

begin_include
include|#
directive|include
file|"alpha/tm-alpha.h"
end_include

begin_comment
comment|/* FreeBSD uses the old gcc convention for struct returns.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STRUCT_CONVENTION
end_undef

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
define|\
value|alphafbsd_use_struct_convention (gcc_p, type)
end_define

begin_comment
comment|/* FreeBSD doesn't mark the outermost frame.  While some FreeBSD/Alpha    releases include (a minimal amount of) debugging info in its    startup code (crt1.o), the safest thing is to consider the user    code entry point as the outermost frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|func_frame_chain_valid(chain, thisframe)
end_define

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  The    default is right for FreeBSD.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_FBSD_H */
end_comment

end_unit

