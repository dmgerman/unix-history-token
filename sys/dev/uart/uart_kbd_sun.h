begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jason L. Wright  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* keyboard commands (host->kbd) */
end_comment

begin_define
define|#
directive|define
name|SKBD_CMD_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_BELLON
value|0x02
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_BELLOFF
value|0x03
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_CLICKON
value|0x0a
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_CLICKOFF
value|0x0b
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_SETLED
value|0x0e
end_define

begin_define
define|#
directive|define
name|SKBD_CMD_LAYOUT
value|0x0f
end_define

begin_comment
comment|/* keyboard responses (kbd->host) */
end_comment

begin_define
define|#
directive|define
name|SKBD_RSP_RESET_OK
value|0x04
end_define

begin_comment
comment|/* normal reset status for type 4/5/6 */
end_comment

begin_define
define|#
directive|define
name|SKBD_RSP_IDLE
value|0x7f
end_define

begin_comment
comment|/* no keys down */
end_comment

begin_define
define|#
directive|define
name|SKBD_RSP_LAYOUT
value|0xfe
end_define

begin_comment
comment|/* layout follows */
end_comment

begin_define
define|#
directive|define
name|SKBD_RSP_RESET
value|0xff
end_define

begin_comment
comment|/* reset status follows */
end_comment

begin_define
define|#
directive|define
name|SKBD_LED_NUMLOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|SKBD_LED_COMPOSE
value|0x02
end_define

begin_define
define|#
directive|define
name|SKBD_LED_SCROLLLOCK
value|0x04
end_define

begin_define
define|#
directive|define
name|SKBD_LED_CAPSLOCK
value|0x08
end_define

begin_define
define|#
directive|define
name|SKBD_STATE_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SKBD_STATE_LAYOUT
value|1
end_define

begin_define
define|#
directive|define
name|SKBD_STATE_GETKEY
value|2
end_define

begin_comment
comment|/* keyboard types */
end_comment

begin_define
define|#
directive|define
name|KB_SUN2
value|2
end_define

begin_comment
comment|/* type 2 keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_SUN3
value|3
end_define

begin_comment
comment|/* type 3 keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_SUN4
value|4
end_define

begin_comment
comment|/* type 4/5/6 keyboard */
end_comment

end_unit

