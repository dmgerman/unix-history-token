begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ring.h	1.10 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * This defines a structure for a ring buffer.  *  * The circular buffer has two parts:  *(((  *	full:	[consume, supply)  *	empty:	[supply, consume)  *]]]  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINT_ARGS
argument_list|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LINT_ARGS */
end_comment

begin_function_decl
specifier|extern
name|int
name|ring_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ring_supply_data
parameter_list|()
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
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|ring_supplied
argument_list|()
decl_stmt|,
name|ring_consumed
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ring_clear_mark
argument_list|()
decl_stmt|,
name|ring_mark
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ring_empty_count
argument_list|()
decl_stmt|,
name|ring_empty_consecutive
argument_list|()
decl_stmt|,
name|ring_full_count
argument_list|()
decl_stmt|,
name|ring_full_consecutive
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LINT_ARGS) */
end_comment

end_unit

