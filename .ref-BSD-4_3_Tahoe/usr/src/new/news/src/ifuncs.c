begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is Copyright (c) 1986 by Rick Adams.  *  * Permission is hereby granted to copy, reproduce, redistribute or  * otherwise use this software as long as: there is no monetary  * profit gained specifically from the use or reproduction or this  * software, it is not sold, rented, traded or otherwise marketed, and  * this copyright notice is included prominently in any copy  * made.  *  * The author make no claims as to the fitness or correctness of  * this software for any use whatsoever, and it is provided as is.   * Any use of this software is at the user's own risk.  *  * ifuncs - functions used by inews.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)ifuncs.c	2.66	10/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_include
include|#
directive|include
file|"iparams.h"
end_include

begin_function_decl
specifier|extern
name|long
name|localize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  * Transmit this article to all interested systems.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|u370
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|srec
name|srec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u370 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|hbuf
name|h
decl_stmt|,
name|hh
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MULTICAST
end_ifdef

begin_define
define|#
directive|define
name|MAXMCAST
value|20
end_define

begin_define
define|#
directive|define
name|MAXMCS
value|10
end_define

begin_struct
struct|struct
name|multicast
block|{
name|char
name|mc_name
index|[
name|SBUFLEN
index|]
decl_stmt|;
comment|/* "multi-cast" name */
name|short
name|mc_syscnt
decl_stmt|;
name|char
name|mc_tosys
index|[
name|MAXMCAST
index|]
index|[
name|SBUFLEN
index|]
decl_stmt|;
block|}
name|mcast
index|[
name|MAXMCS
index|]
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|mccount
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTICAST */
end_comment

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DBM
end_ifndef

begin_function_decl
name|char
modifier|*
name|histfile
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DBM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/*  * For VMS/Eunice there are no links: article was moved to firstbufname  * before broadcast is reached.  So we read it from there.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|firstbufname
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GENERICPATH
end_ifndef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !GENERICPATH */
end_comment

begin_macro
name|broadcast
argument_list|(
argument|is_rnews
argument_list|)
end_macro

