begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)db_reload.c	4.22 (Berkeley) 3/21/91"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * ++Copyright++ 1986, 1988  * -  * Copyright (c) 1986, 1988  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"named.h"
end_include

begin_comment
comment|/*  * Flush and reload data base.  */
end_comment

begin_function
name|void
name|db_reload
parameter_list|()
block|{
name|dprintf
argument_list|(
literal|3
argument_list|,
operator|(
name|ddt
operator|,
literal|"reload()\n"
operator|)
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"reloading nameserver\n"
argument_list|)
expr_stmt|;
name|qflush
argument_list|()
expr_stmt|;
name|sqflush
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|getnetconf
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|FORCED_RELOAD
name|reloading
operator|=
literal|1
expr_stmt|;
comment|/* to force transfer if secondary and backing up */
endif|#
directive|endif
name|ns_init
argument_list|(
name|bootfile
argument_list|)
expr_stmt|;
name|time
argument_list|(
operator|&
name|resettime
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|FORCED_RELOAD
name|reloading
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|needmaint
condition|)
name|sched_maint
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* FORCED_RELOAD */
name|dprintf
argument_list|(
literal|1
argument_list|,
operator|(
name|ddt
operator|,
literal|"Ready to answer queries.\n"
operator|)
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Ready to answer queries.\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* someday we'll need this.. (untested since before 1990) */
end_comment

begin_endif
unit|void db_free(htp) 	struct hashbuf *htp; { 	register struct databuf *dp, *nextdp; 	register struct namebuf *np, *nextnp; 	struct namebuf **npp, **nppend;  	npp = htp->h_tab; 	nppend = npp + htp->h_size; 	while (npp< nppend) { 	    for (np = *npp++; np != NULL; np = nextnp) { 		if (np->n_hash != NULL) 			db_free(np->n_hash); 		(void) free((char *)np->n_dname); 		for (dp = np->n_data; dp != NULL; ) { 			nextdp = dp->d_next; 			(void) free((char *)dp); 			dp = nextdp; 		} 		nextnp = np->n_next; 		free((char *)np); 	    } 	} 	(void) free((char *)htp); }
endif|#
directive|endif
end_endif

end_unit

