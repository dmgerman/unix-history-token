begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: pim6.h,v 1.3 2000/03/25 07:23:58 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Protocol Independent Multicast (PIM) definitions  *  * Written by Ahmed Helmy, SGI, July 1996  *  * MULTICAST  */
end_comment

begin_comment
comment|/*  * PIM packet header  */
end_comment

begin_define
define|#
directive|define
name|PIM_VERSION
value|2
end_define

begin_struct
struct|struct
name|pim
block|{
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
name|u_char
name|pim_type
range|:
literal|4
decl_stmt|,
comment|/* the PIM message type, currently they are: 			     * Hello, Register, Register-Stop, Join/Prune, 			     * Bootstrap, Assert, Graft (PIM-DM only), 			     * Graft-Ack (PIM-DM only), C-RP-Adv 			     */
name|pim_ver
range|:
literal|4
decl_stmt|;
comment|/* PIM version number; 2 for PIMv2 */
else|#
directive|else
name|u_char
name|pim_ver
range|:
literal|4
decl_stmt|,
comment|/* PIM version */
name|pim_type
range|:
literal|4
decl_stmt|;
comment|/* PIM type    */
endif|#
directive|endif
name|u_char
name|pim_rsv
decl_stmt|;
comment|/* Reserved */
name|u_short
name|pim_cksum
decl_stmt|;
comment|/* IP style check sum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PIM_MINLEN
value|8
end_define

begin_comment
comment|/* The header min. length is 8    */
end_comment

begin_define
define|#
directive|define
name|PIM6_REG_MINLEN
value|(PIM_MINLEN+40)
end_define

begin_comment
comment|/* Register message + inner IP6 header */
end_comment

begin_comment
comment|/*  * Message types  */
end_comment

begin_define
define|#
directive|define
name|PIM_REGISTER
value|1
end_define

begin_comment
comment|/* PIM Register type is 1 */
end_comment

begin_comment
comment|/* second bit in reg_head is the null bit */
end_comment

begin_define
define|#
directive|define
name|PIM_NULL_REGISTER
value|0x40000000
end_define

end_unit

