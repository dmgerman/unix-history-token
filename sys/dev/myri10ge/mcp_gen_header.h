begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2006, Myricom Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Myricom Inc, nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$ ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_mcp_gen_header_h
end_ifndef

begin_define
define|#
directive|define
name|_mcp_gen_header_h
end_define

begin_comment
comment|/* this file define a standard header used as a first entry point to    exchange information between firmware/driver and driver.  The    header structure can be anywhere in the mcp. It will usually be in    the .data section, because some fields needs to be initialized at    compile time.    The 32bit word at offset MX_HEADER_PTR_OFFSET in the mcp must    contains the location of the header.      Typically a MCP will start with the following:    .text      .space 52    ! to help catch MEMORY_INT errors      bt start     ! jump to real code      nop      .long _gen_mcp_header        The source will have a definition like:     mcp_gen_header_t gen_mcp_header = {       .header_length = sizeof(mcp_gen_header_t),       .mcp_type = MCP_TYPE_XXX,       .version = "something $Id: mcp_gen_header.h,v 1.1 2005/12/23 02:10:44 gallatin Exp $",       .mcp_globals = (unsigned)&Globals    }; */
end_comment

begin_define
define|#
directive|define
name|MCP_HEADER_PTR_OFFSET
value|0x3c
end_define

begin_define
define|#
directive|define
name|MCP_TYPE_MX
value|0x4d582020
end_define

begin_comment
comment|/* "MX  " */
end_comment

begin_define
define|#
directive|define
name|MCP_TYPE_PCIE
value|0x70636965
end_define

begin_comment
comment|/* "PCIE" pcie-only MCP */
end_comment

begin_define
define|#
directive|define
name|MCP_TYPE_ETH
value|0x45544820
end_define

begin_comment
comment|/* "ETH " */
end_comment

begin_define
define|#
directive|define
name|MCP_TYPE_MCP0
value|0x4d435030
end_define

begin_comment
comment|/* "MCP0" */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mcp_gen_header
block|{
comment|/* the first 4 fields are filled at compile time */
name|unsigned
name|header_length
decl_stmt|;
name|unsigned
name|mcp_type
decl_stmt|;
name|char
name|version
index|[
literal|128
index|]
decl_stmt|;
name|unsigned
name|mcp_globals
decl_stmt|;
comment|/* pointer to mcp-type specific structure */
comment|/* filled by the MCP at run-time */
name|unsigned
name|sram_size
decl_stmt|;
name|unsigned
name|string_specs
decl_stmt|;
comment|/* either the original STRING_SPECS or a superset */
name|unsigned
name|string_specs_len
decl_stmt|;
comment|/* Fields above this comment are guaranteed to be present.       Fields below this comment are extensions added in later versions      of this struct, drivers should compare the header_length against      offsetof(field) to check wether a given MCP implements them.       Never remove any field.  Keep everything naturally align.   */
block|}
name|mcp_gen_header_t
typedef|;
end_typedef

begin_comment
comment|/* Macro to create a simple mcp header */
end_comment

begin_define
define|#
directive|define
name|MCP_GEN_HEADER_DECL
parameter_list|(
name|type
parameter_list|,
name|version_str
parameter_list|,
name|global_ptr
parameter_list|)
define|\
value|struct mcp_gen_header mcp_gen_header = {			\     sizeof (struct mcp_gen_header),				\     (type),							\     version_str,						\     (global_ptr),						\     SRAM_SIZE,							\     (unsigned int) STRING_SPECS,				\     256								\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _mcp_gen_header_h */
end_comment

end_unit

