begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Interpress utilities  *  * Copyright (c) 1984, 1985 Xerox Corp.  *  *  Written for Xerox Corporation by William LeFebvre  *  24-May-1984  *  */
end_comment

begin_comment
comment|/*  This header appears at the front of every Interpress file  */
end_comment

begin_define
define|#
directive|define
name|IP_Header
value|"Interpress/Xerox/1.0 "
end_define

begin_comment
comment|/* For convenience -- POINT is the size of a point in meters */
end_comment

begin_define
define|#
directive|define
name|POINT
value|(0.00035278)
end_define

begin_comment
comment|/*  *  Definitions pertaining to InterPress tokes:  */
end_comment

begin_define
define|#
directive|define
name|SHORT_OP
value|0200
end_define

begin_define
define|#
directive|define
name|LONG_OP
value|0240
end_define

begin_define
define|#
directive|define
name|SHORT_INTEGER
value|0000
end_define

begin_define
define|#
directive|define
name|SHORT_SEQUENCE
value|0300
end_define

begin_define
define|#
directive|define
name|LONG_SEQUENCE
value|0340
end_define

begin_comment
comment|/* these help us cope with short integer tokens: */
end_comment

begin_define
define|#
directive|define
name|INTEGER_ZERO
value|4000
end_define

begin_define
define|#
directive|define
name|INTEGER_MAX
value|(32767 - INTEGER_ZERO)
end_define

begin_define
define|#
directive|define
name|INTEGER_MIN
value|(0 - INTEGER_ZERO)
end_define

begin_comment
comment|/* the long and short of sequences: */
end_comment

begin_define
define|#
directive|define
name|SHORT_SEQUENCE_LIMIT
value|255
end_define

begin_comment
comment|/* (8 bits) */
end_comment

begin_define
define|#
directive|define
name|LONG_SEQUENCE_LIMIT
value|16777215
end_define

begin_comment
comment|/* (24 bits) */
end_comment

begin_comment
comment|/* Sequence types: */
end_comment

begin_define
define|#
directive|define
name|sequenceAdaptivePixelVector
value|12
end_define

begin_define
define|#
directive|define
name|sequenceAPV
value|sequenceAdaptivePixelVector
end_define

begin_define
define|#
directive|define
name|sequenceComment
value|6
end_define

begin_define
define|#
directive|define
name|sequenceCompressedPixelVector
value|10
end_define

begin_define
define|#
directive|define
name|sequenceCPV
value|sequenceCompressedPixelVector
end_define

begin_define
define|#
directive|define
name|sequenceContinued
value|7
end_define

begin_define
define|#
directive|define
name|sequenceIdentifier
value|5
end_define

begin_define
define|#
directive|define
name|sequenceInsertFile
value|11
end_define

begin_define
define|#
directive|define
name|sequenceInteger
value|2
end_define

begin_define
define|#
directive|define
name|sequenceLargeVector
value|8
end_define

begin_define
define|#
directive|define
name|sequencePackedPixelVector
value|9
end_define

begin_define
define|#
directive|define
name|sequencePPV
value|sequencePackedPixelVector
end_define

begin_define
define|#
directive|define
name|sequenceRational
value|4
end_define

begin_define
define|#
directive|define
name|sequenceString
value|1
end_define

begin_comment
comment|/* imager variables: */
end_comment

begin_define
define|#
directive|define
name|I_DCScpx
value|0
end_define

begin_define
define|#
directive|define
name|I_DCScpy
value|1
end_define

begin_define
define|#
directive|define
name|I_correctMX
value|2
end_define

begin_define
define|#
directive|define
name|I_correctMY
value|3
end_define

begin_define
define|#
directive|define
name|I_T
value|4
end_define

begin_define
define|#
directive|define
name|I_priorityImportant
value|5
end_define

begin_define
define|#
directive|define
name|I_mediumXSize
value|6
end_define

begin_define
define|#
directive|define
name|I_mediumYSize
value|7
end_define

begin_define
define|#
directive|define
name|I_fieldXMin
value|8
end_define

begin_define
define|#
directive|define
name|I_fieldYMin
value|9
end_define

begin_define
define|#
directive|define
name|I_fieldXMax
value|10
end_define

