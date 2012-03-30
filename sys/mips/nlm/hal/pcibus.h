begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XLP_PCIBUS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XLP_PCIBUS_H__
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_BASE
value|0xfee00000
end_define

begin_comment
comment|/* MSI support */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_DEST
value|0x000ff000
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_RH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_RH_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_RH_ON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_DM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_DM_PHYSICAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_ADDR_DM_LOGICAL
value|0x00000004
end_define

begin_comment
comment|/* Fields in data for Intel MSI messages. */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_TRGRMOD
value|0x00008000
end_define

begin_comment
comment|/* Trigger mode */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_TRGREDG
value|0x00000000
end_define

begin_comment
comment|/* edge */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_TRGRLVL
value|0x00008000
end_define

begin_comment
comment|/* level */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_LEVEL
value|0x00004000
end_define

begin_comment
comment|/* Polarity. */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_DEASSERT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_ASSERT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_DELMOD
value|0x00000700
end_define

begin_comment
comment|/* Delivery Mode */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_DELFIXED
value|0x00000000
end_define

begin_comment
comment|/* fixed */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_DELLOPRI
value|0x00000100
end_define

begin_comment
comment|/* lowest priority */
end_comment

begin_define
define|#
directive|define
name|MSI_MIPS_DATA_INTVEC
value|0x000000ff
end_define

begin_comment
comment|/* PCIE Memory and IO regions */
end_comment

begin_define
define|#
directive|define
name|PCIE_MEM_BASE
value|0xd0000000ULL
end_define

begin_define
define|#
directive|define
name|PCIE_MEM_LIMIT
value|0xdfffffffULL
end_define

begin_define
define|#
directive|define
name|PCIE_IO_BASE
value|0x14000000ULL
end_define

begin_define
define|#
directive|define
name|PCIE_IO_LIMIT
value|0x15ffffffULL
end_define

begin_define
define|#
directive|define
name|PCIE_BRIDGE_CMD
value|0x1
end_define

begin_define
define|#
directive|define
name|PCIE_BRIDGE_MSI_CAP
value|0x14
end_define

begin_define
define|#
directive|define
name|PCIE_BRIDGE_MSI_ADDRL
value|0x15
end_define

begin_define
define|#
directive|define
name|PCIE_BRIDGE_MSI_ADDRH
value|0x16
end_define

begin_define
define|#
directive|define
name|PCIE_BRIDGE_MSI_DATA
value|0x17
end_define

begin_comment
comment|/* XLP Global PCIE configuration space registers */
end_comment

begin_define
define|#
directive|define
name|PCIE_BYTE_SWAP_MEM_BASE
value|0x247
end_define

begin_define
define|#
directive|define
name|PCIE_BYTE_SWAP_MEM_LIM
value|0x248
end_define

begin_define
define|#
directive|define
name|PCIE_BYTE_SWAP_IO_BASE
value|0x249
end_define

begin_define
define|#
directive|define
name|PCIE_BYTE_SWAP_IO_LIM
value|0x24A
end_define

begin_define
define|#
directive|define
name|PCIE_MSI_STATUS
value|0x25A
end_define

begin_define
define|#
directive|define
name|PCIE_MSI_EN
value|0x25B
end_define

begin_define
define|#
directive|define
name|PCIE_INT_EN0
value|0x261
end_define

begin_comment
comment|/* PCIE_MSI_EN */
end_comment

begin_define
define|#
directive|define
name|PCIE_MSI_VECTOR_INT_EN
value|0xFFFFFFFF
end_define

begin_comment
comment|/* PCIE_INT_EN0 */
end_comment

begin_define
define|#
directive|define
name|PCIE_MSI_INT_EN
value|(1<< 9)
end_define

begin_comment
comment|/* XXXJC: Ax workaround */
end_comment

begin_define
define|#
directive|define
name|PCIE_LINK0_IRT
value|78
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_read_pcie_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_pcie_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_pcie_base
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_PCIE_OFFSET(node, inst))
end_define

begin_define
define|#
directive|define
name|nlm_get_pcie_regbase
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
define|\
value|(nlm_get_pcie_base(node, inst) + XLP_IO_PCI_HDRSZ)
end_define

begin_function
specifier|static
name|__inline
name|int
name|xlp_pcie_link_irt
parameter_list|(
name|int
name|link
parameter_list|)
block|{
if|if
condition|(
operator|(
name|link
operator|<
literal|0
operator|)
operator|||
operator|(
name|link
operator|>
literal|3
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|PCIE_LINK0_IRT
operator|+
name|link
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Build Intel MSI message and data values from a source.  AMD64 systems  * seem to be compatible, so we use the same function for both.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MSI_ADDR
parameter_list|(
name|cpu
parameter_list|)
define|\
value|(MSI_MIPS_ADDR_BASE | (cpu)<< 12 |			       \ 	 MSI_MIPS_ADDR_RH_OFF | MSI_MIPS_ADDR_DM_PHYSICAL)
end_define

begin_define
define|#
directive|define
name|MIPS_MSI_DATA
parameter_list|(
name|irq
parameter_list|)
define|\
value|(MSI_MIPS_DATA_TRGRLVL | MSI_MIPS_DATA_DELFIXED |	       \ 	 MSI_MIPS_DATA_ASSERT | (irq))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XLP_PCIBUS_H__ */
end_comment

end_unit

