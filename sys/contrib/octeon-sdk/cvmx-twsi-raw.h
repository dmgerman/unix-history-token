begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2007, Cavium Networks. All rights reserved.  *  * This software file (the "File") is owned and distributed by Cavium  * Networks ("Cavium") under the following dual licensing option: The dual  * licensing option gives you, the licensee, the choice between the following  * alternative licensing terms.  Once you have made an election to use the  * File under one of the following alternative licensing terms (license  * types) you are bound by the respective terms and you may distribute the  * file (or any derivative thereof), to the extent allowed by the respective  * licensing term, only if you (i) delete this introductory statement  * regarding the dual licensing option from the file you will distribute,  * (ii) delete the licensing term that you have elected NOT to use from the  * file you will distribute and (iii) follow the respective licensing term  * that you have elected to use with respect to the correct attribution or  * licensing term that you have to include with your distribution.  *  * ***  * OCTEON SDK License Type 2:  *  * IMPORTANT: Read this Agreement carefully before clicking on the "I accept"  * button to download the Software and/or before using the Software.  This  * License Agreement (the "Agreement") is a legal agreement between you,  * either an individual or a single legal entity ("You" or "you"), and Cavium  * Networks ("Cavium").  This Agreement governs your use of the Cavium  * software that can be downloaded after accepting this Agreement and/or that  * is accompanied by this Agreement (the "Software").  You must accept the  * terms of this Agreement before downloading and/or using the Software.  By  * clicking on the "I accept" button to download and/or by using the  * Software, you are indicating that you have read and understood, and assent  * to be bound by, the terms of this Agreement.  If you do not agree to the  * terms of the Agreement, you are not granted any rights whatsoever in the  * Software.  If you are not willing to be bound by these terms and  * conditions, you should not use or cease all use of the Software.  This  * Software is the property of Cavium Networks and constitutes the  * proprietary information of Cavium Networks.  You agree to take reasonable  * steps to prevent the disclosure, unauthorized use or unauthorized  * distribution of the Software to any third party.  *  * License Grant.  Subject to the terms and conditions of this Agreement,  * Cavium grants you a nonexclusive, non-transferable, worldwide, fully-paid  * and royalty-free license to  *  * (a) install, reproduce, and execute the executable version of the Software  * solely for your internal use and only (a) on hardware manufactured by  * Cavium, or (b) software of Cavium that simulates Cavium hardware; *  * (b) create derivative works of any portions of the Software provided to  * you by Cavium in source code form, which portions enable features of the  * Cavium hardware products you or your licensees are entitled to use,  * provided that any such derivative works must be used only (a) on hardware  * manufactured by Cavium, or (b) software of Cavium that simulates Cavium  * hardware; and  *  * (c) distribute derivative works you created in accordance with clause (b)  * above, only in executable form and only if such distribution (i)  * reproduces the copyright notice that can be found at the very end of this  * Agreement and (ii) is pursuant to a binding license agreement that  * contains terms no less restrictive and no less protective of Cavium than  * this Agreement.  You will immediately notify Cavium if you become aware of  * any breach of any such license agreement.  *  * Restrictions.  The rights granted to you in this Agreement are subject to  * the following restrictions: Except as expressly set forth in this  * Agreement (a) you will not license, sell, rent, lease, transfer, assign,  * display, host, outsource, disclose or otherwise commercially exploit or  * make the Software, or any derivatives you create under this Agreement,  * available to any third party; (b) you will not modify or create derivative  * works of any part of the Software; (c) you will not access or use the  * Software in order to create similar or competitive products, components,  * or services; and (d), no part of the Software may be copied (except for  * the making of a single archival copy), reproduced, distributed,  * republished, downloaded, displayed, posted or transmitted in any form or  * by any means.  *  * Ownership.  You acknowledge and agree that, subject to the license grant  * contained in this Agreement and as between you and Cavium (a) Cavium owns  * all copies of and intellectual property rights to the Software, however  * made, and retains all rights in and to the Software, including all  * intellectual property rights therein, and (b) you own all the derivate  * works of the Software created by you under this Agreement, subject to  * Cavium's rights in the Software.  There are no implied licenses under this  * Agreement, and any rights not expressly granted to your hereunder are  * reserved by Cavium.  You will not, at any time, contest anywhere in the  * world Cavium's ownership of the intellectual property rights in and to the  * Software.  *  * Disclaimer of Warranties.  The Software is provided to you free of charge,  * and on an "As-Is" basis.  Cavium provides no technical support, warranties  * or remedies for the Software.  Cavium and its suppliers disclaim all * express, implied or statutory warranties relating to the Software,  * including but not limited to, merchantability, fitness for a particular  * purpose, title, and non-infringement.  Cavium does not warrant that the  * Software and the use thereof will be error-free, that defects will be  * corrected, or that the Software is free of viruses or other harmful  * components.  If applicable law requires any warranties with respect to the  * Software, all such warranties are limited in duration to thirty (30) days  * from the date of download or first use, whichever comes first.  *  * Limitation of Liability.  Neither Cavium nor its suppliers shall be  * responsible or liable with respect to any subject matter of this Agreement  * or terms or conditions related thereto under any contract, negligence,  * strict liability or other theory (a) for loss or inaccuracy of data or  * cost of procurement of substitute goods, services or technology, or (b)  * for any indirect, incidental or consequential damages including, but not  * limited to loss of revenues and loss of profits.  Cavium's aggregate  * cumulative liability hereunder shall not exceed the greater of Fifty U.S.  * Dollars (U.S.$50.00) or the amount paid by you for the Software that  * caused the damage.  Certain states and/or jurisdictions do not allow the  * exclusion of implied warranties or limitation of liability for incidental  * or consequential damages, so the exclusions set forth above may not apply  * to you.  *  * Basis of Bargain.  The warranty disclaimer and limitation of liability set  * forth above are fundamental elements of the basis of the agreement between  * Cavium and you.  Cavium would not provide the Software without such  * limitations.  The warranty disclaimer and limitation of liability inure to  * the benefit of Cavium and Cavium's suppliers.  *  * Term and Termination.  This Agreement and the licenses granted hereunder  * are effective on the date you accept the terms of this Agreement, download  * the Software, or use the Software, whichever comes first, and shall  * continue unless this Agreement is terminated pursuant to this section.  * This Agreement immediately terminates in the event that you materially  * breach any of the terms hereof.  You may terminate this Agreement at any  * time, with or without cause, by destroying any copies of the Software in  * your possession.  Upon termination, the license granted hereunder shall  * terminate but the Sections titled "Restrictions", "Ownership", "Disclaimer  * of Warranties", "Limitation of Liability", "Basis of Bargain", "Term and  * Termination", "Export", and "Miscellaneous" will remain in effect.  *  * Export.  The Software and related technology are subject to U.S.  export  * control laws and may be subject to export or import regulations in other  * countries.  You agree to strictly comply with all such laws and  * regulations and acknowledges that you have the responsibility to obtain  * authorization to export, re-export, or import the Software and related  * technology, as may be required.  You will indemnify and hold Cavium  * harmless from any and all claims, losses, liabilities, damages, fines,  * penalties, costs and expenses (including attorney's fees) arising from or  * relating to any breach by you of your obligations under this section.  * Your obligations under this section shall survive the expiration or  * termination of this Agreement.  *  * Miscellaneous.  Neither the rights nor the obligations arising under this  * Agreement are assignable by you, and any such attempted assignment or  * transfer shall be void and without effect.  This Agreement shall be  * governed by and construed in accordance with the laws of the State of  * California without regard to any conflicts of laws provisions that would  * require application of the laws of another jurisdiction.  Any action under  * or relating to this Agreement shall be brought in the state and federal  * courts located in California, with venue in the courts located in Santa  * Clara County and each party hereby submits to the personal jurisdiction of  * such courts; provided, however, that nothing herein will operate to  * prohibit or restrict Cavium from filing for and obtaining injunctive  * relief from any court of competent jurisdiction.  The United Nations  * Convention on Contracts for the International Sale of Goods shall not  * apply to this Agreement.  In the event that any provision of this  * Agreement is found to be contrary to law, then such provision shall be  * construed as nearly as possible to reflect the intention of the parties,  * with the other provisions remaining in full force and effect.  Any notice  * to you may be provided by email.  This Agreement constitutes the entire  * agreement between the parties and supersedes all prior or contemporaneous,  * agreements, understandings and communications between the parties, whether  * written or oral, pertaining to the subject matter hereof.  Any  * modifications of this Agreement must be in writing and agreed to by both  * parties.  *  * Copyright (c) 2003-2007, Cavium Networks. All rights reserved.  *  * ***  *  * OCTEON SDK License Type 4:  *  * Author: Cavium Networks  *  * Contact: support@caviumnetworks.com  * This file is part of the OCTEON SDK  *  * Copyright (c) 2007 Cavium Networks  *  * This file is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License, Version 2, as published by  * the Free Software Foundation.  *  * This file is distributed in the hope that it will be useful,  * but AS-IS and WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, TITLE, or NONINFRINGEMENT.  * See the GNU General Public License for more details.  * it under the terms of the GNU General Public License, Version 2, as published by  * the Free Software Foundation.  *  * You should have received a copy of the GNU General Public License  * along with this file; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA  * or visit http://www.gnu.org/licenses/.  *  * This file may also be available under a different license from Cavium.  * Contact Cavium Networks for more information  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_TWSI_RAW_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_TWSI_RAW_H__
end_define

begin_comment
comment|/* Addresses for twsi 8-bit registers. Gets written to EOP_IA field of MIO_TWS_SW_TWSI reg *  when OP = 6 and SLONLY =0 */
end_comment

begin_define
define|#
directive|define
name|TWSI_SLAVE_ADD_REG
value|0
end_define

begin_define
define|#
directive|define
name|TWSI_DATA_REG
value|1
end_define

begin_define
define|#
directive|define
name|TWSI_CTL_REG
value|2
end_define

begin_define
define|#
directive|define
name|TWSI_STAT_REG
value|3
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|TWSI_CLKCTL_REG
value|3
end_define

begin_comment
comment|/* write only */
end_comment

begin_define
define|#
directive|define
name|TWSI_SLAVE_EXTADD_REG
value|4
end_define

begin_define
define|#
directive|define
name|TWSI_RST_REG
value|7
end_define

begin_comment
comment|/* twsi core slave address reg */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|slave_addr7
range|:
literal|7
decl_stmt|;
name|uint8_t
name|gce
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
block|}
name|octeon_twsi_slave_add_t
typedef|;
end_typedef

