begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lcp.h - Link Control Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Options.  */
end_comment

begin_define
define|#
directive|define
name|CI_MRU
value|1
end_define

begin_comment
comment|/* Maximum Receive Unit */
end_comment

begin_define
define|#
directive|define
name|CI_ASYNCMAP
value|2
end_define

begin_comment
comment|/* Async Control Character Map */
end_comment

begin_define
define|#
directive|define
name|CI_AUTHTYPE
value|3
end_define

begin_comment
comment|/* Authentication Type */
end_comment

begin_define
define|#
directive|define
name|CI_QUALITY
value|4
end_define

begin_comment
comment|/* Quality Protocol */
end_comment

begin_define
define|#
directive|define
name|CI_MAGICNUMBER
value|5
end_define

begin_comment
comment|/* Magic Number */
end_comment

begin_define
define|#
directive|define
name|CI_PCOMPRESSION
value|7
end_define

begin_comment
comment|/* Protocol Field Compression */
end_comment

begin_define
define|#
directive|define
name|CI_ACCOMPRESSION
value|8
end_define

begin_comment
comment|/* Address/Control Field Compression */
end_comment

begin_comment
comment|/*  * LCP-specific packet types.  */
end_comment

begin_define
define|#
directive|define
name|PROTREJ
value|8
end_define

begin_comment
comment|/* Protocol Reject */
end_comment

begin_define
define|#
directive|define
name|ECHOREQ
value|9
end_define

begin_comment
comment|/* Echo Request */
end_comment

begin_define
define|#
directive|define
name|ECHOREP
value|10
end_define

begin_comment
comment|/* Echo Reply */
end_comment

begin_define
define|#
directive|define
name|DISCREQ
value|11
end_define

begin_comment
comment|/* Discard Request */
end_comment

begin_comment
comment|/*  * The state of options is described by an lcp_options structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lcp_options
block|{
name|int
name|passive
range|:
literal|1
decl_stmt|;
comment|/* Don't die if we don't get a response */
name|int
name|silent
range|:
literal|1
decl_stmt|;
comment|/* Wait for the other end to start first */
name|int
name|restart
range|:
literal|1
decl_stmt|;
comment|/* Restart vs. exit after close */
name|int
name|neg_mru
range|:
literal|1
decl_stmt|;
comment|/* Negotiate the MRU? */
name|int
name|neg_asyncmap
range|:
literal|1
decl_stmt|;
comment|/* Negotiate the async map? */
name|int
name|neg_upap
range|:
literal|1
decl_stmt|;
comment|/* Ask for PPP_PAP authentication? */
name|int
name|neg_chap
range|:
literal|1
decl_stmt|;
comment|/* Ask for CHAP authentication? */
name|int
name|neg_magicnumber
range|:
literal|1
decl_stmt|;
comment|/* Ask for magic number? */
name|int
name|neg_pcompression
range|:
literal|1
decl_stmt|;
comment|/* HDLC Protocol Field Compression? */
name|int
name|neg_accompression
range|:
literal|1
decl_stmt|;
comment|/* HDLC Address/Control Field Compression? */
name|int
name|neg_lqr
range|:
literal|1
decl_stmt|;
comment|/* Negotiate use of Link Quality Reports */
name|u_short
name|mru
decl_stmt|;
comment|/* Value of MRU */
name|u_char
name|chap_mdtype
decl_stmt|;
comment|/* which MD type (hashing algorithm) */
name|u_long
name|asyncmap
decl_stmt|;
comment|/* Value of async map */
name|u_long
name|magicnumber
decl_stmt|;
name|int
name|numloops
decl_stmt|;
comment|/* Number of loops during magic number neg. */
name|u_long
name|lqr_period
decl_stmt|;
comment|/* Reporting period for link quality */
block|}
name|lcp_options
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|fsm
name|lcp_fsm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lcp_options
name|lcp_wantoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lcp_options
name|lcp_gotoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lcp_options
name|lcp_allowoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lcp_options
name|lcp_hisoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|xmit_accm
index|[]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFMRU
value|1500
end_define

begin_comment
comment|/* Try for this */
end_comment

begin_define
define|#
directive|define
name|MINMRU
value|128
end_define

begin_comment
comment|/* No MRUs below this */
end_comment

begin_define
define|#
directive|define
name|MAXMRU
value|16384
end_define

begin_comment
comment|/* Normally limit MRU to this */
end_comment

begin_decl_stmt
name|void
name|lcp_init
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_open
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_close
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_lowerup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_lowerdown
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_input
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_protrej
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lcp_sprotrej
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lcp_printpkt
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lcp_warnloops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about a loopback this often */
end_comment

begin_define
define|#
directive|define
name|DEFWARNLOOPS
value|10
end_define

begin_comment
comment|/* Default value for above */
end_comment

end_unit

