begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_FDT_H
end_ifndef

begin_define
define|#
directive|define
name|_FDT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|fdt_header
block|{
name|uint32_t
name|magic
decl_stmt|;
comment|/* magic word FDT_MAGIC */
name|uint32_t
name|totalsize
decl_stmt|;
comment|/* total size of DT block */
name|uint32_t
name|off_dt_struct
decl_stmt|;
comment|/* offset to structure */
name|uint32_t
name|off_dt_strings
decl_stmt|;
comment|/* offset to strings */
name|uint32_t
name|off_mem_rsvmap
decl_stmt|;
comment|/* offset to memory reserve map */
name|uint32_t
name|version
decl_stmt|;
comment|/* format version */
name|uint32_t
name|last_comp_version
decl_stmt|;
comment|/* last compatible version */
comment|/* version 2 fields below */
name|uint32_t
name|boot_cpuid_phys
decl_stmt|;
comment|/* Which physical CPU id we're 					    booting on */
comment|/* version 3 fields below */
name|uint32_t
name|size_dt_strings
decl_stmt|;
comment|/* size of the strings block */
comment|/* version 17 fields below */
name|uint32_t
name|size_dt_struct
decl_stmt|;
comment|/* size of the structure block */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_reserve_entry
block|{
name|uint64_t
name|address
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_node_header
block|{
name|uint32_t
name|tag
decl_stmt|;
name|char
name|name
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdt_property
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|nameoff
decl_stmt|;
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY */
end_comment

begin_define
define|#
directive|define
name|FDT_MAGIC
value|0xd00dfeed
end_define

begin_comment
comment|/* 4: version, 4: total size */
end_comment

begin_define
define|#
directive|define
name|FDT_TAGSIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|FDT_BEGIN_NODE
value|0x1
end_define

begin_comment
comment|/* Start node: full name */
end_comment

begin_define
define|#
directive|define
name|FDT_END_NODE
value|0x2
end_define

begin_comment
comment|/* End node */
end_comment

begin_define
define|#
directive|define
name|FDT_PROP
value|0x3
end_define

begin_comment
comment|/* Property: name off, 					   size, content */
end_comment

begin_define
define|#
directive|define
name|FDT_NOP
value|0x4
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|FDT_END
value|0x9
end_define

begin_define
define|#
directive|define
name|FDT_V1_SIZE
value|(7*sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V2_SIZE
value|(FDT_V1_SIZE + sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V3_SIZE
value|(FDT_V2_SIZE + sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|FDT_V16_SIZE
value|FDT_V3_SIZE
end_define

begin_define
define|#
directive|define
name|FDT_V17_SIZE
value|(FDT_V16_SIZE + sizeof(uint32_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FDT_H */
end_comment

end_unit

