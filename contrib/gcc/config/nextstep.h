begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC    for NeXTSTEP.    Copyright (C) 1989, 1990, 1991, 1992, 1993, 1996, 1997,    1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Use new NeXT include file search path.    In a cross compiler with NeXT as target, don't expect    the host to use Next's directory scheme.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_undef
undef|#
directive|undef
name|INCLUDE_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{							\     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },		\     { LOCAL_INCLUDE_DIR, 0, 0, 1 },			\     { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1 },		\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },			\
comment|/* These are for fixincludes-fixed ansi/bsd headers	\        which wouldn't be found otherwise.		\        (The use of string catenation here is OK since	\ 	NeXT's native compiler is derived from GCC.) */
value|\     { GCC_INCLUDE_DIR "/ansi", 0, 0, 0 },		\     { GCC_INCLUDE_DIR "/bsd", 0, 0, 0 },		\     { "/NextDeveloper/Headers", 0, 0, 0 },		\     { "/NextDeveloper/Headers/ansi", 0, 0, 0 },		\     { "/NextDeveloper/Headers/bsd", 0, 0, 0 },		\     { "/LocalDeveloper/Headers", 0, 0, 0 },		\     { "/LocalDeveloper/Headers/ansi", 0, 0, 0 },	\     { "/LocalDeveloper/Headers/bsd", 0, 0, 0 },		\     { "/NextDeveloper/2.0CompatibleHeaders", 0, 0, 0 },	\     { STANDARD_INCLUDE_DIR, 0, 0, 0 },                  \     { "/usr/include/bsd", 0, 0, 0 },			\     { 0, 0, 0, 0 }				       	\   }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_undef
undef|#
directive|undef
name|INCLUDE_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{							\     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },		\     { GPLUSPLUS_INCLUDE_DIR, 0, 1, 1 },			\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },			\     { GCC_INCLUDE_DIR "/ansi", 0, 0, 0 },		\     { GCC_INCLUDE_DIR "/bsd", 0, 0, 0 },		\     { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1 },		\     { TOOL_INCLUDE_DIR "/ansi", 0, 0, 0 },		\     { TOOL_INCLUDE_DIR "/bsd", 0, 0, 0 },		\     { "/usr/include/bsd", 0, 0, 0 },			\     { 0, 0, 0, 0 }					\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_FORMAT_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_FORMAT_FUNCTIONS
define|\
value|"NXPrintf",	FALSE,	2,	FALSE,	\       "NXScanf",	TRUE,	2,	FALSE,	\       "NXVPrintf",	FALSE,	2,	TRUE,	\       "NXVScanf",	TRUE,	2,	TRUE,	\       "DPSPrintf",	FALSE,	2,	FALSE,	\       "bsd_sprintf",	FALSE,	2,	FALSE,	\       "bsd_vsprintf",	FALSE,	2,	TRUE,
end_define

begin_comment
comment|/* Make -fnext-runtime the default.  */
end_comment

begin_define
define|#
directive|define
name|NEXT_OBJC_RUNTIME
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
comment|/* wchar_t is unsigned short */
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
value|(BITS_PER_WORD / 2)
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* These compiler options take n arguments.  */
end_comment

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR) ? 1 :	\    !strcmp (STR, "segalign") ? 1 :		\    !strcmp (STR, "seg1addr") ? 1 :		\    !strcmp (STR, "segaddr") ? 2 :		\    !strcmp (STR, "sectobjectsymbols") ? 2 :	\    !strcmp (STR, "segprot") ? 3 :		\    !strcmp (STR, "sectcreate") ? 3 :		\    !strcmp (STR, "sectalign") ? 3 :		\    !strcmp (STR, "segcreate") ? 3 :		\    !strcmp (STR, "sectorder") ? 3 :		\    !strcmp (STR, "siff-mask") ? 1 :		\    !strcmp (STR, "siff-filter") ? 1 :		\    !strcmp (STR, "siff-warning") ? 1 :		\    !strcmp (STR, "arch") ? 1 :			\    !strcmp (STR, "pagezero_size") ? 1 :		\    0)
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH
parameter_list|(
name|STR
parameter_list|)
define|\
value|(WORD_SWITCH_TAKES_ARG (STR)			\    || !strcmp (STR, "bsd")			\    || !strcmp (STR, "object")			\    || !strcmp (STR, "ObjC")			\    || !strcmp (STR, "all_load"))
end_define

