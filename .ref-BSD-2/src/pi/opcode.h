begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*  * operations  */
end_comment

begin_define
define|#
directive|define
name|O_HALT
value|01
end_define

begin_define
define|#
directive|define
name|O_NULL
value|02
end_define

begin_define
define|#
directive|define
name|O_NODUMP
value|03
end_define

begin_define
define|#
directive|define
name|O_BEG
value|04
end_define

begin_define
define|#
directive|define
name|O_END
value|05
end_define

begin_define
define|#
directive|define
name|O_CALL
value|06
end_define

begin_define
define|#
directive|define
name|O_TRACNT
value|07
end_define

begin_define
define|#
directive|define
name|O_PUSH
value|010
end_define

begin_define
define|#
directive|define
name|O_POP
value|011
end_define

begin_define
define|#
directive|define
name|O_INX4
value|012
end_define

begin_define
define|#
directive|define
name|O_SDUP
value|013
end_define

begin_define
define|#
directive|define
name|O_IF
value|014
end_define

begin_define
define|#
directive|define
name|O_TRA
value|015
end_define

begin_define
define|#
directive|define
name|O_LINO
value|016
end_define

begin_define
define|#
directive|define
name|O_GOTO
value|017
end_define

begin_define
define|#
directive|define
name|O_REL2
value|020
end_define

begin_define
define|#
directive|define
name|O_REL4
value|021
end_define

begin_define
define|#
directive|define
name|O_REL24
value|022
end_define

begin_define
define|#
directive|define
name|O_REL42
value|023
end_define

begin_define
define|#
directive|define
name|O_REL8
value|024
end_define

begin_define
define|#
directive|define
name|O_RELG
value|025
end_define

begin_define
define|#
directive|define
name|O_RELT
value|026
end_define

begin_define
define|#
directive|define
name|O_REL28
value|030
end_define

begin_define
define|#
directive|define
name|O_REL48
value|031
end_define

begin_define
define|#
directive|define
name|O_REL82
value|032
end_define

begin_define
define|#
directive|define
name|O_REL84
value|033
end_define

begin_define
define|#
directive|define
name|O_AND
value|034
end_define

begin_define
define|#
directive|define
name|O_OR
value|035
end_define

begin_define
define|#
directive|define
name|O_NOT
value|036
end_define

begin_define
define|#
directive|define
name|O_AS2
value|040
end_define

begin_define
define|#
directive|define
name|O_AS4
value|041
end_define

begin_define
define|#
directive|define
name|O_AS24
value|042
end_define

begin_define
define|#
directive|define
name|O_AS42
value|043
end_define

begin_define
define|#
directive|define
name|O_AS8
value|044
end_define

begin_define
define|#
directive|define
name|O_INX2P2
value|045
end_define

begin_define
define|#
directive|define
name|O_INX4P2
value|046
end_define

begin_define
define|#
directive|define
name|O_AS
value|047
end_define

begin_define
define|#
directive|define
name|O_AS21
value|050
end_define

begin_define
define|#
directive|define
name|O_AS41
value|051
end_define

begin_define
define|#
directive|define
name|O_AS28
value|052
end_define

begin_define
define|#
directive|define
name|O_AS48
value|053
end_define

begin_define
define|#
directive|define
name|O_OFF
value|054
end_define

begin_define
define|#
directive|define
name|O_INX2
value|055
end_define

begin_define
define|#
directive|define
name|O_NIL
value|056
end_define

begin_define
define|#
directive|define
name|O_LV
value|057
end_define

begin_define
define|#
directive|define
name|O_ADD2
value|060
end_define

begin_define
define|#
directive|define
name|O_ADD4
value|061
end_define

begin_define
define|#
directive|define
name|O_ADD24
value|062
end_define

begin_define
define|#
directive|define
name|O_ADD42
value|063
end_define

begin_define
define|#
directive|define
name|O_ADD28
value|064
end_define

begin_define
define|#
directive|define
name|O_ADD48
value|065
end_define

begin_define
define|#
directive|define
name|O_ADD82
value|066
end_define

begin_define
define|#
directive|define
name|O_ADD84
value|067
end_define

begin_define
define|#
directive|define
name|O_SUB2
value|070
end_define

begin_define
define|#
directive|define
name|O_MUL2
value|0100
end_define

begin_define
define|#
directive|define
name|O_ABS2
value|0110
end_define

begin_define
define|#
directive|define
name|O_ABS8
value|0112
end_define

begin_define
define|#
directive|define
name|O_ADD8
value|0114
end_define

begin_define
define|#
directive|define
name|O_SUB8
value|0115
end_define

begin_define
define|#
directive|define
name|O_MUL8
value|0116
end_define

begin_define
define|#
directive|define
name|O_DVD8
value|0117
end_define