begin_define
define|#
directive|define
name|I_fieldYMax
value|11
end_define

begin_define
define|#
directive|define
name|I_showVec
value|12
end_define

begin_define
define|#
directive|define
name|I_color
value|13
end_define

begin_define
define|#
directive|define
name|I_noImage
value|14
end_define

begin_define
define|#
directive|define
name|I_strokeWidth
value|15
end_define

begin_define
define|#
directive|define
name|I_strokeEnd
value|16
end_define

begin_define
define|#
directive|define
name|I_underlineStart
value|17
end_define

begin_define
define|#
directive|define
name|I_amplifySpace
value|18
end_define

begin_define
define|#
directive|define
name|I_correctPass
value|19
end_define

begin_define
define|#
directive|define
name|I_correctShrink
value|20
end_define

begin_define
define|#
directive|define
name|I_correctTX
value|21
end_define

begin_define
define|#
directive|define
name|I_correctTY
value|22
end_define

begin_comment
comment|/* operation codes: */
end_comment

begin_define
define|#
directive|define
name|OP_nil
value|0
end_define

begin_define
define|#
directive|define
name|OP_nop
value|1
end_define

begin_define
define|#
directive|define
name|OP_setxy
value|10
end_define

begin_define
define|#
directive|define
name|OP_setxyrel
value|11
end_define

begin_define
define|#
directive|define
name|OP_setxrel
value|12
end_define

begin_define
define|#
directive|define
name|OP_setyrel
value|13
end_define

begin_define
define|#
directive|define
name|OP_linetox
value|14
end_define

begin_define
define|#
directive|define
name|OP_linetoy
value|15
end_define

begin_define
define|#
directive|define
name|OP_space
value|16
end_define

begin_define
define|#
directive|define
name|OP_get
value|17
end_define

begin_define
define|#
directive|define
name|OP_iget
value|18
end_define

begin_define
define|#
directive|define
name|OP_iset
value|19
end_define

begin_define
define|#
directive|define
name|OP_fget
value|20
end_define

begin_define
define|#
directive|define
name|OP_fset
value|21
end_define

begin_define
define|#
directive|define
name|OP_show
value|22
end_define

begin_define
define|#
directive|define
name|OP_lineto
value|23
end_define

begin_define
define|#
directive|define
name|OP_maskstroke
value|24
end_define

begin_define
define|#
directive|define
name|OP_moveto
value|25
end_define

begin_define
define|#
directive|define
name|SHORT_OP_LIMIT
value|31
end_define

begin_define
define|#
directive|define
name|OP_metricMaster
value|100
end_define

begin_define
define|#
directive|define
name|OP_environmentMaster
value|101
end_define

begin_define
define|#
directive|define
name|OP_beginBlock
value|102
end_define

begin_define
define|#
directive|define
name|OP_endBlock
value|103
end_define

begin_define
define|#
directive|define
name|OP_noPages
value|104
end_define

begin_define
define|#
directive|define
name|OP_pageInstructions
value|105
end_define

begin_define
define|#
directive|define
name|OP_beginBody
value|106
end_define

begin_define
define|#
directive|define
name|OP_endBody
value|107
end_define

begin_define
define|#
directive|define
name|OP_correct
value|110
end_define

begin_define
define|#
directive|define
name|OP_makesimpleco
value|114
end_define

begin_define
define|#
directive|define
name|OP_makeco
value|115
end_define

begin_define
define|#
directive|define
name|OP_makecompiledimage
value|116
end_define

begin_define
define|#
directive|define
name|OP_dosavesimplebody
value|120
end_define

begin_define
define|#
directive|define
name|OP_dobody
value|121
end_define

begin_define
define|#
directive|define
name|OP_dosavebody
value|122
end_define

begin_define
define|#
directive|define
name|OP_dosaveallbody
value|123
end_define

begin_define
define|#
directive|define
name|OP_showandxrel
value|146
end_define

begin_define
define|#
directive|define
name|OP_findfont
value|147
end_define

begin_define
define|#
directive|define
name|OP_modifyfont
value|148
end_define

begin_define
define|#
directive|define
name|OP_finddecompressor
value|149
end_define

begin_define
define|#
directive|define
name|OP_findfontvec
value|150
end_define