begin_comment
comment|/* twsi core 10-bit slave address reg */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|slave_addr8
range|:
literal|8
decl_stmt|;
block|}
name|s
struct|;
block|}
name|octeon_twsi_slave_extadd_t
typedef|;
end_typedef

begin_comment
comment|/* twsi core control register */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|ce
range|:
literal|1
decl_stmt|;
comment|/* enable HLC*/
name|uint8_t
name|enab
range|:
literal|1
decl_stmt|;
comment|/* bus enable */
name|uint8_t
name|sta
range|:
literal|1
decl_stmt|;
comment|/* start request */
name|uint8_t
name|stp
range|:
literal|1
decl_stmt|;
comment|/* stop request */
name|uint8_t
name|iflg
range|:
literal|1
decl_stmt|;
comment|/* interrupt flag - request completed (1) start new (0) */
name|uint8_t
name|aak
range|:
literal|1
decl_stmt|;
comment|/* assert ack (1) -neg ack at end of Rx sequence */
name|uint8_t
name|rsv
range|:
literal|2
decl_stmt|;
comment|/* not used */
block|}
name|s
struct|;
block|}
name|octeon_twsi_ctl_t
typedef|;
end_typedef

begin_comment
comment|/* clock dividers register */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|m_divider
range|:
literal|4
decl_stmt|;
name|uint8_t
name|n_divider
range|:
literal|3
decl_stmt|;
block|}
name|s
struct|;
block|}
name|octeon_twsi_clkctl_t
typedef|;
end_typedef

