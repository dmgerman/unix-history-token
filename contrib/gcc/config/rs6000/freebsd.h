begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for PowerPC running FreeBSD using the ELF format    Copyright (C) 2001, 2003 Free Software Foundation, Inc.    Contributed by David E. O'Brien<obrien@FreeBSD.org> and BSDi.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Override the defaults, which exist to force the proper definition.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_64BIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On 64-bit systems, use the AIX ABI like Linux and NetBSD */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_ABI
end_undef

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|(TARGET_64BIT ? ABI_AIX : ABI_V4)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_AIX
end_undef

begin_define
define|#
directive|define
name|TARGET_AIX
value|TARGET_64BIT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_NO_DOT_SYMS
end_ifdef

begin_comment
comment|/* New ABI uses a local sym for the function entry point.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dot_symbols
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DOT_SYMBOLS
end_undef

begin_define
define|#
directive|define
name|DOT_SYMBOLS
value|dot_symbols
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|FBSD_TARGET_CPU_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|FBSD_TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("__PPC__");		\       builtin_define ("__ppc__");		\       builtin_define ("__PowerPC__");		\       builtin_define ("__powerpc__");		\       if (TARGET_64BIT)				\ 	{					\ 	  builtin_define ("__LP64__");		\ 	  builtin_define ("__ppc64__");		\ 	  builtin_define ("__powerpc64__");	\ 	  builtin_define ("__arch64__");	\ 	  builtin_assert ("cpu=powerpc64");	\ 	  builtin_assert ("machine=powerpc64");	\ 	} else {				\ 	  builtin_assert ("cpu=powerpc");	\ 	  builtin_assert ("machine=powerpc");	\ 	}					\     }						\   while (0)
end_define

begin_define
define|#
directive|define
name|INVALID_64BIT
value|"-m%s not supported in this configuration"
end_define

begin_define
define|#
directive|define
name|INVALID_32BIT
value|INVALID_64BIT
end_define

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_OVERRIDE_OPTIONS
define|\
value|do								\     {								\       if (!rs6000_explicit_options.alignment)			\ 	rs6000_alignment_flags = MASK_ALIGN_NATURAL;		\       if (TARGET_64BIT)						\ 	{							\ 	  if (DEFAULT_ABI != ABI_AIX)				\ 	    {							\ 	      rs6000_current_abi = ABI_AIX;			\ 	      error (INVALID_64BIT, "call");			\ 	    }							\ 	  dot_symbols = !strcmp (rs6000_abi_name, "aixdesc");	\ 	  if (target_flags& MASK_RELOCATABLE)			\ 	    {							\ 	      target_flags&= ~MASK_RELOCATABLE;		\ 	      error (INVALID_64BIT, "relocatable");		\ 	    }							\ 	  if (target_flags& MASK_EABI)				\ 	    {							\ 	      target_flags&= ~MASK_EABI;			\ 	      error (INVALID_64BIT, "eabi");			\ 	    }							\ 	  if (target_flags& MASK_PROTOTYPE)			\ 	    {							\ 	      target_flags&= ~MASK_PROTOTYPE;			\ 	      error (INVALID_64BIT, "prototype");		\ 	    }							\ 	  if ((target_flags& MASK_POWERPC64) == 0)		\ 	    {							\ 	      target_flags |= MASK_POWERPC64;			\ 	      error ("64 bit CPU required");			\ 	    }							\ 	}							\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_freebsd)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_freebsd)"
end_define

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_freebsd)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_freebsd)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_freebsd)"
end_define

begin_comment
comment|/* XXX: This is wrong for many platforms in sysv4.h.    We should work on getting that definition fixed.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"%{shared:-shared} %{!shared: %{static:-static}}"
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.      Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|(TARGET_64BIT ? "long unsigned int" : "unsigned int")
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
value|(TARGET_64BIT ? "long int" : "int")
end_define

begin_comment
comment|/* rs6000.h gets this wrong for FreeBSD.  We use the GCC defaults instead.  */
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
name|WCHAR_TYPE_SIZE
value|32
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
value|fprintf (stderr, " (FreeBSD/PowerPC ELF)");
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* Tell the assembler we want 32/64-bit binaries if -m32 or -m64 is passed */
end_comment

begin_if
if|#
directive|if
operator|(
name|TARGET_DEFAULT
operator|&
name|MASK_64BIT
operator|)
end_if

