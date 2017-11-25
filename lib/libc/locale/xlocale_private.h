begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2011 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by David Chisnall under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLOCALE_PRIVATE__H_
end_ifndef

begin_define
define|#
directive|define
name|_XLOCALE_PRIVATE__H_
end_define

begin_include
include|#
directive|include
file|<xlocale.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|"setlocale.h"
end_include

begin_comment
comment|/**  * The XLC_ values are indexes into the components array.  They are defined in  * the same order as the LC_ values in locale.h, but without the LC_ALL zero  * value.  Translating from LC_X to XLC_X is done by subtracting one.  *  * Any reordering of this enum should ensure that these invariants are not  * violated.  */
end_comment

begin_enum
enum|enum
block|{
name|XLC_COLLATE
init|=
literal|0
block|,
name|XLC_CTYPE
block|,
name|XLC_MONETARY
block|,
name|XLC_NUMERIC
block|,
name|XLC_TIME
block|,
name|XLC_MESSAGES
block|,
name|XLC_LAST
block|}
enum|;
end_enum

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_LAST
operator|-
name|XLC_COLLATE
operator|==
literal|6
argument_list|,
literal|"XLC values should be contiguous"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_COLLATE
operator|==
name|LC_COLLATE
operator|-
literal|1
argument_list|,
literal|"XLC_COLLATE doesn't match the LC_COLLATE value."
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_CTYPE
operator|==
name|LC_CTYPE
operator|-
literal|1
argument_list|,
literal|"XLC_CTYPE doesn't match the LC_CTYPE value."
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_MONETARY
operator|==
name|LC_MONETARY
operator|-
literal|1
argument_list|,
literal|"XLC_MONETARY doesn't match the LC_MONETARY value."
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_NUMERIC
operator|==
name|LC_NUMERIC
operator|-
literal|1
argument_list|,
literal|"XLC_NUMERIC doesn't match the LC_NUMERIC value."
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_TIME
operator|==
name|LC_TIME
operator|-
literal|1
argument_list|,
literal|"XLC_TIME doesn't match the LC_TIME value."
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|XLC_MESSAGES
operator|==
name|LC_MESSAGES
operator|-
literal|1
argument_list|,
literal|"XLC_MESSAGES doesn't match the LC_MESSAGES value."
argument_list|)
assert|;
end_assert

begin_comment
comment|/**  * Header used for objects that are reference counted.  Objects may optionally  * have a destructor associated, which is responsible for destroying the  * structure.  Global / static versions of the structure should have no  * destructor set - they can then have their reference counts manipulated as  * normal, but will not do anything with them.  *  * The header stores a retain count - objects are assumed to have a reference  * count of 1 when they are created, but the retain count is 0.  When the  * retain count is less than 0, they are freed.  */
end_comment

