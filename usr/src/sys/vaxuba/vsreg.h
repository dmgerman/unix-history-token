begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)vsreg.h	7.1 (MIT) 6/5/86 */
end_comment

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1983, 1984 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished on an as-is basis and may be used and copied *  *  only with inclusion of the above copyright notice. This software or any *  *  other copies thereof may be provided or otherwise made available to     *  *  others only for non-commercial purposes.  No title to or ownership of   *  *  the software is hereby transferred.					    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
end_comment

begin_comment
comment|/*   * vsreg.h - VS100 Registers and Bits  *   * Author:	Christopher A. Kent  *		Digital Equipment Corporation  *		Western Research Lab  * Date:	Tue Jun 14 1983  */
end_comment

begin_struct
struct|struct
name|vsdevice
block|{
name|u_short
name|vs_csr0
decl_stmt|;
comment|/* Control and Status */
name|u_short
name|vs_csr1
decl_stmt|;
comment|/* Interrupt Reason */
name|u_short
name|vs_csr2
decl_stmt|;
comment|/* Keyboard Receive */
name|u_short
name|vs_csr3
decl_stmt|;
comment|/* Function Parameter Low */
name|u_short
name|vs_csr4
decl_stmt|;
comment|/* Function Parameter High */
name|u_short
name|vs_csr5
decl_stmt|;
comment|/* Cursor Position X */
name|u_short
name|vs_csr6
decl_stmt|;
comment|/* Cursor Position Y */
name|u_short
name|vs_csr7
decl_stmt|;
comment|/* Interrupt Vector */
name|u_short
name|vs_csr8
decl_stmt|;
comment|/* Spare 1 */
name|u_short
name|vs_csr9
decl_stmt|;
comment|/* Spare 2 */
name|u_short
name|vs_csra
decl_stmt|;
comment|/* Spare 3 */
name|u_short
name|vs_csrb
decl_stmt|;
comment|/* Spare 4 */
name|u_short
name|vs_csrc
decl_stmt|;
comment|/* Spare 5 */
name|u_short
name|vs_csrd
decl_stmt|;
comment|/* Spare 6 */
name|u_short
name|vs_csre
decl_stmt|;
comment|/* Spare 7 */
name|u_short
name|vs_csrf
decl_stmt|;
comment|/* Interrupt Vector (2Bs) */
block|}
struct|;
end_struct

begin_comment
comment|/*   * CSR0 - Control and Status  */
end_comment

begin_define
define|#
directive|define
name|VS_LNK_TRNS
value|0100000
end_define

begin_comment
comment|/* Link Transition */
end_comment

begin_define
define|#
directive|define
name|VS_LNK_AVL
value|0040000
end_define

begin_comment
comment|/* Link Available */
end_comment

begin_define
define|#
directive|define
name|VS_LNK_ERR
value|0020000
end_define

begin_comment
comment|/* Link Error */
end_comment

begin_define
define|#
directive|define
name|VS_XMIT_ON
value|0010000
end_define

begin_comment
comment|/* Transmitter On */
end_comment

begin_define
define|#
directive|define
name|VS_MNT_MODE
value|0004000
end_define

begin_comment
comment|/* Maintenance Mode */
end_comment

begin_define
define|#
directive|define
name|VS_CRC_DIS
value|0002000
end_define

begin_comment
comment|/* CRC Disable */
end_comment

begin_define
define|#
directive|define
name|VS_MNT_DONE
value|0001000
end_define

begin_comment
comment|/* Maintenance Done */
end_comment

begin_define
define|#
directive|define
name|VS_SPARE
value|0000400
end_define

begin_comment
comment|/* Spare */
end_comment

begin_define
define|#
directive|define
name|VS_OWN
value|0000200
end_define

begin_comment
comment|/* Owner */
end_comment

begin_define
define|#
directive|define
name|VS_IE
value|0000100
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|VS_FCN
value|0000076
end_define

begin_comment
comment|/* Function Code */
end_comment

begin_define
define|#
directive|define
name|VS_GO
value|0000001
end_define

begin_comment
comment|/* GO! */
end_comment

