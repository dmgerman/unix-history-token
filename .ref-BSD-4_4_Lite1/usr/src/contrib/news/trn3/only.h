begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: only.h,v 3.0 1991/09/09 20:23:31 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NBRA
end_ifndef

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONLY
end_ifdef

begin_decl_stmt
name|EXT
name|char
modifier|*
name|ngtodo
index|[
name|NGMAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restrictions in effect */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPEED_OVER_MEM
end_ifdef

begin_decl_stmt
name|EXT
name|COMPEX
modifier|*
name|compextodo
index|[
name|NGMAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restrictions in compiled form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|maxngtodo
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0 => no restrictions */
end_comment

begin_comment
comment|/*>0 => # of entries in ngtodo */
end_comment

begin_decl_stmt
name|void
name|only_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|inlist
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return TRUE if ngname is in command line list */
end_comment

begin_comment
comment|/* or if there was no list */
end_comment

begin_decl_stmt
name|void
name|setngtodo
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ONLY
end_ifdef

begin_decl_stmt
name|void
name|end_only
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