begin_define
define|#
directive|define
name|SVR4_ASM_SPEC
value|"%(asm_cpu) \ %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \ %{mrelocatable} %{mrelocatable-lib} %{fpic|fpie|fPIC|fPIE:-K PIC} \ %{memb|msdata|msdata=eabi: -memb} \ %{mlittle|mlittle-endian:-mlittle; \   mbig|mbig-endian      :-mbig;    \   mcall-aixdesc |		   \   mcall-freebsd |		   \   mcall-netbsd  |		   \   mcall-openbsd |		   \   mcall-linux   |		   \   mcall-gnu             :-mbig;    \   mcall-i960-old        :-mlittle}"
end_define

begin_define
define|#
directive|define
name|LINK_OS_FREEBSD_SPEC_DEF
value|"\   %{p:%nconsider using `-pg' instead of `-p' with gprof(1)} \   %{v:-V} \   %{assert*} %{R*} %{rpath*} %{defsym*} \   %{shared:-Bshareable %{h*} %{soname*}} \   %{!static:--enable-new-dtags}	\   %{!shared: \     %{!static: \       %{rdynamic: -export-dynamic} \       %{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }} \     %{static:-Bstatic}} \   %{symbolic:-Bsymbolic}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LINK_OS_FREEBSD_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc%{!m32:64}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m32:-a32}%{!m32:-a64} " SVR4_ASM_SPEC
end_define

begin_define
define|#
directive|define
name|LINK_OS_FREEBSD_SPEC
value|"%{m32:-melf32ppc_fbsd}%{!m32:-melf64ppc_fbsd} " LINK_OS_FREEBSD_SPEC_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _init and _fini functions are built from bits spread across many    object files, each potentially with a different TOC pointer.  For    that reason, place a nop after the call so that the linker can    restore the TOC pointer if a TOC adjusting call stub is needed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n"					\ "	bl " #FUNC "\n"					\ "	nop\n"						\ "	.previous");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __throw will restore its own return address to be the same as the    return address of the function that the throw is being made to.    This is unfortunate, because we want to check the original    return address to see if we need to restore the TOC.    So we have to squirrel it away with this.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_FRAME_ADDRESSES
parameter_list|()
define|\
value|do { if (TARGET_64BIT) rs6000_aix_emit_builtin_unwind_init (); } while (0)
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.  */
end_comment

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
value|((TARGET_64BIT || flag_pic || TARGET_RELOCATABLE)			\    ? (((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel		\       | (TARGET_64BIT ? DW_EH_PE_udata8 : DW_EH_PE_sdata4))		\    : DW_EH_PE_absptr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|MD_FROB_UPDATE_CONTEXT
parameter_list|(
name|CTX
parameter_list|,
name|FS
parameter_list|)
define|\
value|if ((FS)->regs.reg[2].how == REG_UNSAVED)				\       {									\ 	unsigned int *insn = (unsigned int *)				\ 	    _Unwind_GetGR ((CTX), LINK_REGISTER_REGNUM);		\ 	if (insn != NULL&& *insn == 0xE8410028)			\ 	  _Unwind_SetGRPtr ((CTX), 2, (CTX)->cfa + 40);			\       }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|rs6000_elf_end_indicate_exec_stack
end_define

begin_comment
comment|/* FreeBSD doesn't support saving and restoring 64-bit regs with a 32-bit    kernel. This is supported when running on a 64-bit kernel with    COMPAT_FREEBSD32, but tell GCC it isn't so that our 32-bit binaries    are compatible. */
end_comment

begin_define
define|#
directive|define
name|OS_MISSING_POWERPC64
value|!TARGET_64BIT
end_define

begin_comment
comment|/* Function profiling bits */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_MCOUNT
end_undef

begin_define
define|#
directive|define
name|RS6000_MCOUNT
value|((TARGET_64BIT) ? "._mcount" : "_mcount")
end_define

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|LABEL
parameter_list|)
define|\
value|do { if (TARGET_64BIT) output_profile_hook (LABEL); } while (0)
end_define

begin_undef
undef|#
directive|undef
name|NEED_INDICATE_EXEC_STACK
end_undef

begin_define
define|#
directive|define
name|NEED_INDICATE_EXEC_STACK
value|1
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|FNAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do                                                                    \     {                                                                   \       if (!flag_inhibit_size_directive)                                 \         {                                                               \           fputs ("\t.size\t", (FILE));                                  \           if (TARGET_64BIT&& DOT_SYMBOLS)                              \             putc ('.', (FILE));                                         \           assemble_name ((FILE), (FNAME));                              \           fputs (",.-", (FILE));                                        \           rs6000_output_function_entry (FILE, FNAME);                   \           putc ('\n', (FILE));                                          \         }                                                               \     }                                                                   \   while (0)
end_define

end_unit

