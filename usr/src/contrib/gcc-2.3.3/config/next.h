begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* next.h:  definitions for NeXT.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* Use new NeXT include file search path.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_comment
comment|/* In a cross compiler with NeXT as target, don't expect 			 the host to use Next's directory scheme.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{							\     { GPLUSPLUS_INCLUDE_DIR, 1},			\     { GCC_INCLUDE_DIR, 0},				\     { LOCAL_INCLUDE_DIR, 0},				\     { "/NextDeveloper/Headers", 0},			\     { "/NextDeveloper/Headers/ansi", 0},		\     { "/NextDeveloper/Headers/bsd", 0},			\     { "/LocalDeveloper/Headers", 0},			\     { "/LocalDeveloper/Headers/ansi", 0},		\     { "/LocalDeveloper/Headers/bsd", 0},		\     { "/NextDeveloper/2.0CompatibleHeaders", 0},	\     { STANDARD_INCLUDE_DIR, 0},				\     { 0, 0}						\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FORMAT_FUNCTIONS
define|\
value|"NXPrintf",	FALSE,	2,	FALSE,	\       "NXScanf",	TRUE,	2,	FALSE,	\       "NXVPrintf",	FALSE,	2,	TRUE,	\       "NXVScanf",	TRUE,	2,	TRUE,	\       "DPSPrintf",	FALSE,	2,	FALSE,	\       "bsd_sprintf",	FALSE,	2,	FALSE,	\       "bsd_vsprintf",	FALSE,	2,	TRUE,
end_define

begin_comment
comment|/* Use NeXT's special calling convention for sending an Objc message.  */
end_comment

begin_define
define|#
directive|define
name|NEXT_OBJC_RUNTIME
end_define

begin_comment
comment|/* We have atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Enable recent gcc to compile under the old gcc in Next release 1.0.  */
end_comment

begin_define
define|#
directive|define
name|__inline
value|inline
end_define

begin_comment
comment|/* See m68k.h.  0407 means 68040 (or 68030 or 68020, with 68881/2).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0407
end_define

begin_comment
comment|/* wchar_t is unsigned short */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|(BITS_PER_WORD / 2)
end_define

begin_comment
comment|/* Give methods pretty symbol names on NeXT. */
end_comment

begin_define
define|#
directive|define
name|OBJC_GEN_METHOD_LABEL
parameter_list|(
name|BUF
parameter_list|,
name|IS_INST
parameter_list|,
name|CLASS_NAME
parameter_list|,
name|CAT_NAME
parameter_list|,
name|SEL_NAME
parameter_list|)
define|\
value|do { if (CAT_NAME)							\ 	 sprintf (BUF, "%c[%s(%s) %s]", (IS_INST) ? '-' : '+',		\ 		  (CLASS_NAME), (CAT_NAME), (SEL_NAME));		\        else								\ 	 sprintf (BUF, "%c[%s %s]", (IS_INST) ? '-' : '+',		\ 		  (CLASS_NAME), (SEL_NAME));				\      } while (0)
end_define

begin_comment
comment|/* Wrap new method names in quotes so the assembler doesn't gag.    Make Objective-C internal symbols local.  */
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
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { if (NAME[0] == '+' || NAME[0] == '-') fprintf (FILE, "\"%s\"", NAME); \        else if (!strncmp (NAME, "_OBJC_", 6)) fprintf (FILE, "L%s", NAME);   \        else if (!strncmp (NAME, ".objc_class_name_", 17))		\ 	 fprintf (FILE, "%s", NAME);					\        else fprintf (FILE, "_%s", NAME); } while (0)
end_define

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* These compiler options take n arguments.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "Ttext") ? 1 :			\    !strcmp (STR, "Tdata") ? 1 :			\    !strcmp (STR, "Tbss") ? 1 :			\    !strcmp (STR, "include") ? 1 :		\    !strcmp (STR, "imacros") ? 1 :		\    !strcmp (STR, "segalign") ? 1 :		\    !strcmp (STR, "seg1addr") ? 1 :		\    !strcmp (STR, "segaddr") ? 2 :		\    !strcmp (STR, "sectobjectsymbols") ? 2 :	\    !strcmp (STR, "segprot") ? 3 :		\    !strcmp (STR, "sectcreate") ? 3 :		\    !strcmp (STR, "sectalign") ? 3 :		\    !strcmp (STR, "segcreate") ? 3 :		\    !strcmp (STR, "sectorder") ? 3 :		\    !strcmp (STR, "aux-info") ? 1 :		\    0)
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dm68k -DNeXT -Dunix -D__MACH__ -D__ARCHITECTURE__=\"m68k\""
end_define