begin_struct
struct|struct
name|xlocale_refcounted
block|{
comment|/** Number of references to this component.  */
name|long
name|retain_count
decl_stmt|;
comment|/** Function used to destroy this component, if one is required*/
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Header for a locale component.  All locale components must begin with this  * header.  */
end_comment

begin_struct
struct|struct
name|xlocale_component
block|{
name|struct
name|xlocale_refcounted
name|header
decl_stmt|;
comment|/** Name of the locale used for this component. */
name|char
name|locale
index|[
name|ENCODING_LEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * xlocale structure, stores per-thread locale information.    */
end_comment

begin_struct
struct|struct
name|_xlocale
block|{
name|struct
name|xlocale_refcounted
name|header
decl_stmt|;
comment|/** Components for the locale.  */
name|struct
name|xlocale_component
modifier|*
name|components
index|[
name|XLC_LAST
index|]
decl_stmt|;
comment|/** Flag indicating if components[XLC_MONETARY] has changed since the 	 * last call to localeconv_l() with this locale. */
name|int
name|monetary_locale_changed
decl_stmt|;
comment|/** Flag indicating whether this locale is actually using a locale for 	 * LC_MONETARY (1), or if it should use the C default instead (0). */
name|int
name|using_monetary_locale
decl_stmt|;
comment|/** Flag indicating if components[XLC_NUMERIC] has changed since the 	 * last call to localeconv_l() with this locale. */
name|int
name|numeric_locale_changed
decl_stmt|;
comment|/** Flag indicating whether this locale is actually using a locale for 	 * LC_NUMERIC (1), or if it should use the C default instead (0). */
name|int
name|using_numeric_locale
decl_stmt|;
comment|/** Flag indicating whether this locale is actually using a locale for 	 * LC_TIME (1), or if it should use the C default instead (0). */
name|int
name|using_time_locale
decl_stmt|;
comment|/** Flag indicating whether this locale is actually using a locale for 	 * LC_MESSAGES (1), or if it should use the C default instead (0). */
name|int
name|using_messages_locale
decl_stmt|;
comment|/** The structure to be returned from localeconv_l() for this locale. */
name|struct
name|lconv
name|lconv
decl_stmt|;
comment|/** Persistent state used by mblen() calls. */
name|__mbstate_t
name|mblen
decl_stmt|;
comment|/** Persistent state used by mbrlen() calls. */
name|__mbstate_t
name|mbrlen
decl_stmt|;
comment|/** Persistent state used by mbrtoc16() calls. */
name|__mbstate_t
name|mbrtoc16
decl_stmt|;
comment|/** Persistent state used by mbrtoc32() calls. */
name|__mbstate_t
name|mbrtoc32
decl_stmt|;
comment|/** Persistent state used by mbrtowc() calls. */
name|__mbstate_t
name|mbrtowc
decl_stmt|;
comment|/** Persistent state used by mbsnrtowcs() calls. */
name|__mbstate_t
name|mbsnrtowcs
decl_stmt|;
comment|/** Persistent state used by mbsrtowcs() calls. */
name|__mbstate_t
name|mbsrtowcs
decl_stmt|;
comment|/** Persistent state used by mbtowc() calls. */
name|__mbstate_t
name|mbtowc
decl_stmt|;
comment|/** Persistent state used by c16rtomb() calls. */
name|__mbstate_t
name|c16rtomb
decl_stmt|;
comment|/** Persistent state used by c32rtomb() calls. */
name|__mbstate_t
name|c32rtomb
decl_stmt|;
comment|/** Persistent state used by wcrtomb() calls. */
name|__mbstate_t
name|wcrtomb
decl_stmt|;
comment|/** Persistent state used by wcsnrtombs() calls. */
name|__mbstate_t
name|wcsnrtombs
decl_stmt|;
comment|/** Persistent state used by wcsrtombs() calls. */
name|__mbstate_t
name|wcsrtombs
decl_stmt|;
comment|/** Persistent state used by wctomb() calls. */
name|__mbstate_t
name|wctomb
decl_stmt|;
comment|/** Buffer used by nl_langinfo_l() */
name|char
modifier|*
name|csym
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Increments the reference count of a reference-counted structure.  */
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
end_macro

begin_function
specifier|static
name|void
modifier|*
name|xlocale_retain
parameter_list|(
name|void
modifier|*
name|val
parameter_list|)
block|{
name|struct
name|xlocale_refcounted
modifier|*
name|obj
init|=
name|val
decl_stmt|;
name|atomic_add_long
argument_list|(
operator|&
operator|(
name|obj
operator|->
name|retain_count
operator|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Decrements the reference count of a reference-counted structure, freeing it  * if this is the last reference, calling its destructor if it has one.  */
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
end_macro

begin_function
specifier|static
name|void
name|xlocale_release
parameter_list|(
name|void
modifier|*
name|val
parameter_list|)
block|{
name|struct
name|xlocale_refcounted
modifier|*
name|obj
init|=
name|val
decl_stmt|;
name|long
name|count
decl_stmt|;
name|count
operator|=
name|atomic_fetchadd_long
argument_list|(
operator|&
operator|(
name|obj
operator|->
name|retain_count
operator|)
argument_list|,
operator|-
literal|1
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|0
operator|&&
name|obj
operator|->
name|destructor
operator|!=
name|NULL
condition|)
name|obj
operator|->
name|destructor
argument_list|(
name|obj
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Load functions.  Each takes the name of a locale and a pointer to the data  * to be initialised as arguments.  Two special values are allowed for the   */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|__collate_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__ctype_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__messages_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__monetary_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__numeric_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__time_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|_xlocale
name|__xlocale_global_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_xlocale
name|__xlocale_C_locale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * Caches the rune table in TLS for fast access.  */
end_comment

begin_function_decl
name|void
name|__set_thread_rune_locale
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Flag indicating whether a per-thread locale has been set.  If no per-thread  * locale has ever been set, then we always use the global locale.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__has_thread_locale
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__NO_TLS
end_ifndef

begin_comment
comment|/**  * The per-thread locale.  Avoids the need to use pthread lookup functions when  * getting the per-thread locale.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|_Thread_local
name|locale_t
name|__thread_locale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * Returns the current locale for this thread, or the global locale if none is  * set.  The caller does not have to free the locale.  The return value from  * this call is not guaranteed to remain valid after the locale changes.  As  * such, this should only be called within libc functions.  */
end_comment

begin_function
specifier|static
specifier|inline
name|locale_t
name|__get_locale
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|__has_thread_locale
condition|)
block|{
return|return
operator|(
operator|&
name|__xlocale_global_locale
operator|)
return|;
block|}
return|return
operator|(
name|__thread_locale
condition|?
name|__thread_locale
else|:
operator|&
name|__xlocale_global_locale
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
name|locale_t
name|__get_locale
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Two magic values are allowed for locale_t objects.  NULL and -1.  This  * function maps those to the real locales that they represent.  */
end_comment

begin_function
specifier|static
specifier|inline
name|locale_t
name|get_real_locale
parameter_list|(
name|locale_t
name|locale
parameter_list|)
block|{
switch|switch
condition|(
operator|(
name|intptr_t
operator|)
name|locale
condition|)
block|{
case|case
literal|0
case|:
return|return
operator|(
operator|&
name|__xlocale_C_locale
operator|)
return|;
case|case
operator|-
literal|1
case|:
return|return
operator|(
operator|&
name|__xlocale_global_locale
operator|)
return|;
default|default:
return|return
operator|(
name|locale
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/**  * Replace a placeholder locale with the real global or thread-local locale_t.  */
end_comment

begin_define
define|#
directive|define
name|FIX_LOCALE
parameter_list|(
name|l
parameter_list|)
value|(l = get_real_locale(l))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