begin_define
define|#
directive|define
name|OP_setfont
value|151
end_define

begin_define
define|#
directive|define
name|OP_setcorrectmeasure
value|154
end_define

begin_define
define|#
directive|define
name|OP_setcorrecttollerance
value|155
end_define

begin_define
define|#
directive|define
name|OP_correctmask
value|156
end_define

begin_define
define|#
directive|define
name|OP_correctspace
value|157
end_define

begin_define
define|#
directive|define
name|OP_getcp
value|159
end_define

begin_define
define|#
directive|define
name|OP_maket
value|160
end_define

begin_define
define|#
directive|define
name|OP_opent
value|161
end_define

begin_define
define|#
directive|define
name|OP_translate
value|162
end_define

begin_define
define|#
directive|define
name|OP_rotate
value|163
end_define

begin_define
define|#
directive|define
name|OP_scale
value|164
end_define

begin_define
define|#
directive|define
name|OP_concat
value|165
end_define

begin_define
define|#
directive|define
name|OP_scale2
value|166
end_define

begin_define
define|#
directive|define
name|OP_invert
value|167
end_define

begin_define
define|#
directive|define
name|OP_concatt
value|168
end_define

begin_define
define|#
directive|define
name|OP_move
value|169
end_define

begin_define
define|#
directive|define
name|OP_trans
value|170
end_define

begin_define
define|#
directive|define
name|OP_transform
value|174
end_define

begin_define
define|#
directive|define
name|OP_transformvewc
value|175
end_define

begin_define
define|#
directive|define
name|OP_roundxy
value|176
end_define

begin_define
define|#
directive|define
name|OP_roundxyvec
value|177
end_define

begin_define
define|#
directive|define
name|OP_pop
value|180
end_define

begin_define
define|#
directive|define
name|OP_dup
value|181
end_define

begin_define
define|#
directive|define
name|OP_copy
value|183
end_define

begin_define
define|#
directive|define
name|OP_roll
value|184
end_define

begin_define
define|#
directive|define
name|OP_exch
value|185
end_define

begin_define
define|#
directive|define
name|OP_mark
value|186
end_define

begin_define
define|#
directive|define
name|OP_unmark
value|187
end_define

begin_define
define|#
directive|define
name|OP_count
value|188
end_define

begin_define
define|#
directive|define
name|OP_unmark0
value|192
end_define

begin_define
define|#
directive|define
name|OP_abs
value|200
end_define

begin_define
define|#
directive|define
name|OP_add
value|201
end_define

begin_define
define|#
directive|define
name|OP_and
value|202
end_define

begin_define
define|#
directive|define
name|OP_ceiling
value|203
end_define

begin_define
define|#
directive|define
name|OP_div
value|204
end_define

begin_define
define|#
directive|define
name|OP_eq
value|205
end_define

begin_define
define|#
directive|define
name|OP_floor
value|206
end_define

begin_define
define|#
directive|define
name|OP_ge
value|207
end_define

begin_define
define|#
directive|define
name|OP_gt
value|208
end_define

begin_define
define|#
directive|define
name|OP_mod
value|209
end_define

begin_define
define|#
directive|define
name|OP_mul
value|210
end_define

begin_define
define|#
directive|define
name|OP_neg
value|211
end_define

begin_define
define|#
directive|define
name|OP_not
value|212
end_define

begin_define
define|#
directive|define
name|OP_or
value|213
end_define

begin_define
define|#
directive|define
name|OP_sub
value|214
end_define

begin_define
define|#
directive|define
name|OP_trunc
value|215
end_define

begin_define
define|#
directive|define
name|OP_rem
value|216
end_define

begin_define
define|#
directive|define
name|OP_round
value|217
end_define

begin_define
define|#
directive|define
name|OP_eqn
value|218
end_define

begin_define
define|#
directive|define
name|OP_type
value|220
end_define

begin_define
define|#
directive|define
name|OP_atan
value|221
end_define

begin_define
define|#
directive|define
name|OP_cos
value|222
end_define

begin_define
define|#
directive|define
name|OP_exp
value|223
end_define

begin_define
define|#
directive|define
name|OP_log
value|224
end_define

begin_define
define|#
directive|define
name|OP_sin
value|225
end_define

