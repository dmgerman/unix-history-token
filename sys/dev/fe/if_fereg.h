begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Hardware specification of various 8696x based Ethernet cards.  * Contributed by M. Sekiguchi<seki@sysrap.cs.fujitsu.co.jp>  *  * All Rights Reserved, Copyright (C) Fujitsu Limited 1995  *  * This software may be used, modified, copied, distributed, and sold,  * in both source and binary form provided that the above copyright,  * these terms and the following disclaimer are retained.  The name of  * the author and/or the contributor may not be used to endorse or  * promote products derived from this software without specific prior  * written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND THE CONTRIBUTOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE CONTRIBUTOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Registers on FMV-180 series' ISA bus interface ASIC.  * I'm not sure the following register names are appropriate.  * Doesn't it look silly, eh?  FIXME.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV0
value|16
end_define

begin_comment
comment|/* Card status register #0	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV1
value|17
end_define

begin_comment
comment|/* Card status register #1	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV2
value|18
end_define

begin_comment
comment|/* Card config register #0	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV3
value|19
end_define

begin_comment
comment|/* Card config register #1	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV4
value|20
end_define

begin_comment
comment|/* Station address #1		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV5
value|21
end_define

begin_comment
comment|/* Station address #2		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV6
value|22
end_define

begin_comment
comment|/* Station address #3		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV7
value|23
end_define

begin_comment
comment|/* Station address #4		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV8
value|24
end_define

begin_comment
comment|/* Station address #5		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV9
value|25
end_define

begin_comment
comment|/* Station address #6		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV10
value|26
end_define

begin_comment
comment|/* Buffer RAM control register	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV11
value|27
end_define

begin_comment
comment|/* Buffer RAM data register	*/
end_comment

begin_comment
comment|/*  * FMV-180 series' ASIC register values.  */
end_comment

begin_comment
comment|/* FMV0: Card status register #0: Misc info?  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MEDIA
value|0x07
end_define

begin_comment
comment|/* Supported physical media.	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_PRRDY
value|0x10
end_define

begin_comment
comment|/* ???				*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_PRERR
value|0x20
end_define

begin_comment
comment|/* ???				*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_ERRDY
value|0x40
end_define

begin_comment
comment|/* ???				*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_IREQ
value|0x80
end_define

begin_comment
comment|/* ???				*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MEDIUM_5
value|0x01
end_define

begin_comment
comment|/* 10base5/Dsub		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MEDIUM_2
value|0x02
end_define

begin_comment
comment|/* 10base2/BNC		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MEDIUM_T
value|0x04
end_define

begin_comment
comment|/* 10baseT/RJ45		*/
end_comment

begin_comment
comment|/* Card status register #1: Hardware revision.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV1_REV
value|0x0F
end_define

begin_comment
comment|/* Card revision		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV1_UPPER
value|0xF0
end_define

begin_comment
comment|/* Usage unknown		*/
end_comment

begin_comment
comment|/* Card config register #0: I/O port address assignment.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_IOS
value|0x07
end_define

begin_comment
comment|/* I/O selection.		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_MES
value|0x38
end_define

begin_comment
comment|/* ??? boot ROM?		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_IRS
value|0xC0
end_define

begin_comment
comment|/* IRQ selection.		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_IOS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FE_FMV2_MES_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|FE_FMV2_IRS_SHIFT
value|6
end_define

begin_comment
comment|/* Card config register #1: IRQ enable  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV3_IRQENB
value|0x80
end_define

begin_comment
comment|/* IRQ enable.			*/
end_comment

begin_comment
comment|/*  * Register(?) specific to AT1700/RE2000.  */
end_comment

begin_define
define|#
directive|define
name|FE_ATI_RESET
value|0x1F
end_define

begin_comment
comment|/* Write to reset the 86965.	*/
end_comment

begin_comment
comment|/* EEPROM allocation (offsets) of AT1700/RE2000.  */
end_comment

begin_define
define|#
directive|define
name|FE_ATI_EEP_ADDR
value|0x08
end_define

begin_comment
comment|/* Station address.  (8-13)	*/
end_comment

begin_define
define|#
directive|define
name|FE_ATI_EEP_MEDIA
value|0x18
end_define

begin_comment
comment|/* Media type.			*/
end_comment

begin_define
define|#
directive|define
name|FE_ATI_EEP_MAGIC
value|0x19
end_define

begin_comment
comment|/* XXX Magic.			*/
end_comment

begin_define
define|#
directive|define
name|FE_ATI_EEP_MODEL
value|0x1e
end_define

begin_comment
comment|/* Hardware type.		*/
end_comment

begin_define
define|#
directive|define
name|FE_ATI_EEP_REVISION
value|0x1f
end_define

begin_comment
comment|/* Hardware revision.		*/
end_comment

begin_comment
comment|/* Value for FE_ATI_EEP_MODEL.  */
end_comment

begin_define
define|#
directive|define
name|FE_ATI_MODEL_AT1700T
value|0x00
end_define

begin_define
define|#
directive|define
name|FE_ATI_MODEL_AT1700BT
value|0x01
end_define

