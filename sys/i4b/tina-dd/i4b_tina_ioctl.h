begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1994, 1998 Hellmuth Michaelis. All rights reserved.  *  *   Based on code written by Stollmann GmbH, Hamburg. Many thanks to  *   Christian Luehrs and Manfred Jung for docs, sources and answers!  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_tina_ioctl.h - i4b Stollman Tina-dd ioctl header file  *	---------------------------------------------------------  *  * $FreeBSD$  *  *	last edit-date: [Sat Dec  5 18:41:51 1998]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_TINA_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_TINA_IOCTL_H_
end_define

begin_define
define|#
directive|define
name|TINA_IOSIZE
value|8
end_define

begin_comment
comment|/* 8 byte wide iospace occupied */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	register offsets in i/o address space  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CTRL_STAT
value|0
end_define

begin_comment
comment|/* control& status	*/
end_comment

begin_define
define|#
directive|define
name|ADDR_CNTL
value|1
end_define

begin_comment
comment|/* address pointer low	*/
end_comment

begin_define
define|#
directive|define
name|ADDR_CNTM
value|2
end_define

begin_comment
comment|/* address pointer mid	*/
end_comment

begin_define
define|#
directive|define
name|ADDR_CNTH
value|3
end_define

begin_comment
comment|/* address pointer high	*/
end_comment

begin_define
define|#
directive|define
name|DATA_LOW
value|4
end_define

begin_comment
comment|/* data register low	*/
end_comment

begin_define
define|#
directive|define
name|DATA_HIGH
value|5
end_define

begin_comment
comment|/* data register high	*/
end_comment

begin_define
define|#
directive|define
name|DATA_LOW_INC
value|6
end_define

begin_comment
comment|/* data register low, post inc	*/
end_comment

begin_define
define|#
directive|define
name|DATA_HIGH_INC
value|7
end_define

begin_comment
comment|/* data register high, post inc	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	status register (CTRL_STAT read access)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CR_INTC
value|0x80
end_define

begin_comment
comment|/* irq FROM tina-dd TO pc active */
end_comment

begin_define
define|#
directive|define
name|CR_INTP
value|0x40
end_define

begin_comment
comment|/* irq FROM pc TO tina-dd active */
end_comment

begin_define
define|#
directive|define
name|CR_INTPA
value|0x20
end_define

begin_comment
comment|/* irq FROM pc TO tina-dd active */
end_comment

begin_define
define|#
directive|define
name|CR_NMI
value|0x10
end_define

begin_comment
comment|/* nmi FROM PC TO tina-dd active */
end_comment

begin_define
define|#
directive|define
name|CR_FLASHLD
value|0x08
end_define

begin_comment
comment|/* read of the FLASHLD-bit (n/c) */
end_comment

begin_define
define|#
directive|define
name|CR_S2C
value|0x04
end_define

begin_comment
comment|/* info bit */
end_comment

begin_define
define|#
directive|define
name|CR_S1C
value|0x02
end_define

begin_comment
comment|/* info bit */
end_comment

begin_define
define|#
directive|define
name|CR_S0C
value|0x01
end_define

begin_comment
comment|/* info bit */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	control register (CTRL_STAT write access)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CR_CLR_INTC
value|0x80
end_define

begin_comment
comment|/* clear irq on tina-dd */
end_comment

begin_define
define|#
directive|define
name|CR_SET_INTP
value|0x40
end_define

begin_comment
comment|/* trigger irq on tina-dd */
end_comment

begin_define
define|#
directive|define
name|CR_RESET
value|0x20
end_define

begin_comment
comment|/* reset tina-dd */
end_comment

begin_define
define|#
directive|define
name|CR_SET_NMI
value|0x10
end_define

begin_comment
comment|/* trigger nmi on tina-dd */
end_comment

begin_define
define|#
directive|define
name|CR_SET_FLASHLD
value|0x08
end_define

begin_comment
comment|/* activates pin FLASHLD (n/c) */
end_comment

begin_define
define|#
directive|define
name|CR_S2P
value|0x04
end_define

begin_comment
comment|/* info bit (not readable !) */
end_comment

begin_define
define|#
directive|define
name|CR_S1P
value|0x02
end_define

