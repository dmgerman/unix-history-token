begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)trace.h	5.2 (Berkeley) 4/20/86  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
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
comment|/* metric on associated metric */
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
value|{ \ 	  if (tracing) \ 		traceaction(ftrace, "action", route); \ 	}
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
value|{ \ 	  if (tracing) { \ 		ifp = if_iflookup(src); \ 		if (ifp) \ 			trace(&ifp->int_input, src, packet, size, \ 				ntohl(ifp->int_metric)); \ 	  } \ 	  if (tracepackets) \ 		dumppacket(stdout, "from", src, packet, size); \ 	}
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
value|{ \ 	  if (tracing&& ifp) \ 		trace(&ifp->int_output, dst, packet, size, ifp->int_metric); \ 	  if (tracepackets) \ 		dumppacket(stdout, "to", dst, packet, size); \ 	}
end_define

end_unit