begin_comment
comment|/* Machine dependent ccp options.  */
end_comment

begin_comment
comment|/* This option used to be called -bsd, but that conflicts with the    general -b option.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{strict-bsd:-D__STRICT_BSD__}"
end_define

begin_comment
comment|/* Machine dependent ld options.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{Z} %{M} \ %{execute*} %{object*} %{preload*} %{fvmlib*} \ %{segalign*} %{seg1addr*} %{segaddr*} %{segprot*} \ %{seglinkedit*} %{noseglinkedit*} \ %{sectcreate*} %{sectalign*} %{sectobjectsymbols}\ %{segcreate*} %{Mach*} %{whyload} %{w} \ %{sectorder*} %{whatsloaded}"
end_define

begin_comment
comment|/* Machine dependent libraries.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lsys_s}} %{pg:-lsys_p}"
end_define

begin_comment
comment|/* We specify crt0.o as -lcrt0.o so that ld will search the library path. */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:-lgcrt0.o}%{!pg: \      %{p:%e-p profiling is no longer supported.  Use -pg instead.} \      %{!p:-lcrt0.o}}"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.    (Why isn't this in m68k.h?)  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* Why not? */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|2
end_define

begin_comment
comment|/* Allow #sscs (but don't do anything). */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* We use Dbx symbol format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* This saves a fair amount of space. */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* These screw up NeXT's gdb at the moment, so don't use them. */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
end_define

begin_comment
comment|/* gdb needs a null N_SO at the end of each file for scattered loading. */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|fprintf (FILE,							\ 	   "\t.text\n\t.stabs \"%s\",%d,0,0,Letext\nLetext:\n",		\ 	   "" , N_SO)
end_define

begin_comment
comment|/* Don't use .gcc_compiled symbols to communicate with GDB;    They interfere with numerically sorted symbol lists. */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|asm_out_file
parameter_list|)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "\t.double 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.double 0r%.20e\n", (VALUE)))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "\t.single 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.single 0r%.20e\n", (VALUE)))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "#0r%.9g", (VALUE)))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "#0r%.20g", (VALUE)))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This is for system verson 3.0, which isn't out yet.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { constructor_section ();			\        ASM_OUTPUT_ALIGN (FILE, 1);		\        fprintf (FILE, "\t.long ");		\        assemble_name (FILE, NAME);		\        fprintf (FILE, "\n"); } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { destructor_section ();			\        ASM_OUTPUT_ALIGN (FILE, 1);		\        fprintf (FILE, "\t.long ");		\        assemble_name (FILE, NAME);		\        fprintf (FILE, "\n"); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How to parse #pragma's */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA
parameter_list|(
name|finput
parameter_list|)
value|handle_pragma (finput)
end_define

begin_comment
comment|/* Create new Mach-O sections. */
end_comment

