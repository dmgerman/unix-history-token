begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for Darwin (Mac OS X) systems.    Copyright (C) 1989, 1990, 1991, 1992, 1993, 2000, 2001, 2002, 2003, 2004,    2005    Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_DARWIN_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_DARWIN_H
end_define

begin_comment
comment|/* The definitions in this file are common to all processor types    running Darwin, which is the kernel for Mac OS X.  Darwin is    basically a BSD user layer laid over a Mach kernel, then evolved    for many years (at NeXT) in parallel with other Unix systems.  So    while the runtime is a somewhat idiosyncratic Mach-based thing,    other definitions look like they would for a BSD variant.  */
end_comment

begin_comment
comment|/* Although NeXT ran on many different architectures, as of Jan 2001    the only supported Darwin targets are PowerPC and x86.  */
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
comment|/* Suppress g++ attempt to link in the math library automatically. */
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
comment|/* True if pragma ms_struct is in effect.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|int
name|darwin_ms_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This table intercepts weirdo options whose names would interfere    with normal driver conventions, and either translates them into    standardly-named options, or adds a 'Z' so that they can get to    specs processing without interference.     Do not expand a linker option to "-Xlinker -<option>", since that    forfeits the ability to control via spec strings later.  However,    as a special exception, do this translation with -filelist, because    otherwise the driver will think there are no input files and quit.    (The alternative would be to hack the driver to recognize -filelist    specially, but it's simpler to use the translation table.)     Note that an option name with a prefix that matches another option    name, that also takes an argument, needs to be modified so the    prefix is different, otherwise a '*' after the shorter option will    match with the longer one.     The SUBTARGET_OPTION_TRANSLATE_TABLE macro, which _must_ be defined    in gcc/config/{i386,rs6000}/darwin.h, should contain any additional    command-line option translations specific to the particular target    architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTION_TRANSLATE_TABLE
define|\
value|{ "-all_load", "-Zall_load" },  \   { "-allowable_client", "-Zallowable_client" },  \   { "-arch_errors_fatal", "-Zarch_errors_fatal" },  \   { "-bind_at_load", "-Zbind_at_load" },  \   { "-bundle", "-Zbundle" },  \   { "-bundle_loader", "-Zbundle_loader" },  \   { "-weak_reference_mismatches", "-Zweak_reference_mismatches" },  \   { "-dead_strip", "-Zdead_strip" }, \   { "-no_dead_strip_inits_and_terms", "-Zno_dead_strip_inits_and_terms" }, \   { "-dependency-file", "-MF" }, \   { "-dylib_file", "-Zdylib_file" }, \   { "-dynamic", "-Zdynamic" },  \   { "-dynamiclib", "-Zdynamiclib" },  \   { "-exported_symbols_list", "-Zexported_symbols_list" },  \   { "-gfull", "-g -fno-eliminate-unused-debug-symbols" }, \   { "-gused", "-g -feliminate-unused-debug-symbols" }, \   { "-segaddr", "-Zsegaddr" }, \   { "-segs_read_only_addr", "-Zsegs_read_only_addr" }, \   { "-segs_read_write_addr", "-Zsegs_read_write_addr" }, \   { "-seg_addr_table", "-Zseg_addr_table" }, \   { "-seg_addr_table_filename", "-Zfn_seg_addr_table_filename" }, \   { "-fapple-kext", "-fapple-kext -static -Wa,-static" }, \   { "-filelist", "-Xlinker -filelist -Xlinker" },  \   { "-findirect-virtual-calls", "-fapple-kext" }, \   { "-flat_namespace", "-Zflat_namespace" },  \   { "-force_cpusubtype_ALL", "-Zforce_cpusubtype_ALL" },  \   { "-force_flat_namespace", "-Zforce_flat_namespace" },  \   { "-framework", "-Xlinker -framework -Xlinker" },  \   { "-fterminated-vtables", "-fapple-kext" }, \   { "-image_base", "-Zimage_base" },  \   { "-init", "-Zinit" },  \   { "-install_name", "-Zinstall_name" },  \   { "-mkernel", "-mkernel -static -Wa,-static" }, \   { "-multiply_defined_unused", "-Zmultiplydefinedunused" },  \   { "-multiply_defined", "-Zmultiply_defined" },  \   { "-multi_module", "-Zmulti_module" },  \   { "-static", "-static -Wa,-static" },  \   { "-single_module", "-Zsingle_module" },  \   { "-unexported_symbols_list", "-Zunexported_symbols_list" }, \   SUBTARGET_OPTION_TRANSLATE_TABLE
end_define

begin_define
define|#
directive|define
name|SUBSUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\     darwin_override_options ();						\   } while (0)
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
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR) ? 1 :    \    !strcmp (STR, "Zallowable_client") ? 1 :     \    !strcmp (STR, "arch") ? 1 :                  \    !strcmp (STR, "arch_only") ? 1 :             \    !strcmp (STR, "Zbundle_loader") ? 1 :        \    !strcmp (STR, "client_name") ? 1 :           \    !strcmp (STR, "compatibility_version") ? 1 : \    !strcmp (STR, "current_version") ? 1 :       \    !strcmp (STR, "Zdylib_file") ? 1 :           \    !strcmp (STR, "Zexported_symbols_list") ? 1 : \    !strcmp (STR, "Zimage_base") ? 1 :           \    !strcmp (STR, "Zinit") ? 1 :                 \    !strcmp (STR, "Zinstall_name") ? 1 :         \    !strcmp (STR, "Zmultiplydefinedunused") ? 1 : \    !strcmp (STR, "Zmultiply_defined") ? 1 :     \    !strcmp (STR, "precomp-trustfile") ? 1 :     \    !strcmp (STR, "read_only_relocs") ? 1 :      \    !strcmp (STR, "sectcreate") ? 3 :            \    !strcmp (STR, "sectorder") ? 3 :             \    !strcmp (STR, "Zsegaddr") ? 2 :              \    !strcmp (STR, "Zsegs_read_only_addr") ? 1 :  \    !strcmp (STR, "Zsegs_read_write_addr") ? 1 : \    !strcmp (STR, "Zseg_addr_table") ? 1 :       \    !strcmp (STR, "Zfn_seg_addr_table_filename") ? 1 :\    !strcmp (STR, "seg1addr") ? 1 :              \    !strcmp (STR, "segprot") ? 3 :               \    !strcmp (STR, "sub_library") ? 1 :           \    !strcmp (STR, "sub_umbrella") ? 1 :          \    !strcmp (STR, "umbrella") ? 1 :              \    !strcmp (STR, "undefined") ? 1 :             \    !strcmp (STR, "Zunexported_symbols_list") ? 1 : \    !strcmp (STR, "Zweak_reference_mismatches") ? 1 : \    !strcmp (STR, "pagezero_size") ? 1 :         \    !strcmp (STR, "segs_read_only_addr") ? 1 :   \    !strcmp (STR, "segs_read_write_addr") ? 1 :  \    !strcmp (STR, "sectalign") ? 3 :             \    !strcmp (STR, "sectobjectsymbols") ? 2 :     \    !strcmp (STR, "segcreate") ? 3 :             \    !strcmp (STR, "dylinker_install_name") ? 1 : \    0)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_C_COMMON_OVERRIDE_OPTIONS
value|do {                        \     if (flag_mkernel || flag_apple_kext)				\       {									\ 	if (flag_use_cxa_atexit == 2)					\ 	  flag_use_cxa_atexit = 0;					\
comment|/* kexts should always be built without the coalesced sections	\ 	   because the kernel loader doesn't grok such sections.  */
value|\ 	flag_weak = 0;							\
comment|/* No RTTI in kexts.  */
value|\ 	flag_rtti = 0;							\       }									\   } while (0)
end_define

