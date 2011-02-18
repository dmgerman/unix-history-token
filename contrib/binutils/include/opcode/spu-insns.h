begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPU ELF support for BFD.     Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* SPU Opcode Table  -=-=-= FORMAT =-=-=-                                              		                                                     +----+-------+-------+-------+-------+  		       +------------+-------+-------+-------+ RRR    | op |  RC   |  RB   |  RA   |  RT   |		RI7    | op         |  I7   |  RA   |  RT   |        +----+-------+-------+-------+-------+		       +------------+-------+-------+-------+         0  3       1       1       2       3		        0          1       1       2       3                     0       7       4       1		                   0       7       4       1          +-----------+--------+-------+-------+		       +---------+----------+-------+-------+ RI8    | op        |   I8   |  RA   |  RT   |		RI10   | op      |   I10    |  RA   |  RT   |        +-----------+--------+-------+-------+		       +---------+----------+-------+-------+         0         9        1       2       3		        0       7          1       2       3                             7       4       1		                           7       4       1          +----------+-----------------+-------+		       +--------+-------------------+-------+ RI16   | op       |       I16       |  RT   |		RI18   | op     |       I18         |  RT   |        +----------+-----------------+-------+		       +--------+-------------------+-------+         0        8                 2       3		        0      6                   2       3                                     4       1		                                   4       1          +------------+-------+-------+-------+		       +-------+--+-----------------+-------+ RR     | op         |  RB   |  RA   |  RT   |		LBT    | op    |RO|       I16       |  RO   |        +------------+-------+-------+-------+		       +-------+--+-----------------+-------+         0          1       1       2       3		        0     6  8                 2       3                     0       7       4       1		                                   4       1   							       +------------+----+--+-------+-------+ 							LBTI   | op         | // |RO|  RA   |  RO   | 							       +------------+----+--+-------+-------+ 							        0          1    1  1       2       3 							                   0    5  7       4       1  -=-=-= OPCODE =-=-=-  OPCODE field specifies the most significant 11bit of the instruction. Some formats don't have 11bits for opcode field, and in this case, bit field other than op are defined as 0s. For example, opcode of fma instruction which is RRR format is defined as 0x700, since 0x700 -> 11'b11100000000, this means opcode is 4'b1110, and other 7bits are defined as 7'b0000000.  -=-=-= ASM_FORMAT =-=-=-  RRR category						RI7 category                                	ASM_RRR		mnemonic RC, RA, RB, RT		        ASM_RI4         mnemonic RT, RA, I4 							        ASM_RI7         mnemonic RT, RA, I7  RI8 category						RI10 category                                	ASM_RUI8	mnemonic RT, RA, UI8		        ASM_AI10        mnemonic RA, I10     							        ASM_RI10        mnemonic RT, RA, R10 							        ASM_RI10IDX     mnemonic RT, I10(RA)  RI16 category						RI18 category                            	ASM_I16W	mnemonic I16W			        ASM_RI18        mnemonic RT, I18 	ASM_RI16	mnemonic RT, I16 	ASM_RI16W	mnemonic RT, I16W  RR category						LBT category                                     	ASM_MFSPR	mnemonic RT, SA			        ASM_LBT         mnemonic brinst, brtarg  	ASM_MTSPR	mnemonic SA, RT			                                                 	ASM_NOOP	mnemonic			LBTI category                                    	ASM_RA		mnemonic RA			        ASM_LBTI        mnemonic brinst, RA      	ASM_RAB		mnemonic RA, RB 	ASM_RDCH	mnemonic RT, CA 	ASM_RR		mnemonic RT, RA, RB 	ASM_RT		mnemonic RT 	ASM_RTA		mnemonic RT, RA 	ASM_WRCH	mnemonic CA, RT  Note that RRR instructions have the names for RC and RT reversed from what's in the ISA, in order to put RT in the same position it appears for other formats.  -=-=-= DEPENDENCY =-=-=-  DEPENDENCY filed consists of 5 digits. This represents which register is used as source and which register is used as target. The first(most significant) digit is always 0. Then it is followd by RC, RB, RA and RT digits. If the digit is 0, this means the corresponding register is not used in the instruction. If the digit is 1, this means the corresponding register is used as a source in the instruction. If the digit is 2, this means the corresponding register is used as a target in the instruction. If the digit is 3, this means the corresponding register is used as both source and target in the instruction. For example, fms instruction has 00113 as the DEPENDENCY field. This means RC is not used in this operation, RB and RA are used as sources and RT is the target.  -=-=-= PIPE =-=-=-  This field shows which execution pipe is used for the instruction  pipe0 execution pipelines: 	FP6	SP floating pipeline 	FP7	integer operations executed in SP floating pipeline 	FPD	DP floating pipeline 	FX2	FXU pipeline 	FX3	Rotate/Shift pipeline 	FXB	Byte pipeline 	NOP	No pipeline  pipe1 execution pipelines: 	BR	Branch pipeline 	LNOP	No pipeline 	LS	Load/Store pipeline 	SHUF	Shuffle pipeline 	SPR	SPR/CH pipeline  */
end_comment

begin_define
define|#
directive|define
name|_A0
parameter_list|()
value|{0}
end_define

begin_define
define|#
directive|define
name|_A1
parameter_list|(
name|a
parameter_list|)
value|{1,a}
end_define

begin_define
define|#
directive|define
name|_A2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{2,a,b}
end_define

begin_define
define|#
directive|define
name|_A3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{3,a,b,c}
end_define

begin_define
define|#
directive|define
name|_A4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{4,a,b,c,d}
end_define

begin_comment
comment|/*    TAG		FORMAT	OPCODE	MNEMONIC	ASM_FORMAT	DEPENDENCY	PIPE	COMMENT				*/
end_comment

begin_comment
comment|/*									0[RC][RB][RA][RT]					*/
end_comment

