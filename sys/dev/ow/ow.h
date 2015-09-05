begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 M. Warner Losh<imp@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_OW_OW_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_OW_OW_H
value|1
end_define

begin_enum
enum|enum
name|ow_device_ivars
block|{
name|OW_IVAR_FAMILY
block|,
name|OW_IVAR_ROMID
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|OW_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(ow, var, OW, ivar, type);
end_define

begin_macro
name|OW_ACCESSOR
argument_list|(
argument|family
argument_list|,
argument|FAMILY
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|OW_ACCESSOR
argument_list|(
argument|romid
argument_list|,
argument|ROMID
argument_list|,
argument|uint8_t *
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|OW_ACCSSOR
end_undef

begin_comment
comment|/*  * The following likely should be in the own.h file, but needs to be here to  * avoid recursive issues when defining the own_if.m interface.  */
end_comment

begin_comment
comment|/*  * Generalized command structure for a 1wire bus transaction. Not all possible  * transactions on the 1wire bus can be represented here (a notable exception  * being both the search ROM commands), but most of them can be, allowing for  * general transactions from userland. A lower-level interface to the link  * layer is also provided.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ROM
value|10
end_define

begin_define
define|#
directive|define
name|MAX_XPT
value|32
end_define

begin_define
define|#
directive|define
name|MAX_READ
value|32
end_define

begin_struct
struct|struct
name|ow_cmd
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/* Various flags */
define|#
directive|define
name|OW_FLAG_OVERDRIVE
value|1
comment|/* Send xpt stuff overdrive speed */
define|#
directive|define
name|OW_FLAG_READ_BIT
value|2
comment|/* Read a single bit after xpt_cmd */
name|uint8_t
name|rom_len
decl_stmt|;
comment|/* Number of ROM bytes to send */
name|uint8_t
name|rom_cmd
index|[
name|MAX_ROM
index|]
decl_stmt|;
comment|/* Rom command to send */
name|uint8_t
name|rom_read_len
decl_stmt|;
comment|/* Number of bytes to read */
name|uint8_t
name|rom_read
index|[
name|MAX_ROM
index|]
decl_stmt|;
comment|/* Extra bytes read */
name|uint8_t
name|xpt_len
decl_stmt|;
comment|/* Total transport bytes to send */
name|uint8_t
name|xpt_cmd
index|[
name|MAX_XPT
index|]
decl_stmt|;
comment|/* Device specific command to send, if flagged */
name|uint8_t
name|xpt_read_len
decl_stmt|;
comment|/* Number of bytes to read after */
name|uint8_t
name|xpt_read
index|[
name|MAX_READ
index|]
decl_stmt|;
comment|/* Buffer for read bytes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint64_t
name|romid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_OW_OW_H */
end_comment

end_unit