begin_comment
comment|/* Machine dependent cpp options.  Don't add more options here, add    them to darwin_cpp_builtins in darwin-c.c.  */
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
value|"%{static:%{!dynamic:-D__STATIC__}}%{!static:-D__DYNAMIC__}" \ 	" %{pthread:-D_REENTRANT}"
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
value|"\ %{!fdump=*:%{!fsyntax-only:%{!precomp:%{!c:%{!M:%{!MM:%{!E:%{!S:\     %{!Zdynamiclib:%(linker)}%{Zdynamiclib:/usr/bin/libtool} \     %l %X %{d} %{s} %{t} %{Z} \     %{!Zdynamiclib:%{A} %{e*} %{m} %{N} %{n} %{r} %{u*} %{x} %{z}} \     %{@:-o %f%u.out}%{!@:%{o*}%{!o:-o a.out}} \     %{!A:%{!nostdlib:%{!nostartfiles:%S}}} \     %{L*} %{fopenmp:%:include(libgomp.spec)%(link_gomp)}   \     %(link_libgcc) %o %{fprofile-arcs|fprofile-generate|coverage:-lgcov} \     %{!nostdlib:%{!nodefaultlibs:%(link_ssp) %G %L}} \     %{!A:%{!nostdlib:%{!nostartfiles:%E}}} %{T*} %{F*} }}}}}}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_SYSTEM_ROOT
end_ifdef

