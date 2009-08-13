begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, 2009 Yahoo!, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MFIUTIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__MFIUTIL_H__
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<dev/mfi/mfireg.h>
end_include

begin_comment
comment|/* 4.x compat */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_DECLARE
end_ifndef

begin_comment
comment|/*<sys/cdefs.h> */
end_comment

begin_define
define|#
directive|define
name|__used
end_define

begin_define
define|#
directive|define
name|__section
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__section__(x)))
end_define

begin_comment
comment|/*<sys/linker_set.h> */
end_comment

begin_undef
undef|#
directive|undef
name|__MAKE_SET
end_undef

begin_undef
undef|#
directive|undef
name|DATA_SET
end_undef

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
define|\
value|static void const * const __set_##set##_sym_##sym 		\ 	__section("set_" #set) __used =&sym
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|SET_DECLARE
parameter_list|(
name|set
parameter_list|,
name|ptype
parameter_list|)
define|\
value|extern ptype *__CONCAT(__start_set_,set);			\ 	extern ptype *__CONCAT(__stop_set_,set)
end_define

begin_define
define|#
directive|define
name|SET_BEGIN
parameter_list|(
name|set
parameter_list|)
define|\
value|(&__CONCAT(__start_set_,set))
end_define

begin_define
define|#
directive|define
name|SET_LIMIT
parameter_list|(
name|set
parameter_list|)
define|\
value|(&__CONCAT(__stop_set_,set))
end_define

begin_define
define|#
directive|define
name|SET_FOREACH
parameter_list|(
name|pvar
parameter_list|,
name|set
parameter_list|)
define|\
value|for (pvar = SET_BEGIN(set); pvar< SET_LIMIT(set); pvar++)
end_define

begin_function_decl
name|int
name|humanize_number
parameter_list|(
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|,
name|int64_t
name|_number
parameter_list|,
specifier|const
name|char
modifier|*
name|_suffix
parameter_list|,
name|int
name|_scale
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* humanize_number(3) */
end_comment

begin_define
define|#
directive|define
name|HN_DECIMAL
value|0x01
end_define

begin_define
define|#
directive|define
name|HN_NOSPACE
value|0x02
end_define

begin_define
define|#
directive|define
name|HN_B
value|0x04
end_define

begin_define
define|#
directive|define
name|HN_DIVISOR_1000
value|0x08
end_define

begin_define
define|#
directive|define
name|HN_GETSCALE
value|0x10
end_define

begin_define
define|#
directive|define
name|HN_AUTOSCALE
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Constants for DDF RAID levels. */
end_comment

begin_define
define|#
directive|define
name|DDF_RAID0
value|0x00
end_define

begin_define
define|#
directive|define
name|DDF_RAID1
value|0x01
end_define

begin_define
define|#
directive|define
name|DDF_RAID3
value|0x03
end_define

begin_define
define|#
directive|define
name|DDF_RAID5
value|0x05
end_define

begin_define
define|#
directive|define
name|DDF_RAID6
value|0x06
end_define

begin_define
define|#
directive|define
name|DDF_RAID1E
value|0x11
end_define

begin_define
define|#
directive|define
name|DDF_JBOD
value|0x0f
end_define

begin_define
define|#
directive|define
name|DDF_CONCAT
value|0x1f
end_define

begin_define
define|#
directive|define
name|DDF_RAID5E
value|0x15
end_define

begin_define
define|#
directive|define
name|DDF_RAID5EE
value|0x25
end_define

begin_struct
struct|struct
name|mfiutil_command
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_DATASET
parameter_list|(
name|name
parameter_list|)
value|mfiutil_ ## name ## _table
end_define

begin_define
define|#
directive|define
name|MFI_COMMAND
parameter_list|(
name|set
parameter_list|,
name|name
parameter_list|,
name|function
parameter_list|)
define|\
value|static struct mfiutil_command function ## _mfiutil_command =	\ 	{ #name, function };						\ 	DATA_SET(MFI_DATASET(set), function ## _mfiutil_command)
end_define

begin_define
define|#
directive|define
name|MFI_TABLE
parameter_list|(
name|set
parameter_list|,
name|name
parameter_list|)
define|\
value|SET_DECLARE(MFI_DATASET(name), struct mfiutil_command);		\ 									\ 	static int							\ 	mfiutil_ ## name ## _table_handler(int ac, char **av)		\ 	{								\ 		return (mfi_table_handler(SET_BEGIN(MFI_DATASET(name)), \ 		    SET_LIMIT(MFI_DATASET(name)), ac, av));		\ 	}								\ 	MFI_COMMAND(set, name, mfiutil_ ## name ## _table_handler)
end_define

begin_decl_stmt
specifier|extern
name|int
name|mfi_unit
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mbox_store_ldref
parameter_list|(
name|uint8_t
modifier|*
name|mbox
parameter_list|,
name|union
name|mfi_ld_ref
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbox_store_pdref
parameter_list|(
name|uint8_t
modifier|*
name|mbox
parameter_list|,
name|union
name|mfi_pd_ref
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mfi_display_progress
parameter_list|(
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|struct
name|mfi_progress
modifier|*
name|prog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_table_handler
parameter_list|(
name|struct
name|mfiutil_command
modifier|*
modifier|*
name|start
parameter_list|,
name|struct
name|mfiutil_command
modifier|*
modifier|*
name|end
parameter_list|,
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_raid_level
parameter_list|(
name|uint8_t
name|primary_level
parameter_list|,
name|uint8_t
name|secondary_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_ldstate
parameter_list|(
name|enum
name|mfi_ld_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_pdstate
parameter_list|(
name|enum
name|mfi_pd_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_pd_inq_string
parameter_list|(
name|struct
name|mfi_pd_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_volume_name
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint8_t
name|target_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_volume_busy
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint8_t
name|target_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_config_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|mfi_config_data
modifier|*
modifier|*
name|configp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_lookup_drive
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|drive
parameter_list|,
name|uint16_t
modifier|*
name|device_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_lookup_volume
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint8_t
modifier|*
name|target_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_dcmd_command
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint32_t
name|opcode
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|uint8_t
modifier|*
name|mbox
parameter_list|,
name|size_t
name|mboxlen
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_open
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_ctrl_get_info
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|mfi_ctrl_info
modifier|*
name|info
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_ld_get_info
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint8_t
name|target_id
parameter_list|,
name|struct
name|mfi_ld_info
modifier|*
name|info
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_ld_get_list
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|mfi_ld_list
modifier|*
name|list
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_pd_get_info
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint16_t
name|device_id
parameter_list|,
name|struct
name|mfi_pd_info
modifier|*
name|info
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_pd_get_list
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|mfi_pd_list
modifier|*
modifier|*
name|listp
parameter_list|,
name|uint8_t
modifier|*
name|statusp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mfi_reconfig_supported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mfi_status
parameter_list|(
name|u_int
name|status_code
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MFIUTIL_H__ */
end_comment

end_unit

