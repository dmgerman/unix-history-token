begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: ubsecreg.h,v 1.27 2002/09/11 22:40:31 jason Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000 Theo de Raadt  * Copyright (c) 2001 Patrik Lindergren (patrik@ipunplugged.com)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_comment
comment|/*  * Register definitions for 5601 BlueSteel Networks Ubiquitous Broadband  * Security "uBSec" chip.  Definitions from revision 2.8 of the product  * datasheet.  */
end_comment

begin_define
define|#
directive|define
name|BS_BAR
value|0x10
end_define

begin_comment
comment|/* DMA base address register */
end_comment

begin_define
define|#
directive|define
name|BS_TRDY_TIMEOUT
value|0x40
end_define

begin_comment
comment|/* TRDY timeout */
end_comment

begin_define
define|#
directive|define
name|BS_RETRY_TIMEOUT
value|0x41
end_define

begin_comment
comment|/* DMA retry timeout */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_BROADCOM
value|0x14e4
end_define

begin_comment
comment|/* Broadcom */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_BLUESTEEL
value|0x15ab
end_define

begin_comment
comment|/* Bluesteel Networks */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_SUN
value|0x108e
end_define

begin_comment
comment|/* Sun Microsystems */
end_comment

begin_comment
comment|/* Bluesteel Networks */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BLUESTEEL_5501
value|0x0000
end_define

begin_comment
comment|/* 5501 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BLUESTEEL_5601
value|0x5601
end_define

begin_comment
comment|/* 5601 */
end_comment

begin_comment
comment|/* Broadcom */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_BCM5700
value|0x1644
end_define

begin_comment
comment|/* BCM5700 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_BCM5701
value|0x1645
end_define

begin_comment
comment|/* BCM5701 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5801
value|0x5801
end_define

begin_comment
comment|/* 5801 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5802
value|0x5802
end_define

begin_comment
comment|/* 5802 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5805
value|0x5805
end_define

begin_comment
comment|/* 5805 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5820
value|0x5820
end_define

begin_comment
comment|/* 5820 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5821
value|0x5821
end_define

begin_comment
comment|/* 5821 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5822
value|0x5822
end_define

begin_comment
comment|/* 5822 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_5823
value|0x5823
end_define

begin_comment
comment|/* 5823 */
end_comment

begin_comment
comment|/* Sun Microsystems */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_SUN_5821
value|0x5454
end_define

begin_comment
comment|/* Crypto 5821 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_SUN_SCA1K
value|0x5455
end_define

begin_comment
comment|/* Crypto 1K */
end_comment

begin_define
define|#
directive|define
name|UBS_PCI_RTY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|UBS_PCI_RTY_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|UBS_PCI_RTY
parameter_list|(
name|misc
parameter_list|)
define|\
value|(((misc)>> UBS_PCI_RTY_SHIFT)& UBS_PCI_RTY_MASK)
end_define

begin_define
define|#
directive|define
name|UBS_PCI_TOUT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|UBS_PCI_TOUT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|UBS_PCI_TOUT
parameter_list|(
name|misc
parameter_list|)
define|\
value|(((misc)>> PCI_TOUT_SHIFT)& PCI_TOUT_MASK)
end_define

begin_comment
comment|/*  * DMA Control& Status Registers (offset from BS_BAR)  */
end_comment

begin_define
define|#
directive|define
name|BS_MCR1
value|0x00
end_define

begin_comment
comment|/* DMA Master Command Record 1 */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL
value|0x04
end_define

begin_comment
comment|/* DMA Control */
end_comment

begin_define
define|#
directive|define
name|BS_STAT
value|0x08
end_define

begin_comment
comment|/* DMA Status */
end_comment

begin_define
define|#
directive|define
name|BS_ERR
value|0x0c
end_define

begin_comment
comment|/* DMA Error Address */
end_comment

begin_define
define|#
directive|define
name|BS_MCR2
value|0x10
end_define

begin_comment
comment|/* DMA Master Command Record 2 */
end_comment

