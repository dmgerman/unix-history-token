begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2005 NetGroup, Politecnico di Torino (Italy)  * Copyright (c) 2005 - 2008 CACE Technologies, Davis (California)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino, CACE Technologies  * nor the names of its contributors may be used to endorse or promote  * products derived from this software without specific prior written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCAP_RPCAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCAP_RPCAP_H__
end_define

begin_include
include|#
directive|include
file|"pcap.h"
end_include

begin_include
include|#
directive|include
file|"sockutils.h"
end_include

begin_comment
comment|/* Needed for some structures (like SOCKET, sockaddr_in) which are used here */
end_comment

begin_comment
comment|/*  * \file pcap-pcap.h  *  * This file keeps all the new definitions and typedefs that are exported to the user and  * that are needed for the RPCAP protocol.  *  * \warning All the RPCAP functions that are allowed to return a buffer containing  * the error description can return max PCAP_ERRBUF_SIZE characters.  * However there is no guarantees that the string will be zero-terminated.  * Best practice is to define the errbuf variable as a char of size 'PCAP_ERRBUF_SIZE+1'  * and to insert manually the termination char at the end of the buffer. This will  * guarantee that no buffer overflows occur even if we use the printf() to show  * the error on the screen.  *  * \warning This file declares some typedefs that MUST be of a specific size.  * These definitions (i.e. typedefs) could need to be changed on other platforms than  * Intel IA32.  *  * \warning This file defines some structures that are used to transfer data on the network.  * Be careful that you compiler MUST not insert padding into these structures  * for better alignment.  * These structures have been created in order to be correctly aligned to a 32 bits  * boundary, but be careful in any case.  */
end_comment

begin_comment
comment|/*********************************************************  *                                                       *  * General definitions / typedefs for the RPCAP protocol *  *                                                       *  *********************************************************/
end_comment

begin_comment
comment|/* All the following structures and typedef belongs to the Private Documentation */
end_comment

begin_comment
comment|/*  * \addtogroup remote_pri_struct  * \{  */
end_comment

begin_define
define|#
directive|define
name|RPCAP_DEFAULT_NETPORT
value|"2002"
end_define

begin_comment
comment|/* Default port on which the RPCAP daemon is waiting for connections. */
end_comment

begin_comment
comment|/* Default port on which the client workstation is waiting for connections in case of active mode. */
end_comment

begin_define
define|#
directive|define
name|RPCAP_DEFAULT_NETPORT_ACTIVE
value|"2003"
end_define

begin_define
define|#
directive|define
name|RPCAP_DEFAULT_NETADDR
value|""
end_define

begin_comment
comment|/* Default network address on which the RPCAP daemon binds to. */
end_comment

begin_define
define|#
directive|define
name|RPCAP_VERSION
value|0
end_define

begin_comment
comment|/* Present version of the RPCAP protocol (0 = Experimental). */
end_comment

begin_define
define|#
directive|define
name|RPCAP_TIMEOUT_INIT
value|90
end_define

begin_comment
comment|/* Initial timeout for RPCAP connections (default: 90 sec) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_TIMEOUT_RUNTIME
value|180
end_define

begin_comment
comment|/* Run-time timeout for RPCAP connections (default: 3 min) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_ACTIVE_WAIT
value|30
end_define

begin_comment
comment|/* Waiting time between two attempts to open a connection, in active mode (default: 30 sec) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_SUSPEND_WRONGAUTH
value|1
end_define

begin_comment
comment|/* If the authentication is wrong, stops 1 sec before accepting a new auth message */
end_comment

begin_comment
comment|/*  * \brief Buffer used by socket functions to send-receive packets.  * In case you plan to have messages larger than this value, you have to increase it.  */
end_comment

begin_define
define|#
directive|define
name|RPCAP_NETBUF_SIZE
value|64000
end_define

begin_comment
comment|/*  * \brief Separators used for the host list.  *  * It is used:  * - by the rpcapd daemon, when you types a list of allowed connecting hosts  * - by the rpcap in active mode, when the client waits for incoming connections from other hosts  */
end_comment

