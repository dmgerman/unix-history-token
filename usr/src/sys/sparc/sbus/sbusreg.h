begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sbusreg.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: sbusreg.h,v 1.6 92/11/26 02:28:14 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c S-bus definitions.  (Should be made generic!)  *  * Sbus slot 0 is not a separate slot; it talks to the onboard I/O devices.  * It is, however, addressed just like any `real' Sbus.  *  * Sbus device addresses are obtained from the FORTH PROMs.  They come  * in `absolute' and `relative' address flavors, so we have to handle both.  * Relative addresses do *not* include the slot number.  */
end_comment

begin_define
define|#
directive|define
name|SBUS_BASE
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|SBUS_ADDR
parameter_list|(
name|slot
parameter_list|,
name|off
parameter_list|)
value|(SBUS_BASE + ((slot)<< 25) + (off))
end_define

begin_define
define|#
directive|define
name|SBUS_ABS
parameter_list|(
name|a
parameter_list|)
value|((unsigned)(a)>= SBUS_BASE)
end_define

begin_define
define|#
directive|define
name|SBUS_ABS_TO_SLOT
parameter_list|(
name|a
parameter_list|)
value|(((a) - SBUS_BASE)>> 25)
end_define

begin_define
define|#
directive|define
name|SBUS_ABS_TO_OFFSET
parameter_list|(
name|a
parameter_list|)
value|(((a) - SBUS_BASE)& 0x1ffffff)
end_define

end_unit

