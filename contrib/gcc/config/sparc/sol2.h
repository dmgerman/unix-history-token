begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for SPARC running Solaris 2    Copyright 1992, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2004    Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@netcom.com).    Additional changes by David V. Henkel-Wallace (gumby@cygnus.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Supposedly the same as vanilla sparc svr4, except for the stuff below: */
end_comment

begin_comment
comment|/* This is here rather than in sparc.h because it's not known what    other assemblers will accept.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
end_if

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-xarch=v8plus"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-xarch=v8plusa"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc3
end_if

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-xarch=v8plusb"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
value|"\ %{mcpu=v9:-xarch=v8plus} \ %{mcpu=ultrasparc:-xarch=v8plusa} \ %{mcpu=ultrasparc3:-xarch=v8plusb} \ %{!mcpu*:%(asm_cpu_default)} \ "
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
value|{ "startfile_arch",	STARTFILE_ARCH_SPEC },	\   { "link_arch",	LINK_ARCH_SPEC }
end_define

begin_comment
comment|/* However it appears that Solaris 2.0 uses the same reg numbering as    the old BSD-style system did.  */
end_comment

begin_comment
comment|/* Same as sparc.h */
end_comment

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
name|REGNO
parameter_list|)
define|\
value|(TARGET_FLAT&& (REGNO) == HARD_FRAME_POINTER_REGNUM ? 31 : REGNO)
end_define

begin_comment
comment|/* The Solaris 2 assembler uses .skip, not .zero, so put this back.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "\t.skip %u\n", (int)(SIZE))
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
comment|/* This is how to output a reference to an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".L%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "*.L%s%ld", (PREFIX), (long)(NUM))
end_define

begin_comment
comment|/* The native TLS-enabled assembler requires the directive #tls_object    to be put on objects in TLS sections (as of v7.1).  This is not    required by the GNU assembler but supported on SPARC.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do								\     {								\       HOST_WIDE_INT size;					\ 								\       if (DECL_THREAD_LOCAL (DECL))				\ 	ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "tls_object");	\       else							\ 	ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");	\ 								\       size_directive_output = 0;				\       if (!flag_inhibit_size_directive				\&& (DECL)&& DECL_SIZE (DECL))			\ 	{							\ 	  size_directive_output = 1;				\ 	  size = int_size_in_bytes (TREE_TYPE (DECL));		\ 	  ASM_OUTPUT_SIZE_DIRECTIVE (FILE, NAME, size);		\ 	}							\ 								\       ASM_OUTPUT_LABEL (FILE, NAME);				\     }								\   while (0)
end_define

begin_escape
end_escape

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
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.     Some Solaris dynamic linkers don't handle unaligned section relative    relocs properly, so force them to be aligned.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_AS_SPARC_UA_PCREL
end_ifndef

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
value|((flag_pic || GLOBAL) ? DW_EH_PE_aligned : DW_EH_PE_absptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The Solaris linker doesn't understand constructor priorities.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUPPORTS_INIT_PRIORITY
end_undef

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* ??? This does not work in SunOS 4.x, so it is not enabled in sparc.h.    Instead, it is enabled here, because it does work under Solaris.  */
end_comment

begin_comment
comment|/* Define for support of TFmode long double.    SPARC ABI says that long double is 4 words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* But indicate that it isn't supported by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|WIDEST_HARDWARE_FP_SIZE
value|64
end_define

begin_comment
comment|/* Solaris's _Qp_* library routine implementation clobbers the output    memory before the inputs are fully consumed.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_BUGGY_QP_LIB
end_undef

begin_define
define|#
directive|define
name|TARGET_BUGGY_QP_LIB
value|1
end_define

begin_undef
undef|#
directive|undef
name|SUN_CONVERSION_LIBFUNCS
end_undef

begin_define
define|#
directive|define
name|SUN_CONVERSION_LIBFUNCS
value|1
end_define

begin_undef
undef|#
directive|undef
name|DITF_CONVERSION_LIBFUNCS
end_undef

begin_define
define|#
directive|define
name|DITF_CONVERSION_LIBFUNCS
value|1
end_define

begin_undef
undef|#
directive|undef
name|SUN_INTEGER_MULTIPLY_64
end_undef

begin_define
define|#
directive|define
name|SUN_INTEGER_MULTIPLY_64
value|1
end_define

begin_comment
comment|/* Solaris allows 64 bit out and global registers in 32 bit mode.    sparc_override_options will disable V8+ if not generating V9 code.  */
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
value|(MASK_V8PLUS + MASK_FPU + MASK_LONG_DOUBLE_128)
end_define

end_unit

