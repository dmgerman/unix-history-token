begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for IBM RS/6000 POWER running AIX version 4.1.    Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Contributed by David Edelsohn (edelsohn@gnu.org).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|{"pe",		0,					\    N_("Support message passing with the Parallel Environment") },
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
value|"-u %(asm_cpu)"
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
value|"-mcom"
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
value|"-D_IBMR2 -D_POWER -D_AIX -D_AIX32 -D_AIX41 \ -D_LONG_LONG -Asystem=unix -Asystem=aix"
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
value|"%{posix: -D_POSIX_SOURCE}\    %{ansi: -D_ANSI_C_SOURCE}\    %{mpe: -I/usr/lpp/ppe.poe/include}\    %{pthread: -D_THREAD_SAFE}\    %(cpp_cpu)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_DEFAULT_SPEC
value|"-D_ARCH_COM"
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
value|MASK_NEW_MNEMONICS
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
value|PROCESSOR_PPC601
end_define

begin_comment
comment|/* Define this macro as a C expression for the initializer of an    array of string to tell the driver program which options are    defaults for this target and thus do not need to be handled    specially when using `MULTILIB_OPTIONS'.     Do not define this macro if `MULTILIB_OPTIONS' is not defined in    the target makefile fragment or if none of the options listed in    `MULTILIB_OPTIONS' are set by default.  *Note Target Fragment::.  */
end_comment

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "mcpu=common" }
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
value|"%{pg:-L/lib/profiled -L/usr/lib/profiled}\    %{p:-L/lib/profiled -L/usr/lib/profiled} %{!shared:%{g*:-lg}}\    %{mpe:-L/usr/lpp/ppe.poe/lib -lmpi -lvtd}\    %{pthread: -L/usr/lib/threads -lpthreads -lc_r /usr/lib/libc.a}\    %{!pthread: -lc}"
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
value|"-bpT:0x10000000 -bpD:0x20000000 %{!r:-btextro} -bnodelcsect\    %{static:-bnso %(link_syscalls) } %{!shared: %{g*: %(link_libg) }}\    %{shared:-bM:SRE %{!e:-bnoentry}}"
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
value|"%{!shared:\    %{mpe:%{pg:/usr/lpp/ppe.poe/lib/gcrt0.o}\          %{!pg:%{p:/usr/lpp/ppe.poe/lib/mcrt0.o}\                %{!p:/usr/lpp/ppe.poe/lib/crt0.o}}}\    %{!mpe:\      %{pthread:%{pg:gcrt0_r%O%s}%{!pg:%{p:mcrt0_r%O%s}%{!p:crt0_r%O%s}}}\      %{!pthread:%{pg:gcrt0%O%s}%{!pg:%{p:mcrt0%O%s}%{!p:crt0%O%s}}}}}"
end_define

begin_comment
comment|/* AIX 4 uses PowerPC nop (ori 0,0,0) instruction as call glue for PowerPC    and "cror 31,31,31" for POWER architecture.  */
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

end_unit

