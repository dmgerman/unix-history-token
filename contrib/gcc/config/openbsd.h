begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all OpenBSD targets.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common OpenBSD configuration.     All OpenBSD architectures include this file, which is intended as    a repository for common defines.      Some defines are common to all architectures, a few of them are    triggered by OBSD_* guards, so that we won't override architecture    defaults by mistakes.     OBSD_HAS_CORRECT_SPECS:        another mechanism provides correct specs already.    OBSD_NO_DYNAMIC_LIBRARIES:        no implementation of dynamic libraries.    OBSD_OLD_GAS:        older flavor of gas which needs help for PIC.    OBSD_HAS_DECLARE_FUNCTION_NAME, OBSD_HAS_DECLARE_FUNCTION_SIZE,    OBSD_HAS_DECLARE_OBJECT:        PIC support, FUNCTION_NAME/FUNCTION_SIZE are independent, whereas       the corresponding logic for OBJECTS is necessarily coupled.     There are also a few `default' defines such as ASM_WEAKEN_LABEL,    intended as common ground for arch that don't provide     anything suitable.  */
end_comment

begin_comment
comment|/* OPENBSD_NATIVE is defined only when gcc is configured as part of    the OpenBSD source tree, specifically through Makefile.bsd-wrapper.     In such a case the include path can be trimmed as there is no    distinction between system includes and gcc includes.  */
end_comment

begin_comment
comment|/* This configuration method, namely Makefile.bsd-wrapper and    OPENBSD_NATIVE is NOT recommended for building cross-compilers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENBSD_NATIVE
end_ifdef

begin_undef
undef|#
directive|undef
name|GCC_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_comment
comment|/* The compiler is configured with ONLY the gcc/g++ standard headers.  */
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
value|{						\     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },	\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },		\     { 0, 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under OpenBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Controlling the compilation driver.  */
end_comment

begin_comment
comment|/* CPP_SPEC appropriate for OpenBSD. We deal with -posix and -pthread.    XXX the way threads are handling currently is not very satisfying,    since all code must be compiled with -pthread to work.     This two-stage defines makes it easy to pick that for targets that    have subspecs.  */
end_comment

begin_define
define|#
directive|define
name|OBSD_CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_POSIX_THREADS}"
end_define

begin_comment
comment|/* LIB_SPEC appropriate for OpenBSD.  Select the appropriate libc,     depending on profiling and threads.  Basically,     -lc(_r)?(_p)?, select _r for threads, and _p for p or pg.  */
end_comment

begin_define
define|#
directive|define
name|OBSD_LIB_SPEC
value|"-lc%{pthread:_r}%{p:_p}%{!p:%{pg:_p}}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OBSD_HAS_CORRECT_SPECS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OBSD_NO_DYNAMIC_LIBRARIES
end_ifndef

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
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR) \    || (CHAR) == 'R')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|OBSD_CPP_SPEC
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBSD_OLD_GAS
end_ifdef

begin_comment
comment|/* ASM_SPEC appropriate for OpenBSD.  For some architectures, OpenBSD     still uses a special flavor of gas that needs to be told when generating     pic code.  */
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
value|"%{fpic:-k} %{fPIC:-k -K} %|"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Since we use gas, stdin -> - is a good idea, but we don't want to    override native specs just for that.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%|"
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
comment|/* LINK_SPEC appropriate for OpenBSD.  Support for GCC options     -static, -assert, and -nostdlib.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|OBSD_NO_DYNAMIC_LIBRARIES
end_ifdef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{assert*}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{R*} %{static:-Bstatic} %{assert*}"
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

begin_define
define|#
directive|define
name|LIB_SPEC
value|OBSD_LIB_SPEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Runtime target specification.  */
end_comment

begin_comment
comment|/* You must redefine CPP_PREDEFINES in any arch specific file.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_comment
comment|/* Implicit calls to library routines.  */
end_comment

begin_comment
comment|/* Use memcpy and memset instead of bcopy and bzero.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Miscellaneous parameters.  */
end_comment

begin_comment
comment|/* Tell libgcc2.c that OpenBSD targets support atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Controlling debugging info: dbx options.  */
end_comment

begin_comment
comment|/* Don't use the `xsTAG;' construct in DBX output; OpenBSD systems that    use DBX don't support it.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
end_define

begin_escape
end_escape

begin_comment
comment|/* Support of shared libraries, mostly imported from svr4.h through netbsd.  */
end_comment

