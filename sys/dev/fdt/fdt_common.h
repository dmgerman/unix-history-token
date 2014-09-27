begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FDT_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_FDT_COMMON_H_
end_define

begin_include
include|#
directive|include
file|<sys/slicer.h>
end_include

begin_include
include|#
directive|include
file|<contrib/libfdt/libfdt_env.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_define
define|#
directive|define
name|FDT_MEM_REGIONS
value|8
end_define

begin_define
define|#
directive|define
name|DI_MAX_INTR_NUM
value|32
end_define

begin_struct
struct|struct
name|fdt_sense_level
block|{
name|enum
name|intr_trigger
name|trig
decl_stmt|;
name|enum
name|intr_polarity
name|pol
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|fdt_pic_decode_t
function_decl|)
parameter_list|(
name|phandle_t
parameter_list|,
name|pcell_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|fdt_pic_decode_t
name|fdt_pic_table
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|fdt_fixup_t
function_decl|)
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|fdt_fixup_entry
block|{
name|char
modifier|*
name|model
decl_stmt|;
name|fdt_fixup_t
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fdt_fixup_entry
name|fdt_fixup_table
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SLIST_HEAD(fdt_ic_list
operator|,
extern|fdt_ic
end_extern

begin_expr_stmt
unit|)
name|fdt_ic_list_head
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|fdt_ic
block|{
name|SLIST_ENTRY
argument_list|(
argument|fdt_ic
argument_list|)
name|fdt_ics
expr_stmt|;
name|ihandle_t
name|iph
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|fdt_immr_pa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|fdt_immr_va
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|fdt_immr_size
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|fdt_pm_mask_entry
block|{
name|char
modifier|*
name|compat
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fdt_pm_mask_entry
name|fdt_pm_mask_table
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDT_DTB_STATIC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|u_char
name|fdt_static_dtb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|fdt_addrsize_cells
parameter_list|(
name|phandle_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|fdt_data_get
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_data_to_res
parameter_list|(
name|pcell_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_data_verify
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|fdt_find_compatible
parameter_list|(
name|phandle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|fdt_depth_search_compatible
parameter_list|(
name|phandle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_get_mem_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_get_reserved_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_get_phyaddr
parameter_list|(
name|phandle_t
parameter_list|,
name|device_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_get_range
parameter_list|(
name|phandle_t
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_immr_addr
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_regsize
parameter_list|(
name|phandle_t
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_is_compatible
parameter_list|(
name|phandle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_is_compatible_strict
parameter_list|(
name|phandle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_is_enabled
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_pm_is_enabled
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_is_type
parameter_list|(
name|phandle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_parent_addr_cells
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_ranges_verify
parameter_list|(
name|pcell_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_reg_to_rl
parameter_list|(
name|phandle_t
parameter_list|,
name|struct
name|resource_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_pm
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_get_unit
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FDT_COMMON_H_ */
end_comment

end_unit

