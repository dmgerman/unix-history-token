begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file       Register Definition for IPF.   Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IA64GEN_H_
end_ifndef

begin_define
define|#
directive|define
name|_IA64GEN_H_
end_define

begin_define
define|#
directive|define
name|TT_UNAT
value|0
end_define

begin_define
define|#
directive|define
name|C_PSR
value|0
end_define

begin_define
define|#
directive|define
name|J_UNAT
value|0
end_define

begin_define
define|#
directive|define
name|T_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|T_IPSR
value|0x8
end_define

begin_define
define|#
directive|define
name|T_ISR
value|0x10
end_define

begin_define
define|#
directive|define
name|T_IIP
value|0x18
end_define

begin_define
define|#
directive|define
name|T_IFA
value|0x20
end_define

begin_define
define|#
directive|define
name|T_IIPA
value|0x28
end_define

begin_define
define|#
directive|define
name|T_IFS
value|0x30
end_define

begin_define
define|#
directive|define
name|T_IIM
value|0x38
end_define

begin_define
define|#
directive|define
name|T_RSC
value|0x40
end_define

begin_define
define|#
directive|define
name|T_BSP
value|0x48
end_define

begin_define
define|#
directive|define
name|T_BSPSTORE
value|0x50
end_define

begin_define
define|#
directive|define
name|T_RNAT
value|0x58
end_define

begin_define
define|#
directive|define
name|T_PFS
value|0x60
end_define

begin_define
define|#
directive|define
name|T_KBSPSTORE
value|0x68
end_define

begin_define
define|#
directive|define
name|T_UNAT
value|0x70
end_define

begin_define
define|#
directive|define
name|T_CCV
value|0x78
end_define

begin_define
define|#
directive|define
name|T_DCR
value|0x80
end_define

begin_define
define|#
directive|define
name|T_PREDS
value|0x88
end_define

begin_define
define|#
directive|define
name|T_NATS
value|0x90
end_define

begin_define
define|#
directive|define
name|T_R1
value|0x98
end_define

begin_define
define|#
directive|define
name|T_GP
value|0x98
end_define

begin_define
define|#
directive|define
name|T_R2
value|0xa0
end_define

begin_define
define|#
directive|define
name|T_R3
value|0xa8
end_define

begin_define
define|#
directive|define
name|T_R4
value|0xb0
end_define

begin_define
define|#
directive|define
name|T_R5
value|0xb8
end_define

begin_define
define|#
directive|define
name|T_R6
value|0xc0
end_define

begin_define
define|#
directive|define
name|T_R7
value|0xc8
end_define

begin_define
define|#
directive|define
name|T_R8
value|0xd0
end_define

begin_define
define|#
directive|define
name|T_R9
value|0xd8
end_define

begin_define
define|#
directive|define
name|T_R10
value|0xe0
end_define

begin_define
define|#
directive|define
name|T_R11
value|0xe8
end_define

begin_define
define|#
directive|define
name|T_R12
value|0xf0
end_define

begin_define
define|#
directive|define
name|T_SP
value|0xf0
end_define

begin_define
define|#
directive|define
name|T_R13
value|0xf8
end_define

begin_define
define|#
directive|define
name|T_R14
value|0x100
end_define

begin_define
define|#
directive|define
name|T_R15
value|0x108
end_define

begin_define
define|#
directive|define
name|T_R16
value|0x110
end_define

begin_define
define|#
directive|define
name|T_R17
value|0x118
end_define

begin_define
define|#
directive|define
name|T_R18
value|0x120
end_define

begin_define
define|#
directive|define
name|T_R19
value|0x128
end_define

begin_define
define|#
directive|define
name|T_R20
value|0x130
end_define

begin_define
define|#
directive|define
name|T_R21
value|0x138
end_define

begin_define
define|#
directive|define
name|T_R22
value|0x140
end_define

begin_define
define|#
directive|define
name|T_R23
value|0x148
end_define

begin_define
define|#
directive|define
name|T_R24
value|0x150
end_define

begin_define
define|#
directive|define
name|T_R25
value|0x158
end_define

begin_define
define|#
directive|define
name|T_R26
value|0x160
end_define

begin_define
define|#
directive|define
name|T_R27
value|0x168
end_define

begin_define
define|#
directive|define
name|T_R28
value|0x170
end_define

begin_define
define|#
directive|define
name|T_R29
value|0x178
end_define

begin_define
define|#
directive|define
name|T_R30
value|0x180
end_define

begin_define
define|#
directive|define
name|T_R31
value|0x188
end_define

begin_define
define|#
directive|define
name|T_F2
value|0x1f0
end_define

begin_define
define|#
directive|define
name|T_F3
value|0x200
end_define

begin_define
define|#
directive|define
name|T_F4
value|0x210
end_define

begin_define
define|#
directive|define
name|T_F5
value|0x220
end_define

begin_define
define|#
directive|define
name|T_F6
value|0x230
end_define

begin_define
define|#
directive|define
name|T_F7
value|0x240
end_define

begin_define
define|#
directive|define
name|T_F8
value|0x250
end_define