begin_define
define|#
directive|define
name|FE_ATI_MODEL_AT1700FT
value|0x02
end_define

begin_define
define|#
directive|define
name|FE_ATI_MODEL_AT1700AT
value|0x03
end_define

begin_comment
comment|/*  * Registers on MBH10302.  */
end_comment

begin_define
define|#
directive|define
name|FE_MBH0
value|0x10
end_define

begin_comment
comment|/* ???  Including interrupt.	*/
end_comment

begin_define
define|#
directive|define
name|FE_MBH1
value|0x11
end_define

begin_comment
comment|/* ???				*/
end_comment

begin_define
define|#
directive|define
name|FE_MBH10
value|0x1A
end_define

begin_comment
comment|/* Station address.  (10 - 15)	*/
end_comment

begin_comment
comment|/* Values to be set in MBH0 register.  */
end_comment

begin_define
define|#
directive|define
name|FE_MBH0_MAGIC
value|0x0D
end_define

begin_comment
comment|/* Just a magic constant?	*/
end_comment

begin_define
define|#
directive|define
name|FE_MBH0_INTR
value|0x10
end_define

begin_comment
comment|/* Master interrupt control.	*/
end_comment

begin_define
define|#
directive|define
name|FE_MBH0_INTR_ENABLE
value|0x10
end_define

begin_comment
comment|/* Enable interrupts.	*/
end_comment

begin_define
define|#
directive|define
name|FE_MBH0_INTR_DISABLE
value|0x00
end_define

begin_comment
comment|/* Disable interrupts.	*/
end_comment

begin_comment
comment|/*  * Registers on RE1000.  (*NOT* on RE1000 Plus.)  */
end_comment

begin_comment
comment|/* IRQ configuration.  */
end_comment

begin_define
define|#
directive|define
name|FE_RE1000_IRQCONF
value|0x10
end_define

begin_comment
comment|/*  * Fujitsu MB86965 JLI mode support routines.  */
end_comment

begin_comment
comment|/* Datasheet for 86965 explicitly states that it only supports serial  * EEPROM with 16 words (32 bytes) capacity.  (I.e., 93C06.)  However,  * ones with 64 words (128 bytes) are available in the marked, namely  * 93C46, and are also fully compatible with 86965.  It is known that  * some boards (e.g., ICL) actually have 93C46 on them and use extra  * storage to keep various config info.  */
end_comment

begin_define
define|#
directive|define
name|JLI_EEPROM_SIZE
value|128
end_define

begin_comment
comment|/*  * SSi 78Q8377A support routines.  */
end_comment

begin_define
define|#
directive|define
name|SSI_EEPROM_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|SSI_DIN
value|0x01
end_define

begin_define
define|#
directive|define
name|SSI_DAT
value|0x01
end_define

begin_define
define|#
directive|define
name|SSI_CSL
value|0x02
end_define

begin_define
define|#
directive|define
name|SSI_CLK
value|0x04
end_define

begin_define
define|#
directive|define
name|SSI_EEP
value|0x10
end_define

begin_define
define|#
directive|define
name|FE_SSI_EEP_IRQ
value|9
end_define

begin_comment
comment|/* Irq ???		*/
end_comment

begin_define
define|#
directive|define
name|FE_SSI_EEP_ADDR
value|16
end_define

begin_comment
comment|/* Station(MAC) address	*/
end_comment

begin_define
define|#
directive|define
name|FE_SSI_EEP_DUPLEX
value|25
end_define

begin_comment
comment|/* Duplex mode ???	*/
end_comment

begin_comment
comment|/*  * TDK/LANX boards support routines.  */
end_comment

begin_comment
comment|/* AX012/AX013 equips an X24C01 chip, which has 128 bytes of memory cells.  */
end_comment

begin_define
define|#
directive|define
name|LNX_EEPROM_SIZE
value|128
end_define

begin_comment
comment|/* Bit assignments and command definitions for the serial EEPROM    interface register in LANX ASIC.  */
end_comment

begin_define
define|#
directive|define
name|LNX_SDA_HI
value|0x08
end_define

begin_comment
comment|/* Drive SDA line high (logical 1.)	*/
end_comment

begin_define
define|#
directive|define
name|LNX_SDA_LO
value|0x00
end_define

begin_comment
comment|/* Drive SDA line low (logical 0.)	*/
end_comment

begin_define
define|#
directive|define
name|LNX_SDA_FL
value|0x08
end_define

begin_comment
comment|/* Float (don't drive) SDA line.	*/
end_comment

begin_define
define|#
directive|define
name|LNX_SDA_IN
value|0x01
end_define

begin_comment
comment|/* Mask for reading SDA line.		*/
end_comment

begin_define
define|#
directive|define
name|LNX_CLK_HI
value|0x04
end_define

begin_comment
comment|/* Drive clock line high (active.)	*/
end_comment

begin_define
define|#
directive|define
name|LNX_CLK_LO
value|0x00
end_define

begin_comment
comment|/* Drive clock line low (inactive.)	*/
end_comment

end_unit