begin_comment
comment|/* BS_CTRL - DMA Control */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RESET
value|0x80000000
end_define

begin_comment
comment|/* hardware reset, 5805/5820 */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_MCR2INT
value|0x40000000
end_define

begin_comment
comment|/* enable intr MCR for MCR2 */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_MCR1INT
value|0x20000000
end_define

begin_comment
comment|/* enable intr MCR for MCR1 */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_OFM
value|0x10000000
end_define

begin_comment
comment|/* Output fragment mode */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_BE32
value|0x08000000
end_define

begin_comment
comment|/* big-endian, 32bit bytes */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_BE64
value|0x04000000
end_define

begin_comment
comment|/* big-endian, 64bit bytes */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_DMAERR
value|0x02000000
end_define

begin_comment
comment|/* enable intr DMA error */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RNG_M
value|0x01800000
end_define

begin_comment
comment|/* RNG mode */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RNG_1
value|0x00000000
end_define

begin_comment
comment|/* 1bit rn/one slow clock */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RNG_4
value|0x00800000
end_define

begin_comment
comment|/* 1bit rn/four slow clocks */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RNG_8
value|0x01000000
end_define

begin_comment
comment|/* 1bit rn/eight slow clocks */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_RNG_16
value|0x01800000
end_define

begin_comment
comment|/* 1bit rn/16 slow clocks */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_SWNORM
value|0x00400000
end_define

begin_comment
comment|/* 582[01], sw normalization */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_FRAG_M
value|0x0000ffff
end_define

begin_comment
comment|/* output fragment size mask */
end_comment

begin_define
define|#
directive|define
name|BS_CTRL_LITTLE_ENDIAN
value|(BS_CTRL_BE32 | BS_CTRL_BE64)
end_define

begin_comment
comment|/* BS_STAT - DMA Status */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR1_BUSY
value|0x80000000
end_define

begin_comment
comment|/* MCR1 is busy */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR1_FULL
value|0x40000000
end_define

begin_comment
comment|/* MCR1 is full */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR1_DONE
value|0x20000000
end_define

begin_comment
comment|/* MCR1 is done */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_DMAERR
value|0x10000000
end_define

begin_comment
comment|/* DMA error */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR2_FULL
value|0x08000000
end_define

begin_comment
comment|/* MCR2 is full */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR2_DONE
value|0x04000000
end_define

begin_comment
comment|/* MCR2 is done */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR1_ALLEMPTY
value|0x02000000
end_define

begin_comment
comment|/* 5821, MCR1 is empty */
end_comment

begin_define
define|#
directive|define
name|BS_STAT_MCR2_ALLEMPTY
value|0x01000000
end_define

begin_comment
comment|/* 5821, MCR2 is empty */
end_comment

begin_comment
comment|/* BS_ERR - DMA Error Address */
end_comment

begin_define
define|#
directive|define
name|BS_ERR_ADDR
value|0xfffffffc
end_define

begin_comment
comment|/* error address mask */
end_comment

begin_define
define|#
directive|define
name|BS_ERR_READ
value|0x00000002
end_define

begin_comment
comment|/* fault was on read */
end_comment

