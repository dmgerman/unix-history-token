begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/l2tp.h,v 1.4 2000/12/17 23:07:49 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, 1993, 1994, 1995, 1996, 1997  *      The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * L2TP support contributed by Motonori Shindo (mshindo@mshindo.net)  */
end_comment

begin_define
define|#
directive|define
name|L2TP_FLAG_TYPE
value|0x8000
end_define

begin_comment
comment|/* Type (0=Data, 1=Control) */
end_comment

begin_define
define|#
directive|define
name|L2TP_FLAG_LENGTH
value|0x4000
end_define

begin_comment
comment|/* Length */
end_comment

begin_define
define|#
directive|define
name|L2TP_FLAG_SEQUENCE
value|0x0800
end_define

begin_comment
comment|/* Sequence */
end_comment

begin_define
define|#
directive|define
name|L2TP_FLAG_OFFSET
value|0x0200
end_define

begin_comment
comment|/* Offset */
end_comment

begin_define
define|#
directive|define
name|L2TP_FLAG_PRIORITY
value|0x0100
end_define

begin_comment
comment|/* Priority */
end_comment

begin_define
define|#
directive|define
name|L2TP_VERSION_MASK
value|0x000f
end_define

begin_comment
comment|/* Version Mask */
end_comment

begin_define
define|#
directive|define
name|L2TP_VERSION_L2F
value|0x0001
end_define

begin_comment
comment|/* L2F */
end_comment

begin_define
define|#
directive|define
name|L2TP_VERSION_L2TP
value|0x0002
end_define

begin_comment
comment|/* L2TP */
end_comment

begin_define
define|#
directive|define
name|L2TP_AVP_HDR_FLAG_MANDATORY
value|0x8000
end_define

begin_comment
comment|/* Mandatory Flag */
end_comment

begin_define
define|#
directive|define
name|L2TP_AVP_HDR_FLAG_HIDDEN
value|0x4000
end_define

begin_comment
comment|/* Hidden Flag */
end_comment

begin_define
define|#
directive|define
name|L2TP_AVP_HDR_LEN_MASK
value|0x03ff
end_define

begin_comment
comment|/* Length Mask */
end_comment

begin_define
define|#
directive|define
name|L2TP_FRAMING_CAP_SYNC_MASK
value|0x00000001
end_define

begin_comment
comment|/* Synchronous */
end_comment

begin_define
define|#
directive|define
name|L2TP_FRAMING_CAP_ASYNC_MASK
value|0x00000002
end_define

begin_comment
comment|/* Asynchronous */
end_comment

begin_define
define|#
directive|define
name|L2TP_FRAMING_TYPE_SYNC_MASK
value|0x00000001
end_define

begin_comment
comment|/* Synchronous */
end_comment

begin_define
define|#
directive|define
name|L2TP_FRAMING_TYPE_ASYNC_MASK
value|0x00000002
end_define

begin_comment
comment|/* Asynchronous */
end_comment

begin_define
define|#
directive|define
name|L2TP_BEARER_CAP_DIGITAL_MASK
value|0x00000001
end_define

begin_comment
comment|/* Digital */
end_comment

begin_define
define|#
directive|define
name|L2TP_BEARER_CAP_ANALOG_MASK
value|0x00000002
end_define

begin_comment
comment|/* Analog */
end_comment

begin_define
define|#
directive|define
name|L2TP_BEARER_TYPE_DIGITAL_MASK
value|0x00000001
end_define

begin_comment
comment|/* Digital */
end_comment

begin_define
define|#
directive|define
name|L2TP_BEARER_TYPE_ANALOG_MASK
value|0x00000002
end_define

begin_comment
comment|/* Analog */
end_comment

begin_comment
comment|/* Authen Type */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_RESERVED
value|0x0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_TEXTUAL
value|0x0001
end_define

begin_comment
comment|/* Textual username/password exchange */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_CHAP
value|0x0002
end_define

begin_comment
comment|/* PPP CHAP */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_PAP
value|0x0003
end_define

begin_comment
comment|/* PPP PAP */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_NO_AUTH
value|0x0004
end_define

begin_comment
comment|/* No Authentication */
end_comment

begin_define
define|#
directive|define
name|L2TP_AUTHEN_TYPE_MSCHAP
value|0x0005
end_define

begin_comment
comment|/* MSCHAPv1 */
end_comment

begin_define
define|#
directive|define
name|L2TP_PROXY_AUTH_ID_MASK
value|0x00ff
end_define

begin_struct
struct|struct
name|l2tp_avp_vec
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|print
function_decl|)
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l2tp_call_errors
block|{
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|crc_errs
decl_stmt|;
name|u_int32_t
name|framing_errs
decl_stmt|;
name|u_int32_t
name|hardware_overruns
decl_stmt|;
name|u_int32_t
name|buffer_overruns
decl_stmt|;
name|u_int32_t
name|timeout_errs
decl_stmt|;
name|u_int32_t
name|alignment_errs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l2tp_accm
block|{
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|send_accm
decl_stmt|;
name|u_int32_t
name|recv_accm
decl_stmt|;
block|}
struct|;
end_struct

end_unit

