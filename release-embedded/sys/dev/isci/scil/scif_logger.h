begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_LOGGER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_LOGGER_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the SCI Framework specific logger object  *        constant definitions.  */
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
file|<dev/isci/scil/sci_logger.h>
comment|/* The following is a list of log objects for which log information can */
comment|/* be enabled or disabled.                                              */
comment|/** Enables/disables logging specific to the library. */
define|#
directive|define
name|SCIF_LOG_OBJECT_LIBRARY
value|0x00000001
comment|/** Enables/disables logging specific to the controller. */
define|#
directive|define
name|SCIF_LOG_OBJECT_CONTROLLER
value|0x00000002
comment|/** Enables/disables logging specific to the sas port. */
define|#
directive|define
name|SCIF_LOG_OBJECT_DOMAIN
value|0x00000004
comment|/** Enables/disables logging specific to the domain discovery process. */
define|#
directive|define
name|SCIF_LOG_OBJECT_DOMAIN_DISCOVERY
value|0x00000008
comment|/** Enables/disables logging specific to the remote devices. */
define|#
directive|define
name|SCIF_LOG_OBJECT_REMOTE_DEVICE
value|0x00000010
comment|/** Enables/disables logging specific to remote device configuration. */
define|#
directive|define
name|SCIF_LOG_OBJECT_REMOTE_DEVICE_CONFIG
value|0x00000020
comment|/** Enables/disables logging specific to performing task management. */
define|#
directive|define
name|SCIF_LOG_OBJECT_TASK_MANAGEMENT
value|0x00000040
comment|/** Enables/disables logging specific to SCSI to SATA command translation. */
define|#
directive|define
name|SCIF_LOG_OBJECT_COMMAND_TRANSLATION
value|0x00000080
comment|/** Enables/disables logging specific to SCSI to SATA response translation. */
define|#
directive|define
name|SCIF_LOG_OBJECT_RESPONSE_TRANSLATION
value|0x00000100
comment|/** Enables/disables logging specific to framework initialization. */
define|#
directive|define
name|SCIF_LOG_OBJECT_INITIALIZATION
value|0x00000200
comment|/** Enables/disables logging specific to framework shutdown. */
define|#
directive|define
name|SCIF_LOG_OBJECT_SHUTDOWN
value|0x00000400
comment|/** Enables/disables logging specific to all IO requests. */
define|#
directive|define
name|SCIF_LOG_OBJECT_IO_REQUEST
value|0x00000800
comment|/** Enables/disables logging specific to all IO requests. */
define|#
directive|define
name|SCIF_LOG_OBJECT_CONTROLLER_RESET
value|0x00001000
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
comment|// _SCIF_LOGGER_H_
end_comment

end_unit

