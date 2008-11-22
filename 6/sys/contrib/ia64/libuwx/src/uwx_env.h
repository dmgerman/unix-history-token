begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_include
include|#
directive|include
file|"uwx.h"
end_include

begin_define
define|#
directive|define
name|WORDSZ
value|4
end_define

begin_define
define|#
directive|define
name|DWORDSZ
value|8
end_define

begin_define
define|#
directive|define
name|BUNDLESZ
value|16
end_define

begin_define
define|#
directive|define
name|SLOTSPERBUNDLE
value|3
end_define

begin_define
define|#
directive|define
name|UNWIND_TBL_32BIT
value|0x8000000000000000LL
end_define

begin_define
define|#
directive|define
name|UNW_VER
parameter_list|(
name|x
parameter_list|)
value|((x)>> 48)
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_MASK
value|0x0000ffff00000000LL
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_EHANDLER
value|0x0000000100000000LL
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_UHANDLER
value|0x0000000200000000LL
end_define

begin_define
define|#
directive|define
name|UNW_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00000000ffffffffLL)
end_define

begin_struct_decl
struct_decl|struct
name|uwx_scoreboard
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|NSCOREBOARDS
value|8
end_define

begin_comment
comment|/* Initial allocation of scoreboards */
end_comment

begin_define
define|#
directive|define
name|NSPECIALREG
value|16
end_define

begin_comment
comment|/* Must be even, so FRs are aligned */
end_comment

begin_define
define|#
directive|define
name|NPRESERVEDGR
value|4
end_define

begin_define
define|#
directive|define
name|NPRESERVEDBR
value|5
end_define

begin_define
define|#
directive|define
name|NPRESERVEDFR
value|20
end_define

begin_struct
struct|struct
name|uwx_fpreg
block|{
name|uint64_t
name|part0
decl_stmt|;
name|uint64_t
name|part1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uwx_context
block|{
name|unsigned
name|int
name|valid_regs
decl_stmt|;
name|unsigned
name|int
name|valid_frs
decl_stmt|;
name|uint64_t
name|special
index|[
name|NSPECIALREG
index|]
decl_stmt|;
name|uint64_t
name|gr
index|[
name|NPRESERVEDGR
index|]
decl_stmt|;
name|uint64_t
name|br
index|[
name|NPRESERVEDBR
index|]
decl_stmt|;
name|struct
name|uwx_fpreg
name|fr
index|[
name|NPRESERVEDFR
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VALID_GR_SHIFT
value|NSPECIALREG
end_define

begin_define
define|#
directive|define
name|VALID_BR_SHIFT
value|(NSPECIALREG + NPRESERVEDGR)
end_define

begin_define
define|#
directive|define
name|VALID_BASIC4
value|0x0f
end_define

begin_comment
comment|/* IP, SP, BSP, CFM */
end_comment

begin_define
define|#
directive|define
name|VALID_MARKERS
value|0x70
end_define

begin_comment
comment|/* RP, PSP, PFS */
end_comment

begin_struct
struct|struct
name|uwx_history
block|{
name|uint64_t
name|special
index|[
name|NSPECIALREG
index|]
decl_stmt|;
name|uint64_t
name|gr
index|[
name|NPRESERVEDGR
index|]
decl_stmt|;
name|uint64_t
name|br
index|[
name|NPRESERVEDBR
index|]
decl_stmt|;
name|uint64_t
name|fr
index|[
name|NPRESERVEDFR
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|uwx_str_pool
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|uwx_env
block|{
name|struct
name|uwx_context
name|context
decl_stmt|;
name|uint64_t
modifier|*
name|rstate
decl_stmt|;
name|uint64_t
name|remapped_ip
decl_stmt|;
name|int64_t
name|function_offset
decl_stmt|;
name|struct
name|uwx_history
name|history
decl_stmt|;
name|alloc_cb
name|allocate_cb
decl_stmt|;
name|free_cb
name|free_cb
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|free_scoreboards
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|used_scoreboards
decl_stmt|;
name|struct
name|uwx_scoreboard
modifier|*
name|labeled_scoreboards
decl_stmt|;
name|struct
name|uwx_str_pool
modifier|*
name|string_pool
decl_stmt|;
name|char
modifier|*
name|module_name
decl_stmt|;
name|char
modifier|*
name|function_name
decl_stmt|;
name|intptr_t
name|cb_token
decl_stmt|;
name|copyin_cb
name|copyin
decl_stmt|;
name|lookupip_cb
name|lookupip
decl_stmt|;
name|int
name|remote
decl_stmt|;
name|int
name|byte_swap
decl_stmt|;
name|int
name|abi_context
decl_stmt|;
name|int
name|nsbreg
decl_stmt|;
name|int
name|nscoreboards
decl_stmt|;
name|int
name|trace
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|alloc_cb
name|uwx_allocate_cb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|free_cb
name|uwx_free_cb
decl_stmt|;
end_decl_stmt

end_unit

