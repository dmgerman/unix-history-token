begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)trace.h	5.4 (Berkeley) 5/31/88  */
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
name|traceactions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* on/off */
end_comment

begin_decl_stmt
name|int
name|tracehistory
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

begin_decl_stmt
name|char
modifier|*
name|curtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current timestamp string */
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
value|{ \ 	  if (traceactions) \ 		traceaction(ftrace, action, route); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_NEWMETRIC
parameter_list|(
name|route
parameter_list|,
name|newmetric
parameter_list|)
value|{ \ 	  if (traceactions) \ 		tracenewmetric(ftrace, route, newmetric); \ 	}
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
value|{ \ 	  if (tracehistory) { \ 		ifp = if_iflookup(src); \ 		if (ifp) \ 			trace(&ifp->int_input, src, packet, size, \ 				ntohl(ifp->int_metric)); \ 	  } \ 	  if (tracepackets) { \ 		time_t t; \ 		t = time(0); \ 		dumppacket(stdout, "from", src, packet, size,&t); \ 	  } \ 	}
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
value|{ \ 	  if (tracehistory&& ifp) \ 		trace(&ifp->int_output, dst, packet, size, ifp->int_metric); \ 	  if (tracepackets) { \ 		time_t t; \ 		t = time(0); \ 		dumppacket(stdout, "to", dst, packet, size,&t); \ 	  } \ 	}
end_define

end_unit

