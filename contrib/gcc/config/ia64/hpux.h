begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine GNU compiler.  IA-64 version.    Copyright (C) 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Steve Ellcey<sje@cup.hp.com> and                   Reva Cuthbertson<reva@cup.hp.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) HP-UX");
end_define

begin_comment
comment|/* Enable HPUX ABI quirks.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_HPUX
end_undef

begin_define
define|#
directive|define
name|TARGET_HPUX
value|1
end_define

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {							\ 	builtin_assert("system=hpux");			\ 	builtin_assert("system=posix");			\ 	builtin_assert("system=unix");			\ 	builtin_define_std("hpux");			\ 	builtin_define_std("unix");			\ 	builtin_define("__IA64__");			\ 	builtin_define("_LONGLONG");			\ 	builtin_define("_INCLUDE_LONGLONG");		\ 	builtin_define("_UINT128_T");			\ 	if (c_dialect_cxx () || !flag_iso)		\ 	  {						\ 	    builtin_define("_HPUX_SOURCE");		\ 	    builtin_define("__STDC_EXT__");		\ 	    builtin_define("__STDCPP__");		\ 	  }						\ 	if (TARGET_ILP32)				\ 	  builtin_define("_ILP32");			\ } while (0)
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
define|\
value|"%{mt|pthread:-D_REENTRANT -D_THREAD_SAFE -D_POSIX_C_SOURCE=199506L}"
end_define

begin_comment
comment|/* aCC defines also -DRWSTD_MULTI_THREAD, -DRW_MULTI_THREAD.  These    affect only aCC's C++ library (Rogue Wave-derived) which we do not    use, and they violate the user's name space.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_EXTRA_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_EXTRA_SPEC
value|"%{milp32:-milp32} %{mlp64:-mlp64}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:%{static:crt0%O%s}}"
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
define|\
value|"+Accept TypeMismatch \    %{shared:-b} \    %{!shared: \      -u main \      %{static:-noshared}}"
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
define|\
value|"%{!shared: \      %{mt|pthread:-lpthread} \      %{p:%{!mlp64:-L/usr/lib/hpux32/libp} \ 	 %{mlp64:-L/usr/lib/hpux64/libp} -lprof} \      %{pg:%{!mlp64:-L/usr/lib/hpux32/libp} \ 	  %{mlp64:-L/usr/lib/hpux64/libp} -lgprof} \      %{!symbolic:-lc}}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{shared-libgcc:%{!mlp64:-lgcc_s}%{mlp64:-lgcc_s_hpux64} -lgcc} \    %{!shared-libgcc:-lgcc}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "ilp32",    MASK_ILP32,     "Generate ILP32 code" }, \   { "lp64",    -MASK_ILP32,     "Generate LP64 code" },
end_define

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "milp32" }
end_define

begin_comment
comment|/* A C expression whose value is zero if pointers that need to be extended    from being `POINTER_SIZE' bits wide to `Pmode' are sign-extended and    greater then zero if they are zero-extended and less then zero if the    ptr_extend instruction should be used.  */
end_comment

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|-1
end_define

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|(8 * 76)
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
value|(MASK_DWARF2_ASM | MASK_BIG_ENDIAN | MASK_ILP32)
end_define

begin_comment
comment|/* This needs to be set to force structure arguments with a single    integer field to be treated as structures and not as the type of    their field.  Without this a structure with a single char will be    returned just like a char variable, instead of being returned at the    top of the register as specified for big-endian IA64.  */
end_comment

begin_define
define|#
directive|define
name|MEMBER_TYPE_FORCES_BLK
parameter_list|(
name|FIELD
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(!FLOAT_MODE_P (MODE) || (MODE) == TFmode)
end_define

begin_comment
comment|/* ASM_OUTPUT_EXTERNAL_LIBCALL defaults to just a globalize_label call,    but that doesn't put out the @function type information which causes    shared library problems.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL_LIBCALL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|do {								\   (*targetm.asm_out.globalize_label) (FILE, XSTR (FUN, 0));	\   ASM_OUTPUT_TYPE_DIRECTIVE (FILE, XSTR (FUN, 0), "function");	\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG_PADDING
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|ia64_hpux_function_arg_padding ((MODE), (TYPE))
end_define

begin_undef
undef|#
directive|undef
name|PAD_VARARGS_DOWN
end_undef

begin_define
define|#
directive|define
name|PAD_VARARGS_DOWN
value|(!AGGREGATE_TYPE_P (type))
end_define

begin_define
define|#
directive|define
name|REGISTER_TARGET_PRAGMAS
parameter_list|()
define|\
value|c_register_pragma (0, "builtin", ia64_hpux_handle_builtin_pragma)
end_define

begin_comment
comment|/* Tell ia64.c that we are using the HP linker and we should delay output of    function extern declarations so that we don't output them for functions    which are never used (and may not be defined).  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_HPUX_LD
end_undef

begin_define
define|#
directive|define
name|TARGET_HPUX_LD
value|1
end_define

begin_comment
comment|/* The HPUX dynamic linker objects to weak symbols with no    definitions, so do not use them in gthr-posix.h.  */
end_comment

begin_define
define|#
directive|define
name|GTHREAD_USE_WEAK
value|0
end_define

begin_comment
comment|/* Put out the needed function declarations at the end.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|ia64_hpux_file_end
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section\t.init_array,\t\"aw\",\"init_array\""
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section\t.fini_array,\t\"aw\",\"fini_array\""
end_define

begin_comment
comment|/* The init_array/fini_array technique does not permit the use of    initialization priorities.  */
end_comment

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|0
end_define

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.section\t.rodata,\t\"a\",\t\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.section\t.data,\t\"aw\",\t\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|SDATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.section\t.sdata,\t\"asw\",\t\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss,\t\"aw\",\t\"nobits\""
end_define

begin_undef
undef|#
directive|undef
name|SBSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SBSS_SECTION_ASM_OP
value|"\t.section\t.sbss,\t\"asw\",\t\"nobits\""
end_define

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.section\t.text,\t\"ax\",\t\"progbits\""
end_define

begin_comment
comment|/* It is illegal to have relocations in shared segments on HPUX.    Pretend flag_pic is always set.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_SECTION
value|ia64_rwreloc_select_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_UNIQUE_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|ia64_rwreloc_unique_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|ia64_rwreloc_select_rtx_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_SECTION_TYPE_FLAGS
end_undef

begin_define
define|#
directive|define
name|TARGET_SECTION_TYPE_FLAGS
value|ia64_rwreloc_section_type_flags
end_define

begin_comment
comment|/* ia64 HPUX has the float and long double forms of math functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_C99_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_INIT_LIBFUNCS
value|ia64_hpux_init_libfuncs
end_define

begin_define
define|#
directive|define
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
parameter_list|(
name|MODE
parameter_list|,
name|COMPARISON
parameter_list|)
value|((MODE) == TFmode)
end_define

end_unit

