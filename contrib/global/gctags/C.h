begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997, 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	C.h						20-Aug-98  */
end_comment

begin_define
define|#
directive|define
name|DECLARATIONS
value|0
end_define

begin_define
define|#
directive|define
name|RULES
value|1
end_define

begin_define
define|#
directive|define
name|PROGRAMS
value|2
end_define

begin_define
define|#
directive|define
name|C___P
value|1001
end_define

begin_define
define|#
directive|define
name|C_AUTO
value|1002
end_define

begin_define
define|#
directive|define
name|C_BREAK
value|1003
end_define

begin_define
define|#
directive|define
name|C_CASE
value|1004
end_define

begin_define
define|#
directive|define
name|C_CHAR
value|1005
end_define

begin_define
define|#
directive|define
name|C_CONTINUE
value|1006
end_define

begin_define
define|#
directive|define
name|C_DEFAULT
value|1007
end_define

begin_define
define|#
directive|define
name|C_DO
value|1008
end_define

begin_define
define|#
directive|define
name|C_DOUBLE
value|1009
end_define

begin_define
define|#
directive|define
name|C_ELSE
value|1010
end_define

begin_define
define|#
directive|define
name|C_EXTERN
value|1011
end_define

begin_define
define|#
directive|define
name|C_FLOAT
value|1012
end_define

begin_define
define|#
directive|define
name|C_FOR
value|1013
end_define

begin_define
define|#
directive|define
name|C_GOTO
value|1014
end_define

begin_define
define|#
directive|define
name|C_IF
value|1015
end_define

begin_define
define|#
directive|define
name|C_INT
value|1016
end_define

begin_define
define|#
directive|define
name|C_LONG
value|1017
end_define

begin_define
define|#
directive|define
name|C_REGISTER
value|1018
end_define

begin_define
define|#
directive|define
name|C_RETURN
value|1019
end_define

begin_define
define|#
directive|define
name|C_SHORT
value|1020
end_define

begin_define
define|#
directive|define
name|C_SIZEOF
value|1021
end_define

begin_define
define|#
directive|define
name|C_STATIC
value|1022
end_define

begin_define
define|#
directive|define
name|C_STRUCT
value|1023
end_define

begin_define
define|#
directive|define
name|C_SWITCH
value|1024
end_define

begin_define
define|#
directive|define
name|C_TYPEDEF
value|1025
end_define

begin_define
define|#
directive|define
name|C_UNION
value|1026
end_define

begin_define
define|#
directive|define
name|C_UNSIGNED
value|1027
end_define

begin_define
define|#
directive|define
name|C_VOID
value|1028
end_define

begin_define
define|#
directive|define
name|C_WHILE
value|1029
end_define

begin_define
define|#
directive|define
name|CP_ELIF
value|2001
end_define

begin_define
define|#
directive|define
name|CP_ELSE
value|2002
end_define

begin_define
define|#
directive|define
name|CP_DEFINE
value|2003
end_define

begin_define
define|#
directive|define
name|CP_IF
value|2004
end_define

begin_define
define|#
directive|define
name|CP_IFDEF
value|2005
end_define

begin_define
define|#
directive|define
name|CP_IFNDEF
value|2006
end_define

begin_define
define|#
directive|define
name|CP_INCLUDE
value|2007
end_define

begin_define
define|#
directive|define
name|CP_PRAGMA
value|2008
end_define

begin_define
define|#
directive|define
name|CP_SHARP
value|2009
end_define

begin_define
define|#
directive|define
name|CP_ERROR
value|2010
end_define

begin_define
define|#
directive|define
name|CP_UNDEF
value|2011
end_define

begin_define
define|#
directive|define
name|CP_ENDIF
value|2012
end_define

begin_define
define|#
directive|define
name|CP_LINE
value|2013
end_define

begin_define
define|#
directive|define
name|YACC_SEP
value|3001
end_define

begin_define
define|#
directive|define
name|YACC_BEGIN
value|3002
end_define

begin_define
define|#
directive|define
name|YACC_END
value|3003
end_define

begin_define
define|#
directive|define
name|YACC_LEFT
value|3004
end_define

begin_define
define|#
directive|define
name|YACC_NONASSOC
value|3005
end_define

begin_define
define|#
directive|define
name|YACC_RIGHT
value|3006
end_define

begin_define
define|#
directive|define
name|YACC_START
value|3007
end_define

begin_define
define|#
directive|define
name|YACC_TOKEN
value|3008
end_define

begin_define
define|#
directive|define
name|YACC_TYPE
value|3009
end_define

begin_define
define|#
directive|define
name|IS_CTOKEN
parameter_list|(
name|c
parameter_list|)
value|(c> 1000&& c< 2001)
end_define

begin_define
define|#
directive|define
name|IS_CPTOKEN
parameter_list|(
name|c
parameter_list|)
value|(c> 2000&& c< 3001)
end_define

begin_define
define|#
directive|define
name|IS_YACCTOKEN
parameter_list|(
name|c
parameter_list|)
value|(c> 3000&& c< 4001)
end_define

begin_define
define|#
directive|define
name|MAXPIFSTACK
value|100
end_define

end_unit

