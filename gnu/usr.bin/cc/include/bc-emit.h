begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bc-emit.h - declare entry points for producing object files of bytecodes. */
end_comment

begin_comment
comment|/* Internal format of symbol table for the object file. */
end_comment

begin_struct
struct|struct
name|bc_sym
block|{
comment|/* Private copy separately malloc'd. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Symbol has a defined value. */
name|unsigned
name|int
name|defined
range|:
literal|1
decl_stmt|;
comment|/* Symbol has been globalized. */
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
comment|/* Symbol is common. */
name|unsigned
name|int
name|common
range|:
literal|1
decl_stmt|;
comment|/* Value if defined. */
name|unsigned
name|long
name|int
name|val
decl_stmt|;
comment|/* Used in internal symbol table structure. */
name|struct
name|bc_sym
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* List of symbols defined in a particular segment. */
end_comment

begin_struct
struct|struct
name|bc_segsym
block|{
name|struct
name|bc_sym
modifier|*
name|sym
decl_stmt|;
name|struct
name|bc_segsym
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* List of relocations needed in a particular segment. */
end_comment

begin_struct
struct|struct
name|bc_segreloc
block|{
comment|/* Offset of datum to be relocated. */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* Symbol to be relocated by. */
name|struct
name|bc_sym
modifier|*
name|sym
decl_stmt|;
name|struct
name|bc_segreloc
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Segment of an object file. */
end_comment

begin_struct
struct|struct
name|bc_seg
block|{
comment|/* Size allocated to contents. */
name|unsigned
name|int
name|alloc
decl_stmt|;
comment|/* Pointer to base of contents. */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Actual size of contents. */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* List of symbols defined in this segment. */
name|struct
name|bc_segsym
modifier|*
name|syms
decl_stmt|;
comment|/* List of relocations for this segment. */
name|struct
name|bc_segreloc
modifier|*
name|relocs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Anonymous bytecode label within a single function. */
end_comment

begin_struct
struct|struct
name|bc_label
block|{
comment|/* Offset of label from start of segment. */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* True when offset is valid. */
name|unsigned
name|int
name|defined
range|:
literal|1
decl_stmt|;
comment|/* Unique bytecode ID, used to determine innermost      block containment */
name|int
name|uid
decl_stmt|;
comment|/* Next node in list */
name|struct
name|bc_label
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Reference to a bc_label; a list of all such references is kept for    the function, then when it is finished they are backpatched to    contain the correct values. */
end_comment

begin_struct
struct|struct
name|bc_labelref
block|{
comment|/* Label referenced. */
name|struct
name|bc_label
modifier|*
name|label
decl_stmt|;
comment|/* Code offset of reference. */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* Next labelref in list */
name|struct
name|bc_labelref
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_function_decl
specifier|extern
name|void
name|bc_initialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_begin_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|bc_emit_trampoline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_bytecode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_bytecode_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|bc_label
modifier|*
name|bc_get_bytecode_label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_emit_bytecode_labeldef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_bytecode_labelref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_code_labelref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|bc_end_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_align_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_const_skip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_emit_const_labeldef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_const_labelref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_align_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_data_skip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_emit_data_labeldef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_data_labelref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_define_pointer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_emit_common
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_globalize_label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_align
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_skip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bc_emit_labeldef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_emit_labelref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bc_write_file
parameter_list|()
function_decl|;
end_function_decl

end_unit

