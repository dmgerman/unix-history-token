begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pcap-septel.c: Packet capture interface for Intel Septel card  *  * The functionality of this code attempts to mimic that of pcap-linux as much  * as possible.  This code is only needed when compiling in the Intel/Septel  * card code at the same time as another type of device.  *  * Authors: Gilbert HOYEK (gil_hoyek@hotmail.com), Elias M. KHOURY  * (+961 3 485343);  *  * @(#) $Header: /tcpdump/master/libpcap/pcap-septel.h,v 1.1.2.1 2005/06/20 21:30:19 guy Exp $  */
end_comment

begin_function_decl
name|pcap_t
modifier|*
name|septel_open_live
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

