begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ttychars.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * 4.3 COMPATIBILITY FILE  *  * User visible structures and constants related to terminal handling.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYCHARS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYCHARS_H_
end_define

begin_struct
struct|struct
name|ttychars
block|{
name|char
name|tc_erase
decl_stmt|;
comment|/* erase last character */
name|char
name|tc_kill
decl_stmt|;
comment|/* erase entire line */
name|char
name|tc_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|tc_quitc
decl_stmt|;
comment|/* quit */
name|char
name|tc_startc
decl_stmt|;
comment|/* start output */
name|char
name|tc_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|tc_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|tc_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
name|char
name|tc_suspc
decl_stmt|;
comment|/* stop process signal */
name|char
name|tc_dsuspc
decl_stmt|;
comment|/* delayed stop process signal */
name|char
name|tc_rprntc
decl_stmt|;
comment|/* reprint line */
name|char
name|tc_flushc
decl_stmt|;
comment|/* flush output (toggles) */
name|char
name|tc_werasc
decl_stmt|;
comment|/* word erase */
name|char
name|tc_lnextc
decl_stmt|;
comment|/* literal next character */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_include
include|#
directive|include
file|<sys/ttydefaults.h>
end_include

begin_comment
comment|/* to pick up character defaults */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYCHARS_H_ */
end_comment

end_unit

