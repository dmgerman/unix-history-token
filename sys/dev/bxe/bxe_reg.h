begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* bxe_reg.h: Broadcom Everest network driver.  * The registers description starts with the register Access type followed  * by size in bits. For example [RW 32]. The access types are:  * R  - Read only  * RC - Clear on read  * RW - Read/Write  * ST - Statistics register (clear on read)  * W  - Write only  * WB - Wide bus register - the size is over 32 bits and it should be  *      read/write in consecutive 32 bits accesses  * WR - Write Clear (write 1 to clear the bit)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BXE_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_BXE_REG_H
end_define

begin_comment
comment|/* [R 19] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_INT_STS
value|0x6011c
end_define

begin_comment
comment|/* [RW 4] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_PRTY_MASK
value|0x60138
end_define

begin_comment
comment|/* [R 4] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_PRTY_STS
value|0x6012c
end_define

begin_comment
comment|/*  * [RW 10] At address BRB1_IND_FREE_LIST_PRS_CRDT initialize free head. At  * address BRB1_IND_FREE_LIST_PRS_CRDT+1 initialize free tail. At address  * BRB1_IND_FREE_LIST_PRS_CRDT+2 initialize parser initial credit.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_FREE_LIST_PRS_CRDT
value|0x60200
end_define

begin_comment
comment|/*  * [RW 10] The number of free blocks above which the High_llfc signal to  *  interface #n is de-asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_HIGH_LLFC_HIGH_THRESHOLD_0
value|0x6014c
end_define

begin_comment
comment|/*  * [RW 10] The number of free blocks below which the High_llfc signal to  * interface #n is asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_HIGH_LLFC_LOW_THRESHOLD_0
value|0x6013c
end_define

begin_comment
comment|/* [RW 23] LL RAM data. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_LL_RAM
value|0x61000
end_define

begin_comment
comment|/*  * [RW 10] The number of free blocks above which the Low_llfc signal to  * interface #n is de-asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_LOW_LLFC_HIGH_THRESHOLD_0
value|0x6016c
end_define

begin_comment
comment|/*  * [RW 10] The number of free blocks below which the Low_llfc signal to  * interface #n is asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_LOW_LLFC_LOW_THRESHOLD_0
value|0x6015c
end_define

begin_comment
comment|/* [R 24] The number of full blocks. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_FULL_BLOCKS
value|0x60090
end_define

begin_comment
comment|/*  * [ST 32] The number of cycles that the write_full signal towards MAC #0  * was asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_FULL_CYCLES_0
value|0x600c8
end_define

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_FULL_CYCLES_1
value|0x600cc
end_define

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_FULL_CYCLES_4
value|0x600d8
end_define

begin_comment
comment|/*  * [ST 32] The number of cycles that the pause signal towards MAC #0 was  * asserted.  */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_PAUSE_CYCLES_0
value|0x600b8
end_define

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_PAUSE_CYCLES_1
value|0x600bc
end_define

begin_comment
comment|/* [RW 10] Write client 0: De-assert pause threshold. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_HIGH_THRESHOLD_0
value|0x60078
end_define

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_HIGH_THRESHOLD_1
value|0x6007c
end_define

begin_comment
comment|/* [RW 10] Write client 0: Assert pause threshold. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_LOW_THRESHOLD_0
value|0x60068
end_define

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_LOW_THRESHOLD_1
value|0x6006c
end_define

begin_comment
comment|/* [R 24] The number of full blocks occupied by port. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_PORT_NUM_OCC_BLOCKS_0
value|0x60094
end_define

begin_comment
comment|/* [RW 1] Reset the design by software. */
end_comment

begin_define
define|#
directive|define
name|BRB1_REG_SOFT_RESET
value|0x600dc
end_define

begin_comment
comment|/* [R 5] Used to read the value of the XX protection CAM occupancy counter. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CAM_OCCUP
value|0xd0188
end_define

begin_comment
comment|/*  * [RW 1] CM - CFC Interface enable. If 0 - the valid input is disregarded;  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_CFC_IFEN
value|0xd003c
end_define

begin_comment
comment|/*  * [RW 1] CM - QM Interface enable. If 0 - the acknowledge input is  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_CQM_IFEN
value|0xd000c
end_define

begin_comment
comment|/*  * [RW 1] If set the Q index; received from the QM is inserted to event ID.  * Otherwise 0 is inserted.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_CQM_USE_Q
value|0xd00c0
end_define

begin_comment
comment|/* [RW 11] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_INT_MASK
value|0xd01e4
end_define

begin_comment
comment|/* [R 11] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_INT_STS
value|0xd01d8
end_define

begin_comment
comment|/* [R 27] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_PRTY_STS
value|0xd01e8
end_define

begin_comment
comment|/*  * [RW 3] The size of AG context region 0 in REG-pairs. Designates the MS  * REG-pair number (e.g. if region 0 is 6 REG-pairs; the value should be 5).  * Is used to determine the number of the AG context REG-pairs written back;  * when the input message Reg1WbFlg isn't set.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_REG0_SZ
value|0xd00c4
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 0 Interface enable. If 0 - the acknowledge input is  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_STORM0_IFEN
value|0xd0004
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 1 Interface enable. If 0 - the acknowledge input is  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CCM_STORM1_IFEN
value|0xd0008
end_define

begin_comment
comment|/*  * [RW 1] CDU AG read Interface enable. If 0 - the request input is  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CDU_AG_RD_IFEN
value|0xd0030
end_define

begin_comment
comment|/*  * [RW 1] CDU AG write Interface enable. If 0 - the request and valid input  * are disregarded; all other signals are treated as usual; if 1 - normal  * activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CDU_AG_WR_IFEN
value|0xd002c
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM read Interface enable. If 0 - the request input is  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CDU_SM_RD_IFEN
value|0xd0038
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM write Interface enable. If 0 - the request and valid  * input is disregarded; all other signals are treated as usual; if 1 -  * normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CDU_SM_WR_IFEN
value|0xd0034
end_define

begin_comment
comment|/*  * [RW 4] CFC output initial credit. Max credit available - 15.Write writes  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 1 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CFC_INIT_CRD
value|0xd0204
end_define

begin_comment
comment|/* [RW 2] Auxillary counter flag Q number 1. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CNT_AUX1_Q
value|0xd00c8
end_define

begin_comment
comment|/* [RW 2] Auxillary counter flag Q number 2. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CNT_AUX2_Q
value|0xd00cc
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (primary). */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_CCM_HDR_P
value|0xd008c
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (secondary). */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_CCM_HDR_S
value|0xd0090
end_define

begin_comment
comment|/*  * [RW 1] QM - CM Interface enable. If 0 - the valid input is disregarded;  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_CCM_IFEN
value|0xd0014
end_define

begin_comment
comment|/*  * [RW 6] QM output initial credit. Max credit available - 32. Write writes  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 32 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_INIT_CRD
value|0xd020c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (primary) input in the WRR mechanism. 0  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_P_WEIGHT
value|0xd00b8
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (secondary) input in the WRR mechanism. 0  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CQM_S_WEIGHT
value|0xd00bc
end_define

begin_comment
comment|/*  * [RW 1] Input SDM Interface enable. If 0 - the valid input is disregarded;  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CSDM_IFEN
value|0xd0018
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication)  * at the SDM interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CSDM_LENGTH_MIS
value|0xd0170
end_define

begin_comment
comment|/*  * [RW 3] The weight of the SDM input in the WRR mechanism. 0 stands for  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_CSDM_WEIGHT
value|0xd00b4
end_define

begin_comment
comment|/*  * [RW 28] The CM header for QM formatting in case of an error in the QM  * inputs.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_ERR_CCM_HDR
value|0xd0094
end_define

begin_comment
comment|/* [RW 8] The Event ID in case the input message ErrorFlg is set. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_ERR_EVNT_ID
value|0xd0098
end_define

begin_comment
comment|/*  * [RW 8] FIC0 output initial credit. Max credit available - 255. Write  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_FIC0_INIT_CRD
value|0xd0210
end_define

begin_comment
comment|/*  * [RW 8] FIC1 output initial credit. Max credit available - 255.Write  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_FIC1_INIT_CRD
value|0xd0214
end_define

begin_comment
comment|/*  * [RW 1] Arbitration between Input Arbiter groups: 0 - fair Round-Robin; 1  * - strict priority defined by ~ccm_registers_gr_ag_pr.gr_ag_pr;  * ~ccm_registers_gr_ld0_pr.gr_ld0_pr and  * ~ccm_registers_gr_ld1_pr.gr_ld1_pr. Groups are according to channels and  * outputs to STORM: aggregation; load FIC0; load FIC1 and store.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_GR_ARB_TYPE
value|0xd015c
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC0) channel group priority. The lowest priority is 0; the  * highest priority is 3. It is supposed; that the Store channel priority is  * the compliment to 4 of the rest priorities - Aggregation channel; Load  * (FIC0) channel and Load (FIC1).  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_GR_LD0_PR
value|0xd0164
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC1) channel group priority. The lowest priority is 0; the  * highest priority is 3. It is supposed; that the Store channel priority is  * the compliment to 4 of the rest priorities - Aggregation channel; Load  * (FIC0) channel and Load (FIC1).  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_GR_LD1_PR
value|0xd0168
end_define

begin_comment
comment|/* [RW 2] General flags index. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_INV_DONE_Q
value|0xd0108
end_define

begin_comment
comment|/*  * [RW 4] The number of double REG-pairs(128 bits); loaded from the STORM  * context and sent to STORM; for a specific connection type. The double  * REG-pairs are used in order to align to STORM context row size of 128  * bits. The offset of these data in the STORM context is always 0. Index  * _(0..15) stands for the connection type (one of 16).  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_N_SM_CTX_LD_0
value|0xd004c
end_define

begin_define
define|#
directive|define
name|CCM_REG_N_SM_CTX_LD_1
value|0xd0050
end_define

begin_define
define|#
directive|define
name|CCM_REG_N_SM_CTX_LD_2
value|0xd0054
end_define

begin_define
define|#
directive|define
name|CCM_REG_N_SM_CTX_LD_3
value|0xd0058
end_define

begin_define
define|#
directive|define
name|CCM_REG_N_SM_CTX_LD_4
value|0xd005c
end_define

begin_comment
comment|/*  * [RW 1] Input pbf Interface enable. If 0 - the valid input is disregarded;  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_PBF_IFEN
value|0xd0028
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication)  * at the pbf interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_PBF_LENGTH_MIS
value|0xd0180
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input pbf in the WRR mechanism. 0 stands for  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_PBF_WEIGHT
value|0xd00ac
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM1_0
value|0xd0134
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM1_1
value|0xd0138
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM2_0
value|0xd013c
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM2_1
value|0xd0140
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM3_0
value|0xd0144
end_define

begin_define
define|#
directive|define
name|CCM_REG_PHYS_QNUM3_1
value|0xd0148
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM0_0
value|0xd0114
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM0_1
value|0xd0118
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM1_0
value|0xd011c
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM1_1
value|0xd0120
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM2_0
value|0xd0124
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM2_1
value|0xd0128
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM3_0
value|0xd012c
end_define

begin_define
define|#
directive|define
name|CCM_REG_QOS_PHYS_QNUM3_1
value|0xd0130
end_define

begin_comment
comment|/*  * [RW 1] STORM - CM Interface enable. If 0 - the valid input is  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_STORM_CCM_IFEN
value|0xd0010
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication)  * at the STORM interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_STORM_LENGTH_MIS
value|0xd016c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the STORM input in the WRR (Weighted Round robin)  * mechanism. 0 stands for weight 8 (the most prioritised); 1 stands for  * weight 1(least prioritised); 2 stands for weight 2 (more prioritised);  * tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_STORM_WEIGHT
value|0xd009c
end_define

begin_comment
comment|/*  * [RW 1] Input tsem Interface enable. If 0 - the valid input is  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_TSEM_IFEN
value|0xd001c
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication)  * at the tsem interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_TSEM_LENGTH_MIS
value|0xd0174
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input tsem in the WRR mechanism. 0 stands for  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_TSEM_WEIGHT
value|0xd00a0
end_define

begin_comment
comment|/*  * [RW 1] Input usem Interface enable. If 0 - the valid input is  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_USEM_IFEN
value|0xd0024
end_define

begin_comment
comment|/*  * [RC 1] Set when message length mismatch (relative to last indication) at  * the usem interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_USEM_LENGTH_MIS
value|0xd017c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input usem in the WRR mechanism. 0 stands for  * weight 8 (the most prioritised); 1 stands for weight 1(least prioritised);  * 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_USEM_WEIGHT
value|0xd00a8
end_define

begin_comment
comment|/*  * [RW 1] Input xsem Interface enable. If 0 - the valid input is  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XSEM_IFEN
value|0xd0020
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication)  * at the xsem interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XSEM_LENGTH_MIS
value|0xd0178
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input xsem in the WRR mechanism. 0 stands for  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XSEM_WEIGHT
value|0xd00a4
end_define

begin_comment
comment|/*  * [RW 19] Indirect access to the descriptor table of the XX protection  * mechanism. The fields are: [5:0] - message length; [12:6] - message  * pointer; 18:13] - next pointer.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_DESCR_TABLE
value|0xd0300
end_define

begin_define
define|#
directive|define
name|CCM_REG_XX_DESCR_TABLE_SIZE
value|36
end_define

begin_comment
comment|/* [R 7] Used to read the value of XX protection Free counter. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_FREE
value|0xd0184
end_define

begin_comment
comment|/*  * [RW 6] Initial value for the credit counter; responsible for fulfilling  * of the Input Stage XX protection buffer by the XX protection pending  * messages. Max credit available - 127. Write writes the initial credit  * value; read returns the current value of the credit counter. Must be  * initialized to maximum XX protected message size - 2 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_INIT_CRD
value|0xd0220
end_define

begin_comment
comment|/*  * [RW 7] The maximum number of pending messages; which may be stored in XX  * protection. At read the ~ccm_registers_xx_free.xx_free counter is read.  * At write comprises the start value of the ~ccm_registers_xx_free.xx_free  * counter.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_MSG_NUM
value|0xd0224
end_define

begin_comment
comment|/* [RW 8] The Event ID; sent to the STORM in case of XX overflow. */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_OVFL_EVNT_ID
value|0xd0044
end_define

begin_comment
comment|/*  * [RW 18] Indirect access to the XX table of the XX protection mechanism.  * The fields are: [5:0] - tail pointer; 11:6] - Link List size; 17:12] -  * header pointer.  */
end_comment

begin_define
define|#
directive|define
name|CCM_REG_XX_TABLE
value|0xd0280
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_CHK_MASK0
value|0x101000
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_CHK_MASK1
value|0x101004
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_CONTROL0
value|0x101008
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_DEBUG
value|0x101010
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_GLOBAL_PARAMS
value|0x101020
end_define

begin_comment
comment|/* [RW 7] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_CDU_INT_MASK
value|0x10103c
end_define

begin_comment
comment|/* [R 7] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_CDU_INT_STS
value|0x101030
end_define

begin_comment
comment|/* [RW 5] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_CDU_PRTY_MASK
value|0x10104c
end_define

begin_comment
comment|/* [R 5] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_CDU_PRTY_STS
value|0x101040
end_define

begin_comment
comment|/*  * [RC 32] logging of error data in case of a CDU load error:  * {expected_cid[15:0]; xpected_type[2:0]; xpected_region[2:0]; ctive_error;  * ype_error; ctual_active; ctual_compressed_context};  */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_ERROR_DATA
value|0x101014
end_define

begin_comment
comment|/*  * [WB 216] L1TT ram access. each entry has the following format :  * {mrege_regions[7:0]; ffset12[5:0]...offset0[5:0];  * ength12[5:0]...length0[5:0]; d12[3:0]...id0[3:0]}  */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_L1TT
value|0x101800
end_define

begin_comment
comment|/*  * [WB 24] MATT ram access. each entry has the following  * format:{RegionLength[11:0]; egionOffset[11:0]}  */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_MATT
value|0x101100
end_define

begin_comment
comment|/* [RW 1] when this bit is set the CDU operates in e1hmf mode */
end_comment

begin_define
define|#
directive|define
name|CDU_REG_MF_MODE
value|0x101050
end_define

begin_comment
comment|/*  * [R 1] indication the initializing the activity counter by the hardware  * was done.  */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_AC_INIT_DONE
value|0x104078
end_define

begin_comment
comment|/* [RW 13] activity counter ram access */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_ACTIVITY_COUNTER
value|0x104400
end_define

begin_define
define|#
directive|define
name|CFC_REG_ACTIVITY_COUNTER_SIZE
value|256
end_define

begin_comment
comment|/* [R 1] indication the initializing the cams by the hardware was done. */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CAM_INIT_DONE
value|0x10407c
end_define

begin_comment
comment|/* [RW 2] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CFC_INT_MASK
value|0x104108
end_define

begin_comment
comment|/* [R 2] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CFC_INT_STS
value|0x1040fc
end_define

begin_comment
comment|/* [RC 2] Interrupt register #0 read clear */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CFC_INT_STS_CLR
value|0x104100
end_define

begin_comment
comment|/* [RW 4] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CFC_PRTY_MASK
value|0x104118
end_define

begin_comment
comment|/* [R 4] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CFC_PRTY_STS
value|0x10410c
end_define

begin_comment
comment|/* [RW 21] CID cam access (21:1 - Data; alid - 0) */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_CID_CAM
value|0x104800
end_define

begin_define
define|#
directive|define
name|CFC_REG_CONTROL0
value|0x104028
end_define

begin_define
define|#
directive|define
name|CFC_REG_DEBUG0
value|0x104050
end_define

begin_comment
comment|/*  * [RW 14] indicates per error (in #cfc_registers_cfc_error_vector.cfc_error  * vector) whether the cfc should be disabled upon it.  */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_DISABLE_ON_ERROR
value|0x104044
end_define

begin_comment
comment|/*  * [RC 14] CFC error vector. when the CFC detects an internal error it will  * set one of these bits. the bit description can be found in CFC  * specifications.  */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_ERROR_VECTOR
value|0x10403c
end_define

begin_comment
comment|/* [WB 93] LCID info ram access */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_INFO_RAM
value|0x105000
end_define

begin_define
define|#
directive|define
name|CFC_REG_INFO_RAM_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CFC_REG_INIT_REG
value|0x10404c
end_define

begin_define
define|#
directive|define
name|CFC_REG_INTERFACES
value|0x104058
end_define

begin_comment
comment|/*  * [RW 24] {weight_load_client7[2:0] to weight_load_client0[2:0]}. this  * field allows changing the priorities of the weighted-round-robin arbiter  * which selects which CFC load client should be served next.  */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_LCREQ_WEIGHTS
value|0x104084
end_define

begin_comment
comment|/* [RW 16] Link List ram access; data = {prev_lcid; ext_lcid} */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_LINK_LIST
value|0x104c00
end_define

begin_define
define|#
directive|define
name|CFC_REG_LINK_LIST_SIZE
value|256
end_define

begin_comment
comment|/* [R 1] indication the initializing the link list by the hardware was done. */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_LL_INIT_DONE
value|0x104074
end_define

begin_comment
comment|/* [R 9] Number of allocated LCIDs which are at empty state */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_NUM_LCIDS_ALLOC
value|0x104020
end_define

begin_comment
comment|/* [R 9] Number of Arriving LCIDs in Link List Block */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_NUM_LCIDS_ARRIVING
value|0x104004
end_define

begin_comment
comment|/* [R 9] Number of Leaving LCIDs in Link List Block */
end_comment

begin_define
define|#
directive|define
name|CFC_REG_NUM_LCIDS_LEAVING
value|0x104018
end_define

begin_comment
comment|/* [RW 8] The event id for aggregated interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_0
value|0xc2038
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_10
value|0xc2060
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_11
value|0xc2064
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_12
value|0xc2068
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_13
value|0xc206c
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_14
value|0xc2070
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_15
value|0xc2074
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_16
value|0xc2078
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_2
value|0xc2040
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_3
value|0xc2044
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_4
value|0xc2048
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_5
value|0xc204c
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_6
value|0xc2050
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_7
value|0xc2054
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_8
value|0xc2058
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_EVENT_9
value|0xc205c
end_define

begin_comment
comment|/*  * [RW 1] For each aggregated interrupt index whether the mode is normal (0)  * or auto-mask-mode (1).  */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_10
value|0xc21e0
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_11
value|0xc21e4
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_12
value|0xc21e8
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_13
value|0xc21ec
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_14
value|0xc21f0
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_15
value|0xc21f4
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_16
value|0xc21f8
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_6
value|0xc21d0
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_7
value|0xc21d4
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_8
value|0xc21d8
end_define

begin_define
define|#
directive|define
name|CSDM_REG_AGG_INT_MODE_9
value|0xc21dc
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the cfc_rsp lcid */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CFC_RSP_START_ADDR
value|0xc2008
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #0 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CMP_COUNTER_MAX0
value|0xc201c
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #1 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CMP_COUNTER_MAX1
value|0xc2020
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #2 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CMP_COUNTER_MAX2
value|0xc2024
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #3 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CMP_COUNTER_MAX3
value|0xc2028
end_define

begin_comment
comment|/*  * [RW 13] The start address in the internal RAM for the completion  * counters.  */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CMP_COUNTER_START_ADDR
value|0xc200c
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_MASK_0
value|0xc229c
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_MASK_1
value|0xc22ac
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_STS_0
value|0xc2290
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_STS_1
value|0xc22a0
end_define

begin_comment
comment|/* [RW 11] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_PRTY_MASK
value|0xc22bc
end_define

begin_comment
comment|/* [R 11] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_PRTY_STS
value|0xc22b0
end_define

begin_define
define|#
directive|define
name|CSDM_REG_ENABLE_IN1
value|0xc2238
end_define

begin_define
define|#
directive|define
name|CSDM_REG_ENABLE_IN2
value|0xc223c
end_define

begin_define
define|#
directive|define
name|CSDM_REG_ENABLE_OUT1
value|0xc2240
end_define

begin_define
define|#
directive|define
name|CSDM_REG_ENABLE_OUT2
value|0xc2244
end_define

begin_comment
comment|/*  * [RW 4] The initial number of messages that can be sent to the pxp control  * interface without receiving any ACK.  */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_INIT_CREDIT_PXP_CTRL
value|0xc24bc
end_define

begin_comment
comment|/* [ST 32] The number of ACK after placement messages received */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_ACK_AFTER_PLACE
value|0xc227c
end_define

begin_comment
comment|/* [ST 32] The number of packet end messages received from the parser */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_PKT_END_MSG
value|0xc2274
end_define

begin_comment
comment|/* [ST 32] The number of requests received from the pxp async if */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_PXP_ASYNC_REQ
value|0xc2278
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 0 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q0_CMD
value|0xc2248
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 10 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q10_CMD
value|0xc226c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 11 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q11_CMD
value|0xc2270
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 1 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q1_CMD
value|0xc224c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 3 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q3_CMD
value|0xc2250
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 4 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q4_CMD
value|0xc2254
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 5 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q5_CMD
value|0xc2258
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 6 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q6_CMD
value|0xc225c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 7 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q7_CMD
value|0xc2260
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 8 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q8_CMD
value|0xc2264
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 9 */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_NUM_OF_Q9_CMD
value|0xc2268
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for queue counters */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_Q_COUNTER_START_ADDR
value|0xc2010
end_define

begin_comment
comment|/* [R 1] pxp_ctrl rd_data fifo empty in sdm_dma_rsp block */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_RSP_PXP_CTRL_RDATA_EMPTY
value|0xc2548
end_define

begin_comment
comment|/* [R 1] parser fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_SYNC_PARSER_EMPTY
value|0xc2550
end_define

begin_comment
comment|/* [R 1] parser serial fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_SYNC_SYNC_EMPTY
value|0xc2558
end_define

begin_comment
comment|/*  * [RW 32] Tick for timer counter. Applicable only when  * ~csdm_registers_timer_tick_enable.timer_tick_enable =1  */
end_comment

begin_define
define|#
directive|define
name|CSDM_REG_TIMER_TICK
value|0xc2000
end_define

begin_comment
comment|/* [RW 5] The number of time_slots in the arbitration cycle */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_CYCLE_SIZE
value|0x200034
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 0. Source  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_ELEMENT0
value|0x200020
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 1. Source  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~csem_registers_arb_element0.arb_element0.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_ELEMENT1
value|0x200024
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 2. Source  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~csem_registers_arb_element0.arb_element0  * and ~csem_registers_arb_element1.arb_element1.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_ELEMENT2
value|0x200028
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 3. Source  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.Could  * not be equal to register ~csem_registers_arb_element0.arb_element0 and  * ~csem_registers_arb_element1.arb_element1 and  * ~csem_registers_arb_element2.arb_element2.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_ELEMENT3
value|0x20002c
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 4. Source  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~csem_registers_arb_element0.arb_element0  * and ~csem_registers_arb_element1.arb_element1 and  * ~csem_registers_arb_element2.arb_element2 and  * ~csem_registers_arb_element3.arb_element3.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_ARB_ELEMENT4
value|0x200030
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_MASK_0
value|0x200110
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_MASK_1
value|0x200120
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_STS_0
value|0x200104
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_STS_1
value|0x200114
end_define

begin_comment
comment|/* [RW 32] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_MASK_0
value|0x200130
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_MASK_1
value|0x200140
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_STS_0
value|0x200124
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_STS_1
value|0x200134
end_define

begin_define
define|#
directive|define
name|CSEM_REG_ENABLE_IN
value|0x2000a4
end_define

begin_define
define|#
directive|define
name|CSEM_REG_ENABLE_OUT
value|0x2000a8
end_define

begin_comment
comment|/*  * [RW 32] This address space contains all registers and memories that are  * placed in SEM_FAST block. The SEM_FAST registers are described in  * appendix B. In order to access the sem_fast registers the base address  * ~fast_memory.fast_memory should be added to eachsem_fast register offset.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_FAST_MEMORY
value|0x220000
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC0 May be updated during run_time  * by the microcode.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_FIC0_DISABLE
value|0x200224
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC1 May be updated during run_time  * by the microcode.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_FIC1_DISABLE
value|0x200234
end_define

begin_comment
comment|/*  * [RW 15] Interrupt table Read and write access to it is not possible in  * the middle of the work  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_INT_TABLE
value|0x200400
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered through  FIC0  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FIC0
value|0x200000
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered through  * FIC1  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FIC1
value|0x200004
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent to  * FOC0  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FOC0
value|0x200008
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent to  * FOC1  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FOC1
value|0x20000c
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent to  * FOC2  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FOC2
value|0x200010
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent to  * FOC3  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_MSG_NUM_FOC3
value|0x200014
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from the passive buffer May be updated  * during run_time by the microcode.  */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_PAS_DISABLE
value|0x20024c
end_define

begin_comment
comment|/* [WB 128] Debug only. Passive buffer memory */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_PASSIVE_BUFFER
value|0x202000
end_define

begin_comment
comment|/* [WB 46] pram memory. B45 is parity; b[44:0] - data. */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_PRAM
value|0x240000
end_define

begin_comment
comment|/* [R 16] Valid sleeping threads indication have bit per thread */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_SLEEP_THREADS_VALID
value|0x20026c
end_define

begin_comment
comment|/* [R 1] EXT_STORE FIFO is empty in sem_slow_ls_ext */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_SLOW_EXT_STORE_EMPTY
value|0x2002a0
end_define

begin_comment
comment|/* [RW 16] List of free threads . There is a bit per thread. */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_THREADS_LIST
value|0x2002e4
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 0 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_0_AS
value|0x200038
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 10 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_10_AS
value|0x200060
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 11 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_11_AS
value|0x200064
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 12 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_12_AS
value|0x200068
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 13 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_13_AS
value|0x20006c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 14 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_14_AS
value|0x200070
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 15 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_15_AS
value|0x200074
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 16 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_16_AS
value|0x200078
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 17 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_17_AS
value|0x20007c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 18 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_18_AS
value|0x200080
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 1 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_1_AS
value|0x20003c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 2 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_2_AS
value|0x200040
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 3 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_3_AS
value|0x200044
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 4 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_4_AS
value|0x200048
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 5 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_5_AS
value|0x20004c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 6 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_6_AS
value|0x200050
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 7 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_7_AS
value|0x200054
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 8 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_8_AS
value|0x200058
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 9 */
end_comment

begin_define
define|#
directive|define
name|CSEM_REG_TS_9_AS
value|0x20005c
end_define

begin_comment
comment|/* [RW 1] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|DBG_REG_DBG_PRTY_MASK
value|0xc0a8
end_define

begin_comment
comment|/* [R 1] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|DBG_REG_DBG_PRTY_STS
value|0xc09c
end_define

begin_comment
comment|/*  * [RW 32] Commands memory. The address to command X; row Y is to calculated  * as 14*X+Y.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_CMD_MEM
value|0x102400
end_define

begin_define
define|#
directive|define
name|DMAE_REG_CMD_MEM_SIZE
value|224
end_define

begin_comment
comment|/*  * [RW 1] If 0 - the CRC-16c initial value is all zeroes; if 1 - the CRC-16c  * initial value is all ones.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_CRC16C_INIT
value|0x10201c
end_define

begin_comment
comment|/*  * [RW 1] If 0 - the CRC-16 T10 initial value is all zeroes; if 1 - the  * CRC-16 T10 initial value is all ones.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_CRC16T10_INIT
value|0x102020
end_define

begin_comment
comment|/* [RW 2] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_INT_MASK
value|0x102054
end_define

begin_comment
comment|/* [RW 4] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_PRTY_MASK
value|0x102064
end_define

begin_comment
comment|/* [R 4] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_PRTY_STS
value|0x102058
end_define

begin_comment
comment|/* [RW 1] Command 0 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C0
value|0x102080
end_define

begin_comment
comment|/* [RW 1] Command 1 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C1
value|0x102084
end_define

begin_comment
comment|/* [RW 1] Command 10 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C10
value|0x102088
end_define

begin_comment
comment|/* [RW 1] Command 11 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C11
value|0x10208c
end_define

begin_comment
comment|/* [RW 1] Command 12 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C12
value|0x102090
end_define

begin_comment
comment|/* [RW 1] Command 13 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C13
value|0x102094
end_define

begin_comment
comment|/* [RW 1] Command 14 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C14
value|0x102098
end_define

begin_comment
comment|/* [RW 1] Command 15 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C15
value|0x10209c
end_define

begin_comment
comment|/* [RW 1] Command 2 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C2
value|0x1020a0
end_define

begin_comment
comment|/* [RW 1] Command 3 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C3
value|0x1020a4
end_define

begin_comment
comment|/* [RW 1] Command 4 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C4
value|0x1020a8
end_define

begin_comment
comment|/* [RW 1] Command 5 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C5
value|0x1020ac
end_define

begin_comment
comment|/* [RW 1] Command 6 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C6
value|0x1020b0
end_define

begin_comment
comment|/* [RW 1] Command 7 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C7
value|0x1020b4
end_define

begin_comment
comment|/* [RW 1] Command 8 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C8
value|0x1020b8
end_define

begin_comment
comment|/* [RW 1] Command 9 go. */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GO_C9
value|0x1020bc
end_define