begin_comment
comment|/* Machine dependent ccp options.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!traditional: -D__STDC__}            \                   %{posixstrict:-D_POSIX_SOURCE}         \                   %{!posixstrict:%{bsd:-D__STRICT_BSD__} \                   %{posix:-D_POSIX_SOURCE}               \                   %{!ansi:-D_NEXT_SOURCE}}               \                   %{MD:-MD %M} %{MMD:-MMD %M}"
end_define

begin_comment
comment|/* Machine dependent ld options.  */
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
value|"%{Z} %{M} \ %{execute*} %{preload*} %{fvmlib*} \ %{segalign*} %{seg1addr*} %{segaddr*} %{segprot*} \ %{pagezero_size*} \ %{seglinkedit*} %{noseglinkedit*} \ %{sectcreate*} %{sectalign*} %{sectobjectsymbols}\ %{segcreate*} %{Mach*} %{whyload} %{w} \ %{sectorder*} %{whatsloaded} %{ObjC} %{all_load} %{object}"
end_define

begin_comment
comment|/* Machine dependent libraries.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!posix*:-lsys_s} %{posix*:-lposix}"
end_define

begin_comment
comment|/* We specify crt0.o as -lcrt0.o so that ld will search the library path. */
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
define|\
value|"%{!posix*:%{pg:-lgcrt0.o}%{!pg: \      %{p:%e-p profiling is no longer supported.  Use -pg instead} \      %{!p:-lcrt0.o}}}\      %{posix*:%{pg:-lgposixcrt0.o}%{!pg: \      %{p:%e-p profiling is no longer supported.  Use -pg instead} \      %{!p:-lposixcrt0.o}}} \      -lcrtbegin.o"
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
define|\
value|"-lcrtend.o"
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

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|XCOFF_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* This saves a fair amount of space. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* These screw up NeXT's gdb at the moment, so don't use them. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
end_undef

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
comment|/* These come from bsd386.h, but are specific to sequent, so make sure    they don't bite us.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_NO_XREFS
end_undef

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_comment
comment|/* gdb needs a null N_SO at the end of each file for scattered loading. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
end_undef

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
comment|/* Define our object format type for crtstuff.c */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_MACHO
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
end_define

begin_undef
undef|#
directive|undef
name|INVOKE__main
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|nextstep_asm_out_constructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|nextstep_asm_out_destructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_EXCEPTION_SECTION
value|nextstep_exception_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_EH_FRAME_SECTION
value|nextstep_eh_frame_section
end_define

begin_comment
comment|/* Don't output a .file directive.  That is only used by the assembler for    error reporting.  */
end_comment

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
end_define

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {								\     if (strcmp (lang_hooks.name, "GNU C++") == 0)		\       {								\ 	constructor_section ();					\ 	destructor_section ();					\ 	ASM_OUTPUT_ALIGN (FILE, 1);				\       }								\   } while (0)
end_define

begin_comment
comment|/* How to parse #pragma's */
end_comment

begin_undef
undef|#
directive|undef
name|HANDLE_PRAGMA
end_undef

begin_define
define|#
directive|define
name|HANDLE_PRAGMA
parameter_list|(
name|GETC
parameter_list|,
name|UNGETC
parameter_list|,
name|NAME
parameter_list|)
value|handle_pragma (GETC, UNGETC, NAME)
end_define

begin_comment
comment|/* Give methods pretty symbol names on NeXT. */
end_comment

begin_undef
undef|#
directive|undef
name|OBJC_GEN_METHOD_LABEL
end_undef

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
parameter_list|,
name|NUM
parameter_list|)
define|\
value|do { if (CAT_NAME)							\ 	 sprintf (BUF, "%c[%s(%s) %s]", (IS_INST) ? '-' : '+',		\ 		  (CLASS_NAME), (CAT_NAME), (SEL_NAME));		\        else								\ 	 sprintf (BUF, "%c[%s %s]", (IS_INST) ? '-' : '+',		\ 		  (CLASS_NAME), (SEL_NAME));				\      } while (0)
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols. */
end_comment

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
value|do { if (NAME[0] == '+' || NAME[0] == '-') fprintf (FILE, "\"%s\"", NAME); \        else if (!strncmp (NAME, "_OBJC_", 6)) fprintf (FILE, "L%s", NAME);   \        else if (!strncmp (NAME, ".objc_class_name_", 17))		\ 	 fprintf (FILE, "%s", NAME);					\        else asm_fprintf (FILE, "%U%s", NAME); } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ALIGN_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ALIGN_ASM_OP
value|"\t.align\t"
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
value|if ((LOG) != 0)			\     fprintf (FILE, "%s%d\n", ALIGN_ASM_OP, (LOG))
end_define