begin_comment
comment|/*									1:src, 2:target						*/
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BR
argument_list|,
argument|RI16
argument_list|,
literal|0x190
argument_list|,
literal|"br"
argument_list|,
argument|_A1(A_R18)
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRel          IP<-IP+I16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRSL
argument_list|,
argument|RI16
argument_list|,
literal|0x198
argument_list|,
literal|"brsl"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00002
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRelSetLink   RT,IP<-IP,IP+I16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRA
argument_list|,
argument|RI16
argument_list|,
literal|0x180
argument_list|,
literal|"bra"
argument_list|,
argument|_A1(A_S18)
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRAbs         IP<-I16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRASL
argument_list|,
argument|RI16
argument_list|,
literal|0x188
argument_list|,
literal|"brasl"
argument_list|,
argument|_A2(A_T,A_S18)
argument_list|,
literal|00002
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRAbsSetLink  RT,IP<-IP,I16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSMBI
argument_list|,
argument|RI16
argument_list|,
literal|0x194
argument_list|,
literal|"fsmbi"
argument_list|,
argument|_A2(A_T,A_X16)
argument_list|,
literal|00002
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FormSelMask%I RT<-fsm(I16) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LQA
argument_list|,
argument|RI16
argument_list|,
literal|0x184
argument_list|,
literal|"lqa"
argument_list|,
argument|_A2(A_T,A_S18)
argument_list|,
literal|00002
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* LoadQAbs      RT<-M[I16] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LQR
argument_list|,
argument|RI16
argument_list|,
literal|0x19C
argument_list|,
literal|"lqr"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00002
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* LoadQRel      RT<-M[IP+I16] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STOP
argument_list|,
argument|RR
argument_list|,
literal|0x000
argument_list|,
literal|"stop"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* STOP          stop */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STOP2
argument_list|,
argument|RR
argument_list|,
literal|0x000
argument_list|,
literal|"stop"
argument_list|,
argument|_A1(A_U14)
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* STOP          stop */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STOPD
argument_list|,
argument|RR
argument_list|,
literal|0x140
argument_list|,
literal|"stopd"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00111
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* STOPD         stop (with register dependencies) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LNOP
argument_list|,
argument|RR
argument_list|,
literal|0x001
argument_list|,
literal|"lnop"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|LNOP
argument_list|)
end_macro

