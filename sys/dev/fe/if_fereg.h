begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * All Rights Reserved, Copyright (C) Fujitsu Limited 1995  *  * This software may be used, modified, copied, distributed, and sold,  * in both source and binary form provided that the above copyright,  * these terms and the following disclaimer are retained.  The name of  * the author and/or the contributor may not be used to endorse or  * promote products derived from this software without specific prior  * written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND THE CONTRIBUTOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE CONTRIBUTOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|FE_REG_VERSION
value|"if_fereg.h ver. 0.8"
end_define

begin_comment
comment|/*  * Hardware specification of various 86960/86965 based Ethernet cards.  * Contributed by M.S.<seki@sysrap.cs.fujitsu.co.jp>  */
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
comment|/* Hardware status.		*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV1
value|17
end_define

begin_comment
comment|/* Hardrare type?  Always 0	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV2
value|18
end_define

begin_comment
comment|/* Hardware configuration.	*/
end_comment

begin_define
define|#
directive|define
name|FE_FMV3
value|19
end_define

begin_comment
comment|/* Hardware enable.		*/
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
comment|/* Unknown; to be set to 0.	*/
end_comment

begin_comment
comment|/*  * FMV-180 series' ASIC register values.  */
end_comment

begin_comment
comment|/* Magic value in FMV0 register.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MAGIC_MASK
value|0x78
end_define

begin_define
define|#
directive|define
name|FE_FMV0_MAGIC_VALUE
value|0x50
end_define

begin_comment
comment|/* Model identification.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV0_MODEL
value|0x07
end_define

begin_define
define|#
directive|define
name|FE_FMV0_MODEL_FMV181
value|0x05
end_define

begin_define
define|#
directive|define
name|FE_FMV0_MODEL_FMV182
value|0x03
end_define

begin_comment
comment|/* Card type ID?  Always 0?  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV1_CARDID_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|FE_FMV1_CARDID_ID
value|0x00
end_define

begin_comment
comment|/* I/O port address assignment.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_ADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|FE_FMV2_ADDR_SHIFT
value|0
end_define

begin_comment
comment|/* Boot ROM address assignment.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_ROM
value|0x38
end_define

begin_define
define|#
directive|define
name|FE_FMV2_ROM_SHIFT
value|3
end_define

begin_comment
comment|/* IRQ assignment.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV2_IRQ
value|0xC0
end_define

begin_define
define|#
directive|define
name|FE_FMV2_IRQ_SHIFT
value|6
end_define

begin_comment
comment|/* Hardware(?) enable flag.  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV3_ENABLE_FLAG
value|0x80
end_define

begin_comment
comment|/* Extra bits in FMV3 register.  Always 0?  */
end_comment

begin_define
define|#
directive|define
name|FE_FMV3_EXTRA_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|FE_FMV3_EXTRA_VALUE
value|0x00
end_define

begin_comment
comment|/*  * EEPROM allocation of AT1700/RE2000.  */
end_comment

begin_define
define|#
directive|define
name|FE_EEP_ATI_ADDR
value|8
end_define

begin_comment
comment|/* Station address.  (8-13)	*/
end_comment

begin_define
define|#
directive|define
name|FE_EEP_ATI_TYPE
value|25
end_define

begin_comment
comment|/* Hardware type?  FIXME.	*/
end_comment

begin_define
define|#
directive|define
name|FE_EEP_ATI_TYPE_HIGHIRQ
value|0x04
end_define

begin_comment
comment|/* IRQ delivery? FIXME.	*/
end_comment

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

end_unit