begin_comment
comment|/* Ensure correct alignment of bss data.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|( fputs (".lcomm ", (FILE)),				\   assemble_name ((FILE), (NAME)),			\   fprintf ((FILE), ",%u,%u\n", (SIZE), floor_log2 ((ALIGN) / BITS_PER_UNIT)))
end_define

begin_comment
comment|/* Output #ident as a .ident.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|fprintf (FILE, "\t.ident \"%s\"\n", NAME);
end_define

begin_comment
comment|/* The maximum alignment which the object file format can support.    For NeXT's Mach-O format, this is 2^15.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_OFILE_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|0x8000
end_define

begin_comment
comment|/* Create new Mach-O sections. */
end_comment

begin_undef
undef|#
directive|undef
name|SECTION_FUNCTION
end_undef

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
parameter_list|,
name|OBJC
parameter_list|)
define|\
value|extern void FUNCTION PARAMS ((void));					\ void									\ FUNCTION ()								\ {									\   extern int flag_no_mach_text_sections;				\   									\   if (WAS_TEXT&& flag_no_mach_text_sections)       			\     text_section ();							\   else if (in_section != SECTION)					\     {									\       if (OBJC)								\ 	objc_section_init ();						\       fprintf (asm_out_file, "%s\n", DIRECTIVE);			\       in_section = SECTION;						\     }									\ }									\  #undef	EXTRA_SECTIONS
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
define|\
value|in_const, in_cstring, in_literal4, in_literal8,	\   in_constructor, in_destructor,			\   in_nextstep_exception, in_nextstep_eh_frame,		\   in_objc_class, in_objc_meta_class, in_objc_category,	\   in_objc_class_vars, in_objc_instance_vars,		\   in_objc_cls_meth, in_objc_inst_meth,			\   in_objc_cat_cls_meth, in_objc_cat_inst_meth,		\   in_objc_selector_refs,				\   in_objc_symbols, in_objc_module_info,			\   in_objc_protocol, in_objc_string_object,		\   in_objc_class_names, in_objc_meth_var_names,		\   in_objc_meth_var_types, in_objc_cls_refs
end_define

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
value|extern void objc_section_init PARAMS ((void));	\ SECTION_FUNCTION (const_section,		\ 		  in_const,			\ 		  ".const", 1, 0)		\ SECTION_FUNCTION (cstring_section,		\ 		  in_cstring,			\ 		  ".cstring", 1, 0)		\ SECTION_FUNCTION (literal4_section,		\ 		  in_literal4,			\ 		  ".literal4", 1, 0)		\ SECTION_FUNCTION (literal8_section,		\ 		  in_literal8,			\ 		  ".literal8", 1, 0)		\ SECTION_FUNCTION (constructor_section,		\ 		  in_constructor,		\ 		  ".constructor", 0, 0)		\ SECTION_FUNCTION (destructor_section,		\ 		  in_destructor,		\ 		  ".destructor", 0, 0)		\ SECTION_FUNCTION (nextstep_exception_section,	\ 		  in_nextstep_exception,	\ 		  ".section __TEXT,__gcc_except_tab,regular", 0, 0)	\ SECTION_FUNCTION (nextstep_eh_frame_section,	\ 		  in_nextstep_eh_frame,		\ 		  ".section __TEXT,__eh_frame,regular", 0, 0)		\ SECTION_FUNCTION (objc_class_section,		\ 		  in_objc_class,		\ 		  ".objc_class", 0, 1)		\ SECTION_FUNCTION (objc_meta_class_section,	\ 		  in_objc_meta_class,		\ 		  ".objc_meta_class", 0, 1)	\ SECTION_FUNCTION (objc_category_section,	\ 		  in_objc_category,		\ 		".objc_category", 0, 1)		\ SECTION_FUNCTION (objc_class_vars_section,	\ 		  in_objc_class_vars,		\ 		  ".objc_class_vars", 0, 1)	\ SECTION_FUNCTION (objc_instance_vars_section,	\ 		  in_objc_instance_vars,	\ 		  ".objc_instance_vars", 0, 1)	\ SECTION_FUNCTION (objc_cls_meth_section,	\ 		  in_objc_cls_meth,		\ 		  ".objc_cls_meth", 0, 1)	\ SECTION_FUNCTION (objc_inst_meth_section,	\ 		  in_objc_inst_meth,		\ 		  ".objc_inst_meth", 0, 1)	\ SECTION_FUNCTION (objc_cat_cls_meth_section,	\ 		  in_objc_cat_cls_meth,		\ 		  ".objc_cat_cls_meth", 0, 1)	\ SECTION_FUNCTION (objc_cat_inst_meth_section,	\ 		  in_objc_cat_inst_meth,	\ 		  ".objc_cat_inst_meth", 0, 1)	\ SECTION_FUNCTION (objc_selector_refs_section,	\ 		  in_objc_selector_refs,	\ 		  ".objc_message_refs", 0, 1)	\ SECTION_FUNCTION (objc_symbols_section,		\ 		  in_objc_symbols,		\ 		  ".objc_symbols", 0, 1)	\ SECTION_FUNCTION (objc_module_info_section,	\ 		  in_objc_module_info,		\ 		  ".objc_module_info", 0, 1)	\ SECTION_FUNCTION (objc_protocol_section,	\ 		  in_objc_protocol,		\ 		  ".objc_protocol", 0, 1)	\ SECTION_FUNCTION (objc_string_object_section,	\ 		  in_objc_string_object,	\ 		  ".objc_string_object", 0, 1)	\ SECTION_FUNCTION (objc_class_names_section,	\ 		in_objc_class_names,		\ 		".objc_class_names", 0, 1)	\ SECTION_FUNCTION (objc_meth_var_names_section,	\ 		in_objc_meth_var_names,		\ 		".objc_meth_var_names", 0, 1)	\ SECTION_FUNCTION (objc_meth_var_types_section,	\ 		in_objc_meth_var_types,		\ 		".objc_meth_var_types", 0, 1)	\ SECTION_FUNCTION (objc_cls_refs_section,	\ 		in_objc_cls_refs,		\ 		".objc_cls_refs", 0, 1)		\ 						\ void						\ objc_section_init ()				\ {						\   static int been_here = 0;			\ 						\   if (been_here == 0)				\     {						\       been_here = 1;				\       objc_class_section ();			\       objc_meta_class_section ();		\       objc_cat_cls_meth_section ();		\       objc_cat_inst_meth_section ();		\       objc_cls_meth_section ();			\       objc_inst_meth_section ();		\       objc_selector_refs_section ();		\       objc_symbols_section ();			\       objc_category_section ();			\       objc_protocol_section ();			\       objc_class_vars_section ();		\       objc_instance_vars_section ();		\       objc_module_info_section ();		\       objc_string_object_section ();		\       objc_class_names_section ();		\       objc_meth_var_names_section ();		\       objc_meth_var_types_section ();		\       objc_cls_refs_section ();			\     }						\ }
end_define

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|const_section
end_define

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|exp
parameter_list|,
name|reloc
parameter_list|,
name|align
parameter_list|)
define|\
value|do								\     {								\       if (TREE_CODE (exp) == STRING_CST)			\ 	{							\ 	  if (flag_writable_strings)				\ 	    data_section ();					\ 	  else if (TREE_STRING_LENGTH (exp) !=			\ 		   strlen (TREE_STRING_POINTER (exp)) + 1)	\ 	    readonly_data_section ();				\ 	  else							\ 	    cstring_section ();					\ 	}							\       else if (TREE_CODE (exp) == INTEGER_CST			\ 	       || TREE_CODE (exp) == REAL_CST)			\         {							\ 	  tree size = TYPE_SIZE (TREE_TYPE (exp));		\ 	  							\ 	  if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 4&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal4_section ();				\ 	  else if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 8&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal8_section ();				\ 	  else							\ 	    readonly_data_section ();				\ 	}							\       else if (TREE_CODE (exp) == CONSTRUCTOR				\&& TREE_TYPE (exp)					\&& TREE_CODE (TREE_TYPE (exp)) == RECORD_TYPE		\&& TYPE_NAME (TREE_TYPE (exp))				\&& TREE_CODE (TYPE_NAME (TREE_TYPE (exp))) == IDENTIFIER_NODE \&& IDENTIFIER_POINTER (TYPE_NAME (TREE_TYPE (exp))))	\ 	{								\ 	  if (!strcmp (IDENTIFIER_POINTER (TYPE_NAME (TREE_TYPE (exp))), \ 			"NXConstantString"))				\ 	  objc_string_object_section ();				\ 	else if ((TREE_READONLY (exp) || TREE_CONSTANT (exp))		\&& !TREE_SIDE_EFFECTS (exp))				\ 	  readonly_data_section ();					\ 	else								\ 	  data_section ();						\       }									\       else if (TREE_CODE (exp) == VAR_DECL&&				\ 	       DECL_NAME (exp)&&					\ 	       TREE_CODE (DECL_NAME (exp)) == IDENTIFIER_NODE&&	\ 	       IDENTIFIER_POINTER (DECL_NAME (exp))&&			\ 	       !strncmp (IDENTIFIER_POINTER (DECL_NAME (exp)), "_OBJC_", 6)) \ 	{								\ 	  const char *name = IDENTIFIER_POINTER (DECL_NAME (exp));	\ 	  								\ 	  if (!strncmp (name, "_OBJC_CLASS_METHODS_", 20))		\ 	    objc_cls_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_METHODS_", 23))	\ 	    objc_inst_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_CLASS_METHODS_", 20)) \ 	    objc_cat_cls_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_INSTANCE_METHODS_", 23)) \ 	    objc_cat_inst_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_VARIABLES_", 22))	\ 	    objc_class_vars_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_VARIABLES_", 25))	\ 	    objc_instance_vars_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_PROTOCOLS_", 22))	\ 	    objc_cat_cls_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_NAME_", 17))		\ 	    objc_class_names_section ();				\ 	  else if (!strncmp (name, "_OBJC_METH_VAR_NAME_", 20))		\ 	    objc_meth_var_names_section ();				\ 	  else if (!strncmp (name, "_OBJC_METH_VAR_TYPE_", 20))		\ 	    objc_meth_var_types_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_REFERENCES", 22))	\ 	    objc_cls_refs_section ();					\ 	  else if (!strncmp (name, "_OBJC_CLASS_", 12))			\ 	    objc_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_METACLASS_", 16))		\ 	    objc_meta_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_", 15))		\ 	    objc_category_section ();					\ 	  else if (!strncmp (name, "_OBJC_SELECTOR_REFERENCES", 25))	\ 	    objc_selector_refs_section ();				\ 	  else if (!strncmp (name, "_OBJC_SYMBOLS", 13))		\ 	    objc_symbols_section ();					\ 	  else if (!strncmp (name, "_OBJC_MODULES", 13))		\ 	    objc_module_info_section ();				\ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_INSTANCE_METHODS_", 32)) \ 	    objc_cat_inst_meth_section ();                              \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_CLASS_METHODS_", 29)) \ 	    objc_cat_cls_meth_section ();                               \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_REFS_", 20))         \ 	    objc_cat_cls_meth_section ();                               \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_", 15))              \ 	    objc_protocol_section ();                                   \ 	  else if ((TREE_READONLY (exp) || TREE_CONSTANT (exp))		\&& !TREE_SIDE_EFFECTS (exp))     			\ 	    readonly_data_section ();                                   \ 	  else								\ 	    data_section ();						\ 	}								\       else if (TREE_CODE (exp) == VAR_DECL)				\ 	{								\ 	  if ((flag_pic&& reloc)					\ 	      || !TREE_READONLY (exp) || TREE_SIDE_EFFECTS (exp)	\ 	      || !DECL_INITIAL (exp)					\ 	      || (DECL_INITIAL (exp) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (exp))))		\ 	    data_section ();						\ 	  else								\ 	    readonly_data_section ();					\ 	}								\       else								\ 	readonly_data_section ();					\     }									\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|mode
parameter_list|,
name|rtx
parameter_list|,
name|align
parameter_list|)
define|\
value|do									\     {									\       if (GET_MODE_SIZE(mode) == 8)					\ 	literal8_section();						\       else if (GET_MODE_SIZE(mode) == 4)				\ 	literal4_section();						\       else								\ 	const_section ();						\     }									\   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_COMMENT_START
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|";#"
end_define

end_unit

