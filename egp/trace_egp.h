begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	trace_egp.h	*/
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_comment
comment|/* tracing levels */
end_comment

begin_define
define|#
directive|define
name|TR_INT
value|0x1
end_define

begin_comment
comment|/* internal errors */
end_comment

begin_define
define|#
directive|define
name|TR_EXT
value|0x2
end_define

begin_comment
comment|/* external errors and state changes resulting from 			   egp */
end_comment

begin_define
define|#
directive|define
name|TR_RT
value|0x4
end_define

begin_comment
comment|/* routing changes */
end_comment

begin_define
define|#
directive|define
name|TR_PKT
value|0x8
end_define

begin_comment
comment|/* all egp packets sent and received */
end_comment

begin_define
define|#
directive|define
name|TRACE_INT
value|if( tracing& TR_INT) printf
end_define

begin_define
define|#
directive|define
name|TRACE_EXT
value|if( tracing& TR_EXT) printf
end_define

begin_define
define|#
directive|define
name|TRACE_RT
value|if( tracing& TR_RT) printf
end_define

begin_define
define|#
directive|define
name|TRACE_ACTION
parameter_list|(
name|action
parameter_list|,
name|route
parameter_list|)
value|{ \ 	    if (tracing& TR_RT) \ 		traceaction( stdout, "action", route); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_EGPPKT
parameter_list|(
name|comment
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|,
name|egp
parameter_list|,
name|length
parameter_list|)
value|{ \ 	    if( tracing& TR_PKT) \ 		traceegp( "comment", src, dst, egp, length); \ 	}
end_define

end_unit

