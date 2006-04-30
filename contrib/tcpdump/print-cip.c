begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Marko Kiiskila carnil@cs.tut.fi  *  * Tampere University of Technology - Telecommunications Laboratory  *  * Permission to use, copy, modify and distribute this  * software and its documentation is hereby granted,  * provided that both the copyright notice and this  * permission notice appear in all copies of the software,  * derivative works or modified versions, and any portions  * thereof, that both notices appear in supporting  * documentation, and that the use of this software is  * acknowledged in any publications resulting from using  * the software.  *  * TUT ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION AND DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-cip.c,v 1.25 2005/04/06 21:32:39 mcr Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"ethertype.h"
end_include

begin_include
include|#
directive|include
file|"ether.h"
end_include

begin_define
define|#
directive|define
name|RFC1483LLC_LEN
value|8
end_define

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|rfcllc
index|[]
init|=
block|{
literal|0xaa
block|,
comment|/* DSAP: non-ISO */
literal|0xaa
block|,
comment|/* SSAP: non-ISO */
literal|0x03
block|,
comment|/* Ctrl: Unnumbered Information Command PDU */
literal|0x00
block|,
comment|/* OUI: EtherType */
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|cip_print
parameter_list|(
name|int
name|length
parameter_list|)
block|{
comment|/* 	 * There is no MAC-layer header, so just print the length. 	 */
name|printf
argument_list|(
literal|"%d: "
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the LLC/SNAP or raw header of the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  */
end_comment

begin_function
name|u_int
name|cip_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|u_int
name|caplen
init|=
name|h
operator|->
name|caplen
decl_stmt|;
name|u_int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
name|u_short
name|extracted_ethertype
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rfcllc
argument_list|,
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|rfcllc
argument_list|)
argument_list|)
operator|==
literal|0
operator|&&
name|caplen
operator|<
name|RFC1483LLC_LEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|cip]"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|eflag
condition|)
name|cip_print
argument_list|(
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rfcllc
argument_list|,
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|rfcllc
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * LLC header is present.  Try to print it& higher layers. 		 */
if|if
condition|(
name|llc_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|extracted_ethertype
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* ether_type not known, print raw packet */
if|if
condition|(
operator|!
name|eflag
condition|)
name|cip_print
argument_list|(
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|extracted_ethertype
condition|)
block|{
name|printf
argument_list|(
literal|"(LLC %s) "
argument_list|,
name|etherproto_string
argument_list|(
name|htons
argument_list|(
name|extracted_ethertype
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|xflag
operator|&&
operator|!
name|qflag
condition|)
name|default_print
argument_list|(
name|p
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 		 * LLC header is absent; treat it as just IP. 		 */
name|ip_print
argument_list|(
name|gndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * c-style: whitesmith  * c-basic-offset: 8  * End:  */
end_comment

end_unit

