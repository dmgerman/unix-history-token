begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for IBM RS/6000 POWER running AIX V5.2.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by David Edelsohn (edelsohn@gnu.org).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* AIX V5 and above support 64-bit executables.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_SWITCHES
define|\
value|{"aix64", 		MASK_64BIT | MASK_POWERPC64 | MASK_POWERPC,	\    N_("Compile for 64-bit pointers") },					\   {"aix32",		- (MASK_64BIT | MASK_POWERPC64),		\    N_("Compile for 32-bit pointers") },					\   {"pe",		0,						\    N_("Support message passing with the Parallel Environment") },
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     The macro SUBTARGET_OVERRIDE_OPTIONS is provided for subtargets, to    get control.  */
end_comment

begin_define
define|#
directive|define
name|NON_POWERPC_MASKS
value|(MASK_POWER | MASK_POWER2)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   if (TARGET_64BIT&& (target_flags& NON_POWERPC_MASKS))		\     {									\       target_flags&= ~NON_POWERPC_MASKS;				\       warning ("-maix64 and POWER architecture are incompatible");	\     }									\   if (TARGET_64BIT&& ! TARGET_POWERPC64)				\     {									\       target_flags |= MASK_POWERPC64;					\       warning ("-maix64 requires PowerPC64 architecture remain enabled"); \     }									\   if (TARGET_POWERPC64&& ! TARGET_64BIT)				\     {									\       error ("-maix64 required: 64-bit computation with 32-bit addressing not yet supported"); \     }									\ } while (0);
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-u %{maix64:-a64 -mppc64} %(asm_cpu)"
end_define

begin_comment
comment|/* Common ASM definitions used by ASM_SPEC amonst the various targets    for handling -mcpu=xxx switches.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
define|\
value|"%{!mcpu*: %{!maix64: \   %{mpowerpc64: -mppc64} \   %{!mpower64: %(asm_default)}}} \ %{mcpu=power3: -m604} \ %{mcpu=power4: -m604} \ %{mcpu=powerpc: -mppc} \ %{mcpu=rs64a: -mppc} \ %{mcpu=603: -m603} \ %{mcpu=603e: -m603} \ %{mcpu=604: -m604} \ %{mcpu=604e: -m604} \ %{mcpu=620: -mppc} \ %{mcpu=630: -m604}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                  \     {                                 \       builtin_define ("_IBMR2");      \       builtin_define ("_POWER");      \       builtin_define ("_LONG_LONG");  \       builtin_define ("_AIX");        \       builtin_define ("_AIX32");      \       builtin_define ("_AIX41");      \       builtin_define ("_AIX43");      \       builtin_define ("_AIX51");      \       builtin_define ("_AIX52");      \       builtin_assert ("system=unix"); \       builtin_assert ("system=aix");  \     }                                 \   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix: -D_POSIX_SOURCE}	\   %{ansi: -D_ANSI_C_SOURCE}			\   %{maix64: -D__64BIT__}			\   %{mpe: -I/usr/lpp/ppe.poe/include}		\   %{pthread: -D_THREAD_SAFE}"
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be     defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
define|\
value|"-D_XOPEN_SOURCE=500				\    -D_XOPEN_SOURCE_EXTENDED=1			\    -D_LARGE_FILE_API				\    -D_ALL_SOURCE				\    %{maix64: -D__64BIT__}			\    %{mpe: -I/usr/lpp/ppe.poe/include}		\    %{pthread: -D_THREAD_SAFE}"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_POWERPC | MASK_NEW_MNEMONICS)
end_define

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC630
end_define

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT64
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT64
value|PROCESSOR_POWER4
end_define

begin_undef
undef|#
directive|undef
name|TARGET_POWER
end_undef

begin_define
define|#
directive|define
name|TARGET_POWER
value|0
end_define

begin_comment
comment|/* Define this macro as a C expression for the initializer of an    array of string to tell the driver program which options are    defaults for this target and thus do not need to be handled    specially when using `MULTILIB_OPTIONS'.     Do not define this macro if `MULTILIB_OPTIONS' is not defined in    the target makefile fragment or if none of the options listed in    `MULTILIB_OPTIONS' are set by default.  *Note Target Fragment::.  */
end_comment

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-L/lib/profiled -L/usr/lib/profiled}\    %{p:-L/lib/profiled -L/usr/lib/profiled}\    %{!maix64:%{!shared:%{g*:-lg}}}\    %{mpe:-L/usr/lpp/ppe.poe/lib -lmpi -lvtd}\    %{pthread:-lpthreads} -lc"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-bpT:0x10000000 -bpD:0x20000000 %{!r:-btextro} -bnodelcsect\    %{static:-bnso %(link_syscalls) } %{shared:-bM:SRE %{!e:-bnoentry}}\    %{!maix64:%{!shared:%{g*: %(link_libg) }}} %{maix64:-b64}\    %{mpe:-binitfini:poe_remote_main}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:\    %{maix64:%{pg:gcrt0_64%O%s}%{!pg:%{p:mcrt0_64%O%s}%{!p:crt0_64%O%s}}}\    %{!maix64:\      %{pthread:%{pg:gcrt0_r%O%s}%{!pg:%{p:mcrt0_r%O%s}%{!p:crt0_r%O%s}}}\      %{!pthread:%{pg:gcrt0%O%s}%{!pg:%{p:mcrt0%O%s}%{!p:crt0%O%s}}}}}"
end_define

begin_comment
comment|/* AIX V5 typedefs ptrdiff_t as "long" while earlier releases used "int".  */
end_comment

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_comment
comment|/* Type used for wchar_t, as a string used in a declaration.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|(!TARGET_64BIT ? "short unsigned int" : "unsigned int")
end_define

begin_comment
comment|/* Width of wchar_t in bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|(!TARGET_64BIT ? 16 : 32)
end_define

begin_define
define|#
directive|define
name|MAX_WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* AIX V5 uses PowerPC nop (ori 0,0,0) instruction as call glue for PowerPC    and "cror 31,31,31" for POWER architecture.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_CALL_GLUE
end_undef

begin_define
define|#
directive|define
name|RS6000_CALL_GLUE
value|"{cror 31,31,31|nop}"
end_define

begin_comment
comment|/* AIX 4.2 and above provides initialization and finalization function    support from linker command line.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_define
define|#
directive|define
name|HAS_INIT_SECTION
end_define

begin_undef
undef|#
directive|undef
name|LD_INIT_SWITCH
end_undef

begin_define
define|#
directive|define
name|LD_INIT_SWITCH
value|"-binitfini"
end_define

end_unit