begin_define
define|#
directive|define
name|O_DIV2
value|0120
end_define

begin_define
define|#
directive|define
name|O_MOD2
value|0130
end_define

begin_define
define|#
directive|define
name|O_NEG2
value|0140
end_define

begin_define
define|#
directive|define
name|O_NEG8
value|0142
end_define

begin_define
define|#
directive|define
name|O_DVD2
value|0160
end_define

begin_define
define|#
directive|define
name|O_RV1
value|0170
end_define

begin_define
define|#
directive|define
name|O_RV2
value|0171
end_define

begin_define
define|#
directive|define
name|O_RV4
value|0172
end_define

begin_define
define|#
directive|define
name|O_RV8
value|0173
end_define

begin_define
define|#
directive|define
name|O_IND1
value|0174
end_define

begin_define
define|#
directive|define
name|O_IND2
value|0175
end_define

begin_define
define|#
directive|define
name|O_CON1
value|0200
end_define

begin_define
define|#
directive|define
name|O_CON2
value|0201
end_define

begin_define
define|#
directive|define
name|O_CON4
value|0202
end_define

begin_define
define|#
directive|define
name|O_CON8
value|0203
end_define

begin_define
define|#
directive|define
name|O_RV
value|0204
end_define

begin_define
define|#
directive|define
name|O_IND
value|0205
end_define

begin_define
define|#
directive|define
name|O_CON
value|0206
end_define

begin_define
define|#
directive|define
name|O_RANG2
value|0210
end_define

begin_define
define|#
directive|define
name|O_RANG42
value|0211
end_define

begin_define
define|#
directive|define
name|O_RSNG2
value|0212
end_define

begin_define
define|#
directive|define
name|O_RSNG42
value|0213
end_define

begin_define
define|#
directive|define
name|O_RANG4
value|0214
end_define

begin_define
define|#
directive|define
name|O_RSNG4
value|0216
end_define

begin_define
define|#
directive|define
name|O_RSNG24
value|0217
end_define

begin_define
define|#
directive|define
name|O_CONC
value|0230
end_define

begin_define
define|#
directive|define
name|O_CASEBEG
value|0231
end_define

begin_define
define|#
directive|define
name|O_CASE1
value|0232
end_define

begin_define
define|#
directive|define
name|O_CASE2
value|0233
end_define

begin_define
define|#
directive|define
name|O_CASE4
value|0234
end_define

begin_define
define|#
directive|define
name|O_CASEEND
value|0235
end_define

begin_define
define|#
directive|define
name|O_CONG
value|0236
end_define

begin_define
define|#
directive|define
name|O_ORD2
value|0237
end_define

begin_define
define|#
directive|define
name|O_CASE1OP
value|0240
end_define

begin_define
define|#
directive|define
name|O_CASE2OP
value|0241
end_define

begin_define
define|#
directive|define
name|O_CASE4OP
value|0242
end_define

begin_define
define|#
directive|define
name|O_PXPBUF
value|0243
end_define

begin_define
define|#
directive|define
name|O_COUNT
value|0244
end_define

begin_define
define|#
directive|define
name|O_ADDT
value|0250
end_define

begin_define
define|#
directive|define
name|O_SUBT
value|0251
end_define

begin_define
define|#
directive|define
name|O_MULT
value|0252
end_define

begin_define
define|#
directive|define
name|O_INCT
value|0253
end_define

begin_define
define|#
directive|define
name|O_CTTOT
value|0254
end_define

begin_define
define|#
directive|define
name|O_CARD
value|0255
end_define

begin_define
define|#
directive|define
name|O_IN
value|0256
end_define

begin_define
define|#
directive|define
name|O_ASRT
value|0257
end_define

begin_define
define|#
directive|define
name|O_FOR1U
value|0260
end_define

begin_define
define|#
directive|define
name|O_FOR2U
value|0261
end_define

begin_define
define|#
directive|define
name|O_FOR4U
value|0262
end_define

begin_define
define|#
directive|define
name|O_FOR1D
value|0263
end_define

begin_define
define|#
directive|define
name|O_FOR2D
value|0264
end_define

begin_define
define|#
directive|define
name|O_FOR4D
value|0265
end_define

begin_define
define|#
directive|define
name|O_STLIM
value|0266
end_define

begin_define
define|#
directive|define
name|O_SCLCK
value|0267
end_define

begin_define
define|#
directive|define
name|O_STOI
value|0270
end_define

begin_define
define|#
directive|define
name|O_STOD
value|0271
end_define

begin_define
define|#
directive|define
name|O_ITOD
value|0272
end_define

begin_define
define|#
directive|define
name|O_ITOS
value|0273
end_define

begin_define
define|#
directive|define
name|O_BUFF
value|0274
end_define

