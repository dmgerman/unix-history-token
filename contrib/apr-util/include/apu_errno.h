begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|APU_ERRNO_H
end_define

begin_comment
comment|/**  * @file apu_errno.h  * @brief APR-Util Error Codes  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/**  * @defgroup apu_errno Error Codes  * @ingroup APR_Util  * @{  */
comment|/**  * @defgroup APR_Util_Error APR_Util Error Values  *<PRE>  *<b>APU ERROR VALUES</b>  * APR_ENOKEY         The key provided was empty or NULL  * APR_ENOIV          The initialisation vector provided was NULL  * APR_EKEYTYPE       The key type was not recognised  * APR_ENOSPACE       The buffer supplied was not big enough  * APR_ECRYPT         An error occurred while encrypting or decrypting  * APR_EPADDING       Padding was not supported  * APR_EKEYLENGTH     The key length was incorrect  * APR_ENOCIPHER      The cipher provided was not recognised  * APR_ENODIGEST      The digest provided was not recognised  * APR_ENOENGINE      The engine provided was not recognised  * APR_EINITENGINE    The engine could not be initialised  * APR_EREINIT        Underlying crypto has already been initialised  *</PRE>  *  *<PRE>  *<b>APR STATUS VALUES</b>  * APR_INCHILD        Program is currently executing in the child  *</PRE>  * @{  */
comment|/** @see APR_STATUS_IS_ENOKEY */
define|#
directive|define
name|APR_ENOKEY
value|(APR_UTIL_START_STATUS + 1)
comment|/** @see APR_STATUS_IS_ENOIV */
define|#
directive|define
name|APR_ENOIV
value|(APR_UTIL_START_STATUS + 2)
comment|/** @see APR_STATUS_IS_EKEYTYPE */
define|#
directive|define
name|APR_EKEYTYPE
value|(APR_UTIL_START_STATUS + 3)
comment|/** @see APR_STATUS_IS_ENOSPACE */
define|#
directive|define
name|APR_ENOSPACE
value|(APR_UTIL_START_STATUS + 4)
comment|/** @see APR_STATUS_IS_ECRYPT */
define|#
directive|define
name|APR_ECRYPT
value|(APR_UTIL_START_STATUS + 5)
comment|/** @see APR_STATUS_IS_EPADDING */
define|#
directive|define
name|APR_EPADDING
value|(APR_UTIL_START_STATUS + 6)
comment|/** @see APR_STATUS_IS_EKEYLENGTH */
define|#
directive|define
name|APR_EKEYLENGTH
value|(APR_UTIL_START_STATUS + 7)
comment|/** @see APR_STATUS_IS_ENOCIPHER */
define|#
directive|define
name|APR_ENOCIPHER
value|(APR_UTIL_START_STATUS + 8)
comment|/** @see APR_STATUS_IS_ENODIGEST */
define|#
directive|define
name|APR_ENODIGEST
value|(APR_UTIL_START_STATUS + 9)
comment|/** @see APR_STATUS_IS_ENOENGINE */
define|#
directive|define
name|APR_ENOENGINE
value|(APR_UTIL_START_STATUS + 10)
comment|/** @see APR_STATUS_IS_EINITENGINE */
define|#
directive|define
name|APR_EINITENGINE
value|(APR_UTIL_START_STATUS + 11)
comment|/** @see APR_STATUS_IS_EREINIT */
define|#
directive|define
name|APR_EREINIT
value|(APR_UTIL_START_STATUS + 12)
comment|/** @} */
comment|/**  * @defgroup APU_STATUS_IS Status Value Tests  * @warning For any particular error condition, more than one of these tests  *      may match. This is because platform-specific error codes may not  *      always match the semantics of the POSIX codes these tests (and the  *      corresponding APR error codes) are named after. A notable example  *      are the APR_STATUS_IS_ENOENT and APR_STATUS_IS_ENOTDIR tests on  *      Win32 platforms. The programmer should always be aware of this and  *      adjust the order of the tests accordingly.  * @{  */
comment|/** @} */
comment|/**  * @addtogroup APR_Util_Error  * @{  */
comment|/**  * The key was empty or not provided  */
define|#
directive|define
name|APR_STATUS_IS_ENOKEY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOKEY)
comment|/**  * The initialisation vector was not provided  */
define|#
directive|define
name|APR_STATUS_IS_ENOIV
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOIV)
comment|/**  * The key type was not recognised  */
define|#
directive|define
name|APR_STATUS_IS_EKEYTYPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EKEYTYPE)
comment|/**  * The buffer provided was not big enough  */
define|#
directive|define
name|APR_STATUS_IS_ENOSPACE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPACE)
comment|/**  * An error occurred while encrypting or decrypting  */
define|#
directive|define
name|APR_STATUS_IS_ECRYPT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECRYPT)
comment|/**  * An error occurred while padding  */
define|#
directive|define
name|APR_STATUS_IS_EPADDING
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPADDING)
comment|/**  * An error occurred with the key length  */
define|#
directive|define
name|APR_STATUS_IS_EKEYLENGTH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EKEYLENGTH)
comment|/**  * The cipher provided was not recognised  */
define|#
directive|define
name|APR_STATUS_IS_ENOCIPHER
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOCIPHER)
comment|/**  * The digest provided was not recognised  */
define|#
directive|define
name|APR_STATUS_IS_ENODIGEST
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENODIGEST)
comment|/**  * The engine provided was not recognised  */
define|#
directive|define
name|APR_STATUS_IS_ENOENGINE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENGINE)
comment|/**  * The engine could not be initialised  */
define|#
directive|define
name|APR_STATUS_IS_EINITENGINE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINITENGINE)
comment|/**  * Crypto has already been initialised  */
define|#
directive|define
name|APR_STATUS_IS_EREINIT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EREINIT)
comment|/** @} */
comment|/**  * This structure allows the underlying API error codes to be returned  * along with plain text error messages that explain to us mere mortals  * what really happened.  */
typedef|typedef
struct|struct
name|apu_err_t
block|{
specifier|const
name|char
modifier|*
name|reason
decl_stmt|;
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
name|int
name|rc
decl_stmt|;
block|}
name|apu_err_t
typedef|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
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
comment|/* ! APU_ERRNO_H */
end_comment

end_unit

