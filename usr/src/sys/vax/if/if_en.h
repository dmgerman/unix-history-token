begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_en.h	4.1	81/11/30	*/
end_comment

begin_comment
comment|/*  * Structure of a Ethernet header.  */
end_comment

begin_struct
struct|struct
name|en_header
block|{
name|u_char
name|en_shost
decl_stmt|;
name|u_char
name|en_dhost
decl_stmt|;
name|u_short
name|en_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENPUP_IPTYPE
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_comment
comment|/*  * The ENPUP_NTRAILER packet types starting at ENPUP_TRAIL have  * (type-ENPUP_TRAIL)*512 bytes of data followed  * by a PUP type (as given above).  */
end_comment

begin_define
define|#
directive|define
name|ENPUP_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer PUP */
end_comment

begin_define
define|#
directive|define
name|ENPUP_NTRAILER
value|16
end_define

end_unit