begin_comment
comment|/*  * [RW 1] DMAE GRC Interface (Target; aster) enable. If 0 - the acknowledge  * input is disregarded; valid is deasserted; all other signals are treated  * as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_GRC_IFEN
value|0x102008
end_define

begin_comment
comment|/*  * [RW 1] DMAE PCI Interface (Request; ead; rite) enable. If 0 - the  * acknowledge input is disregarded; valid is deasserted; full is asserted;  * all other signals are treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_PCI_IFEN
value|0x102004
end_define

begin_comment
comment|/*  * [RW 4] DMAE- PCI Request Interface initial credit. Write writes the  * initial value to the credit counter; related to the address. Read returns  * the current value of the counter.  */
end_comment

begin_define
define|#
directive|define
name|DMAE_REG_PXP_REQ_INIT_CRD
value|0x1020c0
end_define

begin_comment
comment|/* [RW 8] Aggregation command. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_AGG_CMD0
value|0x170060
end_define

begin_comment
comment|/* [RW 8] Aggregation command. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_AGG_CMD1
value|0x170064
end_define

begin_comment
comment|/* [RW 8] Aggregation command. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_AGG_CMD2
value|0x170068
end_define

begin_comment
comment|/* [RW 8] Aggregation command. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_AGG_CMD3
value|0x17006c
end_define

begin_comment
comment|/* [RW 28] UCM Header. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_CMHEAD_RX
value|0x170050
end_define

begin_comment
comment|/* [RW 32] Doorbell address for RBC doorbells (function 0). */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DB_ADDR0
value|0x17008c
end_define

begin_comment
comment|/* [RW 5] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_INT_MASK
value|0x170180
end_define

begin_comment
comment|/* [R 5] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_INT_STS
value|0x170174
end_define

begin_comment
comment|/* [RC 5] Interrupt register #0 read clear */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_INT_STS_CLR
value|0x170178
end_define

begin_comment
comment|/* [RW 2] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_PRTY_MASK
value|0x170190
end_define

begin_comment
comment|/* [R 2] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_PRTY_STS
value|0x170184
end_define

begin_comment
comment|/* [RW 8] The address to write the DPM CID to STORM. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DPM_CID_ADDR
value|0x170044
end_define

begin_comment
comment|/* [RW 5] The DPM mode CID extraction offset. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DPM_CID_OFST
value|0x170030
end_define

begin_comment
comment|/* [RW 12] The threshold of the DQ FIFO to send the almost full interrupt. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DQ_FIFO_AFULL_TH
value|0x17007c
end_define

begin_comment
comment|/* [RW 12] The threshold of the DQ FIFO to send the full interrupt. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DQ_FIFO_FULL_TH
value|0x170078
end_define

begin_comment
comment|/*  * [R 13] Current value of the DQ FIFO fill level according to following  * pointer. The range is 0 - 256 FIFO rows; where each row stands for the  * doorbell.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DQ_FILL_LVLF
value|0x1700a4
end_define

begin_comment
comment|/*  * [R 1] DQ FIFO full status. Is set; when FIFO filling level is more o  * equal to full threshold; reset on full clear.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_DQ_FULL_ST
value|0x1700c0
end_define

begin_comment
comment|/* [RW 28] The value sent to CM header in the case of CFC load error. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_ERR_CMHEAD
value|0x170058
end_define

begin_define
define|#
directive|define
name|DORQ_REG_IF_EN
value|0x170004
end_define

begin_define
define|#
directive|define
name|DORQ_REG_MODE_ACT
value|0x170008
end_define

begin_comment
comment|/* [RW 5] The normal mode CID extraction offset. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_NORM_CID_OFST
value|0x17002c
end_define

begin_comment
comment|/* [RW 28] TCM Header when only TCP context is loaded. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_NORM_CMHEAD_TX
value|0x17004c
end_define

begin_comment
comment|/*  * [RW 3] The number of simultaneous outstanding requests to Context Fetc  * Interface.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_OUTST_REQ
value|0x17003c
end_define

begin_define
define|#
directive|define
name|DORQ_REG_REGN
value|0x170038
end_define

begin_comment
comment|/*  * [R 4] Current value of response A counter credit. Initial credit i  * configured through write to ~dorq_registers_rsp_init_crd.rsp_init_crd  * register.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_RSPA_CRD_CNT
value|0x1700ac
end_define

begin_comment
comment|/*  * [R 4] Current value of response B counter credit. Initial credit i  * configured through write to ~dorq_registers_rsp_init_crd.rsp_init_crd  * register.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_RSPB_CRD_CNT
value|0x1700b0
end_define

begin_comment
comment|/*  * [RW 4] The initial credit at the Doorbell Response Interface. The writ  * writes the same initial credit to the rspa_crd_cnt and rspb_crd_cnt. The  * read reads this written value.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_RSP_INIT_CRD
value|0x170048
end_define

begin_comment
comment|/*  * [RW 4] Initial activity counter value on the load request; when th  * shortcut is done.  */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_SHRT_ACT_CNT
value|0x170070
end_define

begin_comment
comment|/* [RW 28] TCM Header when both ULP and TCP context is loaded. */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_SHRT_CMHEAD
value|0x170054
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_ATTN_BIT_EN_0
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_INT_LINE_EN_0
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_MSI_ATTN_EN_0
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_SINGLE_ISR_EN_0
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|HC_REG_AGG_INT_0
value|0x108050
end_define

begin_define
define|#
directive|define
name|HC_REG_AGG_INT_1
value|0x108054
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_BIT
value|0x108120
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_IDX
value|0x108100
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_MSG0_ADDR_L
value|0x108018
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_MSG1_ADDR_L
value|0x108020
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_NUM_P0
value|0x108038
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_NUM_P1
value|0x10803c
end_define

begin_define
define|#
directive|define
name|HC_REG_COMMAND_REG
value|0x108180
end_define

begin_define
define|#
directive|define
name|HC_REG_CONFIG_0
value|0x108000
end_define

begin_define
define|#
directive|define
name|HC_REG_CONFIG_1
value|0x108004
end_define

begin_define
define|#
directive|define
name|HC_REG_FUNC_NUM_P0
value|0x1080ac
end_define

begin_define
define|#
directive|define
name|HC_REG_FUNC_NUM_P1
value|0x1080b0
end_define

begin_comment
comment|/* [RW 3] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|HC_REG_HC_PRTY_MASK
value|0x1080a0
end_define

begin_comment
comment|/* [R 3] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|HC_REG_HC_PRTY_STS
value|0x108094
end_define

begin_define
define|#
directive|define
name|HC_REG_INT_MASK
value|0x108108
end_define

begin_define
define|#
directive|define
name|HC_REG_LEADING_EDGE_0
value|0x108040
end_define

begin_define
define|#
directive|define
name|HC_REG_LEADING_EDGE_1
value|0x108048
end_define

begin_define
define|#
directive|define
name|HC_REG_P0_PROD_CONS
value|0x108200
end_define

begin_define
define|#
directive|define
name|HC_REG_P1_PROD_CONS
value|0x108400
end_define

begin_define
define|#
directive|define
name|HC_REG_PBA_COMMAND
value|0x108140
end_define

begin_define
define|#
directive|define
name|HC_REG_PCI_CONFIG_0
value|0x108010
end_define

begin_define
define|#
directive|define
name|HC_REG_PCI_CONFIG_1
value|0x108014
end_define

begin_define
define|#
directive|define
name|HC_REG_STATISTIC_COUNTERS
value|0x109000
end_define

begin_define
define|#
directive|define
name|HC_REG_TRAILING_EDGE_0
value|0x108044
end_define

begin_define
define|#
directive|define
name|HC_REG_TRAILING_EDGE_1
value|0x10804c
end_define

begin_define
define|#
directive|define
name|HC_REG_UC_RAM_ADDR_0
value|0x108028
end_define

begin_define
define|#
directive|define
name|HC_REG_UC_RAM_ADDR_1
value|0x108030
end_define

begin_define
define|#
directive|define
name|HC_REG_USTORM_ADDR_FOR_COALESCE
value|0x108068
end_define

begin_define
define|#
directive|define
name|HC_REG_VQID_0
value|0x108008
end_define

begin_define
define|#
directive|define
name|HC_REG_VQID_1
value|0x10800c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_ACCESS_ENABLE
value|0x86424
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_ADDR
value|0x8640c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_CFG4
value|0x8642c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_COMMAND
value|0x86400
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_READ
value|0x86410
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_SW_ARB
value|0x86420
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_WRITE
value|0x86408
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_SCRATCH
value|0xa0000
end_define

begin_comment
comment|/*  * [R 32] read first 32 bit after inversion of function 0. mapped a  * follows: [0] NIG attention for function0; [1] NIG attention for  * function1; [2] GPIO1 mcp; [3] GPIO2 mcp; [4] GPIO3 mcp; [5] GPIO4 mcp;  * [6] GPIO1 function 1; [7] GPIO2 function 1; [8] GPIO3 function 1; [9]  * GPIO4 function 1; [10] PCIE glue/PXP VPD event function0; [11] PCIE  * glue/PXP VPD event function1; [12] PCIE glue/PXP Expansion ROM event0;  * [13] PCIE glue/PXP Expansion ROM event1; [14] SPIO4; [15] SPIO5; [16]  * MSI/X indication for mcp; [17] MSI/X indication for function 1; [18] BRB  * Parity error; [19] BRB Hw interrupt; [20] PRS Parity error; [21] PRS Hw  * interrupt; [22] SRC Parity error; [23] SRC Hw interrupt; [24] TSDM Parity  * error; [25] TSDM Hw interrupt; [26] TCM Parity error; [27] TCM Hw  * interrupt; [28] TSEMI Parity error; [29] TSEMI Hw interrupt; [30] PBF  * Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_1_FUNC_0
value|0xa42c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_1_FUNC_1
value|0xa430
end_define

begin_comment
comment|/*  * [R 32] read first 32 bit after inversion of mcp. mapped as follows: [0  * NIG attention for function0; [1] NIG attention for function1; [2] GPIO1  * mcp; [3] GPIO2 mcp; [4] GPIO3 mcp; [5] GPIO4 mcp; [6] GPIO1 function 1;  * [7] GPIO2 function 1; [8] GPIO3 function 1; [9] GPIO4 function 1; [10]  * PCIE glue/PXP VPD event function0; [11] PCIE glue/PXP VPD event  * function1; [12] PCIE glue/PXP Expansion ROM event0; [13] PCIE glue/PXP  * Expansion ROM event1; [14] SPIO4; [15] SPIO5; [16] MSI/X indication for  * mcp; [17] MSI/X indication for function 1; [18] BRB Parity error; [19]  * BRB Hw interrupt; [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC  * Parity error; [23] SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw  * interrupt; [26] TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI  * Parity error; [29] TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_1_MCP
value|0xa434
end_define

begin_comment
comment|/*  * [R 32] read second 32 bit after inversion of function 0. mapped a  * follows: [0] PBClient Parity error; [1] PBClient Hw interrupt; [2] QM  * Parity error; [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw  * interrupt; [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity  * error; [9] XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw  * interrupt; [12] DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14]  * NIG Parity error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error;  * [17] Vaux PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw  * interrupt; [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM  * Parity error; [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI  * Hw interrupt; [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM  * Parity error; [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_2_FUNC_0
value|0xa438
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_2_FUNC_1
value|0xa43c
end_define

begin_comment
comment|/*  * [R 32] read second 32 bit after inversion of mcp. mapped as follows: [0  * PBClient Parity error; [1] PBClient Hw interrupt; [2] QM Parity error;  * [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw interrupt;  * [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity error; [9]  * XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw interrupt; [12]  * DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14] NIG Parity  * error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error; [17] Vaux  * PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw interrupt;  * [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM Parity error;  * [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI Hw interrupt;  * [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM Parity error;  * [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_2_MCP
value|0xa440
end_define

begin_comment
comment|/*  * [R 32] read third 32 bit after inversion of function 0. mapped a  * follows: [0] CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP Parity  * error; [3] PXP Hw interrupt; [4] PXPpciClockClient Parity error; [5]  * PXPpciClockClient Hw interrupt; [6] CFC Parity error; [7] CFC Hw  * interrupt; [8] CDU Parity error; [9] CDU Hw interrupt; [10] DMAE Parity  * error; [11] DMAE Hw interrupt; [12] IGU (HC) Parity error; [13] IGU (HC)  * Hw interrupt; [14] MISC Parity error; [15] MISC Hw interrupt; [16]  * pxp_misc_mps_attn; [17] Flash event; [18] SMB event; [19] MCP attn0; [20]  * MCP attn1; [21] SW timers attn_1 func0; [22] SW timers attn_2 func0; [23]  * SW timers attn_3 func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW  * timers attn_1 func1; [27] SW timers attn_2 func1; [28] SW timers attn_3  * func1; [29] SW timers attn_4 func1; [30] General attn0; [31] General  * attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_3_FUNC_0
value|0xa444
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_3_FUNC_1
value|0xa448
end_define

begin_comment
comment|/*  * [R 32] read third 32 bit after inversion of mcp. mapped as follows: [0  * CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP Parity error; [3] PXP  * Hw interrupt; [4] PXPpciClockClient Parity error; [5] PXPpciClockClient  * Hw interrupt; [6] CFC Parity error; [7] CFC Hw interrupt; [8] CDU Parity  * error; [9] CDU Hw interrupt; [10] DMAE Parity error; [11] DMAE Hw  * interrupt; [12] IGU (HC) Parity error; [13] IGU (HC) Hw interrupt; [14]  * MISC Parity error; [15] MISC Hw interrupt; [16] pxp_misc_mps_attn; [17]  * Flash event; [18] SMB event; [19] MCP attn0; [20] MCP attn1; [21] SW  * timers attn_1 func0; [22] SW timers attn_2 func0; [23] SW timers attn_3  * func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW timers attn_1  * func1; [27] SW timers attn_2 func1; [28] SW timers attn_3 func1; [29] SW  * timers attn_4 func1; [30] General attn0; [31] General attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_3_MCP
value|0xa44c
end_define

begin_comment
comment|/*  * [R 32] read fourth 32 bit after inversion of function 0. mapped a  * follows: [0] General attn2; [1] General attn3; [2] General attn4; [3]  * General attn5; [4] General attn6; [5] General attn7; [6] General attn8;  * [7] General attn9; [8] General attn10; [9] General attn11; [10] General  * attn12; [11] General attn13; [12] General attn14; [13] General attn15;  * [14] General attn16; [15] General attn17; [16] General attn18; [17]  * General attn19; [18] General attn20; [19] General attn21; [20] Main power  * interrupt; [21] RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN  * Latched attn; [24] RBCU Latched attn; [25] RBCP Latched attn; [26] GRC  * Latched timeout attention; [27] GRC Latched reserved access attention;  * [28] MCP Latched rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP  * Latched ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_4_FUNC_0
value|0xa450
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_4_FUNC_1
value|0xa454
end_define

begin_comment
comment|/*  * [R 32] read fourth 32 bit after inversion of mcp. mapped as follows: [0  * General attn2; [1] General attn3; [2] General attn4; [3] General attn5;  * [4] General attn6; [5] General attn7; [6] General attn8; [7] General  * attn9; [8] General attn10; [9] General attn11; [10] General attn12; [11]  * General attn13; [12] General attn14; [13] General attn15; [14] General  * attn16; [15] General attn17; [16] General attn18; [17] General attn19;  * [18] General attn20; [19] General attn21; [20] Main power interrupt; [21]  * RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN Latched attn; [24]  * RBCU Latched attn; [25] RBCP Latched attn; [26] GRC Latched timeout  * attention; [27] GRC Latched reserved access attention; [28] MCP Latched  * rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP Latched  * ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_4_MCP
value|0xa458
end_define

begin_comment
comment|/*  * [W 14] write to this register results with the clear of the latche  * signals; one in d0 clears RBCR latch; one in d1 clears RBCT latch; one in  * d2 clears RBCN latch; one in d3 clears RBCU latch; one in d4 clears RBCP  * latch; one in d5 clears GRC Latched timeout attention; one in d6 clears  * GRC Latched reserved access attention; one in d7 clears Latched  * rom_parity; one in d8 clears Latched ump_rx_parity; one in d9 clears  * Latched ump_tx_parity; one in d10 clears Latched scpad_parity (both  * ports); one in d11 clears pxpv_misc_mps_attn; one in d12 clears  * pxp_misc_exp_rom_attn0; one in d13 clears pxp_misc_exp_rom_attn1; read  * from this register return zero  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_CLR_LATCH_SIGNAL
value|0xa45c
end_define

begin_comment
comment|/*  * [RW 32] first 32b for enabling the output for function 0 output0. mappe  * as follows: [0] NIG attention for function0; [1] NIG attention for  * function1; [2] GPIO1 function 0; [3] GPIO2 function 0; [4] GPIO3 function  * 0; [5] GPIO4 function 0; [6] GPIO1 function 1; [7] GPIO2 function 1; [8]  * GPIO3 function 1; [9] GPIO4 function 1; [10] PCIE glue/PXP VPD event  * function0; [11] PCIE glue/PXP VPD event function1; [12] PCIE glue/PXP  * Expansion ROM event0; [13] PCIE glue/PXP Expansion ROM event1; [14]  * SPIO4; [15] SPIO5; [16] MSI/X indication for function 0; [17] MSI/X  * indication for function 1; [18] BRB Parity error; [19] BRB Hw interrupt;  * [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC Parity error; [23]  * SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw interrupt; [26]  * TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI Parity error; [29]  * TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0
value|0xa06c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_1
value|0xa07c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_2
value|0xa08c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_3
value|0xa09c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_5
value|0xa0bc
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_6
value|0xa0cc
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_7
value|0xa0dc
end_define

begin_comment
comment|/*  * [RW 32] first 32b for enabling the output for function 1 output0. mappe  * as follows: [0] NIG attention for function0; [1] NIG attention for  * function1; [2] GPIO1 function 1; [3] GPIO2 function 1; [4] GPIO3 function  * 1; [5] GPIO4 function 1; [6] GPIO1 function 1; [7] GPIO2 function 1; [8]  * GPIO3 function 1; [9] GPIO4 function 1; [10] PCIE glue/PXP VPD event  * function0; [11] PCIE glue/PXP VPD event function1; [12] PCIE glue/PXP  * Expansion ROM event0; [13] PCIE glue/PXP Expansion ROM event1; [14]  * SPIO4; [15] SPIO5; [16] MSI/X indication for function 1; [17] MSI/X  * indication for function 1; [18] BRB Parity error; [19] BRB Hw interrupt;  * [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC Parity error; [23]  * SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw interrupt; [26]  * TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI Parity error; [29]  * TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0
value|0xa10c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_1
value|0xa11c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_2
value|0xa12c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_3
value|0xa13c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_5
value|0xa15c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_6
value|0xa16c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_7
value|0xa17c
end_define

begin_comment
comment|/*  * [RW 32] first 32b for enabling the output for close the gate nig. mappe  * as follows: [0] NIG attention for function0; [1] NIG attention for  * function1; [2] GPIO1 function 0; [3] GPIO2 function 0; [4] GPIO3 function  * 0; [5] GPIO4 function 0; [6] GPIO1 function 1; [7] GPIO2 function 1; [8]  * GPIO3 function 1; [9] GPIO4 function 1; [10] PCIE glue/PXP VPD event  * function0; [11] PCIE glue/PXP VPD event function1; [12] PCIE glue/PXP  * Expansion ROM event0; [13] PCIE glue/PXP Expansion ROM event1; [14]  * SPIO4; [15] SPIO5; [16] MSI/X indication for function 0; [17] MSI/X  * indication for function 1; [18] BRB Parity error; [19] BRB Hw interrupt;  * [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC Parity error; [23]  * SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw interrupt; [26]  * TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI Parity error; [29]  * TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_NIG_0
value|0xa0ec
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_NIG_1
value|0xa18c
end_define

begin_comment
comment|/*  * [RW 32] first 32b for enabling the output for close the gate pxp. mappe  * as follows: [0] NIG attention for function0; [1] NIG attention for  * function1; [2] GPIO1 function 0; [3] GPIO2 function 0; [4] GPIO3 function  * 0; [5] GPIO4 function 0; [6] GPIO1 function 1; [7] GPIO2 function 1; [8]  * GPIO3 function 1; [9] GPIO4 function 1; [10] PCIE glue/PXP VPD event  * function0; [11] PCIE glue/PXP VPD event function1; [12] PCIE glue/PXP  * Expansion ROM event0; [13] PCIE glue/PXP Expansion ROM event1; [14]  * SPIO4; [15] SPIO5; [16] MSI/X indication for function 0; [17] MSI/X  * indication for function 1; [18] BRB Parity error; [19] BRB Hw interrupt;  * [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC Parity error; [23]  * SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw interrupt; [26]  * TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI Parity error; [29]  * TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_PXP_0
value|0xa0fc
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_PXP_1
value|0xa19c
end_define

begin_comment
comment|/*  * [RW 32] second 32b for enabling the output for function 0 output0. mappe  * as follows: [0] PBClient Parity error; [1] PBClient Hw interrupt; [2] QM  * Parity error; [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw  * interrupt; [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity  * error; [9] XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw  * interrupt; [12] DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14]  * NIG Parity error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error;  * [17] Vaux PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw  * interrupt; [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM  * Parity error; [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI  * Hw interrupt; [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM  * Parity error; [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_FUNC_0_OUT_0
value|0xa070
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_FUNC_0_OUT_1
value|0xa080
end_define

begin_comment
comment|/*  * [RW 32] second 32b for enabling the output for function 1 output0. mappe  * as follows: [0] PBClient Parity error; [1] PBClient Hw interrupt; [2] QM  * Parity error; [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw  * interrupt; [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity  * error; [9] XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw  * interrupt; [12] DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14]  * NIG Parity error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error;  * [17] Vaux PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw  * interrupt; [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM  * Parity error; [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI  * Hw interrupt; [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM  * Parity error; [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_FUNC_1_OUT_0
value|0xa110
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_FUNC_1_OUT_1
value|0xa120
end_define

begin_comment
comment|/*  * [RW 32] second 32b for enabling the output for close the gate nig. mappe  * as follows: [0] PBClient Parity error; [1] PBClient Hw interrupt; [2] QM  * Parity error; [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw  * interrupt; [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity  * error; [9] XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw  * interrupt; [12] DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14]  * NIG Parity error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error;  * [17] Vaux PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw  * interrupt; [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM  * Parity error; [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI  * Hw interrupt; [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM  * Parity error; [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_NIG_0
value|0xa0f0
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_NIG_1
value|0xa190
end_define

begin_comment
comment|/*  * [RW 32] second 32b for enabling the output for close the gate pxp. mappe  * as follows: [0] PBClient Parity error; [1] PBClient Hw interrupt; [2] QM  * Parity error; [3] QM Hw interrupt; [4] Timers Parity error; [5] Timers Hw  * interrupt; [6] XSDM Parity error; [7] XSDM Hw interrupt; [8] XCM Parity  * error; [9] XCM Hw interrupt; [10] XSEMI Parity error; [11] XSEMI Hw  * interrupt; [12] DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14]  * NIG Parity error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error;  * [17] Vaux PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw  * interrupt; [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM  * Parity error; [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI  * Hw interrupt; [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM  * Parity error; [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_PXP_0
value|0xa100
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE2_PXP_1
value|0xa1a0
end_define

begin_comment
comment|/*  * [RW 32] third 32b for enabling the output for function 0 output0. mappe  * as follows: [0] CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP  * Parity error; [3] PXP Hw interrupt; [4] PXPpciClockClient Parity error;  * [5] PXPpciClockClient Hw interrupt; [6] CFC Parity error; [7] CFC Hw  * interrupt; [8] CDU Parity error; [9] CDU Hw interrupt; [10] DMAE Parity  * error; [11] DMAE Hw interrupt; [12] IGU (HC) Parity error; [13] IGU (HC)  * Hw interrupt; [14] MISC Parity error; [15] MISC Hw interrupt; [16]  * pxp_misc_mps_attn; [17] Flash event; [18] SMB event; [19] MCP attn0; [20]  * MCP attn1; [21] SW timers attn_1 func0; [22] SW timers attn_2 func0; [23]  * SW timers attn_3 func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW  * timers attn_1 func1; [27] SW timers attn_2 func1; [28] SW timers attn_3  * func1; [29] SW timers attn_4 func1; [30] General attn0; [31] General  * attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_FUNC_0_OUT_0
value|0xa074
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_FUNC_0_OUT_1
value|0xa084
end_define

begin_comment
comment|/*  * [RW 32] third 32b for enabling the output for function 1 output0. mappe  * as follows: [0] CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP  * Parity error; [3] PXP Hw interrupt; [4] PXPpciClockClient Parity error;  * [5] PXPpciClockClient Hw interrupt; [6] CFC Parity error; [7] CFC Hw  * interrupt; [8] CDU Parity error; [9] CDU Hw interrupt; [10] DMAE Parity  * error; [11] DMAE Hw interrupt; [12] IGU (HC) Parity error; [13] IGU (HC)  * Hw interrupt; [14] MISC Parity error; [15] MISC Hw interrupt; [16]  * pxp_misc_mps_attn; [17] Flash event; [18] SMB event; [19] MCP attn0; [20]  * MCP attn1; [21] SW timers attn_1 func0; [22] SW timers attn_2 func0; [23]  * SW timers attn_3 func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW  * timers attn_1 func1; [27] SW timers attn_2 func1; [28] SW timers attn_3  * func1; [29] SW timers attn_4 func1; [30] General attn0; [31] General  * attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_FUNC_1_OUT_0
value|0xa114
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_FUNC_1_OUT_1
value|0xa124
end_define

begin_comment
comment|/*  * [RW 32] third 32b for enabling the output for close the gate nig. mappe  * as follows: [0] CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP  * Parity error; [3] PXP Hw interrupt; [4] PXPpciClockClient Parity error;  * [5] PXPpciClockClient Hw interrupt; [6] CFC Parity error; [7] CFC Hw  * interrupt; [8] CDU Parity error; [9] CDU Hw interrupt; [10] DMAE Parity  * error; [11] DMAE Hw interrupt; [12] IGU (HC) Parity error; [13] IGU (HC)  * Hw interrupt; [14] MISC Parity error; [15] MISC Hw interrupt; [16]  * pxp_misc_mps_attn; [17] Flash event; [18] SMB event; [19] MCP attn0; [20]  * MCP attn1; [21] SW timers attn_1 func0; [22] SW timers attn_2 func0; [23]  * SW timers attn_3 func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW  * timers attn_1 func1; [27] SW timers attn_2 func1; [28] SW timers attn_3  * func1; [29] SW timers attn_4 func1; [30] General attn0; [31] General  * attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_NIG_0
value|0xa0f4
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_NIG_1
value|0xa194
end_define

begin_comment
comment|/*  * [RW 32] third 32b for enabling the output for close the gate pxp. mappe  * as follows: [0] CSEMI Parity error; [1] CSEMI Hw interrupt; [2] PXP  * Parity error; [3] PXP Hw interrupt; [4] PXPpciClockClient Parity error;  * [5] PXPpciClockClient Hw interrupt; [6] CFC Parity error; [7] CFC Hw  * interrupt; [8] CDU Parity error; [9] CDU Hw interrupt; [10] DMAE Parity  * error; [11] DMAE Hw interrupt; [12] IGU (HC) Parity error; [13] IGU (HC)  * Hw interrupt; [14] MISC Parity error; [15] MISC Hw interrupt; [16]  * pxp_misc_mps_attn; [17] Flash event; [18] SMB event; [19] MCP attn0; [20]  * MCP attn1; [21] SW timers attn_1 func0; [22] SW timers attn_2 func0; [23]  * SW timers attn_3 func0; [24] SW timers attn_4 func0; [25] PERST; [26] SW  * timers attn_1 func1; [27] SW timers attn_2 func1; [28] SW timers attn_3  * func1; [29] SW timers attn_4 func1; [30] General attn0; [31] General  * attn1;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_PXP_0
value|0xa104
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE3_PXP_1
value|0xa1a4
end_define

begin_comment
comment|/*  * [RW 32] fourth 32b for enabling the output for function 0 output0.mappe  * as follows: [0] General attn2; [1] General attn3; [2] General attn4; [3]  * General attn5; [4] General attn6; [5] General attn7; [6] General attn8;  * [7] General attn9; [8] General attn10; [9] General attn11; [10] General  * attn12; [11] General attn13; [12] General attn14; [13] General attn15;  * [14] General attn16; [15] General attn17; [16] General attn18; [17]  * General attn19; [18] General attn20; [19] General attn21; [20] Main power  * interrupt; [21] RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN  * Latched attn; [24] RBCU Latched attn; [25] RBCP Latched attn; [26] GRC  * Latched timeout attention; [27] GRC Latched reserved access attention;  * [28] MCP Latched rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP  * Latched ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_0
value|0xa078
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_2
value|0xa098
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_4
value|0xa0b8
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_5
value|0xa0c8
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_6
value|0xa0d8
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_7
value|0xa0e8
end_define

begin_comment
comment|/*  * [RW 32] fourth 32b for enabling the output for function 1 output0.mappe  * as follows: [0] General attn2; [1] General attn3; [2] General attn4; [3]  * General attn5; [4] General attn6; [5] General attn7; [6] General attn8;  * [7] General attn9; [8] General attn10; [9] General attn11; [10] General  * attn12; [11] General attn13; [12] General attn14; [13] General attn15;  * [14] General attn16; [15] General attn17; [16] General attn18; [17]  * General attn19; [18] General attn20; [19] General attn21; [20] Main power  * interrupt; [21] RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN  * Latched attn; [24] RBCU Latched attn; [25] RBCP Latched attn; [26] GRC  * Latched timeout attention; [27] GRC Latched reserved access attention;  * [28] MCP Latched rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP  * Latched ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_0
value|0xa118
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_2
value|0xa138
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_4
value|0xa158
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_5
value|0xa168
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_6
value|0xa178
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_7
value|0xa188
end_define

begin_comment
comment|/*  * [RW 32] fourth 32b for enabling the output for close the gate nig.mappe  * as follows: [0] General attn2; [1] General attn3; [2] General attn4; [3]  * General attn5; [4] General attn6; [5] General attn7; [6] General attn8;  * [7] General attn9; [8] General attn10; [9] General attn11; [10] General  * attn12; [11] General attn13; [12] General attn14; [13] General attn15;  * [14] General attn16; [15] General attn17; [16] General attn18; [17]  * General attn19; [18] General attn20; [19] General attn21; [20] Main power  * interrupt; [21] RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN  * Latched attn; [24] RBCU Latched attn; [25] RBCP Latched attn; [26] GRC  * Latched timeout attention; [27] GRC Latched reserved access attention;  * [28] MCP Latched rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP  * Latched ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_NIG_0
value|0xa0f8
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_NIG_1
value|0xa198
end_define

begin_comment
comment|/*  * [RW 32] fourth 32b for enabling the output for close the gate pxp.mappe  * as follows: [0] General attn2; [1] General attn3; [2] General attn4; [3]  * General attn5; [4] General attn6; [5] General attn7; [6] General attn8;  * [7] General attn9; [8] General attn10; [9] General attn11; [10] General  * attn12; [11] General attn13; [12] General attn14; [13] General attn15;  * [14] General attn16; [15] General attn17; [16] General attn18; [17]  * General attn19; [18] General attn20; [19] General attn21; [20] Main power  * interrupt; [21] RBCR Latched attn; [22] RBCT Latched attn; [23] RBCN  * Latched attn; [24] RBCU Latched attn; [25] RBCP Latched attn; [26] GRC  * Latched timeout attention; [27] GRC Latched reserved access attention;  * [28] MCP Latched rom_parity; [29] MCP Latched ump_rx_parity; [30] MCP  * Latched ump_tx_parity; [31] MCP Latched scpad_parity;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_PXP_0
value|0xa108
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_PXP_1
value|0xa1a8
end_define

begin_comment
comment|/*  * [RW 1] set/clr general attention 0; this will set/clr bit 94 in the ae  * 128 bit vector  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_0
value|0xa000
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_1
value|0xa004
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_10
value|0xa028
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_11
value|0xa02c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_12
value|0xa030
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_2
value|0xa008
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_3
value|0xa00c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_4
value|0xa010
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_5
value|0xa014
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_6
value|0xa018
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_7
value|0xa01c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_8
value|0xa020
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_9
value|0xa024
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_MASK
value|0xa61c
end_define

begin_comment
comment|/*  * [RW 32] first 32b for inverting the input for function 0; for each bit  * 0= do not invert; 1= invert; mapped as follows: [0] NIG attention for  * function0; [1] NIG attention for function1; [2] GPIO1 mcp; [3] GPIO2 mcp;  * [4] GPIO3 mcp; [5] GPIO4 mcp; [6] GPIO1 function 1; [7] GPIO2 function 1;  * [8] GPIO3 function 1; [9] GPIO4 function 1; [10] PCIE glue/PXP VPD event  * function0; [11] PCIE glue/PXP VPD event function1; [12] PCIE glue/PXP  * Expansion ROM event0; [13] PCIE glue/PXP Expansion ROM event1; [14]  * SPIO4; [15] SPIO5; [16] MSI/X indication for mcp; [17] MSI/X indication  * for function 1; [18] BRB Parity error; [19] BRB Hw interrupt; [20] PRS  * Parity error; [21] PRS Hw interrupt; [22] SRC Parity error; [23] SRC Hw  * interrupt; [24] TSDM Parity error; [25] TSDM Hw interrupt; [26] TCM  * Parity error; [27] TCM Hw interrupt; [28] TSEMI Parity error; [29] TSEMI  * Hw interrupt; [30] PBF Parity error; [31] PBF Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_INVERTER_1_FUNC_0
value|0xa22c
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_INVERTER_1_FUNC_1
value|0xa23c
end_define

begin_comment
comment|/*  * [RW 32] second 32b for inverting the input for function 0; for each bit  * 0= do not invert; 1= invert. mapped as follows: [0] PBClient Parity  * error; [1] PBClient Hw interrupt; [2] QM Parity error; [3] QM Hw  * interrupt; [4] Timers Parity error; [5] Timers Hw interrupt; [6] XSDM  * Parity error; [7] XSDM Hw interrupt; [8] XCM Parity error; [9] XCM Hw  * interrupt; [10] XSEMI Parity error; [11] XSEMI Hw interrupt; [12]  * DoorbellQ Parity error; [13] DoorbellQ Hw interrupt; [14] NIG Parity  * error; [15] NIG Hw interrupt; [16] Vaux PCI core Parity error; [17] Vaux  * PCI core Hw interrupt; [18] Debug Parity error; [19] Debug Hw interrupt;  * [20] USDM Parity error; [21] USDM Hw interrupt; [22] UCM Parity error;  * [23] UCM Hw interrupt; [24] USEMI Parity error; [25] USEMI Hw interrupt;  * [26] UPB Parity error; [27] UPB Hw interrupt; [28] CSDM Parity error;  * [29] CSDM Hw interrupt; [30] CCM Parity error; [31] CCM Hw interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_INVERTER_2_FUNC_0
value|0xa230
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_INVERTER_2_FUNC_1
value|0xa240
end_define

begin_comment
comment|/*  * [RW 10] [7:0] = mask 8 attention output signals toward IGU function0  * [9:8] = raserved. Zero = mask; one = unmask  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_MASK_ATTN_FUNC_0
value|0xa060
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_MASK_ATTN_FUNC_1
value|0xa064
end_define

begin_comment
comment|/* [RW 1] If set a system kill occurred */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_SYS_KILL_OCCURRED
value|0xa610
end_define

