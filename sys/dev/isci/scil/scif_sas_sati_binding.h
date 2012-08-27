begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_SATI_BINDING_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_SATI_BINDING_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the SATI (SCSI to ATA Translation Implementation)  *        callback implementations that can be implemented by the SCI  *        Framework (or core in some cases).  */
end_comment

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
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/scif_user_callback.h>
include|#
directive|include
file|<dev/isci/scil/scif_io_request.h>
include|#
directive|include
file|<dev/isci/scil/scif_remote_device.h>
include|#
directive|include
file|<dev/isci/scil/scic_user_callback.h>
include|#
directive|include
file|<dev/isci/scil/scic_io_request.h>
include|#
directive|include
file|<dev/isci/scil/scic_remote_device.h>
comment|//#include<dev/isci/scil/scic_sds_request.h>
comment|//#include<dev/isci/scil/scu_task_context.h>
include|#
directive|include
file|<dev/isci/scil/sci_object.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_request.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_memory_descriptor_list.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_stp_remote_device.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_remote_device.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_domain.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_controller.h>
include|#
directive|include
file|<dev/isci/scil/scic_sds_request.h>
include|#
directive|include
file|<dev/isci/sci_environment.h>
comment|// SATI callbacks fulfilled by the framework user.
define|#
directive|define
name|sati_cb_get_data_byte
parameter_list|(
name|scsi_io
parameter_list|,
name|byte_offset
parameter_list|,
name|value
parameter_list|)
define|\
value|{                                                                             \    U8 * virtual_address = scif_cb_io_request_get_virtual_address_from_sgl(    \                              sci_object_get_association(scsi_io),(byte_offset)\                           );                                                  \    *(value) = *(virtual_address);                                             \ }
define|#
directive|define
name|sati_cb_set_data_byte
parameter_list|(
name|scsi_io
parameter_list|,
name|byte_offset
parameter_list|,
name|value
parameter_list|)
define|\
value|{                                                                             \    U8 * virtual_address = scif_cb_io_request_get_virtual_address_from_sgl(    \                              sci_object_get_association(scsi_io),(byte_offset)\                           );                                                  \    *(virtual_address) = value;                                                \ }
define|#
directive|define
name|sati_cb_get_cdb_address
parameter_list|(
name|scsi_io
parameter_list|)
define|\
value|scif_cb_io_request_get_cdb_address(sci_object_get_association(scsi_io))
define|#
directive|define
name|sati_cb_get_cdb_length
parameter_list|(
name|scsi_io
parameter_list|)
define|\
value|scif_cb_io_request_get_cdb_length(sci_object_get_association(scsi_io))
define|#
directive|define
name|sati_cb_get_data_direction
parameter_list|(
name|scsi_io
parameter_list|,
name|sati_data_direction
parameter_list|)
define|\
value|{                                                                             \    SCI_IO_REQUEST_DATA_DIRECTION sci_data_direction =                         \       scif_cb_io_request_get_data_direction(                                  \          sci_object_get_association(scsi_io)                                  \       );                                                                      \    if (sci_data_direction == SCI_IO_REQUEST_DATA_IN)                          \       *(sati_data_direction) = SATI_DATA_DIRECTION_IN;                        \    else if (sci_data_direction == SCI_IO_REQUEST_DATA_OUT)                    \       *(sati_data_direction) = SATI_DATA_DIRECTION_OUT;                       \    else if (sci_data_direction == SCI_IO_REQUEST_NO_DATA)                     \       *(sati_data_direction) = SATI_DATA_DIRECTION_NONE;                      \ }
define|#
directive|define
name|sati_cb_get_lun
parameter_list|(
name|scsi_io
parameter_list|)
define|\
value|scif_cb_io_request_get_lun(sci_object_get_association(scsi_io))
comment|// SATI callbacks fulfilled by the framework.
comment|/**  * This method implements the functionality necessary to fulfill the  * SCSI-to-ATA Translation requirements.  It ensures that the SAS  * address for the remote device associated with the supplied IO  * is written into the sas_address parameter.  * For more information on the parameters utilized in this method,  * please refer to sati_cb_device_get_sas_address().  */
define|#
directive|define
name|sati_cb_device_get_sas_address
parameter_list|(
name|scsi_io
parameter_list|,
name|sas_address
parameter_list|)
define|\
value|{                                                                          \    SCIF_SAS_REQUEST_T* fw_request = (SCIF_SAS_REQUEST_T*)scsi_io;          \    SCI_REMOTE_DEVICE_HANDLE_T scic_device                                  \       = scif_remote_device_get_scic_handle(fw_request->device);            \    scic_remote_device_get_sas_address(scic_device, sas_address);           \ }
define|#
directive|define
name|sati_cb_device_get_request_by_ncq_tag
parameter_list|(
name|scsi_io
parameter_list|,
name|ncq_tag
parameter_list|,
name|matching_req
parameter_list|)
define|\
value|{                                                                          \    SCIF_SAS_REQUEST_T* fw_request = (SCIF_SAS_REQUEST_T*)scsi_io;          \    SCIF_SAS_REMOTE_DEVICE_T* fw_device = fw_request->device;               \    matching_req = scif_sas_stp_remote_device_get_request_by_ncq_tag(fw_device, ncq_tag);  \ }
define|#
directive|define
name|sati_cb_io_request_complete
parameter_list|(
name|scsi_io
parameter_list|,
name|completion_status
parameter_list|)
define|\
value|{                                                                          \    SCIF_SAS_REQUEST_T* fw_request = (SCIF_SAS_REQUEST_T*)scsi_io;          \    SCIF_SAS_REMOTE_DEVICE_T* fw_device = fw_request->device;               \    SCIF_SAS_DOMAIN_T*  fw_domain = fw_device->domain;                      \    SCIF_SAS_CONTROLLER_T* fw_controller = fw_domain->controller;           \    scif_cb_io_request_complete(                                            \       fw_controller, fw_device, fw_request, completion_status              \    );                                                                      \ }
define|#
directive|define
name|sati_cb_get_response_iu_address
value|scif_io_request_get_response_iu_address
define|#
directive|define
name|sati_cb_get_task_function
value|scic_cb_ssp_task_request_get_function
define|#
directive|define
name|sati_cb_get_ata_data_address
parameter_list|(
name|the_ata_io
parameter_list|)
define|\
value|scic_io_request_get_rx_frame(                          \       scif_io_request_get_scic_handle((the_ata_io)), 0    \    )
define|#
directive|define
name|sati_cb_get_h2d_register_fis_address
parameter_list|(
name|the_ata_io
parameter_list|)
define|\
value|(U8*) scic_stp_io_request_get_h2d_reg_address(         \             scif_io_request_get_scic_handle((the_ata_io)) \          )
define|#
directive|define
name|sati_cb_get_d2h_register_fis_address
parameter_list|(
name|the_ata_io
parameter_list|)
define|\
value|(U8*) scic_stp_io_request_get_d2h_reg_address(         \             scif_io_request_get_scic_handle((the_ata_io)) \          )
define|#
directive|define
name|sati_cb_allocate_dma_buffer
parameter_list|(
name|scsi_io
parameter_list|,
name|length
parameter_list|,
name|virt_address
parameter_list|,
name|phys_address_low
parameter_list|,
name|phys_address_high
parameter_list|)
define|\
value|{                                                                 \    SCIF_SAS_REQUEST_T* fw_request = (SCIF_SAS_REQUEST_T*)scsi_io; \    SCI_PHYSICAL_MEMORY_DESCRIPTOR_T mde;                          \    mde.virtual_address = NULL;                                    \    sci_base_mde_construct(                                        \&mde, 4, length, SCI_MDE_ATTRIBUTE_PHYSICALLY_CONTIGUOUS    \    );                                                             \    scif_cb_controller_allocate_memory(                            \       fw_request->device->domain->controller,&mde                \    );                                                             \    *(virt_address)       = mde.virtual_address;                      \    *(phys_address_low)   = sci_cb_physical_address_lower(mde.physical_address); \    *(phys_address_high)  = sci_cb_physical_address_upper(mde.physical_address); \ }
define|#
directive|define
name|sati_cb_free_dma_buffer
parameter_list|(
name|scsi_io
parameter_list|,
name|virt_address
parameter_list|)
define|\
value|{                                                                 \    SCIF_SAS_REQUEST_T* fw_request = (SCIF_SAS_REQUEST_T*)scsi_io; \    SCI_PHYSICAL_MEMORY_DESCRIPTOR_T mde;                          \    mde.virtual_address = virt_address;                         \    sci_base_mde_construct(                                        \&mde, 4, 0, SCI_MDE_ATTRIBUTE_PHYSICALLY_CONTIGUOUS         \    );                                                             \    scif_cb_controller_free_memory(                                \       fw_request->device->domain->controller,&mde                \    );                                                             \ }
define|#
directive|define
name|sati_cb_sgl_next_sge
parameter_list|(
name|scsi_io
parameter_list|,
name|ata_io
parameter_list|,
name|current_sge
parameter_list|,
name|next_sge
parameter_list|)
define|\
value|{ \
comment|/* For now just 2 SGEs are supported. */
value|\    SCIC_SDS_REQUEST_T *scic_request; \    SCU_SGL_ELEMENT_PAIR_T *sgl_pair; \    scic_request = scif_io_request_get_scic_handle((scsi_io)); \    sgl_pair     = scic_sds_request_get_sgl_element_pair(scic_request, 0); \  \    if ((current_sge) == NULL) \    { \       *(next_sge) =&(sgl_pair->A); \    } \    else \    { \       *(next_sge) =&(sgl_pair->B); \    } \ }
define|#
directive|define
name|sati_cb_sge_write
parameter_list|(
name|current_sge
parameter_list|,
name|phys_address_low
parameter_list|,
name|phys_address_high
parameter_list|,
name|byte_length
parameter_list|)
define|\
value|{ \    SCU_SGL_ELEMENT_T * scu_sge = (SCU_SGL_ELEMENT_T*) (current_sge); \    scu_sge->address_upper      = (phys_address_high); \    scu_sge->address_lower      = (phys_address_low); \    scu_sge->length             = (byte_length); \    scu_sge->address_modifier   = 0; \ }
define|#
directive|define
name|sati_cb_do_translate_response
parameter_list|(
name|request
parameter_list|)
define|\
value|(request)->stp.sequence.is_translate_response_required
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCIF_SAS_SATI_BINDING_H_
end_comment

end_unit