begin_define
define|#
directive|define
name|SECTION_FUNCTION
parameter_list|(
name|FUNCTION
parameter_list|,
name|SECTION
parameter_list|,
name|DIRECTIVE
parameter_list|,
name|WAS_TEXT
parameter_list|)
define|\
value|void									\ FUNCTION ()								\ {									\   extern void text_section ();					 	\   extern int flag_no_mach_text_sections;		 	      	\   									\   if (WAS_TEXT&& flag_no_mach_text_sections)       			\     text_section ();							\   else if (in_section != SECTION)					\     {									\       fprintf (asm_out_file, "%s\n", DIRECTIVE);			\       in_section = SECTION;						\     }									\ }									\  #define EXTRA_SECTIONS					\   in_const, in_cstring, in_literal4, in_literal8,	\   in_constructor, in_destructor,			\   in_objc_class, in_objc_meta_class, in_objc_category,	\   in_objc_class_vars, in_objc_instance_vars,		\   in_objc_cls_meth, in_objc_inst_meth,			\   in_objc_cat_cls_meth, in_objc_cat_inst_meth,		\   in_objc_selector_strs, in_objc_selector_refs,		\   in_objc_symbols, in_objc_module_info
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|SECTION_FUNCTION (const_section,		\ 		  in_const,			\ 		  ".const", 1)			\ SECTION_FUNCTION (cstring_section,		\ 		  in_cstring,			\ 		  ".cstring", 1)		\ SECTION_FUNCTION (literal4_section,		\ 		  in_literal4,			\ 		  ".literal4", 1)		\ SECTION_FUNCTION (literal8_section,		\ 		  in_literal8,			\ 		  ".literal8", 1)		\ SECTION_FUNCTION (constructor_section,		\ 		  in_constructor,		\ 		  ".constructor", 0)		\ SECTION_FUNCTION (destructor_section,		\ 		  in_destructor,		\ 		  ".destructor", 0)		\ SECTION_FUNCTION (objc_class_section,		\ 		  in_objc_class,		\ 		  ".objc_class", 0)		\ SECTION_FUNCTION (objc_meta_class_section,	\ 		  in_objc_meta_class,		\ 		  ".objc_meta_class", 0)	\ SECTION_FUNCTION (objc_category_section,	\ 		  in_objc_category,		\ 		".objc_category", 0)		\ SECTION_FUNCTION (objc_class_vars_section,	\ 		  in_objc_class_vars,		\ 		  ".objc_class_vars", 0)	\ SECTION_FUNCTION (objc_instance_vars_section,	\ 		  in_objc_instance_vars,	\ 		  ".objc_instance_vars", 0)	\ SECTION_FUNCTION (objc_cls_meth_section,	\ 		  in_objc_cls_meth,		\ 		  ".objc_cls_meth", 0)		\ SECTION_FUNCTION (objc_inst_meth_section,	\ 		  in_objc_inst_meth,		\ 		  ".objc_inst_meth", 0)		\ SECTION_FUNCTION (objc_cat_cls_meth_section,	\ 		  in_objc_cat_cls_meth,		\ 		  ".objc_cat_cls_meth", 0)	\ SECTION_FUNCTION (objc_cat_inst_meth_section,	\ 		  in_objc_cat_inst_meth,	\ 		  ".objc_cat_inst_meth", 0)	\ SECTION_FUNCTION (objc_selector_strs_section,	\ 		  in_objc_selector_strs,	\ 		  ".objc_selector_strs", 0)	\ SECTION_FUNCTION (objc_selector_refs_section,	\ 		  in_objc_selector_refs,	\ 		  ".objc_selector_refs", 0)	\ SECTION_FUNCTION (objc_symbols_section,		\ 		  in_objc_symbols,		\ 		  ".objc_symbols", 0)		\ SECTION_FUNCTION (objc_module_info_section,	\ 		  in_objc_module_info,		\ 		  ".objc_module_info", 0)
end_define

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|const_section
end_define

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|exp
parameter_list|,
name|reloc
parameter_list|)
define|\
value|do								\     {								\       if (TREE_CODE (exp) == STRING_CST)			\ 	{							\ 	  if (flag_writable_strings)				\ 	    data_section ();					\ 	  else if (TREE_STRING_LENGTH (exp) !=			\ 		   strlen (TREE_STRING_POINTER (exp)) + 1)	\ 	    readonly_data_section ();				\ 	  else							\ 	    cstring_section ();					\ 	}							\       else if (TREE_CODE (exp) == INTEGER_CST			\ 	       || TREE_CODE (exp) == REAL_CST)			\         {							\ 	  tree size = TYPE_SIZE (TREE_TYPE (exp));		\ 	  							\ 	  if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 4&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal4_section ();				\ 	  else if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 8&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal8_section ();				\ 	  else							\ 	    readonly_data_section ();				\ 	}							\       else if ((TREE_READONLY (exp) || TREE_CONSTANT (exp))	\&& !TREE_SIDE_EFFECTS (exp))				\ 	readonly_data_section ();					\       else if (TREE_CODE (exp) == VAR_DECL&&				\ 	       DECL_NAME (exp)&&					\ 	       TREE_CODE (DECL_NAME (exp)) == IDENTIFIER_NODE&&	\ 	       IDENTIFIER_POINTER (DECL_NAME (exp))&&			\ 	       !strncmp (IDENTIFIER_POINTER (DECL_NAME (exp)), "_OBJC_", 6)) \ 	{								\ 	  const char *name = IDENTIFIER_POINTER (DECL_NAME (exp));	\ 	  								\ 	  if (!strncmp (name, "_OBJC_CLASS_METHODS_", 20))		\ 	    objc_cls_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_METHODS_", 23))	\ 	    objc_inst_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_CLASS_METHODS_", 20)) \ 	    objc_cat_cls_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_INSTANCE_METHODS_", 23)) \ 	    objc_cat_inst_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_VARIABLES_", 22))	\ 	    objc_class_vars_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_VARIABLES_", 25))	\ 	    objc_instance_vars_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_", 12))			\ 	    objc_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_METACLASS_", 16))		\ 	    objc_meta_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_", 15))		\ 	    objc_category_section ();					\ 	  else if (!strncmp (name, "_OBJC_STRINGS", 13))		\ 	    objc_selector_strs_section ();				\ 	  else if (!strncmp (name, "_OBJC_SELECTOR_REFERENCES", 25))	\ 	    objc_selector_refs_section ();				\ 	  else if (!strncmp (name, "_OBJC_SYMBOLS", 13))		\ 	    objc_symbols_section ();					\ 	  else if (!strncmp (name, "_OBJC_MODULES", 13))		\ 	    objc_module_info_section ();				\ 	  else								\ 	    data_section ();						\ 	}								\       else								\         data_section ();						\     }									\   while (0)
end_define

