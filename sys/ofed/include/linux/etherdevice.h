begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Cisco Systems, Inc.  All rights reserved.  * Copyright (c) 2014 Mellanox Technologies, Ltd. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *	- Redistributions of source code must retain the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer.  *  *	- Redistributions in binary form must reproduce the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer in the documentation and/or other materials  *	  provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_ETHERDEVICE
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_ETHERDEVICE
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/**  * is_zero_ether_addr - Determine if give Ethernet address is all zeros.  * @addr: Pointer to a six-byte array containing the Ethernet address  *  * Return true if the address is all zeroes.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_zero_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|!
operator|(
name|addr
index|[
literal|0
index|]
operator||
name|addr
index|[
literal|1
index|]
operator||
name|addr
index|[
literal|2
index|]
operator||
name|addr
index|[
literal|3
index|]
operator||
name|addr
index|[
literal|4
index|]
operator||
name|addr
index|[
literal|5
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * is_multicast_ether_addr - Determine if the Ethernet address is a multicast.  * @addr: Pointer to a six-byte array containing the Ethernet address  *  * Return true if the address is a multicast address.  * By definition the broadcast address is also a multicast address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_multicast_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
literal|0x01
operator|&
name|addr
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * is_broadcast_ether_addr - Determine if the Ethernet address is broadcast  * @addr: Pointer to a six-byte array containing the Ethernet address  *  * Return true if the address is the broadcast address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_broadcast_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
name|addr
index|[
literal|0
index|]
operator|&
name|addr
index|[
literal|1
index|]
operator|&
name|addr
index|[
literal|2
index|]
operator|&
name|addr
index|[
literal|3
index|]
operator|&
name|addr
index|[
literal|4
index|]
operator|&
name|addr
index|[
literal|5
index|]
operator|)
operator|==
literal|0xff
return|;
block|}
end_function

begin_comment
comment|/**  * is_valid_ether_addr - Determine if the given Ethernet address is valid  * @addr: Pointer to a six-byte array containing the Ethernet address  *  * Check that the Ethernet address (MAC) is not 00:00:00:00:00:00, is not  * a multicast address, and is not FF:FF:FF:FF:FF:FF.  *  * Return true if the address is valid.  **/
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_valid_ether_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
block|{
comment|/* FF:FF:FF:FF:FF:FF is a multicast address so we don't need to         ** explicitly check for it here. */
return|return
operator|!
name|is_multicast_ether_addr
argument_list|(
name|addr
argument_list|)
operator|&&
operator|!
name|is_zero_ether_addr
argument_list|(
name|addr
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_ETHERDEVICE */
end_comment

end_unit

