begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XMODEM support for GDB, the GNU debugger.    Copyright 1995, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|serial
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|xmodem_init_xfer
parameter_list|(
name|struct
name|serial
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_xmodem_packet
parameter_list|(
name|struct
name|serial
modifier|*
name|desc
parameter_list|,
name|unsigned
name|char
modifier|*
name|packet
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|hashmark
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xmodem_finish_xfer
parameter_list|(
name|struct
name|serial
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XMODEM_DATASIZE
value|128
end_define

begin_comment
comment|/* The data size is ALWAYS 128 */
end_comment

begin_define
define|#
directive|define
name|XMODEM_1KDATASIZE
value|1024
end_define

begin_comment
comment|/* Unless it's 1024!!! */
end_comment

begin_define
define|#
directive|define
name|XMODEM_PACKETSIZE
value|133
end_define

begin_comment
comment|/* data + packet headers and crc */
end_comment

begin_define
define|#
directive|define
name|XMODEM_1KPACKETSIZE
value|1024 + 5
end_define

begin_comment
comment|/* data + packet headers and crc */
end_comment

begin_define
define|#
directive|define
name|XMODEM_DATAOFFSET
value|3
end_define

begin_comment
comment|/* Offset to start of actual data */
end_comment

end_unit

