begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SunOS 4.x    Copyright (C) 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|SUNOS4_SHARED_LIBRARIES
value|1
end_define

begin_comment
comment|/* Use N_BINCL stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_USE_BINCL
end_define

begin_include
include|#
directive|include
file|"sparc/sparc.h"
end_include

begin_comment
comment|/* The Sun as doesn't like unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Override MACHINE_STATE_{SAVE,RESTORE} because we have special    traps available which can get and set the condition codes    reliably.  */
end_comment

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_SAVE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_SAVE
parameter_list|(
name|ID
parameter_list|)
define|\
value|unsigned long int ms_flags, ms_saveret;		\   asm volatile("ta	0x20\n\t"			\ 	       "mov	%%g1, %0\n\t"			\ 	       "mov	%%g2, %1\n\t"			\ 	       : "=r" (ms_flags), "=r" (ms_saveret));
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_RESTORE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_RESTORE
parameter_list|(
name|ID
parameter_list|)
define|\
value|asm volatile("mov	%0, %%g1\n\t"			\ 	       "mov	%1, %%g2\n\t"			\ 	       "ta	0x21\n\t"			\ 	       :
comment|/* no outputs */
value|\ 	       : "r" (ms_flags), "r" (ms_saveret));
end_define

end_unit