begin_define
define|#
directive|define
name|OP_sqrt
value|226
end_define

begin_define
define|#
directive|define
name|OP_max
value|227
end_define

begin_define
define|#
directive|define
name|OP_min
value|228
end_define

begin_define
define|#
directive|define
name|OP_do
value|231
end_define

begin_define
define|#
directive|define
name|OP_dosave
value|232
end_define

begin_define
define|#
directive|define
name|OP_dosaveall
value|233
end_define

begin_define
define|#
directive|define
name|OP_if
value|239
end_define

begin_define
define|#
directive|define
name|OP_ifcopy
value|240
end_define

begin_define
define|#
directive|define
name|OP_ifelse
value|241
end_define

begin_define
define|#
directive|define
name|OP_loop
value|242
end_define

begin_define
define|#
directive|define
name|OP_frame
value|250
end_define

begin_define
define|#
directive|define
name|OP_poolop
value|253
end_define

begin_define
define|#
directive|define
name|OP_pool
value|254
end_define

begin_define
define|#
directive|define
name|OP_pget
value|255
end_define

begin_define
define|#
directive|define
name|OP_pset
value|256
end_define

begin_define
define|#
directive|define
name|OP_makepool
value|257
end_define

begin_define
define|#
directive|define
name|OP_nopool
value|258
end_define

begin_define
define|#
directive|define
name|OP_env
value|260
end_define

begin_define
define|#
directive|define
name|OP_makeveclu
value|282
end_define

begin_define
define|#
directive|define
name|OP_makevec
value|283
end_define

begin_define
define|#
directive|define
name|OP_shape
value|285
end_define

begin_define
define|#
directive|define
name|OP_openvec
value|286
end_define

begin_define
define|#
directive|define
name|OP_getprop
value|287
end_define

begin_define
define|#
directive|define
name|OP_getp
value|288
end_define

begin_define
define|#
directive|define
name|OP_mergeprop
value|289
end_define

begin_define
define|#
directive|define
name|OP_dround
value|300
end_define

begin_define
define|#
directive|define
name|OP_getcprounded
value|301
end_define

begin_define
define|#
directive|define
name|OP_curveto
value|402
end_define

begin_define
define|#
directive|define
name|OP_arcto
value|403
end_define

begin_define
define|#
directive|define
name|OP_conicto
value|404
end_define

begin_define
define|#
directive|define
name|OP_maskfill
value|409
end_define

begin_define
define|#
directive|define
name|OP_maskrectangle
value|410
end_define

begin_define
define|#
directive|define
name|OP_masktrapezoidx
value|411
end_define

begin_define
define|#
directive|define
name|OP_masktrapezoidy
value|412
end_define

begin_define
define|#
directive|define
name|OP_startunderline
value|413
end_define

begin_define
define|#
directive|define
name|OP_maskunderline
value|414
end_define

begin_define
define|#
directive|define
name|OP_makeoutline
value|417
end_define

begin_define
define|#
directive|define
name|OP_clipoutline
value|418
end_define

begin_define
define|#
directive|define
name|OP_cliprectangle
value|419
end_define

begin_define
define|#
directive|define
name|OP_findcoloroperator
value|421
end_define

begin_define
define|#
directive|define
name|OP_findcolormodeloperator
value|422
end_define

begin_define
define|#
directive|define
name|OP_findcolor
value|423
end_define

begin_define
define|#
directive|define
name|OP_setgray
value|424
end_define

begin_define
define|#
directive|define
name|OP_makegray
value|425
end_define

begin_define
define|#
directive|define
name|OP_makesampledblack
value|426
end_define

begin_define
define|#
directive|define
name|OP_makesampledcolor
value|427
end_define

begin_define
define|#
directive|define
name|OP_maskstrokeclosed
value|440
end_define

begin_define
define|#
directive|define
name|OP_maskvector
value|441
end_define

begin_define
define|#
directive|define
name|OP_makepixelarray
value|450
end_define

begin_define
define|#
directive|define
name|OP_extractpixelarray
value|451
end_define

begin_define
define|#
directive|define
name|OP_maskpixel
value|452
end_define

begin_define
define|#
directive|define
name|OP_LIMIT
value|OP_maskpixel
end_define

end_unit

