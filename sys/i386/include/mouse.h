begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993 Erik Forsberg.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|mouseinfo
block|{
name|unsigned
name|char
name|status
decl_stmt|;
name|char
name|xmotion
decl_stmt|,
name|ymotion
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BUTSTATMASK
value|0x07
end_define

begin_comment
comment|/* Any mouse button down if any bit set */
end_comment

begin_define
define|#
directive|define
name|BUTCHNGMASK
value|0x38
end_define

begin_comment
comment|/* Any mouse button changed if any bit set */
end_comment

begin_define
define|#
directive|define
name|BUT3STAT
value|0x01
end_define

begin_comment
comment|/* Button 3 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT2STAT
value|0x02
end_define

begin_comment
comment|/* Button 2 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT1STAT
value|0x04
end_define

begin_comment
comment|/* Button 1 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT3CHNG
value|0x08
end_define

begin_comment
comment|/* Button 3 changed if set */
end_comment

begin_define
define|#
directive|define
name|BUT2CHNG
value|0x10
end_define

begin_comment
comment|/* Button 2 changed if set */
end_comment

begin_define
define|#
directive|define
name|BUT1CHNG
value|0x20
end_define

begin_comment
comment|/* Button 1 changed if set */
end_comment

begin_define
define|#
directive|define
name|MOVEMENT
value|0x40
end_define

begin_comment
comment|/* Mouse movement detected */
end_comment

begin_comment
comment|/* Ioctl definitions */
end_comment

begin_define
define|#
directive|define
name|MOUSEIOC
value|('M'<<8)
end_define

begin_define
define|#
directive|define
name|MOUSEIOCREAD
value|(MOUSEIOC|60)
end_define

end_unit

