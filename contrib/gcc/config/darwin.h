begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for Darwin (Mac OS X) systems.    Copyright (C) 1989, 1990, 1991, 1992, 1993, 2000, 2001, 2002    Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The definitions in this file are common to all processor types    running Darwin, which is the kernel for Mac OS X.  Darwin is    basically a BSD user layer laid over a Mach kernel, then evolved    for many years (at NeXT) in parallel with other Unix systems.  So    while the runtime is a somewhat idiosyncratic Mach-based thing,    other definitions look like they would for a BSD variant.  */
end_comment

begin_comment
comment|/* Although NeXT ran on many different architectures, as of Jan 2001    the only supported Darwin targets are PowerPC and x86.  */
end_comment

begin_comment
comment|/* Technically, STANDARD_EXEC_PREFIX should be /usr/libexec/, but in    practice this makes it hard to install new compilers elsewhere, so    leave it undefined and expect system builders to set configure args    correctly.  */
end_comment

begin_comment
comment|/* Suppress g++ attempt to link in the math library automatically.    (Some Darwin versions have a libm, but they seem to cause problems    for C++ executables.)  */
end_comment

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
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
comment|/* Define an empty body for the function do_global_dtors() in libgcc2.c.  */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
end_define

begin_comment
comment|/* The string value for __SIZE_TYPE__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Type used for ptrdiff_t, as a string used in a declaration.  */
end_comment

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_comment
comment|/* wchar_t is int.  */
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
value|"int"
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

begin_comment
comment|/* Default to using the NeXT-style runtime, since that's what is    pre-installed on Darwin systems.  */
end_comment

begin_define
define|#
directive|define
name|NEXT_OBJC_RUNTIME
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
comment|/* Don't warn about MacOS-style 'APPL' four-char-constants.  */
end_comment

begin_undef
undef|#
directive|undef
name|WARN_FOUR_CHAR_CONSTANTS
end_undef

begin_define
define|#
directive|define
name|WARN_FOUR_CHAR_CONSTANTS
value|0
end_define

begin_comment
comment|/* Machine dependent cpp options.  */
end_comment

begin_comment
comment|/* The sequence here allows us to get a more specific version number    glued into __APPLE_CC__.  Normally this number would be updated as    part of submitting to a release engineering organization.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APPLE_CC
end_ifndef

begin_define
define|#
directive|define
name|APPLE_CC
value|999
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRINGIFY_THIS
parameter_list|(
name|x
parameter_list|)
value|# x
end_define

begin_define
define|#
directive|define
name|REALLY_STRINGIFY
parameter_list|(
name|x
parameter_list|)
value|STRINGIFY_THIS(x)
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
value|"-D__APPLE_CC__=" REALLY_STRINGIFY(APPLE_CC) "	\ 		  %{static:-D__STATIC__}%{!static:-D__DYNAMIC__}"
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
value|"%{!static:-lSystem}"
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
value|"%{pg:%{static:-lgcrt0.o}%{!static:-lgcrt1.o}} \     %{!pg:%{static:-lcrt0.o}%{!static:-lcrt1.o}}"
end_define

begin_undef
undef|#
directive|undef
name|DOLLARS_IN_IDENTIFIERS
end_undef

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|2
end_define

begin_comment
comment|/* Allow #sccs (but don't do anything). */
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
comment|/* Also enable Dwarf 2 as an option.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* When generating stabs debugging, use N_BINCL entries.  */
end_comment

begin_define
define|#
directive|define
name|DBX_USE_BINCL
end_define