begin_define
define|#
directive|define
name|LINK_SYSROOT_SPEC
define|\
value|"%{isysroot*:-syslibroot %*;:-syslibroot " TARGET_SYSTEM_ROOT "}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SYSROOT_SPEC
value|"%{isysroot*:-syslibroot %*}"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|"%{static}%{!static:-dynamic} \    %{fgnu-runtime:%:replace-outfile(-lobjc -lobjc-gnu)}\    %{!Zdynamiclib: \      %{Zforce_cpusubtype_ALL:-arch %(darwin_arch) -force_cpusubtype_ALL} \      %{!Zforce_cpusubtype_ALL:-arch %(darwin_subarch)} \      %{Zbundle:-bundle} \      %{Zbundle_loader*:-bundle_loader %*} \      %{client_name*} \      %{compatibility_version*:%e-compatibility_version only allowed with -dynamiclib\ } \      %{current_version*:%e-current_version only allowed with -dynamiclib} \      %{Zforce_flat_namespace:-force_flat_namespace} \      %{Zinstall_name*:%e-install_name only allowed with -dynamiclib} \      %{keep_private_externs} \      %{private_bundle} \     } \    %{Zdynamiclib: \      %{Zbundle:%e-bundle not allowed with -dynamiclib} \      %{Zbundle_loader*:%e-bundle_loader not allowed with -dynamiclib} \      %{client_name*:%e-client_name not allowed with -dynamiclib} \      %{compatibility_version*} \      %{current_version*} \      %{Zforce_cpusubtype_ALL:-arch_only %(darwin_arch)} \      %{!Zforce_cpusubtype_ALL: -arch_only %(darwin_subarch)} \      %{Zforce_flat_namespace:%e-force_flat_namespace not allowed with -dynamiclib} \      %{Zinstall_name*:-install_name %*} \      %{keep_private_externs:%e-keep_private_externs not allowed with -dynamiclib} \      %{private_bundle:%e-private_bundle not allowed with -dynamiclib} \     } \    %{Zall_load:-all_load}%{Zdynamiclib:%{!Zall_load:-noall_load}} \    %{Zallowable_client*:-allowable_client %*} \    %{Zbind_at_load:-bind_at_load} \    %{Zarch_errors_fatal:-arch_errors_fatal} \    %{Zdead_strip:-dead_strip} \    %{Zno_dead_strip_inits_and_terms:-no_dead_strip_inits_and_terms} \    %{Zdylib_file*:-dylib_file %*} \    %{Zdynamic:-dynamic}\    %{Zexported_symbols_list*:-exported_symbols_list %*} \    %{Zflat_namespace:-flat_namespace} \    %{headerpad_max_install_names*} \    %{Zimage_base*:-image_base %*} \    %{Zinit*:-init %*} \    %{mmacosx-version-min=*:-macosx_version_min %*} \    %{!mmacosx-version-min=*:%{shared-libgcc:-macosx_version_min 10.3}} \    %{nomultidefs} \    %{Zmulti_module:-multi_module} %{Zsingle_module:-single_module} \    %{Zmultiply_defined*:-multiply_defined %*} \    %{!Zmultiply_defined*:%{shared-libgcc: \      %:version-compare(< 10.5 mmacosx-version-min= -multiply_defined) \      %:version-compare(< 10.5 mmacosx-version-min= suppress)}} \    %{Zmultiplydefinedunused*:-multiply_defined_unused %*} \    %{prebind} %{noprebind} %{nofixprebinding} %{prebind_all_twolevel_modules} \    %{read_only_relocs} \    %{sectcreate*} %{sectorder*} %{seg1addr*} %{segprot*} \    %{Zsegaddr*:-segaddr %*} \    %{Zsegs_read_only_addr*:-segs_read_only_addr %*} \    %{Zsegs_read_write_addr*:-segs_read_write_addr %*} \    %{Zseg_addr_table*: -seg_addr_table %*} \    %{Zfn_seg_addr_table_filename*:-seg_addr_table_filename %*} \    %{sub_library*} %{sub_umbrella*} \    " LINK_SYSROOT_SPEC " \    %{twolevel_namespace} %{twolevel_namespace_hints} \    %{umbrella*} \    %{undefined*} \    %{Zunexported_symbols_list*:-unexported_symbols_list %*} \    %{Zweak_reference_mismatches*:-weak_reference_mismatches %*} \    %{!Zweak_reference_mismatches*:-weak_reference_mismatches non-weak} \    %{X} \    %{y*} \    %{w} \    %{pagezero_size*} %{segs_read_*} %{seglinkedit} %{noseglinkedit}  \    %{sectalign*} %{sectobjectsymbols*} %{segcreate*} %{whyload} \    %{whatsloaded} %{dylinker_install_name*} \    %{dylinker} %{Mach} "
end_define