begin_comment
comment|/*  * [RW 32] Represent the status of the input vector to the AEU when a syste  * kill occurred. The register is reset in por reset. Mapped as follows: [0]  * NIG attention for function0; [1] NIG attention for function1; [2] GPIO1  * mcp; [3] GPIO2 mcp; [4] GPIO3 mcp; [5] GPIO4 mcp; [6] GPIO1 function 1;  * [7] GPIO2 function 1; [8] GPIO3 function 1; [9] GPIO4 function 1; [10]  * PCIE glue/PXP VPD event function0; [11] PCIE glue/PXP VPD event  * function1; [12] PCIE glue/PXP Expansion ROM event0; [13] PCIE glue/PXP  * Expansion ROM event1; [14] SPIO4; [15] SPIO5; [16] MSI/X indication for  * mcp; [17] MSI/X indication for function 1; [18] BRB Parity error; [19]  * BRB Hw interrupt; [20] PRS Parity error; [21] PRS Hw interrupt; [22] SRC  * Parity error; [23] SRC Hw interrupt; [24] TSDM Parity error; [25] TSDM Hw  * interrupt; [26] TCM Parity error; [27] TCM Hw interrupt; [28] TSEMI  * Parity error; [29] TSEMI Hw interrupt; [30] PBF Parity error; [31] PBF Hw  * interrupt;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_AEU_SYS_KILL_STATUS_0
value|0xa600
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_SYS_KILL_STATUS_1
value|0xa604
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_SYS_KILL_STATUS_2
value|0xa608
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_SYS_KILL_STATUS_3
value|0xa60c
end_define

begin_comment
comment|/*  * [R 4] This field indicates the type of the device. '0' - 2 Ports; '1' -  * Port.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_BOND_ID
value|0xa400
end_define

begin_comment
comment|/*  * [R 8] These bits indicate the metal revision of the chip. This valu  * starts at 0x00 for each all-layer tape-out and increments by one for each  * tape-out.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_CHIP_METAL
value|0xa404
end_define

begin_comment
comment|/* [R 16] These bits indicate the part number for the chip. */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_CHIP_NUM
value|0xa408
end_define

begin_comment
comment|/*  * [R 4] These bits indicate the base revision of the chip. This valu  * starts at 0x0 for the A0 tape-out and increments by one for each  * all-layer tape-out.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_CHIP_REV
value|0xa40c
end_define

begin_comment
comment|/*  * [RW 32] The following driver registers(1...16) represent 16 drivers an  * 32 clients. Each client can be controlled by one driver only. One in each  * bit represent that this driver control the appropriate client (Ex: bit 5  * is set means this driver control client number 5). addr1 = set; addr0 =  * clear; read from both addresses will give the same result = status. write  * to address 1 will set a request to control all the clients that their  * appropriate bit (in the write command) is set. if the client is free (the  * appropriate bit in all the other drivers is clear) one will be written to  * that driver register; if the client isn't free the bit will remain zero.  * if the appropriate bit is set (the driver request to gain control on a  * client it already controls the ~MISC_REGISTERS_INT_STS.GENERIC_SW  * interrupt will be asserted). write to address 0 will set a request to  * free all the clients that their appropriate bit (in the write command) is  * set. if the appropriate bit is clear (the driver request to free a client  * it doesn't controls the ~MISC_REGISTERS_INT_STS.GENERIC_SW interrupt will  * be asserted).  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_1
value|0xa510
end_define

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_7
value|0xa3c8
end_define

begin_comment
comment|/*  * [RW 1] e1hmf for WOL. If clr WOL signal o the PXP will be send on bit  * only.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_E1HMF_MODE
value|0xa5f8
end_define

begin_comment
comment|/* [RW 32] Debug only: spare RW register reset by core reset */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GENERIC_CR_0
value|0xa460
end_define

begin_comment
comment|/*  * [RW 32] GPIO. [31-28] FLOAT port 0; [27-24] FLOAT port 0; When any o  * these bits is written as a '1'; the corresponding SPIO bit will turn off  * it's drivers and become an input. This is the reset state of all GPIO  * pins. The read value of these bits will be a '1' if that last command  * (#SET; #CLR; or #FLOAT) for this bit was a #FLOAT. (reset value 0xff).  * [23-20] CLR port 1; 19-16] CLR port 0; When any of these bits is written  * as a '1'; the corresponding GPIO bit will drive low. The read value of  * these bits will be a '1' if that last command (#SET; #CLR; or #FLOAT) for  * this bit was a #CLR. (reset value 0). [15-12] SET port 1; 11-8] port 0;  * SET When any of these bits is written as a '1'; the corresponding GPIO  * bit will drive high (if it has that capability). The read value of these  * bits will be a '1' if that last command (#SET; #CLR; or #FLOAT) for this  * bit was a #SET. (reset value 0). [7-4] VALUE port 1; [3-0] VALUE port 0;  * RO; These bits indicate the read value of each of the eight GPIO pins.  * This is the result value of the pin; not the drive value. Writing these  * bits will have not effect.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GPIO
value|0xa490
end_define

begin_comment
comment|/*  * [RW 8] These bits enable the GPIO_INTs to signals event to th  * IGU/MCP.according to the following map: [0] p0_gpio_0; [1] p0_gpio_1; [2]  * p0_gpio_2; [3] p0_gpio_3; [4] p1_gpio_0; [5] p1_gpio_1; [6] p1_gpio_2;  * [7] p1_gpio_3;  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GPIO_EVENT_EN
value|0xa2bc
end_define

begin_comment
comment|/*  * [RW 32] GPIO INT. [31-28] OLD_CLR port1; [27-24] OLD_CLR port0; Writing  * '1' to these bit clears the corresponding bit in the #OLD_VALUE register.  * This will acknowledge an interrupt on the falling edge of corresponding  * GPIO input (reset value 0). [23-16] OLD_SET [23-16] port1; OLD_SET port0;  * Writing a '1' to these bit sets the corresponding bit in the #OLD_VALUE  * register. This will acknowledge an interrupt on the rising edge of  * corresponding SPIO input (reset value 0). [15-12] OLD_VALUE [11-8] port1;  * OLD_VALUE port0; RO; These bits indicate the old value of the GPIO input  * value. When the ~INT_STATE bit is set; this bit indicates the OLD value  * of the pin such that if ~INT_STATE is set and this bit is '0'; then the  * interrupt is due to a low to high edge. If ~INT_STATE is set and this bit  * is '1'; then the interrupt is due to a high to low edge (reset value 0).  * [7-4] INT_STATE port1; [3-0] INT_STATE RO port0; These bits indicate the  * current GPIO interrupt state for each GPIO pin. This bit is cleared when  * the appropriate #OLD_SET or #OLD_CLR command bit is written. This bit is  * set when the GPIO input does not match the current value in #OLD_VALUE  * (reset value 0).  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GPIO_INT
value|0xa494
end_define

begin_comment
comment|/*  * [R 28] this field hold the last information that caused reserve  * attention. bits [19:0] - address; [22:20] function; [23] reserved;  * [27:24] the master that caused the attention - according to the following  * encodeing:1 = pxp; 2 = mcp; 3 = usdm; 4 = tsdm; 5 = xsdm; 6 = csdm; 7 =  * dbu; 8 = dmae  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GRC_RSV_ATTN
value|0xa3c0
end_define

begin_comment
comment|/*  * [R 28] this field hold the last information that caused timeou  * attention. bits [19:0] - address; [22:20] function; [23] reserved;  * [27:24] the master that caused the attention - according to the following  * encodeing:1 = pxp; 2 = mcp; 3 = usdm; 4 = tsdm; 5 = xsdm; 6 = csdm; 7 =  * dbu; 8 = dmae  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GRC_TIMEOUT_ATTN
value|0xa3c4
end_define

begin_comment
comment|/*  * [RW 1] Setting this bit enables a timer in the GRC block to timeout an  * access that does not finish within  * ~misc_registers_grc_timout_val.grc_timeout_val cycles. When this bit is  * cleared; this timeout is disabled. If this timeout occurs; the GRC shall  * assert it attention output.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_GRC_TIMEOUT_EN
value|0xa280
end_define

begin_comment
comment|/*  * [RW 28] 28 LSB of LCPLL first register; reset val = 521. inside order o  * the bits is: [2:0] OAC reset value 001) CML output buffer bias control;  * 111 for +40%; 011 for +20%; 001 for 0%; 000 for -20%. [5:3] Icp_ctrl  * (reset value 001) Charge pump current control; 111 for 720u; 011 for  * 600u; 001 for 480u and 000 for 360u. [7:6] Bias_ctrl (reset value 00)  * Global bias control; When bit 7 is high bias current will be 10 0gh; When  * bit 6 is high bias will be 100w; Valid values are 00; 10; 01. [10:8]  * Pll_observe (reset value 010) Bits to control observability. bit 10 is  * for test bias; bit 9 is for test CK; bit 8 is test Vc. [12:11] Vth_ctrl  * (reset value 00) Comparator threshold control. 00 for 0.6V; 01 for 0.54V  * and 10 for 0.66V. [13] pllSeqStart (reset value 0) Enables VCO tuning  * sequencer: 1= sequencer disabled; 0= sequencer enabled (inverted  * internally). [14] reserved (reset value 0) Reset for VCO sequencer is  * connected to RESET input directly. [15] capRetry_en (reset value 0)  * enable retry on cap search failure (inverted). [16] freqMonitor_e (reset  * value 0) bit to continuously monitor vco freq (inverted). [17]  * freqDetRestart_en (reset value 0) bit to enable restart when not freq  * locked (inverted). [18] freqDetRetry_en (reset value 0) bit to enable  * retry on freq det failure(inverted). [19] pllForceFdone_en (reset value  * 0) bit to enable pllForceFdone& pllForceFpass into pllSeq. [20]  * pllForceFdone (reset value 0) bit to force freqDone. [21] pllForceFpass  * (reset value 0) bit to force freqPass. [22] pllForceDone_en (reset value  * 0) bit to enable pllForceCapDone. [23] pllForceCapDone (reset value 0)  * bit to force capDone. [24] pllForceCapPass_en (reset value 0) bit to  * enable pllForceCapPass. [25] pllForceCapPass (reset value 0) bit to force  * capPass. [26] capRestart (reset value 0) bit to force cap sequencer to  * restart. [27] capSelectM_en (reset value 0) bit to enable cap select  * register bits.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_LCPLL_CTRL_1
value|0xa2a4
end_define

begin_define
define|#
directive|define
name|MISC_REG_LCPLL_CTRL_REG_2
value|0xa2a8
end_define

begin_comment
comment|/* [RW 4] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_MISC_INT_MASK
value|0xa388
end_define

begin_comment
comment|/* [RW 1] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_MISC_PRTY_MASK
value|0xa398
end_define

begin_comment
comment|/* [R 1] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_MISC_PRTY_STS
value|0xa38c
end_define

begin_define
define|#
directive|define
name|MISC_REG_NIG_WOL_P0
value|0xa270
end_define

begin_define
define|#
directive|define
name|MISC_REG_NIG_WOL_P1
value|0xa274
end_define

begin_comment
comment|/*  * [R 1] If set indicate that the pcie_rst_b was asserted without pers  * assertion  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_PCIE_HOT_RESET
value|0xa618
end_define

begin_comment
comment|/*  * [RW 32] 32 LSB of storm PLL first register; reset val = 0x 071d2911  * inside order of the bits is: [0] P1 divider[0] (reset value 1); [1] P1  * divider[1] (reset value 0); [2] P1 divider[2] (reset value 0); [3] P1  * divider[3] (reset value 0); [4] P2 divider[0] (reset value 1); [5] P2  * divider[1] (reset value 0); [6] P2 divider[2] (reset value 0); [7] P2  * divider[3] (reset value 0); [8] ph_det_dis (reset value 1); [9]  * freq_det_dis (reset value 0); [10] Icpx[0] (reset value 0); [11] Icpx[1]  * (reset value 1); [12] Icpx[2] (reset value 0); [13] Icpx[3] (reset value  * 1); [14] Icpx[4] (reset value 0); [15] Icpx[5] (reset value 0); [16]  * Rx[0] (reset value 1); [17] Rx[1] (reset value 0); [18] vc_en (reset  * value 1); [19] vco_rng[0] (reset value 1); [20] vco_rng[1] (reset value  * 1); [21] Kvco_xf[0] (reset value 0); [22] Kvco_xf[1] (reset value 0);  * [23] Kvco_xf[2] (reset value 0); [24] Kvco_xs[0] (reset value 1); [25]  * Kvco_xs[1] (reset value 1); [26] Kvco_xs[2] (reset value 1); [27]  * testd_en (reset value 0); [28] testd_sel[0] (reset value 0); [29]  * testd_sel[1] (reset value 0); [30] testd_sel[2] (reset value 0); [31]  * testa_en (reset value 0);  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_PLL_STORM_CTRL_1
value|0xa294
end_define

begin_define
define|#
directive|define
name|MISC_REG_PLL_STORM_CTRL_2
value|0xa298
end_define

begin_define
define|#
directive|define
name|MISC_REG_PLL_STORM_CTRL_3
value|0xa29c
end_define

begin_define
define|#
directive|define
name|MISC_REG_PLL_STORM_CTRL_4
value|0xa2a0
end_define

begin_comment
comment|/*  * [RW 32] reset reg#2; rite/read one = the specific block is out of reset  * write/read zero = the specific block is in reset; addr 0-wr- the write  * value will be written to the register; addr 1-set - one will be written  * to all the bits that have the value of one in the data written (bits that  * have the value of zero will not be change) ; addr 2-clear - zero will be  * written to all the bits that have the value of one in the data written  * (bits that have the value of zero will not be change); addr 3-ignore;  * read ignore from all addr except addr 00; inside order of the bits is:  * [0] rst_bmac0; [1] rst_bmac1; [2] rst_emac0; [3] rst_emac1; [4] rst_grc;  * [5] rst_mcp_n_reset_reg_hard_core; [6] rst_ mcp_n_hard_core_rst_b; [7]  * rst_ mcp_n_reset_cmn_cpu; [8] rst_ mcp_n_reset_cmn_core; [9] rst_rbcn;  * [10] rst_dbg; [11] rst_misc_core; [12] rst_dbue (UART); [13]  * Pci_resetmdio_n; [14] rst_emac0_hard_core; [15] rst_emac1_hard_core; 16]  * rst_pxp_rq_rd_wr; 31:17] reserved  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_RESET_REG_2
value|0xa590
end_define

begin_comment
comment|/*  * [RW 20] 20 bit GRC address where the scratch-pad of the MCP that i  * shared with the driver resides  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SHARED_MEM_ADDR
value|0xa2b4
end_define

begin_comment
comment|/*  * [RW 32] SPIO. [31-24] FLOAT When any of these bits is written as a '1'  * the corresponding SPIO bit will turn off it's drivers and become an  * input. This is the reset state of all SPIO pins. The read value of these  * bits will be a '1' if that last command (#SET; #CL; or #FLOAT) for this  * bit was a #FLOAT. (reset value 0xff). [23-16] CLR When any of these bits  * is written as a '1'; the corresponding SPIO bit will drive low. The read  * value of these bits will be a '1' if that last command (#SET; #CLR; or  * #FLOAT) for this bit was a #CLR. (reset value 0). [15-8] SET When any of  * these bits is written as a '1'; the corresponding SPIO bit will drive  * high (if it has that capability). The read value of these bits will be a  * '1' if that last command (#SET; #CLR; or #FLOAT) for this bit was a #SET.  * (reset value 0). [7-0] VALUE RO; These bits indicate the read value of  * each of the eight SPIO pins. This is the result value of the pin; not the  * drive value. Writing these bits will have not effect. Each 8 bits field  * is divided as follows: [0] VAUX Enable; when pulsed low; enables supply  * from VAUX. (This is an output pin only; the FLOAT field is not applicable  * for this pin); [1] VAUX Disable; when pulsed low; disables supply form  * VAUX. (This is an output pin only; FLOAT field is not applicable for this  * pin); [2] SEL_VAUX_B - Control to power switching logic. Drive low to  * select VAUX supply. (This is an output pin only; it is not controlled by  * the SET and CLR fields; it is controlled by the Main Power SM; the FLOAT  * field is not applicable for this pin; only the VALUE fields is relevant -  * it reflects the output value); [3] port swap [4] spio_4; [5] spio_5; [6]  * Bit 0 of UMP device ID select; read by UMP firmware; [7] Bit 1 of UMP  * device ID select; read by UMP firmware.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SPIO
value|0xa4fc
end_define

begin_comment
comment|/*  * [RW 8] These bits enable the SPIO_INTs to signals event to the IGU/MC  * according to the following map: [3:0] reserved; [4] spio_4 [5] spio_5;  * [7:0] reserved  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SPIO_EVENT_EN
value|0xa2b8
end_define

begin_comment
comment|/*  * [RW 32] SPIO INT. [31-24] OLD_CLR Writing a '1' to these bit clears th  * corresponding bit in the #OLD_VALUE register. This will acknowledge an  * interrupt on the falling edge of corresponding SPIO input (reset value  * 0). [23-16] OLD_SET Writing a '1' to these bit sets the corresponding bit  * in the #OLD_VALUE register. This will acknowledge an interrupt on the  * rising edge of corresponding SPIO input (reset value 0). [15-8] OLD_VALUE  * RO; These bits indicate the old value of the SPIO input value. When the  * ~INT_STATE bit is set; this bit indicates the OLD value of the pin such  * that if ~INT_STATE is set and this bit is '0'; then the interrupt is due  * to a low to high edge. If ~INT_STATE is set and this bit is '1'; then the  * interrupt is due to a high to low edge (reset value 0). [7-0] INT_STATE  * RO; These bits indicate the current SPIO interrupt state for each SPIO  * pin. This bit is cleared when the appropriate #OLD_SET or #OLD_CLR  * command bit is written. This bit is set when the SPIO input does not  * match the current value in #OLD_VALUE (reset value 0).  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SPIO_INT
value|0xa500
end_define

begin_comment
comment|/*  * [RW 32] reload value for counter 4 if reload; the value will be reload i  * the counter reached zero and the reload bit  * (~misc_registers_sw_timer_cfg_4.sw_timer_cfg_4[1] ) is set.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SW_TIMER_RELOAD_VAL_4
value|0xa2fc
end_define

begin_comment
comment|/*  * [RW 32] the value of the counter for sw timers1-8. there are 8 addresse  * in this register. addres 0 - timer 1; address - timer 2ï¿½address 7 -  * timer 8.  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_SW_TIMER_VAL
value|0xa5c0
end_define

begin_comment
comment|/*  * [RW 1] Set by the MCP to remember if one or more of the drivers is/ar  * loaded; 0-prepare; -unprepare  */
end_comment

begin_define
define|#
directive|define
name|MISC_REG_UNPREPARED
value|0xa424
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_BRB1_DRV_MASK_REG_LLH0_BRB1_DRV_MASK_BRCST
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_BRB1_DRV_MASK_REG_LLH0_BRB1_DRV_MASK_MLCST
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_BRB1_DRV_MASK_REG_LLH0_BRB1_DRV_MASK_NO_VLAN
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_BRB1_DRV_MASK_REG_LLH0_BRB1_DRV_MASK_UNCST
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_BRB1_DRV_MASK_REG_LLH0_BRB1_DRV_MASK_VLAN
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_EMAC0_MISC_MI_INT
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_SERDES0_LINK_STATUS
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK10G
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK_STATUS
value|(0xf<<18)
end_define

begin_comment
comment|/* [RW 1] Input enable for RX_BMAC0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_IN_EN
value|0x100ac
end_define

begin_comment
comment|/* [RW 1] output enable for TX_BMAC0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_OUT_EN
value|0x100e0
end_define

begin_comment
comment|/* [RW 1] output enable for TX BMAC pause port 0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_PAUSE_OUT_EN
value|0x10110
end_define

begin_comment
comment|/* [RW 1] output enable for RX_BMAC0_REGS IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_REGS_OUT_EN
value|0x100e8
end_define

begin_comment
comment|/* [RW 1] output enable for RX BRB1 port0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BRB0_OUT_EN
value|0x100f8
end_define

begin_comment
comment|/* [RW 1] Input enable for TX BRB1 pause port 0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BRB0_PAUSE_IN_EN
value|0x100c4
end_define

begin_comment
comment|/* [RW 1] output enable for RX BRB1 port1 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BRB1_OUT_EN
value|0x100fc
end_define

begin_comment
comment|/* [RW 1] Input enable for TX BRB1 pause port 1 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BRB1_PAUSE_IN_EN
value|0x100c8
end_define

begin_comment
comment|/* [RW 1] output enable for RX BRB1 LP IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_BRB_LB_OUT_EN
value|0x10100
end_define

begin_comment
comment|/*  * [WB_W 82] Debug packet to LP from RBC; Data spelling:[63:0] data; 64  * error; [67:65]eop_bvalid; [68]eop; [69]sop; [70]port_id; 71]flush;  * 72:73]-vnic_num; 81:74]-sideband_info  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_DEBUG_PACKET_LB
value|0x10800
end_define

begin_comment
comment|/* [RW 1] Input enable for TX Debug packet */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_DEBUG_IN_EN
value|0x100dc
end_define

begin_comment
comment|/*  * [RW 1] If 1 - egress drain mode for port0 is active. In this mode al  * packets from PBFare not forwarded to the MAC and just deleted from FIFO.  * First packet may be deleted from the middle. And last packet will be  * always deleted till the end.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_DRAIN0_MODE
value|0x10060
end_define

begin_comment
comment|/* [RW 1] Output enable to EMAC0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_EMAC0_OUT_EN
value|0x10120
end_define

begin_comment
comment|/*  * [RW 1] MAC configuration for packets of port0. If 1 - all packet output  * to emac for port0; other way to bmac for port0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_EMAC0_PORT
value|0x10058
end_define

begin_comment
comment|/* [RW 1] Input enable for TX PBF user packet port0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_PBF0_IN_EN
value|0x100cc
end_define

begin_comment
comment|/* [RW 1] Input enable for TX PBF user packet port1 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_PBF1_IN_EN
value|0x100d0
end_define

begin_comment
comment|/* [RW 1] Input enable for TX UMP management packet port0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_UMP0_IN_EN
value|0x100d4
end_define

begin_comment
comment|/* [RW 1] Input enable for RX_EMAC0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_IN_EN
value|0x100a4
end_define

begin_comment
comment|/* [RW 1] output enable for TX EMAC pause port 0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_PAUSE_OUT_EN
value|0x10118
end_define

begin_comment
comment|/*  * [R 1] status from emac0. This bit is set when MDINT from either th  * EXT_MDINT pin or from the Copper PHY is driven low. This condition must  * be cleared in the attached PHY device that is driving the MINT pin.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_STATUS_MISC_MI_INT
value|0x10494
end_define

begin_comment
comment|/*  * [WB 48] This address space contains BMAC0 registers. The BMAC register  * are described in appendix A. In order to access the BMAC0 registers; the  * base address; NIG_REGISTERS_INGRESS_BMAC0_MEM; Offset: 0x10c00; should be  * added to each BMAC register offset  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_BMAC0_MEM
value|0x10c00
end_define

begin_comment
comment|/*  * [WB 48] This address space contains BMAC1 registers. The BMAC register  * are described in appendix A. In order to access the BMAC0 registers; the  * base address; NIG_REGISTERS_INGRESS_BMAC1_MEM; Offset: 0x11000; should be  * added to each BMAC register offset  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_BMAC1_MEM
value|0x11000
end_define

begin_comment
comment|/* [R 1] FIFO empty in EOP descriptor FIFO of LP in NIG_RX_EOP */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_EOP_LB_EMPTY
value|0x104e0
end_define

