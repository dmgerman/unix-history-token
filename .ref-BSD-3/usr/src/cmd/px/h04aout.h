begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Format of an a.out header  */
end_comment

begin_struct
struct|struct
name|exec
block|{
comment|/* a.out header */
name|int
name|a_magic
decl_stmt|;
comment|/* magic number */
name|unsigned
name|a_text
decl_stmt|;
comment|/* size of text segment */
name|unsigned
name|a_data
decl_stmt|;
comment|/* size of initialized data */
name|unsigned
name|a_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|unsigned
name|a_syms
decl_stmt|;
comment|/* size of symbol table */
name|unsigned
name|a_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|a_trsize
decl_stmt|;
comment|/* size of text relocation */
name|unsigned
name|a_drsize
decl_stmt|;
comment|/* size of data relocation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|A_MAGIC1
value|0407
end_define

begin_comment
comment|/* normal */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC2
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC3
value|0411
end_define

begin_comment
comment|/* separated I&D */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC4
value|0405
end_define

begin_comment
comment|/* overlay */
end_comment

end_unit

