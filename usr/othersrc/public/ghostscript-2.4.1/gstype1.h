begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gstype1.h */
end_comment

begin_comment
comment|/* Client interface to Adobe Type 1 font routines for Ghostscript library */
end_comment

begin_comment
comment|/* Encrypt/decrypt procedures */
end_comment

begin_typedef
typedef|typedef
name|ushort
name|crypt_state
typedef|;
end_typedef

begin_define
define|#
directive|define
name|crypt_charstring_seed
value|4330
end_define

begin_decl_stmt
name|int
name|gs_type1_encrypt
argument_list|(
name|P4
argument_list|(
argument|byte *dest
argument_list|,
argument|byte *src
argument_list|,
argument|uint len
argument_list|,
argument|crypt_state *pstate
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_type1_decrypt
argument_list|(
name|P4
argument_list|(
argument|byte *dest
argument_list|,
argument|byte *src
argument_list|,
argument|uint len
argument_list|,
argument|crypt_state *pstate
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CharString interpreter */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_type1_state_s
name|gs_type1_state
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gs_type1_state_sizeof
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|gs_show_enum_s_DEFINED
end_ifndef

begin_struct_decl
struct_decl|struct
name|gs_show_enum_s
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|gs_type1_data_s_DEFINED
end_ifndef

begin_struct_decl
struct_decl|struct
name|gs_type1_data_s
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|gs_type1_init
argument_list|(
name|P5
argument_list|(
argument|gs_type1_state *pis
argument_list|,
argument|struct gs_show_enum_s *penum
argument_list|,
argument|int charpath_flag
argument_list|,
argument|int paint_type
argument_list|,
argument|struct gs_type1_data_s *pdata
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Continue interpreting a Type 1 CharString. */
end_comment

begin_comment
comment|/* If str != 0, it is taken as the byte string to interpret. */
end_comment

begin_comment
comment|/* Return 0 on successful completion,<0 on error, */
end_comment

begin_comment
comment|/* or>0 when client intervention is required. */
end_comment

begin_comment
comment|/* The int * argument is where the character is stored for seac, */
end_comment

begin_comment
comment|/* or the othersubr # for callothersubr. */
end_comment

begin_define
define|#
directive|define
name|type1_result_seac
value|1
end_define

begin_define
define|#
directive|define
name|type1_result_callothersubr
value|2
end_define

begin_decl_stmt
name|int
name|gs_type1_interpret
argument_list|(
name|P3
argument_list|(
name|gs_type1_state
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|int
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop a (fixed) number off the internal stack */
end_comment

begin_decl_stmt
name|int
name|gs_type1_pop
argument_list|(
name|P2
argument_list|(
name|gs_type1_state
operator|*
argument_list|,
name|fixed
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

