begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dohits.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|numberof
parameter_list|(
name|x
parameter_list|)
value|(sizeof x/sizeof x[0])
end_define

begin_define
define|#
directive|define
name|highestof
parameter_list|(
name|x
parameter_list|)
value|(numberof(x)-1)
end_define

begin_define
define|#
directive|define
name|firstentry
parameter_list|(
name|x
parameter_list|)
value|(table[dohash(0, (x))%highestof(table)])
end_define

begin_struct
struct|struct
name|Hits
block|{
name|struct
name|hits
name|hits
decl_stmt|;
name|char
modifier|*
name|name
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|thing
block|{
name|struct
name|thing
modifier|*
name|next
decl_stmt|;
name|struct
name|Hits
modifier|*
name|hits
decl_stmt|;
name|unsigned
name|char
name|value
decl_stmt|;
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|Hits
name|Hits
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one for each of 0x00-0xff */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thing
modifier|*
name|table
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|unsigned
name|int
name|dohash
parameter_list|()
function_decl|;
end_function_decl

end_unit

