begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: lk201.h,v 10.5 86/12/17 20:38:13 swick Exp $ */
end_comment

begin_comment
comment|/*  * The Sun X drivers are a product of Sun Microsystems, Inc. and are provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify these drivers without charge, but are not authorized  * to license or distribute them to anyone else except as part of a product or  * program developed by the user.  *   * THE SUN X DRIVERS ARE PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND  * INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A  * PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE  * PRACTICE.  *  * The Sun X Drivers are provided with no support and without any obligation  * on the part of Sun Microsystems, Inc. to assist in their use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THE SUN X  * DRIVERS OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1986 by Sun Microsystems,  Inc.  *  * @(#)lk201.h 2.1 86/01/28  *  */
end_comment

begin_comment
comment|/*  *	Bogus mapping to the LK201 keycodes.  This is really squalid.  */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|LK201
index|[]
init|=
block|{
literal|0324
operator||
name|ControlMask
block|,
comment|/* 000 nul */
literal|0302
operator||
name|ControlMask
block|,
comment|/* 001 soh */
literal|0331
operator||
name|ControlMask
block|,
comment|/* 002 stx */
literal|0316
operator||
name|ControlMask
block|,
comment|/* 003 etx */
literal|0315
operator||
name|ControlMask
block|,
comment|/* 004 eot */
literal|0314
operator||
name|ControlMask
block|,
comment|/* 005 enq */
literal|0322
operator||
name|ControlMask
block|,
comment|/* 006 ack */
literal|0330
operator||
name|ControlMask
block|,
comment|/* 007 bel */
literal|0335
operator||
name|ControlMask
block|,
comment|/* 010 bs  */
literal|0276
operator||
name|ControlMask
block|,
comment|/* 011 ht  */
literal|0342
operator||
name|ControlMask
block|,
comment|/* 012 nl  */
literal|0347
operator||
name|ControlMask
block|,
comment|/* 013 vt  */
literal|0354
operator||
name|ControlMask
block|,
comment|/* 014 np  */
literal|0275
operator||
name|ControlMask
block|,
comment|/* 015 cr  */
literal|0336
operator||
name|ControlMask
block|,
comment|/* 016 so  */
literal|0353
operator||
name|ControlMask
block|,
comment|/* 017 si  */
literal|0360
operator||
name|ControlMask
block|,
comment|/* 020 dle */
literal|0301
operator||
name|ControlMask
block|,
comment|/* 021 dc1 */
literal|0321
operator||
name|ControlMask
block|,
comment|/* 022 dc2 */
literal|0307
operator||
name|ControlMask
block|,
comment|/* 023 dc3 */
literal|0327
operator||
name|ControlMask
block|,
comment|/* 024 dc4 */
literal|0341
operator||
name|ControlMask
block|,
comment|/* 025 nak */
literal|0323
operator||
name|ControlMask
block|,
comment|/* 026 syn */
literal|0306
operator||
name|ControlMask
block|,
comment|/* 027 etb */
literal|0310
operator||
name|ControlMask
block|,
comment|/* 030 can */
literal|0334
operator||
name|ControlMask
block|,
comment|/* 031 em  */
literal|0303
operator||
name|ControlMask
block|,
comment|/* 032 sub */
literal|0372
operator||
name|ControlMask
block|,
comment|/* 033 esc */
literal|0367
operator||
name|ControlMask
block|,
comment|/* 034 fs  */
literal|0366
operator||
name|ControlMask
block|,
comment|/* 035 gs  */
literal|0277
operator||
name|ControlMask
block|,
comment|/* 036 rs  */
literal|0371
operator||
name|ControlMask
block|,
comment|/* 037 us  */
literal|0324
block|,
comment|/* 040 sp  */
literal|0300
operator||
name|ShiftMask
block|,
comment|/* 041  !  */
literal|0373
operator||
name|ShiftMask
block|,
comment|/* 042  "  */
literal|0313
operator||
name|ShiftMask
block|,
comment|/* 043  #  */
literal|0320
operator||
name|ShiftMask
block|,
comment|/* 044  $  */
literal|0326
operator||
name|ShiftMask
block|,
comment|/* 045  %  */
literal|0340
operator||
name|ShiftMask
block|,
comment|/* 046&  */
literal|0373
block|,
comment|/* 047  '  */
literal|0352
operator||
name|ShiftMask
block|,
comment|/* 050  (  */
literal|0357
operator||
name|ShiftMask
block|,
comment|/* 051  )  */
literal|0345
operator||
name|ShiftMask
block|,
comment|/* 052  *  */
literal|0365
operator||
name|ShiftMask
block|,
comment|/* 053  +  */
literal|0350
block|,
comment|/* 054  ,  */
literal|0371
block|,
comment|/* 055  -  */
literal|0355
block|,
comment|/* 056  .  */
literal|0363
block|,
comment|/* 057  /  */
literal|0357
block|,
comment|/* 060  0  */
literal|0300
block|,
comment|/* 061  1  */
literal|0305
block|,
comment|/* 062  2  */
literal|0313
block|,
comment|/* 063  3  */
literal|0320
block|,
comment|/* 064  4  */
literal|0326
block|,
comment|/* 065  5  */
literal|0333
block|,
comment|/* 066  6  */
literal|0340
block|,
comment|/* 067  7  */
literal|0345
block|,
comment|/* 070  8  */
literal|0352
block|,
comment|/* 071  9  */
literal|0362
operator||
name|ShiftMask
block|,
comment|/* 072  :  */
literal|0362
block|,
comment|/* 073  ;  */
literal|0350
operator||
name|ShiftMask
block|,
comment|/* 074<  */
literal|0365
block|,
comment|/* 075  =  */
literal|0355
operator||
name|ShiftMask
block|,
comment|/* 076>  */
literal|0363
operator||
name|ShiftMask
block|,
comment|/* 077  ?  */
literal|0305
operator||
name|ShiftMask
block|,
comment|/* 100  @  */
literal|0302
operator||
name|ShiftMask
block|,
comment|/* 101  A  */
literal|0331
operator||
name|ShiftMask
block|,
comment|/* 102  B  */
literal|0316
operator||
name|ShiftMask
block|,
comment|/* 103  C  */
literal|0315
operator||
name|ShiftMask
block|,
comment|/* 104  D  */
literal|0314
operator||
name|ShiftMask
block|,
comment|/* 105  E  */
literal|0322
operator||
name|ShiftMask
block|,
comment|/* 106  F  */
literal|0330
operator||
name|ShiftMask
block|,
comment|/* 107  G  */
literal|0335
operator||
name|ShiftMask
block|,
comment|/* 110  H  */
literal|0346
operator||
name|ShiftMask
block|,
comment|/* 111  I  */
literal|0342
operator||
name|ShiftMask
block|,
comment|/* 112  J  */
literal|0347
operator||
name|ShiftMask
block|,
comment|/* 113  K  */
literal|0354
operator||
name|ShiftMask
block|,
comment|/* 114  L  */
literal|0343
operator||
name|ShiftMask
block|,
comment|/* 115  M  */
literal|0336
operator||
name|ShiftMask
block|,
comment|/* 116  N  */
literal|0353
operator||
name|ShiftMask
block|,
comment|/* 117  O  */
literal|0360
operator||
name|ShiftMask
block|,
comment|/* 120  P  */
literal|0301
operator||
name|ShiftMask
block|,
comment|/* 121  Q  */
literal|0321
operator||
name|ShiftMask
block|,
comment|/* 122  R  */
literal|0307
operator||
name|ShiftMask
block|,
comment|/* 123  S  */
literal|0327
operator||
name|ShiftMask
block|,
comment|/* 124  T  */
literal|0341
operator||
name|ShiftMask
block|,
comment|/* 125  U  */
literal|0323
operator||
name|ShiftMask
block|,
comment|/* 126  V  */
literal|0306
operator||
name|ShiftMask
block|,
comment|/* 127  W  */
literal|0310
operator||
name|ShiftMask
block|,
comment|/* 130  X  */
literal|0334
operator||
name|ShiftMask
block|,
comment|/* 131  Y  */
literal|0303
operator||
name|ShiftMask
block|,
comment|/* 132  Z  */
literal|0372
block|,
comment|/* 133  [  */
literal|0367
block|,
comment|/* 134  \  */
literal|0366
block|,
comment|/* 135  ]  */
literal|0333
operator||
name|ShiftMask
block|,
comment|/* 136  ^  */
literal|0371
operator||
name|ShiftMask
block|,
comment|/* 137  _  */
literal|0277
block|,
comment|/* 140  `  */
literal|0302
block|,
comment|/* 141  a  */
literal|0331
block|,
comment|/* 142  b  */
literal|0316
block|,
comment|/* 143  c  */
literal|0315
block|,
comment|/* 144  d  */
literal|0314
block|,
comment|/* 145  e  */
literal|0322
block|,
comment|/* 146  f  */
literal|0330
block|,
comment|/* 147  g  */
literal|0335
block|,
comment|/* 150  h  */
literal|0346
block|,
comment|/* 151  i  */
literal|0342
block|,
comment|/* 152  j  */
literal|0347
block|,
comment|/* 153  k  */
literal|0354
block|,
comment|/* 154  l  */
literal|0343
block|,
comment|/* 155  m  */
literal|0336
block|,
comment|/* 156  n  */
literal|0353
block|,
comment|/* 157  o  */
literal|0360
block|,
comment|/* 160  p  */
literal|0301
block|,
comment|/* 161  q  */
literal|0321
block|,
comment|/* 162  r  */
literal|0307
block|,
comment|/* 163  s  */
literal|0327
block|,
comment|/* 164  t  */
literal|0341
block|,
comment|/* 165  u  */
literal|0323
block|,
comment|/* 166  v  */
literal|0306
block|,
comment|/* 167  w  */
literal|0310
block|,
comment|/* 170  x  */
literal|0334
block|,
comment|/* 171  y  */
literal|0303
block|,
comment|/* 172  z  */
literal|0372
operator||
name|ShiftMask
block|,
comment|/* 173  {  */
literal|0367
operator||
name|ShiftMask
block|,
comment|/* 174  | */
literal|0366
operator||
name|ShiftMask
block|,
comment|/* 175  }  */
literal|0277
operator||
name|ShiftMask
block|,
comment|/* 176  ~  */
literal|0274
block|,
comment|/* 177 del */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RAW_KBD
end_ifdef

begin_decl_stmt
specifier|static
name|u_short
name|TopKeys
index|[
literal|16
index|]
init|=
block|{
literal|0126
block|,
comment|/* F1 */
literal|0127
block|,
comment|/* F2 */
literal|0130
block|,
comment|/* F3 */
literal|0131
block|,
comment|/* F4 */
literal|0132
block|,
comment|/* F5 */
literal|0144
block|,
comment|/* F6 */
literal|0145
block|,
comment|/* F7 */
literal|0146
block|,
comment|/* F8 */
literal|0147
block|,
comment|/* F9 */
literal|0150
block|,
comment|/* F10 */
literal|0161
block|,
comment|/* F11/ESC */
literal|0162
block|,
comment|/* F12/BS */
literal|0163
block|,
comment|/* F13/LF */
literal|0164
block|,
comment|/* F14 */
literal|0174
block|,
comment|/* F15 */
literal|0175
block|,
comment|/* F16 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_short
name|RightKeys
index|[
literal|16
index|]
init|=
block|{
literal|0176
block|,
comment|/* R1 */
literal|0177
block|,
comment|/* R2 */
literal|0200
block|,
comment|/* R3 (F17) */
literal|0201
block|,
comment|/* R4 (F18) */
literal|0202
block|,
comment|/* R5 (F19) */
literal|0203
block|,
comment|/* R6 (F20) */
literal|0204
block|,
comment|/* R7 */
literal|0252
block|,
comment|/* R8 (UPARROW) */
literal|0205
block|,
comment|/* R9 */
literal|0247
block|,
comment|/* R10 (LEFTARROW) */
literal|0206
block|,
comment|/* R11 */
literal|0250
block|,
comment|/* R12 (RIGHTARROW) */
literal|0207
block|,
comment|/* R13 */
literal|0251
block|,
comment|/* R14 (DOWNARROW) */
literal|0210
block|,
comment|/* R15 */
literal|0211
block|,
comment|/* R16 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_short
name|LeftKeys
index|[
literal|16
index|]
init|=
block|{
literal|0212
block|,
comment|/* L1 (E1) */
literal|0213
block|,
comment|/* L2 (E2) */
literal|0214
block|,
comment|/* L3 (E3) */
literal|0215
block|,
comment|/* L4 (E4) */
literal|0216
block|,
comment|/* L5 (E5) */
literal|0217
block|,
comment|/* L6 (E6) */
literal|0241
block|,
comment|/* L7 (PF1) */
literal|0242
block|,
comment|/* L8 (PF2) */
literal|0243
block|,
comment|/* L9 (PF3) */
literal|0244
block|,
comment|/* L10(PF4) */
literal|0245
block|,
comment|/* L11/ALT */
literal|0246
block|,
comment|/* L12 */
literal|0253
block|,
comment|/* L13 */
literal|0254
block|,
comment|/* L14 */
literal|0255
block|,
comment|/* L15 */
literal|0262
block|,
comment|/* L16 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_short
name|BotKeys
index|[
literal|16
index|]
init|=
block|{
literal|0220
block|,
comment|/* B1 */
literal|0221
block|,
comment|/* B2 */
literal|0222
block|,
comment|/* B3 (KEYPAD_0) */
literal|0223
block|,
comment|/* B4 */
literal|0224
block|,
comment|/* B5 (KEYPAD_PERIOD) */
literal|0225
block|,
comment|/* B6 (ENTER) */
literal|0226
block|,
comment|/* B7 (KEYPAD_1) */
literal|0227
block|,
comment|/* B8 (KEYPAD_2) */
literal|0230
block|,
comment|/* B9 (KEYPAD_3) */
literal|0231
block|,
comment|/* B10 (KEYPAD_4) */
literal|0232
block|,
comment|/* B11 (KEYPAD_5) */
literal|0233
block|,
comment|/* B12 (KEYPAD_6) */
literal|0234
block|,
comment|/* B13 (KEYPAD_COMMA) */
literal|0235
block|,
comment|/* B14 (KEYPAD_7) */
literal|0236
block|,
comment|/* B15 (KEYPAD_8) */
literal|0237
block|,
comment|/* B16 (KEYPAD_9) */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

