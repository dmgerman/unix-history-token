begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ANSI and traditional C compatability macros    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000    Free Software Foundation, Inc.    This file is part of the GNU C Library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* ANSI and traditional C compatibility macros     ANSI C is assumed if __STDC__ is #defined.     Macro	ANSI C definition	Traditional C definition    -----	---- - ----------	----------- - ----------    PTR		`void *'		`char *'    LONG_DOUBLE	`long double'		`double'    VOLATILE	`volatile'		`'    SIGNED	`signed'		`'    PTRCONST	`void *const'		`char *'    ANSI_PROTOTYPES  1			not defined     CONST is also defined, but is obsolete.  Just use const.     obsolete --     DEFUN (name, arglist, args)  	Defines function NAME.  	ARGLIST lists the arguments, separated by commas and enclosed in 	parentheses.  ARGLIST becomes the argument list in traditional C.  	ARGS list the arguments with their types.  It becomes a prototype in 	ANSI C, and the type declarations in traditional C.  Arguments should 	be separated with `AND'.  For functions with a variable number of 	arguments, the last thing listed should be `DOTS'.     obsolete --     DEFUN_VOID (name)  	Defines a function NAME, which takes no arguments.     obsolete --     EXFUN (name, (prototype))	-- obsolete.  	Replaced by PARAMS.  Do not use; will disappear someday soon. 	Was used in external function declarations. 	In ANSI C it is `NAME PROTOTYPE' (so PROTOTYPE should be enclosed in 	parentheses).  In traditional C it is `NAME()'. 	For a function that takes no arguments, PROTOTYPE should be `(void)'.     obsolete --     PROTO (type, name, (prototype)    -- obsolete.  	This one has also been replaced by PARAMS.  Do not use.     PARAMS ((args))  	We could use the EXFUN macro to handle prototype declarations, but 	the name is misleading and the result is ugly.  So we just define a 	simple macro to handle the parameter lists, as in:  	      static int foo PARAMS ((int, char));  	This produces:  `static int foo();' or `static int foo (int, char);'  	EXFUN would have done it like this:  	      static int EXFUN (foo, (int, char));  	but the function is not external...and it's hard to visually parse 	the function name out of the mess.   EXFUN should be considered 	obsolete; new code should be written to use PARAMS.     DOTS is also obsolete.     Examples:  	extern int printf PARAMS ((const char *format, ...)); */
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
name|PTR
value|void *
end_define

begin_define
define|#
directive|define
name|PTRCONST
value|void *CONST
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE
value|long double
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_GCC
end_ifndef

begin_define
define|#
directive|define
name|AND
value|,
end_define

begin_define
define|#
directive|define
name|NOARGS
value|void
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IN_GCC */
end_comment

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|paramlist
parameter_list|)
value|paramlist
end_define

begin_define
define|#
directive|define
name|ANSI_PROTOTYPES
value|1
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
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list,var)
end_define

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
name|DOTS
value|, ...
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

begin_ifndef
ifndef|#
directive|ifndef
name|IN_GCC
end_ifndef

begin_define
define|#
directive|define
name|AND
value|;
end_define

begin_define
define|#
directive|define
name|NOARGS
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IN_GCC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_comment
comment|/* some systems define it in header files for non-ansi mode */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|paramlist
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|VPARAMS
parameter_list|(
name|ARGS
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
end_define

begin_define
define|#
directive|define
name|DOTS
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ansidecl.h	*/
end_comment

end_unit

