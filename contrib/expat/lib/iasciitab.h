begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd    See the file COPYING for copying permission. */
end_comment

begin_comment
comment|/* Like asciitab.h, except that 0xD has code BT_S rather than BT_CR */
end_comment

begin_comment
comment|/* 0x00 */
end_comment

begin_expr_stmt
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x04 */
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x08 */
name|BT_NONXML
operator|,
name|BT_S
operator|,
name|BT_LF
operator|,
name|BT_NONXML
operator|,
comment|/* 0x0C */
name|BT_NONXML
operator|,
name|BT_S
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x10 */
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x14 */
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x18 */
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x1C */
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
name|BT_NONXML
operator|,
comment|/* 0x20 */
name|BT_S
operator|,
name|BT_EXCL
operator|,
name|BT_QUOT
operator|,
name|BT_NUM
operator|,
comment|/* 0x24 */
name|BT_OTHER
operator|,
name|BT_PERCNT
operator|,
name|BT_AMP
operator|,
name|BT_APOS
operator|,
comment|/* 0x28 */
name|BT_LPAR
operator|,
name|BT_RPAR
operator|,
name|BT_AST
operator|,
name|BT_PLUS
operator|,
comment|/* 0x2C */
name|BT_COMMA
operator|,
name|BT_MINUS
operator|,
name|BT_NAME
operator|,
name|BT_SOL
operator|,
comment|/* 0x30 */
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
comment|/* 0x34 */
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
comment|/* 0x38 */
name|BT_DIGIT
operator|,
name|BT_DIGIT
operator|,
name|BT_COLON
operator|,
name|BT_SEMI
operator|,
comment|/* 0x3C */
name|BT_LT
operator|,
name|BT_EQUALS
operator|,
name|BT_GT
operator|,
name|BT_QUEST
operator|,
comment|/* 0x40 */
name|BT_OTHER
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
comment|/* 0x44 */
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x48 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x4C */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x50 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x54 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x58 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_LSQB
operator|,
comment|/* 0x5C */
name|BT_OTHER
operator|,
name|BT_RSQB
operator|,
name|BT_OTHER
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x60 */
name|BT_OTHER
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
comment|/* 0x64 */
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_HEX
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x68 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x6C */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x70 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x74 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
comment|/* 0x78 */
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_NMSTRT
operator|,
name|BT_OTHER
operator|,
comment|/* 0x7C */
name|BT_VERBAR
operator|,
name|BT_OTHER
operator|,
name|BT_OTHER
operator|,
name|BT_OTHER
operator|,
end_expr_stmt

end_unit

