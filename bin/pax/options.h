begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)options.h	8.2 (Berkeley) 4/18/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * argv[0] names. Used for tar and cpio emulation  */
end_comment

begin_define
define|#
directive|define
name|NM_TAR
value|"tar"
end_define

begin_define
define|#
directive|define
name|NM_CPIO
value|"cpio"
end_define

begin_define
define|#
directive|define
name|NM_PAX
value|"pax"
end_define

begin_comment
comment|/*  * Constants used to specify the legal sets of flags in pax. For each major  * operation mode of pax, a set of illegal flags is defined. If any one of  * those illegal flags are found set, we scream and exit  */
end_comment

begin_define
define|#
directive|define
name|NONE
value|"none"
end_define

begin_comment
comment|/*  * flags (one for each option).  */
end_comment

begin_define
define|#
directive|define
name|AF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|OF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|UF
value|0x00004000
end_define

begin_define
define|#
directive|define
name|VF
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CBF
value|0x00040000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CDF
value|0x00080000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CEF
value|0x00100000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CGF
value|0x00200000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CHF
value|0x00400000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CLF
value|0x00800000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CPF
value|0x01000000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CTF
value|0x02000000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CUF
value|0x04000000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CXF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CYF
value|0x10000000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_define
define|#
directive|define
name|CZF
value|0x20000000
end_define

begin_comment
comment|/* nonstandard extension */
end_comment

begin_comment
comment|/*  * ascii string indexed by bit position above (alter the above and you must  * alter this string) used to tell the user what flags caused us to complain  */
end_comment

begin_define
define|#
directive|define
name|FLGCH
value|"abcdfiklnoprstuvwxBDEGHLPTUXYZ"
end_define

begin_comment
comment|/*  * legal pax operation bit patterns  */
end_comment

begin_define
define|#
directive|define
name|ISLIST
parameter_list|(
name|x
parameter_list|)
value|(((x)& (RF|WF)) == 0)
end_define

begin_define
define|#
directive|define
name|ISEXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)& (RF|WF)) == RF)
end_define

begin_define
define|#
directive|define
name|ISARCHIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& (AF|RF|WF)) == WF)
end_define

begin_define
define|#
directive|define
name|ISAPPND
parameter_list|(
name|x
parameter_list|)
value|(((x)& (AF|RF|WF)) == (AF|WF))
end_define

begin_define
define|#
directive|define
name|ISCOPY
parameter_list|(
name|x
parameter_list|)
value|(((x)& (RF|WF)) == (RF|WF))
end_define

begin_define
define|#
directive|define
name|ISWRITE
parameter_list|(
name|x
parameter_list|)
value|(((x)& (RF|WF)) == WF)
end_define

begin_comment
comment|/*  * Illegal option flag subsets based on pax operation  */
end_comment

begin_define
define|#
directive|define
name|BDEXTR
value|(AF|BF|LF|TF|WF|XF|CBF|CHF|CLF|CPF|CXF)
end_define

begin_define
define|#
directive|define
name|BDARCH
value|(CF|KF|LF|NF|PF|RF|CDF|CEF|CYF|CZF)
end_define

begin_define
define|#
directive|define
name|BDCOPY
value|(AF|BF|FF|OF|XF|CBF|CEF)
end_define

begin_define
define|#
directive|define
name|BDLIST
value|(AF|BF|IF|KF|LF|OF|PF|RF|TF|UF|WF|XF|CBF|CDF|CHF|CLF|CPF|CXF|CYF|CZF)
end_define

end_unit