begin_comment
comment|/*  * [RW 17] Debug only. RX_EOP_DSCR_lb_FIFO in NIG_RX_EOP. Dat  * packet_length[13:0]; mac_error[14]; trunc_error[15]; parity[16]  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_EOP_LB_FIFO
value|0x104e4
end_define

begin_comment
comment|/*  * [RW 27] 0 - must be active for Everest A0; 1- for Everest B0 when latc  * logic for interrupts must be used. Enable per bit of interrupt of  * ~latch_status.latch_status  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LATCH_BC_0
value|0x16210
end_define

begin_comment
comment|/*  * [RW 27] Latch for each interrupt from Unicore.b[0  * status_emac0_misc_mi_int; b[1] status_emac0_misc_mi_complete;  * b[2]status_emac0_misc_cfg_change; b[3]status_emac0_misc_link_status;  * b[4]status_emac0_misc_link_change; b[5]status_emac0_misc_attn;  * b[6]status_serdes0_mac_crs; b[7]status_serdes0_autoneg_complete;  * b[8]status_serdes0_fiber_rxact; b[9]status_serdes0_link_status;  * b[10]status_serdes0_mr_page_rx; b[11]status_serdes0_cl73_an_complete;  * b[12]status_serdes0_cl73_mr_page_rx; b[13]status_serdes0_rx_sigdet;  * b[14]status_xgxs0_remotemdioreq; b[15]status_xgxs0_link10g;  * b[16]status_xgxs0_autoneg_complete; b[17]status_xgxs0_fiber_rxact;  * b[21:18]status_xgxs0_link_status; b[22]status_xgxs0_mr_page_rx;  * b[23]status_xgxs0_cl73_an_complete; b[24]status_xgxs0_cl73_mr_page_rx;  * b[25]status_xgxs0_rx_sigdet; b[26]status_xgxs0_mac_crs  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LATCH_STATUS_0
value|0x18000
end_define

begin_comment
comment|/* [RW 1] led 10g for port 0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_10G_P0
value|0x10320
end_define

begin_comment
comment|/* [RW 1] led 10g for port 1 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_10G_P1
value|0x10324
end_define

begin_comment
comment|/*  * [RW 1] Port0: This bit is set to enable the use of th  * ~nig_registers_led_control_blink_rate_p0.led_control_blink_rate_p0 field  * defined below. If this bit is cleared; then the blink rate will be about  * 8Hz.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_RATE_ENA_P0
value|0x10318
end_define

begin_comment
comment|/*  * [RW 12] Port0: Specifies the period of each blink cycle (on + off) fo  * Traffic LED in milliseconds. Must be a non-zero value. This 12-bit field  * is reset to 0x080; giving a default blink period of approximately 8Hz.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_RATE_P0
value|0x10310
end_define

begin_comment
comment|/*  * [RW 1] Port0: If set along with th  * ~nig_registers_led_control_override_traffic_p0.led_control_override_traffic_p0  * bit and ~nig_registers_led_control_traffic_p0.led_control_traffic_p0 LED  * bit; the Traffic LED will blink with the blink rate specified in  * ~nig_registers_led_control_blink_rate_p0.led_control_blink_rate_p0 and  * ~nig_registers_led_control_blink_rate_ena_p0.led_control_blink_rate_ena_p0  * fields.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_TRAFFIC_P0
value|0x10308
end_define

begin_comment
comment|/*  * [RW 1] Port0: If set overrides hardware control of the Traffic LED. Th  * Traffic LED will then be controlled via bit ~nig_registers_  * led_control_traffic_p0.led_control_traffic_p0 and bit  * ~nig_registers_led_control_blink_traffic_p0.led_control_blink_traffic_p0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_OVERRIDE_TRAFFIC_P0
value|0x102f8
end_define

begin_comment
comment|/*  * [RW 1] Port0: If set along with the led_control_override_trafic_p0 bit  * turns on the Traffic LED. If the led_control_blink_traffic_p0 bit is also  * set; the LED will blink with blink rate specified in  * ~nig_registers_led_control_blink_rate_p0.led_control_blink_rate_p0 and  * ~nig_regsters_led_control_blink_rate_ena_p0.led_control_blink_rate_ena_p0  * fields.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_TRAFFIC_P0
value|0x10300
end_define

begin_comment
comment|/*  * [RW 4] led mode for port0: 0 MAC; 1-3 PHY1; 4 MAC2; 5-7 PHY4; 8-MAC3  * 9-11PHY7; 12 MAC4; 13-15 PHY10;  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LED_MODE_P0
value|0x102f0
end_define

begin_comment
comment|/*  * [RW 3] for port0 enable for llfc ppp and pause. b0 - brb1 enable; b1  * tsdm enable; b2- usdm enable  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLFC_EGRESS_SRC_ENABLE_0
value|0x16070
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_EGRESS_SRC_ENABLE_1
value|0x16074
end_define

begin_comment
comment|/*  * [RW 1] SAFC enable for port0. This register may get 1 only whe  * ~ppp_enable.ppp_enable = 0 and pause_enable.pause_enable =0 for the same  * port  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLFC_ENABLE_0
value|0x16208
end_define

begin_comment
comment|/* [RW 16] classes are high-priority for port0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLFC_HIGH_PRIORITY_CLASSES_0
value|0x16058
end_define

begin_comment
comment|/* [RW 16] classes are low-priority for port0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLFC_LOW_PRIORITY_CLASSES_0
value|0x16060
end_define

begin_comment
comment|/* [RW 1] Output enable of message to LLFC BMAC IF for port0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLFC_OUT_EN_0
value|0x160c8
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_ACPI_PAT_0_CRC
value|0x1015c
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_ACPI_PAT_6_LEN
value|0x10154
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_DRV_MASK
value|0x10244
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_DRV_MASK_MF
value|0x16048
end_define

begin_comment
comment|/* [RW 1] send to BRB1 if no match on any of RMP rules. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_NOT_MCP
value|0x1025c
end_define

begin_comment
comment|/*  * [RW 2] Determine the classification participants. 0: no classification.1  * classification upon VLAN id. 2: classification upon MAC address. 3:  * classification upon both VLAN id& MAC addr.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_CLS_TYPE
value|0x16080
end_define

begin_comment
comment|/* [RW 32] cm header for llh0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_CM_HEADER
value|0x1007c
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_DEST_IP_0_1
value|0x101dc
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_DEST_MAC_0_0
value|0x101c0
end_define

begin_comment
comment|/*  * [RW 16] destination TCP address 1. The LLH will look for this address i  * all incoming packets.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_DEST_TCP_0
value|0x10220
end_define

begin_comment
comment|/*  * [RW 16] destination UDP address 1 The LLH will look for this address i  * all incoming packets.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_DEST_UDP_0
value|0x10214
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_ERROR_MASK
value|0x1008c
end_define

begin_comment
comment|/* [RW 8] event id for llh0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_EVENT_ID
value|0x10084
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_EN
value|0x160fc
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_VLAN_ID
value|0x16100
end_define

begin_comment
comment|/*  * [RW 1] Determine the IP version to look for i  * ~nig_registers_llh0_dest_ip_0.llh0_dest_ip_0. 0 - IPv6; 1-IPv4  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_IPV4_IPV6_0
value|0x10208
end_define

begin_comment
comment|/* [RW 1] t bit for llh0 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_T_BIT
value|0x10074
end_define

begin_comment
comment|/* [RW 12] VLAN ID 1. In case of VLAN packet the LLH will look for this ID. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_VLAN_ID_0
value|0x1022c
end_define

begin_comment
comment|/* [RW 8] init credit counter for port0 in LLH */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH0_XCM_INIT_CREDIT
value|0x10554
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_XCM_MASK
value|0x10130
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_BRB1_DRV_MASK
value|0x10248
end_define

begin_comment
comment|/* [RW 1] send to BRB1 if no match on any of RMP rules. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH1_BRB1_NOT_MCP
value|0x102dc
end_define

begin_comment
comment|/*  * [RW 2] Determine the classification participants. 0: no classification.1  * classification upon VLAN id. 2: classification upon MAC address. 3:  * classification upon both VLAN id& MAC addr.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH1_CLS_TYPE
value|0x16084
end_define

begin_comment
comment|/* [RW 32] cm header for llh1 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH1_CM_HEADER
value|0x10080
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_ERROR_MASK
value|0x10090
end_define

begin_comment
comment|/* [RW 8] event id for llh1 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH1_EVENT_ID
value|0x10088
end_define

begin_comment
comment|/* [RW 8] init credit counter for port1 in LLH */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH1_XCM_INIT_CREDIT
value|0x10564
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_XCM_MASK
value|0x10134
end_define

begin_comment
comment|/*  * [RW 1] When this bit is set; the LLH will expect all packets to be wit  * e1hov  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH_E1HOV_MODE
value|0x160d8
end_define

begin_comment
comment|/*  * [RW 1] When this bit is set; the LLH will classify the packet befor  * sending it to the BRB or calculating WoL on it.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_LLH_MF_MODE
value|0x16024
end_define

begin_define
define|#
directive|define
name|NIG_REG_MASK_INTERRUPT_PORT0
value|0x10330
end_define

begin_define
define|#
directive|define
name|NIG_REG_MASK_INTERRUPT_PORT1
value|0x10334
end_define

begin_comment
comment|/* [RW 1] Output signal from NIG to EMAC0. When set enables the EMAC0 block. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_NIG_EMAC0_EN
value|0x1003c
end_define

begin_comment
comment|/* [RW 1] Output signal from NIG to EMAC1. When set enables the EMAC1 block. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_NIG_EMAC1_EN
value|0x10040
end_define

begin_comment
comment|/*  * [RW 1] Output signal from NIG to TX_EMAC0. When set indicates to th  * EMAC0 to strip the CRC from the ingress packets.  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_NIG_INGRESS_EMAC0_NO_CRC
value|0x10044
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_NIG_INT_STS_0
value|0x103b0
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_INT_STS_1
value|0x103c0
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_STS
value|0x103d0
end_define

begin_comment
comment|/*  * [RW 1] Pause enable for port0. This register may get 1 only whe  * ~safc_enable.safc_enable = 0 and ppp_enable.ppp_enable =0 for the same  * port  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_PAUSE_ENABLE_0
value|0x160c0
end_define

begin_comment
comment|/* [RW 1] Input enable for RX PBF LP IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_PBF_LB_IN_EN
value|0x100b4
end_define

begin_comment
comment|/*  * [RW 1] Value of this register will be transmitted to port swap whe  * ~nig_registers_strap_override.strap_override =1  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_PORT_SWAP
value|0x10394
end_define

begin_comment
comment|/* [RW 1] output enable for RX parser descriptor IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_PRS_EOP_OUT_EN
value|0x10104
end_define

begin_comment
comment|/* [RW 1] Input enable for RX parser request IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_PRS_REQ_IN_EN
value|0x100b8
end_define

begin_comment
comment|/* [RW 5] control to serdes - CL45 DEVAD */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_MD_DEVAD
value|0x10370
end_define

begin_comment
comment|/* [RW 1] control to serdes; 0 - clause 45; 1 - clause 22 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_MD_ST
value|0x1036c
end_define

begin_comment
comment|/* [RW 5] control to serdes - CL22 PHY_ADD and CL45 PRTAD */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_PHY_ADDR
value|0x10374
end_define

begin_comment
comment|/* [R 1] status from serdes0 that inputs to interrupt logic of link status */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_STATUS_LINK_STATUS
value|0x10578
end_define

begin_comment
comment|/*  * [R 32] Rx statistics : In user packets discarded due to BRB backpressur  * for port0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT0_BRB_DISCARD
value|0x105f0
end_define

begin_comment
comment|/*  * [R 32] Rx statistics : In user packets truncated due to BRB backpressur  * for port0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT0_BRB_TRUNCATE
value|0x105f8
end_define

begin_comment
comment|/*  * [WB_R 36] Tx statistics : Number of packets from emac0 or bmac0 tha  * between 1024 and 1522 bytes for port0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT0_EGRESS_MAC_PKT0
value|0x10750
end_define

begin_comment
comment|/*  * [WB_R 36] Tx statistics : Number of packets from emac0 or bmac0 tha  * between 1523 bytes and above for port0  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT0_EGRESS_MAC_PKT1
value|0x10760
end_define

begin_comment
comment|/*  * [R 32] Rx statistics : In user packets discarded due to BRB backpressur  * for port1  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT1_BRB_DISCARD
value|0x10628
end_define

begin_comment
comment|/*  * [WB_R 36] Tx statistics : Number of packets from emac1 or bmac1 tha  * between 1024 and 1522 bytes for port1  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT1_EGRESS_MAC_PKT0
value|0x107a0
end_define

begin_comment
comment|/*  * [WB_R 36] Tx statistics : Number of packets from emac1 or bmac1 tha  * between 1523 bytes and above for port1  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT1_EGRESS_MAC_PKT1
value|0x107b0
end_define

begin_comment
comment|/* [WB_R 64] Rx statistics : User octets received for LP */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STAT2_BRB_OCTET
value|0x107e0
end_define

begin_define
define|#
directive|define
name|NIG_REG_STATUS_INTERRUPT_PORT0
value|0x10328
end_define

begin_define
define|#
directive|define
name|NIG_REG_STATUS_INTERRUPT_PORT1
value|0x1032c
end_define

begin_comment
comment|/*  * [RW 1] port swap mux selection. If this register equal to 0 then por  * swap is equal to SPIO pin that inputs from ifmux_serdes_swap. If 1 then  * ort swap is equal to ~nig_registers_port_swap.port_swap  */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_STRAP_OVERRIDE
value|0x10398
end_define

begin_comment
comment|/* [RW 1] output enable for RX_XCM0 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XCM0_OUT_EN
value|0x100f0
end_define

begin_comment
comment|/* [RW 1] output enable for RX_XCM1 IF */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XCM1_OUT_EN
value|0x100f4
end_define

begin_comment
comment|/* [RW 1] control to xgxs - remote PHY in-band MDIO */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_EXTREMOTEMDIOST
value|0x10348
end_define

begin_comment
comment|/* [RW 5] control to xgxs - CL45 DEVAD */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_MD_DEVAD
value|0x1033c
end_define

begin_comment
comment|/* [RW 1] control to xgxs; 0 - clause 45; 1 - clause 22 */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_MD_ST
value|0x10338
end_define

begin_comment
comment|/* [RW 5] control to xgxs - CL22 PHY_ADD and CL45 PRTAD */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_PHY_ADDR
value|0x10340
end_define

begin_comment
comment|/* [R 1] status from xgxs0 that inputs to interrupt logic of link10g. */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_STATUS_LINK10G
value|0x10680
end_define

begin_comment
comment|/* [R 4] status from xgxs0 that inputs to interrupt logic of link status */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_STATUS_LINK_STATUS
value|0x10684
end_define

begin_comment
comment|/* [RW 2] selection for XGXS lane of port 0 in NIG_MUX block */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS_LANE_SEL_P0
value|0x102e8
end_define

begin_comment
comment|/* [RW 1] selection for port0 for NIG_MUX block : 0 = SerDes; 1 = XGXS */
end_comment

begin_define
define|#
directive|define
name|NIG_REG_XGXS_SERDES0_MODE_SEL
value|0x102e0
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_EMAC0_MISC_MI_INT
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_SERDES0_LINK_STATUS
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK10G
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS
value|(0xf<<18)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS_SIZE
value|18
end_define

begin_comment
comment|/*  * [RW 1] Disable processing further tasks from port 0 (after ending th  * current task in process).  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_DISABLE_NEW_TASK_PROC_P0
value|0x14005c
end_define

begin_comment
comment|/*  * [RW 1] Disable processing further tasks from port 1 (after ending th  * current task in process).  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_DISABLE_NEW_TASK_PROC_P1
value|0x140060
end_define

begin_comment
comment|/*  * [RW 1] Disable processing further tasks from port 4 (after ending th  * current task in process).  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_DISABLE_NEW_TASK_PROC_P4
value|0x14006c
end_define

begin_define
define|#
directive|define
name|PBF_REG_IF_ENABLE_REG
value|0x140044
end_define

begin_comment
comment|/*  * [RW 1] Init bit. When set the initial credits are copied to the credi  * registers (except the port credits). Should be set and then reset after  * the configuration of the block has ended.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_INIT
value|0x140000
end_define

begin_comment
comment|/*  * [RW 1] Init bit for port 0. When set the initial credit of port 0 i  * copied to the credit register. Should be set and then reset after the  * configuration of the port has ended.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_INIT_P0
value|0x140004
end_define

begin_comment
comment|/*  * [RW 1] Init bit for port 1. When set the initial credit of port 1 i  * copied to the credit register. Should be set and then reset after the  * configuration of the port has ended.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_INIT_P1
value|0x140008
end_define

begin_comment
comment|/*  * [RW 1] Init bit for port 4. When set the initial credit of port 4 i  * copied to the credit register. Should be set and then reset after the  * configuration of the port has ended.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_INIT_P4
value|0x14000c
end_define

begin_comment
comment|/* [RW 1] Enable for mac interface 0. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_MAC_IF0_ENABLE
value|0x140030
end_define

begin_comment
comment|/* [RW 1] Enable for mac interface 1. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_MAC_IF1_ENABLE
value|0x140034
end_define

begin_comment
comment|/* [RW 1] Enable for the loopback interface. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_MAC_LB_ENABLE
value|0x140040
end_define

begin_comment
comment|/*  * [RW 10] Port 0 threshold used by arbiter in 16 byte lines used when paus  * not suppoterd.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P0_ARB_THRSH
value|0x1400e4
end_define

begin_comment
comment|/* [R 11] Current credit for port 0 in the tx port buffers in 16 byte lines. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P0_CREDIT
value|0x140200
end_define

begin_comment
comment|/*  * [RW 11] Initial credit for port 0 in the tx port buffers in 16 byt  * lines.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P0_INIT_CRD
value|0x1400d0
end_define

begin_comment
comment|/* [RW 1] Indication that pause is enabled for port 0. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P0_PAUSE_ENABLE
value|0x140014
end_define

begin_comment
comment|/* [R 8] Number of tasks in port 0 task queue. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P0_TASK_CNT
value|0x140204
end_define

begin_comment
comment|/* [R 11] Current credit for port 1 in the tx port buffers in 16 byte lines. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P1_CREDIT
value|0x140208
end_define

begin_comment
comment|/*  * [RW 11] Initial credit for port 1 in the tx port buffers in 16 byt  * lines.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P1_INIT_CRD
value|0x1400d4
end_define

begin_comment
comment|/* [R 8] Number of tasks in port 1 task queue. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P1_TASK_CNT
value|0x14020c
end_define

begin_comment
comment|/* [R 11] Current credit for port 4 in the tx port buffers in 16 byte lines. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P4_CREDIT
value|0x140210
end_define

begin_comment
comment|/*  * [RW 11] Initial credit for port 4 in the tx port buffers in 16 byt  * lines.  */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P4_INIT_CRD
value|0x1400e0
end_define

begin_comment
comment|/* [R 8] Number of tasks in port 4 task queue. */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_P4_TASK_CNT
value|0x140214
end_define

begin_comment
comment|/* [RW 5] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_PBF_INT_MASK
value|0x1401d4
end_define

begin_comment
comment|/* [R 5] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|PBF_REG_PBF_INT_STS
value|0x1401c8
end_define

begin_define
define|#
directive|define
name|PB_REG_CONTROL
value|0
end_define

begin_comment
comment|/* [RW 2] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PB_REG_PB_INT_MASK
value|0x28
end_define

begin_comment
comment|/* [R 2] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|PB_REG_PB_INT_STS
value|0x1c
end_define

begin_comment
comment|/* [RW 4] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PB_REG_PB_PRTY_MASK
value|0x38
end_define

begin_comment
comment|/* [R 4] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|PB_REG_PB_PRTY_STS
value|0x2c
end_define

begin_define
define|#
directive|define
name|PRS_REG_A_PRSU_20
value|0x40134
end_define

begin_comment
comment|/* [R 8] debug only: CFC load request current credit. Transaction based. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CFC_LD_CURRENT_CREDIT
value|0x40164
end_define

begin_comment
comment|/* [R 8] debug only: CFC search request current credit. Transaction based. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CFC_SEARCH_CURRENT_CREDIT
value|0x40168
end_define

begin_comment
comment|/*  * [RW 6] The initial credit for the search message to the CFC interface  * Credit is transaction based.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CFC_SEARCH_INITIAL_CREDIT
value|0x4011c
end_define

begin_comment
comment|/* [RW 24] CID for port 0 if no match */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CID_PORT_0
value|0x400fc
end_define

begin_comment
comment|/*  * [RW 32] The CM header for flush message where 'load existed' bit in CF  * load response is reset and packet type is 0. Used in packet start message  * to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_0
value|0x400dc
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_1
value|0x400e0
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_2
value|0x400e4
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_3
value|0x400e8
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_4
value|0x400ec
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_LOAD_TYPE_5
value|0x400f0
end_define

begin_comment
comment|/*  * [RW 32] The CM header for flush message where 'load existed' bit in CF  * load response is set and packet type is 0. Used in packet start message  * to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_0
value|0x400bc
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_1
value|0x400c0
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_2
value|0x400c4
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_3
value|0x400c8
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_4
value|0x400cc
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_FLUSH_NO_LOAD_TYPE_5
value|0x400d0
end_define

begin_comment
comment|/*  * [RW 32] The CM header for a match and packet type 1 for loopback port  * Used in packet start message to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_LOOPBACK_TYPE_1
value|0x4009c
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_LOOPBACK_TYPE_2
value|0x400a0
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_LOOPBACK_TYPE_3
value|0x400a4
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_LOOPBACK_TYPE_4
value|0x400a8
end_define

begin_comment
comment|/*  * [RW 32] The CM header for a match and packet type 0. Used in packet star  * message to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_TYPE_0
value|0x40078
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_TYPE_1
value|0x4007c
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_TYPE_2
value|0x40080
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_TYPE_3
value|0x40084
end_define

begin_define
define|#
directive|define
name|PRS_REG_CM_HDR_TYPE_4
value|0x40088
end_define

begin_comment
comment|/* [RW 32] The CM header in case there was not a match on the connection */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_CM_NO_MATCH_HDR
value|0x400b8
end_define

begin_comment
comment|/* [RW 1] Indicates if in e1hov mode. 0=non-e1hov mode; 1=e1hov mode. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_E1HOV_MODE
value|0x401c8
end_define

begin_comment
comment|/*  * [RW 8] The 8-bit event ID for a match and packet type 1. Used in packe  * start message to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_EVENT_ID_1
value|0x40054
end_define

begin_define
define|#
directive|define
name|PRS_REG_EVENT_ID_2
value|0x40058
end_define

begin_define
define|#
directive|define
name|PRS_REG_EVENT_ID_3
value|0x4005c
end_define

begin_comment
comment|/* [RW 16] The Ethernet type value for FCoE */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_FCOE_TYPE
value|0x401d0
end_define

begin_comment
comment|/*  * [RW 8] Context region for flush packet with packet type 0. Used in CF  * load request message.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_0
value|0x40004
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_1
value|0x40008
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_2
value|0x4000c
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_3
value|0x40010
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_4
value|0x40014
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_5
value|0x40018
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_6
value|0x4001c
end_define

begin_define
define|#
directive|define
name|PRS_REG_FLUSH_REGIONS_TYPE_7
value|0x40020
end_define

begin_comment
comment|/* [RW 4] The increment value to send in the CFC load request message */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_INC_VALUE
value|0x40048
end_define

begin_comment
comment|/* [RW 1] If set indicates not to send messages to CFC on received packets */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NIC_MODE
value|0x40138
end_define

begin_comment
comment|/*  * [RW 8] The 8-bit event ID for cases where there is no match on th  * connection. Used in packet start message to TCM.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NO_MATCH_EVENT_ID
value|0x40070
end_define

begin_comment
comment|/* [ST 24] The number of input CFC flush packets */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NUM_OF_CFC_FLUSH_MESSAGES
value|0x40128
end_define

begin_comment
comment|/*  * [ST 32] The number of cycles the Parser halted its operation since i  * could not allocate the next serial number  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NUM_OF_DEAD_CYCLES
value|0x40130
end_define

begin_comment
comment|/* [ST 24] The number of input packets */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NUM_OF_PACKETS
value|0x40124
end_define

begin_comment
comment|/* [ST 24] The number of input transparent flush packets */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_NUM_OF_TRANSPARENT_FLUSH_MESSAGES
value|0x4012c
end_define

begin_comment
comment|/*  * [RW 8] Context region for received Ethernet packet with a match an  * packet type 0. Used in CFC load request message  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_0
value|0x40028
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_1
value|0x4002c
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_2
value|0x40030
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_3
value|0x40034
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_4
value|0x40038
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_5
value|0x4003c
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_6
value|0x40040
end_define

begin_define
define|#
directive|define
name|PRS_REG_PACKET_REGIONS_TYPE_7
value|0x40044
end_define

begin_comment
comment|/* [R 2] debug only: Number of pending requests for CAC on port 0. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PENDING_BRB_CAC0_RQ
value|0x40174
end_define

begin_comment
comment|/* [R 2] debug only: Number of pending requests for header parsing. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PENDING_BRB_PRS_RQ
value|0x40170
end_define

begin_comment
comment|/* [R 1] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PRS_INT_STS
value|0x40188
end_define

begin_comment
comment|/* [RW 8] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PRS_PRTY_MASK
value|0x401a4
end_define

begin_comment
comment|/* [R 8] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PRS_PRTY_STS
value|0x40198
end_define

begin_comment
comment|/*  * [RW 8] Context region for pure acknowledge packets. Used in CFC loa  * request message  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_PURE_REGIONS
value|0x40024
end_define

begin_comment
comment|/*  * [R 32] debug only: Serial number status lsb 32 bits. '1' indicates thi  * serail number was released by SDM but cannot be used because a previous  * serial number was not released.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_SERIAL_NUM_STATUS_LSB
value|0x40154
end_define

begin_comment
comment|/*  * [R 32] debug only: Serial number status msb 32 bits. '1' indicates thi  * serail number was released by SDM but cannot be used because a previous  * serial number was not released.  */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_SERIAL_NUM_STATUS_MSB
value|0x40158
end_define

begin_comment
comment|/* [R 4] debug only: SRC current credit. Transaction based. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_SRC_CURRENT_CREDIT
value|0x4016c
end_define

begin_comment
comment|/* [R 8] debug only: TCM current credit. Cycle based. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_TCM_CURRENT_CREDIT
value|0x40160
end_define

begin_comment
comment|/* [R 8] debug only: TSDM current credit. Transaction based. */
end_comment

begin_define
define|#
directive|define
name|PRS_REG_TSDM_CURRENT_CREDIT
value|0x4015c
end_define

begin_comment
comment|/* [R 6] Debug only: Number of used entries in the data FIFO */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_HST_DATA_FIFO_STATUS
value|0x12047c
end_define

begin_comment
comment|/* [R 7] Debug only: Number of used entries in the header FIFO */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_HST_HEADER_FIFO_STATUS
value|0x120478
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_88_F0
value|0x120534
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_8C_F0
value|0x120538
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_90_F0
value|0x12053c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_94_F0
value|0x120540
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_CONTROL0
value|0x120490
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_CONTROL1
value|0x120514
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_DEBUG
value|0x120520
end_define

begin_comment
comment|/*  * [RW 32] third dword data of expansion rom request. this register i  * special. reading from it provides a vector outstanding read requests. if  * a bit is zero it means that a read request on the corresponding tag did  * not finish yet (not all completions have arrived for it)  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_EXP_ROM2
value|0x120808
end_define

begin_comment
comment|/*  * [RW 32] Inbound interrupt table for CSDM: bits[31:16]-mask  * its[15:0]-address  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_0
value|0x1204f4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_1
value|0x1204f8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_2
value|0x1204fc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_3
value|0x120500
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_4
value|0x120504
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_5
value|0x120508
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_6
value|0x12050c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_CSDM_7
value|0x120510
end_define

begin_comment
comment|/*  * [RW 32] Inbound interrupt table for TSDM: bits[31:16]-mask  * its[15:0]-address  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_0
value|0x120494
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_1
value|0x120498
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_2
value|0x12049c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_3
value|0x1204a0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_4
value|0x1204a4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_5
value|0x1204a8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_6
value|0x1204ac
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_TSDM_7
value|0x1204b0
end_define

begin_comment
comment|/*  * [RW 32] Inbound interrupt table for USDM: bits[31:16]-mask  * its[15:0]-address  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_0
value|0x1204b4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_1
value|0x1204b8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_2
value|0x1204bc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_3
value|0x1204c0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_4
value|0x1204c4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_5
value|0x1204c8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_6
value|0x1204cc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_USDM_7
value|0x1204d0
end_define

begin_comment
comment|/*  * [RW 32] Inbound interrupt table for XSDM: bits[31:16]-mask  * its[15:0]-address  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_0
value|0x1204d4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_1
value|0x1204d8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_2
value|0x1204dc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_3
value|0x1204e0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_4
value|0x1204e4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_5
value|0x1204e8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_6
value|0x1204ec
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_INT_XSDM_7
value|0x1204f0
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F0
value|0x120674
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F1
value|0x120678
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F2
value|0x12067c
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F3
value|0x120680
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F4
value|0x120684
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F5
value|0x120688
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F6
value|0x12068c
end_define

begin_comment
comment|/*  * [RW 3] this field allows one function to pretend being another functio  * when accessing any BAR mapped resource within the device. the value of  * the field is the number of the function that will be accessed  * effectively. after software write to this bit it must read it in order to  * know that the new value is updated.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F7
value|0x120690
end_define

begin_comment
comment|/*  * [R 1] this bit indicates that a read request was blocked because o  * bus_master_en was deasserted.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_READ_BLOCKED
value|0x120568
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_TAGS_LIMIT
value|0x1205a8
end_define

begin_comment
comment|/* [R 18] debug only */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_TXW_CDTS
value|0x12052c
end_define

begin_comment
comment|/*  * [R 1] this bit indicates that a write request was blocked because o  * bus_master_en was deasserted.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PGL_WRITE_BLOCKED
value|0x120564
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD1
value|0x1201c0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD10
value|0x1201e4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD11
value|0x1201e8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD2
value|0x1201c4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD28
value|0x120228
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD3
value|0x1201c8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD6
value|0x1201d4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD7
value|0x1201d8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD8
value|0x1201dc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD9
value|0x1201e0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_CREDIT
value|0x12032c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L1
value|0x1202b0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L10
value|0x1202d4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L11
value|0x1202d8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L2
value|0x1202b4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L28
value|0x120318
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L3
value|0x1202b8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L6
value|0x1202c4
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L7
value|0x1202c8
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L8
value|0x1202cc
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L9
value|0x1202d0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_RD
value|0x120324
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB1
value|0x120238
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB10
value|0x12025c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB11
value|0x120260
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB2
value|0x12023c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB28
value|0x1202a0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB3
value|0x120240
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB6
value|0x12024c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB7
value|0x120250
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB8
value|0x120254
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB9
value|0x120258
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_WR
value|0x120328
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_CDU0_L2P
value|0x120000
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_QM0_L2P
value|0x120038
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_SRC0_L2P
value|0x120054
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_TM0_L2P
value|0x12001c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_TSDM0_L2P
value|0x1200e0
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_MASK_0
value|0x120578
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_0
value|0x12056c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_1
value|0x120608
end_define

begin_comment
comment|/* [RC 32] Interrupt register #0 read clear */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_CLR_0
value|0x120570
end_define

begin_comment
comment|/* [RW 32] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_MASK_0
value|0x120588
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_MASK_1
value|0x120598
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_STS_0
value|0x12057c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_STS_1
value|0x12058c
end_define

begin_comment
comment|/*  * [R 1] Debug only: The 'almost full' indication from each fifo (give  * indication about backpressure)  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_ALMOST_FULL_0
value|0x120424
end_define

begin_comment
comment|/* [R 8] Debug only: The blocks counter - number of unused block ids */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_BLK_CNT
value|0x120418
end_define

begin_comment
comment|/*  * [RW 8] Debug only: Total number of available blocks in Tetris Buffer  * Must be bigger than 6. Normally should not be changed.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_BLK_NUM_CFG
value|0x12040c
end_define

begin_comment
comment|/* [RW 2] CDU byte swapping mode configuration for master read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_CDURD_SWAP_MODE
value|0x120404
end_define

begin_comment
comment|/* [RW 1] When '1'; inputs to the PSWRD block are ignored */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_DISABLE_INPUTS
value|0x120374
end_define

begin_comment
comment|/* [R 1] PSWRD internal memories initialization is done */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_INIT_DONE
value|0x120370
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq10.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ10
value|0x1203a0
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq11  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ11
value|0x1203a4
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq17  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ17
value|0x1203bc
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq18  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ18
value|0x1203c0
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq19  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ19
value|0x1203c4
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq22  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ22
value|0x1203d0
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq25  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ25
value|0x1203dc
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq6  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ6
value|0x120390
end_define

begin_comment
comment|/*  * [RW 8] The maximum number of blocks in Tetris Buffer that can b  * allocated for vq9  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_MAX_BLKS_VQ9
value|0x12039c
end_define

begin_comment
comment|/* [RW 2] PBF byte swapping mode configuration for master read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_PBF_SWAP_MODE
value|0x1203f4
end_define

begin_comment
comment|/* [R 1] Debug only: Indication if delivery ports are idle */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_PORT_IS_IDLE_0
value|0x12041c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_PORT_IS_IDLE_1
value|0x120420
end_define

begin_comment
comment|/* [RW 2] QM byte swapping mode configuration for master read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_QM_SWAP_MODE
value|0x1203f8
end_define

begin_comment
comment|/* [R 7] Debug only: The SR counter - number of unused sub request ids */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_SR_CNT
value|0x120414
end_define

