begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kbdmap.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_define
define|#
directive|define
name|DEL
value|'\177'
end_define

begin_struct
struct|struct
name|kbdmap
block|{
name|int
name|kbd_code
decl_stmt|;
name|char
modifier|*
name|kbd_desc
decl_stmt|;
name|char
modifier|*
name|kbd_keymap
decl_stmt|;
name|char
modifier|*
name|kbd_shiftmap
decl_stmt|;
name|char
modifier|*
name|kbd_ctrlmap
decl_stmt|;
name|char
modifier|*
name|kbd_ctrlshiftmap
decl_stmt|;
name|char
modifier|*
modifier|*
name|kbd_stringmap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* kbd_code */
end_comment

begin_define
define|#
directive|define
name|KBD_SPECIAL
value|0x00
end_define

begin_comment
comment|/* user defined */
end_comment

begin_define
define|#
directive|define
name|KBD_US
value|0x1F
end_define

begin_comment
comment|/* US ASCII */
end_comment

begin_define
define|#
directive|define
name|KBD_UK
value|0x17
end_define

begin_comment
comment|/* United Kingdom */
end_comment

begin_define
define|#
directive|define
name|KBD_DEFAULT
value|KBD_US
end_define

begin_comment
comment|/* default type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* XXX: ITE interface */
end_comment

begin_decl_stmt
name|char
modifier|*
name|kbd_keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_shiftmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_ctrlmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_ctrlshiftmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|kbd_stringmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kbdmap
name|kbd_map
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

