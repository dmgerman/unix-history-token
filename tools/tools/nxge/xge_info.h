begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/******************************************  *  getinfo.h  *  *  To get the Tx, Rx, PCI, Interrupt statistics,  *  PCI configuration space,device configuration  *  and bar0 register values  ******************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_CMN_H
end_ifndef

begin_include
include|#
directive|include
file|"xge_cmn.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XGE_QUERY_STATS
value|1
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_PCICONF
value|2
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_INTRSTATS
value|3
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_DEVCONF
value|4
end_define

begin_define
define|#
directive|define
name|XGE_READ_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_TCODE
value|6
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_1
value|7
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_2
value|8
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_3
value|9
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_5
value|10
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_BUFFER_MODE
value|11
end_define

begin_comment
comment|/* Function declerations */
end_comment

begin_function_decl
name|int
name|getPciConf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getDevConf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getStats
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getRegInfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getIntrStats
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getTcodeStats
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getReadReg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getWriteReg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getDriverVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getBufMode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeBufMode
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logStats
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logPciConf
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logDevConf
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logRegInfo
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logReadReg
parameter_list|(
name|u64
parameter_list|,
name|u64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logIntrStats
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logTcodeStats
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logDriverInfo
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|xge_pci_bar0_t
name|regInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xge_pci_config_t
name|pciconfInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xge_stats_hw_info_t
name|statsInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xge_device_config_t
name|devconfInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xge_stats_intr_info_t
name|intrInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xge_stats_tcode_info_t
name|tcodeInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifreq
name|ifreqp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sockfd
decl_stmt|,
name|indexer
decl_stmt|,
name|bufferSize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pAccess
decl_stmt|;
end_decl_stmt

end_unit

