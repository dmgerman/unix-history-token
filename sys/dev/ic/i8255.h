begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 TAKAHASHI Yoshihiro  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IC_I8255_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IC_I8255_H_
end_define

begin_comment
comment|/*  * modem status via SYSTM_PORTB  */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CD
value|0x20
end_define

begin_comment
comment|/* CD */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CS
value|0x40
end_define

begin_comment
comment|/* CS */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CI
value|0x80
end_define

begin_comment
comment|/* CI */
end_comment

begin_comment
comment|/*  * control intrline via SYSTM_PORTC   */
end_comment

begin_define
define|#
directive|define
name|IEN_Rx
value|0x01
end_define

begin_define
define|#
directive|define
name|IEN_TxEMP
value|0x02
end_define

begin_define
define|#
directive|define
name|IEN_Tx
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IC_I8255_H_ */
end_comment

end_unit