begin_struct
struct|struct
name|ubsec_pktctx
block|{
name|u_int32_t
name|pc_deskey
index|[
literal|6
index|]
decl_stmt|;
comment|/* 3DES key */
name|u_int32_t
name|pc_hminner
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac inner state */
name|u_int32_t
name|pc_hmouter
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac outer state */
name|u_int32_t
name|pc_iv
index|[
literal|2
index|]
decl_stmt|;
comment|/* [3]DES iv */
name|u_int16_t
name|pc_flags
decl_stmt|;
comment|/* flags, below */
name|u_int16_t
name|pc_offset
decl_stmt|;
comment|/* crypto offset */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_PKTCTX_ENC_3DES
value|0x8000
end_define

begin_comment
comment|/* use 3des */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_ENC_NONE
value|0x0000
end_define

begin_comment
comment|/* no encryption */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_INBOUND
value|0x4000
end_define

begin_comment
comment|/* inbound packet */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_AUTH
value|0x3000
end_define

begin_comment
comment|/* authentication mask */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_AUTH_NONE
value|0x0000
end_define

begin_comment
comment|/* no authentication */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_AUTH_MD5
value|0x1000
end_define

begin_comment
comment|/* use hmac-md5 */
end_comment

begin_define
define|#
directive|define
name|UBS_PKTCTX_AUTH_SHA1
value|0x2000
end_define

begin_comment
comment|/* use hmac-sha1 */
end_comment

begin_struct
struct|struct
name|ubsec_pktctx_long
block|{
specifier|volatile
name|u_int16_t
name|pc_len
decl_stmt|;
comment|/* length of ctx struct */
specifier|volatile
name|u_int16_t
name|pc_type
decl_stmt|;
comment|/* context type, 0 */
specifier|volatile
name|u_int16_t
name|pc_flags
decl_stmt|;
comment|/* flags, same as above */
specifier|volatile
name|u_int16_t
name|pc_offset
decl_stmt|;
comment|/* crypto/auth offset */
specifier|volatile
name|u_int32_t
name|pc_deskey
index|[
literal|6
index|]
decl_stmt|;
comment|/* 3DES key */
specifier|volatile
name|u_int32_t
name|pc_iv
index|[
literal|2
index|]
decl_stmt|;
comment|/* [3]DES iv */
specifier|volatile
name|u_int32_t
name|pc_hminner
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac inner state */
specifier|volatile
name|u_int32_t
name|pc_hmouter
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac outer state */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_PKTCTX_TYPE_IPSEC
value|0x0000
end_define

begin_struct
struct|struct
name|ubsec_pktbuf
block|{
specifier|volatile
name|u_int32_t
name|pb_addr
decl_stmt|;
comment|/* address of buffer start */
specifier|volatile
name|u_int32_t
name|pb_next
decl_stmt|;
comment|/* pointer to next pktbuf */
specifier|volatile
name|u_int32_t
name|pb_len
decl_stmt|;
comment|/* packet length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_PKTBUF_LEN
value|0x0000ffff
end_define

begin_comment
comment|/* length mask */
end_comment

begin_struct
struct|struct
name|ubsec_mcr
block|{
specifier|volatile
name|u_int16_t
name|mcr_pkts
decl_stmt|;
comment|/* #pkts in this mcr */
specifier|volatile
name|u_int16_t
name|mcr_flags
decl_stmt|;
comment|/* mcr flags (below) */
specifier|volatile
name|u_int32_t
name|mcr_cmdctxp
decl_stmt|;
comment|/* command ctx pointer */
name|struct
name|ubsec_pktbuf
name|mcr_ipktbuf
decl_stmt|;
comment|/* input chain header */
specifier|volatile
name|u_int16_t
name|mcr_reserved
decl_stmt|;
specifier|volatile
name|u_int16_t
name|mcr_pktlen
decl_stmt|;
name|struct
name|ubsec_pktbuf
name|mcr_opktbuf
decl_stmt|;
comment|/* output chain header */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_mcr_add
block|{
specifier|volatile
name|u_int32_t
name|mcr_cmdctxp
decl_stmt|;
comment|/* command ctx pointer */
name|struct
name|ubsec_pktbuf
name|mcr_ipktbuf
decl_stmt|;
comment|/* input chain header */
specifier|volatile
name|u_int16_t
name|mcr_reserved
decl_stmt|;
specifier|volatile
name|u_int16_t
name|mcr_pktlen
decl_stmt|;
name|struct
name|ubsec_pktbuf
name|mcr_opktbuf
decl_stmt|;
comment|/* output chain header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_MCR_DONE
value|0x0001
end_define

begin_comment
comment|/* mcr has been processed */
end_comment

begin_define
define|#
directive|define
name|UBS_MCR_ERROR
value|0x0002
end_define

begin_comment
comment|/* error in processing */
end_comment

begin_define
define|#
directive|define
name|UBS_MCR_ERRORCODE
value|0xff00
end_define

begin_comment
comment|/* error type */
end_comment

begin_struct
struct|struct
name|ubsec_ctx_keyop
block|{
specifier|volatile
name|u_int16_t
name|ctx_len
decl_stmt|;
comment|/* command length */
specifier|volatile
name|u_int16_t
name|ctx_op
decl_stmt|;
comment|/* operation code */
specifier|volatile
name|u_int8_t
name|ctx_pad
index|[
literal|60
index|]
decl_stmt|;
comment|/* padding */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_CTXOP_DHPKGEN
value|0x01
end_define

begin_comment
comment|/* dh public key generation */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_DHSSGEN
value|0x02
end_define

begin_comment
comment|/* dh shared secret gen. */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_RSAPUB
value|0x03
end_define

begin_comment
comment|/* rsa public key op */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_RSAPRIV
value|0x04
end_define

begin_comment
comment|/* rsa private key op */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_DSASIGN
value|0x05
end_define

begin_comment
comment|/* dsa signing op */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_DSAVRFY
value|0x06
end_define

begin_comment
comment|/* dsa verification */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_RNGBYPASS
value|0x41
end_define

begin_comment
comment|/* rng direct test mode */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_RNGSHA1
value|0x42
end_define

begin_comment
comment|/* rng sha1 test mode */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODADD
value|0x43
end_define

begin_comment
comment|/* modular addition */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODSUB
value|0x44
end_define

begin_comment
comment|/* modular subtraction */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODMUL
value|0x45
end_define

begin_comment
comment|/* modular multiplication */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODRED
value|0x46
end_define

begin_comment
comment|/* modular reduction */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODEXP
value|0x47
end_define

begin_comment
comment|/* modular exponentiation */
end_comment

begin_define
define|#
directive|define
name|UBS_CTXOP_MODINV
value|0x48
end_define

begin_comment
comment|/* modular inverse */
end_comment

begin_struct
struct|struct
name|ubsec_ctx_rngbypass
block|{
specifier|volatile
name|u_int16_t
name|rbp_len
decl_stmt|;
comment|/* command length, 64 */
specifier|volatile
name|u_int16_t
name|rbp_op
decl_stmt|;
comment|/* rng bypass, 0x41 */
specifier|volatile
name|u_int8_t
name|rbp_pad
index|[
literal|60
index|]
decl_stmt|;
comment|/* padding */
block|}
struct|;
end_struct

begin_comment
comment|/* modexp: C = (M ^ E) mod N */
end_comment

begin_struct
struct|struct
name|ubsec_ctx_modexp
block|{
specifier|volatile
name|u_int16_t
name|me_len
decl_stmt|;
comment|/* command length */
specifier|volatile
name|u_int16_t
name|me_op
decl_stmt|;
comment|/* modexp, 0x47 */
specifier|volatile
name|u_int16_t
name|me_E_len
decl_stmt|;
comment|/* E (bits) */
specifier|volatile
name|u_int16_t
name|me_N_len
decl_stmt|;
comment|/* N (bits) */
name|u_int8_t
name|me_N
index|[
literal|2048
operator|/
literal|8
index|]
decl_stmt|;
comment|/* N */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_ctx_rsapriv
block|{
specifier|volatile
name|u_int16_t
name|rpr_len
decl_stmt|;
comment|/* command length */
specifier|volatile
name|u_int16_t
name|rpr_op
decl_stmt|;
comment|/* rsaprivate, 0x04 */
specifier|volatile
name|u_int16_t
name|rpr_q_len
decl_stmt|;
comment|/* q (bits) */
specifier|volatile
name|u_int16_t
name|rpr_p_len
decl_stmt|;
comment|/* p (bits) */
name|u_int8_t
name|rpr_buf
index|[
literal|5
operator|*
literal|1024
operator|/
literal|8
index|]
decl_stmt|;
comment|/* parameters: */
comment|/* p, q, dp, dq, pinv */
block|}
struct|;
end_struct

end_unit

