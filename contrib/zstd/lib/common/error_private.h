begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/* Note : this module is expected to remain private, do not expose it */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ERROR_H_MODULE
end_ifndef

begin_define
define|#
directive|define
name|ERROR_H_MODULE
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* **************************************** *  Dependencies ******************************************/
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
include|#
directive|include
file|"zstd_errors.h"
comment|/* enum list */
comment|/* **************************************** *  Compiler-specific ******************************************/
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
define|#
directive|define
name|ERR_STATIC
value|static __attribute__((unused))
elif|#
directive|elif
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
operator|(
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|)
comment|/* C99 */
operator|)
define|#
directive|define
name|ERR_STATIC
value|static inline
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
define|#
directive|define
name|ERR_STATIC
value|static __inline
else|#
directive|else
define|#
directive|define
name|ERR_STATIC
value|static
comment|/* this version may generate warnings for unused static functions; disable the relevant warning */
endif|#
directive|endif
comment|/*-**************************************** *  Customization (error_public.h) ******************************************/
typedef|typedef
name|ZSTD_ErrorCode
name|ERR_enum
typedef|;
define|#
directive|define
name|PREFIX
parameter_list|(
name|name
parameter_list|)
value|ZSTD_error_##name
comment|/*-**************************************** *  Error codes handling ******************************************/
ifdef|#
directive|ifdef
name|ERROR
undef|#
directive|undef
name|ERROR
comment|/* reported already defined on VS 2015 (Rich Geldreich) */
endif|#
directive|endif
define|#
directive|define
name|ERROR
parameter_list|(
name|name
parameter_list|)
value|((size_t)-PREFIX(name))
name|ERR_STATIC
name|unsigned
name|ERR_isError
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
return|return
operator|(
name|code
operator|>
name|ERROR
argument_list|(
name|maxCode
argument_list|)
operator|)
return|;
block|}
name|ERR_STATIC
name|ERR_enum
name|ERR_getErrorCode
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ERR_isError
argument_list|(
name|code
argument_list|)
condition|)
return|return
operator|(
name|ERR_enum
operator|)
literal|0
return|;
return|return
call|(
name|ERR_enum
call|)
argument_list|(
literal|0
operator|-
name|code
argument_list|)
return|;
block|}
comment|/*-**************************************** *  Error Strings ******************************************/
specifier|const
name|char
modifier|*
name|ERR_getErrorString
parameter_list|(
name|ERR_enum
name|code
parameter_list|)
function_decl|;
comment|/* error_private.c */
name|ERR_STATIC
specifier|const
name|char
modifier|*
name|ERR_getErrorName
parameter_list|(
name|size_t
name|code
parameter_list|)
block|{
return|return
name|ERR_getErrorString
argument_list|(
name|ERR_getErrorCode
argument_list|(
name|code
argument_list|)
argument_list|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR_H_MODULE */
end_comment

end_unit

