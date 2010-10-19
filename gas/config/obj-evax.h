begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is obj-evax.h    Copyright 1996, 2000, 2005 Free Software Foundation, Inc.    Contributed by Klaus Kämpf (kkaempf@progis.de) of      proGIS Software, Aachen, Germany.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  * This file is obj-evax.h and is intended to be a template for  * object format specific header files.  */
end_comment

begin_comment
comment|/* define an obj specific macro off which target cpu back ends may key.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_EVAX
value|1
end_define

begin_comment
comment|/* include whatever target cpu is appropriate.  */
end_comment

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_evax_flavour
end_define

begin_comment
comment|/*  * SYMBOLS  */
end_comment

begin_comment
comment|/*  * If your object format needs to reorder symbols, define this.  When  * defined, symbols are kept on a doubly linked list and functions are  * made available for push, insert, append, and delete.  If not defined,  * symbols are kept on a singly linked list, only the append and clear  * facilities are available, and they are macros.  */
end_comment

begin_comment
comment|/* #define SYMBOLS_NEED_PACKPOINTERS */
end_comment

begin_comment
comment|/*  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|nothing
decl_stmt|;
block|}
name|obj_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* should be the format's symbol structure */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|object_headers
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OBJ_EMIT_LINENO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_comment
comment|/* must be *something*.  This no-op's it out.  */
end_comment

begin_define
define|#
directive|define
name|obj_symbol_new_hook
parameter_list|(
name|s
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|S_SET_OTHER
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|)
end_define

begin_define
define|#
directive|define
name|S_SET_TYPE
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|S_SET_DESC
parameter_list|(
name|S
parameter_list|,
name|D
parameter_list|)
end_define

begin_define
define|#
directive|define
name|S_GET_OTHER
parameter_list|(
name|S
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|S_GET_TYPE
parameter_list|(
name|S
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|S_GET_DESC
parameter_list|(
name|S
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_KIND_FP_STACK
value|9
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_KIND_FP_REGISTER
value|10
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_KIND_NULL
value|8
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_MIN_STACK_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_MIN_REGISTER_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|PDSC_S_K_NULL_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|PDSC_S_M_BASE_REG_IS_FP
value|0x80
end_define

begin_comment
comment|/* low byte */
end_comment

begin_define
define|#
directive|define
name|PDSC_S_M_NATIVE
value|0x10
end_define

begin_comment
comment|/* high byte */
end_comment

begin_define
define|#
directive|define
name|PDSC_S_M_NO_JACKET
value|0x20
end_define

begin_comment
comment|/* high byte */
end_comment

begin_define
define|#
directive|define
name|LKP_S_K_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|TC_IMPLICIT_LCOMM_ALIGNMENT
parameter_list|(
name|SIZE
parameter_list|,
name|P2VAR
parameter_list|)
value|(P2VAR) = 3
end_define

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

end_unit

