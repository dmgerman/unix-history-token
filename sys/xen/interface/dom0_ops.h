begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * dom0_ops.h  *   * Process command requests from domain-0 guest OS.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2002-2003, B Dragovic  * Copyright (c) 2002-2006, K Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_DOM0_OPS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_DOM0_OPS_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_include
include|#
directive|include
file|"platform.h"
end_include

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030204
end_if

begin_error
error|#
directive|error
literal|"dom0_ops.h is a compatibility interface only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DOM0_INTERFACE_VERSION
value|XENPF_INTERFACE_VERSION
end_define

begin_define
define|#
directive|define
name|DOM0_SETTIME
value|XENPF_settime
end_define

begin_define
define|#
directive|define
name|dom0_settime
value|xenpf_settime
end_define

begin_define
define|#
directive|define
name|dom0_settime_t
value|xenpf_settime_t
end_define

begin_define
define|#
directive|define
name|DOM0_ADD_MEMTYPE
value|XENPF_add_memtype
end_define

begin_define
define|#
directive|define
name|dom0_add_memtype
value|xenpf_add_memtype
end_define

begin_define
define|#
directive|define
name|dom0_add_memtype_t
value|xenpf_add_memtype_t
end_define

begin_define
define|#
directive|define
name|DOM0_DEL_MEMTYPE
value|XENPF_del_memtype
end_define

begin_define
define|#
directive|define
name|dom0_del_memtype
value|xenpf_del_memtype
end_define

begin_define
define|#
directive|define
name|dom0_del_memtype_t
value|xenpf_del_memtype_t
end_define

begin_define
define|#
directive|define
name|DOM0_READ_MEMTYPE
value|XENPF_read_memtype
end_define

begin_define
define|#
directive|define
name|dom0_read_memtype
value|xenpf_read_memtype
end_define

begin_define
define|#
directive|define
name|dom0_read_memtype_t
value|xenpf_read_memtype_t
end_define

begin_define
define|#
directive|define
name|DOM0_MICROCODE
value|XENPF_microcode_update
end_define

begin_define
define|#
directive|define
name|dom0_microcode
value|xenpf_microcode_update
end_define

begin_define
define|#
directive|define
name|dom0_microcode_t
value|xenpf_microcode_update_t
end_define

begin_define
define|#
directive|define
name|DOM0_PLATFORM_QUIRK
value|XENPF_platform_quirk
end_define

begin_define
define|#
directive|define
name|dom0_platform_quirk
value|xenpf_platform_quirk
end_define

begin_define
define|#
directive|define
name|dom0_platform_quirk_t
value|xenpf_platform_quirk_t
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|cpumap_t
typedef|;
end_typedef

begin_comment
comment|/* Unsupported legacy operation -- defined for API compatibility. */
end_comment

begin_define
define|#
directive|define
name|DOM0_MSR
value|15
end_define

begin_struct
struct|struct
name|dom0_msr
block|{
comment|/* IN variables. */
name|uint32_t
name|write
decl_stmt|;
name|cpumap_t
name|cpu_mask
decl_stmt|;
name|uint32_t
name|msr
decl_stmt|;
name|uint32_t
name|in1
decl_stmt|;
name|uint32_t
name|in2
decl_stmt|;
comment|/* OUT variables. */
name|uint32_t
name|out1
decl_stmt|;
name|uint32_t
name|out2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dom0_msr
name|dom0_msr_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|dom0_msr_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Unsupported legacy operation -- defined for API compatibility. */
end_comment

begin_define
define|#
directive|define
name|DOM0_PHYSICAL_MEMORY_MAP
value|40
end_define

begin_struct
struct|struct
name|dom0_memory_map_entry
block|{
name|uint64_t
name|start
decl_stmt|,
name|end
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* reserved */
name|uint8_t
name|is_ram
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dom0_memory_map_entry
name|dom0_memory_map_entry_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|dom0_memory_map_entry_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|dom0_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* DOM0_INTERFACE_VERSION */
union|union
block|{
name|struct
name|dom0_msr
name|msr
decl_stmt|;
name|struct
name|dom0_settime
name|settime
decl_stmt|;
name|struct
name|dom0_add_memtype
name|add_memtype
decl_stmt|;
name|struct
name|dom0_del_memtype
name|del_memtype
decl_stmt|;
name|struct
name|dom0_read_memtype
name|read_memtype
decl_stmt|;
name|struct
name|dom0_microcode
name|microcode
decl_stmt|;
name|struct
name|dom0_platform_quirk
name|platform_quirk
decl_stmt|;
name|struct
name|dom0_memory_map_entry
name|physical_memory_map
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|128
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dom0_op
name|dom0_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|dom0_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_DOM0_OPS_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

