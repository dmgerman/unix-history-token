begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ANSI_STDDEF_H
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__STDDEF_H__
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_size_t
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_NULL
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_comment
comment|/* Any one of these symbols __need_* means that GNU libc    wants us just to define one data type.  So don't define    the symbols that indicate this file's entire job has been done.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__need_size_t
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__need_NULL
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_STDDEF_H
end_define

begin_define
define|#
directive|define
name|_STDDEF_H_
end_define

begin_comment
comment|/* snaroff@next.com says the NeXT needs this.  */
end_comment

begin_define
define|#
directive|define
name|_ANSI_STDDEF_H
end_define

begin_comment
comment|/* Irix 5.1 needs this.  */
end_comment

begin_define
define|#
directive|define
name|__STDDEF_H__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__sys_stdtypes_h
end_ifndef

begin_comment
comment|/* This avoids lossage on SunOS but only if stdtypes.h comes first.    There's no way to win with the other order!  Sun lossage.  */
end_comment

begin_comment
comment|/* On 4.3bsd-net2, make sure ansi.h is included, so we have    one less case to deal with in the following.  */
end_comment

begin_if
if|#
directive|if
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
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are    defined if the corresponding type is *not* defined.    FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ANSI_H_
argument_list|)
operator|||
name|defined
argument_list|(
name|_MACHINE_ANSI_H_
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SIZE_T_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD_SIZE_T_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_SIZE_T
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
name|_PTRDIFF_T_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD_PTRDIFF_T_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PTRDIFF_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_    instead of _WCHAR_T_. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WCHAR_T_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD_WCHAR_T_
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_WCHAR_T_
end_ifndef

begin_define
define|#
directive|define
name|_WCHAR_T
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
comment|/* Undef _FOO_T_ if we are supposed to define foo_t.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_PTRDIFF_T_
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
name|__need_size_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
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
name|__need_wchar_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) */
end_comment

begin_comment
comment|/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.    Just ignore it.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sequent__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_PTRDIFF_T_
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On VxWorks,<type/vxTypesBase.h> may have defined macros like    _TYPE_size_t which will typedef size_t.  fixincludes patched the    vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is    not defined, and so that defining this macro defines _GCC_SIZE_T.    If we find that the macros are still defined at this point, we must    invoke them so that the type is defined as expected.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_TYPE_ptrdiff_t
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
operator|)
end_if

begin_expr_stmt
name|_TYPE_ptrdiff_t
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|_TYPE_ptrdiff_t
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
name|_TYPE_size_t
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__need_size_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
operator|)
end_if

begin_expr_stmt
name|_TYPE_size_t
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|_TYPE_size_t
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
name|_TYPE_wchar_t
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDDEF_H_
argument_list|)
operator|)
end_if

begin_expr_stmt
name|_TYPE_wchar_t
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|_TYPE_wchar_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In case nobody has defined these types, but we aren't running under    GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE__TYPE__, and    __WCHAR_TYPE__ have reasonable values.  This can happen if the    parts of GCC is compiled by an older compiler, that actually    include gstddef.h, such as collect2.  */
end_comment

begin_comment
comment|/* Signed type of difference of two pointers.  */
end_comment

