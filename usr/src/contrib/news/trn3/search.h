begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: search.h,v 3.0 1991/09/09 20:27:37 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NBRA
end_ifndef

begin_define
define|#
directive|define
name|NBRA
value|10
end_define

begin_comment
comment|/* the maximum number of meta-brackets in an 				   RE -- \( \) */
end_comment

begin_define
define|#
directive|define
name|NALTS
value|10
end_define

begin_comment
comment|/* the maximum number of \|'s */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|expbuf
decl_stmt|;
comment|/* The compiled search string */
name|int
name|eblen
decl_stmt|;
comment|/* Length of above buffer */
name|char
modifier|*
name|alternatives
index|[
name|NALTS
index|]
decl_stmt|;
comment|/* The list of \| seperated alternatives */
name|char
modifier|*
name|braslist
index|[
name|NBRA
index|]
decl_stmt|;
comment|/* RE meta-bracket start list */
name|char
modifier|*
name|braelist
index|[
name|NBRA
index|]
decl_stmt|;
comment|/* RE meta-bracket end list */
name|char
modifier|*
name|brastr
decl_stmt|;
comment|/* saved match string after execute() */
name|char
name|nbra
decl_stmt|;
comment|/* The number of meta-brackets int the most 				   recenlty compiled RE */
name|bool
name|do_folding
decl_stmt|;
comment|/* fold upper and lower case? */
block|}
name|COMPEX
typedef|;
end_typedef

begin_decl_stmt
name|void
name|search_init
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
name|init_compex
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_compex
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getbracket
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|case_fold
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|compile
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|grow_eb
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
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
name|char
modifier|*
name|execute
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|advance
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
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
name|bool
name|backref
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|cclass
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

