begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /a/cvs/386BSD/src/contrib/tcpdump/tcpdump/interface.h,v 1.1.1.1 1993/06/12 14:42:12 rgrimes Exp $ (LBL)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"os.h"
end_include

begin_comment
comment|/* operating system stuff */
end_comment

begin_include
include|#
directive|include
file|"md.h"
end_include

begin_comment
comment|/* machine dependent stuff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print filter code */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print ethernet header */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leave addresses as numbers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remove domains from printed host names */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|qflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quick (shorter) output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print raw TCP sequence numbers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print packet arrival time */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print packet in hex */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to generate self-identifying messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|snaplen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global pointers to beginning and end of current packet (during printing) */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|packetp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|snapend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|thiszone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* gmt to local correction */
end_comment

begin_function_decl
specifier|extern
name|void
name|ts_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|clock_sigfigs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lookup_device
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warning
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|read_infile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|copy_argv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_addrtoname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The printer routines. */
end_comment

begin_function_decl
specifier|extern
name|void
name|ether_if_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ip_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|udp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icmp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ntp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfsreq_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfsreply_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ns_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ddp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tftp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bootp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|snmp_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sl_if_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ppp_if_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fddi_if_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|null_if_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|egp_print
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b)>(a)?(b):(a))
end_define

begin_comment
comment|/*   * The default snapshot length.  This value allows most printers to print  * useful information while keeping the amount of unwanted data down.  * In particular, it allows for an ethernet header, tcp/ip header, and  * 14 bytes of data (assuming no ip options).  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SNAPLEN
value|68
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

