begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	in_local.h	4.2	83/03/13	*/
end_comment

begin_comment
comment|/*  * Internet definitions and variables  * specific to installation at Berkeley.  */
end_comment

begin_comment
comment|/*  * Local subnetwork address mapping.  * The standard scheme is:  *	internet address = network.local-part  * where  *	network is between 8 and 34 bits  *	local-part is between 8 and 24 bits  *  * This is modified by interpreting network as 32 bits  * and local-part as something between 8 and 23 bits  * depending on the high bit in the local-part.  When  * the high bit in the local-part is a 1, the upper byte  * is interpreted as a local network extension, and used  * as the high byte in the network (extending it to 32 bits).  * The additional 8 bits of network number are administered  * locally and are not visible outside Berkeley, since  * they're part of the local-part.  */
end_comment

begin_comment
comment|/* network mappings */
end_comment

begin_define
define|#
directive|define
name|CLASSA_LOCALNETMAP
parameter_list|(
name|n
parameter_list|,
name|in
parameter_list|)
define|\
value|(in)& 0x800000 ? (n) | (((in)& 0xef0000)<< 8) : (n)
end_define

begin_define
define|#
directive|define
name|CLASSB_LOCALNETMAP
parameter_list|(
name|n
parameter_list|,
name|in
parameter_list|)
define|\
value|(in)& 0x8000 ? (n) | (((in)& 0xef00)<< 16) : (n)
end_define

begin_define
define|#
directive|define
name|CLASSC_LOCALNETMAP
parameter_list|(
name|n
parameter_list|,
name|in
parameter_list|)
value|(n)
end_define

begin_comment
comment|/* local-part mappings */
end_comment

begin_define
define|#
directive|define
name|CLASSA_LOCALHOSTMAP
parameter_list|(
name|h
parameter_list|,
name|in
parameter_list|)
define|\
value|(in)& 0x800000 ? (h)& ~0xef0000 : (h)
end_define

begin_define
define|#
directive|define
name|CLASSB_LOCALHOSTMAP
parameter_list|(
name|h
parameter_list|,
name|in
parameter_list|)
define|\
value|(in)& 0x8000 ? (h)& ~0xef00 : (h)
end_define

begin_define
define|#
directive|define
name|CLASSC_LOCALHOSTMAP
parameter_list|(
name|h
parameter_list|,
name|in
parameter_list|)
value|(h)
end_define

end_unit

