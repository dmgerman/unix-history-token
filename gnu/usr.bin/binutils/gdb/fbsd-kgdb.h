begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-kernel debugging definitions for FreeBSD.  * $FreeBSD$   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FBSD_KGDB_H
end_ifndef

begin_define
define|#
directive|define
name|FBSD_KGDB_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kernel_writablecore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|target_so_ops
name|kgdb_so_ops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ADDITIONAL_OPTIONS
define|\
value|{"kernel", no_argument,&kernel_debugging, 1}, \        {"k", no_argument,&kernel_debugging, 1}, \        {"wcore", no_argument,&kernel_writablecore, 1}, \        {"w", no_argument,&kernel_writablecore, 1},
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_OPTION_HELP
define|\
value|"\   --kernel           Enable kernel debugging.\n\   --wcore            Make core file writable (only works for /dev/mem).\n\                      This option only works while debugging a kernel !!\n\ "
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROMPT
value|kernel_debugging?"(kgdb) ":"(gdb) "
end_define

begin_comment
comment|/* misuse START_PROGRESS to test whether we're running as kgdb */
end_comment

begin_comment
comment|/* START_PROGRESS is called at the top of main */
end_comment

begin_undef
undef|#
directive|undef
name|START_PROGRESS
end_undef

begin_define
define|#
directive|define
name|START_PROGRESS
parameter_list|(
name|STR
parameter_list|,
name|N
parameter_list|)
define|\
value|if (!strcmp (STR, "kgdb")) \      kernel_debugging = 1;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FBSD_KGDB_H */
end_comment

end_unit

