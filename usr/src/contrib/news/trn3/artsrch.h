begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: artsrch.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
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
name|ARTSEARCH
end_ifdef

begin_define
define|#
directive|define
name|SRCH_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|SRCH_INTR
value|1
end_define

begin_define
define|#
directive|define
name|SRCH_FOUND
value|2
end_define

begin_define
define|#
directive|define
name|SRCH_NOTFOUND
value|3
end_define

begin_define
define|#
directive|define
name|SRCH_DONE
value|4
end_define

begin_define
define|#
directive|define
name|SRCH_SUBJDONE
value|5
end_define

begin_define
define|#
directive|define
name|SRCH_ERROR
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|char
modifier|*
name|lastpat
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* last search pattern */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARTSEARCH
end_ifdef

begin_decl_stmt
name|EXT
name|COMPEX
name|sub_compex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last compiled subject search */
end_comment

begin_decl_stmt
name|EXT
name|COMPEX
name|art_compex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last compiled normal search */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONDSUB
end_ifdef

begin_decl_stmt
name|EXT
name|COMPEX
modifier|*
name|bra_compex
name|INIT
argument_list|(
operator|&
operator|(
name|art_compex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current compex with brackets */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
name|art_howmuch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search just the subjects */
end_comment

begin_decl_stmt
name|EXT
name|bool
name|art_doread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search read articles? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|artsrch_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ARTSEARCH
end_ifdef

begin_decl_stmt
name|int
name|art_search
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

begin_decl_stmt
name|bool
name|wanted
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|ART_NUM
operator|,
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return TRUE if current article matches pattern */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

