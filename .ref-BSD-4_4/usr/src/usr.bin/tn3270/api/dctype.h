begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dctype.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ECTYPE
end_define

begin_define
define|#
directive|define
name|D_UPPER
value|0x01
end_define

begin_define
define|#
directive|define
name|D_LOWER
value|0x02
end_define

begin_define
define|#
directive|define
name|D_DIGIT
value|0x04
end_define

begin_define
define|#
directive|define
name|D_SPACE
value|0x08
end_define

begin_define
define|#
directive|define
name|D_PUNCT
value|0x10
end_define

begin_define
define|#
directive|define
name|D_PRINT
value|0x20
end_define

begin_define
define|#
directive|define
name|Disalpha
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&(D_UPPER|D_LOWER))
end_define

begin_define
define|#
directive|define
name|Disupper
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_UPPER)
end_define

begin_define
define|#
directive|define
name|Dislower
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_LOWER)
end_define

begin_define
define|#
directive|define
name|Disdigit
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_DIGIT)
end_define

begin_define
define|#
directive|define
name|Disalnum
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&(D_UPPER|D_LOWER|D_DIGIT))
end_define

begin_define
define|#
directive|define
name|Disspace
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_SPACE)
end_define

begin_comment
comment|/* blank or null */
end_comment

begin_define
define|#
directive|define
name|Dispunct
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_PUNCT)
end_define

begin_define
define|#
directive|define
name|Disprint
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_PRINT)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|dctype
index|[
literal|192
index|]
decl_stmt|;
end_decl_stmt

end_unit

