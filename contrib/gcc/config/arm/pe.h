begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM with PE obj format.    Copyright (C) 1995, 1996, 1999, 2000, 2002, 2003 Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
end_define

begin_comment
comment|/* Support the __declspec keyword by turning them into attributes.    We currently only support: naked, dllimport, and dllexport.    Note that the current way we do this may result in a collision with    predefined attributes later on.  This can be solved by using one attribute,    say __declspec__, and passing args to it.  The problem with that approach    is that args are not accumulated: each new appearance would clobber any    existing args.  */
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
value|"-D__pe__ -D__declspec(x)=__attribute__((x))"
end_define

begin_comment
comment|/* Experimental addition for pr 7885.    Ignore dllimport for functions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_NOP_FUN
value|(1<< 24)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_NOP_FUN_DLLIMPORT
end_undef

begin_define
define|#
directive|define
name|TARGET_NOP_FUN_DLLIMPORT
value|(target_flags& TARGET_FLAG_NOP_FUN)
end_define

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
value|{ "nop-fun-dllimport",		  TARGET_FLAG_NOP_FUN,		\   N_("Ignore dllimport attribute for functions") },		\ { "no-nop-fun-dllimport",	- TARGET_FLAG_NOP_FUN, "" },
end_define

begin_comment
comment|/* Defaulting to APCS-26 support is a legacy issue.   It has been done    that way for a long time, so changing it will probably break some    people's worlds.  Support for APCS-32 is now enabled as a multilib,    and at some point in the future APCS-32 may become the default.    Possibly when chips that support APCS-26 are no longer made.  */
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
value|(ARM_FLAG_SOFT_FLOAT | TARGET_FLAG_NOP_FUN | ARM_FLAG_MMU_TRAPS)
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
value|{ "marm", "mlittle-endian", "msoft-float", "mapcs-26", "mno-thumb-interwork" }
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
comment|/* Define this macro if in some cases global symbols from one translation    unit may not be bound to undefined symbols in another translation unit    without user intervention.  For instance, under Microsoft Windows    symbols must be explicitly imported from shared libraries (DLLs).  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
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
value|do								\     {								\       if (arm_dllexport_name_p (NAME))				\ 	{							\ 	  drectve_section ();					\ 	  fprintf (STREAM, "\t.ascii \" -export:%s\"\n",	\ 		   arm_strip_name_encoding (NAME));		\ 	  function_section (DECL);				\ 	}							\       ARM_DECLARE_FUNCTION_NAME (STREAM, NAME, DECL);		\       if (TARGET_THUMB)						\ 	fprintf (STREAM, "\t.code 16\n");			\       ASM_OUTPUT_LABEL (STREAM, NAME);				\     }								\   while (0)
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
value|do							\     {							\       if (arm_dllexport_name_p (NAME))			\ 	{						\ 	  enum in_section save_section = in_section;	\ 	  drectve_section ();				\ 	  fprintf (STREAM, "\t.ascii \" -export:%s\"\n",\ 		   arm_strip_name_encoding (NAME));	\ 	  switch_to_section (save_section, (DECL));	\ 	}						\       ASM_OUTPUT_LABEL ((STREAM), (NAME));		\     }							\   while (0)
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

begin_comment
comment|/* A list of other sections which the compiler might be "in" at any    given time.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_drectve
end_define

begin_comment
comment|/* A list of extra section function definitions.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|DRECTVE_SECTION_FUNCTION	\   SWITCH_TO_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|DRECTVE_SECTION_FUNCTION
define|\
value|void									\ drectve_section (void)							\ {									\   if (in_section != in_drectve)						\     {									\       fprintf (asm_out_file, "%s\n", DRECTVE_SECTION_ASM_OP);		\       in_section = in_drectve;						\     }									\ }
end_define

begin_comment
comment|/* Switch to SECTION (an `enum in_section').     ??? This facility should be provided by GCC proper.    The problem is that we want to temporarily switch sections in    ASM_DECLARE_OBJECT_NAME and then switch back to the original section    afterwards.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TO_SECTION_FUNCTION
define|\
value|static void							\ switch_to_section (enum in_section section, tree decl)		\ {								\   switch (section)						\     {								\       case in_text: text_section (); break;			\       case in_data: data_section (); break;			\       case in_named: named_section (decl, NULL, 0); break;	\       case in_readonly_data: readonly_data_section (); break;	\       case in_ctors: ctors_section (); break;			\       case in_dtors: dtors_section (); break;			\       case in_drectve: drectve_section (); break;		\       default: abort (); break;					\     }								\ }
end_define

end_unit

