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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-lane.c,v 1.25 2005-11-13 12:12:42 guy Exp $ (LBL)"
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
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"ether.h"
end_include

begin_include
include|#
directive|include
file|"lane.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|lecop2str
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"configure request"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"configure response"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"join request"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"join response"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"ready query"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"ready indication"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"register request"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"register response"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"unregister request"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"unregister response"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"ARP request"
block|}
block|,
block|{
literal|0x0106
block|,
literal|"ARP response"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"flush request"
block|}
block|,
block|{
literal|0x0107
block|,
literal|"flush response"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"NARP request"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"topology request"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|lane_hdr_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"lecid:%x "
argument_list|,
name|EXTRACT_16BITS
argument_list|(
name|bp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the LANE header of the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  *  * This assumes 802.3, not 802.5, LAN emulation.  */
end_comment

begin_function
name|void
name|lane_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
name|struct
name|lane_controlhdr
modifier|*
name|lec
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|lane_controlhdr
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|lane]"
argument_list|)
expr_stmt|;
return|return;
block|}
name|lec
operator|=
operator|(
expr|struct
name|lane_controlhdr
operator|*
operator|)
name|p
expr_stmt|;
if|if
condition|(
name|EXTRACT_16BITS
argument_list|(
operator|&
name|lec
operator|->
name|lec_header
argument_list|)
operator|==
literal|0xff00
condition|)
block|{
comment|/* 		 * LE Control. 		 */
name|printf
argument_list|(
literal|"lec: proto %x vers %x %s"
argument_list|,
name|lec
operator|->
name|lec_proto
argument_list|,
name|lec
operator|->
name|lec_vers
argument_list|,
name|tok2str
argument_list|(
name|lecop2str
argument_list|,
literal|"opcode-#%u"
argument_list|,
name|EXTRACT_16BITS
argument_list|(
operator|&
name|lec
operator|->
name|lec_opcode
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Go past the LE header. 	 */
name|length
operator|-=
literal|2
expr_stmt|;
name|caplen
operator|-=
literal|2
expr_stmt|;
name|p
operator|+=
literal|2
expr_stmt|;
comment|/* 	 * Now print the encapsulated frame, under the assumption 	 * that it's an Ethernet frame. 	 */
name|ether_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|,
name|lane_hdr_print
argument_list|,
name|p
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|u_int
name|lane_if_print
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
name|lane_print
argument_list|(
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|)
expr_stmt|;
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|lecdatahdr_8023
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

