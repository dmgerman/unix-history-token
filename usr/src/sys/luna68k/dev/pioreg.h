begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pioreg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * PIO definitions  * OMRON: $Id: pioreg.h,v 1.1 92/05/27 14:33:18 moti Exp $  * by Shigeto Mochida   */
end_comment

begin_define
define|#
directive|define
name|PIO0_ADDR
value|0x49000000
end_define

begin_comment
comment|/* pio0 address */
end_comment

begin_define
define|#
directive|define
name|PIO1_ADDR
value|0x4D000000
end_define

begin_comment
comment|/* pio1 address */
end_comment

begin_define
define|#
directive|define
name|PIO_MODED
value|0xB6
end_define

begin_comment
comment|/* pio mode set */
end_comment

begin_struct
struct|struct
name|pio
block|{
name|unsigned
name|char
name|a_port
decl_stmt|;
name|unsigned
name|char
name|b_port
decl_stmt|;
name|unsigned
name|char
name|c_port
decl_stmt|;
name|unsigned
name|char
name|control_port
decl_stmt|;
block|}
struct|;
end_struct

end_unit

