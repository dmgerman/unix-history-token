begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to ARM embedded systems.    Copyright 1986, 1987, 1988, 1989, 1991, 1993, 1994, 1995, 1996, 1997,    1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_ARMEMBED_H
end_ifndef

begin_define
define|#
directive|define
name|TM_ARMEMBED_H
end_define

begin_comment
comment|/* Include the common ARM definitions. */
end_comment

begin_include
include|#
directive|include
file|"arm/tm-arm.h"
end_include

begin_comment
comment|/* The remote stub should be able to single-step. */
end_comment

begin_undef
undef|#
directive|undef
name|SOFTWARE_SINGLE_STEP_P
end_undef

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
parameter_list|()
value|0
end_define

begin_comment
comment|/* The first 0x20 bytes are the trap vectors.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOWEST_PC
end_undef

begin_define
define|#
directive|define
name|LOWEST_PC
value|0x20
end_define

begin_comment
comment|/* Override defaults.  */
end_comment

begin_undef
undef|#
directive|undef
name|THUMB_LE_BREAKPOINT
end_undef

begin_define
define|#
directive|define
name|THUMB_LE_BREAKPOINT
value|{0xbe,0xbe}
end_define

begin_undef
undef|#
directive|undef
name|THUMB_BE_BREAKPOINT
end_undef

begin_define
define|#
directive|define
name|THUMB_BE_BREAKPOINT
value|{0xbe,0xbe}
end_define

begin_comment
comment|/* Functions for dealing with Thumb call thunks.  */
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
value|arm_in_call_stub (pc, name)
end_define

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|arm_skip_stub (pc)
end_define

begin_function_decl
specifier|extern
name|int
name|arm_in_call_stub
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|arm_skip_stub
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|IN_SIGTRAMP
end_undef

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_ARMEMBED_H */
end_comment

end_unit

