begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 - Andrey "nording" Chernyak<andrew@nording.ru>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Format and print Realtek Remote Control Protocol (RRCP)  * and Realtek Echo Protocol (RRCP-REP) packets.  */
end_comment

begin_comment
comment|/* \summary: Realtek Remote Control Protocol (RRCP) printer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdissect-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"ether.h"
end_include

begin_define
define|#
directive|define
name|RRCP_OPCODE_MASK
value|0x7F
end_define

begin_comment
comment|/* 0x00 = hello, 0x01 = get, 0x02 = set */
end_comment

begin_define
define|#
directive|define
name|RRCP_ISREPLY
value|0x80
end_define

begin_comment
comment|/* 0 = request to switch, 0x80 = reply from switch */
end_comment

begin_define
define|#
directive|define
name|RRCP_PROTO_OFFSET
value|0
end_define

begin_comment
comment|/* proto - 1 byte, must be 1 */
end_comment

begin_define
define|#
directive|define
name|RRCP_OPCODE_ISREPLY_OFFSET
value|1
end_define

begin_comment
comment|/* opcode and isreply flag - 1 byte */
end_comment

begin_define
define|#
directive|define
name|RRCP_AUTHKEY_OFFSET
value|2
end_define

begin_comment
comment|/* authorization key - 2 bytes, 0x2379 by default */
end_comment

begin_comment
comment|/* most packets */
end_comment

begin_define
define|#
directive|define
name|RRCP_REG_ADDR_OFFSET
value|4
end_define

begin_comment
comment|/* register address - 2 bytes */
end_comment

begin_define
define|#
directive|define
name|RRCP_REG_DATA_OFFSET
value|6
end_define

begin_comment
comment|/* register data - 4 bytes */
end_comment

begin_define
define|#
directive|define
name|RRCP_COOKIE1_OFFSET
value|10
end_define

begin_comment
comment|/* 4 bytes */
end_comment

begin_define
define|#
directive|define
name|RRCP_COOKIE2_OFFSET
value|14
end_define

begin_comment
comment|/* 4 bytes */
end_comment

begin_comment
comment|/* hello reply packets */
end_comment

begin_define
define|#
directive|define
name|RRCP_DOWNLINK_PORT_OFFSET
value|4
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|RRCP_UPLINK_PORT_OFFSET
value|5
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|RRCP_UPLINK_MAC_OFFSET
value|6
end_define

begin_comment
comment|/* 6 byte MAC address */
end_comment

begin_define
define|#
directive|define
name|RRCP_CHIP_ID_OFFSET
value|12
end_define

begin_comment
comment|/* 2 bytes */
end_comment

begin_define
define|#
directive|define
name|RRCP_VENDOR_ID_OFFSET
value|14
end_define

