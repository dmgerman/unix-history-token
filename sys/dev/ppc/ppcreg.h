begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ppcreg.h,v 1.2 1997/08/16 14:07:26 msmith Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPCREG_H
end_ifndef

begin_define
define|#
directive|define
name|__PPCREG_H
end_define

begin_comment
comment|/*  * Parallel Port Chipset type.  */
end_comment

begin_define
define|#
directive|define
name|SMC_LIKE
value|0x0
end_define

begin_define
define|#
directive|define
name|SMC_37C665GT
value|0x1
end_define

begin_define
define|#
directive|define
name|SMC_37C666GT
value|0x2
end_define

begin_define
define|#
directive|define
name|NS_PC87332
value|0x3
end_define

begin_define
define|#
directive|define
name|NS_PC87306
value|0x4
end_define

begin_define
define|#
directive|define
name|INTEL_820191AA
value|0x5
end_define

begin_comment
comment|/* XXX not implemented */
end_comment

begin_define
define|#
directive|define
name|GENERIC
value|0x6
end_define

begin_define
define|#
directive|define
name|WINB_W83877F
value|0x7
end_define

begin_define
define|#
directive|define
name|WINB_W83877AF
value|0x8
end_define

begin_define
define|#
directive|define
name|WINB_UNKNOWN
value|0x9
end_define

begin_comment
comment|/*  * Generic structure to hold parallel port chipset info.  */
end_comment

begin_struct
struct|struct
name|ppc_data
block|{
name|int
name|ppc_unit
decl_stmt|;
name|int
name|ppc_type
decl_stmt|;
name|int
name|ppc_mode
decl_stmt|;
comment|/* chipset current mode */
name|int
name|ppc_avm
decl_stmt|;
comment|/* chipset available modes */
define|#
directive|define
name|ppc_base
value|ppc_link.base
define|#
directive|define
name|ppc_epp
value|ppc_link.epp_protocol
define|#
directive|define
name|ppc_irq
value|ppc_link.id_irq
define|#
directive|define
name|ppc_subm
value|ppc_link.submicroseq
name|unsigned
name|char
name|ppc_flags
decl_stmt|;
name|struct
name|ppb_link
name|ppc_link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parallel Port Chipset registers.  */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_DTR
value|0
end_define

begin_comment
comment|/* SPP data register */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_STR
value|1
end_define

begin_comment
comment|/* SPP status register */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_CTR
value|2
end_define

begin_comment
comment|/* SPP control register */
end_comment

begin_define
define|#
directive|define
name|PPC_EPP_DATA
value|4
end_define

begin_comment
comment|/* EPP data register (8, 16 or 32 bit) */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_FIFO
value|0x400
end_define

begin_comment
comment|/* ECP fifo register */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_ECR
value|0x402
end_define

begin_comment
comment|/* ECP extended control register */
end_comment

begin_define
define|#
directive|define
name|r_dtr
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_SPP_DTR))
end_define

begin_define
define|#
directive|define
name|r_str
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_SPP_STR))
end_define

begin_define
define|#
directive|define
name|r_ctr
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_SPP_CTR))
end_define

begin_define
define|#
directive|define
name|r_epp
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_EPP_DATA))
end_define

begin_define
define|#
directive|define
name|r_ecr
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_ECP_ECR))
end_define

begin_define
define|#
directive|define
name|r_fifo
parameter_list|(
name|ppc
parameter_list|)
value|((char)inb((ppc)->ppc_base + PPC_ECP_FIFO))
end_define

begin_define
define|#
directive|define
name|w_dtr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_DTR, byte)
end_define

begin_define
define|#
directive|define
name|w_str
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_STR, byte)
end_define

begin_define
define|#
directive|define
name|w_ctr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_CTR, byte)
end_define

begin_define
define|#
directive|define
name|w_epp
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_EPP_DATA, byte)
end_define

begin_define
define|#
directive|define
name|w_ecr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_ECP_ECR, byte)
end_define

begin_define
define|#
directive|define
name|w_fifo
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_ECP_FIFO, byte)
end_define

begin_comment
comment|/*  * Register defines for the PC873xx parts  */
end_comment

begin_define
define|#
directive|define
name|PC873_FER
value|0x00
end_define

begin_define
define|#
directive|define
name|PC873_PPENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PC873_FAR
value|0x01
end_define

begin_define
define|#
directive|define
name|PC873_PTR
value|0x02
end_define

begin_define
define|#
directive|define
name|PC873_CFGLOCK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PC873_EPPRDIR
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PC873_FCR
value|0x03
end_define