begin_define
define|#
directive|define
name|RPCAP_HOSTLIST_SEP
value|" ,;\n\r"
end_define

begin_comment
comment|/* WARNING: These could need to be changed on other platforms */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8
typedef|;
end_typedef

begin_comment
comment|/* Provides an 8-bits unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16
typedef|;
end_typedef

begin_comment
comment|/* Provides a 16-bits unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32
typedef|;
end_typedef

begin_comment
comment|/* Provides a 32-bits unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|int
name|int32
typedef|;
end_typedef

begin_comment
comment|/* Provides a 32-bits integer */
end_comment

begin_comment
comment|/*  * \brief Keeps a list of all the opened connections in the active mode.  *  * This structure defines a linked list of items that are needed to keep the info required to  * manage the active mode.  * In other words, when a new connection in active mode starts, this structure is updated so that  * it reflects the list of active mode connections currently opened.  * This structure is required by findalldevs() and open_remote() to see if they have to open a new  * control connection toward the host, or they already have a control connection in place.  */
end_comment

begin_struct
struct|struct
name|activehosts
block|{
name|struct
name|sockaddr_storage
name|host
decl_stmt|;
name|SOCKET
name|sockctrl
decl_stmt|;
name|struct
name|activehosts
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*********************************************************  *                                                       *  * Protocol messages formats                             *  *                                                       *  *********************************************************/
end_comment

begin_comment
comment|/* WARNING Take care you compiler does not insert padding for better alignments into these structs */
end_comment

begin_comment
comment|/* Common header for all the RPCAP messages */
end_comment

begin_struct
struct|struct
name|rpcap_header
block|{
name|uint8
name|ver
decl_stmt|;
comment|/* RPCAP version number */
name|uint8
name|type
decl_stmt|;
comment|/* RPCAP message type (error, findalldevs, ...) */
name|uint16
name|value
decl_stmt|;
comment|/* Message-dependent value (not always used) */
name|uint32
name|plen
decl_stmt|;
comment|/* Length of the payload of this RPCAP message */
block|}
struct|;
end_struct

begin_comment
comment|/* Format of the message for the interface description (findalldevs command) */
end_comment

begin_struct
struct|struct
name|rpcap_findalldevs_if
block|{
name|uint16
name|namelen
decl_stmt|;
comment|/* Length of the interface name */
name|uint16
name|desclen
decl_stmt|;
comment|/* Length of the interface description */
name|uint32
name|flags
decl_stmt|;
comment|/* Interface flags */
name|uint16
name|naddr
decl_stmt|;
comment|/* Number of addresses */
name|uint16
name|dummy
decl_stmt|;
comment|/* Must be zero */
block|}
struct|;
end_struct

begin_comment
comment|/* Format of the message for the address listing (findalldevs command) */
end_comment

begin_struct
struct|struct
name|rpcap_findalldevs_ifaddr
block|{
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/* Network address */
name|struct
name|sockaddr_storage
name|netmask
decl_stmt|;
comment|/* Netmask for that address */
name|struct
name|sockaddr_storage
name|broadaddr
decl_stmt|;
comment|/* Broadcast address for that address */
name|struct
name|sockaddr_storage
name|dstaddr
decl_stmt|;
comment|/* P2P destination address for that address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * \brief Format of the message of the connection opening reply (open command).  *  * This structure transfers over the network some of the values useful on the client side.  */
end_comment

begin_struct
struct|struct
name|rpcap_openreply
block|{
name|int32
name|linktype
decl_stmt|;
comment|/* Link type */
name|int32
name|tzoff
decl_stmt|;
comment|/* Timezone offset */
block|}
struct|;
end_struct

begin_comment
comment|/* Format of the message that starts a remote capture (startcap command) */
end_comment

begin_struct
struct|struct
name|rpcap_startcapreq
block|{
name|uint32
name|snaplen
decl_stmt|;
comment|/* Length of the snapshot (number of bytes to capture for each packet) */
name|uint32
name|read_timeout
decl_stmt|;
comment|/* Read timeout in milliseconds */
name|uint16
name|flags
decl_stmt|;
comment|/* Flags (see RPCAP_STARTCAPREQ_FLAG_xxx) */
name|uint16
name|portdata
decl_stmt|;
comment|/* Network port on which the client is waiting at (if 'serveropen') */
block|}
struct|;
end_struct

begin_comment
comment|/* Format of the reply message that devoted to start a remote capture (startcap reply command) */
end_comment

begin_struct
struct|struct
name|rpcap_startcapreply
block|{
name|int32
name|bufsize
decl_stmt|;
comment|/* Size of the user buffer allocated by WinPcap; it can be different from the one we chose */
name|uint16
name|portdata
decl_stmt|;
comment|/* Network port on which the server is waiting at (passive mode only) */
name|uint16
name|dummy
decl_stmt|;
comment|/* Must be zero */
block|}
struct|;
end_struct

begin_comment
comment|/*  * \brief Format of the header which encapsulates captured packets when transmitted on the network.  *  * This message requires the general header as well, since we want to be able to exchange  * more information across the network in the future (for example statistics, and kind like that).  */
end_comment

begin_struct
struct|struct
name|rpcap_pkthdr
block|{
name|uint32
name|timestamp_sec
decl_stmt|;
comment|/* 'struct timeval' compatible, it represents the 'tv_sec' field */
name|uint32
name|timestamp_usec
decl_stmt|;
comment|/* 'struct timeval' compatible, it represents the 'tv_usec' field */
name|uint32
name|caplen
decl_stmt|;
comment|/* Length of portion present in the capture */
name|uint32
name|len
decl_stmt|;
comment|/* Real length this packet (off wire) */
name|uint32
name|npkt
decl_stmt|;
comment|/* Ordinal number of the packet (i.e. the first one captured has '1', the second one '2', etc) */
block|}
struct|;
end_struct

begin_comment
comment|/* General header used for the pcap_setfilter() command; keeps just the number of BPF instructions */
end_comment

begin_struct
struct|struct
name|rpcap_filter
block|{
name|uint16
name|filtertype
decl_stmt|;
comment|/* type of the filter transferred (BPF instructions, ...) */
name|uint16
name|dummy
decl_stmt|;
comment|/* Must be zero */
name|uint32
name|nitems
decl_stmt|;
comment|/* Number of items contained into the filter (e.g. BPF instructions for BPF filters) */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure that keeps a single BPF instuction; it is repeated 'ninsn' times according to the 'rpcap_filterbpf' header */
end_comment

begin_struct
struct|struct
name|rpcap_filterbpf_insn
block|{
name|uint16
name|code
decl_stmt|;
comment|/* opcode of the instruction */
name|uint8
name|jt
decl_stmt|;
comment|/* relative offset to jump to in case of 'true' */
name|uint8
name|jf
decl_stmt|;
comment|/* relative offset to jump to in case of 'false' */
name|int32
name|k
decl_stmt|;
comment|/* instruction-dependent value */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure that keeps the data required for the authentication on the remote host */
end_comment

begin_struct
struct|struct
name|rpcap_auth
block|{
name|uint16
name|type
decl_stmt|;
comment|/* Authentication type */
name|uint16
name|dummy
decl_stmt|;
comment|/* Must be zero */
name|uint16
name|slen1
decl_stmt|;
comment|/* Length of the first authentication item (e.g. username) */
name|uint16
name|slen2
decl_stmt|;
comment|/* Length of the second authentication item (e.g. password) */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure that keeps the statistics about the number of packets captured, dropped, etc. */
end_comment

begin_struct
struct|struct
name|rpcap_stats
block|{
name|uint32
name|ifrecv
decl_stmt|;
comment|/* Packets received by the kernel filter (i.e. pcap_stats.ps_recv) */
name|uint32
name|ifdrop
decl_stmt|;
comment|/* Packets dropped by the network interface (e.g. not enough buffers) (i.e. pcap_stats.ps_ifdrop) */
name|uint32
name|krnldrop
decl_stmt|;
comment|/* Packets dropped by the kernel filter (i.e. pcap_stats.ps_drop) */
name|uint32
name|svrcapt
decl_stmt|;
comment|/* Packets captured by the RPCAP daemon and sent on the network */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure that is needed to set sampling parameters */
end_comment

begin_struct
struct|struct
name|rpcap_sampling
block|{
name|uint8
name|method
decl_stmt|;
comment|/* Sampling method */
name|uint8
name|dummy1
decl_stmt|;
comment|/* Must be zero */
name|uint16
name|dummy2
decl_stmt|;
comment|/* Must be zero */
name|uint32
name|value
decl_stmt|;
comment|/* Parameter related to the sampling method */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private data for doing a live capture.  */
end_comment

begin_struct
struct|struct
name|pcap_md
block|{
name|struct
name|pcap_stat
name|stat
decl_stmt|;
comment|/* XXX */
name|int
name|use_bpf
decl_stmt|;
comment|/* using kernel filter */
name|u_long
name|TotPkts
decl_stmt|;
comment|/* can't overflow for 79 hrs on ether */
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
name|char
modifier|*
name|device
decl_stmt|;
comment|/* device name */
name|int
name|timeout
decl_stmt|;
comment|/* timeout for buffering */
name|int
name|must_clear
decl_stmt|;
comment|/* stuff we must clear when we close */
name|struct
name|pcap
modifier|*
name|next
decl_stmt|;
comment|/* list of open pcaps that need stuff cleared on close */
ifdef|#
directive|ifdef
name|linux
name|int
name|sock_packet
decl_stmt|;
comment|/* using Linux 2.0 compatible interface */
name|int
name|cooked
decl_stmt|;
comment|/* using SOCK_DGRAM rather than SOCK_RAW */
name|int
name|ifindex
decl_stmt|;
comment|/* interface index of device we're bound to */
name|int
name|lo_ifindex
decl_stmt|;
comment|/* interface index of the loopback device */
name|u_int
name|packets_read
decl_stmt|;
comment|/* count of packets read with recvfrom() */
name|bpf_u_int32
name|oldmode
decl_stmt|;
comment|/* mode to restore when turning monitor mode off */
name|u_int
name|tp_version
decl_stmt|;
comment|/* version of tpacket_hdr for mmaped ring */
name|u_int
name|tp_hdrlen
decl_stmt|;
comment|/* hdrlen of tpacket_hdr for mmaped ring */
endif|#
directive|endif
comment|/* linux */
ifdef|#
directive|ifdef
name|HAVE_DAG_API
ifdef|#
directive|ifdef
name|HAVE_DAG_STREAMS_API
name|u_char
modifier|*
name|dag_mem_bottom
decl_stmt|;
comment|/* DAG card current memory bottom pointer */
name|u_char
modifier|*
name|dag_mem_top
decl_stmt|;
comment|/* DAG card current memory top pointer */
else|#
directive|else
comment|/* HAVE_DAG_STREAMS_API */
name|void
modifier|*
name|dag_mem_base
decl_stmt|;
comment|/* DAG card memory base address */
name|u_int
name|dag_mem_bottom
decl_stmt|;
comment|/* DAG card current memory bottom offset */
name|u_int
name|dag_mem_top
decl_stmt|;
comment|/* DAG card current memory top offset */
endif|#
directive|endif
comment|/* HAVE_DAG_STREAMS_API */
name|int
name|dag_fcs_bits
decl_stmt|;
comment|/* Number of checksum bits from link layer */
name|int
name|dag_offset_flags
decl_stmt|;
comment|/* Flags to pass to dag_offset(). */
name|int
name|dag_stream
decl_stmt|;
comment|/* DAG stream number */
name|int
name|dag_timeout
decl_stmt|;
comment|/* timeout specified to pcap_open_live. 							 * Same as in linux above, introduce 							 * generally? 							 */
endif|#
directive|endif
comment|/* HAVE_DAG_API */
ifdef|#
directive|ifdef
name|HAVE_ZEROCOPY_BPF
comment|/* 	 * Zero-copy read buffer -- for zero-copy BPF.  'buffer' above will 	 * alternative between these two actual mmap'd buffers as required. 	 * As there is a header on the front size of the mmap'd buffer, only 	 * some of the buffer is exposed to libpcap as a whole via bufsize; 	 * zbufsize is the true size.  zbuffer tracks the current zbuf 	 * associated with buffer so that it can be used to decide which the 	 * next buffer to read will be. 	 */
name|u_char
modifier|*
name|zbuf1
decl_stmt|,
modifier|*
name|zbuf2
decl_stmt|,
modifier|*
name|zbuffer
decl_stmt|;
name|u_int
name|zbufsize
decl_stmt|;
name|u_int
name|zerocopy
decl_stmt|;
name|u_int
name|interrupted
decl_stmt|;
name|struct
name|timespec
name|firstsel
decl_stmt|;
comment|/* 	 * If there's currently a buffer being actively processed, then it is 	 * referenced here; 'buffer' is also pointed at it, but offset by the 	 * size of the header. 	 */
name|struct
name|bpf_zbuf_header
modifier|*
name|bzh
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_ZEROCOPY_BPF */
ifdef|#
directive|ifdef
name|HAVE_REMOTE
comment|/* 	 * There is really a mess with previous variables, and it seems to me that they are not used 	 * (they are used in pcap_pf.c only). I think we have to start using them. 	 * The meaning is the following: 	 * 	 * - TotPkts: the amount of packets received by the bpf filter, *before* applying the filter 	 * - TotAccepted: the amount of packets that satisfies the filter 	 * - TotDrops: the amount of packet that were dropped into the kernel buffer because of lack of space 	 * - TotMissed: the amount of packets that were dropped by the physical interface; it is basically 	 * the value of the hardware counter into the card. This number is never put to zero, so this number 	 * takes into account the *total* number of interface drops starting from the interface power-on. 	 * - OrigMissed: the amount of packets that were dropped by the interface *when the capture begins*. 	 * This value is used to detect the number of packets dropped by the interface *during the present 	 * capture*, so that (ps_ifdrops= TotMissed - OrigMissed). 	 */
name|unsigned
name|int
name|TotNetDrops
decl_stmt|;
comment|/* keeps the number of packets that have been dropped by the network */
comment|/* 	 * \brief It keeps the number of packets that have been received by the application. 	 * 	 * Packets dropped by the kernel buffer are not counted in this variable. The variable is always 	 * equal to (TotAccepted - TotDrops), except for the case of remote capture, in which we have also 	 * packets in flight, i.e. that have been transmitted by the remote host, but that have not been 	 * received (yet) from the client. In this case, (TotAccepted - TotDrops - TotNetDrops) gives a 	 * wrong result, since this number does not corresponds always to the number of packet received by 	 * the application. For this reason, in the remote capture we need another variable that takes 	 * into account of the number of packets actually received by the application. 	 */
name|unsigned
name|int
name|TotCapt
decl_stmt|;
comment|/*! \brief '1' if we're the network client; needed by several functions (like pcap_setfilter() ) to know if 	they have to use the socket or they have to open the local adapter. */
name|int
name|rmt_clientside
decl_stmt|;
name|SOCKET
name|rmt_sockctrl
decl_stmt|;
comment|//!< socket ID of the socket used for the control connection
name|SOCKET
name|rmt_sockdata
decl_stmt|;
comment|//!< socket ID of the socket used for the data connection
name|int
name|rmt_flags
decl_stmt|;
comment|//!< we have to save flags, since they are passed by the pcap_open_live(), but they are used by the pcap_startcapture()
name|int
name|rmt_capstarted
decl_stmt|;
comment|//!< 'true' if the capture is already started (needed to knoe if we have to call the pcap_startcapture()
name|struct
name|pcap_samp
name|rmt_samp
decl_stmt|;
comment|//!< Keeps the parameters related to the sampling process.
name|char
modifier|*
name|currentfilter
decl_stmt|;
comment|//!< Pointer to a buffer (allocated at run-time) that stores the current filter. Needed when flag PCAP_OPENFLAG_NOCAPTURE_RPCAP is turned on.
endif|#
directive|endif
comment|/* HAVE_REMOTE */
block|}
struct|;
end_struct

begin_comment
comment|/* Messages field coding */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_ERROR
value|1
end_define

begin_comment
comment|/* Message that keeps an error notification */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_FINDALLIF_REQ
value|2
end_define

begin_comment
comment|/* Request to list all the remote interfaces */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_OPEN_REQ
value|3
end_define

begin_comment
comment|/* Request to open a remote device */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_STARTCAP_REQ
value|4
end_define

begin_comment
comment|/* Request to start a capture on a remote device */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_UPDATEFILTER_REQ
value|5
end_define

begin_comment
comment|/* Send a compiled filter into the remote device */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_CLOSE
value|6
end_define

begin_comment
comment|/* Close the connection with the remote peer */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_PACKET
value|7
end_define

begin_comment
comment|/* This is a 'data' message, which carries a network packet */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_AUTH_REQ
value|8
end_define

begin_comment
comment|/* Message that keeps the authentication parameters */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_STATS_REQ
value|9
end_define

begin_comment
comment|/* It requires to have network statistics */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_ENDCAP_REQ
value|10
end_define

begin_comment
comment|/* Stops the current capture, keeping the device open */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_SETSAMPLING_REQ
value|11
end_define

begin_comment
comment|/* Set sampling parameters */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_FINDALLIF_REPLY
value|(128+RPCAP_MSG_FINDALLIF_REQ)
end_define

begin_comment
comment|/* Keeps the list of all the remote interfaces */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_OPEN_REPLY
value|(128+RPCAP_MSG_OPEN_REQ)
end_define

begin_comment
comment|/* The remote device has been opened correctly */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_STARTCAP_REPLY
value|(128+RPCAP_MSG_STARTCAP_REQ)
end_define

begin_comment
comment|/* The capture is starting correctly */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_UPDATEFILTER_REPLY
value|(128+RPCAP_MSG_UPDATEFILTER_REQ)
end_define

begin_comment
comment|/* The filter has been applied correctly on the remote device */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_AUTH_REPLY
value|(128+RPCAP_MSG_AUTH_REQ)
end_define

begin_comment
comment|/* Sends a message that says 'ok, authorization successful' */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_STATS_REPLY
value|(128+RPCAP_MSG_STATS_REQ)
end_define

begin_comment
comment|/* Message that keeps the network statistics */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_ENDCAP_REPLY
value|(128+RPCAP_MSG_ENDCAP_REQ)
end_define

begin_comment
comment|/* Confirms that the capture stopped successfully */
end_comment

begin_define
define|#
directive|define
name|RPCAP_MSG_SETSAMPLING_REPLY
value|(128+RPCAP_MSG_SETSAMPLING_REQ)
end_define

begin_comment
comment|/* Confirms that the capture stopped successfully */
end_comment

begin_define
define|#
directive|define
name|RPCAP_STARTCAPREQ_FLAG_PROMISC
value|1
end_define

begin_comment
comment|/* Enables promiscuous mode (default: disabled) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_STARTCAPREQ_FLAG_DGRAM
value|2
end_define

begin_comment
comment|/* Use a datagram (i.e. UDP) connection for the data stream (default: use TCP)*/
end_comment

begin_define
define|#
directive|define
name|RPCAP_STARTCAPREQ_FLAG_SERVEROPEN
value|4
end_define

begin_comment
comment|/* The server has to open the data connection toward the client */
end_comment

begin_define
define|#
directive|define
name|RPCAP_STARTCAPREQ_FLAG_INBOUND
value|8
end_define

begin_comment
comment|/* Capture only inbound packets (take care: the flag has no effects with promiscuous enabled) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_STARTCAPREQ_FLAG_OUTBOUND
value|16
end_define

begin_comment
comment|/* Capture only outbound packets (take care: the flag has no effects with promiscuous enabled) */
end_comment

begin_define
define|#
directive|define
name|RPCAP_UPDATEFILTER_BPF
value|1
end_define

begin_comment
comment|/* This code tells us that the filter is encoded with the BPF/NPF syntax */
end_comment

begin_comment
comment|/* Network error codes */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_NETW
value|1
end_define

begin_comment
comment|/* Network error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_INITTIMEOUT
value|2
end_define

begin_comment
comment|/* The RPCAP initial timeout has expired */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_AUTH
value|3
end_define

begin_comment
comment|/* Generic authentication error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_FINDALLIF
value|4
end_define

begin_comment
comment|/* Generic findalldevs error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_NOREMOTEIF
value|5
end_define

begin_comment
comment|/* The findalldevs was ok, but the remote end had no interfaces to list */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_OPEN
value|6
end_define

begin_comment
comment|/* Generic pcap_open error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_UPDATEFILTER
value|7
end_define

begin_comment
comment|/* Generic updatefilter error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_GETSTATS
value|8
end_define

begin_comment
comment|/* Generic pcap_stats error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_READEX
value|9
end_define

begin_comment
comment|/* Generic pcap_next_ex error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_HOSTNOAUTH
value|10
end_define

begin_comment
comment|/* The host is not authorized to connect to this server */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_REMOTEACCEPT
value|11
end_define

begin_comment
comment|/* Generic pcap_remoteaccept error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_STARTCAPTURE
value|12
end_define

begin_comment
comment|/* Generic pcap_startcapture error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_ENDCAPTURE
value|13
end_define

begin_comment
comment|/* Generic pcap_endcapture error */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_RUNTIMETIMEOUT
value|14
end_define

begin_comment
comment|/* The RPCAP run-time timeout has expired */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_SETSAMPLING
value|15
end_define

begin_comment
comment|/* Error during the settings of sampling parameters */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_WRONGMSG
value|16
end_define

begin_comment
comment|/* The other end endpoint sent a message which has not been recognized */
end_comment

begin_define
define|#
directive|define
name|PCAP_ERR_WRONGVER
value|17
end_define

begin_comment
comment|/* The other end endpoint has a version number that is not compatible with our */
end_comment

begin_comment
comment|/*  * \}  * // end of private documentation  */
end_comment

begin_comment
comment|/*********************************************************  *                                                       *  * Exported function prototypes                          *  *                                                       *  *********************************************************/
end_comment

begin_function_decl
name|int
name|pcap_opensource_remote
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|struct
name|pcap_rmtauth
modifier|*
name|auth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_startcapture_remote
parameter_list|(
name|pcap_t
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcap_createhdr
parameter_list|(
name|struct
name|rpcap_header
modifier|*
name|header
parameter_list|,
name|uint8
name|type
parameter_list|,
name|uint16
name|value
parameter_list|,
name|uint32
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcap_deseraddr
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|sockaddrin
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
modifier|*
name|sockaddrout
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcap_checkmsg
parameter_list|(
name|char
modifier|*
name|errbuf
parameter_list|,
name|SOCKET
name|sock
parameter_list|,
name|struct
name|rpcap_header
modifier|*
name|header
parameter_list|,
name|uint8
name|first
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcap_senderror
parameter_list|(
name|SOCKET
name|sock
parameter_list|,
name|char
modifier|*
name|error
parameter_list|,
name|unsigned
name|short
name|errcode
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcap_sendauth
parameter_list|(
name|SOCKET
name|sock
parameter_list|,
name|struct
name|pcap_rmtauth
modifier|*
name|auth
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SOCKET
name|rpcap_remoteact_getsock
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|int
modifier|*
name|isactive
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

