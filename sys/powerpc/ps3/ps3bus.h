begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2010 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_PS3_PS3BUS_H
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_PS3_PS3BUS_H
end_define

begin_enum
enum|enum
block|{
name|PS3BUS_IVAR_BUS
block|,
name|PS3BUS_IVAR_DEVICE
block|,
name|PS3BUS_IVAR_BUSTYPE
block|,
name|PS3BUS_IVAR_DEVTYPE
block|,
name|PS3BUS_IVAR_BUSIDX
block|,
name|PS3BUS_IVAR_DEVIDX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PS3BUS_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|__BUS_ACCESSOR(ps3bus, A, PS3BUS, B, T)
end_define

begin_macro
name|PS3BUS_ACCESSOR
argument_list|(
argument|bus
argument_list|,
argument|BUS
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PS3BUS_ACCESSOR
argument_list|(
argument|device
argument_list|,
argument|DEVICE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PS3BUS_ACCESSOR
argument_list|(
argument|bustype
argument_list|,
argument|BUSTYPE
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_macro
name|PS3BUS_ACCESSOR
argument_list|(
argument|devtype
argument_list|,
argument|DEVTYPE
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_macro
name|PS3BUS_ACCESSOR
argument_list|(
argument|busidx
argument_list|,
argument|BUSIDX
argument_list|,
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|PS3BUS_ACCESSOR
argument_list|(
name|devidx
argument_list|,
name|DEVIDX
argument_list|,
name|int
argument_list|)
comment|/* Bus types */
expr|enum
block|{
name|PS3_BUSTYPE_SYSBUS
operator|=
literal|4
block|,
name|PS3_BUSTYPE_STORAGE
operator|=
literal|5
block|, }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Device types */
end_comment

begin_enum
enum|enum
block|{
comment|/* System bus devices */
name|PS3_DEVTYPE_GELIC
init|=
literal|3
block|,
name|PS3_DEVTYPE_USB
init|=
literal|4
block|,
name|PS3_DEVTYPE_GPIO
init|=
literal|6
block|,
comment|/* Storage bus devices */
name|PS3_DEVTYPE_DISK
init|=
literal|0
block|,
name|PS3_DEVTYPE_CDROM
init|=
literal|5
block|,
name|PS3_DEVTYPE_FLASH
init|=
literal|14
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_PS3_PS3BUS_H */
end_comment

end_unit

