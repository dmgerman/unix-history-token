begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ring.h	5.4 (Berkeley) %G%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|P
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|LINT_ARGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

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
ifdef|#
directive|ifdef
name|ENCRYPTION
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
comment|/* ENCRYPTION */
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

begin_decl_stmt
specifier|extern
name|int
name|ring_init
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|unsigned
name|char
operator|*
name|buffer
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data movement routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ring_supply_data
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|unsigned
name|char
operator|*
name|buffer
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|ring_consume_data
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|unsigned
name|char
operator|*
name|buffer
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|,
name|ring_consumed
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|int
name|count
operator|)
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
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|)
argument_list|)
decl_stmt|,
name|ring_empty_consecutive
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|)
argument_list|)
decl_stmt|,
name|ring_full_count
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|)
argument_list|)
decl_stmt|,
name|ring_full_consecutive
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|ring_encrypt
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|,
name|void
argument_list|(
operator|*
name|func
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|,
name|ring_clearto
name|P
argument_list|(
operator|(
name|Ring
operator|*
name|ring
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCRYPTION */
end_comment

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

end_unit

