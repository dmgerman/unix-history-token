begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************* SPDX-License-Identifier: BSD-3-Clause  Copyright (c) 2003-2007  Cavium Networks (support@cavium.com). All rights reserved.   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above       copyright notice, this list of conditions and the following       disclaimer in the documentation and/or other materials provided       with the distribution.      * Neither the name of Cavium Networks nor the names of       its contributors may be used to endorse or promote products       derived from this software without specific prior written       permission.  This Software, including technical data, may be subject to U.S. export  control laws, including the U.S. Export Administration Act and its  associated regulations, and may be subject to export or import  regulations in other countries.  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|DEBUGPRINT
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
value|printf(format, ##__VA_ARGS__)
end_define

begin_comment
comment|/**  * Given a packet data address, return a pointer to the  * beginning of the packet buffer.  *  * @param packet_ptr Packet data hardware address  * @return Packet buffer pointer  */
end_comment

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|cvm_oct_get_buffer_ptr
parameter_list|(
name|cvmx_buf_ptr_t
name|packet_ptr
parameter_list|)
block|{
return|return
name|cvmx_phys_to_ptr
argument_list|(
operator|(
operator|(
name|packet_ptr
operator|.
name|s
operator|.
name|addr
operator|>>
literal|7
operator|)
operator|-
name|packet_ptr
operator|.
name|s
operator|.
name|back
operator|)
operator|<<
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Given an IPD/PKO port number, return the logical interface it is  * on.  *  * @param ipd_port Port to check  *  * @return Logical interface  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|INTERFACE
parameter_list|(
name|int
name|ipd_port
parameter_list|)
block|{
if|if
condition|(
name|ipd_port
operator|<
literal|32
condition|)
comment|/* Interface 0 or 1 for RGMII,GMII,SPI, etc */
return|return
name|ipd_port
operator|>>
literal|4
return|;
elseif|else
if|if
condition|(
name|ipd_port
operator|<
literal|36
condition|)
comment|/* Interface 2 for NPI */
return|return
literal|2
return|;
elseif|else
if|if
condition|(
name|ipd_port
operator|<
literal|40
condition|)
comment|/* Interface 3 for loopback */
return|return
literal|3
return|;
elseif|else
if|if
condition|(
name|ipd_port
operator|==
literal|40
condition|)
comment|/* Non existant interface for POW0 */
return|return
literal|4
return|;
else|else
name|panic
argument_list|(
literal|"Illegal ipd_port %d passed to INTERFACE\n"
argument_list|,
name|ipd_port
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Given an IPD/PKO port number, return the port's index on a  * logical interface.  *  * @param ipd_port Port to check  *  * @return Index into interface port list  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|INDEX
parameter_list|(
name|int
name|ipd_port
parameter_list|)
block|{
if|if
condition|(
name|ipd_port
operator|<
literal|32
condition|)
return|return
name|ipd_port
operator|&
literal|15
return|;
else|else
return|return
name|ipd_port
operator|&
literal|3
return|;
block|}
end_function

end_unit

