begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Memory range attribute operations, peformed on /dev/mem  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Memory range attributes */
end_comment

begin_define
define|#
directive|define
name|MDF_UNCACHEABLE
value|(1<<0)
end_define

begin_comment
comment|/* region not cached */
end_comment

begin_define
define|#
directive|define
name|MDF_WRITECOMBINE
value|(1<<1)
end_define

begin_comment
comment|/* region supports "write combine" action */
end_comment

begin_define
define|#
directive|define
name|MDF_WRITETHROUGH
value|(1<<2)
end_define

begin_comment
comment|/* write-through cached */
end_comment

begin_define
define|#
directive|define
name|MDF_WRITEBACK
value|(1<<3)
end_define

begin_comment
comment|/* write-back cached */
end_comment

begin_define
define|#
directive|define
name|MDF_WRITEPROTECT
value|(1<<4)
end_define

begin_comment
comment|/* read-only region */
end_comment

begin_define
define|#
directive|define
name|MDF_ATTRMASK
value|(0x00ffffff)
end_define

begin_define
define|#
directive|define
name|MDF_FIXBASE
value|(1<<24)
end_define

begin_comment
comment|/* fixed base */
end_comment

begin_define
define|#
directive|define
name|MDF_FIXLEN
value|(1<<25)
end_define

begin_comment
comment|/* fixed length */
end_comment

begin_define
define|#
directive|define
name|MDF_FIRMWARE
value|(1<<26)
end_define

begin_comment
comment|/* set by firmware (XXX not useful?) */
end_comment

begin_define
define|#
directive|define
name|MDF_ACTIVE
value|(1<<27)
end_define

begin_comment
comment|/* currently active */
end_comment

begin_define
define|#
directive|define
name|MDF_BOGUS
value|(1<<28)
end_define

begin_comment
comment|/* we don't like it */
end_comment

begin_define
define|#
directive|define
name|MDF_FIXACTIVE
value|(1<<29)
end_define

begin_comment
comment|/* can't be turned off */
end_comment

begin_define
define|#
directive|define
name|MDF_BUSY
value|(1<<30)
end_define

begin_comment
comment|/* range is in use */
end_comment

begin_struct
struct|struct
name|mem_range_desc
block|{
name|u_int64_t
name|mr_base
decl_stmt|;
name|u_int64_t
name|mr_len
decl_stmt|;
name|int
name|mr_flags
decl_stmt|;
name|char
name|mr_owner
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mem_range_op
block|{
name|struct
name|mem_range_desc
modifier|*
name|mo_desc
decl_stmt|;
name|int
name|mo_arg
index|[
literal|2
index|]
decl_stmt|;
define|#
directive|define
name|MEMRANGE_SET_UPDATE
value|0
define|#
directive|define
name|MEMRANGE_SET_REMOVE
value|1
comment|/* XXX want a flag that says "set and undo when I exit" */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MEMRANGE_GET
value|_IOWR('m', 50, struct mem_range_op)
end_define

begin_define
define|#
directive|define
name|MEMRANGE_SET
value|_IOW('m', 51, struct mem_range_op)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MEMDESC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|mem_range_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mem_range_ops
block|{
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|mem_range_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set
function_decl|)
parameter_list|(
name|struct
name|mem_range_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mem_range_desc
modifier|*
name|mrd
parameter_list|,
name|int
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|initAP
function_decl|)
parameter_list|(
name|struct
name|mem_range_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mem_range_softc
block|{
name|struct
name|mem_range_ops
modifier|*
name|mr_op
decl_stmt|;
name|int
name|mr_cap
decl_stmt|;
name|int
name|mr_ndesc
decl_stmt|;
name|struct
name|mem_range_desc
modifier|*
name|mr_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mem_range_softc
name|mem_range_softc
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|mem_range_attr_get
parameter_list|(
name|struct
name|mem_range_desc
modifier|*
name|mrd
parameter_list|,
name|int
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mem_range_attr_set
parameter_list|(
name|struct
name|mem_range_desc
modifier|*
name|mrd
parameter_list|,
name|int
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mem_range_AP_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

