begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ANSI and traditional C compatability macros    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    This file is part of the GNU C Library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* ANSI and traditional C compatibility macros     ANSI C is assumed if __STDC__ is #defined.     Macro		ANSI C definition	Traditional C definition    -----		---- - ----------	----------- - ----------    ANSI_PROTOTYPES	1			not defined    PTR			`void *'		`char *'    PTRCONST		`void *const'		`char *'    LONG_DOUBLE		`long double'		`double'    const		not defined		`'    volatile		not defined		`'    signed		not defined		`'    VA_START(ap, var)	va_start(ap, var)	va_start(ap)     Note that it is safe to write "void foo();" indicating a function    with no return value, in all K+R compilers we have been able to test.     For declaring functions with prototypes, we also provide these:     PARAMS ((prototype))    -- for functions which take a fixed number of arguments.  Use this    when declaring the function.  When defining the function, write a    K+R style argument list.  For example:  	char *strcpy PARAMS ((char *dest, char *source)); 	... 	char * 	strcpy (dest, source) 	     char *dest; 	     char *source; 	{ ... }      VPARAMS ((prototype, ...))    -- for functions which take a variable number of arguments.  Use    PARAMS to declare the function, VPARAMS to define it.  For example:  	int printf PARAMS ((const char *format, ...)); 	... 	int 	printf VPARAMS ((const char *format, ...)) 	{ 	   ... 	}     For writing functions which take variable numbers of arguments, we    also provide the VA_OPEN, VA_CLOSE, and VA_FIXEDARG macros.  These    hide the differences between K+R<varargs.h> and C89<stdarg.h> more    thoroughly than the simple VA_START() macro mentioned above.     VA_OPEN and VA_CLOSE are used *instead of* va_start and va_end.    Immediately after VA_OPEN, put a sequence of VA_FIXEDARG calls    corresponding to the list of fixed arguments.  Then use va_arg    normally to get the variable arguments, or pass your va_list object    around.  You do not declare the va_list yourself; VA_OPEN does it    for you.     Here is a complete example:  	int 	printf VPARAMS ((const char *format, ...)) 	{ 	   int result;  	   VA_OPEN (ap, format); 	   VA_FIXEDARG (ap, const char *, format);  	   result = vfprintf (stdout, format, ap); 	   VA_CLOSE (ap);  	   return result; 	}      You can declare variables either before or after the VA_OPEN,    VA_FIXEDARG sequence.  Also, VA_OPEN and VA_CLOSE are the beginning    and end of a block.  They must appear at the same nesting level,    and any variables declared after VA_OPEN go out of scope at    VA_CLOSE.  Unfortunately, with a K+R compiler, that includes the    argument list.  You can have multiple instances of VA_OPEN/VA_CLOSE    pairs in a single function in case you need to traverse the    argument list more than once.     For ease of writing code which uses GCC extensions but needs to be    portable to other compilers, we provide the GCC_VERSION macro that    simplifies testing __GNUC__ and __GNUC_MINOR__ together, and various    wrappers around __attribute__.  Also, __extension__ will be #defined    to nothing if it doesn't work.  See below.     This header also defines a lot of obsolete macros:    CONST, VOLATILE, SIGNED, PROTO, EXFUN, DEFUN, DEFUN_VOID,    AND, DOTS, NOARGS.  Don't use them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSIDECL_H
end_ifndef

begin_define
define|#
directive|define
name|_ANSIDECL_H
value|1
end_define

begin_comment
comment|/* Every source file includes this file,    so they will all get the switch for lint.  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_comment
comment|/* Using MACRO(x,y) in cpp #if conditionals does not work with some    older preprocessors.  Thus we can't define something like this:  #define HAVE_GCC_VERSION(MAJOR, MINOR) \   (__GNUC__> (MAJOR) || (__GNUC__ == (MAJOR)&& __GNUC_MINOR__>= (MINOR)))  and then test "#if HAVE_GCC_VERSION(2,7)".  So instead we use the macro below and test it against specific values.  */
end_comment

begin_comment
comment|/* This macro simplifies testing whether we are using gcc, and if it    is of a particular minimum version. (Both major& minor numbers are    significant.)  This macro will evaluate to 0 if we are not using    gcc at all.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_VERSION
end_ifndef

begin_define
define|#
directive|define
name|GCC_VERSION
value|(__GNUC__ * 1000 + __GNUC_MINOR__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_VERSION */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SYSTYPE_SVR4
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_comment
comment|/* All known AIX compilers implement these things (but don't always    define __STDC__).  The RISC/OS MIPS compiler defines these things    in SVR4 mode, but does not define __STDC__.  */
end_comment

begin_define
define|#
directive|define
name|ANSI_PROTOTYPES
value|1
end_define

begin_define
define|#
directive|define
name|PTR
value|void *
end_define

begin_define
define|#
directive|define
name|PTRCONST
value|void *const
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE
value|long double
end_define

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VPARAMS
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|VA_LIST
parameter_list|,
name|VAR
parameter_list|)
value|va_start(VA_LIST, VAR)
end_define

begin_comment
comment|/* variadic function helper macros */
end_comment

begin_comment
comment|/* "struct Qdmy" swallows the semicolon after VA_OPEN/VA_FIXEDARG's    use without inhibiting further decls and without declaring an    actual variable.  */
end_comment

begin_define
define|#
directive|define
name|VA_OPEN
parameter_list|(
name|AP
parameter_list|,
name|VAR
parameter_list|)
value|{ va_list AP; va_start(AP, VAR); { struct Qdmy
end_define

begin_define
define|#
directive|define
name|VA_CLOSE
parameter_list|(
name|AP
parameter_list|)
value|} va_end(AP); }
end_define

