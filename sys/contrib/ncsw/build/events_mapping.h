begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENTS_MAPPING_H_
end_ifndef

begin_define
define|#
directive|define
name|EVENTS_MAPPING_H_
end_define

begin_define
define|#
directive|define
name|EV_RX_DISCARD_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_define
define|#
directive|define
name|EV_RX_ERROR_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_define
define|#
directive|define
name|EV_TX_ERROR_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_define
define|#
directive|define
name|EV_NO_BUFFERS_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_NO_MB_FRAMES_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_NO_SB_FRAMES_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_TX_QUEUE_FULL_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_define
define|#
directive|define
name|EV_RX_QUEUE_FULL_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_INTR_QUEUE_FULL_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_define
define|#
directive|define
name|EV_NO_DATA_BUFFER_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_OBJ_POOL_EMPTY_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_BUS_ERROR_LEVEL
value|REPORT_LEVEL_CRITICAL
end_define

begin_define
define|#
directive|define
name|EV_PTP_TXTS_QUEUE_FULL_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_define
define|#
directive|define
name|EV_PTP_RXTS_QUEUE_FULL_LEVEL
value|REPORT_LEVEL_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENTS_MAPPING_H_ */
end_comment

end_unit

