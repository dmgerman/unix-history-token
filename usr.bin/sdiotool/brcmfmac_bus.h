begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Broadcom Corporation  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* The level of bus communication with the dongle */
end_comment

begin_enum
enum|enum
name|brcmf_bus_state
block|{
name|BRCMF_BUS_DOWN
block|,
comment|/* Not ready for frame transfers */
name|BRCMF_BUS_UP
comment|/* Ready for frame transfers */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|brcmf_bus
block|{
name|enum
name|brcmf_bus_state
name|state
decl_stmt|;
block|}
struct|;
end_struct

end_unit

