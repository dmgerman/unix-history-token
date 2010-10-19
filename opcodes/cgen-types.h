begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Type definitions for CGEN-based opcode libraries.    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Red Hat.  This file is part of the GNU opcodes library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|CGEN_TYPES_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
name|int8_t
name|QI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|UQI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|HI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|UHI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|SI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|USI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|DI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|UDI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|SF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|DF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|double
name|XF
typedef|,
name|TF
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CGEN_TYPES_H */
end_comment

end_unit

