begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC
parameter_list|(
name|n
parameter_list|)
value|(n * 0x04)
end_define

begin_define
define|#
directive|define
name|IOMUXCN
value|135
end_define

begin_define
define|#
directive|define
name|IOMUXC_PTA6
value|0x000
end_define

begin_comment
comment|/* Software MUX Pad Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA8
value|0x004
end_define

begin_comment
comment|/* Software MUX Pad Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA9
value|0x008
end_define

begin_comment
comment|/* Software MUX Pad Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA10
value|0x00C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 3 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA11
value|0x010
end_define

begin_comment
comment|/* Software MUX Pad Control Register 4 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA12
value|0x014
end_define

begin_comment
comment|/* Software MUX Pad Control Register 5 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA16
value|0x018
end_define

begin_comment
comment|/* Software MUX Pad Control Register 6 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA17
value|0x01C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 7 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA18
value|0x020
end_define

begin_comment
comment|/* Software MUX Pad Control Register 8 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA19
value|0x024
end_define

begin_comment
comment|/* Software MUX Pad Control Register 9 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA20
value|0x028
end_define

begin_comment
comment|/* Software MUX Pad Control Register 10 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA21
value|0x02C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 11 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA22
value|0x030
end_define

begin_comment
comment|/* Software MUX Pad Control Register 12 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA23
value|0x034
end_define

begin_comment
comment|/* Software MUX Pad Control Register 13 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA24
value|0x038
end_define

begin_comment
comment|/* Software MUX Pad Control Register 14 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA25
value|0x03C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 15 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA26
value|0x040
end_define

begin_comment
comment|/* Software MUX Pad Control Register 16 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA27
value|0x044
end_define

begin_comment
comment|/* Software MUX Pad Control Register 17 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA28
value|0x048
end_define

begin_comment
comment|/* Software MUX Pad Control Register 18 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA29
value|0x04C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 19 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA30
value|0x050
end_define

begin_comment
comment|/* Software MUX Pad Control Register 20 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA31
value|0x054
end_define

begin_comment
comment|/* Software MUX Pad Control Register 21 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB0
value|0x058
end_define

begin_comment
comment|/* Software MUX Pad Control Register 22 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB1
value|0x05C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 23 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB2
value|0x060
end_define

begin_comment
comment|/* Software MUX Pad Control Register 24 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB3
value|0x064
end_define

begin_comment
comment|/* Software MUX Pad Control Register 25 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB4
value|0x068
end_define

begin_comment
comment|/* Software MUX Pad Control Register 26 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB5
value|0x06C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 27 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB6
value|0x070
end_define

begin_comment
comment|/* Software MUX Pad Control Register 28 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB7
value|0x074
end_define

begin_comment
comment|/* Software MUX Pad Control Register 29 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB8
value|0x078
end_define

begin_comment
comment|/* Software MUX Pad Control Register 30 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB9
value|0x07C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 31 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB10
value|0x080
end_define

begin_comment
comment|/* Software MUX Pad Control Register 32 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB11
value|0x084
end_define

begin_comment
comment|/* Software MUX Pad Control Register 33 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB12
value|0x088
end_define

begin_comment
comment|/* Software MUX Pad Control Register 34 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB13
value|0x08C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 35 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB14
value|0x090
end_define

begin_comment
comment|/* Software MUX Pad Control Register 36 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB15
value|0x094
end_define

begin_comment
comment|/* Software MUX Pad Control Register 37 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB16
value|0x098
end_define

begin_comment
comment|/* Software MUX Pad Control Register 38 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB17
value|0x09C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 39 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB18
value|0x0A0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 40 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB19
value|0x0A4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 41 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB20
value|0x0A8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 42 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB21
value|0x0AC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 43 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB22
value|0x0B0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 44 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC0
value|0x0B4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 45 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC1
value|0x0B8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 46 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC2
value|0x0BC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 47 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC3
value|0x0C0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 48 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC4
value|0x0C4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 49 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC5
value|0x0C8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 50 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC6
value|0x0CC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 51 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC7
value|0x0D0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 52 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC8
value|0x0D4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 53 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC9
value|0x0D8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 54 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC10
value|0x0DC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 55 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC11
value|0x0E0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 56 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC12
value|0x0E4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 57 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC13
value|0x0E8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 58 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC14
value|0x0EC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 59 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC15
value|0x0F0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 60 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC16
value|0x0F4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 61 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC17
value|0x0F8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 62 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD31
value|0x0FC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 63 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD30
value|0x100
end_define

begin_comment
comment|/* Software MUX Pad Control Register 64 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD29
value|0x104
end_define

begin_comment
comment|/* Software MUX Pad Control Register 65 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD28
value|0x108
end_define

begin_comment
comment|/* Software MUX Pad Control Register 66 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD27
value|0x10C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 67 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD26
value|0x110
end_define

begin_comment
comment|/* Software MUX Pad Control Register 68 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD25
value|0x114
end_define

begin_comment
comment|/* Software MUX Pad Control Register 69 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD24
value|0x118
end_define

begin_comment
comment|/* Software MUX Pad Control Register 70 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD23
value|0x11C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 71 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD22
value|0x120
end_define

begin_comment
comment|/* Software MUX Pad Control Register 72 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD21
value|0x124
end_define

begin_comment
comment|/* Software MUX Pad Control Register 73 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD20
value|0x128
end_define

begin_comment
comment|/* Software MUX Pad Control Register 74 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD19
value|0x12C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 75 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD18
value|0x130
end_define

begin_comment
comment|/* Software MUX Pad Control Register 76 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD17
value|0x134
end_define

begin_comment
comment|/* Software MUX Pad Control Register 77 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD16
value|0x138
end_define

begin_comment
comment|/* Software MUX Pad Control Register 78 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD0
value|0x13C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 79 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD1
value|0x140
end_define

begin_comment
comment|/* Software MUX Pad Control Register 80 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD2
value|0x144
end_define

begin_comment
comment|/* Software MUX Pad Control Register 81 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD3
value|0x148
end_define

begin_comment
comment|/* Software MUX Pad Control Register 82 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD4
value|0x14C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 83 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD5
value|0x150
end_define

begin_comment
comment|/* Software MUX Pad Control Register 84 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD6
value|0x154
end_define

begin_comment
comment|/* Software MUX Pad Control Register 85 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD7
value|0x158
end_define

begin_comment
comment|/* Software MUX Pad Control Register 86 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD8
value|0x15C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 87 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD9
value|0x160
end_define

begin_comment
comment|/* Software MUX Pad Control Register 88 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD10
value|0x164
end_define

begin_comment
comment|/* Software MUX Pad Control Register 89 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD11
value|0x168
end_define

begin_comment
comment|/* Software MUX Pad Control Register 90 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD12
value|0x16C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 91 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTD13
value|0x170
end_define

begin_comment
comment|/* Software MUX Pad Control Register 92 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB23
value|0x174
end_define

begin_comment
comment|/* Software MUX Pad Control Register 93 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB24
value|0x178
end_define

begin_comment
comment|/* Software MUX Pad Control Register 94 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB25
value|0x17C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 95 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB26
value|0x180
end_define

begin_comment
comment|/* Software MUX Pad Control Register 96 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB27
value|0x184
end_define

begin_comment
comment|/* Software MUX Pad Control Register 97 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTB28
value|0x188
end_define

begin_comment
comment|/* Software MUX Pad Control Register 98 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC26
value|0x18C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 99 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC27
value|0x190
end_define

begin_comment
comment|/* Software MUX Pad Control Register 100 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC28
value|0x194
end_define

begin_comment
comment|/* Software MUX Pad Control Register 101 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC29
value|0x198
end_define

begin_comment
comment|/* Software MUX Pad Control Register 102 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC30
value|0x19C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 103 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTC31
value|0x1A0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 104 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE0
value|0x1A4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 105 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE1
value|0x1A8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 106 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE2
value|0x1AC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 107 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE3
value|0x1B0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 108 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE4
value|0x1B4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 109 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE5
value|0x1B8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 110 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE6
value|0x1BC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 111 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE7
value|0x1C0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 112 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE8
value|0x1C4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 113 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE9
value|0x1C8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 114 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE10
value|0x1CC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 115 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE11
value|0x1D0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 116 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE12
value|0x1D4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 117 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE13
value|0x1D8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 118 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE14
value|0x1DC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 119 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE15
value|0x1E0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 120 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE16
value|0x1E4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 121 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE17
value|0x1E8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 122 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE18
value|0x1EC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 123 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE19
value|0x1F0
end_define

begin_comment
comment|/* Software MUX Pad Control Register 124 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE20
value|0x1F4
end_define

begin_comment
comment|/* Software MUX Pad Control Register 125 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE21
value|0x1F8
end_define

begin_comment
comment|/* Software MUX Pad Control Register 126 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE22
value|0x1FC
end_define

begin_comment
comment|/* Software MUX Pad Control Register 127 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE23
value|0x200
end_define

begin_comment
comment|/* Software MUX Pad Control Register 128 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE24
value|0x204
end_define

begin_comment
comment|/* Software MUX Pad Control Register 129 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE25
value|0x208
end_define

begin_comment
comment|/* Software MUX Pad Control Register 130 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE26
value|0x20C
end_define

begin_comment
comment|/* Software MUX Pad Control Register 131 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE27
value|0x210
end_define

begin_comment
comment|/* Software MUX Pad Control Register 132 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTE28
value|0x214
end_define

begin_comment
comment|/* Software MUX Pad Control Register 133 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PTA7
value|0x218
end_define

begin_comment
comment|/* Software MUX Pad Control Register 134 */
end_comment

end_unit

