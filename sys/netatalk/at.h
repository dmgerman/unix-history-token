begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Mike Clark  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-763-0525  *	netatalk@itd.umich.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AT_HEADER__
end_ifndef

begin_define
define|#
directive|define
name|__AT_HEADER__
end_define

begin_comment
comment|/*  * Supported protocols  */
end_comment

begin_define
define|#
directive|define
name|ATPROTO_DDP
value|0
end_define

begin_define
define|#
directive|define
name|ATPROTO_AARP
value|254
end_define

begin_comment
comment|/*  * Ethernet types, for DIX.  * These should really be in some global header file, but we can't  * count on them being there, and it's annoying to patch system files.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AT
value|0x809B
end_define

begin_comment
comment|/* AppleTalk protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AARP
value|0x80F3
end_define

begin_comment
comment|/* AppleTalk ARP */
end_comment

begin_define
define|#
directive|define
name|DDP_MAXSZ
value|587
end_define

begin_comment
comment|/*  * If ATPORT_FIRST<= Port< ATPORT_RESERVED,  * Port was created by a privileged process.  * If ATPORT_RESERVED<= Port< ATPORT_LAST,  * Port was not necessarily created by a  * privileged process.  */
end_comment

begin_define
define|#
directive|define
name|ATPORT_FIRST
value|1
end_define

begin_define
define|#
directive|define
name|ATPORT_RESERVED
value|128
end_define

begin_define
define|#
directive|define
name|ATPORT_LAST
value|255
end_define

begin_comment
comment|/*  * AppleTalk address.  */
end_comment

begin_struct
struct|struct
name|at_addr
block|{
name|u_short
name|s_net
decl_stmt|;
name|u_char
name|s_node
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATADDR_ANYNET
value|(u_short)0xffff
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATADDR_ANYNET
value|(u_short)0x0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATADDR_ANYNODE
value|(u_char)0x00
end_define

begin_define
define|#
directive|define
name|ATADDR_ANYPORT
value|(u_char)0x00
end_define

begin_define
define|#
directive|define
name|ATADDR_BCAST
value|(u_char)0xff
end_define

begin_comment
comment|/* There is no BCAST for NET */
end_comment

begin_comment
comment|/*  * Socket address, AppleTalk style.  We keep magic information in the   * zero bytes.  There are three types, NONE, CONFIG which has the phase  * and a net range, and IFACE which has the network address of an  * interface.  IFACE may be filled in by the client, and is filled in  * by the kernel.  */
end_comment

begin_struct
struct|struct
name|sockaddr_at
block|{
ifdef|#
directive|ifdef
name|BSD4_4
name|u_char
name|sat_len
decl_stmt|;
name|u_char
name|sat_family
decl_stmt|;
else|#
directive|else
else|BSD4_4
name|short
name|sat_family
decl_stmt|;
endif|#
directive|endif
endif|BSD4_4
name|u_char
name|sat_port
decl_stmt|;
name|struct
name|at_addr
name|sat_addr
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
struct|struct
block|{
name|u_char
name|sh_type
decl_stmt|;
define|#
directive|define
name|SATHINT_NONE
value|0
define|#
directive|define
name|SATHINT_CONFIG
value|1
define|#
directive|define
name|SATHINT_IFACE
value|2
union|union
block|{
name|char
name|su_zero
index|[
literal|7
index|]
decl_stmt|;
comment|/* XXX check size */
struct|struct
block|{
name|u_char
name|sr_phase
decl_stmt|;
name|u_short
name|sr_firstnet
decl_stmt|,
name|sr_lastnet
decl_stmt|;
block|}
name|su_range
struct|;
name|u_short
name|su_interface
decl_stmt|;
block|}
name|sh_un
union|;
block|}
name|sat_hints
struct|;
else|#
directive|else
else|notdef
name|char
name|sat_zero
index|[
literal|8
index|]
decl_stmt|;
endif|#
directive|endif
endif|notdef
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netrange
block|{
name|u_char
name|nr_phase
decl_stmt|;
name|u_short
name|nr_firstnet
decl_stmt|;
name|u_short
name|nr_lastnet
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|atalkdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|atalksw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|__AT_HEADER__
end_endif

end_unit

