begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * #define for SAS intiator in SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ITD_GLOBALS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ITD_GLOBALS_H__
end_define

begin_comment
comment|/*   * Transport specific default parameters.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_NUM_DOMAINS
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_NUM_AREAS_PER_DOMAIN
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_DEVSLOTS_PER_AREA
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAX_TARGETS
value|256
end_define

begin_define
define|#
directive|define
name|DEFAULT_EVENT_LOG_ELEMENTS
value|64
end_define

begin_define
define|#
directive|define
name|DEFAULT_INI_TIMER_TICK
value|1000000
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TOTAL_DYNAMIC_MEM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ITD_GLOBALS_H__ */
end_comment

end_unit

