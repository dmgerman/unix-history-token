begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)args.h	8.4 (Berkeley) 3/16/94  */
end_comment

begin_comment
comment|/*  * Structure for building "argc/argv" vector of arguments.  *  * !!!  * All arguments are nul terminated as well as having an associated length.  * The argument vector is NOT necessarily NULL terminated.  The proper way  * to check the number of arguments is to use the argc value in the EXCMDARG  * structure or to walk the array until an ARGS structure with a length of 0  * is found.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_args
block|{
name|CHAR_T
modifier|*
name|bp
decl_stmt|;
comment|/* Argument. */
name|size_t
name|blen
decl_stmt|;
comment|/* Buffer length. */
name|size_t
name|len
decl_stmt|;
comment|/* Argument length. */
define|#
directive|define
name|A_ALLOCATED
value|0x01
comment|/* If allocated space. */
name|u_char
name|flags
decl_stmt|;
block|}
name|ARGS
typedef|;
end_typedef

end_unit