begin_comment
comment|/* There is no limit to the length of stabs strings.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

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
value|do { text_section ();							\      fprintf (FILE,							\ 	      "\t.stabs \"%s\",%d,0,0,Letext\nLetext:\n", "" , N_SO);	\    } while (0)
end_define

begin_comment
comment|/* Our profiling scheme doesn't LP labels and counter words.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
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
value|machopic_asm_out_constructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|machopic_asm_out_destructor
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
value|do {								\     machopic_finish (asm_out_file);                             \     if (strcmp (lang_hooks.name, "GNU C++") == 0)		\       {								\ 	constructor_section ();					\ 	destructor_section ();					\ 	ASM_OUTPUT_ALIGN (FILE, 1);				\       }								\   } while (0)
end_define

begin_comment
comment|/* Give ObjcC methods pretty symbol names. */
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
comment|/* The RTTI data (e.g., __ti4name) is common and public (and static),    but it does need to be referenced via indirect PIC data pointers.    The machopic_define_name calls are telling the machopic subsystem    that the name *is* defined in this module, so it doesn't need to    make them indirect.  */
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
value|do {									\     const char *xname = NAME;                                           \     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)             \       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));                    \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       machopic_define_name (xname);                                     \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       ENCODE_SECTION_INFO (DECL);  \     ASM_OUTPUT_LABEL (FILE, xname);                                     \   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     const char *xname = NAME;                                           \     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)             \       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));                    \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       machopic_define_name (xname);                                     \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       ENCODE_SECTION_INFO (DECL);					\     ASM_OUTPUT_LABEL (FILE, xname);                                     \
comment|/* Avoid generating stubs for functions we've just defined by	\        outputting any required stub name label now.  */
value|\     machopic_output_possible_stub_label (FILE, xname);			\   } while (0)
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
value|do {									\        STRIP_NAME_ENCODING (NAME, NAME);  \        if (NAME[0] == '&' || NAME[0] == '*')				\          {								\            int len = strlen (NAME);					\ 	   if (len> 6&& !strcmp ("$stub", NAME + len - 5))		\ 	     machopic_validate_stub_or_non_lazy_ptr (NAME, 1);		\ 	   else if (len> 7&& !strcmp ("$stub\"", NAME + len - 6))	\ 	     machopic_validate_stub_or_non_lazy_ptr (NAME, 1);		\ 	   else if (len> 14&& !strcmp ("$non_lazy_ptr", NAME + len - 13)) \ 	     machopic_validate_stub_or_non_lazy_ptr (NAME, 0);		\ 	   fputs (&NAME[1], FILE); \ 	 } \        else if (NAME[0] == '+' || NAME[0] == '-')   \          fprintf (FILE, "\"%s\"", NAME); \        else if (!strncmp (NAME, "_OBJC_", 6))  \          fprintf (FILE, "L%s", NAME);   \        else if (!strncmp (NAME, ".objc_class_name_", 17))		\ 	 fprintf (FILE, "%s", NAME);					\        else								\          fprintf (FILE, "_%s", NAME);					\   } while (0)
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
comment|/* Ensure correct alignment of bss data.  */
end_comment

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
value|do {  \     fputs (".lcomm ", (FILE));				\     assemble_name ((FILE), (NAME));			\     fprintf ((FILE), ",%u,%u\n", (SIZE), floor_log2 ((ALIGN) / BITS_PER_UNIT)); \     if ((DECL)&& ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL)))                                         \       ENCODE_SECTION_INFO (DECL);  \     if ((DECL)&& ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL)))                                         \       machopic_define_name (NAME);                                     \   } while (0)
end_define

begin_comment
comment|/* Output nothing for #ident.  */
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
end_define

begin_comment
comment|/* The maximum alignment which the object file format can support.    For Mach-O, this is 2^15.  */
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
name|OBJC
parameter_list|)
define|\
value|extern void FUNCTION PARAMS ((void));					\ void									\ FUNCTION ()								\ {									\   if (in_section != SECTION)						\     {									\       if (OBJC)								\ 	objc_section_init ();						\       data_section ();							\       if (asm_out_file)							\ 	fprintf (asm_out_file, "%s\n", DIRECTIVE);			\       in_section = SECTION;						\     }									\ }									\  #define ALIAS_SECTION(enum_value, alias_name) 				\ do { if (!strcmp (alias_name, name))					\        section_alias[enum_value] = (alias ? get_identifier (alias) : 0);  \    } while (0)
end_define

