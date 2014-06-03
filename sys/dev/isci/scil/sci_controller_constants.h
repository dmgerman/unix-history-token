begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_CONTROLLER_CONSTANTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_CONTROLLER_CONSTANTS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/**  * @file  *  * @brief This file contains constant values that change based on the type  *        of core or framework being managed.  These constants are exported  *        in order to provide the user with information as to the bounds  *        (i.e. how many) of specific objects.  */
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
ifdef|#
directive|ifdef
name|SCIC_SDS_4_ENABLED
ifndef|#
directive|ifndef
name|SCI_MAX_PHYS
comment|/**  * This constant defines the maximum number of phy objects that can be  * supported for the SCU Driver Standard (SDS) library.  This is tied  * directly to silicon capabilities.  */
define|#
directive|define
name|SCI_MAX_PHYS
value|(4)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_PORTS
comment|/**  * This constant defines the maximum number of port objects that can be  * supported for the SCU Driver Standard (SDS) library.  This is tied  * directly to silicon capabilities.  */
define|#
directive|define
name|SCI_MAX_PORTS
value|SCI_MAX_PHYS
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MIN_SMP_PHYS
comment|/**  * This constant defines the minimum number of SMP phy objects that  * can be supported for a single expander level.  * This was determined by using 36 physical phys and room for 2 virtual  * phys.  */
define|#
directive|define
name|SCI_MIN_SMP_PHYS
value|(38)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_SMP_PHYS
comment|/**  * This constant defines the maximum number of SMP phy objects that  * can be supported for the SCU Driver Standard (SDS) library.  * This number can be increased if required.  */
define|#
directive|define
name|SCI_MAX_SMP_PHYS
value|(384)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_REMOTE_DEVICES
comment|/**  * This constant defines the maximum number of remote device objects that  * can be supported for the SCU Driver Standard (SDS) library.  This is tied  * directly to silicon capabilities.  */
define|#
directive|define
name|SCI_MAX_REMOTE_DEVICES
value|(256)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MIN_REMOTE_DEVICES
comment|/**  * This constant defines the minimum number of remote device objects that  * can be supported for the SCU Driver Standard (SDS) library.  This # can  * be configured for minimum memory environments to any value less than  * SCI_MAX_REMOTE_DEVICES  */
define|#
directive|define
name|SCI_MIN_REMOTE_DEVICES
value|(16)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_IO_REQUESTS
comment|/**  * This constant defines the maximum number of IO request objects that  * can be supported for the SCU Driver Standard (SDS) library.  This is tied  * directly to silicon capabilities.  */
define|#
directive|define
name|SCI_MAX_IO_REQUESTS
value|(256)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MIN_IO_REQUESTS
comment|/**  * This constant defines the minimum number of IO request objects that  * can be supported for the SCU Driver Standard (SDS) library.  This #  * can be configured for minimum memory environments to any value less  * than SCI_MAX_IO_REQUESTS.  */
define|#
directive|define
name|SCI_MIN_IO_REQUESTS
value|(1)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_SCATTER_GATHER_ELEMENTS
comment|/**  * This constant defines the maximum number of Scatter-Gather Elements  * to be used by any SCI component.  *  * Note: number of elements must be an even number, since descriptors  * posted to hardware always contain pairs of elements (with second  * element set to zeroes if not needed).  */
define|#
directive|define
name|__MAXPHYS_ELEMENTS
value|((MAXPHYS / PAGE_SIZE) + 1)
define|#
directive|define
name|SCI_MAX_SCATTER_GATHER_ELEMENTS
value|((__MAXPHYS_ELEMENTS + 1)& ~0x1)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MIN_SCATTER_GATHER_ELEMENTS
comment|/**  * This constant defines the minimum number of Scatter-Gather Elements  * to be used by any SCI component.  */
define|#
directive|define
name|SCI_MIN_SCATTER_GATHER_ELEMENTS
value|1
endif|#
directive|endif
else|#
directive|else
comment|// SCIC_SDS_4_ENABLED
error|#
directive|error
literal|"SCI Core configuration left unspecified (e.g. SCIC_SDS_4_ENABLED)"
endif|#
directive|endif
comment|// SCIC_SDS_4_ENABLED
comment|/**  * This constant defines the maximum number of PCI devices that can be supported  * by the driver.  */
define|#
directive|define
name|SCI_MAX_PCI_DEVICES
value|(2)
comment|/**  * This constant defines the maximum number of controllers that can  * occur in a single silicon package.  */
define|#
directive|define
name|SCI_MAX_CONTROLLERS_PER_PCI_DEVICE
value|(2)
comment|/**  * This constant defines the maximum number of controllers that can  * be supported by a library object.  The user specified maximum controller  * count must be less than or equal to this number.  This is a driver  * specific constant that is not tied to silicon capabilities.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SCI_MAX_CONTROLLERS
argument_list|)
define|#
directive|define
name|SCI_MAX_CONTROLLERS
value|(2)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SCI_MAX_MSIX_MESSAGES_PER_CONTROLLER
comment|/**  * This constant defines the maximum number of MSI-X interrupt vectors/messages  * supported for an SCU hardware controller instance.  */
define|#
directive|define
name|SCI_MAX_MSIX_MESSAGES_PER_CONTROLLER
value|(2)
endif|#
directive|endif
comment|/**  * This constant defines the maximum number of MSI-X interrupt vectors/messages  * supported for an SCU device.  */
define|#
directive|define
name|SCI_MAX_MSIX_MESSAGES
define|\
value|(SCI_MAX_MSIX_MESSAGES_PER_CONTROLLER * SCI_MAX_CONTROLLERS)
comment|/**  * The maximum number of supported domain objects is currently tied to the  * maximum number of support port objects.  */
define|#
directive|define
name|SCI_MAX_DOMAINS
value|SCI_MAX_PORTS
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
comment|// _SCI_CONTROLLER_CONSTANTS_H_
end_comment

end_unit

