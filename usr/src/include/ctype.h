begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * %sccs.include.redist.c%  *  *	@(#)ctype.h	5.8 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTYPE_H_
end_define

begin_include
include|#
directive|include
file|<runetype.h>
end_include

begin_define
define|#
directive|define
name|_A
value|0x00000100L
end_define

begin_comment
comment|/* Alpha */
end_comment

begin_define
define|#
directive|define
name|_C
value|0x00000200L
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|_D
value|0x00000400L
end_define

begin_comment
comment|/* Digit */
end_comment

begin_define
define|#
directive|define
name|_G
value|0x00000800L
end_define

begin_comment
comment|/* Graph */
end_comment

begin_define
define|#
directive|define
name|_L
value|0x00001000L
end_define

begin_comment
comment|/* Lower */
end_comment

begin_define
define|#
directive|define
name|_P
value|0x00002000L
end_define

begin_comment
comment|/* Punct */
end_comment

begin_define
define|#
directive|define
name|_S
value|0x00004000L
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|_U
value|0x00008000L
end_define

begin_comment
comment|/* Upper */
end_comment

begin_define
define|#
directive|define
name|_X
value|0x00010000L
end_define

begin_comment
comment|/* X digit */
end_comment

begin_define
define|#
directive|define
name|_B
value|0x00020000L
end_define

begin_comment
comment|/* Blank */
end_comment

begin_define
define|#
directive|define
name|_R
value|0x00040000L
end_define

begin_comment
comment|/* Print */
end_comment

begin_define
define|#
directive|define
name|_I
value|0x00080000L
end_define

begin_comment
comment|/* Ideogram */
end_comment

begin_define
define|#
directive|define
name|_T
value|0x00100000L
end_define

begin_comment
comment|/* Special */
end_comment

begin_define
define|#
directive|define
name|_Q
value|0x00200000L
end_define

begin_comment
comment|/* Phonogram */
end_comment

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|__istype((c), (_A|_D))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _A)
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _C)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _D)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _G)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _L)
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _R)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _P)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _S)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _U)
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _X)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

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

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((c& ~0x7F) == 0)
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x7F)
end_define

begin_define
define|#
directive|define
name|digittoint
parameter_list|(
name|c
parameter_list|)
value|__istype((c), 0xFF)
end_define

begin_define
define|#
directive|define
name|isideogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _I)
end_define

begin_define
define|#
directive|define
name|isphonogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _T)
end_define

begin_define
define|#
directive|define
name|isspecial
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _Q)
end_define

begin_define
define|#
directive|define
name|isblank
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _B)
end_define

begin_define
define|#
directive|define
name|isrune
parameter_list|(
name|c
parameter_list|)
value|__istype((c),  0xFFFFFF00L)
end_define

begin_define
define|#
directive|define
name|isnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _D)
end_define

begin_define
define|#
directive|define
name|ishexnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|unsigned
name|long
name|___runetype
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_BSD_RUNE_T_
name|___tolower
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_BSD_RUNE_T_
name|___toupper
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|__END_DECLS
comment|/*  * See comments in<machine/ansi.h> about _BSD_RUNE_T_.  *  * If your compiler supports inline functions, #define _USE_CTYPE_INLINE_.  * Otherwise, if you want inline macros, #define _USE_CTYPE_MACROS_, else  * #define _USE_CTYPE_CLIBRARY_ to call C library functions.  */
define|#
directive|define
name|_USE_CTYPE_INLINE_
comment|/* 4.4BSD */
if|#
directive|if
name|defined
argument_list|(
name|_USE_CTYPE_INLINE_
argument_list|)
specifier|static
specifier|inline
name|int
name|__istype
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
name|_BSD_RUNE_T_
name|c
decl_stmt|;
name|unsigned
name|long
name|f
decl_stmt|;
block|{
return|return
operator|(
operator|(
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___runetype
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|runetype
index|[
name|c
index|]
operator|)
operator|&
name|f
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__isctype
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
name|_BSD_RUNE_T_
name|c
decl_stmt|;
name|unsigned
name|long
name|f
decl_stmt|;
block|{
return|return
operator|(
operator|(
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
literal|0
else|:
name|_DefaultRuneLocale
operator|.
name|runetype
index|[
name|c
index|]
operator|)
operator|&
name|f
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_LIBRARY
argument_list|)
end_if

begin_comment
comment|/* _ANSI_LIBRARY: for lib/libc/gen/isctype.c. */
end_comment

begin_function
specifier|static
specifier|inline
name|_BSD_RUNE_T_
name|toupper
parameter_list|(
name|c
parameter_list|)
name|_BSD_RUNE_T_
name|c
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___toupper
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|mapupper
index|[
name|c
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|_BSD_RUNE_T_
name|tolower
parameter_list|(
name|c
parameter_list|)
name|_BSD_RUNE_T_
name|c
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|c
operator|&
name|_CRMASK
operator|)
condition|?
name|___tolower
argument_list|(
name|c
argument_list|)
else|:
name|_CurrentRuneLocale
operator|->
name|maplower
index|[
name|c
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_LIBRARY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USE_CTYPE_INLINE_ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_CTYPE_MACROS_
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|int
name|___ctype_junk
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__istype
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|(((((___ctype_junk = (c))& _CRMASK) ?				\ 	    ___runetype(___ctype_junk) :				\ 	    _CurrentRuneLocale->runetype[___ctype_junk])& f) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|__isctype
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|(((((___ctype_junk = (c))& _CRMASK) ? 0 :			\ 	    _DefaultRuneLocale.runetype[___ctype_junk])& f) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
define|\
value|(((___ctype_junk = (c))& _CRMASK) ?				\ 	    ___toupper(___ctype_junk) :					\ 	    _CurrentRuneLocale->mapupper[___ctype_junk])
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
define|\
value|(((___ctype_junk = (c))& _CRMASK) ?				\ 	    ___tolower(___ctype_junk) :					\ 	    _CurrentRuneLocale->maplower[___ctype_junk])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USE_CTYPE_MACROS_*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_CTYPE_CLIBRARY_
argument_list|)
end_if

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|int
name|__istype
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__isctype
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_BSD_RUNE_T_
name|toupper
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_BSD_RUNE_T_
name|tolower
name|__P
argument_list|(
operator|(
name|_BSD_RUNE_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USE_CTYPE_CLIBRARY_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CTYPE_H_ */
end_comment

end_unit

