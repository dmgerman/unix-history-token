begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	newsgate.h  *  *	This file contains the definitions needed for the notesfile/news  *	gateway features.  *  *	The new (April 4) implementation allows gateing from news to   *	notesfiles at ANY site. Gateing from notes to news is allowed   *	by a SINGLE site (for any given newsgroup) per notesfile 'subnet'.  *  *	An example:  *	4 sites at U. of I. running notesfiles: A,B,C and D.  *  *	A and B also interface to news and the rest of the network.  *	C and D run notesfiles only, A and B run news in parallel.  *	A is the specified gateway from notesfiles to news.   *	Both A and B can gateway from news to notesfiles, without  *	fear of duplication.  *  *	So, for any given 'subnet' of notesfiles, count the N sites that  *	also run news. One of these N 'parallel' sites should gate from  *	notesfiles to news. It should (and the other N-1 if they desire)  *	run gateways from news to notesfiles.  *  *	Original Coding:	Ray Essick	April 4, 1982  */
end_comment

begin_define
define|#
directive|define
name|NEWSSYS
value|"News:system"
end_define

begin_comment
comment|/* news' sequencer name */
end_comment

begin_define
define|#
directive|define
name|NEWSALIAS
value|"newsgroups"
end_define

begin_comment
comment|/* maps nf's to newsgroups */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
name|.1c
end_ifdef

begin_define
define|#
directive|define
name|NGRPLEN
value|255
end_define

begin_comment
comment|/* max newsgroup length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NGRPLEN
value|30
end_define

begin_comment
comment|/* max newsgroup length */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD4.1c
end_endif

begin_define
define|#
directive|define
name|NEWSNF
value|1
end_define

begin_comment
comment|/* alias newsgroup to nf name */
end_comment

begin_define
define|#
directive|define
name|NFNEWS
value|2
end_define

begin_comment
comment|/* alias nf to newsgroup */
end_comment

begin_define
define|#
directive|define
name|OLDSUFFIX
value|"- from a notesfile"
end_define

begin_comment
comment|/* to catch nf-news-nf */
end_comment

begin_define
define|#
directive|define
name|NFSUFFIX
value|"- (nf)"
end_define

begin_comment
comment|/* to catch nf-news-nf */
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

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|NETCHRS
value|"!:.@^"
end_define

begin_comment
comment|/* Punct. chars used for various networks	*/
end_comment

begin_define
define|#
directive|define
name|PROTO
value|'A'
end_define

begin_comment
comment|/* old protocol */
end_comment

begin_define
define|#
directive|define
name|NUMGROUPS
value|5
end_define

end_unit