begin_comment
comment|/* Two differences from svr4.h:    - we use . - _func instead of a local label,    - we put extra spaces in expressions such as       .type _func , @function      This is more readable for a human being and confuses c++filt less.  */
end_comment

begin_comment
comment|/* Assembler format: output and generation of labels.  */
end_comment

begin_comment
comment|/* Define the strings used for the .type and .size directives.    These strings generally do not vary from one system running OpenBSD    to another, but if a given system needs to use different pseudo-op    names for these, they may be overridden in the arch specific file.  */
end_comment

begin_comment
comment|/* OpenBSD assembler is hacked to have .type& .size support even in a.out    format object files.  Functions size are supported but not activated     yet (look for GRACE_PERIOD_EXPIRED in gas/config/obj-aout.c).      SET_ASM_OP is needed for attribute alias to work.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|".type"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|".size"
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"@%s"
end_define

begin_comment
comment|/* Provision if extra assembler code is needed to declare a function's result    (taken from svr4, not needed yet actually).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries under OpenBSD.  These macros also have to output the starting     labels for the relevant functions/objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBSD_HAS_DECLARE_FUNCTION_NAME
end_ifndef

begin_comment
comment|/* Extra assembler code needed to declare a function properly.    Some assemblers may also need to also have something extra said     about the function's return value.  We allow for that here.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

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
value|do {									\     fprintf (FILE, "\t%s\t", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     fputs (" , ", FILE);						\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OBSD_HAS_DECLARE_FUNCTION_SIZE
end_ifndef

begin_comment
comment|/* Declare the size of a function.  */
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
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\ 	fprintf (FILE, "\t%s\t", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\ 	fputs (" , . - ", FILE);					\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OBSD_HAS_DECLARE_OBJECT
end_ifndef

begin_comment
comment|/* Extra assembler code needed to declare an object properly.  */
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
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     fputs (" , ", FILE);						\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "\t%s\t", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, " , %d\n", int_size_in_bytes (TREE_TYPE (DECL)));\       }									\     ASM_OUTPUT_LABEL (FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set by ASM_DECLARE_OBJECT_NAME     when it was run for the same decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TOP_LEVEL
parameter_list|,
name|AT_END
parameter_list|)
define|\
value|do {									 \      char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);			 \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		 \&& ! AT_END&& TOP_LEVEL					 \&& DECL_INITIAL (DECL) == error_mark_node			 \&& !size_directive_output)					 \        {								 \ 	 size_directive_output = 1;					 \ 	 fprintf (FILE, "\t%s\t", SIZE_ASM_OP);			 \ 	 assemble_name (FILE, name);					 \ 	 fprintf (FILE, " , %d\n", int_size_in_bytes (TREE_TYPE (DECL)));\        }								 \    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Those are `generic' ways to weaken/globalize a label. We shouldn't need    to override a processor specific definition. Hence, #ifndef ASM_*    In case overriding turns out to be needed, one can always #undef ASM_*     before including this file.  */
end_comment

begin_comment
comment|/* Tell the assembler that a symbol is weak.  */
end_comment

begin_comment
comment|/* Note: netbsd arm32 assembler needs a .globl here. An override may     be needed when/if we go for arm32 support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_WEAKEN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tell the assembler that a symbol is global.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_GLOBALIZE_LABEL
end_ifndef

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
value|do { fputs ("\t.globl\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Storage layout.  */
end_comment

begin_comment
comment|/* We don't have to worry about binary compatibility with older C++ code,    but there is a big known bug with vtable thunks which has not been    fixed yet, so DON'T activate it by default.  */
end_comment

begin_comment
comment|/* #define DEFAULT_VTABLE_THUNKS 1 */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Otherwise, since we support weak, gthr.h erroneously tries to use    #pragma weak.  */
end_comment

begin_define
define|#
directive|define
name|GTHREAD_USE_WEAK
value|0
end_define

begin_comment
comment|/* bug work around: we don't want to support #pragma weak, but the current    code layout needs HANDLE_PRAGMA_WEAK asserted for __attribute((weak)) to    work.  On the other hand, we don't define HANDLE_PRAGMA_WEAK directly,    as this depends on a few other details as well...  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

end_unit

