begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010-2012 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CUSE_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CUSE_DEFS_H_
end_define

begin_define
define|#
directive|define
name|CUSE_VERSION
value|0x000122
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_BUSY
value|-1
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_WOULDBLOCK
value|-2
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_INVALID
value|-3
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_NO_MEMORY
value|-4
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_FAULT
value|-5
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_SIGNAL
value|-6
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_OTHER
value|-7
end_define

begin_define
define|#
directive|define
name|CUSE_ERR_NOT_LOADED
value|-8
end_define

begin_define
define|#
directive|define
name|CUSE_POLL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CUSE_POLL_READ
value|1
end_define

begin_define
define|#
directive|define
name|CUSE_POLL_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|CUSE_POLL_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|CUSE_FFLAG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CUSE_FFLAG_READ
value|1
end_define

begin_define
define|#
directive|define
name|CUSE_FFLAG_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|CUSE_FFLAG_NONBLOCK
value|4
end_define

begin_define
define|#
directive|define
name|CUSE_DBG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CUSE_DBG_FULL
value|1
end_define

begin_comment
comment|/* maximum data transfer length */
end_comment

begin_define
define|#
directive|define
name|CUSE_LENGTH_MAX
value|0x7FFFFFFFU
end_define

begin_enum
enum|enum
block|{
name|CUSE_CMD_NONE
block|,
name|CUSE_CMD_OPEN
block|,
name|CUSE_CMD_CLOSE
block|,
name|CUSE_CMD_READ
block|,
name|CUSE_CMD_WRITE
block|,
name|CUSE_CMD_IOCTL
block|,
name|CUSE_CMD_POLL
block|,
name|CUSE_CMD_SIGNAL
block|,
name|CUSE_CMD_SYNC
block|,
name|CUSE_CMD_MAX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|CUSE_MAKE_ID
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|u
parameter_list|)
value|((((a)& 0x7F)<< 24)| \     (((b)& 0xFF)<< 16)|(((c)& 0xFF)<< 8)|((u)& 0xFF))
end_define

begin_define
define|#
directive|define
name|CUSE_ID_MASK
value|0x7FFFFF00U
end_define

begin_comment
comment|/*  * The following ID's are defined:  * ===============================  */
end_comment

begin_define
define|#
directive|define
name|CUSE_ID_DEFAULT
parameter_list|(
name|what
parameter_list|)
value|CUSE_MAKE_ID(0,0,what,0)
end_define

begin_define
define|#
directive|define
name|CUSE_ID_WEBCAMD
parameter_list|(
name|what
parameter_list|)
value|CUSE_MAKE_ID('W','C',what,0)
end_define

begin_comment
comment|/* Used by Webcamd. */
end_comment

begin_define
define|#
directive|define
name|CUSE_ID_SUNDTEK
parameter_list|(
name|what
parameter_list|)
value|CUSE_MAKE_ID('S','K',what,0)
end_define

begin_comment
comment|/* Used by Sundtek. */
end_comment

begin_define
define|#
directive|define
name|CUSE_ID_CX88
parameter_list|(
name|what
parameter_list|)
value|CUSE_MAKE_ID('C','X',what,0)
end_define

begin_comment
comment|/* Used by cx88 driver. */
end_comment

begin_define
define|#
directive|define
name|CUSE_ID_UHIDD
parameter_list|(
name|what
parameter_list|)
value|CUSE_MAKE_ID('U','D',what,0)
end_define

begin_comment
comment|/* Used by uhidd. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CUSE_DEFS_H_ */
end_comment

end_unit

