begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: keymatch.h,v 10.1 86/11/19 10:45:43 jg Exp $ */
end_comment

begin_comment
comment|/* Copyright 1985 Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* keymatch.h - Table to match key codes from RTPC to X default (DEC) codes   *  *	Author:  *  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *		Providence, RI 02912  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_decl_stmt
name|unsigned
name|char
name|keymatch
index|[]
init|=
block|{
comment|/* IBM key code		X Key Code */
comment|/* 0x00 */
literal|0000
block|,
comment|/* 0x01 */
literal|0001
block|,
comment|/* 0x02 */
literal|0002
block|,
comment|/* 0x03 */
literal|0003
block|,
comment|/* 0x04 */
literal|0004
block|,
comment|/* 0x05 */
literal|0005
block|,
comment|/* 0x06 */
literal|0006
block|,
comment|/* 0x07 */
literal|0126
block|,
comment|/* F1 */
comment|/* 0x08 */
literal|0161
block|,
comment|/* ESC */
comment|/* 0x09 */
literal|0007
block|,
comment|/* 0x0A */
literal|0010
block|,
comment|/* 0x0B */
literal|0011
block|,
comment|/* 0x0C */
literal|0012
block|,
comment|/* 0x0D */
literal|0276
block|,
comment|/* Tab */
comment|/* 0x0E */
literal|0277
block|,
comment|/* ` */
comment|/* 0x0F */
literal|0127
block|,
comment|/* F2 */
comment|/* 0x10 */
literal|0013
block|,
comment|/* 0x11 */
literal|0257
block|,
comment|/* Ctrl */
comment|/* 0x12 */
literal|0256
block|,
comment|/* SHIFT1 -> Shift/SHFT */
comment|/* 0x13 */
literal|0311
block|,
comment|/* ????? */
comment|/* 0x14 */
literal|0260
block|,
comment|/* Caps Lock -> Lock */
comment|/* 0x15 */
literal|0301
block|,
comment|/* q */
comment|/* 0x16 */
literal|0300
block|,
comment|/* 1 * /* 0x17 */
literal|0130
block|,
comment|/* F3 */
comment|/* 0x18 */
literal|0017
block|,
comment|/* 0x19 */
literal|0261
block|,
comment|/* ALT1 -> Compose Character/SYMBOL */
comment|/* 0x1A */
literal|0303
block|,
comment|/* z */
comment|/* 0x1B */
literal|0307
block|,
comment|/* s */
comment|/* 0x1C */
literal|0302
block|,
comment|/* a */
comment|/* 0x1D */
literal|0306
block|,
comment|/* w */
comment|/* 0x1E */
literal|0305
block|,
comment|/* 2 */
comment|/* 0x1F */
literal|0131
block|,
comment|/* F4 */
comment|/* 0x20 */
literal|0021
block|,
comment|/* 0x21 */
literal|0316
block|,
comment|/* c */
comment|/* 0x22 */
literal|0310
block|,
comment|/* x */
comment|/* 0x23 */
literal|0315
block|,
comment|/* d */
comment|/* 0x24 */
literal|0314
block|,
comment|/* e */
comment|/* 0x25 */
literal|0320
block|,
comment|/* 4 */
comment|/* 0x26 */
literal|0313
block|,
comment|/* 3 */
comment|/* 0x27 */
literal|0132
block|,
comment|/* F5 */
comment|/* 0x28 */
literal|0022
block|,
comment|/* 0x29 */
literal|0324
block|,
comment|/* Space */
comment|/* 0x2A */
literal|0323
block|,
comment|/* v */
comment|/* 0x2B */
literal|0322
block|,
comment|/* f */
comment|/* 0x2C */
literal|0327
block|,
comment|/* t */
comment|/* 0x2D */
literal|0321
block|,
comment|/* r */
comment|/* 0x2E */
literal|0326
block|,
comment|/* 5 */
comment|/* 0x2F */
literal|0144
block|,
comment|/* F6 */
comment|/* 0x30 */
literal|0023
block|,
comment|/* 0x31 */
literal|0336
block|,
comment|/* n */
comment|/* 0x32 */
literal|0331
block|,
comment|/* b */
comment|/* 0x33 */
literal|0335
block|,
comment|/* h */
comment|/* 0x34 */
literal|0330
block|,
comment|/* g */
comment|/* 0x35 */
literal|0334
block|,
comment|/* y */
comment|/* 0x36 */
literal|0333
block|,
comment|/* 6 */
comment|/* 0x37 */
literal|0145
block|,
comment|/* F7 */
comment|/* 0x38 */
literal|0024
block|,
comment|/* 0x39 */
literal|0261
block|,
comment|/* ALT2 -> Compose Character/SYMBOL */
comment|/* 0x3A */
literal|0343
block|,
comment|/* m */
comment|/* 0x3B */
literal|0342
block|,
comment|/* j */
comment|/* 0x3C */
literal|0341
block|,
comment|/* u */
comment|/* 0x3D */
literal|0340
block|,
comment|/* 7 */
comment|/* 0x3E */
literal|0345
block|,
comment|/* 8 */
comment|/* 0x3F */
literal|0146
block|,
comment|/* F8 */
comment|/* 0x40 */
literal|0026
block|,
comment|/* 0x41 */
literal|0350
block|,
comment|/* , */
comment|/* 0x42 */
literal|0347
block|,
comment|/* k */
comment|/* 0x43 */
literal|0346
block|,
comment|/* i */
comment|/* 0x44 */
literal|0353
block|,
comment|/* o */
comment|/* 0x45 */
literal|0357
block|,
comment|/* 0 */
comment|/* 0x46 */
literal|0352
block|,
comment|/* 9 */
comment|/* 0x47 */
literal|0147
block|,
comment|/* F9 */
comment|/* 0x48 */
literal|0027
block|,
comment|/* 0x49 */
literal|0355
block|,
comment|/* . */
comment|/* 0x4A */
literal|0363
block|,
comment|/* / */
comment|/* 0x4B */
literal|0354
block|,
comment|/* l */
comment|/* 0x4C */
literal|0362
block|,
comment|/* ; */
comment|/* 0x4D */
literal|0360
block|,
comment|/* p */
comment|/* 0x4E */
literal|0371
block|,
comment|/* - */
comment|/* 0x4F */
literal|0150
block|,
comment|/* F10 */
comment|/* 0x50 */
literal|0030
block|,
comment|/* 0x51 */
literal|0031
block|,
comment|/* 0x52 */
literal|0373
block|,
comment|/* ' */
comment|/* 0x53 */
literal|0032
block|,
comment|/* 0x54 */
literal|0372
block|,
comment|/* [ */
comment|/* 0x55 */
literal|0365
block|,
comment|/* = */
comment|/* 0x56 */
literal|0164
block|,
comment|/* F11 -> F14 */
comment|/* 0x57 */
literal|0202
block|,
comment|/* Print Screen -> F19 */
comment|/* 0x58 */
literal|0033
block|,
comment|/* 0x59 */
literal|0256
block|,
comment|/* SHIFT2 -> Shift/SHFT */
comment|/* 0x5A */
literal|0275
block|,
comment|/* Return */
comment|/* 0x5B */
literal|0366
block|,
comment|/* ] */
comment|/* 0x5C */
literal|0367
block|,
comment|/* \ */
comment|/* 0x5D */
literal|0035
block|,
comment|/* 0x5E */
literal|0200
block|,
comment|/* F12 -> F17 */
comment|/* 005F */
literal|0203
block|,
comment|/* Scroll Lock -> F20 */
comment|/* 0x60 */
literal|0251
block|,
comment|/* downarrow */
comment|/* 0x61 */
literal|0247
block|,
comment|/* leftarrow */
comment|/* 0x62 */
literal|0201
block|,
comment|/* Pause -> F18 */
comment|/* 0x63 */
literal|0252
block|,
comment|/* uparrow */
comment|/* 0x64 */
literal|0274
block|,
comment|/* delete -> back*/
comment|/* 0x65 */
literal|0175
block|,
comment|/* end -> Do/F16 */
comment|/* 0x66 */
literal|0162
block|,
comment|/* BS  -> F12/BS*/
comment|/* 0x67 */
literal|0213
block|,
comment|/* Insert/E2 */
comment|/* 0x68 */
literal|0037
block|,
comment|/* 0x69 */
literal|0226
block|,
comment|/* R1 */
comment|/* 0x6a */
literal|0250
block|,
comment|/* rightarrow */
comment|/* 0x6b */
literal|0231
block|,
comment|/* R4 */
comment|/* 0x6c */
literal|0235
block|,
comment|/* R7 */
comment|/* 0x6d */
literal|0217
block|,
comment|/* Page Down -> Next Screen */
comment|/* 0x6e */
literal|0215
block|,
comment|/* Home -> Select ???  */
comment|/* 0x6f */
literal|0216
block|,
comment|/* Page Up -> Prev Screen  */
comment|/* 0x70 */
literal|0222
block|,
comment|/* R0 */
comment|/* 0x71 */
literal|0224
block|,
comment|/* R. */
comment|/* 0x72 */
literal|0227
block|,
comment|/* R2 */
comment|/* 0x73 */
literal|0232
block|,
comment|/* R5 */
comment|/* 0x74 */
literal|0233
block|,
comment|/* R6 */
comment|/* 0x75 */
literal|0236
block|,
comment|/* R8 */
comment|/* 0x76 */
literal|0234
block|,
comment|/* Num Lock -> R, ??? */
comment|/* 0x77 */
literal|0241
block|,
comment|/* R/ -> PF1 */
comment|/* 0x78 */
literal|0041
block|,
comment|/* 0x79 */
literal|0225
block|,
comment|/* Enter */
comment|/* 0x7a */
literal|0230
block|,
comment|/* R3 */
comment|/* 0x7b */
literal|0042
block|,
comment|/* 0x7c */
literal|0242
block|,
comment|/* R+ -> PF2 */
comment|/* 0x7d */
literal|0237
block|,
comment|/* R9 */
comment|/* 0x7e */
literal|0243
block|,
comment|/* R* -> PF3*/
comment|/* 0x7f */
literal|0043
block|,
comment|/* 0x80 */
literal|0044
block|,
comment|/* 0x81 */
literal|0045
block|,
comment|/* 0x82 */
literal|0046
block|,
comment|/* 0x83 */
literal|0047
block|,
comment|/* 0x84 */
literal|0240
block|,
comment|/* R- */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RTPC_CODES
value|0x84
end_define

end_unit

