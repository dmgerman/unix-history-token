begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)asscan3.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"asscanl.h"
end_include

begin_decl_stmt
name|readonly
name|short
name|type
index|[]
init|=
block|{
comment|/*hit the hard end of file*/
name|SCANEOF
block|,
comment|/* '^@' 0x00 0000 */
name|SP
block|,
comment|/* '^A' 0x01 0001 */
name|BADCHAR
block|,
comment|/* '^B' 0x02 0002 */
name|BADCHAR
block|,
comment|/* '^C' 0x03 0003 */
name|BADCHAR
block|,
comment|/* '^D' 0x04 0004 */
name|BADCHAR
block|,
comment|/* '^E' 0x05 0005 */
name|BADCHAR
block|,
comment|/* '^F' 0x06 0006 */
name|BADCHAR
block|,
comment|/* '^G' 0x07 0007 */
name|BADCHAR
block|,
comment|/* '\b' 0x08 0010 */
name|BADCHAR
block|,
comment|/* '\t' 0x09 0011 */
name|SP
block|,
comment|/* '\n' 0x0a 0012 */
name|NL
block|,
comment|/* '^K' 0x0b 0013 */
name|BADCHAR
block|,
comment|/* '\f' 0x0c 0014 */
name|BADCHAR
block|,
comment|/* '\r' 0x0d 0015 */
name|SP
block|,
comment|/* '^N' 0x0e 0016 */
name|BADCHAR
block|,
comment|/* '^O' 0x0f 0017 */
name|BADCHAR
block|,
comment|/* '^P' 0x10 0020 */
name|BADCHAR
block|,
comment|/* '^Q' 0x11 0021 */
name|BADCHAR
block|,
comment|/* '^R' 0x12 0022 */
name|BADCHAR
block|,
comment|/* '^S' 0x13 0023 */
name|BADCHAR
block|,
comment|/* '^T' 0x14 0024 */
name|BADCHAR
block|,
comment|/* '^U' 0x15 0025 */
name|BADCHAR
block|,
comment|/* '^V' 0x16 0026 */
name|BADCHAR
block|,
comment|/* '^W' 0x17 0027 */
name|BADCHAR
block|,
comment|/* '^X' 0x18 0030 */
name|BADCHAR
block|,
comment|/* '^Y' 0x19 0031 */
name|BADCHAR
block|,
comment|/* '^Z' 0x1a 0032 */
name|BADCHAR
block|,
comment|/* '^[' 0x1b 0033 */
name|BADCHAR
block|,
comment|/* '^\' 0x1c 0034 */
name|BADCHAR
block|,
comment|/* '^]' 0x1d 0035 */
name|BADCHAR
block|,
comment|/* '^^' 0x1e 0036 */
name|BADCHAR
block|,
comment|/* '^_' 0x1f 0037 */
name|BADCHAR
block|,
comment|/* ' ' 0x20 0040 */
name|SP
block|,
comment|/* '!' 0x21 0041 */
name|ORNOT
block|,
comment|/* '"' 0x22 0042 */
name|DQ
block|,
comment|/* '#' 0x23 0043 */
name|SH
block|,
comment|/* '$' 0x24 0044 */
name|LITOP
block|,
comment|/* '%' 0x25 0045 */
name|REGOP
block|,
comment|/* '&' 0x26 0046 */
name|AND
block|,
comment|/* ''' 0x27 0047 */
name|SQ
block|,
comment|/* '(' 0x28 0050 */
name|LP
block|,
comment|/* ')' 0x29 0051 */
name|RP
block|,
comment|/* '*' 0x2a 0052 */
name|MUL
block|,
comment|/* '+' 0x2b 0053 */
name|PLUS
block|,
comment|/* ',' 0x2c 0054 */
name|CM
block|,
comment|/* '-' 0x2d 0055 */
name|MINUS
block|,
comment|/* '.' 0x2e 0056 */
name|ALPH
block|,
comment|/* '/' 0x2f 0057 */
name|DIV
block|,
comment|/* '0' 0x30 0060 */
name|DIG
block|,
comment|/* '1' 0x31 0061 */
name|DIG
block|,
comment|/* '2' 0x32 0062 */
name|DIG
block|,
comment|/* '3' 0x33 0063 */
name|DIG
block|,
comment|/* '4' 0x34 0064 */
name|DIG
block|,
comment|/* '5' 0x35 0065 */
name|DIG
block|,
comment|/* '6' 0x36 0066 */
name|DIG
block|,
comment|/* '7' 0x37 0067 */
name|DIG
block|,
comment|/* '8' 0x38 0070 */
name|DIG
block|,
comment|/* '9' 0x39 0071 */
name|DIG
block|,
comment|/* ':' 0x3a 0072 */
name|COLON
block|,
comment|/* ';' 0x3b 0073 */
name|SEMI
block|,
comment|/* '<' 0x3c 0074 */
name|LSH
block|,
comment|/* '=' 0x3d 0075 */
name|BADCHAR
block|,
comment|/* '>' 0x3e 0076 */
name|RSH
block|,
comment|/* '?' 0x3f 0077 */
name|BADCHAR
block|,
comment|/* '@' 0x40 0100 */
name|BADCHAR
block|,
comment|/* 'A' 0x41 0101 */
name|ALPH
block|,
comment|/* 'B' 0x42 0102 */
name|ALPH
block|,
comment|/* 'C' 0x43 0103 */
name|ALPH
block|,
comment|/* 'D' 0x44 0104 */
name|ALPH
block|,
comment|/* 'E' 0x45 0105 */
name|ALPH
block|,
comment|/* 'F' 0x46 0106 */
name|ALPH
block|,
comment|/* 'G' 0x47 0107 */
name|ALPH
block|,
comment|/* 'H' 0x48 0110 */
name|ALPH
block|,
comment|/* 'I' 0x49 0111 */
name|ALPH
block|,
comment|/* 'J' 0x4a 0112 */
name|ALPH
block|,
comment|/* 'K' 0x4b 0113 */
name|ALPH
block|,
comment|/* 'L' 0x4c 0114 */
name|ALPH
block|,
comment|/* 'M' 0x4d 0115 */
name|ALPH
block|,
comment|/* 'N' 0x4e 0116 */
name|ALPH
block|,
comment|/* 'O' 0x4f 0117 */
name|ALPH
block|,
comment|/* 'P' 0x50 0120 */
name|ALPH
block|,
comment|/* 'Q' 0x51 0121 */
name|ALPH
block|,
comment|/* 'R' 0x52 0122 */
name|ALPH
block|,
comment|/* 'S' 0x53 0123 */
name|ALPH
block|,
comment|/* 'T' 0x54 0124 */
name|ALPH
block|,
comment|/* 'U' 0x55 0125 */
name|ALPH
block|,
comment|/* 'V' 0x56 0126 */
name|ALPH
block|,
comment|/* 'W' 0x57 0127 */
name|ALPH
block|,
comment|/* 'X' 0x58 0130 */
name|ALPH
block|,
comment|/* 'Y' 0x59 0131 */
name|ALPH
block|,
comment|/* 'Z' 0x5a 0132 */
name|ALPH
block|,
comment|/* '[' 0x5b 0133 */
name|LB
block|,
comment|/* '\\' 0x5c 0134 */
name|BADCHAR
block|,
comment|/* ']' 0x5d 0135 */
name|RB
block|,
comment|/* '^' 0x5e 0136 */
name|XOR
block|,
comment|/* '_' 0x5f 0137 */
name|ALPH
block|,
comment|/* '`' 0x60 0140 */
name|SIZEQUOTE
block|,
comment|/* 'a' 0x61 0141 */
name|ALPH
block|,
comment|/* 'b' 0x62 0142 */
name|ALPH
block|,
comment|/* 'c' 0x63 0143 */
name|ALPH
block|,
comment|/* 'd' 0x64 0144 */
name|ALPH
block|,
comment|/* 'e' 0x65 0145 */
name|ALPH
block|,
comment|/* 'f' 0x66 0146 */
name|ALPH
block|,
comment|/* 'g' 0x67 0147 */
name|ALPH
block|,
comment|/* 'h' 0x68 0150 */
name|ALPH
block|,
comment|/* 'i' 0x69 0151 */
name|ALPH
block|,
comment|/* 'j' 0x6a 0152 */
name|ALPH
block|,
comment|/* 'k' 0x6b 0153 */
name|ALPH
block|,
comment|/* 'l' 0x6c 0154 */
name|ALPH
block|,
comment|/* 'm' 0x6d 0155 */
name|ALPH
block|,
comment|/* 'n' 0x6e 0156 */
name|ALPH
block|,
comment|/* 'o' 0x6f 0157 */
name|ALPH
block|,
comment|/* 'p' 0x70 0160 */
name|ALPH
block|,
comment|/* 'q' 0x71 0161 */
name|ALPH
block|,
comment|/* 'r' 0x72 0162 */
name|ALPH
block|,
comment|/* 's' 0x73 0163 */
name|ALPH
block|,
comment|/* 't' 0x74 0164 */
name|ALPH
block|,
comment|/* 'u' 0x75 0165 */
name|ALPH
block|,
comment|/* 'v' 0x76 0166 */
name|ALPH
block|,
comment|/* 'w' 0x77 0167 */
name|ALPH
block|,
comment|/* 'x' 0x78 0170 */
name|ALPH
block|,
comment|/* 'y' 0x79 0171 */
name|ALPH
block|,
comment|/* 'z' 0x7a 0172 */
name|ALPH
block|,
comment|/* '{' 0x7b 0173 */
name|BADCHAR
block|,
comment|/* '|' 0x7c 0174 */
name|IOR
block|,
comment|/* '}' 0x7d 0175 */
name|BADCHAR
block|,
comment|/* '~' 0x7e 0176 */
name|TILDE
block|,
comment|/* '^[' 0x7f 0177 */
name|BADCHAR
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|readonly
name|short
name|charsets
index|[]
init|=
block|{
comment|/* '^@' 0x00 0000 */
literal|0
block|,
comment|/* '^A' 0x01 0001 */
literal|0
block|,
comment|/* '^B' 0x02 0002 */
literal|0
block|,
comment|/* '^C' 0x03 0003 */
literal|0
block|,
comment|/* '^D' 0x04 0004 */
literal|0
block|,
comment|/* '^E' 0x05 0005 */
literal|0
block|,
comment|/* '^F' 0x06 0006 */
literal|0
block|,
comment|/* '^G' 0x07 0007 */
literal|0
block|,
comment|/* '\b' 0x08 0010 */
literal|0
block|,
comment|/* '\t' 0x09 0011 */
name|SPACE
block|,
comment|/* '\n' 0x0a 0012 */
name|STRESCAPE
block|,
comment|/* '^K' 0x0b 0013 */
literal|0
block|,
comment|/* '\f' 0x0c 0014 */
literal|0
block|,
comment|/* '\r' 0x0d 0015 */
literal|0
block|,
comment|/* '^N' 0x0e 0016 */
literal|0
block|,
comment|/* '^O' 0x0f 0017 */
literal|0
block|,
comment|/* '^P' 0x10 0020 */
literal|0
block|,
comment|/* '^Q' 0x11 0021 */
literal|0
block|,
comment|/* '^R' 0x12 0022 */
literal|0
block|,
comment|/* '^S' 0x13 0023 */
literal|0
block|,
comment|/* '^T' 0x14 0024 */
literal|0
block|,
comment|/* '^U' 0x15 0025 */
literal|0
block|,
comment|/* '^V' 0x16 0026 */
literal|0
block|,
comment|/* '^W' 0x17 0027 */
literal|0
block|,
comment|/* '^X' 0x18 0030 */
literal|0
block|,
comment|/* '^Y' 0x19 0031 */
literal|0
block|,
comment|/* '^Z' 0x1a 0032 */
literal|0
block|,
comment|/* '^[' 0x1b 0033 */
literal|0
block|,
comment|/* '^\' 0x1c 0034 */
literal|0
block|,
comment|/* '^]' 0x1d 0035 */
literal|0
block|,
comment|/* '^^' 0x1e 0036 */
literal|0
block|,
comment|/* '^_' 0x1f 0037 */
literal|0
block|,
comment|/* ' ' 0x20 0040 */
name|SPACE
block|,
comment|/* '!' 0x21 0041 */
literal|0
block|,
comment|/* '"' 0x22 0042 */
name|STRESCAPE
block|,
comment|/* '#' 0x23 0043 */
literal|0
block|,
comment|/* '$' 0x24 0044 */
name|ALPHA
block|,
comment|/* '%' 0x25 0045 */
literal|0
block|,
comment|/* '&' 0x26 0046 */
literal|0
block|,
comment|/* ''' 0x27 0047 */
literal|0
block|,
comment|/* '(' 0x28 0050 */
literal|0
block|,
comment|/* ')' 0x29 0051 */
literal|0
block|,
comment|/* '*' 0x2a 0052 */
literal|0
block|,
comment|/* '+' 0x2b 0053 */
name|SIGN
block|,
comment|/* ',' 0x2c 0054 */
literal|0
block|,
comment|/* '-' 0x2d 0055 */
name|SIGN
block|,
comment|/* '.' 0x2e 0056 */
name|POINT
operator|+
name|ALPHA
block|,
comment|/* '/' 0x2f 0057 */
literal|0
block|,
comment|/* '0' 0x30 0060 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '1' 0x31 0061 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '2' 0x32 0062 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '3' 0x33 0063 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '4' 0x34 0064 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '5' 0x35 0065 */
name|DIGIT
operator|+
name|REGDIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '6' 0x36 0066 */
name|DIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '7' 0x37 0067 */
name|DIGIT
operator|+
name|OCTDIGIT
block|,
comment|/* '8' 0x38 0070 */
name|DIGIT
block|,
comment|/* '9' 0x39 0071 */
name|DIGIT
block|,
comment|/* ':' 0x3a 0072 */
literal|0
block|,
comment|/* ';' 0x3b 0073 */
literal|0
block|,
comment|/* '<' 0x3c 0074 */
literal|0
block|,
comment|/* '=' 0x3d 0075 */
literal|0
block|,
comment|/* '>' 0x3e 0076 */
literal|0
block|,
comment|/* '?' 0x3f 0077 */
literal|0
block|,
comment|/* '@' 0x40 0100 */
literal|0
block|,
comment|/* 'A' 0x41 0101 */
name|ALPHA
operator|+
name|HEXUDIGIT
block|,
comment|/* 'B' 0x42 0102 */
name|ALPHA
operator|+
name|HEXUDIGIT
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'C' 0x43 0103 */
name|ALPHA
operator|+
name|HEXUDIGIT
block|,
comment|/* 'D' 0x44 0104 */
name|ALPHA
operator|+
name|HEXUDIGIT
operator|+
name|FLOATEXP
operator|+
name|FLOATFLAG
block|,
comment|/* 'E' 0x45 0105 */
name|ALPHA
operator|+
name|HEXUDIGIT
operator|+
name|FLOATEXP
block|,
comment|/* 'F' 0x46 0106 */
name|ALPHA
operator|+
name|HEXUDIGIT
operator|+
name|FLOATFLAG
operator|+
name|FLOATEXP
block|,
comment|/* 'G' 0x47 0107 */
name|ALPHA
operator|+
name|FLOATFLAG
operator|+
name|FLOATEXP
block|,
comment|/* 'H' 0x48 0110 */
name|ALPHA
operator|+
name|FLOATFLAG
operator|+
name|FLOATEXP
block|,
comment|/* 'I' 0x49 0111 */
name|ALPHA
block|,
comment|/* 'J' 0x4a 0112 */
name|ALPHA
block|,
comment|/* 'K' 0x4b 0113 */
name|ALPHA
block|,
comment|/* 'L' 0x4c 0114 */
name|ALPHA
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'M' 0x4d 0115 */
name|ALPHA
block|,
comment|/* 'N' 0x4e 0116 */
name|ALPHA
block|,
comment|/* 'O' 0x4f 0117 */
name|ALPHA
block|,
comment|/* 'P' 0x50 0120 */
name|ALPHA
block|,
comment|/* 'Q' 0x51 0121 */
name|ALPHA
block|,
comment|/* 'R' 0x52 0122 */
name|ALPHA
block|,
comment|/* 'S' 0x53 0123 */
name|ALPHA
block|,
comment|/* 'T' 0x54 0124 */
name|ALPHA
block|,
comment|/* 'U' 0x55 0125 */
name|ALPHA
block|,
comment|/* 'V' 0x56 0126 */
name|ALPHA
block|,
comment|/* 'W' 0x57 0127 */
name|ALPHA
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'X' 0x58 0130 */
name|ALPHA
operator|+
name|HEXFLAG
block|,
comment|/* 'Y' 0x59 0131 */
name|ALPHA
block|,
comment|/* 'Z' 0x5a 0132 */
name|ALPHA
block|,
comment|/* '[' 0x5b 0133 */
literal|0
block|,
comment|/* '\\' 0x5c 0134 */
name|STRESCAPE
block|,
comment|/* ']' 0x5d 0135 */
literal|0
block|,
comment|/* '^' 0x5e 0136 */
literal|0
block|,
comment|/* '_' 0x5f 0137 */
name|ALPHA
block|,
comment|/* '`' 0x60 0140 */
literal|0
block|,
comment|/* 'a' 0x61 0141 */
name|ALPHA
operator|+
name|HEXLDIGIT
block|,
comment|/* 'b' 0x62 0142 */
name|ALPHA
operator|+
name|HEXLDIGIT
operator|+
name|BSESCAPE
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'c' 0x63 0143 */
name|ALPHA
operator|+
name|HEXLDIGIT
block|,
comment|/* 'd' 0x64 0144 */
name|ALPHA
operator|+
name|HEXLDIGIT
operator|+
name|FLOATEXP
operator|+
name|FLOATFLAG
block|,
comment|/* 'e' 0x65 0145 */
name|ALPHA
operator|+
name|HEXLDIGIT
operator|+
name|FLOATEXP
block|,
comment|/* 'f' 0x66 0146 */
name|ALPHA
operator|+
name|HEXLDIGIT
operator|+
name|BSESCAPE
operator|+
name|FLOATEXP
operator|+
name|FLOATFLAG
block|,
comment|/* 'g' 0x67 0147 */
name|ALPHA
operator|+
name|FLOATEXP
operator|+
name|FLOATFLAG
block|,
comment|/* 'h' 0x68 0150 */
name|ALPHA
operator|+
name|FLOATEXP
operator|+
name|FLOATFLAG
block|,
comment|/* 'i' 0x69 0151 */
name|ALPHA
block|,
comment|/* 'j' 0x6a 0152 */
name|ALPHA
block|,
comment|/* 'k' 0x6b 0153 */
name|ALPHA
block|,
comment|/* 'l' 0x6c 0154 */
name|ALPHA
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'm' 0x6d 0155 */
name|ALPHA
block|,
comment|/* 'n' 0x6e 0156 */
name|ALPHA
operator|+
name|BSESCAPE
block|,
comment|/* 'o' 0x6f 0157 */
name|ALPHA
block|,
comment|/* 'p' 0x70 0160 */
name|ALPHA
block|,
comment|/* 'q' 0x71 0161 */
name|ALPHA
block|,
comment|/* 'r' 0x72 0162 */
name|ALPHA
operator|+
name|BSESCAPE
block|,
comment|/* 's' 0x73 0163 */
name|ALPHA
block|,
comment|/* 't' 0x74 0164 */
name|ALPHA
operator|+
name|BSESCAPE
block|,
comment|/* 'u' 0x75 0165 */
name|ALPHA
block|,
comment|/* 'v' 0x76 0166 */
name|ALPHA
block|,
comment|/* 'w' 0x77 0167 */
name|ALPHA
operator|+
name|SZSPECBEGIN
block|,
comment|/* 'x' 0x78 0170 */
name|ALPHA
operator|+
name|HEXFLAG
block|,
comment|/* 'y' 0x79 0171 */
name|ALPHA
block|,
comment|/* 'z' 0x7a 0172 */
name|ALPHA
block|,
comment|/* '{' 0x7b 0173 */
literal|0
block|,
comment|/* '|' 0x7c 0174 */
literal|0
block|,
comment|/* '}' 0x7d 0175 */
literal|0
block|,
comment|/* '~' 0x7e 0176 */
literal|0
block|,
comment|/* '^[' 0x7f 0177 */
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

