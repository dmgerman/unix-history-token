begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ARM running Linux-based GNU systems using ELF    Copyright (C) 1993, 1994, 1997, 1998, 1999, 2000, 2001     Free Software Foundation, Inc.    Contributed by Philip Blundell<philb@gnu.org>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* elfos.h should have already been included.  Now just override    any conflicting definitions and add any extras.  */
end_comment

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM GNU/Linux with ELF)", stderr);
end_define

begin_comment
comment|/* Do not assume anything about header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Default is to use APCS-32 mode.  */
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
value|(ARM_FLAG_APCS_32 | ARM_FLAG_MMU_TRAPS)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_LINK_SPEC
value|" -m armelf_linux -p"
end_define

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
define|\
value|{ "marm", "mlittle-endian", "mhard-float", "mapcs-32", "mno-thumb-interwork" }
end_define

begin_define
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_32__"
end_define

begin_comment
comment|/* Now we define the strings used to build the spec file.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared: -lc} \    %{!shared: %{pthread:-lpthread} \    %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{msoft-float:-lfloat} -lgcc"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add    the GNU/Linux magical crtbegin.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main'. */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \ 		       %{!p:%{profile:gcrt1.o%s} \ 			 %{!profile:crt1.o%s}}}} \    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for GNU/Linux.  Here we tack on    the GNU/Linux magical crtend.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main', followed by a normal    GNU/Linux "finalizer" file, `crtn.o'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
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
value|"%{h*} %{version:-v} \    %{b} %{Wl,*:%*} \    %{static:-Bstatic} \    %{shared:-shared} \    %{symbolic:-Bsymbolic} \    %{rdynamic:-export-dynamic} \    %{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.2} \    -X \    %{mbig-endian:-EB}" \    SUBTARGET_EXTRA_LINK_SPEC
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
value|"-Dunix -Dlinux -D__ELF__ \ -Asystem=unix -Asystem=posix"
end_define

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|NAME1
parameter_list|,
name|NAME2
parameter_list|)
define|\
value|do					   \     {					   \       assemble_name (FILE, NAME1); 	   \       fputs (" = ", FILE);		   \       assemble_name (FILE, NAME2);	   \       fputc ('\n', FILE);		   \     }					   \   while (0)
end_define

begin_comment
comment|/* NWFPE always understands FPA instructions.  */
end_comment

begin_undef
undef|#
directive|undef
name|FP_DEFAULT
end_undef

begin_define
define|#
directive|define
name|FP_DEFAULT
value|FP_SOFT3
end_define

begin_comment
comment|/* Call the function profiler with a given profile label.  */
end_comment

begin_undef
undef|#
directive|undef
name|ARM_FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|ARM_FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\tbl\tmcount%s\n", NEED_PLT_RELOC ? "(PLT)" : "");	\ }
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p}"
end_define

end_unit

