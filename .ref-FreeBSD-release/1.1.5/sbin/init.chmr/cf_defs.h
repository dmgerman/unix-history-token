begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Christoph M. Robitschko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christoph M. Robitschko  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * cf_defs.h  * typedefs and defines for the configuration subsystem.  */
end_comment

begin_struct
struct|struct
name|Command
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* command name / value description   */
name|short
name|level
decl_stmt|;
comment|/* level of command nesting           */
name|u_char
name|type
decl_stmt|;
comment|/* type of entry (exact, string, int) */
name|u_char
name|flags
decl_stmt|;
comment|/* additional flags                   */
name|void
modifier|*
name|var
decl_stmt|;
comment|/* Pointer to variable to assign to   */
union|union
block|{
name|int
name|intval
decl_stmt|;
comment|/* Integer value to assign to *var    */
name|char
modifier|*
name|chval
decl_stmt|;
comment|/* String ...                         */
block|}
name|val
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* defines for the level field */
end_comment

begin_define
define|#
directive|define
name|SUB
value|0x100
end_define

begin_comment
comment|/* There must be another argument */
end_comment

begin_define
define|#
directive|define
name|OPT
value|0x200
end_define

begin_comment
comment|/* There can be another argument (not yet impl) */
end_comment

begin_define
define|#
directive|define
name|LEVEL
value|0x0ff
end_define

begin_comment
comment|/* Flags masked off */
end_comment

begin_comment
comment|/* Valid types */
end_comment

begin_define
define|#
directive|define
name|T_EX
value|0x00
end_define

begin_comment
comment|/* Must match exact */
end_comment

begin_define
define|#
directive|define
name|T_STR
value|0x01
end_define

begin_comment
comment|/* Matches any string */
end_comment

begin_define
define|#
directive|define
name|T_INT
value|0x02
end_define

begin_comment
comment|/* Matches an integer */
end_comment

begin_define
define|#
directive|define
name|T_BYTE
value|0x03
end_define

begin_comment
comment|/* Matches a byte expression (1m = 1024k == 1024 == 1048576b) */
end_comment

begin_define
define|#
directive|define
name|T_TIME
value|0x04
end_define

begin_comment
comment|/* Matches a time expression (1:00:00 == 1h == 60m == 3600s == 3600) */
end_comment

begin_comment
comment|/* values for the flags field */
end_comment

begin_define
define|#
directive|define
name|NRAISE
value|0x01
end_define

begin_comment
comment|/* Variable can be lowered but not raised */
end_comment

begin_define
define|#
directive|define
name|MAXVAL
value|0x02
end_define

begin_comment
comment|/* intval contains the maximum allowed value */
end_comment

begin_define
define|#
directive|define
name|CFUNC
value|0x04
end_define

begin_comment
comment|/* Call the function *(void (*)())var(argc, argv) */
end_comment

begin_define
define|#
directive|define
name|NOVAR
value|NULL, {0}
end_define

end_unit

