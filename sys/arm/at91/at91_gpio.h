begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_GPIO_H
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|at91_pin_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AT91_PIN_NONE
value|0xfffffffful
end_define

begin_comment
comment|/* No pin / Not GPIO controlled */
end_comment

begin_comment
comment|/*  * Map Atmel PIO pins to a unique number. They are just numbered sequentially.  */
end_comment

begin_define
define|#
directive|define
name|AT91_PIN_PA0
value|(at91_pin_t)0
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA1
value|(at91_pin_t)1
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA2
value|(at91_pin_t)2
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA3
value|(at91_pin_t)3
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA4
value|(at91_pin_t)4
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA5
value|(at91_pin_t)5
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA6
value|(at91_pin_t)6
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA7
value|(at91_pin_t)7
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA8
value|(at91_pin_t)8
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA9
value|(at91_pin_t)9
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA10
value|(at91_pin_t)10
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA11
value|(at91_pin_t)11
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA12
value|(at91_pin_t)12
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA13
value|(at91_pin_t)13
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA14
value|(at91_pin_t)14
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA15
value|(at91_pin_t)15
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA16
value|(at91_pin_t)16
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA17
value|(at91_pin_t)17
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA18
value|(at91_pin_t)18
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA19
value|(at91_pin_t)19
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA20
value|(at91_pin_t)20
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA21
value|(at91_pin_t)21
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA22
value|(at91_pin_t)22
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA23
value|(at91_pin_t)23
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA24
value|(at91_pin_t)24
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA25
value|(at91_pin_t)25
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA26
value|(at91_pin_t)26
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA27
value|(at91_pin_t)27
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA28
value|(at91_pin_t)28
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA29
value|(at91_pin_t)29
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA30
value|(at91_pin_t)30
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PA31
value|(at91_pin_t)31
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB0
value|(at91_pin_t)32
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB1
value|(at91_pin_t)33
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB2
value|(at91_pin_t)34
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB3
value|(at91_pin_t)35
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB4
value|(at91_pin_t)36
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB5
value|(at91_pin_t)37
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB6
value|(at91_pin_t)38
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB7
value|(at91_pin_t)39
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB8
value|(at91_pin_t)40
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB9
value|(at91_pin_t)41
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB10
value|(at91_pin_t)42
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB11
value|(at91_pin_t)43
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB12
value|(at91_pin_t)44
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB13
value|(at91_pin_t)45
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB14
value|(at91_pin_t)46
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB15
value|(at91_pin_t)47
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB16
value|(at91_pin_t)48
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB17
value|(at91_pin_t)49
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB18
value|(at91_pin_t)50
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB19
value|(at91_pin_t)51
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB20
value|(at91_pin_t)52
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB21
value|(at91_pin_t)53
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB22
value|(at91_pin_t)54
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB23
value|(at91_pin_t)55
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB24
value|(at91_pin_t)56
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB25
value|(at91_pin_t)57
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB26
value|(at91_pin_t)58
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB27
value|(at91_pin_t)59
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB28
value|(at91_pin_t)60
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB29
value|(at91_pin_t)61
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB30
value|(at91_pin_t)62
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PB31
value|(at91_pin_t)63
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC0
value|(at91_pin_t)64
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC1
value|(at91_pin_t)65
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC2
value|(at91_pin_t)66
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC3
value|(at91_pin_t)67
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC4
value|(at91_pin_t)68
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC5
value|(at91_pin_t)69
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC6
value|(at91_pin_t)70
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC7
value|(at91_pin_t)71
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC8
value|(at91_pin_t)72
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC9
value|(at91_pin_t)73
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC10
value|(at91_pin_t)74
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC11
value|(at91_pin_t)75
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC12
value|(at91_pin_t)76
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC13
value|(at91_pin_t)77
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC14
value|(at91_pin_t)78
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC15
value|(at91_pin_t)79
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC16
value|(at91_pin_t)80
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC17
value|(at91_pin_t)81
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC18
value|(at91_pin_t)82
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC19
value|(at91_pin_t)83
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC20
value|(at91_pin_t)84
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC21
value|(at91_pin_t)85
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC22
value|(at91_pin_t)86
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC23
value|(at91_pin_t)87
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC24
value|(at91_pin_t)88
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC25
value|(at91_pin_t)89
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC26
value|(at91_pin_t)90
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC27
value|(at91_pin_t)91
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC28
value|(at91_pin_t)92
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC29
value|(at91_pin_t)93
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC30
value|(at91_pin_t)94
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PC31
value|(at91_pin_t)95
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD0
value|(at91_pin_t)96
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD1
value|(at91_pin_t)97
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD2
value|(at91_pin_t)98
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD3
value|(at91_pin_t)99
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD4
value|(at91_pin_t)100
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD5
value|(at91_pin_t)101
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD6
value|(at91_pin_t)102
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD7
value|(at91_pin_t)103
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD8
value|(at91_pin_t)104
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD9
value|(at91_pin_t)105
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD10
value|(at91_pin_t)106
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD11
value|(at91_pin_t)107
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD12
value|(at91_pin_t)108
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD13
value|(at91_pin_t)109
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD14
value|(at91_pin_t)110
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD15
value|(at91_pin_t)111
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD16
value|(at91_pin_t)112
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD17
value|(at91_pin_t)113
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD18
value|(at91_pin_t)114
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD19
value|(at91_pin_t)115
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD20
value|(at91_pin_t)116
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD21
value|(at91_pin_t)117
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD22
value|(at91_pin_t)118
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD23
value|(at91_pin_t)119
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD24
value|(at91_pin_t)120
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD25
value|(at91_pin_t)121
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD26
value|(at91_pin_t)122
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD27
value|(at91_pin_t)123
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD28
value|(at91_pin_t)124
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD29
value|(at91_pin_t)125
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD30
value|(at91_pin_t)126
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PD31
value|(at91_pin_t)127
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE0
value|(at91_pin_t)128
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE1
value|(at91_pin_t)129
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE2
value|(at91_pin_t)130
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE3
value|(at91_pin_t)131
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE4
value|(at91_pin_t)132
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE5
value|(at91_pin_t)133
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE6
value|(at91_pin_t)134
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE7
value|(at91_pin_t)135
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE8
value|(at91_pin_t)136
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE9
value|(at91_pin_t)137
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE10
value|(at91_pin_t)138
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE11
value|(at91_pin_t)139
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE12
value|(at91_pin_t)140
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE13
value|(at91_pin_t)141
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE14
value|(at91_pin_t)142
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE15
value|(at91_pin_t)143
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE16
value|(at91_pin_t)144
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE17
value|(at91_pin_t)145
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE18
value|(at91_pin_t)146
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE19
value|(at91_pin_t)147
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE20
value|(at91_pin_t)148
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE21
value|(at91_pin_t)149
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE22
value|(at91_pin_t)150
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE23
value|(at91_pin_t)151
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE24
value|(at91_pin_t)152
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE25
value|(at91_pin_t)153
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE26
value|(at91_pin_t)154
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE27
value|(at91_pin_t)155
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE28
value|(at91_pin_t)156
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE29
value|(at91_pin_t)157
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE30
value|(at91_pin_t)158
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PE31
value|(at91_pin_t)159
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF0
value|(at91_pin_t)160
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF1
value|(at91_pin_t)161
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF2
value|(at91_pin_t)162
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF3
value|(at91_pin_t)163
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF4
value|(at91_pin_t)164
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF5
value|(at91_pin_t)165
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF6
value|(at91_pin_t)166
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF7
value|(at91_pin_t)167
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF8
value|(at91_pin_t)168
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF9
value|(at91_pin_t)169
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF10
value|(at91_pin_t)170
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF11
value|(at91_pin_t)171
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF12
value|(at91_pin_t)172
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF13
value|(at91_pin_t)173
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF14
value|(at91_pin_t)174
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF15
value|(at91_pin_t)175
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF16
value|(at91_pin_t)176
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF17
value|(at91_pin_t)177
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF18
value|(at91_pin_t)178
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF19
value|(at91_pin_t)179
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF20
value|(at91_pin_t)180
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF21
value|(at91_pin_t)181
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF22
value|(at91_pin_t)182
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF23
value|(at91_pin_t)183
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF24
value|(at91_pin_t)184
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF25
value|(at91_pin_t)185
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF26
value|(at91_pin_t)186
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF27
value|(at91_pin_t)187
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF28
value|(at91_pin_t)188
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF29
value|(at91_pin_t)189
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF30
value|(at91_pin_t)190
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PF31
value|(at91_pin_t)191
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG0
value|(at91_pin_t)192
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG1
value|(at91_pin_t)193
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG2
value|(at91_pin_t)194
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG3
value|(at91_pin_t)195
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG4
value|(at91_pin_t)196
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG5
value|(at91_pin_t)197
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG6
value|(at91_pin_t)198
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG7
value|(at91_pin_t)199
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG8
value|(at91_pin_t)200
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG9
value|(at91_pin_t)201
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG10
value|(at91_pin_t)202
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG11
value|(at91_pin_t)203
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG12
value|(at91_pin_t)204
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG13
value|(at91_pin_t)205
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG14
value|(at91_pin_t)206
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG15
value|(at91_pin_t)207
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG16
value|(at91_pin_t)208
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG17
value|(at91_pin_t)209
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG18
value|(at91_pin_t)210
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG19
value|(at91_pin_t)211
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG20
value|(at91_pin_t)212
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG21
value|(at91_pin_t)213
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG22
value|(at91_pin_t)214
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG23
value|(at91_pin_t)215
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG24
value|(at91_pin_t)216
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG25
value|(at91_pin_t)217
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG26
value|(at91_pin_t)218
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG27
value|(at91_pin_t)219
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG28
value|(at91_pin_t)220
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG29
value|(at91_pin_t)221
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG30
value|(at91_pin_t)222
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PG31
value|(at91_pin_t)223
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH0
value|(at91_pin_t)224
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH1
value|(at91_pin_t)225
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH2
value|(at91_pin_t)226
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH3
value|(at91_pin_t)227
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH4
value|(at91_pin_t)228
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH5
value|(at91_pin_t)229
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH6
value|(at91_pin_t)230
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH7
value|(at91_pin_t)231
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH8
value|(at91_pin_t)232
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH9
value|(at91_pin_t)233
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH10
value|(at91_pin_t)234
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH11
value|(at91_pin_t)235
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH12
value|(at91_pin_t)236
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH13
value|(at91_pin_t)237
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH14
value|(at91_pin_t)238
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH15
value|(at91_pin_t)239
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH16
value|(at91_pin_t)240
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH17
value|(at91_pin_t)241
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH18
value|(at91_pin_t)242
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH19
value|(at91_pin_t)243
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH20
value|(at91_pin_t)244
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH21
value|(at91_pin_t)245
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH22
value|(at91_pin_t)246
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH23
value|(at91_pin_t)247
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH24
value|(at91_pin_t)248
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH25
value|(at91_pin_t)249
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH26
value|(at91_pin_t)250
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH27
value|(at91_pin_t)251
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH28
value|(at91_pin_t)252
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH29
value|(at91_pin_t)253
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH30
value|(at91_pin_t)254
end_define

begin_define
define|#
directive|define
name|AT91_PIN_PH31
value|(at91_pin_t)255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_GPIO_H */
end_comment

end_unit

