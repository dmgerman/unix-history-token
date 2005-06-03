begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for Darwin (Mac OS X) systems.    Copyright (C) 1989, 1990, 1991, 1992, 1993, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* One of Darwin's NeXT legacies is the Mach-O format, which is partly    like a.out and partly like COFF, with additional features like    multi-architecture binary support.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_MACHO
end_define

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
comment|/* This table intercepts weirdo options whose names would interfere    with normal driver conventions, and either translates them into    standardly-named options, or adds a 'Z' so that they can get to    specs processing without interference.     Do not expand a linker option to "-Xlinker -<option>", since that    forfeits the ability to control via spec strings later.  However,    as a special exception, do this translation with -filelist, because    otherwise the driver will think there are no input files and quit.    (The alternative would be to hack the driver to recognize -filelist    specially, but it's simpler to use the translation table.)     Note that an option name with a prefix that matches another option    name, that also takes an argument, needs to be modified so the    prefix is different, otherwise a '*' after the shorter option will    match with the longer one.     The SUBTARGET_OPTION_TRANSLATE_TABLE macro, which _must_ be defined    in gcc/config/{i386,rs6000}/darwin.h, should contain any additional    command-line option translations specific to the particular target    architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTION_TRANSLATE_TABLE
define|\
value|{ "-all_load", "-Zall_load" },  \   { "-allowable_client", "-Zallowable_client" },  \   { "-arch_errors_fatal", "-Zarch_errors_fatal" },  \   { "-bind_at_load", "-Zbind_at_load" },  \   { "-bundle", "-Zbundle" },  \   { "-bundle_loader", "-Zbundle_loader" },  \   { "-weak_reference_mismatches", "-Zweak_reference_mismatches" },  \   { "-dependency-file", "-MF" }, \   { "-dylib_file", "-Zdylib_file" }, \   { "-dynamic", "-Zdynamic" },  \   { "-dynamiclib", "-Zdynamiclib" },  \   { "-exported_symbols_list", "-Zexported_symbols_list" },  \   { "-seg_addr_table_filename", "-Zseg_addr_table_filename" }, \   { "-filelist", "-Xlinker -filelist -Xlinker" },  \   { "-flat_namespace", "-Zflat_namespace" },  \   { "-force_cpusubtype_ALL", "-Zforce_cpusubtype_ALL" },  \   { "-force_flat_namespace", "-Zforce_flat_namespace" },  \   { "-image_base", "-Zimage_base" },  \   { "-init", "-Zinit" },  \   { "-install_name", "-Zinstall_name" },  \   { "-multiply_defined_unused", "-Zmultiplydefinedunused" },  \   { "-multiply_defined", "-Zmultiply_defined" },  \   { "-multi_module", "-Zmulti_module" },  \   { "-static", "-static -Wa,-static" },  \   { "-single_module", "-Zsingle_module" },  \   { "-unexported_symbols_list", "-Zunexported_symbols_list" },  \   SUBTARGET_OPTION_TRANSLATE_TABLE
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
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR) ? 1 :    \    !strcmp (STR, "Zallowable_client") ? 1 :     \    !strcmp (STR, "arch") ? 1 :                  \    !strcmp (STR, "arch_only") ? 1 :             \    !strcmp (STR, "Zbundle_loader") ? 1 :        \    !strcmp (STR, "client_name") ? 1 :           \    !strcmp (STR, "compatibility_version") ? 1 : \    !strcmp (STR, "current_version") ? 1 :       \    !strcmp (STR, "Zdylib_file") ? 1 :           \    !strcmp (STR, "Zexported_symbols_list") ? 1 : \    !strcmp (STR, "Zimage_base") ? 1 :           \    !strcmp (STR, "Zinit") ? 1 :                 \    !strcmp (STR, "Zinstall_name") ? 1 :         \    !strcmp (STR, "Zmultiplydefinedunused") ? 1 : \    !strcmp (STR, "Zmultiply_defined") ? 1 :     \    !strcmp (STR, "precomp-trustfile") ? 1 :     \    !strcmp (STR, "read_only_relocs") ? 1 :      \    !strcmp (STR, "sectcreate") ? 3 :            \    !strcmp (STR, "sectorder") ? 3 :             \    !strcmp (STR, "Zseg_addr_table_filename") ?1 :\    !strcmp (STR, "seg1addr") ? 1 :              \    !strcmp (STR, "segprot") ? 3 :               \    !strcmp (STR, "seg_addr_table") ? 1 :        \    !strcmp (STR, "sub_library") ? 1 :           \    !strcmp (STR, "sub_umbrella") ? 1 :          \    !strcmp (STR, "umbrella") ? 1 :              \    !strcmp (STR, "undefined") ? 1 :             \    !strcmp (STR, "Zunexported_symbols_list") ? 1 : \    !strcmp (STR, "Zweak_reference_mismatches") ? 1 : \    !strcmp (STR, "pagezero_size") ? 1 :         \    !strcmp (STR, "segs_read_only_addr") ? 1 :   \    !strcmp (STR, "segs_read_write_addr") ? 1 :  \    !strcmp (STR, "sectalign") ? 3 :             \    !strcmp (STR, "sectobjectsymbols") ? 2 :     \    !strcmp (STR, "segcreate") ? 3 :             \    !strcmp (STR, "dylinker_install_name") ? 1 : \    0)
end_define

begin_comment
comment|/* Machine dependent cpp options.  */
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
value|"%{static:%{!dynamic:-D__STATIC__}}%{!static:-D__DYNAMIC__}"
end_define

