begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ngsrch.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NGSEARCH
end_ifdef

begin_define
define|#
directive|define
name|NGS_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|NGS_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|NGS_INTR
value|2
end_define

begin_define
define|#
directive|define
name|NGS_NOTFOUND
value|3
end_define

begin_define
define|#
directive|define
name|NGS_ERROR
value|4
end_define

begin_function_decl
name|EXT
name|bool
name|ng_doread
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* search read newsgroups? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|ngsrch_init
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
name|NGSEARCH
end_ifdef

begin_decl_stmt
name|int
name|ng_search
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ng_wanted
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

begin_ifdef
ifdef|#
directive|ifdef
name|NGSORONLY
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ng_comp
name|_
argument_list|(
operator|(
name|COMPEX
operator|*
operator|,
name|char
operator|*
operator|,
name|bool_int
operator|,
name|bool_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