begin_comment
comment|/* 4 bytes */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|proto_values
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"RRCP"
block|}
block|,
block|{
literal|2
block|,
literal|"RRCP-REP"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|opcode_values
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"hello"
block|}
block|,
block|{
literal|1
block|,
literal|"get"
block|}
block|,
block|{
literal|2
block|,
literal|"set"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print RRCP requests  */
end_comment

begin_function
name|void
name|rrcp_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
name|u_int
name|length
name|_U_
parameter_list|,
specifier|const
name|struct
name|lladdr_info
modifier|*
name|src
parameter_list|,
specifier|const
name|struct
name|lladdr_info
modifier|*
name|dst
parameter_list|)
block|{
name|uint8_t
name|rrcp_proto
decl_stmt|;
name|uint8_t
name|rrcp_opcode
decl_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_PROTO_OFFSET
operator|)
argument_list|)
expr_stmt|;
name|rrcp_proto
operator|=
operator|*
operator|(
name|cp
operator|+
name|RRCP_PROTO_OFFSET
operator|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_OPCODE_ISREPLY_OFFSET
operator|)
argument_list|)
expr_stmt|;
name|rrcp_opcode
operator|=
operator|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_OPCODE_ISREPLY_OFFSET
operator|)
operator|)
operator|&
name|RRCP_OPCODE_MASK
expr_stmt|;
if|if
condition|(
name|src
operator|!=
name|NULL
operator|&&
name|dst
operator|!=
name|NULL
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s> %s, "
operator|,
call|(
name|src
operator|->
name|addr_string
call|)
argument_list|(
name|ndo
argument_list|,
name|src
operator|->
name|addr
argument_list|)
operator|,
call|(
name|dst
operator|->
name|addr_string
call|)
argument_list|(
name|ndo
argument_list|,
name|dst
operator|->
name|addr
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s %s"
operator|,
name|tok2str
argument_list|(
name|proto_values
argument_list|,
literal|"RRCP-0x%02x"
argument_list|,
name|rrcp_proto
argument_list|)
operator|,
operator|(
operator|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_OPCODE_ISREPLY_OFFSET
operator|)
operator|)
operator|&
name|RRCP_ISREPLY
operator|)
condition|?
literal|"reply"
else|:
literal|"query"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rrcp_proto
operator|==
literal|1
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|": %s"
operator|,
name|tok2str
argument_list|(
name|opcode_values
argument_list|,
literal|"unknown opcode (0x%02x)"
argument_list|,
name|rrcp_opcode
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rrcp_opcode
operator|==
literal|1
operator|||
name|rrcp_opcode
operator|==
literal|2
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_REG_ADDR_OFFSET
operator|)
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" addr=0x%04x, data=0x%08x"
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
name|cp
operator|+
name|RRCP_REG_ADDR_OFFSET
argument_list|)
operator|,
name|EXTRACT_LE_32BITS
argument_list|(
name|cp
operator|+
name|RRCP_REG_DATA_OFFSET
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rrcp_proto
operator|==
literal|1
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_AUTHKEY_OFFSET
operator|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|", auth=0x%04x"
operator|,
name|EXTRACT_16BITS
argument_list|(
name|cp
operator|+
name|RRCP_AUTHKEY_OFFSET
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rrcp_proto
operator|==
literal|1
operator|&&
name|rrcp_opcode
operator|==
literal|0
operator|&&
operator|(
operator|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_OPCODE_ISREPLY_OFFSET
operator|)
operator|)
operator|&
name|RRCP_ISREPLY
operator|)
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_VENDOR_ID_OFFSET
operator|)
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" downlink_port=%d, uplink_port=%d, uplink_mac=%s, vendor_id=%08x ,chip_id=%04x "
operator|,
operator|*
operator|(
name|cp
operator|+
name|RRCP_DOWNLINK_PORT_OFFSET
operator|)
operator|,
operator|*
operator|(
name|cp
operator|+
name|RRCP_UPLINK_PORT_OFFSET
operator|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|cp
operator|+
name|RRCP_UPLINK_MAC_OFFSET
argument_list|)
operator|,
name|EXTRACT_32BITS
argument_list|(
name|cp
operator|+
name|RRCP_VENDOR_ID_OFFSET
argument_list|)
operator|,
name|EXTRACT_16BITS
argument_list|(
name|cp
operator|+
name|RRCP_CHIP_ID_OFFSET
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|rrcp_opcode
operator|==
literal|1
operator|||
name|rrcp_opcode
operator|==
literal|2
operator|||
name|rrcp_proto
operator|==
literal|2
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
operator|(
name|cp
operator|+
name|RRCP_COOKIE2_OFFSET
operator|)
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|", cookie=0x%08x%08x "
operator|,
name|EXTRACT_32BITS
argument_list|(
name|cp
operator|+
name|RRCP_COOKIE2_OFFSET
argument_list|)
operator|,
name|EXTRACT_32BITS
argument_list|(
name|cp
operator|+
name|RRCP_COOKIE1_OFFSET
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[|rrcp]"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

