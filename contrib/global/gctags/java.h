begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	java.h						20-Aug-98  */
end_comment

begin_comment
comment|/*  * java's reserved words.  */
end_comment

begin_define
define|#
directive|define
name|J_ABSTRACT
value|1001
end_define

begin_define
define|#
directive|define
name|J_BOOLEAN
value|1002
end_define

begin_define
define|#
directive|define
name|J_BREAK
value|1003
end_define

begin_define
define|#
directive|define
name|J_BYTE
value|1004
end_define

begin_define
define|#
directive|define
name|J_CASE
value|1005
end_define

begin_define
define|#
directive|define
name|J_CATCH
value|1006
end_define

begin_define
define|#
directive|define
name|J_CHAR
value|1007
end_define

begin_define
define|#
directive|define
name|J_CLASS
value|1008
end_define

begin_define
define|#
directive|define
name|J_CONST
value|1009
end_define

begin_define
define|#
directive|define
name|J_CONTINUE
value|1010
end_define

begin_define
define|#
directive|define
name|J_DEFAULT
value|1011
end_define

begin_define
define|#
directive|define
name|J_DO
value|1012
end_define

begin_define
define|#
directive|define
name|J_DOUBLE
value|1013
end_define

begin_define
define|#
directive|define
name|J_ELSE
value|1014
end_define

begin_define
define|#
directive|define
name|J_EXTENDS
value|1015
end_define

begin_define
define|#
directive|define
name|J_FALSE
value|1016
end_define

begin_define
define|#
directive|define
name|J_FINAL
value|1017
end_define

begin_define
define|#
directive|define
name|J_FINALLY
value|1018
end_define

begin_define
define|#
directive|define
name|J_FLOAT
value|1019
end_define

begin_define
define|#
directive|define
name|J_FOR
value|1020
end_define

begin_define
define|#
directive|define
name|J_GOTO
value|1021
end_define

begin_define
define|#
directive|define
name|J_IF
value|1022
end_define

begin_define
define|#
directive|define
name|J_IMPLEMENTS
value|1023
end_define

begin_define
define|#
directive|define
name|J_IMPORT
value|1024
end_define

begin_define
define|#
directive|define
name|J_INSTANCEOF
value|1025
end_define

begin_define
define|#
directive|define
name|J_INT
value|1026
end_define

begin_define
define|#
directive|define
name|J_INTERFACE
value|1027
end_define

begin_define
define|#
directive|define
name|J_LONG
value|1028
end_define

begin_define
define|#
directive|define
name|J_NATIVE
value|1029
end_define

begin_define
define|#
directive|define
name|J_NEW
value|1030
end_define

begin_define
define|#
directive|define
name|J_NULL
value|1031
end_define

begin_define
define|#
directive|define
name|J_PACKAGE
value|1032
end_define

begin_define
define|#
directive|define
name|J_PRIVATE
value|1033
end_define

begin_define
define|#
directive|define
name|J_PROTECTED
value|1034
end_define

begin_define
define|#
directive|define
name|J_PUBLIC
value|1035
end_define

begin_define
define|#
directive|define
name|J_RETURN
value|1036
end_define

begin_define
define|#
directive|define
name|J_SHORT
value|1037
end_define

begin_define
define|#
directive|define
name|J_STATIC
value|1038
end_define

begin_define
define|#
directive|define
name|J_SUPER
value|1039
end_define

begin_define
define|#
directive|define
name|J_SWITCH
value|1040
end_define

begin_define
define|#
directive|define
name|J_SYNCHRONIZED
value|1041
end_define

begin_define
define|#
directive|define
name|J_THIS
value|1042
end_define

begin_define
define|#
directive|define
name|J_THROW
value|1043
end_define

begin_define
define|#
directive|define
name|J_THROWS
value|1044
end_define

begin_define
define|#
directive|define
name|J_UNION
value|1045
end_define

begin_define
define|#
directive|define
name|J_TRANSIENT
value|1046
end_define

begin_define
define|#
directive|define
name|J_TRUE
value|1047
end_define

begin_define
define|#
directive|define
name|J_TRY
value|1048
end_define

begin_define
define|#
directive|define
name|J_VOID
value|1049
end_define

begin_define
define|#
directive|define
name|J_VOLATILE
value|1050
end_define

begin_define
define|#
directive|define
name|J_WHILE
value|1051
end_define

begin_define
define|#
directive|define
name|J_STRICTFP
value|1052
end_define

begin_define
define|#
directive|define
name|J_WIDEFP
value|1053
end_define

begin_define
define|#
directive|define
name|MAXCOMPLETENAME
value|1024
end_define

begin_comment
comment|/* max size of complete name of class */
end_comment

begin_define
define|#
directive|define
name|MAXCLASSSTACK
value|10
end_define

begin_comment
comment|/* max size of class stack */
end_comment

end_unit

