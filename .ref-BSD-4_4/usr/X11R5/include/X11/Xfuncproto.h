begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xfuncproto.h,v 1.7 91/05/13 20:49:21 rws Exp $ */
end_comment

begin_comment
comment|/*   * Copyright 1989, 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  */
end_comment

begin_comment
comment|/* Definitions to make function prototypes manageable */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XFUNCPROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_XFUNCPROTO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NeedFunctionPrototypes
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FUNCPROTO
argument_list|)
operator|||
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|NeedFunctionPrototypes
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NeedFunctionPrototypes
value|0
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
comment|/* NeedFunctionPrototypes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NeedVarargsPrototypes
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
operator|||
operator|(
name|FUNCPROTO
operator|&
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|NeedVarargsPrototypes
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NeedVarargsPrototypes
value|0
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
comment|/* NeedVarargsPrototypes */
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|NeedNestedPrototypes
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
operator|||
operator|(
name|FUNCPROTO
operator|&
literal|8
operator|)
end_if

begin_define
define|#
directive|define
name|NeedNestedPrototypes
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NeedNestedPrototypes
value|0
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
comment|/* NeedNestedPrototypes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xconst
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
operator|||
operator|(
name|FUNCPROTO
operator|&
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|_Xconst
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Xconst
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
comment|/* _Xconst */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NeedWidePrototypes
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NARROWPROTO
end_ifdef

begin_define
define|#
directive|define
name|NeedWidePrototypes
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NeedWidePrototypes
value|1
end_define

begin_comment
comment|/* default to make interropt. easier */
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
comment|/* NeedWidePrototypes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeedFunctionPrototypes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XFUNCPROTOBEGIN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* for C++ V2.0 */
end_comment

begin_define
define|#
directive|define
name|_XFUNCPROTOBEGIN
value|extern "C" {
end_define

begin_comment
comment|/* do not leave open across includes */
end_comment

begin_define
define|#
directive|define
name|_XFUNCPROTOEND
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_XFUNCPROTOBEGIN
end_define

begin_define
define|#
directive|define
name|_XFUNCPROTOEND
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
comment|/* _XFUNCPROTOBEGIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XFUNCPROTO_H_ */
end_comment

end_unit

