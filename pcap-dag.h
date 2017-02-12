begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pcap-dag.c: Packet capture interface for Endace DAG card.  *  * The functionality of this code attempts to mimic that of pcap-linux as much  * as possible.  This code is only needed when compiling in the DAG card code  * at the same time as another type of device.  *  * Author: Richard Littin, Sean Irvine ({richard,sean}@reeltwo.com)  */
end_comment

begin_function_decl
name|pcap_t
modifier|*
name|dag_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dag_findalldevs
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|devlistp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

end_unit

