begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)alias.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|alias
value|var
end_define

begin_define
define|#
directive|define
name|a_name
value|r_name
end_define

begin_define
define|#
directive|define
name|a_buf
value|r_val.v_str
end_define

begin_define
define|#
directive|define
name|a_flags
value|r_val.v_type
end_define

begin_comment
comment|/* a_flags bits, must not interfere with v_type values */
end_comment

begin_define
define|#
directive|define
name|A_INUSE
value|0x010
end_define

begin_comment
comment|/* already inuse */
end_comment

begin_define
define|#
directive|define
name|alias_set
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|var_setstr1(&alias_head, n, s)
end_define

begin_define
define|#
directive|define
name|alias_walk
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|var_walk1(alias_head, f, a)
end_define

begin_define
define|#
directive|define
name|alias_unset
parameter_list|(
name|n
parameter_list|)
value|var_unset1(&alias_head, n)
end_define

begin_define
define|#
directive|define
name|alias_lookup
parameter_list|(
name|n
parameter_list|)
value|(*var_lookup1(&alias_head, n))
end_define

begin_decl_stmt
name|struct
name|var
modifier|*
name|alias_head
decl_stmt|;
end_decl_stmt

end_unit