begin_decl_stmt
name|int
name|is_rnews
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|hptr
decl_stmt|;
specifier|register
name|char
modifier|*
name|sptr
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
ifndef|#
directive|ifndef
name|u370
name|struct
name|srec
name|srec
decl_stmt|;
endif|#
directive|endif
name|char
name|sentbuf
index|[
name|LBUFLEN
index|]
decl_stmt|;
name|int
name|nsent
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|sentsys
decl_stmt|;
ifdef|#
directive|ifdef
name|GENERICPATH
name|int
name|len
decl_stmt|;
endif|#
directive|endif
comment|/* GENERICPATH */
comment|/* h is a local copy of the header we can scribble on */
ifdef|#
directive|ifdef
name|VMS
name|fp
operator|=
name|xfopen
argument_list|(
name|firstbufname
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
else|#
directive|else
name|fp
operator|=
name|xfopen
argument_list|(
name|ARTICLE
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hread
argument_list|(
operator|&
name|h
argument_list|,
name|fp
argument_list|,
name|TRUE
argument_list|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot reread article"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|sentbuf
argument_list|,
name|h
operator|.
name|ident
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|sentbuf
argument_list|,
literal|" sent to "
argument_list|)
expr_stmt|;
name|sentsys
operator|=
name|index
argument_list|(
name|sentbuf
argument_list|,
literal|'\0'
argument_list|)
expr_stmt|;
name|nsent
operator|=
literal|0
expr_stmt|;
comment|/* break path into list of systems. */
name|hptr
operator|=
name|h
operator|.
name|path
expr_stmt|;
ifdef|#
directive|ifdef
name|GENERICPATH
if|if
condition|(
operator|!
name|is_rnews
operator|&&
name|STRNCMP
argument_list|(
name|PATHSYSNAME
argument_list|,
name|h
operator|.
name|path
argument_list|,
operator|(
name|len
operator|=
name|strlen
argument_list|(
name|PATHSYSNAME
argument_list|)
operator|)
argument_list|)
operator|==
literal|0
operator|&&
name|index
argument_list|(
name|NETCHRS
argument_list|,
name|h
operator|.
name|path
index|[
name|len
index|]
argument_list|)
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|h
operator|.
name|path
argument_list|,
operator|&
operator|(
name|h
operator|.
name|path
index|[
name|len
operator|+
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* GENERICPATH */
name|sptr
operator|=
name|hptr
operator|=
name|h
operator|.
name|path
expr_stmt|;
while|while
condition|(
operator|(
name|hptr
operator|=
name|strpbrk
argument_list|(
name|hptr
argument_list|,
name|NETCHRS
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|hptr
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|sptr
operator|=
name|hptr
expr_stmt|;
block|}
operator|*
name|sptr
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|MULTICAST
name|mccount
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* MULTICAST */
comment|/* loop once per system. */
name|s_openr
argument_list|()
expr_stmt|;
while|while
condition|(
name|s_read
argument_list|(
operator|&
name|srec
argument_list|)
condition|)
block|{
name|char
modifier|*
name|dist
init|=
name|h
operator|.
name|distribution
decl_stmt|;
if|if
condition|(
name|STRNCMP
argument_list|(
name|srec
operator|.
name|s_name
argument_list|,
name|LOCALPATHSYSNAME
argument_list|,
name|SNLN
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
if|if
condition|(
name|sptr
operator|=
name|srec
operator|.
name|s_nosend
condition|)
block|{
while|while
condition|(
operator|*
name|sptr
condition|)
block|{
while|while
condition|(
operator|*
name|sptr
operator|&&
operator|*
name|sptr
operator|!=
literal|','
condition|)
name|sptr
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|sptr
operator|==
literal|','
condition|)
operator|*
name|sptr
operator|++
operator|=
literal|'\0'
expr_stmt|;
block|}
operator|*
operator|++
name|sptr
operator|=
literal|'\0'
expr_stmt|;
block|}
name|hptr
operator|=
name|h
operator|.
name|path
expr_stmt|;
while|while
condition|(
operator|*
name|hptr
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|STRNCMP
argument_list|(
name|srec
operator|.
name|s_name
argument_list|,
name|hptr
argument_list|,
name|SNLN
argument_list|)
operator|==
literal|0
condition|)
goto|goto
name|contin
goto|;
if|if
condition|(
name|sptr
operator|=
name|srec
operator|.
name|s_nosend
condition|)
block|{
while|while
condition|(
operator|*
name|sptr
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|STRNCMP
argument_list|(
name|sptr
argument_list|,
name|hptr
argument_list|,
name|SNLN
argument_list|)
operator|==
literal|0
condition|)
goto|goto
name|contin
goto|;
while|while
condition|(
operator|*
name|sptr
operator|++
condition|)
empty_stmt|;
block|}
block|}
while|while
condition|(
operator|*
name|hptr
operator|++
operator|!=
literal|'\0'
condition|)
empty_stmt|;
block|}
if|if
condition|(
operator|!
name|ngmatch
argument_list|(
name|h
operator|.
name|nbuf
argument_list|,
name|srec
operator|.
name|s_nbuf
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|*
name|dist
operator|==
literal|'\0'
condition|)
name|dist
operator|=
literal|"world"
expr_stmt|;
if|if
condition|(
operator|!
name|ngmatch
argument_list|(
name|dist
argument_list|,
name|srec
operator|.
name|s_nbuf
argument_list|)
operator|&&
operator|!
name|ngmatch
argument_list|(
name|srec
operator|.
name|s_nbuf
argument_list|,
name|dist
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|nsent
condition|)
block|{
name|hptr
operator|=
name|sentsys
expr_stmt|;
while|while
condition|(
operator|(
name|sptr
operator|=
name|index
argument_list|(
name|hptr
argument_list|,
literal|','
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|sptr
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|STRCMP
argument_list|(
name|hptr
argument_list|,
name|srec
operator|.
name|s_name
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|*
name|sptr
operator|=
literal|','
expr_stmt|;
goto|goto
name|contin
goto|;
block|}
operator|*
name|sptr
operator|++
operator|=
literal|','
expr_stmt|;
for|for
control|(
name|hptr
operator|=
name|sptr
init|;
name|isspace
argument_list|(
operator|*
name|hptr
argument_list|)
condition|;
name|hptr
operator|++
control|)
empty_stmt|;
block|}
if|if
condition|(
name|STRCMP
argument_list|(
name|hptr
argument_list|,
name|srec
operator|.
name|s_name
argument_list|)
operator|==
literal|0
condition|)
continue|continue;
block|}
comment|/* now we've found a system to send this article to */
ifdef|#
directive|ifdef
name|MULTICAST
if|if
condition|(
name|index
argument_list|(
name|srec
operator|.
name|s_flags
argument_list|,
literal|'M'
argument_list|)
condition|)
block|{
comment|/* do a "multi-cast" transmit */
specifier|register
name|struct
name|multicast
modifier|*
name|m
decl_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|srec
operator|.
name|s_name
argument_list|)
operator|>=
name|SBUFLEN
operator|||
name|strlen
argument_list|(
name|srec
operator|.
name|s_xmit
argument_list|)
operator|>=
name|SBUFLEN
condition|)
name|xerror
argument_list|(
literal|"system name too long for multicast"
argument_list|)
expr_stmt|;
for|for
control|(
name|m
operator|=
name|mcast
init|;
name|m
operator|<
operator|&
name|mcast
index|[
name|mccount
index|]
condition|;
name|m
operator|++
control|)
if|if
condition|(
name|STRCMP
argument_list|(
name|srec
operator|.
name|s_xmit
argument_list|,
name|m
operator|->
name|mc_name
argument_list|)
operator|==
literal|0
condition|)
break|break;
if|if
condition|(
name|m
operator|>=
operator|&
name|mcast
index|[
name|MAXMCS
index|]
condition|)
name|xerror
argument_list|(
literal|"Too many multicasts"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
operator|&
name|mcast
index|[
name|mccount
index|]
condition|)
block|{
name|mccount
operator|++
expr_stmt|;
name|m
operator|->
name|mc_syscnt
operator|=
literal|0
expr_stmt|;
name|strcpy
argument_list|(
name|m
operator|->
name|mc_name
argument_list|,
name|srec
operator|.
name|s_xmit
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m
operator|->
name|mc_syscnt
operator|>=
name|MAXMCAST
condition|)
name|xerror
argument_list|(
literal|"Too many systems for multicast"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|m
operator|->
name|mc_tosys
index|[
name|m
operator|->
name|mc_syscnt
operator|++
index|]
argument_list|,
name|srec
operator|.
name|s_name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|register
name|struct
name|multicast
modifier|*
name|m
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|yptr
decl_stmt|;
name|char
modifier|*
name|sysptrs
index|[
name|MAXMCAST
index|]
decl_stmt|;
name|int
name|mc
decl_stmt|;
name|mc
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|m
operator|=
name|mcast
init|;
name|m
operator|<
operator|&
name|mcast
index|[
name|mccount
index|]
condition|;
name|m
operator|++
control|)
if|if
condition|(
name|STRCMP
argument_list|(
name|m
operator|->
name|mc_name
argument_list|,
name|srec
operator|.
name|s_name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|yptr
operator|=
name|sysptrs
expr_stmt|;
while|while
condition|(
name|mc
operator|<
name|m
operator|->
name|mc_syscnt
condition|)
operator|*
name|yptr
operator|++
operator|=
name|m
operator|->
name|mc_tosys
index|[
name|mc
operator|++
index|]
expr_stmt|;
break|break;
block|}
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
operator|!
name|transmit
argument_list|(
argument|&srec
argument_list|,
argument|xfopen(firstbufname,
literal|"r"
argument|)
argument_list|,
else|#
directive|else
comment|/* !VMS */
argument|if (!transmit(&srec, xfopen(ARTICLE,
literal|"r"
argument|),
endif|#
directive|endif
comment|/* !VMS */
argument|(STRNCMP(h.nbuf,
literal|"to."
argument|,
literal|3
argument|) !=
literal|0
argument|), 				sysptrs, mc)) 				continue; 		}
else|#
directive|else
comment|/* !MULTICAST */
ifdef|#
directive|ifdef
name|VMS
argument|if (!transmit(&srec, xfopen(firstbufname,
literal|"r"
argument|),
else|#
directive|else
comment|/* !VMS */
argument|if (!transmit(&srec, xfopen(ARTICLE,
literal|"r"
argument|),
endif|#
directive|endif
comment|/* !VMS */
argument|(STRNCMP(h.nbuf,
literal|"to."
argument|,
literal|3
argument|) !=
literal|0
argument|), 			(char **) NULL, FALSE)) 				continue;
endif|#
directive|endif
comment|/* !MULTICAST */
argument|if (nsent) 			(void) strcat(sentbuf,
literal|", "
argument|); 		(void) strcat(sentbuf, srec.s_name); 		nsent++; 	contin:; 	} 	if (nsent) 		log(sentbuf); 	s_close(); }
comment|/*  * Transmit file to system.  */
define|#
directive|define
name|PROC
value|0004
ifndef|#
directive|ifndef
name|MULTICAST
comment|/* ARGSUSED */
endif|#
directive|endif
comment|/* !MULTICAST */
argument|transmit(sp, ifp, maynotify, sysnames, mc) register struct srec *sp; register FILE *ifp; int maynotify; char **sysnames; int mc; { 	register FILE *ofp; 	register int c; 	register char *ptr; 	char TRANS[BUFLEN]; 	char *argv[
literal|20
argument|]; 	register int pid; 	extern char firstbufname[];
comment|/* A:	afmt: the other machine runs an A news, so we xmit in A format */
argument|int afmt = (index(sp->s_flags,
literal|'A'
argument|) != NULL);
comment|/* B:	use B format (this is the default - don't use this letter elsewise). */
comment|/* F:	append name to file */
argument|int appfile = (index(sp->s_flags,
literal|'F'
argument|) != NULL);
comment|/* L:	local: don't send the article unless it was generated locally */
argument|int local = ((ptr = index(sp->s_flags,
literal|'L'
argument|)) != NULL);
comment|/* H:	interpolate history line into command, use existing file */
argument|int history = (index(sp->s_flags,
literal|'H'
argument|) != NULL);
comment|/* m:	moderated: only send if group is moderated */
argument|int sendifmoderated = (index(sp->s_flags,
literal|'m'
argument|) != NULL);
comment|/* u:	unmoderated: only send if group is unmoderated */
argument|int sendifunmoderated = (index(sp->s_flags,
literal|'u'
argument|) != NULL);
comment|/* M:	multi-cast: this is taken care of above, but don't reuse flag */
ifdef|#
directive|ifdef
name|MULTICAST
comment|/* O:	multi-cast only, don't send article if not multicast hosts */
argument|int multisend = (index(sp->s_flags,
literal|'O'
argument|) != NULL);
endif|#
directive|endif
comment|/* MULTICAST */
comment|/* N:	notify: don't send the article, just tell him we have it */
argument|int notify = maynotify&& (index(sp->s_flags,
literal|'N'
argument|) != NULL);
comment|/* S:	noshell: don't fork a shell to execute the xmit command */
argument|int noshell = (index(sp->s_flags,
literal|'S'
argument|) != NULL);
comment|/* U:	useexist: use the -c option to uux to use the existing copy */
argument|int useexist = (index(sp->s_flags,
literal|'U'
argument|) != NULL);
comment|/* I:	append messageid to file. implies F flag */
argument|int appmsgid = maynotify&& (index(sp->s_flags,
literal|'I'
argument|) != NULL);  	if (notify) 		appfile = appmsgid = FALSE;  	if (local&& mode == PROC) { 		local =
literal|0
argument|; 		while (isdigit(*++ptr)) 			local = local *
literal|10
argument|+ *ptr -
literal|'0'
argument|; 		for (ptr = h.path; *ptr !=
literal|'\0'
argument|&& local>=
literal|0
argument|; local--) 			while (*ptr++ !=
literal|'\0'
argument|) 				; 		if (local<
literal|0
argument|) { 			(void) fclose(ifp); 			return FALSE; 		} 	}
comment|/* 	** Do not transmit to system specified in -x flag. 	*/
argument|if (not_here[
literal|0
argument|]&& STRCMP(not_here, sp->s_name) ==
literal|0
argument|) { 		(void) fclose(ifp); 		return FALSE; 	}
ifdef|#
directive|ifdef
name|DEBUG
argument|printf(
literal|"Transmitting to '%s'\n"
argument|, sp->s_name);
endif|#
directive|endif
comment|/* DEBUG */
ifdef|#
directive|ifdef
name|MULTICAST
argument|if (multisend&& mc ==
literal|0
argument|) { 		(void) fclose(ifp); 		return FALSE; 	}
endif|#
directive|endif
comment|/* MULTICAST */
argument|if ((sendifmoderated&& is_mod[
literal|0
argument|] ==
literal|'\0'
argument|) || 	    (sendifunmoderated&& is_mod[
literal|0
argument|] !=
literal|'\0'
argument|)) { 		fclose(ifp); 		return FALSE; 	}  	if (appmsgid || (!appfile&& !useexist&& !history)) { 		if (!hread(&hh, ifp, TRUE)) { 			logerr(
literal|"Bad header, not transmitting %s re %s to %s"
argument|, 				hh.ident, hh.title, sp->s_name); 			(void) fclose(ifp); 			return FALSE; 		} 		if (hh.nbuf[
literal|0
argument|] ==
literal|'\0'
argument|) { 			fprintf(stderr,
literal|"Article not subscribed to by %s\n"
argument|, sp->s_name); 			(void) fclose(ifp); 			return FALSE; 		} 		(void) sprintf(TRANS,
literal|"%s/trXXXXXX"
argument|, SPOOL); 	}  	if (notify) { 		char oldid[
literal|50
argument|]; 		(void) sprintf(hh.title,
literal|"ihave %s %s"
argument|, hh.ident, PATHSYSNAME); 		(void) strcpy(hh.ctlmsg, hh.title); 		(void) strcpy(hh.numlines,
literal|"0"
argument|); 		(void) sprintf(hh.nbuf,
literal|"to.%s.ctl"
argument|, sp->s_name); 		(void) strcpy(oldid, hh.ident); 		getident(&hh); 		log(
literal|"tell %s about %s, notif. id %s"
argument|, 			sp->s_name, oldid, hh.ident); 	}  	if (appfile || appmsgid) { 		if (firstbufname[
literal|0
argument|] ==
literal|'\0'
argument|) { 			extern char histline[]; 			localize(
literal|"junk"
argument|); 			savehist(histline); 			xerror(
literal|"No file name to xmit from"
argument|); 		} 		if (sp->s_xmit[
literal|0
argument|] ==
literal|'\0'
argument|) 			sprintf(sp->s_xmit,
literal|"%s/%s%s"
argument|, BATCHDIR, sp->s_name, 				appmsgid ?
literal|".ihave"
argument|:
literal|""
argument|);
ifdef|#
directive|ifdef
name|LOGDIR
argument|(void) sprintf(TRANS,
literal|"%s/%s/%s"
argument|, logdir(HOME), BATCHDIR, sp->s_xmit); 		ofp = fopen(TRANS,
literal|"a"
argument|);
else|#
directive|else
comment|/* !LOGDIR */
argument|ofp = fopen(sp->s_xmit,
literal|"a"
argument|);
endif|#
directive|endif
comment|/* !LOGDIR */
argument|if (ofp == NULL) 			xerror(
literal|"Cannot append to %s"
argument|, sp->s_xmit); 		fprintf(ofp,
literal|"%s"
argument|, appmsgid ? hh.ident : firstbufname);
ifdef|#
directive|ifdef
name|MULTICAST
argument|while (--mc>=
literal|0
argument|) 			fprintf(ofp,
literal|" %s"
argument|, *sysnames++);
endif|#
directive|endif
comment|/* !MULTICAST */
argument|putc(
literal|'\n'
argument|, ofp); 		(void) fclose(ofp); 		(void) fclose(ifp); 		return TRUE; 	} 	else if (useexist) { 		if (firstbufname[
literal|0
argument|] ==
literal|'\0'
argument|) 			xerror(
literal|"No file name to xmit from"
argument|); 		if (*sp->s_xmit ==
literal|'\0'
argument|)
ifdef|#
directive|ifdef
name|UXMIT
argument|(void) sprintf(bfr, UXMIT, sp->s_name, firstbufname);
else|#
directive|else
argument|xerror(
literal|"UXMIT not defined for U flag"
argument|);
endif|#
directive|endif
argument|else
ifdef|#
directive|ifdef
name|MULTICAST
argument|makeargs(bfr, sp->s_xmit, firstbufname, sysnames, mc);
else|#
directive|else
argument|(void) sprintf(bfr, sp->s_xmit, firstbufname);
endif|#
directive|endif
argument|(void) fclose(ifp); 	} else if (history) { 		extern char histline[];  		if (*sp->s_xmit ==
literal|'\0'
argument|) 			xerror(
literal|"no xmit command with H flag"
argument|);
ifdef|#
directive|ifdef
name|MULTICAST
argument|makeargs(bfr, sp->s_xmit, histline, sysnames, mc);
else|#
directive|else
argument|(void) sprintf(bfr, sp->s_xmit, histline);
endif|#
directive|endif
argument|} else { 		ofp = xfopen(mktemp(TRANS),
literal|"w"
argument|); 		if (afmt) {
ifdef|#
directive|ifdef
name|OLD
argument|fprintf(ofp,
literal|"A%s\n%s\n%s!%s\n%s\n%s\n"
argument|, oident(hh.ident), hh.nbuf, PATHSYSNAME, 				hh.path, hh.subdate, hh.title);
else|#
directive|else
comment|/* !OLD */
argument|logerr(
literal|"Must have OLD defined to use A flag for xmit"
argument|); 			return FALSE;
endif|#
directive|endif
comment|/* !OLD */
argument|} else 			hwrite(&hh, ofp); 		if (!notify) 			while ((c = getc(ifp)) != EOF) 				putc(c, ofp); 		if (ferror(ofp)) 			xerror(
literal|"write failed on transmit"
argument|); 		(void) fclose(ifp); 		(void) fclose(ofp); 		if (*sp->s_xmit ==
literal|'\0'
argument|) 			(void) sprintf(bfr, DFTXMIT, sp->s_name, TRANS); 		else
ifdef|#
directive|ifdef
name|MULTICAST
argument|makeargs(bfr, sp->s_xmit, TRANS, sysnames, mc);
else|#
directive|else
comment|/* !MULTICAST */
argument|(void) sprintf(bfr, sp->s_xmit, TRANS);
endif|#
directive|endif
comment|/* !MULTICAST */
argument|}
comment|/* At this point, the command to be executed is in bfr. */
argument|if (noshell) { 		if (pid = vfork()) 			fwait(pid); 		else { 			(void) close(
literal|0
argument|); 			(void) open(TRANS,
literal|0
argument|); 			ptr = bfr; 			for (pid =
literal|0
argument|; pid<
literal|19
argument|; pid++) { 				while (isspace(*ptr)) 					*ptr++ =
literal|0
argument|; 				argv[pid] = ptr; 				while (!isspace(*++ptr)&& *ptr) 					; 				if (!*ptr) 					break; 			} 			argv[++pid] =
literal|0
argument|; 			(void) setgid(gid); 			(void) setuid(uid); 			execvp(argv[
literal|0
argument|], argv); 			xerror(
literal|"Can't execv %s"
argument|, argv[
literal|0
argument|]); 		} 	} else { 		if (!history&& sp->s_xmit[
literal|0
argument|]&& !index(bfr,
literal|'<'
argument|)) { 			char newcmd[LBUFLEN];  			(void) sprintf(newcmd,
literal|"(%s)<%s"
argument|, bfr, 			    useexist ? firstbufname : TRANS); 			system(newcmd); 		} else 			system(bfr); 	} 	if (!appfile&& !useexist&& !history) 		(void) unlink(TRANS); 	(void) fclose(ifp); 	return TRUE; }
ifdef|#
directive|ifdef
name|MULTICAST
argument|makeargs(buf, cmd, arg2, sysargs, sac) char *buf; char *cmd; char *arg2; register char **sysargs; int sac; { 	register char *p = cmd; 	register char *q; 	register ac =
literal|0
argument|; 	register char *b = buf;  	q = p; 	do { 		if (q = index(q,
literal|' '
argument|)) 			*q =
literal|'\0'
argument|; 		if (index(p,
literal|'%'
argument|)) { 			switch (++ac) { 			case
literal|1
argument|: 				while (--sac>=
literal|0
argument|) { 					sprintf(b, p, *sysargs++); 					b = index(b,
literal|'\0'
argument|); 				} 				break; 			case
literal|2
argument|: 				sprintf(b, p, arg2); 				b = index(b,
literal|'\0'
argument|); 				break; 			default: 				if (q) 					*q =
literal|' '
argument|; 				xerror(
literal|"badly formed command: %s"
argument|, cmd); 			} 		} else { 			strcpy(b, p); 			b = index(b,
literal|'\0'
argument|); 		} 		if (q) { 			*q =
literal|' '
argument|; 			p = q; 			while (isspace(*q)) 				q++; 		} 	} while (q != NULL); }
endif|#
directive|endif
comment|/* MULTICAST */
comment|/*  * Return TRUE if we have seen this file before, else FALSE.  */
argument|history(hp) struct hbuf *hp; {
ifdef|#
directive|ifdef
name|DBM
argument|datum lhs, rhs; 	datum fetch();
else|#
directive|else
comment|/* !DBM */
argument|register FILE *hfp; 	register char *p;
endif|#
directive|endif
comment|/* !DBM */
argument|char lcident[BUFLEN]; 	extern char histline[];
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(stderr,
literal|"history(%s)\n"
argument|, hp->ident);
endif|#
directive|endif
comment|/* DEBUG */
comment|/* 	 * Make the article ID case insensitive. 	 */
argument|(void) strcpy(lcident, hp->ident); 	lcase(lcident);  	idlock(lcident);
ifdef|#
directive|ifdef
name|DBM
argument|initdbm(ARTFILE); 	lhs.dptr = lcident; 	lhs.dsize = strlen(lhs.dptr) +
literal|1
argument|; 	rhs = fetch(lhs); 	if (rhs.dptr) { 		idunlock(); 		return(TRUE); 	}
else|#
directive|else
comment|/* !DBM */
argument|hfp = xfopen(histfile(lcident),
literal|"r"
argument|); 	while (fgets(bfr, BUFLEN, hfp) != NULL) { 		p = index(bfr,
literal|'\t'
argument|); 		if (p == NULL) 			p = index(bfr,
literal|'\n'
argument|); 		if (p != NULL)
comment|/* can happen if nulls in file */
argument|*p =
literal|0
argument|; 		lcase(bfr);  		if (STRCMP(bfr, lcident) ==
literal|0
argument|) { 			(void) fclose(hfp); 			idunlock();
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(stderr,
literal|"history returns true\n"
argument|);
endif|#
directive|endif
comment|/* DEBUG */
argument|return TRUE; 		} 	} 	(void) fclose(hfp);
endif|#
directive|endif
comment|/* !DBM */
argument|histline[
literal|0
argument|] =
literal|'\0'
argument|; 	addhist(hp->ident); 	addhist(
literal|"\t"
argument|);
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(stderr,
literal|"history returns false\n"
argument|);
endif|#
directive|endif
argument|return FALSE; }  char histline[PATHLEN];  addhist(msg) char *msg; { 	(void) strcat(histline, msg); }  savehist(hline) char *hline; { 	register FILE *hfp; 	register char *p;
ifdef|#
directive|ifdef
name|DBM
argument|long fpos;
endif|#
directive|endif
comment|/* !DBM */
ifndef|#
directive|ifndef
name|DBM
argument|if (STRCMP((p = histfile(hline)), ARTFILE) !=
literal|0
argument|) {
comment|/* If the history subfile is accessible */
argument|if ((hfp = xfopen(p,
literal|"a"
argument|)) != NULL ) {
comment|/* If we can append */
argument|fprintf(hfp,
literal|"%s\n"
argument|, hline);
comment|/* Append */
argument|(void) fclose(hfp); 		} else 			logerr(
literal|"Unable to append to %s: %s"
argument|, p, errmsg(errno)); 	} else
endif|#
directive|endif
comment|/* !DBM */
argument|{ 	hfp = xfopen(ARTFILE,
literal|"a"
argument|); 	(void) fseek(hfp,
literal|0L
argument|,
literal|2
argument|);
comment|/* Unisoft 5.1 doesn't seek to EOF on 'a' */
ifdef|#
directive|ifdef
name|DBM
argument|fpos = ftell(hfp);
endif|#
directive|endif
comment|/* !DBM */
argument|fprintf(hfp,
literal|"%s\n"
argument|, hline); 	(void) fclose(hfp); 	}
ifdef|#
directive|ifdef
name|DBM
argument|{ 	datum lhs, rhs;
comment|/* We assume that history has already been called, calling dbminit. */
argument|p = index(hline,
literal|'\t'
argument|); 	if (p) 		*p =
literal|0
argument|; 	lcase(hline); 	lhs.dptr = hline; 	lhs.dsize = strlen(lhs.dptr) +
literal|1
argument|; 	rhs.dptr = (char *)&fpos; 	rhs.dsize = sizeof fpos; 	store(lhs, rhs); 	}
endif|#
directive|endif
comment|/* DBM */
argument|idunlock(); }
comment|/*  * Save partial news.  */
comment|/* ARGSUSED */
argument|newssave(fd, dummy) FILE *fd; char *dummy; { 	register FILE *tofd, *fromfd; 	char sfname[BUFLEN]; 	register int c; 	time_t tim;  	if (fd == NULL) 		fromfd = xfopen(INFILE,
literal|"r"
argument|); 	else 		fromfd = fd; 	(void) umask(savmask); 	(void) setgid(gid); 	(void) setuid(uid);  	(void) sprintf(sfname,
literal|"%s/%s"
argument|, userhome, PARTIAL); 	if ((tofd = fopen(sfname,
literal|"a"
argument|)) == NULL) 		xerror(
literal|"Cannot save partial news in %s"
argument|, sfname); 	(void) time(&tim); 	fprintf(tofd,
literal|"----- News saved at %s\n"
argument|, arpadate(&tim)); 	while ((c = getc(fromfd)) != EOF) 		putc(c, tofd); 	(void) fclose(fromfd); 	(void) fclose(tofd); 	printf(
literal|"News saved in %s\n"
argument|, sfname); 	xxit(
literal|1
argument|); }
comment|/*  * Handle dates in header.  */
argument|dates(hp) struct hbuf *hp; { 	time_t edt;  	if (*hp->subdate) { 		if (cgtdate(hp->subdate)<
literal|0
argument|) { 			error(
literal|"Cannot parse submittal date '%s'"
argument|, hp->subdate); 		} 	} else { 		(void) time(&edt); 		(void) strcpy(hp->subdate, arpadate(&edt)); 	} }
define|#
directive|define
name|LOCKSIZE
value|128
argument|char lockname[LOCKSIZE];  idlock(str) char *str; { 	register int i; 	register char *cp, *scp; 	char tempname[LOCKSIZE]; 	time_t now; 	struct stat sbuf; 	extern int errno;
ifdef|#
directive|ifdef
name|VMS
argument|int fd;
comment|/* The name here is because of the peculiar properties of version numbers  * in Eunice.  We eliminate any troublesome characters also.  */
argument|(void) sprintf(lockname,
literal|"/tmp/%.10s.l.1"
argument|, str); 	for (cp = lockname; *cp; cp++) 		if (*cp ==
literal|'/'
argument||| *cp ==
literal|'['
argument||| *cp ==
literal|']'
argument|) *cp =
literal|'.'
argument|; 	while ((fd = creat(lockname,
literal|0444
argument|))<
literal|0
argument|) {
else|#
directive|else
comment|/* !VMS */
argument|(void) strcpy(tempname,
literal|"/tmp/LTMP.XXXXXX"
argument|); 	(void) mktemp(tempname); 	(void) strcpy(lockname,
literal|"/tmp/L"
argument|); 	i = strlen(lockname); 	cp =&lockname[i]; 	scp = str -
literal|1
argument|; 	while (i++< LOCKSIZE&& *++scp !=
literal|'\0'
argument|) 		if (*scp ==
literal|'/'
argument|)
comment|/* slash screws up the open */
argument|*cp++ =
literal|'.'
argument|; 		else 			*cp++ = *scp; 	*cp =
literal|'\0'
argument|;
ifdef|#
directive|ifdef
name|FOURTEENMAX
argument|lockname[
literal|5
comment|/* /tmp/ */
argument|+
literal|14
argument|] =
literal|'\0'
argument|;
endif|#
directive|endif
argument|i = creat(tempname,
literal|0666
argument|); 	if (i<
literal|0
argument|) 		xerror(
literal|"Cannot creat %s: errno %d"
argument|, tempname, errno); 	(void) close(i); 	while (link(tempname, lockname)) {
endif|#
directive|endif
comment|/* !VMS */
argument|(void) time(&now); 		if (stat(lockname,&sbuf)<
literal|0
argument|) 			xerror(
literal|"Directory permission problem in /tmp"
argument|);  		if (sbuf.st_mtime +
literal|10
argument|*
literal|60
argument|< now) { 			(void) unlink(lockname); 			logerr(
literal|"Article %s locked up"
argument|, str); 			break; 		} 		log(
literal|"waiting on lock for %s"
argument|, lockname); 		sleep((unsigned)
literal|60
argument|); 	}
ifdef|#
directive|ifdef
name|VMS
argument|(void) close(fd);
endif|#
directive|endif
argument|(void) unlink(tempname); }  idunlock() { 	(void) unlink(lockname); }
comment|/*  * Put a unique name into header.ident.  */
argument|getident(hp) struct hbuf *hp; { 	long seqn; 	register FILE *fp; 	extern char *mydomain();  	lock(); 	fp = xfopen(SEQFILE,
literal|"r"
argument|); 	(void) fgets(bfr, BUFLEN, fp); 	(void) fclose(fp); 	seqn = atol(bfr) +
literal|1
argument|;
comment|/*  * For Eunice, this breaks if SEQFILE is not in Unix format.  */
argument|fp = xfopen(SEQFILE,
literal|"r+w"
argument|); 	fprintf(fp,
literal|"%ld\n"
argument|, seqn); 	(void) fclose(fp); 	unlock(); 	(void) sprintf(hp->ident,
literal|"<%ld@%s>"
argument|, seqn, LOCALSYSNAME); }
comment|/*  * Check that header.nbuf contains only valid newsgroup names;  * exit with error if not valid.  */
argument|ngfcheck(isproc) { 	register FILE *	f; 	register char *	cp; 	register int	i, j; 	register int	ngcount, okcount, havealiased; 	register int	pass; 	char *		ngs[sizeof header.nbuf /
literal|2
argument|]; 	char		uses[sizeof header.nbuf /
literal|2
argument|]; 	char		tbuf[sizeof header.nbuf]; 	char		abuf[BUFLEN];  	havealiased = ngcount =
literal|0
argument|; 	is_mod[
literal|0
argument|] =
literal|'\0'
argument|;
comment|/* 	** Split header.nbuf into constituent newsgroups. 	** Zap "local" newsgroups of articles from remote sites. 	*/
argument|cp = tbuf; 	(void) strcpy(cp, header.nbuf); 	for ( ; ; ) { 		while (*cp == NGDELIM || *cp ==
literal|' '
argument|) 			++cp; 		if (*cp ==
literal|'\0'
argument|) 			break; 		ngs[ngcount] = cp; 		do { 			++cp; 		} while (*cp !=
literal|'\0'
argument|&& *cp != NGDELIM&& *cp !=
literal|' '
argument|); 		if (*cp !=
literal|'\0'
argument|) 			*cp++ =
literal|'\0'
argument|;
comment|/* 		** Check for local only distribution on incoming 		** newsgroups.  This might occur if someone posted to 		** general,net.unix 		*/
argument|if (isproc&& index(ngs[ngcount],
literal|'.'
argument|) == NULL&& 			index(header.nbuf,
literal|'.'
argument|) != NULL) { 				logerr(
literal|"Local group %s removed"
argument|, 					ngs[ngcount]); 				continue; 		} 		uses[ngcount] =
literal|1
argument|;
comment|/* it should go in "Newsgroups" line */
argument|++ngcount; 	}
comment|/* 	** Check groups against active file. 	*/
argument|recheck: 	okcount =
literal|0
argument|; 	rewind(actfp); clearerr(actfp); 	while (okcount< ngcount&& fgets(bfr, BUFLEN, actfp) == bfr) { 		if ((cp = index(bfr,
literal|' '
argument|)) == NULL) 			continue;
comment|/* strange line in input! */
comment|/* newsgroup 12345 12345 X */
comment|/*  cp +    01234567890123 */
argument|if (!isproc&& cp[
literal|13
argument|]  ==
literal|'n'
argument|) 			continue;
comment|/* can't post to this group! */
argument|*cp =
literal|'\0'
argument|; 		for (i =
literal|0
argument|; i< ngcount; ++i) 			if (uses[i]>=
literal|1
argument|&& STRCMP(bfr, ngs[i]) ==
literal|0
argument|) { 				uses[i] =
literal|2
argument|;
comment|/* it should be localized too */
argument|if (cp[
literal|13
argument|] ==
literal|'m'
argument|) 					strcpy(is_mod, bfr); 				++okcount; 			} 	}
ifdef|#
directive|ifdef
name|ALWAYSALIAS
argument|okcount =
literal|0
argument|;
endif|#
directive|endif
comment|/* ALWAYSALIAS */
comment|/* 	** Handle groups absent from active file. 	*/
argument|if (havealiased ==
literal|0
argument|&& okcount< ngcount) {
comment|/* 		** See if remaining groups are in our alias list. 		*/
argument|f = xfopen(ALIASES,
literal|"r"
argument|); 		while (okcount< ngcount&& fscanf(f,
literal|"%s %s%*[^\n]"
argument|, abuf, bfr) ==
literal|2
argument|) 			for (i =
literal|0
argument|; i< ngcount; ++i) {
ifndef|#
directive|ifndef
name|ALWAYSALIAS
argument|if (uses[i] ==
literal|2
argument|) 					continue;
endif|#
directive|endif
comment|/* ALWAYSALIAS */
argument|if (STRCMP(ngs[i], abuf) !=
literal|0
argument|) 					continue; 				if (isproc) 					cp =
literal|"Aliased newsgroup %s to %s"
argument|; 				else 					cp =
literal|"Please change %s to %s"
argument|; 				logerr(cp, abuf, bfr); 				ngs[i] = AllocCpy(bfr); 				uses[i] =
literal|2
argument|; 				++havealiased; 				++okcount; 			} 		(void) fclose(f); 		for (i =
literal|0
argument|; i< ngcount; ++i) { 			if (uses[i] ==
literal|2
argument|) 				continue; 			if (isproc) 				log(
literal|"Unknown newsgroup %s not localized"
argument|, 					ngs[i]); 			else 				logerr(
literal|"Unknown newsgroup %s"
argument|, ngs[i]);
ifdef|#
directive|ifdef
name|ALWAYSALIAS
argument|++okcount;
comment|/* so we know to exit below */
argument|} 		if (!isproc&& okcount>
literal|0
argument|)
else|#
directive|else
comment|/* !ALWAYSALIAS */
argument|} 		if (!isproc)
endif|#
directive|endif
comment|/* !ALWAYSALIAS */
argument|newssave(infp, (char *) NULL);
comment|/* 		 * Unfortunately, if you alias an unmoderated group to a 		 * moderated group, you must recheck the active file to see 		 * if the new group is moderated. Rude but necessary. 		 */
argument|if (havealiased) 			goto recheck;	 	}
comment|/* 	** Zap duplicates. 	*/
argument|for (i =
literal|0
argument|; i< ngcount -
literal|1
argument|; ++i) { 		if (uses[i] ==
literal|0
argument|) 			continue; 		for (j = i +
literal|1
argument|; j< ngcount; ++j) { 			if (uses[j] ==
literal|0
argument|) 				continue; 			if (STRCMP(ngs[i], ngs[j]) !=
literal|0
argument|) 				continue; 			logerr(
literal|"Duplicate %s removed"
argument|, ngs[j]); 			if (uses[i]< uses[j]) 				uses[i] = uses[j]; 			uses[j] =
literal|0
argument|; 		} 	} 	for (pass =
literal|1
argument|; pass<=
literal|2
argument|; ++pass) { 		register int	avail;  		if (pass ==
literal|1
argument|) {
comment|/* 			** Rewrite header.nbuf. 			*/
argument|cp = header.nbuf; 			avail = sizeof header.nbuf; 		} else {
comment|/* 			** Fill in nbuf. 			*/
argument|cp = nbuf; 			avail = sizeof nbuf; 		} 		for (i =
literal|0
argument|; i< ngcount; ++i) { 			if (uses[i]< pass) 				continue; 			j = strlen(ngs[i]); 			if (j +
literal|2
argument|> avail) { 				logerr(
literal|"Redone Newsgroups too long"
argument|); 				break; 			} 			(void) strcpy(cp, ngs[i]); 			cp += j; 			*cp++ = (pass ==
literal|1
argument|) ? NGDELIM :
literal|'\0'
argument|; 			avail -= (j +
literal|1
argument|); 		} 		if (pass ==
literal|1
argument|) { 			if (cp == header.nbuf) 				*cp =
literal|'\0'
argument|; 			else	*(cp -
literal|1
argument|) =
literal|'\0'
argument|; 		} else	*cp =
literal|'\0'
argument|; 	}
comment|/* 	** Free aliases. 	*/
argument|for (i =
literal|0
argument|; i< ngcount; ++i) 		if (ngs[i]< tbuf || ngs[i]>&tbuf[sizeof tbuf -
literal|1
argument|]) 			free(ngs[i]); 	return nbuf[
literal|0
argument|] ==
literal|'\0'
argument|; }
comment|/*  * Figure out who posted the article (which is locally entered).  * The results are placed in the header structure hp.  */
argument|gensender(hp, logname) struct hbuf *hp; char *logname; { 	register char *fn, *p; 	char buf[BUFLEN]; 	char *fullname(), *getenv(); 	int fd, n; 	extern char *mydomain();  	if ((fn = getenv(
literal|"NAME"
argument|)) == NULL) { 		(void) sprintf(buf,
literal|"%s/%s"
argument|, userhome,
literal|".name"
argument|); 		if ((fd = open(buf,
literal|0
argument|))>=
literal|0
argument|) { 			n = read(fd, buf, sizeof buf); 			(void) close(fd); 			if (n>
literal|0
argument|&& buf[
literal|0
argument|]>=
literal|'A'
argument|) { 				for (p = fn = buf; *p; p++) 					if (*p<
literal|' '
argument|) 						*p =
literal|'\0'
argument|; 			} 		} 	}  	if (fn == NULL) 		fn = fullname(logname);  	(void) sprintf(hp->path,
literal|"%s"
argument|, logname); 	(void) sprintf(hp->from,
literal|"%s@%s (%s)"
argument|, logname, FROMSYSNAME, fn); }
comment|/*  * Trap interrupts.  */
argument|onsig(n) int n; { 	static int numsigs =
literal|0
argument|;
comment|/* 	 * Most UNIX systems reset caught signals to SIG_DFL. 	 * This bad design requires that the trap be set again here. 	 * Unfortunately, if the signal recurs before the trap is set, 	 * the program will die, possibly leaving the lock in place. 	 */
argument|if (++numsigs>
literal|100
argument|) { 		xerror(
literal|"inews ran away looping on signal %d"
argument|, n); 	} 	(void) signal(n, onsig); 	SigTrap = n; }
comment|/*  * If the stdin begins with "#" the input is some kind of batch.  if  * the first line is:  *	#!cunbatch  * or  *	#!c7unbatch  * then fork off a pipe to do the either a  *	"compress -d"  * or a  *	"decode | compress -d"  * and check their output for more batch headers.  They probably  * contain a batch format that looks like this:  *	#! rnews 1234  *	article with 1234 chars  *	#! rnews 4321  *	article with 4321 chars  * If so, then for each article, copy the indicated number of chars into  * a temp file, fork a copy of ourselves, make its input the temp file,  * and allow the copy to process the article.  This avoids an exec of  * rnews for each article.  */
argument|checkbatch() { 	int c; 	char *cp;  	setbuf(infp, (char *)NULL); 	while ((c = getc(infp)) ==
literal|'#'
argument|) {
comment|/* some kind of batch, investigate further */
argument|int i; 		char cmd[BUFLEN]; 		cmd[
literal|0
argument|] = c; 		fgets(cmd +
literal|1
argument|, BUFLEN, infp); 		if (strncmp(cmd,
literal|"#! cunbatch"
argument|,
literal|11
argument|) ==
literal|0
argument|) { 			(void) sprintf(cmd,
literal|"%s/compress"
argument|, LIB); 			input_pipe(cmd,
literal|"compress"
argument|,
literal|"-d"
argument|, (char *)
literal|0
argument|); 			setbuf(infp, (char *)NULL); 			continue;
comment|/* look for the #! rnews */
argument|} else if (strncmp(cmd,
literal|"#! c7unbatch"
argument|,
literal|12
argument|) ==
literal|0
argument|) { 			(void) sprintf(cmd,
literal|"%s/decode | %s/compress -d"
argument|, 				LIB, LIB); 			input_pipe(
literal|"/bin/sh"
argument|,
literal|"news-unpack"
argument|,
literal|"-c"
argument|, cmd); 			setbuf(infp, (char *)NULL); 			continue;
comment|/* look for the #! rnews */
argument|} else if (strncmp(cmd,
literal|"#! rnews "
argument|,
literal|9
argument|) ==
literal|0
argument||| 			strncmp(cmd,
literal|"! rnews "
argument|,
literal|8
argument|) ==
literal|0
argument|) {
comment|/* instead of execing unbatch do it ourselves */
argument|register int fd, rc, wc; 			int piped[
literal|2
argument|]; 			register long size, asize; 			char *tfilename; 			int pid, wpid, exstat;
define|#
directive|define
name|CPBFSZ
value|8192
argument|char buf[CPBFSZ];  			tfilename =
literal|0
argument|; 			cp = malloc((unsigned)BUFSIZ); 			if (cp != NULL) 				setbuf(infp, cp); 			do { 				while (STRNCMP(cmd,
literal|"#! rnews "
argument|,
literal|9
argument|)) { 					fprintf(stderr,
literal|"out of sync, skipping %s\n"
argument|, cmd); 					if (fgets(cmd, BUFLEN, infp) == NULL) 						exit(
literal|0
argument|); 				} 				asize = atol(cmd +
literal|9
argument|); 				if (asize<=
literal|0
argument|) 					xerror(
literal|"checkbatch: bad batch count %ld"
argument|, asize); 				fd = -
literal|1
argument|; 				size = asize; 				do { 					if (size> CPBFSZ) 						rc = CPBFSZ; 					else 						rc = size; 					rc = fread(buf,
literal|1
argument|, rc, infp); 					if (rc<=
literal|0
argument|) 						break; 					if (fd<
literal|0
argument|) { 						if (rc == asize) 							break;
comment|/* fits in buffer */
argument|if (!tfilename) 							tfilename = mktemp(
literal|"/tmp/unbnewsXXXXXX"
argument|); 						if ((fd = creat(tfilename,
literal|0666
argument|))<
literal|0
argument|) { 							fprintf(stderr,
literal|"rnews: creat of \"%s\" failed"
argument|, 								tfilename); 							perror(
literal|" "
argument|); 							exit(
literal|1
argument|); 						} 					} 					wc = write(fd, buf, rc);
comment|/* write to temp file */
argument|if (wc != rc) { 						fprintf(stderr,
literal|"write of %d to \"%s\" returned %d"
argument|, 							rc, tfilename, wc); 						perror(
literal|" "
argument|); 						exit(
literal|1
argument|); 					} 					size -= rc; 				} while (size>
literal|0
argument|); 				if (fd>=
literal|0
argument|) 					(void) close(fd);
comment|/* 				 * If we got a truncated batch, don't process 				 * the last article; it will probably be 				 * received again.  				 */
argument|if ((rc< asize)&& (size>
literal|0
argument|)) 					break;
comment|/* 				 * This differs from the old unbatcher in 				 * that we don't exec rnews, mainly because 				 * we ARE rnews.  Instead we fork off a copy 				 * of ourselves for each article and allow it 				 * to process.  				 */
argument|if (rc == asize) {
comment|/* 					 * article fits in buffer, use a pipe 					 * instead of a temporary file.  					 */
argument|if (pipe(piped) !=
literal|0
argument|) 						xerror(
literal|"checkbatch: pipe() failed"
argument|); 				} 				while ((pid = fork()) == -
literal|1
argument|) { 					fprintf(stderr,
literal|"fork failed, waiting...\r\n"
argument|); 					sleep(
literal|60
argument|); 				} 				if (pid ==
literal|0
argument|) { 					if (rc == asize) {
comment|/* article fits in buffer 						 * make the output of the 						 * pipe for STDIN  						 */
argument|(void) fclose(infp);
comment|/* redundant but why not */
argument|(void) close(
literal|0
argument|); 						if ((i = dup(piped[
literal|0
argument|])) !=
literal|0
argument|) 							xerror(
literal|"dup() returned %d, should be 0"
argument|, i); 						(void) close(piped[
literal|0
argument|]); 						(void) close(piped[
literal|1
argument|]); 						infp = fdopen(
literal|0
argument|,
literal|"r"
argument|); 					} else
comment|/* supstitute temp file as 						 * input */
argument|freopen(tfilename,
literal|"r"
argument|, infp); 					return;
comment|/* from checkbatch as if 						 * normal article */
argument|}
comment|/* parent of fork */
argument|if (rc == asize) {
comment|/* article fits in buffer */
argument|wc = write(piped[
literal|1
argument|], buf, rc); 					if (wc != rc) { 						fprintf(stderr,
literal|"write of %d to pipe returned %d"
argument|, 							rc, wc); 						perror(
literal|"rnews: write"
argument|); 						exit(
literal|1
argument|); 					} 					(void) close(piped[
literal|0
argument|]); 					(void) close(piped[
literal|1
argument|]); 				} 				while ((wpid = wait(&exstat))>=
literal|0
argument|&& wpid != pid); 				(void) unlink(tfilename); 			} while (fgets(cmd, BUFLEN, infp) != NULL); 			exit(
literal|0
argument|);
comment|/* all done */
argument|} else { 			docmd(cmd); 			xxit(
literal|0
argument|); 		} 	}
comment|/* while a batch */
argument|cp = malloc((unsigned)BUFSIZ); 	if (cp != NULL) 		setbuf(infp, cp); 	if (c != EOF) 		(void) ungetc(c, infp); 	clearerr(infp); }
comment|/*  * The input requires some processing so fork and exec the indicated command  * with its output piped to our input.   */
argument|static  input_pipe(cmd, arg0, arg1, arg2) char *cmd, *arg0, *arg1, *arg2; { 	int i, pid; 	int piped[
literal|2
argument|];  	if (pipe(piped) !=
literal|0
argument|) { 		perror(
literal|"checkbatch: pipe() failed"
argument|); 		exit(
literal|1
argument|); 	} 	fflush(stdout); 	while ((pid = vfork()) == -
literal|1
argument|) { 		perror(
literal|"checkbatch: fork failed, waiting"
argument|); 		sleep(
literal|60
argument|); 	} 	if (pid ==
literal|0
argument|) {
comment|/* child process */
comment|/* 		 * setup a pipe such that the exec'ed process will read our 		 * input file and write to the pipe  		 */
argument|(void) close(
literal|1
argument|); 		if ((i = dup(piped[
literal|1
argument|])) !=
literal|1
argument|) 			xerror(
literal|"dup() returned %d, should be 1"
argument|, i); 		(void) close(piped[
literal|0
argument|]); 		(void) close(piped[
literal|1
argument|]); 		execl(cmd, arg0, arg1, arg2, (char *)
literal|0
argument|); 		perror(
literal|"checkbatch"
argument|); 		xerror(
literal|"Unable to exec %s to unpack news."
argument|, cmd); 	} else {
comment|/* parent process */
comment|/* make the output of the pipe for STDIN */
argument|(void) fclose(infp); 		(void) close(
literal|0
argument|); 		if ((i = dup(piped[
literal|0
argument|])) !=
literal|0
argument|) 			xerror(
literal|"dup() returned %d, should be 0"
argument|, i); 		(void) close(piped[
literal|0
argument|]); 		(void) close(piped[
literal|1
argument|]);
comment|/* 		 * there should be a way to clear any buffered input and just 		 * replace file descriptor 0 but I can't find a portable way.  		 */
argument|infp = fdopen(
literal|0
argument|,
literal|"r"
argument|); 	} }
define|#
directive|define
name|MAXARGS
value|32
argument|docmd(p) register char *p; { 	char *args[MAXARGS]; 	register char **ap = args; 	char path[BUFSIZ]; 	char *rindex(), *cp;  	while (*p&& !isspace(*p))
comment|/* skip leading #! crud */
argument|p++;  	while (isspace(*p)) 		p++;  	while (*p !=
literal|'\0'
argument|) { 		*ap++ = p; 		if (ap>=&args[MAXARGS]) { 			logerr(
literal|"inews: unbatch: Too many args to %s"
argument|, args[
literal|0
argument|]); 			exit(
literal|2
argument|); 		} 		while (*p&& !isspace(*p)) 			p++; 		if (*p) 			*p++ =
literal|'\0'
argument|; 		while (isspace(*p)) 			p++; 	} 	*ap = (char *)
literal|0
argument|;  	if (ap == args) { 		logerr(
literal|"inews: unbatch: no command to execute"
argument|); 		exit(
literal|2
argument|); 	}
comment|/* strip off any leading pathname in case someone gets tricky */
argument|cp = rindex(args[
literal|0
argument|],
literal|'/'
argument|); 	if (cp++ == NULL) 		cp = args[
literal|0
argument|];
ifdef|#
directive|ifdef
name|HOME
argument|sprintf(path,
literal|"%s/%s/%s"
argument|, logdir(HOME), LIBDIR, cp);
else|#
directive|else
comment|/* !HOME */
argument|sprintf(path,
literal|"%s/%s"
argument|, LIBDIR, cp);
endif|#
directive|endif
comment|/* HOME */
comment|/* 	 * "path" is absolute, no searching is needed,  we use 	 * 'execvp' solely so that sh scripts will be handled 	 */
argument|(void) execvp(path, args); 	perror(path); 	xxit(
literal|2
argument|); }
comment|/*  *	Exit and cleanup.  */
argument|xxit(status) int status; { 	(void) unlink(INFILE); 	(void) unlink(ARTICLE); 	while (lockcount>
literal|0
argument|) 		unlock(); 	idunlock(); 	exit(status); }  rwaccess(fname) char *fname; { 	int fd;  	fd = open(fname,
literal|2
argument|); 	if (fd<
literal|0
argument|) 		return
literal|0
argument|; 	(void) close(fd); 	return
literal|1
argument|; }  exists(fname) char *fname; { 	int fd;  	fd = open(fname,
literal|0
argument|); 	if (fd<
literal|0
argument|) 		return
literal|0
argument|; 	(void) close(fd); 	return
literal|1
argument|; }  int	lockcount =
literal|0
argument|;
comment|/* no. of times we've called lock */
ifdef|#
directive|ifdef
name|VMS
define|#
directive|define
name|SUBLOCK
value|"/tmp/netnews.lck.1"
comment|/*  * Newsystem locking.  * These routines are different for VMS because we can not  * effectively simulate links, and VMS supports multiple  * version numbers of files  */
argument|lock() { 	register int i; 	register int fd;  	if (lockcount++ ==
literal|0
argument|) { 		i = DEADTIME; 		while ((fd = creat(SUBLOCK,
literal|0444
argument|))<
literal|0
argument|) { 			if (--i<
literal|0
argument|) { 				(void) unlink(SUBLOCK); 				logerr(
literal|"News system locked up"
argument|); 			} 			if (i< -
literal|3
argument|) 				xerror(
literal|"Unable to unlock news system"
argument|); 			sleep((unsigned)
literal|1
argument|); 		} 		(void) close(fd); 	} }  unlock() { 	if (--lockcount ==
literal|0
argument|) 		(void) unlink(SUBLOCK);  }
else|#
directive|else
comment|/* !VMS */
comment|/*  * Newsystem locking.  */
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|LOCKF
argument_list|)
ifdef|#
directive|ifdef
name|LOCKF
include|#
directive|include
file|<unistd.h>
else|#
directive|else
comment|/* !LOCKF */
include|#
directive|include
file|<sys/file.h>
endif|#
directive|endif
comment|/* !LOCKF */
argument|static int LockFd = -
literal|1
argument|; lock() { 	LockFd = open(SUBFILE,
literal|2
argument|); 	if (LockFd<
literal|0
argument|) 		logerr(
literal|"Can't open(\"%s\", 2) to lock"
argument|, SUBFILE);
comment|/* This will sleep until the other program releases the lock */
comment|/* We may need to alarm out of this, but I don't think so */
ifdef|#
directive|ifdef
name|LOCKF
argument|if (lockf(LockFd, F_LOCK,
literal|0L
argument|)<
literal|0
argument|)
else|#
directive|else
argument|if (flock(LockFd, LOCK_EX)<
literal|0
argument|)
endif|#
directive|endif
argument|xerror(
literal|"Can't get lock on %s: %s"
argument|, SUBFILE, errmsg(errno)); }  unlock() { 	(void) close(LockFd); }
else|#
directive|else
comment|/* !BSD4_2 */
argument|lock() { 	register int i; 	extern int errno;  	if (lockcount++ ==
literal|0
argument|) { 		i = DEADTIME; 		while (link(SUBFILE, LOCKFILE)) { 			if (errno != EEXIST) 				break; 			if (--i<
literal|0
argument|) 				xerror(
literal|"News system locked up"
argument|); 			sleep((unsigned)
literal|1
argument|); 		} 	} }  unlock() { 	if (--lockcount ==
literal|0
argument|) 		(void) unlink(LOCKFILE); }
endif|#
directive|endif
comment|/* !BSD4_2 */
endif|#
directive|endif
comment|/* !VMS */
comment|/* VARARGS1 */
argument|error(message, arg1, arg2, arg3) char *message; long arg1, arg2, arg3; { 	char buffer[LBUFLEN];  	fflush(stdout); 	(void) sprintf(buffer, message, arg1, arg2, arg3); 	logerr(buffer); 	xxit(mode == PROC ?
literal|0
argument|:
literal|1
argument|); }
end_block

end_unit