begin_comment
comment|/* Define this type if we are doing the whole job,    or if we want this type in particular.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T
end_ifndef

begin_comment
comment|/* in case<sys/types.h> has defined it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T_PTRDIFF_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_T_PTRDIFF
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__PTRDIFF_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_PTRDIFF_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|___int_ptrdiff_t_h
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_GCC_PTRDIFF_T
end_ifndef

begin_define
define|#
directive|define
name|_PTRDIFF_T
end_define

begin_define
define|#
directive|define
name|_T_PTRDIFF_
end_define

begin_define
define|#
directive|define
name|_T_PTRDIFF
end_define

begin_define
define|#
directive|define
name|__PTRDIFF_T
end_define

begin_define
define|#
directive|define
name|_PTRDIFF_T_
end_define

begin_define
define|#
directive|define
name|_BSD_PTRDIFF_T_
end_define

begin_define
define|#
directive|define
name|___int_ptrdiff_t_h
end_define

begin_define
define|#
directive|define
name|_GCC_PTRDIFF_T
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__PTRDIFF_TYPE__
end_ifndef

begin_define
define|#
directive|define
name|__PTRDIFF_TYPE__
value|long int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__PTRDIFF_TYPE__
name|ptrdiff_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GCC_PTRDIFF_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___int_ptrdiff_t_h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_PTRDIFF_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTRDIFF_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PTRDIFF_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_PTRDIFF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_PTRDIFF_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTRDIFF_T */
end_comment

begin_comment
comment|/* If this symbol has done its job, get rid of it.  */
end_comment

begin_undef
undef|#
directive|undef
name|__need_ptrdiff_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H or __need_ptrdiff_t.  */
end_comment

begin_comment
comment|/* Unsigned type of `sizeof' something.  */
end_comment

begin_comment
comment|/* Define this type if we are doing the whole job,    or if we want this type in particular.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_size_t
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__size_t__
end_ifndef

begin_comment
comment|/* BeOS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_comment
comment|/* in case<sys/types.h> has defined it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIZE_T_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_T_SIZE_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_T_SIZE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__SIZE_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_SIZE_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DEFINED_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DEFINED
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|___int_size_t_h
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_GCC_SIZE_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZET_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__size_t
end_ifndef

begin_define
define|#
directive|define
name|__size_t__
end_define

begin_comment
comment|/* BeOS */
end_comment

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_define
define|#
directive|define
name|_SYS_SIZE_T_H
end_define

begin_define
define|#
directive|define
name|_T_SIZE_
end_define

begin_define
define|#
directive|define
name|_T_SIZE
end_define

begin_define
define|#
directive|define
name|__SIZE_T
end_define

begin_define
define|#
directive|define
name|_SIZE_T_
end_define

begin_define
define|#
directive|define
name|_BSD_SIZE_T_
end_define

begin_define
define|#
directive|define
name|_SIZE_T_DEFINED_
end_define

begin_define
define|#
directive|define
name|_SIZE_T_DEFINED
end_define

begin_define
define|#
directive|define
name|___int_size_t_h
end_define

begin_define
define|#
directive|define
name|_GCC_SIZE_T
end_define

begin_define
define|#
directive|define
name|_SIZET_
end_define

begin_define
define|#
directive|define
name|__size_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SIZE_TYPE__
end_ifndef

