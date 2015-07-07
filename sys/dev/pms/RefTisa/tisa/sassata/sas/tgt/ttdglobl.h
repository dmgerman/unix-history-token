begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * $RCSfile: ttdglobl.h,v $  *  * Copyright 2006 PMC-Sierra, Inc.  *  * $Author: vempatin $  * $Revision: 113679 $  * $Date: 2012-04-16 14:35:19 -0700 (Mon, 16 Apr 2012) $  *  * #define for SAS target in SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TTD_GLOBALS_H__
end_ifndef

begin_define
define|#
directive|define
name|__TTD_GLOBALS_H__
end_define

begin_comment
comment|/*   * Transport Target specific default parameters.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_XCHGS
value|256
end_define

begin_define
define|#
directive|define
name|DEFAULT_TGT_TIMER_TICK
value|1000000
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAX_TARGETS
value|256
end_define

begin_define
define|#
directive|define
name|DEFAULT_BLOCK_SIZE
value|512
end_define

begin_comment
comment|/* Exchange field accessors */
end_comment

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT
parameter_list|(
name|ti_root
parameter_list|)
value|(&TD_GET_TITGT_CONTEXT(ti_root)->ttdsaXchgData)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_MAX_NUM_XCHGS
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->maxNumXchgs)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_USED
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noUsed)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_FREED
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noFreed)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_CMD_RCVD
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noCmdRcvd)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_START_IO
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noStartIo)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_SEND_RSP
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noSendRsp)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_CONTEXT_NO_IO_COMPLETED
parameter_list|(
name|ti_root
parameter_list|)
value|(TD_XCHG_CONTEXT(ti_root)->noCompleted)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_GET_CONTEXT
parameter_list|(
name|ti_request
parameter_list|)
value|((ttdsaXchg_t *)(ti_request)->tdData)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_GET_STATE
parameter_list|(
name|xchg
parameter_list|)
value|(xchg->state)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_SET_STATE
parameter_list|(
name|xchg
parameter_list|,
name|val
parameter_list|)
value|(xchg->state) = (val)
end_define

begin_define
define|#
directive|define
name|TD_XCHG_STATE_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|TD_XCHG_STATE_INACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|READ_GOOD_RESPONSE
value|0x1
end_define

begin_define
define|#
directive|define
name|WRITE_GOOD_RESPONSE
value|0x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TTD_GLOBALS_H__ */
end_comment

end_unit