begin_comment
comment|/* Force the assembler to create all the Objective-C sections,     so that their order is guaranteed. */
end_comment

begin_define
define|#
directive|define
name|OBJC_PROLOGUE
define|\
value|do {							\ 	extern void objc_class_section ();		\ 	extern void objc_meta_class_section ();		\ 	extern void objc_cat_cls_meth_section ();	\ 	extern void objc_cat_inst_meth_section ();	\ 	extern void objc_cls_meth_section ();		\ 	extern void objc_inst_meth_section ();		\ 	extern void objc_selector_refs_section ();	\ 	extern void objc_symbols_section ();		\ 	extern void objc_category_section ();		\ 	extern void objc_class_vars_section ();		\ 	extern void objc_instance_vars_section ();	\ 	extern void objc_module_info_section ();	\ 	extern void objc_selector_strs_section ();	\ 							\ 	objc_class_section ();		\ 	objc_meta_class_section ();	\ 	objc_cat_cls_meth_section ();	\ 	objc_cat_inst_meth_section ();	\ 	objc_cls_meth_section ();	\ 	objc_inst_meth_section ();	\ 	objc_selector_refs_section ();	\ 	objc_symbols_section ();	\ 	objc_category_section ();	\ 	objc_class_vars_section ();	\ 	objc_instance_vars_section ();	\ 	objc_module_info_section ();	\ 	objc_selector_strs_section ();	\      } while (0)
end_define

begin_comment
comment|/* We do not define JUMP_TABLES_IN_TEXT_SECTION, since we wish to keep    the text section pure.  There is no point in addressing the jump    tables using pc relative addressing, since they are not in the text    section, so we undefine CASE_VECTOR_PC_RELATIVE.  This also    causes the compiler to use absolute addresses in the jump table,    so we redefine CASE_VECTOR_MODE to be SImode. */
end_comment

begin_undef
undef|#
directive|undef
name|CASE_VECTOR_MODE
end_undef

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_undef
undef|#
directive|undef
name|CASE_VECTOR_PC_RELATIVE
end_undef

begin_comment
comment|/* Don't treat addresses involving labels differently from symbol names.    Previously, references to labels generated pc-relative addressing modes    while references to symbol names generated absolute addressing modes.  */
end_comment

begin_undef
undef|#
directive|undef
name|GO_IF_INDEXABLE_BASE
name|(
name|X
name|,
name|ADDR
name|)
end_undef

begin_define
define|#
directive|define
name|GO_IF_INDEXABLE_BASE
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X)) goto ADDR; }
end_define

begin_define
define|#
directive|define
name|ALIGN_ASM_OP
value|".align"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG) != 0)			\     fprintf (FILE, "\t%s %d\n", ALIGN_ASM_OP, (LOG))
end_define

begin_comment
comment|/* The maximum alignment which the object file format can support.    For NeXT's Mach-O format, this is 2^15.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|0x8000
end_define

end_unit

