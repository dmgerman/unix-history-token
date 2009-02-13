begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_KGDB_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_KGDB_H__
end_define

begin_define
define|#
directive|define
name|KDB_ARGCOUNT
value|EINVAL
end_define

begin_struct
struct|struct
name|pt_regs
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MODULE_AUTHOR
parameter_list|(
name|s
parameter_list|)
value|static char __module_author[] = s;
end_define

begin_define
define|#
directive|define
name|MODULE_DESCRIPTION
parameter_list|(
name|s
parameter_list|)
value|static char __module_description[] = s;
end_define

begin_define
define|#
directive|define
name|MODULE_LICENSE
parameter_list|(
name|s
parameter_list|)
value|static char __module_license[] = s
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kdb_func_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|pt_regs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|register_t
name|kdb_machreg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Symbol table format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__ksymtab
block|{
name|unsigned
name|long
name|value
decl_stmt|;
comment|/* Address of symbol */
specifier|const
name|char
modifier|*
name|sym_name
decl_stmt|;
comment|/* Full symbol name, including any version */
name|unsigned
name|long
name|sym_start
decl_stmt|;
name|unsigned
name|long
name|sym_end
decl_stmt|;
block|}
name|kdb_symtab_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|kdb_register
parameter_list|(
name|char
modifier|*
parameter_list|,
name|kdb_func_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kdb_unregister
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kdbgetaddrarg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|kdb_machreg_t
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|pt_regs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kdbnearsym
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|kdb_symtab_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdb_printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|kdb_getarea_size
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kdb_putarea_size
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|kdb_getarea
parameter_list|(
name|x
parameter_list|,
name|addr
parameter_list|)
value|kdb_getarea_size(&(x), addr, sizeof((x)))
end_define

begin_define
define|#
directive|define
name|kdb_putarea
parameter_list|(
name|addr
parameter_list|,
name|x
parameter_list|)
value|kdb_putarea_size(addr,&(x), sizeof((x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_KGDB_H__ */
end_comment

end_unit

