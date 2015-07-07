begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_define
define|#
directive|define
name|LINUX_PERBI_SUPPORT
end_define

begin_define
define|#
directive|define
name|HIALEAH_ENCRYPTION
end_define

begin_define
define|#
directive|define
name|HOTPLUG_SUPPORT
end_define

begin_define
define|#
directive|define
name|AG_CPU_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|INITIATOR_DRIVER
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SA
end_define

begin_define
define|#
directive|define
name|AGTIAPI_EVENT_LOG
end_define

begin_comment
comment|// #define	AGTIAPI_DPC
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_SA
end_define

begin_define
define|#
directive|define
name|PMC_SPC
end_define

begin_define
define|#
directive|define
name|SPC_MSIX_INTR
end_define

begin_define
define|#
directive|define
name|SPC_INT_ENABLE
end_define

begin_define
define|#
directive|define
name|AGTIAPI_LOCAL_LOCK
end_define

begin_define
define|#
directive|define
name|AGTIAPI_LOCAL_RESET
end_define

begin_define
define|#
directive|define
name|MU_I2O_DISABLE
end_define

begin_define
define|#
directive|define
name|HOST_SAST_ENABLE
end_define

begin_define
define|#
directive|define
name|HOST_PM2_ENABLE
end_define

begin_define
define|#
directive|define
name|TD_DISCOVER
end_define

begin_define
define|#
directive|define
name|SA_ENABLE_HDA_FUNCTIONS
end_define

begin_comment
comment|// #define	SA_FW_TEST_INTERRUPT_REASSERT
end_comment

begin_define
define|#
directive|define
name|SALLSDK_DEBUG
end_define

begin_define
define|#
directive|define
name|AGTIAPI_DEBUG
end_define

begin_comment
comment|// #define	TD_DEBUG_ENABLE
end_comment

begin_comment
comment|// #define	AGTIAPI_IO_DEBUG
end_comment

begin_comment
comment|// #define	AGTIAPI_FLOW_DEBUG
end_comment

begin_comment
comment|// #define	AGTIAPI_INIT_DEBUG
end_comment

begin_define
define|#
directive|define
name|PMC_PM8001_BAR64KB
end_define

begin_define
define|#
directive|define
name|DM_DEBUG
end_define

begin_define
define|#
directive|define
name|FDS_DM
end_define

begin_define
define|#
directive|define
name|SM_DEBUG
end_define

begin_define
define|#
directive|define
name|FDS_SM
end_define

begin_define
define|#
directive|define
name|SATA_ENABLE
end_define

begin_define
define|#
directive|define
name|CHAR_DEVICE
end_define

begin_define
define|#
directive|define
name|TD_4GB_WORKAROUND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