begin_comment
comment|/* [RW 2] SRC byte swapping mode configuration for master read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_SRC_SWAP_MODE
value|0x120400
end_define

begin_comment
comment|/*  * [RW 7] Debug only: Total number of available PCI read sub-requests. Mus  * be bigger than 1. Normally should not be changed.  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_SR_NUM_CFG
value|0x120408
end_define

begin_comment
comment|/* [RW 1] Signals the PSWRD block to start initializing internal memories */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_START_INIT
value|0x12036c
end_define

begin_comment
comment|/* [RW 2] TM byte swapping mode configuration for master read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RD_TM_SWAP_MODE
value|0x1203fc
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ0 write requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD0
value|0x1201bc
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ12 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD12
value|0x1201ec
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ13 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD13
value|0x1201f0
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ14 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD14
value|0x1201f4
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ15 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD15
value|0x1201f8
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ16 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD16
value|0x1201fc
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ17 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD17
value|0x120200
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ18 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD18
value|0x120204
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ19 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD19
value|0x120208
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ20 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD20
value|0x12020c
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ22 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD22
value|0x120210
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ23 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD23
value|0x120214
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ24 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD24
value|0x120218
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ25 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD25
value|0x12021c
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ26 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD26
value|0x120220
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ27 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD27
value|0x120224
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ4 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD4
value|0x1201cc
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ5 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD5
value|0x1201d0
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ0 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L0
value|0x1202ac
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ12 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L12
value|0x1202dc
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ13 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L13
value|0x1202e0
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ14 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L14
value|0x1202e4
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ15 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L15
value|0x1202e8
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ16 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L16
value|0x1202ec
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ17 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L17
value|0x1202f0
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ18 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L18
value|0x1202f4
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ19 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L19
value|0x1202f8
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ20 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L20
value|0x1202fc
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ22 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L22
value|0x120300
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ23 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L23
value|0x120304
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ24 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L24
value|0x120308
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ25 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L25
value|0x12030c
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ26 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L26
value|0x120310
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ27 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L27
value|0x120314
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ4 Read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L4
value|0x1202bc
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ5 Read- currently not used */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L5
value|0x1202c0
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ0 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND0
value|0x120234
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ12 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND12
value|0x120264
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ13 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND13
value|0x120268
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ14 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND14
value|0x12026c
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ15 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND15
value|0x120270
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ16 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND16
value|0x120274
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ17 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND17
value|0x120278
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ18 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND18
value|0x12027c
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ19 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND19
value|0x120280
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ20 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND20
value|0x120284
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ22 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND22
value|0x120288
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ23 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND23
value|0x12028c
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ24 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND24
value|0x120290
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ25 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND25
value|0x120294
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ26 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND26
value|0x120298
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ27 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND27
value|0x12029c
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ4 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND4
value|0x120244
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ5 read requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND5
value|0x120248
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ29 write requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_ADD29
value|0x12022c
end_define

begin_comment
comment|/* [RW 10] Bandwidth addition to VQ30 write requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_ADD30
value|0x120230
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ29 Write requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_L29
value|0x12031c
end_define

begin_comment
comment|/* [RW 10] Bandwidth Typical L for VQ30 Write requests */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_L30
value|0x120320
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ29 */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_UBOUND29
value|0x1202a4
end_define

begin_comment
comment|/* [RW 7] Bandwidth upper bound for VQ30 */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_UBOUND30
value|0x1202a8
end_define

begin_comment
comment|/* [RW 18] external first_mem_addr field in L2P table for CDU module port 0 */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU0_EFIRST_MEM_ADDR
value|0x120008
end_define

begin_comment
comment|/* [RW 2] Endian mode for cdu */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_ENDIAN_M
value|0x1201a0
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_FIRST_ILT
value|0x12061c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_LAST_ILT
value|0x120620
end_define

begin_comment
comment|/*  * [RW 3] page size in L2P table for CDU module; -4k; -8k; -16k; -32k; -64k  * -128k  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_P_SIZE
value|0x120018
end_define

begin_comment
comment|/*  * [R 1] 1' indicates that the requester has finished its interna  * configuration  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CFG_DONE
value|0x1201b4
end_define

begin_comment
comment|/* [RW 2] Endian mode for debug */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DBG_ENDIAN_M
value|0x1201a4
end_define

begin_comment
comment|/*  * [RW 1] When '1'; requests will enter input buffers but wont get ou  * towards the glue  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DISABLE_INPUTS
value|0x120330
end_define

begin_comment
comment|/* [RW 1] 1 - SR will be aligned by 64B; 0 - SR will be aligned by 8B */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DRAM_ALIGN
value|0x1205b0
end_define

begin_comment
comment|/*  * [RW 1] If 1 ILT failiue will not result in ELT access; An interrupt wil  * be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ELT_DISABLE
value|0x12066c
end_define

begin_comment
comment|/* [RW 2] Endian mode for hc */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_HC_ENDIAN_M
value|0x1201a8
end_define

begin_comment
comment|/*  * [RW 1] when '0' ILT logic will work as in A0; otherwise B0; for bac  * compatibility needs; Note that different registers are used per mode  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ILT_MODE
value|0x1205b4
end_define

begin_comment
comment|/* [WB 53] Onchip address table */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ONCHIP_AT
value|0x122000
end_define

begin_comment
comment|/* [WB 53] Onchip address table - B0 */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ONCHIP_AT_B0
value|0x128000
end_define

begin_comment
comment|/* [RW 13] Pending read limiter threshold; in Dwords */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_PDR_LIMIT
value|0x12033c
end_define

begin_comment
comment|/* [RW 2] Endian mode for qm */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_ENDIAN_M
value|0x120194
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_FIRST_ILT
value|0x120634
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_LAST_ILT
value|0x120638
end_define

begin_comment
comment|/*  * [RW 3] page size in L2P table for QM module; -4k; -8k; -16k; -32k; -64k  * -128k  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_P_SIZE
value|0x120050
end_define

begin_comment
comment|/* [RW 1] 1' indicates that the RBC has finished configuring the PSWRQ */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RBC_DONE
value|0x1201b0
end_define

begin_comment
comment|/*  * [RW 3] Max burst size filed for read requests port 0; 000 - 128B  * 001:256B; 010: 512B; 11:1K:100:2K; 01:4K  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RD_MBS0
value|0x120160
end_define

begin_comment
comment|/*  * [RW 3] Max burst size filed for read requests port 1; 000 - 128B  * 001:256B; 010: 512B; 11:1K:100:2K; 01:4K  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RD_MBS1
value|0x120168
end_define

begin_comment
comment|/* [RW 2] Endian mode for src */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_ENDIAN_M
value|0x12019c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_FIRST_ILT
value|0x12063c
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_LAST_ILT
value|0x120640
end_define

begin_comment
comment|/*  * [RW 3] page size in L2P table for SRC module; -4k; -8k; -16k; -32k; -64k  * -128k  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_P_SIZE
value|0x12006c
end_define

begin_comment
comment|/* [RW 2] Endian mode for tm */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_ENDIAN_M
value|0x120198
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_FIRST_ILT
value|0x120644
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_LAST_ILT
value|0x120648
end_define

begin_comment
comment|/*  * [RW 3] page size in L2P table for TM module; -4k; -8k; -16k; -32k; -64k  *  -128k  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_P_SIZE
value|0x120034
end_define

begin_comment
comment|/* [R 5] Number of entries in the ufifo; his fifo has l2p completions */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_UFIFO_NUM_OF_ENTRY
value|0x12080c
end_define

begin_comment
comment|/* [RW 18] external first_mem_addr field in L2P table for USDM module port 0 */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_USDM0_EFIRST_MEM_ADDR
value|0x120094
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 0 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ0_ENTRY_CNT
value|0x120810
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 10 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ10_ENTRY_CNT
value|0x120818
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 11 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ11_ENTRY_CNT
value|0x120820
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 12 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ12_ENTRY_CNT
value|0x120828
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 13 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ13_ENTRY_CNT
value|0x120830
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 14 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ14_ENTRY_CNT
value|0x120838
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 15 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ15_ENTRY_CNT
value|0x120840
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 16 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ16_ENTRY_CNT
value|0x120848
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 17 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ17_ENTRY_CNT
value|0x120850
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 18 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ18_ENTRY_CNT
value|0x120858
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 19 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ19_ENTRY_CNT
value|0x120860
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 1 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ1_ENTRY_CNT
value|0x120868
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 20 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ20_ENTRY_CNT
value|0x120870
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 21 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ21_ENTRY_CNT
value|0x120878
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 22 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ22_ENTRY_CNT
value|0x120880
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 23 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ23_ENTRY_CNT
value|0x120888
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 24 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ24_ENTRY_CNT
value|0x120890
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 25 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ25_ENTRY_CNT
value|0x120898
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 26 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ26_ENTRY_CNT
value|0x1208a0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 27 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ27_ENTRY_CNT
value|0x1208a8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 28 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ28_ENTRY_CNT
value|0x1208b0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 29 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ29_ENTRY_CNT
value|0x1208b8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 2 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ2_ENTRY_CNT
value|0x1208c0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 30 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ30_ENTRY_CNT
value|0x1208c8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 31 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ31_ENTRY_CNT
value|0x1208d0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 3 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ3_ENTRY_CNT
value|0x1208d8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 4 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ4_ENTRY_CNT
value|0x1208e0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 5 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ5_ENTRY_CNT
value|0x1208e8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 6 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ6_ENTRY_CNT
value|0x1208f0
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 7 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ7_ENTRY_CNT
value|0x1208f8
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 8 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ8_ENTRY_CNT
value|0x120900
end_define

begin_comment
comment|/* [R 8] Number of entries occupied by vq 9 in pswrq memory */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_VQ9_ENTRY_CNT
value|0x120908
end_define

begin_comment
comment|/*  * [RW 3] Max burst size filed for write requests port 0; 000 - 128B  * 001:256B; 010: 512B;  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_WR_MBS0
value|0x12015c
end_define

begin_comment
comment|/*  * [RW 3] Max burst size filed for write requests port 1; 000 - 128B  * 001:256B; 010: 512B;  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_RQ_WR_MBS1
value|0x120164
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_CDU_MPS
value|0x1205f0
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_CSDM_MPS
value|0x1205d0
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_DBG_MPS
value|0x1205e8
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_DMAE_MPS
value|0x1205ec
end_define

begin_comment
comment|/*  * [RW 10] if Number of entries in dmae fifo will be higher than thi  * threshold then has_payload indication will be asserted; the default value  * should be equal to&gt;  write MBS size!  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_DMAE_TH
value|0x120368
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_HC_MPS
value|0x1205c8
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_QM_MPS
value|0x1205dc
end_define

begin_comment
comment|/* [RW 1] 0 - working in A0 mode;  - working in B0 mode */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_REV_MODE
value|0x120670
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_SRC_MPS
value|0x1205e4
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_TM_MPS
value|0x1205e0
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_TSDM_MPS
value|0x1205d4
end_define

begin_comment
comment|/*  * [RW 10] if Number of entries in usdmdp fifo will be higher than thi  * threshold then has_payload indication will be asserted; the default value  * should be equal to&gt;  write MBS size!  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_USDMDP_TH
value|0x120348
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_USDM_MPS
value|0x1205cc
end_define

begin_comment
comment|/*  * [RW 2] 0 - 128B;  - 256B;  - 512B;  - 1024B; when the payload in th  * buffer reaches this number has_payload will be asserted  */
end_comment

begin_define
define|#
directive|define
name|PXP2_REG_WR_XSDM_MPS
value|0x1205d8
end_define

begin_comment
comment|/* [R 1] debug only: Indication if PSWHST arbiter is idle */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_HST_ARB_IS_IDLE
value|0x103004
end_define

begin_comment
comment|/*  * [R 8] debug only: A bit mask for all PSWHST arbiter clients. '1' mean  * this client is waiting for the arbiter.  */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_HST_CLIENTS_WAITING_TO_ARB
value|0x103008
end_define

begin_comment
comment|/*  * [R 1] debug only: '1' means this PSWHST is discarding doorbells. This bi  * should update accoring to 'hst_discard_doorbells' register when the state  * machine is idle  */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_HST_DISCARD_DOORBELLS_STATUS
value|0x1030a0
end_define

begin_comment
comment|/*  * [R 6] debug only: A bit mask for all PSWHST internal write clients. '1  * means this PSWHST is discarding inputs from this client. Each bit should  * update accoring to 'hst_discard_internal_writes' register when the state  * machine is idle.  */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_HST_DISCARD_INTERNAL_WRITES_STATUS
value|0x10309c
end_define

begin_comment
comment|/* [WB 160] Used for initialization of the inbound interrupts memory */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_HST_INBOUND_INT
value|0x103800
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_MASK_0
value|0x103074
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_MASK_1
value|0x103084
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_STS_0
value|0x103068
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_STS_1
value|0x103078
end_define

begin_comment
comment|/* [RC 32] Interrupt register #0 read clear */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_STS_CLR_0
value|0x10306c
end_define

begin_comment
comment|/* [RW 26] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_PXP_PRTY_MASK
value|0x103094
end_define

begin_comment
comment|/* [R 26] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|PXP_REG_PXP_PRTY_STS
value|0x103088
end_define

begin_comment
comment|/*  * [RW 4] The activity counter initial increment value sent in the loa  * request  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ACTCTRINITVAL_0
value|0x168040
end_define

begin_define
define|#
directive|define
name|QM_REG_ACTCTRINITVAL_1
value|0x168044
end_define

begin_define
define|#
directive|define
name|QM_REG_ACTCTRINITVAL_2
value|0x168048
end_define

begin_define
define|#
directive|define
name|QM_REG_ACTCTRINITVAL_3
value|0x16804c
end_define

begin_comment
comment|/*  * [RW 32] The base logical address (in bytes) of each physical queue. Th  * index I represents the physical queue number. The 12 lsbs are ignore and  * considered zero so practically there are only 20 bits in this register;  * queues 63-0  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BASEADDR
value|0x168900
end_define

begin_comment
comment|/*  * [RW 32] The base logical address (in bytes) of each physical queue. Th  * index I represents the physical queue number. The 12 lsbs are ignore and  * considered zero so practically there are only 20 bits in this register;  * queues 127-64  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BASEADDR_EXT_A
value|0x16e100
end_define

begin_comment
comment|/* [RW 16] The byte credit cost for each task. This value is for both ports */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDCOST
value|0x168234
end_define

begin_comment
comment|/* [RW 16] The initial byte credit value for both ports. */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDINITVAL
value|0x168238
end_define

begin_comment
comment|/*  * [RW 32] A bit per physical queue. If the bit is cleared then the physica  * queue uses port 0 else it uses port 1; queues 31-0  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDPORT_LSB
value|0x168228
end_define

begin_comment
comment|/*  * [RW 32] A bit per physical queue. If the bit is cleared then the physica  * queue uses port 0 else it uses port 1; queues 95-64  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDPORT_LSB_EXT_A
value|0x16e520
end_define

begin_comment
comment|/*  * [RW 32] A bit per physical queue. If the bit is cleared then the physica  * queue uses port 0 else it uses port 1; queues 63-32  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDPORT_MSB
value|0x168224
end_define

begin_comment
comment|/*  * [RW 32] A bit per physical queue. If the bit is cleared then the physica  * queue uses port 0 else it uses port 1; queues 127-96  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECRDPORT_MSB_EXT_A
value|0x16e51c
end_define

begin_comment
comment|/*  * [RW 16] The byte credit value that if above the QM is considered almos  * full  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_BYTECREDITAFULLTHR
value|0x168094
end_define

begin_comment
comment|/* [RW 4] The initial credit for interface */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_0
value|0x1680cc
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_1
value|0x1680d0
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_2
value|0x1680d4
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_3
value|0x1680d8
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_4
value|0x1680dc
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_5
value|0x1680e0
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_6
value|0x1680e4
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINITCRD_7
value|0x1680e8
end_define

begin_comment
comment|/*  * [RW 8] A mask bit per CM interface. If this bit is 0 then this interfac  * is masked  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CMINTEN
value|0x1680ec
end_define

begin_comment
comment|/*  * [RW 12] A bit vector which indicates which one of the queues are tied t  * interface 0  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_0
value|0x1681f4
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_1
value|0x1681f8
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_2
value|0x1681fc
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_3
value|0x168200
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_4
value|0x168204
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_5
value|0x168208
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_6
value|0x16820c
end_define

begin_define
define|#
directive|define
name|QM_REG_CMINTVOQMASK_7
value|0x168210
end_define

begin_comment
comment|/*  * [RW 20] The number of connections divided by 16 which dictates the siz  * of each queue which belongs to even function number.  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CONNNUM_0
value|0x168020
end_define

begin_comment
comment|/* [R 6] Keep the fill level of the fifo from write client 4 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CQM_WRC_FIFOLVL
value|0x168018
end_define

begin_comment
comment|/* [RW 8] The context regions sent in the CFC load request */
end_comment

begin_define
define|#
directive|define
name|QM_REG_CTXREG_0
value|0x168030
end_define

begin_define
define|#
directive|define
name|QM_REG_CTXREG_1
value|0x168034
end_define

begin_define
define|#
directive|define
name|QM_REG_CTXREG_2
value|0x168038
end_define

begin_define
define|#
directive|define
name|QM_REG_CTXREG_3
value|0x16803c
end_define

begin_comment
comment|/*  * [RW 12] The VOQ mask used to select the VOQs which needs to be full fo  * bypass enable  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENBYPVOQMASK
value|0x16823c
end_define

begin_comment
comment|/*  * [RW 32] A bit mask per each physical queue. If a bit is set then th  * physical queue uses the byte credit; queues 31-0  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENBYTECRD_LSB
value|0x168220
end_define

begin_comment
comment|/*  * [RW 32] A bit mask per each physical queue. If a bit is set then th  * physical queue uses the byte credit; queues 95-64  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENBYTECRD_LSB_EXT_A
value|0x16e518
end_define

begin_comment
comment|/*  * [RW 32] A bit mask per each physical queue. If a bit is set then th  * physical queue uses the byte credit; queues 63-32  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENBYTECRD_MSB
value|0x16821c
end_define

begin_comment
comment|/*  * [RW 32] A bit mask per each physical queue. If a bit is set then th  * physical queue uses the byte credit; queues 127-96  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENBYTECRD_MSB_EXT_A
value|0x16e514
end_define

begin_comment
comment|/*  * [RW 4] If cleared then the secondary interface will not be served by th  * RR arbiter  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_ENSEC
value|0x1680f0
end_define

begin_comment
comment|/* [RW 32] NA */
end_comment

begin_define
define|#
directive|define
name|QM_REG_FUNCNUMSEL_LSB
value|0x168230
end_define

begin_comment
comment|/* [RW 32] NA */
end_comment

begin_define
define|#
directive|define
name|QM_REG_FUNCNUMSEL_MSB
value|0x16822c
end_define

begin_comment
comment|/*  * [RW 32] A mask register to mask the Almost empty signals which will no  * be use for the almost empty indication to the HW block; queues 31:0  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_HWAEMPTYMASK_LSB
value|0x168218
end_define

begin_comment
comment|/*  * [RW 32] A mask register to mask the Almost empty signals which will no  * be use for the almost empty indication to the HW block; queues 95-64  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_HWAEMPTYMASK_LSB_EXT_A
value|0x16e510
end_define

begin_comment
comment|/*  * [RW 32] A mask register to mask the Almost empty signals which will no  * be use for the almost empty indication to the HW block; queues 63:32  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_HWAEMPTYMASK_MSB
value|0x168214
end_define

begin_comment
comment|/*  * [RW 32] A mask register to mask the Almost empty signals which will no  * be use for the almost empty indication to the HW block; queues 127-96  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_HWAEMPTYMASK_MSB_EXT_A
value|0x16e50c
end_define

begin_comment
comment|/* [RW 4] The number of outstanding request to CFC */
end_comment

begin_define
define|#
directive|define
name|QM_REG_OUTLDREQ
value|0x168804
end_define

begin_comment
comment|/*  * [RC 1] A flag to indicate that overflow error occurred in one of th  * queues.  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_OVFERROR
value|0x16805c
end_define

begin_comment
comment|/* [RC 7] the Q were the qverflow occurs */
end_comment

begin_define
define|#
directive|define
name|QM_REG_OVFQNUM
value|0x168058
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 15-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE0
value|0x168410
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 31-16 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE1
value|0x168414
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 47-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE2
value|0x16e684
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 63-48 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE3
value|0x16e688
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 79-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE4
value|0x16e68c
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 95-80 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE5
value|0x16e690
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 111-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE6
value|0x16e694
end_define

begin_comment
comment|/* [R 16] Pause state for physical queues 127-112 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PAUSESTATE7
value|0x16e698
end_define

begin_comment
comment|/* [RW 2] The PCI attributes field used in the PCI request. */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PCIREQAT
value|0x168054
end_define

begin_comment
comment|/* [R 16] The byte credit of port 0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PORT0BYTECRD
value|0x168300
end_define

begin_comment
comment|/* [R 16] The byte credit of port 1 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PORT1BYTECRD
value|0x168304
end_define

begin_comment
comment|/* [RW 3] pci function number of queues 15-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_0
value|0x16e6bc
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_1
value|0x16e6c0
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_2
value|0x16e6c4
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_3
value|0x16e6c8
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_4
value|0x16e6cc
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_5
value|0x16e6d0
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_6
value|0x16e6d4
end_define

begin_define
define|#
directive|define
name|QM_REG_PQ2PCIFUNC_7
value|0x16e6d8
end_define

begin_comment
comment|/*  * [WB 54] Pointer Table Memory for queues 63-0; The mapping is as follow  * ptrtbl[53:30] read pointer; ptrtbl[29:6] write pointer; ptrtbl[5:4] read  * bank0; ptrtbl[3:2] read bank 1; ptrtbl[1:0] write bank;  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PTRTBL
value|0x168a00
end_define

begin_comment
comment|/*  * [WB 54] Pointer Table Memory for queues 127-64; The mapping is as follow  * ptrtbl[53:30] read pointer; ptrtbl[29:6] write pointer; ptrtbl[5:4] read  * bank0; ptrtbl[3:2] read bank 1; ptrtbl[1:0] write bank;  */
end_comment

begin_define
define|#
directive|define
name|QM_REG_PTRTBL_EXT_A
value|0x16e200
end_define

begin_comment
comment|/* [RW 2] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QM_INT_MASK
value|0x168444
end_define

begin_comment
comment|/* [R 2] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QM_INT_STS
value|0x168438
end_define

begin_comment
comment|/* [RW 12] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QM_PRTY_MASK
value|0x168454
end_define

begin_comment
comment|/* [R 12] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QM_PRTY_STS
value|0x168448
end_define

begin_comment
comment|/* [R 32] Current queues in pipeline: Queues from 32 to 63 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QSTATUS_HIGH
value|0x16802c
end_define

begin_comment
comment|/* [R 32] Current queues in pipeline: Queues from 96 to 127 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QSTATUS_HIGH_EXT_A
value|0x16e408
end_define

begin_comment
comment|/* [R 32] Current queues in pipeline: Queues from 0 to 31 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QSTATUS_LOW
value|0x168028
end_define

begin_comment
comment|/* [R 32] Current queues in pipeline: Queues from 64 to 95 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QSTATUS_LOW_EXT_A
value|0x16e404
end_define

begin_comment
comment|/* [R 24] The number of tasks queued for each queue; queues 63-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QTASKCTR_0
value|0x168308
end_define

begin_comment
comment|/* [R 24] The number of tasks queued for each queue; queues 127-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QTASKCTR_EXT_A_0
value|0x16e584
end_define

begin_comment
comment|/* [RW 4] Queue tied to VOQ */
end_comment

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_0
value|0x1680f4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_10
value|0x16811c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_100
value|0x16e49c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_101
value|0x16e4a0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_102
value|0x16e4a4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_103
value|0x16e4a8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_104
value|0x16e4ac
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_105
value|0x16e4b0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_106
value|0x16e4b4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_107
value|0x16e4b8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_108
value|0x16e4bc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_109
value|0x16e4c0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_11
value|0x168120
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_110
value|0x16e4c4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_111
value|0x16e4c8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_112
value|0x16e4cc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_113
value|0x16e4d0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_114
value|0x16e4d4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_115
value|0x16e4d8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_116
value|0x16e4dc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_117
value|0x16e4e0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_118
value|0x16e4e4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_119
value|0x16e4e8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_12
value|0x168124
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_120
value|0x16e4ec
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_121
value|0x16e4f0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_122
value|0x16e4f4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_123
value|0x16e4f8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_124
value|0x16e4fc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_125
value|0x16e500
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_126
value|0x16e504
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_127
value|0x16e508
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_13
value|0x168128
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_14
value|0x16812c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_15
value|0x168130
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_16
value|0x168134
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_17
value|0x168138
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_21
value|0x168148
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_22
value|0x16814c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_23
value|0x168150
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_24
value|0x168154
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_25
value|0x168158
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_26
value|0x16815c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_27
value|0x168160
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_28
value|0x168164
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_29
value|0x168168
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_30
value|0x16816c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_31
value|0x168170
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_32
value|0x168174
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_33
value|0x168178
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_34
value|0x16817c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_35
value|0x168180
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_36
value|0x168184
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_37
value|0x168188
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_38
value|0x16818c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_39
value|0x168190
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_40
value|0x168194
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_41
value|0x168198
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_42
value|0x16819c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_43
value|0x1681a0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_44
value|0x1681a4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_45
value|0x1681a8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_46
value|0x1681ac
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_47
value|0x1681b0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_48
value|0x1681b4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_49
value|0x1681b8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_5
value|0x168108
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_50
value|0x1681bc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_51
value|0x1681c0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_52
value|0x1681c4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_53
value|0x1681c8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_54
value|0x1681cc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_55
value|0x1681d0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_56
value|0x1681d4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_57
value|0x1681d8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_58
value|0x1681dc
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_59
value|0x1681e0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_6
value|0x16810c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_60
value|0x1681e4
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_61
value|0x1681e8
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_62
value|0x1681ec
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_63
value|0x1681f0
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_64
value|0x16e40c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_65
value|0x16e410
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_69
value|0x16e420
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_7
value|0x168110
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_70
value|0x16e424
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_71
value|0x16e428
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_72
value|0x16e42c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_73
value|0x16e430
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_74
value|0x16e434
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_75
value|0x16e438
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_76
value|0x16e43c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_77
value|0x16e440
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_78
value|0x16e444
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_79
value|0x16e448
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_8
value|0x168114
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_80
value|0x16e44c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_81
value|0x16e450
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_85
value|0x16e460
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_86
value|0x16e464
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_87
value|0x16e468
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_88
value|0x16e46c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_89
value|0x16e470
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_9
value|0x168118
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_90
value|0x16e474
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_91
value|0x16e478
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_92
value|0x16e47c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_93
value|0x16e480
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_94
value|0x16e484
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_95
value|0x16e488
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_96
value|0x16e48c
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_97
value|0x16e490
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_98
value|0x16e494
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_99
value|0x16e498
end_define

begin_comment
comment|/* [RW 1] Initialization bit command */
end_comment

begin_define
define|#
directive|define
name|QM_REG_SOFT_RESET
value|0x168428
end_define

begin_comment
comment|/* [RW 8] The credit cost per every task in the QM. A value per each VOQ */
end_comment

begin_define
define|#
directive|define
name|QM_REG_TASKCRDCOST_0
value|0x16809c
end_define

begin_define
define|#
directive|define
name|QM_REG_TASKCRDCOST_1
value|0x1680a0
end_define

begin_define
define|#
directive|define
name|QM_REG_TASKCRDCOST_2
value|0x1680a4
end_define

begin_define
define|#
directive|define
name|QM_REG_TASKCRDCOST_4
value|0x1680ac
end_define

begin_define
define|#
directive|define
name|QM_REG_TASKCRDCOST_5
value|0x1680b0
end_define

begin_comment
comment|/* [R 6] Keep the fill level of the fifo from write client 3 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_TQM_WRC_FIFOLVL
value|0x168010
end_define

begin_comment
comment|/* [R 6] Keep the fill level of the fifo from write client 2 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_UQM_WRC_FIFOLVL
value|0x168008
end_define

begin_comment
comment|/* [RC 32] Credit update error register */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQCRDERRREG
value|0x168408
end_define

begin_comment
comment|/* [R 16] The credit value for each VOQ */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQCREDIT_0
value|0x1682d0
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQCREDIT_1
value|0x1682d4
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQCREDIT_4
value|0x1682e0
end_define

begin_comment
comment|/* [RW 16] The credit value that if above the QM is considered almost full */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQCREDITAFULLTHR
value|0x168090
end_define

begin_comment
comment|/* [RW 16] The init and maximum credit for each VoQ */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQINITCREDIT_0
value|0x168060
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCREDIT_1
value|0x168064
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCREDIT_2
value|0x168068
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCREDIT_4
value|0x168070
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCREDIT_5
value|0x168074
end_define

begin_comment
comment|/* [RW 1] The port of which VOQ belongs */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQPORT_0
value|0x1682a0
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQPORT_1
value|0x1682a4
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQPORT_2
value|0x1682a8
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_0_LSB
value|0x168240
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_0_LSB_EXT_A
value|0x16e524
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_0_MSB
value|0x168244
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_0_MSB_EXT_A
value|0x16e528
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_10_LSB
value|0x168290
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_10_LSB_EXT_A
value|0x16e574
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_10_MSB
value|0x168294
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_10_MSB_EXT_A
value|0x16e578
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_11_LSB
value|0x168298
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_11_LSB_EXT_A
value|0x16e57c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_11_MSB
value|0x16829c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_11_MSB_EXT_A
value|0x16e580
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_1_LSB
value|0x168248
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_1_LSB_EXT_A
value|0x16e52c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_1_MSB
value|0x16824c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_1_MSB_EXT_A
value|0x16e530
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_2_LSB
value|0x168250
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_2_LSB_EXT_A
value|0x16e534
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_2_MSB
value|0x168254
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_2_MSB_EXT_A
value|0x16e538
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_3_LSB
value|0x168258
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_3_LSB_EXT_A
value|0x16e53c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_3_MSB_EXT_A
value|0x16e540
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_4_LSB
value|0x168260
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_4_LSB_EXT_A
value|0x16e544
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_4_MSB
value|0x168264
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_4_MSB_EXT_A
value|0x16e548
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_5_LSB
value|0x168268
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_5_LSB_EXT_A
value|0x16e54c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_5_MSB
value|0x16826c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_5_MSB_EXT_A
value|0x16e550
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_6_LSB
value|0x168270
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_6_LSB_EXT_A
value|0x16e554
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_6_MSB
value|0x168274
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_6_MSB_EXT_A
value|0x16e558
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_7_LSB
value|0x168278
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_7_LSB_EXT_A
value|0x16e55c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_7_MSB
value|0x16827c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_7_MSB_EXT_A
value|0x16e560
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_8_LSB
value|0x168280
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_8_LSB_EXT_A
value|0x16e564
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 63-32 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_8_MSB
value|0x168284
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_8_MSB_EXT_A
value|0x16e568
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 31-0 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_9_LSB
value|0x168288
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 95-64 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_9_LSB_EXT_A
value|0x16e56c
end_define

