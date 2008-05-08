begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd    See the file COPYING for copying permission. */
end_comment

begin_define
define|#
directive|define
name|ASCII_A
value|0x41
end_define

begin_define
define|#
directive|define
name|ASCII_B
value|0x42
end_define

begin_define
define|#
directive|define
name|ASCII_C
value|0x43
end_define

begin_define
define|#
directive|define
name|ASCII_D
value|0x44
end_define

begin_define
define|#
directive|define
name|ASCII_E
value|0x45
end_define

begin_define
define|#
directive|define
name|ASCII_F
value|0x46
end_define

begin_define
define|#
directive|define
name|ASCII_G
value|0x47
end_define

begin_define
define|#
directive|define
name|ASCII_H
value|0x48
end_define

begin_define
define|#
directive|define
name|ASCII_I
value|0x49
end_define

begin_define
define|#
directive|define
name|ASCII_J
value|0x4A
end_define

begin_define
define|#
directive|define
name|ASCII_K
value|0x4B
end_define

begin_define
define|#
directive|define
name|ASCII_L
value|0x4C
end_define

begin_define
define|#
directive|define
name|ASCII_M
value|0x4D
end_define

begin_define
define|#
directive|define
name|ASCII_N
value|0x4E
end_define

begin_define
define|#
directive|define
name|ASCII_O
value|0x4F
end_define

begin_define
define|#
directive|define
name|ASCII_P
value|0x50
end_define

begin_define
define|#
directive|define
name|ASCII_Q
value|0x51
end_define

begin_define
define|#
directive|define
name|ASCII_R
value|0x52
end_define

begin_define
define|#
directive|define
name|ASCII_S
value|0x53
end_define

begin_define
define|#
directive|define
name|ASCII_T
value|0x54
end_define

begin_define
define|#
directive|define
name|ASCII_U
value|0x55
end_define

begin_define
define|#
directive|define
name|ASCII_V
value|0x56
end_define

begin_define
define|#
directive|define
name|ASCII_W
value|0x57
end_define

begin_define
define|#
directive|define
name|ASCII_X
value|0x58
end_define

begin_define
define|#
directive|define
name|ASCII_Y
value|0x59
end_define

begin_define
define|#
directive|define
name|ASCII_Z
value|0x5A
end_define

begin_define
define|#
directive|define
name|ASCII_a
value|0x61
end_define

begin_define
define|#
directive|define
name|ASCII_b
value|0x62
end_define

begin_define
define|#
directive|define
name|ASCII_c
value|0x63
end_define

begin_define
define|#
directive|define
name|ASCII_d
value|0x64
end_define

begin_define
define|#
directive|define
name|ASCII_e
value|0x65
end_define

begin_define
define|#
directive|define
name|ASCII_f
value|0x66
end_define

begin_define
define|#
directive|define
name|ASCII_g
value|0x67
end_define

begin_define
define|#
directive|define
name|ASCII_h
value|0x68
end_define

begin_define
define|#
directive|define
name|ASCII_i
value|0x69
end_define

begin_define
define|#
directive|define
name|ASCII_j
value|0x6A
end_define

begin_define
define|#
directive|define
name|ASCII_k
value|0x6B
end_define

begin_define
define|#
directive|define
name|ASCII_l
value|0x6C
end_define

begin_define
define|#
directive|define
name|ASCII_m
value|0x6D
end_define

begin_define
define|#
directive|define
name|ASCII_n
value|0x6E
end_define

begin_define
define|#
directive|define
name|ASCII_o
value|0x6F
end_define

begin_define
define|#
directive|define
name|ASCII_p
value|0x70
end_define

begin_define
define|#
directive|define
name|ASCII_q
value|0x71
end_define

begin_define
define|#
directive|define
name|ASCII_r
value|0x72
end_define

begin_define
define|#
directive|define
name|ASCII_s
value|0x73
end_define

begin_define
define|#
directive|define
name|ASCII_t
value|0x74
end_define

begin_define
define|#
directive|define
name|ASCII_u
value|0x75
end_define

begin_define
define|#
directive|define
name|ASCII_v
value|0x76
end_define

begin_define
define|#
directive|define
name|ASCII_w
value|0x77
end_define

begin_define
define|#
directive|define
name|ASCII_x
value|0x78
end_define

begin_define
define|#
directive|define
name|ASCII_y
value|0x79
end_define

begin_define
define|#
directive|define
name|ASCII_z
value|0x7A
end_define

begin_define
define|#
directive|define
name|ASCII_0
value|0x30
end_define

begin_define
define|#
directive|define
name|ASCII_1
value|0x31
end_define

begin_define
define|#
directive|define
name|ASCII_2
value|0x32
end_define

begin_define
define|#
directive|define
name|ASCII_3
value|0x33
end_define

begin_define
define|#
directive|define
name|ASCII_4
value|0x34
end_define

begin_define
define|#
directive|define
name|ASCII_5
value|0x35
end_define

begin_define
define|#
directive|define
name|ASCII_6
value|0x36
end_define

begin_define
define|#
directive|define
name|ASCII_7
value|0x37
end_define

begin_define
define|#
directive|define
name|ASCII_8
value|0x38
end_define

begin_define
define|#
directive|define
name|ASCII_9
value|0x39
end_define

begin_define
define|#
directive|define
name|ASCII_TAB
value|0x09
end_define

begin_define
define|#
directive|define
name|ASCII_SPACE
value|0x20
end_define

begin_define
define|#
directive|define
name|ASCII_EXCL
value|0x21
end_define

begin_define
define|#
directive|define
name|ASCII_QUOT
value|0x22
end_define

begin_define
define|#
directive|define
name|ASCII_AMP
value|0x26
end_define

begin_define
define|#
directive|define
name|ASCII_APOS
value|0x27
end_define

begin_define
define|#
directive|define
name|ASCII_MINUS
value|0x2D
end_define

begin_define
define|#
directive|define
name|ASCII_PERIOD
value|0x2E
end_define

begin_define
define|#
directive|define
name|ASCII_COLON
value|0x3A
end_define

begin_define
define|#
directive|define
name|ASCII_SEMI
value|0x3B
end_define

begin_define
define|#
directive|define
name|ASCII_LT
value|0x3C
end_define

begin_define
define|#
directive|define
name|ASCII_EQUALS
value|0x3D
end_define

begin_define
define|#
directive|define
name|ASCII_GT
value|0x3E
end_define

begin_define
define|#
directive|define
name|ASCII_LSQB
value|0x5B
end_define

begin_define
define|#
directive|define
name|ASCII_RSQB
value|0x5D
end_define

begin_define
define|#
directive|define
name|ASCII_UNDERSCORE
value|0x5F
end_define

begin_define
define|#
directive|define
name|ASCII_LPAREN
value|0x28
end_define

begin_define
define|#
directive|define
name|ASCII_RPAREN
value|0x29
end_define

begin_define
define|#
directive|define
name|ASCII_FF
value|0x0C
end_define

begin_define
define|#
directive|define
name|ASCII_SLASH
value|0x2F
end_define

begin_define
define|#
directive|define
name|ASCII_HASH
value|0x23
end_define

begin_define
define|#
directive|define
name|ASCII_PIPE
value|0x7C
end_define

begin_define
define|#
directive|define
name|ASCII_COMMA
value|0x2C
end_define

end_unit

