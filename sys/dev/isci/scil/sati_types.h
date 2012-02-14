begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATI_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATI_TYPES_H_
end_define

begin_comment
comment|/**  * @file  * @brief This file contains various type definitions to be utilized with  *        SCSI to ATA Translation Implementation.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/types.h>
end_include

begin_comment
comment|/**  * @enum _SATI_STATUS  *  * @brief This enumeration defines the possible return values from the  *        SATI translation methods.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SATI_STATUS
block|{
comment|/**     * This indicates that the translation was supported and occurred     * without error.     */
name|SATI_SUCCESS
block|,
comment|/**     * This indicates that the translation was supported and occurred     * without error.     * Additionally, this indicates the translation actually already     * translated the scatter gather list elements appropriately as     * well.     */
name|SATI_SUCCESS_SGL_TRANSLATED
block|,
comment|/**     * This indicates that the translation was supported, occurred without     * error, and no additional translation is necessary.  This is done in     * conditions where the SCSI command doesn't require any interaction with     * the remote device.     */
name|SATI_COMPLETE
block|,
comment|/**    * This indicated everything SATI_COMPLETE does in addition to the response data      not using all the memory allocated by the OS.    */
name|SATI_COMPLETE_IO_DONE_EARLY
block|,
comment|/**     * This indicates that translator sequence has finished some specific     * command in the sequence, but additional commands are necessary.     */
name|SATI_SEQUENCE_INCOMPLETE
block|,
comment|/**     * This indicates a general failure has occurred for which no further     * specification information is available.     */
name|SATI_FAILURE
block|,
comment|/**     * This indicates that the result of the IO request indicates a     * failure.  The caller should reference the corresponding response     * data for further details.     */
name|SATI_FAILURE_CHECK_RESPONSE_DATA
block|,
comment|/**     * This status indicates that the supplied sequence type doesn't map     * to an existing definition.     */
name|SATI_FAILURE_INVALID_SEQUENCE_TYPE
block|,
comment|/**     * This status indicates that the supplied sequence state doesn't match     * the operation being requested by the user.     */
name|SATI_FAILURE_INVALID_STATE
block|}
name|SATI_STATUS
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|DISABLE_SATI_MODE_SENSE
argument_list|)
expr|\
operator|||
operator|!
name|defined
argument_list|(
name|DISABLE_SATI_MODE_SELECT
argument_list|)
expr|\
operator|||
operator|!
name|defined
argument_list|(
name|DISABLE_SATI_REQUEST_SENSE
argument_list|)
operator|)
expr|\
operator|#
expr|if
operator|!
name|defined
argument_list|(
name|ENABLE_SATI_MODE_PAGES
argument_list|)
end_if

begin_comment
comment|/**  * This macro enables the common mode page data structures and code.  * Currently, MODE SENSE, MODE SELECT, and REQUEST SENSE all make  * reference to this common code.  As a result, enable the common  * mode page code if any of these 3 are being translated.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_SATI_MODE_PAGES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(ENABLE_SATI_MODE_PAGES)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MODE_SENSE/SELECT/REQUEST_SENSE
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATI_TYPES_H_
end_comment

end_unit