begin_define
define|#
directive|define
name|VA_FIXEDARG
parameter_list|(
name|AP
parameter_list|,
name|T
parameter_list|,
name|N
parameter_list|)
value|struct Qdmy
end_define

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_undef
undef|#
directive|undef
name|volatile
end_undef

begin_undef
undef|#
directive|undef
name|signed
end_undef

begin_comment
comment|/* inline requires special treatment; it's in C99, and GCC>=2.7 supports    it too, but it's not in C89.  */
end_comment

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

begin_comment
comment|/* it's a keyword */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|2007
end_if

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_comment
comment|/* __inline__ prevents -pedantic warnings */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are obsolete.  Do not use.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_GCC
end_ifndef

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_define
define|#
directive|define
name|SIGNED
value|signed
end_define

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|arglist
parameter_list|)
value|type name arglist
end_define

begin_define
define|#
directive|define
name|EXFUN
parameter_list|(
name|name
parameter_list|,
name|proto
parameter_list|)
value|name proto
end_define

begin_define
define|#
directive|define
name|DEFUN
parameter_list|(
name|name
parameter_list|,
name|arglist
parameter_list|,
name|args
parameter_list|)
value|name(args)
end_define

begin_define
define|#
directive|define
name|DEFUN_VOID
parameter_list|(
name|name
parameter_list|)
value|name(void)
end_define

begin_define
define|#
directive|define
name|AND
value|,
end_define

begin_define
define|#
directive|define
name|DOTS
value|, ...
end_define

begin_define
define|#
directive|define
name|NOARGS
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IN_GCC */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI C.  */
end_comment

begin_undef
undef|#
directive|undef
name|ANSI_PROTOTYPES
end_undef

begin_define
define|#
directive|define
name|PTR
value|char *
end_define

begin_define
define|#
directive|define
name|PTRCONST
value|PTR
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE
value|double
end_define

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|VPARAMS
parameter_list|(
name|args
parameter_list|)
value|(va_alist) va_dcl
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list)
end_define

begin_define
define|#
directive|define
name|VA_OPEN
parameter_list|(
name|AP
parameter_list|,
name|VAR
parameter_list|)
value|{ va_list AP; va_start(AP); { struct Qdmy
end_define

begin_define
define|#
directive|define
name|VA_CLOSE
parameter_list|(
name|AP
parameter_list|)
value|} va_end(AP); }
end_define

begin_define
define|#
directive|define
name|VA_FIXEDARG
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|,
name|NAME
parameter_list|)
value|TYPE NAME = va_arg(AP, TYPE)
end_define

begin_comment
comment|/* some systems define these in header files for non-ansi mode */
end_comment

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_undef
undef|#
directive|undef
name|volatile
end_undef

begin_undef
undef|#
directive|undef
name|signed
end_undef

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_define
define|#
directive|define
name|inline
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_GCC
end_ifndef

begin_define
define|#
directive|define
name|CONST
end_define

begin_define
define|#
directive|define
name|VOLATILE
end_define

begin_define
define|#
directive|define
name|SIGNED
end_define

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|arglist
parameter_list|)
value|type name ()
end_define

begin_define
define|#
directive|define
name|EXFUN
parameter_list|(
name|name
parameter_list|,
name|proto
parameter_list|)
value|name()
end_define

begin_define
define|#
directive|define
name|DEFUN
parameter_list|(
name|name
parameter_list|,
name|arglist
parameter_list|,
name|args
parameter_list|)
value|name arglist args;
end_define

begin_define
define|#
directive|define
name|DEFUN_VOID
parameter_list|(
name|name
parameter_list|)
value|name()
end_define

begin_define
define|#
directive|define
name|AND
value|;
end_define

begin_define
define|#
directive|define
name|DOTS
end_define

begin_define
define|#
directive|define
name|NOARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IN_GCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI C.  */
end_comment

begin_comment
comment|/* Define macros for some gcc attributes.  This permits us to use the    macros freely, and know that they will come into play for the    version of gcc in which they are supported.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|<
literal|2007
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Attribute __malloc__ on functions was valid as of gcc 2.96. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_MALLOC
end_ifndef

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|2096
operator|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_MALLOC
value|__attribute__ ((__malloc__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_MALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC>= 2.96 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_MALLOC */
end_comment

begin_comment
comment|/* Attributes on labels were valid as of gcc 2.93. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED_LABEL
end_ifndef

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|2093
operator|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED_LABEL
value|ATTRIBUTE_UNUSED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED_LABEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC>= 2.93 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_UNUSED_LABEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_UNUSED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NORETURN
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_NORETURN
value|__attribute__ ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_NORETURN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_PRINTF
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (__printf__, m, n)))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_1
value|ATTRIBUTE_PRINTF(1, 2)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_2
value|ATTRIBUTE_PRINTF(2, 3)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_3
value|ATTRIBUTE_PRINTF(3, 4)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_4
value|ATTRIBUTE_PRINTF(4, 5)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_5
value|ATTRIBUTE_PRINTF(5, 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_PRINTF */
end_comment

begin_comment
comment|/* We use __extension__ in some places to suppress -pedantic warnings    about GCC extensions.  This feature didn't work properly before    gcc 2.8.  */
end_comment

begin_if
if|#
directive|if
name|GCC_VERSION
operator|<
literal|2008
end_if

begin_define
define|#
directive|define
name|__extension__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bootstrap support:  Adjust certain macros defined by Autoconf,    which are only valid for the stage1 compiler.  If we detect    a modern version of GCC, we are probably in stage2 or beyond,    so unconditionally reset the values.  Note that const, inline,    etc. have been dealt with above.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LONG_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
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
comment|/* GCC>= 2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ansidecl.h	*/
end_comment

end_unit