begin_comment
comment|/* Machine dependent libraries.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!static:-lSystem}"
end_define

begin_comment
comment|/* Support -mmacosx-version-min by supplying different (stub) libgcc_s.dylib    libraries to link against, and by not linking against libgcc_s on    earlier-than-10.3.9.     Note that by default, -lgcc_eh is not linked against!  This is    because in a future version of Darwin the EH frame information may    be in a new format, or the fallback routine might be changed; if    you want to explicitly link against the static version of those    routines, because you know you don't need to unwind through system    libraries, you need to explicitly say -static-libgcc.     If it is linked against, it has to be before -lgcc, because it may    need symbols from -lgcc.  */
end_comment

begin_undef
undef|#
directive|undef
name|REAL_LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|REAL_LIBGCC_SPEC
define|\
value|"%{static-libgcc|static: -lgcc_eh -lgcc;				   \       shared-libgcc|fexceptions|fgnu-runtime:				   \        %:version-compare(!> 10.5 mmacosx-version-min= -lgcc_s.10.4)	   \        %:version-compare(>= 10.5 mmacosx-version-min= -lgcc_s.10.5)	   \        -lgcc;								   \       :%:version-compare(>< 10.3.9 10.5 mmacosx-version-min= -lgcc_s.10.4) \        %:version-compare(>= 10.5 mmacosx-version-min= -lgcc_s.10.5)	   \        -lgcc}"
end_define

begin_comment
comment|/* We specify crt0.o as -lcrt0.o so that ld will search the library path.     crt3.o provides __cxa_atexit on systems that don't have it.  Since    it's only used with C++, which requires passing -shared-libgcc, key    off that to avoid unnecessarily adding a destructor to every    powerpc program built.  */
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
value|"%{!Zdynamiclib:%{Zbundle:%{!static:-lbundle1.o}}			    \      %{!Zbundle:%{pg:%{static:-lgcrt0.o}				    \                      %{!static:%{object:-lgcrt0.o}			    \                                %{!object:%{preload:-lgcrt0.o}		    \                                  %{!preload:-lgcrt1.o %(darwin_crt2)}}}}    \                 %{!pg:%{static:-lcrt0.o}				    \                       %{!static:%{object:-lcrt0.o}			    \                                 %{!object:%{preload:-lcrt0.o}		    \                                   %{!preload:-lcrt1.o %(darwin_crt2)}}}}}}  \   %{shared-libgcc:%:version-compare(< 10.5 mmacosx-version-min= crt3.o%s)}"
end_define

begin_comment
comment|/* The native Darwin linker doesn't necessarily place files in the order    that they're specified on the link line.  Thus, it is pointless    to put anything in ENDFILE_SPEC.  */
end_comment

begin_comment
comment|/* #define ENDFILE_SPEC "" */
end_comment

