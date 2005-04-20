begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pcap-dag.c: Packet capture interface for Endace DAG card.  *  * The functionality of this code attempts to mimic that of pcap-linux as much  * as possible.  This code is only needed when compiling in the DAG card code  * at the same time as another type of device.  *  * Author: Richard Littin, Sean Irvine ({richard,sean}@reeltwo.com)  *  * @(#) $Header: /tcpdump/master/libpcap/pcap-dag.h,v 1.3 2003/07/25 05:32:03 guy Exp $ (LBL)  */
end_comment

begin_function_decl
name|pcap_t
modifier|*
name|dag_open_live
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|,
name|int
name|snaplen
parameter_list|,
name|int
name|promisc
parameter_list|,
name|int
name|to_ms
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|)
function_decl|;
end_function_decl

end_unit

