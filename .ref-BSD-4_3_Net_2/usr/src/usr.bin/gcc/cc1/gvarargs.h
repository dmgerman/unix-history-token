begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* Use the system's macros with the system's compiler.  */
end_comment

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Record that varargs.h is defined; this turns off stdarg.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VARARGS_H
end_ifndef

begin_define
define|#
directive|define
name|_VARARGS_H
end_define

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
name|__spur__
end_ifdef

begin_include
include|#
directive|include
file|"va-spur.h"
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
name|__pyr__
end_ifdef

begin_include
include|#
directive|include
file|"va-pyr.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__NeXT__
end_ifdef

begin_comment
comment|/* On Next, erase any vestiges of stdarg.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|va_alist
end_undef

begin_undef
undef|#
directive|undef
name|va_dcl
end_undef

begin_undef
undef|#
directive|undef
name|va_list
end_undef

begin_undef
undef|#
directive|undef
name|va_start
end_undef

begin_undef
undef|#
directive|undef
name|va_end
end_undef

begin_undef
undef|#
directive|undef
name|__va_rounded_size
end_undef

begin_undef
undef|#
directive|undef
name|va_arg
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NeXT__ */
end_comment

begin_comment
comment|/* These macros implement traditional (non-ANSI) varargs    for GNU C.  */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist;
end_define

begin_define
define|#
directive|define
name|va_list
value|char *
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|(__builtin_saveregs (),					\   AP = ((void *)&__builtin_va_alist))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|AP=(char *)&__builtin_va_alist
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
end_define

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
value|(*((TYPE *) (AP += __va_rounded_size (TYPE),			\ 	      AP - __va_rounded_size (TYPE))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not pyr */
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
comment|/* not mips */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not spur */
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
comment|/* not _VARARGS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

end_unit

