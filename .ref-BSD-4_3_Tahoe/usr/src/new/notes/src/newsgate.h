begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|RCSIDENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|zznewsgate
init|=
literal|"$Header: newsgate.h,v 1.7.0.2 85/07/20 13:44:37 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(RCSIDENT)&& defined(MAINLINE)
end_endif

begin_comment
comment|/*  *	newsgate.h  *  *	This file contains the definitions needed for the notesfile/news  *	gateway features.  *  *	The new (April 4) implementation allows gateing from news to   *	notesfiles at ANY site. Gateing from notes to news is allowed   *	by a SINGLE site (for any given newsgroup) per notesfile 'subnet'.  *  *	An example:  *	4 sites running notesfiles: A,B,C and D.  *  *	Both A and B run news alongside the notesfile program.  *	A and B both gateway news into notesfiles; this is safe  *	and does not generate duplicate articles.  *	Neither C nor D run news; they do want the articles they  *	have written to go to the news system beyond A and B.  *	Sites A and B should at least gateway their locally generated  *	articles to news.  Sites C and D should each make their own  *	arrangements to have their articles passed to the news  *	networks.  Good criteria for choosing the site include  *	the load of the machine to gateway, how well it is connected  *	to the rest of the network and who runs the machine.  *	In this case, suppose C goes with A and D goes with B.  *	The gateway scripts will look something like:  *  *	On A:  *		newsoutput list			(local articles (A))  *		newsoutput -sC list		(C's articles)  *  *	On B:  *		newsoutput list			(local articles (B))  *		newsoutput -sD list		(D's articles)  *  *  *	Original Coding:	Ray Essick	April 4, 1982  *  */
end_comment

begin_comment
comment|/*  *	Definitions that are likely to change between sites:  */
end_comment

begin_define
define|#
directive|define
name|DFLTRNEWS
value|"rnews"
end_define

begin_comment
comment|/* if getnet fails */
end_comment

begin_undef
undef|#
directive|undef
name|EXPANDPATH
end_undef

begin_comment
comment|/* do indirect links */
end_comment

begin_define
define|#
directive|define
name|DFLTDOMAIN
value|"UUCP"
end_define

begin_comment
comment|/* if undomained */
end_comment

begin_define
define|#
directive|define
name|PATHMAP
value|"/usr/local/lib/usemap"
end_define

begin_comment
comment|/* path to the paths */
end_comment

begin_comment
comment|/* pathmap unused. */
end_comment

begin_comment
comment|/*  *	definitions that aren't likely to be changed.  */
end_comment

begin_define
define|#
directive|define
name|UGLYPATH
end_define

begin_comment
comment|/* want Path: ....!author */
end_comment

begin_define
define|#
directive|define
name|RNEWSNAME
value|"Usenet"
end_define

begin_comment
comment|/* getnet pseudohost */
end_comment

begin_define
define|#
directive|define
name|NEWSSYS
value|"Anysystem"
end_define

begin_comment
comment|/* news' sequencer */
end_comment

begin_define
define|#
directive|define
name|NEWSSEQ
value|"News"
end_define

begin_comment
comment|/* prefix for above */
end_comment

begin_define
define|#
directive|define
name|NEWSALIAS
value|"newsgroups"
end_define

begin_comment
comment|/* mapping file */
end_comment

begin_define
define|#
directive|define
name|NGRPLEN
value|30
end_define

begin_comment
comment|/* longest newsgroup */
end_comment

begin_define
define|#
directive|define
name|NEWSNF
value|1
end_define

begin_comment
comment|/* alias news->nf */
end_comment

begin_define
define|#
directive|define
name|NFBASENEWS
value|2
end_define

begin_comment
comment|/* alias nf->news */
end_comment

begin_define
define|#
directive|define
name|NFRESPNEWS
value|3
end_define

begin_comment
comment|/* alias nf->news */
end_comment

begin_define
define|#
directive|define
name|OLDSUFFIX
value|"- from a notesfile"
end_define

begin_comment
comment|/* catch loops */
end_comment

begin_define
define|#
directive|define
name|NFSUFFIX
value|"- (nf)"
end_define

begin_comment
comment|/* catch nf-news-nf */
end_comment

begin_define
define|#
directive|define
name|CTL
value|".ctl"
end_define

begin_comment
comment|/* control msgs */
end_comment

begin_define
define|#
directive|define
name|SLEEPTIME
value|10
end_define

begin_comment
comment|/* between rnews' */
end_comment

begin_define
define|#
directive|define
name|GATEMAX
value|100
end_define

begin_comment
comment|/* for newsoutput -c */
end_comment

