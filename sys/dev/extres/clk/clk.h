begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_EXTRES_CLK_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_EXTRES_CLK_H_
end_define

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"clknode_if.h"
end_include

begin_define
define|#
directive|define
name|CLKNODE_IDX_NONE
value|-1
end_define

begin_comment
comment|/* Not-selected index */
end_comment

begin_comment
comment|/* clknode flags. */
end_comment

begin_define
define|#
directive|define
name|CLK_NODE_STATIC_STRINGS
value|0x00000001
end_define

begin_comment
comment|/* Static name strings */
end_comment

begin_define
define|#
directive|define
name|CLK_NODE_GLITCH_FREE
value|0x00000002
end_define

begin_comment
comment|/* Freq can change w/o stop */
end_comment

begin_define
define|#
directive|define
name|CLK_NODE_CANNOT_STOP
value|0x00000004
end_define

begin_comment
comment|/* Clock cannot be disabled */
end_comment

begin_comment
comment|/* Flags passed to clk_set_freq() and clknode_set_freq(). */
end_comment

begin_define
define|#
directive|define
name|CLK_SET_ROUND_UP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CLK_SET_ROUND_DOWN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CLK_SET_USER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|CLK_SET_DRYRUN
value|0x00010000
end_define

begin_typedef
typedef|typedef
name|struct
name|clk
modifier|*
name|clk_t
typedef|;
end_typedef

begin_comment
comment|/* Initialization parameters for clocknode creation. */
end_comment

begin_struct
struct|struct
name|clknode_init_def
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|intptr_t
name|id
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|parent_names
decl_stmt|;
name|int
name|parent_cnt
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Shorthands for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|CLKNODEMETHOD
value|KOBJMETHOD
end_define

begin_define
define|#
directive|define
name|CLKNODEMETHOD_END
value|KOBJMETHOD_END
end_define

begin_define
define|#
directive|define
name|clknode_method_t
value|kobj_method_t
end_define

begin_define
define|#
directive|define
name|clknode_class_t
value|kobj_class_t
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|clknode_class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  Clock domain functions.  */
end_comment

begin_function_decl
name|struct
name|clkdom
modifier|*
name|clkdom_create
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clkdom_finit
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clkdom_dump
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clkdom_unlock
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clkdom_xlock
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clock providers interface.  */
end_comment

begin_function_decl
name|struct
name|clkdom
modifier|*
name|clkdom_get_by_dev
parameter_list|(
specifier|const
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|clknode
modifier|*
name|clknode_create
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|clknode_class_t
name|clknode_class
parameter_list|,
specifier|const
name|struct
name|clknode_init_def
modifier|*
name|def
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|clknode
modifier|*
name|clknode_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|cldom
parameter_list|,
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_typedef
typedef|typedef
name|int
name|clknode_ofw_mapper_func
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|uint32_t
name|ncells
parameter_list|,
name|phandle_t
modifier|*
name|cells
parameter_list|,
name|struct
name|clknode
modifier|*
modifier|*
name|clk
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|clkdom_set_ofw_mapper
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|clknode_ofw_mapper_func
modifier|*
name|cmp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|clknode_init_parent_idx
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_set_parent_by_idx
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_set_parent_by_name
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|clknode_get_name
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|clknode_get_parent_names
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_get_parents_num
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_get_parent_idx
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|clknode
modifier|*
name|clknode_get_parent
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_get_flags
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|clknode_get_softc
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|clknode_get_device
parameter_list|(
name|struct
name|clknode
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|clknode
modifier|*
name|clknode_find_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|clknode
modifier|*
name|clknode_find_by_id
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|intptr_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_get_freq
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|,
name|uint64_t
modifier|*
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_set_freq
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|,
name|uint64_t
name|freq
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|enablecnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_enable
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_disable
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clknode_stop
parameter_list|(
name|struct
name|clknode
modifier|*
name|clknode
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clock consumers interface.  */
end_comment

begin_function_decl
name|int
name|clk_get_by_name
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|clk_t
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_get_by_id
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|intptr_t
name|id
parameter_list|,
name|clk_t
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_release
parameter_list|(
name|clk_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_get_freq
parameter_list|(
name|clk_t
name|clk
parameter_list|,
name|uint64_t
modifier|*
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_set_freq
parameter_list|(
name|clk_t
name|clk
parameter_list|,
name|uint64_t
name|freq
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_test_freq
parameter_list|(
name|clk_t
name|clk
parameter_list|,
name|uint64_t
name|freq
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_enable
parameter_list|(
name|clk_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_disable
parameter_list|(
name|clk_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_stop
parameter_list|(
name|clk_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_get_parent
parameter_list|(
name|clk_t
name|clk
parameter_list|,
name|clk_t
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_set_parent_by_clk
parameter_list|(
name|clk_t
name|clk
parameter_list|,
name|clk_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|clk_get_name
parameter_list|(
name|clk_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|int
name|clk_get_by_ofw_index
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|idx
parameter_list|,
name|clk_t
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_get_by_ofw_name
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|clk_t
modifier|*
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_parse_ofw_out_names
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
modifier|*
name|out_names
parameter_list|,
name|uint32_t
modifier|*
modifier|*
name|indices
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clk_parse_ofw_clk_name
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_EXTRES_CLK_H_ */
end_comment

end_unit

