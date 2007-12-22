begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration file for ARM BPABI targets.    Copyright (C) 2004, 2005    Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Use the AAPCS ABI by default.  */
end_comment

begin_define
define|#
directive|define
name|ARM_DEFAULT_ABI
value|ARM_ABI_AAPCS
end_define

begin_comment
comment|/* Assume that AAPCS ABIs should adhere to the full BPABI.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BPABI
value|(TARGET_AAPCS_BASED)
end_define

begin_comment
comment|/* BPABI targets use EABI frame unwinding tables.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UNWIND_INFO
value|1
end_define

begin_comment
comment|/* Section 4.1 of the AAPCS requires the use of VFP format.  */
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
value|FPUTYPE_VFP
end_define

begin_comment
comment|/* EABI targets should enable interworking by default.  */
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
value|MASK_INTERWORK
end_define

begin_comment
comment|/* The ARM BPABI functions return a boolean; they use no special    calling convention.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
parameter_list|(
name|MODE
parameter_list|,
name|COMPARISON
parameter_list|)
value|TARGET_BPABI
end_define

begin_comment
comment|/* The BPABI integer comparison routines return { -1, 0, 1 }.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LIB_INT_CMP_BIASED
value|!TARGET_BPABI
end_define

begin_comment
comment|/* Tell the assembler to build BPABI binaries.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
value|"%{mabi=apcs-gnu|mabi=atpcs:-meabi=gnu;:-meabi=4}"
end_define

begin_comment
comment|/* The generic link spec in elf.h does not support shared libraries.  */
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
value|"%{mbig-endian:-EB} %{mlittle-endian:-EL} "		\   "%{static:-Bstatic} %{shared:-shared} %{symbolic:-Bsymbolic} "	\   "-X"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__thumb__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RENAME_LIBRARY_SET
value|".thumb_set"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RENAME_LIBRARY_SET
value|".set"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make __aeabi_AEABI_NAME an alias for __GCC_NAME.  */
end_comment

begin_define
define|#
directive|define
name|RENAME_LIBRARY
parameter_list|(
name|GCC_NAME
parameter_list|,
name|AEABI_NAME
parameter_list|)
define|\
value|__asm__ (".globl\t__aeabi_" #AEABI_NAME "\n"		\ 	   RENAME_LIBRARY_SET "\t__aeabi_" #AEABI_NAME 	\ 	     ", __" #GCC_NAME "\n");
end_define

begin_comment
comment|/* Give some libgcc functions an additional __aeabi name.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_muldi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (muldi3, lmul)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_muldi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (muldi3, lmul)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixdfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (fixdfdi, d2lz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (fixunsdfdi, d2ulz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixsfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (fixsfdi, f2lz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (fixunssfdi, f2ulz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdidf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (floatdidf, l2d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdisf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY (floatdisf, l2f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The BPABI requires that we always use an out-of-line implementation    of RTTI comparison, even if the target supports weak symbols,    because the same object file might be used on a target that does    not support merging symbols across DLL boundaries.  This macro is    broken out separately so that it can be used within    TARGET_OS_CPP_BUILTINS in configuration files for systems based on    the BPABI.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BPABI_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\       builtin_define ("__GXX_MERGED_TYPEINFO_NAMES=0");	\     }							\   while (false)
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
value|TARGET_BPABI_CPP_BUILTINS()
end_define

begin_comment
comment|/* The BPABI specifies the use of .{init,fini}_array.  Therefore, we    do not want GCC to put anything into the .{init,fini} sections.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_ARRAY_SECTION_ASM_OP
value|ARM_EABI_CTORS_SECTION_OP
end_define

begin_define
define|#
directive|define
name|FINI_ARRAY_SECTION_ASM_OP
value|ARM_EABI_DTORS_SECTION_OP
end_define

end_unit

