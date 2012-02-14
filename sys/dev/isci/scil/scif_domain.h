begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_DOMAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_DOMAIN_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the interface methods that can be called  *        by an SCI Framework user on the SAS/SATA domain object.  */
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
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/sci_status.h>
include|#
directive|include
file|<dev/isci/scil/intel_sas.h>
comment|/**  * @brief This method enables the framework user to find the SCI Core Port  *        object through which the supplied domain is accessed.  *  * @param[in]  domain This parameter specifies the framework domain object  *             for which to return the corresponding SCI Core port object.  *  * @return Return a handle to the SCI Core port through which the supplied  *         domain is accessed.  * @retval SCI_INVALID_HANDLE This value is returned if the core port  *         object can not be retrieved.  */
name|SCI_PORT_HANDLE_T
name|scif_domain_get_scic_port_handle
parameter_list|(
name|SCI_DOMAIN_HANDLE_T
name|domain
parameter_list|)
function_decl|;
comment|/**  * @brief This method will find and retreive the device associated with the  *        supplied SAS address if such a device exists.  *  * @param[in]  domain This parameter specifies the framework domain object  *             on which to discover devices.  * @param[in]  sas_address This parameter specifies the SAS address of the  *             object to locate in this domain.  *  * @return Indicate if the device was successfully found in the domain.  * @retval SCI_INVALID_HANDLE This value is returned if the device is not  *         found in the domain.  * @retval All other values indicate a valid remote device being found.  */
name|SCI_REMOTE_DEVICE_HANDLE_T
name|scif_domain_get_device_by_sas_address
parameter_list|(
name|SCI_DOMAIN_HANDLE_T
name|domain
parameter_list|,
name|SCI_SAS_ADDRESS_T
modifier|*
name|sas_address
parameter_list|)
function_decl|;
comment|/**  * @brief This method will attempt to discover the supplied domain.  *  * @warning This method must be synchronized with the controller completion  *          handler (see scic_controller_get_handler_methods()).  The user  *          may call this method from within the completion handler in which  *          case, no synchronization is necessary.  *  * @note  *        - IO requests from the OS driver are held off until discovery  *          of the domain is complete.  *        - Discovery may perform SSP or STP IO requests to configure  *          remote devices prior to informing the SCIF User of their  *          existence via the remote_device_ready user callback.  *  * @param[in]  domain This parameter specifies the framework domain object  *             on which to discover devices.  * @param[in]  discover_timeout This parameter specifies the number of  *             milliseconds in which the domain discovery operation should  *             complete.  * @param[in]  device_timeout This parameter specifies the number of  *             milliseconds in which the device configuration and/or reset  *             operations should complete.  Logically, the device_timeout  *             parameter should be shorter then the domain_timeout value.  *             Especially considering the domain could be made up of "n"  *             different devices.  *  * @return Indicate if the discover operation started successfully.  * @retval SCI_SUCCESS This value is returned if the discover operation  *         started successfully.  * @retval SCI_WARNING_TIMER_CONFLICT This value is returned if the SCI  *         implementation doesn't support the desired timeout amounts or if  *         the desired timeout amounts conflict in some manner.  */
name|SCI_STATUS
name|scif_domain_discover
parameter_list|(
name|SCI_DOMAIN_HANDLE_T
name|domain
parameter_list|,
name|U32
name|discover_timeout
parameter_list|,
name|U32
name|device_timeout
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_SCI_ITERATORS
argument_list|)
comment|/**  * @brief This method gets an iterator for the list of remote devices in the  *        specified domain.  *  * @param[in] domain: This parameter specifies the framework domain handle  * @param[in] iterator_buffer: This parameters specifies the memory buffer that  *            will be used to construct the iterator.  *  * @retval Handle to the remote device list iterator.  */
name|SCI_ITERATOR_HANDLE_T
name|scif_domain_get_remote_device_iterator
parameter_list|(
name|SCI_DOMAIN_HANDLE_T
name|domain
parameter_list|,
name|void
modifier|*
name|iterator_buffer
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_SCI_ITERATORS)
define|#
directive|define
name|scif_domain_get_remote_device_iterator
parameter_list|(
name|the_domain
parameter_list|,
name|the_buffer
parameter_list|)
define|\
value|SCI_INVALID_HANDLE
endif|#
directive|endif
comment|// !defined(DISABLE_SCI_ITERATORS)
comment|/**  * @brief This method simply returns a suggest timeout value for discovery.  *  * @param[in] domain The handle to the domain whose discover activity is to  *     be started.  *  * @return The suggested timeout value for domain discover in milli-seconds.  */
name|U32
name|scif_domain_get_suggested_discover_timeout
parameter_list|(
name|SCI_DOMAIN_HANDLE_T
name|domain
parameter_list|)
function_decl|;
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
comment|// _SCIF_DOMAIN_H_
end_comment

end_unit

