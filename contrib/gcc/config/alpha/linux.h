begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for Alpha Linux-based GNU systems.    Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Richard Henderson.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dlinux -Dunix -Asystem(linux) -D_LONGLONG -D__alpha__ " \ SUB_CPP_PREDEFINES
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-lgmon} %{pg:-lc_p} %{!pg:-lc}"
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc. */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
value|1
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fputs ("\tlda $28,_mcount\n\tjsr $28,($28),_mcount\n", (FILE))
end_define

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
value|1
end_define

begin_comment
comment|/* Don't care about faults in the prologue.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_CAN_FAULT_IN_PROLOGUE
end_undef

begin_define
define|#
directive|define
name|TARGET_CAN_FAULT_IN_PROLOGUE
value|1
end_define

end_unit

