begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Generic IRIX version.    Copyright (C) 1993, 1995, 1996, 1998, 2000,    2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* We are compiling for IRIX now.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_IRIX
end_undef

begin_define
define|#
directive|define
name|TARGET_IRIX
value|1
end_define

begin_comment
comment|/* The size in bytes of a DWARF field indicating an offset or length    relative to a debug info section, specified to be 4 bytes in the DWARF-2    specification.  The SGI/MIPS ABI defines it to be the same as PTR_SIZE.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_OFFSET_SIZE
value|PTR_SIZE
end_define

begin_comment
comment|/* The size in bytes of the initial length field in a debug info    section.  The DWARF 3 (draft) specification defines this to be    either 4 or 12 (with a 4-byte "escape" word when it's 12), but the    SGI/MIPS ABI predates this standard and defines it to be the same    as DWARF_OFFSET_SIZE.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_INITIAL_LENGTH_SIZE
value|DWARF_OFFSET_SIZE
end_define

begin_comment
comment|/* MIPS assemblers don't have the usual .set foo,bar construct;    .set is used for assembler options instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

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
value|do								\     {								\       fputc ('\t', FILE);					\       assemble_name (FILE, LABEL1);				\       fputs (" = ", FILE);					\       assemble_name (FILE, LABEL2);				\       fputc ('\n', FILE);					\     }								\   while (0)
end_define

begin_comment
comment|/* The MIPSpro o32 linker warns about not linking .comment sections.  */
end_comment

begin_undef
undef|#
directive|undef
name|IDENT_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|(TARGET_NEWABI ? "." : "$")
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
value|mips_declare_object_name
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
value|mips_finish_declare_object
end_define

begin_comment
comment|/* Also do this for libcalls.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_EXTERNAL_LIBCALL
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_EXTERNAL_LIBCALL
value|irix_output_external_libcall
end_define

begin_comment
comment|/* The linker needs a space after "-o".  */
end_comment

begin_define
define|#
directive|define
name|SWITCHES_NEED_SPACES
value|"o"
end_define

begin_comment
comment|/* Specify wchar_t types.  */
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
value|(Pmode == DImode ? "int" : "long int")
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
value|INT_TYPE_SIZE
end_define

begin_comment
comment|/* Same for wint_t.  */
end_comment

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|(Pmode == DImode ? "int" : "long int")
end_define

