begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)sig.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.sig.h: Signal handling functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_sig
end_ifndef

begin_define
define|#
directive|define
name|_h_el_sig
end_define

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_comment
comment|/*  * Define here all the signals we are going to handle  * The _DO macro is used to iterate in the source code  */
end_comment

begin_define
define|#
directive|define
name|ALLSIGS
define|\
value|_DO(SIGINT)		\     _DO(SIGTSTP)	\     _DO(SIGSTOP)	\     _DO(SIGQUIT)	\     _DO(SIGHUP)		\     _DO(SIGTERM)	\     _DO(SIGCONT)	\     _DO(SIGWINCH)
end_define

begin_typedef
typedef|typedef
name|sig_t
modifier|*
name|el_signal_t
typedef|;
end_typedef

begin_decl_stmt
name|protected
name|void
name|sig_end
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|sig_init
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|sig_set
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|sig_clr
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_sig */
end_comment

end_unit

