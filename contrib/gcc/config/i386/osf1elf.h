begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OSF/1 1.3 now is compitable with SVR4, so include sysv4.h, and    put difference here.    Copyright (C) 2000 Free Software Foundation, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 OSF/1)");
end_define

begin_define
define|#
directive|define
name|TARGET_OSF1ELF
end_define

begin_comment
comment|/* WORD_SWITCH_TAKES_ARG defined in svr4 is not correct. We also  need an extra -soname */
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
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)                 \   || !strcmp (STR, "Tdata") || !strcmp (STR, "Ttext") \   || !strcmp (STR, "Tbss") || !strcmp (STR, "soname"))
end_define

begin_comment
comment|/* Note, -fpic and -fPIC are equivalent */
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
value|"\ %(cpp_cpu) \ %{fpic: -D__SHARED__} %{fPIC: %{!fpic: -D__SHARED__}} \ %{.S:	%{!ansi:%{!traditional:%{!traditional-cpp:%{!ftraditional: -traditional}}}}} \ %{.S:	-D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_comment
comment|/* -mmcount or -mno-mcount should be used with -pg or -p */
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
value|"%(cc1_cpu) %{p: %{!mmcount: %{!mno-mcount: -mno-mcount }}} \ %{!p: %{pg: %{!mmcount: %{!mno-mcount: -mno-mcount }}}}"
end_define

begin_comment
comment|/* Note, -D__NO_UNDERSCORES__ -D__ELF__ are provided in the older version of    OSF/1 gcc. We keep them here, so that old /usr/include/i386/asm.h works.    */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__NO_UNDERSCORES__ -D__ELF__ -DOSF -DOSF1 -Dunix \    -Asystem=unix -Asystem=xpg4 -Asystem=osf1"
end_define

begin_comment
comment|/* current OSF/1 doesn't provide separate crti.o and gcrti.o (and also, crtn.o    and gcrtn.o) for profile.  */
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
value|"%{!shared: \                          %{!symbolic: \                           %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}\ 			crti.o%s \ 			crtbegin.o%s"
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
value|"crtend.o%s crtn.o%s"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v*: -v}"
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
value|"%{v*: -v} \ 		%{h*} %{z*} \ 		%{dy:-call_shared} %{dn:-static} \ 		%{static:-static} \ 		%{shared:-shared} \ 		%{call_shared:-call_shared} \ 		%{symbolic:-Bsymbolic -shared -call_shared} \ 		%{!dy: %{!dn: %{!static: %{!shared: %{!symbolic: \ 			%{noshrlib: -static } \ 			%{!noshrlib: -call_shared}}}}}}"
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/gcc/"
end_define

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_comment
comment|/* Define this macro meaning that gcc should find the library 'libgcc.a'    by hand, rather than passing the argument '-lgcc' to tell the linker    to do the search */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_comment
comment|/* This goes with LINK_LIBGCC_SPECIAL, we need tell libgcc.a differently */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{!shared:%{!symbolic:libgcc.a%s}}"
end_define

begin_comment
comment|/* Specify size_t, ptrdiff_t, and wchar_t types.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

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
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Turn off long double being 96 bits.  */
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
value|64
end_define

begin_comment
comment|/* Work with OSF/1 profile */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_MCOUNT
value|000200000000
end_define

begin_comment
comment|/* profiling uses mcount_ptr */
end_comment

begin_define
define|#
directive|define
name|TARGET_MCOUNT
value|((target_flags& MASK_NO_MCOUNT) == 0)
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
value|{ "mcount",		-MASK_NO_MCOUNT,			\        N_("Profiling uses mcount") },					\      { "no-mcount",		 MASK_NO_MCOUNT, "" },
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.     We override it here to allow for the new profiling code to go before    the prologue and the old mcount code to go after the prologue (and    after %ebx has been set up for ELF shared library support).  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|OSF_PROFILE_BEFORE_PROLOGUE
define|\
value|(!TARGET_MCOUNT							\&& !current_function_needs_context					\&& (!flag_pic							\        || !frame_pointer_needed						\        || (!current_function_uses_pic_offset_table			\&& !current_function_uses_const_pool)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSF_PROFILE_BEFORE_PROLOGUE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C statement or compound statement to output to FILE some assembler code to    call the profiling subroutine `mcount'.  Before calling, the assembler code    must load the address of a counter variable into a register where `mcount'    expects to find the address.  The name of this variable is `LP' followed by    the number LABELNO, so you would generate the name using `LP%d' in a    `fprintf'.     The details of how the address should be passed to `mcount' are determined    by your operating system environment, not by GNU CC.  To figure them out,    compile a small program for profiling using the system's installed C    compiler and look at the assembler code that results.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|do									\   {									\     if (!OSF_PROFILE_BEFORE_PROLOGUE)					\       {									\ 	const char *const prefix = "";					\ 	const char *const lprefix = LPREFIX;				\ 	int labelno = LABELNO;						\ 									\
comment|/* Note that OSF/rose blew it in terms of calling mcount,	\ 	   since OSF/rose prepends a leading underscore, but mcount's	\ 	   doesn't.  At present, we keep this kludge for ELF as well	\ 	   to allow old kernels to build profiling.  */
value|\ 									\ 	if (flag_pic							\&& !current_function_uses_pic_offset_table			\&& !current_function_uses_const_pool)			\ 	  abort ();							\ 									\ 	if (TARGET_MCOUNT&& flag_pic)					\ 	  {								\ 	    fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",	\ 		     lprefix, labelno);					\ 	    fprintf (FILE, "\tcall *%smcount@GOT(%%ebx)\n", prefix);	\ 	  }								\ 									\ 	else if (TARGET_MCOUNT)						\ 	  {								\ 	    fprintf (FILE, "\tmovl $%sP%d,%%edx\n", lprefix, labelno);	\ 	    fprintf (FILE, "\tcall %smcount\n", prefix);		\ 	  }								\ 									\ 	else if (flag_pic&& frame_pointer_needed)			\ 	  {								\ 	    fprintf (FILE, "\tmovl 4(%%ebp),%%ecx\n");			\ 	    fprintf (FILE, "\tpushl %%ecx\n");				\ 	    fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",	\ 		     lprefix, labelno);					\ 	    fprintf (FILE, "\tmovl _mcount_ptr@GOT(%%ebx),%%eax\n");	\ 	    fprintf (FILE, "\tcall *(%%eax)\n");			\ 	    fprintf (FILE, "\tpopl %%eax\n");				\ 	  }								\ 									\ 	else if (frame_pointer_needed)					\ 	  {								\ 	    fprintf (FILE, "\tmovl 4(%%ebp),%%ecx\n");			\ 	    fprintf (FILE, "\tpushl %%ecx\n");				\ 	    fprintf (FILE, "\tmovl $%sP%d,%%edx\n", lprefix, labelno);	\ 	    fprintf (FILE, "\tcall *_mcount_ptr\n");			\ 	    fprintf (FILE, "\tpopl %%eax\n");				\ 	  }								\ 									\ 	else								\ 	  abort ();							\       }									\   }									\ while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CROSS_COMPILE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HOST_BITS_PER_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|HOST_BITS_PER_LONG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HOST_BITS_PER_LONGLONG
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|HOST_BITS_PER_INT
operator|==
literal|32
operator|)
operator|&&
operator|(
name|HOST_BITS_PER_LONG
operator|==
literal|64
operator|)
operator|&&
operator|(
name|HOST_BITS_PER_LONGLONG
operator|==
literal|64
operator|)
end_if

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

