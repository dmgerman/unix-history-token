begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha    running Windows/NT.    Copyright (C) 1995, 1996, 1999, 2000, 2002 Free Software Foundation, Inc.     Donn Terry, Softway Systems, Inc.    From code        Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* cpp handles __STDC__ */
end_comment

begin_comment
comment|/* The three "Alpha" defines on the first such line are from the CLAXP spec */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {							\ 	builtin_define ("__INTERIX");				\ 	builtin_define ("__OPENNT");				\ 	builtin_define ("__Alpha_AXP");				\ 	builtin_define ("_M_ALPHA");				\ 	builtin_define ("_ALPHA_");				\ 	builtin_define ("__stdcall=");				\ 	builtin_define ("__cdecl=");				\ 	builtin_assert ("system=unix");				\ 	builtin_assert ("system=interix");			\     } while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"\ -remap \ %{posix:-D_POSIX_SOURCE} \ -isystem %$INTERIX_ROOT/usr/include"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (alpha Interix)");
end_define

begin_comment
comment|/* alpha.h sets this, but it doesn't apply to us */
end_comment

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ECOFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_comment
comment|/* LINK_SPEC */
end_comment

begin_comment
comment|/* MD_STARTFILE_PREFIX */
end_comment

begin_comment
comment|/* ASM_OUTPUT_LOOP_ALIGN; ASM_OUTPUT_ALIGN_CODE */
end_comment

begin_comment
comment|/* Codegen macro overrides for NT internal conventions */
end_comment

begin_comment
comment|/* the below are ecoff specific... we don't need them, so    undef them (they'll get a default later) */
end_comment

begin_undef
undef|#
directive|undef
name|PUT_SDB_BLOCK_START
end_undef

begin_undef
undef|#
directive|undef
name|PUT_SDB_BLOCK_END
end_undef

begin_comment
comment|/* The following are needed for C++, but also needed for profiling */
end_comment

begin_comment
comment|/* Support const sections and the ctors and dtors sections for g++.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.rdata"
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.     Note that we want to give these sections the SHF_WRITE attribute    because these sections will actually contain data (i.e. tables of    addresses of functions in the current root executable or shared library    file) and, in the case of a shared library, the relocatable addresses    will have to be properly resolved/relocated (and then written into) by    the dynamic linker when it actually attaches the given shared library    to the executing process.  (Note that on SVR4, you may wish to use the    `-z text' option to the ELF linker, when building a shared library, as    an additional check that you are doing everything right.  But if you do    use the `-z text' option when building a shared library, you will get    errors unless the .ctors and .dtors sections are marked as writable    via the SHF_WRITE attribute.)  */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.ctors"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.dtors"
end_define

begin_comment
comment|/* The linker will take care of this, and having them causes problems with    ld -r (specifically -rU).  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
value|1
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_comment
comment|/* Output a definition (implements alias) */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do									\ {									\     fprintf ((FILE), "\t");						\     assemble_name (FILE, LABEL1);					\     fprintf (FILE, "=");						\     assemble_name (FILE, LABEL2);					\     fprintf (FILE, "\n");						\     }									\ while (0)
end_define

begin_comment
comment|/* We use the defaults, so undef the null definitions */
end_comment

begin_undef
undef|#
directive|undef
name|PUT_SDB_FUNCTION_START
end_undef

begin_undef
undef|#
directive|undef
name|PUT_SDB_FUNCTION_END
end_undef

begin_undef
undef|#
directive|undef
name|PUT_SDB_EPILOGUE_END
end_undef

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
value|"%p"
end_define

begin_define
define|#
directive|define
name|HOST_PTR_AS_INT
value|unsigned long
end_define

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_TEST
value|TYPE_NATIVE(rec)
end_define

begin_define
define|#
directive|define
name|GROUP_BITFIELDS_BY_ALIGN
value|TYPE_NATIVE(rec)
end_define

begin_comment
comment|/* DWARF2 Unwinding doesn't work with exception handling yet.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.     On NT (according to the spec) anything except strings/array that fits    in 64 bits is returned in the registers (this appears to differ from    the rest of the Alpha family).  */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_IN_MEMORY
end_undef

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE || int_size_in_bytes(TYPE)> 8)
end_define

begin_define
define|#
directive|define
name|ASM_LOAD_ADDR
parameter_list|(
name|loc
parameter_list|,
name|reg
parameter_list|)
value|"     lda " #reg "," #loc "\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{								\   alpha_write_verstamp (FILE);					\   fprintf (FILE, "\t.set noreorder\n");				\   fprintf (FILE, "\t.set volatile\n");                          \   fprintf (FILE, "\t.set noat\n");				\   fprintf (FILE, "\t.globl\t__fltused\n");			\   ASM_OUTPUT_SOURCE_FILENAME (FILE, main_input_filename);	\ }
end_define

end_unit

