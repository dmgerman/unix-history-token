begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /tcpdump/master/tcpdump/ntp.h,v 1.4 2000/10/03 02:54:57 itojun Exp $ */
end_comment

begin_comment
comment|/*  * Based on ntp.h from the U of MD implementation  *	This file is based on Version 2 of the NTP spec (RFC1119).  */
end_comment

begin_comment
comment|/*  *  Definitions for the masses  */
end_comment

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_comment
comment|/*  * Structure definitions for NTP fixed point values  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Integer Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Fraction Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |		  Integer Part	     |	   Fraction Part	     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|l_fixedpt
block|{
name|u_int32_t
name|int_part
decl_stmt|;
name|u_int32_t
name|fraction
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s_fixedpt
block|{
name|u_int16_t
name|int_part
decl_stmt|;
name|u_int16_t
name|fraction
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  =================  Table 3.3. Packet Variables   ================= */
end_comment

begin_comment
comment|/*  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |LI | VN  | Mode|	  Stratum    |	    Poll     |	 Precision   |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			   Synchronizing Distance		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			  Synchronizing Dispersion		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			Reference Clock Identifier		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |		       Reference Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |		       Originate Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |			Receive Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |			Transmit Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|ntpdata
block|{
name|u_char
name|status
decl_stmt|;
comment|/* status of local clock and leap info */
name|u_char
name|stratum
decl_stmt|;
comment|/* Stratum level */
name|u_char
name|ppoll
decl_stmt|;
comment|/* poll value */
name|int
name|precision
range|:
literal|8
decl_stmt|;
name|struct
name|s_fixedpt
name|distance
decl_stmt|;
name|struct
name|s_fixedpt
name|dispersion
decl_stmt|;
name|u_int32_t
name|refid
decl_stmt|;
name|struct
name|l_fixedpt
name|reftime
decl_stmt|;
name|struct
name|l_fixedpt
name|org
decl_stmt|;
name|struct
name|l_fixedpt
name|rec
decl_stmt|;
name|struct
name|l_fixedpt
name|xmt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Leap Second Codes (high order two bits)  */
end_comment

begin_define
define|#
directive|define
name|NO_WARNING
value|0x00
end_define

begin_comment
comment|/* no warning */
end_comment

begin_define
define|#
directive|define
name|PLUS_SEC
value|0x40
end_define

begin_comment
comment|/* add a second (61 seconds) */
end_comment

begin_define
define|#
directive|define
name|MINUS_SEC
value|0x80
end_define

begin_comment
comment|/* minus a second (59 seconds) */
end_comment

begin_define
define|#
directive|define
name|ALARM
value|0xc0
end_define

begin_comment
comment|/* alarm condition (clock unsynchronized) */
end_comment

begin_comment
comment|/*  *	Clock Status Bits that Encode Version  */
end_comment

begin_define
define|#
directive|define
name|NTPVERSION_1
value|0x08
end_define

begin_define
define|#
directive|define
name|VERSIONMASK
value|0x38
end_define

begin_define
define|#
directive|define
name|LEAPMASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|MODEMASK
value|0x07
end_define

begin_comment
comment|/*  *	Code values  */
end_comment

begin_define
define|#
directive|define
name|MODE_UNSPEC
value|0
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_define
define|#
directive|define
name|MODE_SYM_ACT
value|1
end_define

begin_comment
comment|/* symmetric active */
end_comment

begin_define
define|#
directive|define
name|MODE_SYM_PAS
value|2
end_define

begin_comment
comment|/* symmetric passive */
end_comment

begin_define
define|#
directive|define
name|MODE_CLIENT
value|3
end_define

begin_comment
comment|/* client */
end_comment

begin_define
define|#
directive|define
name|MODE_SERVER
value|4
end_define

begin_comment
comment|/* server */
end_comment

begin_define
define|#
directive|define
name|MODE_BROADCAST
value|5
end_define

begin_comment
comment|/* broadcast */
end_comment

begin_define
define|#
directive|define
name|MODE_RES1
value|6
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|MODE_RES2
value|7
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/*  *	Stratum Definitions  */
end_comment

begin_define
define|#
directive|define
name|UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|PRIM_REF
value|1
end_define

begin_comment
comment|/* radio clock */
end_comment

begin_define
define|#
directive|define
name|INFO_QUERY
value|62
end_define

begin_comment
comment|/* **** THIS implementation dependent **** */
end_comment

begin_define
define|#
directive|define
name|INFO_REPLY
value|63
end_define

begin_comment
comment|/* **** THIS implementation dependent **** */
end_comment

end_unit

