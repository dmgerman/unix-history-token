begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running Solaris 2    Copyright (C) 1993, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.    Contributed by Fred Fish (fnf@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|CMOV_SUN_AS_SYNTAX
value|1
end_define

begin_comment
comment|/* The Solaris 2.0 x86 linker botches alignment of code sections.    It tries to align to a 16 byte boundary by padding with 0x00000090    ints, rather than 0x90 bytes (nop).  This generates trash in the    ".init" section since the contribution from crtbegin.o is only 7    bytes.  The linker pads it to 16 bytes with a single 0x90 byte, and    two 0x00000090 ints, which generates a segmentation violation when    executed.  This macro forces the assembler to do the padding, since    it knows what it is doing.  */
end_comment

begin_define
define|#
directive|define
name|FORCE_CODE_SECTION_ALIGN
value|asm(ALIGN_ASM_OP "16");
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|(flag_pic ? (GLOBAL ? DW_EH_PE_indirect : 0) | DW_EH_PE_datarel	\    : DW_EH_PE_absptr)
end_define

begin_comment
comment|/* Solaris 2/Intel as chokes on #line directives.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{.S:-P} %(cpp_subtarget)"
end_define

begin_comment
comment|/* FIXME: Removed -K PIC from generic Solaris 2 ASM_SPEC: the native assembler    gives many warnings: R_386_32 relocation is used for symbol ".text".  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s \ %(asm_cpu) \ "
end_define

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "cpp_subtarget",	CPP_SUBTARGET_SPEC },	\   { "asm_cpu",		ASM_CPU_SPEC },		\   { "startfile_arch",	STARTFILE_ARCH_SPEC },	\   { "link_arch",	LINK_ARCH_SPEC }
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* The Solaris assembler does not support .quad.  Do not use it.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_QUAD
end_undef

end_unit

