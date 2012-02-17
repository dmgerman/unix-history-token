begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATI_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATI_H_
end_define

begin_comment
comment|/**  * @file  * @brief This file contains all of the interface methods, macros, structures  *        that can be utilized by a user to perform SCSI-to-ATA Translation.  *        SATI adheres to the www.t10.org SAT specification.  *  * For specific compliance information please refer to:  * - sati_get_sat_compliance_version() and  * - sati_get_sat_compliance_version_revision()  *  * For situations where compliance is not observed, the SATI will  * return an error indication (most likely INVALID FIELD IN CDB sense).  */
end_comment

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

begin_comment
comment|/**  * @brief This method will be called by the core to indicate the start of a  *        new translation sequence.  Set up the initial sequence state.  *  * @return None  */
end_comment

begin_function_decl
name|void
name|sati_sequence_construct
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief This method will be called by the core to request the current translation  *        sequence be terminated.  *  * @param[in]  sequence This parameter specifies the sequence  *             data associated with the translation.  * @param[in,out] scsi_io This parameter specifies the user's SCSI IO request  *                object.  SATI expects that the user can access the SCSI CDB,  *                response, and data from this pointer.  For example, if there  *                is a failure in translation resulting in sense data, then  *                SATI will call sati_cb_set_status() and pass the scsi_io  *                pointer as a parameter.  * @param[out] ata_io This parameter specifies the location of the  *             ATA register FIS into which the translator can write the  *             resultant ATA command if translation is successful.  This  *             parameter is passed back to the user through the  *             SATI_SATA_CALLBACKS when it is necessary to write fields  *             in the ata_io.  *  * @return None  */
end_comment

begin_function_decl
name|void
name|sati_sequence_terminate
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

begin_comment
comment|/**  * @brief This method translates the supplied SCSI command into a  *        corresponding ATA command.  *  * @param[in]  sequence This parameter specifies the sequence  *             data associated with the translation.  * @param[in]  sati_device This parameter specifies the remote device  *             for which the translated request is destined.  * @param[in,out] scsi_io This parameter specifies the user's SCSI IO request  *                object.  SATI expects that the user can access the SCSI CDB,  *                response, and data from this pointer.  For example, if there  *                is a failure in translation resulting in sense data, then  *                SATI will call sati_cb_set_status() and pass the scsi_io  *                pointer as a parameter.  * @param[out] ata_io This parameter specifies the location of the  *             ATA register FIS into which the translator can write the  *             resultant ATA command if translation is successful.  This  *             parameter is passed back to the user through the  *             SATI_SATA_CALLBACKS when it is necessary to write fields  *             in the ata_io.  *  * @return Indicate if the translation was successful.  * @retval SATI_SUCCESS  * @retval SATI_FAILURE_CHECK_RESPONSE_DATA  */
end_comment

begin_function_decl
name|SATI_STATUS
name|sati_translate_command
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|,
name|SATI_DEVICE_T
modifier|*
name|sati_device
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

begin_comment
comment|/**  * @brief This method translates the supplied SCSI task management request  *        into a corresponding ATA command/control FIS.  *  * @param[in]  sequence This parameter specifies the sequence  *             data associated with the translation.  * @param[in]  sati_device This parameter specifies the remote device  *             for which the translated request is destined.  * @param[in,out] scsi_io This parameter specifies the user's SCSI IO request  *                object.  SATI expects that the user can access the SCSI CDB,  *                response, and data from this pointer.  For example, if there  *                is a failure in translation resulting in sense data, then  *                SATI will call sati_cb_set_status() and pass the scsi_io  *                pointer as a parameter.  * @param[out] ata_io This parameter specifies the location of the  *             ATA register FIS into which the translator can write the  *             resultant ATA command if translation is successful.  This  *             parameter is passed back to the user through the  *             SATI_SATA_CALLBACKS when it is necessary to write fields  *             in the ata_io.  *  * @return Indicate if the translation was successful.  * @retval SATI_SUCCESS  * @retval SATI_FAILURE_CHECK_RESPONSE_DATA  */
end_comment

begin_function_decl
name|SATI_STATUS
name|sati_translate_task_management
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|,
name|SATI_DEVICE_T
modifier|*
name|sati_device
parameter_list|,
name|void
modifier|*
name|scsi_task
parameter_list|,
name|void
modifier|*
name|ata_io
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief This method translates the supplied ATA response into the  *        corresponding SCSI command response.  *  * @param[in]  sequence This parameter specifies the sequence  *             data associated with the translation.  * @param[out] scsi_io This parameter specifies the user's SCSI IO request  *             object.  SATI expects that the user can access the SCSI CDB,  *             response, and data from this pointer.  For example, if there  *             is a failure in translation resulting in sense data, then  *             SATI will call sati_cb_set_status() and pass the scsi_io  *             pointer as a parameter.  * @param[out] ata_io This parameter specifies the location of the  *             ATA IO request (e.g. register FIS, PIO Setup etc.) from which  *             the translator can read the received ATA status and error  *             fields.  *  * @return Indicate if the translation was successful.  * @retval SATI_SUCCESS  * @retval SATI_FAILURE_CHECK_RESPONSE_DATA  */
end_comment

begin_function_decl
name|SATI_STATUS
name|sati_translate_command_response
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

begin_comment
comment|/**  * @brief This method translates the supplied ATA response into the  *        corresponding SCSI task response.  *  * @param[in]  sequence This parameter specifies the sequence  *             data associated with the translation.  * @param[out] scsi_io This parameter specifies the user's SCSI IO request  *             object.  SATI expects that the user can access the SCSI CDB,  *             response, and data from this pointer.  For example, if there  *             is a failure in translation resulting in sense data, then  *             SATI will call sati_cb_set_status() and pass the scsi_io  *             pointer as a parameter.  * @param[out] ata_io This parameter specifies the location of the  *             ATA IO request (e.g. register FIS, PIO Setup etc.) from which  *             the translator can read the received ATA status and error  *             fields.  *  * @return Indicate if the translation was successful.  * @retval SATI_FAILURE_CHECK_RESPONSE_DATA  */
end_comment

begin_function_decl
name|SATI_STATUS
name|sati_translate_task_response
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

begin_comment
comment|/**  * @brief This method simply returns the SAT major compliance version number  *        for which the implementation is compliant.  *  * @return Return the specification identifier with which this translator  *         is compliant.  */
end_comment

begin_function_decl
name|U32
name|sati_get_sat_compliance_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief This method simply returns the SAT version revision identifier  *        for which the implementation is compliant.  *  * @return Return the specification revision identifier with which this  *         translator is compliant.  */
end_comment

begin_function_decl
name|U32
name|sati_get_sat_compliance_version_revision
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief This method returns the number of data bytes written *        by the translation sequence. * * @param[in] sequence This parameter specifies the sequence data *            associated with the translation. * * @return Return the U16 number_data_bytes_set in the *         SATI_TRANSLATOR_SEQUENCE. */
end_comment

begin_function_decl
name|U16
name|sati_get_number_data_bytes_set
parameter_list|(
name|SATI_TRANSLATOR_SEQUENCE_T
modifier|*
name|sequence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sati_translate_error
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
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATI_H_
end_comment

end_unit

