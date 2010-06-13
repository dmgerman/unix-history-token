begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PRISM54_H
end_ifndef

begin_define
define|#
directive|define
name|PRISM54_H
end_define

begin_struct
struct|struct
name|ieee802_3_hdr_s
block|{
name|unsigned
name|char
name|da
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|sa
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|type
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ieee802_3_hdr_s
name|ieee802_3_hdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIMOP_GET
value|0
end_define

begin_define
define|#
directive|define
name|PIMOP_SET
value|1
end_define

begin_define
define|#
directive|define
name|PIMOP_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|PIMOP_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|PIMOP_TRAP
value|4
end_define

begin_struct
struct|struct
name|pimdev_hdr_s
block|{
name|int
name|op
decl_stmt|;
name|unsigned
name|long
name|oid
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pimdev_hdr_s
name|pimdev_hdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DOT11_OID_ATTACHMENT
value|0x19000003
end_define

begin_comment
comment|/* really need to check */
end_comment

begin_define
define|#
directive|define
name|DOT11_PKT_BEACON
value|0x80
end_define

begin_define
define|#
directive|define
name|DOT11_PKT_ASSOC_RESP
value|0x10
end_define

begin_define
define|#
directive|define
name|DOT11_PKT_REASSOC_RESP
value|0x30
end_define

begin_define
define|#
directive|define
name|DOT11_PKT_PROBE_RESP
value|0x50
end_define

begin_struct
struct|struct
name|obj_attachment_hdr
block|{
name|char
name|type
decl_stmt|;
name|char
name|reserved
decl_stmt|;
name|short
name|id
decl_stmt|;
name|short
name|size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|obj_attachment
block|{
name|char
name|type
decl_stmt|;
name|char
name|reserved
decl_stmt|;
name|short
name|id
decl_stmt|;
name|short
name|size
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_MLMEAUTOLEVEL
value|0x19000001
end_define

begin_define
define|#
directive|define
name|DOT11_MLME_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|DOT11_MLME_INTERMEDIATE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DOT11_MLME_EXTENDED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DEAUTHENTICATE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|DOT11_OID_AUTHENTICATE
value|0x18000001
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DISASSOCIATE
value|0x18000002
end_define

begin_define
define|#
directive|define
name|DOT11_OID_ASSOCIATE
value|0x18000003
end_define

begin_define
define|#
directive|define
name|DOT11_OID_BEACON
value|0x18000005
end_define

begin_define
define|#
directive|define
name|DOT11_OID_PROBE
value|0x18000006
end_define

begin_define
define|#
directive|define
name|DOT11_OID_REASSOCIATE
value|0x1800000b
end_define

begin_struct
struct|struct
name|obj_mlme
block|{
name|char
name|address
index|[
literal|6
index|]
decl_stmt|;
name|short
name|id
decl_stmt|;
name|short
name|state
decl_stmt|;
name|short
name|code
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_DEAUTHENTICATEEX
value|0x18000007
end_define

begin_define
define|#
directive|define
name|DOT11_OID_AUTHENTICATEEX
value|0x18000008
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DISASSOCIATEEX
value|0x18000009
end_define

begin_define
define|#
directive|define
name|DOT11_OID_ASSOCIATEEX
value|0x1800000a
end_define

begin_define
define|#
directive|define
name|DOT11_OID_REASSOCIATEEX
value|0x1800000c
end_define

begin_struct
struct|struct
name|obj_mlmeex
block|{
name|char
name|address
index|[
literal|6
index|]
decl_stmt|;
name|short
name|id
decl_stmt|;
name|short
name|state
decl_stmt|;
name|short
name|code
decl_stmt|;
name|short
name|size
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_STAKEY
value|0x12000008
end_define

begin_define
define|#
directive|define
name|DOT11_PRIV_WEP
value|0
end_define

begin_define
define|#
directive|define
name|DOT11_PRIV_TKIP
value|1
end_define

begin_comment
comment|/* endian reversed to bigger endian */
end_comment

begin_define
define|#
directive|define
name|DOT11_STAKEY_OPTION_DEFAULTKEY
value|0x100
end_define

begin_struct
struct|struct
name|obj_stakey
block|{
name|char
name|address
index|[
literal|6
index|]
decl_stmt|;
name|char
name|keyid
decl_stmt|;
name|char
name|reserved
decl_stmt|;
name|short
name|options
decl_stmt|;
name|char
name|type
decl_stmt|;
name|char
name|length
decl_stmt|;
name|char
name|key
index|[
literal|32
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_DEFKEYID
value|0x12000003
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DEFKEY1
value|0x12000004
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DEFKEY2
value|0x12000005
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DEFKEY3
value|0x12000006
end_define

begin_define
define|#
directive|define
name|DOT11_OID_DEFKEY4
value|0x12000007
end_define

begin_struct
struct|struct
name|obj_key
block|{
name|char
name|type
decl_stmt|;
name|char
name|length
decl_stmt|;
name|char
name|key
index|[
literal|32
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_STASC
value|0x1200000a
end_define

begin_struct
struct|struct
name|obj_stasc
block|{
name|char
name|address
index|[
literal|6
index|]
decl_stmt|;
name|char
name|keyid
decl_stmt|;
name|char
name|tx_sc
decl_stmt|;
name|unsigned
name|long
name|sc_high
decl_stmt|;
name|unsigned
name|short
name|sc_low
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_CLIENTS
value|0x15000001
end_define

begin_define
define|#
directive|define
name|DOT11_OID_CLIENTSASSOCIATED
value|0x15000002
end_define

begin_define
define|#
directive|define
name|DOT11_OID_CLIENTST
value|0x15000003
end_define

begin_define
define|#
directive|define
name|DOT11_OID_CLIENTEND
value|0x150007d9
end_define

begin_define
define|#
directive|define
name|DOT11_OID_CLIENTFIND
value|0x150007db
end_define

begin_define
define|#
directive|define
name|DOT11_NODE_UNKNOWN
end_define

begin_define
define|#
directive|define
name|DOT11_NODE_CLIENT
end_define

begin_define
define|#
directive|define
name|DOT11_NODE_AP
end_define

begin_comment
comment|/* endian reversed to bigger endian */
end_comment

begin_define
define|#
directive|define
name|DOT11_STATE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_AUTHING
value|0x100
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_AUTH
value|0x200
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_ASSOCING
value|0x300
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_REASSOCING
value|0x400
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_ASSOC
value|0x500
end_define

begin_define
define|#
directive|define
name|DOT11_STATE_WDS
value|0x600
end_define

begin_struct
struct|struct
name|obj_sta
block|{
name|char
name|address
index|[
literal|6
index|]
decl_stmt|;
name|char
name|pad
index|[
literal|2
index|]
decl_stmt|;
name|char
name|state
decl_stmt|;
name|char
name|node
decl_stmt|;
name|short
name|age
decl_stmt|;
name|char
name|reserved1
decl_stmt|;
name|char
name|rssi
decl_stmt|;
name|char
name|rate
decl_stmt|;
name|char
name|reserved2
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_SSID
value|0x10000002
end_define

begin_define
define|#
directive|define
name|DOT11_OID_SSIDOVERRIDE
value|0x10000006
end_define

begin_struct
struct|struct
name|obj_ssid
block|{
name|char
name|length
decl_stmt|;
name|char
name|octets
index|[
literal|33
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|DOT11_OID_EAPAUTHSTA
value|0x150007de
end_define

begin_define
define|#
directive|define
name|DOT11_OID_EAPUNAUTHSTA
value|0x150007df
end_define

begin_comment
comment|/* not in 38801 datasheet??? */
end_comment

begin_define
define|#
directive|define
name|DOT11_OID_DOT1XENABLE
value|0x150007e0
end_define

begin_define
define|#
directive|define
name|DOT11_OID_MICFAILURE
value|0x150007e1
end_define

begin_define
define|#
directive|define
name|DOT11_OID_AUTHENABLE
value|0x12000000
end_define

begin_define
define|#
directive|define
name|DOT11_OID_PRIVACYINVOKED
value|0x12000001
end_define

begin_define
define|#
directive|define
name|DOT11_OID_EXUNENCRYPTED
value|0x12000002
end_define

begin_define
define|#
directive|define
name|DOT11_AUTH_OS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DOT11_AUTH_SK
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DOT11_AUTH_BOTH
value|0x03000000
end_define

begin_define
define|#
directive|define
name|DOT11_BOOL_TRUE
value|0x01000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRISM54_H */
end_comment

end_unit

