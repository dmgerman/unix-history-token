begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Jason R. Thorpe<thorpej@and.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgements:  *	This product includes software developed by Jason R. Thorpe  *	for And Communications, http://www.and.com/  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_struct
struct|struct
name|element_type
block|{
specifier|const
name|char
modifier|*
name|et_name
decl_stmt|;
comment|/* name; i.e. "picker, "slot", etc. */
name|int
name|et_type
decl_stmt|;
comment|/* type number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|changer_command
block|{
specifier|const
name|char
modifier|*
name|cc_name
decl_stmt|;
comment|/* command name */
comment|/* command handler */
name|int
function_decl|(
modifier|*
name|cc_handler
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|special_word
block|{
specifier|const
name|char
modifier|*
name|sw_name
decl_stmt|;
comment|/* special word */
name|int
name|sw_value
decl_stmt|;
comment|/* token value */
block|}
struct|;
end_struct

begin_comment
comment|/* sw_value */
end_comment

begin_define
define|#
directive|define
name|SW_INVERT
value|1
end_define

begin_comment
comment|/* set "invert media" flag */
end_comment

begin_define
define|#
directive|define
name|SW_INVERT1
value|2
end_define

begin_comment
comment|/* set "invert media 1" flag */
end_comment

begin_define
define|#
directive|define
name|SW_INVERT2
value|3
end_define

begin_comment
comment|/* set "invert media 2" flag */
end_comment

begin_comment
comment|/* Environment variable to check for default changer. */
end_comment

begin_define
define|#
directive|define
name|CHANGER_ENV_VAR
value|"CHANGER"
end_define

end_unit