begin_struct
struct|struct
name|vs_csr
block|{
union|union
block|{
name|u_short
name|_register
decl_stmt|;
struct|struct
block|{
name|unsigned
name|_go
range|:
literal|1
decl_stmt|;
name|unsigned
name|_function
range|:
literal|5
decl_stmt|;
name|unsigned
name|_ie
range|:
literal|1
decl_stmt|;
name|unsigned
name|_own
range|:
literal|1
decl_stmt|;
name|unsigned
name|_spare
range|:
literal|1
decl_stmt|;
name|unsigned
name|_mainDone
range|:
literal|1
decl_stmt|;
name|unsigned
name|_CRCdisable
range|:
literal|1
decl_stmt|;
name|unsigned
name|_mainMode
range|:
literal|1
decl_stmt|;
name|unsigned
name|_xmitOn
range|:
literal|1
decl_stmt|;
name|unsigned
name|_linkErr
range|:
literal|1
decl_stmt|;
name|unsigned
name|_linkAvail
range|:
literal|1
decl_stmt|;
name|unsigned
name|_linkTran
range|:
literal|1
decl_stmt|;
block|}
name|_bits
struct|;
block|}
name|_X
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|csr_reg
value|_X._register
end_define

begin_define
define|#
directive|define
name|csr_go
value|_X._bits._go
end_define

begin_define
define|#
directive|define
name|csr_ie
value|_X._bits._ie
end_define

begin_define
define|#
directive|define
name|csr_own
value|_X._bits._own
end_define

begin_define
define|#
directive|define
name|csr_mainDone
value|_X._bits._mainDone
end_define

begin_define
define|#
directive|define
name|csr_CRCdisable
value|_X._bits._CRCdisable
end_define

begin_define
define|#
directive|define
name|csr_mainMode
value|_X._bits._mainMode
end_define

begin_define
define|#
directive|define
name|csr_xmitOn
value|_X._bits._xmitOn
end_define

begin_define
define|#
directive|define
name|csr_linkErr
value|_X._bits._linkErr
end_define

begin_define
define|#
directive|define
name|csr_linkAvail
value|_X._bits._linkAvail
end_define

begin_define
define|#
directive|define
name|csr_linkTran
value|_X._bits._linkTran
end_define

begin_comment
comment|/* Function Codes */
end_comment

begin_define
define|#
directive|define
name|VS_INIT
value|01
end_define

begin_comment
comment|/* Initialize Display */
end_comment

begin_define
define|#
directive|define
name|VS_SEND
value|02
end_define

begin_comment
comment|/* Send Packet */
end_comment

begin_define
define|#
directive|define
name|VS_START
value|03
end_define

begin_comment
comment|/* Start Microcode */
end_comment

begin_define
define|#
directive|define
name|VS_ABORT
value|04
end_define

begin_comment
comment|/* Abort Command Chain */
end_comment

begin_define
define|#
directive|define
name|VS_PWRUP
value|05
end_define

begin_comment
comment|/* Power Up Reset */
end_comment

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|VS_ENABBA
value|020
end_define

begin_comment
comment|/* Enable BBA */
end_comment

begin_define
define|#
directive|define
name|VS_DISBBA
value|021
end_define

begin_comment
comment|/* Disable BBA */
end_comment

begin_define
define|#
directive|define
name|VS_INFINITE
value|022
end_define

begin_comment
comment|/* Inifinite Retries */
end_comment

begin_define
define|#
directive|define
name|VS_FINITE
value|023
end_define

begin_comment
comment|/* Finite Retries */
end_comment

begin_comment
comment|/* amount to shift to get function code into right place */
end_comment

begin_define
define|#
directive|define
name|VS_FCSHIFT
value|01
end_define

begin_comment
comment|/*   * CSR1 - Interrupt Reason  */
end_comment

begin_define
define|#
directive|define
name|vs_irr
value|vs_csr1
end_define

begin_define
define|#
directive|define
name|VS_ERROR
value|0100000
end_define

begin_comment
comment|/* Any error */
end_comment

begin_define
define|#
directive|define
name|VS_REASON
value|0077777
end_define

begin_comment
comment|/* Reason Mask */
end_comment

begin_define
define|#
directive|define
name|VSIRR_BITS
define|\
value|"\20\20ERROR\10PWRUP\6TABLET\5MOUSE\4BUTTON\3START\2DONE\1INIT"
end_define

begin_define
define|#
directive|define
name|VS_INT_US
value|0
end_define

begin_define
define|#
directive|define
name|VS_INT_ID
value|01
end_define

begin_define
define|#
directive|define
name|VS_INT_CD
value|02
end_define

begin_define
define|#
directive|define
name|VS_INT_SE
value|04
end_define

begin_define
define|#
directive|define
name|VS_INT_BE
value|010
end_define

begin_define
define|#
directive|define
name|VS_INT_MM
value|020
end_define

begin_define
define|#
directive|define
name|VS_INT_TM
value|040
end_define

begin_define
define|#
directive|define
name|VS_INT_PWR
value|0200
end_define

begin_struct
struct|struct
name|vs_intr
block|{
union|union
block|{
name|u_short
name|_register
decl_stmt|;
comment|/* whole register */
struct|struct
block|{
name|unsigned
name|_reason
range|:
literal|14
decl_stmt|;
comment|/* Reason bits */
name|unsigned
name|_diagnostic
range|:
literal|1
decl_stmt|;
comment|/* Diagnostic Error bit */
name|unsigned
name|_error
range|:
literal|1
decl_stmt|;
comment|/* Error bit */
block|}
name|_bits
struct|;
block|}
name|_X
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|intr_reg
value|_X._register
end_define

begin_define
define|#
directive|define
name|intr_reason
value|_X._bits._reason
end_define

begin_define
define|#
directive|define
name|intr_diagnostic
value|_X._bits._diagnostic
end_define

begin_comment
comment|/* not in rev 2b */
end_comment

begin_define
define|#
directive|define
name|intr_error
value|_X._bits._error
end_define

begin_comment
comment|/*   * CSR2 - Keyboard Receive  */
end_comment

begin_define
define|#
directive|define
name|vs_krr
value|vs_csr2
end_define

begin_define
define|#
directive|define
name|VS_KBDEV
value|0007000
end_define

begin_comment
comment|/* Device mask */
end_comment

begin_define
define|#
directive|define
name|VS_KBT
value|0000400
end_define

begin_comment
comment|/* Transition direction */
end_comment

begin_define
define|#
directive|define
name|VS_KBKEY
value|0000377
end_define

begin_comment
comment|/* Key mask */
end_comment

begin_struct
struct|struct
name|vs_kbd
block|{
union|union
block|{
name|u_short
name|_register
decl_stmt|;
comment|/* whole register */
struct|struct
block|{
name|unsigned
name|_key
range|:
literal|8
decl_stmt|;
comment|/* Key number */
name|unsigned
name|_transition
range|:
literal|1
decl_stmt|;
comment|/* Transition direction */
name|unsigned
name|_device
range|:
literal|3
decl_stmt|;
comment|/* Device */
name|unsigned
name|_x
range|:
literal|4
decl_stmt|;
comment|/* Unused */
block|}
name|_bits
struct|;
block|}
name|_X
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|kbd_reg
value|_X._register
end_define

begin_define
define|#
directive|define
name|kbd_key
value|_X._bits._key
end_define

begin_define
define|#
directive|define
name|kbd_transition
value|_X._bits._transition
end_define

begin_define
define|#
directive|define
name|kbd_device
value|_X._bits._device
end_define

begin_define
define|#
directive|define
name|VS_KBTUP
value|0
end_define

begin_comment
comment|/* up */
end_comment

begin_define
define|#
directive|define
name|VS_KBTDOWN
value|1
end_define

begin_comment
comment|/* down */
end_comment

begin_comment
comment|/*   * CSR3/4 Function Parameter Address  */
end_comment

begin_define
define|#
directive|define
name|vs_pr1
value|vs_csr3
end_define

begin_define
define|#
directive|define
name|vs_pr2
value|vs_csr4
end_define

begin_struct
struct|struct
name|vs_fparm
block|{
union|union
block|{
struct|struct
block|{
name|u_short
name|_plow
decl_stmt|;
comment|/* low 16 bits of address */
name|u_short
name|_phigh
decl_stmt|;
comment|/* high 16 bits of address */
block|}
name|_parts
struct|;
name|caddr_t
name|_pall
decl_stmt|;
block|}
name|_X
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fparm_low
value|_X._parts._plow
end_define

begin_define
define|#
directive|define
name|fparm_high
value|_X._parts._phigh
end_define

begin_define
define|#
directive|define
name|fparm_all
value|_X._pall
end_define

begin_comment
comment|/*   * CSR5/6 - Cursor position  */
end_comment

begin_define
define|#
directive|define
name|vs_cxr
value|vs_csr5
end_define

begin_define
define|#
directive|define
name|vs_cyr
value|vs_csr6
end_define

begin_comment
comment|/*   * CSR 7 - Interrupt vector in fiber cable machines  */
end_comment

begin_define
define|#
directive|define
name|vs_ivr
value|vs_csr7
end_define

begin_comment
comment|/*   * CSR 8 through 14 Spare  */
end_comment

begin_define
define|#
directive|define
name|vs_spr2
value|vs_csr8
end_define

begin_define
define|#
directive|define
name|vs_spr3
value|vs_csr9
end_define

begin_define
define|#
directive|define
name|vs_spr4
value|vs_csra
end_define

begin_define
define|#
directive|define
name|vs_spr5
value|vs_csrb
end_define

begin_define
define|#
directive|define
name|vs_spr6
value|vs_csrc
end_define

begin_define
define|#
directive|define
name|vs_spr7
value|vs_csrd
end_define

begin_define
define|#
directive|define
name|vs_spr8
value|vs_csre
end_define

begin_comment
comment|/*   * CSR 15 - Interrupt vector in rev 2B  */
end_comment

begin_define
define|#
directive|define
name|vs_ivr2
value|vs_csrf
end_define

end_unit