begin_comment
comment|/* This is mostly a clone of the standard LINK_COMMAND_SPEC, plus    precomp, libtool, and fat build additions.  Also we    don't specify a second %G after %L because libSystem is    self-contained and doesn't need to link against libgcc.a.  */
end_comment

begin_comment
comment|/* In general, random Darwin linker flags should go into LINK_SPEC    instead of LINK_COMMAND_SPEC.  The command spec is better for    specifying the handling of options understood by generic Unix    linkers, and for positional arguments like libraries.  */
end_comment

begin_define
define|#
directive|define
name|LINK_COMMAND_SPEC
value|"\ %{!fdump=*:%{!fsyntax-only:%{!precomp:%{!c:%{!M:%{!MM:%{!E:%{!S:\     %{!Zdynamiclib:%(linker)}%{Zdynamiclib:/usr/bin/libtool} \     %{!Zdynamiclib:-arch %(darwin_arch)} \     %{Zdynamiclib:-arch_only %(darwin_arch)} \     %l %X %{d} %{s} %{t} %{Z} \     %{!Zdynamiclib:%{A} %{e*} %{m} %{N} %{n} %{r} %{u*} %{x} %{z}} \     %{@:-o %f%u.out}%{!@:%{o*}%{!o:-o a.out}} \     %{!Zdynamiclib:%{!A:%{!nostdlib:%{!nostartfiles:%S}}}} \     %{L*} %(link_libgcc) %o %{fprofile-arcs|fprofile-generate:-lgcov} \     %{!nostdlib:%{!nodefaultlibs:%G %L}} \     %{!A:%{!nostdlib:%{!nostartfiles:%E}}} %{T*} %{F*} \     %{!--help:%{!no-c++filt|c++filt:| c++filt }} }}}}}}}}"
end_define

begin_comment
comment|/* Please keep the random linker options in alphabetical order (modulo    'Z' and 'no' prefixes).  Options that can only go to one of libtool    or ld must be listed twice, under both !Zdynamiclib and    Zdynamiclib, with one of the cases reporting an error.  */
end_comment

