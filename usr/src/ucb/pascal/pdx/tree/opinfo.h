begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)opinfo.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_comment
comment|/*  * Tree operator definitions.  */
end_comment

begin_struct
struct|struct
name|opinfo
block|{
name|short
name|opflags
decl_stmt|;
name|char
modifier|*
name|opstring
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|OPINFO
name|opinfo
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|O_NOP
value|0
end_define

begin_comment
comment|/* no op */
end_comment

begin_define
define|#
directive|define
name|O_NAME
value|1
end_define

begin_comment
comment|/* leaf op for address of a variable */
end_comment

begin_define
define|#
directive|define
name|O_QNAME
value|2
end_define

begin_comment
comment|/* variable qualified by surrounding block */
end_comment

begin_define
define|#
directive|define
name|O_LCON
value|3
end_define

begin_comment
comment|/* long constant (i.e. integer) */
end_comment

begin_define
define|#
directive|define
name|O_FCON
value|4
end_define

begin_comment
comment|/* floating constant (i.e. real) */
end_comment

begin_define
define|#
directive|define
name|O_SCON
value|5
end_define

begin_comment
comment|/* string constant (type alfa) */
end_comment

begin_define
define|#
directive|define
name|O_INDEX
value|6
end_define

begin_comment
comment|/* array subscript (does just one index) */
end_comment

begin_define
define|#
directive|define
name|O_INDIR
value|7
end_define

begin_comment
comment|/* indirection through a pointer */
end_comment

begin_define
define|#
directive|define
name|O_RVAL
value|8
end_define

begin_comment
comment|/* get value of an operand address */
end_comment

begin_define
define|#
directive|define
name|O_COMMA
value|9
end_define

begin_comment
comment|/* as in parameter lists */
end_comment

begin_comment
comment|/*  * arithmetic operators  */
end_comment

begin_define
define|#
directive|define
name|O_ITOF
value|10
end_define

begin_comment
comment|/* convert integer to real */
end_comment

begin_define
define|#
directive|define
name|O_ADD
value|11
end_define

begin_define
define|#
directive|define
name|O_ADDF
value|12
end_define

begin_define
define|#
directive|define
name|O_SUB
value|13
end_define

begin_define
define|#
directive|define
name|O_SUBF
value|14
end_define

begin_define
define|#
directive|define
name|O_NEG
value|15
end_define

begin_define
define|#
directive|define
name|O_NEGF
value|16
end_define

begin_define
define|#
directive|define
name|O_MUL
value|17
end_define

begin_define
define|#
directive|define
name|O_MULF
value|18
end_define

begin_define
define|#
directive|define
name|O_DIVF
value|19
end_define

begin_comment
comment|/* real divided by real */
end_comment

begin_define
define|#
directive|define
name|O_DIV
value|20
end_define

begin_comment
comment|/* integer divided by integer, integer result */
end_comment

begin_define
define|#
directive|define
name|O_MOD
value|21
end_define

begin_comment
comment|/*  * logical operators  */
end_comment

begin_define
define|#
directive|define
name|O_AND
value|22
end_define

begin_define
define|#
directive|define
name|O_OR
value|23
end_define

begin_comment
comment|/*  * relational operators  */
end_comment

begin_define
define|#
directive|define
name|O_LT
value|24
end_define

begin_define
define|#
directive|define
name|O_LTF
value|25
end_define

begin_define
define|#
directive|define
name|O_LE
value|26
end_define

begin_define
define|#
directive|define
name|O_LEF
value|27
end_define

begin_define
define|#
directive|define
name|O_GT
value|28
end_define

begin_define
define|#
directive|define
name|O_GTF
value|29
end_define

begin_define
define|#
directive|define
name|O_GE
value|30
end_define

begin_define
define|#
directive|define
name|O_GEF
value|31
end_define

begin_define
define|#
directive|define
name|O_EQ
value|32
end_define

begin_define
define|#
directive|define
name|O_EQF
value|33
end_define

begin_define
define|#
directive|define
name|O_NE
value|34
end_define

begin_define
define|#
directive|define
name|O_NEF
value|35
end_define

begin_comment
comment|/*  * debugger commands  */
end_comment

begin_define
define|#
directive|define
name|O_ASSIGN
value|36
end_define

begin_define
define|#
directive|define
name|O_CHFILE
value|37
end_define

begin_define
define|#
directive|define
name|O_CONT
value|38
end_define

begin_define
define|#
directive|define
name|O_LIST
value|39
end_define

begin_define
define|#
directive|define
name|O_NEXT
value|40
end_define

begin_define
define|#
directive|define
name|O_PRINT
value|41
end_define

begin_define
define|#
directive|define
name|O_STEP
value|42
end_define

begin_define
define|#
directive|define
name|O_WHATIS
value|43
end_define

begin_define
define|#
directive|define
name|O_WHERE
value|44
end_define

begin_define
define|#
directive|define
name|O_XI
value|45
end_define

begin_define
define|#
directive|define
name|O_XD
value|46
end_define

begin_define
define|#
directive|define
name|O_CALL
value|47
end_define

begin_define
define|#
directive|define
name|O_EDIT
value|48
end_define

begin_define
define|#
directive|define
name|O_DUMP
value|49
end_define

begin_define
define|#
directive|define
name|O_HELP
value|50
end_define

begin_define
define|#
directive|define
name|O_REMAKE
value|51
end_define

begin_define
define|#
directive|define
name|O_RUN
value|52
end_define

begin_define
define|#
directive|define
name|O_SOURCE
value|53
end_define

begin_define
define|#
directive|define
name|O_STATUS
value|54
end_define

begin_define
define|#
directive|define
name|O_TRACE
value|55
end_define

begin_define
define|#
directive|define
name|O_TRACEI
value|56
end_define

begin_define
define|#
directive|define
name|O_STOP
value|57
end_define

begin_define
define|#
directive|define
name|O_STOPI
value|58
end_define

begin_define
define|#
directive|define
name|O_DELETE
value|59
end_define

begin_define
define|#
directive|define
name|O_WHICH
value|60
end_define

begin_define
define|#
directive|define
name|O_QLINE
value|61
end_define

begin_comment
comment|/* filename : linenumber */
end_comment

begin_define
define|#
directive|define
name|O_ALIAS
value|62
end_define

begin_define
define|#
directive|define
name|O_GRIPE
value|63
end_define

begin_define
define|#
directive|define
name|O_LASTOP
value|63
end_define

begin_comment
comment|/* must be number of last operator */
end_comment

begin_comment
comment|/*  * operator flags and predicates  */
end_comment

begin_define
define|#
directive|define
name|LEAF
value|01
end_define

begin_define
define|#
directive|define
name|UNARY
value|02
end_define

begin_define
define|#
directive|define
name|BINARY
value|04
end_define

begin_define
define|#
directive|define
name|BOOL
value|010
end_define

begin_define
define|#
directive|define
name|REALOP
value|020
end_define

begin_define
define|#
directive|define
name|INTOP
value|040
end_define

begin_define
define|#
directive|define
name|isbitset
parameter_list|(
name|a
parameter_list|,
name|m
parameter_list|)
value|((a&m) == m)
end_define

begin_define
define|#
directive|define
name|isleaf
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, LEAF)
end_define

begin_define
define|#
directive|define
name|isunary
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, UNARY)
end_define

begin_define
define|#
directive|define
name|isbinary
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, BINARY)
end_define

begin_define
define|#
directive|define
name|isreal
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, REALOP)
end_define

begin_define
define|#
directive|define
name|isint
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, INTOP)
end_define

begin_define
define|#
directive|define
name|isboolean
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[o].opflags, BOOL)
end_define

begin_define
define|#
directive|define
name|degree
parameter_list|(
name|o
parameter_list|)
value|(opinfo[o].opflags&(LEAF|UNARY|BINARY))
end_define

end_unit

