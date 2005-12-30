begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * CIS Handling for the Cardbus Bus  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/pciio.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccard_cis.h>
end_include

begin_include
include|#
directive|include
file|<dev/cardbus/cardbusreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/cardbus/cardbusvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/cardbus/cardbus_cis.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|cardbus_cis_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|a
parameter_list|)
value|if (cardbus_cis_debug) printf a
end_define

begin_define
define|#
directive|define
name|DEVPRINTF
parameter_list|(
name|x
parameter_list|)
value|if (cardbus_cis_debug) device_printf x
end_define

begin_function_decl
specifier|static
name|int
name|decode_tuple_generic
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_linktarget
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_vers_1
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_funcid
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_manfid
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_funce
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_bar
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_unhandled
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple_end
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|cardbus_read_tuple_conf
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|int
modifier|*
name|tupleid
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|cardbus_read_tuple_mem
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|int
modifier|*
name|tupleid
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|cardbus_read_tuple
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|int
modifier|*
name|tupleid
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|cardbus_read_tuple_finish
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|resource
modifier|*
name|cardbus_read_tuple_init
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|uint32_t
modifier|*
name|start
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|decode_tuple
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|tupleid
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|callbacks
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAKETUPLE
parameter_list|(
name|NAME
parameter_list|,
name|FUNC
parameter_list|)
value|{ CISTPL_ ## NAME, #NAME, decode_tuple_ ## FUNC }
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|funcnames
index|[]
init|=
block|{
literal|"Multi-Functioned"
block|,
literal|"Memory"
block|,
literal|"Serial Port"
block|,
literal|"Parallel Port"
block|,
literal|"Fixed Disk"
block|,
literal|"Video Adaptor"
block|,
literal|"Network Adaptor"
block|,
literal|"AIMS"
block|,
literal|"SCSI"
block|,
literal|"Security"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Handler functions for various CIS tuples  */
end_comment

begin_function
specifier|static
name|int
name|decode_tuple_generic
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
if|if
condition|(
name|info
condition|)
name|printf
argument_list|(
literal|"TUPLE: %s [%d]:"
argument_list|,
name|info
operator|->
name|name
argument_list|,
name|len
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"TUPLE: Unknown(0x%02x) [%d]:"
argument_list|,
name|id
argument_list|,
name|len
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|%
literal|0x10
operator|==
literal|0
operator|&&
name|len
operator|>
literal|0x10
condition|)
name|printf
argument_list|(
literal|"\n       0x%02x:"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %02x"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_linktarget
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
name|printf
argument_list|(
literal|"TUPLE: %s [%d]:"
argument_list|,
name|info
operator|->
name|name
argument_list|,
name|len
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|%
literal|0x10
operator|==
literal|0
operator|&&
name|len
operator|>
literal|0x10
condition|)
name|printf
argument_list|(
literal|"\n       0x%02x:"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %02x"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|!=
literal|3
operator|||
name|tupledata
index|[
literal|0
index|]
operator|!=
literal|'C'
operator|||
name|tupledata
index|[
literal|1
index|]
operator|!=
literal|'I'
operator|||
name|tupledata
index|[
literal|2
index|]
operator|!=
literal|'S'
condition|)
block|{
name|printf
argument_list|(
literal|"Invalid data for CIS Link Target!\n"
argument_list|)
expr_stmt|;
name|decode_tuple_generic
argument_list|(
name|cbdev
argument_list|,
name|child
argument_list|,
name|id
argument_list|,
name|len
argument_list|,
name|tupledata
argument_list|,
name|start
argument_list|,
name|off
argument_list|,
name|info
argument_list|,
name|argp
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_vers_1
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
name|printf
argument_list|(
literal|"Product version: %d.%d\n"
argument_list|,
name|tupledata
index|[
literal|0
index|]
argument_list|,
name|tupledata
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Product name: "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|tupledata
index|[
name|i
index|]
operator|==
literal|'\0'
condition|)
name|printf
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|tupledata
index|[
name|i
index|]
operator|==
literal|0xff
condition|)
break|break;
else|else
name|printf
argument_list|(
literal|"%c"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_funcid
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|struct
name|cardbus_devinfo
modifier|*
name|dinfo
init|=
name|device_get_ivars
argument_list|(
name|child
argument_list|)
decl_stmt|;
name|int
name|numnames
init|=
sizeof|sizeof
argument_list|(
name|funcnames
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|funcnames
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
name|printf
argument_list|(
literal|"Functions: "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|tupledata
index|[
name|i
index|]
operator|<
name|numnames
condition|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|funcnames
index|[
name|tupledata
index|[
name|i
index|]
index|]
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Unknown(%d)"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
name|len
operator|-
literal|1
condition|)
name|printf
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|dinfo
operator|->
name|funcid
operator|=
name|tupledata
index|[
literal|0
index|]
expr_stmt|;
comment|/* use first in list */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_manfid
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|struct
name|cardbus_devinfo
modifier|*
name|dinfo
init|=
name|device_get_ivars
argument_list|(
name|child
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
name|printf
argument_list|(
literal|"Manufacturer ID: "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%02x"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|==
literal|5
condition|)
block|{
name|dinfo
operator|->
name|mfrid
operator|=
name|tupledata
index|[
literal|1
index|]
operator||
operator|(
name|tupledata
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
expr_stmt|;
name|dinfo
operator|->
name|prodid
operator|=
name|tupledata
index|[
literal|3
index|]
operator||
operator|(
name|tupledata
index|[
literal|4
index|]
operator|<<
literal|8
operator|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_funce
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|struct
name|cardbus_devinfo
modifier|*
name|dinfo
init|=
name|device_get_ivars
argument_list|(
name|child
argument_list|)
decl_stmt|;
name|int
name|type
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
name|cardbus_cis_debug
condition|)
block|{
name|printf
argument_list|(
literal|"Function Extension: "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%02x"
argument_list|,
name|tupledata
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|<
literal|2
condition|)
comment|/* too short */
return|return
operator|(
literal|0
operator|)
return|;
name|type
operator|=
name|tupledata
index|[
literal|0
index|]
expr_stmt|;
comment|/* XXX<32 always? */
switch|switch
condition|(
name|dinfo
operator|->
name|funcid
condition|)
block|{
case|case
name|PCCARD_FUNCTION_NETWORK
case|:
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|PCCARD_TPLFE_TYPE_LAN_NID
case|:
if|if
condition|(
name|tupledata
index|[
literal|1
index|]
operator|>
sizeof|sizeof
argument_list|(
name|dinfo
operator|->
name|funce
operator|.
name|lan
operator|.
name|nid
argument_list|)
condition|)
block|{
comment|/* ignore, warning? */
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|bcopy
argument_list|(
name|tupledata
operator|+
literal|2
argument_list|,
name|dinfo
operator|->
name|funce
operator|.
name|lan
operator|.
name|nid
argument_list|,
name|tupledata
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
name|dinfo
operator|->
name|fepresent
operator||=
literal|1
operator|<<
name|type
expr_stmt|;
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|decode_tuple_bar
parameter_list|(
name|device_t
name|cbdev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|tupledata
parameter_list|,
name|uint32_t
name|start
parameter_list|,
name|uint32_t
modifier|*
name|off
parameter_list|,
name|struct
name|tuple_callbacks
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
block|{
name|struct
name|cardbus_devinfo
modifier|*
name|dinfo
init|=
name|device_get_ivars
argument_list|(
name|child
argument_list|)
decl_stmt|;
name|int
name|type
decl_stmt|;
name|uint8_t
name|reg
decl_stmt|;
name|uint32_t
name|bar
decl_stmt|,
name|pci_bar
decl_stmt|;
if|if
condition|(
name|len
operator|!=
literal|6
condition|)
block|{
name|device_printf
argument_list|(
name|cbdev
argument_list|,
literal|"CIS BAR length not 6 (%d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|reg
operator|=
operator|*
name|tupledata
expr_stmt|;
name|len
operator|=
name|le32toh
argument_list|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|tupledata
operator|+
literal|2
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|TPL_BAR_REG_AS
condition|)
block|{
name|type
operator|=
name|SYS_RES_IOPORT
expr_stmt|;
block|}
else|else
block|{
name|type
operator|=
name|SYS_RES_MEMORY
expr_stmt|;
block|}
name|bar
operator|=
name|reg
operator|&
name|TPL_BAR_REG_ASI_MASK
expr_stmt|;
if|if
condition|(
name|bar
operator|==
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|cbdev
argument_list|,
literal|"Invalid BAR type 0 in CIS\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* XXX Return an error? */
block|}
elseif|else
if|if
condition|(
name|bar
operator|==
literal|7
condition|)
block|{
comment|/* XXX Should we try to map in Option ROMs? */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Convert from BAR type to BAR offset */
name|bar
operator|=
name|PCIR_BAR
argument_list|(
name|bar
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|SYS_RES_MEMORY
condition|)
block|{
if|if
condition|(
name|reg
operator|&
name|TPL_BAR_REG_PREFETCHABLE
condition|)
name|dinfo
operator|->
name|mprefetchable
operator||=
operator|(
literal|1
operator|<<
name|PCI_RID2BAR
argument_list|(
name|bar
argument_list|)
operator|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* 		 * XXX: It appears from a careful reading of the spec 		 * that we're not supposed to honor this when the bridge 		 * is not on the main system bus.  PCI spec doesn't appear 		 * to allow for memory ranges not listed in the bridge's 		 * decode range to be decoded.  The PC Card spec seems to 		 * indicate that this should only be done on x86 based 		 * machines, which seems to imply that on non-x86 machines 		 * the adddresses can be anywhere.  This further implies that 		 * since the hardware can do it on non-x86 machines, it should 		 * be able to do it on x86 machines.  Therefore, we can and 		 * should ignore this hint.  Furthermore, the PC Card spec 		 * recommends always allocating memory above 1MB, contradicting 		 * the other part of the PC Card spec. 		 * 		 * NetBSD ignores this bit, but it also ignores the 		 * prefetchable bit too, so that's not an indication of 		 * correctness. 		 */
block|if (reg& TPL_BAR_REG_BELOW1MB) 			dinfo->mbelow1mb |= (1<< PCI_RID2BAR(bar));
endif|#
directive|endif
block|}
comment|/* 	 * Sanity check the BAR length reported in the CIS with the length 	 * encoded in the PCI BAR.  The latter seems to be more reliable. 	 * XXX - This probably belongs elsewhere. 	 */
name|pci_write_config
argument_list|(
name|child
argument_list|,
name|bar
argument_list|,
literal|0xffffffff
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|pci_bar
operator|=
name|pci_read_config
argument_list|(
name|child
argument_list|,
name|bar
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pci_bar
operator|!=
literal|0x0
operator|)
operator|&&
operator|(
name|pci_bar
operator|!=
literal|0xffffffff
operator|)
condition|)
block|{
if|if
condition|(
name|type
operator|==
name|SYS_RES_MEMORY
condition|)
block|{
name|pci_bar
operator|&=
operator|~
literal|0xf
expr_stmt|;
block|}
else|else
block|{
name|pci_bar
operator|&=
operator|~
literal|0x3
expr_stmt|;
block|}
name|len
operator|=
literal|1
operator|<<
operator|(
name|ffs
argument_list|(
name|pci_bar
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
block|}
name|DEVPRINTF
argument_list|(
argument|(cbdev,
literal|"Opening BAR: type=%s, bar=%02x, len=%04x%s%s\n"
argument|, 	    (type == SYS_RES_MEMORY) ?
literal|"MEM"
argument|:
literal|"IO"
argument|, bar, len, 	    (type == SYS_RES_MEMORY&& 	    dinfo->mprefetchable& (
literal|1
argument|<< PCI_RID2BAR(bar))) ?
literal|" (Prefetchable)"
argument|:
literal|""
argument|, type == SYS_RES_MEMORY ? 	    ((dinfo->mbelow1mb& (
literal|1
argument|<< PCI_RID2BAR(bar)) ?
literal|" (Below 1Mb)"
argument|:
literal|""
argument|) :
literal|""
argument|));  	resource_list_add(&dinfo->pci.resources, type, bar,
literal|0UL
argument|, ~
literal|0UL
argument|, len);
comment|/* 	 * Mark the appropriate bit in the PCI command register so that 	 * device drivers will know which type of BARs can be used. 	 */
argument|pci_enable_io(child, type); 	return (
literal|0
argument|); }  static int decode_tuple_unhandled(device_t cbdev, device_t child, int id,     int len, uint8_t *tupledata, uint32_t start, uint32_t *off,     struct tuple_callbacks *info, void *argp) {
comment|/* Make this message suck less XXX */
argument|printf(
literal|"TUPLE: %s [%d] is unhandled! Bailing..."
argument|, info->name, len); 	return (EINVAL); }  static int decode_tuple_end(device_t cbdev, device_t child, int id,     int len, uint8_t *tupledata, uint32_t start, uint32_t *off,     struct tuple_callbacks *info, void *argp) { 	if (cardbus_cis_debug) 		printf(
literal|"CIS reading done\n"
argument|); 	return (
literal|0
argument|); }
comment|/*  * Functions to read the a tuple from the card  */
argument|static int cardbus_read_tuple_conf(device_t cbdev, device_t child, uint32_t start,     uint32_t *off, int *tupleid, int *len, uint8_t *tupledata) { 	int i
argument_list|,
argument|j; 	uint32_t e; 	uint32_t loc;  	loc = start + *off;  	e = pci_read_config(child, loc - loc %
literal|4
argument|,
literal|4
argument|); 	for (j = loc %
literal|4
argument|; j>
literal|0
argument|; j--) 		e>>=
literal|8
argument|; 	*len =
literal|0
argument|; 	for (i = loc, j = -
literal|2
argument|; j< *len; j++, i++) { 		if (i %
literal|4
argument|==
literal|0
argument|) 			e = pci_read_config(child, i,
literal|4
argument|); 		if (j == -
literal|2
argument|) 			*tupleid =
literal|0xff
argument|& e; 		else if (j == -
literal|1
argument|) 			*len =
literal|0xff
argument|& e; 		else 			tupledata[j] =
literal|0xff
argument|& e; 		e>>=
literal|8
argument|; 	} 	*off += *len +
literal|2
argument|; 	return (
literal|0
argument|); }  static int cardbus_read_tuple_mem(device_t cbdev, struct resource *res, uint32_t start,     uint32_t *off, int *tupleid, int *len, uint8_t *tupledata) { 	bus_space_tag_t bt; 	bus_space_handle_t bh; 	int ret;  	bt = rman_get_bustag(res); 	bh = rman_get_bushandle(res);  	*tupleid = bus_space_read_1(bt, bh, start + *off); 	*len = bus_space_read_1(bt, bh, start + *off +
literal|1
argument|); 	bus_space_read_region_1(bt, bh, *off + start +
literal|2
argument|, tupledata, *len); 	ret =
literal|0
argument|; 	*off += *len +
literal|2
argument|; 	return (ret); }  static int cardbus_read_tuple(device_t cbdev, device_t child, struct resource *res,     uint32_t start, uint32_t *off, int *tupleid, int *len,     uint8_t *tupledata) { 	if (res == (struct resource*)~
literal|0UL
argument|) { 		return (cardbus_read_tuple_conf(cbdev, child, start, off, 		    tupleid, len, tupledata)); 	} else { 		return (cardbus_read_tuple_mem(cbdev, res, start, off, 		    tupleid, len, tupledata)); 	} }  static void cardbus_read_tuple_finish(device_t cbdev, device_t child, int rid,     struct resource *res) { 	if (res != (struct resource*)~
literal|0UL
argument|) { 		bus_release_resource(cbdev, SYS_RES_MEMORY, rid, res); 		if (rid == PCIM_CIS_ASI_ROM) 			pci_write_config(child, rid, pci_read_config(child, 			    rid,
literal|4
argument|)& ~PCIR_BIOS,
literal|4
argument|); 	} }  static struct resource * cardbus_read_tuple_init(device_t cbdev, device_t child, uint32_t *start,     int *rid) { 	struct resource *res; 	uint32_t space;  	space = *start& PCIM_CIS_ASI_MASK; 	switch (space) { 	case PCIM_CIS_ASI_TUPLE: 		if (cardbus_cis_debug) 			device_printf(cbdev,
literal|"CIS in PCI config space\n"
argument|);
comment|/* CIS in PCI config space need no initialization */
argument|return ((struct resource*)~
literal|0UL
argument|); 	case PCIM_CIS_ASI_BAR0: 	case PCIM_CIS_ASI_BAR1: 	case PCIM_CIS_ASI_BAR2: 	case PCIM_CIS_ASI_BAR3: 	case PCIM_CIS_ASI_BAR4: 	case PCIM_CIS_ASI_BAR5: 		*rid = PCIR_BAR(space - PCIM_CIS_ASI_BAR0); 		if (cardbus_cis_debug) 			device_printf(cbdev,
literal|"CIS in BAR %#x\n"
argument|, *rid); 		break; 	case PCIM_CIS_ASI_ROM: 		*rid = PCIR_BIOS; 		if (cardbus_cis_debug) 			device_printf(cbdev,
literal|"CIS in option rom\n"
argument|); 		break; 	default: 		device_printf(cbdev,
literal|"Unable to read CIS: Unknown space: %d\n"
argument|, 		    space); 		return (NULL); 	}
comment|/* allocate the memory space to read CIS */
argument|res = bus_alloc_resource(cbdev, SYS_RES_MEMORY, rid,
literal|0
argument|, ~
literal|0
argument|,
literal|1
argument|, 	    rman_make_alignment_flags(
literal|4096
argument|) | RF_ACTIVE); 	if (res == NULL) { 		device_printf(cbdev,
literal|"Unable to allocate resource "
literal|"to read CIS.\n"
argument|); 		return (NULL); 	} 	PCI_ENABLE_IO(cbdev, child, SYS_RES_MEMORY); 	pci_write_config(child, *rid, rman_get_start(res),
literal|4
argument|); 	if (*rid == PCIR_BIOS) 		pci_write_config(child, *rid, 		    rman_get_start(res) | PCIM_BIOS_ENABLE,
literal|4
argument|);
comment|/* Flip to the right ROM image if CIS is in ROM */
argument|if (space == PCIM_CIS_ASI_ROM) { 		bus_space_tag_t bt; 		bus_space_handle_t bh; 		uint32_t imagesize; 		uint32_t imagebase =
literal|0
argument|; 		uint32_t pcidata; 		uint16_t romsig; 		int romnum =
literal|0
argument|; 		int imagenum;  		bt = rman_get_bustag(res); 		bh = rman_get_bushandle(res);  		imagenum = (*start& PCIM_CIS_ROM_MASK)>>
literal|28
argument|; 		for (romnum =
literal|0
argument|;; romnum++) { 			romsig = bus_space_read_2(bt, bh, 			    imagebase + CARDBUS_EXROM_SIGNATURE); 			if (romsig !=
literal|0xaa55
argument|) { 				device_printf(cbdev,
literal|"Bad header in rom %d: "
literal|"[%x] %04x\n"
argument|, romnum, imagebase + 				    CARDBUS_EXROM_SIGNATURE, romsig); 				bus_release_resource(cbdev, SYS_RES_MEMORY, 				    *rid, res); 				*rid =
literal|0
argument|; 				return (NULL); 			}
comment|/* 			 * If this was the Option ROM image that we were 			 * looking for, then we are done. 			 */
argument|if (romnum == imagenum) 				break;
comment|/* Find out where the next Option ROM image is */
argument|pcidata = imagebase + bus_space_read_2(bt, bh, 			    imagebase + CARDBUS_EXROM_DATA_PTR); 			imagesize = bus_space_read_2(bt, bh, 			    pcidata + CARDBUS_EXROM_DATA_IMAGE_LENGTH);  			if (imagesize ==
literal|0
argument|) {
comment|/* 				 * XXX some ROMs seem to have this as zero, 				 * can we assume this means 1 block? 				 */
argument|device_printf(cbdev,
literal|"Warning, size of Option "
literal|"ROM image %d is 0 bytes, assuming 512 "
literal|"bytes.\n"
argument|, romnum); 				imagesize =
literal|1
argument|; 			}
comment|/* Image size is in 512 byte units */
argument|imagesize<<=
literal|9
argument|;  			if ((bus_space_read_1(bt, bh, pcidata + 			    CARDBUS_EXROM_DATA_INDICATOR)&
literal|0x80
argument|) !=
literal|0
argument|) { 				device_printf(cbdev,
literal|"Cannot find CIS in "
literal|"Option ROM\n"
argument|); 				bus_release_resource(cbdev, SYS_RES_MEMORY, 				    *rid, res); 				*rid =
literal|0
argument|; 				return (NULL); 			} 			imagebase += imagesize; 		} 		*start = imagebase + (*start& PCIM_CIS_ADDR_MASK); 	} else { 		*start = *start& PCIM_CIS_ADDR_MASK; 	}  	return (res); }
comment|/*  * Dispatch the right handler function per tuple  */
argument|static int decode_tuple(device_t cbdev, device_t child, int tupleid, int len,     uint8_t *tupledata, uint32_t start, uint32_t *off,     struct tuple_callbacks *callbacks, void *argp) { 	int i; 	for (i =
literal|0
argument|; callbacks[i].id != CISTPL_GENERIC; i++) { 		if (tupleid == callbacks[i].id) 			return (callbacks[i].func(cbdev, child, tupleid, len, 			    tupledata, start, off,&callbacks[i], argp)); 	} 	return (callbacks[i].func(cbdev, child, tupleid, len, 	    tupledata, start, off, NULL, argp)); }  int cardbus_parse_cis(device_t cbdev, device_t child,     struct tuple_callbacks *callbacks, void *argp) { 	uint8_t tupledata[MAXTUPLESIZE]; 	int tupleid; 	int len; 	int expect_linktarget; 	uint32_t start
argument_list|,
argument|off; 	struct resource *res; 	int rid;  	bzero(tupledata, MAXTUPLESIZE); 	expect_linktarget = TRUE; 	if ((start = pci_read_config(child, PCIR_CIS,
literal|4
argument|)) ==
literal|0
argument|) { 		device_printf(cbdev,
literal|"CIS pointer is 0!\n"
argument|); 		return (ENXIO); 	} 	if (cardbus_cis_debug) 		device_printf(cbdev,
literal|"CIS pointer is %#x\n"
argument|, start); 	off =
literal|0
argument|; 	res = cardbus_read_tuple_init(cbdev, child,&start,&rid); 	if (res == NULL) { 		device_printf(cbdev,
literal|"Unable to allocate resources for CIS\n"
argument|); 		return (ENXIO); 	}  	do { 		if (cardbus_read_tuple(cbdev, child, res, start,&off,&tupleid,&len, tupledata) !=
literal|0
argument|) { 			device_printf(cbdev,
literal|"Failed to read CIS.\n"
argument|); 			cardbus_read_tuple_finish(cbdev, child, rid, res); 			return (ENXIO); 		}  		if (expect_linktarget&& tupleid != CISTPL_LINKTARGET) { 			device_printf(cbdev,
literal|"Expecting link target, got 0x%x\n"
argument|, 			    tupleid); 			cardbus_read_tuple_finish(cbdev, child, rid, res); 			return (EINVAL); 		} 		expect_linktarget = decode_tuple(cbdev, child, tupleid, len, 		    tupledata, start,&off, callbacks, argp); 		if (expect_linktarget !=
literal|0
argument|) { 			device_printf(cbdev,
literal|"Parsing failed with %d\n"
argument|, 			    expect_linktarget); 			cardbus_read_tuple_finish(cbdev, child, rid, res); 			return (expect_linktarget); 		} 	} while (tupleid != CISTPL_END); 	cardbus_read_tuple_finish(cbdev, child, rid, res); 	return (
literal|0
argument|); }  int cardbus_do_cis(device_t cbdev, device_t child) { 	int ret; 	struct tuple_callbacks init_callbacks[] = { 		MAKETUPLE(LONGLINK_CB,		unhandled)
argument_list|,
argument|MAKETUPLE(INDIRECT,		unhandled)
argument_list|,
argument|MAKETUPLE(LONGLINK_MFC,		unhandled)
argument_list|,
argument|MAKETUPLE(BAR,			bar)
argument_list|,
argument|MAKETUPLE(LONGLINK_A,		unhandled)
argument_list|,
argument|MAKETUPLE(LONGLINK_C,		unhandled)
argument_list|,
argument|MAKETUPLE(LINKTARGET,		linktarget)
argument_list|,
argument|MAKETUPLE(VERS_1,		vers_1)
argument_list|,
argument|MAKETUPLE(MANFID,		manfid)
argument_list|,
argument|MAKETUPLE(FUNCID,		funcid)
argument_list|,
argument|MAKETUPLE(FUNCE,		funce)
argument_list|,
argument|MAKETUPLE(END,			end)
argument_list|,
argument|MAKETUPLE(GENERIC,		generic)
argument_list|,
argument|};  	ret = cardbus_parse_cis(cbdev, child, init_callbacks, NULL); 	if (ret<
literal|0
argument|) 		return (ret); 	return
literal|0
argument|; }
end_function

end_unit