begin_comment
comment|/* info bit (not readable !) */
end_comment

begin_define
define|#
directive|define
name|CR_S0P
value|0x01
end_define

begin_comment
comment|/* info bit (not readable !) */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	misc definitions in dual-ported mem on board of tina-dd  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|FW_SYSCB
value|0x200
end_define

begin_comment
comment|/* address of FW SYSCB / MJ 300392 */
end_comment

begin_define
define|#
directive|define
name|FW_SINFO_NAME
value|0x220
end_define

begin_comment
comment|/* address of general info label   */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TYPE
value|0x224
end_define

begin_comment
comment|/* address of hardware type byte:  */
end_comment

begin_define
define|#
directive|define
name|FW_HW_UNDEF
value|0x00
end_define

begin_comment
comment|/* undefined ..                    */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TINA_DD
value|0x10
end_define

begin_comment
comment|/* TINA-dd			   */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TINA_DS
value|0x20
end_define

begin_comment
comment|/* TINA-ds 	(B channel/ser ?)  */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TINA_D
value|0x30
end_define

begin_comment
comment|/* TINA-d	(one B channel ?)  */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TINA_DDM
value|0x40
end_define

begin_comment
comment|/* TINA-dd with fax module	   */
end_comment

begin_define
define|#
directive|define
name|FW_HW_TINA_DDS
value|0x50
end_define

begin_comment
comment|/* TINA-dd with fax/voice module   */
end_comment

begin_define
define|#
directive|define
name|FW_HW_SICCE
value|0x80
end_define

begin_comment
comment|/* X.25 board			   */
end_comment

begin_define
define|#
directive|define
name|FW_HW_ASIC
value|0x01
end_define

begin_comment
comment|/* ASIC version bit                */
end_comment

begin_define
define|#
directive|define
name|FW_STAT
value|0x228
end_define

begin_comment
comment|/* address of firmware status byte */
end_comment

begin_define
define|#
directive|define
name|FW_READY
value|0x20
end_define

begin_comment
comment|/* firmware ready bit		   */
end_comment

begin_define
define|#
directive|define
name|FW_BOOTPRM_RDY
value|0x02
end_define

begin_comment
comment|/* boot PROM ready		   */
end_comment

begin_define
define|#
directive|define
name|FW_UNDEF_0
value|0x00
end_define

begin_comment
comment|/* undefined			   */
end_comment

begin_define
define|#
directive|define
name|FW_UNDEF_1
value|0xFF
end_define

begin_comment
comment|/* undefined			   */
end_comment

begin_define
define|#
directive|define
name|FW_SINFO_ID
value|"SYSI"
end_define

begin_comment
comment|/* general info label for FW> 2.13*/
end_comment

begin_define
define|#
directive|define
name|FW_SINFO_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|FW_ADDR_PROFPTR
value|0x260
end_define

begin_comment
comment|/* addr of ptr to board profile	   */
end_comment

begin_comment
comment|/*===========================================================================*  *	Layer 0 - Hardware layer  *===========================================================================*/
end_comment

begin_comment
comment|/* control and status register access */
end_comment

begin_define
define|#
directive|define
name|ISDN_GETCSR
value|_IOR('I', 1, unsigned char)
end_define

begin_comment
comment|/* get csr */
end_comment

begin_define
define|#
directive|define
name|ISDN_SETCSR
value|_IOW('I', 2, unsigned char)
end_define

begin_comment
comment|/* set csr */
end_comment

begin_comment
comment|/* dual ported ram access */
end_comment

begin_define
define|#
directive|define
name|ISDN_GETBLK
value|_IOWR('I', 3, struct record)
end_define

begin_comment
comment|/* get dpr record */
end_comment

begin_define
define|#
directive|define
name|ISDN_SETBLK
value|_IOW('I', 4, struct record)
end_define

begin_comment
comment|/* set dpr record */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	record structure for dual ported ram block rd/wr  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|record
block|{
name|unsigned
name|int
name|length
decl_stmt|;
comment|/* length of data block */
name|unsigned
name|int
name|addr
decl_stmt|;
comment|/* address of mem on tina-dd board */
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
comment|/* pointer to the datablock itself */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_TINA_IOCTL_H_ */
end_comment

end_unit

