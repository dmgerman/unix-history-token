begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stdarg.h for GNU.    Note that the type used in va_arg is supposed to match the    actual type **after default promotions**.    Thus, va_arg (..., short) is not valid.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDARG_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_STDARG_H_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__need___va_list
end_ifndef

begin_define
define|#
directive|define
name|_STDARG_H
end_define

begin_define
define|#
directive|define
name|_ANSI_STDARG_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __need___va_list */
end_comment

begin_undef
undef|#
directive|undef
name|__need___va_list
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__clipper__
end_ifdef

begin_include
include|#
directive|include
file|"va-clipper.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__m88k__
end_ifdef

begin_include
include|#
directive|include
file|"va-m88k.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__i860__
end_ifdef

begin_include
include|#
directive|include
file|"va-i860.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__hppa__
end_ifdef

begin_include
include|#
directive|include
file|"va-pa.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_include
include|#
directive|include
file|"va-mips.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_include
include|#
directive|include
file|"va-sparc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__i960__
end_ifdef

begin_include
include|#
directive|include
file|"va-i960.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_include
include|#
directive|include
file|"va-alpha.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__H8300__
argument_list|)
operator|||
name|defined
argument_list|(
name|__H8300H__
argument_list|)
operator|||
name|defined
argument_list|(
name|__H8300S__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"va-h8300.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PPC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_CALL_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|"va-ppc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__arc__
end_ifdef

begin_include
include|#
directive|include
file|"va-arc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__M32R__
end_ifdef

begin_include
include|#
directive|include
file|"va-m32r.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__sh__
end_ifdef

begin_include
include|#
directive|include
file|"va-sh.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__mn10300__
end_ifdef

begin_include
include|#
directive|include
file|"va-mn10300.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__mn10200__
end_ifdef

begin_include
include|#
directive|include
file|"va-mn10200.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__v850__
end_ifdef

begin_include
include|#
directive|include
file|"va-v850.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_TMS320C4x
argument_list|)
operator|||
name|defined
argument_list|(
name|_TMS320C3x
argument_list|)
end_if

begin_include
include|#
directive|include
file|<va-c4x.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Define __gnuc_va_list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
modifier|*
name|__gnuc_va_list
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
modifier|*
name|__gnuc_va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the standard macros for the user,    if this invocation was from the user program.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* Amount of space required in an argument list for an arg of type TYPE.    TYPE may alternatively be an expression whose type is used.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sysV68
argument_list|)
end_if

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (short) - 1) / sizeof (short)) * sizeof (short))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (long) - 1) / sizeof (long)) * sizeof (long))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(AP = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))
end_define

begin_undef
undef|#
directive|undef
name|va_end
end_undef

begin_function_decl
name|void
name|va_end
parameter_list|(
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in libgcc.a */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
value|((void)0)
end_define

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i860__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ns32000__
argument_list|)
operator|||
name|defined
argument_list|(
name|__vax__
argument_list|)
end_if

begin_comment
comment|/* This is for little-endian machines; small args are padded upward.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)),	\   *((TYPE *) (void *) ((char *) (AP) - __va_rounded_size (TYPE))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* big-endian */
end_comment

begin_comment
comment|/* This is for big-endian machines; small args are padded downward.  */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)),	\   *((TYPE *) (void *) ((char *) (AP)					\ 		       - ((sizeof (TYPE)< __va_rounded_size (char)	\ 			   ? sizeof (TYPE) : __va_rounded_size (TYPE))))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* big-endian */
end_comment

begin_comment
comment|/* Copy __gnuc_va_list into another variable of this type.  */
end_comment

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(dest) = (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TMS320C3x or TMS320C4x */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not v850 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not mn10200 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not mn10300 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sh */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not m32r */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not arc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not powerpc with V.4 calling sequence */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not h8300 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not alpha */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not i960 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sparc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not mips */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not hppa */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not i860 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not m88k */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not clipper */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* Define va_list, if desired, from __gnuc_va_list. */
end_comment

begin_comment
comment|/* We deliberately do not define va_list when called from    stdio.h, because ANSI C says that stdio.h is not supposed to define    va_list.  stdio.h needs to have access to that data type,     but must not use that name.  It should use the name __gnuc_va_list,    which is safe because it is reserved for the implementation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_HIDDEN_VA_LIST
end_ifdef

begin_comment
comment|/* On OSF1, this means varargs.h is "half-loaded".  */
end_comment

begin_undef
undef|#
directive|undef
name|_VA_LIST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_VA_LIST
end_ifdef

begin_undef
undef|#
directive|undef
name|_BSD_VA_LIST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_SCO_DS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__VA_LIST
argument_list|)
operator|)
end_if

begin_comment
comment|/* SVR4.2 uses _VA_LIST for an internal alias for va_list,    so we must avoid testing it and setting it here.    SVR4 uses _VA_LIST as a flag in stdarg.h, but we should    have no conflict with that.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i860__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
value|va_list
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
comment|/* __i860__ */
end_comment

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_DS
end_ifdef

begin_define
define|#
directive|define
name|__VA_LIST
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
comment|/* _VA_LIST_ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __svr4__ || _SCO_DS */
end_comment

begin_comment
comment|/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.    But on BSD NET2 we must not test or define or undef it.    (Note that the comments in NET 2's ansi.h    are incorrect for _VA_LIST_--see stdio.h!)  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VA_LIST_
argument_list|)
operator|||
name|defined
argument_list|(
name|__BSD_NET2__
argument_list|)
operator|||
name|defined
argument_list|(
name|____386BSD____
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sequent__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|WINNT
argument_list|)
end_if

begin_comment
comment|/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DEFINED
end_ifndef

begin_comment
comment|/* The macro _VA_LIST is used in SCO Unix 3.2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_comment
comment|/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_T_H
end_ifndef

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST_T_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST_DEFINED */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__BSD_NET2__
argument_list|)
operator|||
name|defined
argument_list|(
name|____386BSD____
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sequent__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_T_H
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_T_H
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
comment|/* not _VA_LIST_, except on certain systems */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __svr4__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _ANSI_STDARG_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _STDARG_H */
end_comment

end_unit

