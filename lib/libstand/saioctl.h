begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: saioctl.h,v 1.2 1994/10/26 05:45:04 cgd Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)saioctl.h	8.1 (Berkeley) 6/11/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ioctl's -- for disks just now */
end_comment

begin_define
define|#
directive|define
name|SAIOHDR
value|(('d'<<8)|1)
end_define

begin_comment
comment|/* next i/o includes header */
end_comment

begin_define
define|#
directive|define
name|SAIOCHECK
value|(('d'<<8)|2)
end_define

begin_comment
comment|/* next i/o checks data */
end_comment

begin_define
define|#
directive|define
name|SAIOHCHECK
value|(('d'<<8)|3)
end_define

begin_comment
comment|/* next i/o checks header& data */
end_comment

begin_define
define|#
directive|define
name|SAIONOBAD
value|(('d'<<8)|4)
end_define

begin_comment
comment|/* inhibit bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIODOBAD
value|(('d'<<8)|5)
end_define

begin_comment
comment|/* enable bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIOECCLIM
value|(('d'<<8)|6)
end_define

begin_comment
comment|/* set limit to ecc correction, bits */
end_comment

begin_define
define|#
directive|define
name|SAIOECCUNL
value|(('d'<<8)|7)
end_define

begin_comment
comment|/* use standard ecc procedures */
end_comment

begin_define
define|#
directive|define
name|SAIORETRIES
value|(('d'<<8)|8)
end_define

begin_comment
comment|/* set retry count for unit */
end_comment

begin_define
define|#
directive|define
name|SAIODEVDATA
value|(('d'<<8)|9)
end_define

begin_comment
comment|/* get pointer to pack label */
end_comment

begin_define
define|#
directive|define
name|SAIOSSI
value|(('d'<<8)|10)
end_define

begin_comment
comment|/* set skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|SAIONOSSI
value|(('d'<<8)|11)
end_define

begin_comment
comment|/* inhibit skip sector handling */
end_comment

begin_define
define|#
directive|define
name|SAIOSSDEV
value|(('d'<<8)|12)
end_define

begin_comment
comment|/* is device skip sector type? */
end_comment

begin_define
define|#
directive|define
name|SAIODEBUG
value|(('d'<<8)|13)
end_define

begin_comment
comment|/* enable/disable debugging */
end_comment

begin_define
define|#
directive|define
name|SAIOGBADINFO
value|(('d'<<8)|14)
end_define

begin_comment
comment|/* get bad-sector table */
end_comment

end_unit

