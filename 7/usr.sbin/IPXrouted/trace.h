begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * This file includes significant work done at Cornell University by  * Bill Nesheim.  That work included by permission.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)trace.h	8.1 (Berkeley) 6/5/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * IPX Routing Information Protocol.  */
end_comment

begin_comment
comment|/*  * Trace record format.  */
end_comment

begin_struct
struct|struct
name|iftrace
block|{
name|time_t
name|ift_stamp
decl_stmt|;
comment|/* time stamp */
name|struct
name|sockaddr
name|ift_who
decl_stmt|;
comment|/* from/to */
name|char
modifier|*
name|ift_packet
decl_stmt|;
comment|/* pointer to packet */
name|short
name|ift_size
decl_stmt|;
comment|/* size of packet */
name|short
name|ift_metric
decl_stmt|;
comment|/* metric  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per interface packet tracing buffers.  An incoming and  * outgoing circular buffer of packets is maintained, per  * interface, for debugging.  Buffers are dumped whenever  * an interface is marked down.  */
end_comment

begin_struct
struct|struct
name|ifdebug
block|{
name|struct
name|iftrace
modifier|*
name|ifd_records
decl_stmt|;
comment|/* array of trace records */
name|struct
name|iftrace
modifier|*
name|ifd_front
decl_stmt|;
comment|/* next empty trace record */
name|int
name|ifd_count
decl_stmt|;
comment|/* number of unprinted records */
name|struct
name|interface
modifier|*
name|ifd_if
decl_stmt|;
comment|/* for locating stuff */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packet tracing stuff.  */
end_comment

begin_decl_stmt
name|int
name|tracepackets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* watch packets as they go by */
end_comment

begin_decl_stmt
name|int
name|tracing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* on/off */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|ftrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output trace file */
end_comment

begin_define
define|#
directive|define
name|TRACE_ACTION
parameter_list|(
name|action
parameter_list|,
name|route
parameter_list|)
value|{ \ 	  if (tracing) \ 		traceaction(ftrace, "action", route); \ 	  traceactionlog(action, route); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_SAP_ACTION
parameter_list|(
name|action
parameter_list|,
name|service
parameter_list|)
value|{ \ 	  tracesapactionlog(action, service); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_INPUT
parameter_list|(
name|ifp
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|{ \ 	  if (tracing) { \ 		ifp = if_iflookup(src); \ 		if (ifp) \ 			trace(&ifp->int_input, src, \&packet[sizeof(struct ipx)], size, \ 				ntohl(ifp->int_metric)); \ 	  } \ 	  if (tracepackets&& ftrace) \ 		dumppacket(ftrace, "from", src, \&packet[sizeof(struct ipx)], size); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_OUTPUT
parameter_list|(
name|ifp
parameter_list|,
name|dst
parameter_list|,
name|size
parameter_list|)
value|{ \ 	  if (tracing) { \ 		ifp = if_iflookup(dst); \ 		if (ifp) \ 		    trace(&ifp->int_output, dst, \&packet[sizeof(struct ipx)], \ 				size, ifp->int_metric); \ 	  } \ 	  if (tracepackets&& ftrace) \ 		dumppacket(ftrace, "to", dst, \&packet[sizeof(struct ipx)], size); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_SAP_OUTPUT
parameter_list|(
name|ifp
parameter_list|,
name|dst
parameter_list|,
name|size
parameter_list|)
value|{ \ 	  if (tracing) { \ 		ifp = if_iflookup(dst); \ 		if (ifp) \ 		    trace(&ifp->int_output, dst, \&packet[sizeof(struct ipx)], \ 				size, ifp->int_metric); \ 	  } \ 	  if (tracepackets&& ftrace) \ 		dumpsappacket(ftrace, "to", dst, \&packet[sizeof(struct ipx)], size); \ 	}
end_define

begin_function_decl
name|void
name|traceinit
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|traceon
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|traceoff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|traceaction
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|traceactionlog
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tracesapactionlog
parameter_list|(
name|char
modifier|*
name|action
parameter_list|,
name|struct
name|sap_entry
modifier|*
name|sap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace
parameter_list|(
name|struct
name|ifdebug
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumppacket
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpsappacket
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpsaptable
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|struct
name|sap_hash
modifier|*
name|sh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpriptable
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ipxdp_nettoa
parameter_list|(
name|union
name|ipx_net
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ipxdp_ntoa
parameter_list|(
name|struct
name|ipx_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