begin_comment
comment|/* Darwin uses many types of special sections.  */
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
define|\
value|in_const, in_const_data, in_cstring, in_literal4, in_literal8,	\   in_constructor, in_destructor, in_mod_init, in_mod_term,		\   in_objc_class, in_objc_meta_class, in_objc_category,	\   in_objc_class_vars, in_objc_instance_vars,		\   in_objc_cls_meth, in_objc_inst_meth,			\   in_objc_cat_cls_meth, in_objc_cat_inst_meth,		\   in_objc_selector_refs,				\   in_objc_selector_fixup,				\   in_objc_symbols, in_objc_module_info,			\   in_objc_protocol, in_objc_string_object,		\   in_objc_constant_string_object,			\   in_objc_class_names, in_objc_meth_var_names,		\   in_objc_meth_var_types, in_objc_cls_refs, 		\   in_machopic_nl_symbol_ptr,				\   in_machopic_lazy_symbol_ptr,				\   in_machopic_symbol_stub,				\   in_machopic_picsymbol_stub,				\   in_darwin_exception, in_darwin_eh_frame,		\   num_sections
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
value|static void objc_section_init PARAMS ((void));	\ SECTION_FUNCTION (const_section,		\                   in_const,			\                   ".const", 0)			\ SECTION_FUNCTION (const_data_section,		\                   in_const_data,		\                   ".const_data", 0)		\ SECTION_FUNCTION (cstring_section,		\ 		  in_cstring,			\ 		  ".cstring", 0)		\ SECTION_FUNCTION (literal4_section,		\ 		  in_literal4,			\ 		  ".literal4", 0)		\ SECTION_FUNCTION (literal8_section,		\ 		  in_literal8,			\ 		  ".literal8", 0)		\ SECTION_FUNCTION (constructor_section,		\ 		  in_constructor,		\ 		  ".constructor", 0)		\ SECTION_FUNCTION (mod_init_section,		\ 		  in_mod_init,			\ 		  ".mod_init_func", 0)	\ SECTION_FUNCTION (mod_term_section, \ 		  in_mod_term,			\ 		  ".mod_term_func", 0)	\ SECTION_FUNCTION (destructor_section,		\ 		  in_destructor,		\ 		  ".destructor", 0)		\ SECTION_FUNCTION (objc_class_section,		\ 		  in_objc_class,		\ 		  ".objc_class", 1)		\ SECTION_FUNCTION (objc_meta_class_section,	\ 		  in_objc_meta_class,		\ 		  ".objc_meta_class", 1)	\ SECTION_FUNCTION (objc_category_section,	\ 		  in_objc_category,		\ 		".objc_category", 1)		\ SECTION_FUNCTION (objc_class_vars_section,	\ 		  in_objc_class_vars,		\ 		  ".objc_class_vars", 1)	\ SECTION_FUNCTION (objc_instance_vars_section,	\ 		  in_objc_instance_vars,	\ 		  ".objc_instance_vars", 1)	\ SECTION_FUNCTION (objc_cls_meth_section,	\ 		  in_objc_cls_meth,		\ 		  ".objc_cls_meth", 1)	\ SECTION_FUNCTION (objc_inst_meth_section,	\ 		  in_objc_inst_meth,		\ 		  ".objc_inst_meth", 1)	\ SECTION_FUNCTION (objc_cat_cls_meth_section,	\ 		  in_objc_cat_cls_meth,		\ 		  ".objc_cat_cls_meth", 1)	\ SECTION_FUNCTION (objc_cat_inst_meth_section,	\ 		  in_objc_cat_inst_meth,	\ 		  ".objc_cat_inst_meth", 1)	\ SECTION_FUNCTION (objc_selector_refs_section,	\ 		  in_objc_selector_refs,	\ 		  ".objc_message_refs", 1)	\ SECTION_FUNCTION (objc_selector_fixup_section,	\ 		  in_objc_selector_fixup,	\ 		  ".section __OBJC, __sel_fixup", 1)	\ SECTION_FUNCTION (objc_symbols_section,		\ 		  in_objc_symbols,		\ 		  ".objc_symbols", 1)	\ SECTION_FUNCTION (objc_module_info_section,	\ 		  in_objc_module_info,		\ 		  ".objc_module_info", 1)	\ SECTION_FUNCTION (objc_protocol_section,	\ 		  in_objc_protocol,		\ 		  ".objc_protocol", 1)	\ SECTION_FUNCTION (objc_string_object_section,	\ 		  in_objc_string_object,	\ 		  ".objc_string_object", 1)	\ SECTION_FUNCTION (objc_constant_string_object_section,	\ 		  in_objc_constant_string_object,	\ 		  ".section __OBJC, __cstring_object", 1)	\ SECTION_FUNCTION (objc_class_names_section,	\ 		in_objc_class_names,		\ 		".objc_class_names", 1)	\ SECTION_FUNCTION (objc_meth_var_names_section,	\ 		in_objc_meth_var_names,		\ 		".objc_meth_var_names", 1)	\ SECTION_FUNCTION (objc_meth_var_types_section,	\ 		in_objc_meth_var_types,		\ 		".objc_meth_var_types", 1)	\ SECTION_FUNCTION (objc_cls_refs_section,	\ 		in_objc_cls_refs,		\ 		".objc_cls_refs", 1)		\ 						\ SECTION_FUNCTION (machopic_lazy_symbol_ptr_section,	\ 		in_machopic_lazy_symbol_ptr,		\ 		".lazy_symbol_pointer", 0)      	\ SECTION_FUNCTION (machopic_nl_symbol_ptr_section,	\ 		in_machopic_nl_symbol_ptr,		\ 		".non_lazy_symbol_pointer", 0)      	\ SECTION_FUNCTION (machopic_symbol_stub_section,		\ 		in_machopic_symbol_stub,		\ 		".symbol_stub", 0)      		\ SECTION_FUNCTION (machopic_picsymbol_stub_section,	\ 		in_machopic_picsymbol_stub,		\ 		".picsymbol_stub", 0)      		\ SECTION_FUNCTION (darwin_exception_section,		\ 		in_darwin_exception,			\ 		".section __TEXT,__gcc_except_tab", 0)	\ SECTION_FUNCTION (darwin_eh_frame_section,		\ 		in_darwin_eh_frame,			\ 		".section __TEXT,__eh_frame", 0)	\ 							\ static void					\ objc_section_init ()				\ {						\   static int been_here = 0;			\ 						\   if (been_here == 0)				\     {						\       been_here = 1;				\
comment|/* written, cold -> hot */
value|\       objc_cat_cls_meth_section ();		\       objc_cat_inst_meth_section ();		\       objc_string_object_section ();		\       objc_constant_string_object_section ();	\       objc_selector_refs_section ();		\       objc_selector_fixup_section ();		\       objc_cls_refs_section ();			\       objc_class_section ();			\       objc_meta_class_section ();		\
comment|/* shared, hot -> cold */
value|\       objc_cls_meth_section ();			\       objc_inst_meth_section ();		\       objc_protocol_section ();			\       objc_class_names_section ();		\       objc_meth_var_types_section ();		\       objc_meth_var_names_section ();		\       objc_category_section ();			\       objc_class_vars_section ();		\       objc_instance_vars_section ();		\       objc_module_info_section ();		\       objc_symbols_section ();			\     }						\ } 						\ static tree section_alias[(int) num_sections];	\ static void try_section_alias PARAMS ((void));	\ static void try_section_alias () 		\ {						\     if (section_alias[in_section]&& asm_out_file) \       fprintf (asm_out_file, "%s\n",		\ 	       IDENTIFIER_POINTER (section_alias[in_section]));	\ }      						\  #if 0
end_define

