begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_STDDEF_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_STDDEF_H_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_STDDEF_H
end_ifndef

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

begin_comment
comment|/* #if defined (__BSD_NET2__) || defined (____386BSD____)*/
end_comment

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_comment
comment|/* #endif*/
end_comment

begin_comment
comment|/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are     defined if the corresponding type is *not* defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ANSI_H_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_
end_ifndef

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_
end_ifndef

begin_define
define|#
directive|define
name|_PTRDIFF_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_
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

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|__need_ptrdiff_t
end_ifndef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
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
comment|/* _ANSI_H_ */
end_comment

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
name|_SIZE_T
end_ifndef

begin_comment
comment|/* in case<sys/types.h> has defined it. */
end_comment

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

begin_define
define|#
directive|define
name|_SIZE_T
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

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

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
comment|/* _SIZE_T */
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
name|___int_wchar_t_h
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_GCC_WCHAR_T
end_ifndef

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
name|___int_wchar_t_h
end_define

begin_define
define|#
directive|define
name|_GCC_WCHAR_T
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__WCHAR_TYPE__
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_comment
comment|/* In C++, wchar_t is a distinct basic type,    and we can expect __wchar_t to be defined by cc1plus.  */
end_comment

begin_typedef
typedef|typedef
name|__wchar_t
name|wchar_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* In C, cpp tells us which type to make an alias for.  */
end_comment

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

begin_comment
comment|/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.     are already defined.  We need not worry about the case of wanting just     one of these types, not on 4.3bsd-net2, because only the GNU libc     header files do that.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ANSI_H_
end_ifdef

begin_undef
undef|#
directive|undef
name|_PTRDIFF_T_
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_STDDEF_H
end_ifdef

begin_comment
comment|/* This is a kludge. 		    _STDDEF_H is defined when we are using the whole file, 		    undefined when obstack.h wants just ptrdiff_t.  */
end_comment

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

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
comment|/* _ANSI_STDDEF_H was not defined before */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H_ was not defined before */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H was not defined before */
end_comment

end_unit

