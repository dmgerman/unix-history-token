begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective-C Typed Streams interface.    Copyright (C) 1993, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled    with GCC to produce an executable, this does not cause the resulting    executable to be covered by the GNU General Public License.  This    exception does not however invalidate any other reasons why the    executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__typedstream_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__typedstream_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|"objc/objc.h"
end_include

begin_include
include|#
directive|include
file|"objc/hash.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|objc_typed_read_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|objc_typed_write_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|objc_typed_flush_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|objc_typed_eof_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|OBJC_READONLY
value|0x01
end_define

begin_define
define|#
directive|define
name|OBJC_WRITEONLY
value|0x02
end_define

begin_define
define|#
directive|define
name|OBJC_MANAGED_STREAM
value|0x01
end_define

begin_define
define|#
directive|define
name|OBJC_FILE_STREAM
value|0x02
end_define

begin_define
define|#
directive|define
name|OBJC_MEMORY_STREAM
value|0x04
end_define

begin_define
define|#
directive|define
name|OBJC_TYPED_STREAM_VERSION
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|objc_typed_stream
block|{
name|void
modifier|*
name|physical
decl_stmt|;
name|cache_ptr
name|object_table
decl_stmt|;
comment|/* read/written objects */
name|cache_ptr
name|stream_table
decl_stmt|;
comment|/* other read/written but shared things.. */
name|cache_ptr
name|class_table
decl_stmt|;
comment|/* class version mapping */
name|cache_ptr
name|object_refs
decl_stmt|;
comment|/* forward references */
name|int
name|mode
decl_stmt|;
comment|/* OBJC_READONLY or OBJC_WRITEONLY */
name|int
name|type
decl_stmt|;
comment|/* MANAGED, FILE, MEMORY etc bit string */
name|int
name|version
decl_stmt|;
comment|/* version used when writing */
name|int
name|writing_root_p
decl_stmt|;
name|objc_typed_read_func
name|read
decl_stmt|;
name|objc_typed_write_func
name|write
decl_stmt|;
name|objc_typed_eof_func
name|eof
decl_stmt|;
name|objc_typed_flush_func
name|flush
decl_stmt|;
block|}
name|TypedStream
typedef|;
end_typedef

begin_comment
comment|/* opcode masks */
end_comment

begin_define
define|#
directive|define
name|_B_VALUE
value|0x1fU
end_define

begin_define
define|#
directive|define
name|_B_CODE
value|0xe0U
end_define

begin_define
define|#
directive|define
name|_B_SIGN
value|0x10U
end_define

begin_define
define|#
directive|define
name|_B_NUMBER
value|0x0fU
end_define

begin_comment
comment|/* standard opcodes */
end_comment

begin_define
define|#
directive|define
name|_B_INVALID
value|0x00U
end_define

begin_define
define|#
directive|define
name|_B_SINT
value|0x20U
end_define

begin_define
define|#
directive|define
name|_B_NINT
value|0x40U
end_define

begin_define
define|#
directive|define
name|_B_SSTR
value|0x60U
end_define

begin_define
define|#
directive|define
name|_B_NSTR
value|0x80U
end_define

begin_define
define|#
directive|define
name|_B_RCOMM
value|0xa0U
end_define

begin_define
define|#
directive|define
name|_B_UCOMM
value|0xc0U
end_define

begin_define
define|#
directive|define
name|_B_EXT
value|0xe0U
end_define

begin_comment
comment|/* eXtension opcodes */
end_comment

begin_define
define|#
directive|define
name|_BX_OBJECT
value|0x00U
end_define

begin_define
define|#
directive|define
name|_BX_CLASS
value|0x01U
end_define

begin_define
define|#
directive|define
name|_BX_SEL
value|0x02U
end_define

begin_define
define|#
directive|define
name|_BX_OBJREF
value|0x03U
end_define

begin_define
define|#
directive|define
name|_BX_OBJROOT
value|0x04U
end_define

begin_define
define|#
directive|define
name|_BX_EXT
value|0x1fU
end_define

begin_comment
comment|/* ** Read and write objects as specified by TYPE.  All the `last' ** arguments are pointers to the objects to read/write.   */
end_comment

begin_function_decl
name|int
name|objc_write_type
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_read_type
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_write_types
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_read_types
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_write_object_reference
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_write_root_object
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|objc_get_stream_class_version
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
name|Class
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Convenience functions */
end_comment

begin_function_decl
name|int
name|objc_write_array
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_read_array
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|count
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_write_object
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_read_object
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|,
name|id
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Open a typed stream for reading or writing.  MODE may be either of ** OBJC_READONLY or OBJC_WRITEONLY.   */
end_comment

begin_function_decl
name|TypedStream
modifier|*
name|objc_open_typed_stream
parameter_list|(
name|FILE
modifier|*
name|physical
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypedStream
modifier|*
name|objc_open_typed_stream_for_file
parameter_list|(
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_close_typed_stream
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOL
name|objc_end_of_typed_stream
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_flush_typed_stream
parameter_list|(
name|TypedStream
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __typedstream_INCLUDE_GNU */
end_comment

end_unit