begin_define
define|#
directive|define
name|__SIZE_TYPE__
value|long unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__GNUG__
argument_list|)
operator|&&
name|defined
argument_list|(
name|size_t
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__BEOS__
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ssize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BEOS__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined (__GNUG__)&& defined (size_t)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __size_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZET_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GCC_SIZE_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___int_size_t_h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T_DEFINED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T_DEFINED_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_SIZE_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SIZE_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_SIZE_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SIZE_T_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __size_t__ */
end_comment

begin_undef
undef|#
directive|undef
name|__need_size_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H or __need_size_t.  */
end_comment

begin_comment
comment|/* Wide character type.    Locale-writers should change this as necessary to    be big enough to hold unique values not between 0 and 127,    and not (wchar_t) -1, for each defined multibyte character.  */
end_comment

begin_comment
comment|/* Define this type if we are doing the whole job,    or if we want this type in particular.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__wchar_t__
end_ifndef

begin_comment
comment|/* BeOS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_T_WCHAR_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_T_WCHAR
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__WCHAR_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_WCHAR_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_DEFINED_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_DEFINED
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|___int_wchar_t_h
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__INT_WCHAR_T_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_GCC_WCHAR_T
end_ifndef

begin_define
define|#
directive|define
name|__wchar_t__
end_define

begin_comment
comment|/* BeOS */
end_comment

begin_define
define|#
directive|define
name|_WCHAR_T
end_define

begin_define
define|#
directive|define
name|_T_WCHAR_
end_define

begin_define
define|#
directive|define
name|_T_WCHAR
end_define

begin_define
define|#
directive|define
name|__WCHAR_T
end_define

begin_define
define|#
directive|define
name|_WCHAR_T_
end_define

begin_define
define|#
directive|define
name|_BSD_WCHAR_T_
end_define

begin_define
define|#
directive|define
name|_WCHAR_T_DEFINED_
end_define

begin_define
define|#
directive|define
name|_WCHAR_T_DEFINED
end_define

begin_define
define|#
directive|define
name|_WCHAR_T_H
end_define

begin_define
define|#
directive|define
name|___int_wchar_t_h
end_define

begin_define
define|#
directive|define
name|__INT_WCHAR_T_H
end_define

begin_define
define|#
directive|define
name|_GCC_WCHAR_T
end_define

begin_comment
comment|/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_    instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other    symbols in the _FOO_T_ family, stays defined even after its    corresponding type is defined).  If we define wchar_t, then we    must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if    we undef _WCHAR_T_, then we must also define rune_t, since     headers like runetype.h assume that if machine/ansi.h is included,    and _BSD_WCHAR_T_ is not defined, then rune_t is available.    machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of    the same type." */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WCHAR_T_
end_ifdef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_RUNE_T_
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_typedef
typedef|typedef
name|_BSD_RUNE_T_
name|rune_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__WCHAR_TYPE__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__BEOS__
end_ifdef

begin_define
define|#
directive|define
name|__WCHAR_TYPE__
value|unsigned char
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__WCHAR_TYPE__
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __wchar_t__ */
end_comment

begin_undef
undef|#
directive|undef
name|__need_wchar_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H or __need_wchar_t.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_WINT_T
end_ifndef

begin_define
define|#
directive|define
name|_WINT_T
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__WINT_TYPE__
end_ifndef

begin_define
define|#
directive|define
name|__WINT_TYPE__
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__WINT_TYPE__
name|wint_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__need_wint_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.     are already defined.  */
end_comment

begin_comment
comment|/*  BSD/OS 3.1 requires the MACHINE_ANSI_H check here.  FreeBSD 2.x apparently     does not, even though there is a check for MACHINE_ANSI_H above.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ANSI_H_
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MACHINE_ANSI_H_
argument_list|)
operator|)
end_if

begin_comment
comment|/*  The references to _GCC_PTRDIFF_T_, _GCC_SIZE_T_, and _GCC_WCHAR_T_     are probably typos and should be removed before 2.8 is released.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_PTRDIFF_T_
end_ifdef

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_PTRDIFF_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_SIZE_T_
end_ifdef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_WCHAR_T_
end_ifdef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  The following ones are the real ones.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_PTRDIFF_T
end_ifdef

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_PTRDIFF_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_SIZE_T
end_ifdef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_WCHAR_T
end_ifdef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ANSI_H_ || ( __bsdi__&& _MACHINE_ANSI_H_ ) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sys_stdtypes_h */
end_comment

begin_comment
comment|/* A null pointer constant.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_NULL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* in case<stdio.h> has defined it. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_define
define|#
directive|define
name|NULL
value|__null
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* G++ */
end_comment

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* G++ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NULL not defined and<stddef.h> or need NULL.  */
end_comment

begin_undef
undef|#
directive|undef
name|__need_NULL
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_STDDEF_H
end_ifdef

begin_comment
comment|/* Offset of member MEMBER in a struct of type TYPE.  */
end_comment

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((size_t)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H was defined this time */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDDEF_H&& !_STDDEF_H_&& !_ANSI_STDDEF_H&& !__STDDEF_H__ 	  || __need_XXX was not defined before */
end_comment

end_unit

