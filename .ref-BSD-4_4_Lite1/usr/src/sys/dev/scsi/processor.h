begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)processor.h	8.1 (Berkeley) 6/10/93  *  * from: $Header: processor.h,v 1.3 92/12/02 03:52:27 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Processor Devices.  */
end_comment

begin_define
define|#
directive|define
name|CMD_RECEIVE
value|0x08
end_define

begin_comment
comment|/* receive */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND
value|0x0a
end_define

begin_comment
comment|/* send */
end_comment

begin_comment
comment|/*  * Structure of a RECEIVE or SEND command (i.e., the cdb).  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_rs
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x8 or 0xa */
name|cdb_lun_xxx
decl_stmt|,
comment|/* logical unit number + reserved */
name|cdb_lenh
decl_stmt|,
comment|/* buffer or data length (MSB) */
name|cdb_lenm
decl_stmt|,
comment|/* buffer or data length */
name|cdb_lenl
decl_stmt|,
comment|/* buffer or data length (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

end_unit

