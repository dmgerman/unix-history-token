begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GCC core type declarations.    Copyright (C) 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Provide forward declarations of core types which are referred to by    most of the compiler.  This allows header files to use these types    (e.g. in function prototypes) without concern for whether the full    definitions are visible.  Some other declarations that need to be    universally visible are here, too.     In the context of tconfig.h, most of these have special definitions    which prevent them from being used except in further type    declarations.  This is a kludge; the right thing is to avoid    including the "tm.h" header set in the context of tconfig.h, but    we're not there yet.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CORETYPES_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CORETYPES_H
end_define

begin_define
define|#
directive|define
name|GTY
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* nothing - marker for gengtype */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USED_FOR_TARGET
end_ifndef

begin_struct_decl
struct_decl|struct
name|rtx_def
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|rtx_def
modifier|*
name|rtx
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|rtvec_def
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|rtvec_def
modifier|*
name|rtvec
typedef|;
end_typedef

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
name|union
name|tree_node
modifier|*
name|tree
typedef|;
end_typedef

begin_comment
comment|/* Provide forward struct declaration so that we don't have to include    all of cpplib.h whenever a random prototype includes a pointer.    Note that the cpp_reader typedef remains part of cpplib.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cpp_reader
struct_decl|;
end_struct_decl

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|_dont_use_rtx_here_
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_dont_use_rtvec_here_
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|_dont_use_tree_here_
union_decl|;
end_union_decl

begin_define
define|#
directive|define
name|rtx
value|struct _dont_use_rtx_here_ *
end_define

begin_define
define|#
directive|define
name|rtvec
value|struct _dont_use_rtvec_here *
end_define

begin_define
define|#
directive|define
name|tree
value|union _dont_use_tree_here_ *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* coretypes.h */
end_comment

end_unit

