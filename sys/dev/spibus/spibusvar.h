begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SPIBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct spibus_ivar *) device_get_ivars(d)
end_define

begin_define
define|#
directive|define
name|SPIBUS_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct spibus_softc *) device_get_softc(d)
end_define

begin_struct
struct|struct
name|spibus_softc
block|{
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spibus_ivar
block|{
name|uint32_t
name|cs
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|SPIBUS_IVAR_CS
comment|/* chip select that we're on */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SPIBUS_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|static inline int							\ spibus_get_ ## A(device_t dev, T *t)					\ {									\ 	return BUS_READ_IVAR(device_get_parent(dev), dev,		\ 	    SPIBUS_IVAR_ ## B, (uintptr_t *) t);			\ }
end_define

begin_macro
name|SPIBUS_ACCESSOR
argument_list|(
argument|cs
argument_list|,
argument|CS
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|driver_t
name|spibus_driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|spibus_devclass
decl_stmt|;
end_decl_stmt

end_unit

