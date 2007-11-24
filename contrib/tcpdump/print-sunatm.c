begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Yen Yen Lim and North Dakota State University  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Yen Yen Lim and 	North Dakota State University  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-sunatm.c,v 1.8 2004/03/17 23:24:38 guy Exp $ (LBL)"
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

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

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
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"atm.h"
end_include

begin_include
include|#
directive|include
file|"atmuni31.h"
end_include

begin_comment
comment|/* SunATM header for ATM packet */
end_comment

begin_define
define|#
directive|define
name|DIR_POS
value|0
end_define

begin_comment
comment|/* Direction (0x80 = transmit, 0x00 = receive) */
end_comment

begin_define
define|#
directive|define
name|VPI_POS
value|1
end_define

begin_comment
comment|/* VPI */
end_comment

begin_define
define|#
directive|define
name|VCI_POS
value|2
end_define

begin_comment
comment|/* VCI */
end_comment

begin_define
define|#
directive|define
name|PKT_BEGIN_POS
value|4
end_define

begin_comment
comment|/* Start of the ATM packet */
end_comment

begin_comment
comment|/* Protocol type values in the bottom for bits of the byte at SUNATM_DIR_POS. */
end_comment

begin_define
define|#
directive|define
name|PT_LANE
value|0x01
end_define

begin_comment
comment|/* LANE */
end_comment

begin_define
define|#
directive|define
name|PT_LLC
value|0x02
end_define

begin_comment
comment|/* LLC encapsulation */
end_comment

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the SunATM pseudo-header for the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  */
end_comment

begin_function
name|u_int
name|sunatm_if_print
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
name|vci
decl_stmt|;
name|u_char
name|vpi
decl_stmt|;
name|u_int
name|traftype
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
name|PKT_BEGIN_POS
condition|)
block|{
name|printf
argument_list|(
literal|"[|atm]"
argument_list|)
expr_stmt|;
return|return
operator|(
name|caplen
operator|)
return|;
block|}
if|if
condition|(
name|eflag
condition|)
block|{
if|if
condition|(
name|p
index|[
name|DIR_POS
index|]
operator|&
literal|0x80
condition|)
name|printf
argument_list|(
literal|"Tx: "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Rx: "
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|p
index|[
name|DIR_POS
index|]
operator|&
literal|0x0f
condition|)
block|{
case|case
name|PT_LANE
case|:
name|traftype
operator|=
name|ATM_LANE
expr_stmt|;
break|break;
case|case
name|PT_LLC
case|:
name|traftype
operator|=
name|ATM_LLC
expr_stmt|;
break|break;
default|default:
name|traftype
operator|=
name|ATM_UNKNOWN
expr_stmt|;
break|break;
block|}
name|vci
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|p
index|[
name|VCI_POS
index|]
argument_list|)
expr_stmt|;
name|vpi
operator|=
name|p
index|[
name|VPI_POS
index|]
expr_stmt|;
name|p
operator|+=
name|PKT_BEGIN_POS
expr_stmt|;
name|caplen
operator|-=
name|PKT_BEGIN_POS
expr_stmt|;
name|length
operator|-=
name|PKT_BEGIN_POS
expr_stmt|;
name|atm_print
argument_list|(
name|vpi
argument_list|,
name|vci
argument_list|,
name|traftype
argument_list|,
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
return|return
operator|(
name|PKT_BEGIN_POS
operator|)
return|;
block|}
end_function

end_unit

