begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ioccom.h	8.2 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCCOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCCOM_H_
end_define

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word, and the size of  * any in or out parameters in the upper word.  The high 3 bits of the  * upper word are used to encode the in/out status of the parameter.  */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_MASK
value|0x1fff
end_define

begin_comment
comment|/* parameter length, at most 13 bits */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& IOCPARM_MASK)
end_define

begin_define
define|#
directive|define
name|IOCBASECMD
parameter_list|(
name|x
parameter_list|)
value|((x)& ~(IOCPARM_MASK<< 16))
end_define

begin_define
define|#
directive|define
name|IOCGROUP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|IOCPARM_MAX
value|PAGE_SIZE
end_define

begin_comment
comment|/* max size of ioctl, mult. of PAGE_SIZE */
end_comment

begin_define
define|#
directive|define
name|IOC_VOID
value|0x20000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_OUT
value|0x40000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_IN
value|0x80000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_INOUT
value|(IOC_IN|IOC_OUT)
end_define

begin_define
define|#
directive|define
name|IOC_DIRMASK
value|0xe0000000
end_define

begin_comment
comment|/* mask for IN/OUT/VOID */
end_comment

begin_define
define|#
directive|define
name|_IOC
parameter_list|(
name|inout
parameter_list|,
name|group
parameter_list|,
name|num
parameter_list|,
name|len
parameter_list|)
define|\
value|((unsigned long)(inout | ((len& IOCPARM_MASK)<< 16) | ((group)<< 8) | (num)))
end_define

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
value|_IOC(IOC_VOID,	(g), (n), 0)
end_define

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_OUT,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_IN,	(g), (n), sizeof(t))
end_define

begin_comment
comment|/* this should be _IORW, but stdio got there first */
end_comment

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_INOUT,	(g), (n), sizeof(t))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ioctl
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCCOM_H_ */
end_comment

end_unit