begin_comment
comment|/* Default Darwin ASM_SPEC, very simple.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-arch %(darwin_arch) \   %{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL}"
end_define

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

begin_define
define|#
directive|define
name|DEBUG_FRAME_SECTION
value|"__DWARF,__debug_frame,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_INFO_SECTION
value|"__DWARF,__debug_info,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_ABBREV_SECTION
value|"__DWARF,__debug_abbrev,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_ARANGES_SECTION
value|"__DWARF,__debug_aranges,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_MACINFO_SECTION
value|"__DWARF,__debug_macinfo,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_LINE_SECTION
value|"__DWARF,__debug_line,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_LOC_SECTION
value|"__DWARF,__debug_loc,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_PUBNAMES_SECTION
value|"__DWARF,__debug_pubnames,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_PUBTYPES_SECTION
value|"__DWARF,__debug_pubtypes,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_STR_SECTION
value|"__DWARF,__debug_str,regular,debug"
end_define

begin_define
define|#
directive|define
name|DEBUG_RANGES_SECTION
value|"__DWARF,__debug_ranges,regular,debug"
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

begin_define
define|#
directive|define
name|DBX_OUTPUT_NULL_N_SO_AT_MAIN_SOURCE_FILE_END
end_define

begin_comment
comment|/* GCC's definition of 'one_only' is the same as its definition of 'weak'.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_DECL_ONE_ONLY
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_WEAK (DECL) = 1)
end_define

begin_comment
comment|/* Mach-O supports 'weak imports', and 'weak definitions' in coalesced    sections.  machopic_select_section ensures that weak variables go in    coalesced sections.  Weak aliases (or any other kind of aliases) are    not supported.  Weak symbols that aren't visible outside the .s file    are not supported.  */
end_comment

begin_define
define|#
directive|define
name|ASM_WEAKEN_DECL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|ALIAS
parameter_list|)
define|\
value|do {									\     if (ALIAS)								\       {									\ 	warning (0, "alias definitions not supported in Mach-O; ignored");	\ 	break;								\       }									\  									\     if (! DECL_EXTERNAL (DECL)&& TREE_PUBLIC (DECL))			\       targetm.asm_out.globalize_label (FILE, NAME);			\     if (DECL_EXTERNAL (DECL))						\       fputs ("\t.weak_reference ", FILE);				\     else if (! lookup_attribute ("weak", DECL_ATTRIBUTES (DECL))	\&& lookup_attribute ("weak_import", DECL_ATTRIBUTES (DECL)))	\       break;								\     else if (TREE_PUBLIC (DECL))					\       fputs ("\t.weak_definition ", FILE);				\     else								\       break;								\     assemble_name (FILE, NAME);						\     fputc ('\n', FILE);							\   } while (0)
end_define

begin_comment
comment|/* Darwin has the pthread routines in libSystem, which every program    links to, so there's no need for weak-ness for that.  */
end_comment

begin_define
define|#
directive|define
name|GTHREAD_USE_WEAK
value|0
end_define

begin_comment
comment|/* The Darwin linker imposes two limitations on common symbols: they    can't have hidden visibility, and they can't appear in dylibs.  As    a consequence, we should never use common symbols to represent    vague linkage. */
end_comment

begin_undef
undef|#
directive|undef
name|USE_COMMON_FOR_ONE_ONLY
end_undef

begin_define
define|#
directive|define
name|USE_COMMON_FOR_ONE_ONLY
value|0
end_define

begin_comment
comment|/* The Darwin linker doesn't want coalesced symbols to appear in    a static archive's table of contents. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_WEAK_NOT_IN_ARCHIVE_TOC
end_undef

begin_define
define|#
directive|define
name|TARGET_WEAK_NOT_IN_ARCHIVE_TOC
value|1
end_define

begin_comment
comment|/* On Darwin, we don't (at the time of writing) have linkonce sections    with names, so it's safe to make the class data not comdat.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT
value|hook_bool_void_false
end_define

begin_comment
comment|/* For efficiency, on Darwin the RTTI information that is always    emitted in the standard C++ library should not be COMDAT.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CXX_LIBRARY_RTTI_COMDAT
value|hook_bool_void_false
end_define

begin_comment
comment|/* We make exception information linkonce. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_USES_WEAK_UNWIND_INFO
end_undef

begin_define
define|#
directive|define
name|TARGET_USES_WEAK_UNWIND_INFO
value|1
end_define

begin_comment
comment|/* We need to use a nonlocal label for the start of an EH frame: the    Darwin linker requires that a coalesced section start with a label.    Unfortunately, it also requires that 'debug' sections don't contain    labels.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_BEGIN_LABEL
end_undef

begin_define
define|#
directive|define
name|FRAME_BEGIN_LABEL
value|(for_eh ? "EH_frame" : "Lframe")
end_define

begin_comment
comment|/* Emit a label for the FDE corresponding to DECL.  EMPTY means    emit a label for an empty FDE. */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_EMIT_UNWIND_LABEL
value|darwin_emit_unwind_label
end_define

