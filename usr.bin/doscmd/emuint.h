begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Helmut Wirth<hfwirth@ping.at>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, witout modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * The emulator helper interrupt:  *  * Interrupt 0xFF is used by some emulator functions. It is a portal into  * the emulator and cannot be used by ordinary DOS applications directly  * The interrupt 0xFF is called by helper functions under DOS (such as  * the redirector interfcae and the EMS emulation).  * There are functions and subfunctions defined. (See emuint.c for details)  */
end_comment

begin_comment
comment|/* The redirector interface (formerly instbsdi.exe) */
end_comment

begin_define
define|#
directive|define
name|EMU_REDIR
value|0x1
end_define

begin_comment
comment|/* Function for redirector interface */
end_comment

begin_comment
comment|/* No subfunctions defined */
end_comment

begin_comment
comment|/* Expanded memory (EMS) driver callback */
end_comment

begin_define
define|#
directive|define
name|EMU_EMS
value|0x2
end_define

begin_comment
comment|/* Function for EMS driver control */
end_comment

begin_comment
comment|/* subfunctions for EMS */
end_comment

begin_define
define|#
directive|define
name|EMU_EMS_CTL
value|0x0
end_define

begin_comment
comment|/* Control function, used during init */
end_comment

begin_define
define|#
directive|define
name|EMU_EMS_CALL
value|0x1
end_define

begin_comment
comment|/* Callback, calls are routed via this */
end_comment

end_unit

