begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|HTIF_DEV_ID_SHIFT
value|(56)
end_define

begin_define
define|#
directive|define
name|HTIF_DEV_ID_MASK
value|(0xfful<< HTIF_DEV_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_SHIFT
value|(48)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_MASK
value|(0xfful<< HTIF_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|HTIF_DATA_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|HTIF_DATA_MASK
value|(0xffffffff<< HTIF_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_READ
value|(0x00ul)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_WRITE
value|(0x01ul)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_READ_CONTROL_REG
value|(0x02ul)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_WRITE_CONTROL_REG
value|(0x03ul)
end_define

begin_define
define|#
directive|define
name|HTIF_CMD_IDENTIFY
value|(0xfful)
end_define

begin_define
define|#
directive|define
name|IDENTIFY_PADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IDENTIFY_IDENT
value|0xff
end_define

begin_define
define|#
directive|define
name|HTIF_NDEV
value|(256)
end_define

begin_define
define|#
directive|define
name|HTIF_ID_LEN
value|(64)
end_define

begin_define
define|#
directive|define
name|HTIF_ALIGN
value|(64)
end_define

begin_define
define|#
directive|define
name|HTIF_DEV_CMD
parameter_list|(
name|entry
parameter_list|)
value|((entry& HTIF_CMD_MASK)>> HTIF_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|HTIF_DEV_ID
parameter_list|(
name|entry
parameter_list|)
value|((entry& HTIF_DEV_ID_MASK)>> HTIF_DEV_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|HTIF_DEV_DATA
parameter_list|(
name|entry
parameter_list|)
value|((entry& HTIF_DATA_MASK)>> HTIF_DATA_SHIFT)
end_define

begin_comment
comment|/* bus softc */
end_comment

begin_struct
struct|struct
name|htif_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|ihl
index|[
literal|1
index|]
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|uint64_t
name|identify_id
decl_stmt|;
name|uint64_t
name|identify_done
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* device private data */
end_comment

begin_struct
struct|struct
name|htif_dev_ivars
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|int
name|index
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|htif_softc
modifier|*
name|sc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|uint64_t
name|htif_command
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|htif_setup_intr
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|htif_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|htif_device_ivars
block|{
name|HTIF_IVAR_INDEX
block|,
name|HTIF_IVAR_ID
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for HTIF devices  */
end_comment

begin_define
define|#
directive|define
name|HTIF_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(htif, var, HTIF, ivar, type)
end_define

begin_expr_stmt
name|HTIF_ACCESSOR
argument_list|(
name|index
argument_list|,
name|INDEX
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HTIF_ACCESSOR
argument_list|(
name|id
argument_list|,
name|ID
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

