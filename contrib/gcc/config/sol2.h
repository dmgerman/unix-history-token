begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for any    Solaris 2 system.    Copyright 2002 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* We use stabs-in-elf for debugging, because that is what the native    toolchain uses.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* Solaris 2 (at least as of 2.5.1) uses a 32-bit wchar_t.  */
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
value|"long int"
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
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Solaris 2 uses a wint_t different from the default. This is required    by the SCD 2.4.1, p. 6-83, Figure 6-66.  */
end_comment

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WINT_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_REDEFINE_EXTNAME
value|1
end_define

begin_comment
comment|/* ??? Note: in order for -compat-bsd to work fully,    we must somehow arrange to fixincludes /usr/ucbinclude    and put the result in $(libsubdir)/ucbinclude.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"\ %{pthreads:-D_REENTRANT -D_PTHREADS} \ %{!pthreads:%{threads:-D_REENTRANT -D_SOLARIS_THREADS}} \ %{compat-bsd:-iwithprefixbefore ucbinclude -I/usr/ucbinclude} \ "
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {						\ 	builtin_define_std ("unix");			\ 	builtin_define_std ("sun");			\ 	builtin_define ("__svr4__");			\ 	builtin_define ("__SVR4");			\ 	builtin_define ("__PRAGMA_REDEFINE_EXTNAME");	\ 	builtin_assert ("system=unix");			\ 	builtin_assert ("system=svr4");			\
comment|/* For C++ we need to add some additional macro \ 	   definitions required by the C++ standard	\ 	   library.  */
value|\ 	if (c_language == clk_cplusplus)		\ 	  {						\ 	    builtin_define ("_XOPEN_SOURCE=500");	\ 	    builtin_define ("_LARGEFILE_SOURCE=1");	\ 	    builtin_define ("_LARGEFILE64_SOURCE=1");	\ 	    builtin_define ("__EXTENSIONS__");		\ 	  }						\     } while (0)
end_define

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
value|"\ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s \ %{fpic:-K PIC} %{fPIC:-K PIC} \ %(asm_cpu) \ "
end_define

begin_comment
comment|/* We don't use the standard LIB_SPEC only because we don't yet support c++.  */
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
define|\
value|"%{compat-bsd:-lucb -lsocket -lnsl -lelf -laio} \    %{!shared:\      %{!symbolic:\        %{pthreads:-lpthread} \        %{!pthreads:%{threads:-lthread}} \        %{p|pg:-ldl} -lc}}"
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

begin_comment
comment|/* We don't use the standard svr4 STARTFILE_SPEC because it's wrong for us.  */
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
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{p:mcrt1.o%s} \                           %{!p: \ 	                    %{pg:gcrt1.o%s gmon.o%s} \                             %{!pg:crt1.o%s}}}} \ 			crti.o%s %(startfile_arch) \ 			crtbegin.o%s"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_ARCH32_SPEC
value|"%{ansi:values-Xc.o%s} \ 			    %{!ansi:values-Xa.o%s}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_ARCH_SPEC
value|STARTFILE_ARCH32_SPEC
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH32_SPEC
define|\
value|"%{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \              %{!p:%{!pg:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}}} \              -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \              %{!p:%{!pg:-Y P,/usr/ccs/lib:/usr/lib}}}}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|LINK_ARCH32_SPEC
end_define

begin_comment
comment|/* This should be the same as in svr4.h, except with -R added.  */
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
define|\
value|"%{h*} %{v:-V} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy %{!mimpure-text:-z text}} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %(link_arch) \    %{Qy:} %{!Qn:-Qy}"
end_define

begin_comment
comment|/* This defines which switch letters take arguments.    It is as in svr4.h but with -R added.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR) \    || (CHAR) == 'R' \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

begin_define
define|#
directive|define
name|STDC_0_IN_SYSTEM_HEADERS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Attempt to turn on access permissions for the stack.  *  * This code must be defined when compiling gcc but not when compiling  * libgcc2.a, unless we're generating code for 64-bit SPARC  *  * _SC_STACK_PROT is only defined for post 2.6, but we want this code  * to run always.  2.6 can change the stack protection but has no way to  * query it.  *  */
end_comment

begin_comment
comment|/* This declares mprotect (used in TRANSFER_FROM_TRAMPOLINE) for    libgcc2.c.  */
end_comment

begin_comment
comment|/* We don't want to include this because sys/mman.h is not present on    some non-Solaris configurations that use sol2.h.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* def L_trampoline */
end_comment

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\ 									\
comment|/* #define STACK_PROT_RWX (PROT_READ | PROT_WRITE | PROT_EXEC) */
define|\ 									\
value|static int need_enable_exec_stack;					\ 									\ static void check_enabling(void) __attribute__ ((constructor));		\ static void check_enabling(void)					\ {									\   extern long sysconf(int);						\ 									\   int prot = (int) sysconf(515
comment|/* _SC_STACK_PROT */
value|);			\   if (prot != 7
comment|/* STACK_PROT_RWX */
value|)					\     need_enable_exec_stack = 1;						\ }									\ 									\ extern void __enable_execute_stack (void *);				\ void									\ __enable_execute_stack (addr)						\      void *addr;							\ {									\   if (!need_enable_exec_stack)						\     return;								\   else {								\     long size = getpagesize ();						\     long mask = ~(size-1);						\     char *page = (char *) (((long) addr)& mask); 			\     char *end  = (char *) ((((long) (addr + TRAMPOLINE_SIZE))& mask) + size); \ 									\     if (mprotect (page, end - page, 7
comment|/* STACK_PROT_RWX */
value|)< 0)	\       perror ("mprotect of trampoline code");				\   }									\ }
end_define

end_unit

