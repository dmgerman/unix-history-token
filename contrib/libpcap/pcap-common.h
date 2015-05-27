begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * We use the "receiver-makes-right" approach to byte order,  * because time is at a premium when we are writing the file.  * In other words, the pcap_file_header and pcap_pkthdr,  * records are written in host byte order.  * Note that the bytes of packet data are written out in the order in  * which they were received, so multi-byte fields in packets are not  * written in host byte order, they're written in whatever order the  * sending machine put them in.  *  * ntoh[ls] aren't sufficient because we might need to swap on a big-endian  * machine (if the file was written in little-end order).  */
end_comment

begin_define
define|#
directive|define
name|SWAPLONG
parameter_list|(
name|y
parameter_list|)
define|\
value|((((y)&0xff)<<24) | (((y)&0xff00)<<8) | (((y)&0xff0000)>>8) | (((y)>>24)&0xff))
end_define

begin_define
define|#
directive|define
name|SWAPSHORT
parameter_list|(
name|y
parameter_list|)
define|\
value|( (((y)&0xff)<<8) | ((u_short)((y)&0xff00)>>8) )
end_define

begin_function_decl
specifier|extern
name|int
name|dlt_to_linktype
parameter_list|(
name|int
name|dlt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linktype_to_dlt
parameter_list|(
name|int
name|linktype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|swap_pseudo_headers
parameter_list|(
name|int
name|linktype
parameter_list|,
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

