begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xlocale.h,v 1.8 91/04/10 10:41:17 rws Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLOCALE_H_
end_ifndef

begin_define
define|#
directive|define
name|_XLOCALE_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|X_LOCALE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|X_NOT_STDC_ENV
end_ifdef

begin_define
define|#
directive|define
name|X_LOCALE
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
name|X_LOCALE
end_ifndef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LC_ALL
value|0
end_define

begin_define
define|#
directive|define
name|LC_COLLATE
value|1
end_define

begin_define
define|#
directive|define
name|LC_CTYPE
value|2
end_define

begin_define
define|#
directive|define
name|LC_MONETARY
value|3
end_define

begin_define
define|#
directive|define
name|LC_NUMERIC
value|4
end_define

begin_define
define|#
directive|define
name|LC_TIME
value|5
end_define

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|char
modifier|*
name|_Xsetlocale
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* category */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_define
define|#
directive|define
name|setlocale
value|_Xsetlocale
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
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
comment|/* X_LOCALE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XLOCALE_H_ */
end_comment

end_unit

