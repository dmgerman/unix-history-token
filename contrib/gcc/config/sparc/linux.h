begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for SPARC running Linux-based GNU systems with ELF.    Copyright (C) 1996, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by Eddie C. Dost (ecd@skynet.be)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_DEFAULT_ELF
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* GNU/Linux uses ctype from glibc.a. I am not sure how complete it is.    For now, we play safe. It may change later.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|MULTIBYTE_CHARS
end_undef

begin_define
define|#
directive|define
name|MULTIBYTE_CHARS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add    the GNU/Linux magical crtbegin.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main'.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}\    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}\    crti.o%s %{static:crtbeginT.o%s}\    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for GNU/Linux.  Here we tack on    the GNU/Linux magical crtend.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main', followed by a normal    GNU/Linux "finalizer" file, `crtn.o'.  */
end_comment

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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/* This is for -profile to use -lc_p instead of -lc.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p} \ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ "
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|"-D_GNU_SOURCE %(cpp)"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (sparc GNU/Linux with ELF)");
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
value|{"long-double-64", -MASK_LONG_DOUBLE_128, N_("Use 64 bit long doubles") }, \ {"long-double-128", MASK_LONG_DOUBLE_128, N_("Use 128 bit long doubles") },
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

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

begin_undef
undef|#
directive|undef
name|MAX_WCHAR_TYPE_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ELF__ -Dunix -D__sparc__ -Dlinux -Asystem=unix -Asystem=posix"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
define|\
value|"%{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{posix:-D_POSIX_SOURCE} \ %{mlong-double-128:-D__LONG_DOUBLE_128__}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
define|\
value|"%{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{posix:-D_POSIX_SOURCE} \ %{pthread:-D_REENTRANT} %{mlong-double-128:-D__LONG_DOUBLE_128__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_comment
comment|/* We no longer link with libc_p.a or libg.a by default. If you    want to profile or debug the GNU/Linux C library, please add    -lc_p or -ggdb to LDFLAGS at the link time, respectively.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{!shared: %{p:-lgmon} %{pg:-lgmon} %{profile:-lgmon -lc_p} \      %{!profile:%{!ggdb:-lc} %{ggdb:-lg}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared: -lc} \    %{!shared: %{mieee-fp:-lieee} %{pthread:-lpthread} \      %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{!shared: \      %{mieee-fp:-lieee} %{p:-lgmon -lc_p} %{pg:-lgmon -lc_p} \        %{!p:%{!pg:%{!g*:-lc} %{g*:-lg}}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a LINK_SPEC appropriate for GNU/Linux.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     I took out %{v:%{!V:-V}}. It is too much :-(. They can use    -Wl,-V.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_comment
comment|/* If ELF is the default format, we should not use /lib/elf.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_DEFAULT_ELF
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf32_sparc -Y P,/usr/lib %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib/elf/ld-linux.so.1} \         %{!rpath:-rpath /lib/elf/}} %{static:-static}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf32_sparc -Y P,/usr/lib %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.1}} \         %{static:-static}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf32_sparc -Y P,/usr/lib %{shared:-shared} \   %{!mno-relax:%{!r:-relax}} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.2}} \         %{static:-static}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The sun bundled assembler doesn't accept -Yd, (and neither does gas).    It's safe to pass -s always, even if -g is not used.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{V} %{v:%{!V:-V}} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s %{fpic:-K PIC} \    %{fPIC:-K PIC} %(asm_relax)"
end_define

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
value|(REGNO)
end_define

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
value|do {									\   fputs ("\t.local\t", (FILE));		\   assemble_name ((FILE), (NAME));					\   putc ('\n', (FILE));							\   ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);			\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.common\t"
end_define

begin_comment
comment|/* This is how to output a definition of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
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
value|fprintf (FILE, ".L%s%d:\n", PREFIX, NUM)
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
value|sprintf (LABEL, "*.L%s%ld", PREFIX, (long)(NUM))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define for support of TFmode long double and REAL_ARITHMETIC.    Sparc ABI says that long double is 4 words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_LONG_DOUBLE_128 ? 128 : 64)
end_define

begin_comment
comment|/* Constant which presents upper bound of the above value.  */
end_comment

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* Define this to set long double type size to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LONG_DOUBLE_128__
end_ifdef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_GNULIBC_1
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LD_EH_FRAME_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|"%{!static:--eh-frame-hdr} "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

end_unit

