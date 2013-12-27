begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM with PE obj format.    Copyright (C) 1995, 1996, 1999, 2000, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Enable PE specific code.  */
end_comment

begin_define
define|#
directive|define
name|ARM_PE
value|1
end_define

begin_define
define|#
directive|define
name|ARM_PE_FLAG_CHAR
value|'@'
end_define

begin_comment
comment|/* Ensure that @x. will be stripped from the function name.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_NAME_ENCODING_LENGTHS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_NAME_ENCODING_LENGTHS
define|\
value|case ARM_PE_FLAG_CHAR: return 3;
end_define

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_escape
end_escape

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
value|fputs (" (ARM/pe)", stderr)
end_define

begin_comment
comment|/* Get tree.c to declare a target-specific specialization of    merge_decl_attributes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
value|1
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"-D__pe__"
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
value|(MASK_NOP_FUN_DLLIMPORT)
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
value|{ "marm", "mlittle-endian", "msoft-float", "mno-thumb-interwork" }
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
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
value|16
end_define

begin_comment
comment|/* r11 is fixed.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CONDITIONAL_REGISTER_USAGE
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CONDITIONAL_REGISTER_USAGE
define|\
value|fixed_regs [11] = 1; \   call_used_regs [11] = 1;
end_define

begin_escape
end_escape

begin_comment
comment|/* PE/COFF uses explicit import from shared libraries.  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|arm_pe_unique_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_RODATA_SECTION
value|default_no_function_rodata_section
end_define

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_pe_asm_named_section
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|true
end_define

begin_comment
comment|/* Output a reference to a label.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|asm_fprintf (STREAM, "%U%s", arm_strip_name_encoding (NAME))
end_define

begin_comment
comment|/* Output a function definition label.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do								\     {								\       if (arm_dllexport_name_p (NAME))				\ 	{							\ 	  drectve_section ();					\ 	  fprintf (STREAM, "\t.ascii \" -export:%s\"\n",	\ 		   arm_strip_name_encoding (NAME));		\ 	  switch_to_section (function_section (DECL));		\ 	}							\       ARM_DECLARE_FUNCTION_NAME (STREAM, NAME, DECL);		\       if (TARGET_THUMB)						\ 	fprintf (STREAM, "\t.code 16\n");			\       ASM_OUTPUT_LABEL (STREAM, NAME);				\     }								\   while (0)
end_define

begin_comment
comment|/* Output a common block.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do							\     {							\       if (arm_dllexport_name_p (NAME))			\ 	{						\ 	  drectve_section ();				\ 	  fprintf ((STREAM), "\t.ascii \" -export:%s\"\n",\ 		   arm_strip_name_encoding (NAME));	\ 	}						\       if (! arm_dllimport_name_p (NAME))		\ 	{						\ 	  fprintf ((STREAM), "\t.comm\t"); 		\ 	  assemble_name ((STREAM), (NAME));		\ 	  asm_fprintf ((STREAM), ", %d\t%@ %d\n",	\  		   (int)(ROUNDED), (int)(SIZE));	\ 	}						\     }							\   while (0)
end_define

begin_comment
comment|/* Output the label for an initialized variable.  */
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
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do							\     {							\       if (arm_dllexport_name_p (NAME))			\ 	{						\ 	  section *save_section = in_section;		\ 	  drectve_section ();				\ 	  fprintf (STREAM, "\t.ascii \" -export:%s\"\n",\ 		   arm_strip_name_encoding (NAME));	\ 	  switch_to_section (save_section);		\ 	}						\       ASM_OUTPUT_LABEL ((STREAM), (NAME));		\     }							\   while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Support the ctors/dtors and other sections.  */
end_comment

begin_define
define|#
directive|define
name|DRECTVE_SECTION_ASM_OP
value|"\t.section .drectve"
end_define

begin_define
define|#
directive|define
name|drectve_section
parameter_list|()
define|\
value|(fprintf (asm_out_file, "%s\n", DRECTVE_SECTION_ASM_OP), \    in_section = NULL)
end_define

end_unit

