begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for decoding the picoJava opcode table.    Copyright 1999, 2002, 2003 Free Software Foundation, Inc.    Contributed by Steve Chamberlain of Transmeta (sac@pobox.com).  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Names used to describe the type of instruction arguments, used by    the assembler and disassembler.  Attributes are encoded in various fields. */
end_comment

begin_comment
comment|/*            reloc  size pcrel    uns */
end_comment

begin_define
define|#
directive|define
name|O_N
value|0
end_define

begin_define
define|#
directive|define
name|O_16
value|(1<<4 | 2 | (0<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|O_U16
value|(1<<4 | 2 | (0<<6) | (1<<3))
end_define

begin_define
define|#
directive|define
name|O_R16
value|(2<<4 | 2 | (1<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|O_8
value|(3<<4 | 1 | (0<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|O_U8
value|(3<<4 | 1 | (0<<6) | (1<<3))
end_define

begin_define
define|#
directive|define
name|O_R8
value|(4<<4 | 1 | (0<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|O_R32
value|(5<<4 | 4 | (1<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|O_32
value|(6<<4 | 4 | (0<<6) | (0<<3))
end_define

begin_define
define|#
directive|define
name|ASIZE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_define
define|#
directive|define
name|PCREL
parameter_list|(
name|x
parameter_list|)
value|(!!((x)& (1<<6)))
end_define

begin_define
define|#
directive|define
name|UNS
parameter_list|(
name|x
parameter_list|)
value|(!!((x)& (1<<3)))
end_define

begin_typedef
typedef|typedef
struct|struct
name|pj_opc_info_t
block|{
name|short
name|opcode
decl_stmt|;
name|short
name|opcode_next
decl_stmt|;
name|char
name|len
decl_stmt|;
name|unsigned
name|char
name|arg
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|pj_opc_info_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
name|u
union|;
block|}
name|pj_opc_info_t
typedef|;
end_typedef

end_unit