begin_comment
comment|/* Emit a label to separate the exception table.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL
value|darwin_emit_except_table_label
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
comment|/* The RTTI data (e.g., __ti4name) is common and public (and static),    but it does need to be referenced via indirect PIC data pointers.    The machopic_define_symbol calls are telling the machopic subsystem    that the name *is* defined in this module, so it doesn't need to    make them indirect.  */
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
value|do {									\     const char *xname = NAME;						\     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\     if (! DECL_WEAK (DECL)						\&& ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\             || DECL_INITIAL (DECL)))					\         machopic_define_symbol (DECL_RTL (DECL));			\     if ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL))						\       (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\     ASM_OUTPUT_LABEL (FILE, xname);					\
comment|/* Darwin doesn't support zero-size objects, so give them a		\        byte.  */
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
value|do {									\     const char *xname = NAME;						\     if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\       xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\     if (! DECL_WEAK (DECL)						\&& ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\             || DECL_INITIAL (DECL)))					\         machopic_define_symbol (DECL_RTL (DECL));			\     if ((TREE_STATIC (DECL)						\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL))						\       (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\     ASM_OUTPUT_LABEL (FILE, xname);					\   } while (0)
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
value|do {									     \        const char *xname = (NAME);					     \        if (! strcmp (xname, "<pic base>"))				     \          machopic_output_function_base_name(FILE);                           \        else if (xname[0] == '&' || xname[0] == '*')			     \          {								     \            int len = strlen (xname);					     \ 	   if (len> 6&& !strcmp ("$stub", xname + len - 5))		     \ 	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \ 	   else if (len> 7&& !strcmp ("$stub\"", xname + len - 6))	     \ 	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \ 	   else if (len> 14&& !strcmp ("$non_lazy_ptr", xname + len - 13)) \ 	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \ 	   else if (len> 15&& !strcmp ("$non_lazy_ptr\"", xname + len - 14)) \ 	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \ 	   if (xname[1] != '"'&& name_needs_quotes (&xname[1]))	     \ 	     fprintf (FILE, "\"%s\"",&xname[1]);			     \ 	   else								     \ 	     fputs (&xname[1], FILE); 					     \ 	 }								     \        else if (xname[0] == '+' || xname[0] == '-')			     \          fprintf (FILE, "\"%s\"", xname);				     \        else if (!strncmp (xname, "_OBJC_", 6))				     \          fprintf (FILE, "L%s", xname);					     \        else if (!strncmp (xname, ".objc_class_name_", 17))		     \ 	 fprintf (FILE, "%s", xname);					     \        else if (xname[0] != '"'&& name_needs_quotes (xname))		     \ 	 fprintf (FILE, "\"%s\"", xname);				     \        else								     \          asm_fprintf (FILE, "%U%s", xname);				     \   } while (0)
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
value|"\t.text"
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
value|"\t.data"
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
value|do {									\     unsigned HOST_WIDE_INT _new_size = SIZE;				\     fputs (".lcomm ", (FILE));						\     assemble_name ((FILE), (NAME));					\     if (_new_size == 0) _new_size = 1;					\     fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", _new_size,	\ 	     floor_log2 ((ALIGN) / BITS_PER_UNIT));			\     if ((DECL)&& ((TREE_STATIC (DECL)					\&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\         || DECL_INITIAL (DECL)))					\       {									\ 	(* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\ 	machopic_define_symbol (DECL_RTL (DECL));			\       }									\   } while (0)
end_define

begin_comment
comment|/* The maximum alignment which the object file format can support in    bits.  For Mach-O, this is 2^15 bytes.  */
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
value|(0x8000 * 8)
end_define

begin_comment
comment|/* Declare the section variables.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USED_FOR_TARGET
end_ifndef

begin_enum
enum|enum
name|darwin_section_enum
block|{
define|#
directive|define
name|DEF_SECTION
parameter_list|(
name|NAME
parameter_list|,
name|FLAGS
parameter_list|,
name|DIRECTIVE
parameter_list|,
name|OBJC
parameter_list|)
value|NAME,
include|#
directive|include
file|"darwin-sections.def"
undef|#
directive|undef
name|DEF_SECTION
name|NUM_DARWIN_SECTIONS
block|}
enum|;
end_enum

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|darwin_sections
index|[
name|NUM_DARWIN_SECTIONS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|USE_SELECT_SECTION_FOR_FUNCTIONS
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

begin_undef
undef|#
directive|undef
name|TARGET_ASM_UNIQUE_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|darwin_unique_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FUNCTION_RODATA_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_RODATA_SECTION
value|default_no_function_rodata_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_RELOC_RW_MASK
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_RELOC_RW_MASK
value|machopic_reloc_rw_mask
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
comment|/* Emit an assembler directive to set visibility for a symbol.  Used    to support visibility attribute and Darwin's private extern    feature.  */
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

begin_comment
comment|/* Extra attributes for Darwin.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_ATTRIBUTE_TABLE
define|\
comment|/* { name, min_len, max_len, decl_req, type_req, fn_type_req, handler } */
define|\
value|{ "apple_kext_compatibility", 0, 0, false, true, false,		     \     darwin_handle_kext_attribute },					     \   { "weak_import", 0, 0, true, false, false,				     \     darwin_handle_weak_import_attribute }
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

begin_undef
undef|#
directive|undef
name|TARGET_ASM_MARK_DECL_PRESERVED
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_MARK_DECL_PRESERVED
value|darwin_mark_decl_preserved
end_define

begin_comment
comment|/* Set on a symbol with SYMBOL_FLAG_FUNCTION or    MACHO_SYMBOL_FLAG_VARIABLE to indicate that the function or    variable has been defined in this translation unit.    When porting Mach-O to new architectures you need to make    sure these aren't clobbered by the backend.  */
end_comment

begin_define
define|#
directive|define
name|MACHO_SYMBOL_FLAG_VARIABLE
value|(SYMBOL_FLAG_MACH_DEP)
end_define

begin_define
define|#
directive|define
name|MACHO_SYMBOL_FLAG_DEFINED
value|((SYMBOL_FLAG_MACH_DEP)<< 1)
end_define

begin_comment
comment|/* Set on a symbol to indicate when fix-and-continue style code    generation is being used and the symbol refers to a static symbol    that should be rebound from new instances of a translation unit to    the original instance of the data.  */
end_comment

begin_define
define|#
directive|define
name|MACHO_SYMBOL_STATIC
value|((SYMBOL_FLAG_MACH_DEP)<< 2)
end_define

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
value|(MACHO_DYNAMIC_NO_PIC_P)
end_define

begin_define
define|#
directive|define
name|MACHOPIC_PURE
value|(flag_pic&& ! MACHO_DYNAMIC_NO_PIC_P)
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
value|default_strip_name_encoding
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
value|do {								\     const char *symbol_ = (SYMBOL);                             \     char *buffer_ = (BUF);					\     if (symbol_[0] == '"')					\       {								\         strcpy (buffer_, "\"L");				\         strcpy (buffer_ + 2, symbol_ + 1);			\ 	strcpy (buffer_ + (SYMBOL_LENGTH), "$lazy_ptr\"");	\       }								\     else if (name_needs_quotes (symbol_))			\       {								\         strcpy (buffer_, "\"L");				\         strcpy (buffer_ + 2, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 2, "$lazy_ptr\"");	\       }								\     else							\       {								\         strcpy (buffer_, "L");					\         strcpy (buffer_ + 1, symbol_);				\ 	strcpy (buffer_ + (SYMBOL_LENGTH) + 1, "$lazy_ptr");	\       }								\   } while (0)
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_NAME
value|"__TEXT"
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ATTR
value|",coalesced,no_toc+strip_static_syms+live_support"
end_define

begin_comment
comment|/* Java runtime class list.  */
end_comment

begin_define
define|#
directive|define
name|JCR_SECTION_NAME
value|"__DATA,jcr,regular,no_dead_strip"
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
value|(((CODE) == 2&& (GLOBAL) == 1) \    ? (DW_EH_PE_pcrel | DW_EH_PE_indirect | DW_EH_PE_sdata4) : \      ((CODE) == 1 || (GLOBAL) == 0) ? DW_EH_PE_pcrel : DW_EH_PE_absptr)
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
name|ASM_OUTPUT_DWARF_OFFSET
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|,
name|LABEL
parameter_list|,
name|BASE
parameter_list|)
define|\
value|darwin_asm_output_dwarf_offset (FILE, SIZE, LABEL, BASE)
end_define

begin_define
define|#
directive|define
name|ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX
parameter_list|(
name|ASM_OUT_FILE
parameter_list|,
name|ENCODING
parameter_list|,
name|SIZE
parameter_list|,
name|ADDR
parameter_list|,
name|DONE
parameter_list|)
define|\
value|if (ENCODING == ASM_PREFERRED_EH_DATA_FORMAT (2, 1)) {				\ 	darwin_non_lazy_pcrel (ASM_OUT_FILE, ADDR);					\ 	goto DONE;									\       }
end_define

begin_comment
comment|/* Experimentally, putting jump tables in text is faster on SPEC.    Also this is needed for correctness for coalesced functions.  */
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

begin_define
define|#
directive|define
name|TARGET_TERMINATE_DW2_EH_FRAME_INFO
value|false
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_INIT_SECTIONS
value|darwin_init_sections
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|darwin_asm_named_section
end_define

begin_comment
comment|/* Handle pragma weak and pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_define
define|#
directive|define
name|DARWIN_REGISTER_TARGET_PRAGMAS
parameter_list|()
define|\
value|do {								\
comment|/* APPLE LOCAL begin pragma mark 5614511 */
value|\
comment|/* Removed mark.  */
value|\
comment|/* APPLE LOCAL end pragma mark 5614511 */
value|\     c_register_pragma (0, "options", darwin_pragma_options);	\     c_register_pragma (0, "segment", darwin_pragma_ignore);	\     c_register_pragma (0, "unused", darwin_pragma_unused);	\     c_register_pragma (0, "ms_struct", darwin_pragma_ms_struct); \   } while (0)
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