begin_comment
comment|/* address of the remote slave + r/w bit */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|slave_addr7
range|:
literal|7
decl_stmt|;
name|uint8_t
name|r
range|:
literal|1
decl_stmt|;
comment|/* read (1) write (0) bit */
block|}
name|s
struct|;
block|}
name|octeon_twsi_addr_t
typedef|;
end_typedef

begin_comment
comment|/* core state reg */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|stat
range|:
literal|8
decl_stmt|;
block|}
name|s
struct|;
block|}
name|octeon_twsi_stat_t
typedef|;
end_typedef

begin_comment
comment|/* data byte reg */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|data
range|:
literal|8
decl_stmt|;
block|}
name|s
struct|;
block|}
name|octeon_twsi_data_t
typedef|;
end_typedef

begin_comment
comment|/* twsi core states as reported in twsi core stat register */
end_comment

begin_define
define|#
directive|define
name|TWSI_BUS_ERROR
value|0x00
end_define

begin_define
define|#
directive|define
name|TWSI_START_TXED
value|0x08
end_define

begin_define
define|#
directive|define
name|TWSI_ADDR_W_TX_ACK_RXED
value|0x18
end_define

begin_define
define|#
directive|define
name|TWSI_ADDR_W_TX_NACK_RXED
value|0x20
end_define

