begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* ** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  *  * #define for SAS intiator in SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ITDDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ITDDEFS_H__
end_define

begin_comment
comment|/* discovery related state */
end_comment

begin_define
define|#
directive|define
name|ITD_DSTATE_NOT_STARTED
value|0
end_define

begin_define
define|#
directive|define
name|ITD_DSTATE_STARTED
value|1
end_define

begin_define
define|#
directive|define
name|ITD_DSTATE_COMPLETED
value|2
end_define

begin_comment
comment|/* SAS/SATA discovery status */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_NOT_START
value|0
end_define

begin_comment
comment|/**< status indicates discovery not started */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_UP_STREAM
value|1
end_define

begin_comment
comment|/**< status indicates discover upstream */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_DOWN_STREAM
value|2
end_define

begin_comment
comment|/**< status indicates discover downstream */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_CONFIG_ROUTING
value|3
end_define

begin_comment
comment|/**< status indicates discovery config routing table */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_SAS_DONE
value|4
end_define

begin_comment
comment|/**< status indicates discovery done */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_REPORT_PHY_SATA
value|5
end_define

begin_comment
comment|/**< status indicates discovery report phy sata */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ITDDEFS_H__ */
end_comment

end_unit

