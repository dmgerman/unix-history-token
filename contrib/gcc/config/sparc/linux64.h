begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for 64-bit SPARC running Linux-based GNU systems with ELF.    Copyright 1996, 1997, 1998, 2000 Free Software Foundation, Inc.    Contributed by David S. Miller (davem@caip.rutgers.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_comment
comment|/* A 64 bit v9 compiler with stack-bias,    in a Medium/Low code model environment.  */
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
define|\
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT
comment|/* + MASK_HARD_QUAD */
value|\    + MASK_STACK_BIAS + MASK_APP_REGS + MASK_EPILOGUE + MASK_FPU + MASK_LONG_DOUBLE_128)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-Av9a"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH32_SPEC
value|"%{mlong-double-128:-D__LONG_DOUBLE_128__} \ -D__SIZE_TYPE__=unsigned\\ int -D__PTRDIFF_TYPE__=int \ -D__GCC_NEW_VARARGS__ -Acpu=sparc -Amachine=sparc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add    the GNU/Linux magical crtbegin.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main'.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC32
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}\    crti.o%s %{static:crtbeginT.o%s}\    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC64
define|\
value|"%{!shared: \      %{pg:/usr/lib64/gcrt1.o%s} %{!pg:%{p:/usr/lib64/gcrt1.o%s} %{!p:/usr/lib64/crt1.o%s}}}\    /usr/lib64/crti.o%s %{static:crtbeginT.o%s}\    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\ %{m32:" STARTFILE_SPEC32 "} \ %{m64:" STARTFILE_SPEC64 "} \ %{!m32:%{!m64:" STARTFILE_SPEC32 "}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\ %{m32:" STARTFILE_SPEC32 "} \ %{m64:" STARTFILE_SPEC64 "} \ %{!m32:%{!m64:" STARTFILE_SPEC64 "}}"
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
name|STARTFILE_SPEC
value|STARTFILE_SPEC64
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
name|ENDFILE_SPEC32
define|\
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC64
define|\
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} /usr/lib64/crtn.o%s"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"\ %{m32:" ENDFILE_SPEC32 "} \ %{m64:" ENDFILE_SPEC64 "} \ %{!m32:%{!m64:" ENDFILE_SPEC32 "}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"\ %{m32:" ENDFILE_SPEC32 "} \ %{m64:" ENDFILE_SPEC64 "} \ %{!m32:%{!m64:" ENDFILE_SPEC64 "}}"
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
name|ENDFILE_SPEC
value|ENDFILE_SPEC64
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|fprintf (stderr, " (sparc64 GNU/Linux with ELF)");
end_define

begin_comment
comment|/* The default code model.  */
end_comment

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_MEDLOW
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
value|{"long-double-64", -MASK_LONG_DOUBLE_128, N_("Use 64 bit long doubles") },  \ {"long-double-128", MASK_LONG_DOUBLE_128, N_("Use 128 bit long doubles") },
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

begin_comment
comment|/* Define for support of TFmode long double and REAL_ARITHMETIC.    Sparc ABI says that long double is 4 words.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_LONG_DOUBLE_128 ? 128 : 64)
end_define

begin_comment
comment|/* Constant which presents upper bound of the above value.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* Define this to set long double type size to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__LONG_DOUBLE_128__
argument_list|)
end_if

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

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ELF__ -Dunix -D_LONGLONG -D__sparc__ -Dlinux -Asystem=unix -Asystem=posix"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"\ %{fPIC:-D__PIC__ -D__pic__} \ %{fpic:-D__PIC__ -D__pic__} \ %{posix:-D_POSIX_SOURCE} \ %{pthread:-D_REENTRANT} \ "
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared: -lc} \    %{!shared: %{mieee-fp:-lieee} %{pthread:-lpthread} \      %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for GNU/Linux.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     I took out %{v:%{!V:-V}}. It is too much :-(. They can use    -Wl,-V.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_comment
comment|/* If ELF is the default format, we should not use /lib/elf.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

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
value|{ "link_arch32",       LINK_ARCH32_SPEC },              \   { "link_arch64",       LINK_ARCH64_SPEC },              \   { "link_arch_default", LINK_ARCH_DEFAULT_SPEC },	  \   { "link_arch",	 LINK_ARCH_SPEC },
end_define

begin_define
define|#
directive|define
name|LINK_ARCH32_SPEC
value|"-m elf32_sparc -Y P,/usr/lib %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.2}} \         %{static:-static}}} \ "
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
value|"-m elf64_sparc -Y P,/usr/lib64 %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib64/ld-linux.so.2}} \         %{static:-static}}} \ "
end_define

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%(link_arch32)} \ %{m64:%(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_define
define|#
directive|define
name|LINK_ARCH_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? LINK_ARCH32_SPEC : LINK_ARCH64_SPEC)
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %(link_arch) \ %{mlittle-endian:-EL} \ %{!mno-relax:%{!r:-relax}} \ "
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m64:-mptr64 -mstack-bias -mlong-double-128 \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:-mcpu=ultrasparc}}}}}}} \   %{!mno-vis:%{!mcpu=v9:-mvis}}} \ "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m32:-mptr32 -mno-stack-bias %{!mlong-double-128:-mlong-double-64} \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:-mcpu=cypress}}}}}}}} \ %{!m32:%{!mcpu*:-mcpu=ultrasparc}} \ %{!mno-vis:%{!m32:%{!mcpu=v9:-mvis}}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m32" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SPARC_BI_ARCH */
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
value|"-m elf64_sparc -Y P,/usr/lib64 %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib64/ld-linux.so.2}} \         %{static:-static}}} \ %{mlittle-endian:-EL} \ %{!mno-relax:%{!r:-relax}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SPARC_BI_ARCH */
end_comment

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
value|"\ %{V} \ %{v:%{!V:-V}} \ %{!Qn:-Qy} \ %{n} \ %{T} \ %{Ym,*} \ %{Wa,*:%*} \ -s %{fpic:-K PIC} %{fPIC:-K PIC} \ %{mlittle-endian:-EL} \ %(asm_cpu) %(asm_arch) %(asm_relax)"
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

begin_comment
comment|/* System V Release 4 uses DWARF debugging info.  Buf DWARF1 doesn't do    64-bit anything, so we use DWARF2.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
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

begin_comment
comment|/* DWARF bits.  */
end_comment

begin_comment
comment|/* Follow Irix 6 and not the Dwarf2 draft in using 64-bit offsets.     Obviously the Dwarf2 folks haven't tried to actually build systems    with their spec.  On a 64-bit system, only 64-bit relocs become    RELATIVE relocations.  */
end_comment

begin_comment
comment|/* #define DWARF_OFFSET_SIZE PTR_SIZE */
end_comment

begin_if
if|#
directive|if
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