begin_define
define|#
directive|define
name|TWSI_DATA_TX_ACK_RXED
value|0x28
end_define

begin_define
define|#
directive|define
name|TWSI_DATA_TX_NACK_RXED
value|0x30
end_define

begin_define
define|#
directive|define
name|TWSI_ARB_LOST
value|0x38
end_define

begin_define
define|#
directive|define
name|TWSI_ADDR_R_TX_ACK_RXED
value|0x40
end_define

begin_define
define|#
directive|define
name|TWSI_ADDR_R_TX_NACK_RXED
value|0x48
end_define

begin_define
define|#
directive|define
name|TWSI_DATA_RX_ACK_TXED
value|0x50
end_define

begin_define
define|#
directive|define
name|TWSI_DATA_RX_NACK_TXED
value|0x58
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_ADDR_RX_ACK_TXED
value|0x60
end_define

begin_define
define|#
directive|define
name|TWSI_ARB_LOST_SLAVE_ADDR_RX
value|0x68
end_define

begin_define
define|#
directive|define
name|TWSI_GEN_ADDR_RXED_ACK_TXED
value|0x70
end_define

begin_define
define|#
directive|define
name|TWSI_ARB_LOST_GEN_ADDR_RXED
value|0x78
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_DATA_RX_ACK_TXED
value|0x80
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_DATA_RX_NACK_TXED
value|0x88
end_define

begin_define
define|#
directive|define
name|TWSI_GEN_DATA_RX_ACK_TXED
value|0x90
end_define

begin_define
define|#
directive|define
name|TWSI_GEN_DATA_RX_NACK_TXED
value|0x98
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_STOP_OR_START_RXED
value|0xa0
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_ADDR_R_RX_ACK_TXED
value|0xa8
end_define

begin_define
define|#
directive|define
name|TWSI_ARB_LOST_SLAVE_ADDR_R_RX_ACK_TXED
value|0xb0
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_DATA_TX_ACK_RXED
value|0xb8
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_DATA_TX_NACK_RXED
value|0xc0
end_define

begin_define
define|#
directive|define
name|TWSI_SLAVE_LAST_DATA_TX_ACK_RXED
value|0xc8
end_define

begin_define
define|#
directive|define
name|TWSI_SECOND_ADDR_W_TX_ACK_RXED
value|0xd0
end_define

begin_define
define|#
directive|define
name|TWSI_SECOND_ADDR_W_TX_NACK_RXED
value|0xd8
end_define

begin_define
define|#
directive|define
name|TWSI_IDLE
value|0xf8
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX
end_ifndef

begin_comment
comment|/* msg definition similar to Linux */
end_comment

begin_struct
struct|struct
name|i2c_msg
block|{
name|uint16_t
name|addr
decl_stmt|;
comment|/* slave address                        */
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
comment|/* msg length                           */
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to msg data                  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I2C_M_TEN
value|0x10
end_define

begin_comment
comment|/* we have a ten bit chip address       */
end_comment

begin_define
define|#
directive|define
name|I2C_M_RD
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|octeon_i2c_xfer_msg_raw
parameter_list|(
name|int
name|twsi_id
parameter_list|,
name|struct
name|i2c_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