begin_define
define|#
directive|define
name|T_F9
value|0x260
end_define

begin_define
define|#
directive|define
name|T_F10
value|0x270
end_define

begin_define
define|#
directive|define
name|T_F11
value|0x280
end_define

begin_define
define|#
directive|define
name|T_F12
value|0x290
end_define

begin_define
define|#
directive|define
name|T_F13
value|0x2a0
end_define

begin_define
define|#
directive|define
name|T_F14
value|0x2b0
end_define

begin_define
define|#
directive|define
name|T_F15
value|0x2c0
end_define

begin_define
define|#
directive|define
name|T_F16
value|0x2d0
end_define

begin_define
define|#
directive|define
name|T_F17
value|0x2e0
end_define

begin_define
define|#
directive|define
name|T_F18
value|0x2f0
end_define

begin_define
define|#
directive|define
name|T_F19
value|0x300
end_define

begin_define
define|#
directive|define
name|T_F20
value|0x310
end_define

begin_define
define|#
directive|define
name|T_F21
value|0x320
end_define

begin_define
define|#
directive|define
name|T_F22
value|0x330
end_define

begin_define
define|#
directive|define
name|T_F23
value|0x340
end_define

begin_define
define|#
directive|define
name|T_F24
value|0x350
end_define

begin_define
define|#
directive|define
name|T_F25
value|0x360
end_define

begin_define
define|#
directive|define
name|T_F26
value|0x370
end_define

begin_define
define|#
directive|define
name|T_F27
value|0x380
end_define

begin_define
define|#
directive|define
name|T_F28
value|0x390
end_define

begin_define
define|#
directive|define
name|T_F29
value|0x3a0
end_define

begin_define
define|#
directive|define
name|T_F30
value|0x3b0
end_define

begin_define
define|#
directive|define
name|T_F31
value|0x3c0
end_define

begin_define
define|#
directive|define
name|T_FPSR
value|0x1e0
end_define

begin_define
define|#
directive|define
name|T_B0
value|0x190
end_define

begin_define
define|#
directive|define
name|T_B1
value|0x198
end_define

begin_define
define|#
directive|define
name|T_B2
value|0x1a0
end_define

begin_define
define|#
directive|define
name|T_B3
value|0x1a8
end_define

begin_define
define|#
directive|define
name|T_B4
value|0x1b0
end_define

begin_define
define|#
directive|define
name|T_B5
value|0x1b8
end_define

begin_define
define|#
directive|define
name|T_B6
value|0x1c0
end_define

begin_define
define|#
directive|define
name|T_B7
value|0x1c8
end_define

begin_define
define|#
directive|define
name|T_EC
value|0x1d0
end_define

begin_define
define|#
directive|define
name|T_LC
value|0x1d8
end_define

begin_define
define|#
directive|define
name|J_NATS
value|0x8
end_define

begin_define
define|#
directive|define
name|J_PFS
value|0x10
end_define

begin_define
define|#
directive|define
name|J_BSP
value|0x18
end_define

begin_define
define|#
directive|define
name|J_RNAT
value|0x20
end_define

begin_define
define|#
directive|define
name|J_PREDS
value|0x28
end_define

begin_define
define|#
directive|define
name|J_LC
value|0x30
end_define

begin_define
define|#
directive|define
name|J_R4
value|0x38
end_define

begin_define
define|#
directive|define
name|J_R5
value|0x40
end_define

begin_define
define|#
directive|define
name|J_R6
value|0x48
end_define

begin_define
define|#
directive|define
name|J_R7
value|0x50
end_define

begin_define
define|#
directive|define
name|J_SP
value|0x58
end_define

begin_define
define|#
directive|define
name|J_F2
value|0x60
end_define

begin_define
define|#
directive|define
name|J_F3
value|0x70
end_define

begin_define
define|#
directive|define
name|J_F4
value|0x80
end_define

begin_define
define|#
directive|define
name|J_F5
value|0x90
end_define

begin_define
define|#
directive|define
name|J_F16
value|0xa0
end_define

begin_define
define|#
directive|define
name|J_F17
value|0xb0
end_define

begin_define
define|#
directive|define
name|J_F18
value|0xc0
end_define

begin_define
define|#
directive|define
name|J_F19
value|0xd0
end_define

begin_define
define|#
directive|define
name|J_F20
value|0xe0
end_define

begin_define
define|#
directive|define
name|J_F21
value|0xf0
end_define

begin_define
define|#
directive|define
name|J_F22
value|0x100
end_define

begin_define
define|#
directive|define
name|J_F23
value|0x110
end_define

begin_define
define|#
directive|define
name|J_F24
value|0x120
end_define

begin_define
define|#
directive|define
name|J_F25
value|0x130
end_define

begin_define
define|#
directive|define
name|J_F26
value|0x140
end_define

begin_define
define|#
directive|define
name|J_F27
value|0x150
end_define

begin_define
define|#
directive|define
name|J_F28
value|0x160
end_define

begin_define
define|#
directive|define
name|J_F29
value|0x170
end_define