begin_comment
comment|/* [RW 32] The physical queue number associated with each VOQ; queues 127-96 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_9_MSB_EXT_A
value|0x16e570
end_define

begin_comment
comment|/* [RW 32] Wrr weights */
end_comment

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_0
value|0x16880c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_1
value|0x168810
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_10
value|0x168814
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_11
value|0x168818
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_12
value|0x16881c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_13
value|0x168820
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_14
value|0x168824
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_15
value|0x168828
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_16
value|0x16e000
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_17
value|0x16e004
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_18
value|0x16e008
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_19
value|0x16e00c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_2
value|0x16882c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_20
value|0x16e010
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_21
value|0x16e014
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_22
value|0x16e018
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_23
value|0x16e01c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_24
value|0x16e020
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_25
value|0x16e024
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_26
value|0x16e028
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_27
value|0x16e02c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_28
value|0x16e030
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_29
value|0x16e034
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_3
value|0x168830
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_30
value|0x16e038
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_31
value|0x16e03c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_4
value|0x168834
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_5
value|0x168838
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_6
value|0x16883c
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_7
value|0x168840
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_8
value|0x168844
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRWEIGHTS_9
value|0x168848
end_define

begin_comment
comment|/* [R 6] Keep the fill level of the fifo from write client 1 */
end_comment

begin_define
define|#
directive|define
name|QM_REG_XQM_WRC_FIFOLVL
value|0x168000
end_define

begin_define
define|#
directive|define
name|SRC_REG_COUNTFREE0
value|0x40500
end_define

begin_comment
comment|/*  * [RW 1] If clr the searcher is compatible to E1 A0 - support only tw  * ports. If set the searcher support 8 functions.  */
end_comment

begin_define
define|#
directive|define
name|SRC_REG_E1HMF_ENABLE
value|0x404cc
end_define

begin_define
define|#
directive|define
name|SRC_REG_FIRSTFREE0
value|0x40510
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYRSS0_0
value|0x40408
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYRSS0_7
value|0x40424
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYRSS1_9
value|0x40454
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_0
value|0x40458
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_1
value|0x4045c
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_2
value|0x40460
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_3
value|0x40464
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_4
value|0x40468
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_5
value|0x4046c
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_6
value|0x40470
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_7
value|0x40474
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_8
value|0x40478
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_9
value|0x4047c
end_define

begin_define
define|#
directive|define
name|SRC_REG_LASTFREE0
value|0x40530
end_define

begin_define
define|#
directive|define
name|SRC_REG_NUMBER_HASH_BITS0
value|0x40400
end_define

begin_comment
comment|/* [RW 1] Reset internal state machines. */
end_comment

begin_define
define|#
directive|define
name|SRC_REG_SOFT_RST
value|0x4049c
end_define

begin_comment
comment|/* [R 3] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|SRC_REG_SRC_INT_STS
value|0x404ac
end_define

begin_comment
comment|/* [RW 3] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|SRC_REG_SRC_PRTY_MASK
value|0x404c8
end_define

begin_comment
comment|/* [R 3] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|SRC_REG_SRC_PRTY_STS
value|0x404bc
end_define

begin_comment
comment|/* [R 4] Used to read the value of the XX protection CAM occupancy counter. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CAM_OCCUP
value|0x5017c
end_define

begin_comment
comment|/*  * [RW 1] CDU AG read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CDU_AG_RD_IFEN
value|0x50034
end_define

begin_comment
comment|/*  * [RW 1] CDU AG write Interface enable. If 0 - the request and valid inpu  * are disregarded; all other signals are treated as usual; if 1 - normal  * activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CDU_AG_WR_IFEN
value|0x50030
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CDU_SM_RD_IFEN
value|0x5003c
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM write Interface enable. If 0 - the request and vali  * input is disregarded; all other signals are treated as usual; if 1 -  * normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CDU_SM_WR_IFEN
value|0x50038
end_define

begin_comment
comment|/*  * [RW 4] CFC output initial credit. Max credit available - 15.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 1 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CFC_INIT_CRD
value|0x50204
end_define

begin_comment
comment|/*  * [RW 3] The weight of the CP input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CP_WEIGHT
value|0x500c0
end_define

begin_comment
comment|/*  * [RW 1] Input csem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CSEM_IFEN
value|0x5002c
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the In#  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CSEM_LENGTH_MIS
value|0x50174
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input csem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_CSEM_WEIGHT
value|0x500bc
end_define

begin_comment
comment|/* [RW 8] The Event ID in case of ErrorFlg is set in the input message. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_ERR_EVNT_ID
value|0x500a0
end_define

begin_comment
comment|/* [RW 28] The CM erroneous header for QM and Timers formatting. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_ERR_TCM_HDR
value|0x5009c
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers expiration. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_EXPR_EVNT_ID
value|0x500a4
end_define

begin_comment
comment|/*  * [RW 8] FIC0 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_FIC0_INIT_CRD
value|0x5020c
end_define

begin_comment
comment|/*  * [RW 8] FIC1 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_FIC1_INIT_CRD
value|0x50210
end_define

begin_comment
comment|/*  * [RW 1] Arbitration between Input Arbiter groups: 0 - fair Round-Robin;  * - strict priority defined by ~tcm_registers_gr_ag_pr.gr_ag_pr;  * ~tcm_registers_gr_ld0_pr.gr_ld0_pr and  * ~tcm_registers_gr_ld1_pr.gr_ld1_pr.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_GR_ARB_TYPE
value|0x50114
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC0) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Store channel is the  * compliment of the other 3 groups.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_GR_LD0_PR
value|0x5011c
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC1) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Store channel is the  * compliment of the other 3 groups.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_GR_LD1_PR
value|0x50120
end_define

begin_comment
comment|/*  * [RW 4] The number of double REG-pairs; loaded from the STORM context an  * sent to STORM; for a specific connection type. The double REG-pairs are  * used to align to STORM context row size of 128 bits. The offset of these  * data in the STORM context is always 0. Index _i stands for the connection  * type (one of 16).  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_0
value|0x50050
end_define

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_1
value|0x50054
end_define

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_2
value|0x50058
end_define

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_3
value|0x5005c
end_define

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_4
value|0x50060
end_define

begin_define
define|#
directive|define
name|TCM_REG_N_SM_CTX_LD_5
value|0x50064
end_define

begin_comment
comment|/*  * [RW 1] Input pbf Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PBF_IFEN
value|0x50024
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the In#  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PBF_LENGTH_MIS
value|0x5016c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input pbf in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PBF_WEIGHT
value|0x500b4
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM0_0
value|0x500e0
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM0_1
value|0x500e4
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM1_0
value|0x500e8
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM1_1
value|0x500ec
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM2_0
value|0x500f0
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM2_1
value|0x500f4
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM3_0
value|0x500f8
end_define

begin_define
define|#
directive|define
name|TCM_REG_PHYS_QNUM3_1
value|0x500fc
end_define

begin_comment
comment|/*  * [RW 1] Input prs Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PRS_IFEN
value|0x50020
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the In#  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PRS_LENGTH_MIS
value|0x50168
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input prs in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_PRS_WEIGHT
value|0x500b0
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers formatting in case of stop done. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_STOP_EVNT_ID
value|0x500a8
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the STOR  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_STORM_LENGTH_MIS
value|0x50160
end_define

begin_comment
comment|/*  * [RW 1] STORM - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_STORM_TCM_IFEN
value|0x50010
end_define

begin_comment
comment|/*  * [RW 3] The weight of the STORM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_STORM_WEIGHT
value|0x500ac
end_define

begin_comment
comment|/*  * [RW 1] CM - CFC Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_CFC_IFEN
value|0x50040
end_define

begin_comment
comment|/* [RW 11] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_INT_MASK
value|0x501dc
end_define

begin_comment
comment|/* [R 11] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_INT_STS
value|0x501d0
end_define

begin_comment
comment|/* [R 27] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_PRTY_STS
value|0x501e0
end_define

begin_comment
comment|/*  * [RW 3] The size of AG context region 0 in REG-pairs. Designates the M  * REG-pair number (e.g. if region 0 is 6 REG-pairs; the value should be 5).  * Is used to determine the number of the AG context REG-pairs written back;  * when the input message Reg1WbFlg isn't set.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_REG0_SZ
value|0x500d8
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 0 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_STORM0_IFEN
value|0x50004
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 1 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_STORM1_IFEN
value|0x50008
end_define

begin_comment
comment|/*  * [RW 1] CM - QM Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_TQM_IFEN
value|0x5000c
end_define

begin_comment
comment|/* [RW 1] If set the Q index; received from the QM is inserted to event ID. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TCM_TQM_USE_Q
value|0x500d4
end_define

begin_comment
comment|/* [RW 28] The CM header for Timers expiration command. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TM_TCM_HDR
value|0x50098
end_define

begin_comment
comment|/*  * [RW 1] Timers - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TM_TCM_IFEN
value|0x5001c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the Timers input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TM_WEIGHT
value|0x500d0
end_define

begin_comment
comment|/*  * [RW 6] QM output initial credit. Max credit available - 32.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 32 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_INIT_CRD
value|0x5021c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (primary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_P_WEIGHT
value|0x500c8
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (secondary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_S_WEIGHT
value|0x500cc
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (primary). */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_TCM_HDR_P
value|0x50090
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (secondary). */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_TCM_HDR_S
value|0x50094
end_define

begin_comment
comment|/*  * [RW 1] QM - CM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TQM_TCM_IFEN
value|0x50014
end_define

begin_comment
comment|/*  * [RW 1] Input SDM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TSDM_IFEN
value|0x50018
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the SD  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TSDM_LENGTH_MIS
value|0x50164
end_define

begin_comment
comment|/*  * [RW 3] The weight of the SDM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_TSDM_WEIGHT
value|0x500c4
end_define

begin_comment
comment|/*  * [RW 1] Input usem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_USEM_IFEN
value|0x50028
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the In#  * interface.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_USEM_LENGTH_MIS
value|0x50170
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input usem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_USEM_WEIGHT
value|0x500b8
end_define

begin_comment
comment|/*  * [RW 21] Indirect access to the descriptor table of the XX protectio  * mechanism. The fields are: [5:0] - length of the message; 15:6] - message  * pointer; 20:16] - next pointer.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_DESCR_TABLE
value|0x50280
end_define

begin_define
define|#
directive|define
name|TCM_REG_XX_DESCR_TABLE_SIZE
value|32
end_define

begin_comment
comment|/* [R 6] Use to read the value of XX protection Free counter. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_FREE
value|0x50178
end_define

begin_comment
comment|/*  * [RW 6] Initial value for the credit counter; responsible for fulfillin  * of the Input Stage XX protection buffer by the XX protection pending  * messages. Max credit available - 127.Write writes the initial credit  * value; read returns the current value of the credit counter. Must be  * initialized to 19 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_INIT_CRD
value|0x50220
end_define

begin_comment
comment|/*  * [RW 6] Maximum link list size (messages locked) per connection in the X  * protection.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_MAX_LL_SZ
value|0x50044
end_define

begin_comment
comment|/*  * [RW 6] The maximum number of pending messages; which may be stored in X  * protection. ~tcm_registers_xx_free.xx_free is read on read.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_MSG_NUM
value|0x50224
end_define

begin_comment
comment|/* [RW 8] The Event ID; sent to the STORM in case of XX overflow. */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_OVFL_EVNT_ID
value|0x50048
end_define

begin_comment
comment|/*  * [RW 16] Indirect access to the XX table of the XX protection mechanism  * The fields are:[4:0] - tail pointer; [10:5] - Link List size; 15:11] -  * header pointer.  */
end_comment

begin_define
define|#
directive|define
name|TCM_REG_XX_TABLE
value|0x50240
end_define

begin_comment
comment|/* [RW 4] Load value for for cfc ac credit cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CFC_AC_CRDCNT_VAL
value|0x164208
end_define

begin_comment
comment|/* [RW 4] Load value for cfc cld credit cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CFC_CLD_CRDCNT_VAL
value|0x164210
end_define

begin_comment
comment|/* [RW 8] Client0 context region. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CL0_CONT_REGION
value|0x164030
end_define

begin_comment
comment|/* [RW 8] Client1 context region. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CL1_CONT_REGION
value|0x164034
end_define

begin_comment
comment|/* [RW 8] Client2 context region. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CL2_CONT_REGION
value|0x164038
end_define

begin_comment
comment|/* [RW 2] Client in High priority client number. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CLIN_PRIOR0_CLIENT
value|0x164024
end_define

begin_comment
comment|/* [RW 4] Load value for clout0 cred cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CLOUT_CRDCNT0_VAL
value|0x164220
end_define

begin_comment
comment|/* [RW 4] Load value for clout1 cred cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CLOUT_CRDCNT1_VAL
value|0x164228
end_define

begin_comment
comment|/* [RW 4] Load value for clout2 cred cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_CLOUT_CRDCNT2_VAL
value|0x164230
end_define

begin_comment
comment|/* [RW 1] Enable client0 input. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EN_CL0_INPUT
value|0x164008
end_define

begin_comment
comment|/* [RW 1] Enable client1 input. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EN_CL1_INPUT
value|0x16400c
end_define

begin_comment
comment|/* [RW 1] Enable client2 input. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EN_CL2_INPUT
value|0x164010
end_define

begin_define
define|#
directive|define
name|TM_REG_EN_LINEAR0_TIMER
value|0x164014
end_define

begin_comment
comment|/* [RW 1] Enable real time counter. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EN_REAL_TIME_CNT
value|0x1640d8
end_define

begin_comment
comment|/* [RW 1] Enable for Timers state machines. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EN_TIMERS
value|0x164000
end_define

begin_comment
comment|/*  * [RW 4] Load value for expiration credit cnt. CFC max number o  * outstanding load requests for timers (expiration) context loading.  */
end_comment

begin_define
define|#
directive|define
name|TM_REG_EXP_CRDCNT_VAL
value|0x164238
end_define

begin_comment
comment|/* [RW 32] Linear0 logic address. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN0_LOGIC_ADDR
value|0x164240
end_define

begin_comment
comment|/* [RW 18] Linear0 Max active cid (in banks of 32 entries). */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN0_MAX_ACTIVE_CID
value|0x164048
end_define

begin_comment
comment|/* [WB 64] Linear0 phy address. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN0_PHY_ADDR
value|0x164270
end_define

begin_comment
comment|/* [RW 1] Linear0 physical address valid. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN0_PHY_ADDR_VALID
value|0x164248
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_SCAN_ON
value|0x1640d0
end_define

begin_comment
comment|/* [RW 24] Linear0 array scan timeout. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN0_SCAN_TIME
value|0x16403c
end_define

begin_comment
comment|/* [RW 32] Linear1 logic address. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN1_LOGIC_ADDR
value|0x164250
end_define

begin_comment
comment|/* [WB 64] Linear1 phy address. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN1_PHY_ADDR
value|0x164280
end_define

begin_comment
comment|/* [RW 1] Linear1 physical address valid. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN1_PHY_ADDR_VALID
value|0x164258
end_define

begin_comment
comment|/* [RW 6] Linear timer set_clear fifo threshold. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_LIN_SETCLR_FIFO_ALFULL_THR
value|0x164070
end_define

begin_comment
comment|/* [RW 2] Load value for pci arbiter credit cnt. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_PCIARB_CRDCNT_VAL
value|0x164260
end_define

begin_comment
comment|/* [RW 20] The amount of hardware cycles for each timer tick. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_TIMER_TICK_SIZE
value|0x16401c
end_define

begin_comment
comment|/* [RW 8] Timers Context region. */
end_comment

begin_define
define|#
directive|define
name|TM_REG_TM_CONTEXT_REGION
value|0x164044
end_define

begin_comment
comment|/* [RW 1] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TM_REG_TM_INT_MASK
value|0x1640fc
end_define

begin_comment
comment|/* [R 1] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|TM_REG_TM_INT_STS
value|0x1640f0
end_define

begin_comment
comment|/* [RW 8] The event id for aggregated interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_EVENT_0
value|0x42038
end_define

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_EVENT_1
value|0x4203c
end_define

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_EVENT_2
value|0x42040
end_define

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_EVENT_3
value|0x42044
end_define

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_EVENT_4
value|0x42048
end_define

begin_comment
comment|/* [RW 1] The T bit for aggregated interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_T_0
value|0x420b8
end_define

begin_define
define|#
directive|define
name|TSDM_REG_AGG_INT_T_1
value|0x420bc
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the cfc_rsp lcid */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CFC_RSP_START_ADDR
value|0x42008
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #0 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CMP_COUNTER_MAX0
value|0x4201c
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #1 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CMP_COUNTER_MAX1
value|0x42020
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #2 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CMP_COUNTER_MAX2
value|0x42024
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #3 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CMP_COUNTER_MAX3
value|0x42028
end_define

begin_comment
comment|/*  * [RW 13] The start address in the internal RAM for the completio  * counters.  */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_CMP_COUNTER_START_ADDR
value|0x4200c
end_define

begin_define
define|#
directive|define
name|TSDM_REG_ENABLE_IN1
value|0x42238
end_define

begin_define
define|#
directive|define
name|TSDM_REG_ENABLE_IN2
value|0x4223c
end_define

begin_define
define|#
directive|define
name|TSDM_REG_ENABLE_OUT1
value|0x42240
end_define

begin_define
define|#
directive|define
name|TSDM_REG_ENABLE_OUT2
value|0x42244
end_define

begin_comment
comment|/*  * [RW 4] The initial number of messages that can be sent to the pxp contro  * interface without receiving any ACK.  */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_INIT_CREDIT_PXP_CTRL
value|0x424bc
end_define

begin_comment
comment|/* [ST 32] The number of ACK after placement messages received */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_ACK_AFTER_PLACE
value|0x4227c
end_define

begin_comment
comment|/* [ST 32] The number of packet end messages received from the parser */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_PKT_END_MSG
value|0x42274
end_define

begin_comment
comment|/* [ST 32] The number of requests received from the pxp async if */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_PXP_ASYNC_REQ
value|0x42278
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 0 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q0_CMD
value|0x42248
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 10 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q10_CMD
value|0x4226c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 11 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q11_CMD
value|0x42270
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 1 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q1_CMD
value|0x4224c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 3 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q3_CMD
value|0x42250
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 4 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q4_CMD
value|0x42254
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 5 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q5_CMD
value|0x42258
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 6 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q6_CMD
value|0x4225c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 7 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q7_CMD
value|0x42260
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 8 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q8_CMD
value|0x42264
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 9 */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_NUM_OF_Q9_CMD
value|0x42268
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the packet end message */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_PCK_END_MSG_START_ADDR
value|0x42014
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for queue counters */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_Q_COUNTER_START_ADDR
value|0x42010
end_define

begin_comment
comment|/* [R 1] pxp_ctrl rd_data fifo empty in sdm_dma_rsp block */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_RSP_PXP_CTRL_RDATA_EMPTY
value|0x42548
end_define

begin_comment
comment|/* [R 1] parser fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_SYNC_PARSER_EMPTY
value|0x42550
end_define

begin_comment
comment|/* [R 1] parser serial fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_SYNC_SYNC_EMPTY
value|0x42558
end_define

begin_comment
comment|/*  * [RW 32] Tick for timer counter. Applicable only whe  * ~tsdm_registers_timer_tick_enable.timer_tick_enable =1  */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_TIMER_TICK
value|0x42000
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_MASK_0
value|0x4229c
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_MASK_1
value|0x422ac
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_STS_0
value|0x42290
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_STS_1
value|0x422a0
end_define

begin_comment
comment|/* [RW 11] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_PRTY_MASK
value|0x422bc
end_define

begin_comment
comment|/* [R 11] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_PRTY_STS
value|0x422b0
end_define

begin_comment
comment|/* [RW 5] The number of time_slots in the arbitration cycle */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_CYCLE_SIZE
value|0x180034
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 0. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_ELEMENT0
value|0x180020
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 1. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~tsem_registers_arb_element0.arb_element0  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_ELEMENT1
value|0x180024
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 2. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~tsem_registers_arb_element0.arb_element0  * and ~tsem_registers_arb_element1.arb_element1  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_ELEMENT2
value|0x180028
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 3. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.Could  * not be equal to register ~tsem_registers_arb_element0.arb_element0 and  * ~tsem_registers_arb_element1.arb_element1 and  * ~tsem_registers_arb_element2.arb_element2  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_ELEMENT3
value|0x18002c
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 4. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~tsem_registers_arb_element0.arb_element0  * and ~tsem_registers_arb_element1.arb_element1 and  * ~tsem_registers_arb_element2.arb_element2 and  * ~tsem_registers_arb_element3.arb_element3  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_ARB_ELEMENT4
value|0x180030
end_define

begin_define
define|#
directive|define
name|TSEM_REG_ENABLE_IN
value|0x1800a4
end_define

begin_define
define|#
directive|define
name|TSEM_REG_ENABLE_OUT
value|0x1800a8
end_define

begin_comment
comment|/*  * [RW 32] This address space contains all registers and memories that ar  * placed in SEM_FAST block. The SEM_FAST registers are described in  * appendix B. In order to access the sem_fast registers the base address  * ~fast_memory.fast_memory should be added to eachsem_fast register offset.  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_FAST_MEMORY
value|0x1a0000
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC0 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_FIC0_DISABLE
value|0x180224
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC1 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_FIC1_DISABLE
value|0x180234
end_define

begin_comment
comment|/*  * [RW 15] Interrupt table Read and write access to it is not possible i  * the middle of the work  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_INT_TABLE
value|0x180400
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC0  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FIC0
value|0x180000
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC1  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FIC1
value|0x180004
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC0  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FOC0
value|0x180008
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC1  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FOC1
value|0x18000c
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC2  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FOC2
value|0x180010
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC3  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_MSG_NUM_FOC3
value|0x180014
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from the passive buffer May be update  * during run_time by the microcode  */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_PAS_DISABLE
value|0x18024c
end_define

begin_comment
comment|/* [WB 128] Debug only. Passive buffer memory */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_PASSIVE_BUFFER
value|0x181000
end_define

begin_comment
comment|/* [WB 46] pram memory. B45 is parity; b[44:0] - data. */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_PRAM
value|0x1c0000
end_define

begin_comment
comment|/* [R 8] Valid sleeping threads indication have bit per thread */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_SLEEP_THREADS_VALID
value|0x18026c
end_define

begin_comment
comment|/* [R 1] EXT_STORE FIFO is empty in sem_slow_ls_ext */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_SLOW_EXT_STORE_EMPTY
value|0x1802a0
end_define

begin_comment
comment|/* [RW 8] List of free threads . There is a bit per thread. */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_THREADS_LIST
value|0x1802e4
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 0 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_0_AS
value|0x180038
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 10 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_10_AS
value|0x180060
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 11 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_11_AS
value|0x180064
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 12 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_12_AS
value|0x180068
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 13 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_13_AS
value|0x18006c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 14 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_14_AS
value|0x180070
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 15 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_15_AS
value|0x180074
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 16 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_16_AS
value|0x180078
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 17 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_17_AS
value|0x18007c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 18 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_18_AS
value|0x180080
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 1 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_1_AS
value|0x18003c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 2 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_2_AS
value|0x180040
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 3 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_3_AS
value|0x180044
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 4 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_4_AS
value|0x180048
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 5 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_5_AS
value|0x18004c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 6 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_6_AS
value|0x180050
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 7 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_7_AS
value|0x180054
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 8 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_8_AS
value|0x180058
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 9 */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TS_9_AS
value|0x18005c
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_MASK_0
value|0x180100
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_MASK_1
value|0x180110
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_STS_0
value|0x1800f4
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_STS_1
value|0x180104
end_define

begin_comment
comment|/* [RW 32] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_MASK_0
value|0x180120
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_MASK_1
value|0x180130
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_STS_0
value|0x180114
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_STS_1
value|0x180124
end_define

begin_comment
comment|/* [R 5] Used to read the XX protection CAM occupancy counter. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CAM_OCCUP
value|0xe0170
end_define

begin_comment
comment|/*  * [RW 1] CDU AG read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CDU_AG_RD_IFEN
value|0xe0038
end_define

begin_comment
comment|/*  * [RW 1] CDU AG write Interface enable. If 0 - the request and valid inpu  * are disregarded; all other signals are treated as usual; if 1 - normal  * activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CDU_AG_WR_IFEN
value|0xe0034
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CDU_SM_RD_IFEN
value|0xe0040
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM write Interface enable. If 0 - the request and vali  * input is disregarded; all other signals are treated as usual; if 1 -  * normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CDU_SM_WR_IFEN
value|0xe003c
end_define

begin_comment
comment|/*  * [RW 4] CFC output initial credit. Max credit available - 15.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 1 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CFC_INIT_CRD
value|0xe0204
end_define

begin_comment
comment|/*  * [RW 3] The weight of the CP input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CP_WEIGHT
value|0xe00c4
end_define

begin_comment
comment|/*  * [RW 1] Input csem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CSEM_IFEN
value|0xe0028
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the csem interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CSEM_LENGTH_MIS
value|0xe0160
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input csem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_CSEM_WEIGHT
value|0xe00b8
end_define

begin_comment
comment|/*  * [RW 1] Input dorq Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_DORQ_IFEN
value|0xe0030
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the dorq interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_DORQ_LENGTH_MIS
value|0xe0168
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input dorq in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_DORQ_WEIGHT
value|0xe00c0
end_define

begin_comment
comment|/* [RW 8] The Event ID in case ErrorFlg input message bit is set. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_ERR_EVNT_ID
value|0xe00a4
end_define

begin_comment
comment|/* [RW 28] The CM erroneous header for QM and Timers formatting. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_ERR_UCM_HDR
value|0xe00a0
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers expiration. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_EXPR_EVNT_ID
value|0xe00a8
end_define

begin_comment
comment|/*  * [RW 8] FIC0 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_FIC0_INIT_CRD
value|0xe020c
end_define

begin_comment
comment|/*  * [RW 8] FIC1 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_FIC1_INIT_CRD
value|0xe0210
end_define

begin_comment
comment|/*  * [RW 1] Arbitration between Input Arbiter groups: 0 - fair Round-Robin;  * - strict priority defined by ~ucm_registers_gr_ag_pr.gr_ag_pr;  * ~ucm_registers_gr_ld0_pr.gr_ld0_pr and  * ~ucm_registers_gr_ld1_pr.gr_ld1_pr.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_GR_ARB_TYPE
value|0xe0144
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC0) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Store channel group is  * compliment to the others.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_GR_LD0_PR
value|0xe014c
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC1) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Store channel group is  * compliment to the others.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_GR_LD1_PR
value|0xe0150
end_define

begin_comment
comment|/* [RW 2] The queue index for invalidate counter flag decision. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_INV_CFLG_Q
value|0xe00e4
end_define

begin_comment
comment|/*  * [RW 5] The number of double REG-pairs; loaded from the STORM context an  * sent to STORM; for a specific connection type. the double REG-pairs are  * used in order to align to STORM context row size of 128 bits. The offset  * of these data in the STORM context is always 0. Index _i stands for the  * connection type (one of 16).  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_0
value|0xe0054
end_define

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_1
value|0xe0058
end_define

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_2
value|0xe005c
end_define

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_3
value|0xe0060
end_define

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_4
value|0xe0064
end_define

begin_define
define|#
directive|define
name|UCM_REG_N_SM_CTX_LD_5
value|0xe0068
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM0_0
value|0xe0110
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM0_1
value|0xe0114
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM1_0
value|0xe0118
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM1_1
value|0xe011c
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM2_0
value|0xe0120
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM2_1
value|0xe0124
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM3_0
value|0xe0128
end_define

begin_define
define|#
directive|define
name|UCM_REG_PHYS_QNUM3_1
value|0xe012c
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers formatting in case of stop done. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_STOP_EVNT_ID
value|0xe00ac
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the STORM interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_STORM_LENGTH_MIS
value|0xe0154
end_define

begin_comment
comment|/*  * [RW 1] STORM - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_STORM_UCM_IFEN
value|0xe0010
end_define

begin_comment
comment|/*  * [RW 3] The weight of the STORM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_STORM_WEIGHT
value|0xe00b0
end_define

begin_comment
comment|/*  * [RW 4] Timers output initial credit. Max credit available - 15.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 4 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TM_INIT_CRD
value|0xe021c
end_define

begin_comment
comment|/* [RW 28] The CM header for Timers expiration command. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TM_UCM_HDR
value|0xe009c
end_define

begin_comment
comment|/*  * [RW 1] Timers - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TM_UCM_IFEN
value|0xe001c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the Timers input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TM_WEIGHT
value|0xe00d4
end_define

begin_comment
comment|/*  * [RW 1] Input tsem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TSEM_IFEN
value|0xe0024
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the tsem interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TSEM_LENGTH_MIS
value|0xe015c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input tsem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_TSEM_WEIGHT
value|0xe00b4
end_define

begin_comment
comment|/*  * [RW 1] CM - CFC Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_CFC_IFEN
value|0xe0044
end_define

begin_comment
comment|/* [RW 11] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_INT_MASK
value|0xe01d4
end_define

begin_comment
comment|/* [R 11] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_INT_STS
value|0xe01c8
end_define

begin_comment
comment|/* [R 27] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_PRTY_STS
value|0xe01d8
end_define

begin_comment
comment|/*  * [RW 2] The size of AG context region 0 in REG-pairs. Designates the M  * REG-pair number (e.g. if region 0 is 6 REG-pairs; the value should be 5).  * Is used to determine the number of the AG context REG-pairs written back;  * when the Reg1WbFlg isn't set.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_REG0_SZ
value|0xe00dc
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 0 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_STORM0_IFEN
value|0xe0004
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 1 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_STORM1_IFEN
value|0xe0008
end_define

begin_comment
comment|/*  * [RW 1] CM - Timers Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_TM_IFEN
value|0xe0020
end_define

begin_comment
comment|/*  * [RW 1] CM - QM Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_UQM_IFEN
value|0xe000c
end_define

begin_comment
comment|/* [RW 1] If set the Q index; received from the QM is inserted to event ID. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UCM_UQM_USE_Q
value|0xe00d8
end_define

begin_comment
comment|/*  * [RW 6] QM output initial credit. Max credit available - 32.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 32 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_INIT_CRD
value|0xe0220
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (primary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_P_WEIGHT
value|0xe00cc
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (secondary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_S_WEIGHT
value|0xe00d0
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (primary). */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_UCM_HDR_P
value|0xe0094
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (secondary). */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_UCM_HDR_S
value|0xe0098
end_define

