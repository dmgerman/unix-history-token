begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: varargs.h,v 1.7 2001/09/13 16:45:40 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm variable argument lists */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_VARARGS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_VARARGS_H
end_define

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
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_VA_STD
value|1
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|SM_VA_START
parameter_list|(
name|ap
parameter_list|,
name|f
parameter_list|)
value|va_start(ap, f)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|SM_VA_STD
value|0
end_define

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|SM_VA_START
parameter_list|(
name|ap
parameter_list|,
name|f
parameter_list|)
value|va_start(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|va_copy
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_VA_COPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|va_copy((dst), (src))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__va_copy
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SM_VA_COPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|__va_copy((dst), (src))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SM_VA_COPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|(dst) = (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  The following macros are useless, but are provided for symmetry. */
end_comment

begin_define
define|#
directive|define
name|SM_VA_LOCAL_DECL
value|va_list ap;
end_define

begin_define
define|#
directive|define
name|SM_VA_ARG
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|va_arg(ap, type)
end_define

begin_define
define|#
directive|define
name|SM_VA_END
parameter_list|(
name|ap
parameter_list|)
value|va_end(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_VARARGS_H */
end_comment

end_unit

