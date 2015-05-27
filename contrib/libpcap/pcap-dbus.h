begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|pcap_t
modifier|*
name|dbus_create
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
name|dbus_findalldevs
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

