begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_XLATE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_XLATE_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/**  * @file apr_xlate.h  * @brief APR I18N translation library  */
comment|/**  * @defgroup APR_XLATE I18N translation library  * @ingroup APR  * @{  */
comment|/** Opaque translation buffer */
typedef|typedef
name|struct
name|apr_xlate_t
name|apr_xlate_t
typedef|;
comment|/**  * Set up for converting text from one charset to another.  * @param convset The handle to be filled in by this function  * @param topage The name of the target charset  * @param frompage The name of the source charset  * @param pool The pool to use  * @remark  *  Specify APR_DEFAULT_CHARSET for one of the charset  *  names to indicate the charset of the source code at  *  compile time.  This is useful if there are literal  *  strings in the source code which must be translated  *  according to the charset of the source code.  *  APR_DEFAULT_CHARSET is not useful if the source code  *  of the caller was not encoded in the same charset as  *  APR at compile time.  *  * @remark  *  Specify APR_LOCALE_CHARSET for one of the charset  *  names to indicate the charset of the current locale.  *  * @remark  *  Return APR_EINVAL if unable to procure a convset, or APR_ENOTIMPL  *  if charset transcoding is not available in this instance of  *  apr-util at all (i.e., APR_HAS_XLATE is undefined).  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xlate_open
argument_list|(
name|apr_xlate_t
operator|*
operator|*
name|convset
argument_list|,
specifier|const
name|char
operator|*
name|topage
argument_list|,
specifier|const
name|char
operator|*
name|frompage
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**   * This is to indicate the charset of the sourcecode at compile time  * names to indicate the charset of the source code at  * compile time.  This is useful if there are literal  * strings in the source code which must be translated  * according to the charset of the source code.  */
define|#
directive|define
name|APR_DEFAULT_CHARSET
value|(const char *)0
comment|/**  * To indicate charset names of the current locale   */
define|#
directive|define
name|APR_LOCALE_CHARSET
value|(const char *)1
comment|/**  * Find out whether or not the specified conversion is single-byte-only.  * @param convset The handle allocated by apr_xlate_open, specifying the   *                parameters of conversion  * @param onoff Output: whether or not the conversion is single-byte-only  * @remark  *  Return APR_ENOTIMPL if charset transcoding is not available  *  in this instance of apr-util (i.e., APR_HAS_XLATE is undefined).  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xlate_sb_get
argument_list|(
name|apr_xlate_t
operator|*
name|convset
argument_list|,
name|int
operator|*
name|onoff
argument_list|)
expr_stmt|;
comment|/**  * Convert a buffer of text from one codepage to another.  * @param convset The handle allocated by apr_xlate_open, specifying   *                the parameters of conversion  * @param inbuf The address of the source buffer  * @param inbytes_left Input: the amount of input data to be translated  *                     Output: the amount of input data not yet translated      * @param outbuf The address of the destination buffer  * @param outbytes_left Input: the size of the output buffer  *                      Output: the amount of the output buffer not yet used  * @remark  * Returns APR_ENOTIMPL if charset transcoding is not available  * in this instance of apr-util (i.e., APR_HAS_XLATE is undefined).  * Returns APR_INCOMPLETE if the input buffer ends in an incomplete  * multi-byte character.  *  * To correctly terminate the output buffer for some multi-byte  * character set encodings, a final call must be made to this function  * after the complete input string has been converted, passing  * the inbuf and inbytes_left parameters as NULL.  (Note that this  * mode only works from version 1.1.0 onwards)  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xlate_conv_buffer
argument_list|(
name|apr_xlate_t
operator|*
name|convset
argument_list|,
specifier|const
name|char
operator|*
name|inbuf
argument_list|,
name|apr_size_t
operator|*
name|inbytes_left
argument_list|,
name|char
operator|*
name|outbuf
argument_list|,
name|apr_size_t
operator|*
name|outbytes_left
argument_list|)
expr_stmt|;
comment|/* @see apr_file_io.h the comment in apr_file_io.h about this hack */
ifdef|#
directive|ifdef
name|APR_NOT_DONE_YET
comment|/**  * The purpose of apr_xlate_conv_char is to translate one character  * at a time.  This needs to be written carefully so that it works  * with double-byte character sets.   * @param convset The handle allocated by apr_xlate_open, specifying the  *                parameters of conversion  * @param inchar The character to convert  * @param outchar The converted character  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xlate_conv_char
argument_list|(
argument|apr_xlate_t *convset
argument_list|,
argument|char inchar
argument_list|,
argument|char outchar
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/**  * Convert a single-byte character from one charset to another.  * @param convset The handle allocated by apr_xlate_open, specifying the   *                parameters of conversion  * @param inchar The single-byte character to convert.  * @warning This only works when converting between single-byte character sets.  *          -1 will be returned if the conversion can't be performed.  */
name|APU_DECLARE
argument_list|(
argument|apr_int32_t
argument_list|)
name|apr_xlate_conv_byte
argument_list|(
argument|apr_xlate_t *convset
argument_list|,
argument|unsigned char inchar
argument_list|)
empty_stmt|;
comment|/**  * Close a codepage translation handle.  * @param convset The codepage translation handle to close  * @remark  *  Return APR_ENOTIMPL if charset transcoding is not available  *  in this instance of apr-util (i.e., APR_HAS_XLATE is undefined).  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xlate_close
argument_list|(
name|apr_xlate_t
operator|*
name|convset
argument_list|)
expr_stmt|;
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
comment|/* ! APR_XLATE_H */
end_comment

end_unit