begin_decl_stmt
specifier|static
name|void
name|alias_section
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
unit|\
specifier|static
name|void
name|alias_section
parameter_list|(
name|name
parameter_list|,
name|alias
parameter_list|)
function|\
specifier|const
name|char
modifier|*
name|name
decl_stmt|,
decl|*
name|alias
decl_stmt|;
end_function

begin_block
unit|\
block|{							\
name|ALIAS_SECTION
argument_list|(
name|in_data
argument_list|,
literal|"data"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_text
argument_list|,
literal|"text"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_const
argument_list|,
literal|"const"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_const_data
argument_list|,
literal|"const_data"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_cstring
argument_list|,
literal|"cstring"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_literal4
argument_list|,
literal|"literal4"
argument_list|)
expr_stmt|;
block|\
name|ALIAS_SECTION
argument_list|(
name|in_literal8
argument_list|,
literal|"literal8"
argument_list|)
expr_stmt|;
block|\ }
end_block

begin_endif
endif|#
directive|endif
end_endif

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
value|do								\     {								\       if (TREE_CODE (exp) == STRING_CST)			\ 	{							\ 	  if (flag_writable_strings)				\ 	    data_section ();					\ 	  else if (TREE_STRING_LENGTH (exp) !=			\ 		   strlen (TREE_STRING_POINTER (exp)) + 1)	\ 	    readonly_data_section ();				\ 	  else							\ 	    cstring_section ();					\ 	}							\       else if (TREE_CODE (exp) == INTEGER_CST			\ 	       || TREE_CODE (exp) == REAL_CST)			\         {							\ 	  tree size = TYPE_SIZE (TREE_TYPE (exp));		\ 	  							\ 	  if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 4&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal4_section ();				\ 	  else if (TREE_CODE (size) == INTEGER_CST&&		\ 	      TREE_INT_CST_LOW (size) == 8&&			\ 	      TREE_INT_CST_HIGH (size) == 0)			\ 	    literal8_section ();				\ 	  else							\ 	    readonly_data_section ();				\ 	}							\       else if (TREE_CODE (exp) == CONSTRUCTOR				\&& TREE_TYPE (exp)					\&& TREE_CODE (TREE_TYPE (exp)) == RECORD_TYPE		\&& TYPE_NAME (TREE_TYPE (exp)))				\ 	{								\ 	  tree name = TYPE_NAME (TREE_TYPE (exp));			\ 	  if (TREE_CODE (name) == TYPE_DECL)				\ 	    name = DECL_NAME (name);					\ 	  if (!strcmp (IDENTIFIER_POINTER (name), "NSConstantString"))	\ 	    objc_constant_string_object_section ();			\ 	  else if (!strcmp (IDENTIFIER_POINTER (name), "NXConstantString")) \ 	    objc_string_object_section ();				\ 	  else if (TREE_READONLY (exp) || TREE_CONSTANT (exp))		\ 	    {								\ 	      if (TREE_SIDE_EFFECTS (exp) || flag_pic&& reloc)		\ 		const_data_section ();					\ 	      else							\ 		readonly_data_section (); 				\             }								\ 	  else								\ 	    data_section ();						\       }									\       else if (TREE_CODE (exp) == VAR_DECL&&				\ 	       DECL_NAME (exp)&&					\ 	       TREE_CODE (DECL_NAME (exp)) == IDENTIFIER_NODE&&	\ 	       IDENTIFIER_POINTER (DECL_NAME (exp))&&			\ 	       !strncmp (IDENTIFIER_POINTER (DECL_NAME (exp)), "_OBJC_", 6)) \ 	{								\ 	  const char *name = IDENTIFIER_POINTER (DECL_NAME (exp));	\ 	  								\ 	  if (!strncmp (name, "_OBJC_CLASS_METHODS_", 20))		\ 	    objc_cls_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_METHODS_", 23))	\ 	    objc_inst_meth_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_CLASS_METHODS_", 20)) \ 	    objc_cat_cls_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_INSTANCE_METHODS_", 23)) \ 	    objc_cat_inst_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_VARIABLES_", 22))	\ 	    objc_class_vars_section ();					\ 	  else if (!strncmp (name, "_OBJC_INSTANCE_VARIABLES_", 25))	\ 	    objc_instance_vars_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_PROTOCOLS_", 22))	\ 	    objc_cat_cls_meth_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_NAME_", 17))		\ 	    objc_class_names_section ();				\ 	  else if (!strncmp (name, "_OBJC_METH_VAR_NAME_", 20))		\ 	    objc_meth_var_names_section ();				\ 	  else if (!strncmp (name, "_OBJC_METH_VAR_TYPE_", 20))		\ 	    objc_meth_var_types_section ();				\ 	  else if (!strncmp (name, "_OBJC_CLASS_REFERENCES", 22))	\ 	    objc_cls_refs_section ();					\ 	  else if (!strncmp (name, "_OBJC_CLASS_", 12))			\ 	    objc_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_METACLASS_", 16))		\ 	    objc_meta_class_section ();					\ 	  else if (!strncmp (name, "_OBJC_CATEGORY_", 15))		\ 	    objc_category_section ();					\ 	  else if (!strncmp (name, "_OBJC_SELECTOR_REFERENCES", 25))	\ 	    objc_selector_refs_section ();				\ 	  else if (!strncmp (name, "_OBJC_SELECTOR_FIXUP", 20))		\ 	    objc_selector_fixup_section ();				\ 	  else if (!strncmp (name, "_OBJC_SYMBOLS", 13))		\ 	    objc_symbols_section ();					\ 	  else if (!strncmp (name, "_OBJC_MODULES", 13))		\ 	    objc_module_info_section ();				\ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_INSTANCE_METHODS_", 32)) \ 	    objc_cat_inst_meth_section ();                              \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_CLASS_METHODS_", 29)) \ 	    objc_cat_cls_meth_section ();                               \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_REFS_", 20))         \ 	    objc_cat_cls_meth_section ();                               \ 	  else if (!strncmp (name, "_OBJC_PROTOCOL_", 15))              \ 	    objc_protocol_section ();                                   \ 	  else if ((TREE_READONLY (exp) || TREE_CONSTANT (exp))		\&& !TREE_SIDE_EFFECTS (exp))     			\              { if (flag_pic&& reloc ) const_data_section ();             \                else readonly_data_section (); }                       	\ 	  else								\ 	    data_section ();						\ 	}								\       else if (TREE_READONLY (exp) || TREE_CONSTANT (exp))		\ 	{								\ 	  if (TREE_SIDE_EFFECTS (exp) || flag_pic&& reloc)		\ 	    const_data_section ();					\ 	  else								\ 	    readonly_data_section (); 					\         }								\       else								\         data_section ();						\       try_section_alias ();						\     }									\   while (0)
end_define

