begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)wtreg.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1989 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Robert Baron  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*   * HISTORY  * $Log:	wtreg.h,v $  * Revision 2.2.1.1  90/01/08  13:29:25  rvb  * 	Add Intel copyright.  * 	[90/01/08            rvb]  *   * Revision 2.2  89/09/25  12:33:09  rvb  * 	Driver was provided by Intel 9/18/89.  * 	[89/09/23            rvb]  *   */
end_comment

begin_comment
comment|/*  *  *  Copyright 1988, 1989 by Intel Corporation  *  */
end_comment

begin_comment
comment|/*  *  wtioctl.h  *   defines ioctl parameters for direct QIC commands  */
end_comment

begin_define
define|#
directive|define
name|WTIOC
value|('W'<<8)
end_define

begin_define
define|#
directive|define
name|WTQICMD
value|(WTIOC|0)
end_define

begin_comment
comment|/* QIC commands allowed */
end_comment

begin_define
define|#
directive|define
name|SELECT
value|0x01
end_define

begin_define
define|#
directive|define
name|REWIND
value|0x21
end_define

begin_define
define|#
directive|define
name|ERASE
value|0x22
end_define

begin_define
define|#
directive|define
name|RETENS
value|0x24
end_define

end_unit

