begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from db.h	4.16 (Berkeley) 6/1/90  *	$Id: db_glob.h,v 8.14 2000/04/21 06:54:02 vixie Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1990  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Global variables for data base routines.  */
end_comment

begin_comment
comment|/* ONE_WEEK maximum ttl */
end_comment

begin_decl_stmt
name|DECL
name|u_int
name|max_cache_ttl
name|INIT
argument_list|(
literal|7
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no minimum ttl */
end_comment

begin_decl_stmt
name|DECL
name|u_int
name|min_cache_ttl
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number */
end_comment

begin_decl_stmt
name|DECL
name|int
name|lineno
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root hash table */
end_comment

begin_function_decl
name|DECL
name|struct
name|hashbuf
modifier|*
name|hashtab
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hash table of cache read from file */
end_comment

begin_function_decl
name|DECL
name|struct
name|hashbuf
modifier|*
name|fcachetab
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* state of ns_reload() and ns_reconfig(). */
end_comment

begin_decl_stmt
name|DECL
name|int
name|reloading
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|reconfiging
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|noexpired
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|int
name|hashsizes
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
init|=
block|{
literal|2
block|,
literal|11
block|,
literal|113
block|,
literal|337
block|,
literal|977
block|,
literal|2053
block|,
literal|4073
block|,
literal|8011
block|,
literal|16001
block|,
literal|99887
block|,
literal|0
block|}
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

end_unit

