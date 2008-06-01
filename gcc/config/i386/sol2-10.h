begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Solaris 10 configuration.    Copyright (C) 2004 Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
value|"/"
end_define

begin_comment
comment|/* binutils' GNU as understands --32 and --64, but the native Solaris    assembler requires -xarch=generic or -xarch=generic64 instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GAS
end_ifdef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} " \ 		 "%{Wa,*:%*} %{m32:--32} %{m64:--64} -s %(asm_cpu)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} " \ 		 "%{Wa,*:%*} %{m32:-xarch=generic} %{m64:-xarch=generic64} " \ 		 "-s %(asm_cpu)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NO_PROFILE_COUNTERS
end_undef

begin_undef
undef|#
directive|undef
name|MCOUNT_NAME
end_undef

begin_define
define|#
directive|define
name|MCOUNT_NAME
value|"_mcount"
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
value|(TARGET_64BIT ? "int" : "long int")
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
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|(TARGET_64BIT ? "int" : "long int")
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

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do								\     {								\       if (flag_omit_frame_pointer == 2)				\ 	flag_omit_frame_pointer = 0;				\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
value|(MASK_80387 | MASK_IEEE_FP	\ 				  | MASK_FLOAT_RETURNS)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_OPTIMIZATION_OPTIONS
define|\
value|do							\     {							\       if (optimize>= 1)				\ 	target_flags |= MASK_OMIT_LEAF_FRAME_POINTER;	\     }							\   while (0)
end_define

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m32" }
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH64_SPEC_BASE
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC_BASE
define|\
value|"%{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/ucblib/64:/usr/lib/libp/64:/lib/64:/usr/lib/64} \              %{!p:%{!pg:-Y P,/usr/ucblib/64:/lib:/usr/lib/64}}} \              -R /usr/ucblib/64} \    %{!compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/lib/libp/64:/lib/64:/usr/lib/64} \              %{!p:%{!pg:-Y P,/lib/64:/usr/lib/64}}}}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH64_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
value|LINK_ARCH64_SPEC_BASE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_GNU_LD
end_ifdef

begin_define
define|#
directive|define
name|TARGET_LD_EMULATION
value|"%{m64:-m elf_x86_64}%{!m64:-m elf_i386} "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_LD_EMULATION
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|TARGET_LD_EMULATION \ 		       "%{m64:" LINK_ARCH64_SPEC "}%{!m64:" LINK_ARCH32_SPEC "}"
end_define

begin_comment
comment|/* We do not need to search a special directory for startup files.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|i386_solaris_elf_named_section
end_define

begin_comment
comment|/* In 32-bit mode, follow the SVR4 ABI definition; in 64-bit mode, use    the AMD64 ABI definition.  */
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
value|(TARGET_64BIT 				\    ? ix86_return_in_memory (TYPE)		\    : (TYPE_MODE (TYPE) == BLKmode		\       || (VECTOR_MODE_P (TYPE_MODE (TYPE)) 	\&& int_size_in_bytes (TYPE) == 8)))
end_define

end_unit