begin_define
define|#
directive|define
name|AUTHORPLACEHOLDER
value|"seefromline"
end_define

begin_comment
comment|/* for Path: line */
end_comment

begin_comment
comment|/*  *	classes to send back  */
end_comment

begin_define
define|#
directive|define
name|NEWS_ALLSEND
value|001
end_define

begin_comment
comment|/* all non-local */
end_comment

begin_define
define|#
directive|define
name|NEWS_LOCALSEND
value|002
end_define

begin_comment
comment|/* local articles */
end_comment

begin_comment
comment|/*  *	stuff to be compatible with Salkind/Spickelmier work  *	Most of these are carried over from the news system.  */
end_comment

begin_define
define|#
directive|define
name|NGDELIM
value|','
end_define

begin_define
define|#
directive|define
name|NEGCHAR
value|'!'
end_define

begin_comment
comment|/* negation */
end_comment

begin_define
define|#
directive|define
name|PROTO
value|'A'
end_define

begin_comment
comment|/* A-news protocol */
end_comment

begin_define
define|#
directive|define
name|NUMGROUPS
value|5
end_define

begin_comment
comment|/*  *	Definitions for the New and Improved version thanks to  *	Tw Cook of Hewlett-Packard.  */
end_comment

begin_define
define|#
directive|define
name|NFLINE1
value|"Nf-ID"
end_define

begin_comment
comment|/* parent, etc */
end_comment

begin_define
define|#
directive|define
name|NFLINE2
value|"Nf-From"
end_define

begin_comment
comment|/* author,dates */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tzone
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in newsdump.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpath
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in newspath.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in newsdump.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rnewscmd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in newsoutput.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sendclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* classes to send */
end_comment

begin_comment
comment|/*  *	The following lines are from the B-news program.  *  * header.h - Article header format  *  *	@(#)header.h	2.11	4/24/83";  */
end_comment

begin_define
define|#
directive|define
name|NUNREC
value|50
end_define

begin_comment
comment|/* bnews:header.h */
end_comment

begin_define
define|#
directive|define
name|BUFLEN
value|256
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_define
define|#
directive|define
name|PATHLEN
value|512
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_define
define|#
directive|define
name|NAMELEN
value|64
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_define
define|#
directive|define
name|NETCHRS
value|"!:.@^%"
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_define
define|#
directive|define
name|LBUFLEN
value|1024
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_define
define|#
directive|define
name|BDATE
value|64
end_define

begin_comment
comment|/* bnews:defs.h */
end_comment

begin_comment
comment|/* was DATELEN */
end_comment

begin_struct
struct|struct
name|hbuf
comment|/* article header */
block|{
comment|/* bnews:header.h */
name|char
name|from
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* From: */
name|char
name|path
index|[
name|PATHLEN
index|]
decl_stmt|;
comment|/* Path: */
name|char
name|nbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Newsgroups: */
name|char
name|snbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Squashed nbuf. */
name|char
name|title
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Subject: */
name|char
name|oident
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Article-I.D.: */
name|char
name|ident
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Message-ID: */
name|char
name|replyto
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Reply-To: */
name|char
name|followid
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* References: */
name|char
name|subdate
index|[
name|BDATE
index|]
decl_stmt|;
comment|/* (submitted) Date: */
name|long
name|subtime
decl_stmt|;
comment|/* subdate in secs */
name|char
name|recdate
index|[
name|BDATE
index|]
decl_stmt|;
comment|/* Date-Received: */
name|long
name|rectime
decl_stmt|;
comment|/* recdate in secs */
name|char
name|expdate
index|[
name|BDATE
index|]
decl_stmt|;
comment|/* Expires: */
name|long
name|exptime
decl_stmt|;
comment|/* expdate in secs */
name|char
name|ctlmsg
index|[
name|PATHLEN
index|]
decl_stmt|;
comment|/* Control: */
name|char
name|sender
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Sender: */
name|char
name|followto
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Followup-to: */
name|char
name|postversion
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Post-Version: */
name|char
name|relayversion
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Relay-Version: */
name|char
name|distribution
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Distribution: */
name|char
name|organization
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Organization: */
name|char
name|numlines
index|[
literal|8
index|]
decl_stmt|;
comment|/* Lines: */
name|int
name|intnumlines
decl_stmt|;
comment|/* Integer version */
name|char
name|keywords
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Keywords: */
name|char
name|approved
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Approved: */
name|char
name|nline1
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* NF-Id: */
name|char
name|nline2
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* NF-From: */
name|char
modifier|*
name|unrec
index|[
name|NUNREC
index|]
decl_stmt|;
comment|/* unrecognized lines */
block|}
struct|;
end_struct

end_unit

