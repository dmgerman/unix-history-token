begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ARM running Linux-based GNU systems using ELF    Copyright (C) 1993, 1994, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,    2005, 2006    Free Software Foundation, Inc.    Contributed by Philip Blundell<philb@gnu.org>     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
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

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT_FLOAT_ABI
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_HARD
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
value|(0)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm6
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
value|{ "marm", "mlittle-endian", "mhard-float", "mno-thumb-interwork" }
end_define

begin_comment
comment|/* Now we define the strings used to build the spec file.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{pthread:-lpthread} \    %{shared:-lc} \    %{!shared:%{profile:-lc_p}%{!profile:-lc}}"
end_define

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{msoft-float:-lfloat} %{mfloat-abi=soft*:-lfloat} -lgcc"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld-linux.so.2"
end_define

begin_define
define|#
directive|define
name|LINUX_TARGET_LINK_SPEC
value|"%{h*} %{version:-v} \    %{b} \    %{static:-Bstatic} \    %{shared:-shared} \    %{symbolic:-Bsymbolic} \    %{rdynamic:-export-dynamic} \    %{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER "} \    -X \    %{mbig-endian:-EB}" \    SUBTARGET_EXTRA_LINK_SPEC
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
value|LINUX_TARGET_LINK_SPEC
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	LINUX_TARGET_OS_CPP_BUILTINS();		\     }						\   while (0)
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
name|FPUTYPE_DEFAULT
end_undef

begin_define
define|#
directive|define
name|FPUTYPE_DEFAULT
value|FPUTYPE_FPA_EMU3
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
value|{									\   fprintf (STREAM, "\tbl\tmcount%s\n",					\ 	   (TARGET_ARM&& NEED_PLT_RELOC) ? "(PLT)" : "");		\ }
end_define

begin_comment
comment|/* The GNU/Linux profiler clobbers the link register.  Make sure the    prologue knows to save it.  */
end_comment

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|X
parameter_list|)
define|\
value|emit_insn (gen_rtx_CLOBBER (VOIDmode, gen_rtx_REG (SImode, LR_REGNUM)))
end_define

begin_comment
comment|/* The GNU/Linux profiler needs a frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_FRAME_POINTER_REQUIRED
value|current_function_profile
end_define

end_unit