begin_comment
comment|/* This can be called with address expressions as "rtx".    They must go in "const". */
end_comment

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
value|do									\     {									\       if (GET_MODE_SIZE (mode) == 8)					\ 	literal8_section ();						\       else if (GET_MODE_SIZE (mode) == 4				\&& (GET_CODE (rtx) == CONST_INT				\ 	           || GET_CODE (rtx) == CONST_DOUBLE))			\ 	literal4_section ();						\       else								\ 	const_section ();						\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_UNRESOLVED_REFERENCE
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { 								\ 	 if (FILE) {							\ 	   if (flag_pic)						\ 	     fprintf (FILE, "\t.lazy_reference ");			\ 	   else								\ 	     fprintf (FILE, "\t.reference ");				\ 	   assemble_name (FILE, NAME);					\ 	   fprintf (FILE, "\n");					\ 	 }                                                              \        } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_CLASS_REFERENCE
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {								\ 	 if (FILE) {							\ 	   fprintf (FILE, "\t");					\ 	   assemble_name (FILE, NAME); 					\ 	   fprintf (FILE, "=0\n");					\ 	   assemble_global (NAME);					\ 	 }								\        } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_GLOBALIZE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { const char *const _x = (NAME); if (!!strncmp (_x, "_OBJC_", 6)) { \   (fputs (".globl ", FILE), assemble_name (FILE, _x), fputs ("\n", FILE)); \  }} while (0)
end_define

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
value|sprintf (LABEL, "*%s%ld", PREFIX, (long)(NUM))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where PREFIX is    the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* Since we have a separate readonly data section, define this so that    jump tables end up in text rather than data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JUMP_TABLES_IN_TEXT_SECTION
end_ifndef

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Symbolic names for various things we might know about a symbol.  */
end_comment

begin_enum
enum|enum
name|machopic_addr_class
block|{
name|MACHOPIC_UNDEFINED
block|,
name|MACHOPIC_DEFINED_DATA
block|,
name|MACHOPIC_UNDEFINED_DATA
block|,
name|MACHOPIC_DEFINED_FUNCTION
block|,
name|MACHOPIC_UNDEFINED_FUNCTION
block|}
enum|;
end_enum

begin_comment
comment|/* Macros defining the various PIC cases.  */
end_comment

begin_define
define|#
directive|define
name|MACHOPIC_INDIRECT
value|(flag_pic)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_JUST_INDIRECT
value|(flag_pic == 1)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_PURE
value|(flag_pic == 2)
end_define

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|darwin_encode_section_info (DECL)
end_define

begin_comment
comment|/* Be conservative and always redo the encoding.  */
end_comment

begin_define
define|#
directive|define
name|REDO_SECTION_INFO_P
parameter_list|(
name|DECL
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|((VAR) = ((SYMBOL_NAME[0] == '!') ? (SYMBOL_NAME) + 4 : (SYMBOL_NAME)))
end_define

begin_define
define|#
directive|define
name|GEN_BINDER_NAME_FOR_STUB
parameter_list|(
name|BUF
parameter_list|,
name|STUB
parameter_list|,
name|STUB_LENGTH
parameter_list|)
define|\
value|do {								\     const char *const stub_ = (STUB);				\     char *buffer_ = (BUF);					\     strcpy (buffer_, stub_);					\     if (stub_[0] == '"')					\       {								\ 	strcpy (buffer_ + (STUB_LENGTH) - 1, "_binder\"");	\       }								\     else							\       {								\ 	strcpy (buffer_ + (STUB_LENGTH), "_binder");		\       }								\   } while (0)
end_define

begin_define
define|#
directive|define
name|GEN_SYMBOL_NAME_FOR_SYMBOL
parameter_list|(
name|BUF
parameter_list|,
name|SYMBOL
parameter_list|,
name|SYMBOL_LENGTH
parameter_list|)
define|\
value|do {								\     const char *const symbol_ = (SYMBOL);			\     char *buffer_ = (BUF);					\     if (name_needs_quotes (symbol_)&& symbol_[0] != '"')	\       {								\ 	  sprintf (buffer_, "\"%s\"", symbol_);			\       }								\     else							\       {								\ 	strcpy (buffer_, symbol_);				\       }								\   } while (0)
end_define

begin_comment
comment|/* Given a symbol name string, create the lazy pointer version    of the symbol name.  */
end_comment

begin_define
define|#
directive|define
name|GEN_LAZY_PTR_NAME_FOR_SYMBOL
parameter_list|(
name|BUF
parameter_list|,
name|SYMBOL
parameter_list|,
name|SYMBOL_LENGTH
parameter_list|)
define|\
value|do {								\     const char *symbol_ = (SYMBOL);				\     char *buffer_ = (BUF);					\     STRIP_NAME_ENCODING (symbol_, symbol_);  \     if (symbol_[0] == '"')					\       {								\         strcpy (buffer_, "\"L");					\         strcpy (buffer_ + 2, symbol_ + 1);			\ 	strcpy (buffer_ + (SYMBOL_LENGTH), "$lazy_ptr\"");	\       }								\     else if (name_needs_quotes (symbol_))			\       {								\         strcpy (buffer_, "\"L");				\         strcpy (buffer_ + 2, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 2, "$lazy_ptr\"");	\       }								\     else							\       {								\         strcpy (buffer_, "L");					\         strcpy (buffer_ + 1, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 1, "$lazy_ptr");	\       }								\   } while (0)
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_EXCEPTION_SECTION
value|darwin_exception_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_EH_FRAME_SECTION
value|darwin_eh_frame_section
end_define

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
value|(((CODE) == 1 || (GLOBAL) == 0) ? DW_EH_PE_pcrel : DW_EH_PE_absptr)
end_define

begin_define
define|#
directive|define
name|REGISTER_TARGET_PRAGMAS
parameter_list|(
name|PFILE
parameter_list|)
define|\
value|do {                                                          \     cpp_register_pragma (PFILE, 0, "mark", darwin_pragma_ignore);  \     cpp_register_pragma (PFILE, 0, "options", darwin_pragma_options);  \     cpp_register_pragma (PFILE, 0, "segment", darwin_pragma_ignore);  \     cpp_register_pragma (PFILE, 0, "unused", darwin_pragma_unused);  \   } while (0)
end_define

end_unit

