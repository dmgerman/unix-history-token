begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: katelib.h,v 1.3 2001/11/23 19:21:48 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994-1996 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * katelib.h  *  * Prototypes for machine specific functions. Most of these  * could be inlined.  *  * This should not really be a separate header file. Eventually I will merge  * this into other header files once I have decided where the declarations  * should go.   *  * Created      : 18/09/94  *  * Based on kate/katelib/prototypes.h  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * USE OF THIS FILE IS DEPRECATED  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_KATELIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_KATELIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Assembly modules */
end_comment

begin_comment
comment|/* In blockio.S */
end_comment

begin_include
include|#
directive|include
file|<machine/blockio.h>
end_include

begin_comment
comment|/* Macros for reading and writing words, shorts, bytes */
end_comment

begin_define
define|#
directive|define
name|WriteWord
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|*((volatile unsigned int *)(a)) = (b)
end_define

begin_define
define|#
directive|define
name|ReadWord
parameter_list|(
name|a
parameter_list|)
define|\
value|(*((volatile unsigned int *)(a)))
end_define

begin_define
define|#
directive|define
name|WriteShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|*((volatile unsigned int *)(a)) = ((b) | ((b)<< 16))
end_define

begin_define
define|#
directive|define
name|ReadShort
parameter_list|(
name|a
parameter_list|)
define|\
value|((*((volatile unsigned int *)(a)))& 0xffff)
end_define

begin_define
define|#
directive|define
name|WriteByte
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|*((volatile unsigned char *)(a)) = (b)
end_define

begin_define
define|#
directive|define
name|ReadByte
parameter_list|(
name|a
parameter_list|)
define|\
value|(*((volatile unsigned char *)(a)))
end_define

begin_comment
comment|/* Define in/out macros */
end_comment

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|ReadByte((port))
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|byte
parameter_list|)
value|WriteByte((port), (byte))
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|port
parameter_list|)
value|ReadShort((port))
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|port
parameter_list|,
name|word
parameter_list|)
value|WriteShort((port), (word))
end_define

begin_define
define|#
directive|define
name|inl
parameter_list|(
name|port
parameter_list|)
value|ReadWord((port))
end_define

begin_define
define|#
directive|define
name|outl
parameter_list|(
name|port
parameter_list|,
name|lword
parameter_list|)
value|WriteWord((port), (lword))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_KATELIB_H_ */
end_comment

begin_comment
comment|/* End of katelib.h */
end_comment

end_unit

