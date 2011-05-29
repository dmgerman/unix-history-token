begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
name|ipnet_hdr
block|{
name|uint8_t
name|iph_version
decl_stmt|;
name|uint8_t
name|iph_family
decl_stmt|;
name|uint16_t
name|iph_htype
decl_stmt|;
name|uint32_t
name|iph_pktlen
decl_stmt|;
name|uint32_t
name|iph_ifindex
decl_stmt|;
name|uint32_t
name|iph_grifindex
decl_stmt|;
name|uint32_t
name|iph_zsrc
decl_stmt|;
name|uint32_t
name|iph_zdst
decl_stmt|;
block|}
name|ipnet_hdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPH_AF_INET
value|2
end_define

begin_comment
comment|/* Matches Solaris's AF_INET */
end_comment

begin_define
define|#
directive|define
name|IPH_AF_INET6
value|26
end_define

begin_comment
comment|/* Matches Solaris's AF_INET6 */
end_comment

end_unit