begin_comment
comment|/* LNOP          no_operation */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SYNC
argument_list|,
argument|RR
argument_list|,
literal|0x002
argument_list|,
literal|"sync"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* SYNC          flush_pipe */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DSYNC
argument_list|,
argument|RR
argument_list|,
literal|0x003
argument_list|,
literal|"dsync"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* DSYNC         flush_store_queue */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MFSPR
argument_list|,
argument|RR
argument_list|,
literal|0x00c
argument_list|,
literal|"mfspr"
argument_list|,
argument|_A2(A_T,A_S)
argument_list|,
literal|00002
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* MFSPR         RT<-SA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_RDCH
argument_list|,
argument|RR
argument_list|,
literal|0x00d
argument_list|,
literal|"rdch"
argument_list|,
argument|_A2(A_T,A_H)
argument_list|,
literal|00002
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* ReaDCHannel   RT<-CA:data */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_RCHCNT
argument_list|,
argument|RR
argument_list|,
literal|0x00f
argument_list|,
literal|"rchcnt"
argument_list|,
argument|_A2(A_T,A_H)
argument_list|,
literal|00002
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* ReaDCHanCouNT RT<-CA:count */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HBRA
argument_list|,
argument|LBT
argument_list|,
literal|0x080
argument_list|,
literal|"hbra"
argument_list|,
argument|_A2(A_S11,A_S18)
argument_list|,
literal|00000
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* HBRA          BTB[B9]<-M[I16] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HBRR
argument_list|,
argument|LBT
argument_list|,
literal|0x090
argument_list|,
literal|"hbrr"
argument_list|,
argument|_A2(A_S11,A_R18)
argument_list|,
literal|00000
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* HBRR          BTB[B9]<-M[IP+I16] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRZ
argument_list|,
argument|RI16
argument_list|,
literal|0x100
argument_list|,
literal|"brz"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00001
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRZ           IP<-IP+I16_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRNZ
argument_list|,
argument|RI16
argument_list|,
literal|0x108
argument_list|,
literal|"brnz"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00001
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRNZ          IP<-IP+I16_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRHZ
argument_list|,
argument|RI16
argument_list|,
literal|0x110
argument_list|,
literal|"brhz"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00001
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRHZ          IP<-IP+I16_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BRHNZ
argument_list|,
argument|RI16
argument_list|,
literal|0x118
argument_list|,
literal|"brhnz"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00001
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BRHNZ         IP<-IP+I16_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STQA
argument_list|,
argument|RI16
argument_list|,
literal|0x104
argument_list|,
literal|"stqa"
argument_list|,
argument|_A2(A_T,A_S18)
argument_list|,
literal|00001
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* SToreQAbs     M[I16]<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STQR
argument_list|,
argument|RI16
argument_list|,
literal|0x11C
argument_list|,
literal|"stqr"
argument_list|,
argument|_A2(A_T,A_R18)
argument_list|,
literal|00001
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* SToreQRel     M[IP+I16]<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MTSPR
argument_list|,
argument|RR
argument_list|,
literal|0x10c
argument_list|,
literal|"mtspr"
argument_list|,
argument|_A2(A_S,A_T)
argument_list|,
literal|00001
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* MTSPR         SA<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_WRCH
argument_list|,
argument|RR
argument_list|,
literal|0x10d
argument_list|,
literal|"wrch"
argument_list|,
argument|_A2(A_H,A_T)
argument_list|,
literal|00001
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* ChanWRite     CA<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LQD
argument_list|,
argument|RI10
argument_list|,
literal|0x1a0
argument_list|,
literal|"lqd"
argument_list|,
argument|_A4(A_T,A_S14,A_P,A_A)
argument_list|,
literal|00012
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* LoadQDisp     RT<-M[Ra+I10] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BI
argument_list|,
argument|RR
argument_list|,
literal|0x1a8
argument_list|,
literal|"bi"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BI            IP<-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BISL
argument_list|,
argument|RR
argument_list|,
literal|0x1a9
argument_list|,
literal|"bisl"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISL          RT,IP<-IP,RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_IRET
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|"iret"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_IRET2
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|"iret"
argument_list|,
argument|_A0()
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BISLED
argument_list|,
argument|RR
argument_list|,
literal|0x1ab
argument_list|,
literal|"bisled"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISLED        RT,IP<-IP,RA_if(ext) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HBR
argument_list|,
argument|LBTI
argument_list|,
literal|0x1ac
argument_list|,
literal|"hbr"
argument_list|,
argument|_A2(A_S11I,A_A)
argument_list|,
literal|00010
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* HBR           BTB[B9]<-M[Ra] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FREST
argument_list|,
argument|RR
argument_list|,
literal|0x1b8
argument_list|,
literal|"frest"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FREST         RT<-recip(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FRSQEST
argument_list|,
argument|RR
argument_list|,
literal|0x1b9
argument_list|,
literal|"frsqest"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FRSQEST       RT<-rsqrt(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSM
argument_list|,
argument|RR
argument_list|,
literal|0x1b4
argument_list|,
literal|"fsm"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FormSelMask%  RT<-expand(Ra) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSMH
argument_list|,
argument|RR
argument_list|,
literal|0x1b5
argument_list|,
literal|"fsmh"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FormSelMask%  RT<-expand(Ra) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSMB
argument_list|,
argument|RR
argument_list|,
literal|0x1b6
argument_list|,
literal|"fsmb"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* FormSelMask%  RT<-expand(Ra) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_GB
argument_list|,
argument|RR
argument_list|,
literal|0x1b0
argument_list|,
literal|"gb"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* GatherBits%   RT<-gather(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_GBH
argument_list|,
argument|RR
argument_list|,
literal|0x1b1
argument_list|,
literal|"gbh"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* GatherBits%   RT<-gather(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_GBB
argument_list|,
argument|RR
argument_list|,
literal|0x1b2
argument_list|,
literal|"gbb"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* GatherBits%   RT<-gather(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CBD
argument_list|,
argument|RI7
argument_list|,
literal|0x1f4
argument_list|,
literal|"cbd"
argument_list|,
argument|_A4(A_T,A_U7,A_P,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insD  RT<-sta(Ra+I4,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CHD
argument_list|,
argument|RI7
argument_list|,
literal|0x1f5
argument_list|,
literal|"chd"
argument_list|,
argument|_A4(A_T,A_U7,A_P,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insD  RT<-sta(Ra+I4,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CWD
argument_list|,
argument|RI7
argument_list|,
literal|0x1f6
argument_list|,
literal|"cwd"
argument_list|,
argument|_A4(A_T,A_U7,A_P,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insD  RT<-sta(Ra+I4,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CDD
argument_list|,
argument|RI7
argument_list|,
literal|0x1f7
argument_list|,
literal|"cdd"
argument_list|,
argument|_A4(A_T,A_U7,A_P,A_A)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insD  RT<-sta(Ra+I4,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQBII
argument_list|,
argument|RI7
argument_list|,
literal|0x1f8
argument_list|,
literal|"rotqbii"
argument_list|,
argument|_A3(A_T,A_A,A_U3)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQBII       RT<-RA<<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQBYI
argument_list|,
argument|RI7
argument_list|,
literal|0x1fc
argument_list|,
literal|"rotqbyi"
argument_list|,
argument|_A3(A_T,A_A,A_S7N)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQBYI       RT<-RA<<<(I7*8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQMBII
argument_list|,
argument|RI7
argument_list|,
literal|0x1f9
argument_list|,
literal|"rotqmbii"
argument_list|,
argument|_A3(A_T,A_A,A_S3)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQMBII      RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQMBYI
argument_list|,
argument|RI7
argument_list|,
literal|0x1fd
argument_list|,
literal|"rotqmbyi"
argument_list|,
argument|_A3(A_T,A_A,A_S6)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQMBYI      RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLQBII
argument_list|,
argument|RI7
argument_list|,
literal|0x1fb
argument_list|,
literal|"shlqbii"
argument_list|,
argument|_A3(A_T,A_A,A_U3)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHLQBII       RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLQBYI
argument_list|,
argument|RI7
argument_list|,
literal|0x1ff
argument_list|,
literal|"shlqbyi"
argument_list|,
argument|_A3(A_T,A_A,A_U5)
argument_list|,
literal|00012
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHLQBYI       RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STQD
argument_list|,
argument|RI10
argument_list|,
literal|0x120
argument_list|,
literal|"stqd"
argument_list|,
argument|_A4(A_T,A_S14,A_P,A_A)
argument_list|,
literal|00011
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* SToreQDisp    M[Ra+I10]<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIHNZ
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|"bihnz"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNZ         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIHZ
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|"bihz"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BINZ
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|"binz"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIZ
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|"biz"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CBX
argument_list|,
argument|RR
argument_list|,
literal|0x1d4
argument_list|,
literal|"cbx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insX  RT<-sta(Ra+Rb,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CHX
argument_list|,
argument|RR
argument_list|,
literal|0x1d5
argument_list|,
literal|"chx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insX  RT<-sta(Ra+Rb,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CWX
argument_list|,
argument|RR
argument_list|,
literal|0x1d6
argument_list|,
literal|"cwx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insX  RT<-sta(Ra+Rb,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CDX
argument_list|,
argument|RR
argument_list|,
literal|0x1d7
argument_list|,
literal|"cdx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* genCtl%%insX  RT<-sta(Ra+Rb,siz) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LQX
argument_list|,
argument|RR
argument_list|,
literal|0x1c4
argument_list|,
literal|"lqx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* LoadQindeX    RT<-M[Ra+Rb] */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQBI
argument_list|,
argument|RR
argument_list|,
literal|0x1d8
argument_list|,
literal|"rotqbi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQBI        RT<-RA<<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQMBI
argument_list|,
argument|RR
argument_list|,
literal|0x1d9
argument_list|,
literal|"rotqmbi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQMBI       RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLQBI
argument_list|,
argument|RR
argument_list|,
literal|0x1db
argument_list|,
literal|"shlqbi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHLQBI        RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQBY
argument_list|,
argument|RR
argument_list|,
literal|0x1dc
argument_list|,
literal|"rotqby"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQBY        RT<-RA<<<(Rb*8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQMBY
argument_list|,
argument|RR
argument_list|,
literal|0x1dd
argument_list|,
literal|"rotqmby"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQMBY       RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLQBY
argument_list|,
argument|RR
argument_list|,
literal|0x1df
argument_list|,
literal|"shlqby"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHLQBY        RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQBYBI
argument_list|,
argument|RR
argument_list|,
literal|0x1cc
argument_list|,
literal|"rotqbybi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQBYBI      RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTQMBYBI
argument_list|,
argument|RR
argument_list|,
literal|0x1cd
argument_list|,
literal|"rotqmbybi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* ROTQMBYBI     RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLQBYBI
argument_list|,
argument|RR
argument_list|,
literal|0x1cf
argument_list|,
literal|"shlqbybi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHLQBYBI      RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_STQX
argument_list|,
argument|RR
argument_list|,
literal|0x144
argument_list|,
literal|"stqx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00111
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* SToreQindeX   M[Ra+Rb]<-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHUFB
argument_list|,
argument|RRR
argument_list|,
literal|0x580
argument_list|,
literal|"shufb"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|SHUF
argument_list|)
end_macro

begin_comment
comment|/* SHUFfleBytes  RC<-f(RA,RB,RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_IL
argument_list|,
argument|RI16
argument_list|,
literal|0x204
argument_list|,
literal|"il"
argument_list|,
argument|_A2(A_T,A_S16)
argument_list|,
literal|00002
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ImmLoad       RT<-sxt(I16) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ILH
argument_list|,
argument|RI16
argument_list|,
literal|0x20c
argument_list|,
literal|"ilh"
argument_list|,
argument|_A2(A_T,A_X16)
argument_list|,
literal|00002
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ImmLoadH      RT<-I16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ILHU
argument_list|,
argument|RI16
argument_list|,
literal|0x208
argument_list|,
literal|"ilhu"
argument_list|,
argument|_A2(A_T,A_X16)
argument_list|,
literal|00002
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ImmLoadHUpper RT<-I16<<16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ILA
argument_list|,
argument|RI18
argument_list|,
literal|0x210
argument_list|,
literal|"ila"
argument_list|,
argument|_A2(A_T,A_U18)
argument_list|,
literal|00002
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ImmLoadAddr   RT<-zxt(I18) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_NOP
argument_list|,
argument|RR
argument_list|,
literal|0x201
argument_list|,
literal|"nop"
argument_list|,
argument|_A1(A_T)
argument_list|,
literal|00000
argument_list|,
argument|NOP
argument_list|)
end_macro

begin_comment
comment|/* XNOP          no_operation */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_NOP2
argument_list|,
argument|RR
argument_list|,
literal|0x201
argument_list|,
literal|"nop"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|NOP
argument_list|)
end_macro

begin_comment
comment|/* XNOP          no_operation */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_IOHL
argument_list|,
argument|RI16
argument_list|,
literal|0x304
argument_list|,
literal|"iohl"
argument_list|,
argument|_A2(A_T,A_X16)
argument_list|,
literal|00003
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* AddImmeXt     RT<-RT+sxt(I16) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ANDBI
argument_list|,
argument|RI10
argument_list|,
literal|0x0b0
argument_list|,
literal|"andbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* AND%I         RT<-RA&I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ANDHI
argument_list|,
argument|RI10
argument_list|,
literal|0x0a8
argument_list|,
literal|"andhi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* AND%I         RT<-RA&I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ANDI
argument_list|,
argument|RI10
argument_list|,
literal|0x0a0
argument_list|,
literal|"andi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* AND%I         RT<-RA&I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ORBI
argument_list|,
argument|RI10
argument_list|,
literal|0x030
argument_list|,
literal|"orbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* OR%I          RT<-RA|I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ORHI
argument_list|,
argument|RI10
argument_list|,
literal|0x028
argument_list|,
literal|"orhi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* OR%I          RT<-RA|I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ORI
argument_list|,
argument|RI10
argument_list|,
literal|0x020
argument_list|,
literal|"ori"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* OR%I          RT<-RA|I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ORX
argument_list|,
argument|RR
argument_list|,
literal|0x1f0
argument_list|,
literal|"orx"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* ORX           RT<-RA.w0|RA.w1|RA.w2|RA.w3 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XORBI
argument_list|,
argument|RI10
argument_list|,
literal|0x230
argument_list|,
literal|"xorbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* XOR%I         RT<-RA^I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XORHI
argument_list|,
argument|RI10
argument_list|,
literal|0x228
argument_list|,
literal|"xorhi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* XOR%I         RT<-RA^I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XORI
argument_list|,
argument|RI10
argument_list|,
literal|0x220
argument_list|,
literal|"xori"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* XOR%I         RT<-RA^I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_AHI
argument_list|,
argument|RI10
argument_list|,
literal|0x0e8
argument_list|,
literal|"ahi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add%Immed     RT<-RA+I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_AI
argument_list|,
argument|RI10
argument_list|,
literal|0x0e0
argument_list|,
literal|"ai"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add%Immed     RT<-RA+I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SFHI
argument_list|,
argument|RI10
argument_list|,
literal|0x068
argument_list|,
literal|"sfhi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* SubFrom%Imm   RT<-I10-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SFI
argument_list|,
argument|RI10
argument_list|,
literal|0x060
argument_list|,
literal|"sfi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* SubFrom%Imm   RT<-I10-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGTBI
argument_list|,
argument|RI10
argument_list|,
literal|0x270
argument_list|,
literal|"cgtbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%I         RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGTHI
argument_list|,
argument|RI10
argument_list|,
literal|0x268
argument_list|,
literal|"cgthi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%I         RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGTI
argument_list|,
argument|RI10
argument_list|,
literal|0x260
argument_list|,
literal|"cgti"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%I         RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGTBI
argument_list|,
argument|RI10
argument_list|,
literal|0x2f0
argument_list|,
literal|"clgtbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%I        RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGTHI
argument_list|,
argument|RI10
argument_list|,
literal|0x2e8
argument_list|,
literal|"clgthi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%I        RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGTI
argument_list|,
argument|RI10
argument_list|,
literal|0x2e0
argument_list|,
literal|"clgti"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%I        RT<-(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQBI
argument_list|,
argument|RI10
argument_list|,
literal|0x3f0
argument_list|,
literal|"ceqbi"
argument_list|,
argument|_A3(A_T,A_A,A_S10B)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%I         RT<-(RA=I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQHI
argument_list|,
argument|RI10
argument_list|,
literal|0x3e8
argument_list|,
literal|"ceqhi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%I         RT<-(RA=I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQI
argument_list|,
argument|RI10
argument_list|,
literal|0x3e0
argument_list|,
literal|"ceqi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%I         RT<-(RA=I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HGTI
argument_list|,
argument|RI10
argument_list|,
literal|0x278
argument_list|,
literal|"hgti"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltGTI       halt_if(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HGTI2
argument_list|,
argument|RI10
argument_list|,
literal|0x278
argument_list|,
literal|"hgti"
argument_list|,
argument|_A2(A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltGTI       halt_if(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HLGTI
argument_list|,
argument|RI10
argument_list|,
literal|0x2f8
argument_list|,
literal|"hlgti"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltLGTI      halt_if(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HLGTI2
argument_list|,
argument|RI10
argument_list|,
literal|0x2f8
argument_list|,
literal|"hlgti"
argument_list|,
argument|_A2(A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltLGTI      halt_if(RA>I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HEQI
argument_list|,
argument|RI10
argument_list|,
literal|0x3f8
argument_list|,
literal|"heqi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltEQImm     halt_if(RA=I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HEQI2
argument_list|,
argument|RI10
argument_list|,
literal|0x3f8
argument_list|,
literal|"heqi"
argument_list|,
argument|_A2(A_A,A_S10)
argument_list|,
literal|00010
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltEQImm     halt_if(RA=I10) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYI
argument_list|,
argument|RI10
argument_list|,
literal|0x3a0
argument_list|,
literal|"mpyi"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYI          RT<-RA*I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYUI
argument_list|,
argument|RI10
argument_list|,
literal|0x3a8
argument_list|,
literal|"mpyui"
argument_list|,
argument|_A3(A_T,A_A,A_S10)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYUI         RT<-RA*I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CFLTS
argument_list|,
argument|RI8
argument_list|,
literal|0x3b0
argument_list|,
literal|"cflts"
argument_list|,
argument|_A3(A_T,A_A,A_U7A)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* CFLTS         RT<-int(RA,I8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CFLTU
argument_list|,
argument|RI8
argument_list|,
literal|0x3b2
argument_list|,
literal|"cfltu"
argument_list|,
argument|_A3(A_T,A_A,A_U7A)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* CFLTU         RT<-int(RA,I8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CSFLT
argument_list|,
argument|RI8
argument_list|,
literal|0x3b4
argument_list|,
literal|"csflt"
argument_list|,
argument|_A3(A_T,A_A,A_U7B)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* CSFLT         RT<-flt(RA,I8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CUFLT
argument_list|,
argument|RI8
argument_list|,
literal|0x3b6
argument_list|,
literal|"cuflt"
argument_list|,
argument|_A3(A_T,A_A,A_U7B)
argument_list|,
literal|00012
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* CUFLT         RT<-flt(RA,I8) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FESD
argument_list|,
argument|RR
argument_list|,
literal|0x3b8
argument_list|,
literal|"fesd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* FESD          RT<-double(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FRDS
argument_list|,
argument|RR
argument_list|,
literal|0x3b9
argument_list|,
literal|"frds"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* FRDS          RT<-single(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSCRRD
argument_list|,
argument|RR
argument_list|,
literal|0x398
argument_list|,
literal|"fscrrd"
argument_list|,
argument|_A1(A_T)
argument_list|,
literal|00002
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* FSCRRD        RT<-FP_status */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSCRWR
argument_list|,
argument|RR
argument_list|,
literal|0x3ba
argument_list|,
literal|"fscrwr"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00010
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* FSCRWR        FP_status<-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FSCRWR2
argument_list|,
argument|RR
argument_list|,
literal|0x3ba
argument_list|,
literal|"fscrwr"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* FSCRWR        FP_status<-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLZ
argument_list|,
argument|RR
argument_list|,
literal|0x2a5
argument_list|,
literal|"clz"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLZ           RT<-clz(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CNTB
argument_list|,
argument|RR
argument_list|,
literal|0x2b4
argument_list|,
literal|"cntb"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FXB
argument_list|)
end_macro

begin_comment
comment|/* CNT           RT<-pop(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XSBH
argument_list|,
argument|RR
argument_list|,
literal|0x2b6
argument_list|,
literal|"xsbh"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* eXtSignBtoH   RT<-sign_ext(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XSHW
argument_list|,
argument|RR
argument_list|,
literal|0x2ae
argument_list|,
literal|"xshw"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* eXtSignHtoW   RT<-sign_ext(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XSWD
argument_list|,
argument|RR
argument_list|,
literal|0x2a6
argument_list|,
literal|"xswd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* eXtSignWtoD   RT<-sign_ext(RA) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTI
argument_list|,
argument|RI7
argument_list|,
literal|0x078
argument_list|,
literal|"roti"
argument_list|,
argument|_A3(A_T,A_A,A_S7N)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%I         RT<-RA<<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTMI
argument_list|,
argument|RI7
argument_list|,
literal|0x079
argument_list|,
literal|"rotmi"
argument_list|,
argument|_A3(A_T,A_A,A_S7)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%MI        RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTMAI
argument_list|,
argument|RI7
argument_list|,
literal|0x07a
argument_list|,
literal|"rotmai"
argument_list|,
argument|_A3(A_T,A_A,A_S7)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROTMA%I       RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLI
argument_list|,
argument|RI7
argument_list|,
literal|0x07b
argument_list|,
literal|"shli"
argument_list|,
argument|_A3(A_T,A_A,A_U6)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* SHL%I         RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTHI
argument_list|,
argument|RI7
argument_list|,
literal|0x07c
argument_list|,
literal|"rothi"
argument_list|,
argument|_A3(A_T,A_A,A_S7N)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%I         RT<-RA<<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTHMI
argument_list|,
argument|RI7
argument_list|,
literal|0x07d
argument_list|,
literal|"rothmi"
argument_list|,
argument|_A3(A_T,A_A,A_S6)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%MI        RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTMAHI
argument_list|,
argument|RI7
argument_list|,
literal|0x07e
argument_list|,
literal|"rotmahi"
argument_list|,
argument|_A3(A_T,A_A,A_S6)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROTMA%I       RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLHI
argument_list|,
argument|RI7
argument_list|,
literal|0x07f
argument_list|,
literal|"shlhi"
argument_list|,
argument|_A3(A_T,A_A,A_U5)
argument_list|,
literal|00012
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* SHL%I         RT<-RA<<I7 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_A
argument_list|,
argument|RR
argument_list|,
literal|0x0c0
argument_list|,
literal|"a"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add%          RT<-RA+RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_AH
argument_list|,
argument|RR
argument_list|,
literal|0x0c8
argument_list|,
literal|"ah"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add%          RT<-RA+RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SF
argument_list|,
argument|RR
argument_list|,
literal|0x040
argument_list|,
literal|"sf"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* SubFrom%      RT<-RB-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SFH
argument_list|,
argument|RR
argument_list|,
literal|0x048
argument_list|,
literal|"sfh"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* SubFrom%      RT<-RB-RA */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGT
argument_list|,
argument|RR
argument_list|,
literal|0x240
argument_list|,
literal|"cgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%          RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGTB
argument_list|,
argument|RR
argument_list|,
literal|0x250
argument_list|,
literal|"cgtb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%          RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGTH
argument_list|,
argument|RR
argument_list|,
literal|0x248
argument_list|,
literal|"cgth"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CGT%          RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGT
argument_list|,
argument|RR
argument_list|,
literal|0x2c0
argument_list|,
literal|"clgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%         RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGTB
argument_list|,
argument|RR
argument_list|,
literal|0x2d0
argument_list|,
literal|"clgtb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%         RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CLGTH
argument_list|,
argument|RR
argument_list|,
literal|0x2c8
argument_list|,
literal|"clgth"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CLGT%         RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3c0
argument_list|,
literal|"ceq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%          RT<-(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQB
argument_list|,
argument|RR
argument_list|,
literal|0x3d0
argument_list|,
literal|"ceqb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%          RT<-(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CEQH
argument_list|,
argument|RR
argument_list|,
literal|0x3c8
argument_list|,
literal|"ceqh"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CEQ%          RT<-(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HGT
argument_list|,
argument|RR
argument_list|,
literal|0x258
argument_list|,
literal|"hgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltGT        halt_if(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HGT2
argument_list|,
argument|RR
argument_list|,
literal|0x258
argument_list|,
literal|"hgt"
argument_list|,
argument|_A2(A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltGT        halt_if(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HLGT
argument_list|,
argument|RR
argument_list|,
literal|0x2d8
argument_list|,
literal|"hlgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltLGT       halt_if(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HLGT2
argument_list|,
argument|RR
argument_list|,
literal|0x2d8
argument_list|,
literal|"hlgt"
argument_list|,
argument|_A2(A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltLGT       halt_if(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3d8
argument_list|,
literal|"heq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltEQ        halt_if(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_HEQ2
argument_list|,
argument|RR
argument_list|,
literal|0x3d8
argument_list|,
literal|"heq"
argument_list|,
argument|_A2(A_A,A_B)
argument_list|,
literal|00110
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* HaltEQ        halt_if(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FCEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3c2
argument_list|,
literal|"fceq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* FCEQ          RT<-(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FCMEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3ca
argument_list|,
literal|"fcmeq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* FCMEQ         RT<-(|RA|=|RB|) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FCGT
argument_list|,
argument|RR
argument_list|,
literal|0x2c2
argument_list|,
literal|"fcgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* FCGT          RT<-(RA<RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FCMGT
argument_list|,
argument|RR
argument_list|,
literal|0x2ca
argument_list|,
literal|"fcmgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* FCMGT         RT<-(|RA|<|RB|) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_AND
argument_list|,
argument|RR
argument_list|,
literal|0x0c1
argument_list|,
literal|"and"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* AND           RT<-RA&RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_NAND
argument_list|,
argument|RR
argument_list|,
literal|0x0c9
argument_list|,
literal|"nand"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* NAND          RT<-!(RA&RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_OR
argument_list|,
argument|RR
argument_list|,
literal|0x041
argument_list|,
literal|"or"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* OR            RT<-RA|RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_NOR
argument_list|,
argument|RR
argument_list|,
literal|0x049
argument_list|,
literal|"nor"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* NOR           RT<-!(RA&RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_XOR
argument_list|,
argument|RR
argument_list|,
literal|0x241
argument_list|,
literal|"xor"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* XOR           RT<-RA^RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_EQV
argument_list|,
argument|RR
argument_list|,
literal|0x249
argument_list|,
literal|"eqv"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* EQuiValent    RT<-!(RA^RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ANDC
argument_list|,
argument|RR
argument_list|,
literal|0x2c1
argument_list|,
literal|"andc"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ANDComplement RT<-RA&!RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ORC
argument_list|,
argument|RR
argument_list|,
literal|0x2c9
argument_list|,
literal|"orc"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* ORComplement  RT<-RA|!RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ABSDB
argument_list|,
argument|RR
argument_list|,
literal|0x053
argument_list|,
literal|"absdb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FXB
argument_list|)
end_macro

begin_comment
comment|/* ABSoluteDiff  RT<-|RA-RB| */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_AVGB
argument_list|,
argument|RR
argument_list|,
literal|0x0d3
argument_list|,
literal|"avgb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FXB
argument_list|)
end_macro

begin_comment
comment|/* AVG%          RT<-(RA+RB+1)/2 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SUMB
argument_list|,
argument|RR
argument_list|,
literal|0x253
argument_list|,
literal|"sumb"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FXB
argument_list|)
end_macro

begin_comment
comment|/* SUM%          RT<-f(RA,RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFA
argument_list|,
argument|RR
argument_list|,
literal|0x2cc
argument_list|,
literal|"dfa"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFAdd         RT<-RA+RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFM
argument_list|,
argument|RR
argument_list|,
literal|0x2ce
argument_list|,
literal|"dfm"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFMul         RT<-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFS
argument_list|,
argument|RR
argument_list|,
literal|0x2cd
argument_list|,
literal|"dfs"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFSub         RT<-RA-RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FA
argument_list|,
argument|RR
argument_list|,
literal|0x2c4
argument_list|,
literal|"fa"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FAdd          RT<-RA+RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FM
argument_list|,
argument|RR
argument_list|,
literal|0x2c6
argument_list|,
literal|"fm"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FMul          RT<-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FS
argument_list|,
argument|RR
argument_list|,
literal|0x2c5
argument_list|,
literal|"fs"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FSub          RT<-RA-RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPY
argument_list|,
argument|RR
argument_list|,
literal|0x3c4
argument_list|,
literal|"mpy"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPY           RT<-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYH
argument_list|,
argument|RR
argument_list|,
literal|0x3c5
argument_list|,
literal|"mpyh"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYH          RT<-(RAh*RB)<<16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYHH
argument_list|,
argument|RR
argument_list|,
literal|0x3c6
argument_list|,
literal|"mpyhh"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYHH         RT<-RAh*RBh */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYHHU
argument_list|,
argument|RR
argument_list|,
literal|0x3ce
argument_list|,
literal|"mpyhhu"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYHHU        RT<-RAh*RBh */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYS
argument_list|,
argument|RR
argument_list|,
literal|0x3c7
argument_list|,
literal|"mpys"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYS          RT<-(RA*RB)>>16 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYU
argument_list|,
argument|RR
argument_list|,
literal|0x3cc
argument_list|,
literal|"mpyu"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYU          RT<-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FI
argument_list|,
argument|RR
argument_list|,
literal|0x3d4
argument_list|,
literal|"fi"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* FInterpolate  RT<-f(RA,RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROT
argument_list|,
argument|RR
argument_list|,
literal|0x058
argument_list|,
literal|"rot"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%          RT<-RA<<<RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTM
argument_list|,
argument|RR
argument_list|,
literal|0x059
argument_list|,
literal|"rotm"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%M         RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTMA
argument_list|,
argument|RR
argument_list|,
literal|0x05a
argument_list|,
literal|"rotma"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROTMA%        RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHL
argument_list|,
argument|RR
argument_list|,
literal|0x05b
argument_list|,
literal|"shl"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* SHL%          RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTH
argument_list|,
argument|RR
argument_list|,
literal|0x05c
argument_list|,
literal|"roth"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%          RT<-RA<<<RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTHM
argument_list|,
argument|RR
argument_list|,
literal|0x05d
argument_list|,
literal|"rothm"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROT%M         RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ROTMAH
argument_list|,
argument|RR
argument_list|,
literal|0x05e
argument_list|,
literal|"rotmah"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* ROTMA%        RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SHLH
argument_list|,
argument|RR
argument_list|,
literal|0x05f
argument_list|,
literal|"shlh"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX3
argument_list|)
end_macro

begin_comment
comment|/* SHL%          RT<-RA<<Rb */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYHHA
argument_list|,
argument|RR
argument_list|,
literal|0x346
argument_list|,
literal|"mpyhha"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYHHA        RT<-RAh*RBh+RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYHHAU
argument_list|,
argument|RR
argument_list|,
literal|0x34e
argument_list|,
literal|"mpyhhau"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYHHAU       RT<-RAh*RBh+RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFMA
argument_list|,
argument|RR
argument_list|,
literal|0x35c
argument_list|,
literal|"dfma"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFMAdd        RT<-RT+RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFMS
argument_list|,
argument|RR
argument_list|,
literal|0x35d
argument_list|,
literal|"dfms"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFMSub        RT<-RA*RB-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFNMS
argument_list|,
argument|RR
argument_list|,
literal|0x35e
argument_list|,
literal|"dfnms"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFNMSub       RT<-RT-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFNMA
argument_list|,
argument|RR
argument_list|,
literal|0x35f
argument_list|,
literal|"dfnma"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FPD
argument_list|)
end_macro

begin_comment
comment|/* DFNMAdd       RT<-(-RT)-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FMA
argument_list|,
argument|RRR
argument_list|,
literal|0x700
argument_list|,
literal|"fma"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FMAdd         RC<-RT+RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FMS
argument_list|,
argument|RRR
argument_list|,
literal|0x780
argument_list|,
literal|"fms"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FMSub         RC<-RA*RB-RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_FNMS
argument_list|,
argument|RRR
argument_list|,
literal|0x680
argument_list|,
literal|"fnms"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|FP6
argument_list|)
end_macro

begin_comment
comment|/* FNMSub        RC<-RT-RA*RB */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_MPYA
argument_list|,
argument|RRR
argument_list|,
literal|0x600
argument_list|,
literal|"mpya"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|FP7
argument_list|)
end_macro

begin_comment
comment|/* MPYA          RC<-RA*RB+RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SELB
argument_list|,
argument|RRR
argument_list|,
literal|0x400
argument_list|,
literal|"selb"
argument_list|,
argument|_A4(A_C,A_A,A_B,A_T)
argument_list|,
literal|02111
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* SELectBits    RC<-RA&RT|RB&!RT */
end_comment

begin_comment
comment|/* for system function call, this uses op-code of mtspr */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SYSCALL
argument_list|,
argument|RI7
argument_list|,
literal|0x10c
argument_list|,
literal|"syscall"
argument_list|,
argument|_A3(A_T,A_A,A_S7N)
argument_list|,
literal|00002
argument_list|,
argument|SPR
argument_list|)
end_macro

begin_comment
comment|/* System Call */
end_comment

begin_comment
comment|/* pseudo instruction: system call value of I9	operation 0	halt 1		rt[0] = open(MEM[ra[0]],	ra[1]) 2		rt[0] = close(ra[0]) 3		rt[0] = read(ra[0],	MEM[ra[1]],	ra[2]) 4		rt[0] = write(ra[0],	MEM[ra[1]],	ra[2]) 5		printf(MEM[ra[0]],	ra[1],	ra[2],	ra[3]) 42		rt[0] = clock() 52		rt[0] = lseek(ra0,	ra1,	ra2)  */
end_comment

begin_comment
comment|/* new multiprecision add/sub */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_ADDX
argument_list|,
argument|RR
argument_list|,
literal|0x340
argument_list|,
literal|"addx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add_eXtended  RT<-RA+RB+RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CG
argument_list|,
argument|RR
argument_list|,
literal|0x0c2
argument_list|,
literal|"cg"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CarryGenerate RT<-cout(RA+RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_CGX
argument_list|,
argument|RR
argument_list|,
literal|0x342
argument_list|,
literal|"cgx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CarryGen_eXtd RT<-cout(RA+RB+RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_SFX
argument_list|,
argument|RR
argument_list|,
literal|0x341
argument_list|,
literal|"sfx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* Add_eXtended  RT<-RA+RB+RT */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BG
argument_list|,
argument|RR
argument_list|,
literal|0x042
argument_list|,
literal|"bg"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CarryGenerate RT<-cout(RA+RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BGX
argument_list|,
argument|RR
argument_list|,
literal|0x343
argument_list|,
literal|"bgx"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00113
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* CarryGen_eXtd RT<-cout(RA+RB+RT) */
end_comment

begin_comment
comment|/*  The following ops are a subset of above except with feature bits set. Feature bits are bits 11-17 of the instruction:    11 - C& P feature bit   12 - disable interrupts   13 - enable interrupts  */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BID
argument_list|,
argument|RR
argument_list|,
literal|0x1a8
argument_list|,
literal|0x20
argument_list|,
literal|"bid"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BI            IP<-RA */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIE
argument_list|,
argument|RR
argument_list|,
literal|0x1a8
argument_list|,
literal|0x10
argument_list|,
literal|"bie"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BI            IP<-RA */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BISLD
argument_list|,
argument|RR
argument_list|,
literal|0x1a9
argument_list|,
literal|0x20
argument_list|,
literal|"bisld"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISL          RT,IP<-IP,RA */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BISLE
argument_list|,
argument|RR
argument_list|,
literal|0x1a9
argument_list|,
literal|0x10
argument_list|,
literal|"bisle"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISL          RT,IP<-IP,RA */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_IRETD
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|0x20
argument_list|,
literal|"iretd"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_IRETD2
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|0x20
argument_list|,
literal|"iretd"
argument_list|,
argument|_A0()
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_IRETE
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|0x10
argument_list|,
literal|"irete"
argument_list|,
argument|_A1(A_A)
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_IRETE2
argument_list|,
argument|RR
argument_list|,
literal|0x1aa
argument_list|,
literal|0x10
argument_list|,
literal|"irete"
argument_list|,
argument|_A0()
argument_list|,
literal|00010
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* IRET          IP<-SRR0 */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BISLEDD
argument_list|,
argument|RR
argument_list|,
literal|0x1ab
argument_list|,
literal|0x20
argument_list|,
literal|"bisledd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISLED        RT,IP<-IP,RA_if(ext) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BISLEDE
argument_list|,
argument|RR
argument_list|,
literal|0x1ab
argument_list|,
literal|0x10
argument_list|,
literal|"bislede"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BISLED        RT,IP<-IP,RA_if(ext) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHNZD
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|0x20
argument_list|,
literal|"bihnzd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNZ         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHNZE
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|0x10
argument_list|,
literal|"bihnze"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNZ         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHZD
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|0x20
argument_list|,
literal|"bihzd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHZE
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|0x10
argument_list|,
literal|"bihze"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BINZD
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|0x20
argument_list|,
literal|"binzd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BINZE
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|0x10
argument_list|,
literal|"binze"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIZD
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|0x20
argument_list|,
literal|"bizd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIZE
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|0x10
argument_list|,
literal|"bize"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_SYNCC
argument_list|,
argument|RR
argument_list|,
literal|0x002
argument_list|,
literal|0x40
argument_list|,
literal|"syncc"
argument_list|,
argument|_A0()
argument_list|,
literal|00000
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* SYNCC          flush_pipe */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_HBRP
argument_list|,
argument|LBTI
argument_list|,
literal|0x1ac
argument_list|,
literal|0x40
argument_list|,
literal|"hbrp"
argument_list|,
argument|_A0()
argument_list|,
literal|00010
argument_list|,
argument|LS
argument_list|)
end_macro

begin_comment
comment|/* HBR           BTB[B9]<-M[Ra] */
end_comment

begin_comment
comment|/* Synonyms required by the AS manual. */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_LR
argument_list|,
argument|RI10
argument_list|,
literal|0x020
argument_list|,
literal|"lr"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* OR%I          RT<-RA|I10 */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIHT
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|"biht"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNZ         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIHF
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|"bihf"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIT
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|"bit"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_BIF
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|"bif"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHTD
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|0x20
argument_list|,
literal|"bihtd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNF         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHTE
argument_list|,
argument|RR
argument_list|,
literal|0x12b
argument_list|,
literal|0x10
argument_list|,
literal|"bihte"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHNF         IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHFD
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|0x20
argument_list|,
literal|"bihfd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIHFE
argument_list|,
argument|RR
argument_list|,
literal|0x12a
argument_list|,
literal|0x10
argument_list|,
literal|"bihfe"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIHZ          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BITD
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|0x20
argument_list|,
literal|"bitd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINF          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BITE
argument_list|,
argument|RR
argument_list|,
literal|0x129
argument_list|,
literal|0x10
argument_list|,
literal|"bite"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BINF          IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIFD
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|0x20
argument_list|,
literal|"bifd"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_macro
name|APUOPFB
argument_list|(
argument|M_BIFE
argument_list|,
argument|RR
argument_list|,
literal|0x128
argument_list|,
literal|0x10
argument_list|,
literal|"bife"
argument_list|,
argument|_A2(A_T,A_A)
argument_list|,
literal|00011
argument_list|,
argument|BR
argument_list|)
end_macro

begin_comment
comment|/* BIZ           IP<-RA_if(RT) */
end_comment

begin_comment
comment|/* New soma double-float insns.  */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFCEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3c3
argument_list|,
literal|"dfceq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* DFCEQ         RT<-(RA=RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFCMEQ
argument_list|,
argument|RR
argument_list|,
literal|0x3cb
argument_list|,
literal|"dfcmeq"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* DFCMEQ        RT<-(|RA|=|RB|) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFCGT
argument_list|,
argument|RR
argument_list|,
literal|0x2c3
argument_list|,
literal|"dfcgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* DFCGT         RT<-(RA>RB) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFCMGT
argument_list|,
argument|RR
argument_list|,
literal|0x2cb
argument_list|,
literal|"dfcmgt"
argument_list|,
argument|_A3(A_T,A_A,A_B)
argument_list|,
literal|00112
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* DFCMGT        RT<-(|RA|>|RB|) */
end_comment

begin_macro
name|APUOP
argument_list|(
argument|M_DFTSV
argument_list|,
argument|RI7
argument_list|,
literal|0x3bf
argument_list|,
literal|"dftsv"
argument_list|,
argument|_A3(A_T,A_A,A_U7)
argument_list|,
literal|00012
argument_list|,
argument|FX2
argument_list|)
end_macro

begin_comment
comment|/* DFTSV         RT<-testspecial(RA,I7) */
end_comment

begin_undef
undef|#
directive|undef
name|_A0
end_undef

begin_undef
undef|#
directive|undef
name|_A1
end_undef

begin_undef
undef|#
directive|undef
name|_A2
end_undef

begin_undef
undef|#
directive|undef
name|_A3
end_undef

begin_undef
undef|#
directive|undef
name|_A4
end_undef

end_unit