begin_define
define|#
directive|define
name|O_WCLCK
value|0275
end_define

begin_define
define|#
directive|define
name|O_WRHEX2
value|0276
end_define

begin_define
define|#
directive|define
name|O_GET
value|0300
end_define

begin_define
define|#
directive|define
name|O_PUT
value|0301
end_define

begin_define
define|#
directive|define
name|O_MESSAGE
value|0302
end_define

begin_define
define|#
directive|define
name|O_FNIL
value|0303
end_define

begin_define
define|#
directive|define
name|O_EOF
value|0304
end_define

begin_define
define|#
directive|define
name|O_EOLN
value|0305
end_define

begin_define
define|#
directive|define
name|O_RESET
value|0306
end_define

begin_define
define|#
directive|define
name|O_REWRITE
value|0307
end_define

begin_define
define|#
directive|define
name|O_REMOVE
value|0310
end_define

begin_define
define|#
directive|define
name|O_READ4
value|0311
end_define

begin_define
define|#
directive|define
name|O_UNIT
value|0312
end_define

begin_define
define|#
directive|define
name|O_READC
value|0313
end_define

begin_define
define|#
directive|define
name|O_READ8
value|0314
end_define

begin_define
define|#
directive|define
name|O_UNITINP
value|0315
end_define

begin_define
define|#
directive|define
name|O_UNITOUT
value|0316
end_define

begin_define
define|#
directive|define
name|O_READLN
value|0317
end_define

begin_define
define|#
directive|define
name|O_WRIT2
value|0320
end_define

begin_define
define|#
directive|define
name|O_WRIT4
value|0321
end_define

begin_define
define|#
directive|define
name|O_WRITB
value|0322
end_define

begin_define
define|#
directive|define
name|O_WRITC
value|0323
end_define

begin_define
define|#
directive|define
name|O_WRIT8
value|0324
end_define

begin_define
define|#
directive|define
name|O_WRITG
value|0325
end_define

begin_define
define|#
directive|define
name|O_WRIT82
value|0326
end_define

begin_define
define|#
directive|define
name|O_WRITLN
value|0327
end_define

begin_define
define|#
directive|define
name|O_WROCT2
value|0330
end_define

begin_define
define|#
directive|define
name|O_FLUSH
value|0332
end_define

begin_define
define|#
directive|define
name|O_PACK
value|0333
end_define

begin_define
define|#
directive|define
name|O_UNPACK
value|0334
end_define

begin_define
define|#
directive|define
name|O_LLIMIT
value|0335
end_define

begin_define
define|#
directive|define
name|O_ARGC
value|0336
end_define

begin_define
define|#
directive|define
name|O_ARGV
value|0337
end_define

begin_define
define|#
directive|define
name|O_CLCK
value|0340
end_define

begin_define
define|#
directive|define
name|O_SEED
value|0341
end_define

begin_define
define|#
directive|define
name|O_RANDOM
value|0342
end_define

begin_define
define|#
directive|define
name|O_DISPOSE
value|0343
end_define

begin_define
define|#
directive|define
name|O_NEW
value|0344
end_define

begin_define
define|#
directive|define
name|O_EXPO
value|0345
end_define

begin_define
define|#
directive|define
name|O_DATE
value|0346
end_define

begin_define
define|#
directive|define
name|O_TIME
value|0347
end_define

begin_define
define|#
directive|define
name|O_ATAN
value|0350
end_define

begin_define
define|#
directive|define
name|O_COS
value|0351
end_define

begin_define
define|#
directive|define
name|O_EXP
value|0352
end_define

begin_define
define|#
directive|define
name|O_LN
value|0353
end_define

begin_define
define|#
directive|define
name|O_SIN
value|0354
end_define

begin_define
define|#
directive|define
name|O_SQRT
value|0355
end_define

begin_define
define|#
directive|define
name|O_CHR2
value|0356
end_define

begin_define
define|#
directive|define
name|O_ODD2
value|0360
end_define

begin_define
define|#
directive|define
name|O_PRED2
value|0362
end_define

begin_define
define|#
directive|define
name|O_PRED24
value|0364
end_define

begin_define
define|#
directive|define
name|O_SUCC2
value|0365
end_define

begin_define
define|#
directive|define
name|O_DEFNAME
value|0370
end_define

begin_define
define|#
directive|define
name|O_PAGE
value|0371
end_define

begin_define
define|#
directive|define
name|O_UNDEF
value|0372
end_define

begin_define
define|#
directive|define
name|O_SQR2
value|0373
end_define

begin_define
define|#
directive|define
name|O_ROUND
value|0376
end_define

begin_define
define|#
directive|define
name|O_TRUNC
value|0377
end_define

end_unit