begin_define
define|#
directive|define
name|PC873_ZWS
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PC873_ZWSPWDN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PC873_PCR
value|0x04
end_define

begin_define
define|#
directive|define
name|PC873_EPPEN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PC873_EPP19
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PC873_ECPEN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PC873_ECPCLK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PC873_PMC
value|0x06
end_define

begin_define
define|#
directive|define
name|PC873_TUP
value|0x07
end_define

begin_define
define|#
directive|define
name|PC873_SID
value|0x08
end_define

begin_comment
comment|/*  * Register defines for the SMC FDC37C66xGT parts  */
end_comment

begin_comment
comment|/* Init codes */
end_comment

begin_define
define|#
directive|define
name|SMC665_iCODE
value|0x55
end_define

begin_define
define|#
directive|define
name|SMC666_iCODE
value|0x44
end_define

begin_comment
comment|/* Base configuration ports */
end_comment

begin_define
define|#
directive|define
name|SMC66x_CSR
value|0x3F0
end_define

begin_define
define|#
directive|define
name|SMC666_CSR
value|0x370
end_define

begin_comment
comment|/* hard-configured value for 666 */
end_comment

begin_comment
comment|/* Bits */
end_comment

begin_define
define|#
directive|define
name|SMC_CR1_ADDR
value|0x3
end_define

begin_comment
comment|/* bit 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR1_MODE
value|(1<<3)
end_define

begin_comment
comment|/* bit 3 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR4_EMODE
value|0x3
end_define

begin_comment
comment|/* bits 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR4_EPPTYPE
value|(1<<6)
end_define

begin_comment
comment|/* bit 6 */
end_comment

begin_comment
comment|/* Extended modes */
end_comment

begin_define
define|#
directive|define
name|SMC_SPP
value|0x0
end_define

begin_comment
comment|/* SPP */
end_comment

begin_define
define|#
directive|define
name|SMC_EPPSPP
value|0x1
end_define

begin_comment
comment|/* EPP and SPP */
end_comment

begin_define
define|#
directive|define
name|SMC_ECP
value|0x2
end_define

begin_comment
comment|/* ECP */
end_comment

begin_define
define|#
directive|define
name|SMC_ECPEPP
value|0x3
end_define

begin_comment
comment|/* ECP and EPP */
end_comment

begin_comment
comment|/*  * Register defines for the Winbond W83877F parts  */
end_comment

begin_define
define|#
directive|define
name|WINB_W83877F_ID
value|0xa
end_define

begin_define
define|#
directive|define
name|WINB_W83877AF_ID
value|0xb
end_define

begin_comment
comment|/* Configuration bits */
end_comment

begin_define
define|#
directive|define
name|WINB_HEFERE
value|(1<<5)
end_define

begin_comment
comment|/* CROC bit 5 */
end_comment

begin_define
define|#
directive|define
name|WINB_HEFRAS
value|(1<<0)
end_define

begin_comment
comment|/* CR16 bit 0 */
end_comment

begin_define
define|#
directive|define
name|WINB_PNPCVS
value|(1<<2)
end_define

begin_comment
comment|/* CR16 bit 2 */
end_comment

begin_define
define|#
directive|define
name|WINB_CHIPID
value|0xf
end_define

begin_comment
comment|/* CR9 bits 0-3 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS0
value|(1<<2)
end_define

begin_comment
comment|/* CR0 bit 2 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS1
value|(1<<3)
end_define

begin_comment
comment|/* CR0 bit 3 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS2
value|(1<<7)
end_define

begin_comment
comment|/* CR9 bit 7 */
end_comment

begin_comment
comment|/* W83877F modes: CR9/bit7 | CR0/bit3 | CR0/bit2 */
end_comment

begin_define
define|#
directive|define
name|WINB_W83757
value|0x0
end_define

begin_define
define|#
directive|define
name|WINB_EXTFDC
value|0x4
end_define

begin_define
define|#
directive|define
name|WINB_EXTADP
value|0x8
end_define

begin_define
define|#
directive|define
name|WINB_EXT2FDD
value|0xc
end_define

begin_define
define|#
directive|define
name|WINB_JOYSTICK
value|0x80
end_define

begin_define
define|#
directive|define
name|WINB_PARALLEL
value|0x80
end_define

begin_define
define|#
directive|define
name|WINB_EPP_SPP
value|0x4
end_define

begin_define
define|#
directive|define
name|WINB_ECP
value|0x8
end_define

begin_define
define|#
directive|define
name|WINB_ECP_EPP
value|0xc
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

