begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ring.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/* $Id: ring.h,v 1.4 2000/02/06 05:15:47 assar Exp $ */
end_comment

begin_comment
comment|/*  * This defines a structure for a ring buffer.  *  * The circular buffer has two parts:  *(((  *	full:	[consume, supply)  *	empty:	[supply, consume)  *]]]  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
modifier|*
name|consume
decl_stmt|,
comment|/* where data comes out of */
modifier|*
name|supply
decl_stmt|,
comment|/* where data comes in to */
modifier|*
name|bottom
decl_stmt|,
comment|/* lowest address in buffer */
modifier|*
name|top
decl_stmt|,
comment|/* highest address+1 in buffer */
modifier|*
name|mark
decl_stmt|;
comment|/* marker (user defined) */
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
name|unsigned
name|char
modifier|*
name|clearto
decl_stmt|;
comment|/* Data to this point is clear text */
name|unsigned
name|char
modifier|*
name|encryyptedto
decl_stmt|;
comment|/* Data is encrypted to here */
endif|#
directive|endif
name|int
name|size
decl_stmt|;
comment|/* size in bytes of buffer */
name|u_long
name|consumetime
decl_stmt|,
comment|/* help us keep straight full, empty, etc. */
name|supplytime
decl_stmt|;
block|}
name|Ring
typedef|;
end_typedef

begin_comment
comment|/* Here are some functions and macros to deal with the ring buffer */
end_comment

begin_comment
comment|/* Initialization routine */
end_comment

begin_function_decl
specifier|extern
name|int
name|ring_init
parameter_list|(
name|Ring
modifier|*
name|ring
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Data movement routines */
end_comment

begin_function_decl
specifier|extern
name|void
name|ring_supply_data
parameter_list|(
name|Ring
modifier|*
name|ring
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ring_consume_data
parameter_list|(
name|Ring
modifier|*
name|ring
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Buffer state transition routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ring_supplied
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|,
name|ring_consumed
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer state query routines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ring_empty_count
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_empty_consecutive
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_full_count
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_full_consecutive
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|ring_encrypt
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|void
argument_list|(
argument|*func
argument_list|)
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|,
name|ring_clearto
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|ring_at_mark
parameter_list|(
name|Ring
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|ring_clear_mark
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_mark
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

