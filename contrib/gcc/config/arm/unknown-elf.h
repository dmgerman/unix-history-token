begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for non-Linux based ARM systems using ELF    Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Catherine Moore<clm@cygnus.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* elfos.h should have already been included.  Now just override    any conflicting definitions and add any extras.  */
end_comment

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/ELF)", stderr);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default to using APCS-32 and software floating point.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(ARM_FLAG_SOFT_FLOAT | ARM_FLAG_APCS_32 | ARM_FLAG_APCS_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now we define the strings used to build the spec file.  */
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
value|" crti%O%s crtbegin%O%s crt0%O%s"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend%O%s crtn%O%s"
end_define

begin_comment
comment|/* The __USES_INITFINI__ define is tested in newlib/libc/sys/arm/crt0.S    to see if it needs to invoked _init() and _fini().  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"-D__ELF__ -D__USES_INITFINI__"
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

begin_comment
comment|/* Return a non-zero value if DECL has a section attribute.  */
end_comment

begin_define
define|#
directive|define
name|IN_NAMED_SECTION
parameter_list|(
name|DECL
parameter_list|)
define|\
value|((TREE_CODE (DECL) == FUNCTION_DECL || TREE_CODE (DECL) == VAR_DECL)	\&& DECL_SECTION_NAME (DECL) != NULL_TREE)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

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
value|do									\     {									\       if (IN_NAMED_SECTION (DECL))					\ 	named_section (DECL, NULL, 0);					\       else								\ 	bss_section ();							\       									\       ASM_GLOBALIZE_LABEL (FILE, NAME);					\       									\       ASM_OUTPUT_ALIGN (FILE, floor_log2 (ALIGN / BITS_PER_UNIT));	\ 									\       last_assemble_variable_decl = DECL;				\       ASM_DECLARE_OBJECT_NAME (FILE, NAME, DECL);			\       ASM_OUTPUT_SKIP (FILE, SIZE ? SIZE : 1);				\     } 									\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
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
value|do									\     {									\       if ((DECL) != NULL&& IN_NAMED_SECTION (DECL))			\ 	named_section (DECL, NULL, 0);					\       else								\ 	bss_section ();							\ 									\       ASM_OUTPUT_ALIGN (FILE, floor_log2 (ALIGN / BITS_PER_UNIT));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\       fprintf (FILE, "\t.space\t%d\n", SIZE);				\     }									\   while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ELF__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_APCS_PC_DEFAULT_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_32__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPU_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm7tdmi
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