begin_define
define|#
directive|define
name|J_F30
value|0x180
end_define

begin_define
define|#
directive|define
name|J_F31
value|0x190
end_define

begin_define
define|#
directive|define
name|J_FPSR
value|0x1a0
end_define

begin_define
define|#
directive|define
name|J_B0
value|0x1a8
end_define

begin_define
define|#
directive|define
name|J_B1
value|0x1b0
end_define

begin_define
define|#
directive|define
name|J_B2
value|0x1b8
end_define

begin_define
define|#
directive|define
name|J_B3
value|0x1c0
end_define

begin_define
define|#
directive|define
name|J_B4
value|0x1c8
end_define

begin_define
define|#
directive|define
name|J_B5
value|0x1d0
end_define

begin_define
define|#
directive|define
name|TRAP_FRAME_LENGTH
value|0x3d0
end_define

begin_define
define|#
directive|define
name|C_UNAT
value|0x28
end_define

begin_define
define|#
directive|define
name|C_NATS
value|0x30
end_define

begin_define
define|#
directive|define
name|C_PFS
value|0x8
end_define

begin_define
define|#
directive|define
name|C_BSPSTORE
value|0x10
end_define

begin_define
define|#
directive|define
name|C_RNAT
value|0x18
end_define

begin_define
define|#
directive|define
name|C_RSC
value|0x20
end_define

begin_define
define|#
directive|define
name|C_PREDS
value|0x38
end_define

begin_define
define|#
directive|define
name|C_LC
value|0x40
end_define

begin_define
define|#
directive|define
name|C_DCR
value|0x48
end_define

begin_define
define|#
directive|define
name|C_R1
value|0x50
end_define

begin_define
define|#
directive|define
name|C_GP
value|0x50
end_define

begin_define
define|#
directive|define
name|C_R4
value|0x58
end_define

begin_define
define|#
directive|define
name|C_R5
value|0x60
end_define

begin_define
define|#
directive|define
name|C_R6
value|0x68
end_define

begin_define
define|#
directive|define
name|C_R7
value|0x70
end_define

begin_define
define|#
directive|define
name|C_SP
value|0x78
end_define

begin_define
define|#
directive|define
name|C_R13
value|0x80
end_define

begin_define
define|#
directive|define
name|C_F2
value|0x90
end_define

begin_define
define|#
directive|define
name|C_F3
value|0xa0
end_define

begin_define
define|#
directive|define
name|C_F4
value|0xb0
end_define

begin_define
define|#
directive|define
name|C_F5
value|0xc0
end_define

begin_define
define|#
directive|define
name|C_F16
value|0xd0
end_define

begin_define
define|#
directive|define
name|C_F17
value|0xe0
end_define

begin_define
define|#
directive|define
name|C_F18
value|0xf0
end_define

begin_define
define|#
directive|define
name|C_F19
value|0x100
end_define

begin_define
define|#
directive|define
name|C_F20
value|0x110
end_define

begin_define
define|#
directive|define
name|C_F21
value|0x120
end_define

begin_define
define|#
directive|define
name|C_F22
value|0x130
end_define

begin_define
define|#
directive|define
name|C_F23
value|0x140
end_define

begin_define
define|#
directive|define
name|C_F24
value|0x150
end_define

begin_define
define|#
directive|define
name|C_F25
value|0x160
end_define

begin_define
define|#
directive|define
name|C_F26
value|0x170
end_define

begin_define
define|#
directive|define
name|C_F27
value|0x180
end_define

begin_define
define|#
directive|define
name|C_F28
value|0x190
end_define

begin_define
define|#
directive|define
name|C_F29
value|0x1a0
end_define

begin_define
define|#
directive|define
name|C_F30
value|0x1b0
end_define

begin_define
define|#
directive|define
name|C_F31
value|0x1c0
end_define

begin_define
define|#
directive|define
name|C_FPSR
value|0x1d0
end_define

begin_define
define|#
directive|define
name|C_B0
value|0x1d8
end_define

begin_define
define|#
directive|define
name|C_B1
value|0x1e0
end_define

begin_define
define|#
directive|define
name|C_B2
value|0x1e8
end_define

begin_define
define|#
directive|define
name|C_B3
value|0x1f0
end_define

begin_define
define|#
directive|define
name|C_B4
value|0x1f8
end_define

begin_define
define|#
directive|define
name|C_B5
value|0x200
end_define

begin_define
define|#
directive|define
name|TT_R2
value|0x8
end_define

begin_define
define|#
directive|define
name|TT_R3
value|0x10
end_define

begin_define
define|#
directive|define
name|TT_R8
value|0x18
end_define

begin_define
define|#
directive|define
name|TT_R9
value|0x20
end_define

begin_define
define|#
directive|define
name|TT_R10
value|0x28
end_define

begin_define
define|#
directive|define
name|TT_R11
value|0x30
end_define

begin_define
define|#
directive|define
name|TT_R14
value|0x38
end_define

begin_endif
endif|#
directive|endif
endif|_IA64GEN_H
end_endif

end_unit

