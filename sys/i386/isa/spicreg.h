begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000  Nick Sayer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|160
end_define

begin_comment
comment|/*  * Find the PCI device that holds the G10 register needed to map in the SPIC  */
end_comment

begin_define
define|#
directive|define
name|PIIX4_BUS
value|0
end_define

begin_define
define|#
directive|define
name|PIIX4_SLOT
value|7
end_define

begin_define
define|#
directive|define
name|PIIX4_FUNC
value|3
end_define

begin_define
define|#
directive|define
name|PIIX4_DEVID
value|0x71138086
end_define

begin_define
define|#
directive|define
name|G10A
value|(0x64)
end_define

begin_define
define|#
directive|define
name|G10L
value|(G10A + 2)
end_define

begin_define
define|#
directive|define
name|SPIC_IRQ_PORT
value|0x8034
end_define

begin_define
define|#
directive|define
name|SPIC_IRQ_SHIFT
value|22
end_define

begin_comment
comment|/* Define SPIC model type */
end_comment

begin_define
define|#
directive|define
name|SPIC_DEVICE_MODEL_TYPE1
value|1
end_define

begin_define
define|#
directive|define
name|SPIC_DEVICE_MODEL_TYPE2
value|2
end_define

begin_comment
comment|/* type2 series specifics */
end_comment

begin_define
define|#
directive|define
name|SPIC_SIRQ
value|0x9b
end_define

begin_define
define|#
directive|define
name|SPIC_SLOB
value|0x9c
end_define

begin_define
define|#
directive|define
name|SPIC_SHIB
value|0x9d
end_define

begin_comment
comment|/* ioports used for brightness and type2 events */
end_comment

begin_define
define|#
directive|define
name|SPIC_DATA_IOPORT
value|0x62
end_define

begin_define
define|#
directive|define
name|SPIC_CST_IOPORT
value|0x66
end_define

end_unit

