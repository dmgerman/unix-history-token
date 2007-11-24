begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SC_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SC_MACHDEP_H_
end_define

begin_comment
comment|/* Color attributes for foreground text */
end_comment

begin_define
define|#
directive|define
name|FG_BLACK
value|0x0
end_define

begin_define
define|#
directive|define
name|FG_BLUE
value|0x1
end_define

begin_define
define|#
directive|define
name|FG_GREEN
value|0x2
end_define

begin_define
define|#
directive|define
name|FG_CYAN
value|0x3
end_define

begin_define
define|#
directive|define
name|FG_RED
value|0x4
end_define

begin_define
define|#
directive|define
name|FG_MAGENTA
value|0x5
end_define

begin_define
define|#
directive|define
name|FG_BROWN
value|0x6
end_define

begin_define
define|#
directive|define
name|FG_LIGHTGREY
value|0x7
end_define

begin_comment
comment|/* aka white */
end_comment

begin_define
define|#
directive|define
name|FG_DARKGREY
value|0x8
end_define

begin_define
define|#
directive|define
name|FG_LIGHTBLUE
value|0x9
end_define

begin_define
define|#
directive|define
name|FG_LIGHTGREEN
value|0xa
end_define

begin_define
define|#
directive|define
name|FG_LIGHTCYAN
value|0xb
end_define

begin_define
define|#
directive|define
name|FG_LIGHTRED
value|0xc
end_define

begin_define
define|#
directive|define
name|FG_LIGHTMAGENTA
value|0xd
end_define

begin_define
define|#
directive|define
name|FG_YELLOW
value|0xe
end_define

begin_define
define|#
directive|define
name|FG_WHITE
value|0xf
end_define

begin_comment
comment|/* aka bright white */
end_comment

begin_define
define|#
directive|define
name|FG_BLINK
value|0x80
end_define

begin_comment
comment|/* Color attributes for text background */
end_comment

begin_define
define|#
directive|define
name|BG_BLACK
value|0x00
end_define

begin_define
define|#
directive|define
name|BG_BLUE
value|0x10
end_define

begin_define
define|#
directive|define
name|BG_GREEN
value|0x20
end_define

begin_define
define|#
directive|define
name|BG_CYAN
value|0x30
end_define

begin_define
define|#
directive|define
name|BG_RED
value|0x40
end_define

begin_define
define|#
directive|define
name|BG_MAGENTA
value|0x50
end_define

begin_define
define|#
directive|define
name|BG_BROWN
value|0x60
end_define

begin_define
define|#
directive|define
name|BG_LIGHTGREY
value|0x70
end_define

begin_define
define|#
directive|define
name|BG_DARKGREY
value|0x80
end_define

begin_define
define|#
directive|define
name|BG_LIGHTBLUE
value|0x90
end_define

begin_define
define|#
directive|define
name|BG_LIGHTGREEN
value|0xa0
end_define

begin_define
define|#
directive|define
name|BG_LIGHTCYAN
value|0xb0
end_define

begin_define
define|#
directive|define
name|BG_LIGHTRED
value|0xc0
end_define

begin_define
define|#
directive|define
name|BG_LIGHTMAGENTA
value|0xd0
end_define

begin_define
define|#
directive|define
name|BG_YELLOW
value|0xe0
end_define

begin_define
define|#
directive|define
name|BG_WHITE
value|0xf0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SC_MACHDEP_H_ */
end_comment

end_unit

