begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xfuncs.h,v 1.8 91/04/17 09:27:52 rws Exp $  *   * Copyright 1990 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XFUNCS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XFUNCS_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|X_USEBFUNCS
end_ifdef

begin_function_decl
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcmp
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|X_NOT_STDC_ENV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|macII
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|memmove(b2, b1, (size_t)(len))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|len
parameter_list|)
value|memset(b, 0, (size_t)(len))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|memcmp(b1, b2, (size_t)(len))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_include
include|#
directive|include
file|<bstring.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_XBCOPYFUNC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|macII
argument_list|)
end_if

begin_define
define|#
directive|define
name|bcopy
value|_XBCOPYFUNC
end_define

begin_define
define|#
directive|define
name|_XNEEDBCOPYFUNC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|len
parameter_list|)
value|memset(b, 0, len)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|memcmp(b1, b2, len)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* bsd */
end_comment

begin_function_decl
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ and relatives */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* X_USEBFUNCS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XFUNCS_H_ */
end_comment

end_unit

