begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_vv.h	4.1	82/06/04	*/
end_comment

begin_comment
comment|/*  * Local network header for V2LNI Ring  * This is arbitrated by "V2LNI-PEOPLE@MIT-MC"  * (aka Joel N. Chiappa)  */
end_comment

begin_struct
struct|struct
name|vv_header
block|{
comment|/* the first two fields are required by the hardware */
name|u_char
name|vh_dhost
decl_stmt|;
comment|/* destination address */
name|u_char
name|vh_shost
decl_stmt|;
comment|/* source address */
comment|/* the next three fields are the local network header */
name|u_char
name|vh_version
decl_stmt|;
comment|/* header version */
name|u_char
name|vh_type
decl_stmt|;
comment|/* packet type => protocol number */
name|short
name|vh_info
decl_stmt|;
comment|/* protocol-specific information */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RING_VERSION
value|1
end_define

begin_comment
comment|/* current version of v2lni header */
end_comment

begin_comment
comment|/*  * Packet types (protocol numbers) in v2lni header  */
end_comment

begin_define
define|#
directive|define
name|RING_IP
value|1
end_define

begin_define
define|#
directive|define
name|RING_IPTrailer
value|2
end_define

begin_define
define|#
directive|define
name|RING_WHOAMI
value|0xa5
end_define

begin_comment
comment|/* insure some bit transitions */
end_comment

begin_define
define|#
directive|define
name|VV_BROADCAST
value|0
end_define

begin_comment
comment|/* hardware-defined broadcast address */
end_comment

begin_comment
comment|/*  * Proteon V2LNI Hardware definitions  * register bit definitions - new style  */
end_comment

begin_define
define|#
directive|define
name|VV_ENB
value|01
end_define

begin_comment
comment|/* Enable Operation */
end_comment

begin_define
define|#
directive|define
name|VV_DEN
value|02
end_define

begin_comment
comment|/* Enable DMA */
end_comment

begin_define
define|#
directive|define
name|VV_HEN
value|04
end_define

begin_comment
comment|/* Host Relay Enable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_CPB
value|04
end_define

begin_comment
comment|/* Clear Packet Buffer (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_STE
value|010
end_define

begin_comment
comment|/* Self Test Enable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_UT1
value|010
end_define

begin_comment
comment|/* Unused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_LPB
value|020
end_define

begin_comment
comment|/* Modem Disable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_INR
value|020
end_define

begin_comment
comment|/* Initialize Ring (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_RST
value|040
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|VV_IEN
value|0100
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|VV_RDY
value|0200
end_define

begin_comment
comment|/* Done */
end_comment

begin_define
define|#
directive|define
name|VV_DPR
value|0400
end_define

begin_comment
comment|/* Data Present (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_RFS
value|0400
end_define

begin_comment
comment|/* Refused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_NXM
value|01000
end_define

begin_comment
comment|/* Non Existent Memory */
end_comment

begin_define
define|#
directive|define
name|VV_OVR
value|02000
end_define

begin_comment
comment|/* Overrun */
end_comment

begin_define
define|#
directive|define
name|VV_ODB
value|04000
end_define

begin_comment
comment|/* Odd Byte (Achtung, mein Fuehrer) (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_UT2
value|04000
end_define

begin_comment
comment|/* Unused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_LDE
value|010000
end_define

begin_comment
comment|/* Link Data Error (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_OPT
value|010000
end_define

begin_comment
comment|/* Output Timeout (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_NOK
value|020000
end_define

begin_comment
comment|/* Ring Not OK */
end_comment

begin_define
define|#
directive|define
name|VV_BDF
value|040000
end_define

begin_comment
comment|/* Bad Format in Operation */
end_comment

begin_define
define|#
directive|define
name|VV_NIR
value|0100000
end_define

begin_comment
comment|/* Not in Ring */
end_comment

begin_define
define|#
directive|define
name|VVXERR
value|(VV_NXM|VV_OVR|VV_OPT|VV_BDF)
end_define

begin_comment
comment|/* Xmit errs */
end_comment

begin_define
define|#
directive|define
name|VVRERR
value|(VV_NXM|VV_OVR|VV_ODB|VV_BDF)
end_define

begin_comment
comment|/* Rcv errs */
end_comment

begin_define
define|#
directive|define
name|VVFE
value|(VV_NXM|VV_OVR)
end_define

begin_comment
comment|/* Fatal errors */
end_comment

begin_define
define|#
directive|define
name|VV_IBITS
define|\
value|"\10\20NIR\17BDF\16NOK\15LDE\14ODB\13OVR\12NXM\11DPR\10RDY\7IEN\6RST\5LPB\4STE\3HEN\2DEN\1ENB"
end_define

begin_define
define|#
directive|define
name|VV_OBITS
define|\
value|"\10\20NIR\17BDF\16NOK\15OPT\13OVR\12NXM\11RFS\10RDY\7IEN\6RST\5INR\3HEN\2DEN\1ENB"
end_define

begin_comment
comment|/* device registers */
end_comment

begin_struct
struct|struct
name|vvreg
block|{
name|short
name|vvicsr
decl_stmt|;
comment|/* input csr */
name|u_short
name|vviwc
decl_stmt|;
comment|/* input word count */
name|u_short
name|vviba
decl_stmt|;
comment|/* input addr lo */
name|u_short
name|vviea
decl_stmt|;
comment|/* input addr hi */
name|short
name|vvocsr
decl_stmt|;
comment|/* output csr */
name|u_short
name|vvowc
decl_stmt|;
comment|/* output word count */
name|u_short
name|vvoba
decl_stmt|;
comment|/* output addr lo */
name|u_short
name|vvoea
decl_stmt|;
comment|/* output addr hi */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VVRETRY
value|7
end_define

end_unit

