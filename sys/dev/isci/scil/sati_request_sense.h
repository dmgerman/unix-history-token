begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  * @brief This file contains the method definitions to translate  *        SCSI Request Sense command based of the SAT spec.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATI_REQUEST_SENSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATI_REQUEST_SENSE_H_
end_define

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_translator_sequence.h>
end_include

begin_function_decl
name|SATI_STATUS
name|sati_request_sense_translate_command
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|,
name|void
modifier|*
name|scsi_io
parameter_list|,
name|void
modifier|*
name|ata_io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SATI_STATUS
name|sati_request_sense_translate_response
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|,
name|void
modifier|*
name|scsi_io
parameter_list|,
name|void
modifier|*
name|ata_io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sati_request_sense_data_response_construct
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|,
name|void
modifier|*
name|scsi_io
parameter_list|,
name|U8
name|sense_key
parameter_list|,
name|U8
name|additional_sense_code
parameter_list|,
name|U8
name|additional_sense_code_qualifier
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATI_REQUEST_SENSE_H_
end_comment

end_unit