begin_comment
comment|/* Note that options taking arguments may appear multiple times on a    command line with different arguments each time, so put a * after    their names so all of them get passed.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{static}%{!static:-dynamic} \    %{!Zdynamiclib: \      %{Zbundle:-bundle} \      %{Zbundle_loader*:-bundle_loader %*} \      %{client_name*} \      %{compatibility_version*:%e-compatibility_version only allowed with -dynamiclib\ } \      %{current_version*:%e-current_version only allowed with -dynamiclib} \      %{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL} \      %{Zforce_flat_namespace:-force_flat_namespace} \      %{Zinstall_name*:%e-install_name only allowed with -dynamiclib} \      %{keep_private_externs} \      %{private_bundle} \     } \    %{Zdynamiclib: \      %{Zbundle:%e-bundle not allowed with -dynamiclib} \      %{Zbundle_loader*:%e-bundle_loader not allowed with -dynamiclib} \      %{client_name*:%e-client_name not allowed with -dynamiclib} \      %{compatibility_version*} \      %{current_version*} \      %{Zforce_cpusubtype_ALL:%e-force_cpusubtype_ALL not allowed with -dynamiclib} \      %{Zforce_flat_namespace:%e-force_flat_namespace not allowed with -dynamiclib} \      %{Zinstall_name*:-install_name %*} \      %{keep_private_externs:%e-keep_private_externs not allowed with -dynamiclib} \      %{private_bundle:%e-private_bundle not allowed with -dynamiclib} \     } \    %{Zall_load:-all_load}%{Zdynamiclib:%{!Zall_load:-noall_load}} \    %{Zallowable_client*:-allowable_client %*} \    %{Zbind_at_load:-bind_at_load} \    %{Zarch_errors_fatal:-arch_errors_fatal} \    %{Zdylib_file*:-dylib_file %*} \    %{Zdynamic:-dynamic}\    %{Zexported_symbols_list*:-exported_symbols_list %*} \    %{Zflat_namespace:-flat_namespace} \    %{headerpad_max_install_names*} \    %{Zimage_base*:-image_base %*} \    %{Zinit*:-init %*} \    %{nomultidefs} \    %{Zmulti_module:-multi_module} %{Zsingle_module:-single_module} \    %{Zmultiply_defined*:-multiply_defined %*} \    %{Zmultiplydefinedunused*:-multiply_defined_unused %*} \    %{prebind} %{noprebind} %{nofixprebinding} %{prebind_all_twolevel_modules} \    %{read_only_relocs} \    %{sectcreate*} %{sectorder*} %{seg1addr*} %{segprot*} %{seg_addr_table*} \    %{Zseg_addr_table_filename*:-seg_addr_table_filename %*} \    %{sub_library*} %{sub_umbrella*} \    %{twolevel_namespace} %{twolevel_namespace_hints} \    %{umbrella*} \    %{undefined*} \    %{Zunexported_symbols_list*:-unexported_symbols_list %*} \    %{Zweak_reference_mismatches*:-weak_reference_mismatches %*} \    %{X} \    %{y*} \    %{w} \    %{pagezero_size*} %{segs_read_*} %{seglinkedit} %{noseglinkedit}  \    %{sectalign*} %{sectobjectsymbols*} %{segcreate*} %{whyload} \    %{whatsloaded} %{dylinker_install_name*} \    %{dylinker} %{Mach} "
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
comment|/* We specify crt0.o as -lcrt0.o so that ld will search the library path.  */
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
value|"%{!Zdynamiclib:%{Zbundle:%{!static:-lbundle1.o}} \      %{!Zbundle:%{pg:%{static:-lgcrt0.o} \                      %{!static:%{object:-lgcrt0.o} \                                %{!object:%{preload:-lgcrt0.o} \                                  %{!preload:-lgcrt1.o -lcrt2.o}}}} \                 %{!pg:%{static:-lcrt0.o} \                       %{!static:%{object:-lcrt0.o} \                                 %{!object:%{preload:-lcrt0.o} \                                   %{!preload:-lcrt1.o -lcrt2.o}}}}}}"
end_define

begin_comment
comment|/* The native Darwin linker doesn't necessarily place files in the order    that they're specified on the link line.  Thus, it is pointless    to put anything in ENDFILE_SPEC.  */
end_comment

