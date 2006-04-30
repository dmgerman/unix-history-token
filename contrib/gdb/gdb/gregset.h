begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for functions using gregset and fpregset types.    Copyright 2000, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GREGSET_H
end_ifndef

begin_define
define|#
directive|define
name|GREGSET_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_GREGSET_T
end_ifndef

begin_define
define|#
directive|define
name|GDB_GREGSET_T
value|gregset_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_FPREGSET_T
end_ifndef

begin_define
define|#
directive|define
name|GDB_FPREGSET_T
value|fpregset_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|GDB_GREGSET_T
name|gdb_gregset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|GDB_FPREGSET_T
name|gdb_fpregset_t
typedef|;
end_typedef

begin_comment
comment|/* A gregset is a data structure supplied by the native OS containing    the general register values of the debugged process.  Usually this    includes integer registers and control registers.  An fpregset is a    data structure containing the floating point registers.  These data    structures were originally a part of the /proc interface, but have    been borrowed or copied by other GDB targets, eg. GNU/Linux.  */
end_comment

begin_comment
comment|/* Copy register values from the native target gregset/fpregset    into GDB's internal register cache.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|supply_gregset
parameter_list|(
name|gdb_gregset_t
modifier|*
name|gregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|supply_fpregset
parameter_list|(
name|gdb_fpregset_t
modifier|*
name|fpregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy register values from GDB's register cache into    the native target gregset/fpregset.  If regno is -1,     copy all the registers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|fill_gregset
parameter_list|(
name|gdb_gregset_t
modifier|*
name|gregs
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fill_fpregset
parameter_list|(
name|gdb_fpregset_t
modifier|*
name|fpregs
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FILL_FPXREGSET
end_ifdef

begin_comment
comment|/* GNU/Linux i386: Copy register values between GDB's internal register cache    and the i386 extended floating point registers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_FPXREGSET_T
end_ifndef

begin_define
define|#
directive|define
name|GDB_FPXREGSET_T
value|elf_fpxregset_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|GDB_FPXREGSET_T
name|gdb_fpxregset_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|supply_fpxregset
parameter_list|(
name|gdb_fpxregset_t
modifier|*
name|fpxregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fill_fpxregset
parameter_list|(
name|gdb_fpxregset_t
modifier|*
name|fpxregs
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

