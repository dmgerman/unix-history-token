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
literal|"@(#)db_save.c	4.16 (Berkeley) 3/21/91"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: db_save.c,v 4.9.1.3 1993/09/09 19:56:44 vixie Exp $"
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
comment|/*  * ++Copyright++ 1986  * -  * Copyright (c) 1986  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  * Buffer allocation and deallocation routines.  */
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
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"named.h"
end_include

begin_comment
comment|/*  * Allocate a name buffer& save name.  */
end_comment

begin_function
name|struct
name|namebuf
modifier|*
name|savename
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|register
name|struct
name|namebuf
modifier|*
name|np
decl_stmt|;
name|np
operator|=
operator|(
expr|struct
name|namebuf
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|namebuf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|np
operator|==
name|NULL
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"savename: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|np
operator|->
name|n_dname
operator|=
name|savestr
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|np
operator|->
name|n_next
operator|=
name|NULL
expr_stmt|;
name|np
operator|->
name|n_data
operator|=
name|NULL
expr_stmt|;
name|np
operator|->
name|n_hash
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|np
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Allocate a data buffer& save data.  */
end_comment

begin_function
name|struct
name|databuf
modifier|*
ifdef|#
directive|ifdef
name|DMALLOC
name|savedata_tagged
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|,
name|class
parameter_list|,
name|type
parameter_list|,
name|ttl
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
else|#
directive|else
function|savedata
parameter_list|(
name|class
parameter_list|,
name|type
parameter_list|,
name|ttl
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
endif|#
directive|endif
name|int
name|class
decl_stmt|,
name|type
decl_stmt|;
name|u_int32_t
name|ttl
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{
specifier|register
name|struct
name|databuf
modifier|*
name|dp
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|T_NS
condition|)
name|dp
operator|=
operator|(
expr|struct
name|databuf
operator|*
operator|)
ifdef|#
directive|ifdef
name|DMALLOC
name|dmalloc
argument_list|(
argument|file
argument_list|,
argument|line
argument_list|,
else|#
directive|else
argument|malloc(
endif|#
directive|endif
argument|(unsigned)DATASIZE(size)+sizeof(u_int32_t)); 	else 		dp = (struct databuf *)
ifdef|#
directive|ifdef
name|DMALLOC
argument|dmalloc(file, line,
else|#
directive|else
argument|malloc(
endif|#
directive|endif
argument|(unsigned)DATASIZE(size)); 	if (dp == NULL) { 		syslog(LOG_ERR,
literal|"savedata: %m"
argument|); 		exit(
literal|1
argument|); 	} 	dp->d_next = NULL; 	dp->d_type = type; 	dp->d_class = class; 	dp->d_ttl = ttl; 	dp->d_size = size; 	dp->d_mark =
literal|0
argument|; 	dp->d_flags =
literal|0
argument|;
ifdef|#
directive|ifdef
name|CRED
argument|dp->d_cred =
literal|0
argument|; 	dp->d_clev =
literal|0
argument|;
endif|#
directive|endif
comment|/*CRED*/
ifdef|#
directive|ifdef
name|NCACHE
argument|dp->d_rcode = NOERROR;
endif|#
directive|endif
comment|/*NCACHE*/
argument|dp->d_nstime =
literal|0
argument|; 	bcopy(data, dp->d_data, dp->d_size); 	return (dp); }  int hashsizes[] = {
comment|/* hashtable sizes */
literal|2
argument|,
literal|11
argument|,
literal|113
argument|,
literal|337
argument|,
literal|977
argument|,
literal|2053
argument|,
literal|4073
argument|,
literal|8011
argument|,
literal|16001
argument|,
literal|0
argument|};
comment|/*  * Allocate a data buffer& save data.  */
argument|struct hashbuf * savehash(oldhtp) 	register struct hashbuf *oldhtp; { 	register struct hashbuf *htp; 	register struct namebuf *np, *nnp, **hp; 	register int n; 	int newsize;  	if (oldhtp == NULL) 		newsize = hashsizes[
literal|0
argument|]; 	else { 		for (n =
literal|0
argument|; newsize = hashsizes[n++]; ) 			if (oldhtp->h_size == newsize) { 				newsize = hashsizes[n]; 				break; 			} 		if (newsize ==
literal|0
argument|) 			newsize = oldhtp->h_size *
literal|2
argument|+
literal|1
argument|; 	} 	dprintf(
literal|4
argument|, (ddt,
literal|"savehash GROWING to %d\n"
argument|, newsize)); 	htp = (struct hashbuf *) malloc((unsigned)HASHSIZE(newsize)); 	if (htp == NULL) { 		syslog(LOG_ERR,
literal|"savehash: %m"
argument|); 		exit(
literal|1
argument|); 	} 	htp->h_size = newsize; 	bzero((char *) htp->h_tab, newsize * sizeof(struct namebuf *)); 	if (oldhtp == NULL) { 		htp->h_cnt =
literal|0
argument|; 		return (htp); 	} 	dprintf(
literal|4
argument|, (ddt,
literal|"savehash(%#x) cnt=%d, sz=%d, newsz=%d\n"
argument|, 		    oldhtp, oldhtp->h_cnt, oldhtp->h_size, newsize)); 	htp->h_cnt = oldhtp->h_cnt; 	for (n =
literal|0
argument|; n< oldhtp->h_size; n++) { 		for (np = oldhtp->h_tab[n]; np != NULL; np = nnp) { 			nnp = np->n_next; 			hp =&htp->h_tab[np->n_hashval % htp->h_size]; 			np->n_next = *hp; 			*hp = np; 		} 	} 	free((char *) oldhtp); 	return (htp); }
end_function

end_unit