begin_comment
comment|/*  * [RW 1] QM - CM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_UQM_UCM_IFEN
value|0xe0014
end_define

begin_comment
comment|/*  * [RW 1] Input SDM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_USDM_IFEN
value|0xe0018
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the SDM interface is detected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_USDM_LENGTH_MIS
value|0xe0158
end_define

begin_comment
comment|/*  * [RW 3] The weight of the SDM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_USDM_WEIGHT
value|0xe00c8
end_define

begin_comment
comment|/*  * [RW 1] Input xsem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XSEM_IFEN
value|0xe002c
end_define

begin_comment
comment|/*  * [RC 1] Set when the message length mismatch (relative to last indication  * at the xsem interface isdetected.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XSEM_LENGTH_MIS
value|0xe0164
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input xsem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XSEM_WEIGHT
value|0xe00bc
end_define

begin_comment
comment|/*  * [RW 20] Indirect access to the descriptor table of the XX protectio  * mechanism. The fields are:[5:0] - message length; 14:6] - message  * pointer; 19:15] - next pointer.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_DESCR_TABLE
value|0xe0280
end_define

begin_define
define|#
directive|define
name|UCM_REG_XX_DESCR_TABLE_SIZE
value|32
end_define

begin_comment
comment|/* [R 6] Use to read the XX protection Free counter. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_FREE
value|0xe016c
end_define

begin_comment
comment|/*  * [RW 6] Initial value for the credit counter; responsible for fulfillin  * of the Input Stage XX protection buffer by the XX protection pending  * messages. Write writes the initial credit value; read returns the current  * value of the credit counter. Must be initialized to 12 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_INIT_CRD
value|0xe0224
end_define

begin_comment
comment|/*  * [RW 6] The maximum number of pending messages; which may be stored in X  * protection. ~ucm_registers_xx_free.xx_free read on read.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_MSG_NUM
value|0xe0228
end_define

begin_comment
comment|/* [RW 8] The Event ID; sent to the STORM in case of XX overflow. */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_OVFL_EVNT_ID
value|0xe004c
end_define

begin_comment
comment|/*  * [RW 16] Indirect access to the XX table of the XX protection mechanism  * The fields are: [4:0] - tail pointer; 10:5] - Link List size; 15:11] -  * header pointer.  */
end_comment

begin_define
define|#
directive|define
name|UCM_REG_XX_TABLE
value|0xe0300
end_define

begin_comment
comment|/* [RW 8] The event id for aggregated interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_0
value|0xc4038
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_1
value|0xc403c
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_2
value|0xc4040
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_4
value|0xc4048
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_5
value|0xc404c
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_EVENT_6
value|0xc4050
end_define

begin_comment
comment|/*  * [RW 1] For each aggregated interrupt index whether the mode is normal (0  * or auto-mask-mode (1)  */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_MODE_0
value|0xc41b8
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_MODE_1
value|0xc41bc
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_MODE_4
value|0xc41c8
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_MODE_5
value|0xc41cc
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_MODE_6
value|0xc41d0
end_define

begin_comment
comment|/* [RW 1] The T bit for aggregated interrupt 5 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_T_5
value|0xc40cc
end_define

begin_define
define|#
directive|define
name|USDM_REG_AGG_INT_T_6
value|0xc40d0
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the cfc_rsp lcid */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CFC_RSP_START_ADDR
value|0xc4008
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #0 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CMP_COUNTER_MAX0
value|0xc401c
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #1 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CMP_COUNTER_MAX1
value|0xc4020
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #2 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CMP_COUNTER_MAX2
value|0xc4024
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #3 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CMP_COUNTER_MAX3
value|0xc4028
end_define

begin_comment
comment|/*  * [RW 13] The start address in the internal RAM for the completio  * counters.  */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_CMP_COUNTER_START_ADDR
value|0xc400c
end_define

begin_define
define|#
directive|define
name|USDM_REG_ENABLE_IN1
value|0xc4238
end_define

begin_define
define|#
directive|define
name|USDM_REG_ENABLE_IN2
value|0xc423c
end_define

begin_define
define|#
directive|define
name|USDM_REG_ENABLE_OUT1
value|0xc4240
end_define

begin_define
define|#
directive|define
name|USDM_REG_ENABLE_OUT2
value|0xc4244
end_define

begin_comment
comment|/*  * [RW 4] The initial number of messages that can be sent to the pxp contro  * interface without receiving any ACK.  */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_INIT_CREDIT_PXP_CTRL
value|0xc44c0
end_define

begin_comment
comment|/* [ST 32] The number of ACK after placement messages received */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_ACK_AFTER_PLACE
value|0xc4280
end_define

begin_comment
comment|/* [ST 32] The number of packet end messages received from the parser */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_PKT_END_MSG
value|0xc4278
end_define

begin_comment
comment|/* [ST 32] The number of requests received from the pxp async if */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_PXP_ASYNC_REQ
value|0xc427c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 0 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q0_CMD
value|0xc4248
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 10 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q10_CMD
value|0xc4270
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 11 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q11_CMD
value|0xc4274
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 1 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q1_CMD
value|0xc424c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 2 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q2_CMD
value|0xc4250
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 3 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q3_CMD
value|0xc4254
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 4 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q4_CMD
value|0xc4258
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 5 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q5_CMD
value|0xc425c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 6 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q6_CMD
value|0xc4260
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 7 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q7_CMD
value|0xc4264
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 8 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q8_CMD
value|0xc4268
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 9 */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_NUM_OF_Q9_CMD
value|0xc426c
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the packet end message */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_PCK_END_MSG_START_ADDR
value|0xc4014
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for queue counters */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_Q_COUNTER_START_ADDR
value|0xc4010
end_define

begin_comment
comment|/* [R 1] pxp_ctrl rd_data fifo empty in sdm_dma_rsp block */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_RSP_PXP_CTRL_RDATA_EMPTY
value|0xc4550
end_define

begin_comment
comment|/* [R 1] parser fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_SYNC_PARSER_EMPTY
value|0xc4558
end_define

begin_comment
comment|/* [R 1] parser serial fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_SYNC_SYNC_EMPTY
value|0xc4560
end_define

begin_comment
comment|/*  * [RW 32] Tick for timer counter. Applicable only whe  * ~usdm_registers_timer_tick_enable.timer_tick_enable =1  */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_TIMER_TICK
value|0xc4000
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_MASK_0
value|0xc42a0
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_MASK_1
value|0xc42b0
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_STS_0
value|0xc4294
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_STS_1
value|0xc42a4
end_define

begin_comment
comment|/* [RW 11] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_USDM_PRTY_MASK
value|0xc42c0
end_define

begin_comment
comment|/* [R 11] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|USDM_REG_USDM_PRTY_STS
value|0xc42b4
end_define

begin_comment
comment|/* [RW 5] The number of time_slots in the arbitration cycle */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_CYCLE_SIZE
value|0x300034
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 0. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_ELEMENT0
value|0x300020
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 1. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~usem_registers_arb_element0.arb_element0  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_ELEMENT1
value|0x300024
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 2. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~usem_registers_arb_element0.arb_element0  * and ~usem_registers_arb_element1.arb_element1  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_ELEMENT2
value|0x300028
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 3. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.Could  * not be equal to register ~usem_registers_arb_element0.arb_element0 and  * ~usem_registers_arb_element1.arb_element1 and  * ~usem_registers_arb_element2.arb_element2  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_ELEMENT3
value|0x30002c
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 4. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~usem_registers_arb_element0.arb_element0  * and ~usem_registers_arb_element1.arb_element1 and  * ~usem_registers_arb_element2.arb_element2 and  * ~usem_registers_arb_element3.arb_element3  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_ARB_ELEMENT4
value|0x300030
end_define

begin_define
define|#
directive|define
name|USEM_REG_ENABLE_IN
value|0x3000a4
end_define

begin_define
define|#
directive|define
name|USEM_REG_ENABLE_OUT
value|0x3000a8
end_define

begin_comment
comment|/*  * [RW 32] This address space contains all registers and memories that ar  * placed in SEM_FAST block. The SEM_FAST registers are described in  * appendix B. In order to access the sem_fast registers the base address  * ~fast_memory.fast_memory should be added to eachsem_fast register offset.  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_FAST_MEMORY
value|0x320000
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC0 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_FIC0_DISABLE
value|0x300224
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC1 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_FIC1_DISABLE
value|0x300234
end_define

begin_comment
comment|/*  * [RW 15] Interrupt table Read and write access to it is not possible i  * the middle of the work  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_INT_TABLE
value|0x300400
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC0  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FIC0
value|0x300000
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC1  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FIC1
value|0x300004
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC0  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FOC0
value|0x300008
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC1  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FOC1
value|0x30000c
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC2  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FOC2
value|0x300010
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC3  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_MSG_NUM_FOC3
value|0x300014
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from the passive buffer May be update  * during run_time by the microcode  */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_PAS_DISABLE
value|0x30024c
end_define

begin_comment
comment|/* [WB 128] Debug only. Passive buffer memory */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_PASSIVE_BUFFER
value|0x302000
end_define

begin_comment
comment|/* [WB 46] pram memory. B45 is parity; b[44:0] - data. */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_PRAM
value|0x340000
end_define

begin_comment
comment|/* [R 16] Valid sleeping threads indication have bit per thread */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_SLEEP_THREADS_VALID
value|0x30026c
end_define

begin_comment
comment|/* [R 1] EXT_STORE FIFO is empty in sem_slow_ls_ext */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_SLOW_EXT_STORE_EMPTY
value|0x3002a0
end_define

begin_comment
comment|/* [RW 16] List of free threads . There is a bit per thread. */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_THREADS_LIST
value|0x3002e4
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 0 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_0_AS
value|0x300038
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 10 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_10_AS
value|0x300060
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 11 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_11_AS
value|0x300064
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 12 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_12_AS
value|0x300068
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 13 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_13_AS
value|0x30006c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 14 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_14_AS
value|0x300070
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 15 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_15_AS
value|0x300074
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 16 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_16_AS
value|0x300078
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 17 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_17_AS
value|0x30007c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 18 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_18_AS
value|0x300080
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 1 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_1_AS
value|0x30003c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 2 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_2_AS
value|0x300040
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 3 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_3_AS
value|0x300044
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 4 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_4_AS
value|0x300048
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 5 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_5_AS
value|0x30004c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 6 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_6_AS
value|0x300050
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 7 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_7_AS
value|0x300054
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 8 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_8_AS
value|0x300058
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 9 */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_TS_9_AS
value|0x30005c
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_MASK_0
value|0x300110
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_MASK_1
value|0x300120
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_STS_0
value|0x300104
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_STS_1
value|0x300114
end_define

begin_comment
comment|/* [RW 32] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_MASK_0
value|0x300130
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_MASK_1
value|0x300140
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_STS_0
value|0x300124
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_STS_1
value|0x300134
end_define

begin_comment
comment|/* [RW 2] The queue index for registration on Aux1 counter flag. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_AUX1_Q
value|0x20134
end_define

begin_comment
comment|/* [RW 2] Per each decision rule the queue index to register to. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_AUX_CNT_FLG_Q_19
value|0x201b0
end_define

begin_comment
comment|/* [R 5] Used to read the XX protection CAM occupancy counter. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CAM_OCCUP
value|0x20244
end_define

begin_comment
comment|/*  * [RW 1] CDU AG read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CDU_AG_RD_IFEN
value|0x20044
end_define

begin_comment
comment|/*  * [RW 1] CDU AG write Interface enable. If 0 - the request and valid inpu  * are disregarded; all other signals are treated as usual; if 1 - normal  * activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CDU_AG_WR_IFEN
value|0x20040
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM read Interface enable. If 0 - the request input i  * disregarded; valid output is deasserted; all other signals are treated as  * usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CDU_SM_RD_IFEN
value|0x2004c
end_define

begin_comment
comment|/*  * [RW 1] CDU STORM write Interface enable. If 0 - the request and vali  * input is disregarded; all other signals are treated as usual; if 1 -  * normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CDU_SM_WR_IFEN
value|0x20048
end_define

begin_comment
comment|/*  * [RW 4] CFC output initial credit. Max credit available - 15.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 1 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CFC_INIT_CRD
value|0x20404
end_define

begin_comment
comment|/*  * [RW 3] The weight of the CP input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CP_WEIGHT
value|0x200dc
end_define

begin_comment
comment|/*  * [RW 1] Input csem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CSEM_IFEN
value|0x20028
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the csem interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CSEM_LENGTH_MIS
value|0x20228
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input csem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_CSEM_WEIGHT
value|0x200c4
end_define

begin_comment
comment|/*  * [RW 1] Input dorq Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_DORQ_IFEN
value|0x20030
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the dorq interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_DORQ_LENGTH_MIS
value|0x20230
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input dorq in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_DORQ_WEIGHT
value|0x200cc
end_define

begin_comment
comment|/* [RW 8] The Event ID in case the ErrorFlg input message bit is set. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_ERR_EVNT_ID
value|0x200b0
end_define

begin_comment
comment|/* [RW 28] The CM erroneous header for QM and Timers formatting. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_ERR_XCM_HDR
value|0x200ac
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers expiration. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_EXPR_EVNT_ID
value|0x200b4
end_define

begin_comment
comment|/*  * [RW 8] FIC0 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_FIC0_INIT_CRD
value|0x2040c
end_define

begin_comment
comment|/*  * [RW 8] FIC1 output initial credit. Max credit available - 255.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 64 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_FIC1_INIT_CRD
value|0x20410
end_define

begin_define
define|#
directive|define
name|XCM_REG_GLB_DEL_ACK_MAX_CNT_0
value|0x20118
end_define

begin_define
define|#
directive|define
name|XCM_REG_GLB_DEL_ACK_MAX_CNT_1
value|0x2011c
end_define

begin_define
define|#
directive|define
name|XCM_REG_GLB_DEL_ACK_TMR_VAL_0
value|0x20108
end_define

begin_define
define|#
directive|define
name|XCM_REG_GLB_DEL_ACK_TMR_VAL_1
value|0x2010c
end_define

begin_comment
comment|/*  * [RW 1] Arbitratiojn between Input Arbiter groups: 0 - fair Round-Robin;  * - strict priority defined by ~xcm_registers_gr_ag_pr.gr_ag_pr;  * ~xcm_registers_gr_ld0_pr.gr_ld0_pr and  * ~xcm_registers_gr_ld1_pr.gr_ld1_pr.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_GR_ARB_TYPE
value|0x2020c
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC0) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Channel group is the  * compliment of the other 3 groups.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_GR_LD0_PR
value|0x20214
end_define

begin_comment
comment|/*  * [RW 2] Load (FIC1) channel group priority. The lowest priority is 0; th  * highest priority is 3. It is supposed that the Channel group is the  * compliment of the other 3 groups.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_GR_LD1_PR
value|0x20218
end_define

begin_comment
comment|/*  * [RW 1] Input nig0 Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_NIG0_IFEN
value|0x20038
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the nig0 interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_NIG0_LENGTH_MIS
value|0x20238
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input nig0 in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_NIG0_WEIGHT
value|0x200d4
end_define

begin_comment
comment|/*  * [RW 1] Input nig1 Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_NIG1_IFEN
value|0x2003c
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the nig1 interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_NIG1_LENGTH_MIS
value|0x2023c
end_define

begin_comment
comment|/*  * [RW 5] The number of double REG-pairs; loaded from the STORM context an  * sent to STORM; for a specific connection type. The double REG-pairs are  * used in order to align to STORM context row size of 128 bits. The offset  * of these data in the STORM context is always 0. Index _i stands for the  * connection type (one of 16).  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_0
value|0x20060
end_define

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_1
value|0x20064
end_define

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_2
value|0x20068
end_define

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_3
value|0x2006c
end_define

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_4
value|0x20070
end_define

begin_define
define|#
directive|define
name|XCM_REG_N_SM_CTX_LD_5
value|0x20074
end_define

begin_comment
comment|/*  * [RW 1] Input pbf Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_PBF_IFEN
value|0x20034
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the pbf interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_PBF_LENGTH_MIS
value|0x20234
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input pbf in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_PBF_WEIGHT
value|0x200d0
end_define

begin_define
define|#
directive|define
name|XCM_REG_PHYS_QNUM3_0
value|0x20100
end_define

begin_define
define|#
directive|define
name|XCM_REG_PHYS_QNUM3_1
value|0x20104
end_define

begin_comment
comment|/* [RW 8] The Event ID for Timers formatting in case of stop done. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_STOP_EVNT_ID
value|0x200b8
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the STORM interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_STORM_LENGTH_MIS
value|0x2021c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the STORM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_STORM_WEIGHT
value|0x200bc
end_define

begin_comment
comment|/*  * [RW 1] STORM - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_STORM_XCM_IFEN
value|0x20010
end_define

begin_comment
comment|/*  * [RW 4] Timers output initial credit. Max credit available - 15.Writ  * writes the initial credit value; read returns the current value of the  * credit counter. Must be initialized to 4 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TM_INIT_CRD
value|0x2041c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the Timers input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TM_WEIGHT
value|0x200ec
end_define

begin_comment
comment|/* [RW 28] The CM header for Timers expiration command. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TM_XCM_HDR
value|0x200a8
end_define

begin_comment
comment|/*  * [RW 1] Timers - CM Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TM_XCM_IFEN
value|0x2001c
end_define

begin_comment
comment|/*  * [RW 1] Input tsem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TSEM_IFEN
value|0x20024
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the tsem interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TSEM_LENGTH_MIS
value|0x20224
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input tsem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_TSEM_WEIGHT
value|0x200c0
end_define

begin_comment
comment|/* [RW 2] The queue index for registration on UNA greater NXT decision rule. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_UNA_GT_NXT_Q
value|0x20120
end_define

begin_comment
comment|/*  * [RW 1] Input usem Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_USEM_IFEN
value|0x2002c
end_define

begin_comment
comment|/*  * [RC 1] Message length mismatch (relative to last indication) at the use  * interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_USEM_LENGTH_MIS
value|0x2022c
end_define

begin_comment
comment|/*  * [RW 3] The weight of the input usem in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_USEM_WEIGHT
value|0x200c8
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_CMD00
value|0x201d4
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_CMD01
value|0x201d8
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_CMD10
value|0x201dc
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_CMD11
value|0x201e0
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_UPD_VAL00
value|0x201e4
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_UPD_VAL01
value|0x201e8
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_UPD_VAL10
value|0x201ec
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_CNT_UPD_VAL11
value|0x201f0
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_SET_TMR_CNT_FLG_CMD00
value|0x201c4
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_SET_TMR_CNT_FLG_CMD01
value|0x201c8
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_SET_TMR_CNT_FLG_CMD10
value|0x201cc
end_define

begin_define
define|#
directive|define
name|XCM_REG_WU_DA_SET_TMR_CNT_FLG_CMD11
value|0x201d0
end_define

begin_comment
comment|/*  * [RW 1] CM - CFC Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_CFC_IFEN
value|0x20050
end_define

begin_comment
comment|/* [RW 14] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_INT_MASK
value|0x202b4
end_define

begin_comment
comment|/* [R 14] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_INT_STS
value|0x202a8
end_define

begin_comment
comment|/* [R 30] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_PRTY_STS
value|0x202b8
end_define

begin_comment
comment|/*  * [RW 4] The size of AG context region 0 in REG-pairs. Designates the M  * REG-pair number (e.g. if region 0 is 6 REG-pairs; the value should be 5).  * Is used to determine the number of the AG context REG-pairs written back;  * when the Reg1WbFlg isn't set.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_REG0_SZ
value|0x200f4
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 0 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_STORM0_IFEN
value|0x20004
end_define

begin_comment
comment|/*  * [RW 1] CM - STORM 1 Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_STORM1_IFEN
value|0x20008
end_define

begin_comment
comment|/*  * [RW 1] CM - Timers Interface enable. If 0 - the valid input i  * disregarded; acknowledge output is deasserted; all other signals are  * treated as usual; if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_TM_IFEN
value|0x20020
end_define

begin_comment
comment|/*  * [RW 1] CM - QM Interface enable. If 0 - the acknowledge input i  * disregarded; valid is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_XQM_IFEN
value|0x2000c
end_define

begin_comment
comment|/* [RW 1] If set the Q index; received from the QM is inserted to event ID. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XCM_XQM_USE_Q
value|0x200f0
end_define

begin_comment
comment|/* [RW 4] The value by which CFC updates the activity counter at QM bypass. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_BYP_ACT_UPD
value|0x200fc
end_define

begin_comment
comment|/*  * [RW 6] QM output initial credit. Max credit available - 32.Write write  * the initial credit value; read returns the current value of the credit  * counter. Must be initialized to 32 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_INIT_CRD
value|0x20420
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (primary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_P_WEIGHT
value|0x200e4
end_define

begin_comment
comment|/*  * [RW 3] The weight of the QM (secondary) input in the WRR mechanism.  * stands for weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_S_WEIGHT
value|0x200e8
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (primary). */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_XCM_HDR_P
value|0x200a0
end_define

begin_comment
comment|/* [RW 28] The CM header value for QM request (secondary). */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_XCM_HDR_S
value|0x200a4
end_define

begin_comment
comment|/*  * [RW 1] QM - CM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XQM_XCM_IFEN
value|0x20014
end_define

begin_comment
comment|/*  * [RW 1] Input SDM Interface enable. If 0 - the valid input is disregarded  * acknowledge output is deasserted; all other signals are treated as usual;  * if 1 - normal activity.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XSDM_IFEN
value|0x20018
end_define

begin_comment
comment|/*  * [RC 1] Set at message length mismatch (relative to last indication) a  * the SDM interface.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XSDM_LENGTH_MIS
value|0x20220
end_define

begin_comment
comment|/*  * [RW 3] The weight of the SDM input in the WRR mechanism. 0 stands fo  * weight 8 (the most prioritised); 1 stands for weight 1(least  * prioritised); 2 stands for weight 2; tc.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XSDM_WEIGHT
value|0x200e0
end_define

begin_comment
comment|/*  * [RW 17] Indirect access to the descriptor table of the XX protectio  * mechanism. The fields are: [5:0] - message length; 11:6] - message  * pointer; 16:12] - next pointer.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_DESCR_TABLE
value|0x20480
end_define

begin_define
define|#
directive|define
name|XCM_REG_XX_DESCR_TABLE_SIZE
value|32
end_define

begin_comment
comment|/* [R 6] Used to read the XX protection Free counter. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_FREE
value|0x20240
end_define

begin_comment
comment|/*  * [RW 6] Initial value for the credit counter; responsible for fulfillin  * of the Input Stage XX protection buffer by the XX protection pending  * messages. Max credit available - 3.Write writes the initial credit value;  * read returns the current value of the credit counter. Must be initialized  * to 2 at start-up.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_INIT_CRD
value|0x20424
end_define

begin_comment
comment|/*  * [RW 6] The maximum number of pending messages; which may be stored in X  * protection. ~xcm_registers_xx_free.xx_free read on read.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_MSG_NUM
value|0x20428
end_define

begin_comment
comment|/* [RW 8] The Event ID; sent to the STORM in case of XX overflow. */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_OVFL_EVNT_ID
value|0x20058
end_define

begin_comment
comment|/*  * [RW 16] Indirect access to the XX table of the XX protection mechanism  * The fields are:[4:0] - tail pointer; 9:5] - Link List size; 14:10] -  * header pointer.  */
end_comment

begin_define
define|#
directive|define
name|XCM_REG_XX_TABLE
value|0x20500
end_define

begin_comment
comment|/* [RW 8] The event id for aggregated interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_0
value|0x166038
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_1
value|0x16603c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_10
value|0x166060
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_11
value|0x166064
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_12
value|0x166068
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_13
value|0x16606c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_14
value|0x166070
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_2
value|0x166040
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_3
value|0x166044
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_4
value|0x166048
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_5
value|0x16604c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_6
value|0x166050
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_7
value|0x166054
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_8
value|0x166058
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_EVENT_9
value|0x16605c
end_define

begin_comment
comment|/*  * [RW 1] For each aggregated interrupt index whether the mode is normal (0  * or auto-mask-mode (1)  */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_MODE_0
value|0x1661b8
end_define

begin_define
define|#
directive|define
name|XSDM_REG_AGG_INT_MODE_1
value|0x1661bc
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for the cfc_rsp lcid */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CFC_RSP_START_ADDR
value|0x166008
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #0 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CMP_COUNTER_MAX0
value|0x16601c
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #1 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CMP_COUNTER_MAX1
value|0x166020
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #2 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CMP_COUNTER_MAX2
value|0x166024
end_define

begin_comment
comment|/* [RW 16] The maximum value of the competion counter #3 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CMP_COUNTER_MAX3
value|0x166028
end_define

begin_comment
comment|/*  * [RW 13] The start address in the internal RAM for the completio  * counters.  */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_CMP_COUNTER_START_ADDR
value|0x16600c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_ENABLE_IN1
value|0x166238
end_define

begin_define
define|#
directive|define
name|XSDM_REG_ENABLE_IN2
value|0x16623c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_ENABLE_OUT1
value|0x166240
end_define

begin_define
define|#
directive|define
name|XSDM_REG_ENABLE_OUT2
value|0x166244
end_define

begin_comment
comment|/*  * [RW 4] The initial number of messages that can be sent to the pxp contro  * interface without receiving any ACK.  */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_INIT_CREDIT_PXP_CTRL
value|0x1664bc
end_define

begin_comment
comment|/* [ST 32] The number of ACK after placement messages received */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_ACK_AFTER_PLACE
value|0x16627c
end_define

begin_comment
comment|/* [ST 32] The number of packet end messages received from the parser */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_PKT_END_MSG
value|0x166274
end_define

begin_comment
comment|/* [ST 32] The number of requests received from the pxp async if */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_PXP_ASYNC_REQ
value|0x166278
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 0 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q0_CMD
value|0x166248
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 10 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q10_CMD
value|0x16626c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 11 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q11_CMD
value|0x166270
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 1 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q1_CMD
value|0x16624c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 3 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q3_CMD
value|0x166250
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 4 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q4_CMD
value|0x166254
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 5 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q5_CMD
value|0x166258
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 6 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q6_CMD
value|0x16625c
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 7 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q7_CMD
value|0x166260
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 8 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q8_CMD
value|0x166264
end_define

begin_comment
comment|/* [ST 32] The number of commands received in queue 9 */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_NUM_OF_Q9_CMD
value|0x166268
end_define

begin_comment
comment|/* [RW 13] The start address in the internal RAM for queue counters */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_Q_COUNTER_START_ADDR
value|0x166010
end_define

begin_comment
comment|/* [R 1] pxp_ctrl rd_data fifo empty in sdm_dma_rsp block */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_RSP_PXP_CTRL_RDATA_EMPTY
value|0x166548
end_define

begin_comment
comment|/* [R 1] parser fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_SYNC_PARSER_EMPTY
value|0x166550
end_define

begin_comment
comment|/* [R 1] parser serial fifo empty in sdm_sync block */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_SYNC_SYNC_EMPTY
value|0x166558
end_define

begin_comment
comment|/*  * [RW 32] Tick for timer counter. Applicable only whe  * ~xsdm_registers_timer_tick_enable.timer_tick_enable =1  */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_TIMER_TICK
value|0x166000
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_MASK_0
value|0x16629c
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_MASK_1
value|0x1662ac
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_STS_0
value|0x166290
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_STS_1
value|0x1662a0
end_define

begin_comment
comment|/* [RW 11] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_PRTY_MASK
value|0x1662bc
end_define

begin_comment
comment|/* [R 11] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_PRTY_STS
value|0x1662b0
end_define

begin_comment
comment|/* [RW 5] The number of time_slots in the arbitration cycle */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_CYCLE_SIZE
value|0x280034
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 0. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_ELEMENT0
value|0x280020
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 1. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~xsem_registers_arb_element0.arb_element0  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_ELEMENT1
value|0x280024
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 2. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~xsem_registers_arb_element0.arb_element0  * and ~xsem_registers_arb_element1.arb_element1  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_ELEMENT2
value|0x280028
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 3. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.Could  * not be equal to register ~xsem_registers_arb_element0.arb_element0 and  * ~xsem_registers_arb_element1.arb_element1 and  * ~xsem_registers_arb_element2.arb_element2  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_ELEMENT3
value|0x28002c
end_define

begin_comment
comment|/*  * [RW 3] The source that is associated with arbitration element 4. Sourc  * decoding is: 0- foc0; 1-fic1; 2-sleeping thread with priority 0; 3-  * sleeping thread with priority 1; 4- sleeping thread with priority 2.  * Could not be equal to register ~xsem_registers_arb_element0.arb_element0  * and ~xsem_registers_arb_element1.arb_element1 and  * ~xsem_registers_arb_element2.arb_element2 and  * ~xsem_registers_arb_element3.arb_element3  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_ARB_ELEMENT4
value|0x280030
end_define

begin_define
define|#
directive|define
name|XSEM_REG_ENABLE_IN
value|0x2800a4
end_define

begin_define
define|#
directive|define
name|XSEM_REG_ENABLE_OUT
value|0x2800a8
end_define

begin_comment
comment|/*  * [RW 32] This address space contains all registers and memories that ar  * placed in SEM_FAST block. The SEM_FAST registers are described in  * appendix B. In order to access the sem_fast registers the base address  * ~fast_memory.fast_memory should be added to eachsem_fast register offset.  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_FAST_MEMORY
value|0x2a0000
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC0 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_FIC0_DISABLE
value|0x280224
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from FIC1 May be updated during run_tim  * by the microcode  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_FIC1_DISABLE
value|0x280234
end_define

begin_comment
comment|/*  * [RW 15] Interrupt table Read and write access to it is not possible i  * the middle of the work  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_INT_TABLE
value|0x280400
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC0  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FIC0
value|0x280000
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that entered throug  * FIC1  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FIC1
value|0x280004
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC0  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FOC0
value|0x280008
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC1  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FOC1
value|0x28000c
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC2  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FOC2
value|0x280010
end_define

begin_comment
comment|/*  * [ST 24] Statistics register. The number of messages that were sent t  * FOC3  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_MSG_NUM_FOC3
value|0x280014
end_define

begin_comment
comment|/*  * [RW 1] Disables input messages from the passive buffer May be update  * during run_time by the microcode  */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_PAS_DISABLE
value|0x28024c
end_define

begin_comment
comment|/* [WB 128] Debug only. Passive buffer memory */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_PASSIVE_BUFFER
value|0x282000
end_define

begin_comment
comment|/* [WB 46] pram memory. B45 is parity; b[44:0] - data. */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_PRAM
value|0x2c0000
end_define

begin_comment
comment|/* [R 16] Valid sleeping threads indication have bit per thread */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_SLEEP_THREADS_VALID
value|0x28026c
end_define

begin_comment
comment|/* [R 1] EXT_STORE FIFO is empty in sem_slow_ls_ext */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_SLOW_EXT_STORE_EMPTY
value|0x2802a0
end_define

begin_comment
comment|/* [RW 16] List of free threads . There is a bit per thread. */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_THREADS_LIST
value|0x2802e4
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 0 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_0_AS
value|0x280038
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 10 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_10_AS
value|0x280060
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 11 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_11_AS
value|0x280064
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 12 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_12_AS
value|0x280068
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 13 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_13_AS
value|0x28006c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 14 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_14_AS
value|0x280070
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 15 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_15_AS
value|0x280074
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 16 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_16_AS
value|0x280078
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 17 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_17_AS
value|0x28007c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 18 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_18_AS
value|0x280080
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 1 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_1_AS
value|0x28003c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 2 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_2_AS
value|0x280040
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 3 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_3_AS
value|0x280044
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 4 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_4_AS
value|0x280048
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 5 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_5_AS
value|0x28004c
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 6 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_6_AS
value|0x280050
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 7 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_7_AS
value|0x280054
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 8 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_8_AS
value|0x280058
end_define

begin_comment
comment|/* [RW 3] The arbitration scheme of time_slot 9 */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_TS_9_AS
value|0x28005c
end_define