begin_function_decl
name|void
name|darwin_register_frameworks
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|darwin_register_objc_includes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_EXTRA_PRE_INCLUDES
value|darwin_register_objc_includes
end_define

begin_define
define|#
directive|define
name|TARGET_EXTRA_INCLUDES
value|darwin_register_frameworks
end_define

begin_function_decl
name|void
name|add_framework_path
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_OPTF
value|add_framework_path
end_define

begin_define
define|#
directive|define
name|TARGET_POSIX_IO
end_define

begin_comment
comment|/* All new versions of Darwin have C99 functions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
value|1
end_define

begin_define
define|#
directive|define
name|WINT_TYPE
value|"int"
end_define

begin_comment
comment|/* Every program on darwin links against libSystem which contains the pthread    routines, so there's no need to explicitly call out when doing threaded    work.  */
end_comment

begin_undef
undef|#
directive|undef
name|GOMP_SELF_SPECS
end_undef

begin_define
define|#
directive|define
name|GOMP_SELF_SPECS
value|""
end_define

begin_comment
comment|/* Darwin can't support anchors until we can cope with the adjustments    to size that ASM_DECLARE_OBJECT_NAME and ASM_DECLARE_CONSTANT_NAME    when outputting members of an anchor block and the linker can be    taught to keep them together or we find some other suitable    code-gen technique.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_ANCHOR
value|darwin_asm_output_anchor
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_ANCHOR
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attempt to turn on execute permission for the stack.  This may be     used by INITIALIZE_TRAMPOLINE of the target needs it (that is,     if the target machine can change execute permissions on a page).      There is no way to query the execute permission of the stack, so     we always issue the mprotect() call.      Unfortunately it is not possible to make this namespace-clean.      Also note that no errors should be emitted by this code; it is     considered dangerous for library calls to send messages to     stdout/stderr.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_EXECUTE_STACK
define|\
value|extern void __enable_execute_stack (void *);                            \ void                                                                    \ __enable_execute_stack (void *addr)                                     \ {                                                                       \    extern int mprotect (void *, size_t, int);                           \    extern int getpagesize (void);					\    static int size;                                                     \    static long mask;                                                    \                                                                         \    char *page, *end;                                                    \                                                                         \    if (size == 0)                                                       \      {                                                                  \        size = getpagesize();						\        mask = ~((long) size - 1);                                       \      }                                                                  \                                                                         \    page = (char *) (((long) addr)& mask);                              \    end  = (char *) ((((long) (addr + (TARGET_64BIT ? 48 : 40)))& mask) + size); \                                                                         \
comment|/* 7 == PROT_READ | PROT_WRITE | PROT_EXEC */
value|\    (void) mprotect (page, end - page, 7);                               \ }
end_define

begin_comment
comment|/* For Apple KEXTs, we make the constructors return this to match gcc    2.95.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CXX_CDTOR_RETURNS_THIS
value|(darwin_kextabi_p)
end_define

begin_decl_stmt
specifier|extern
name|int
name|flag_mkernel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_apple_kext
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_KEXTABI
value|flag_apple_kext
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DARWIN_H */
end_comment

end_unit

