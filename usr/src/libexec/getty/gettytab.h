begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gettytab.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * Getty description definitions.  */
end_comment

begin_struct
struct|struct
name|gettystrs
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup in gettytab */
name|char
modifier|*
name|defalt
decl_stmt|;
comment|/* value we find by looking in defaults */
name|char
modifier|*
name|value
decl_stmt|;
comment|/* value that we find there */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gettynums
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup */
name|long
name|defalt
decl_stmt|;
comment|/* number we find in defaults */
name|long
name|value
decl_stmt|;
comment|/* number we find there */
name|int
name|set
decl_stmt|;
comment|/* we actually got this one */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gettyflags
block|{
name|char
modifier|*
name|field
decl_stmt|;
comment|/* name to lookup */
name|char
name|invrt
decl_stmt|;
comment|/* name existing in gettytab --> false */
name|char
name|defalt
decl_stmt|;
comment|/* true/false in defaults */
name|char
name|value
decl_stmt|;
comment|/* true/false flag */
name|char
name|set
decl_stmt|;
comment|/* we found it */
block|}
struct|;
end_struct

begin_comment
comment|/*  * String values.  */
end_comment

begin_define
define|#
directive|define
name|NX
value|gettystrs[0].value
end_define

begin_define
define|#
directive|define
name|CL
value|gettystrs[1].value
end_define

begin_define
define|#
directive|define
name|IM
value|gettystrs[2].value
end_define

begin_define
define|#
directive|define
name|LM
value|gettystrs[3].value
end_define

begin_define
define|#
directive|define
name|ER
value|gettystrs[4].value
end_define

begin_define
define|#
directive|define
name|KL
value|gettystrs[5].value
end_define

begin_define
define|#
directive|define
name|ET
value|gettystrs[6].value
end_define

begin_define
define|#
directive|define
name|PC
value|gettystrs[7].value
end_define

begin_define
define|#
directive|define
name|TT
value|gettystrs[8].value
end_define

begin_define
define|#
directive|define
name|EV
value|gettystrs[9].value
end_define

begin_define
define|#
directive|define
name|LO
value|gettystrs[10].value
end_define

begin_define
define|#
directive|define
name|HN
value|gettystrs[11].value
end_define

begin_define
define|#
directive|define
name|HE
value|gettystrs[12].value
end_define

begin_define
define|#
directive|define
name|IN
value|gettystrs[13].value
end_define

begin_define
define|#
directive|define
name|QU
value|gettystrs[14].value
end_define

begin_define
define|#
directive|define
name|XN
value|gettystrs[15].value
end_define

begin_define
define|#
directive|define
name|XF
value|gettystrs[16].value
end_define

begin_define
define|#
directive|define
name|BK
value|gettystrs[17].value
end_define

begin_define
define|#
directive|define
name|SU
value|gettystrs[18].value
end_define

begin_define
define|#
directive|define
name|DS
value|gettystrs[19].value
end_define

begin_define
define|#
directive|define
name|RP
value|gettystrs[20].value
end_define

begin_define
define|#
directive|define
name|FL
value|gettystrs[21].value
end_define

begin_define
define|#
directive|define
name|WE
value|gettystrs[22].value
end_define

begin_define
define|#
directive|define
name|LN
value|gettystrs[23].value
end_define

begin_comment
comment|/*  * Numeric definitions.  */
end_comment

begin_define
define|#
directive|define
name|IS
value|gettynums[0].value
end_define

begin_define
define|#
directive|define
name|OS
value|gettynums[1].value
end_define

begin_define
define|#
directive|define
name|SP
value|gettynums[2].value
end_define

begin_define
define|#
directive|define
name|ND
value|gettynums[3].value
end_define

begin_define
define|#
directive|define
name|CD
value|gettynums[4].value
end_define

begin_define
define|#
directive|define
name|TD
value|gettynums[5].value
end_define

begin_define
define|#
directive|define
name|FD
value|gettynums[6].value
end_define

begin_define
define|#
directive|define
name|BD
value|gettynums[7].value
end_define

begin_define
define|#
directive|define
name|TO
value|gettynums[8].value
end_define

begin_define
define|#
directive|define
name|F0
value|gettynums[9].value
end_define

begin_define
define|#
directive|define
name|F0set
value|gettynums[9].set
end_define

begin_define
define|#
directive|define
name|F1
value|gettynums[10].value
end_define

begin_define
define|#
directive|define
name|F1set
value|gettynums[10].set
end_define

begin_define
define|#
directive|define
name|F2
value|gettynums[11].value
end_define

begin_define
define|#
directive|define
name|F2set
value|gettynums[11].set
end_define

begin_define
define|#
directive|define
name|PF
value|gettynums[12].value
end_define

begin_comment
comment|/*  * Boolean values.  */
end_comment

begin_define
define|#
directive|define
name|HT
value|gettyflags[0].value
end_define

begin_define
define|#
directive|define
name|NL
value|gettyflags[1].value
end_define

begin_define
define|#
directive|define
name|EP
value|gettyflags[2].value
end_define

begin_define
define|#
directive|define
name|EPset
value|gettyflags[2].set
end_define

begin_define
define|#
directive|define
name|OP
value|gettyflags[3].value
end_define

begin_define
define|#
directive|define
name|OPset
value|gettyflags[2].set
end_define

begin_define
define|#
directive|define
name|AP
value|gettyflags[4].value
end_define

begin_define
define|#
directive|define
name|APset
value|gettyflags[2].set
end_define

begin_define
define|#
directive|define
name|EC
value|gettyflags[5].value
end_define

begin_define
define|#
directive|define
name|CO
value|gettyflags[6].value
end_define

begin_define
define|#
directive|define
name|CB
value|gettyflags[7].value
end_define

begin_define
define|#
directive|define
name|CK
value|gettyflags[8].value
end_define

begin_define
define|#
directive|define
name|CE
value|gettyflags[9].value
end_define

begin_define
define|#
directive|define
name|PE
value|gettyflags[10].value
end_define

begin_define
define|#
directive|define
name|RW
value|gettyflags[11].value
end_define

begin_define
define|#
directive|define
name|XC
value|gettyflags[12].value
end_define

begin_define
define|#
directive|define
name|LC
value|gettyflags[13].value
end_define

begin_define
define|#
directive|define
name|UC
value|gettyflags[14].value
end_define

begin_define
define|#
directive|define
name|IG
value|gettyflags[15].value
end_define

begin_define
define|#
directive|define
name|PS
value|gettyflags[16].value
end_define

begin_define
define|#
directive|define
name|HC
value|gettyflags[17].value
end_define

begin_define
define|#
directive|define
name|UB
value|gettyflags[18].value
end_define

begin_define
define|#
directive|define
name|AB
value|gettyflags[19].value
end_define

begin_define
define|#
directive|define
name|DX
value|gettyflags[20].value
end_define

begin_define
define|#
directive|define
name|NP
value|gettyflags[21].value
end_define

begin_decl_stmt
name|int
name|getent
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|getnum
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getflag
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getstr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gettyflags
name|gettyflags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gettynums
name|gettynums
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gettystrs
name|gettystrs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hopcount
decl_stmt|;
end_decl_stmt

end_unit

