begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OS independent definitions for AMD x86-64.    Copyright (C) 2001 Free Software Foundation, Inc.    Contributed by Bo Thorsen<bo@suse.de>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|(TARGET_64BIT ? dbx64_register_map[n] : svr4_dbx_register_map[n])
end_define

begin_comment
comment|/* Output assembler code to FILE to call the profiler.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
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
value|{									\   if (TARGET_64BIT&& flag_pic)						\     fprintf (FILE, "\tcall\t*mcount@PLT\n");				\   else if (flag_pic)							\     fprintf (FILE, "\tcall\t*mcount@GOT(%%ebx)\n");			\   else									\     fprintf (FILE, "\tcall\tmcount\n");					\ }
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|(TARGET_64BIT ? "long unsigned int" : "unsigned int")
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|(TARGET_64BIT ? "long int" : "int")
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
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
value|"%(cc1_cpu) %{profile:-p}"
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
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} \  %{Wa,*:%*} %{m32:--32}"
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    FILE the assembler definition of uninitialized global DECL named    NAME whose size is SIZE bytes and alignment is ALIGN bytes.    Try to use asm_output_aligned_bss to implement this macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|do {									\     if ((LOG) != 0) {							\       if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\       else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\     }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 System V Release 4 uses DWARF debugging info.    x86-64 ABI specifies DWARF2.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_comment
comment|/* Incorrectly autodetected in cross compilation.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_AS_DWARF2_DEBUG_LINE
end_undef

begin_define
define|#
directive|define
name|HAVE_AS_DWARF2_DEBUG_LINE
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

end_unit

