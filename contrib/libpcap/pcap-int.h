begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  * @(#) $Header: /tcpdump/master/libpcap/pcap-int.h,v 1.32 2000/12/21 10:29:23 guy Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|pcap_int_h
end_ifndef

begin_define
define|#
directive|define
name|pcap_int_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<pcap.h>
comment|/*  * Savefile  */
struct|struct
name|pcap_sf
block|{
name|FILE
modifier|*
name|rfile
decl_stmt|;
name|int
name|swapped
decl_stmt|;
name|int
name|hdrsize
decl_stmt|;
name|int
name|version_major
decl_stmt|;
name|int
name|version_minor
decl_stmt|;
name|u_char
modifier|*
name|base
decl_stmt|;
block|}
struct|;
struct|struct
name|pcap_md
block|{
name|struct
name|pcap_stat
name|stat
decl_stmt|;
comment|/*XXX*/
name|int
name|use_bpf
decl_stmt|;
comment|/* using kernel filter */
name|u_long
name|TotPkts
decl_stmt|;
comment|/* can't oflow for 79 hrs on ether */
name|u_long
name|TotAccepted
decl_stmt|;
comment|/* count accepted by filter */
name|u_long
name|TotDrops
decl_stmt|;
comment|/* count of dropped packets */
name|long
name|TotMissed
decl_stmt|;
comment|/* missed by i/f during this run */
name|long
name|OrigMissed
decl_stmt|;
comment|/* missed by i/f before this run */
ifdef|#
directive|ifdef
name|linux
name|int
name|sock_packet
decl_stmt|;
comment|/* using Linux 2.0 compatible interface */
name|int
name|readlen
decl_stmt|;
comment|/* byte count to hand to "recvmsg()" */
name|int
name|timeout
decl_stmt|;
comment|/* timeout specified to pcap_open_live */
name|int
name|clear_promisc
decl_stmt|;
comment|/* must clear promiscuous mode when we close */
name|int
name|cooked
decl_stmt|;
comment|/* using SOCK_DGRAM rather than SOCK_RAW */
name|int
name|lo_ifindex
decl_stmt|;
comment|/* interface index of the loopback device */
name|char
modifier|*
name|device
decl_stmt|;
comment|/* device name */
name|struct
name|pcap
modifier|*
name|next
decl_stmt|;
comment|/* list of open promiscuous sock_packet pcaps */
endif|#
directive|endif
block|}
struct|;
struct|struct
name|pcap
block|{
name|int
name|fd
decl_stmt|;
name|int
name|snapshot
decl_stmt|;
name|int
name|linktype
decl_stmt|;
name|int
name|tzoff
decl_stmt|;
comment|/* timezone offset */
name|int
name|offset
decl_stmt|;
comment|/* offset for proper alignment */
name|struct
name|pcap_sf
name|sf
decl_stmt|;
name|struct
name|pcap_md
name|md
decl_stmt|;
comment|/* 	 * Read buffer. 	 */
name|int
name|bufsize
decl_stmt|;
name|u_char
modifier|*
name|buffer
decl_stmt|;
name|u_char
modifier|*
name|bp
decl_stmt|;
name|int
name|cc
decl_stmt|;
comment|/* 	 * Place holder for pcap_next(). 	 */
name|u_char
modifier|*
name|pkt
decl_stmt|;
comment|/* 	 * Placeholder for filter code if bpf not in kernel. 	 */
name|struct
name|bpf_program
name|fcode
decl_stmt|;
name|char
name|errbuf
index|[
name|PCAP_ERRBUF_SIZE
index|]
decl_stmt|;
block|}
struct|;
comment|/*  * This is a timeval as stored in disk in a dumpfile.  * It has to use the same types everywhere, independent of the actual  * `struct timeval'  */
struct|struct
name|pcap_timeval
block|{
name|bpf_int32
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|bpf_int32
name|tv_usec
decl_stmt|;
comment|/* microseconds */
block|}
struct|;
comment|/*  * How a `pcap_pkthdr' is actually stored in the dumpfile.  *  * Do not change the format of this structure, in any way (this includes  * changes that only affect the length of fields in this structure),  * and do not make the time stamp anything other than seconds and  * microseconds (e.g., seconds and nanoseconds).  Instead:  *  *	introduce a new structure for the new format;  *  *	send mail to "tcpdump-workers@tcpdump.org", requesting a new  *	magic number for your new capture file format, and, when  *	you get the new magic number, put it in "savefile.c";  *  *	use that magic number for save files with the changed record  *	header;  *  *	make the code in "savefile.c" capable of reading files with  *	the old record header as well as files with the new record header  *	(using the magic number to determine the header format).  *  * Then supply the changes to "patches@tcpdump.org", so that future  * versions of libpcap and programs that use it (such as tcpdump) will  * be able to read your new capture file format.  */
struct|struct
name|pcap_sf_pkthdr
block|{
name|struct
name|pcap_timeval
name|ts
decl_stmt|;
comment|/* time stamp */
name|bpf_u_int32
name|caplen
decl_stmt|;
comment|/* length of portion present */
name|bpf_u_int32
name|len
decl_stmt|;
comment|/* length this packet (off wire) */
block|}
struct|;
comment|/*  * How a `pcap_pkthdr' is actually stored in dumpfiles written  * by some patched versions of libpcap (e.g. the ones in Red  * Hat Linux 6.1 and 6.2).  *  * Do not change the format of this structure, in any way (this includes  * changes that only affect the length of fields in this structure).  * Instead, introduce a new structure, as per the above.  */
struct|struct
name|pcap_sf_patched_pkthdr
block|{
name|struct
name|pcap_timeval
name|ts
decl_stmt|;
comment|/* time stamp */
name|bpf_u_int32
name|caplen
decl_stmt|;
comment|/* length of portion present */
name|bpf_u_int32
name|len
decl_stmt|;
comment|/* length this packet (off wire) */
name|int
name|index
decl_stmt|;
name|unsigned
name|short
name|protocol
decl_stmt|;
name|unsigned
name|char
name|pkt_type
decl_stmt|;
block|}
struct|;
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|min
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
endif|#
directive|endif
comment|/* XXX should these be in pcap.h? */
name|int
name|pcap_offline_read
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|pcap_handler
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
name|int
name|pcap_read
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
name|cnt
parameter_list|,
name|pcap_handler
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Ultrix, DEC OSF/1^H^H^H^H^H^H^H^H^HDigital UNIX^H^H^H^H^H^H^H^H^H^H^H^H  * Tru64 UNIX, and NetBSD pad to make everything line up on a nice boundary.  */
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
define|#
directive|define
name|PCAP_FDDIPAD
value|3
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
define|#
directive|define
name|strlcpy
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|(strncpy((x), (y), (z)), \ 	 ((z)<= 0 ? 0 : ((x)[(z) - 1] = '\0')), \ 	 strlen((y)))
endif|#
directive|endif
ifdef|#
directive|ifdef
name|linux
name|void
name|pcap_close_linux
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* XXX */
specifier|extern
name|int
name|pcap_fddipad
decl_stmt|;
name|int
name|install_bpf_program
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|bpf_program
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

