begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * This file contains wcs code   *  */
end_comment

begin_comment
comment|/* wcsImage */
end_comment

begin_decl_stmt
name|bit32
name|oldwcsImage
index|[]
init|=
block|{
literal|0x011
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ba
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0bb
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x010
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ba
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0bb
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x033
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x011
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0bb
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x010
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0bb
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x010
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0ca
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x010
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x0ff
block|,
comment|// 0x02a = 42 -
literal|0x01b
block|,
comment|// 0x02b = 43 - START_IT_NEXUS_LOSS_TIMER_SFO
literal|0x017
block|,
comment|// 0x02c = 44 - PATHWAY_BLOCKED_CNT_SFO_RESET
literal|0x013
block|,
comment|// 0x02d = 45 - START_ARB_WAIT_TIMER_SFO
literal|0x001
block|,
comment|// 0x02e = 46 - OPEN_REQUEST_SFO
literal|0x000
block|,
comment|// 0x02f = 47 - NO_OP
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x000
block|,
comment|// 0x031 = 49 - NO_OP
literal|0x000
block|,
comment|// 0x032 = 50 - NO_OP
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x091
block|,
comment|// 0x034 = 52 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x056
block|,
comment|// 0x035 = 53 -
literal|0x097
block|,
comment|// 0x036 = 54 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x059
block|,
comment|// 0x037 = 55 -
literal|0x09b
block|,
comment|// 0x038 = 56 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x05c
block|,
comment|// 0x039 = 57 -
literal|0x09d
block|,
comment|// 0x03a = 58 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x05f
block|,
comment|// 0x03b = 59 -
literal|0x096
block|,
comment|// 0x03c = 60 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x062
block|,
comment|// 0x03d = 61 -
literal|0x095
block|,
comment|// 0x03e = 62 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x065
block|,
comment|// 0x03f = 63 -
literal|0x0a1
block|,
comment|// 0x040 = 64 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_SFO
literal|0x068
block|,
comment|// 0x041 = 65 -
literal|0x09c
block|,
comment|// 0x042 = 66 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x02b
block|,
comment|// 0x043 = 67 -
literal|0x098
block|,
comment|// 0x044 = 68 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x0ff
block|,
comment|// 0x045 = 69 -
literal|0x099
block|,
comment|// 0x046 = 70 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x06b
block|,
comment|// 0x047 = 71 -
literal|0x09a
block|,
comment|// 0x048 = 72 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x02e
block|,
comment|// 0x049 = 73 -
literal|0x094
block|,
comment|// 0x04a = 74 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x02e
block|,
comment|// 0x04b = 75 -
literal|0x0a7
block|,
comment|// 0x04c = 76 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x114
block|,
comment|// 0x04d = 77 -
literal|0x092
block|,
comment|// 0x04e = 78 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x02e
block|,
comment|// 0x04f = 79 -
literal|0x0ca
block|,
comment|// 0x050 = 80 - JUMP_IF_PHY_READY
literal|0x034
block|,
comment|// 0x051 = 81 -
literal|0x031
block|,
comment|// 0x052 = 82 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x053 = 83 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x054 = 84 - JUMP
literal|0x001
block|,
comment|// 0x055 = 85 -
literal|0x021
block|,
comment|// 0x056 = 86 - SET_OPEN_STATUS_NORMAL_SFO
literal|0x0ff
block|,
comment|// 0x057 = 87 - JUMP
literal|0x06e
block|,
comment|// 0x058 = 88 -
literal|0x025
block|,
comment|// 0x059 = 89 - SET_OPEN_STATUS_BAD_RATE_SFO
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x0ff
block|,
comment|// 0x05b = 91 -
literal|0x026
block|,
comment|// 0x05c = 92 - SET_OPEN_STATUS_BAD_PROTOCOL_SFO
literal|0x0ff
block|,
comment|// 0x05d = 93 - JUMP
literal|0x0ff
block|,
comment|// 0x05e = 94 -
literal|0x028
block|,
comment|// 0x05f = 95 - SET_OPEN_STATUS_WRONG_DEST_SFO
literal|0x0ff
block|,
comment|// 0x060 = 96 - JUMP
literal|0x0ff
block|,
comment|// 0x061 = 97 -
literal|0x024
block|,
comment|// 0x062 = 98 - SET_OPEN_STATUS_BREAK_SFO
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x0ff
block|,
comment|// 0x064 = 100 -
literal|0x023
block|,
comment|// 0x065 = 101 - SET_OPEN_STATUS_BAD_DEST_SFO
literal|0x0ff
block|,
comment|// 0x066 = 102 - JUMP
literal|0x0ff
block|,
comment|// 0x067 = 103 -
literal|0x022
block|,
comment|// 0x068 = 104 - SET_OPEN_STATUS_IT_NEXUS_LOSS_SFO
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x0ff
block|,
comment|// 0x06a = 106 -
literal|0x019
block|,
comment|// 0x06b = 107 - PATHWAY_BLOCKED_CNT_SFO_INC
literal|0x0ff
block|,
comment|// 0x06c = 108 - JUMP
literal|0x02e
block|,
comment|// 0x06d = 109 -
literal|0x000
block|,
comment|// 0x06e = 110 - NO_OP
literal|0x0aa
block|,
comment|// 0x06f = 111 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x08e
block|,
comment|// 0x070 = 112 -
literal|0x0ab
block|,
comment|// 0x071 = 113 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x080
block|,
comment|// 0x072 = 114 -
literal|0x0ac
block|,
comment|// 0x073 = 115 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x083
block|,
comment|// 0x074 = 116 -
literal|0x0ad
block|,
comment|// 0x075 = 117 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x083
block|,
comment|// 0x076 = 118 -
literal|0x0af
block|,
comment|// 0x077 = 119 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x087
block|,
comment|// 0x078 = 120 -
literal|0x0ae
block|,
comment|// 0x079 = 121 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x080
block|,
comment|// 0x07a = 122 -
literal|0x0ca
block|,
comment|// 0x07b = 123 - JUMP_IF_PHY_READY
literal|0x06f
block|,
comment|// 0x07c = 124 -
literal|0x033
block|,
comment|// 0x07d = 125 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x07e = 126 - JUMP
literal|0x001
block|,
comment|// 0x07f = 127 -
literal|0x006
block|,
comment|// 0x080 = 128 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x081 = 129 - JUMP
literal|0x08b
block|,
comment|// 0x082 = 130 -
literal|0x009
block|,
comment|// 0x083 = 131 - CLOSE_BREAK
literal|0x034
block|,
comment|// 0x084 = 132 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x085 = 133 - JUMP
literal|0x0ff
block|,
comment|// 0x086 = 134 -
literal|0x009
block|,
comment|// 0x087 = 135 - CLOSE_BREAK
literal|0x034
block|,
comment|// 0x088 = 136 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x089 = 137 - JUMP
literal|0x0ff
block|,
comment|// 0x08a = 138 -
literal|0x034
block|,
comment|// 0x08b = 139 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x08c = 140 - JUMP
literal|0x12d
block|,
comment|// 0x08d = 141 -
literal|0x034
block|,
comment|// 0x08e = 142 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x08f = 143 - JUMP
literal|0x0ff
block|,
comment|// 0x090 = 144 -
literal|0x01c
block|,
comment|// 0x091 = 145 - START_IT_NEXUS_LOSS_TIMER_DOC
literal|0x018
block|,
comment|// 0x092 = 146 - PATHWAY_BLOCKED_CNT_DOC_RESET
literal|0x014
block|,
comment|// 0x093 = 147 - START_ARB_WAIT_TIMER_DOC
literal|0x002
block|,
comment|// 0x094 = 148 - OPEN_REQUEST_DOC
literal|0x000
block|,
comment|// 0x095 = 149 - NO_OP
literal|0x000
block|,
comment|// 0x096 = 150 - NO_OP
literal|0x000
block|,
comment|// 0x097 = 151 - NO_OP
literal|0x000
block|,
comment|// 0x098 = 152 - NO_OP
literal|0x000
block|,
comment|// 0x099 = 153 - NO_OP
literal|0x091
block|,
comment|// 0x09a = 154 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0bc
block|,
comment|// 0x09b = 155 -
literal|0x097
block|,
comment|// 0x09c = 156 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0bf
block|,
comment|// 0x09d = 157 -
literal|0x09b
block|,
comment|// 0x09e = 158 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0c2
block|,
comment|// 0x09f = 159 -
literal|0x09d
block|,
comment|// 0x0a0 = 160 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0c5
block|,
comment|// 0x0a1 = 161 -
literal|0x096
block|,
comment|// 0x0a2 = 162 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0c8
block|,
comment|// 0x0a3 = 163 -
literal|0x095
block|,
comment|// 0x0a4 = 164 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0cb
block|,
comment|// 0x0a5 = 165 -
literal|0x0a2
block|,
comment|// 0x0a6 = 166 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_DOC
literal|0x0ce
block|,
comment|// 0x0a7 = 167 -
literal|0x09c
block|,
comment|// 0x0a8 = 168 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x091
block|,
comment|// 0x0a9 = 169 -
literal|0x098
block|,
comment|// 0x0aa = 170 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x0ff
block|,
comment|// 0x0ab = 171 -
literal|0x099
block|,
comment|// 0x0ac = 172 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0d1
block|,
comment|// 0x0ad = 173 -
literal|0x09a
block|,
comment|// 0x0ae = 174 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x094
block|,
comment|// 0x0af = 175 -
literal|0x094
block|,
comment|// 0x0b0 = 176 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x094
block|,
comment|// 0x0b1 = 177 -
literal|0x0a7
block|,
comment|// 0x0b2 = 178 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x122
block|,
comment|// 0x0b3 = 179 -
literal|0x092
block|,
comment|// 0x0b4 = 180 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x094
block|,
comment|// 0x0b5 = 181 -
literal|0x0ca
block|,
comment|// 0x0b6 = 182 - JUMP_IF_PHY_READY
literal|0x09a
block|,
comment|// 0x0b7 = 183 -
literal|0x032
block|,
comment|// 0x0b8 = 184 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x0b9 = 185 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0ba = 186 - JUMP
literal|0x001
block|,
comment|// 0x0bb = 187 -
literal|0x029
block|,
comment|// 0x0bc = 188 - SET_OPEN_STATUS_NORMAL_DOC
literal|0x0ff
block|,
comment|// 0x0bd = 189 - JUMP
literal|0x0d4
block|,
comment|// 0x0be = 190 -
literal|0x02d
block|,
comment|// 0x0bf = 191 - SET_OPEN_STATUS_BAD_RATE_DOC
literal|0x0ff
block|,
comment|// 0x0c0 = 192 - JUMP
literal|0x0ff
block|,
comment|// 0x0c1 = 193 -
literal|0x02e
block|,
comment|// 0x0c2 = 194 - SET_OPEN_STATUS_BAD_PROTOCOL_DOC
literal|0x0ff
block|,
comment|// 0x0c3 = 195 - JUMP
literal|0x0ff
block|,
comment|// 0x0c4 = 196 -
literal|0x030
block|,
comment|// 0x0c5 = 197 - SET_OPEN_STATUS_WRONG_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0c6 = 198 - JUMP
literal|0x0ff
block|,
comment|// 0x0c7 = 199 -
literal|0x02c
block|,
comment|// 0x0c8 = 200 - SET_OPEN_STATUS_BREAK_DOC
literal|0x0ff
block|,
comment|// 0x0c9 = 201 - JUMP
literal|0x0ff
block|,
comment|// 0x0ca = 202 -
literal|0x02b
block|,
comment|// 0x0cb = 203 - SET_OPEN_STATUS_BAD_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0cc = 204 - JUMP
literal|0x0ff
block|,
comment|// 0x0cd = 205 -
literal|0x02a
block|,
comment|// 0x0ce = 206 - SET_OPEN_STATUS_IT_NEXUS_LOSS_DOC
literal|0x0ff
block|,
comment|// 0x0cf = 207 - JUMP
literal|0x0ff
block|,
comment|// 0x0d0 = 208 -
literal|0x01a
block|,
comment|// 0x0d1 = 209 - PATHWAY_BLOCKED_CNT_DOC_INC
literal|0x0ff
block|,
comment|// 0x0d2 = 210 - JUMP
literal|0x094
block|,
comment|// 0x0d3 = 211 -
literal|0x000
block|,
comment|// 0x0d4 = 212 - NO_OP
literal|0x0b1
block|,
comment|// 0x0d5 = 213 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x0fc
block|,
comment|// 0x0d6 = 214 -
literal|0x0b2
block|,
comment|// 0x0d7 = 215 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x0ee
block|,
comment|// 0x0d8 = 216 -
literal|0x0b3
block|,
comment|// 0x0d9 = 217 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x0f1
block|,
comment|// 0x0da = 218 -
literal|0x0b4
block|,
comment|// 0x0db = 219 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x0f1
block|,
comment|// 0x0dc = 220 -
literal|0x0b6
block|,
comment|// 0x0dd = 221 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x0f5
block|,
comment|// 0x0de = 222 -
literal|0x0b5
block|,
comment|// 0x0df = 223 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x0ee
block|,
comment|// 0x0e0 = 224 -
literal|0x0ca
block|,
comment|// 0x0e1 = 225 - JUMP_IF_PHY_READY
literal|0x0e6
block|,
comment|// 0x0e2 = 226 -
literal|0x033
block|,
comment|// 0x0e3 = 227 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0e4 = 228 - JUMP
literal|0x001
block|,
comment|// 0x0e5 = 229 -
literal|0x0b7
block|,
comment|// 0x0e6 = 230 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x0ee
block|,
comment|// 0x0e7 = 231 -
literal|0x0b8
block|,
comment|// 0x0e8 = 232 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x0ee
block|,
comment|// 0x0e9 = 233 -
literal|0x0b9
block|,
comment|// 0x0ea = 234 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x0ee
block|,
comment|// 0x0eb = 235 -
literal|0x0ff
block|,
comment|// 0x0ec = 236 - JUMP
literal|0x0d5
block|,
comment|// 0x0ed = 237 -
literal|0x006
block|,
comment|// 0x0ee = 238 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x0ef = 239 - JUMP
literal|0x0f9
block|,
comment|// 0x0f0 = 240 -
literal|0x009
block|,
comment|// 0x0f1 = 241 - CLOSE_BREAK
literal|0x035
block|,
comment|// 0x0f2 = 242 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x0f3 = 243 - JUMP
literal|0x0ff
block|,
comment|// 0x0f4 = 244 -
literal|0x009
block|,
comment|// 0x0f5 = 245 - CLOSE_BREAK
literal|0x035
block|,
comment|// 0x0f6 = 246 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x0f7 = 247 - JUMP
literal|0x0ff
block|,
comment|// 0x0f8 = 248 -
literal|0x035
block|,
comment|// 0x0f9 = 249 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x0fa = 250 - JUMP
literal|0x12d
block|,
comment|// 0x0fb = 251 -
literal|0x035
block|,
comment|// 0x0fc = 252 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x0fd = 253 - JUMP
literal|0x0ff
block|,
comment|// 0x0fe = 254 -
literal|0x0a9
block|,
comment|// 0x0ff = 255 - JUMP_IF_SFO_REQ
literal|0x10a
block|,
comment|// 0x100 = 256 -
literal|0x0b0
block|,
comment|// 0x101 = 257 - JUMP_IF_DOC_REQ
literal|0x118
block|,
comment|// 0x102 = 258 -
literal|0x0a8
block|,
comment|// 0x103 = 259 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x126
block|,
comment|// 0x104 = 260 -
literal|0x0ca
block|,
comment|// 0x105 = 261 - JUMP_IF_PHY_READY
literal|0x0ff
block|,
comment|// 0x106 = 262 -
literal|0x033
block|,
comment|// 0x107 = 263 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x108 = 264 - JUMP
literal|0x001
block|,
comment|// 0x109 = 265 -
literal|0x0ca
block|,
comment|// 0x10a = 266 - JUMP_IF_PHY_READY
literal|0x110
block|,
comment|// 0x10b = 267 -
literal|0x031
block|,
comment|// 0x10c = 268 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x10d = 269 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x10e = 270 - JUMP
literal|0x001
block|,
comment|// 0x10f = 271 -
literal|0x0a8
block|,
comment|// 0x110 = 272 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x114
block|,
comment|// 0x111 = 273 -
literal|0x0ff
block|,
comment|// 0x112 = 274 - JUMP
literal|0x02b
block|,
comment|// 0x113 = 275 -
literal|0x0a3
block|,
comment|// 0x114 = 276 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_SFO
literal|0x056
block|,
comment|// 0x115 = 277 -
literal|0x0ff
block|,
comment|// 0x116 = 278 - JUMP
literal|0x101
block|,
comment|// 0x117 = 279 -
literal|0x0ca
block|,
comment|// 0x118 = 280 - JUMP_IF_PHY_READY
literal|0x11e
block|,
comment|// 0x119 = 281 -
literal|0x032
block|,
comment|// 0x11a = 282 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x11b = 283 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x11c = 284 - JUMP
literal|0x001
block|,
comment|// 0x11d = 285 -
literal|0x0a8
block|,
comment|// 0x11e = 286 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x122
block|,
comment|// 0x11f = 287 -
literal|0x0ff
block|,
comment|// 0x120 = 288 - JUMP
literal|0x091
block|,
comment|// 0x121 = 289 -
literal|0x0a4
block|,
comment|// 0x122 = 290 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_DOC
literal|0x0bc
block|,
comment|// 0x123 = 291 -
literal|0x0ff
block|,
comment|// 0x124 = 292 - JUMP
literal|0x103
block|,
comment|// 0x125 = 293 -
literal|0x0a6
block|,
comment|// 0x126 = 294 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x12a
block|,
comment|// 0x127 = 295 -
literal|0x0ff
block|,
comment|// 0x128 = 296 - JUMP
literal|0x143
block|,
comment|// 0x129 = 297 -
literal|0x006
block|,
comment|// 0x12a = 298 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x12b = 299 - JUMP
literal|0x12d
block|,
comment|// 0x12c = 300 -
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x09e
block|,
comment|// 0x132 = 306 - JUMP_IF_CLOSE_STATUS_EQUAL_NORMAL
literal|0x0ff
block|,
comment|// 0x133 = 307 -
literal|0x0c8
block|,
comment|// 0x134 = 308 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x135 = 309 -
literal|0x0ca
block|,
comment|// 0x136 = 310 - JUMP_IF_PHY_READY
literal|0x12d
block|,
comment|// 0x137 = 311 -
literal|0x033
block|,
comment|// 0x138 = 312 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x139 = 313 - JUMP
literal|0x001
block|,
comment|// 0x13a = 314 -
literal|0x009
block|,
comment|// 0x13b = 315 - CLOSE_BREAK
literal|0x0c8
block|,
comment|// 0x13c = 316 - JUMP_IF_BREAK_RECEIVED
literal|0x0ff
block|,
comment|// 0x13d = 317 -
literal|0x0ca
block|,
comment|// 0x13e = 318 - JUMP_IF_PHY_READY
literal|0x13c
block|,
comment|// 0x13f = 319 -
literal|0x033
block|,
comment|// 0x140 = 320 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x141 = 321 - JUMP
literal|0x001
block|,
comment|// 0x142 = 322 -
literal|0x0c8
block|,
comment|// 0x143 = 323 - JUMP_IF_BREAK_RECEIVED
literal|0x14c
block|,
comment|// 0x144 = 324 -
literal|0x0c9
block|,
comment|// 0x145 = 325 - JUMP_IF_DONE_NORMAL_RECEIVED
literal|0x154
block|,
comment|// 0x146 = 326 -
literal|0x0ca
block|,
comment|// 0x147 = 327 - JUMP_IF_PHY_READY
literal|0x0ff
block|,
comment|// 0x148 = 328 -
literal|0x033
block|,
comment|// 0x149 = 329 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x14a = 330 - JUMP
literal|0x0ff
block|,
comment|// 0x14b = 331 -
literal|0x009
block|,
comment|// 0x14c = 332 - CLOSE_BREAK
literal|0x0c8
block|,
comment|// 0x14d = 333 - JUMP_IF_BREAK_RECEIVED
literal|0x0ff
block|,
comment|// 0x14e = 334 -
literal|0x0ca
block|,
comment|// 0x14f = 335 - JUMP_IF_PHY_READY
literal|0x14d
block|,
comment|// 0x150 = 336 -
literal|0x033
block|,
comment|// 0x151 = 337 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x152 = 338 - JUMP
literal|0x001
block|,
comment|// 0x153 = 339 -
literal|0x006
block|,
comment|// 0x154 = 340 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x09e
block|,
comment|// 0x15a = 346 - JUMP_IF_CLOSE_STATUS_EQUAL_NORMAL
literal|0x0ff
block|,
comment|// 0x15b = 347 -
literal|0x0ca
block|,
comment|// 0x15c = 348 - JUMP_IF_PHY_READY
literal|0x15a
block|,
comment|// 0x15d = 349 -
literal|0x033
block|,
comment|// 0x15e = 350 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x15f = 351 - JUMP
literal|0x001
block|,
comment|// 0x160 = 352 -
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as of 6/27 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage0627
index|[]
init|=
block|{
literal|0x011
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ba
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0bb
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x010
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ba
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0bb
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x033
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x011
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0bb
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x010
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0bb
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x010
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0ca
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x010
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x10d
block|,
comment|// 0x02a = 42 -
literal|0x01b
block|,
comment|// 0x02b = 43 - START_IT_NEXUS_LOSS_TIMER_SFO
literal|0x017
block|,
comment|// 0x02c = 44 - PATHWAY_BLOCKED_CNT_SFO_RESET
literal|0x013
block|,
comment|// 0x02d = 45 - START_ARB_WAIT_TIMER_SFO
literal|0x001
block|,
comment|// 0x02e = 46 - OPEN_REQUEST_SFO
literal|0x000
block|,
comment|// 0x02f = 47 - NO_OP
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x000
block|,
comment|// 0x031 = 49 - NO_OP
literal|0x000
block|,
comment|// 0x032 = 50 - NO_OP
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x091
block|,
comment|// 0x034 = 52 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x056
block|,
comment|// 0x035 = 53 -
literal|0x097
block|,
comment|// 0x036 = 54 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x059
block|,
comment|// 0x037 = 55 -
literal|0x09b
block|,
comment|// 0x038 = 56 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x05c
block|,
comment|// 0x039 = 57 -
literal|0x09d
block|,
comment|// 0x03a = 58 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x05f
block|,
comment|// 0x03b = 59 -
literal|0x096
block|,
comment|// 0x03c = 60 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x062
block|,
comment|// 0x03d = 61 -
literal|0x095
block|,
comment|// 0x03e = 62 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x065
block|,
comment|// 0x03f = 63 -
literal|0x0a1
block|,
comment|// 0x040 = 64 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_SFO
literal|0x068
block|,
comment|// 0x041 = 65 -
literal|0x09c
block|,
comment|// 0x042 = 66 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x02b
block|,
comment|// 0x043 = 67 -
literal|0x098
block|,
comment|// 0x044 = 68 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x10d
block|,
comment|// 0x045 = 69 -
literal|0x099
block|,
comment|// 0x046 = 70 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x06b
block|,
comment|// 0x047 = 71 -
literal|0x09a
block|,
comment|// 0x048 = 72 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x02e
block|,
comment|// 0x049 = 73 -
literal|0x094
block|,
comment|// 0x04a = 74 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x02e
block|,
comment|// 0x04b = 75 -
literal|0x0a7
block|,
comment|// 0x04c = 76 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x122
block|,
comment|// 0x04d = 77 -
literal|0x092
block|,
comment|// 0x04e = 78 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x02e
block|,
comment|// 0x04f = 79 -
literal|0x0ca
block|,
comment|// 0x050 = 80 - JUMP_IF_PHY_READY
literal|0x034
block|,
comment|// 0x051 = 81 -
literal|0x031
block|,
comment|// 0x052 = 82 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x053 = 83 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x054 = 84 - JUMP
literal|0x001
block|,
comment|// 0x055 = 85 -
literal|0x021
block|,
comment|// 0x056 = 86 - SET_OPEN_STATUS_NORMAL_SFO
literal|0x0ff
block|,
comment|// 0x057 = 87 - JUMP
literal|0x06e
block|,
comment|// 0x058 = 88 -
literal|0x025
block|,
comment|// 0x059 = 89 - SET_OPEN_STATUS_BAD_RATE_SFO
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x10d
block|,
comment|// 0x05b = 91 -
literal|0x026
block|,
comment|// 0x05c = 92 - SET_OPEN_STATUS_BAD_PROTOCOL_SFO
literal|0x0ff
block|,
comment|// 0x05d = 93 - JUMP
literal|0x10d
block|,
comment|// 0x05e = 94 -
literal|0x028
block|,
comment|// 0x05f = 95 - SET_OPEN_STATUS_WRONG_DEST_SFO
literal|0x0ff
block|,
comment|// 0x060 = 96 - JUMP
literal|0x10d
block|,
comment|// 0x061 = 97 -
literal|0x024
block|,
comment|// 0x062 = 98 - SET_OPEN_STATUS_BREAK_SFO
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x10d
block|,
comment|// 0x064 = 100 -
literal|0x023
block|,
comment|// 0x065 = 101 - SET_OPEN_STATUS_BAD_DEST_SFO
literal|0x0ff
block|,
comment|// 0x066 = 102 - JUMP
literal|0x10d
block|,
comment|// 0x067 = 103 -
literal|0x022
block|,
comment|// 0x068 = 104 - SET_OPEN_STATUS_IT_NEXUS_LOSS_SFO
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x10d
block|,
comment|// 0x06a = 106 -
literal|0x019
block|,
comment|// 0x06b = 107 - PATHWAY_BLOCKED_CNT_SFO_INC
literal|0x0ff
block|,
comment|// 0x06c = 108 - JUMP
literal|0x02e
block|,
comment|// 0x06d = 109 -
literal|0x000
block|,
comment|// 0x06e = 110 - NO_OP
literal|0x0aa
block|,
comment|// 0x06f = 111 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x082
block|,
comment|// 0x070 = 112 -
literal|0x0ab
block|,
comment|// 0x071 = 113 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x086
block|,
comment|// 0x072 = 114 -
literal|0x0ac
block|,
comment|// 0x073 = 115 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x089
block|,
comment|// 0x074 = 116 -
literal|0x0ad
block|,
comment|// 0x075 = 117 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x08f
block|,
comment|// 0x076 = 118 -
literal|0x0af
block|,
comment|// 0x077 = 119 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x08c
block|,
comment|// 0x078 = 120 -
literal|0x0ae
block|,
comment|// 0x079 = 121 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x086
block|,
comment|// 0x07a = 122 -
literal|0x0d2
block|,
comment|// 0x07b = 123 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x095
block|,
comment|// 0x07c = 124 -
literal|0x0ca
block|,
comment|// 0x07d = 125 - JUMP_IF_PHY_READY
literal|0x06f
block|,
comment|// 0x07e = 126 -
literal|0x033
block|,
comment|// 0x07f = 127 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x001
block|,
comment|// 0x081 = 129 -
literal|0x0d0
block|,
comment|// 0x082 = 130 - JUMP_IF_SMP_PROTOCOL
literal|0x086
block|,
comment|// 0x083 = 131 -
literal|0x0ff
block|,
comment|// 0x084 = 132 - JUMP
literal|0x092
block|,
comment|// 0x085 = 133 -
literal|0x006
block|,
comment|// 0x086 = 134 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x087 = 135 - JUMP
literal|0x08f
block|,
comment|// 0x088 = 136 -
literal|0x007
block|,
comment|// 0x089 = 137 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08a = 138 - JUMP
literal|0x08f
block|,
comment|// 0x08b = 139 -
literal|0x008
block|,
comment|// 0x08c = 140 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08d = 141 - JUMP
literal|0x08f
block|,
comment|// 0x08e = 142 -
literal|0x034
block|,
comment|// 0x08f = 143 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x090 = 144 - JUMP
literal|0x141
block|,
comment|// 0x091 = 145 -
literal|0x034
block|,
comment|// 0x092 = 146 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x093 = 147 - JUMP
literal|0x10d
block|,
comment|// 0x094 = 148 -
literal|0x034
block|,
comment|// 0x095 = 149 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x096 = 150 - JUMP
literal|0x14f
block|,
comment|// 0x097 = 151 -
literal|0x01c
block|,
comment|// 0x098 = 152 - START_IT_NEXUS_LOSS_TIMER_DOC
literal|0x018
block|,
comment|// 0x099 = 153 - PATHWAY_BLOCKED_CNT_DOC_RESET
literal|0x014
block|,
comment|// 0x09a = 154 - START_ARB_WAIT_TIMER_DOC
literal|0x002
block|,
comment|// 0x09b = 155 - OPEN_REQUEST_DOC
literal|0x000
block|,
comment|// 0x09c = 156 - NO_OP
literal|0x000
block|,
comment|// 0x09d = 157 - NO_OP
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x000
block|,
comment|// 0x09f = 159 - NO_OP
literal|0x000
block|,
comment|// 0x0a0 = 160 - NO_OP
literal|0x091
block|,
comment|// 0x0a1 = 161 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0c3
block|,
comment|// 0x0a2 = 162 -
literal|0x097
block|,
comment|// 0x0a3 = 163 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0c6
block|,
comment|// 0x0a4 = 164 -
literal|0x09b
block|,
comment|// 0x0a5 = 165 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0c9
block|,
comment|// 0x0a6 = 166 -
literal|0x09d
block|,
comment|// 0x0a7 = 167 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0cc
block|,
comment|// 0x0a8 = 168 -
literal|0x096
block|,
comment|// 0x0a9 = 169 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0cf
block|,
comment|// 0x0aa = 170 -
literal|0x095
block|,
comment|// 0x0ab = 171 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0d2
block|,
comment|// 0x0ac = 172 -
literal|0x0a2
block|,
comment|// 0x0ad = 173 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_DOC
literal|0x0d5
block|,
comment|// 0x0ae = 174 -
literal|0x09c
block|,
comment|// 0x0af = 175 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x098
block|,
comment|// 0x0b0 = 176 -
literal|0x098
block|,
comment|// 0x0b1 = 177 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x10d
block|,
comment|// 0x0b2 = 178 -
literal|0x099
block|,
comment|// 0x0b3 = 179 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0d8
block|,
comment|// 0x0b4 = 180 -
literal|0x09a
block|,
comment|// 0x0b5 = 181 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x09b
block|,
comment|// 0x0b6 = 182 -
literal|0x094
block|,
comment|// 0x0b7 = 183 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x09b
block|,
comment|// 0x0b8 = 184 -
literal|0x0a7
block|,
comment|// 0x0b9 = 185 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x130
block|,
comment|// 0x0ba = 186 -
literal|0x092
block|,
comment|// 0x0bb = 187 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x09b
block|,
comment|// 0x0bc = 188 -
literal|0x0ca
block|,
comment|// 0x0bd = 189 - JUMP_IF_PHY_READY
literal|0x0a1
block|,
comment|// 0x0be = 190 -
literal|0x032
block|,
comment|// 0x0bf = 191 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x0c0 = 192 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0c1 = 193 - JUMP
literal|0x001
block|,
comment|// 0x0c2 = 194 -
literal|0x029
block|,
comment|// 0x0c3 = 195 - SET_OPEN_STATUS_NORMAL_DOC
literal|0x0ff
block|,
comment|// 0x0c4 = 196 - JUMP
literal|0x0db
block|,
comment|// 0x0c5 = 197 -
literal|0x02d
block|,
comment|// 0x0c6 = 198 - SET_OPEN_STATUS_BAD_RATE_DOC
literal|0x0ff
block|,
comment|// 0x0c7 = 199 - JUMP
literal|0x10d
block|,
comment|// 0x0c8 = 200 -
literal|0x02e
block|,
comment|// 0x0c9 = 201 - SET_OPEN_STATUS_BAD_PROTOCOL_DOC
literal|0x0ff
block|,
comment|// 0x0ca = 202 - JUMP
literal|0x10d
block|,
comment|// 0x0cb = 203 -
literal|0x030
block|,
comment|// 0x0cc = 204 - SET_OPEN_STATUS_WRONG_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x10d
block|,
comment|// 0x0ce = 206 -
literal|0x02c
block|,
comment|// 0x0cf = 207 - SET_OPEN_STATUS_BREAK_DOC
literal|0x0ff
block|,
comment|// 0x0d0 = 208 - JUMP
literal|0x10d
block|,
comment|// 0x0d1 = 209 -
literal|0x02b
block|,
comment|// 0x0d2 = 210 - SET_OPEN_STATUS_BAD_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0d3 = 211 - JUMP
literal|0x10d
block|,
comment|// 0x0d4 = 212 -
literal|0x02a
block|,
comment|// 0x0d5 = 213 - SET_OPEN_STATUS_IT_NEXUS_LOSS_DOC
literal|0x0ff
block|,
comment|// 0x0d6 = 214 - JUMP
literal|0x10d
block|,
comment|// 0x0d7 = 215 -
literal|0x01a
block|,
comment|// 0x0d8 = 216 - PATHWAY_BLOCKED_CNT_DOC_INC
literal|0x0ff
block|,
comment|// 0x0d9 = 217 - JUMP
literal|0x09b
block|,
comment|// 0x0da = 218 -
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0b1
block|,
comment|// 0x0dc = 220 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x0ef
block|,
comment|// 0x0dd = 221 -
literal|0x0b2
block|,
comment|// 0x0de = 222 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x0fb
block|,
comment|// 0x0df = 223 -
literal|0x0b3
block|,
comment|// 0x0e0 = 224 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x0fe
block|,
comment|// 0x0e1 = 225 -
literal|0x0b4
block|,
comment|// 0x0e2 = 226 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x104
block|,
comment|// 0x0e3 = 227 -
literal|0x0b6
block|,
comment|// 0x0e4 = 228 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x101
block|,
comment|// 0x0e5 = 229 -
literal|0x0b5
block|,
comment|// 0x0e6 = 230 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x0fb
block|,
comment|// 0x0e7 = 231 -
literal|0x0d3
block|,
comment|// 0x0e8 = 232 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x10a
block|,
comment|// 0x0e9 = 233 -
literal|0x0ca
block|,
comment|// 0x0ea = 234 - JUMP_IF_PHY_READY
literal|0x0f3
block|,
comment|// 0x0eb = 235 -
literal|0x033
block|,
comment|// 0x0ec = 236 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0ed = 237 - JUMP
literal|0x001
block|,
comment|// 0x0ee = 238 -
literal|0x0d0
block|,
comment|// 0x0ef = 239 - JUMP_IF_SMP_PROTOCOL
literal|0x0fb
block|,
comment|// 0x0f0 = 240 -
literal|0x0ff
block|,
comment|// 0x0f1 = 241 - JUMP
literal|0x107
block|,
comment|// 0x0f2 = 242 -
literal|0x0b7
block|,
comment|// 0x0f3 = 243 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x0fb
block|,
comment|// 0x0f4 = 244 -
literal|0x0b8
block|,
comment|// 0x0f5 = 245 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x0fb
block|,
comment|// 0x0f6 = 246 -
literal|0x0b9
block|,
comment|// 0x0f7 = 247 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x0fb
block|,
comment|// 0x0f8 = 248 -
literal|0x0ff
block|,
comment|// 0x0f9 = 249 - JUMP
literal|0x0dc
block|,
comment|// 0x0fa = 250 -
literal|0x006
block|,
comment|// 0x0fb = 251 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x104
block|,
comment|// 0x0fd = 253 -
literal|0x007
block|,
comment|// 0x0fe = 254 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0ff = 255 - JUMP
literal|0x104
block|,
comment|// 0x100 = 256 -
literal|0x008
block|,
comment|// 0x101 = 257 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x102 = 258 - JUMP
literal|0x104
block|,
comment|// 0x103 = 259 -
literal|0x035
block|,
comment|// 0x104 = 260 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x141
block|,
comment|// 0x106 = 262 -
literal|0x035
block|,
comment|// 0x107 = 263 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x108 = 264 - JUMP
literal|0x10d
block|,
comment|// 0x109 = 265 -
literal|0x035
block|,
comment|// 0x10a = 266 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x10b = 267 - JUMP
literal|0x14f
block|,
comment|// 0x10c = 268 -
literal|0x0a9
block|,
comment|// 0x10d = 269 - JUMP_IF_SFO_REQ
literal|0x118
block|,
comment|// 0x10e = 270 -
literal|0x0b0
block|,
comment|// 0x10f = 271 - JUMP_IF_DOC_REQ
literal|0x126
block|,
comment|// 0x110 = 272 -
literal|0x0a8
block|,
comment|// 0x111 = 273 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x134
block|,
comment|// 0x112 = 274 -
literal|0x0ca
block|,
comment|// 0x113 = 275 - JUMP_IF_PHY_READY
literal|0x10d
block|,
comment|// 0x114 = 276 -
literal|0x033
block|,
comment|// 0x115 = 277 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x116 = 278 - JUMP
literal|0x001
block|,
comment|// 0x117 = 279 -
literal|0x0ca
block|,
comment|// 0x118 = 280 - JUMP_IF_PHY_READY
literal|0x11e
block|,
comment|// 0x119 = 281 -
literal|0x031
block|,
comment|// 0x11a = 282 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x11b = 283 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x11c = 284 - JUMP
literal|0x001
block|,
comment|// 0x11d = 285 -
literal|0x0a8
block|,
comment|// 0x11e = 286 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x122
block|,
comment|// 0x11f = 287 -
literal|0x0ff
block|,
comment|// 0x120 = 288 - JUMP
literal|0x02b
block|,
comment|// 0x121 = 289 -
literal|0x0a3
block|,
comment|// 0x122 = 290 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_SFO
literal|0x056
block|,
comment|// 0x123 = 291 -
literal|0x0ff
block|,
comment|// 0x124 = 292 - JUMP
literal|0x10f
block|,
comment|// 0x125 = 293 -
literal|0x0ca
block|,
comment|// 0x126 = 294 - JUMP_IF_PHY_READY
literal|0x12c
block|,
comment|// 0x127 = 295 -
literal|0x032
block|,
comment|// 0x128 = 296 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x129 = 297 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x12a = 298 - JUMP
literal|0x001
block|,
comment|// 0x12b = 299 -
literal|0x0a8
block|,
comment|// 0x12c = 300 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x130
block|,
comment|// 0x12d = 301 -
literal|0x0ff
block|,
comment|// 0x12e = 302 - JUMP
literal|0x098
block|,
comment|// 0x12f = 303 -
literal|0x0a4
block|,
comment|// 0x130 = 304 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_DOC
literal|0x0c3
block|,
comment|// 0x131 = 305 -
literal|0x0ff
block|,
comment|// 0x132 = 306 - JUMP
literal|0x111
block|,
comment|// 0x133 = 307 -
literal|0x0d0
block|,
comment|// 0x134 = 308 - JUMP_IF_SMP_PROTOCOL
literal|0x13d
block|,
comment|// 0x135 = 309 -
literal|0x0a6
block|,
comment|// 0x136 = 310 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x13a
block|,
comment|// 0x137 = 311 -
literal|0x0ff
block|,
comment|// 0x138 = 312 - JUMP
literal|0x157
block|,
comment|// 0x139 = 313 -
literal|0x006
block|,
comment|// 0x13a = 314 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x13b = 315 - JUMP
literal|0x141
block|,
comment|// 0x13c = 316 -
literal|0x0d1
block|,
comment|// 0x13d = 317 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x160
block|,
comment|// 0x13e = 318 -
literal|0x0ff
block|,
comment|// 0x13f = 319 - JUMP
literal|0x10d
block|,
comment|// 0x140 = 320 -
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x09e
block|,
comment|// 0x146 = 326 - JUMP_IF_CLOSE_STATUS_EQUAL_NORMAL
literal|0x10d
block|,
comment|// 0x147 = 327 -
literal|0x0c8
block|,
comment|// 0x148 = 328 - JUMP_IF_BREAK_RECEIVED
literal|0x14f
block|,
comment|// 0x149 = 329 -
literal|0x0ca
block|,
comment|// 0x14a = 330 - JUMP_IF_PHY_READY
literal|0x141
block|,
comment|// 0x14b = 331 -
literal|0x033
block|,
comment|// 0x14c = 332 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x14d = 333 - JUMP
literal|0x001
block|,
comment|// 0x14e = 334 -
literal|0x009
block|,
comment|// 0x14f = 335 - CLOSE_BREAK
literal|0x0c8
block|,
comment|// 0x150 = 336 - JUMP_IF_BREAK_RECEIVED
literal|0x10d
block|,
comment|// 0x151 = 337 -
literal|0x0ca
block|,
comment|// 0x152 = 338 - JUMP_IF_PHY_READY
literal|0x150
block|,
comment|// 0x153 = 339 -
literal|0x033
block|,
comment|// 0x154 = 340 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x155 = 341 - JUMP
literal|0x001
block|,
comment|// 0x156 = 342 -
literal|0x0c8
block|,
comment|// 0x157 = 343 - JUMP_IF_BREAK_RECEIVED
literal|0x160
block|,
comment|// 0x158 = 344 -
literal|0x0c9
block|,
comment|// 0x159 = 345 - JUMP_IF_DONE_NORMAL_RECEIVED
literal|0x168
block|,
comment|// 0x15a = 346 -
literal|0x0ca
block|,
comment|// 0x15b = 347 - JUMP_IF_PHY_READY
literal|0x10d
block|,
comment|// 0x15c = 348 -
literal|0x033
block|,
comment|// 0x15d = 349 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x15e = 350 - JUMP
literal|0x10d
block|,
comment|// 0x15f = 351 -
literal|0x009
block|,
comment|// 0x160 = 352 - CLOSE_BREAK
literal|0x0c8
block|,
comment|// 0x161 = 353 - JUMP_IF_BREAK_RECEIVED
literal|0x10d
block|,
comment|// 0x162 = 354 -
literal|0x0ca
block|,
comment|// 0x163 = 355 - JUMP_IF_PHY_READY
literal|0x161
block|,
comment|// 0x164 = 356 -
literal|0x033
block|,
comment|// 0x165 = 357 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x166 = 358 - JUMP
literal|0x001
block|,
comment|// 0x167 = 359 -
literal|0x006
block|,
comment|// 0x168 = 360 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x09e
block|,
comment|// 0x16e = 366 - JUMP_IF_CLOSE_STATUS_EQUAL_NORMAL
literal|0x10d
block|,
comment|// 0x16f = 367 -
literal|0x0ca
block|,
comment|// 0x170 = 368 - JUMP_IF_PHY_READY
literal|0x16e
block|,
comment|// 0x171 = 369 -
literal|0x033
block|,
comment|// 0x172 = 370 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x173 = 371 - JUMP
literal|0x001
block|,
comment|// 0x174 = 372 -
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as of 8/18/2005 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage0818
index|[]
init|=
block|{
literal|0x011
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ba
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0bb
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x010
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ba
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0bb
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x033
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x011
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0bb
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x010
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0bb
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x010
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0ca
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x010
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x10d
block|,
comment|// 0x02a = 42 -
literal|0x01b
block|,
comment|// 0x02b = 43 - START_IT_NEXUS_LOSS_TIMER_SFO
literal|0x017
block|,
comment|// 0x02c = 44 - PATHWAY_BLOCKED_CNT_SFO_RESET
literal|0x013
block|,
comment|// 0x02d = 45 - START_ARB_WAIT_TIMER_SFO
literal|0x001
block|,
comment|// 0x02e = 46 - OPEN_REQUEST_SFO
literal|0x000
block|,
comment|// 0x02f = 47 - NO_OP
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x000
block|,
comment|// 0x031 = 49 - NO_OP
literal|0x000
block|,
comment|// 0x032 = 50 - NO_OP
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x091
block|,
comment|// 0x034 = 52 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x056
block|,
comment|// 0x035 = 53 -
literal|0x097
block|,
comment|// 0x036 = 54 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x059
block|,
comment|// 0x037 = 55 -
literal|0x09b
block|,
comment|// 0x038 = 56 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x05c
block|,
comment|// 0x039 = 57 -
literal|0x09d
block|,
comment|// 0x03a = 58 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x05f
block|,
comment|// 0x03b = 59 -
literal|0x096
block|,
comment|// 0x03c = 60 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x062
block|,
comment|// 0x03d = 61 -
literal|0x095
block|,
comment|// 0x03e = 62 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x065
block|,
comment|// 0x03f = 63 -
literal|0x0a1
block|,
comment|// 0x040 = 64 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_SFO
literal|0x068
block|,
comment|// 0x041 = 65 -
literal|0x09c
block|,
comment|// 0x042 = 66 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x02b
block|,
comment|// 0x043 = 67 -
literal|0x098
block|,
comment|// 0x044 = 68 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x10d
block|,
comment|// 0x045 = 69 -
literal|0x099
block|,
comment|// 0x046 = 70 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x06b
block|,
comment|// 0x047 = 71 -
literal|0x09a
block|,
comment|// 0x048 = 72 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x02e
block|,
comment|// 0x049 = 73 -
literal|0x094
block|,
comment|// 0x04a = 74 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x02e
block|,
comment|// 0x04b = 75 -
literal|0x0a7
block|,
comment|// 0x04c = 76 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x122
block|,
comment|// 0x04d = 77 -
literal|0x092
block|,
comment|// 0x04e = 78 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x02e
block|,
comment|// 0x04f = 79 -
literal|0x0ca
block|,
comment|// 0x050 = 80 - JUMP_IF_PHY_READY
literal|0x034
block|,
comment|// 0x051 = 81 -
literal|0x031
block|,
comment|// 0x052 = 82 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x053 = 83 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x054 = 84 - JUMP
literal|0x001
block|,
comment|// 0x055 = 85 -
literal|0x021
block|,
comment|// 0x056 = 86 - SET_OPEN_STATUS_NORMAL_SFO
literal|0x0ff
block|,
comment|// 0x057 = 87 - JUMP
literal|0x06e
block|,
comment|// 0x058 = 88 -
literal|0x025
block|,
comment|// 0x059 = 89 - SET_OPEN_STATUS_BAD_RATE_SFO
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x10d
block|,
comment|// 0x05b = 91 -
literal|0x026
block|,
comment|// 0x05c = 92 - SET_OPEN_STATUS_BAD_PROTOCOL_SFO
literal|0x0ff
block|,
comment|// 0x05d = 93 - JUMP
literal|0x10d
block|,
comment|// 0x05e = 94 -
literal|0x028
block|,
comment|// 0x05f = 95 - SET_OPEN_STATUS_WRONG_DEST_SFO
literal|0x0ff
block|,
comment|// 0x060 = 96 - JUMP
literal|0x10d
block|,
comment|// 0x061 = 97 -
literal|0x024
block|,
comment|// 0x062 = 98 - SET_OPEN_STATUS_BREAK_SFO
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x10d
block|,
comment|// 0x064 = 100 -
literal|0x023
block|,
comment|// 0x065 = 101 - SET_OPEN_STATUS_BAD_DEST_SFO
literal|0x0ff
block|,
comment|// 0x066 = 102 - JUMP
literal|0x10d
block|,
comment|// 0x067 = 103 -
literal|0x022
block|,
comment|// 0x068 = 104 - SET_OPEN_STATUS_IT_NEXUS_LOSS_SFO
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x10d
block|,
comment|// 0x06a = 106 -
literal|0x019
block|,
comment|// 0x06b = 107 - PATHWAY_BLOCKED_CNT_SFO_INC
literal|0x0ff
block|,
comment|// 0x06c = 108 - JUMP
literal|0x02e
block|,
comment|// 0x06d = 109 -
literal|0x000
block|,
comment|// 0x06e = 110 - NO_OP
literal|0x0aa
block|,
comment|// 0x06f = 111 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x082
block|,
comment|// 0x070 = 112 -
literal|0x0ab
block|,
comment|// 0x071 = 113 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x086
block|,
comment|// 0x072 = 114 -
literal|0x0ac
block|,
comment|// 0x073 = 115 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x089
block|,
comment|// 0x074 = 116 -
literal|0x0ad
block|,
comment|// 0x075 = 117 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x08f
block|,
comment|// 0x076 = 118 -
literal|0x0af
block|,
comment|// 0x077 = 119 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x08c
block|,
comment|// 0x078 = 120 -
literal|0x0ae
block|,
comment|// 0x079 = 121 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x086
block|,
comment|// 0x07a = 122 -
literal|0x0d2
block|,
comment|// 0x07b = 123 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x095
block|,
comment|// 0x07c = 124 -
literal|0x0ca
block|,
comment|// 0x07d = 125 - JUMP_IF_PHY_READY
literal|0x06f
block|,
comment|// 0x07e = 126 -
literal|0x033
block|,
comment|// 0x07f = 127 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x001
block|,
comment|// 0x081 = 129 -
literal|0x0d0
block|,
comment|// 0x082 = 130 - JUMP_IF_SMP_PROTOCOL
literal|0x086
block|,
comment|// 0x083 = 131 -
literal|0x0ff
block|,
comment|// 0x084 = 132 - JUMP
literal|0x092
block|,
comment|// 0x085 = 133 -
literal|0x006
block|,
comment|// 0x086 = 134 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x087 = 135 - JUMP
literal|0x08f
block|,
comment|// 0x088 = 136 -
literal|0x007
block|,
comment|// 0x089 = 137 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08a = 138 - JUMP
literal|0x08f
block|,
comment|// 0x08b = 139 -
literal|0x008
block|,
comment|// 0x08c = 140 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08d = 141 - JUMP
literal|0x08f
block|,
comment|// 0x08e = 142 -
literal|0x034
block|,
comment|// 0x08f = 143 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x090 = 144 - JUMP
literal|0x14c
block|,
comment|// 0x091 = 145 -
literal|0x034
block|,
comment|// 0x092 = 146 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x093 = 147 - JUMP
literal|0x10d
block|,
comment|// 0x094 = 148 -
literal|0x034
block|,
comment|// 0x095 = 149 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x096 = 150 - JUMP
literal|0x15a
block|,
comment|// 0x097 = 151 -
literal|0x01c
block|,
comment|// 0x098 = 152 - START_IT_NEXUS_LOSS_TIMER_DOC
literal|0x018
block|,
comment|// 0x099 = 153 - PATHWAY_BLOCKED_CNT_DOC_RESET
literal|0x014
block|,
comment|// 0x09a = 154 - START_ARB_WAIT_TIMER_DOC
literal|0x002
block|,
comment|// 0x09b = 155 - OPEN_REQUEST_DOC
literal|0x000
block|,
comment|// 0x09c = 156 - NO_OP
literal|0x000
block|,
comment|// 0x09d = 157 - NO_OP
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x000
block|,
comment|// 0x09f = 159 - NO_OP
literal|0x000
block|,
comment|// 0x0a0 = 160 - NO_OP
literal|0x091
block|,
comment|// 0x0a1 = 161 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0c3
block|,
comment|// 0x0a2 = 162 -
literal|0x097
block|,
comment|// 0x0a3 = 163 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0c6
block|,
comment|// 0x0a4 = 164 -
literal|0x09b
block|,
comment|// 0x0a5 = 165 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0c9
block|,
comment|// 0x0a6 = 166 -
literal|0x09d
block|,
comment|// 0x0a7 = 167 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0cc
block|,
comment|// 0x0a8 = 168 -
literal|0x096
block|,
comment|// 0x0a9 = 169 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0cf
block|,
comment|// 0x0aa = 170 -
literal|0x095
block|,
comment|// 0x0ab = 171 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0d2
block|,
comment|// 0x0ac = 172 -
literal|0x0a2
block|,
comment|// 0x0ad = 173 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_DOC
literal|0x0d5
block|,
comment|// 0x0ae = 174 -
literal|0x09c
block|,
comment|// 0x0af = 175 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x098
block|,
comment|// 0x0b0 = 176 -
literal|0x098
block|,
comment|// 0x0b1 = 177 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x10d
block|,
comment|// 0x0b2 = 178 -
literal|0x099
block|,
comment|// 0x0b3 = 179 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0d8
block|,
comment|// 0x0b4 = 180 -
literal|0x09a
block|,
comment|// 0x0b5 = 181 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x09b
block|,
comment|// 0x0b6 = 182 -
literal|0x094
block|,
comment|// 0x0b7 = 183 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x09b
block|,
comment|// 0x0b8 = 184 -
literal|0x0a7
block|,
comment|// 0x0b9 = 185 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x134
block|,
comment|// 0x0ba = 186 -
literal|0x092
block|,
comment|// 0x0bb = 187 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x09b
block|,
comment|// 0x0bc = 188 -
literal|0x0ca
block|,
comment|// 0x0bd = 189 - JUMP_IF_PHY_READY
literal|0x0a1
block|,
comment|// 0x0be = 190 -
literal|0x032
block|,
comment|// 0x0bf = 191 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x0c0 = 192 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0c1 = 193 - JUMP
literal|0x001
block|,
comment|// 0x0c2 = 194 -
literal|0x029
block|,
comment|// 0x0c3 = 195 - SET_OPEN_STATUS_NORMAL_DOC
literal|0x0ff
block|,
comment|// 0x0c4 = 196 - JUMP
literal|0x0db
block|,
comment|// 0x0c5 = 197 -
literal|0x02d
block|,
comment|// 0x0c6 = 198 - SET_OPEN_STATUS_BAD_RATE_DOC
literal|0x0ff
block|,
comment|// 0x0c7 = 199 - JUMP
literal|0x10d
block|,
comment|// 0x0c8 = 200 -
literal|0x02e
block|,
comment|// 0x0c9 = 201 - SET_OPEN_STATUS_BAD_PROTOCOL_DOC
literal|0x0ff
block|,
comment|// 0x0ca = 202 - JUMP
literal|0x10d
block|,
comment|// 0x0cb = 203 -
literal|0x030
block|,
comment|// 0x0cc = 204 - SET_OPEN_STATUS_WRONG_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x10d
block|,
comment|// 0x0ce = 206 -
literal|0x02c
block|,
comment|// 0x0cf = 207 - SET_OPEN_STATUS_BREAK_DOC
literal|0x0ff
block|,
comment|// 0x0d0 = 208 - JUMP
literal|0x10d
block|,
comment|// 0x0d1 = 209 -
literal|0x02b
block|,
comment|// 0x0d2 = 210 - SET_OPEN_STATUS_BAD_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0d3 = 211 - JUMP
literal|0x10d
block|,
comment|// 0x0d4 = 212 -
literal|0x02a
block|,
comment|// 0x0d5 = 213 - SET_OPEN_STATUS_IT_NEXUS_LOSS_DOC
literal|0x0ff
block|,
comment|// 0x0d6 = 214 - JUMP
literal|0x10d
block|,
comment|// 0x0d7 = 215 -
literal|0x01a
block|,
comment|// 0x0d8 = 216 - PATHWAY_BLOCKED_CNT_DOC_INC
literal|0x0ff
block|,
comment|// 0x0d9 = 217 - JUMP
literal|0x09b
block|,
comment|// 0x0da = 218 -
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0b1
block|,
comment|// 0x0dc = 220 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x0ef
block|,
comment|// 0x0dd = 221 -
literal|0x0b2
block|,
comment|// 0x0de = 222 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x0fb
block|,
comment|// 0x0df = 223 -
literal|0x0b3
block|,
comment|// 0x0e0 = 224 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x0fe
block|,
comment|// 0x0e1 = 225 -
literal|0x0b4
block|,
comment|// 0x0e2 = 226 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x104
block|,
comment|// 0x0e3 = 227 -
literal|0x0b6
block|,
comment|// 0x0e4 = 228 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x101
block|,
comment|// 0x0e5 = 229 -
literal|0x0b5
block|,
comment|// 0x0e6 = 230 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x0fb
block|,
comment|// 0x0e7 = 231 -
literal|0x0d3
block|,
comment|// 0x0e8 = 232 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x10a
block|,
comment|// 0x0e9 = 233 -
literal|0x0ca
block|,
comment|// 0x0ea = 234 - JUMP_IF_PHY_READY
literal|0x0f3
block|,
comment|// 0x0eb = 235 -
literal|0x033
block|,
comment|// 0x0ec = 236 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0ed = 237 - JUMP
literal|0x001
block|,
comment|// 0x0ee = 238 -
literal|0x0d0
block|,
comment|// 0x0ef = 239 - JUMP_IF_SMP_PROTOCOL
literal|0x0fb
block|,
comment|// 0x0f0 = 240 -
literal|0x0ff
block|,
comment|// 0x0f1 = 241 - JUMP
literal|0x107
block|,
comment|// 0x0f2 = 242 -
literal|0x0b7
block|,
comment|// 0x0f3 = 243 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x0fb
block|,
comment|// 0x0f4 = 244 -
literal|0x0b8
block|,
comment|// 0x0f5 = 245 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x0fb
block|,
comment|// 0x0f6 = 246 -
literal|0x0b9
block|,
comment|// 0x0f7 = 247 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x0fb
block|,
comment|// 0x0f8 = 248 -
literal|0x0ff
block|,
comment|// 0x0f9 = 249 - JUMP
literal|0x0dc
block|,
comment|// 0x0fa = 250 -
literal|0x006
block|,
comment|// 0x0fb = 251 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x104
block|,
comment|// 0x0fd = 253 -
literal|0x007
block|,
comment|// 0x0fe = 254 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0ff = 255 - JUMP
literal|0x104
block|,
comment|// 0x100 = 256 -
literal|0x008
block|,
comment|// 0x101 = 257 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x102 = 258 - JUMP
literal|0x104
block|,
comment|// 0x103 = 259 -
literal|0x035
block|,
comment|// 0x104 = 260 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x14c
block|,
comment|// 0x106 = 262 -
literal|0x035
block|,
comment|// 0x107 = 263 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x108 = 264 - JUMP
literal|0x10d
block|,
comment|// 0x109 = 265 -
literal|0x035
block|,
comment|// 0x10a = 266 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x10b = 267 - JUMP
literal|0x15a
block|,
comment|// 0x10c = 268 -
literal|0x0a9
block|,
comment|// 0x10d = 269 - JUMP_IF_SFO_REQ
literal|0x118
block|,
comment|// 0x10e = 270 -
literal|0x0b0
block|,
comment|// 0x10f = 271 - JUMP_IF_DOC_REQ
literal|0x12a
block|,
comment|// 0x110 = 272 -
literal|0x0a8
block|,
comment|// 0x111 = 273 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x13c
block|,
comment|// 0x112 = 274 -
literal|0x0ca
block|,
comment|// 0x113 = 275 - JUMP_IF_PHY_READY
literal|0x10d
block|,
comment|// 0x114 = 276 -
literal|0x033
block|,
comment|// 0x115 = 277 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x116 = 278 - JUMP
literal|0x001
block|,
comment|// 0x117 = 279 -
literal|0x0ca
block|,
comment|// 0x118 = 280 - JUMP_IF_PHY_READY
literal|0x11e
block|,
comment|// 0x119 = 281 -
literal|0x031
block|,
comment|// 0x11a = 282 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x11b = 283 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x11c = 284 - JUMP
literal|0x001
block|,
comment|// 0x11d = 285 -
literal|0x0a8
block|,
comment|// 0x11e = 286 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x122
block|,
comment|// 0x11f = 287 -
literal|0x0ff
block|,
comment|// 0x120 = 288 - JUMP
literal|0x02b
block|,
comment|// 0x121 = 289 -
literal|0x0a3
block|,
comment|// 0x122 = 290 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_SFO
literal|0x126
block|,
comment|// 0x123 = 291 -
literal|0x0ff
block|,
comment|// 0x124 = 292 - JUMP
literal|0x10f
block|,
comment|// 0x125 = 293 -
literal|0x0c8
block|,
comment|// 0x126 = 294 - JUMP_IF_BREAK_RECEIVED
literal|0x15a
block|,
comment|// 0x127 = 295 -
literal|0x0ff
block|,
comment|// 0x128 = 296 - JUMP
literal|0x056
block|,
comment|// 0x129 = 297 -
literal|0x0ca
block|,
comment|// 0x12a = 298 - JUMP_IF_PHY_READY
literal|0x130
block|,
comment|// 0x12b = 299 -
literal|0x032
block|,
comment|// 0x12c = 300 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x12d = 301 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x12e = 302 - JUMP
literal|0x001
block|,
comment|// 0x12f = 303 -
literal|0x0a8
block|,
comment|// 0x130 = 304 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x134
block|,
comment|// 0x131 = 305 -
literal|0x0ff
block|,
comment|// 0x132 = 306 - JUMP
literal|0x098
block|,
comment|// 0x133 = 307 -
literal|0x0a4
block|,
comment|// 0x134 = 308 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_DOC
literal|0x138
block|,
comment|// 0x135 = 309 -
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x111
block|,
comment|// 0x137 = 311 -
literal|0x0c8
block|,
comment|// 0x138 = 312 - JUMP_IF_BREAK_RECEIVED
literal|0x15a
block|,
comment|// 0x139 = 313 -
literal|0x0ff
block|,
comment|// 0x13a = 314 - JUMP
literal|0x0c3
block|,
comment|// 0x13b = 315 -
literal|0x0d0
block|,
comment|// 0x13c = 316 - JUMP_IF_SMP_PROTOCOL
literal|0x145
block|,
comment|// 0x13d = 317 -
literal|0x0a6
block|,
comment|// 0x13e = 318 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x142
block|,
comment|// 0x13f = 319 -
literal|0x0ff
block|,
comment|// 0x140 = 320 - JUMP
literal|0x15f
block|,
comment|// 0x141 = 321 -
literal|0x006
block|,
comment|// 0x142 = 322 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x143 = 323 - JUMP
literal|0x14c
block|,
comment|// 0x144 = 324 -
literal|0x0d1
block|,
comment|// 0x145 = 325 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x168
block|,
comment|// 0x146 = 326 -
literal|0x0ff
block|,
comment|// 0x147 = 327 - JUMP
literal|0x10d
block|,
comment|// 0x148 = 328 -
literal|0x0c8
block|,
comment|// 0x149 = 329 - JUMP_IF_BREAK_RECEIVED
literal|0x15a
block|,
comment|// 0x14a = 330 -
literal|0x006
block|,
comment|// 0x14b = 331 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x0cd
block|,
comment|// 0x151 = 337 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x10d
block|,
comment|// 0x152 = 338 -
literal|0x0c8
block|,
comment|// 0x153 = 339 - JUMP_IF_BREAK_RECEIVED
literal|0x15a
block|,
comment|// 0x154 = 340 -
literal|0x0ca
block|,
comment|// 0x155 = 341 - JUMP_IF_PHY_READY
literal|0x14c
block|,
comment|// 0x156 = 342 -
literal|0x033
block|,
comment|// 0x157 = 343 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x158 = 344 - JUMP
literal|0x001
block|,
comment|// 0x159 = 345 -
literal|0x009
block|,
comment|// 0x15a = 346 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x15b = 347 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x15b
block|,
comment|// 0x15c = 348 -
literal|0x0ff
block|,
comment|// 0x15d = 349 - JUMP
literal|0x10d
block|,
comment|// 0x15e = 350 -
literal|0x0c8
block|,
comment|// 0x15f = 351 - JUMP_IF_BREAK_RECEIVED
literal|0x168
block|,
comment|// 0x160 = 352 -
literal|0x0ce
block|,
comment|// 0x161 = 353 - JUMP_IF_ANY_DONE_RECEIVED
literal|0x16d
block|,
comment|// 0x162 = 354 -
literal|0x0ca
block|,
comment|// 0x163 = 355 - JUMP_IF_PHY_READY
literal|0x10d
block|,
comment|// 0x164 = 356 -
literal|0x033
block|,
comment|// 0x165 = 357 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x166 = 358 - JUMP
literal|0x10d
block|,
comment|// 0x167 = 359 -
literal|0x009
block|,
comment|// 0x168 = 360 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x169 = 361 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x169
block|,
comment|// 0x16a = 362 -
literal|0x0ff
block|,
comment|// 0x16b = 363 - JUMP
literal|0x10d
block|,
comment|// 0x16c = 364 -
literal|0x006
block|,
comment|// 0x16d = 365 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x0cd
block|,
comment|// 0x173 = 371 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x10d
block|,
comment|// 0x174 = 372 -
literal|0x0c8
block|,
comment|// 0x175 = 373 - JUMP_IF_BREAK_RECEIVED
literal|0x168
block|,
comment|// 0x176 = 374 -
literal|0x0ca
block|,
comment|// 0x177 = 375 - JUMP_IF_PHY_READY
literal|0x173
block|,
comment|// 0x178 = 376 -
literal|0x033
block|,
comment|// 0x179 = 377 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x17a = 378 - JUMP
literal|0x001
block|,
comment|// 0x17b = 379 -
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 8/24/05 not worked */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage0824
index|[]
init|=
block|{
literal|0x011
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ba
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0bb
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x010
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ba
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0bb
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x033
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x011
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0bb
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x010
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0bb
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x010
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0ca
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x010
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x11b
block|,
comment|// 0x02a = 42 -
literal|0x01b
block|,
comment|// 0x02b = 43 - START_IT_NEXUS_LOSS_TIMER_SFO
literal|0x017
block|,
comment|// 0x02c = 44 - PATHWAY_BLOCKED_CNT_SFO_RESET
literal|0x015
block|,
comment|// 0x02d = 45 - NO_OP
literal|0x07f
block|,
comment|// 0x02e = 46 - NO_OP
literal|0x001
block|,
comment|// 0x02f = 47 - OPEN_REQUEST_SFO
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x000
block|,
comment|// 0x031 = 49 - NO_OP
literal|0x000
block|,
comment|// 0x032 = 50 - NO_OP
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x000
block|,
comment|// 0x034 = 52 - NO_OP
literal|0x091
block|,
comment|// 0x035 = 53 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x057
block|,
comment|// 0x036 = 54 -
literal|0x097
block|,
comment|// 0x037 = 55 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x05a
block|,
comment|// 0x038 = 56 -
literal|0x09b
block|,
comment|// 0x039 = 57 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x05d
block|,
comment|// 0x03a = 58 -
literal|0x09d
block|,
comment|// 0x03b = 59 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x060
block|,
comment|// 0x03c = 60 -
literal|0x096
block|,
comment|// 0x03d = 61 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x063
block|,
comment|// 0x03e = 62 -
literal|0x095
block|,
comment|// 0x03f = 63 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x066
block|,
comment|// 0x040 = 64 -
literal|0x0a1
block|,
comment|// 0x041 = 65 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_SFO
literal|0x069
block|,
comment|// 0x042 = 66 -
literal|0x09c
block|,
comment|// 0x043 = 67 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x02b
block|,
comment|// 0x044 = 68 -
literal|0x098
block|,
comment|// 0x045 = 69 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x11b
block|,
comment|// 0x046 = 70 -
literal|0x099
block|,
comment|// 0x047 = 71 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x06c
block|,
comment|// 0x048 = 72 -
literal|0x09a
block|,
comment|// 0x049 = 73 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x02f
block|,
comment|// 0x04a = 74 -
literal|0x094
block|,
comment|// 0x04b = 75 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x02f
block|,
comment|// 0x04c = 76 -
literal|0x0a7
block|,
comment|// 0x04d = 77 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x130
block|,
comment|// 0x04e = 78 -
literal|0x092
block|,
comment|// 0x04f = 79 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x02f
block|,
comment|// 0x050 = 80 -
literal|0x0ca
block|,
comment|// 0x051 = 81 - JUMP_IF_PHY_READY
literal|0x035
block|,
comment|// 0x052 = 82 -
literal|0x031
block|,
comment|// 0x053 = 83 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x054 = 84 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x055 = 85 - JUMP
literal|0x001
block|,
comment|// 0x056 = 86 -
literal|0x021
block|,
comment|// 0x057 = 87 - SET_OPEN_STATUS_NORMAL_SFO
literal|0x0ff
block|,
comment|// 0x058 = 88 - JUMP
literal|0x06f
block|,
comment|// 0x059 = 89 -
literal|0x025
block|,
comment|// 0x05a = 90 - SET_OPEN_STATUS_BAD_RATE_SFO
literal|0x0ff
block|,
comment|// 0x05b = 91 - JUMP
literal|0x11b
block|,
comment|// 0x05c = 92 -
literal|0x026
block|,
comment|// 0x05d = 93 - SET_OPEN_STATUS_BAD_PROTOCOL_SFO
literal|0x0ff
block|,
comment|// 0x05e = 94 - JUMP
literal|0x11b
block|,
comment|// 0x05f = 95 -
literal|0x028
block|,
comment|// 0x060 = 96 - SET_OPEN_STATUS_WRONG_DEST_SFO
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x11b
block|,
comment|// 0x062 = 98 -
literal|0x024
block|,
comment|// 0x063 = 99 - SET_OPEN_STATUS_BREAK_SFO
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x11b
block|,
comment|// 0x065 = 101 -
literal|0x023
block|,
comment|// 0x066 = 102 - SET_OPEN_STATUS_BAD_DEST_SFO
literal|0x0ff
block|,
comment|// 0x067 = 103 - JUMP
literal|0x11b
block|,
comment|// 0x068 = 104 -
literal|0x022
block|,
comment|// 0x069 = 105 - SET_OPEN_STATUS_IT_NEXUS_LOSS_SFO
literal|0x0ff
block|,
comment|// 0x06a = 106 - JUMP
literal|0x11b
block|,
comment|// 0x06b = 107 -
literal|0x019
block|,
comment|// 0x06c = 108 - PATHWAY_BLOCKED_CNT_SFO_INC
literal|0x0ff
block|,
comment|// 0x06d = 109 - JUMP
literal|0x02f
block|,
comment|// 0x06e = 110 -
literal|0x000
block|,
comment|// 0x06f = 111 - NO_OP
literal|0x0d4
block|,
comment|// 0x070 = 112 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x09b
block|,
comment|// 0x071 = 113 -
literal|0x0aa
block|,
comment|// 0x072 = 114 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x085
block|,
comment|// 0x073 = 115 -
literal|0x0ab
block|,
comment|// 0x074 = 116 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x089
block|,
comment|// 0x075 = 117 -
literal|0x0ac
block|,
comment|// 0x076 = 118 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x08c
block|,
comment|// 0x077 = 119 -
literal|0x0ad
block|,
comment|// 0x078 = 120 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x092
block|,
comment|// 0x079 = 121 -
literal|0x0af
block|,
comment|// 0x07a = 122 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x08f
block|,
comment|// 0x07b = 123 -
literal|0x0ae
block|,
comment|// 0x07c = 124 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x089
block|,
comment|// 0x07d = 125 -
literal|0x0d2
block|,
comment|// 0x07e = 126 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x098
block|,
comment|// 0x07f = 127 -
literal|0x0ca
block|,
comment|// 0x080 = 128 - JUMP_IF_PHY_READY
literal|0x070
block|,
comment|// 0x081 = 129 -
literal|0x033
block|,
comment|// 0x082 = 130 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x083 = 131 - JUMP
literal|0x001
block|,
comment|// 0x084 = 132 -
literal|0x0d0
block|,
comment|// 0x085 = 133 - JUMP_IF_SMP_PROTOCOL
literal|0x089
block|,
comment|// 0x086 = 134 -
literal|0x0ff
block|,
comment|// 0x087 = 135 - JUMP
literal|0x095
block|,
comment|// 0x088 = 136 -
literal|0x006
block|,
comment|// 0x089 = 137 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x08a = 138 - JUMP
literal|0x092
block|,
comment|// 0x08b = 139 -
literal|0x007
block|,
comment|// 0x08c = 140 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08d = 141 - JUMP
literal|0x092
block|,
comment|// 0x08e = 142 -
literal|0x008
block|,
comment|// 0x08f = 143 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x090 = 144 - JUMP
literal|0x092
block|,
comment|// 0x091 = 145 -
literal|0x034
block|,
comment|// 0x092 = 146 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x093 = 147 - JUMP
literal|0x15f
block|,
comment|// 0x094 = 148 -
literal|0x034
block|,
comment|// 0x095 = 149 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x096 = 150 - JUMP
literal|0x11b
block|,
comment|// 0x097 = 151 -
literal|0x034
block|,
comment|// 0x098 = 152 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x099 = 153 - JUMP
literal|0x16f
block|,
comment|// 0x09a = 154 -
literal|0x037
block|,
comment|// 0x09b = 155 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x09c = 156 - JUMP
literal|0x072
block|,
comment|// 0x09d = 157 -
literal|0x01c
block|,
comment|// 0x09e = 158 - START_IT_NEXUS_LOSS_TIMER_DOC
literal|0x018
block|,
comment|// 0x09f = 159 - PATHWAY_BLOCKED_CNT_DOC_RESET
literal|0x016
block|,
comment|// 0x0a0 = 160 - NO_OP
literal|0x07f
block|,
comment|// 0x0a1 = 161 - NO_OP
literal|0x002
block|,
comment|// 0x0a2 = 162 - OPEN_REQUEST_DOC
literal|0x000
block|,
comment|// 0x0a3 = 163 - NO_OP
literal|0x000
block|,
comment|// 0x0a4 = 164 - NO_OP
literal|0x000
block|,
comment|// 0x0a5 = 165 - NO_OP
literal|0x000
block|,
comment|// 0x0a6 = 166 - NO_OP
literal|0x000
block|,
comment|// 0x0a7 = 167 - NO_OP
literal|0x091
block|,
comment|// 0x0a8 = 168 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0ca
block|,
comment|// 0x0a9 = 169 -
literal|0x097
block|,
comment|// 0x0aa = 170 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0cd
block|,
comment|// 0x0ab = 171 -
literal|0x09b
block|,
comment|// 0x0ac = 172 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0d0
block|,
comment|// 0x0ad = 173 -
literal|0x09d
block|,
comment|// 0x0ae = 174 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0d3
block|,
comment|// 0x0af = 175 -
literal|0x096
block|,
comment|// 0x0b0 = 176 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0d6
block|,
comment|// 0x0b1 = 177 -
literal|0x095
block|,
comment|// 0x0b2 = 178 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0d9
block|,
comment|// 0x0b3 = 179 -
literal|0x0a2
block|,
comment|// 0x0b4 = 180 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_DOC
literal|0x0dc
block|,
comment|// 0x0b5 = 181 -
literal|0x09c
block|,
comment|// 0x0b6 = 182 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x09e
block|,
comment|// 0x0b7 = 183 -
literal|0x098
block|,
comment|// 0x0b8 = 184 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x11b
block|,
comment|// 0x0b9 = 185 -
literal|0x099
block|,
comment|// 0x0ba = 186 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0df
block|,
comment|// 0x0bb = 187 -
literal|0x09a
block|,
comment|// 0x0bc = 188 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0a2
block|,
comment|// 0x0bd = 189 -
literal|0x094
block|,
comment|// 0x0be = 190 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0a2
block|,
comment|// 0x0bf = 191 -
literal|0x0a7
block|,
comment|// 0x0c0 = 192 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x142
block|,
comment|// 0x0c1 = 193 -
literal|0x092
block|,
comment|// 0x0c2 = 194 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x0a2
block|,
comment|// 0x0c3 = 195 -
literal|0x0ca
block|,
comment|// 0x0c4 = 196 - JUMP_IF_PHY_READY
literal|0x0a8
block|,
comment|// 0x0c5 = 197 -
literal|0x032
block|,
comment|// 0x0c6 = 198 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x0c7 = 199 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0c8 = 200 - JUMP
literal|0x001
block|,
comment|// 0x0c9 = 201 -
literal|0x029
block|,
comment|// 0x0ca = 202 - SET_OPEN_STATUS_NORMAL_DOC
literal|0x0ff
block|,
comment|// 0x0cb = 203 - JUMP
literal|0x0e2
block|,
comment|// 0x0cc = 204 -
literal|0x02d
block|,
comment|// 0x0cd = 205 - SET_OPEN_STATUS_BAD_RATE_DOC
literal|0x0ff
block|,
comment|// 0x0ce = 206 - JUMP
literal|0x11b
block|,
comment|// 0x0cf = 207 -
literal|0x02e
block|,
comment|// 0x0d0 = 208 - SET_OPEN_STATUS_BAD_PROTOCOL_DOC
literal|0x0ff
block|,
comment|// 0x0d1 = 209 - JUMP
literal|0x11b
block|,
comment|// 0x0d2 = 210 -
literal|0x030
block|,
comment|// 0x0d3 = 211 - SET_OPEN_STATUS_WRONG_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0d4 = 212 - JUMP
literal|0x11b
block|,
comment|// 0x0d5 = 213 -
literal|0x02c
block|,
comment|// 0x0d6 = 214 - SET_OPEN_STATUS_BREAK_DOC
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x11b
block|,
comment|// 0x0d8 = 216 -
literal|0x02b
block|,
comment|// 0x0d9 = 217 - SET_OPEN_STATUS_BAD_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0da = 218 - JUMP
literal|0x11b
block|,
comment|// 0x0db = 219 -
literal|0x02a
block|,
comment|// 0x0dc = 220 - SET_OPEN_STATUS_IT_NEXUS_LOSS_DOC
literal|0x0ff
block|,
comment|// 0x0dd = 221 - JUMP
literal|0x11b
block|,
comment|// 0x0de = 222 -
literal|0x01a
block|,
comment|// 0x0df = 223 - PATHWAY_BLOCKED_CNT_DOC_INC
literal|0x0ff
block|,
comment|// 0x0e0 = 224 - JUMP
literal|0x0a2
block|,
comment|// 0x0e1 = 225 -
literal|0x000
block|,
comment|// 0x0e2 = 226 - NO_OP
literal|0x0d4
block|,
comment|// 0x0e3 = 227 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x118
block|,
comment|// 0x0e4 = 228 -
literal|0x0b1
block|,
comment|// 0x0e5 = 229 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x0fa
block|,
comment|// 0x0e6 = 230 -
literal|0x0b2
block|,
comment|// 0x0e7 = 231 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x106
block|,
comment|// 0x0e8 = 232 -
literal|0x0b3
block|,
comment|// 0x0e9 = 233 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x109
block|,
comment|// 0x0ea = 234 -
literal|0x0b4
block|,
comment|// 0x0eb = 235 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x10f
block|,
comment|// 0x0ec = 236 -
literal|0x0b6
block|,
comment|// 0x0ed = 237 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x10c
block|,
comment|// 0x0ee = 238 -
literal|0x0b5
block|,
comment|// 0x0ef = 239 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x106
block|,
comment|// 0x0f0 = 240 -
literal|0x0d3
block|,
comment|// 0x0f1 = 241 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x115
block|,
comment|// 0x0f2 = 242 -
literal|0x0d5
block|,
comment|// 0x0f3 = 243 - JUMP_IF_DOC_CLOSE_REQ
literal|0x15c
block|,
comment|// 0x0f4 = 244 -
literal|0x0ca
block|,
comment|// 0x0f5 = 245 - JUMP_IF_PHY_READY
literal|0x0fe
block|,
comment|// 0x0f6 = 246 -
literal|0x033
block|,
comment|// 0x0f7 = 247 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0f8 = 248 - JUMP
literal|0x001
block|,
comment|// 0x0f9 = 249 -
literal|0x0d0
block|,
comment|// 0x0fa = 250 - JUMP_IF_SMP_PROTOCOL
literal|0x106
block|,
comment|// 0x0fb = 251 -
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x112
block|,
comment|// 0x0fd = 253 -
literal|0x0b7
block|,
comment|// 0x0fe = 254 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x106
block|,
comment|// 0x0ff = 255 -
literal|0x0b8
block|,
comment|// 0x100 = 256 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x106
block|,
comment|// 0x101 = 257 -
literal|0x0b9
block|,
comment|// 0x102 = 258 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x106
block|,
comment|// 0x103 = 259 -
literal|0x0ff
block|,
comment|// 0x104 = 260 - JUMP
literal|0x0e3
block|,
comment|// 0x105 = 261 -
literal|0x006
block|,
comment|// 0x106 = 262 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x107 = 263 - JUMP
literal|0x10f
block|,
comment|// 0x108 = 264 -
literal|0x007
block|,
comment|// 0x109 = 265 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x10f
block|,
comment|// 0x10b = 267 -
literal|0x008
block|,
comment|// 0x10c = 268 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x10f
block|,
comment|// 0x10e = 270 -
literal|0x035
block|,
comment|// 0x10f = 271 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x110 = 272 - JUMP
literal|0x15f
block|,
comment|// 0x111 = 273 -
literal|0x035
block|,
comment|// 0x112 = 274 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x113 = 275 - JUMP
literal|0x11b
block|,
comment|// 0x114 = 276 -
literal|0x035
block|,
comment|// 0x115 = 277 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x116 = 278 - JUMP
literal|0x16f
block|,
comment|// 0x117 = 279 -
literal|0x037
block|,
comment|// 0x118 = 280 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x0e5
block|,
comment|// 0x11a = 282 -
literal|0x0a9
block|,
comment|// 0x11b = 283 - JUMP_IF_SFO_REQ
literal|0x126
block|,
comment|// 0x11c = 284 -
literal|0x0b0
block|,
comment|// 0x11d = 285 - JUMP_IF_DOC_REQ
literal|0x138
block|,
comment|// 0x11e = 286 -
literal|0x0a8
block|,
comment|// 0x11f = 287 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x14a
block|,
comment|// 0x120 = 288 -
literal|0x0ca
block|,
comment|// 0x121 = 289 - JUMP_IF_PHY_READY
literal|0x11b
block|,
comment|// 0x122 = 290 -
literal|0x033
block|,
comment|// 0x123 = 291 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x124 = 292 - JUMP
literal|0x001
block|,
comment|// 0x125 = 293 -
literal|0x0ca
block|,
comment|// 0x126 = 294 - JUMP_IF_PHY_READY
literal|0x12c
block|,
comment|// 0x127 = 295 -
literal|0x031
block|,
comment|// 0x128 = 296 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x129 = 297 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x12a = 298 - JUMP
literal|0x001
block|,
comment|// 0x12b = 299 -
literal|0x0a8
block|,
comment|// 0x12c = 300 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x130
block|,
comment|// 0x12d = 301 -
literal|0x0ff
block|,
comment|// 0x12e = 302 - JUMP
literal|0x02b
block|,
comment|// 0x12f = 303 -
literal|0x0a3
block|,
comment|// 0x130 = 304 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_SFO
literal|0x134
block|,
comment|// 0x131 = 305 -
literal|0x0ff
block|,
comment|// 0x132 = 306 - JUMP
literal|0x11d
block|,
comment|// 0x133 = 307 -
literal|0x0c8
block|,
comment|// 0x134 = 308 - JUMP_IF_BREAK_RECEIVED
literal|0x16f
block|,
comment|// 0x135 = 309 -
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x057
block|,
comment|// 0x137 = 311 -
literal|0x0ca
block|,
comment|// 0x138 = 312 - JUMP_IF_PHY_READY
literal|0x13e
block|,
comment|// 0x139 = 313 -
literal|0x032
block|,
comment|// 0x13a = 314 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x13b = 315 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x13c = 316 - JUMP
literal|0x001
block|,
comment|// 0x13d = 317 -
literal|0x0a8
block|,
comment|// 0x13e = 318 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x142
block|,
comment|// 0x13f = 319 -
literal|0x0ff
block|,
comment|// 0x140 = 320 - JUMP
literal|0x09e
block|,
comment|// 0x141 = 321 -
literal|0x0a4
block|,
comment|// 0x142 = 322 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_DOC
literal|0x146
block|,
comment|// 0x143 = 323 -
literal|0x0ff
block|,
comment|// 0x144 = 324 - JUMP
literal|0x11f
block|,
comment|// 0x145 = 325 -
literal|0x0c8
block|,
comment|// 0x146 = 326 - JUMP_IF_BREAK_RECEIVED
literal|0x16f
block|,
comment|// 0x147 = 327 -
literal|0x0ff
block|,
comment|// 0x148 = 328 - JUMP
literal|0x0ca
block|,
comment|// 0x149 = 329 -
literal|0x0d0
block|,
comment|// 0x14a = 330 - JUMP_IF_SMP_PROTOCOL
literal|0x155
block|,
comment|// 0x14b = 331 -
literal|0x0d4
block|,
comment|// 0x14c = 332 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x159
block|,
comment|// 0x14d = 333 -
literal|0x0a6
block|,
comment|// 0x14e = 334 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x152
block|,
comment|// 0x14f = 335 -
literal|0x0ff
block|,
comment|// 0x150 = 336 - JUMP
literal|0x177
block|,
comment|// 0x151 = 337 -
literal|0x006
block|,
comment|// 0x152 = 338 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x153 = 339 - JUMP
literal|0x15f
block|,
comment|// 0x154 = 340 -
literal|0x0d1
block|,
comment|// 0x155 = 341 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x180
block|,
comment|// 0x156 = 342 -
literal|0x0ff
block|,
comment|// 0x157 = 343 - JUMP
literal|0x11b
block|,
comment|// 0x158 = 344 -
literal|0x037
block|,
comment|// 0x159 = 345 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x15a = 346 - JUMP
literal|0x14e
block|,
comment|// 0x15b = 347 -
literal|0x0c8
block|,
comment|// 0x15c = 348 - JUMP_IF_BREAK_RECEIVED
literal|0x16f
block|,
comment|// 0x15d = 349 -
literal|0x006
block|,
comment|// 0x15e = 350 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x0d4
block|,
comment|// 0x164 = 356 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x174
block|,
comment|// 0x165 = 357 -
literal|0x0cd
block|,
comment|// 0x166 = 358 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x11b
block|,
comment|// 0x167 = 359 -
literal|0x0c8
block|,
comment|// 0x168 = 360 - JUMP_IF_BREAK_RECEIVED
literal|0x16f
block|,
comment|// 0x169 = 361 -
literal|0x0ca
block|,
comment|// 0x16a = 362 - JUMP_IF_PHY_READY
literal|0x15f
block|,
comment|// 0x16b = 363 -
literal|0x033
block|,
comment|// 0x16c = 364 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x16d = 365 - JUMP
literal|0x001
block|,
comment|// 0x16e = 366 -
literal|0x009
block|,
comment|// 0x16f = 367 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x170 = 368 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x170
block|,
comment|// 0x171 = 369 -
literal|0x0ff
block|,
comment|// 0x172 = 370 - JUMP
literal|0x11b
block|,
comment|// 0x173 = 371 -
literal|0x037
block|,
comment|// 0x174 = 372 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x175 = 373 - JUMP
literal|0x166
block|,
comment|// 0x176 = 374 -
literal|0x0c8
block|,
comment|// 0x177 = 375 - JUMP_IF_BREAK_RECEIVED
literal|0x180
block|,
comment|// 0x178 = 376 -
literal|0x0ce
block|,
comment|// 0x179 = 377 - JUMP_IF_ANY_DONE_RECEIVED
literal|0x185
block|,
comment|// 0x17a = 378 -
literal|0x0ca
block|,
comment|// 0x17b = 379 - JUMP_IF_PHY_READY
literal|0x11b
block|,
comment|// 0x17c = 380 -
literal|0x033
block|,
comment|// 0x17d = 381 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x17e = 382 - JUMP
literal|0x11b
block|,
comment|// 0x17f = 383 -
literal|0x009
block|,
comment|// 0x180 = 384 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x181 = 385 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x181
block|,
comment|// 0x182 = 386 -
literal|0x0ff
block|,
comment|// 0x183 = 387 - JUMP
literal|0x11b
block|,
comment|// 0x184 = 388 -
literal|0x006
block|,
comment|// 0x185 = 389 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x0cd
block|,
comment|// 0x18b = 395 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x11b
block|,
comment|// 0x18c = 396 -
literal|0x0d4
block|,
comment|// 0x18d = 397 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x196
block|,
comment|// 0x18e = 398 -
literal|0x0c8
block|,
comment|// 0x18f = 399 - JUMP_IF_BREAK_RECEIVED
literal|0x180
block|,
comment|// 0x190 = 400 -
literal|0x0ca
block|,
comment|// 0x191 = 401 - JUMP_IF_PHY_READY
literal|0x18b
block|,
comment|// 0x192 = 402 -
literal|0x033
block|,
comment|// 0x193 = 403 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x194 = 404 - JUMP
literal|0x001
block|,
comment|// 0x195 = 405 -
literal|0x037
block|,
comment|// 0x196 = 406 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x197 = 407 - JUMP
literal|0x18f
block|,
comment|// 0x198 = 408 -
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as of 8/23/05 and worked, used for Houston demo, bitmap0822 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage0822
index|[]
init|=
block|{
literal|0x011
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ba
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0bb
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x010
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ba
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0bb
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x033
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x011
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0ca
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0bb
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x010
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0bb
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x010
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0ca
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x010
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x112
block|,
comment|// 0x02a = 42 -
literal|0x01b
block|,
comment|// 0x02b = 43 - START_IT_NEXUS_LOSS_TIMER_SFO
literal|0x017
block|,
comment|// 0x02c = 44 - PATHWAY_BLOCKED_CNT_SFO_RESET
literal|0x013
block|,
comment|// 0x02d = 45 - START_ARB_WAIT_TIMER_SFO
literal|0x001
block|,
comment|// 0x02e = 46 - OPEN_REQUEST_SFO
literal|0x000
block|,
comment|// 0x02f = 47 - NO_OP
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x000
block|,
comment|// 0x031 = 49 - NO_OP
literal|0x000
block|,
comment|// 0x032 = 50 - NO_OP
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x091
block|,
comment|// 0x034 = 52 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x056
block|,
comment|// 0x035 = 53 -
literal|0x097
block|,
comment|// 0x036 = 54 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x059
block|,
comment|// 0x037 = 55 -
literal|0x09b
block|,
comment|// 0x038 = 56 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x05c
block|,
comment|// 0x039 = 57 -
literal|0x09d
block|,
comment|// 0x03a = 58 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x05f
block|,
comment|// 0x03b = 59 -
literal|0x096
block|,
comment|// 0x03c = 60 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x062
block|,
comment|// 0x03d = 61 -
literal|0x095
block|,
comment|// 0x03e = 62 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x065
block|,
comment|// 0x03f = 63 -
literal|0x0a1
block|,
comment|// 0x040 = 64 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_SFO
literal|0x068
block|,
comment|// 0x041 = 65 -
literal|0x09c
block|,
comment|// 0x042 = 66 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x02b
block|,
comment|// 0x043 = 67 -
literal|0x098
block|,
comment|// 0x044 = 68 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x112
block|,
comment|// 0x045 = 69 -
literal|0x099
block|,
comment|// 0x046 = 70 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x06b
block|,
comment|// 0x047 = 71 -
literal|0x09a
block|,
comment|// 0x048 = 72 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x02e
block|,
comment|// 0x049 = 73 -
literal|0x094
block|,
comment|// 0x04a = 74 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x02e
block|,
comment|// 0x04b = 75 -
literal|0x0a7
block|,
comment|// 0x04c = 76 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x127
block|,
comment|// 0x04d = 77 -
literal|0x092
block|,
comment|// 0x04e = 78 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x02e
block|,
comment|// 0x04f = 79 -
literal|0x0ca
block|,
comment|// 0x050 = 80 - JUMP_IF_PHY_READY
literal|0x034
block|,
comment|// 0x051 = 81 -
literal|0x031
block|,
comment|// 0x052 = 82 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x053 = 83 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x054 = 84 - JUMP
literal|0x001
block|,
comment|// 0x055 = 85 -
literal|0x021
block|,
comment|// 0x056 = 86 - SET_OPEN_STATUS_NORMAL_SFO
literal|0x0ff
block|,
comment|// 0x057 = 87 - JUMP
literal|0x06e
block|,
comment|// 0x058 = 88 -
literal|0x025
block|,
comment|// 0x059 = 89 - SET_OPEN_STATUS_BAD_RATE_SFO
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x112
block|,
comment|// 0x05b = 91 -
literal|0x026
block|,
comment|// 0x05c = 92 - SET_OPEN_STATUS_BAD_PROTOCOL_SFO
literal|0x0ff
block|,
comment|// 0x05d = 93 - JUMP
literal|0x112
block|,
comment|// 0x05e = 94 -
literal|0x028
block|,
comment|// 0x05f = 95 - SET_OPEN_STATUS_WRONG_DEST_SFO
literal|0x0ff
block|,
comment|// 0x060 = 96 - JUMP
literal|0x112
block|,
comment|// 0x061 = 97 -
literal|0x024
block|,
comment|// 0x062 = 98 - SET_OPEN_STATUS_BREAK_SFO
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x112
block|,
comment|// 0x064 = 100 -
literal|0x023
block|,
comment|// 0x065 = 101 - SET_OPEN_STATUS_BAD_DEST_SFO
literal|0x0ff
block|,
comment|// 0x066 = 102 - JUMP
literal|0x112
block|,
comment|// 0x067 = 103 -
literal|0x022
block|,
comment|// 0x068 = 104 - SET_OPEN_STATUS_IT_NEXUS_LOSS_SFO
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x112
block|,
comment|// 0x06a = 106 -
literal|0x019
block|,
comment|// 0x06b = 107 - PATHWAY_BLOCKED_CNT_SFO_INC
literal|0x0ff
block|,
comment|// 0x06c = 108 - JUMP
literal|0x02e
block|,
comment|// 0x06d = 109 -
literal|0x000
block|,
comment|// 0x06e = 110 - NO_OP
literal|0x0d4
block|,
comment|// 0x06f = 111 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x093
block|,
comment|// 0x070 = 112 -
literal|0x0aa
block|,
comment|// 0x071 = 113 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x084
block|,
comment|// 0x072 = 114 -
literal|0x0ab
block|,
comment|// 0x073 = 115 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x084
block|,
comment|// 0x074 = 116 -
literal|0x0ac
block|,
comment|// 0x075 = 117 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x087
block|,
comment|// 0x076 = 118 -
literal|0x0ad
block|,
comment|// 0x077 = 119 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x08d
block|,
comment|// 0x078 = 120 -
literal|0x0af
block|,
comment|// 0x079 = 121 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x08a
block|,
comment|// 0x07a = 122 -
literal|0x0ae
block|,
comment|// 0x07b = 123 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x084
block|,
comment|// 0x07c = 124 -
literal|0x0d2
block|,
comment|// 0x07d = 125 - JUMP_IF_SFO_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x090
block|,
comment|// 0x07e = 126 -
literal|0x0ca
block|,
comment|// 0x07f = 127 - JUMP_IF_PHY_READY
literal|0x06f
block|,
comment|// 0x080 = 128 -
literal|0x033
block|,
comment|// 0x081 = 129 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x082 = 130 - JUMP
literal|0x001
block|,
comment|// 0x083 = 131 -
literal|0x006
block|,
comment|// 0x084 = 132 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x085 = 133 - JUMP
literal|0x08d
block|,
comment|// 0x086 = 134 -
literal|0x007
block|,
comment|// 0x087 = 135 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x08d
block|,
comment|// 0x089 = 137 -
literal|0x008
block|,
comment|// 0x08a = 138 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x08b = 139 - JUMP
literal|0x08d
block|,
comment|// 0x08c = 140 -
literal|0x034
block|,
comment|// 0x08d = 141 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x08e = 142 - JUMP
literal|0x156
block|,
comment|// 0x08f = 143 -
literal|0x034
block|,
comment|// 0x090 = 144 - ADVANCE_SFO
literal|0x0ff
block|,
comment|// 0x091 = 145 - JUMP
literal|0x166
block|,
comment|// 0x092 = 146 -
literal|0x037
block|,
comment|// 0x093 = 147 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x094 = 148 - JUMP
literal|0x071
block|,
comment|// 0x095 = 149 -
literal|0x01c
block|,
comment|// 0x096 = 150 - START_IT_NEXUS_LOSS_TIMER_DOC
literal|0x018
block|,
comment|// 0x097 = 151 - PATHWAY_BLOCKED_CNT_DOC_RESET
literal|0x014
block|,
comment|// 0x098 = 152 - START_ARB_WAIT_TIMER_DOC
literal|0x002
block|,
comment|// 0x099 = 153 - OPEN_REQUEST_DOC
literal|0x000
block|,
comment|// 0x09a = 154 - NO_OP
literal|0x000
block|,
comment|// 0x09b = 155 - NO_OP
literal|0x000
block|,
comment|// 0x09c = 156 - NO_OP
literal|0x000
block|,
comment|// 0x09d = 157 - NO_OP
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x091
block|,
comment|// 0x09f = 159 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0c1
block|,
comment|// 0x0a0 = 160 -
literal|0x097
block|,
comment|// 0x0a1 = 161 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0c4
block|,
comment|// 0x0a2 = 162 -
literal|0x09b
block|,
comment|// 0x0a3 = 163 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0c7
block|,
comment|// 0x0a4 = 164 -
literal|0x09d
block|,
comment|// 0x0a5 = 165 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0ca
block|,
comment|// 0x0a6 = 166 -
literal|0x096
block|,
comment|// 0x0a7 = 167 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0cd
block|,
comment|// 0x0a8 = 168 -
literal|0x095
block|,
comment|// 0x0a9 = 169 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0d0
block|,
comment|// 0x0aa = 170 -
literal|0x0a2
block|,
comment|// 0x0ab = 171 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT_DOC
literal|0x0d3
block|,
comment|// 0x0ac = 172 -
literal|0x09c
block|,
comment|// 0x0ad = 173 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x096
block|,
comment|// 0x0ae = 174 -
literal|0x098
block|,
comment|// 0x0af = 175 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x112
block|,
comment|// 0x0b0 = 176 -
literal|0x099
block|,
comment|// 0x0b1 = 177 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0d6
block|,
comment|// 0x0b2 = 178 -
literal|0x09a
block|,
comment|// 0x0b3 = 179 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x099
block|,
comment|// 0x0b4 = 180 -
literal|0x094
block|,
comment|// 0x0b5 = 181 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x099
block|,
comment|// 0x0b6 = 182 -
literal|0x0a7
block|,
comment|// 0x0b7 = 183 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x139
block|,
comment|// 0x0b8 = 184 -
literal|0x092
block|,
comment|// 0x0b9 = 185 - JUMP_IF_OPEN_STATUS_EQUAL_OCSM_BUSY
literal|0x099
block|,
comment|// 0x0ba = 186 -
literal|0x0ca
block|,
comment|// 0x0bb = 187 - JUMP_IF_PHY_READY
literal|0x09f
block|,
comment|// 0x0bc = 188 -
literal|0x032
block|,
comment|// 0x0bd = 189 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x0be = 190 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0bf = 191 - JUMP
literal|0x001
block|,
comment|// 0x0c0 = 192 -
literal|0x029
block|,
comment|// 0x0c1 = 193 - SET_OPEN_STATUS_NORMAL_DOC
literal|0x0ff
block|,
comment|// 0x0c2 = 194 - JUMP
literal|0x0d9
block|,
comment|// 0x0c3 = 195 -
literal|0x02d
block|,
comment|// 0x0c4 = 196 - SET_OPEN_STATUS_BAD_RATE_DOC
literal|0x0ff
block|,
comment|// 0x0c5 = 197 - JUMP
literal|0x112
block|,
comment|// 0x0c6 = 198 -
literal|0x02e
block|,
comment|// 0x0c7 = 199 - SET_OPEN_STATUS_BAD_PROTOCOL_DOC
literal|0x0ff
block|,
comment|// 0x0c8 = 200 - JUMP
literal|0x112
block|,
comment|// 0x0c9 = 201 -
literal|0x030
block|,
comment|// 0x0ca = 202 - SET_OPEN_STATUS_WRONG_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0cb = 203 - JUMP
literal|0x112
block|,
comment|// 0x0cc = 204 -
literal|0x02c
block|,
comment|// 0x0cd = 205 - SET_OPEN_STATUS_BREAK_DOC
literal|0x0ff
block|,
comment|// 0x0ce = 206 - JUMP
literal|0x112
block|,
comment|// 0x0cf = 207 -
literal|0x02b
block|,
comment|// 0x0d0 = 208 - SET_OPEN_STATUS_BAD_DEST_DOC
literal|0x0ff
block|,
comment|// 0x0d1 = 209 - JUMP
literal|0x112
block|,
comment|// 0x0d2 = 210 -
literal|0x02a
block|,
comment|// 0x0d3 = 211 - SET_OPEN_STATUS_IT_NEXUS_LOSS_DOC
literal|0x0ff
block|,
comment|// 0x0d4 = 212 - JUMP
literal|0x112
block|,
comment|// 0x0d5 = 213 -
literal|0x01a
block|,
comment|// 0x0d6 = 214 - PATHWAY_BLOCKED_CNT_DOC_INC
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x099
block|,
comment|// 0x0d8 = 216 -
literal|0x000
block|,
comment|// 0x0d9 = 217 - NO_OP
literal|0x0d4
block|,
comment|// 0x0da = 218 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x10f
block|,
comment|// 0x0db = 219 -
literal|0x0b1
block|,
comment|// 0x0dc = 220 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x0f1
block|,
comment|// 0x0dd = 221 -
literal|0x0b2
block|,
comment|// 0x0de = 222 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x0fd
block|,
comment|// 0x0df = 223 -
literal|0x0b3
block|,
comment|// 0x0e0 = 224 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x100
block|,
comment|// 0x0e1 = 225 -
literal|0x0b4
block|,
comment|// 0x0e2 = 226 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x106
block|,
comment|// 0x0e3 = 227 -
literal|0x0b6
block|,
comment|// 0x0e4 = 228 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x103
block|,
comment|// 0x0e5 = 229 -
literal|0x0b5
block|,
comment|// 0x0e6 = 230 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_UNEXPECTED_CLOSE
literal|0x0fd
block|,
comment|// 0x0e7 = 231 -
literal|0x0d3
block|,
comment|// 0x0e8 = 232 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x10c
block|,
comment|// 0x0e9 = 233 -
literal|0x0d5
block|,
comment|// 0x0ea = 234 - JUMP_IF_DOC_CLOSE_REQ
literal|0x153
block|,
comment|// 0x0eb = 235 -
literal|0x0ca
block|,
comment|// 0x0ec = 236 - JUMP_IF_PHY_READY
literal|0x0f5
block|,
comment|// 0x0ed = 237 -
literal|0x033
block|,
comment|// 0x0ee = 238 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0ef = 239 - JUMP
literal|0x001
block|,
comment|// 0x0f0 = 240 -
literal|0x0d0
block|,
comment|// 0x0f1 = 241 - JUMP_IF_SMP_PROTOCOL
literal|0x0fd
block|,
comment|// 0x0f2 = 242 -
literal|0x0ff
block|,
comment|// 0x0f3 = 243 - JUMP
literal|0x109
block|,
comment|// 0x0f4 = 244 -
literal|0x0b7
block|,
comment|// 0x0f5 = 245 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x0fd
block|,
comment|// 0x0f6 = 246 -
literal|0x0b8
block|,
comment|// 0x0f7 = 247 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x0fd
block|,
comment|// 0x0f8 = 248 -
literal|0x0b9
block|,
comment|// 0x0f9 = 249 - JUMP_IF_DOC_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x0fd
block|,
comment|// 0x0fa = 250 -
literal|0x0ff
block|,
comment|// 0x0fb = 251 - JUMP
literal|0x0da
block|,
comment|// 0x0fc = 252 -
literal|0x006
block|,
comment|// 0x0fd = 253 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x0fe = 254 - JUMP
literal|0x106
block|,
comment|// 0x0ff = 255 -
literal|0x007
block|,
comment|// 0x100 = 256 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x101 = 257 - JUMP
literal|0x106
block|,
comment|// 0x102 = 258 -
literal|0x008
block|,
comment|// 0x103 = 259 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x104 = 260 - JUMP
literal|0x106
block|,
comment|// 0x105 = 261 -
literal|0x035
block|,
comment|// 0x106 = 262 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x107 = 263 - JUMP
literal|0x156
block|,
comment|// 0x108 = 264 -
literal|0x035
block|,
comment|// 0x109 = 265 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x112
block|,
comment|// 0x10b = 267 -
literal|0x035
block|,
comment|// 0x10c = 268 - ADVANCE_DOC
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x166
block|,
comment|// 0x10e = 270 -
literal|0x037
block|,
comment|// 0x10f = 271 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x110 = 272 - JUMP
literal|0x0dc
block|,
comment|// 0x111 = 273 -
literal|0x0a9
block|,
comment|// 0x112 = 274 - JUMP_IF_SFO_REQ
literal|0x11d
block|,
comment|// 0x113 = 275 -
literal|0x0b0
block|,
comment|// 0x114 = 276 - JUMP_IF_DOC_REQ
literal|0x12f
block|,
comment|// 0x115 = 277 -
literal|0x0a8
block|,
comment|// 0x116 = 278 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x141
block|,
comment|// 0x117 = 279 -
literal|0x0ca
block|,
comment|// 0x118 = 280 - JUMP_IF_PHY_READY
literal|0x112
block|,
comment|// 0x119 = 281 -
literal|0x033
block|,
comment|// 0x11a = 282 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x11b = 283 - JUMP
literal|0x001
block|,
comment|// 0x11c = 284 -
literal|0x0ca
block|,
comment|// 0x11d = 285 - JUMP_IF_PHY_READY
literal|0x123
block|,
comment|// 0x11e = 286 -
literal|0x031
block|,
comment|// 0x11f = 287 - SET_OPEN_STATUS_PHY_NOT_RDY_SFO
literal|0x033
block|,
comment|// 0x120 = 288 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x121 = 289 - JUMP
literal|0x001
block|,
comment|// 0x122 = 290 -
literal|0x0a8
block|,
comment|// 0x123 = 291 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x127
block|,
comment|// 0x124 = 292 -
literal|0x0ff
block|,
comment|// 0x125 = 293 - JUMP
literal|0x02b
block|,
comment|// 0x126 = 294 -
literal|0x0a3
block|,
comment|// 0x127 = 295 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_SFO
literal|0x12b
block|,
comment|// 0x128 = 296 -
literal|0x0ff
block|,
comment|// 0x129 = 297 - JUMP
literal|0x114
block|,
comment|// 0x12a = 298 -
literal|0x0c8
block|,
comment|// 0x12b = 299 - JUMP_IF_BREAK_RECEIVED
literal|0x166
block|,
comment|// 0x12c = 300 -
literal|0x0ff
block|,
comment|// 0x12d = 301 - JUMP
literal|0x056
block|,
comment|// 0x12e = 302 -
literal|0x0ca
block|,
comment|// 0x12f = 303 - JUMP_IF_PHY_READY
literal|0x135
block|,
comment|// 0x130 = 304 -
literal|0x032
block|,
comment|// 0x131 = 305 - SET_OPEN_STATUS_PHY_NOT_RDY_DOC
literal|0x033
block|,
comment|// 0x132 = 306 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x133 = 307 - JUMP
literal|0x001
block|,
comment|// 0x134 = 308 -
literal|0x0a8
block|,
comment|// 0x135 = 309 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x139
block|,
comment|// 0x136 = 310 -
literal|0x0ff
block|,
comment|// 0x137 = 311 - JUMP
literal|0x096
block|,
comment|// 0x138 = 312 -
literal|0x0a4
block|,
comment|// 0x139 = 313 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL_DOC
literal|0x13d
block|,
comment|// 0x13a = 314 -
literal|0x0ff
block|,
comment|// 0x13b = 315 - JUMP
literal|0x116
block|,
comment|// 0x13c = 316 -
literal|0x0c8
block|,
comment|// 0x13d = 317 - JUMP_IF_BREAK_RECEIVED
literal|0x166
block|,
comment|// 0x13e = 318 -
literal|0x0ff
block|,
comment|// 0x13f = 319 - JUMP
literal|0x0c1
block|,
comment|// 0x140 = 320 -
literal|0x0d0
block|,
comment|// 0x141 = 321 - JUMP_IF_SMP_PROTOCOL
literal|0x14c
block|,
comment|// 0x142 = 322 -
literal|0x0d4
block|,
comment|// 0x143 = 323 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x150
block|,
comment|// 0x144 = 324 -
literal|0x0a6
block|,
comment|// 0x145 = 325 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x149
block|,
comment|// 0x146 = 326 -
literal|0x0ff
block|,
comment|// 0x147 = 327 - JUMP
literal|0x16e
block|,
comment|// 0x148 = 328 -
literal|0x006
block|,
comment|// 0x149 = 329 - CLOSE_NORMAL
literal|0x0ff
block|,
comment|// 0x14a = 330 - JUMP
literal|0x156
block|,
comment|// 0x14b = 331 -
literal|0x0d1
block|,
comment|// 0x14c = 332 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x177
block|,
comment|// 0x14d = 333 -
literal|0x0ff
block|,
comment|// 0x14e = 334 - JUMP
literal|0x112
block|,
comment|// 0x14f = 335 -
literal|0x037
block|,
comment|// 0x150 = 336 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x151 = 337 - JUMP
literal|0x145
block|,
comment|// 0x152 = 338 -
literal|0x0c8
block|,
comment|// 0x153 = 339 - JUMP_IF_BREAK_RECEIVED
literal|0x166
block|,
comment|// 0x154 = 340 -
literal|0x006
block|,
comment|// 0x155 = 341 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x0d4
block|,
comment|// 0x15b = 347 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x16b
block|,
comment|// 0x15c = 348 -
literal|0x0cd
block|,
comment|// 0x15d = 349 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x112
block|,
comment|// 0x15e = 350 -
literal|0x0c8
block|,
comment|// 0x15f = 351 - JUMP_IF_BREAK_RECEIVED
literal|0x166
block|,
comment|// 0x160 = 352 -
literal|0x0ca
block|,
comment|// 0x161 = 353 - JUMP_IF_PHY_READY
literal|0x156
block|,
comment|// 0x162 = 354 -
literal|0x033
block|,
comment|// 0x163 = 355 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x164 = 356 - JUMP
literal|0x001
block|,
comment|// 0x165 = 357 -
literal|0x009
block|,
comment|// 0x166 = 358 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x167 = 359 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x167
block|,
comment|// 0x168 = 360 -
literal|0x0ff
block|,
comment|// 0x169 = 361 - JUMP
literal|0x112
block|,
comment|// 0x16a = 362 -
literal|0x037
block|,
comment|// 0x16b = 363 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x16c = 364 - JUMP
literal|0x15d
block|,
comment|// 0x16d = 365 -
literal|0x0c8
block|,
comment|// 0x16e = 366 - JUMP_IF_BREAK_RECEIVED
literal|0x177
block|,
comment|// 0x16f = 367 -
literal|0x0ce
block|,
comment|// 0x170 = 368 - JUMP_IF_ANY_DONE_RECEIVED
literal|0x17c
block|,
comment|// 0x171 = 369 -
literal|0x0ca
block|,
comment|// 0x172 = 370 - JUMP_IF_PHY_READY
literal|0x112
block|,
comment|// 0x173 = 371 -
literal|0x033
block|,
comment|// 0x174 = 372 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x175 = 373 - JUMP
literal|0x112
block|,
comment|// 0x176 = 374 -
literal|0x009
block|,
comment|// 0x177 = 375 - CLOSE_BREAK
literal|0x0a8
block|,
comment|// 0x178 = 376 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x178
block|,
comment|// 0x179 = 377 -
literal|0x0ff
block|,
comment|// 0x17a = 378 - JUMP
literal|0x112
block|,
comment|// 0x17b = 379 -
literal|0x006
block|,
comment|// 0x17c = 380 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x0cd
block|,
comment|// 0x182 = 386 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x112
block|,
comment|// 0x183 = 387 -
literal|0x0d4
block|,
comment|// 0x184 = 388 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x18d
block|,
comment|// 0x185 = 389 -
literal|0x0c8
block|,
comment|// 0x186 = 390 - JUMP_IF_BREAK_RECEIVED
literal|0x177
block|,
comment|// 0x187 = 391 -
literal|0x0ca
block|,
comment|// 0x188 = 392 - JUMP_IF_PHY_READY
literal|0x182
block|,
comment|// 0x189 = 393 -
literal|0x033
block|,
comment|// 0x18a = 394 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x18b = 395 - JUMP
literal|0x001
block|,
comment|// 0x18c = 396 -
literal|0x037
block|,
comment|// 0x18d = 397 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x18e = 398 - JUMP
literal|0x186
block|,
comment|// 0x18f = 399 -
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* worked with the bitmap both pnr11020.bit(mainly this) and t091505d0.bit,    this has been golden */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage11020
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ae
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0af
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x00c
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0af
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x01c
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0af
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x00c
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0be
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x00c
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x061
block|,
comment|// 0x02a = 42 -
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x0c9
block|,
comment|// 0x02c = 44 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x05e
block|,
comment|// 0x02d = 45 -
literal|0x0a5
block|,
comment|// 0x02e = 46 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x041
block|,
comment|// 0x02f = 47 -
literal|0x0a6
block|,
comment|// 0x030 = 48 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x052
block|,
comment|// 0x031 = 49 -
literal|0x0a7
block|,
comment|// 0x032 = 50 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x055
block|,
comment|// 0x033 = 51 -
literal|0x0a8
block|,
comment|// 0x034 = 52 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x052
block|,
comment|// 0x035 = 53 -
literal|0x0aa
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x058
block|,
comment|// 0x037 = 55 -
literal|0x0c5
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x05b
block|,
comment|// 0x039 = 57 -
literal|0x0ca
block|,
comment|// 0x03a = 58 - JUMP_IF_DOC_CLOSE_REQ
literal|0x0a5
block|,
comment|// 0x03b = 59 -
literal|0x0be
block|,
comment|// 0x03c = 60 - JUMP_IF_PHY_READY
literal|0x04a
block|,
comment|// 0x03d = 61 -
literal|0x01c
block|,
comment|// 0x03e = 62 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x03f = 63 - JUMP
literal|0x001
block|,
comment|// 0x040 = 64 -
literal|0x01d
block|,
comment|// 0x041 = 65 - ADVANCE
literal|0x0c3
block|,
comment|// 0x042 = 66 - JUMP_IF_SMP_PROTOCOL
literal|0x046
block|,
comment|// 0x043 = 67 -
literal|0x0ff
block|,
comment|// 0x044 = 68 - JUMP
literal|0x061
block|,
comment|// 0x045 = 69 -
literal|0x0a2
block|,
comment|// 0x046 = 70 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0a5
block|,
comment|// 0x047 = 71 -
literal|0x0ff
block|,
comment|// 0x048 = 72 - JUMP
literal|0x061
block|,
comment|// 0x049 = 73 -
literal|0x0ab
block|,
comment|// 0x04a = 74 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_BLOCKED
literal|0x052
block|,
comment|// 0x04b = 75 -
literal|0x0ac
block|,
comment|// 0x04c = 76 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x052
block|,
comment|// 0x04d = 77 -
literal|0x0ad
block|,
comment|// 0x04e = 78 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_CONNECTION_TIME
literal|0x052
block|,
comment|// 0x04f = 79 -
literal|0x0ff
block|,
comment|// 0x050 = 80 - JUMP
literal|0x02c
block|,
comment|// 0x051 = 81 -
literal|0x01d
block|,
comment|// 0x052 = 82 - ADVANCE
literal|0x0ff
block|,
comment|// 0x053 = 83 - JUMP
literal|0x061
block|,
comment|// 0x054 = 84 -
literal|0x01d
block|,
comment|// 0x055 = 85 - ADVANCE
literal|0x0ff
block|,
comment|// 0x056 = 86 - JUMP
literal|0x0c2
block|,
comment|// 0x057 = 87 -
literal|0x01d
block|,
comment|// 0x058 = 88 - ADVANCE
literal|0x0ff
block|,
comment|// 0x059 = 89 - JUMP
literal|0x0c5
block|,
comment|// 0x05a = 90 -
literal|0x01d
block|,
comment|// 0x05b = 91 - ADVANCE
literal|0x0ff
block|,
comment|// 0x05c = 92 - JUMP
literal|0x0b6
block|,
comment|// 0x05d = 93 -
literal|0x022
block|,
comment|// 0x05e = 94 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x05f = 95 - JUMP
literal|0x02e
block|,
comment|// 0x060 = 96 -
literal|0x0c8
block|,
comment|// 0x061 = 97 - JUMP_IF_HIP_REQ
literal|0x06d
block|,
comment|// 0x062 = 98 -
literal|0x0c6
block|,
comment|// 0x063 = 99 - JUMP_IF_SFO_REQ
literal|0x07d
block|,
comment|// 0x064 = 100 -
literal|0x0c7
block|,
comment|// 0x065 = 101 - JUMP_IF_DOC_REQ
literal|0x08d
block|,
comment|// 0x066 = 102 -
literal|0x0a3
block|,
comment|// 0x067 = 103 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x09d
block|,
comment|// 0x068 = 104 -
literal|0x0a2
block|,
comment|// 0x069 = 105 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0a5
block|,
comment|// 0x06a = 106 -
literal|0x0ff
block|,
comment|// 0x06b = 107 - JUMP
literal|0x061
block|,
comment|// 0x06c = 108 -
literal|0x020
block|,
comment|// 0x06d = 109 - SELECT_HIP
literal|0x000
block|,
comment|// 0x06e = 110 - NO_OP
literal|0x000
block|,
comment|// 0x06f = 111 - NO_OP
literal|0x0a4
block|,
comment|// 0x070 = 112 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x074
block|,
comment|// 0x071 = 113 -
literal|0x0ff
block|,
comment|// 0x072 = 114 - JUMP
literal|0x0c8
block|,
comment|// 0x073 = 115 -
literal|0x0a0
block|,
comment|// 0x074 = 116 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x07a
block|,
comment|// 0x075 = 117 -
literal|0x0a3
block|,
comment|// 0x076 = 118 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x09d
block|,
comment|// 0x077 = 119 -
literal|0x0ff
block|,
comment|// 0x078 = 120 - JUMP
literal|0x0a5
block|,
comment|// 0x079 = 121 -
literal|0x013
block|,
comment|// 0x07a = 122 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x07b = 123 - JUMP
literal|0x02b
block|,
comment|// 0x07c = 124 -
literal|0x01e
block|,
comment|// 0x07d = 125 - SELECT_SFO
literal|0x000
block|,
comment|// 0x07e = 126 - NO_OP
literal|0x000
block|,
comment|// 0x07f = 127 - NO_OP
literal|0x0a4
block|,
comment|// 0x080 = 128 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x084
block|,
comment|// 0x081 = 129 -
literal|0x0ff
block|,
comment|// 0x082 = 130 - JUMP
literal|0x0c8
block|,
comment|// 0x083 = 131 -
literal|0x0a0
block|,
comment|// 0x084 = 132 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x08a
block|,
comment|// 0x085 = 133 -
literal|0x0a3
block|,
comment|// 0x086 = 134 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x09d
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x0a5
block|,
comment|// 0x089 = 137 -
literal|0x013
block|,
comment|// 0x08a = 138 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x08b = 139 - JUMP
literal|0x02b
block|,
comment|// 0x08c = 140 -
literal|0x01f
block|,
comment|// 0x08d = 141 - SELECT_DOC
literal|0x000
block|,
comment|// 0x08e = 142 - NO_OP
literal|0x000
block|,
comment|// 0x08f = 143 - NO_OP
literal|0x0a4
block|,
comment|// 0x090 = 144 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x094
block|,
comment|// 0x091 = 145 -
literal|0x0ff
block|,
comment|// 0x092 = 146 - JUMP
literal|0x0c8
block|,
comment|// 0x093 = 147 -
literal|0x0a0
block|,
comment|// 0x094 = 148 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x09a
block|,
comment|// 0x095 = 149 -
literal|0x0a3
block|,
comment|// 0x096 = 150 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x09d
block|,
comment|// 0x097 = 151 -
literal|0x0ff
block|,
comment|// 0x098 = 152 - JUMP
literal|0x0a5
block|,
comment|// 0x099 = 153 -
literal|0x013
block|,
comment|// 0x09a = 154 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x09b = 155 - JUMP
literal|0x02b
block|,
comment|// 0x09c = 156 -
literal|0x0c3
block|,
comment|// 0x09d = 157 - JUMP_IF_SMP_PROTOCOL
literal|0x0a1
block|,
comment|// 0x09e = 158 -
literal|0x0ff
block|,
comment|// 0x09f = 159 - JUMP
literal|0x0a5
block|,
comment|// 0x0a0 = 160 -
literal|0x0c4
block|,
comment|// 0x0a1 = 161 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x0b6
block|,
comment|// 0x0a2 = 162 -
literal|0x0ff
block|,
comment|// 0x0a3 = 163 - JUMP
literal|0x061
block|,
comment|// 0x0a4 = 164 -
literal|0x004
block|,
comment|// 0x0a5 = 165 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x0a6 = 166 - NO_OP
literal|0x000
block|,
comment|// 0x0a7 = 167 - NO_OP
literal|0x000
block|,
comment|// 0x0a8 = 168 - NO_OP
literal|0x000
block|,
comment|// 0x0a9 = 169 - NO_OP
literal|0x0c9
block|,
comment|// 0x0aa = 170 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x0b3
block|,
comment|// 0x0ab = 171 -
literal|0x0c0
block|,
comment|// 0x0ac = 172 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x061
block|,
comment|// 0x0ad = 173 -
literal|0x0be
block|,
comment|// 0x0ae = 174 - JUMP_IF_PHY_READY
literal|0x0a6
block|,
comment|// 0x0af = 175 -
literal|0x01c
block|,
comment|// 0x0b0 = 176 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0b1 = 177 - JUMP
literal|0x001
block|,
comment|// 0x0b2 = 178 -
literal|0x022
block|,
comment|// 0x0b3 = 179 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x0b4 = 180 - JUMP
literal|0x0a6
block|,
comment|// 0x0b5 = 181 -
literal|0x007
block|,
comment|// 0x0b6 = 182 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x0b7 = 183 - NO_OP
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x000
block|,
comment|// 0x0b9 = 185 - NO_OP
literal|0x000
block|,
comment|// 0x0ba = 186 - NO_OP
literal|0x0c0
block|,
comment|// 0x0bb = 187 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x061
block|,
comment|// 0x0bc = 188 -
literal|0x0be
block|,
comment|// 0x0bd = 189 - JUMP_IF_PHY_READY
literal|0x0b7
block|,
comment|// 0x0be = 190 -
literal|0x01c
block|,
comment|// 0x0bf = 191 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0c0 = 192 - JUMP
literal|0x001
block|,
comment|// 0x0c1 = 193 -
literal|0x005
block|,
comment|// 0x0c2 = 194 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0c3 = 195 - JUMP
literal|0x0a6
block|,
comment|// 0x0c4 = 196 -
literal|0x006
block|,
comment|// 0x0c5 = 197 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0c6 = 198 - JUMP
literal|0x0a6
block|,
comment|// 0x0c7 = 199 -
literal|0x0b0
block|,
comment|// 0x0c8 = 200 - JUMP_IF_FLAG_0_SET
literal|0x0cd
block|,
comment|// 0x0c9 = 201 -
literal|0x011
block|,
comment|// 0x0ca = 202 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x0cb = 203 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x0cc = 204 - START_ARB_WAIT_TIMER
literal|0x001
block|,
comment|// 0x0cd = 205 - OPEN_REQUEST
literal|0x000
block|,
comment|// 0x0ce = 206 - NO_OP
literal|0x000
block|,
comment|// 0x0cf = 207 - NO_OP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x090
block|,
comment|// 0x0d2 = 210 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0f8
block|,
comment|// 0x0d3 = 211 -
literal|0x095
block|,
comment|// 0x0d4 = 212 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0fd
block|,
comment|// 0x0d5 = 213 -
literal|0x099
block|,
comment|// 0x0d6 = 214 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x100
block|,
comment|// 0x0d7 = 215 -
literal|0x09b
block|,
comment|// 0x0d8 = 216 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x103
block|,
comment|// 0x0d9 = 217 -
literal|0x094
block|,
comment|// 0x0da = 218 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0cd
block|,
comment|// 0x0db = 219 -
literal|0x093
block|,
comment|// 0x0dc = 220 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x106
block|,
comment|// 0x0dd = 221 -
literal|0x09f
block|,
comment|// 0x0de = 222 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x109
block|,
comment|// 0x0df = 223 -
literal|0x09a
block|,
comment|// 0x0e0 = 224 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x0cd
block|,
comment|// 0x0e1 = 225 -
literal|0x096
block|,
comment|// 0x0e2 = 226 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x106
block|,
comment|// 0x0e3 = 227 -
literal|0x097
block|,
comment|// 0x0e4 = 228 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x10c
block|,
comment|// 0x0e5 = 229 -
literal|0x098
block|,
comment|// 0x0e6 = 230 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0cd
block|,
comment|// 0x0e7 = 231 -
literal|0x092
block|,
comment|// 0x0e8 = 232 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0cd
block|,
comment|// 0x0e9 = 233 -
literal|0x0a4
block|,
comment|// 0x0ea = 234 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0f2
block|,
comment|// 0x0eb = 235 -
literal|0x0be
block|,
comment|// 0x0ec = 236 - JUMP_IF_PHY_READY
literal|0x0d2
block|,
comment|// 0x0ed = 237 -
literal|0x01b
block|,
comment|// 0x0ee = 238 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x0ef = 239 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0f0 = 240 - JUMP
literal|0x001
block|,
comment|// 0x0f1 = 241 -
literal|0x0a0
block|,
comment|// 0x0f2 = 242 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0f8
block|,
comment|// 0x0f3 = 243 -
literal|0x000
block|,
comment|// 0x0f4 = 244 - NO_OP
literal|0x000
block|,
comment|// 0x0f5 = 245 - NO_OP
literal|0x0ff
block|,
comment|// 0x0f6 = 246 - JUMP
literal|0x09d
block|,
comment|// 0x0f7 = 247 -
literal|0x013
block|,
comment|// 0x0f8 = 248 - SET_OPEN_STATUS_NORMAL
literal|0x000
block|,
comment|// 0x0f9 = 249 - NO_OP
literal|0x000
block|,
comment|// 0x0fa = 250 - NO_OP
literal|0x0ff
block|,
comment|// 0x0fb = 251 - JUMP
literal|0x02b
block|,
comment|// 0x0fc = 252 -
literal|0x017
block|,
comment|// 0x0fd = 253 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x0fe = 254 - JUMP
literal|0x061
block|,
comment|// 0x0ff = 255 -
literal|0x018
block|,
comment|// 0x100 = 256 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x101 = 257 - JUMP
literal|0x061
block|,
comment|// 0x102 = 258 -
literal|0x01a
block|,
comment|// 0x103 = 259 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x104 = 260 - JUMP
literal|0x061
block|,
comment|// 0x105 = 261 -
literal|0x015
block|,
comment|// 0x106 = 262 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x107 = 263 - JUMP
literal|0x061
block|,
comment|// 0x108 = 264 -
literal|0x014
block|,
comment|// 0x109 = 265 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x061
block|,
comment|// 0x10b = 267 -
literal|0x010
block|,
comment|// 0x10c = 268 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x0cd
block|,
comment|// 0x10e = 270 -
literal|0x000
block|,
comment|// 0x10f = 271 - NO_OP
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x000
block|,
comment|// 0x112 = 274 - NO_OP
literal|0x000
block|,
comment|// 0x113 = 275 - NO_OP
literal|0x000
block|,
comment|// 0x114 = 276 - NO_OP
literal|0x000
block|,
comment|// 0x115 = 277 - NO_OP
literal|0x000
block|,
comment|// 0x116 = 278 - NO_OP
literal|0x000
block|,
comment|// 0x117 = 279 - NO_OP
literal|0x000
block|,
comment|// 0x118 = 280 - NO_OP
literal|0x000
block|,
comment|// 0x119 = 281 - NO_OP
literal|0x000
block|,
comment|// 0x11a = 282 - NO_OP
literal|0x000
block|,
comment|// 0x11b = 283 - NO_OP
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x000
block|,
comment|// 0x120 = 288 - NO_OP
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x000
block|,
comment|// 0x125 = 293 - NO_OP
literal|0x000
block|,
comment|// 0x126 = 294 - NO_OP
literal|0x000
block|,
comment|// 0x127 = 295 - NO_OP
literal|0x000
block|,
comment|// 0x128 = 296 - NO_OP
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x000
block|,
comment|// 0x132 = 306 - NO_OP
literal|0x000
block|,
comment|// 0x133 = 307 - NO_OP
literal|0x000
block|,
comment|// 0x134 = 308 - NO_OP
literal|0x000
block|,
comment|// 0x135 = 309 - NO_OP
literal|0x000
block|,
comment|// 0x136 = 310 - NO_OP
literal|0x000
block|,
comment|// 0x137 = 311 - NO_OP
literal|0x000
block|,
comment|// 0x138 = 312 - NO_OP
literal|0x000
block|,
comment|// 0x139 = 313 - NO_OP
literal|0x000
block|,
comment|// 0x13a = 314 - NO_OP
literal|0x000
block|,
comment|// 0x13b = 315 - NO_OP
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x000
block|,
comment|// 0x140 = 320 - NO_OP
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x000
block|,
comment|// 0x146 = 326 - NO_OP
literal|0x000
block|,
comment|// 0x147 = 327 - NO_OP
literal|0x000
block|,
comment|// 0x148 = 328 - NO_OP
literal|0x000
block|,
comment|// 0x149 = 329 - NO_OP
literal|0x000
block|,
comment|// 0x14a = 330 - NO_OP
literal|0x000
block|,
comment|// 0x14b = 331 - NO_OP
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x000
block|,
comment|// 0x151 = 337 - NO_OP
literal|0x000
block|,
comment|// 0x152 = 338 - NO_OP
literal|0x000
block|,
comment|// 0x153 = 339 - NO_OP
literal|0x000
block|,
comment|// 0x154 = 340 - NO_OP
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x000
block|,
comment|// 0x15b = 347 - NO_OP
literal|0x000
block|,
comment|// 0x15c = 348 - NO_OP
literal|0x000
block|,
comment|// 0x15d = 349 - NO_OP
literal|0x000
block|,
comment|// 0x15e = 350 - NO_OP
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for pnr12220.bit  */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage12220
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ae
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0af
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x00c
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0af
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x01c
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0af
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x00c
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0be
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x00c
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x059
block|,
comment|// 0x02a = 42 -
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x0c9
block|,
comment|// 0x02c = 44 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x056
block|,
comment|// 0x02d = 45 -
literal|0x0a5
block|,
comment|// 0x02e = 46 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x041
block|,
comment|// 0x02f = 47 -
literal|0x0a6
block|,
comment|// 0x030 = 48 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x04a
block|,
comment|// 0x031 = 49 -
literal|0x0a7
block|,
comment|// 0x032 = 50 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x04d
block|,
comment|// 0x033 = 51 -
literal|0x0a8
block|,
comment|// 0x034 = 52 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x053
block|,
comment|// 0x035 = 53 -
literal|0x0aa
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x050
block|,
comment|// 0x037 = 55 -
literal|0x0c5
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x053
block|,
comment|// 0x039 = 57 -
literal|0x0ca
block|,
comment|// 0x03a = 58 - JUMP_IF_CLOSE_REQ
literal|0x08e
block|,
comment|// 0x03b = 59 -
literal|0x0be
block|,
comment|// 0x03c = 60 - JUMP_IF_PHY_READY
literal|0x02c
block|,
comment|// 0x03d = 61 -
literal|0x01c
block|,
comment|// 0x03e = 62 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x03f = 63 - JUMP
literal|0x001
block|,
comment|// 0x040 = 64 -
literal|0x01d
block|,
comment|// 0x041 = 65 - ADVANCE
literal|0x0c3
block|,
comment|// 0x042 = 66 - JUMP_IF_SMP_PROTOCOL
literal|0x046
block|,
comment|// 0x043 = 67 -
literal|0x0ff
block|,
comment|// 0x044 = 68 - JUMP
literal|0x059
block|,
comment|// 0x045 = 69 -
literal|0x0a2
block|,
comment|// 0x046 = 70 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x08e
block|,
comment|// 0x047 = 71 -
literal|0x0ff
block|,
comment|// 0x048 = 72 - JUMP
literal|0x059
block|,
comment|// 0x049 = 73 -
literal|0x01d
block|,
comment|// 0x04a = 74 - ADVANCE
literal|0x0ff
block|,
comment|// 0x04b = 75 - JUMP
literal|0x059
block|,
comment|// 0x04c = 76 -
literal|0x01d
block|,
comment|// 0x04d = 77 - ADVANCE
literal|0x0ff
block|,
comment|// 0x04e = 78 - JUMP
literal|0x0ad
block|,
comment|// 0x04f = 79 -
literal|0x01d
block|,
comment|// 0x050 = 80 - ADVANCE
literal|0x0ff
block|,
comment|// 0x051 = 81 - JUMP
literal|0x0b0
block|,
comment|// 0x052 = 82 -
literal|0x01d
block|,
comment|// 0x053 = 83 - ADVANCE
literal|0x0ff
block|,
comment|// 0x054 = 84 - JUMP
literal|0x0a1
block|,
comment|// 0x055 = 85 -
literal|0x022
block|,
comment|// 0x056 = 86 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x057 = 87 - JUMP
literal|0x02e
block|,
comment|// 0x058 = 88 -
literal|0x0c8
block|,
comment|// 0x059 = 89 - JUMP_IF_HIP_REQ
literal|0x065
block|,
comment|// 0x05a = 90 -
literal|0x0c6
block|,
comment|// 0x05b = 91 - JUMP_IF_SFO_REQ
literal|0x06a
block|,
comment|// 0x05c = 92 -
literal|0x0c7
block|,
comment|// 0x05d = 93 - JUMP_IF_DOC_REQ
literal|0x06f
block|,
comment|// 0x05e = 94 -
literal|0x0a3
block|,
comment|// 0x05f = 95 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x086
block|,
comment|// 0x060 = 96 -
literal|0x0a2
block|,
comment|// 0x061 = 97 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x08e
block|,
comment|// 0x062 = 98 -
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x059
block|,
comment|// 0x064 = 100 -
literal|0x020
block|,
comment|// 0x065 = 101 - SELECT_HIP
literal|0x000
block|,
comment|// 0x066 = 102 - NO_OP
literal|0x000
block|,
comment|// 0x067 = 103 - NO_OP
literal|0x0ff
block|,
comment|// 0x068 = 104 - JUMP
literal|0x072
block|,
comment|// 0x069 = 105 -
literal|0x01e
block|,
comment|// 0x06a = 106 - SELECT_SFO
literal|0x000
block|,
comment|// 0x06b = 107 - NO_OP
literal|0x000
block|,
comment|// 0x06c = 108 - NO_OP
literal|0x0ff
block|,
comment|// 0x06d = 109 - JUMP
literal|0x072
block|,
comment|// 0x06e = 110 -
literal|0x01f
block|,
comment|// 0x06f = 111 - SELECT_DOC
literal|0x000
block|,
comment|// 0x070 = 112 - NO_OP
literal|0x000
block|,
comment|// 0x071 = 113 - NO_OP
literal|0x0a4
block|,
comment|// 0x072 = 114 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x076
block|,
comment|// 0x073 = 115 -
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x0b3
block|,
comment|// 0x075 = 117 -
literal|0x0a0
block|,
comment|// 0x076 = 118 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x07c
block|,
comment|// 0x077 = 119 -
literal|0x0a3
block|,
comment|// 0x078 = 120 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x086
block|,
comment|// 0x079 = 121 -
literal|0x0ff
block|,
comment|// 0x07a = 122 - JUMP
literal|0x08e
block|,
comment|// 0x07b = 123 -
literal|0x0cb
block|,
comment|// 0x07c = 124 - JUMP_IF_FREEZE_ACTIVE
literal|0x081
block|,
comment|// 0x07d = 125 -
literal|0x013
block|,
comment|// 0x07e = 126 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x07f = 127 - JUMP
literal|0x02b
block|,
comment|// 0x080 = 128 -
literal|0x024
block|,
comment|// 0x081 = 129 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x082 = 130 - NO_OP
literal|0x000
block|,
comment|// 0x083 = 131 - NO_OP
literal|0x0ff
block|,
comment|// 0x084 = 132 - JUMP
literal|0x059
block|,
comment|// 0x085 = 133 -
literal|0x0c3
block|,
comment|// 0x086 = 134 - JUMP_IF_SMP_PROTOCOL
literal|0x08a
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x08e
block|,
comment|// 0x089 = 137 -
literal|0x0c4
block|,
comment|// 0x08a = 138 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x0a1
block|,
comment|// 0x08b = 139 -
literal|0x0ff
block|,
comment|// 0x08c = 140 - JUMP
literal|0x059
block|,
comment|// 0x08d = 141 -
literal|0x004
block|,
comment|// 0x08e = 142 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x08f = 143 - NO_OP
literal|0x000
block|,
comment|// 0x090 = 144 - NO_OP
literal|0x000
block|,
comment|// 0x091 = 145 - NO_OP
literal|0x000
block|,
comment|// 0x092 = 146 - NO_OP
literal|0x0c9
block|,
comment|// 0x093 = 147 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x09e
block|,
comment|// 0x094 = 148 -
literal|0x0c0
block|,
comment|// 0x095 = 149 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x059
block|,
comment|// 0x096 = 150 -
literal|0x0bc
block|,
comment|// 0x097 = 151 - JUMP_IF_BREAK_RECEIVED
literal|0x0a1
block|,
comment|// 0x098 = 152 -
literal|0x0be
block|,
comment|// 0x099 = 153 - JUMP_IF_PHY_READY
literal|0x08f
block|,
comment|// 0x09a = 154 -
literal|0x01c
block|,
comment|// 0x09b = 155 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x09c = 156 - JUMP
literal|0x001
block|,
comment|// 0x09d = 157 -
literal|0x022
block|,
comment|// 0x09e = 158 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x09f = 159 - JUMP
literal|0x08f
block|,
comment|// 0x0a0 = 160 -
literal|0x007
block|,
comment|// 0x0a1 = 161 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x0a2 = 162 - NO_OP
literal|0x000
block|,
comment|// 0x0a3 = 163 - NO_OP
literal|0x000
block|,
comment|// 0x0a4 = 164 - NO_OP
literal|0x000
block|,
comment|// 0x0a5 = 165 - NO_OP
literal|0x0c0
block|,
comment|// 0x0a6 = 166 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x059
block|,
comment|// 0x0a7 = 167 -
literal|0x0be
block|,
comment|// 0x0a8 = 168 - JUMP_IF_PHY_READY
literal|0x0a2
block|,
comment|// 0x0a9 = 169 -
literal|0x01c
block|,
comment|// 0x0aa = 170 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0ab = 171 - JUMP
literal|0x001
block|,
comment|// 0x0ac = 172 -
literal|0x005
block|,
comment|// 0x0ad = 173 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0ae = 174 - JUMP
literal|0x08f
block|,
comment|// 0x0af = 175 -
literal|0x006
block|,
comment|// 0x0b0 = 176 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0b1 = 177 - JUMP
literal|0x08f
block|,
comment|// 0x0b2 = 178 -
literal|0x0cc
block|,
comment|// 0x0b3 = 179 - JUMP_IF_RX_BUFFER_FULL
literal|0x059
block|,
comment|// 0x0b4 = 180 -
literal|0x0b0
block|,
comment|// 0x0b5 = 181 - JUMP_IF_FLAG_0_SET
literal|0x0ba
block|,
comment|// 0x0b6 = 182 -
literal|0x011
block|,
comment|// 0x0b7 = 183 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x0b8 = 184 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x0b9 = 185 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x0ba = 186 - JUMP_IF_FREEZE_ACTIVE
literal|0x0fb
block|,
comment|// 0x0bb = 187 -
literal|0x001
block|,
comment|// 0x0bc = 188 - OPEN_REQUEST
literal|0x000
block|,
comment|// 0x0bd = 189 - NO_OP
literal|0x000
block|,
comment|// 0x0be = 190 - NO_OP
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x090
block|,
comment|// 0x0c1 = 193 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0e7
block|,
comment|// 0x0c2 = 194 -
literal|0x095
block|,
comment|// 0x0c3 = 195 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0ec
block|,
comment|// 0x0c4 = 196 -
literal|0x099
block|,
comment|// 0x0c5 = 197 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0ef
block|,
comment|// 0x0c6 = 198 -
literal|0x09b
block|,
comment|// 0x0c7 = 199 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0f2
block|,
comment|// 0x0c8 = 200 -
literal|0x094
block|,
comment|// 0x0c9 = 201 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0ba
block|,
comment|// 0x0ca = 202 -
literal|0x093
block|,
comment|// 0x0cb = 203 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0f5
block|,
comment|// 0x0cc = 204 -
literal|0x09f
block|,
comment|// 0x0cd = 205 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x0f8
block|,
comment|// 0x0ce = 206 -
literal|0x09a
block|,
comment|// 0x0cf = 207 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x0ba
block|,
comment|// 0x0d0 = 208 -
literal|0x096
block|,
comment|// 0x0d1 = 209 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x0f5
block|,
comment|// 0x0d2 = 210 -
literal|0x097
block|,
comment|// 0x0d3 = 211 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x100
block|,
comment|// 0x0d4 = 212 -
literal|0x098
block|,
comment|// 0x0d5 = 213 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0ba
block|,
comment|// 0x0d6 = 214 -
literal|0x092
block|,
comment|// 0x0d7 = 215 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0ba
block|,
comment|// 0x0d8 = 216 -
literal|0x0a4
block|,
comment|// 0x0d9 = 217 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0e1
block|,
comment|// 0x0da = 218 -
literal|0x0be
block|,
comment|// 0x0db = 219 - JUMP_IF_PHY_READY
literal|0x0c1
block|,
comment|// 0x0dc = 220 -
literal|0x01b
block|,
comment|// 0x0dd = 221 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x0de = 222 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0df = 223 - JUMP
literal|0x001
block|,
comment|// 0x0e0 = 224 -
literal|0x0a0
block|,
comment|// 0x0e1 = 225 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e7
block|,
comment|// 0x0e2 = 226 -
literal|0x000
block|,
comment|// 0x0e3 = 227 - NO_OP
literal|0x000
block|,
comment|// 0x0e4 = 228 - NO_OP
literal|0x0ff
block|,
comment|// 0x0e5 = 229 - JUMP
literal|0x086
block|,
comment|// 0x0e6 = 230 -
literal|0x013
block|,
comment|// 0x0e7 = 231 - SET_OPEN_STATUS_NORMAL
literal|0x000
block|,
comment|// 0x0e8 = 232 - NO_OP
literal|0x000
block|,
comment|// 0x0e9 = 233 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ea = 234 - JUMP
literal|0x02b
block|,
comment|// 0x0eb = 235 -
literal|0x017
block|,
comment|// 0x0ec = 236 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x0ed = 237 - JUMP
literal|0x0fc
block|,
comment|// 0x0ee = 238 -
literal|0x018
block|,
comment|// 0x0ef = 239 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x0f0 = 240 - JUMP
literal|0x0fc
block|,
comment|// 0x0f1 = 241 -
literal|0x01a
block|,
comment|// 0x0f2 = 242 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x0f3 = 243 - JUMP
literal|0x0fc
block|,
comment|// 0x0f4 = 244 -
literal|0x015
block|,
comment|// 0x0f5 = 245 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x0f6 = 246 - JUMP
literal|0x0fc
block|,
comment|// 0x0f7 = 247 -
literal|0x014
block|,
comment|// 0x0f8 = 248 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x0f9 = 249 - JUMP
literal|0x0fc
block|,
comment|// 0x0fa = 250 -
literal|0x024
block|,
comment|// 0x0fb = 251 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0fc = 252 - NO_OP
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x0ff
block|,
comment|// 0x0fe = 254 - JUMP
literal|0x059
block|,
comment|// 0x0ff = 255 -
literal|0x010
block|,
comment|// 0x100 = 256 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x101 = 257 - JUMP
literal|0x0ba
block|,
comment|// 0x102 = 258 -
literal|0x000
block|,
comment|// 0x103 = 259 - NO_OP
literal|0x000
block|,
comment|// 0x104 = 260 - NO_OP
literal|0x000
block|,
comment|// 0x105 = 261 - NO_OP
literal|0x000
block|,
comment|// 0x106 = 262 - NO_OP
literal|0x000
block|,
comment|// 0x107 = 263 - NO_OP
literal|0x000
block|,
comment|// 0x108 = 264 - NO_OP
literal|0x000
block|,
comment|// 0x109 = 265 - NO_OP
literal|0x000
block|,
comment|// 0x10a = 266 - NO_OP
literal|0x000
block|,
comment|// 0x10b = 267 - NO_OP
literal|0x000
block|,
comment|// 0x10c = 268 - NO_OP
literal|0x000
block|,
comment|// 0x10d = 269 - NO_OP
literal|0x000
block|,
comment|// 0x10e = 270 - NO_OP
literal|0x000
block|,
comment|// 0x10f = 271 - NO_OP
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x000
block|,
comment|// 0x112 = 274 - NO_OP
literal|0x000
block|,
comment|// 0x113 = 275 - NO_OP
literal|0x000
block|,
comment|// 0x114 = 276 - NO_OP
literal|0x000
block|,
comment|// 0x115 = 277 - NO_OP
literal|0x000
block|,
comment|// 0x116 = 278 - NO_OP
literal|0x000
block|,
comment|// 0x117 = 279 - NO_OP
literal|0x000
block|,
comment|// 0x118 = 280 - NO_OP
literal|0x000
block|,
comment|// 0x119 = 281 - NO_OP
literal|0x000
block|,
comment|// 0x11a = 282 - NO_OP
literal|0x000
block|,
comment|// 0x11b = 283 - NO_OP
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x000
block|,
comment|// 0x120 = 288 - NO_OP
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x000
block|,
comment|// 0x125 = 293 - NO_OP
literal|0x000
block|,
comment|// 0x126 = 294 - NO_OP
literal|0x000
block|,
comment|// 0x127 = 295 - NO_OP
literal|0x000
block|,
comment|// 0x128 = 296 - NO_OP
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x000
block|,
comment|// 0x132 = 306 - NO_OP
literal|0x000
block|,
comment|// 0x133 = 307 - NO_OP
literal|0x000
block|,
comment|// 0x134 = 308 - NO_OP
literal|0x000
block|,
comment|// 0x135 = 309 - NO_OP
literal|0x000
block|,
comment|// 0x136 = 310 - NO_OP
literal|0x000
block|,
comment|// 0x137 = 311 - NO_OP
literal|0x000
block|,
comment|// 0x138 = 312 - NO_OP
literal|0x000
block|,
comment|// 0x139 = 313 - NO_OP
literal|0x000
block|,
comment|// 0x13a = 314 - NO_OP
literal|0x000
block|,
comment|// 0x13b = 315 - NO_OP
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x000
block|,
comment|// 0x140 = 320 - NO_OP
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x000
block|,
comment|// 0x146 = 326 - NO_OP
literal|0x000
block|,
comment|// 0x147 = 327 - NO_OP
literal|0x000
block|,
comment|// 0x148 = 328 - NO_OP
literal|0x000
block|,
comment|// 0x149 = 329 - NO_OP
literal|0x000
block|,
comment|// 0x14a = 330 - NO_OP
literal|0x000
block|,
comment|// 0x14b = 331 - NO_OP
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x000
block|,
comment|// 0x151 = 337 - NO_OP
literal|0x000
block|,
comment|// 0x152 = 338 - NO_OP
literal|0x000
block|,
comment|// 0x153 = 339 - NO_OP
literal|0x000
block|,
comment|// 0x154 = 340 - NO_OP
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x000
block|,
comment|// 0x15b = 347 - NO_OP
literal|0x000
block|,
comment|// 0x15c = 348 - NO_OP
literal|0x000
block|,
comment|// 0x15d = 349 - NO_OP
literal|0x000
block|,
comment|// 0x15e = 350 - NO_OP
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WCS 022406 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage022406
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ae
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0af
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x00c
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0af
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x01c
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0af
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x00c
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0be
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x00c
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x055
block|,
comment|// 0x02a = 42 -
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x0c9
block|,
comment|// 0x02c = 44 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x052
block|,
comment|// 0x02d = 45 -
literal|0x0a5
block|,
comment|// 0x02e = 46 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x041
block|,
comment|// 0x02f = 47 -
literal|0x0a6
block|,
comment|// 0x030 = 48 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x046
block|,
comment|// 0x031 = 49 -
literal|0x0a7
block|,
comment|// 0x032 = 50 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x049
block|,
comment|// 0x033 = 51 -
literal|0x0a8
block|,
comment|// 0x034 = 52 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x04f
block|,
comment|// 0x035 = 53 -
literal|0x0aa
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x04c
block|,
comment|// 0x037 = 55 -
literal|0x0c5
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x04f
block|,
comment|// 0x039 = 57 -
literal|0x0ca
block|,
comment|// 0x03a = 58 - JUMP_IF_CLOSE_REQ
literal|0x08a
block|,
comment|// 0x03b = 59 -
literal|0x0be
block|,
comment|// 0x03c = 60 - JUMP_IF_PHY_READY
literal|0x02c
block|,
comment|// 0x03d = 61 -
literal|0x01c
block|,
comment|// 0x03e = 62 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x03f = 63 - JUMP
literal|0x001
block|,
comment|// 0x040 = 64 -
literal|0x01d
block|,
comment|// 0x041 = 65 - ADVANCE
literal|0x0c3
block|,
comment|// 0x042 = 66 - JUMP_IF_SMP_PROTOCOL
literal|0x08a
block|,
comment|// 0x043 = 67 -
literal|0x0ff
block|,
comment|// 0x044 = 68 - JUMP
literal|0x055
block|,
comment|// 0x045 = 69 -
literal|0x01d
block|,
comment|// 0x046 = 70 - ADVANCE
literal|0x0ff
block|,
comment|// 0x047 = 71 - JUMP
literal|0x055
block|,
comment|// 0x048 = 72 -
literal|0x01d
block|,
comment|// 0x049 = 73 - ADVANCE
literal|0x0ff
block|,
comment|// 0x04a = 74 - JUMP
literal|0x0a9
block|,
comment|// 0x04b = 75 -
literal|0x01d
block|,
comment|// 0x04c = 76 - ADVANCE
literal|0x0ff
block|,
comment|// 0x04d = 77 - JUMP
literal|0x0ac
block|,
comment|// 0x04e = 78 -
literal|0x01d
block|,
comment|// 0x04f = 79 - ADVANCE
literal|0x0ff
block|,
comment|// 0x050 = 80 - JUMP
literal|0x09d
block|,
comment|// 0x051 = 81 -
literal|0x022
block|,
comment|// 0x052 = 82 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x053 = 83 - JUMP
literal|0x02e
block|,
comment|// 0x054 = 84 -
literal|0x0c8
block|,
comment|// 0x055 = 85 - JUMP_IF_HIP_REQ
literal|0x061
block|,
comment|// 0x056 = 86 -
literal|0x0c6
block|,
comment|// 0x057 = 87 - JUMP_IF_SFO_REQ
literal|0x066
block|,
comment|// 0x058 = 88 -
literal|0x0c7
block|,
comment|// 0x059 = 89 - JUMP_IF_DOC_REQ
literal|0x06b
block|,
comment|// 0x05a = 90 -
literal|0x0a3
block|,
comment|// 0x05b = 91 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x082
block|,
comment|// 0x05c = 92 -
literal|0x0a2
block|,
comment|// 0x05d = 93 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x08a
block|,
comment|// 0x05e = 94 -
literal|0x0ff
block|,
comment|// 0x05f = 95 - JUMP
literal|0x055
block|,
comment|// 0x060 = 96 -
literal|0x020
block|,
comment|// 0x061 = 97 - SELECT_HIP
literal|0x000
block|,
comment|// 0x062 = 98 - NO_OP
literal|0x000
block|,
comment|// 0x063 = 99 - NO_OP
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x06e
block|,
comment|// 0x065 = 101 -
literal|0x01e
block|,
comment|// 0x066 = 102 - SELECT_SFO
literal|0x000
block|,
comment|// 0x067 = 103 - NO_OP
literal|0x000
block|,
comment|// 0x068 = 104 - NO_OP
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x06e
block|,
comment|// 0x06a = 106 -
literal|0x01f
block|,
comment|// 0x06b = 107 - SELECT_DOC
literal|0x000
block|,
comment|// 0x06c = 108 - NO_OP
literal|0x000
block|,
comment|// 0x06d = 109 - NO_OP
literal|0x0a4
block|,
comment|// 0x06e = 110 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x072
block|,
comment|// 0x06f = 111 -
literal|0x0ff
block|,
comment|// 0x070 = 112 - JUMP
literal|0x0af
block|,
comment|// 0x071 = 113 -
literal|0x0a0
block|,
comment|// 0x072 = 114 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x078
block|,
comment|// 0x073 = 115 -
literal|0x0a3
block|,
comment|// 0x074 = 116 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x082
block|,
comment|// 0x075 = 117 -
literal|0x0ff
block|,
comment|// 0x076 = 118 - JUMP
literal|0x08a
block|,
comment|// 0x077 = 119 -
literal|0x0cb
block|,
comment|// 0x078 = 120 - JUMP_IF_FREEZE_ACTIVE
literal|0x07d
block|,
comment|// 0x079 = 121 -
literal|0x013
block|,
comment|// 0x07a = 122 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x07b = 123 - JUMP
literal|0x02b
block|,
comment|// 0x07c = 124 -
literal|0x024
block|,
comment|// 0x07d = 125 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x07e = 126 - NO_OP
literal|0x000
block|,
comment|// 0x07f = 127 - NO_OP
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x055
block|,
comment|// 0x081 = 129 -
literal|0x0c3
block|,
comment|// 0x082 = 130 - JUMP_IF_SMP_PROTOCOL
literal|0x086
block|,
comment|// 0x083 = 131 -
literal|0x0ff
block|,
comment|// 0x084 = 132 - JUMP
literal|0x08a
block|,
comment|// 0x085 = 133 -
literal|0x0c4
block|,
comment|// 0x086 = 134 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x09d
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x055
block|,
comment|// 0x089 = 137 -
literal|0x004
block|,
comment|// 0x08a = 138 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x08b = 139 - NO_OP
literal|0x000
block|,
comment|// 0x08c = 140 - NO_OP
literal|0x000
block|,
comment|// 0x08d = 141 - NO_OP
literal|0x000
block|,
comment|// 0x08e = 142 - NO_OP
literal|0x0c9
block|,
comment|// 0x08f = 143 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x09a
block|,
comment|// 0x090 = 144 -
literal|0x0c0
block|,
comment|// 0x091 = 145 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x055
block|,
comment|// 0x092 = 146 -
literal|0x0bc
block|,
comment|// 0x093 = 147 - JUMP_IF_BREAK_RECEIVED
literal|0x09d
block|,
comment|// 0x094 = 148 -
literal|0x0be
block|,
comment|// 0x095 = 149 - JUMP_IF_PHY_READY
literal|0x08b
block|,
comment|// 0x096 = 150 -
literal|0x01c
block|,
comment|// 0x097 = 151 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x098 = 152 - JUMP
literal|0x001
block|,
comment|// 0x099 = 153 -
literal|0x022
block|,
comment|// 0x09a = 154 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x09b = 155 - JUMP
literal|0x08b
block|,
comment|// 0x09c = 156 -
literal|0x007
block|,
comment|// 0x09d = 157 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x000
block|,
comment|// 0x09f = 159 - NO_OP
literal|0x000
block|,
comment|// 0x0a0 = 160 - NO_OP
literal|0x000
block|,
comment|// 0x0a1 = 161 - NO_OP
literal|0x0c0
block|,
comment|// 0x0a2 = 162 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x055
block|,
comment|// 0x0a3 = 163 -
literal|0x0be
block|,
comment|// 0x0a4 = 164 - JUMP_IF_PHY_READY
literal|0x09e
block|,
comment|// 0x0a5 = 165 -
literal|0x01c
block|,
comment|// 0x0a6 = 166 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0a7 = 167 - JUMP
literal|0x001
block|,
comment|// 0x0a8 = 168 -
literal|0x005
block|,
comment|// 0x0a9 = 169 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0aa = 170 - JUMP
literal|0x08b
block|,
comment|// 0x0ab = 171 -
literal|0x006
block|,
comment|// 0x0ac = 172 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0ad = 173 - JUMP
literal|0x08b
block|,
comment|// 0x0ae = 174 -
literal|0x0cc
block|,
comment|// 0x0af = 175 - JUMP_IF_RX_BUFFER_FULL
literal|0x055
block|,
comment|// 0x0b0 = 176 -
literal|0x0b7
block|,
comment|// 0x0b1 = 177 - JUMP_IF_FLAG_7_SET
literal|0x0b6
block|,
comment|// 0x0b2 = 178 -
literal|0x011
block|,
comment|// 0x0b3 = 179 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x0b4 = 180 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x0b5 = 181 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x0b6 = 182 - JUMP_IF_FREEZE_ACTIVE
literal|0x0f9
block|,
comment|// 0x0b7 = 183 -
literal|0x001
block|,
comment|// 0x0b8 = 184 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x0b9 = 185 - SET_FLAG
literal|0x080
block|,
comment|// 0x0ba = 186 -
literal|0x000
block|,
comment|// 0x0bb = 187 - NO_OP
literal|0x000
block|,
comment|// 0x0bc = 188 - NO_OP
literal|0x000
block|,
comment|// 0x0bd = 189 - NO_OP
literal|0x090
block|,
comment|// 0x0be = 190 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0e4
block|,
comment|// 0x0bf = 191 -
literal|0x095
block|,
comment|// 0x0c0 = 192 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0ea
block|,
comment|// 0x0c1 = 193 -
literal|0x099
block|,
comment|// 0x0c2 = 194 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0ed
block|,
comment|// 0x0c3 = 195 -
literal|0x09b
block|,
comment|// 0x0c4 = 196 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0f0
block|,
comment|// 0x0c5 = 197 -
literal|0x094
block|,
comment|// 0x0c6 = 198 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0b6
block|,
comment|// 0x0c7 = 199 -
literal|0x093
block|,
comment|// 0x0c8 = 200 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x0f3
block|,
comment|// 0x0c9 = 201 -
literal|0x09f
block|,
comment|// 0x0ca = 202 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x0f6
block|,
comment|// 0x0cb = 203 -
literal|0x09a
block|,
comment|// 0x0cc = 204 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x0b6
block|,
comment|// 0x0cd = 205 -
literal|0x096
block|,
comment|// 0x0ce = 206 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x0f3
block|,
comment|// 0x0cf = 207 -
literal|0x097
block|,
comment|// 0x0d0 = 208 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x0fe
block|,
comment|// 0x0d1 = 209 -
literal|0x098
block|,
comment|// 0x0d2 = 210 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0b6
block|,
comment|// 0x0d3 = 211 -
literal|0x092
block|,
comment|// 0x0d4 = 212 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0b6
block|,
comment|// 0x0d5 = 213 -
literal|0x0a4
block|,
comment|// 0x0d6 = 214 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0de
block|,
comment|// 0x0d7 = 215 -
literal|0x0be
block|,
comment|// 0x0d8 = 216 - JUMP_IF_PHY_READY
literal|0x0be
block|,
comment|// 0x0d9 = 217 -
literal|0x01b
block|,
comment|// 0x0da = 218 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x0db = 219 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0dc = 220 - JUMP
literal|0x001
block|,
comment|// 0x0dd = 221 -
literal|0x0a0
block|,
comment|// 0x0de = 222 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e4
block|,
comment|// 0x0df = 223 -
literal|0x000
block|,
comment|// 0x0e0 = 224 - NO_OP
literal|0x000
block|,
comment|// 0x0e1 = 225 - NO_OP
literal|0x0ff
block|,
comment|// 0x0e2 = 226 - JUMP
literal|0x082
block|,
comment|// 0x0e3 = 227 -
literal|0x013
block|,
comment|// 0x0e4 = 228 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x0e5 = 229 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x0e6 = 230 -
literal|0x000
block|,
comment|// 0x0e7 = 231 - NO_OP
literal|0x0ff
block|,
comment|// 0x0e8 = 232 - JUMP
literal|0x02b
block|,
comment|// 0x0e9 = 233 -
literal|0x017
block|,
comment|// 0x0ea = 234 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x0eb = 235 - JUMP
literal|0x0fa
block|,
comment|// 0x0ec = 236 -
literal|0x018
block|,
comment|// 0x0ed = 237 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x0ee = 238 - JUMP
literal|0x0fa
block|,
comment|// 0x0ef = 239 -
literal|0x01a
block|,
comment|// 0x0f0 = 240 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x0f1 = 241 - JUMP
literal|0x0fa
block|,
comment|// 0x0f2 = 242 -
literal|0x015
block|,
comment|// 0x0f3 = 243 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x0f4 = 244 - JUMP
literal|0x0fa
block|,
comment|// 0x0f5 = 245 -
literal|0x014
block|,
comment|// 0x0f6 = 246 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x0f7 = 247 - JUMP
literal|0x0fa
block|,
comment|// 0x0f8 = 248 -
literal|0x024
block|,
comment|// 0x0f9 = 249 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0fa = 250 - NO_OP
literal|0x000
block|,
comment|// 0x0fb = 251 - NO_OP
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x055
block|,
comment|// 0x0fd = 253 -
literal|0x010
block|,
comment|// 0x0fe = 254 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x0ff = 255 - JUMP
literal|0x0b6
block|,
comment|// 0x100 = 256 -
literal|0x000
block|,
comment|// 0x101 = 257 - NO_OP
literal|0x000
block|,
comment|// 0x102 = 258 - NO_OP
literal|0x000
block|,
comment|// 0x103 = 259 - NO_OP
literal|0x000
block|,
comment|// 0x104 = 260 - NO_OP
literal|0x000
block|,
comment|// 0x105 = 261 - NO_OP
literal|0x000
block|,
comment|// 0x106 = 262 - NO_OP
literal|0x000
block|,
comment|// 0x107 = 263 - NO_OP
literal|0x000
block|,
comment|// 0x108 = 264 - NO_OP
literal|0x000
block|,
comment|// 0x109 = 265 - NO_OP
literal|0x000
block|,
comment|// 0x10a = 266 - NO_OP
literal|0x000
block|,
comment|// 0x10b = 267 - NO_OP
literal|0x000
block|,
comment|// 0x10c = 268 - NO_OP
literal|0x000
block|,
comment|// 0x10d = 269 - NO_OP
literal|0x000
block|,
comment|// 0x10e = 270 - NO_OP
literal|0x000
block|,
comment|// 0x10f = 271 - NO_OP
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x000
block|,
comment|// 0x112 = 274 - NO_OP
literal|0x000
block|,
comment|// 0x113 = 275 - NO_OP
literal|0x000
block|,
comment|// 0x114 = 276 - NO_OP
literal|0x000
block|,
comment|// 0x115 = 277 - NO_OP
literal|0x000
block|,
comment|// 0x116 = 278 - NO_OP
literal|0x000
block|,
comment|// 0x117 = 279 - NO_OP
literal|0x000
block|,
comment|// 0x118 = 280 - NO_OP
literal|0x000
block|,
comment|// 0x119 = 281 - NO_OP
literal|0x000
block|,
comment|// 0x11a = 282 - NO_OP
literal|0x000
block|,
comment|// 0x11b = 283 - NO_OP
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x000
block|,
comment|// 0x120 = 288 - NO_OP
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x000
block|,
comment|// 0x125 = 293 - NO_OP
literal|0x000
block|,
comment|// 0x126 = 294 - NO_OP
literal|0x000
block|,
comment|// 0x127 = 295 - NO_OP
literal|0x000
block|,
comment|// 0x128 = 296 - NO_OP
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x000
block|,
comment|// 0x132 = 306 - NO_OP
literal|0x000
block|,
comment|// 0x133 = 307 - NO_OP
literal|0x000
block|,
comment|// 0x134 = 308 - NO_OP
literal|0x000
block|,
comment|// 0x135 = 309 - NO_OP
literal|0x000
block|,
comment|// 0x136 = 310 - NO_OP
literal|0x000
block|,
comment|// 0x137 = 311 - NO_OP
literal|0x000
block|,
comment|// 0x138 = 312 - NO_OP
literal|0x000
block|,
comment|// 0x139 = 313 - NO_OP
literal|0x000
block|,
comment|// 0x13a = 314 - NO_OP
literal|0x000
block|,
comment|// 0x13b = 315 - NO_OP
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x000
block|,
comment|// 0x140 = 320 - NO_OP
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x000
block|,
comment|// 0x146 = 326 - NO_OP
literal|0x000
block|,
comment|// 0x147 = 327 - NO_OP
literal|0x000
block|,
comment|// 0x148 = 328 - NO_OP
literal|0x000
block|,
comment|// 0x149 = 329 - NO_OP
literal|0x000
block|,
comment|// 0x14a = 330 - NO_OP
literal|0x000
block|,
comment|// 0x14b = 331 - NO_OP
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x000
block|,
comment|// 0x151 = 337 - NO_OP
literal|0x000
block|,
comment|// 0x152 = 338 - NO_OP
literal|0x000
block|,
comment|// 0x153 = 339 - NO_OP
literal|0x000
block|,
comment|// 0x154 = 340 - NO_OP
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x000
block|,
comment|// 0x15b = 347 - NO_OP
literal|0x000
block|,
comment|// 0x15c = 348 - NO_OP
literal|0x000
block|,
comment|// 0x15d = 349 - NO_OP
literal|0x000
block|,
comment|// 0x15e = 350 - NO_OP
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WCS 031606 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage031606
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ae
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0af
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x00c
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0af
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x01c
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0af
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x00c
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0be
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x00c
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x05b
block|,
comment|// 0x02a = 42 -
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x0c9
block|,
comment|// 0x02c = 44 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x058
block|,
comment|// 0x02d = 45 -
literal|0x0a5
block|,
comment|// 0x02e = 46 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x041
block|,
comment|// 0x02f = 47 -
literal|0x0a6
block|,
comment|// 0x030 = 48 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x048
block|,
comment|// 0x031 = 49 -
literal|0x0a7
block|,
comment|// 0x032 = 50 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x04b
block|,
comment|// 0x033 = 51 -
literal|0x0a8
block|,
comment|// 0x034 = 52 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x055
block|,
comment|// 0x035 = 53 -
literal|0x0aa
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x050
block|,
comment|// 0x037 = 55 -
literal|0x0c5
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x055
block|,
comment|// 0x039 = 57 -
literal|0x0ca
block|,
comment|// 0x03a = 58 - JUMP_IF_CLOSE_REQ
literal|0x09c
block|,
comment|// 0x03b = 59 -
literal|0x0be
block|,
comment|// 0x03c = 60 - JUMP_IF_PHY_READY
literal|0x02c
block|,
comment|// 0x03d = 61 -
literal|0x01c
block|,
comment|// 0x03e = 62 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x03f = 63 - JUMP
literal|0x001
block|,
comment|// 0x040 = 64 -
literal|0x01d
block|,
comment|// 0x041 = 65 - ADVANCE
literal|0x0bc
block|,
comment|// 0x042 = 66 - JUMP_IF_BREAK_RECEIVED
literal|0x0af
block|,
comment|// 0x043 = 67 -
literal|0x0c3
block|,
comment|// 0x044 = 68 - JUMP_IF_SMP_PROTOCOL
literal|0x09c
block|,
comment|// 0x045 = 69 -
literal|0x0ff
block|,
comment|// 0x046 = 70 - JUMP
literal|0x05b
block|,
comment|// 0x047 = 71 -
literal|0x01d
block|,
comment|// 0x048 = 72 - ADVANCE
literal|0x0ff
block|,
comment|// 0x049 = 73 - JUMP
literal|0x05b
block|,
comment|// 0x04a = 74 -
literal|0x01d
block|,
comment|// 0x04b = 75 - ADVANCE
literal|0x0bc
block|,
comment|// 0x04c = 76 - JUMP_IF_BREAK_RECEIVED
literal|0x0af
block|,
comment|// 0x04d = 77 -
literal|0x0ff
block|,
comment|// 0x04e = 78 - JUMP
literal|0x0bb
block|,
comment|// 0x04f = 79 -
literal|0x01d
block|,
comment|// 0x050 = 80 - ADVANCE
literal|0x0bc
block|,
comment|// 0x051 = 81 - JUMP_IF_BREAK_RECEIVED
literal|0x0af
block|,
comment|// 0x052 = 82 -
literal|0x0ff
block|,
comment|// 0x053 = 83 - JUMP
literal|0x0be
block|,
comment|// 0x054 = 84 -
literal|0x01d
block|,
comment|// 0x055 = 85 - ADVANCE
literal|0x0ff
block|,
comment|// 0x056 = 86 - JUMP
literal|0x0af
block|,
comment|// 0x057 = 87 -
literal|0x022
block|,
comment|// 0x058 = 88 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x059 = 89 - JUMP
literal|0x02e
block|,
comment|// 0x05a = 90 -
literal|0x0bc
block|,
comment|// 0x05b = 91 - JUMP_IF_BREAK_RECEIVED
literal|0x0af
block|,
comment|// 0x05c = 92 -
literal|0x0c8
block|,
comment|// 0x05d = 93 - JUMP_IF_HIP_REQ
literal|0x069
block|,
comment|// 0x05e = 94 -
literal|0x0c6
block|,
comment|// 0x05f = 95 - JUMP_IF_SFO_REQ
literal|0x06e
block|,
comment|// 0x060 = 96 -
literal|0x0c7
block|,
comment|// 0x061 = 97 - JUMP_IF_DOC_REQ
literal|0x073
block|,
comment|// 0x062 = 98 -
literal|0x0a3
block|,
comment|// 0x063 = 99 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x08a
block|,
comment|// 0x064 = 100 -
literal|0x0a2
block|,
comment|// 0x065 = 101 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x09c
block|,
comment|// 0x066 = 102 -
literal|0x0ff
block|,
comment|// 0x067 = 103 - JUMP
literal|0x05b
block|,
comment|// 0x068 = 104 -
literal|0x020
block|,
comment|// 0x069 = 105 - SELECT_HIP
literal|0x000
block|,
comment|// 0x06a = 106 - NO_OP
literal|0x000
block|,
comment|// 0x06b = 107 - NO_OP
literal|0x0ff
block|,
comment|// 0x06c = 108 - JUMP
literal|0x076
block|,
comment|// 0x06d = 109 -
literal|0x01e
block|,
comment|// 0x06e = 110 - SELECT_SFO
literal|0x000
block|,
comment|// 0x06f = 111 - NO_OP
literal|0x000
block|,
comment|// 0x070 = 112 - NO_OP
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x076
block|,
comment|// 0x072 = 114 -
literal|0x01f
block|,
comment|// 0x073 = 115 - SELECT_DOC
literal|0x000
block|,
comment|// 0x074 = 116 - NO_OP
literal|0x000
block|,
comment|// 0x075 = 117 - NO_OP
literal|0x0a4
block|,
comment|// 0x076 = 118 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x07a
block|,
comment|// 0x077 = 119 -
literal|0x0ff
block|,
comment|// 0x078 = 120 - JUMP
literal|0x0c1
block|,
comment|// 0x079 = 121 -
literal|0x0a0
block|,
comment|// 0x07a = 122 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x080
block|,
comment|// 0x07b = 123 -
literal|0x0a3
block|,
comment|// 0x07c = 124 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x08a
block|,
comment|// 0x07d = 125 -
literal|0x0ff
block|,
comment|// 0x07e = 126 - JUMP
literal|0x09c
block|,
comment|// 0x07f = 127 -
literal|0x0cb
block|,
comment|// 0x080 = 128 - JUMP_IF_FREEZE_ACTIVE
literal|0x085
block|,
comment|// 0x081 = 129 -
literal|0x013
block|,
comment|// 0x082 = 130 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x083 = 131 - JUMP
literal|0x02b
block|,
comment|// 0x084 = 132 -
literal|0x024
block|,
comment|// 0x085 = 133 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x086 = 134 - NO_OP
literal|0x000
block|,
comment|// 0x087 = 135 - NO_OP
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x05b
block|,
comment|// 0x089 = 137 -
literal|0x0c3
block|,
comment|// 0x08a = 138 - JUMP_IF_SMP_PROTOCOL
literal|0x092
block|,
comment|// 0x08b = 139 -
literal|0x0d2
block|,
comment|// 0x08c = 140 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x096
block|,
comment|// 0x08d = 141 -
literal|0x0d1
block|,
comment|// 0x08e = 142 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x09a
block|,
comment|// 0x08f = 143 -
literal|0x0ff
block|,
comment|// 0x090 = 144 - JUMP
literal|0x05b
block|,
comment|// 0x091 = 145 -
literal|0x0c4
block|,
comment|// 0x092 = 146 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x0af
block|,
comment|// 0x093 = 147 -
literal|0x0ff
block|,
comment|// 0x094 = 148 - JUMP
literal|0x05b
block|,
comment|// 0x095 = 149 -
literal|0x0d1
block|,
comment|// 0x096 = 150 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x09a
block|,
comment|// 0x097 = 151 -
literal|0x0ff
block|,
comment|// 0x098 = 152 - JUMP
literal|0x05b
block|,
comment|// 0x099 = 153 -
literal|0x0ff
block|,
comment|// 0x09a = 154 - JUMP
literal|0x09c
block|,
comment|// 0x09b = 155 -
literal|0x004
block|,
comment|// 0x09c = 156 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x09d = 157 - NO_OP
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x000
block|,
comment|// 0x09f = 159 - NO_OP
literal|0x000
block|,
comment|// 0x0a0 = 160 - NO_OP
literal|0x0c9
block|,
comment|// 0x0a1 = 161 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x0ac
block|,
comment|// 0x0a2 = 162 -
literal|0x0c0
block|,
comment|// 0x0a3 = 163 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x05b
block|,
comment|// 0x0a4 = 164 -
literal|0x0bc
block|,
comment|// 0x0a5 = 165 - JUMP_IF_BREAK_RECEIVED
literal|0x0af
block|,
comment|// 0x0a6 = 166 -
literal|0x0be
block|,
comment|// 0x0a7 = 167 - JUMP_IF_PHY_READY
literal|0x09d
block|,
comment|// 0x0a8 = 168 -
literal|0x01c
block|,
comment|// 0x0a9 = 169 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0aa = 170 - JUMP
literal|0x001
block|,
comment|// 0x0ab = 171 -
literal|0x022
block|,
comment|// 0x0ac = 172 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x0ad = 173 - JUMP
literal|0x09d
block|,
comment|// 0x0ae = 174 -
literal|0x007
block|,
comment|// 0x0af = 175 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x0b0 = 176 - NO_OP
literal|0x000
block|,
comment|// 0x0b1 = 177 - NO_OP
literal|0x000
block|,
comment|// 0x0b2 = 178 - NO_OP
literal|0x000
block|,
comment|// 0x0b3 = 179 - NO_OP
literal|0x0c0
block|,
comment|// 0x0b4 = 180 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x05b
block|,
comment|// 0x0b5 = 181 -
literal|0x0be
block|,
comment|// 0x0b6 = 182 - JUMP_IF_PHY_READY
literal|0x0b0
block|,
comment|// 0x0b7 = 183 -
literal|0x01c
block|,
comment|// 0x0b8 = 184 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0b9 = 185 - JUMP
literal|0x001
block|,
comment|// 0x0ba = 186 -
literal|0x005
block|,
comment|// 0x0bb = 187 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0bc = 188 - JUMP
literal|0x09d
block|,
comment|// 0x0bd = 189 -
literal|0x006
block|,
comment|// 0x0be = 190 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0bf = 191 - JUMP
literal|0x09d
block|,
comment|// 0x0c0 = 192 -
literal|0x0cc
block|,
comment|// 0x0c1 = 193 - JUMP_IF_RX_BUFFER_FULL
literal|0x05b
block|,
comment|// 0x0c2 = 194 -
literal|0x0b7
block|,
comment|// 0x0c3 = 195 - JUMP_IF_FLAG_7_SET
literal|0x0c8
block|,
comment|// 0x0c4 = 196 -
literal|0x011
block|,
comment|// 0x0c5 = 197 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x0c6 = 198 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x0c7 = 199 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x0c8 = 200 - JUMP_IF_FREEZE_ACTIVE
literal|0x107
block|,
comment|// 0x0c9 = 201 -
literal|0x001
block|,
comment|// 0x0ca = 202 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x0cb = 203 - SET_FLAG
literal|0x080
block|,
comment|// 0x0cc = 204 -
literal|0x090
block|,
comment|// 0x0cd = 205 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0f3
block|,
comment|// 0x0ce = 206 -
literal|0x095
block|,
comment|// 0x0cf = 207 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x0f8
block|,
comment|// 0x0d0 = 208 -
literal|0x099
block|,
comment|// 0x0d1 = 209 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x0fb
block|,
comment|// 0x0d2 = 210 -
literal|0x09b
block|,
comment|// 0x0d3 = 211 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x0fe
block|,
comment|// 0x0d4 = 212 -
literal|0x094
block|,
comment|// 0x0d5 = 213 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0c8
block|,
comment|// 0x0d6 = 214 -
literal|0x093
block|,
comment|// 0x0d7 = 215 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x101
block|,
comment|// 0x0d8 = 216 -
literal|0x09f
block|,
comment|// 0x0d9 = 217 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x104
block|,
comment|// 0x0da = 218 -
literal|0x09a
block|,
comment|// 0x0db = 219 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x0c8
block|,
comment|// 0x0dc = 220 -
literal|0x096
block|,
comment|// 0x0dd = 221 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x101
block|,
comment|// 0x0de = 222 -
literal|0x097
block|,
comment|// 0x0df = 223 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x10c
block|,
comment|// 0x0e0 = 224 -
literal|0x098
block|,
comment|// 0x0e1 = 225 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0c8
block|,
comment|// 0x0e2 = 226 -
literal|0x092
block|,
comment|// 0x0e3 = 227 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0c8
block|,
comment|// 0x0e4 = 228 -
literal|0x0a4
block|,
comment|// 0x0e5 = 229 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0ed
block|,
comment|// 0x0e6 = 230 -
literal|0x0be
block|,
comment|// 0x0e7 = 231 - JUMP_IF_PHY_READY
literal|0x0cd
block|,
comment|// 0x0e8 = 232 -
literal|0x01b
block|,
comment|// 0x0e9 = 233 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x0ea = 234 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0eb = 235 - JUMP
literal|0x001
block|,
comment|// 0x0ec = 236 -
literal|0x0a0
block|,
comment|// 0x0ed = 237 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0f3
block|,
comment|// 0x0ee = 238 -
literal|0x000
block|,
comment|// 0x0ef = 239 - NO_OP
literal|0x000
block|,
comment|// 0x0f0 = 240 - NO_OP
literal|0x0ff
block|,
comment|// 0x0f1 = 241 - JUMP
literal|0x05b
block|,
comment|// 0x0f2 = 242 -
literal|0x013
block|,
comment|// 0x0f3 = 243 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x0f4 = 244 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x0f5 = 245 -
literal|0x0ff
block|,
comment|// 0x0f6 = 246 - JUMP
literal|0x02b
block|,
comment|// 0x0f7 = 247 -
literal|0x017
block|,
comment|// 0x0f8 = 248 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x0f9 = 249 - JUMP
literal|0x108
block|,
comment|// 0x0fa = 250 -
literal|0x018
block|,
comment|// 0x0fb = 251 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x108
block|,
comment|// 0x0fd = 253 -
literal|0x01a
block|,
comment|// 0x0fe = 254 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x0ff = 255 - JUMP
literal|0x108
block|,
comment|// 0x100 = 256 -
literal|0x015
block|,
comment|// 0x101 = 257 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x102 = 258 - JUMP
literal|0x108
block|,
comment|// 0x103 = 259 -
literal|0x014
block|,
comment|// 0x104 = 260 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x108
block|,
comment|// 0x106 = 262 -
literal|0x024
block|,
comment|// 0x107 = 263 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x108 = 264 - NO_OP
literal|0x000
block|,
comment|// 0x109 = 265 - NO_OP
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x05b
block|,
comment|// 0x10b = 267 -
literal|0x010
block|,
comment|// 0x10c = 268 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x0c8
block|,
comment|// 0x10e = 270 -
literal|0x000
block|,
comment|// 0x10f = 271 - NO_OP
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x000
block|,
comment|// 0x112 = 274 - NO_OP
literal|0x000
block|,
comment|// 0x113 = 275 - NO_OP
literal|0x000
block|,
comment|// 0x114 = 276 - NO_OP
literal|0x000
block|,
comment|// 0x115 = 277 - NO_OP
literal|0x000
block|,
comment|// 0x116 = 278 - NO_OP
literal|0x000
block|,
comment|// 0x117 = 279 - NO_OP
literal|0x000
block|,
comment|// 0x118 = 280 - NO_OP
literal|0x000
block|,
comment|// 0x119 = 281 - NO_OP
literal|0x000
block|,
comment|// 0x11a = 282 - NO_OP
literal|0x000
block|,
comment|// 0x11b = 283 - NO_OP
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x000
block|,
comment|// 0x120 = 288 - NO_OP
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x000
block|,
comment|// 0x125 = 293 - NO_OP
literal|0x000
block|,
comment|// 0x126 = 294 - NO_OP
literal|0x000
block|,
comment|// 0x127 = 295 - NO_OP
literal|0x000
block|,
comment|// 0x128 = 296 - NO_OP
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x000
block|,
comment|// 0x132 = 306 - NO_OP
literal|0x000
block|,
comment|// 0x133 = 307 - NO_OP
literal|0x000
block|,
comment|// 0x134 = 308 - NO_OP
literal|0x000
block|,
comment|// 0x135 = 309 - NO_OP
literal|0x000
block|,
comment|// 0x136 = 310 - NO_OP
literal|0x000
block|,
comment|// 0x137 = 311 - NO_OP
literal|0x000
block|,
comment|// 0x138 = 312 - NO_OP
literal|0x000
block|,
comment|// 0x139 = 313 - NO_OP
literal|0x000
block|,
comment|// 0x13a = 314 - NO_OP
literal|0x000
block|,
comment|// 0x13b = 315 - NO_OP
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x000
block|,
comment|// 0x140 = 320 - NO_OP
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x000
block|,
comment|// 0x146 = 326 - NO_OP
literal|0x000
block|,
comment|// 0x147 = 327 - NO_OP
literal|0x000
block|,
comment|// 0x148 = 328 - NO_OP
literal|0x000
block|,
comment|// 0x149 = 329 - NO_OP
literal|0x000
block|,
comment|// 0x14a = 330 - NO_OP
literal|0x000
block|,
comment|// 0x14b = 331 - NO_OP
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x000
block|,
comment|// 0x151 = 337 - NO_OP
literal|0x000
block|,
comment|// 0x152 = 338 - NO_OP
literal|0x000
block|,
comment|// 0x153 = 339 - NO_OP
literal|0x000
block|,
comment|// 0x154 = 340 - NO_OP
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x000
block|,
comment|// 0x15b = 347 - NO_OP
literal|0x000
block|,
comment|// 0x15c = 348 - NO_OP
literal|0x000
block|,
comment|// 0x15d = 349 - NO_OP
literal|0x000
block|,
comment|// 0x15e = 350 - NO_OP
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WCS 032006 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage032006
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x001 = 1 - JUMP_IF_PHY_READY
literal|0x009
block|,
comment|// 0x002 = 2 -
literal|0x0ae
block|,
comment|// 0x003 = 3 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x004 = 4 -
literal|0x0af
block|,
comment|// 0x005 = 5 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01e
block|,
comment|// 0x006 = 6 -
literal|0x0ff
block|,
comment|// 0x007 = 7 - JUMP
literal|0x001
block|,
comment|// 0x008 = 8 -
literal|0x00c
block|,
comment|// 0x009 = 9 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00a = 10 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x010
block|,
comment|// 0x00b = 11 -
literal|0x0af
block|,
comment|// 0x00c = 12 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x00d = 13 -
literal|0x0ff
block|,
comment|// 0x00e = 14 - JUMP
literal|0x00a
block|,
comment|// 0x00f = 15 -
literal|0x01c
block|,
comment|// 0x010 = 16 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x011 = 17 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x012 = 18 - JUMP_IF_PHY_READY
literal|0x016
block|,
comment|// 0x013 = 19 -
literal|0x0af
block|,
comment|// 0x014 = 20 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01b
block|,
comment|// 0x015 = 21 -
literal|0x00c
block|,
comment|// 0x016 = 22 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x017 = 23 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x01c = 28 - JUMP
literal|0x023
block|,
comment|// 0x01d = 29 -
literal|0x0be
block|,
comment|// 0x01e = 30 - JUMP_IF_PHY_READY
literal|0x022
block|,
comment|// 0x01f = 31 -
literal|0x0ff
block|,
comment|// 0x020 = 32 - JUMP
literal|0x01e
block|,
comment|// 0x021 = 33 -
literal|0x00c
block|,
comment|// 0x022 = 34 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x023 = 35 - NO_OP
literal|0x000
block|,
comment|// 0x024 = 36 - NO_OP
literal|0x000
block|,
comment|// 0x025 = 37 - NO_OP
literal|0x000
block|,
comment|// 0x026 = 38 - NO_OP
literal|0x000
block|,
comment|// 0x027 = 39 - NO_OP
literal|0x000
block|,
comment|// 0x028 = 40 - NO_OP
literal|0x0ff
block|,
comment|// 0x029 = 41 - JUMP
literal|0x063
block|,
comment|// 0x02a = 42 -
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x0c9
block|,
comment|// 0x02c = 44 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x058
block|,
comment|// 0x02d = 45 -
literal|0x0a5
block|,
comment|// 0x02e = 46 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x041
block|,
comment|// 0x02f = 47 -
literal|0x0a6
block|,
comment|// 0x030 = 48 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x048
block|,
comment|// 0x031 = 49 -
literal|0x0a7
block|,
comment|// 0x032 = 50 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x04b
block|,
comment|// 0x033 = 51 -
literal|0x0a8
block|,
comment|// 0x034 = 52 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x055
block|,
comment|// 0x035 = 53 -
literal|0x0aa
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x050
block|,
comment|// 0x037 = 55 -
literal|0x0c5
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x055
block|,
comment|// 0x039 = 57 -
literal|0x0ca
block|,
comment|// 0x03a = 58 - JUMP_IF_CLOSE_REQ
literal|0x0a4
block|,
comment|// 0x03b = 59 -
literal|0x0be
block|,
comment|// 0x03c = 60 - JUMP_IF_PHY_READY
literal|0x02c
block|,
comment|// 0x03d = 61 -
literal|0x01c
block|,
comment|// 0x03e = 62 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x03f = 63 - JUMP
literal|0x001
block|,
comment|// 0x040 = 64 -
literal|0x01d
block|,
comment|// 0x041 = 65 - ADVANCE
literal|0x0bc
block|,
comment|// 0x042 = 66 - JUMP_IF_BREAK_RECEIVED
literal|0x0b7
block|,
comment|// 0x043 = 67 -
literal|0x0c3
block|,
comment|// 0x044 = 68 - JUMP_IF_SMP_PROTOCOL
literal|0x0a4
block|,
comment|// 0x045 = 69 -
literal|0x0ff
block|,
comment|// 0x046 = 70 - JUMP
literal|0x05b
block|,
comment|// 0x047 = 71 -
literal|0x01d
block|,
comment|// 0x048 = 72 - ADVANCE
literal|0x0ff
block|,
comment|// 0x049 = 73 - JUMP
literal|0x05b
block|,
comment|// 0x04a = 74 -
literal|0x01d
block|,
comment|// 0x04b = 75 - ADVANCE
literal|0x0bc
block|,
comment|// 0x04c = 76 - JUMP_IF_BREAK_RECEIVED
literal|0x0b7
block|,
comment|// 0x04d = 77 -
literal|0x0ff
block|,
comment|// 0x04e = 78 - JUMP
literal|0x0c3
block|,
comment|// 0x04f = 79 -
literal|0x01d
block|,
comment|// 0x050 = 80 - ADVANCE
literal|0x0bc
block|,
comment|// 0x051 = 81 - JUMP_IF_BREAK_RECEIVED
literal|0x0b7
block|,
comment|// 0x052 = 82 -
literal|0x0ff
block|,
comment|// 0x053 = 83 - JUMP
literal|0x0c6
block|,
comment|// 0x054 = 84 -
literal|0x01d
block|,
comment|// 0x055 = 85 - ADVANCE
literal|0x0ff
block|,
comment|// 0x056 = 86 - JUMP
literal|0x0b7
block|,
comment|// 0x057 = 87 -
literal|0x022
block|,
comment|// 0x058 = 88 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x059 = 89 - JUMP
literal|0x02e
block|,
comment|// 0x05a = 90 -
literal|0x083
block|,
comment|// 0x05b = 91 - TIMER_START
literal|0x002
block|,
comment|// 0x05c = 92 -
literal|0x000
block|,
comment|// 0x05d = 93 - NO_OP
literal|0x000
block|,
comment|// 0x05e = 94 - NO_OP
literal|0x0b8
block|,
comment|// 0x05f = 95 - JUMP_IF_TIMER_EXPIRED
literal|0x063
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x05d
block|,
comment|// 0x062 = 98 -
literal|0x0bc
block|,
comment|// 0x063 = 99 - JUMP_IF_BREAK_RECEIVED
literal|0x0b7
block|,
comment|// 0x064 = 100 -
literal|0x0c8
block|,
comment|// 0x065 = 101 - JUMP_IF_HIP_REQ
literal|0x071
block|,
comment|// 0x066 = 102 -
literal|0x0c6
block|,
comment|// 0x067 = 103 - JUMP_IF_SFO_REQ
literal|0x076
block|,
comment|// 0x068 = 104 -
literal|0x0c7
block|,
comment|// 0x069 = 105 - JUMP_IF_DOC_REQ
literal|0x07b
block|,
comment|// 0x06a = 106 -
literal|0x0a3
block|,
comment|// 0x06b = 107 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x092
block|,
comment|// 0x06c = 108 -
literal|0x0a2
block|,
comment|// 0x06d = 109 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0a4
block|,
comment|// 0x06e = 110 -
literal|0x0ff
block|,
comment|// 0x06f = 111 - JUMP
literal|0x063
block|,
comment|// 0x070 = 112 -
literal|0x020
block|,
comment|// 0x071 = 113 - SELECT_HIP
literal|0x000
block|,
comment|// 0x072 = 114 - NO_OP
literal|0x000
block|,
comment|// 0x073 = 115 - NO_OP
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x07e
block|,
comment|// 0x075 = 117 -
literal|0x01e
block|,
comment|// 0x076 = 118 - SELECT_SFO
literal|0x000
block|,
comment|// 0x077 = 119 - NO_OP
literal|0x000
block|,
comment|// 0x078 = 120 - NO_OP
literal|0x0ff
block|,
comment|// 0x079 = 121 - JUMP
literal|0x07e
block|,
comment|// 0x07a = 122 -
literal|0x01f
block|,
comment|// 0x07b = 123 - SELECT_DOC
literal|0x000
block|,
comment|// 0x07c = 124 - NO_OP
literal|0x000
block|,
comment|// 0x07d = 125 - NO_OP
literal|0x0a4
block|,
comment|// 0x07e = 126 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x082
block|,
comment|// 0x07f = 127 -
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x0c9
block|,
comment|// 0x081 = 129 -
literal|0x0a0
block|,
comment|// 0x082 = 130 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x088
block|,
comment|// 0x083 = 131 -
literal|0x0a3
block|,
comment|// 0x084 = 132 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x092
block|,
comment|// 0x085 = 133 -
literal|0x0ff
block|,
comment|// 0x086 = 134 - JUMP
literal|0x0a4
block|,
comment|// 0x087 = 135 -
literal|0x0cb
block|,
comment|// 0x088 = 136 - JUMP_IF_FREEZE_ACTIVE
literal|0x08d
block|,
comment|// 0x089 = 137 -
literal|0x013
block|,
comment|// 0x08a = 138 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x08b = 139 - JUMP
literal|0x02b
block|,
comment|// 0x08c = 140 -
literal|0x024
block|,
comment|// 0x08d = 141 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x08e = 142 - NO_OP
literal|0x000
block|,
comment|// 0x08f = 143 - NO_OP
literal|0x0ff
block|,
comment|// 0x090 = 144 - JUMP
literal|0x063
block|,
comment|// 0x091 = 145 -
literal|0x0c3
block|,
comment|// 0x092 = 146 - JUMP_IF_SMP_PROTOCOL
literal|0x09a
block|,
comment|// 0x093 = 147 -
literal|0x0d2
block|,
comment|// 0x094 = 148 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x09e
block|,
comment|// 0x095 = 149 -
literal|0x0d1
block|,
comment|// 0x096 = 150 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x0a2
block|,
comment|// 0x097 = 151 -
literal|0x0ff
block|,
comment|// 0x098 = 152 - JUMP
literal|0x063
block|,
comment|// 0x099 = 153 -
literal|0x0c4
block|,
comment|// 0x09a = 154 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x0b7
block|,
comment|// 0x09b = 155 -
literal|0x0ff
block|,
comment|// 0x09c = 156 - JUMP
literal|0x063
block|,
comment|// 0x09d = 157 -
literal|0x0d1
block|,
comment|// 0x09e = 158 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x0a2
block|,
comment|// 0x09f = 159 -
literal|0x0ff
block|,
comment|// 0x0a0 = 160 - JUMP
literal|0x063
block|,
comment|// 0x0a1 = 161 -
literal|0x0ff
block|,
comment|// 0x0a2 = 162 - JUMP
literal|0x0a4
block|,
comment|// 0x0a3 = 163 -
literal|0x004
block|,
comment|// 0x0a4 = 164 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x0a5 = 165 - NO_OP
literal|0x000
block|,
comment|// 0x0a6 = 166 - NO_OP
literal|0x000
block|,
comment|// 0x0a7 = 167 - NO_OP
literal|0x000
block|,
comment|// 0x0a8 = 168 - NO_OP
literal|0x0c9
block|,
comment|// 0x0a9 = 169 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x0b4
block|,
comment|// 0x0aa = 170 -
literal|0x0c0
block|,
comment|// 0x0ab = 171 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x063
block|,
comment|// 0x0ac = 172 -
literal|0x0bc
block|,
comment|// 0x0ad = 173 - JUMP_IF_BREAK_RECEIVED
literal|0x0b7
block|,
comment|// 0x0ae = 174 -
literal|0x0be
block|,
comment|// 0x0af = 175 - JUMP_IF_PHY_READY
literal|0x0a5
block|,
comment|// 0x0b0 = 176 -
literal|0x01c
block|,
comment|// 0x0b1 = 177 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0b2 = 178 - JUMP
literal|0x001
block|,
comment|// 0x0b3 = 179 -
literal|0x022
block|,
comment|// 0x0b4 = 180 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x0b5 = 181 - JUMP
literal|0x0a5
block|,
comment|// 0x0b6 = 182 -
literal|0x007
block|,
comment|// 0x0b7 = 183 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x000
block|,
comment|// 0x0b9 = 185 - NO_OP
literal|0x000
block|,
comment|// 0x0ba = 186 - NO_OP
literal|0x000
block|,
comment|// 0x0bb = 187 - NO_OP
literal|0x0c0
block|,
comment|// 0x0bc = 188 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x063
block|,
comment|// 0x0bd = 189 -
literal|0x0be
block|,
comment|// 0x0be = 190 - JUMP_IF_PHY_READY
literal|0x0b8
block|,
comment|// 0x0bf = 191 -
literal|0x01c
block|,
comment|// 0x0c0 = 192 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0c1 = 193 - JUMP
literal|0x001
block|,
comment|// 0x0c2 = 194 -
literal|0x005
block|,
comment|// 0x0c3 = 195 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0c4 = 196 - JUMP
literal|0x0a5
block|,
comment|// 0x0c5 = 197 -
literal|0x006
block|,
comment|// 0x0c6 = 198 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x0c7 = 199 - JUMP
literal|0x0a5
block|,
comment|// 0x0c8 = 200 -
literal|0x0cc
block|,
comment|// 0x0c9 = 201 - JUMP_IF_RX_BUFFER_FULL
literal|0x063
block|,
comment|// 0x0ca = 202 -
literal|0x0b7
block|,
comment|// 0x0cb = 203 - JUMP_IF_FLAG_7_SET
literal|0x0d0
block|,
comment|// 0x0cc = 204 -
literal|0x011
block|,
comment|// 0x0cd = 205 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x0ce = 206 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x0cf = 207 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x0d0 = 208 - JUMP_IF_FREEZE_ACTIVE
literal|0x10f
block|,
comment|// 0x0d1 = 209 -
literal|0x001
block|,
comment|// 0x0d2 = 210 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x0d3 = 211 - SET_FLAG
literal|0x080
block|,
comment|// 0x0d4 = 212 -
literal|0x090
block|,
comment|// 0x0d5 = 213 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x0fb
block|,
comment|// 0x0d6 = 214 -
literal|0x095
block|,
comment|// 0x0d7 = 215 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x100
block|,
comment|// 0x0d8 = 216 -
literal|0x099
block|,
comment|// 0x0d9 = 217 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x103
block|,
comment|// 0x0da = 218 -
literal|0x09b
block|,
comment|// 0x0db = 219 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x106
block|,
comment|// 0x0dc = 220 -
literal|0x094
block|,
comment|// 0x0dd = 221 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x0d0
block|,
comment|// 0x0de = 222 -
literal|0x093
block|,
comment|// 0x0df = 223 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x109
block|,
comment|// 0x0e0 = 224 -
literal|0x09f
block|,
comment|// 0x0e1 = 225 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x10c
block|,
comment|// 0x0e2 = 226 -
literal|0x09a
block|,
comment|// 0x0e3 = 227 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x0d0
block|,
comment|// 0x0e4 = 228 -
literal|0x096
block|,
comment|// 0x0e5 = 229 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x109
block|,
comment|// 0x0e6 = 230 -
literal|0x097
block|,
comment|// 0x0e7 = 231 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x114
block|,
comment|// 0x0e8 = 232 -
literal|0x098
block|,
comment|// 0x0e9 = 233 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x0d0
block|,
comment|// 0x0ea = 234 -
literal|0x092
block|,
comment|// 0x0eb = 235 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x0d0
block|,
comment|// 0x0ec = 236 -
literal|0x0a4
block|,
comment|// 0x0ed = 237 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0f5
block|,
comment|// 0x0ee = 238 -
literal|0x0be
block|,
comment|// 0x0ef = 239 - JUMP_IF_PHY_READY
literal|0x0d5
block|,
comment|// 0x0f0 = 240 -
literal|0x01b
block|,
comment|// 0x0f1 = 241 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x0f2 = 242 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0f3 = 243 - JUMP
literal|0x001
block|,
comment|// 0x0f4 = 244 -
literal|0x0a0
block|,
comment|// 0x0f5 = 245 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0fb
block|,
comment|// 0x0f6 = 246 -
literal|0x000
block|,
comment|// 0x0f7 = 247 - NO_OP
literal|0x000
block|,
comment|// 0x0f8 = 248 - NO_OP
literal|0x0ff
block|,
comment|// 0x0f9 = 249 - JUMP
literal|0x063
block|,
comment|// 0x0fa = 250 -
literal|0x013
block|,
comment|// 0x0fb = 251 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x0fc = 252 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x0fd = 253 -
literal|0x0ff
block|,
comment|// 0x0fe = 254 - JUMP
literal|0x02b
block|,
comment|// 0x0ff = 255 -
literal|0x017
block|,
comment|// 0x100 = 256 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x101 = 257 - JUMP
literal|0x110
block|,
comment|// 0x102 = 258 -
literal|0x018
block|,
comment|// 0x103 = 259 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x104 = 260 - JUMP
literal|0x110
block|,
comment|// 0x105 = 261 -
literal|0x01a
block|,
comment|// 0x106 = 262 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x107 = 263 - JUMP
literal|0x110
block|,
comment|// 0x108 = 264 -
literal|0x015
block|,
comment|// 0x109 = 265 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x110
block|,
comment|// 0x10b = 267 -
literal|0x014
block|,
comment|// 0x10c = 268 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x110
block|,
comment|// 0x10e = 270 -
literal|0x024
block|,
comment|// 0x10f = 271 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x0ff
block|,
comment|// 0x112 = 274 - JUMP
literal|0x063
block|,
comment|// 0x113 = 275 -
literal|0x010
block|,
comment|// 0x114 = 276 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x115 = 277 - JUMP
literal|0x0d0
block|,
comment|// 0x116 = 278 -
literal|0x000
block|,
comment|// 0x117 = 279 - NO_OP
literal|0x000
block|,
comment|// 0x118 = 280 - NO_OP
literal|0x000
block|,
comment|// 0x119 = 281 - NO_OP
literal|0x000
block|,
comment|// 0x11a = 282 - NO_OP
literal|0x000
block|,
comment|// 0x11b = 283 - NO_OP
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x000
block|,
comment|// 0x120 = 288 - NO_OP
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x000
block|,
comment|// 0x125 = 293 - NO_OP
literal|0x000
block|,
comment|// 0x126 = 294 - NO_OP
literal|0x000
block|,
comment|// 0x127 = 295 - NO_OP
literal|0x000
block|,
comment|// 0x128 = 296 - NO_OP
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x000
block|,
comment|// 0x12d = 301 - NO_OP
literal|0x000
block|,
comment|// 0x12e = 302 - NO_OP
literal|0x000
block|,
comment|// 0x12f = 303 - NO_OP
literal|0x000
block|,
comment|// 0x130 = 304 - NO_OP
literal|0x000
block|,
comment|// 0x131 = 305 - NO_OP
literal|0x000
block|,
comment|// 0x132 = 306 - NO_OP
literal|0x000
block|,
comment|// 0x133 = 307 - NO_OP
literal|0x000
block|,
comment|// 0x134 = 308 - NO_OP
literal|0x000
block|,
comment|// 0x135 = 309 - NO_OP
literal|0x000
block|,
comment|// 0x136 = 310 - NO_OP
literal|0x000
block|,
comment|// 0x137 = 311 - NO_OP
literal|0x000
block|,
comment|// 0x138 = 312 - NO_OP
literal|0x000
block|,
comment|// 0x139 = 313 - NO_OP
literal|0x000
block|,
comment|// 0x13a = 314 - NO_OP
literal|0x000
block|,
comment|// 0x13b = 315 - NO_OP
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x000
block|,
comment|// 0x140 = 320 - NO_OP
literal|0x000
block|,
comment|// 0x141 = 321 - NO_OP
literal|0x000
block|,
comment|// 0x142 = 322 - NO_OP
literal|0x000
block|,
comment|// 0x143 = 323 - NO_OP
literal|0x000
block|,
comment|// 0x144 = 324 - NO_OP
literal|0x000
block|,
comment|// 0x145 = 325 - NO_OP
literal|0x000
block|,
comment|// 0x146 = 326 - NO_OP
literal|0x000
block|,
comment|// 0x147 = 327 - NO_OP
literal|0x000
block|,
comment|// 0x148 = 328 - NO_OP
literal|0x000
block|,
comment|// 0x149 = 329 - NO_OP
literal|0x000
block|,
comment|// 0x14a = 330 - NO_OP
literal|0x000
block|,
comment|// 0x14b = 331 - NO_OP
literal|0x000
block|,
comment|// 0x14c = 332 - NO_OP
literal|0x000
block|,
comment|// 0x14d = 333 - NO_OP
literal|0x000
block|,
comment|// 0x14e = 334 - NO_OP
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x000
block|,
comment|// 0x151 = 337 - NO_OP
literal|0x000
block|,
comment|// 0x152 = 338 - NO_OP
literal|0x000
block|,
comment|// 0x153 = 339 - NO_OP
literal|0x000
block|,
comment|// 0x154 = 340 - NO_OP
literal|0x000
block|,
comment|// 0x155 = 341 - NO_OP
literal|0x000
block|,
comment|// 0x156 = 342 - NO_OP
literal|0x000
block|,
comment|// 0x157 = 343 - NO_OP
literal|0x000
block|,
comment|// 0x158 = 344 - NO_OP
literal|0x000
block|,
comment|// 0x159 = 345 - NO_OP
literal|0x000
block|,
comment|// 0x15a = 346 - NO_OP
literal|0x000
block|,
comment|// 0x15b = 347 - NO_OP
literal|0x000
block|,
comment|// 0x15c = 348 - NO_OP
literal|0x000
block|,
comment|// 0x15d = 349 - NO_OP
literal|0x000
block|,
comment|// 0x15e = 350 - NO_OP
literal|0x000
block|,
comment|// 0x15f = 351 - NO_OP
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x000
block|,
comment|// 0x162 = 354 - NO_OP
literal|0x000
block|,
comment|// 0x163 = 355 - NO_OP
literal|0x000
block|,
comment|// 0x164 = 356 - NO_OP
literal|0x000
block|,
comment|// 0x165 = 357 - NO_OP
literal|0x000
block|,
comment|// 0x166 = 358 - NO_OP
literal|0x000
block|,
comment|// 0x167 = 359 - NO_OP
literal|0x000
block|,
comment|// 0x168 = 360 - NO_OP
literal|0x000
block|,
comment|// 0x169 = 361 - NO_OP
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x000
block|,
comment|// 0x16c = 364 - NO_OP
literal|0x000
block|,
comment|// 0x16d = 365 - NO_OP
literal|0x000
block|,
comment|// 0x16e = 366 - NO_OP
literal|0x000
block|,
comment|// 0x16f = 367 - NO_OP
literal|0x000
block|,
comment|// 0x170 = 368 - NO_OP
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WCS 20060825 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage_20060825
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x00c
block|,
comment|// 0x003 = 3 -
literal|0x0ae
block|,
comment|// 0x004 = 4 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x015
block|,
comment|// 0x005 = 5 -
literal|0x0af
block|,
comment|// 0x006 = 6 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x026
block|,
comment|// 0x007 = 7 -
literal|0x0ce
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x009 = 9 -
literal|0x0ff
block|,
comment|// 0x00a = 10 - JUMP
literal|0x002
block|,
comment|// 0x00b = 11 -
literal|0x00c
block|,
comment|// 0x00c = 12 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00d = 13 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x015
block|,
comment|// 0x00e = 14 -
literal|0x0af
block|,
comment|// 0x00f = 15 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x02b
block|,
comment|// 0x010 = 16 -
literal|0x0ce
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x012 = 18 -
literal|0x0ff
block|,
comment|// 0x013 = 19 - JUMP
literal|0x00d
block|,
comment|// 0x014 = 20 -
literal|0x01c
block|,
comment|// 0x015 = 21 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x016 = 22 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x017 = 23 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x018 = 24 - JUMP_IF_PHY_READY
literal|0x01c
block|,
comment|// 0x019 = 25 -
literal|0x0af
block|,
comment|// 0x01a = 26 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x023
block|,
comment|// 0x01b = 27 -
literal|0x00c
block|,
comment|// 0x01c = 28 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x01d = 29 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x02b
block|,
comment|// 0x01e = 30 -
literal|0x0ce
block|,
comment|// 0x01f = 31 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x020 = 32 -
literal|0x0ff
block|,
comment|// 0x021 = 33 - JUMP
literal|0x01d
block|,
comment|// 0x022 = 34 -
literal|0x00c
block|,
comment|// 0x023 = 35 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x024 = 36 - JUMP
literal|0x02b
block|,
comment|// 0x025 = 37 -
literal|0x0be
block|,
comment|// 0x026 = 38 - JUMP_IF_PHY_READY
literal|0x02a
block|,
comment|// 0x027 = 39 -
literal|0x0ff
block|,
comment|// 0x028 = 40 - JUMP
literal|0x026
block|,
comment|// 0x029 = 41 -
literal|0x00c
block|,
comment|// 0x02a = 42 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x02b = 43 - NO_OP
literal|0x000
block|,
comment|// 0x02c = 44 - NO_OP
literal|0x000
block|,
comment|// 0x02d = 45 - NO_OP
literal|0x000
block|,
comment|// 0x02e = 46 - NO_OP
literal|0x000
block|,
comment|// 0x02f = 47 - NO_OP
literal|0x000
block|,
comment|// 0x030 = 48 - NO_OP
literal|0x0ff
block|,
comment|// 0x031 = 49 - JUMP
literal|0x06d
block|,
comment|// 0x032 = 50 -
literal|0x000
block|,
comment|// 0x033 = 51 - NO_OP
literal|0x0c9
block|,
comment|// 0x034 = 52 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x062
block|,
comment|// 0x035 = 53 -
literal|0x0a5
block|,
comment|// 0x036 = 54 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x04b
block|,
comment|// 0x037 = 55 -
literal|0x0a6
block|,
comment|// 0x038 = 56 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x052
block|,
comment|// 0x039 = 57 -
literal|0x0a7
block|,
comment|// 0x03a = 58 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x055
block|,
comment|// 0x03b = 59 -
literal|0x0a8
block|,
comment|// 0x03c = 60 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x05f
block|,
comment|// 0x03d = 61 -
literal|0x0aa
block|,
comment|// 0x03e = 62 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x05a
block|,
comment|// 0x03f = 63 -
literal|0x0c5
block|,
comment|// 0x040 = 64 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x05f
block|,
comment|// 0x041 = 65 -
literal|0x0ac
block|,
comment|// 0x042 = 66 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x052
block|,
comment|// 0x043 = 67 -
literal|0x0ca
block|,
comment|// 0x044 = 68 - JUMP_IF_CLOSE_REQ
literal|0x0fc
block|,
comment|// 0x045 = 69 -
literal|0x0be
block|,
comment|// 0x046 = 70 - JUMP_IF_PHY_READY
literal|0x034
block|,
comment|// 0x047 = 71 -
literal|0x01c
block|,
comment|// 0x048 = 72 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x049 = 73 - JUMP
literal|0x002
block|,
comment|// 0x04a = 74 -
literal|0x01d
block|,
comment|// 0x04b = 75 - ADVANCE
literal|0x0bc
block|,
comment|// 0x04c = 76 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x04d = 77 -
literal|0x0c3
block|,
comment|// 0x04e = 78 - JUMP_IF_SMP_PROTOCOL
literal|0x0fc
block|,
comment|// 0x04f = 79 -
literal|0x0ff
block|,
comment|// 0x050 = 80 - JUMP
literal|0x065
block|,
comment|// 0x051 = 81 -
literal|0x01d
block|,
comment|// 0x052 = 82 - ADVANCE
literal|0x0ff
block|,
comment|// 0x053 = 83 - JUMP
literal|0x065
block|,
comment|// 0x054 = 84 -
literal|0x01d
block|,
comment|// 0x055 = 85 - ADVANCE
literal|0x0bc
block|,
comment|// 0x056 = 86 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x057 = 87 -
literal|0x0ff
block|,
comment|// 0x058 = 88 - JUMP
literal|0x11b
block|,
comment|// 0x059 = 89 -
literal|0x01d
block|,
comment|// 0x05a = 90 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05b = 91 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x05c = 92 -
literal|0x0ff
block|,
comment|// 0x05d = 93 - JUMP
literal|0x11e
block|,
comment|// 0x05e = 94 -
literal|0x01d
block|,
comment|// 0x05f = 95 - ADVANCE
literal|0x0ff
block|,
comment|// 0x060 = 96 - JUMP
literal|0x10f
block|,
comment|// 0x061 = 97 -
literal|0x022
block|,
comment|// 0x062 = 98 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x063 = 99 - JUMP
literal|0x036
block|,
comment|// 0x064 = 100 -
literal|0x083
block|,
comment|// 0x065 = 101 - TIMER_START
literal|0x004
block|,
comment|// 0x066 = 102 -
literal|0x000
block|,
comment|// 0x067 = 103 - NO_OP
literal|0x000
block|,
comment|// 0x068 = 104 - NO_OP
literal|0x0b8
block|,
comment|// 0x069 = 105 - JUMP_IF_TIMER_EXPIRED
literal|0x06d
block|,
comment|// 0x06a = 106 -
literal|0x0ff
block|,
comment|// 0x06b = 107 - JUMP
literal|0x067
block|,
comment|// 0x06c = 108 -
literal|0x0bc
block|,
comment|// 0x06d = 109 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x06e = 110 -
literal|0x0be
block|,
comment|// 0x06f = 111 - JUMP_IF_PHY_READY
literal|0x074
block|,
comment|// 0x070 = 112 -
literal|0x01c
block|,
comment|// 0x071 = 113 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x072 = 114 - JUMP
literal|0x002
block|,
comment|// 0x073 = 115 -
literal|0x0c8
block|,
comment|// 0x074 = 116 - JUMP_IF_HIP_REQ
literal|0x086
block|,
comment|// 0x075 = 117 -
literal|0x0c6
block|,
comment|// 0x076 = 118 - JUMP_IF_SFO_REQ
literal|0x08f
block|,
comment|// 0x077 = 119 -
literal|0x0c7
block|,
comment|// 0x078 = 120 - JUMP_IF_DOC_REQ
literal|0x09a
block|,
comment|// 0x079 = 121 -
literal|0x0a3
block|,
comment|// 0x07a = 122 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x0db
block|,
comment|// 0x07b = 123 -
literal|0x0a2
block|,
comment|// 0x07c = 124 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0c4
block|,
comment|// 0x07d = 125 -
literal|0x0c8
block|,
comment|// 0x07e = 126 - JUMP_IF_HIP_REQ
literal|0x0a3
block|,
comment|// 0x07f = 127 -
literal|0x0c6
block|,
comment|// 0x080 = 128 - JUMP_IF_SFO_REQ
literal|0x0a8
block|,
comment|// 0x081 = 129 -
literal|0x0c7
block|,
comment|// 0x082 = 130 - JUMP_IF_DOC_REQ
literal|0x0ad
block|,
comment|// 0x083 = 131 -
literal|0x0ff
block|,
comment|// 0x084 = 132 - JUMP
literal|0x06d
block|,
comment|// 0x085 = 133 -
literal|0x028
block|,
comment|// 0x086 = 134 - CHECK_HIP
literal|0x000
block|,
comment|// 0x087 = 135 - NO_OP
literal|0x000
block|,
comment|// 0x088 = 136 - NO_OP
literal|0x000
block|,
comment|// 0x089 = 137 - NO_OP
literal|0x000
block|,
comment|// 0x08a = 138 - NO_OP
literal|0x0d8
block|,
comment|// 0x08b = 139 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0a3
block|,
comment|// 0x08c = 140 -
literal|0x0ff
block|,
comment|// 0x08d = 141 - JUMP
literal|0x07a
block|,
comment|// 0x08e = 142 -
literal|0x029
block|,
comment|// 0x08f = 143 - CHECK_SFO
literal|0x000
block|,
comment|// 0x090 = 144 - NO_OP
literal|0x000
block|,
comment|// 0x091 = 145 - NO_OP
literal|0x000
block|,
comment|// 0x092 = 146 - NO_OP
literal|0x000
block|,
comment|// 0x093 = 147 - NO_OP
literal|0x0d8
block|,
comment|// 0x094 = 148 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0a8
block|,
comment|// 0x095 = 149 -
literal|0x0c7
block|,
comment|// 0x096 = 150 - JUMP_IF_DOC_REQ
literal|0x09a
block|,
comment|// 0x097 = 151 -
literal|0x0ff
block|,
comment|// 0x098 = 152 - JUMP
literal|0x07a
block|,
comment|// 0x099 = 153 -
literal|0x02a
block|,
comment|// 0x09a = 154 - CHECK_DOC
literal|0x000
block|,
comment|// 0x09b = 155 - NO_OP
literal|0x000
block|,
comment|// 0x09c = 156 - NO_OP
literal|0x000
block|,
comment|// 0x09d = 157 - NO_OP
literal|0x000
block|,
comment|// 0x09e = 158 - NO_OP
literal|0x0d8
block|,
comment|// 0x09f = 159 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0ad
block|,
comment|// 0x0a0 = 160 -
literal|0x0ff
block|,
comment|// 0x0a1 = 161 - JUMP
literal|0x07a
block|,
comment|// 0x0a2 = 162 -
literal|0x020
block|,
comment|// 0x0a3 = 163 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0a4 = 164 - NO_OP
literal|0x000
block|,
comment|// 0x0a5 = 165 - NO_OP
literal|0x0ff
block|,
comment|// 0x0a6 = 166 - JUMP
literal|0x0b0
block|,
comment|// 0x0a7 = 167 -
literal|0x01e
block|,
comment|// 0x0a8 = 168 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0a9 = 169 - NO_OP
literal|0x000
block|,
comment|// 0x0aa = 170 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ab = 171 - JUMP
literal|0x0b0
block|,
comment|// 0x0ac = 172 -
literal|0x01f
block|,
comment|// 0x0ad = 173 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0ae = 174 - NO_OP
literal|0x000
block|,
comment|// 0x0af = 175 - NO_OP
literal|0x0a4
block|,
comment|// 0x0b0 = 176 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0b4
block|,
comment|// 0x0b1 = 177 -
literal|0x0ff
block|,
comment|// 0x0b2 = 178 - JUMP
literal|0x121
block|,
comment|// 0x0b3 = 179 -
literal|0x0a0
block|,
comment|// 0x0b4 = 180 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0ba
block|,
comment|// 0x0b5 = 181 -
literal|0x0a3
block|,
comment|// 0x0b6 = 182 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x0db
block|,
comment|// 0x0b7 = 183 -
literal|0x0ff
block|,
comment|// 0x0b8 = 184 - JUMP
literal|0x0fc
block|,
comment|// 0x0b9 = 185 -
literal|0x0cb
block|,
comment|// 0x0ba = 186 - JUMP_IF_FREEZE_ACTIVE
literal|0x0bf
block|,
comment|// 0x0bb = 187 -
literal|0x013
block|,
comment|// 0x0bc = 188 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0bd = 189 - JUMP
literal|0x033
block|,
comment|// 0x0be = 190 -
literal|0x024
block|,
comment|// 0x0bf = 191 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x000
block|,
comment|// 0x0c1 = 193 - NO_OP
literal|0x0ff
block|,
comment|// 0x0c2 = 194 - JUMP
literal|0x06d
block|,
comment|// 0x0c3 = 195 -
literal|0x0d2
block|,
comment|// 0x0c4 = 196 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0c8
block|,
comment|// 0x0c5 = 197 -
literal|0x0ff
block|,
comment|// 0x0c6 = 198 - JUMP
literal|0x0fc
block|,
comment|// 0x0c7 = 199 -
literal|0x0d5
block|,
comment|// 0x0c8 = 200 - JUMP_IF_CLOSE_RECEIVED
literal|0x0fc
block|,
comment|// 0x0c9 = 201 -
literal|0x0d6
block|,
comment|// 0x0ca = 202 - JUMP_IF_SYNC_RECEIVED
literal|0x0ce
block|,
comment|// 0x0cb = 203 -
literal|0x0ff
block|,
comment|// 0x0cc = 204 - JUMP
literal|0x06d
block|,
comment|// 0x0cd = 205 -
literal|0x027
block|,
comment|// 0x0ce = 206 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0cf = 207 - NO_OP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x000
block|,
comment|// 0x0d2 = 210 - NO_OP
literal|0x0d5
block|,
comment|// 0x0d3 = 211 - JUMP_IF_CLOSE_RECEIVED
literal|0x0fc
block|,
comment|// 0x0d4 = 212 -
literal|0x0bc
block|,
comment|// 0x0d5 = 213 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x0d6 = 214 -
literal|0x0d7
block|,
comment|// 0x0d7 = 215 - JUMP_IF_STP_CLOSE_ACK
literal|0x0fc
block|,
comment|// 0x0d8 = 216 -
literal|0x0ff
block|,
comment|// 0x0d9 = 217 - JUMP
literal|0x0cf
block|,
comment|// 0x0da = 218 -
literal|0x0c3
block|,
comment|// 0x0db = 219 - JUMP_IF_SMP_PROTOCOL
literal|0x0e3
block|,
comment|// 0x0dc = 220 -
literal|0x0d2
block|,
comment|// 0x0dd = 221 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0e7
block|,
comment|// 0x0de = 222 -
literal|0x0d1
block|,
comment|// 0x0df = 223 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x0ed
block|,
comment|// 0x0e0 = 224 -
literal|0x0ff
block|,
comment|// 0x0e1 = 225 - JUMP
literal|0x06d
block|,
comment|// 0x0e2 = 226 -
literal|0x0c4
block|,
comment|// 0x0e3 = 227 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x10f
block|,
comment|// 0x0e4 = 228 -
literal|0x0ff
block|,
comment|// 0x0e5 = 229 - JUMP
literal|0x07e
block|,
comment|// 0x0e6 = 230 -
literal|0x0d5
block|,
comment|// 0x0e7 = 231 - JUMP_IF_CLOSE_RECEIVED
literal|0x0ed
block|,
comment|// 0x0e8 = 232 -
literal|0x0d6
block|,
comment|// 0x0e9 = 233 - JUMP_IF_SYNC_RECEIVED
literal|0x0ef
block|,
comment|// 0x0ea = 234 -
literal|0x0ff
block|,
comment|// 0x0eb = 235 - JUMP
literal|0x0e7
block|,
comment|// 0x0ec = 236 -
literal|0x0ff
block|,
comment|// 0x0ed = 237 - JUMP
literal|0x0fc
block|,
comment|// 0x0ee = 238 -
literal|0x027
block|,
comment|// 0x0ef = 239 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0f0 = 240 - NO_OP
literal|0x000
block|,
comment|// 0x0f1 = 241 - NO_OP
literal|0x000
block|,
comment|// 0x0f2 = 242 - NO_OP
literal|0x000
block|,
comment|// 0x0f3 = 243 - NO_OP
literal|0x0d5
block|,
comment|// 0x0f4 = 244 - JUMP_IF_CLOSE_RECEIVED
literal|0x0fc
block|,
comment|// 0x0f5 = 245 -
literal|0x0bc
block|,
comment|// 0x0f6 = 246 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x0f7 = 247 -
literal|0x0d7
block|,
comment|// 0x0f8 = 248 - JUMP_IF_STP_CLOSE_ACK
literal|0x0fc
block|,
comment|// 0x0f9 = 249 -
literal|0x0ff
block|,
comment|// 0x0fa = 250 - JUMP
literal|0x0f0
block|,
comment|// 0x0fb = 251 -
literal|0x004
block|,
comment|// 0x0fc = 252 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x000
block|,
comment|// 0x0fe = 254 - NO_OP
literal|0x000
block|,
comment|// 0x0ff = 255 - NO_OP
literal|0x000
block|,
comment|// 0x100 = 256 - NO_OP
literal|0x0c9
block|,
comment|// 0x101 = 257 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x10c
block|,
comment|// 0x102 = 258 -
literal|0x0c0
block|,
comment|// 0x103 = 259 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x06d
block|,
comment|// 0x104 = 260 -
literal|0x0bc
block|,
comment|// 0x105 = 261 - JUMP_IF_BREAK_RECEIVED
literal|0x10f
block|,
comment|// 0x106 = 262 -
literal|0x0be
block|,
comment|// 0x107 = 263 - JUMP_IF_PHY_READY
literal|0x0fd
block|,
comment|// 0x108 = 264 -
literal|0x01c
block|,
comment|// 0x109 = 265 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x10a = 266 - JUMP
literal|0x002
block|,
comment|// 0x10b = 267 -
literal|0x022
block|,
comment|// 0x10c = 268 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x0fd
block|,
comment|// 0x10e = 270 -
literal|0x007
block|,
comment|// 0x10f = 271 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x000
block|,
comment|// 0x112 = 274 - NO_OP
literal|0x000
block|,
comment|// 0x113 = 275 - NO_OP
literal|0x0c0
block|,
comment|// 0x114 = 276 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x06d
block|,
comment|// 0x115 = 277 -
literal|0x0be
block|,
comment|// 0x116 = 278 - JUMP_IF_PHY_READY
literal|0x110
block|,
comment|// 0x117 = 279 -
literal|0x01c
block|,
comment|// 0x118 = 280 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x002
block|,
comment|// 0x11a = 282 -
literal|0x005
block|,
comment|// 0x11b = 283 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x11c = 284 - JUMP
literal|0x0fd
block|,
comment|// 0x11d = 285 -
literal|0x006
block|,
comment|// 0x11e = 286 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x11f = 287 - JUMP
literal|0x0fd
block|,
comment|// 0x120 = 288 -
literal|0x0cc
block|,
comment|// 0x121 = 289 - JUMP_IF_RX_BUFFER_FULL
literal|0x06d
block|,
comment|// 0x122 = 290 -
literal|0x0b7
block|,
comment|// 0x123 = 291 - JUMP_IF_FLAG_7_SET
literal|0x128
block|,
comment|// 0x124 = 292 -
literal|0x011
block|,
comment|// 0x125 = 293 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x126 = 294 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x127 = 295 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x128 = 296 - JUMP_IF_FREEZE_ACTIVE
literal|0x169
block|,
comment|// 0x129 = 297 -
literal|0x001
block|,
comment|// 0x12a = 298 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x12b = 299 - SET_FLAG
literal|0x080
block|,
comment|// 0x12c = 300 -
literal|0x090
block|,
comment|// 0x12d = 301 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x153
block|,
comment|// 0x12e = 302 -
literal|0x095
block|,
comment|// 0x12f = 303 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x158
block|,
comment|// 0x130 = 304 -
literal|0x099
block|,
comment|// 0x131 = 305 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x15b
block|,
comment|// 0x132 = 306 -
literal|0x09b
block|,
comment|// 0x133 = 307 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x15e
block|,
comment|// 0x134 = 308 -
literal|0x094
block|,
comment|// 0x135 = 309 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x128
block|,
comment|// 0x136 = 310 -
literal|0x093
block|,
comment|// 0x137 = 311 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x161
block|,
comment|// 0x138 = 312 -
literal|0x09f
block|,
comment|// 0x139 = 313 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x164
block|,
comment|// 0x13a = 314 -
literal|0x09a
block|,
comment|// 0x13b = 315 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x128
block|,
comment|// 0x13c = 316 -
literal|0x096
block|,
comment|// 0x13d = 317 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x128
block|,
comment|// 0x13e = 318 -
literal|0x097
block|,
comment|// 0x13f = 319 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x16e
block|,
comment|// 0x140 = 320 -
literal|0x098
block|,
comment|// 0x141 = 321 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x128
block|,
comment|// 0x142 = 322 -
literal|0x092
block|,
comment|// 0x143 = 323 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x128
block|,
comment|// 0x144 = 324 -
literal|0x0a4
block|,
comment|// 0x145 = 325 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x14d
block|,
comment|// 0x146 = 326 -
literal|0x0be
block|,
comment|// 0x147 = 327 - JUMP_IF_PHY_READY
literal|0x12d
block|,
comment|// 0x148 = 328 -
literal|0x01b
block|,
comment|// 0x149 = 329 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x14a = 330 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x14b = 331 - JUMP
literal|0x002
block|,
comment|// 0x14c = 332 -
literal|0x0a0
block|,
comment|// 0x14d = 333 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x153
block|,
comment|// 0x14e = 334 -
literal|0x000
block|,
comment|// 0x14f = 335 - NO_OP
literal|0x000
block|,
comment|// 0x150 = 336 - NO_OP
literal|0x0ff
block|,
comment|// 0x151 = 337 - JUMP
literal|0x06d
block|,
comment|// 0x152 = 338 -
literal|0x013
block|,
comment|// 0x153 = 339 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x154 = 340 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x155 = 341 -
literal|0x0ff
block|,
comment|// 0x156 = 342 - JUMP
literal|0x033
block|,
comment|// 0x157 = 343 -
literal|0x017
block|,
comment|// 0x158 = 344 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x159 = 345 - JUMP
literal|0x16a
block|,
comment|// 0x15a = 346 -
literal|0x018
block|,
comment|// 0x15b = 347 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x15c = 348 - JUMP
literal|0x16a
block|,
comment|// 0x15d = 349 -
literal|0x01a
block|,
comment|// 0x15e = 350 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x15f = 351 - JUMP
literal|0x16a
block|,
comment|// 0x160 = 352 -
literal|0x015
block|,
comment|// 0x161 = 353 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x162 = 354 - JUMP
literal|0x16a
block|,
comment|// 0x163 = 355 -
literal|0x014
block|,
comment|// 0x164 = 356 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x081
block|,
comment|// 0x165 = 357 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x166 = 358 -
literal|0x0ff
block|,
comment|// 0x167 = 359 - JUMP
literal|0x16a
block|,
comment|// 0x168 = 360 -
literal|0x024
block|,
comment|// 0x169 = 361 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x16a = 362 - NO_OP
literal|0x000
block|,
comment|// 0x16b = 363 - NO_OP
literal|0x0ff
block|,
comment|// 0x16c = 364 - JUMP
literal|0x06d
block|,
comment|// 0x16d = 365 -
literal|0x010
block|,
comment|// 0x16e = 366 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x16f = 367 - JUMP
literal|0x128
block|,
comment|// 0x170 = 368 -
literal|0x000
block|,
comment|// 0x171 = 369 - NO_OP
literal|0x000
block|,
comment|// 0x172 = 370 - NO_OP
literal|0x000
block|,
comment|// 0x173 = 371 - NO_OP
literal|0x000
block|,
comment|// 0x174 = 372 - NO_OP
literal|0x000
block|,
comment|// 0x175 = 373 - NO_OP
literal|0x000
block|,
comment|// 0x176 = 374 - NO_OP
literal|0x000
block|,
comment|// 0x177 = 375 - NO_OP
literal|0x000
block|,
comment|// 0x178 = 376 - NO_OP
literal|0x000
block|,
comment|// 0x179 = 377 - NO_OP
literal|0x000
block|,
comment|// 0x17a = 378 - NO_OP
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x000
block|,
comment|// 0x17f = 383 - NO_OP
literal|0x000
block|,
comment|// 0x180 = 384 - NO_OP
literal|0x000
block|,
comment|// 0x181 = 385 - NO_OP
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wcs with A1302_20 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage_A1302_20
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x002
block|,
comment|// 0x003 = 3 -
literal|0x0be
block|,
comment|// 0x004 = 4 - JUMP_IF_PHY_READY
literal|0x00e
block|,
comment|// 0x005 = 5 -
literal|0x0ae
block|,
comment|// 0x006 = 6 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x007 = 7 -
literal|0x0af
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x017
block|,
comment|// 0x009 = 9 -
literal|0x0ce
block|,
comment|// 0x00a = 10 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x00b = 11 -
literal|0x0ff
block|,
comment|// 0x00c = 12 - JUMP
literal|0x004
block|,
comment|// 0x00d = 13 -
literal|0x00c
block|,
comment|// 0x00e = 14 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00f = 15 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x010 = 16 -
literal|0x0af
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01c
block|,
comment|// 0x012 = 18 -
literal|0x0ce
block|,
comment|// 0x013 = 19 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x014 = 20 -
literal|0x0ff
block|,
comment|// 0x015 = 21 - JUMP
literal|0x00f
block|,
comment|// 0x016 = 22 -
literal|0x0be
block|,
comment|// 0x017 = 23 - JUMP_IF_PHY_READY
literal|0x01b
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x01c = 28 - NO_OP
literal|0x000
block|,
comment|// 0x01d = 29 - NO_OP
literal|0x000
block|,
comment|// 0x01e = 30 - NO_OP
literal|0x000
block|,
comment|// 0x01f = 31 - NO_OP
literal|0x000
block|,
comment|// 0x020 = 32 - NO_OP
literal|0x000
block|,
comment|// 0x021 = 33 - NO_OP
literal|0x0ff
block|,
comment|// 0x022 = 34 - JUMP
literal|0x07e
block|,
comment|// 0x023 = 35 -
literal|0x01c
block|,
comment|// 0x024 = 36 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x025 = 37 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x026 = 38 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x027 = 39 - JUMP_IF_PHY_READY
literal|0x027
block|,
comment|// 0x028 = 40 -
literal|0x0be
block|,
comment|// 0x029 = 41 - JUMP_IF_PHY_READY
literal|0x02f
block|,
comment|// 0x02a = 42 -
literal|0x0af
block|,
comment|// 0x02b = 43 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x036
block|,
comment|// 0x02c = 44 -
literal|0x0ff
block|,
comment|// 0x02d = 45 - JUMP
literal|0x029
block|,
comment|// 0x02e = 46 -
literal|0x00c
block|,
comment|// 0x02f = 47 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x030 = 48 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x039
block|,
comment|// 0x031 = 49 -
literal|0x0ce
block|,
comment|// 0x032 = 50 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x024
block|,
comment|// 0x033 = 51 -
literal|0x0ff
block|,
comment|// 0x034 = 52 - JUMP
literal|0x030
block|,
comment|// 0x035 = 53 -
literal|0x00c
block|,
comment|// 0x036 = 54 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x037 = 55 - JUMP
literal|0x039
block|,
comment|// 0x038 = 56 -
literal|0x000
block|,
comment|// 0x039 = 57 - NO_OP
literal|0x0cb
block|,
comment|// 0x03a = 58 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03b = 59 -
literal|0x0ff
block|,
comment|// 0x03c = 60 - JUMP
literal|0x03a
block|,
comment|// 0x03d = 61 -
literal|0x0cb
block|,
comment|// 0x03e = 62 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03f = 63 -
literal|0x0ff
block|,
comment|// 0x040 = 64 - JUMP
literal|0x07e
block|,
comment|// 0x041 = 65 -
literal|0x000
block|,
comment|// 0x042 = 66 - NO_OP
literal|0x0c9
block|,
comment|// 0x043 = 67 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x073
block|,
comment|// 0x044 = 68 -
literal|0x0a5
block|,
comment|// 0x045 = 69 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x05c
block|,
comment|// 0x046 = 70 -
literal|0x0a6
block|,
comment|// 0x047 = 71 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x063
block|,
comment|// 0x048 = 72 -
literal|0x0a7
block|,
comment|// 0x049 = 73 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x066
block|,
comment|// 0x04a = 74 -
literal|0x0a8
block|,
comment|// 0x04b = 75 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x070
block|,
comment|// 0x04c = 76 -
literal|0x0aa
block|,
comment|// 0x04d = 77 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x06b
block|,
comment|// 0x04e = 78 -
literal|0x0c5
block|,
comment|// 0x04f = 79 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x070
block|,
comment|// 0x050 = 80 -
literal|0x0ac
block|,
comment|// 0x051 = 81 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x063
block|,
comment|// 0x052 = 82 -
literal|0x0d9
block|,
comment|// 0x053 = 83 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_FREEZE_TIMEOUT
literal|0x070
block|,
comment|// 0x054 = 84 -
literal|0x0ca
block|,
comment|// 0x055 = 85 - JUMP_IF_CLOSE_REQ
literal|0x10d
block|,
comment|// 0x056 = 86 -
literal|0x0be
block|,
comment|// 0x057 = 87 - JUMP_IF_PHY_READY
literal|0x043
block|,
comment|// 0x058 = 88 -
literal|0x01c
block|,
comment|// 0x059 = 89 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x004
block|,
comment|// 0x05b = 91 -
literal|0x01d
block|,
comment|// 0x05c = 92 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05d = 93 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x05e = 94 -
literal|0x0c3
block|,
comment|// 0x05f = 95 - JUMP_IF_SMP_PROTOCOL
literal|0x10d
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x076
block|,
comment|// 0x062 = 98 -
literal|0x01d
block|,
comment|// 0x063 = 99 - ADVANCE
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x076
block|,
comment|// 0x065 = 101 -
literal|0x01d
block|,
comment|// 0x066 = 102 - ADVANCE
literal|0x0bc
block|,
comment|// 0x067 = 103 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x068 = 104 -
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x12c
block|,
comment|// 0x06a = 106 -
literal|0x01d
block|,
comment|// 0x06b = 107 - ADVANCE
literal|0x0bc
block|,
comment|// 0x06c = 108 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x06d = 109 -
literal|0x0ff
block|,
comment|// 0x06e = 110 - JUMP
literal|0x12f
block|,
comment|// 0x06f = 111 -
literal|0x01d
block|,
comment|// 0x070 = 112 - ADVANCE
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x120
block|,
comment|// 0x072 = 114 -
literal|0x022
block|,
comment|// 0x073 = 115 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x045
block|,
comment|// 0x075 = 117 -
literal|0x083
block|,
comment|// 0x076 = 118 - TIMER_START
literal|0x004
block|,
comment|// 0x077 = 119 -
literal|0x000
block|,
comment|// 0x078 = 120 - NO_OP
literal|0x000
block|,
comment|// 0x079 = 121 - NO_OP
literal|0x0b8
block|,
comment|// 0x07a = 122 - JUMP_IF_TIMER_EXPIRED
literal|0x07e
block|,
comment|// 0x07b = 123 -
literal|0x0ff
block|,
comment|// 0x07c = 124 - JUMP
literal|0x078
block|,
comment|// 0x07d = 125 -
literal|0x0bc
block|,
comment|// 0x07e = 126 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x07f = 127 -
literal|0x0be
block|,
comment|// 0x080 = 128 - JUMP_IF_PHY_READY
literal|0x085
block|,
comment|// 0x081 = 129 -
literal|0x01c
block|,
comment|// 0x082 = 130 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x083 = 131 - JUMP
literal|0x004
block|,
comment|// 0x084 = 132 -
literal|0x0c8
block|,
comment|// 0x085 = 133 - JUMP_IF_HIP_REQ
literal|0x097
block|,
comment|// 0x086 = 134 -
literal|0x0c6
block|,
comment|// 0x087 = 135 - JUMP_IF_SFO_REQ
literal|0x0a0
block|,
comment|// 0x088 = 136 -
literal|0x0c7
block|,
comment|// 0x089 = 137 - JUMP_IF_DOC_REQ
literal|0x0ab
block|,
comment|// 0x08a = 138 -
literal|0x0a3
block|,
comment|// 0x08b = 139 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x0ec
block|,
comment|// 0x08c = 140 -
literal|0x0a2
block|,
comment|// 0x08d = 141 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0d5
block|,
comment|// 0x08e = 142 -
literal|0x0c8
block|,
comment|// 0x08f = 143 - JUMP_IF_HIP_REQ
literal|0x0b4
block|,
comment|// 0x090 = 144 -
literal|0x0c6
block|,
comment|// 0x091 = 145 - JUMP_IF_SFO_REQ
literal|0x0b9
block|,
comment|// 0x092 = 146 -
literal|0x0c7
block|,
comment|// 0x093 = 147 - JUMP_IF_DOC_REQ
literal|0x0be
block|,
comment|// 0x094 = 148 -
literal|0x0ff
block|,
comment|// 0x095 = 149 - JUMP
literal|0x07e
block|,
comment|// 0x096 = 150 -
literal|0x028
block|,
comment|// 0x097 = 151 - CHECK_HIP
literal|0x000
block|,
comment|// 0x098 = 152 - NO_OP
literal|0x000
block|,
comment|// 0x099 = 153 - NO_OP
literal|0x000
block|,
comment|// 0x09a = 154 - NO_OP
literal|0x000
block|,
comment|// 0x09b = 155 - NO_OP
literal|0x0d8
block|,
comment|// 0x09c = 156 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0b4
block|,
comment|// 0x09d = 157 -
literal|0x0ff
block|,
comment|// 0x09e = 158 - JUMP
literal|0x08b
block|,
comment|// 0x09f = 159 -
literal|0x029
block|,
comment|// 0x0a0 = 160 - CHECK_SFO
literal|0x000
block|,
comment|// 0x0a1 = 161 - NO_OP
literal|0x000
block|,
comment|// 0x0a2 = 162 - NO_OP
literal|0x000
block|,
comment|// 0x0a3 = 163 - NO_OP
literal|0x000
block|,
comment|// 0x0a4 = 164 - NO_OP
literal|0x0d8
block|,
comment|// 0x0a5 = 165 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0b9
block|,
comment|// 0x0a6 = 166 -
literal|0x0c7
block|,
comment|// 0x0a7 = 167 - JUMP_IF_DOC_REQ
literal|0x0ab
block|,
comment|// 0x0a8 = 168 -
literal|0x0ff
block|,
comment|// 0x0a9 = 169 - JUMP
literal|0x08b
block|,
comment|// 0x0aa = 170 -
literal|0x02a
block|,
comment|// 0x0ab = 171 - CHECK_DOC
literal|0x000
block|,
comment|// 0x0ac = 172 - NO_OP
literal|0x000
block|,
comment|// 0x0ad = 173 - NO_OP
literal|0x000
block|,
comment|// 0x0ae = 174 - NO_OP
literal|0x000
block|,
comment|// 0x0af = 175 - NO_OP
literal|0x0d8
block|,
comment|// 0x0b0 = 176 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0be
block|,
comment|// 0x0b1 = 177 -
literal|0x0ff
block|,
comment|// 0x0b2 = 178 - JUMP
literal|0x08b
block|,
comment|// 0x0b3 = 179 -
literal|0x020
block|,
comment|// 0x0b4 = 180 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0b5 = 181 - NO_OP
literal|0x000
block|,
comment|// 0x0b6 = 182 - NO_OP
literal|0x0ff
block|,
comment|// 0x0b7 = 183 - JUMP
literal|0x0c1
block|,
comment|// 0x0b8 = 184 -
literal|0x01e
block|,
comment|// 0x0b9 = 185 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0ba = 186 - NO_OP
literal|0x000
block|,
comment|// 0x0bb = 187 - NO_OP
literal|0x0ff
block|,
comment|// 0x0bc = 188 - JUMP
literal|0x0c1
block|,
comment|// 0x0bd = 189 -
literal|0x01f
block|,
comment|// 0x0be = 190 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x0a4
block|,
comment|// 0x0c1 = 193 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0c5
block|,
comment|// 0x0c2 = 194 -
literal|0x0ff
block|,
comment|// 0x0c3 = 195 - JUMP
literal|0x132
block|,
comment|// 0x0c4 = 196 -
literal|0x0a0
block|,
comment|// 0x0c5 = 197 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0cb
block|,
comment|// 0x0c6 = 198 -
literal|0x0a3
block|,
comment|// 0x0c7 = 199 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x0ec
block|,
comment|// 0x0c8 = 200 -
literal|0x0ff
block|,
comment|// 0x0c9 = 201 - JUMP
literal|0x10d
block|,
comment|// 0x0ca = 202 -
literal|0x0cb
block|,
comment|// 0x0cb = 203 - JUMP_IF_FREEZE_ACTIVE
literal|0x0d0
block|,
comment|// 0x0cc = 204 -
literal|0x013
block|,
comment|// 0x0cd = 205 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0ce = 206 - JUMP
literal|0x042
block|,
comment|// 0x0cf = 207 -
literal|0x024
block|,
comment|// 0x0d0 = 208 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x000
block|,
comment|// 0x0d2 = 210 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d3 = 211 - JUMP
literal|0x07e
block|,
comment|// 0x0d4 = 212 -
literal|0x0d2
block|,
comment|// 0x0d5 = 213 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0d9
block|,
comment|// 0x0d6 = 214 -
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x10d
block|,
comment|// 0x0d8 = 216 -
literal|0x0d5
block|,
comment|// 0x0d9 = 217 - JUMP_IF_CLOSE_RECEIVED
literal|0x10d
block|,
comment|// 0x0da = 218 -
literal|0x0d6
block|,
comment|// 0x0db = 219 - JUMP_IF_SYNC_RECEIVED
literal|0x0df
block|,
comment|// 0x0dc = 220 -
literal|0x0ff
block|,
comment|// 0x0dd = 221 - JUMP
literal|0x07e
block|,
comment|// 0x0de = 222 -
literal|0x027
block|,
comment|// 0x0df = 223 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0e0 = 224 - NO_OP
literal|0x000
block|,
comment|// 0x0e1 = 225 - NO_OP
literal|0x000
block|,
comment|// 0x0e2 = 226 - NO_OP
literal|0x000
block|,
comment|// 0x0e3 = 227 - NO_OP
literal|0x0d5
block|,
comment|// 0x0e4 = 228 - JUMP_IF_CLOSE_RECEIVED
literal|0x10d
block|,
comment|// 0x0e5 = 229 -
literal|0x0bc
block|,
comment|// 0x0e6 = 230 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x0e7 = 231 -
literal|0x0d7
block|,
comment|// 0x0e8 = 232 - JUMP_IF_STP_CLOSE_ACK
literal|0x10d
block|,
comment|// 0x0e9 = 233 -
literal|0x0ff
block|,
comment|// 0x0ea = 234 - JUMP
literal|0x0e0
block|,
comment|// 0x0eb = 235 -
literal|0x0c3
block|,
comment|// 0x0ec = 236 - JUMP_IF_SMP_PROTOCOL
literal|0x0f4
block|,
comment|// 0x0ed = 237 -
literal|0x0d2
block|,
comment|// 0x0ee = 238 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0f8
block|,
comment|// 0x0ef = 239 -
literal|0x0d1
block|,
comment|// 0x0f0 = 240 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x0fe
block|,
comment|// 0x0f1 = 241 -
literal|0x0ff
block|,
comment|// 0x0f2 = 242 - JUMP
literal|0x07e
block|,
comment|// 0x0f3 = 243 -
literal|0x0c4
block|,
comment|// 0x0f4 = 244 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x120
block|,
comment|// 0x0f5 = 245 -
literal|0x0ff
block|,
comment|// 0x0f6 = 246 - JUMP
literal|0x08f
block|,
comment|// 0x0f7 = 247 -
literal|0x0d5
block|,
comment|// 0x0f8 = 248 - JUMP_IF_CLOSE_RECEIVED
literal|0x0fe
block|,
comment|// 0x0f9 = 249 -
literal|0x0d6
block|,
comment|// 0x0fa = 250 - JUMP_IF_SYNC_RECEIVED
literal|0x100
block|,
comment|// 0x0fb = 251 -
literal|0x0ff
block|,
comment|// 0x0fc = 252 - JUMP
literal|0x0f8
block|,
comment|// 0x0fd = 253 -
literal|0x0ff
block|,
comment|// 0x0fe = 254 - JUMP
literal|0x10d
block|,
comment|// 0x0ff = 255 -
literal|0x027
block|,
comment|// 0x100 = 256 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x101 = 257 - NO_OP
literal|0x000
block|,
comment|// 0x102 = 258 - NO_OP
literal|0x000
block|,
comment|// 0x103 = 259 - NO_OP
literal|0x000
block|,
comment|// 0x104 = 260 - NO_OP
literal|0x0d5
block|,
comment|// 0x105 = 261 - JUMP_IF_CLOSE_RECEIVED
literal|0x10d
block|,
comment|// 0x106 = 262 -
literal|0x0bc
block|,
comment|// 0x107 = 263 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x108 = 264 -
literal|0x0d7
block|,
comment|// 0x109 = 265 - JUMP_IF_STP_CLOSE_ACK
literal|0x10d
block|,
comment|// 0x10a = 266 -
literal|0x0ff
block|,
comment|// 0x10b = 267 - JUMP
literal|0x101
block|,
comment|// 0x10c = 268 -
literal|0x004
block|,
comment|// 0x10d = 269 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x10e = 270 - NO_OP
literal|0x000
block|,
comment|// 0x10f = 271 - NO_OP
literal|0x000
block|,
comment|// 0x110 = 272 - NO_OP
literal|0x000
block|,
comment|// 0x111 = 273 - NO_OP
literal|0x0c9
block|,
comment|// 0x112 = 274 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x11d
block|,
comment|// 0x113 = 275 -
literal|0x0c0
block|,
comment|// 0x114 = 276 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x07e
block|,
comment|// 0x115 = 277 -
literal|0x0bc
block|,
comment|// 0x116 = 278 - JUMP_IF_BREAK_RECEIVED
literal|0x120
block|,
comment|// 0x117 = 279 -
literal|0x0be
block|,
comment|// 0x118 = 280 - JUMP_IF_PHY_READY
literal|0x10e
block|,
comment|// 0x119 = 281 -
literal|0x01c
block|,
comment|// 0x11a = 282 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x11b = 283 - JUMP
literal|0x004
block|,
comment|// 0x11c = 284 -
literal|0x022
block|,
comment|// 0x11d = 285 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x11e = 286 - JUMP
literal|0x10e
block|,
comment|// 0x11f = 287 -
literal|0x007
block|,
comment|// 0x120 = 288 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x121 = 289 - NO_OP
literal|0x000
block|,
comment|// 0x122 = 290 - NO_OP
literal|0x000
block|,
comment|// 0x123 = 291 - NO_OP
literal|0x000
block|,
comment|// 0x124 = 292 - NO_OP
literal|0x0c0
block|,
comment|// 0x125 = 293 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x07e
block|,
comment|// 0x126 = 294 -
literal|0x0be
block|,
comment|// 0x127 = 295 - JUMP_IF_PHY_READY
literal|0x121
block|,
comment|// 0x128 = 296 -
literal|0x01c
block|,
comment|// 0x129 = 297 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x12a = 298 - JUMP
literal|0x004
block|,
comment|// 0x12b = 299 -
literal|0x005
block|,
comment|// 0x12c = 300 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x12d = 301 - JUMP
literal|0x10e
block|,
comment|// 0x12e = 302 -
literal|0x006
block|,
comment|// 0x12f = 303 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x130 = 304 - JUMP
literal|0x10e
block|,
comment|// 0x131 = 305 -
literal|0x0cc
block|,
comment|// 0x132 = 306 - JUMP_IF_RX_BUFFER_FULL
literal|0x07e
block|,
comment|// 0x133 = 307 -
literal|0x0b7
block|,
comment|// 0x134 = 308 - JUMP_IF_FLAG_7_SET
literal|0x139
block|,
comment|// 0x135 = 309 -
literal|0x011
block|,
comment|// 0x136 = 310 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x137 = 311 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x138 = 312 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x139 = 313 - JUMP_IF_FREEZE_ACTIVE
literal|0x17a
block|,
comment|// 0x13a = 314 -
literal|0x001
block|,
comment|// 0x13b = 315 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x13c = 316 - SET_FLAG
literal|0x080
block|,
comment|// 0x13d = 317 -
literal|0x090
block|,
comment|// 0x13e = 318 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x164
block|,
comment|// 0x13f = 319 -
literal|0x095
block|,
comment|// 0x140 = 320 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x169
block|,
comment|// 0x141 = 321 -
literal|0x099
block|,
comment|// 0x142 = 322 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x16c
block|,
comment|// 0x143 = 323 -
literal|0x09b
block|,
comment|// 0x144 = 324 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x16f
block|,
comment|// 0x145 = 325 -
literal|0x094
block|,
comment|// 0x146 = 326 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x139
block|,
comment|// 0x147 = 327 -
literal|0x093
block|,
comment|// 0x148 = 328 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x172
block|,
comment|// 0x149 = 329 -
literal|0x09f
block|,
comment|// 0x14a = 330 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x175
block|,
comment|// 0x14b = 331 -
literal|0x09a
block|,
comment|// 0x14c = 332 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x139
block|,
comment|// 0x14d = 333 -
literal|0x096
block|,
comment|// 0x14e = 334 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x139
block|,
comment|// 0x14f = 335 -
literal|0x097
block|,
comment|// 0x150 = 336 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x17f
block|,
comment|// 0x151 = 337 -
literal|0x098
block|,
comment|// 0x152 = 338 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x139
block|,
comment|// 0x153 = 339 -
literal|0x092
block|,
comment|// 0x154 = 340 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x139
block|,
comment|// 0x155 = 341 -
literal|0x0a4
block|,
comment|// 0x156 = 342 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x15e
block|,
comment|// 0x157 = 343 -
literal|0x0be
block|,
comment|// 0x158 = 344 - JUMP_IF_PHY_READY
literal|0x13e
block|,
comment|// 0x159 = 345 -
literal|0x01b
block|,
comment|// 0x15a = 346 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x15b = 347 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x15c = 348 - JUMP
literal|0x004
block|,
comment|// 0x15d = 349 -
literal|0x0a0
block|,
comment|// 0x15e = 350 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x164
block|,
comment|// 0x15f = 351 -
literal|0x000
block|,
comment|// 0x160 = 352 - NO_OP
literal|0x000
block|,
comment|// 0x161 = 353 - NO_OP
literal|0x0ff
block|,
comment|// 0x162 = 354 - JUMP
literal|0x07e
block|,
comment|// 0x163 = 355 -
literal|0x013
block|,
comment|// 0x164 = 356 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x165 = 357 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x166 = 358 -
literal|0x0ff
block|,
comment|// 0x167 = 359 - JUMP
literal|0x042
block|,
comment|// 0x168 = 360 -
literal|0x017
block|,
comment|// 0x169 = 361 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x16a = 362 - JUMP
literal|0x17b
block|,
comment|// 0x16b = 363 -
literal|0x018
block|,
comment|// 0x16c = 364 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x16d = 365 - JUMP
literal|0x17b
block|,
comment|// 0x16e = 366 -
literal|0x01a
block|,
comment|// 0x16f = 367 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x170 = 368 - JUMP
literal|0x17b
block|,
comment|// 0x171 = 369 -
literal|0x015
block|,
comment|// 0x172 = 370 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x173 = 371 - JUMP
literal|0x17b
block|,
comment|// 0x174 = 372 -
literal|0x014
block|,
comment|// 0x175 = 373 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x081
block|,
comment|// 0x176 = 374 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x177 = 375 -
literal|0x0ff
block|,
comment|// 0x178 = 376 - JUMP
literal|0x17b
block|,
comment|// 0x179 = 377 -
literal|0x024
block|,
comment|// 0x17a = 378 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x0ff
block|,
comment|// 0x17d = 381 - JUMP
literal|0x07e
block|,
comment|// 0x17e = 382 -
literal|0x010
block|,
comment|// 0x17f = 383 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x180 = 384 - JUMP
literal|0x139
block|,
comment|// 0x181 = 385 -
literal|0x000
block|,
comment|// 0x182 = 386 - NO_OP
literal|0x000
block|,
comment|// 0x183 = 387 - NO_OP
literal|0x000
block|,
comment|// 0x184 = 388 - NO_OP
literal|0x000
block|,
comment|// 0x185 = 389 - NO_OP
literal|0x000
block|,
comment|// 0x186 = 390 - NO_OP
literal|0x000
block|,
comment|// 0x187 = 391 - NO_OP
literal|0x000
block|,
comment|// 0x188 = 392 - NO_OP
literal|0x000
block|,
comment|// 0x189 = 393 - NO_OP
literal|0x000
block|,
comment|// 0x18a = 394 - NO_OP
literal|0x000
block|,
comment|// 0x18b = 395 - NO_OP
literal|0x000
block|,
comment|// 0x18c = 396 - NO_OP
literal|0x000
block|,
comment|// 0x18d = 397 - NO_OP
literal|0x000
block|,
comment|// 0x18e = 398 - NO_OP
literal|0x000
block|,
comment|// 0x18f = 399 - NO_OP
literal|0x000
block|,
comment|// 0x190 = 400 - NO_OP
literal|0x000
block|,
comment|// 0x191 = 401 - NO_OP
literal|0x000
block|,
comment|// 0x192 = 402 - NO_OP
literal|0x000
block|,
comment|// 0x193 = 403 - NO_OP
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x000
block|,
comment|// 0x198 = 408 - NO_OP
literal|0x000
block|,
comment|// 0x199 = 409 - NO_OP
literal|0x000
block|,
comment|// 0x19a = 410 - NO_OP
literal|0x000
block|,
comment|// 0x19b = 411 - NO_OP
literal|0x000
block|,
comment|// 0x19c = 412 - NO_OP
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wcs with A1304_24 and A1305_28 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImage1304_24
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x002
block|,
comment|// 0x003 = 3 -
literal|0x0be
block|,
comment|// 0x004 = 4 - JUMP_IF_PHY_READY
literal|0x00e
block|,
comment|// 0x005 = 5 -
literal|0x0ae
block|,
comment|// 0x006 = 6 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x007 = 7 -
literal|0x0af
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x017
block|,
comment|// 0x009 = 9 -
literal|0x0ce
block|,
comment|// 0x00a = 10 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x00b = 11 -
literal|0x0ff
block|,
comment|// 0x00c = 12 - JUMP
literal|0x004
block|,
comment|// 0x00d = 13 -
literal|0x00c
block|,
comment|// 0x00e = 14 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00f = 15 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x010 = 16 -
literal|0x0af
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01c
block|,
comment|// 0x012 = 18 -
literal|0x0ce
block|,
comment|// 0x013 = 19 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x014 = 20 -
literal|0x0ff
block|,
comment|// 0x015 = 21 - JUMP
literal|0x00f
block|,
comment|// 0x016 = 22 -
literal|0x0be
block|,
comment|// 0x017 = 23 - JUMP_IF_PHY_READY
literal|0x01b
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x01c = 28 - NO_OP
literal|0x000
block|,
comment|// 0x01d = 29 - NO_OP
literal|0x000
block|,
comment|// 0x01e = 30 - NO_OP
literal|0x000
block|,
comment|// 0x01f = 31 - NO_OP
literal|0x000
block|,
comment|// 0x020 = 32 - NO_OP
literal|0x000
block|,
comment|// 0x021 = 33 - NO_OP
literal|0x0ff
block|,
comment|// 0x022 = 34 - JUMP
literal|0x09c
block|,
comment|// 0x023 = 35 -
literal|0x01c
block|,
comment|// 0x024 = 36 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x025 = 37 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x026 = 38 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x027 = 39 - JUMP_IF_PHY_READY
literal|0x027
block|,
comment|// 0x028 = 40 -
literal|0x0be
block|,
comment|// 0x029 = 41 - JUMP_IF_PHY_READY
literal|0x02f
block|,
comment|// 0x02a = 42 -
literal|0x0af
block|,
comment|// 0x02b = 43 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x036
block|,
comment|// 0x02c = 44 -
literal|0x0ff
block|,
comment|// 0x02d = 45 - JUMP
literal|0x029
block|,
comment|// 0x02e = 46 -
literal|0x00c
block|,
comment|// 0x02f = 47 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x030 = 48 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x039
block|,
comment|// 0x031 = 49 -
literal|0x0ce
block|,
comment|// 0x032 = 50 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x024
block|,
comment|// 0x033 = 51 -
literal|0x0ff
block|,
comment|// 0x034 = 52 - JUMP
literal|0x030
block|,
comment|// 0x035 = 53 -
literal|0x00c
block|,
comment|// 0x036 = 54 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x037 = 55 - JUMP
literal|0x039
block|,
comment|// 0x038 = 56 -
literal|0x000
block|,
comment|// 0x039 = 57 - NO_OP
literal|0x0cb
block|,
comment|// 0x03a = 58 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03b = 59 -
literal|0x0ff
block|,
comment|// 0x03c = 60 - JUMP
literal|0x03a
block|,
comment|// 0x03d = 61 -
literal|0x0cb
block|,
comment|// 0x03e = 62 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03f = 63 -
literal|0x0ff
block|,
comment|// 0x040 = 64 - JUMP
literal|0x09c
block|,
comment|// 0x041 = 65 -
literal|0x000
block|,
comment|// 0x042 = 66 - NO_OP
literal|0x0c9
block|,
comment|// 0x043 = 67 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x073
block|,
comment|// 0x044 = 68 -
literal|0x0a5
block|,
comment|// 0x045 = 69 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x05c
block|,
comment|// 0x046 = 70 -
literal|0x0a6
block|,
comment|// 0x047 = 71 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x063
block|,
comment|// 0x048 = 72 -
literal|0x0a7
block|,
comment|// 0x049 = 73 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x066
block|,
comment|// 0x04a = 74 -
literal|0x0a8
block|,
comment|// 0x04b = 75 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x070
block|,
comment|// 0x04c = 76 -
literal|0x0aa
block|,
comment|// 0x04d = 77 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x06b
block|,
comment|// 0x04e = 78 -
literal|0x0c5
block|,
comment|// 0x04f = 79 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x070
block|,
comment|// 0x050 = 80 -
literal|0x0ac
block|,
comment|// 0x051 = 81 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x063
block|,
comment|// 0x052 = 82 -
literal|0x0d9
block|,
comment|// 0x053 = 83 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_FREEZE_TIMEOUT
literal|0x070
block|,
comment|// 0x054 = 84 -
literal|0x0ca
block|,
comment|// 0x055 = 85 - JUMP_IF_CLOSE_REQ
literal|0x0f0
block|,
comment|// 0x056 = 86 -
literal|0x0be
block|,
comment|// 0x057 = 87 - JUMP_IF_PHY_READY
literal|0x043
block|,
comment|// 0x058 = 88 -
literal|0x01c
block|,
comment|// 0x059 = 89 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x004
block|,
comment|// 0x05b = 91 -
literal|0x01d
block|,
comment|// 0x05c = 92 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05d = 93 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x05e = 94 -
literal|0x0c3
block|,
comment|// 0x05f = 95 - JUMP_IF_SMP_PROTOCOL
literal|0x128
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x076
block|,
comment|// 0x062 = 98 -
literal|0x01d
block|,
comment|// 0x063 = 99 - ADVANCE
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x076
block|,
comment|// 0x065 = 101 -
literal|0x01d
block|,
comment|// 0x066 = 102 - ADVANCE
literal|0x0bc
block|,
comment|// 0x067 = 103 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x068 = 104 -
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x147
block|,
comment|// 0x06a = 106 -
literal|0x01d
block|,
comment|// 0x06b = 107 - ADVANCE
literal|0x0bc
block|,
comment|// 0x06c = 108 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x06d = 109 -
literal|0x0ff
block|,
comment|// 0x06e = 110 - JUMP
literal|0x14a
block|,
comment|// 0x06f = 111 -
literal|0x01d
block|,
comment|// 0x070 = 112 - ADVANCE
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x13b
block|,
comment|// 0x072 = 114 -
literal|0x022
block|,
comment|// 0x073 = 115 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x045
block|,
comment|// 0x075 = 117 -
literal|0x083
block|,
comment|// 0x076 = 118 - TIMER_START
literal|0x004
block|,
comment|// 0x077 = 119 -
literal|0x0c8
block|,
comment|// 0x078 = 120 - JUMP_IF_HIP_REQ
literal|0x082
block|,
comment|// 0x079 = 121 -
literal|0x0c6
block|,
comment|// 0x07a = 122 - JUMP_IF_SFO_REQ
literal|0x08a
block|,
comment|// 0x07b = 123 -
literal|0x0c7
block|,
comment|// 0x07c = 124 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x07d = 125 -
literal|0x0b8
block|,
comment|// 0x07e = 126 - JUMP_IF_TIMER_EXPIRED
literal|0x09c
block|,
comment|// 0x07f = 127 -
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x078
block|,
comment|// 0x081 = 129 -
literal|0x028
block|,
comment|// 0x082 = 130 - CHECK_HIP
literal|0x000
block|,
comment|// 0x083 = 131 - NO_OP
literal|0x000
block|,
comment|// 0x084 = 132 - NO_OP
literal|0x000
block|,
comment|// 0x085 = 133 - NO_OP
literal|0x0d8
block|,
comment|// 0x086 = 134 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x07e
block|,
comment|// 0x089 = 137 -
literal|0x029
block|,
comment|// 0x08a = 138 - CHECK_SFO
literal|0x000
block|,
comment|// 0x08b = 139 - NO_OP
literal|0x000
block|,
comment|// 0x08c = 140 - NO_OP
literal|0x000
block|,
comment|// 0x08d = 141 - NO_OP
literal|0x0d8
block|,
comment|// 0x08e = 142 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x08f = 143 -
literal|0x0c7
block|,
comment|// 0x090 = 144 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x091 = 145 -
literal|0x0ff
block|,
comment|// 0x092 = 146 - JUMP
literal|0x07e
block|,
comment|// 0x093 = 147 -
literal|0x02a
block|,
comment|// 0x094 = 148 - CHECK_DOC
literal|0x000
block|,
comment|// 0x095 = 149 - NO_OP
literal|0x000
block|,
comment|// 0x096 = 150 - NO_OP
literal|0x000
block|,
comment|// 0x097 = 151 - NO_OP
literal|0x0d8
block|,
comment|// 0x098 = 152 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x099 = 153 -
literal|0x0ff
block|,
comment|// 0x09a = 154 - JUMP
literal|0x07e
block|,
comment|// 0x09b = 155 -
literal|0x0bc
block|,
comment|// 0x09c = 156 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x09d = 157 -
literal|0x0be
block|,
comment|// 0x09e = 158 - JUMP_IF_PHY_READY
literal|0x0a3
block|,
comment|// 0x09f = 159 -
literal|0x01c
block|,
comment|// 0x0a0 = 160 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0a1 = 161 - JUMP
literal|0x004
block|,
comment|// 0x0a2 = 162 -
literal|0x0c8
block|,
comment|// 0x0a3 = 163 - JUMP_IF_HIP_REQ
literal|0x0b5
block|,
comment|// 0x0a4 = 164 -
literal|0x0c6
block|,
comment|// 0x0a5 = 165 - JUMP_IF_SFO_REQ
literal|0x0bd
block|,
comment|// 0x0a6 = 166 -
literal|0x0c7
block|,
comment|// 0x0a7 = 167 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0a8 = 168 -
literal|0x0a3
block|,
comment|// 0x0a9 = 169 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0aa = 170 -
literal|0x0a2
block|,
comment|// 0x0ab = 171 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0f0
block|,
comment|// 0x0ac = 172 -
literal|0x0c8
block|,
comment|// 0x0ad = 173 - JUMP_IF_HIP_REQ
literal|0x0cf
block|,
comment|// 0x0ae = 174 -
literal|0x0c6
block|,
comment|// 0x0af = 175 - JUMP_IF_SFO_REQ
literal|0x0d4
block|,
comment|// 0x0b0 = 176 -
literal|0x0c7
block|,
comment|// 0x0b1 = 177 - JUMP_IF_DOC_REQ
literal|0x0d9
block|,
comment|// 0x0b2 = 178 -
literal|0x0ff
block|,
comment|// 0x0b3 = 179 - JUMP
literal|0x09c
block|,
comment|// 0x0b4 = 180 -
literal|0x028
block|,
comment|// 0x0b5 = 181 - CHECK_HIP
literal|0x000
block|,
comment|// 0x0b6 = 182 - NO_OP
literal|0x000
block|,
comment|// 0x0b7 = 183 - NO_OP
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x0d8
block|,
comment|// 0x0b9 = 185 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x0ba = 186 -
literal|0x0ff
block|,
comment|// 0x0bb = 187 - JUMP
literal|0x0a9
block|,
comment|// 0x0bc = 188 -
literal|0x029
block|,
comment|// 0x0bd = 189 - CHECK_SFO
literal|0x000
block|,
comment|// 0x0be = 190 - NO_OP
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x0d8
block|,
comment|// 0x0c1 = 193 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x0c2 = 194 -
literal|0x0c7
block|,
comment|// 0x0c3 = 195 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0c4 = 196 -
literal|0x0ff
block|,
comment|// 0x0c5 = 197 - JUMP
literal|0x0a9
block|,
comment|// 0x0c6 = 198 -
literal|0x02a
block|,
comment|// 0x0c7 = 199 - CHECK_DOC
literal|0x000
block|,
comment|// 0x0c8 = 200 - NO_OP
literal|0x000
block|,
comment|// 0x0c9 = 201 - NO_OP
literal|0x000
block|,
comment|// 0x0ca = 202 - NO_OP
literal|0x0d8
block|,
comment|// 0x0cb = 203 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x0cc = 204 -
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x0a9
block|,
comment|// 0x0ce = 206 -
literal|0x020
block|,
comment|// 0x0cf = 207 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d2 = 210 - JUMP
literal|0x0dc
block|,
comment|// 0x0d3 = 211 -
literal|0x01e
block|,
comment|// 0x0d4 = 212 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0d5 = 213 - NO_OP
literal|0x000
block|,
comment|// 0x0d6 = 214 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x0dc
block|,
comment|// 0x0d8 = 216 -
literal|0x01f
block|,
comment|// 0x0d9 = 217 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0da = 218 - NO_OP
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0a4
block|,
comment|// 0x0dc = 220 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0e0
block|,
comment|// 0x0dd = 221 -
literal|0x0ff
block|,
comment|// 0x0de = 222 - JUMP
literal|0x14d
block|,
comment|// 0x0df = 223 -
literal|0x0a0
block|,
comment|// 0x0e0 = 224 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e6
block|,
comment|// 0x0e1 = 225 -
literal|0x0a3
block|,
comment|// 0x0e2 = 226 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0e3 = 227 -
literal|0x0ff
block|,
comment|// 0x0e4 = 228 - JUMP
literal|0x128
block|,
comment|// 0x0e5 = 229 -
literal|0x0cb
block|,
comment|// 0x0e6 = 230 - JUMP_IF_FREEZE_ACTIVE
literal|0x0eb
block|,
comment|// 0x0e7 = 231 -
literal|0x013
block|,
comment|// 0x0e8 = 232 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0e9 = 233 - JUMP
literal|0x042
block|,
comment|// 0x0ea = 234 -
literal|0x024
block|,
comment|// 0x0eb = 235 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0ec = 236 - NO_OP
literal|0x000
block|,
comment|// 0x0ed = 237 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ee = 238 - JUMP
literal|0x09c
block|,
comment|// 0x0ef = 239 -
literal|0x0d2
block|,
comment|// 0x0f0 = 240 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0f4
block|,
comment|// 0x0f1 = 241 -
literal|0x0ff
block|,
comment|// 0x0f2 = 242 - JUMP
literal|0x128
block|,
comment|// 0x0f3 = 243 -
literal|0x0d5
block|,
comment|// 0x0f4 = 244 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x0f5 = 245 -
literal|0x0d6
block|,
comment|// 0x0f6 = 246 - JUMP_IF_SYNC_RECEIVED
literal|0x0fa
block|,
comment|// 0x0f7 = 247 -
literal|0x0ff
block|,
comment|// 0x0f8 = 248 - JUMP
literal|0x09c
block|,
comment|// 0x0f9 = 249 -
literal|0x027
block|,
comment|// 0x0fa = 250 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0fb = 251 - NO_OP
literal|0x000
block|,
comment|// 0x0fc = 252 - NO_OP
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x000
block|,
comment|// 0x0fe = 254 - NO_OP
literal|0x0d5
block|,
comment|// 0x0ff = 255 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x100 = 256 -
literal|0x0bc
block|,
comment|// 0x101 = 257 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x102 = 258 -
literal|0x0d7
block|,
comment|// 0x103 = 259 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x104 = 260 -
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x0fb
block|,
comment|// 0x106 = 262 -
literal|0x0c3
block|,
comment|// 0x107 = 263 - JUMP_IF_SMP_PROTOCOL
literal|0x10f
block|,
comment|// 0x108 = 264 -
literal|0x0d2
block|,
comment|// 0x109 = 265 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x113
block|,
comment|// 0x10a = 266 -
literal|0x0d1
block|,
comment|// 0x10b = 267 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x119
block|,
comment|// 0x10c = 268 -
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x09c
block|,
comment|// 0x10e = 270 -
literal|0x0c4
block|,
comment|// 0x10f = 271 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x13b
block|,
comment|// 0x110 = 272 -
literal|0x0ff
block|,
comment|// 0x111 = 273 - JUMP
literal|0x0ad
block|,
comment|// 0x112 = 274 -
literal|0x0d5
block|,
comment|// 0x113 = 275 - JUMP_IF_CLOSE_RECEIVED
literal|0x119
block|,
comment|// 0x114 = 276 -
literal|0x0d6
block|,
comment|// 0x115 = 277 - JUMP_IF_SYNC_RECEIVED
literal|0x11b
block|,
comment|// 0x116 = 278 -
literal|0x0ff
block|,
comment|// 0x117 = 279 - JUMP
literal|0x113
block|,
comment|// 0x118 = 280 -
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x128
block|,
comment|// 0x11a = 282 -
literal|0x027
block|,
comment|// 0x11b = 283 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x0d5
block|,
comment|// 0x120 = 288 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x121 = 289 -
literal|0x0bc
block|,
comment|// 0x122 = 290 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x123 = 291 -
literal|0x0d7
block|,
comment|// 0x124 = 292 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x125 = 293 -
literal|0x0ff
block|,
comment|// 0x126 = 294 - JUMP
literal|0x11c
block|,
comment|// 0x127 = 295 -
literal|0x004
block|,
comment|// 0x128 = 296 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x0c9
block|,
comment|// 0x12d = 301 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x138
block|,
comment|// 0x12e = 302 -
literal|0x0c0
block|,
comment|// 0x12f = 303 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x130 = 304 -
literal|0x0bc
block|,
comment|// 0x131 = 305 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x132 = 306 -
literal|0x0be
block|,
comment|// 0x133 = 307 - JUMP_IF_PHY_READY
literal|0x129
block|,
comment|// 0x134 = 308 -
literal|0x01c
block|,
comment|// 0x135 = 309 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x004
block|,
comment|// 0x137 = 311 -
literal|0x022
block|,
comment|// 0x138 = 312 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x139 = 313 - JUMP
literal|0x129
block|,
comment|// 0x13a = 314 -
literal|0x007
block|,
comment|// 0x13b = 315 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x0c0
block|,
comment|// 0x140 = 320 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x141 = 321 -
literal|0x0be
block|,
comment|// 0x142 = 322 - JUMP_IF_PHY_READY
literal|0x13c
block|,
comment|// 0x143 = 323 -
literal|0x01c
block|,
comment|// 0x144 = 324 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x145 = 325 - JUMP
literal|0x004
block|,
comment|// 0x146 = 326 -
literal|0x005
block|,
comment|// 0x147 = 327 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x148 = 328 - JUMP
literal|0x129
block|,
comment|// 0x149 = 329 -
literal|0x006
block|,
comment|// 0x14a = 330 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x14b = 331 - JUMP
literal|0x129
block|,
comment|// 0x14c = 332 -
literal|0x0cc
block|,
comment|// 0x14d = 333 - JUMP_IF_RX_BUFFER_FULL
literal|0x09c
block|,
comment|// 0x14e = 334 -
literal|0x0b7
block|,
comment|// 0x14f = 335 - JUMP_IF_FLAG_7_SET
literal|0x154
block|,
comment|// 0x150 = 336 -
literal|0x011
block|,
comment|// 0x151 = 337 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x152 = 338 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x153 = 339 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x154 = 340 - JUMP_IF_FREEZE_ACTIVE
literal|0x195
block|,
comment|// 0x155 = 341 -
literal|0x001
block|,
comment|// 0x156 = 342 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x157 = 343 - SET_FLAG
literal|0x080
block|,
comment|// 0x158 = 344 -
literal|0x090
block|,
comment|// 0x159 = 345 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x17f
block|,
comment|// 0x15a = 346 -
literal|0x095
block|,
comment|// 0x15b = 347 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x184
block|,
comment|// 0x15c = 348 -
literal|0x099
block|,
comment|// 0x15d = 349 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x187
block|,
comment|// 0x15e = 350 -
literal|0x09b
block|,
comment|// 0x15f = 351 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x18a
block|,
comment|// 0x160 = 352 -
literal|0x094
block|,
comment|// 0x161 = 353 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x154
block|,
comment|// 0x162 = 354 -
literal|0x093
block|,
comment|// 0x163 = 355 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x18d
block|,
comment|// 0x164 = 356 -
literal|0x09f
block|,
comment|// 0x165 = 357 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x190
block|,
comment|// 0x166 = 358 -
literal|0x09a
block|,
comment|// 0x167 = 359 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x153
block|,
comment|// 0x168 = 360 -
literal|0x096
block|,
comment|// 0x169 = 361 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x154
block|,
comment|// 0x16a = 362 -
literal|0x097
block|,
comment|// 0x16b = 363 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x19a
block|,
comment|// 0x16c = 364 -
literal|0x098
block|,
comment|// 0x16d = 365 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x153
block|,
comment|// 0x16e = 366 -
literal|0x092
block|,
comment|// 0x16f = 367 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x154
block|,
comment|// 0x170 = 368 -
literal|0x0a4
block|,
comment|// 0x171 = 369 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x179
block|,
comment|// 0x172 = 370 -
literal|0x0be
block|,
comment|// 0x173 = 371 - JUMP_IF_PHY_READY
literal|0x159
block|,
comment|// 0x174 = 372 -
literal|0x01b
block|,
comment|// 0x175 = 373 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x176 = 374 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x177 = 375 - JUMP
literal|0x004
block|,
comment|// 0x178 = 376 -
literal|0x0a0
block|,
comment|// 0x179 = 377 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x17f
block|,
comment|// 0x17a = 378 -
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x0ff
block|,
comment|// 0x17d = 381 - JUMP
literal|0x09c
block|,
comment|// 0x17e = 382 -
literal|0x013
block|,
comment|// 0x17f = 383 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x180 = 384 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x181 = 385 -
literal|0x0ff
block|,
comment|// 0x182 = 386 - JUMP
literal|0x042
block|,
comment|// 0x183 = 387 -
literal|0x017
block|,
comment|// 0x184 = 388 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x185 = 389 - JUMP
literal|0x196
block|,
comment|// 0x186 = 390 -
literal|0x018
block|,
comment|// 0x187 = 391 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x188 = 392 - JUMP
literal|0x196
block|,
comment|// 0x189 = 393 -
literal|0x01a
block|,
comment|// 0x18a = 394 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x18b = 395 - JUMP
literal|0x196
block|,
comment|// 0x18c = 396 -
literal|0x015
block|,
comment|// 0x18d = 397 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x18e = 398 - JUMP
literal|0x196
block|,
comment|// 0x18f = 399 -
literal|0x014
block|,
comment|// 0x190 = 400 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x081
block|,
comment|// 0x191 = 401 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x192 = 402 -
literal|0x0ff
block|,
comment|// 0x193 = 403 - JUMP
literal|0x196
block|,
comment|// 0x194 = 404 -
literal|0x024
block|,
comment|// 0x195 = 405 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x0ff
block|,
comment|// 0x198 = 408 - JUMP
literal|0x09c
block|,
comment|// 0x199 = 409 -
literal|0x010
block|,
comment|// 0x19a = 410 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x19b = 411 - JUMP
literal|0x154
block|,
comment|// 0x19c = 412 -
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wcs with A1306_02 and A1307_06 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImageA1306_02
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x002
block|,
comment|// 0x003 = 3 -
literal|0x0be
block|,
comment|// 0x004 = 4 - JUMP_IF_PHY_READY
literal|0x00e
block|,
comment|// 0x005 = 5 -
literal|0x0ae
block|,
comment|// 0x006 = 6 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x007 = 7 -
literal|0x0af
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x017
block|,
comment|// 0x009 = 9 -
literal|0x0ce
block|,
comment|// 0x00a = 10 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x00b = 11 -
literal|0x0ff
block|,
comment|// 0x00c = 12 - JUMP
literal|0x004
block|,
comment|// 0x00d = 13 -
literal|0x00c
block|,
comment|// 0x00e = 14 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00f = 15 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x010 = 16 -
literal|0x0af
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01c
block|,
comment|// 0x012 = 18 -
literal|0x0ce
block|,
comment|// 0x013 = 19 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x014 = 20 -
literal|0x0ff
block|,
comment|// 0x015 = 21 - JUMP
literal|0x00f
block|,
comment|// 0x016 = 22 -
literal|0x0be
block|,
comment|// 0x017 = 23 - JUMP_IF_PHY_READY
literal|0x01b
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x01c = 28 - NO_OP
literal|0x000
block|,
comment|// 0x01d = 29 - NO_OP
literal|0x000
block|,
comment|// 0x01e = 30 - NO_OP
literal|0x000
block|,
comment|// 0x01f = 31 - NO_OP
literal|0x000
block|,
comment|// 0x020 = 32 - NO_OP
literal|0x000
block|,
comment|// 0x021 = 33 - NO_OP
literal|0x0ff
block|,
comment|// 0x022 = 34 - JUMP
literal|0x09c
block|,
comment|// 0x023 = 35 -
literal|0x01c
block|,
comment|// 0x024 = 36 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x025 = 37 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x026 = 38 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x027 = 39 - JUMP_IF_PHY_READY
literal|0x027
block|,
comment|// 0x028 = 40 -
literal|0x0be
block|,
comment|// 0x029 = 41 - JUMP_IF_PHY_READY
literal|0x02f
block|,
comment|// 0x02a = 42 -
literal|0x0af
block|,
comment|// 0x02b = 43 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x036
block|,
comment|// 0x02c = 44 -
literal|0x0ff
block|,
comment|// 0x02d = 45 - JUMP
literal|0x029
block|,
comment|// 0x02e = 46 -
literal|0x00c
block|,
comment|// 0x02f = 47 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x030 = 48 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x039
block|,
comment|// 0x031 = 49 -
literal|0x0ce
block|,
comment|// 0x032 = 50 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x024
block|,
comment|// 0x033 = 51 -
literal|0x0ff
block|,
comment|// 0x034 = 52 - JUMP
literal|0x030
block|,
comment|// 0x035 = 53 -
literal|0x00c
block|,
comment|// 0x036 = 54 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x037 = 55 - JUMP
literal|0x039
block|,
comment|// 0x038 = 56 -
literal|0x000
block|,
comment|// 0x039 = 57 - NO_OP
literal|0x0cb
block|,
comment|// 0x03a = 58 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03b = 59 -
literal|0x0ff
block|,
comment|// 0x03c = 60 - JUMP
literal|0x03a
block|,
comment|// 0x03d = 61 -
literal|0x0cb
block|,
comment|// 0x03e = 62 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03f = 63 -
literal|0x0ff
block|,
comment|// 0x040 = 64 - JUMP
literal|0x09c
block|,
comment|// 0x041 = 65 -
literal|0x000
block|,
comment|// 0x042 = 66 - NO_OP
literal|0x0c9
block|,
comment|// 0x043 = 67 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x073
block|,
comment|// 0x044 = 68 -
literal|0x0a5
block|,
comment|// 0x045 = 69 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x05c
block|,
comment|// 0x046 = 70 -
literal|0x0a6
block|,
comment|// 0x047 = 71 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x063
block|,
comment|// 0x048 = 72 -
literal|0x0a7
block|,
comment|// 0x049 = 73 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x066
block|,
comment|// 0x04a = 74 -
literal|0x0a8
block|,
comment|// 0x04b = 75 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x070
block|,
comment|// 0x04c = 76 -
literal|0x0aa
block|,
comment|// 0x04d = 77 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x06b
block|,
comment|// 0x04e = 78 -
literal|0x0c5
block|,
comment|// 0x04f = 79 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x070
block|,
comment|// 0x050 = 80 -
literal|0x0ac
block|,
comment|// 0x051 = 81 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x063
block|,
comment|// 0x052 = 82 -
literal|0x0d9
block|,
comment|// 0x053 = 83 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_FREEZE_TIMEOUT
literal|0x070
block|,
comment|// 0x054 = 84 -
literal|0x0ca
block|,
comment|// 0x055 = 85 - JUMP_IF_CLOSE_REQ
literal|0x0f0
block|,
comment|// 0x056 = 86 -
literal|0x0be
block|,
comment|// 0x057 = 87 - JUMP_IF_PHY_READY
literal|0x043
block|,
comment|// 0x058 = 88 -
literal|0x01c
block|,
comment|// 0x059 = 89 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x004
block|,
comment|// 0x05b = 91 -
literal|0x01d
block|,
comment|// 0x05c = 92 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05d = 93 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x05e = 94 -
literal|0x0c3
block|,
comment|// 0x05f = 95 - JUMP_IF_SMP_PROTOCOL
literal|0x128
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x076
block|,
comment|// 0x062 = 98 -
literal|0x01d
block|,
comment|// 0x063 = 99 - ADVANCE
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x076
block|,
comment|// 0x065 = 101 -
literal|0x01d
block|,
comment|// 0x066 = 102 - ADVANCE
literal|0x0bc
block|,
comment|// 0x067 = 103 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x068 = 104 -
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x147
block|,
comment|// 0x06a = 106 -
literal|0x01d
block|,
comment|// 0x06b = 107 - ADVANCE
literal|0x0bc
block|,
comment|// 0x06c = 108 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x06d = 109 -
literal|0x0ff
block|,
comment|// 0x06e = 110 - JUMP
literal|0x14a
block|,
comment|// 0x06f = 111 -
literal|0x01d
block|,
comment|// 0x070 = 112 - ADVANCE
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x13b
block|,
comment|// 0x072 = 114 -
literal|0x022
block|,
comment|// 0x073 = 115 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x045
block|,
comment|// 0x075 = 117 -
literal|0x083
block|,
comment|// 0x076 = 118 - TIMER_START
literal|0x004
block|,
comment|// 0x077 = 119 -
literal|0x0c8
block|,
comment|// 0x078 = 120 - JUMP_IF_HIP_REQ
literal|0x082
block|,
comment|// 0x079 = 121 -
literal|0x0c6
block|,
comment|// 0x07a = 122 - JUMP_IF_SFO_REQ
literal|0x08a
block|,
comment|// 0x07b = 123 -
literal|0x0c7
block|,
comment|// 0x07c = 124 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x07d = 125 -
literal|0x0b8
block|,
comment|// 0x07e = 126 - JUMP_IF_TIMER_EXPIRED
literal|0x09c
block|,
comment|// 0x07f = 127 -
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x078
block|,
comment|// 0x081 = 129 -
literal|0x028
block|,
comment|// 0x082 = 130 - CHECK_HIP
literal|0x000
block|,
comment|// 0x083 = 131 - NO_OP
literal|0x000
block|,
comment|// 0x084 = 132 - NO_OP
literal|0x000
block|,
comment|// 0x085 = 133 - NO_OP
literal|0x0d8
block|,
comment|// 0x086 = 134 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x07e
block|,
comment|// 0x089 = 137 -
literal|0x029
block|,
comment|// 0x08a = 138 - CHECK_SFO
literal|0x000
block|,
comment|// 0x08b = 139 - NO_OP
literal|0x000
block|,
comment|// 0x08c = 140 - NO_OP
literal|0x000
block|,
comment|// 0x08d = 141 - NO_OP
literal|0x0d8
block|,
comment|// 0x08e = 142 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x08f = 143 -
literal|0x0c7
block|,
comment|// 0x090 = 144 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x091 = 145 -
literal|0x0ff
block|,
comment|// 0x092 = 146 - JUMP
literal|0x07e
block|,
comment|// 0x093 = 147 -
literal|0x02a
block|,
comment|// 0x094 = 148 - CHECK_DOC
literal|0x000
block|,
comment|// 0x095 = 149 - NO_OP
literal|0x000
block|,
comment|// 0x096 = 150 - NO_OP
literal|0x000
block|,
comment|// 0x097 = 151 - NO_OP
literal|0x0d8
block|,
comment|// 0x098 = 152 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x099 = 153 -
literal|0x0ff
block|,
comment|// 0x09a = 154 - JUMP
literal|0x07e
block|,
comment|// 0x09b = 155 -
literal|0x0bc
block|,
comment|// 0x09c = 156 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x09d = 157 -
literal|0x0be
block|,
comment|// 0x09e = 158 - JUMP_IF_PHY_READY
literal|0x0a3
block|,
comment|// 0x09f = 159 -
literal|0x01c
block|,
comment|// 0x0a0 = 160 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0a1 = 161 - JUMP
literal|0x004
block|,
comment|// 0x0a2 = 162 -
literal|0x0c8
block|,
comment|// 0x0a3 = 163 - JUMP_IF_HIP_REQ
literal|0x0b5
block|,
comment|// 0x0a4 = 164 -
literal|0x0c6
block|,
comment|// 0x0a5 = 165 - JUMP_IF_SFO_REQ
literal|0x0bd
block|,
comment|// 0x0a6 = 166 -
literal|0x0c7
block|,
comment|// 0x0a7 = 167 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0a8 = 168 -
literal|0x0a3
block|,
comment|// 0x0a9 = 169 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0aa = 170 -
literal|0x0a2
block|,
comment|// 0x0ab = 171 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0f0
block|,
comment|// 0x0ac = 172 -
literal|0x0c8
block|,
comment|// 0x0ad = 173 - JUMP_IF_HIP_REQ
literal|0x0cf
block|,
comment|// 0x0ae = 174 -
literal|0x0c6
block|,
comment|// 0x0af = 175 - JUMP_IF_SFO_REQ
literal|0x0d4
block|,
comment|// 0x0b0 = 176 -
literal|0x0c7
block|,
comment|// 0x0b1 = 177 - JUMP_IF_DOC_REQ
literal|0x0d9
block|,
comment|// 0x0b2 = 178 -
literal|0x0ff
block|,
comment|// 0x0b3 = 179 - JUMP
literal|0x09c
block|,
comment|// 0x0b4 = 180 -
literal|0x028
block|,
comment|// 0x0b5 = 181 - CHECK_HIP
literal|0x000
block|,
comment|// 0x0b6 = 182 - NO_OP
literal|0x000
block|,
comment|// 0x0b7 = 183 - NO_OP
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x0d8
block|,
comment|// 0x0b9 = 185 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x0ba = 186 -
literal|0x0ff
block|,
comment|// 0x0bb = 187 - JUMP
literal|0x0a9
block|,
comment|// 0x0bc = 188 -
literal|0x029
block|,
comment|// 0x0bd = 189 - CHECK_SFO
literal|0x000
block|,
comment|// 0x0be = 190 - NO_OP
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x0d8
block|,
comment|// 0x0c1 = 193 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x0c2 = 194 -
literal|0x0c7
block|,
comment|// 0x0c3 = 195 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0c4 = 196 -
literal|0x0ff
block|,
comment|// 0x0c5 = 197 - JUMP
literal|0x0a9
block|,
comment|// 0x0c6 = 198 -
literal|0x02a
block|,
comment|// 0x0c7 = 199 - CHECK_DOC
literal|0x000
block|,
comment|// 0x0c8 = 200 - NO_OP
literal|0x000
block|,
comment|// 0x0c9 = 201 - NO_OP
literal|0x000
block|,
comment|// 0x0ca = 202 - NO_OP
literal|0x0d8
block|,
comment|// 0x0cb = 203 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x0cc = 204 -
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x0a9
block|,
comment|// 0x0ce = 206 -
literal|0x020
block|,
comment|// 0x0cf = 207 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d2 = 210 - JUMP
literal|0x0dc
block|,
comment|// 0x0d3 = 211 -
literal|0x01e
block|,
comment|// 0x0d4 = 212 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0d5 = 213 - NO_OP
literal|0x000
block|,
comment|// 0x0d6 = 214 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x0dc
block|,
comment|// 0x0d8 = 216 -
literal|0x01f
block|,
comment|// 0x0d9 = 217 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0da = 218 - NO_OP
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0a4
block|,
comment|// 0x0dc = 220 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0e0
block|,
comment|// 0x0dd = 221 -
literal|0x0ff
block|,
comment|// 0x0de = 222 - JUMP
literal|0x14d
block|,
comment|// 0x0df = 223 -
literal|0x0a0
block|,
comment|// 0x0e0 = 224 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e6
block|,
comment|// 0x0e1 = 225 -
literal|0x0a3
block|,
comment|// 0x0e2 = 226 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0e3 = 227 -
literal|0x0ff
block|,
comment|// 0x0e4 = 228 - JUMP
literal|0x128
block|,
comment|// 0x0e5 = 229 -
literal|0x0cb
block|,
comment|// 0x0e6 = 230 - JUMP_IF_FREEZE_ACTIVE
literal|0x0eb
block|,
comment|// 0x0e7 = 231 -
literal|0x013
block|,
comment|// 0x0e8 = 232 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0e9 = 233 - JUMP
literal|0x042
block|,
comment|// 0x0ea = 234 -
literal|0x024
block|,
comment|// 0x0eb = 235 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0ec = 236 - NO_OP
literal|0x000
block|,
comment|// 0x0ed = 237 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ee = 238 - JUMP
literal|0x09c
block|,
comment|// 0x0ef = 239 -
literal|0x0d2
block|,
comment|// 0x0f0 = 240 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0f4
block|,
comment|// 0x0f1 = 241 -
literal|0x0ff
block|,
comment|// 0x0f2 = 242 - JUMP
literal|0x128
block|,
comment|// 0x0f3 = 243 -
literal|0x0d5
block|,
comment|// 0x0f4 = 244 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x0f5 = 245 -
literal|0x0d6
block|,
comment|// 0x0f6 = 246 - JUMP_IF_SYNC_RECEIVED
literal|0x0fa
block|,
comment|// 0x0f7 = 247 -
literal|0x0ff
block|,
comment|// 0x0f8 = 248 - JUMP
literal|0x09c
block|,
comment|// 0x0f9 = 249 -
literal|0x027
block|,
comment|// 0x0fa = 250 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0fb = 251 - NO_OP
literal|0x000
block|,
comment|// 0x0fc = 252 - NO_OP
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x000
block|,
comment|// 0x0fe = 254 - NO_OP
literal|0x0d5
block|,
comment|// 0x0ff = 255 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x100 = 256 -
literal|0x0bc
block|,
comment|// 0x101 = 257 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x102 = 258 -
literal|0x0d7
block|,
comment|// 0x103 = 259 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x104 = 260 -
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x0fb
block|,
comment|// 0x106 = 262 -
literal|0x0c3
block|,
comment|// 0x107 = 263 - JUMP_IF_SMP_PROTOCOL
literal|0x10f
block|,
comment|// 0x108 = 264 -
literal|0x0d2
block|,
comment|// 0x109 = 265 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x113
block|,
comment|// 0x10a = 266 -
literal|0x0d1
block|,
comment|// 0x10b = 267 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x119
block|,
comment|// 0x10c = 268 -
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x09c
block|,
comment|// 0x10e = 270 -
literal|0x0c4
block|,
comment|// 0x10f = 271 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x13b
block|,
comment|// 0x110 = 272 -
literal|0x0ff
block|,
comment|// 0x111 = 273 - JUMP
literal|0x0ad
block|,
comment|// 0x112 = 274 -
literal|0x0d5
block|,
comment|// 0x113 = 275 - JUMP_IF_CLOSE_RECEIVED
literal|0x119
block|,
comment|// 0x114 = 276 -
literal|0x0d6
block|,
comment|// 0x115 = 277 - JUMP_IF_SYNC_RECEIVED
literal|0x11b
block|,
comment|// 0x116 = 278 -
literal|0x0ff
block|,
comment|// 0x117 = 279 - JUMP
literal|0x113
block|,
comment|// 0x118 = 280 -
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x128
block|,
comment|// 0x11a = 282 -
literal|0x027
block|,
comment|// 0x11b = 283 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x0d5
block|,
comment|// 0x120 = 288 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x121 = 289 -
literal|0x0bc
block|,
comment|// 0x122 = 290 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x123 = 291 -
literal|0x0d7
block|,
comment|// 0x124 = 292 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x125 = 293 -
literal|0x0ff
block|,
comment|// 0x126 = 294 - JUMP
literal|0x11c
block|,
comment|// 0x127 = 295 -
literal|0x004
block|,
comment|// 0x128 = 296 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x0c9
block|,
comment|// 0x12d = 301 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x138
block|,
comment|// 0x12e = 302 -
literal|0x0c0
block|,
comment|// 0x12f = 303 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x130 = 304 -
literal|0x0bc
block|,
comment|// 0x131 = 305 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x132 = 306 -
literal|0x0be
block|,
comment|// 0x133 = 307 - JUMP_IF_PHY_READY
literal|0x129
block|,
comment|// 0x134 = 308 -
literal|0x01c
block|,
comment|// 0x135 = 309 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x004
block|,
comment|// 0x137 = 311 -
literal|0x022
block|,
comment|// 0x138 = 312 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x139 = 313 - JUMP
literal|0x129
block|,
comment|// 0x13a = 314 -
literal|0x007
block|,
comment|// 0x13b = 315 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x0c0
block|,
comment|// 0x140 = 320 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x141 = 321 -
literal|0x0be
block|,
comment|// 0x142 = 322 - JUMP_IF_PHY_READY
literal|0x13c
block|,
comment|// 0x143 = 323 -
literal|0x01c
block|,
comment|// 0x144 = 324 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x145 = 325 - JUMP
literal|0x004
block|,
comment|// 0x146 = 326 -
literal|0x005
block|,
comment|// 0x147 = 327 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x148 = 328 - JUMP
literal|0x129
block|,
comment|// 0x149 = 329 -
literal|0x006
block|,
comment|// 0x14a = 330 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x14b = 331 - JUMP
literal|0x129
block|,
comment|// 0x14c = 332 -
literal|0x0cc
block|,
comment|// 0x14d = 333 - JUMP_IF_RX_BUFFER_FULL
literal|0x09c
block|,
comment|// 0x14e = 334 -
literal|0x0b7
block|,
comment|// 0x14f = 335 - JUMP_IF_FLAG_7_SET
literal|0x154
block|,
comment|// 0x150 = 336 -
literal|0x011
block|,
comment|// 0x151 = 337 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x152 = 338 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x153 = 339 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x154 = 340 - JUMP_IF_FREEZE_ACTIVE
literal|0x193
block|,
comment|// 0x155 = 341 -
literal|0x001
block|,
comment|// 0x156 = 342 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x157 = 343 - SET_FLAG
literal|0x080
block|,
comment|// 0x158 = 344 -
literal|0x090
block|,
comment|// 0x159 = 345 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x17f
block|,
comment|// 0x15a = 346 -
literal|0x095
block|,
comment|// 0x15b = 347 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x184
block|,
comment|// 0x15c = 348 -
literal|0x099
block|,
comment|// 0x15d = 349 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x187
block|,
comment|// 0x15e = 350 -
literal|0x09b
block|,
comment|// 0x15f = 351 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x18a
block|,
comment|// 0x160 = 352 -
literal|0x094
block|,
comment|// 0x161 = 353 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x154
block|,
comment|// 0x162 = 354 -
literal|0x093
block|,
comment|// 0x163 = 355 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x18d
block|,
comment|// 0x164 = 356 -
literal|0x09f
block|,
comment|// 0x165 = 357 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x190
block|,
comment|// 0x166 = 358 -
literal|0x09a
block|,
comment|// 0x167 = 359 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x153
block|,
comment|// 0x168 = 360 -
literal|0x096
block|,
comment|// 0x169 = 361 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x154
block|,
comment|// 0x16a = 362 -
literal|0x097
block|,
comment|// 0x16b = 363 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x19a
block|,
comment|// 0x16c = 364 -
literal|0x098
block|,
comment|// 0x16d = 365 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x153
block|,
comment|// 0x16e = 366 -
literal|0x092
block|,
comment|// 0x16f = 367 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x154
block|,
comment|// 0x170 = 368 -
literal|0x0a4
block|,
comment|// 0x171 = 369 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x179
block|,
comment|// 0x172 = 370 -
literal|0x0be
block|,
comment|// 0x173 = 371 - JUMP_IF_PHY_READY
literal|0x159
block|,
comment|// 0x174 = 372 -
literal|0x01b
block|,
comment|// 0x175 = 373 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x176 = 374 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x177 = 375 - JUMP
literal|0x004
block|,
comment|// 0x178 = 376 -
literal|0x0a0
block|,
comment|// 0x179 = 377 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x17f
block|,
comment|// 0x17a = 378 -
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x0ff
block|,
comment|// 0x17d = 381 - JUMP
literal|0x09c
block|,
comment|// 0x17e = 382 -
literal|0x013
block|,
comment|// 0x17f = 383 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x180 = 384 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x181 = 385 -
literal|0x0ff
block|,
comment|// 0x182 = 386 - JUMP
literal|0x042
block|,
comment|// 0x183 = 387 -
literal|0x017
block|,
comment|// 0x184 = 388 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x185 = 389 - JUMP
literal|0x194
block|,
comment|// 0x186 = 390 -
literal|0x018
block|,
comment|// 0x187 = 391 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x188 = 392 - JUMP
literal|0x194
block|,
comment|// 0x189 = 393 -
literal|0x01a
block|,
comment|// 0x18a = 394 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x18b = 395 - JUMP
literal|0x194
block|,
comment|// 0x18c = 396 -
literal|0x015
block|,
comment|// 0x18d = 397 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x18e = 398 - JUMP
literal|0x194
block|,
comment|// 0x18f = 399 -
literal|0x014
block|,
comment|// 0x190 = 400 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x191 = 401 - JUMP
literal|0x194
block|,
comment|// 0x192 = 402 -
literal|0x024
block|,
comment|// 0x193 = 403 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x081
block|,
comment|// 0x196 = 406 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x197 = 407 -
literal|0x0ff
block|,
comment|// 0x198 = 408 - JUMP
literal|0x09c
block|,
comment|// 0x199 = 409 -
literal|0x010
block|,
comment|// 0x19a = 410 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x19b = 411 - JUMP
literal|0x154
block|,
comment|// 0x19c = 412 -
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for A1307_09 */
end_comment

begin_decl_stmt
name|bit32
name|wcsImageA1307_09
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x002
block|,
comment|// 0x003 = 3 -
literal|0x0be
block|,
comment|// 0x004 = 4 - JUMP_IF_PHY_READY
literal|0x00e
block|,
comment|// 0x005 = 5 -
literal|0x0ae
block|,
comment|// 0x006 = 6 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x007 = 7 -
literal|0x0af
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x017
block|,
comment|// 0x009 = 9 -
literal|0x0ce
block|,
comment|// 0x00a = 10 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x00b = 11 -
literal|0x0ff
block|,
comment|// 0x00c = 12 - JUMP
literal|0x004
block|,
comment|// 0x00d = 13 -
literal|0x00c
block|,
comment|// 0x00e = 14 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00f = 15 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x010 = 16 -
literal|0x0af
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01c
block|,
comment|// 0x012 = 18 -
literal|0x0ce
block|,
comment|// 0x013 = 19 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x014 = 20 -
literal|0x0ff
block|,
comment|// 0x015 = 21 - JUMP
literal|0x00f
block|,
comment|// 0x016 = 22 -
literal|0x0be
block|,
comment|// 0x017 = 23 - JUMP_IF_PHY_READY
literal|0x01b
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x01c = 28 - NO_OP
literal|0x000
block|,
comment|// 0x01d = 29 - NO_OP
literal|0x000
block|,
comment|// 0x01e = 30 - NO_OP
literal|0x000
block|,
comment|// 0x01f = 31 - NO_OP
literal|0x000
block|,
comment|// 0x020 = 32 - NO_OP
literal|0x000
block|,
comment|// 0x021 = 33 - NO_OP
literal|0x0ff
block|,
comment|// 0x022 = 34 - JUMP
literal|0x09c
block|,
comment|// 0x023 = 35 -
literal|0x01c
block|,
comment|// 0x024 = 36 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x025 = 37 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x026 = 38 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x027 = 39 - JUMP_IF_PHY_READY
literal|0x027
block|,
comment|// 0x028 = 40 -
literal|0x0be
block|,
comment|// 0x029 = 41 - JUMP_IF_PHY_READY
literal|0x02f
block|,
comment|// 0x02a = 42 -
literal|0x0af
block|,
comment|// 0x02b = 43 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x036
block|,
comment|// 0x02c = 44 -
literal|0x0ff
block|,
comment|// 0x02d = 45 - JUMP
literal|0x029
block|,
comment|// 0x02e = 46 -
literal|0x00c
block|,
comment|// 0x02f = 47 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x030 = 48 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x039
block|,
comment|// 0x031 = 49 -
literal|0x0ce
block|,
comment|// 0x032 = 50 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x024
block|,
comment|// 0x033 = 51 -
literal|0x0ff
block|,
comment|// 0x034 = 52 - JUMP
literal|0x030
block|,
comment|// 0x035 = 53 -
literal|0x00c
block|,
comment|// 0x036 = 54 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x037 = 55 - JUMP
literal|0x039
block|,
comment|// 0x038 = 56 -
literal|0x000
block|,
comment|// 0x039 = 57 - NO_OP
literal|0x0cb
block|,
comment|// 0x03a = 58 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03b = 59 -
literal|0x0ff
block|,
comment|// 0x03c = 60 - JUMP
literal|0x03a
block|,
comment|// 0x03d = 61 -
literal|0x0cb
block|,
comment|// 0x03e = 62 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03f = 63 -
literal|0x0ff
block|,
comment|// 0x040 = 64 - JUMP
literal|0x09c
block|,
comment|// 0x041 = 65 -
literal|0x000
block|,
comment|// 0x042 = 66 - NO_OP
literal|0x0c9
block|,
comment|// 0x043 = 67 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x073
block|,
comment|// 0x044 = 68 -
literal|0x0a5
block|,
comment|// 0x045 = 69 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x05c
block|,
comment|// 0x046 = 70 -
literal|0x0a6
block|,
comment|// 0x047 = 71 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x063
block|,
comment|// 0x048 = 72 -
literal|0x0a7
block|,
comment|// 0x049 = 73 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x066
block|,
comment|// 0x04a = 74 -
literal|0x0a8
block|,
comment|// 0x04b = 75 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x070
block|,
comment|// 0x04c = 76 -
literal|0x0aa
block|,
comment|// 0x04d = 77 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x06b
block|,
comment|// 0x04e = 78 -
literal|0x0c5
block|,
comment|// 0x04f = 79 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x070
block|,
comment|// 0x050 = 80 -
literal|0x0ac
block|,
comment|// 0x051 = 81 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x063
block|,
comment|// 0x052 = 82 -
literal|0x0d9
block|,
comment|// 0x053 = 83 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_FREEZE_TIMEOUT
literal|0x070
block|,
comment|// 0x054 = 84 -
literal|0x0ca
block|,
comment|// 0x055 = 85 - JUMP_IF_CLOSE_REQ
literal|0x0f0
block|,
comment|// 0x056 = 86 -
literal|0x0be
block|,
comment|// 0x057 = 87 - JUMP_IF_PHY_READY
literal|0x043
block|,
comment|// 0x058 = 88 -
literal|0x01c
block|,
comment|// 0x059 = 89 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x004
block|,
comment|// 0x05b = 91 -
literal|0x01d
block|,
comment|// 0x05c = 92 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05d = 93 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x05e = 94 -
literal|0x0c3
block|,
comment|// 0x05f = 95 - JUMP_IF_SMP_PROTOCOL
literal|0x128
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x076
block|,
comment|// 0x062 = 98 -
literal|0x01d
block|,
comment|// 0x063 = 99 - ADVANCE
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x076
block|,
comment|// 0x065 = 101 -
literal|0x01d
block|,
comment|// 0x066 = 102 - ADVANCE
literal|0x0bc
block|,
comment|// 0x067 = 103 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x068 = 104 -
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x147
block|,
comment|// 0x06a = 106 -
literal|0x01d
block|,
comment|// 0x06b = 107 - ADVANCE
literal|0x0bc
block|,
comment|// 0x06c = 108 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x06d = 109 -
literal|0x0ff
block|,
comment|// 0x06e = 110 - JUMP
literal|0x14a
block|,
comment|// 0x06f = 111 -
literal|0x01d
block|,
comment|// 0x070 = 112 - ADVANCE
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x13b
block|,
comment|// 0x072 = 114 -
literal|0x022
block|,
comment|// 0x073 = 115 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x045
block|,
comment|// 0x075 = 117 -
literal|0x083
block|,
comment|// 0x076 = 118 - TIMER_START
literal|0x004
block|,
comment|// 0x077 = 119 -
literal|0x0c8
block|,
comment|// 0x078 = 120 - JUMP_IF_HIP_REQ
literal|0x082
block|,
comment|// 0x079 = 121 -
literal|0x0c6
block|,
comment|// 0x07a = 122 - JUMP_IF_SFO_REQ
literal|0x08a
block|,
comment|// 0x07b = 123 -
literal|0x0c7
block|,
comment|// 0x07c = 124 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x07d = 125 -
literal|0x0b8
block|,
comment|// 0x07e = 126 - JUMP_IF_TIMER_EXPIRED
literal|0x09c
block|,
comment|// 0x07f = 127 -
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x078
block|,
comment|// 0x081 = 129 -
literal|0x028
block|,
comment|// 0x082 = 130 - CHECK_HIP
literal|0x000
block|,
comment|// 0x083 = 131 - NO_OP
literal|0x000
block|,
comment|// 0x084 = 132 - NO_OP
literal|0x000
block|,
comment|// 0x085 = 133 - NO_OP
literal|0x0d8
block|,
comment|// 0x086 = 134 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x07e
block|,
comment|// 0x089 = 137 -
literal|0x029
block|,
comment|// 0x08a = 138 - CHECK_SFO
literal|0x000
block|,
comment|// 0x08b = 139 - NO_OP
literal|0x000
block|,
comment|// 0x08c = 140 - NO_OP
literal|0x000
block|,
comment|// 0x08d = 141 - NO_OP
literal|0x0d8
block|,
comment|// 0x08e = 142 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x08f = 143 -
literal|0x0c7
block|,
comment|// 0x090 = 144 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x091 = 145 -
literal|0x0ff
block|,
comment|// 0x092 = 146 - JUMP
literal|0x07e
block|,
comment|// 0x093 = 147 -
literal|0x02a
block|,
comment|// 0x094 = 148 - CHECK_DOC
literal|0x000
block|,
comment|// 0x095 = 149 - NO_OP
literal|0x000
block|,
comment|// 0x096 = 150 - NO_OP
literal|0x000
block|,
comment|// 0x097 = 151 - NO_OP
literal|0x0d8
block|,
comment|// 0x098 = 152 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x099 = 153 -
literal|0x0ff
block|,
comment|// 0x09a = 154 - JUMP
literal|0x07e
block|,
comment|// 0x09b = 155 -
literal|0x0bc
block|,
comment|// 0x09c = 156 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x09d = 157 -
literal|0x0be
block|,
comment|// 0x09e = 158 - JUMP_IF_PHY_READY
literal|0x0a3
block|,
comment|// 0x09f = 159 -
literal|0x01c
block|,
comment|// 0x0a0 = 160 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0a1 = 161 - JUMP
literal|0x004
block|,
comment|// 0x0a2 = 162 -
literal|0x0c8
block|,
comment|// 0x0a3 = 163 - JUMP_IF_HIP_REQ
literal|0x0b5
block|,
comment|// 0x0a4 = 164 -
literal|0x0c6
block|,
comment|// 0x0a5 = 165 - JUMP_IF_SFO_REQ
literal|0x0bd
block|,
comment|// 0x0a6 = 166 -
literal|0x0c7
block|,
comment|// 0x0a7 = 167 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0a8 = 168 -
literal|0x0a3
block|,
comment|// 0x0a9 = 169 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0aa = 170 -
literal|0x0a2
block|,
comment|// 0x0ab = 171 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0f0
block|,
comment|// 0x0ac = 172 -
literal|0x0c8
block|,
comment|// 0x0ad = 173 - JUMP_IF_HIP_REQ
literal|0x0cf
block|,
comment|// 0x0ae = 174 -
literal|0x0c6
block|,
comment|// 0x0af = 175 - JUMP_IF_SFO_REQ
literal|0x0d4
block|,
comment|// 0x0b0 = 176 -
literal|0x0c7
block|,
comment|// 0x0b1 = 177 - JUMP_IF_DOC_REQ
literal|0x0d9
block|,
comment|// 0x0b2 = 178 -
literal|0x0ff
block|,
comment|// 0x0b3 = 179 - JUMP
literal|0x09c
block|,
comment|// 0x0b4 = 180 -
literal|0x028
block|,
comment|// 0x0b5 = 181 - CHECK_HIP
literal|0x000
block|,
comment|// 0x0b6 = 182 - NO_OP
literal|0x000
block|,
comment|// 0x0b7 = 183 - NO_OP
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x0d8
block|,
comment|// 0x0b9 = 185 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x0ba = 186 -
literal|0x0ff
block|,
comment|// 0x0bb = 187 - JUMP
literal|0x0a9
block|,
comment|// 0x0bc = 188 -
literal|0x029
block|,
comment|// 0x0bd = 189 - CHECK_SFO
literal|0x000
block|,
comment|// 0x0be = 190 - NO_OP
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x0d8
block|,
comment|// 0x0c1 = 193 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x0c2 = 194 -
literal|0x0c7
block|,
comment|// 0x0c3 = 195 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0c4 = 196 -
literal|0x0ff
block|,
comment|// 0x0c5 = 197 - JUMP
literal|0x0a9
block|,
comment|// 0x0c6 = 198 -
literal|0x02a
block|,
comment|// 0x0c7 = 199 - CHECK_DOC
literal|0x000
block|,
comment|// 0x0c8 = 200 - NO_OP
literal|0x000
block|,
comment|// 0x0c9 = 201 - NO_OP
literal|0x000
block|,
comment|// 0x0ca = 202 - NO_OP
literal|0x0d8
block|,
comment|// 0x0cb = 203 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x0cc = 204 -
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x0a9
block|,
comment|// 0x0ce = 206 -
literal|0x020
block|,
comment|// 0x0cf = 207 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d2 = 210 - JUMP
literal|0x0dc
block|,
comment|// 0x0d3 = 211 -
literal|0x01e
block|,
comment|// 0x0d4 = 212 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0d5 = 213 - NO_OP
literal|0x000
block|,
comment|// 0x0d6 = 214 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x0dc
block|,
comment|// 0x0d8 = 216 -
literal|0x01f
block|,
comment|// 0x0d9 = 217 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0da = 218 - NO_OP
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0a4
block|,
comment|// 0x0dc = 220 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0e0
block|,
comment|// 0x0dd = 221 -
literal|0x0ff
block|,
comment|// 0x0de = 222 - JUMP
literal|0x14d
block|,
comment|// 0x0df = 223 -
literal|0x0a0
block|,
comment|// 0x0e0 = 224 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e6
block|,
comment|// 0x0e1 = 225 -
literal|0x0a3
block|,
comment|// 0x0e2 = 226 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0e3 = 227 -
literal|0x0ff
block|,
comment|// 0x0e4 = 228 - JUMP
literal|0x0f0
block|,
comment|// 0x0e5 = 229 -
literal|0x0cb
block|,
comment|// 0x0e6 = 230 - JUMP_IF_FREEZE_ACTIVE
literal|0x0eb
block|,
comment|// 0x0e7 = 231 -
literal|0x013
block|,
comment|// 0x0e8 = 232 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0e9 = 233 - JUMP
literal|0x042
block|,
comment|// 0x0ea = 234 -
literal|0x024
block|,
comment|// 0x0eb = 235 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0ec = 236 - NO_OP
literal|0x000
block|,
comment|// 0x0ed = 237 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ee = 238 - JUMP
literal|0x09c
block|,
comment|// 0x0ef = 239 -
literal|0x0d2
block|,
comment|// 0x0f0 = 240 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0f4
block|,
comment|// 0x0f1 = 241 -
literal|0x0ff
block|,
comment|// 0x0f2 = 242 - JUMP
literal|0x128
block|,
comment|// 0x0f3 = 243 -
literal|0x0d5
block|,
comment|// 0x0f4 = 244 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x0f5 = 245 -
literal|0x0d6
block|,
comment|// 0x0f6 = 246 - JUMP_IF_SYNC_RECEIVED
literal|0x0fa
block|,
comment|// 0x0f7 = 247 -
literal|0x0ff
block|,
comment|// 0x0f8 = 248 - JUMP
literal|0x09c
block|,
comment|// 0x0f9 = 249 -
literal|0x027
block|,
comment|// 0x0fa = 250 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0fb = 251 - NO_OP
literal|0x000
block|,
comment|// 0x0fc = 252 - NO_OP
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x000
block|,
comment|// 0x0fe = 254 - NO_OP
literal|0x0d5
block|,
comment|// 0x0ff = 255 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x100 = 256 -
literal|0x0bc
block|,
comment|// 0x101 = 257 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x102 = 258 -
literal|0x0d7
block|,
comment|// 0x103 = 259 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x104 = 260 -
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x0fb
block|,
comment|// 0x106 = 262 -
literal|0x0c3
block|,
comment|// 0x107 = 263 - JUMP_IF_SMP_PROTOCOL
literal|0x10f
block|,
comment|// 0x108 = 264 -
literal|0x0d2
block|,
comment|// 0x109 = 265 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x113
block|,
comment|// 0x10a = 266 -
literal|0x0d1
block|,
comment|// 0x10b = 267 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x119
block|,
comment|// 0x10c = 268 -
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x09c
block|,
comment|// 0x10e = 270 -
literal|0x0c4
block|,
comment|// 0x10f = 271 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x13b
block|,
comment|// 0x110 = 272 -
literal|0x0ff
block|,
comment|// 0x111 = 273 - JUMP
literal|0x0ad
block|,
comment|// 0x112 = 274 -
literal|0x0d5
block|,
comment|// 0x113 = 275 - JUMP_IF_CLOSE_RECEIVED
literal|0x119
block|,
comment|// 0x114 = 276 -
literal|0x0d6
block|,
comment|// 0x115 = 277 - JUMP_IF_SYNC_RECEIVED
literal|0x11b
block|,
comment|// 0x116 = 278 -
literal|0x0ff
block|,
comment|// 0x117 = 279 - JUMP
literal|0x113
block|,
comment|// 0x118 = 280 -
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x128
block|,
comment|// 0x11a = 282 -
literal|0x027
block|,
comment|// 0x11b = 283 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x0d5
block|,
comment|// 0x120 = 288 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x121 = 289 -
literal|0x0bc
block|,
comment|// 0x122 = 290 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x123 = 291 -
literal|0x0d7
block|,
comment|// 0x124 = 292 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x125 = 293 -
literal|0x0ff
block|,
comment|// 0x126 = 294 - JUMP
literal|0x11c
block|,
comment|// 0x127 = 295 -
literal|0x004
block|,
comment|// 0x128 = 296 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x0c9
block|,
comment|// 0x12d = 301 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x138
block|,
comment|// 0x12e = 302 -
literal|0x0c0
block|,
comment|// 0x12f = 303 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x130 = 304 -
literal|0x0bc
block|,
comment|// 0x131 = 305 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x132 = 306 -
literal|0x0be
block|,
comment|// 0x133 = 307 - JUMP_IF_PHY_READY
literal|0x129
block|,
comment|// 0x134 = 308 -
literal|0x01c
block|,
comment|// 0x135 = 309 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x004
block|,
comment|// 0x137 = 311 -
literal|0x022
block|,
comment|// 0x138 = 312 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x139 = 313 - JUMP
literal|0x129
block|,
comment|// 0x13a = 314 -
literal|0x007
block|,
comment|// 0x13b = 315 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x0c0
block|,
comment|// 0x140 = 320 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x141 = 321 -
literal|0x0be
block|,
comment|// 0x142 = 322 - JUMP_IF_PHY_READY
literal|0x13c
block|,
comment|// 0x143 = 323 -
literal|0x01c
block|,
comment|// 0x144 = 324 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x145 = 325 - JUMP
literal|0x004
block|,
comment|// 0x146 = 326 -
literal|0x005
block|,
comment|// 0x147 = 327 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x148 = 328 - JUMP
literal|0x129
block|,
comment|// 0x149 = 329 -
literal|0x006
block|,
comment|// 0x14a = 330 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x14b = 331 - JUMP
literal|0x129
block|,
comment|// 0x14c = 332 -
literal|0x0cc
block|,
comment|// 0x14d = 333 - JUMP_IF_RX_BUFFER_FULL
literal|0x09c
block|,
comment|// 0x14e = 334 -
literal|0x0b7
block|,
comment|// 0x14f = 335 - JUMP_IF_FLAG_7_SET
literal|0x154
block|,
comment|// 0x150 = 336 -
literal|0x011
block|,
comment|// 0x151 = 337 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x152 = 338 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x153 = 339 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x154 = 340 - JUMP_IF_FREEZE_ACTIVE
literal|0x193
block|,
comment|// 0x155 = 341 -
literal|0x001
block|,
comment|// 0x156 = 342 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x157 = 343 - SET_FLAG
literal|0x080
block|,
comment|// 0x158 = 344 -
literal|0x090
block|,
comment|// 0x159 = 345 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x17f
block|,
comment|// 0x15a = 346 -
literal|0x095
block|,
comment|// 0x15b = 347 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x184
block|,
comment|// 0x15c = 348 -
literal|0x099
block|,
comment|// 0x15d = 349 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x187
block|,
comment|// 0x15e = 350 -
literal|0x09b
block|,
comment|// 0x15f = 351 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x18a
block|,
comment|// 0x160 = 352 -
literal|0x094
block|,
comment|// 0x161 = 353 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x154
block|,
comment|// 0x162 = 354 -
literal|0x093
block|,
comment|// 0x163 = 355 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x18d
block|,
comment|// 0x164 = 356 -
literal|0x09f
block|,
comment|// 0x165 = 357 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x190
block|,
comment|// 0x166 = 358 -
literal|0x09a
block|,
comment|// 0x167 = 359 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x153
block|,
comment|// 0x168 = 360 -
literal|0x096
block|,
comment|// 0x169 = 361 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x154
block|,
comment|// 0x16a = 362 -
literal|0x097
block|,
comment|// 0x16b = 363 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x19a
block|,
comment|// 0x16c = 364 -
literal|0x098
block|,
comment|// 0x16d = 365 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x153
block|,
comment|// 0x16e = 366 -
literal|0x092
block|,
comment|// 0x16f = 367 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x154
block|,
comment|// 0x170 = 368 -
literal|0x0a4
block|,
comment|// 0x171 = 369 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x179
block|,
comment|// 0x172 = 370 -
literal|0x0be
block|,
comment|// 0x173 = 371 - JUMP_IF_PHY_READY
literal|0x159
block|,
comment|// 0x174 = 372 -
literal|0x01b
block|,
comment|// 0x175 = 373 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x176 = 374 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x177 = 375 - JUMP
literal|0x004
block|,
comment|// 0x178 = 376 -
literal|0x0a0
block|,
comment|// 0x179 = 377 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x17f
block|,
comment|// 0x17a = 378 -
literal|0x000
block|,
comment|// 0x17b = 379 - NO_OP
literal|0x000
block|,
comment|// 0x17c = 380 - NO_OP
literal|0x0ff
block|,
comment|// 0x17d = 381 - JUMP
literal|0x09c
block|,
comment|// 0x17e = 382 -
literal|0x013
block|,
comment|// 0x17f = 383 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x180 = 384 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x181 = 385 -
literal|0x0ff
block|,
comment|// 0x182 = 386 - JUMP
literal|0x042
block|,
comment|// 0x183 = 387 -
literal|0x017
block|,
comment|// 0x184 = 388 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x185 = 389 - JUMP
literal|0x194
block|,
comment|// 0x186 = 390 -
literal|0x018
block|,
comment|// 0x187 = 391 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x188 = 392 - JUMP
literal|0x194
block|,
comment|// 0x189 = 393 -
literal|0x01a
block|,
comment|// 0x18a = 394 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x18b = 395 - JUMP
literal|0x194
block|,
comment|// 0x18c = 396 -
literal|0x015
block|,
comment|// 0x18d = 397 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x18e = 398 - JUMP
literal|0x194
block|,
comment|// 0x18f = 399 -
literal|0x014
block|,
comment|// 0x190 = 400 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x191 = 401 - JUMP
literal|0x194
block|,
comment|// 0x192 = 402 -
literal|0x024
block|,
comment|// 0x193 = 403 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x194 = 404 - NO_OP
literal|0x000
block|,
comment|// 0x195 = 405 - NO_OP
literal|0x081
block|,
comment|// 0x196 = 406 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x197 = 407 -
literal|0x0ff
block|,
comment|// 0x198 = 408 - JUMP
literal|0x09c
block|,
comment|// 0x199 = 409 -
literal|0x010
block|,
comment|// 0x19a = 410 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x19b = 411 - JUMP
literal|0x154
block|,
comment|// 0x19c = 412 -
literal|0x000
block|,
comment|// 0x19d = 413 - NO_OP
literal|0x000
block|,
comment|// 0x19e = 414 - NO_OP
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for A1407_10, A1410_15, A1412_19, A1415_19*/
end_comment

begin_decl_stmt
name|bit32
name|wcsImage
index|[]
init|=
block|{
literal|0x00d
block|,
comment|// 00000 = 0 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x001 = 1 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x002 = 2 - JUMP_IF_PHY_READY
literal|0x002
block|,
comment|// 0x003 = 3 -
literal|0x0be
block|,
comment|// 0x004 = 4 - JUMP_IF_PHY_READY
literal|0x00e
block|,
comment|// 0x005 = 5 -
literal|0x0ae
block|,
comment|// 0x006 = 6 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x007 = 7 -
literal|0x0af
block|,
comment|// 0x008 = 8 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x017
block|,
comment|// 0x009 = 9 -
literal|0x0ce
block|,
comment|// 0x00a = 10 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x00b = 11 -
literal|0x0ff
block|,
comment|// 0x00c = 12 - JUMP
literal|0x004
block|,
comment|// 0x00d = 13 -
literal|0x00c
block|,
comment|// 0x00e = 14 - SEND_ID_FRAME
literal|0x0ae
block|,
comment|// 0x00f = 15 - JUMP_IF_HARD_RESET_PRIMITIVE
literal|0x024
block|,
comment|// 0x010 = 16 -
literal|0x0af
block|,
comment|// 0x011 = 17 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x01c
block|,
comment|// 0x012 = 18 -
literal|0x0ce
block|,
comment|// 0x013 = 19 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x000
block|,
comment|// 0x014 = 20 -
literal|0x0ff
block|,
comment|// 0x015 = 21 - JUMP
literal|0x00f
block|,
comment|// 0x016 = 22 -
literal|0x0be
block|,
comment|// 0x017 = 23 - JUMP_IF_PHY_READY
literal|0x01b
block|,
comment|// 0x018 = 24 -
literal|0x0ff
block|,
comment|// 0x019 = 25 - JUMP
literal|0x017
block|,
comment|// 0x01a = 26 -
literal|0x00c
block|,
comment|// 0x01b = 27 - SEND_ID_FRAME
literal|0x000
block|,
comment|// 0x01c = 28 - NO_OP
literal|0x000
block|,
comment|// 0x01d = 29 - NO_OP
literal|0x000
block|,
comment|// 0x01e = 30 - NO_OP
literal|0x000
block|,
comment|// 0x01f = 31 - NO_OP
literal|0x000
block|,
comment|// 0x020 = 32 - NO_OP
literal|0x000
block|,
comment|// 0x021 = 33 - NO_OP
literal|0x0ff
block|,
comment|// 0x022 = 34 - JUMP
literal|0x09c
block|,
comment|// 0x023 = 35 -
literal|0x01c
block|,
comment|// 0x024 = 36 - SOFT_RESET
literal|0x00d
block|,
comment|// 0x025 = 37 - PHY_RESET_START
literal|0x00d
block|,
comment|// 0x026 = 38 - PHY_RESET_START
literal|0x0be
block|,
comment|// 0x027 = 39 - JUMP_IF_PHY_READY
literal|0x027
block|,
comment|// 0x028 = 40 -
literal|0x0be
block|,
comment|// 0x029 = 41 - JUMP_IF_PHY_READY
literal|0x02f
block|,
comment|// 0x02a = 42 -
literal|0x0af
block|,
comment|// 0x02b = 43 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x036
block|,
comment|// 0x02c = 44 -
literal|0x0ff
block|,
comment|// 0x02d = 45 - JUMP
literal|0x029
block|,
comment|// 0x02e = 46 -
literal|0x00c
block|,
comment|// 0x02f = 47 - SEND_ID_FRAME
literal|0x0af
block|,
comment|// 0x030 = 48 - JUMP_IF_IDENTIFY_FRAME_RECEIVED
literal|0x039
block|,
comment|// 0x031 = 49 -
literal|0x0ce
block|,
comment|// 0x032 = 50 - JUMP_IF_IDENTIFY_FRAME_TIMEOUT
literal|0x024
block|,
comment|// 0x033 = 51 -
literal|0x0ff
block|,
comment|// 0x034 = 52 - JUMP
literal|0x030
block|,
comment|// 0x035 = 53 -
literal|0x00c
block|,
comment|// 0x036 = 54 - SEND_ID_FRAME
literal|0x0ff
block|,
comment|// 0x037 = 55 - JUMP
literal|0x039
block|,
comment|// 0x038 = 56 -
literal|0x000
block|,
comment|// 0x039 = 57 - NO_OP
literal|0x0cb
block|,
comment|// 0x03a = 58 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03b = 59 -
literal|0x0ff
block|,
comment|// 0x03c = 60 - JUMP
literal|0x03a
block|,
comment|// 0x03d = 61 -
literal|0x0cb
block|,
comment|// 0x03e = 62 - JUMP_IF_FREEZE_ACTIVE
literal|0x03e
block|,
comment|// 0x03f = 63 -
literal|0x0ff
block|,
comment|// 0x040 = 64 - JUMP
literal|0x09c
block|,
comment|// 0x041 = 65 -
literal|0x000
block|,
comment|// 0x042 = 66 - NO_OP
literal|0x0c9
block|,
comment|// 0x043 = 67 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x073
block|,
comment|// 0x044 = 68 -
literal|0x0a5
block|,
comment|// 0x045 = 69 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_GOOD
literal|0x05c
block|,
comment|// 0x046 = 70 -
literal|0x0a6
block|,
comment|// 0x047 = 71 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_NAK
literal|0x063
block|,
comment|// 0x048 = 72 -
literal|0x0a7
block|,
comment|// 0x049 = 73 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_ACK_NAK_TIMEOUT
literal|0x066
block|,
comment|// 0x04a = 74 -
literal|0x0a8
block|,
comment|// 0x04b = 75 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_BREAK
literal|0x070
block|,
comment|// 0x04c = 76 -
literal|0x0aa
block|,
comment|// 0x04d = 77 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_CREDIT_TIMEOUT
literal|0x06b
block|,
comment|// 0x04e = 78 -
literal|0x0c5
block|,
comment|// 0x04f = 79 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_SMP_ERR
literal|0x070
block|,
comment|// 0x050 = 80 -
literal|0x0ac
block|,
comment|// 0x051 = 81 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_MAX_BURST_SIZE
literal|0x063
block|,
comment|// 0x052 = 82 -
literal|0x0d9
block|,
comment|// 0x053 = 83 - JUMP_IF_TRANSMISSION_STATUS_EQUAL_FREEZE_TIMEOUT
literal|0x070
block|,
comment|// 0x054 = 84 -
literal|0x0ca
block|,
comment|// 0x055 = 85 - JUMP_IF_CLOSE_REQ
literal|0x0f0
block|,
comment|// 0x056 = 86 -
literal|0x0be
block|,
comment|// 0x057 = 87 - JUMP_IF_PHY_READY
literal|0x043
block|,
comment|// 0x058 = 88 -
literal|0x01c
block|,
comment|// 0x059 = 89 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x05a = 90 - JUMP
literal|0x004
block|,
comment|// 0x05b = 91 -
literal|0x01d
block|,
comment|// 0x05c = 92 - ADVANCE
literal|0x0bc
block|,
comment|// 0x05d = 93 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x05e = 94 -
literal|0x0c3
block|,
comment|// 0x05f = 95 - JUMP_IF_SMP_PROTOCOL
literal|0x128
block|,
comment|// 0x060 = 96 -
literal|0x0ff
block|,
comment|// 0x061 = 97 - JUMP
literal|0x076
block|,
comment|// 0x062 = 98 -
literal|0x01d
block|,
comment|// 0x063 = 99 - ADVANCE
literal|0x0ff
block|,
comment|// 0x064 = 100 - JUMP
literal|0x076
block|,
comment|// 0x065 = 101 -
literal|0x01d
block|,
comment|// 0x066 = 102 - ADVANCE
literal|0x0bc
block|,
comment|// 0x067 = 103 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x068 = 104 -
literal|0x0ff
block|,
comment|// 0x069 = 105 - JUMP
literal|0x147
block|,
comment|// 0x06a = 106 -
literal|0x01d
block|,
comment|// 0x06b = 107 - ADVANCE
literal|0x0bc
block|,
comment|// 0x06c = 108 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x06d = 109 -
literal|0x0ff
block|,
comment|// 0x06e = 110 - JUMP
literal|0x14a
block|,
comment|// 0x06f = 111 -
literal|0x01d
block|,
comment|// 0x070 = 112 - ADVANCE
literal|0x0ff
block|,
comment|// 0x071 = 113 - JUMP
literal|0x13b
block|,
comment|// 0x072 = 114 -
literal|0x022
block|,
comment|// 0x073 = 115 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x074 = 116 - JUMP
literal|0x045
block|,
comment|// 0x075 = 117 -
literal|0x083
block|,
comment|// 0x076 = 118 - TIMER_START
literal|0x004
block|,
comment|// 0x077 = 119 -
literal|0x0c8
block|,
comment|// 0x078 = 120 - JUMP_IF_HIP_REQ
literal|0x082
block|,
comment|// 0x079 = 121 -
literal|0x0c6
block|,
comment|// 0x07a = 122 - JUMP_IF_SFO_REQ
literal|0x08a
block|,
comment|// 0x07b = 123 -
literal|0x0c7
block|,
comment|// 0x07c = 124 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x07d = 125 -
literal|0x0b8
block|,
comment|// 0x07e = 126 - JUMP_IF_TIMER_EXPIRED
literal|0x09c
block|,
comment|// 0x07f = 127 -
literal|0x0ff
block|,
comment|// 0x080 = 128 - JUMP
literal|0x078
block|,
comment|// 0x081 = 129 -
literal|0x028
block|,
comment|// 0x082 = 130 - CHECK_HIP
literal|0x000
block|,
comment|// 0x083 = 131 - NO_OP
literal|0x000
block|,
comment|// 0x084 = 132 - NO_OP
literal|0x000
block|,
comment|// 0x085 = 133 - NO_OP
literal|0x0d8
block|,
comment|// 0x086 = 134 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x087 = 135 -
literal|0x0ff
block|,
comment|// 0x088 = 136 - JUMP
literal|0x07e
block|,
comment|// 0x089 = 137 -
literal|0x029
block|,
comment|// 0x08a = 138 - CHECK_SFO
literal|0x000
block|,
comment|// 0x08b = 139 - NO_OP
literal|0x000
block|,
comment|// 0x08c = 140 - NO_OP
literal|0x000
block|,
comment|// 0x08d = 141 - NO_OP
literal|0x0d8
block|,
comment|// 0x08e = 142 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x08f = 143 -
literal|0x0c7
block|,
comment|// 0x090 = 144 - JUMP_IF_DOC_REQ
literal|0x094
block|,
comment|// 0x091 = 145 -
literal|0x0ff
block|,
comment|// 0x092 = 146 - JUMP
literal|0x07e
block|,
comment|// 0x093 = 147 -
literal|0x02a
block|,
comment|// 0x094 = 148 - CHECK_DOC
literal|0x000
block|,
comment|// 0x095 = 149 - NO_OP
literal|0x000
block|,
comment|// 0x096 = 150 - NO_OP
literal|0x000
block|,
comment|// 0x097 = 151 - NO_OP
literal|0x0d8
block|,
comment|// 0x098 = 152 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x099 = 153 -
literal|0x0ff
block|,
comment|// 0x09a = 154 - JUMP
literal|0x07e
block|,
comment|// 0x09b = 155 -
literal|0x0bc
block|,
comment|// 0x09c = 156 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x09d = 157 -
literal|0x0be
block|,
comment|// 0x09e = 158 - JUMP_IF_PHY_READY
literal|0x0a3
block|,
comment|// 0x09f = 159 -
literal|0x01c
block|,
comment|// 0x0a0 = 160 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x0a1 = 161 - JUMP
literal|0x004
block|,
comment|// 0x0a2 = 162 -
literal|0x0c8
block|,
comment|// 0x0a3 = 163 - JUMP_IF_HIP_REQ
literal|0x0b5
block|,
comment|// 0x0a4 = 164 -
literal|0x0c6
block|,
comment|// 0x0a5 = 165 - JUMP_IF_SFO_REQ
literal|0x0bd
block|,
comment|// 0x0a6 = 166 -
literal|0x0c7
block|,
comment|// 0x0a7 = 167 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0a8 = 168 -
literal|0x0a3
block|,
comment|// 0x0a9 = 169 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0aa = 170 -
literal|0x0a2
block|,
comment|// 0x0ab = 171 - JUMP_IF_CONNECTION_OPEN_MASTER_FLAG_SET
literal|0x0f0
block|,
comment|// 0x0ac = 172 -
literal|0x0c8
block|,
comment|// 0x0ad = 173 - JUMP_IF_HIP_REQ
literal|0x0cf
block|,
comment|// 0x0ae = 174 -
literal|0x0c6
block|,
comment|// 0x0af = 175 - JUMP_IF_SFO_REQ
literal|0x0d4
block|,
comment|// 0x0b0 = 176 -
literal|0x0c7
block|,
comment|// 0x0b1 = 177 - JUMP_IF_DOC_REQ
literal|0x0d9
block|,
comment|// 0x0b2 = 178 -
literal|0x0ff
block|,
comment|// 0x0b3 = 179 - JUMP
literal|0x09c
block|,
comment|// 0x0b4 = 180 -
literal|0x028
block|,
comment|// 0x0b5 = 181 - CHECK_HIP
literal|0x000
block|,
comment|// 0x0b6 = 182 - NO_OP
literal|0x000
block|,
comment|// 0x0b7 = 183 - NO_OP
literal|0x000
block|,
comment|// 0x0b8 = 184 - NO_OP
literal|0x0d8
block|,
comment|// 0x0b9 = 185 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0cf
block|,
comment|// 0x0ba = 186 -
literal|0x0ff
block|,
comment|// 0x0bb = 187 - JUMP
literal|0x0a9
block|,
comment|// 0x0bc = 188 -
literal|0x029
block|,
comment|// 0x0bd = 189 - CHECK_SFO
literal|0x000
block|,
comment|// 0x0be = 190 - NO_OP
literal|0x000
block|,
comment|// 0x0bf = 191 - NO_OP
literal|0x000
block|,
comment|// 0x0c0 = 192 - NO_OP
literal|0x0d8
block|,
comment|// 0x0c1 = 193 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d4
block|,
comment|// 0x0c2 = 194 -
literal|0x0c7
block|,
comment|// 0x0c3 = 195 - JUMP_IF_DOC_REQ
literal|0x0c7
block|,
comment|// 0x0c4 = 196 -
literal|0x0ff
block|,
comment|// 0x0c5 = 197 - JUMP
literal|0x0a9
block|,
comment|// 0x0c6 = 198 -
literal|0x02a
block|,
comment|// 0x0c7 = 199 - CHECK_DOC
literal|0x000
block|,
comment|// 0x0c8 = 200 - NO_OP
literal|0x000
block|,
comment|// 0x0c9 = 201 - NO_OP
literal|0x000
block|,
comment|// 0x0ca = 202 - NO_OP
literal|0x0d8
block|,
comment|// 0x0cb = 203 - JUMP_IF_NXT_CONN_ACTIVE_PROF_EQ
literal|0x0d9
block|,
comment|// 0x0cc = 204 -
literal|0x0ff
block|,
comment|// 0x0cd = 205 - JUMP
literal|0x0a9
block|,
comment|// 0x0ce = 206 -
literal|0x020
block|,
comment|// 0x0cf = 207 - SELECT_HIP
literal|0x000
block|,
comment|// 0x0d0 = 208 - NO_OP
literal|0x000
block|,
comment|// 0x0d1 = 209 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d2 = 210 - JUMP
literal|0x0dc
block|,
comment|// 0x0d3 = 211 -
literal|0x01e
block|,
comment|// 0x0d4 = 212 - SELECT_SFO
literal|0x000
block|,
comment|// 0x0d5 = 213 - NO_OP
literal|0x000
block|,
comment|// 0x0d6 = 214 - NO_OP
literal|0x0ff
block|,
comment|// 0x0d7 = 215 - JUMP
literal|0x0dc
block|,
comment|// 0x0d8 = 216 -
literal|0x01f
block|,
comment|// 0x0d9 = 217 - SELECT_DOC
literal|0x000
block|,
comment|// 0x0da = 218 - NO_OP
literal|0x000
block|,
comment|// 0x0db = 219 - NO_OP
literal|0x0a4
block|,
comment|// 0x0dc = 220 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x0e0
block|,
comment|// 0x0dd = 221 -
literal|0x0ff
block|,
comment|// 0x0de = 222 - JUMP
literal|0x14d
block|,
comment|// 0x0df = 223 -
literal|0x0a0
block|,
comment|// 0x0e0 = 224 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x0e6
block|,
comment|// 0x0e1 = 225 -
literal|0x0a3
block|,
comment|// 0x0e2 = 226 - JUMP_IF_CONNECTION_OPEN_SLAVE_FLAG_SET
literal|0x107
block|,
comment|// 0x0e3 = 227 -
literal|0x0ff
block|,
comment|// 0x0e4 = 228 - JUMP
literal|0x0f0
block|,
comment|// 0x0e5 = 229 -
literal|0x0cb
block|,
comment|// 0x0e6 = 230 - JUMP_IF_FREEZE_ACTIVE
literal|0x0eb
block|,
comment|// 0x0e7 = 231 -
literal|0x013
block|,
comment|// 0x0e8 = 232 - SET_OPEN_STATUS_NORMAL
literal|0x0ff
block|,
comment|// 0x0e9 = 233 - JUMP
literal|0x042
block|,
comment|// 0x0ea = 234 -
literal|0x024
block|,
comment|// 0x0eb = 235 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x0ec = 236 - NO_OP
literal|0x000
block|,
comment|// 0x0ed = 237 - NO_OP
literal|0x0ff
block|,
comment|// 0x0ee = 238 - JUMP
literal|0x09c
block|,
comment|// 0x0ef = 239 -
literal|0x0d2
block|,
comment|// 0x0f0 = 240 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x0f4
block|,
comment|// 0x0f1 = 241 -
literal|0x0ff
block|,
comment|// 0x0f2 = 242 - JUMP
literal|0x128
block|,
comment|// 0x0f3 = 243 -
literal|0x0d5
block|,
comment|// 0x0f4 = 244 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x0f5 = 245 -
literal|0x0d6
block|,
comment|// 0x0f6 = 246 - JUMP_IF_SYNC_RECEIVED
literal|0x0fa
block|,
comment|// 0x0f7 = 247 -
literal|0x0ff
block|,
comment|// 0x0f8 = 248 - JUMP
literal|0x09c
block|,
comment|// 0x0f9 = 249 -
literal|0x027
block|,
comment|// 0x0fa = 250 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x0fb = 251 - NO_OP
literal|0x000
block|,
comment|// 0x0fc = 252 - NO_OP
literal|0x000
block|,
comment|// 0x0fd = 253 - NO_OP
literal|0x000
block|,
comment|// 0x0fe = 254 - NO_OP
literal|0x0d5
block|,
comment|// 0x0ff = 255 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x100 = 256 -
literal|0x0bc
block|,
comment|// 0x101 = 257 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x102 = 258 -
literal|0x0d7
block|,
comment|// 0x103 = 259 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x104 = 260 -
literal|0x0ff
block|,
comment|// 0x105 = 261 - JUMP
literal|0x0fb
block|,
comment|// 0x106 = 262 -
literal|0x0c3
block|,
comment|// 0x107 = 263 - JUMP_IF_SMP_PROTOCOL
literal|0x10f
block|,
comment|// 0x108 = 264 -
literal|0x0d2
block|,
comment|// 0x109 = 265 - JUMP_IF_STP_CONNECTION_ACTIVE
literal|0x113
block|,
comment|// 0x10a = 266 -
literal|0x0d1
block|,
comment|// 0x10b = 267 - JUMP_IF_IDLE_TIMER_TIMEOUT
literal|0x119
block|,
comment|// 0x10c = 268 -
literal|0x0ff
block|,
comment|// 0x10d = 269 - JUMP
literal|0x09c
block|,
comment|// 0x10e = 270 -
literal|0x0c4
block|,
comment|// 0x10f = 271 - JUMP_IF_SMP_FRAME_ERR_RECEIVED
literal|0x13b
block|,
comment|// 0x110 = 272 -
literal|0x0ff
block|,
comment|// 0x111 = 273 - JUMP
literal|0x0ad
block|,
comment|// 0x112 = 274 -
literal|0x0d5
block|,
comment|// 0x113 = 275 - JUMP_IF_CLOSE_RECEIVED
literal|0x119
block|,
comment|// 0x114 = 276 -
literal|0x0d6
block|,
comment|// 0x115 = 277 - JUMP_IF_SYNC_RECEIVED
literal|0x11b
block|,
comment|// 0x116 = 278 -
literal|0x0ff
block|,
comment|// 0x117 = 279 - JUMP
literal|0x113
block|,
comment|// 0x118 = 280 -
literal|0x0ff
block|,
comment|// 0x119 = 281 - JUMP
literal|0x128
block|,
comment|// 0x11a = 282 -
literal|0x027
block|,
comment|// 0x11b = 283 - SEND_STP_CLOSE_REQ
literal|0x000
block|,
comment|// 0x11c = 284 - NO_OP
literal|0x000
block|,
comment|// 0x11d = 285 - NO_OP
literal|0x000
block|,
comment|// 0x11e = 286 - NO_OP
literal|0x000
block|,
comment|// 0x11f = 287 - NO_OP
literal|0x0d5
block|,
comment|// 0x120 = 288 - JUMP_IF_CLOSE_RECEIVED
literal|0x128
block|,
comment|// 0x121 = 289 -
literal|0x0bc
block|,
comment|// 0x122 = 290 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x123 = 291 -
literal|0x0d7
block|,
comment|// 0x124 = 292 - JUMP_IF_STP_CLOSE_ACK
literal|0x128
block|,
comment|// 0x125 = 293 -
literal|0x0ff
block|,
comment|// 0x126 = 294 - JUMP
literal|0x11c
block|,
comment|// 0x127 = 295 -
literal|0x004
block|,
comment|// 0x128 = 296 - CLOSE_NORMAL
literal|0x000
block|,
comment|// 0x129 = 297 - NO_OP
literal|0x000
block|,
comment|// 0x12a = 298 - NO_OP
literal|0x000
block|,
comment|// 0x12b = 299 - NO_OP
literal|0x000
block|,
comment|// 0x12c = 300 - NO_OP
literal|0x0c9
block|,
comment|// 0x12d = 301 - JUMP_IF_RX_BUFFER_FULL_TIMEOUT
literal|0x138
block|,
comment|// 0x12e = 302 -
literal|0x0c0
block|,
comment|// 0x12f = 303 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x130 = 304 -
literal|0x0bc
block|,
comment|// 0x131 = 305 - JUMP_IF_BREAK_RECEIVED
literal|0x13b
block|,
comment|// 0x132 = 306 -
literal|0x0be
block|,
comment|// 0x133 = 307 - JUMP_IF_PHY_READY
literal|0x129
block|,
comment|// 0x134 = 308 -
literal|0x01c
block|,
comment|// 0x135 = 309 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x136 = 310 - JUMP
literal|0x004
block|,
comment|// 0x137 = 311 -
literal|0x022
block|,
comment|// 0x138 = 312 - SEND_CREDIT_BLOCK
literal|0x0ff
block|,
comment|// 0x139 = 313 - JUMP
literal|0x129
block|,
comment|// 0x13a = 314 -
literal|0x007
block|,
comment|// 0x13b = 315 - CLOSE_BREAK
literal|0x000
block|,
comment|// 0x13c = 316 - NO_OP
literal|0x000
block|,
comment|// 0x13d = 317 - NO_OP
literal|0x000
block|,
comment|// 0x13e = 318 - NO_OP
literal|0x000
block|,
comment|// 0x13f = 319 - NO_OP
literal|0x0c0
block|,
comment|// 0x140 = 320 - JUMP_IF_CLOSE_STATUS_EQUAL_ANY
literal|0x09c
block|,
comment|// 0x141 = 321 -
literal|0x0be
block|,
comment|// 0x142 = 322 - JUMP_IF_PHY_READY
literal|0x13c
block|,
comment|// 0x143 = 323 -
literal|0x01c
block|,
comment|// 0x144 = 324 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x145 = 325 - JUMP
literal|0x004
block|,
comment|// 0x146 = 326 -
literal|0x005
block|,
comment|// 0x147 = 327 - CLOSE_ACK_NAK_TIMEOUT
literal|0x0ff
block|,
comment|// 0x148 = 328 - JUMP
literal|0x129
block|,
comment|// 0x149 = 329 -
literal|0x006
block|,
comment|// 0x14a = 330 - CLOSE_CREDIT_TIMEOUT
literal|0x0ff
block|,
comment|// 0x14b = 331 - JUMP
literal|0x129
block|,
comment|// 0x14c = 332 -
literal|0x0da
block|,
comment|// 0x14d = 333 - JUMP_IF_SMP_TARGET
literal|0x189
block|,
comment|// 0x14e = 334 -
literal|0x0cc
block|,
comment|// 0x14f = 335 - JUMP_IF_RX_BUFFER_FULL
literal|0x09c
block|,
comment|// 0x150 = 336 -
literal|0x0b7
block|,
comment|// 0x151 = 337 - JUMP_IF_FLAG_7_SET
literal|0x156
block|,
comment|// 0x152 = 338 -
literal|0x011
block|,
comment|// 0x153 = 339 - START_IT_NEXUS_LOSS_TIMER
literal|0x00f
block|,
comment|// 0x154 = 340 - PATHWAY_BLOCKED_CNT_RESET
literal|0x00e
block|,
comment|// 0x155 = 341 - START_ARB_WAIT_TIMER
literal|0x0cb
block|,
comment|// 0x156 = 342 - JUMP_IF_FREEZE_ACTIVE
literal|0x195
block|,
comment|// 0x157 = 343 -
literal|0x001
block|,
comment|// 0x158 = 344 - OPEN_REQUEST
literal|0x080
block|,
comment|// 0x159 = 345 - SET_FLAG
literal|0x080
block|,
comment|// 0x15a = 346 -
literal|0x090
block|,
comment|// 0x15b = 347 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_ACCEPT
literal|0x181
block|,
comment|// 0x15c = 348 -
literal|0x095
block|,
comment|// 0x15d = 349 - JUMP_IF_OPEN_STATUS_EQUAL_RATE_NOT_SUPPORTED
literal|0x186
block|,
comment|// 0x15e = 350 -
literal|0x099
block|,
comment|// 0x15f = 351 - JUMP_IF_OPEN_STATUS_EQUAL_PROTOCOL_NOT_SUPPORTED
literal|0x189
block|,
comment|// 0x160 = 352 -
literal|0x09b
block|,
comment|// 0x161 = 353 - JUMP_IF_OPEN_STATUS_EQUAL_WRONG_DESTINATION
literal|0x18c
block|,
comment|// 0x162 = 354 -
literal|0x094
block|,
comment|// 0x163 = 355 - JUMP_IF_OPEN_STATUS_EQUAL_BREAK_RECEIVED
literal|0x156
block|,
comment|// 0x164 = 356 -
literal|0x093
block|,
comment|// 0x165 = 357 - JUMP_IF_OPEN_STATUS_EQUAL_BAD_DESTINATION
literal|0x18f
block|,
comment|// 0x166 = 358 -
literal|0x09f
block|,
comment|// 0x167 = 359 - JUMP_IF_IT_NEXUS_LOSS_TIMEOUT
literal|0x192
block|,
comment|// 0x168 = 360 -
literal|0x09a
block|,
comment|// 0x169 = 361 - JUMP_IF_OPEN_STATUS_EQUAL_STP_RESOURCE_BUSY
literal|0x155
block|,
comment|// 0x16a = 362 -
literal|0x096
block|,
comment|// 0x16b = 363 - JUMP_IF_OPEN_STATUS_EQUAL_NO_DESTINATION
literal|0x156
block|,
comment|// 0x16c = 364 -
literal|0x097
block|,
comment|// 0x16d = 365 - JUMP_IF_OPEN_STATUS_EQUAL_PATHWAY_BLOCKED
literal|0x19c
block|,
comment|// 0x16e = 366 -
literal|0x098
block|,
comment|// 0x16f = 367 - JUMP_IF_OPEN_STATUS_EQUAL_RETRY
literal|0x155
block|,
comment|// 0x170 = 368 -
literal|0x092
block|,
comment|// 0x171 = 369 - JUMP_IF_OPEN_STATUS_EQUAL_OPEN_TIMEOUT
literal|0x156
block|,
comment|// 0x172 = 370 -
literal|0x0a4
block|,
comment|// 0x173 = 371 - JUMP_IF_CONNECTION_ACTIVE_SET
literal|0x17b
block|,
comment|// 0x174 = 372 -
literal|0x0be
block|,
comment|// 0x175 = 373 - JUMP_IF_PHY_READY
literal|0x15b
block|,
comment|// 0x176 = 374 -
literal|0x01b
block|,
comment|// 0x177 = 375 - SET_OPEN_STATUS_PHY_NOT_RDY
literal|0x01c
block|,
comment|// 0x178 = 376 - SOFT_RESET
literal|0x0ff
block|,
comment|// 0x179 = 377 - JUMP
literal|0x004
block|,
comment|// 0x17a = 378 -
literal|0x0a0
block|,
comment|// 0x17b = 379 - JUMP_IF_CONNECTION_PROFILE_OPEN_EQUAL
literal|0x181
block|,
comment|// 0x17c = 380 -
literal|0x000
block|,
comment|// 0x17d = 381 - NO_OP
literal|0x000
block|,
comment|// 0x17e = 382 - NO_OP
literal|0x0ff
block|,
comment|// 0x17f = 383 - JUMP
literal|0x09c
block|,
comment|// 0x180 = 384 -
literal|0x013
block|,
comment|// 0x181 = 385 - SET_OPEN_STATUS_NORMAL
literal|0x081
block|,
comment|// 0x182 = 386 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x183 = 387 -
literal|0x0ff
block|,
comment|// 0x184 = 388 - JUMP
literal|0x042
block|,
comment|// 0x185 = 389 -
literal|0x017
block|,
comment|// 0x186 = 390 - SET_OPEN_STATUS_BAD_RATE
literal|0x0ff
block|,
comment|// 0x187 = 391 - JUMP
literal|0x196
block|,
comment|// 0x188 = 392 -
literal|0x018
block|,
comment|// 0x189 = 393 - SET_OPEN_STATUS_BAD_PROTOCOL
literal|0x0ff
block|,
comment|// 0x18a = 394 - JUMP
literal|0x196
block|,
comment|// 0x18b = 395 -
literal|0x01a
block|,
comment|// 0x18c = 396 - SET_OPEN_STATUS_WRONG_DEST
literal|0x0ff
block|,
comment|// 0x18d = 397 - JUMP
literal|0x196
block|,
comment|// 0x18e = 398 -
literal|0x015
block|,
comment|// 0x18f = 399 - SET_OPEN_STATUS_BAD_DEST
literal|0x0ff
block|,
comment|// 0x190 = 400 - JUMP
literal|0x196
block|,
comment|// 0x191 = 401 -
literal|0x014
block|,
comment|// 0x192 = 402 - SET_OPEN_STATUS_IT_NEXUS_LOSS
literal|0x0ff
block|,
comment|// 0x193 = 403 - JUMP
literal|0x196
block|,
comment|// 0x194 = 404 -
literal|0x024
block|,
comment|// 0x195 = 405 - SET_OPEN_STATUS_FREEZE
literal|0x000
block|,
comment|// 0x196 = 406 - NO_OP
literal|0x000
block|,
comment|// 0x197 = 407 - NO_OP
literal|0x081
block|,
comment|// 0x198 = 408 - CLEAR_FLAG
literal|0x080
block|,
comment|// 0x199 = 409 -
literal|0x0ff
block|,
comment|// 0x19a = 410 - JUMP
literal|0x09c
block|,
comment|// 0x19b = 411 -
literal|0x010
block|,
comment|// 0x19c = 412 - PATHWAY_BLOCKED_CNT_INC
literal|0x0ff
block|,
comment|// 0x19d = 413 - JUMP
literal|0x156
block|,
comment|// 0x19e = 414 -
literal|0x000
block|,
comment|// 0x19f = 415 - NO_OP
literal|0x000
block|,
comment|// 0x1a0 = 416 - NO_OP
literal|0x000
block|,
comment|// 0x1a1 = 417 - NO_OP
literal|0x000
block|,
comment|// 0x1a2 = 418 - NO_OP
literal|0x000
block|,
comment|// 0x1a3 = 419 - NO_OP
literal|0x000
block|,
comment|// 0x1a4 = 420 - NO_OP
literal|0x000
block|,
comment|// 0x1a5 = 421 - NO_OP
literal|0x000
block|,
comment|// 0x1a6 = 422 - NO_OP
literal|0x000
block|,
comment|// 0x1a7 = 423 - NO_OP
literal|0x000
block|,
comment|// 0x1a8 = 424 - NO_OP
literal|0x000
block|,
comment|// 0x1a9 = 425 - NO_OP
literal|0x000
block|,
comment|// 0x1aa = 426 - NO_OP
literal|0x000
block|,
comment|// 0x1ab = 427 - NO_OP
literal|0x000
block|,
comment|// 0x1ac = 428 - NO_OP
literal|0x000
block|,
comment|// 0x1ad = 429 - NO_OP
literal|0x000
block|,
comment|// 0x1ae = 430 - NO_OP
literal|0x000
block|,
comment|// 0x1af = 431 - NO_OP
literal|0x000
block|,
comment|// 0x1b0 = 432 - NO_OP
literal|0x000
block|,
comment|// 0x1b1 = 433 - NO_OP
literal|0x000
block|,
comment|// 0x1b2 = 434 - NO_OP
literal|0x000
block|,
comment|// 0x1b3 = 435 - NO_OP
literal|0x000
block|,
comment|// 0x1b4 = 436 - NO_OP
literal|0x000
block|,
comment|// 0x1b5 = 437 - NO_OP
literal|0x000
block|,
comment|// 0x1b6 = 438 - NO_OP
literal|0x000
block|,
comment|// 0x1b7 = 439 - NO_OP
literal|0x000
block|,
comment|// 0x1b8 = 440 - NO_OP
literal|0x000
block|,
comment|// 0x1b9 = 441 - NO_OP
literal|0x000
block|,
comment|// 0x1ba = 442 - NO_OP
literal|0x000
block|,
comment|// 0x1bb = 443 - NO_OP
literal|0x000
block|,
comment|// 0x1bc = 444 - NO_OP
literal|0x000
block|,
comment|// 0x1bd = 445 - NO_OP
literal|0x000
block|,
comment|// 0x1be = 446 - NO_OP
literal|0x000
block|,
comment|// 0x1bf = 447 - NO_OP
literal|0x000
block|,
comment|// 0x1c0 = 448 - NO_OP
literal|0x000
block|,
comment|// 0x1c1 = 449 - NO_OP
literal|0x000
block|,
comment|// 0x1c2 = 450 - NO_OP
literal|0x000
block|,
comment|// 0x1c3 = 451 - NO_OP
literal|0x000
block|,
comment|// 0x1c4 = 452 - NO_OP
literal|0x000
block|,
comment|// 0x1c5 = 453 - NO_OP
literal|0x000
block|,
comment|// 0x1c6 = 454 - NO_OP
literal|0x000
block|,
comment|// 0x1c7 = 455 - NO_OP
literal|0x000
block|,
comment|// 0x1c8 = 456 - NO_OP
literal|0x000
block|,
comment|// 0x1c9 = 457 - NO_OP
literal|0x000
block|,
comment|// 0x1ca = 458 - NO_OP
literal|0x000
block|,
comment|// 0x1cb = 459 - NO_OP
literal|0x000
block|,
comment|// 0x1cc = 460 - NO_OP
literal|0x000
block|,
comment|// 0x1cd = 461 - NO_OP
literal|0x000
block|,
comment|// 0x1ce = 462 - NO_OP
literal|0x000
block|,
comment|// 0x1cf = 463 - NO_OP
literal|0x000
block|,
comment|// 0x1d0 = 464 - NO_OP
literal|0x000
block|,
comment|// 0x1d1 = 465 - NO_OP
literal|0x000
block|,
comment|// 0x1d2 = 466 - NO_OP
literal|0x000
block|,
comment|// 0x1d3 = 467 - NO_OP
literal|0x000
block|,
comment|// 0x1d4 = 468 - NO_OP
literal|0x000
block|,
comment|// 0x1d5 = 469 - NO_OP
literal|0x000
block|,
comment|// 0x1d6 = 470 - NO_OP
literal|0x000
block|,
comment|// 0x1d7 = 471 - NO_OP
literal|0x000
block|,
comment|// 0x1d8 = 472 - NO_OP
literal|0x000
block|,
comment|// 0x1d9 = 473 - NO_OP
literal|0x000
block|,
comment|// 0x1da = 474 - NO_OP
literal|0x000
block|,
comment|// 0x1db = 475 - NO_OP
literal|0x000
block|,
comment|// 0x1dc = 476 - NO_OP
literal|0x000
block|,
comment|// 0x1dd = 477 - NO_OP
literal|0x000
block|,
comment|// 0x1de = 478 - NO_OP
literal|0x000
block|,
comment|// 0x1df = 479 - NO_OP
literal|0x000
block|,
comment|// 0x1e0 = 480 - NO_OP
literal|0x000
block|,
comment|// 0x1e1 = 481 - NO_OP
literal|0x000
block|,
comment|// 0x1e2 = 482 - NO_OP
literal|0x000
block|,
comment|// 0x1e3 = 483 - NO_OP
literal|0x000
block|,
comment|// 0x1e4 = 484 - NO_OP
literal|0x000
block|,
comment|// 0x1e5 = 485 - NO_OP
literal|0x000
block|,
comment|// 0x1e6 = 486 - NO_OP
literal|0x000
block|,
comment|// 0x1e7 = 487 - NO_OP
literal|0x000
block|,
comment|// 0x1e8 = 488 - NO_OP
literal|0x000
block|,
comment|// 0x1e9 = 489 - NO_OP
literal|0x000
block|,
comment|// 0x1ea = 490 - NO_OP
literal|0x000
block|,
comment|// 0x1eb = 491 - NO_OP
literal|0x000
block|,
comment|// 0x1ec = 492 - NO_OP
literal|0x000
block|,
comment|// 0x1ed = 493 - NO_OP
literal|0x000
block|,
comment|// 0x1ee = 494 - NO_OP
literal|0x000
block|,
comment|// 0x1ef = 495 - NO_OP
literal|0x000
block|,
comment|// 0x1f0 = 496 - NO_OP
literal|0x000
block|,
comment|// 0x1f1 = 497 - NO_OP
literal|0x000
block|,
comment|// 0x1f2 = 498 - NO_OP
literal|0x000
block|,
comment|// 0x1f3 = 499 - NO_OP
literal|0x000
block|,
comment|// 0x1f4 = 500 - NO_OP
literal|0x000
block|,
comment|// 0x1f5 = 501 - NO_OP
literal|0x000
block|,
comment|// 0x1f6 = 502 - NO_OP
literal|0x000
block|,
comment|// 0x1f7 = 503 - NO_OP
literal|0x000
block|,
comment|// 0x1f8 = 504 - NO_OP
literal|0x000
block|,
comment|// 0x1f9 = 505 - NO_OP
literal|0x000
block|,
comment|// 0x1fa = 506 - NO_OP
literal|0x000
block|,
comment|// 0x1fb = 507 - NO_OP
literal|0x000
block|,
comment|// 0x1fc = 508 - NO_OP
literal|0x000
block|,
comment|// 0x1fd = 509 - NO_OP
literal|0x000
block|,
comment|// 0x1fe = 510 - NO_OP
literal|0x000
block|,
comment|// 0x1ff = 511 - NO_OP
block|}
decl_stmt|;
end_decl_stmt

end_unit

