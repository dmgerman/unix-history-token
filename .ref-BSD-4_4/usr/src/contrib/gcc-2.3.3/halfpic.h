begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OSF/rose half-pic support definitions.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_half_pic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global half-pic flag.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|half_pic_number_ptrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # distinct pointers found */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|half_pic_number_refs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # half-pic references */
end_comment

begin_function_decl
specifier|extern
name|void
name|half_pic_encode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* encode whether half-pic */
end_comment

begin_function_decl
specifier|extern
name|void
name|half_pic_declare
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* declare object local */
end_comment

begin_function_decl
specifier|extern
name|void
name|half_pic_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* half_pic initialization */
end_comment

begin_function_decl
specifier|extern
name|void
name|half_pic_finish
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* half_pic termination */
end_comment

begin_function_decl
specifier|extern
name|int
name|half_pic_address_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* true if an address is half-pic */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|half_pic_ptr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return RTX for half-pic pointer */
end_comment

begin_comment
comment|/* Macros to provide access to the half-pic stuff (so they can easily    be stubbed out.  */
end_comment

begin_define
define|#
directive|define
name|HALF_PIC_P
parameter_list|()
value|(flag_half_pic)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_NUMBER_PTRS
value|(half_pic_number_ptrs)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_NUMBER_REFS
value|(half_pic_number_refs)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_ENCODE
parameter_list|(
name|DECL
parameter_list|)
value|half_pic_encode (DECL)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_DECLARE
parameter_list|(
name|NAME
parameter_list|)
value|half_pic_declare (NAME)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_INIT
parameter_list|()
value|half_pic_init ()
end_define

begin_define
define|#
directive|define
name|HALF_PIC_FINISH
parameter_list|(
name|STREAM
parameter_list|)
value|half_pic_finish (STREAM)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|half_pic_address_p (X)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_PTR
parameter_list|(
name|X
parameter_list|)
value|half_pic_ptr (X)
end_define

begin_comment
comment|/* Prefix for half-pic names */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HALF_PIC_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|HALF_PIC_PREFIX
value|"__pic_"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

