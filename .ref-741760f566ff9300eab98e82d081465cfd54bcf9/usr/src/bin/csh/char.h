begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley Software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)char.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Table for spotting special characters quickly  *  * Makes for very obscure but efficient coding.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|_cmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_Q
value|0x01
end_define

begin_comment
comment|/* '" */
end_comment

begin_define
define|#
directive|define
name|_Q1
value|0x02
end_define

begin_comment
comment|/* ` */
end_comment

begin_define
define|#
directive|define
name|_SP
value|0x04
end_define

begin_comment
comment|/* space and tab */
end_comment

begin_define
define|#
directive|define
name|_NL
value|0x08
end_define

begin_comment
comment|/* \n */
end_comment

begin_define
define|#
directive|define
name|_META
value|0x10
end_define

begin_comment
comment|/* lex meta characters, sp #'`";&<>()|\t\n */
end_comment

begin_define
define|#
directive|define
name|_GLOB
value|0x20
end_define

begin_comment
comment|/* glob characters, *?{[` */
end_comment

begin_define
define|#
directive|define
name|_ESC
value|0x40
end_define

begin_comment
comment|/* \ */
end_comment

begin_define
define|#
directive|define
name|_DOL
value|0x80
end_define

begin_comment
comment|/* $ */
end_comment

begin_define
define|#
directive|define
name|_DIG
value|0x100
end_define

begin_comment
comment|/* 0-9 */
end_comment

begin_define
define|#
directive|define
name|_LET
value|0x200
end_define

begin_comment
comment|/* a-z, A-Z, _ */
end_comment

begin_define
define|#
directive|define
name|cmap
parameter_list|(
name|c
parameter_list|,
name|bits
parameter_list|)
value|(_cmap[(unsigned char)(c)]& (bits))
end_define

begin_define
define|#
directive|define
name|isglob
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _GLOB)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP)
end_define

begin_define
define|#
directive|define
name|isspnl
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP|_NL)
end_define

begin_define
define|#
directive|define
name|ismeta
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _META)
end_define

begin_define
define|#
directive|define
name|digit
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _DIG)
end_define

begin_define
define|#
directive|define
name|letter
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _LET)
end_define

begin_define
define|#
directive|define
name|alnum
parameter_list|(
name|c
parameter_list|)
value|(digit(c) || letter(c))
end_define

end_unit

