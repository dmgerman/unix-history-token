begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bits.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|found_bits
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|ART_NUM
name|found_min
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if subscripting is faster than shifting on your machine, define this */
end_comment

begin_undef
undef|#
directive|undef
name|USESUBSCRIPT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USESUBSCRIPT
end_ifdef

begin_decl_stmt
name|EXT
name|char
name|powerof2
index|[]
name|INIT
argument_list|(
block|{
literal|1
operator|,
literal|2
operator|,
literal|4
operator|,
literal|8
operator|,
literal|16
operator|,
literal|32
operator|,
literal|64
operator|,
literal|128
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|pow2
parameter_list|(
name|x
parameter_list|)
value|powerof2[x]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pow2
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|foundart
parameter_list|(
name|a
parameter_list|)
value|(found_bits[((a)-found_min) / BITSPERBYTE] \ 	|= pow2(((a)-found_min) % BITSPERBYTE))
end_define

begin_define
define|#
directive|define
name|artismissing
parameter_list|(
name|a
parameter_list|)
value|(!(found_bits[((a)-found_min) / BITSPERBYTE] \& pow2(((a)-found_min) % BITSPERBYTE)))
end_define

begin_decl_stmt
name|EXT
name|int
name|dmcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bits_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rc_to_bits
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bits_to_rc
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setfoundbits
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setmissingbits
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onemore
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|oneless
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onemissing
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unmark_as_read
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_read
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_unread
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|delay_unmark
name|_
argument_list|(
operator|(
name|ARTICLE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_as_read
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|check_first
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|yankback
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chase_xrefs
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