begin_undef
undef|#
directive|undef
name|WINT_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Plain char is unsigned in the SGI compiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_SIGNED_CHAR
end_undef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)			\    || strcmp (STR, "rpath") == 0)
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\       builtin_define_std ("host_mips");				\       builtin_define_std ("sgi");				\       builtin_define_std ("unix");				\       builtin_define_std ("SYSTYPE_SVR4");			\       builtin_define ("_MODERN_C");				\       builtin_define ("_SVR4_SOURCE");				\       builtin_define ("__DSO__");				\       builtin_assert ("system=unix");				\       builtin_assert ("system=svr4");				\       builtin_assert ("machine=sgi");				\ 								\       if (mips_abi == ABI_32)					\ 	{							\ 	  builtin_define ("_ABIO32=1");				\ 	  builtin_define ("_MIPS_SIM=_ABIO32");			\ 	  builtin_define ("_MIPS_SZINT=32");			\ 	  builtin_define ("_MIPS_SZLONG=32");			\ 	  builtin_define ("_MIPS_SZPTR=32");			\ 	}							\       else if (mips_abi == ABI_64)				\ 	{							\ 	  builtin_define ("_ABI64=3");				\ 	  builtin_define ("_MIPS_SIM=_ABI64");			\ 	  builtin_define ("_MIPS_SZINT=32");			\ 	  builtin_define ("_MIPS_SZLONG=64");			\ 	  builtin_define ("_MIPS_SZPTR=64");			\ 	}							\       else							\ 	{							\ 	  builtin_define ("_ABIN32=2");				\ 	  builtin_define ("_MIPS_SIM=_ABIN32");			\ 	  builtin_define ("_MIPS_SZINT=32");			\ 	  builtin_define ("_MIPS_SZLONG=32");			\ 	  builtin_define ("_MIPS_SZPTR=32");			\         }							\ 								\       if (!ISA_MIPS1&& !ISA_MIPS2)				\ 	builtin_define ("_COMPILER_VERSION=601");		\ 								\       if (!TARGET_FLOAT64)					\ 	builtin_define ("_MIPS_FPSET=16");			\       else							\ 	builtin_define ("_MIPS_FPSET=32");			\ 								\
comment|/* We must always define _LONGLONG, even when -ansi is	\ 	 used, because IRIX 5 system header files require it.	\ 	 This is OK, because gcc never warns when long long	\ 	 is used in system header files.			\ 								\ 	 An alternative would be to support the SGI builtin	\ 	 type __long_long.  */
value|\       builtin_define ("_LONGLONG");				\ 								\
comment|/* IRIX 6.5.18 and above provide many ISO C99		\ 	 features protected by the __c99 macro.			\ 	 libstdc++ v3 needs them as well.  */
value|\       if (TARGET_IRIX6)						\ 	if (flag_isoc99 || c_dialect_cxx ())			\ 	  builtin_define ("__c99");				\ 								\
comment|/* The GNU C++ standard library requires that		\ 	 __EXTENSIONS__ and _SGI_SOURCE be defined on at	\ 	 least IRIX 6.2 and probably all IRIX 6 prior to 6.5.	\ 	 We don't need this on IRIX 6.5 itself, but it		\ 	 shouldn't hurt other than the namespace pollution.  */
value|\       if (!flag_iso || (TARGET_IRIX6&& c_dialect_cxx ()))	\ 	{							\ 	  builtin_define ("__EXTENSIONS__");			\ 	  builtin_define ("_SGI_SOURCE");			\ 	}							\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CC1_SPEC
value|"%{static: -mno-abicalls}"
end_define

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t.gcc_init,\"ax\",@progbits"
end_define

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section\t.gcc_fini,\"ax\",@progbits"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX_USING_GNU_LD
end_ifdef

begin_define
define|#
directive|define
name|IRIX_NO_UNRESOLVED
value|""
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRIX_NO_UNRESOLVED
value|"-no_unresolved"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generic part of the LINK_SPEC.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} %{EB} %{EL} %{mips1} %{mips2} %{mips3} %{mips4} \ %{bestGnum} %{shared} %{non_shared} \ %{call_shared} %{no_archive} %{exact_version} \ %{!shared: \   %{!non_shared: %{!call_shared:%{!r: -call_shared " IRIX_NO_UNRESOLVED "}}}} \ %{rpath} -init __gcc_init -fini __gcc_fini " IRIX_SUBTARGET_LINK_SPEC
end_define

begin_comment
comment|/* A linker error can empirically be avoided by removing duplicate    library search directories.  */
end_comment

begin_define
define|#
directive|define
name|LINK_ELIMINATE_DUPLICATE_LDIRECTORIES
value|1
end_define

begin_comment
comment|/* Add -g to mips.h default to avoid confusing gas with local symbols    generated from stabs info.  */
end_comment

begin_undef
undef|#
directive|undef
name|NM_FLAGS
end_undef

begin_define
define|#
directive|define
name|NM_FLAGS
value|"-Bng"
end_define

begin_comment
comment|/* The system header files are C++ aware.  */
end_comment

begin_comment
comment|/* ??? Unfortunately, most but not all of the headers are C++ aware.    Specifically, curses.h is not, and as a consequence, defining this    used to prevent libg++ building.  This is no longer the case so    define it again to prevent other problems, e.g. with getopt in    unistd.h.  We still need some way to fix just those files that need    fixing.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
value|1
end_define

begin_comment
comment|/* -G is incompatible with -KPIC which is the default, so only allow objects    in the small data section if the user explicitly asks for it.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIPS_DEFAULT_GVALUE
end_undef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|0
end_define

begin_comment
comment|/* The native o32 IRIX linker does not support merging without a    special elspec(5) file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IRIX_USING_GNU_LD
end_ifndef

begin_undef
undef|#
directive|undef
name|HAVE_GAS_SHF_MERGE
end_undef

begin_define
define|#
directive|define
name|HAVE_GAS_SHF_MERGE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

