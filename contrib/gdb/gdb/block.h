begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Code dealing with blocks for GDB.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|BLOCK_H
end_define

begin_comment
comment|/* Opaque declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symtab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block_namespace_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|using_direct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dictionary
struct_decl|;
end_struct_decl

begin_comment
comment|/* All of the name-scope contours of the program    are represented by `struct block' objects.    All of these objects are pointed to by the blockvector.     Each block represents one name scope.    Each lexical context has its own block.     The blockvector begins with some special blocks.    The GLOBAL_BLOCK contains all the symbols defined in this compilation    whose scope is the entire program linked together.    The STATIC_BLOCK contains all the symbols whose scope is the    entire compilation excluding other separate compilations.    Blocks starting with the FIRST_LOCAL_BLOCK are not special.     Each block records a range of core addresses for the code that    is in the scope of the block.  The STATIC_BLOCK and GLOBAL_BLOCK    give, for the range of code, the entire range of code produced    by the compilation that the symbol segment belongs to.     The blocks appear in the blockvector    in order of increasing starting-address,    and, within that, in order of decreasing ending-address.     This implies that within the body of one function    the blocks appear in the order of a depth-first tree walk.  */
end_comment

begin_struct
struct|struct
name|block
block|{
comment|/* Addresses in the executable code that are in this block.  */
name|CORE_ADDR
name|startaddr
decl_stmt|;
name|CORE_ADDR
name|endaddr
decl_stmt|;
comment|/* The symbol that names this block, if the block is the body of a      function; otherwise, zero.  */
name|struct
name|symbol
modifier|*
name|function
decl_stmt|;
comment|/* The `struct block' for the containing block, or 0 if none.       The superblock of a top-level local block (i.e. a function in the      case of C) is the STATIC_BLOCK.  The superblock of the      STATIC_BLOCK is the GLOBAL_BLOCK.  */
name|struct
name|block
modifier|*
name|superblock
decl_stmt|;
comment|/* This is used to store the symbols in the block.  */
name|struct
name|dictionary
modifier|*
name|dict
decl_stmt|;
comment|/* Used for language-specific info.  */
union|union
block|{
struct|struct
block|{
comment|/* Contains information about namespace-related info relevant to 	 this block: using directives and the current namespace 	 scope.  */
name|struct
name|block_namespace_info
modifier|*
name|namespace
decl_stmt|;
block|}
name|cplus_specific
struct|;
block|}
name|language_specific
union|;
comment|/* Version of GCC used to compile the function corresponding      to this block, or 0 if not compiled with GCC.  When possible,      GCC should be compatible with the native compiler, or if that      is not feasible, the differences should be fixed during symbol      reading.  As of 16 Apr 93, this flag is never used to distinguish      between gcc2 and the native compiler.       If there is no function corresponding to this block, this meaning      of this flag is undefined.  */
name|unsigned
name|char
name|gcc_compile_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLOCK_START
parameter_list|(
name|bl
parameter_list|)
value|(bl)->startaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_END
parameter_list|(
name|bl
parameter_list|)
value|(bl)->endaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_FUNCTION
parameter_list|(
name|bl
parameter_list|)
value|(bl)->function
end_define

begin_define
define|#
directive|define
name|BLOCK_SUPERBLOCK
parameter_list|(
name|bl
parameter_list|)
value|(bl)->superblock
end_define

begin_define
define|#
directive|define
name|BLOCK_GCC_COMPILED
parameter_list|(
name|bl
parameter_list|)
value|(bl)->gcc_compile_flag
end_define

begin_define
define|#
directive|define
name|BLOCK_DICT
parameter_list|(
name|bl
parameter_list|)
value|(bl)->dict
end_define

begin_define
define|#
directive|define
name|BLOCK_NAMESPACE
parameter_list|(
name|bl
parameter_list|)
value|(bl)->language_specific.cplus_specific.namespace
end_define

begin_comment
comment|/* Macro to loop through all symbols in a block BL, in no particular    order.  ITER helps keep track of the iteration, and should be a    struct dict_iterator.  SYM points to the current symbol.  */
end_comment

begin_define
define|#
directive|define
name|ALL_BLOCK_SYMBOLS
parameter_list|(
name|block
parameter_list|,
name|iter
parameter_list|,
name|sym
parameter_list|)
define|\
value|ALL_DICT_SYMBOLS (BLOCK_DICT (block), iter, sym)
end_define

begin_struct
struct|struct
name|blockvector
block|{
comment|/* Number of blocks in the list.  */
name|int
name|nblocks
decl_stmt|;
comment|/* The blocks themselves.  */
name|struct
name|block
modifier|*
name|block
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLOCKVECTOR_NBLOCKS
parameter_list|(
name|blocklist
parameter_list|)
value|(blocklist)->nblocks
end_define

begin_define
define|#
directive|define
name|BLOCKVECTOR_BLOCK
parameter_list|(
name|blocklist
parameter_list|,
name|n
parameter_list|)
value|(blocklist)->block[n]
end_define

begin_comment
comment|/* Special block numbers */
end_comment

begin_enum
enum|enum
block|{
name|GLOBAL_BLOCK
init|=
literal|0
block|,
name|STATIC_BLOCK
init|=
literal|1
block|,
name|FIRST_LOCAL_BLOCK
init|=
literal|2
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|block_function
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|contained_in
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|blockvector
modifier|*
name|blockvector_for_pc
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|blockvector
modifier|*
name|blockvector_for_pc_sect
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|block_for_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|block_for_pc_sect
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|block_scope
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|block_set_scope
parameter_list|(
name|struct
name|block
modifier|*
name|block
parameter_list|,
specifier|const
name|char
modifier|*
name|scope
parameter_list|,
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|using_direct
modifier|*
name|block_using
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|block_set_using
parameter_list|(
name|struct
name|block
modifier|*
name|block
parameter_list|,
name|struct
name|using_direct
modifier|*
name|using
parameter_list|,
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|struct
name|block
modifier|*
name|block_static_block
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|struct
name|block
modifier|*
name|block_global_block
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|allocate_block
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BLOCK_H */
end_comment

end_unit