begin_comment
comment|/* #define ENDFILE_SPEC "" */
end_comment

begin_comment
comment|/* We use Dbx symbol format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
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
comment|/* gdb needs a null N_SO at the end of each file for scattered loading.  */
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
value|1
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
comment|/* Always prefix with an underscore.  */
end_comment

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_comment
comment|/* Don't output a .file directive.  That is only used by the assembler for    error reporting.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|false
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|darwin_file_end
end_define

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
value|fprintf (FILE, "\t.space "HOST_WIDE_INT_PRINT_UNSIGNED"\n", SIZE)
end_define

begin_comment
comment|/* Give ObjC methods pretty symbol names.  */
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
value|do {									\     const char *xname = NAME;						\     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\     if ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL))						\       machopic_define_name (xname);					\     if ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL))						\       (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\     ASM_OUTPUT_LABEL (FILE, xname);					\
comment|/* Darwin doesn't support zero-size objects, so give them a	\        byte.  */
value|\     if (tree_low_cst (DECL_SIZE_UNIT (DECL), 1) == 0)			\       assemble_zeros (1);						\   } while (0)
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
value|do {									\     const char *xname = NAME;                                           \     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)             \       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));                    \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       machopic_define_name (xname);                                     \     if ((TREE_STATIC (DECL)                                             \&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))               \         || DECL_INITIAL (DECL))                                         \       (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\     ASM_OUTPUT_LABEL (FILE, xname);                                     \   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_CONSTANT_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|EXP
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do {								\     ASM_OUTPUT_LABEL (FILE, NAME);				\
comment|/* Darwin doesn't support zero-size objects, so give them a	\        byte.  */
value|\     if ((SIZE) == 0)						\       assemble_zeros (1);					\   } while (0)
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
value|do {									     \        const char *xname = darwin_strip_name_encoding (NAME);		     \        if (! strcmp (xname, "<pic base>"))				     \          machopic_output_function_base_name(FILE);                           \        else if (xname[0] == '&' || xname[0] == '*')			     \          {								     \            int len = strlen (xname);					     \ 	   if (len> 6&& !strcmp ("$stub", xname + len - 5))		     \ 	     machopic_validate_stub_or_non_lazy_ptr (xname, 1);		     \ 	   else if (len> 7&& !strcmp ("$stub\"", xname + len - 6))	     \ 	     machopic_validate_stub_or_non_lazy_ptr (xname, 1);		     \ 	   else if (len> 14&& !strcmp ("$non_lazy_ptr", xname + len - 13)) \ 	     machopic_validate_stub_or_non_lazy_ptr (xname, 0);		     \ 	   fputs (&xname[1], FILE);					     \ 	 }								     \        else if (xname[0] == '+' || xname[0] == '-')			     \          fprintf (FILE, "\"%s\"", xname);				     \        else if (!strncmp (xname, "_OBJC_", 6))				     \          fprintf (FILE, "L%s", xname);					     \        else if (!strncmp (xname, ".objc_class_name_", 17))		     \ 	 fprintf (FILE, "%s", xname);					     \        else								     \          fprintf (FILE, "_%s", xname);					     \   } while (0)
end_define

begin_comment
comment|/* Output before executable code.  */
end_comment

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
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
value|do {									\     fputs (".lcomm ", (FILE));						\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", (SIZE),	\ 	     floor_log2 ((ALIGN) / BITS_PER_UNIT));			\     if ((DECL)&& ((TREE_STATIC (DECL)					\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL)))					\       (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\     if ((DECL)&& ((TREE_STATIC (DECL)					\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL)))					\       machopic_define_name (NAME);					\   } while (0)
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
comment|/* Create new Mach-O sections.  */
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
value|extern void FUNCTION (void);						\ void									\ FUNCTION (void)								\ {									\   if (in_section != SECTION)						\     {									\       if (OBJC)								\ 	objc_section_init ();						\       data_section ();							\       if (asm_out_file)							\ 	fprintf (asm_out_file, "%s\n", DIRECTIVE);			\       in_section = SECTION;						\     }									\ }
end_define

begin_comment
unit|\
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
value|in_const, in_const_data, in_cstring, in_literal4, in_literal8,	\   in_constructor, in_destructor, in_mod_init, in_mod_term,		\   in_objc_class, in_objc_meta_class, in_objc_category,	\   in_objc_class_vars, in_objc_instance_vars,		\   in_objc_cls_meth, in_objc_inst_meth,			\   in_objc_cat_cls_meth, in_objc_cat_inst_meth,		\   in_objc_selector_refs,				\   in_objc_selector_fixup,				\   in_objc_symbols, in_objc_module_info,			\   in_objc_protocol, in_objc_string_object,		\   in_objc_constant_string_object,			\   in_objc_image_info,					\   in_objc_class_names, in_objc_meth_var_names,		\   in_objc_meth_var_types, in_objc_cls_refs,		\   in_machopic_nl_symbol_ptr,				\   in_machopic_lazy_symbol_ptr,				\   in_machopic_symbol_stub,				\   in_machopic_symbol_stub1,				\   in_machopic_picsymbol_stub,				\   in_machopic_picsymbol_stub1,				\   in_darwin_exception, in_darwin_eh_frame,		\   num_sections
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
value|static void objc_section_init (void);		\ SECTION_FUNCTION (const_section,		\                   in_const,			\                   ".const", 0)			\ SECTION_FUNCTION (const_data_section,		\                   in_const_data,		\                   ".const_data", 0)		\ SECTION_FUNCTION (cstring_section,		\ 		  in_cstring,			\ 		  ".cstring", 0)		\ SECTION_FUNCTION (literal4_section,		\ 		  in_literal4,			\ 		  ".literal4", 0)		\ SECTION_FUNCTION (literal8_section,		\ 		  in_literal8,			\ 		  ".literal8", 0)		\ SECTION_FUNCTION (constructor_section,		\ 		  in_constructor,		\ 		  ".constructor", 0)		\ SECTION_FUNCTION (mod_init_section,		\ 		  in_mod_init,			\ 		  ".mod_init_func", 0)	\ SECTION_FUNCTION (mod_term_section, \ 		  in_mod_term,			\ 		  ".mod_term_func", 0)	\ SECTION_FUNCTION (destructor_section,		\ 		  in_destructor,		\ 		  ".destructor", 0)		\ SECTION_FUNCTION (objc_class_section,		\ 		  in_objc_class,		\ 		  ".objc_class", 1)		\ SECTION_FUNCTION (objc_meta_class_section,	\ 		  in_objc_meta_class,		\ 		  ".objc_meta_class", 1)	\ SECTION_FUNCTION (objc_category_section,	\ 		  in_objc_category,		\ 		".objc_category", 1)		\ SECTION_FUNCTION (objc_class_vars_section,	\ 		  in_objc_class_vars,		\ 		  ".objc_class_vars", 1)	\ SECTION_FUNCTION (objc_instance_vars_section,	\ 		  in_objc_instance_vars,	\ 		  ".objc_instance_vars", 1)	\ SECTION_FUNCTION (objc_cls_meth_section,	\ 		  in_objc_cls_meth,		\ 		  ".objc_cls_meth", 1)	\ SECTION_FUNCTION (objc_inst_meth_section,	\ 		  in_objc_inst_meth,		\ 		  ".objc_inst_meth", 1)	\ SECTION_FUNCTION (objc_cat_cls_meth_section,	\ 		  in_objc_cat_cls_meth,		\ 		  ".objc_cat_cls_meth", 1)	\ SECTION_FUNCTION (objc_cat_inst_meth_section,	\ 		  in_objc_cat_inst_meth,	\ 		  ".objc_cat_inst_meth", 1)	\ SECTION_FUNCTION (objc_selector_refs_section,	\ 		  in_objc_selector_refs,	\ 		  ".objc_message_refs", 1)	\ SECTION_FUNCTION (objc_selector_fixup_section,	\ 		  in_objc_selector_fixup,	\ 		  ".section __OBJC, __sel_fixup", 1)	\ SECTION_FUNCTION (objc_symbols_section,		\ 		  in_objc_symbols,		\ 		  ".objc_symbols", 1)	\ SECTION_FUNCTION (objc_module_info_section,	\ 		  in_objc_module_info,		\ 		  ".objc_module_info", 1)	\ SECTION_FUNCTION (objc_protocol_section,	\ 		  in_objc_protocol,		\ 		  ".objc_protocol", 1)	\ SECTION_FUNCTION (objc_string_object_section,	\ 		  in_objc_string_object,	\ 		  ".objc_string_object", 1)	\ SECTION_FUNCTION (objc_constant_string_object_section,	\ 		  in_objc_constant_string_object,	\ 		  ".section __OBJC, __cstring_object", 1)	\
comment|/* Fix-and-Continue image marker.  */
value|\ SECTION_FUNCTION (objc_image_info_section,	\                   in_objc_image_info,		\                   ".section __OBJC, __image_info", 1)	\ SECTION_FUNCTION (objc_class_names_section,	\ 		in_objc_class_names,		\ 		".objc_class_names", 1)	\ SECTION_FUNCTION (objc_meth_var_names_section,	\ 		in_objc_meth_var_names,		\ 		".objc_meth_var_names", 1)	\ SECTION_FUNCTION (objc_meth_var_types_section,	\ 		in_objc_meth_var_types,		\ 		".objc_meth_var_types", 1)	\ SECTION_FUNCTION (objc_cls_refs_section,	\ 		in_objc_cls_refs,		\ 		".objc_cls_refs", 1)		\ 						\ SECTION_FUNCTION (machopic_lazy_symbol_ptr_section,	\ 		in_machopic_lazy_symbol_ptr,		\ 		".lazy_symbol_pointer", 0)	\ SECTION_FUNCTION (machopic_nl_symbol_ptr_section,	\ 		in_machopic_nl_symbol_ptr,		\ 		".non_lazy_symbol_pointer", 0)	\ SECTION_FUNCTION (machopic_symbol_stub_section,		\ 		in_machopic_symbol_stub,		\ 		".symbol_stub", 0)		\ SECTION_FUNCTION (machopic_symbol_stub1_section,	\ 		in_machopic_symbol_stub1,		\ 		".section __TEXT,__symbol_stub1,symbol_stubs,pure_instructions,16", 0)\ SECTION_FUNCTION (machopic_picsymbol_stub_section,	\ 		in_machopic_picsymbol_stub,		\ 		".picsymbol_stub", 0)		\ SECTION_FUNCTION (machopic_picsymbol_stub1_section,	\ 		in_machopic_picsymbol_stub1,		\ 		".section __TEXT,__picsymbolstub1,symbol_stubs,pure_instructions,32", 0)\ SECTION_FUNCTION (darwin_exception_section,		\ 		in_darwin_exception,			\ 		".section __DATA,__gcc_except_tab", 0)	\ SECTION_FUNCTION (darwin_eh_frame_section,		\ 		in_darwin_eh_frame,			\ 		".section __TEXT,__eh_frame", 0)	\ 							\ static void					\ objc_section_init (void)			\ {						\   static int been_here = 0;			\ 						\   if (been_here == 0)				\     {						\       been_here = 1;				\
comment|/* written, cold -> hot */
value|\       objc_cat_cls_meth_section ();		\       objc_cat_inst_meth_section ();		\       objc_string_object_section ();		\       objc_constant_string_object_section ();	\       objc_selector_refs_section ();		\       objc_selector_fixup_section ();		\       objc_cls_refs_section ();			\       objc_class_section ();			\       objc_meta_class_section ();		\
comment|/* shared, hot -> cold */
value|\       objc_cls_meth_section ();			\       objc_inst_meth_section ();		\       objc_protocol_section ();			\       objc_class_names_section ();		\       objc_meth_var_types_section ();		\       objc_meth_var_names_section ();		\       objc_category_section ();			\       objc_class_vars_section ();		\       objc_instance_vars_section ();		\       objc_module_info_section ();		\       objc_symbols_section ();			\     }						\ }
end_define

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|const_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_SECTION
value|machopic_select_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|machopic_select_rtx_section
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
value|do {								\ 	 if (FILE) {							\ 	   if (MACHOPIC_INDIRECT)					\ 	     fprintf (FILE, "\t.lazy_reference ");			\ 	   else								\ 	     fprintf (FILE, "\t.reference ");				\ 	   assemble_name (FILE, NAME);					\ 	   fprintf (FILE, "\n");					\ 	 }                                                              \        } while (0)
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
value|do {								\ 	 if (FILE) {							\ 	   fprintf (FILE, "\t");					\ 	   assemble_name (FILE, NAME);					\ 	   fprintf (FILE, "=0\n");					\ 	   (*targetm.asm_out.globalize_label) (FILE, NAME);		\ 	 }								\        } while (0)
end_define

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|".globl "
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_GLOBALIZE_LABEL
value|darwin_globalize_label
end_define

begin_comment
comment|/* Emit an assembler directive to set visibility for a symbol.  Used    to support visibility attribute and Darwin's private extern    feature. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_ASSEMBLE_VISIBILITY
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_ASSEMBLE_VISIBILITY
value|darwin_assemble_visibility
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
name|MACHO_DYNAMIC_NO_PIC_P
value|(TARGET_DYNAMIC_NO_PIC)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_INDIRECT
value|(flag_pic || MACHO_DYNAMIC_NO_PIC_P)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_JUST_INDIRECT
value|(flag_pic == 1 || MACHO_DYNAMIC_NO_PIC_P)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_PURE
value|(flag_pic == 2&& ! MACHO_DYNAMIC_NO_PIC_P)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|TARGET_ENCODE_SECTION_INFO
value|darwin_encode_section_info
end_define

begin_undef
undef|#
directive|undef
name|TARGET_STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|TARGET_STRIP_NAME_ENCODING
value|darwin_strip_name_encoding
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
value|do {								\     const char *symbol_ = darwin_strip_name_encoding (SYMBOL);	\     char *buffer_ = (BUF);					\     if (symbol_[0] == '"')					\       {								\         strcpy (buffer_, "\"L");				\         strcpy (buffer_ + 2, symbol_ + 1);			\ 	strcpy (buffer_ + (SYMBOL_LENGTH), "$lazy_ptr\"");	\       }								\     else if (name_needs_quotes (symbol_))			\       {								\         strcpy (buffer_, "\"L");				\         strcpy (buffer_ + 2, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 2, "$lazy_ptr\"");	\       }								\     else							\       {								\         strcpy (buffer_, "L");					\         strcpy (buffer_ + 1, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 1, "$lazy_ptr");	\       }								\   } while (0)
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

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

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
value|(((CODE) == 2&& (GLOBAL) == 1) \    ? (DW_EH_PE_pcrel | DW_EH_PE_indirect) : \      ((CODE) == 1 || (GLOBAL) == 0) ? DW_EH_PE_pcrel : DW_EH_PE_absptr)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_DELTA
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|darwin_asm_output_dwarf_delta (FILE, SIZE, LABEL1, LABEL2)
end_define

begin_define
define|#
directive|define
name|TARGET_TERMINATE_DW2_EH_FRAME_INFO
value|false
end_define

begin_define
define|#
directive|define
name|DARWIN_REGISTER_TARGET_PRAGMAS
parameter_list|()
define|\
value|do {								\     c_register_pragma (0, "mark", darwin_pragma_ignore);	\     c_register_pragma (0, "options", darwin_pragma_options);	\     c_register_pragma (0, "segment", darwin_pragma_ignore);	\     c_register_pragma (0, "unused", darwin_pragma_unused);	\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

end_unit

