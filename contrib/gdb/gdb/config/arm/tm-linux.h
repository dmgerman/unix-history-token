begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU/Linux on ARM, for GDB.    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_ARMLINUX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_ARMLINUX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GDBSERVER
end_ifdef

begin_define
define|#
directive|define
name|ARM_GNULINUX_TARGET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the common ARM target definitions.  */
end_comment

begin_include
include|#
directive|include
file|"arm/tm-arm.h"
end_include

begin_include
include|#
directive|include
file|"tm-linux.h"
end_include

begin_comment
comment|/* Use target-specific function to define link map offsets.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|link_map_offsets
modifier|*
name|arm_linux_svr4_fetch_link_map_offsets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SVR4_FETCH_LINK_MAP_OFFSETS
parameter_list|()
value|arm_linux_svr4_fetch_link_map_offsets ()
end_define

begin_comment
comment|/* Offset to saved PC in sigcontext structure, from<asm/sigcontext.h> */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|(sizeof(unsigned long) * 18)
end_define

begin_comment
comment|/* We've multi-arched this.  */
end_comment

begin_undef
undef|#
directive|undef
name|IN_SOLIB_CALL_TRAMPOLINE
end_undef

begin_comment
comment|/* On ARM GNU/Linux, a call to a library routine does not have to go    through any trampoline code.  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_RETURN_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|0
end_define

begin_comment
comment|/* We've multi-arched this.  */
end_comment

begin_undef
undef|#
directive|undef
name|SKIP_TRAMPOLINE_CODE
end_undef

begin_comment
comment|/* When we call a function in a shared library, and the PLT sends us    into the dynamic linker to find the function's real address, we    need to skip over the dynamic linker call.  This function decides    when to skip, and where to skip to.  See the comments for    SKIP_SOLIB_RESOLVER at the top of infrun.c.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|arm_linux_skip_solib_resolver
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SKIP_SOLIB_RESOLVER
value|arm_linux_skip_solib_resolver
end_define

begin_comment
comment|/* When we call a function in a shared library, and the PLT sends us    into the dynamic linker to find the function's real address, we    need to skip over the dynamic linker call.  This function decides    when to skip, and where to skip to.  See the comments for    SKIP_SOLIB_RESOLVER at the top of infrun.c.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|IN_SOLIB_DYNSYM_RESOLVE_CODE
end_undef

begin_define
unit|extern CORE_ADDR arm_in_solib_dynsym_resolve_code (CORE_ADDR pc, char *name);
define|#
directive|define
name|IN_SOLIB_DYNSYM_RESOLVE_CODE
value|arm_in_solib_dynsym_resolve_code
end_define

begin_comment
comment|/* ScottB: Current definition is  extern CORE_ADDR in_svr4_dynsym_resolve_code (CORE_ADDR pc, char *name); #define IN_SOLIB_DYNSYM_RESOLVE_CODE  in_svr4_dynsym_resolve_code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When the ARM Linux kernel invokes a signal handler, the return    address points at a special instruction which'll trap back into    the kernel.  These definitions are used to identify this bit of    code as a signal trampoline in order to support backtracing    through calls to signal handlers. */
end_comment

begin_function_decl
name|int
name|arm_linux_in_sigtramp
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

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|arm_linux_in_sigtramp (pc, name)
end_define

begin_comment
comment|/* Each OS has different mechanisms for accessing the various    registers stored in the sigcontext structure.  These definitions    provide a mechanism by which the generic code in arm-tdep.c can    find the addresses at which various registers are saved at in the    sigcontext structure.  If SIGCONTEXT_REGISTER_ADDRESS is not    defined, arm-tdep.c will define it to be 0.  (See ia64-tdep.c and    ia64-linux-tdep.c to see what a similar mechanism looks like when    multi-arched.) */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|arm_linux_sigcontext_register_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SIGCONTEXT_REGISTER_ADDRESS
value|arm_linux_sigcontext_register_address
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_ARMLINUX_H */
end_comment

end_unit