begin_comment
comment|/* [RW 32] Interrupt mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_MASK_0
value|0x280110
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_MASK_1
value|0x280120
end_define

begin_comment
comment|/* [R 32] Interrupt register #0 read */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_STS_0
value|0x280104
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_STS_1
value|0x280114
end_define

begin_comment
comment|/* [RW 32] Parity mask register #0 read/write */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_MASK_0
value|0x280130
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_MASK_1
value|0x280140
end_define

begin_comment
comment|/* [R 32] Parity register #0 read */
end_comment

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_STS_0
value|0x280124
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_STS_1
value|0x280134
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ACCESS_ENABLE_EN
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ACCESS_ENABLE_WR_EN
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ADDR_NVM_ADDR_VALUE
value|(0xffffffL<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_CFG4_FLASH_SIZE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_DOIT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_DONE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_FIRST
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_LAST
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_WR
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_ARB1
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_REQ_CLR1
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_REQ_SET1
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_BMAC_CONTROL
value|(0x00<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_BMAC_XGXS_CONTROL
value|(0x01<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_CNT_MAX_SIZE
value|(0x05<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_CONTROL
value|(0x21<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_LLFC_MSG_FLDS
value|(0x46<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_MAX_SIZE
value|(0x23<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_STAT_GR64
value|(0x26<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_STAT_GRIPJ
value|(0x42<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_CONTROL
value|(0x07<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_MAX_SIZE
value|(0x09<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_PAUSE_THRESHOLD
value|(0x0A<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_SOURCE_ADDR
value|(0x08<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_STAT_GTBYT
value|(0x20<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_STAT_GTPKT
value|(0x0C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_BMAC_CONTROL
value|(0x00<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_BMAC_XGXS_CONTROL
value|(0x01<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_PFC_CONTROL
value|(0x06<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_CONTROL
value|(0x3A<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_LLFC_MSG_FLDS
value|(0x62<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_MAX_SIZE
value|(0x3C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_CONTROL
value|(0x1C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_MAX_SIZE
value|(0x1E<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_SOURCE_ADDR
value|(0x1D<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_1000MB_OVERRIDE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_100MB_OVERRIDE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_10MB_OVERRIDE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_2500MB_OVERRIDE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_OVERRIDE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_TRAFFIC
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_ADDRESS
value|(0L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_READ_45
value|(3L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_WRITE_45
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_DATA
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_START_BUSY
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_AUTO_POLL
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLAUSE_45
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLOCK_CNT
value|(0x3fL<<16)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLOCK_CNT_BITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_25G_MODE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_HALF_DUPLEX
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_GMII
value|(2L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_MII
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_MII_10M
value|(3L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_LED
value|0xc
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MAC_MATCH
value|0x10
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MDIO_COMM
value|0xac
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MDIO_MODE
value|0xb4
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_MODE
value|0xc8
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_MTU_SIZE
value|0x9c
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC
value|0x180
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC_28
value|0x1f4
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_MODE
value|0xbc
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_STAT_AC
value|0x280
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_STAT_AC_COUNT
value|22
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_FLOW_EN
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_KEEP_VLAN_TAG
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_PROMISCUOUS
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MTU_SIZE_JUMBO_ENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_EXT_PAUSE_EN
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_FLOW_EN
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_0
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_1
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_2
value|2
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_3
value|3
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_CLR_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_FLOAT
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_FLOAT_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INPUT_HI_Z
value|2
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_CLR_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_OUTPUT_CLR
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_OUTPUT_SET
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_SET_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_OUTPUT_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_PORT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_SET_POS
value|8
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_CLEAR
value|0x588
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_NIG
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_SET
value|0x584
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_CLEAR
value|0x598
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_BMAC0
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_EMAC0_HARD_CORE
value|(0x1<<14)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_SET
value|0x594
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_CLEAR
value|0x5a8
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_IDDQ
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN_SD
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_RSTB_HW
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_IDDQ
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN_SD
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_RSTB_HW
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_TXD_FIFO_RSTB
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_SET
value|0x5a4
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_4
value|4
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_5
value|5
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_7
value|7
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_CLR_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_FLOAT
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_FLOAT_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_INPUT_HI_Z
value|2
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_INT_OLD_SET_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_OUTPUT_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_SPIO_SET_POS
value|8
end_define

begin_define
define|#
directive|define
name|HW_LOCK_MAX_RESOURCE_VALUE
value|31
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_GPIO
value|1
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_MDIO
value|0
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_PORT0_ATT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_SPIO
value|2
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_UNDI
value|5
end_define

begin_define
define|#
directive|define
name|PRS_FLAG_OVERETH_IPV4
value|1
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_BRB_PARITY_ERROR
value|(1UL<<18)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CCM_HW_INTERRUPT
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CDU_HW_INTERRUPT
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CDU_PARITY_ERROR
value|(1UL<<8)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CFC_HW_INTERRUPT
value|(1UL<<7)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CFC_PARITY_ERROR
value|(1UL<<6)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSDM_HW_INTERRUPT
value|(1UL<<29)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSDM_PARITY_ERROR
value|(1UL<<28)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSEMI_HW_INTERRUPT
value|(1UL<<1)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSEMI_PARITY_ERROR
value|(1UL<<0)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DEBUG_PARITY_ERROR
value|(1UL<<18)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DMAE_HW_INTERRUPT
value|(1UL<<11)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DOORBELLQ_HW_INTERRUPT
value|(1UL<<13)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DOORBELLQ_PARITY_ERROR
value|(1UL<<12)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_0
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_1
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_IGU_PARITY_ERROR
value|(1UL<<12)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MISC_HW_INTERRUPT
value|(1UL<<15)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MISC_PARITY_ERROR
value|(1UL<<14)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PARSER_PARITY_ERROR
value|(1UL<<20)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PBCLIENT_PARITY_ERROR
value|(1UL<<0)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PBF_HW_INTERRUPT
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXP_HW_INTERRUPT
value|(1UL<<3)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXP_PARITY_ERROR
value|(1UL<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_HW_INTERRUPT
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR
value|(1UL<<4)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_QM_HW_INTERRUPT
value|(1UL<<3)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_QM_PARITY_ERROR
value|(1UL<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_SEARCHER_PARITY_ERROR
value|(1UL<<22)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_SPIO5
value|(1UL<<15)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TCM_HW_INTERRUPT
value|(1UL<<27)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TIMERS_HW_INTERRUPT
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSDM_HW_INTERRUPT
value|(1UL<<25)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSDM_PARITY_ERROR
value|(1UL<<24)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSEMI_HW_INTERRUPT
value|(1UL<<29)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSEMI_PARITY_ERROR
value|(1UL<<28)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UCM_HW_INTERRUPT
value|(1UL<<23)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UPB_HW_INTERRUPT
value|(1UL<<27)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UPB_PARITY_ERROR
value|(1UL<<26)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USDM_HW_INTERRUPT
value|(1UL<<21)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USDM_PARITY_ERROR
value|(1UL<<20)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USEMI_HW_INTERRUPT
value|(1UL<<25)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USEMI_PARITY_ERROR
value|(1UL<<24)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_VAUX_PCI_CORE_PARITY_ERROR
value|(1UL<<16)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XCM_HW_INTERRUPT
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSDM_HW_INTERRUPT
value|(1UL<<7)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSDM_PARITY_ERROR
value|(1UL<<6)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSEMI_HW_INTERRUPT
value|(1UL<<11)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSEMI_PARITY_ERROR
value|(1UL<<10)
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_0
value|0
end_define

begin_define
define|#
directive|define
name|EVEREST_GEN_ATTN_IN_USE_MASK
value|0x3ffe0
end_define

begin_define
define|#
directive|define
name|EVEREST_LATCHED_ATTN_IN_USE_MASK
value|0xffe00000
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_6
value|6
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_7
value|7
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_8
value|8
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_9
value|9
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_10
value|10
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_11
value|11
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_12
value|12
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_13
value|13
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_14
value|14
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_15
value|15
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_16
value|16
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_17
value|17
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_18
value|18
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_19
value|19
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_20
value|20
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_21
value|21
end_define

begin_comment
comment|/* storm asserts attention bits */
end_comment

begin_define
define|#
directive|define
name|TSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_7
end_define

begin_define
define|#
directive|define
name|USTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_8
end_define

begin_define
define|#
directive|define
name|CSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_9
end_define

begin_define
define|#
directive|define
name|XSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_10
end_define

begin_comment
comment|/* mcp error attention bit */
end_comment

begin_define
define|#
directive|define
name|MCP_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_11
end_define

begin_comment
comment|/* E1H NIG status sync attention mapped to group 4-7*/
end_comment

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_0
value|RESERVED_GENERAL_ATTENTION_BIT_12
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_1
value|RESERVED_GENERAL_ATTENTION_BIT_13
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_2
value|RESERVED_GENERAL_ATTENTION_BIT_14
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_3
value|RESERVED_GENERAL_ATTENTION_BIT_15
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_4
value|RESERVED_GENERAL_ATTENTION_BIT_16
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_5
value|RESERVED_GENERAL_ATTENTION_BIT_17
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_6
value|RESERVED_GENERAL_ATTENTION_BIT_18
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_7
value|RESERVED_GENERAL_ATTENTION_BIT_19
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCR
value|23
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCT
value|24
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCN
value|25
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCU
value|26
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCP
value|27
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_TIMEOUT_GRC
value|28
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RSVD_GRC
value|29
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_ROM_PARITY_MCP
value|30
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_UM_RX_PARITY_MCP
value|31
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_UM_TX_PARITY_MCP
value|32
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_SCPAD_PARITY_MCP
value|33
end_define

begin_define
define|#
directive|define
name|GENERAL_ATTEN_WORD
parameter_list|(
name|atten_name
parameter_list|)
value|((94 + atten_name) / 32)
end_define

begin_define
define|#
directive|define
name|GENERAL_ATTEN_OFFSET
parameter_list|(
name|atten_name
parameter_list|)
define|\
value|(1UL<< ((94 + atten_name) % 32))
end_define

begin_comment
comment|/*  * This file defines GRC base address for every block.  * This file is included by chipsim, asm microcode and cpp microcode.  * These values are used in Design.xml on regBase attribute  * Use the base with the generated offsets of specific registers.  */
end_comment

begin_define
define|#
directive|define
name|GRCBASE_PXPCS
value|0x000000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PCICONFIG
value|0x002000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PCIREG
value|0x002400
end_define

begin_define
define|#
directive|define
name|GRCBASE_EMAC0
value|0x008000
end_define

begin_define
define|#
directive|define
name|GRCBASE_EMAC1
value|0x008400
end_define

begin_define
define|#
directive|define
name|GRCBASE_DBU
value|0x008800
end_define

begin_define
define|#
directive|define
name|GRCBASE_MISC
value|0x00A000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DBG
value|0x00C000
end_define

begin_define
define|#
directive|define
name|GRCBASE_NIG
value|0x010000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XCM
value|0x020000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PRS
value|0x040000
end_define

begin_define
define|#
directive|define
name|GRCBASE_SRCH
value|0x040400
end_define

begin_define
define|#
directive|define
name|GRCBASE_TSDM
value|0x042000
end_define

begin_define
define|#
directive|define
name|GRCBASE_TCM
value|0x050000
end_define

begin_define
define|#
directive|define
name|GRCBASE_BRB1
value|0x060000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MCP
value|0x080000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UPB
value|0x0C1000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CSDM
value|0x0C2000
end_define

begin_define
define|#
directive|define
name|GRCBASE_USDM
value|0x0C4000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CCM
value|0x0D0000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UCM
value|0x0E0000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CDU
value|0x101000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DMAE
value|0x102000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PXP
value|0x103000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CFC
value|0x104000
end_define

begin_define
define|#
directive|define
name|GRCBASE_HC
value|0x108000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PXP2
value|0x120000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PBF
value|0x140000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XPB
value|0x161000
end_define

begin_define
define|#
directive|define
name|GRCBASE_TIMERS
value|0x164000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XSDM
value|0x166000
end_define

begin_define
define|#
directive|define
name|GRCBASE_QM
value|0x168000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DQ
value|0x170000
end_define

begin_define
define|#
directive|define
name|GRCBASE_TSEM
value|0x180000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CSEM
value|0x200000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XSEM
value|0x280000
end_define

begin_define
define|#
directive|define
name|GRCBASE_USEM
value|0x300000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MISC_AEU
value|GRCBASE_MISC
end_define

begin_comment
comment|/* offset of configuration space in the pci core register */
end_comment

begin_define
define|#
directive|define
name|PCICFG_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCICFG_VENDOR_ID_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_ID_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_IO_SPACE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MEM_SPACE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_BUS_MASTER
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SPECIAL_CYCLES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MWI_CYCLES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_VGA_SNOOP
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_PERR_ENA
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_STEPPING
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SERR_ENA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_FAST_B2B
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_INT_DISABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_RESERVED
value|(0x1f<<11)
end_define

begin_define
define|#
directive|define
name|PCICFG_STATUS_OFFSET
value|0x06
end_define

begin_define
define|#
directive|define
name|PCICFG_REVESION_ID_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|PCICFG_CACHE_LINE_SIZE
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCICFG_LATENCY_TIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_LOW
value|0x10
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_HIGH
value|0x14
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_LOW
value|0x18
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_HIGH
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_VENDOR_ID_OFFSET
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_ID_OFFSET
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_LINE
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_PIN
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY
value|0x48
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_VERSION
value|(0x3<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_CLOCK
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_RESERVED
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_DSI
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_AUX_CURRENT
value|(0x7<<22)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D1_SUPPORT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D2_SUPPORT
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D0
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D1
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D2
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_HOT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_COLD
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_OFFSET
value|0x4c
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_STATE
value|(0x3<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_STATUS
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CAP_ID_OFFSET
value|0x58
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_ENABLE
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MCAP
value|(0x7<<17)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MENA
value|(0x7<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_64_BIT_ADDR_CAP
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MSI_PVMASK_CAPABLE
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_ADDRESS
value|0x78
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CAP_ID_OFFSET
value|0xa0
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_TABLE_SIZE
value|(0x7ff<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_RESERVED
value|(0x7<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_FUNC_MASK
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_MSIX_ENABLE
value|(0x1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_CONTROL
value|0xb4
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS
value|0xb6
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_CORR_ERR_DET
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NON_FATAL_ERR_DET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_FATAL_ERR_DET
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_UNSUP_REQ_DET
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_AUX_PWR_DET
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NO_PEND
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_LINK_CONTROL
value|0xbc
end_define

begin_define
define|#
directive|define
name|BAR_USTORM_INTMEM
value|0x400000
end_define

begin_define
define|#
directive|define
name|BAR_CSTORM_INTMEM
value|0x410000
end_define

begin_define
define|#
directive|define
name|BAR_XSTORM_INTMEM
value|0x420000
end_define

begin_define
define|#
directive|define
name|BAR_TSTORM_INTMEM
value|0x430000
end_define

begin_comment
comment|/* for accessing the IGU in case of status block ACK */
end_comment

begin_define
define|#
directive|define
name|BAR_IGU_INTMEM
value|0x440000
end_define

begin_define
define|#
directive|define
name|BAR_DOORBELL_OFFSET
value|0x800000
end_define

begin_define
define|#
directive|define
name|BAR_ME_REGISTER
value|0x450000
end_define

begin_define
define|#
directive|define
name|ME_REG_PF_NUM
value|(7L<<0)
end_define

begin_comment
comment|/* Relative PF Num */
end_comment

begin_define
define|#
directive|define
name|ME_REG_PF_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ME_REG_ABS_PF_NUM
value|(7L<<16)
end_define

begin_comment
comment|/* Absolute PF Num */
end_comment

begin_define
define|#
directive|define
name|ME_REG_ABS_PF_NUM_SHIFT
value|16
end_define

begin_comment
comment|/* config_2 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_2_SIZE_REG
value|0x408
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_RETRY
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_CFG_CYCLE_RETRY
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_FIRST_CFG_DONE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_DISABLED
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2K
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4K
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8K
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16K
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32K
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_64K
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_128K
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_256K
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_512K
value|(9L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_1M
value|(10L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2M
value|(11L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4M
value|(12L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8M
value|(13L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16M
value|(14L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32M
value|(15L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR_PREFETCH
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_RESERVED0
value|(0x7fffL<<17)
end_define

begin_comment
comment|/* config_3 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_3_SIZE_REG
value|0x40c
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_STICKY_BYTE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_FORCE_PME
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_STATUS
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PM_STATE
value|(0x3L<<27)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_VAUX_PRESET
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PCI_POWER
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|GRC_BAR2_CONFIG
value|0x4e0
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_A
value|0x410
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_B
value|0x414
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL1
value|0x434
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL2
value|0x438
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_IEEEB0
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_RESTART_AN
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_AN_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_MAIN_RST
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_IEEEB1
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1
value|0x00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2
value|0x01
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_1000M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_1000M_KX
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_10G_KX4
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_10G_KR
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1
value|0x03
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX0
value|0x80b0
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS_SIGDET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS_RX_SEQ_DONE
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX1
value|0x80c0
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX2
value|0x80d0
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX3
value|0x80e0
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX_ALL
value|0x80f0
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX0
value|0x8060
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX1
value|0x8070
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX2
value|0x8080
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX3
value|0x8090
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK0
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK0_XGXS_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK1
value|0x8010
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL0
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL1
value|0x16
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL2
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_PRBS
value|0x19
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK2
value|0x8100
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP_FORCE_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TX_LN_SWAP
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TX_LN_SWAP_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_CX4_XGXS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_HIGIG_XGXS
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TEST_MODE_LANE
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_GP_STATUS
value|0x8120
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1
value|0x1B
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_AUTONEG_COMPLETE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL37_AUTONEG_COMPLETE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_LINK_STATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_DUPLEX_STATUS
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_MR_LP_NP_AN_ABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_LP_NP_BAM_ABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_TXSIDE
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_RXSIDE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_MASK
value|0x3f00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_100M
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_2_5G
value|0x0300
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_5G
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_6G
value|0x0500
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_HIG
value|0x0600
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_CX4
value|0x0700
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12G_HIG
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12_5G
value|0x0900
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_13G
value|0x0A00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_15G
value|0x0B00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_16G
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G_KX
value|0x0D00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_KX4
value|0x0E00
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_10G_PARALLEL_DETECT
value|0x8130
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS_PD_LINK
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL_PARDET10G_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK
value|0x13
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK_CNT
value|(0xb71<<1)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_SERDES_DIGITAL
value|0x8300
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_FIBER_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_TBI_IF
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_SIGNAL_DETECT_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_INVERT_SIGNAL_DETECT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_AUTODET
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_MSTR_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_PRL_DT_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_AN_FST_TMR
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_DUPLEX
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_MASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_2_5G
value|0x0018
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_1G
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_100M
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_10M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS2
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS2_AN_DISABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1
value|0x18
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_MASK
value|0xE000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_25M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_100M
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_125M
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_156_25M
value|0x6000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_187_5M
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_SEL
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_2_5G
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_5G
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_6G
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_10G_HIG
value|0x0003
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_10G_CX4
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_12G
value|0x0005
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_12_5G
value|0x0006
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_13G
value|0x0007
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_15G
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_16G
value|0x0009
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_OVER_1G
value|0x8320
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4_MP_ID_MASK
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4_MP_ID_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1
value|0x19
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_2_5G
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_5G
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_6G
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_10G
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_10GH
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_12G
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_12_5G
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_13G
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_15G
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_16G
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2
value|0x1A
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_IPREDRIVER_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_IDRIVER_MASK
value|0x0038
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_PREEMPHASIS_MASK
value|0x03C0
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP3
value|0x1B
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP3_HIGIG2
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP1
value|0x1C
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2
value|0x1D
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_MR_ADV_OVER_1G_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_PREEMPHASIS_MASK
value|0x0780
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_PREEMPHASIS_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP3
value|0x1E
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_REMOTE_PHY
value|0x8330
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_OVER1G_MSG
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_BRCM_OUI_MSG
value|0x0600
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_BAM_NEXT_PAGE
value|0x8350
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_BAM_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_TETON_AN
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_USERB0
value|0x8370
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_UCTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_UCTRL_USTAT1_MUXSEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1_LINK_STATUS_CHECK
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1_AN_GOOD_CHECK_BAM37
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1
value|0x12
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_STATION_MNGR_EN
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_NP_AFTER_BP_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL3
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL3_USE_CL73_HCD_MR
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_AER_BLOCK
value|0xFFD0
end_define

begin_define
define|#
directive|define
name|MDIO_AER_BLOCK_AER_REG
value|0x1E
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_COMBO_IEEE0
value|0xFFE0
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_MASK
value|0x2040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_RESTART_AN
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_AN_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS_LINK_PASS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS_AUTONEG_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_FULL_DUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_HALF_DUPLEX
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_MASK
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_SYMMETRIC
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_MASK
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_BOTH
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_HALF_DUP_CAP
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_FULL_DUP_CAP
value|0x0020
end_define

begin_comment
comment|/*  * WhenthelinkpartnerisinSGMIImode(bit0=1),the  * bit15=link,bit12=duplex,bits11:10=speed,bit14=acknowledge.  * Theotherbitsarereservedandshouldbezero  */
end_comment

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_SGMII_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_DEVAD
value|0x1
end_define

begin_comment
comment|/*ieee*/
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CTRL
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_STATUS
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_10G_CTRL2
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_RX_SD
value|0xa
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_REG_BCM_CTRL
value|0x0096
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_FEC_CTRL
value|0x00ab
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_RX_ALARM_CTRL
value|0x9000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_LASI_CTRL
value|0x9002
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_RX_ALARM
value|0x9003
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_TX_ALARM
value|0x9004
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_LASI_STATUS
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PHY_IDENTIFIER
value|0xc800
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_DIGITAL_CTRL
value|0xc808
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_DIGITAL_STATUS
value|0xc809
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_TX_POWER_DOWN
value|0xca02
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CMU_PLL_BYPASS
value|0xca09
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL
value|0xca0a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL
value|0xca10
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL_ROM_RESET_INTERNAL_MP
value|0x0188
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL_ROM_MICRO_RESET
value|0x018a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_M8051_MSGIN_REG
value|0xca12
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_M8051_MSGOUT_REG
value|0xca13
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_ROM_VER1
value|0xca19
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_ROM_VER2
value|0xca1a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_EDC_FFE_MAIN
value|0xca1b
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PLL_BANDWIDTH
value|0xca1d
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PLL_CTRL
value|0xca1e
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL0
value|0xca23
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_LRM_MODE
value|0xca3f
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CDR_BANDWIDTH
value|0xca46
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL1
value|0xca85
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_CTRL
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IN_PROGRESS
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_FAILED
value|0x000c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_BYTE_CNT
value|0x8002
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_MEM_ADDR
value|0x8003
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TWO_WIRE_DATA_BUF
value|0xc820
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TWO_WIRE_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TX_CTRL1
value|0xca01
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TX_CTRL2
value|0xca05
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_SLAVE_ADDR
value|0x8005
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_DATA_BUF
value|0x8007
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_MISC_CTRL
value|0x8309
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TX_CTRL1
value|0xca02
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TX_CTRL2
value|0xca05
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_PCS_OPT_CTRL
value|0xc808
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_GPIO_CTRL
value|0xc80e
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_CHIP_REV
value|0xc801
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_SPEED_LINK_STATUS
value|0xc820
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_XAUI_WA
value|0xc841
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_RESET
value|0xc000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7107_LED_CNTL
value|0xc007
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_VER1
value|0xc026
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_VER2
value|0xc027
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_PMD_SIGNAL
value|0xa811
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED1_MASK
value|0xa82c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED2_MASK
value|0xa82f
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED3_MASK
value|0xa832
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED3_BLINK
value|0xa834
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_SIGNAL_MASK
value|0xa835
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LINK_SIGNAL
value|0xa83b
end_define

begin_define
define|#
directive|define
name|MDIO_WIS_DEVAD
value|0x2
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_WIS_REG_LASI_CNTL
value|0x9002
end_define

begin_define
define|#
directive|define
name|MDIO_WIS_REG_LASI_STATUS
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_DEVAD
value|0x3
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_STATUS
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_LASI_STATUS
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_DSP_ACCESS
value|0xD000
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_MUX
value|0xD008
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_CTRL_ADDR
value|0xE12A
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_RESET_BIT
value|(5)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR
value|0xE02A
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_WRITE_ENABLE_CMD
value|(6)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_BULK_ERASE_CMD
value|(0xC7)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_PAGE_PROGRAM_CMD
value|(2)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_BYTES_TO_TRANSFER_ADDR
value|0xE028
end_define

begin_define
define|#
directive|define
name|MDIO_XS_DEVAD
value|0x4
end_define

begin_define
define|#
directive|define
name|MDIO_XS_PLL_SEQUENCER
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XS_SFX7101_XGXS_TEST1
value|0xc00a
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX0
value|0x80bc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX1
value|0x80cc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX2
value|0x80dc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX3
value|0x80ec
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RXA
value|0x80fc
end_define

begin_define
define|#
directive|define
name|MDIO_AN_DEVAD
value|0x7
end_define

begin_comment
comment|/*ieee*/
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_REG_CTRL
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_STATUS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_STATUS_AN_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV
value|0x0011
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV2
value|0x0012
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_LP_AUTO_NEG
value|0x0013
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_MASTER_STATUS
value|0x0021
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_REG_LINK_STATUS
value|0x8304
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_CL73
value|0x8370
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_AN
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_FC_LD
value|0xffe4
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_FC_LP
value|0xffe5
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8073_2_5G
value|0x8329
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_MII_CTRL
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_MII_STATUS
value|0xffe1
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_AN_ADV
value|0xffe4
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_AN_EXPANSION
value|0xffe6
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_1000T_CTRL
value|0xffe9
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_EXPANSION_REG_RD_RW
value|0xfff5
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_EXPANSION_REG_ACCESS
value|0xfff7
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_SHADOW
value|0xfffc
end_define

begin_define
define|#
directive|define
name|IGU_FUNC_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSIX
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_INT_ACK
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_PROD_UPD
value|0x0201
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_UPD
value|0x0202
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_SET
value|0x0203
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_CLR
value|0x0204
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_COALESCE_NOW
value|0x0205
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_SIMD_MASK
value|0x0206
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_SIMD_NOMASK
value|0x0207
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_CTL
value|0x0210
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_ADDR_LO
value|0x0211
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_ADDR_HI
value|0x0212
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_DATA
value|0x0213
end_define

begin_define
define|#
directive|define
name|IGU_INT_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|IGU_INT_DISABLE
value|1
end_define

begin_define
define|#
directive|define
name|IGU_INT_NOP
value|2
end_define

begin_define
define|#
directive|define
name|IGU_INT_NOP2
value|3
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_INT_ACK
value|0x0
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_PROD_UPD
value|0x4
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_UPD
value|0x8
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_SET
value|0xc
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_CLR
value|0x10
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_COALESCE_NOW
value|0x14
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_SIMD_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_SIMD_NOMASK
value|0x1c
end_define

begin_define
define|#
directive|define
name|IGU_MEM_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_UPPER
value|0x007f
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_RESERVED_UPPER
value|0x01ff
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_UPPER
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_CMD_BACKWARD_COMP_PROD_UPD
value|0x0201
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_RESERVED_UPPER
value|0x03ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_UPPER
define|\
value|(IGU_CMD_INT_ACK_BASE + MAX_SB_PER_PORT * NUM_OF_PORTS_PER_PATH - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_RESERVED_UPPER
value|0x04ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_BASE
value|0x0500
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_UPPER
define|\
value|(IGU_CMD_E2_PROD_UPD_BASE + MAX_SB_PER_PORT * NUM_OF_PORTS_PER_PATH - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_RESERVED_UPPER
value|0x059f
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_UPD_UPPER
value|0x05a0
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_SET_UPPER
value|0x05a1
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_CLR_UPPER
value|0x05a2
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_UPPER
value|0x05a3
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_LSB_UPPER
value|0x05a4
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_MSB_UPPER
value|0x05a5
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WOMASK_UPPER
value|0x05a6
end_define

begin_define
define|#
directive|define
name|IGU_REG_RESERVED_UPPER
value|0x05ff
end_define

begin_define
define|#
directive|define
name|CDU_REGION_NUMBER_XCM_AG
value|2
end_define

begin_define
define|#
directive|define
name|CDU_REGION_NUMBER_UCM_AG
value|4
end_define

begin_comment
comment|/*  *  * String-to-compress [31:8] = CID (all 24 bits)  * String-to-compress [7:4] = Region  * String-to-compress [3:0] = Type  */
end_comment

begin_define
define|#
directive|define
name|CDU_VALID_DATA
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(((_cid)<< 8) | (((_region)& 0xf)<< 4) | (((_type)& 0xf)))
end_define

begin_define
define|#
directive|define
name|CDU_CRC8
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(calc_crc8(CDU_VALID_DATA(_cid,	_region, _type), 0xff))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_VALUE_TYPE_A
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(0x80 | ((CDU_CRC8(_cid, _region, _type))& 0x7f))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_VALUE_TYPE_B
parameter_list|(
name|_crc
parameter_list|,
name|_type
parameter_list|)
define|\
value|(0x80 | ((_type)& 0xf<< 3) | ((CDU_CRC8(_cid, _region, _type))& 0x7))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_INVALIDATE_CONTEXT_VALUE
parameter_list|(
name|_val
parameter_list|)
value|(((_val)& ~0x80)
end_define

begin_comment
comment|/*  *****************************************************************************  * Description:  *	   Calculates crc 8 on a word value: polynomial 0-1-2-8  *	   Code was translated from Verilog.  * Return: *****************************************************************************/
end_comment

begin_function
specifier|static
name|__inline
name|uint8_t
name|calc_crc8
parameter_list|(
name|uint32_t
name|data
parameter_list|,
name|uint8_t
name|crc
parameter_list|)
block|{
name|uint8_t
name|D
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|NewCRC
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|C
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|crc_res
decl_stmt|;
name|uint8_t
name|i
decl_stmt|;
comment|/* split the data into 31 bits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
name|D
index|[
name|i
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|data
operator|&
literal|1
argument_list|)
expr_stmt|;
name|data
operator|=
name|data
operator|>>
literal|1
expr_stmt|;
block|}
comment|/* split the crc into 8 bits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|C
index|[
name|i
index|]
operator|=
name|crc
operator|&
literal|1
expr_stmt|;
name|crc
operator|=
name|crc
operator|>>
literal|1
expr_stmt|;
block|}
name|NewCRC
index|[
literal|0
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|6
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|1
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|NewCRC
index|[
literal|2
index|]
operator|=
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
expr_stmt|;
name|NewCRC
index|[
literal|3
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|NewCRC
index|[
literal|4
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|6
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|5
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|6
index|]
operator|=
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
expr_stmt|;
name|NewCRC
index|[
literal|7
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|crc_res
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|crc_res
operator||=
operator|(
name|NewCRC
index|[
name|i
index|]
operator|<<
name|i
operator|)
expr_stmt|;
return|return
operator|(
name|crc_res
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BXE_REG_H */
end_comment

end_unit

