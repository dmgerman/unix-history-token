begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * @file  * @brief This file contains the method implementations for translating  *        the SCSI SYNCHRONIZE_CACHE (10, 16-byte) commands.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_SATI_SYNCHRONIZE_CACHE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_synchronize_cache.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_callbacks.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_util.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_translator_sequence.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/intel_ata.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/intel_scsi.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/intel_sat.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* P R I V A T E   M E T H O D S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method performs the SCSI SYNCHRONIZE_CACHE 10 and 16 command translation  *        functionality common to all SYNCHRONIZE_CACHE command sizes.  *        This includes:  *        - setting the command register  *        - setting the device head register  *        - filling in fields in the SATI_TRANSLATOR_SEQUENCE object.  *        For more information on the parameters passed to this method,  *        please reference sati_translate_command().  *  * @return Indicate if the method was successfully completed.  * @retval SATI_SUCCESS This is returned in all other cases.  */
end_comment

begin_function
name|SATI_STATUS
name|sati_synchronize_cache_translate_command
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
block|{
name|U8
modifier|*
name|cdb
init|=
name|sati_cb_get_cdb_address
argument_list|(
name|scsi_io
argument_list|)
decl_stmt|;
name|U8
modifier|*
name|register_fis
init|=
name|sati_cb_get_h2d_register_fis_address
argument_list|(
name|ata_io
argument_list|)
decl_stmt|;
name|sequence
operator|->
name|type
operator|=
name|SATI_SEQUENCE_SYNCHRONIZE_CACHE
expr_stmt|;
name|sequence
operator|->
name|protocol
operator|=
name|SAT_PROTOCOL_NON_DATA
expr_stmt|;
name|sequence
operator|->
name|data_direction
operator|=
name|SATI_DATA_DIRECTION_NONE
expr_stmt|;
if|if
condition|(
name|sati_get_cdb_byte
argument_list|(
name|cdb
argument_list|,
literal|1
argument_list|)
operator|&
name|SCSI_SYNCHRONIZE_CACHE_IMMED_ENABLED
condition|)
block|{
comment|//currently we ignore immed bit.
empty_stmt|;
block|}
comment|// Ensure the device supports the 48 bit feature set.
if|if
condition|(
name|sequence
operator|->
name|device
operator|->
name|capabilities
operator|&
name|SATI_DEVICE_CAP_48BIT_ENABLE
condition|)
name|sati_set_ata_command
argument_list|(
name|register_fis
argument_list|,
name|ATA_FLUSH_CACHE_EXT
argument_list|)
expr_stmt|;
else|else
name|sati_set_ata_command
argument_list|(
name|register_fis
argument_list|,
name|ATA_FLUSH_CACHE
argument_list|)
expr_stmt|;
return|return
name|SATI_SUCCESS
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(DISABLE_SATI_SYNCHRONIZE_CACHE)
end_comment

end_unit

