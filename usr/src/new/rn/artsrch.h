begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: artsrch.h,v 4.3 85/05/01 11:35:55 lwall Exp $  *  * $Log:	artsrch.h,v $  * Revision 4.3  85/05/01  11:35:55  lwall  * Baseline for release with 4.3bsd.  *   */
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
name|art_compex
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

begin_function_decl
name|void
name|artsrch_init
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ARTSEARCH
end_ifdef

begin_function_decl
name|int
name|art_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|wanted
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return TRUE if current article matches pattern */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

