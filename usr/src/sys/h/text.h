begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Text structure.  * One allocated per pure  * procedure on swap device.  * Manipulated by text.c  */
end_comment

begin_struct
struct|struct
name|text
block|{
name|short
name|x_daddr
decl_stmt|;
comment|/* disk address of segment (relative to swplo) */
name|short
name|x_size
decl_stmt|;
comment|/* size (clicks) */
name|struct
name|proc
modifier|*
name|x_caddr
decl_stmt|;
comment|/* ptr to linked proc, if loaded */
name|struct
name|inode
modifier|*
name|x_iptr
decl_stmt|;
comment|/* inode of prototype */
name|char
name|x_count
decl_stmt|;
comment|/* reference count */
name|char
name|x_ccount
decl_stmt|;
comment|/* number of loaded references */
name|char
name|x_flag
decl_stmt|;
comment|/* traced, written flags */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|text
name|text
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XTRC
value|01
end_define

begin_comment
comment|/* Text may be written, exclusive use */
end_comment

begin_define
define|#
directive|define
name|XWRIT
value|02
end_define

begin_comment
comment|/* Text written into, must swap out */
end_comment

begin_define
define|#
directive|define
name|XLOAD
value|04
end_define

begin_comment
comment|/* Currently being read from file */
end_comment

begin_define
define|#
directive|define
name|XLOCK
value|010
end_define

begin_comment
comment|/* Being swapped in or out */
end_comment

begin_define
define|#
directive|define
name|XWANT
value|020
end_define

begin_comment
comment|/* Wanted for swapping */
end_comment

end_unit

