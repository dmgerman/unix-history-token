begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pcap-sita.h: Packet capture interface for SITA WAN devices  *  * Authors: Fulko Hew (fulko.hew@sita.aero) (+1 905 6815570);  */
end_comment

begin_function_decl
specifier|extern
name|int
name|acn_parse_hosts_file
parameter_list|(
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acn_findalldevs
parameter_list|(
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

end_unit

