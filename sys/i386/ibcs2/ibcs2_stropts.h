begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ibcs2_stropts.h  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_STROPTS_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_STROPTS_H
end_define

begin_define
define|#
directive|define
name|IBCS2_STR
value|('S'<<8)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_NREAD
value|(IBCS2_STR|01)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_PUSH
value|(IBCS2_STR|02)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_POP
value|(IBCS2_STR|03)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_LOOK
value|(IBCS2_STR|04)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_FLUSH
value|(IBCS2_STR|05)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_SRDOPT
value|(IBCS2_STR|06)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_GRDOPT
value|(IBCS2_STR|07)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_STR
value|(IBCS2_STR|010)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_SETSIG
value|(IBCS2_STR|011)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_GETSIG
value|(IBCS2_STR|012)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_FIND
value|(IBCS2_STR|013)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_LINK
value|(IBCS2_STR|014)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_UNLINK
value|(IBCS2_STR|015)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_PEEK
value|(IBCS2_STR|017)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_FDINSERT
value|(IBCS2_STR|020)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_SENDFD
value|(IBCS2_STR|021)
end_define

begin_define
define|#
directive|define
name|IBCS2_I_RECVFD
value|(IBCS2_STR|022)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_STROPTS_H */
end_comment

end_unit

