begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Do not modify this file.  */
end_comment

begin_comment
comment|/* It is created automatically by the Makefile.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* For initialize_file_ftype.  */
end_comment

begin_include
include|#
directive|include
file|"call-cmds.h"
end_include

begin_comment
comment|/* For initialize_all_files.  */
end_comment

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gdbtypes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_rs6000_tdep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ppcfbsd_tdep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_corelow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_solib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_svr4_solib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ser_hardwire
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ser_pipe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ser_tcp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_fbsd_proc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gcore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_kernel_u_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_infptrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_inftarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ppcfbsd_nat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_thread_db
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_remote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_dcache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_sr_support
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tracepoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ax_gdb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_annotate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_auxv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_breakpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_regcache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_charset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_dummy_frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_source
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_valops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_valarith
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_valprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_printcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_symtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_symfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_symmisc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_infcall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_infcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_infrun
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_interpreter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_macrocmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gdbarch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gdbarch_utils
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gdb_osabi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_copying
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_parse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_frame_reg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_signals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_kod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gdb_events
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_maint_cmds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_demangler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_dbxread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_coffread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_elfread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mipsread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_stabsread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_core
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_dwarf2_frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_c_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_f_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_objc_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_ui_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cli_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_varobj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_java_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_m2_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_pascal_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_pascal_valprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_scheme_language
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_complaints
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_typeprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cp_valprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_f_valprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_nlmread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_serial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mdebugread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_user_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_frame_unwind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_frame_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gnu_v2_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_gnu_v3_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_hpacc_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cp_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cp_support
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cp_namespace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_inflow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cli_dump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cli_logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cli_interp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mi_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mi_cmds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mi_cmd_env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mi_interp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_mi_main
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_interp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_layout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_tui_win
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|initialize_all_files
parameter_list|(
name|void
parameter_list|)
block|{
name|_initialize_gdbtypes
argument_list|()
expr_stmt|;
name|_initialize_rs6000_tdep
argument_list|()
expr_stmt|;
name|_initialize_ppcfbsd_tdep
argument_list|()
expr_stmt|;
name|_initialize_corelow
argument_list|()
expr_stmt|;
name|_initialize_solib
argument_list|()
expr_stmt|;
name|_initialize_svr4_solib
argument_list|()
expr_stmt|;
name|_initialize_ser_hardwire
argument_list|()
expr_stmt|;
name|_initialize_ser_pipe
argument_list|()
expr_stmt|;
name|_initialize_ser_tcp
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|CROSS_DEBUGGER
name|_initialize_fbsd_proc
argument_list|()
expr_stmt|;
name|_initialize_gcore
argument_list|()
expr_stmt|;
name|_initialize_kernel_u_addr
argument_list|()
expr_stmt|;
name|_initialize_infptrace
argument_list|()
expr_stmt|;
name|_initialize_inftarg
argument_list|()
expr_stmt|;
name|_initialize_ppcfbsd_nat
argument_list|()
expr_stmt|;
name|_initialize_thread_db
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|_initialize_remote
argument_list|()
expr_stmt|;
name|_initialize_dcache
argument_list|()
expr_stmt|;
name|_initialize_sr_support
argument_list|()
expr_stmt|;
name|_initialize_tracepoint
argument_list|()
expr_stmt|;
name|_initialize_ax_gdb
argument_list|()
expr_stmt|;
name|_initialize_annotate
argument_list|()
expr_stmt|;
name|_initialize_auxv
argument_list|()
expr_stmt|;
name|_initialize_breakpoint
argument_list|()
expr_stmt|;
name|_initialize_regcache
argument_list|()
expr_stmt|;
name|_initialize_charset
argument_list|()
expr_stmt|;
name|_initialize_dummy_frame
argument_list|()
expr_stmt|;
name|_initialize_source
argument_list|()
expr_stmt|;
name|_initialize_values
argument_list|()
expr_stmt|;
name|_initialize_valops
argument_list|()
expr_stmt|;
name|_initialize_valarith
argument_list|()
expr_stmt|;
name|_initialize_valprint
argument_list|()
expr_stmt|;
name|_initialize_printcmd
argument_list|()
expr_stmt|;
name|_initialize_symtab
argument_list|()
expr_stmt|;
name|_initialize_symfile
argument_list|()
expr_stmt|;
name|_initialize_symmisc
argument_list|()
expr_stmt|;
name|_initialize_infcall
argument_list|()
expr_stmt|;
name|_initialize_infcmd
argument_list|()
expr_stmt|;
name|_initialize_infrun
argument_list|()
expr_stmt|;
name|_initialize_stack
argument_list|()
expr_stmt|;
name|_initialize_thread
argument_list|()
expr_stmt|;
name|_initialize_interpreter
argument_list|()
expr_stmt|;
name|_initialize_macrocmd
argument_list|()
expr_stmt|;
name|_initialize_gdbarch
argument_list|()
expr_stmt|;
name|_initialize_gdbarch_utils
argument_list|()
expr_stmt|;
name|_initialize_gdb_osabi
argument_list|()
expr_stmt|;
name|_initialize_copying
argument_list|()
expr_stmt|;
name|_initialize_mem
argument_list|()
expr_stmt|;
name|_initialize_parse
argument_list|()
expr_stmt|;
name|_initialize_language
argument_list|()
expr_stmt|;
name|_initialize_frame_reg
argument_list|()
expr_stmt|;
name|_initialize_signals
argument_list|()
expr_stmt|;
name|_initialize_kod
argument_list|()
expr_stmt|;
name|_initialize_gdb_events
argument_list|()
expr_stmt|;
name|_initialize_exec
argument_list|()
expr_stmt|;
name|_initialize_maint_cmds
argument_list|()
expr_stmt|;
name|_initialize_demangler
argument_list|()
expr_stmt|;
name|_initialize_dbxread
argument_list|()
expr_stmt|;
name|_initialize_coffread
argument_list|()
expr_stmt|;
name|_initialize_elfread
argument_list|()
expr_stmt|;
name|_initialize_mipsread
argument_list|()
expr_stmt|;
name|_initialize_stabsread
argument_list|()
expr_stmt|;
name|_initialize_core
argument_list|()
expr_stmt|;
name|_initialize_dwarf2_frame
argument_list|()
expr_stmt|;
name|_initialize_c_language
argument_list|()
expr_stmt|;
name|_initialize_f_language
argument_list|()
expr_stmt|;
name|_initialize_objc_language
argument_list|()
expr_stmt|;
name|_initialize_ui_out
argument_list|()
expr_stmt|;
name|_initialize_cli_out
argument_list|()
expr_stmt|;
name|_initialize_varobj
argument_list|()
expr_stmt|;
name|_initialize_java_language
argument_list|()
expr_stmt|;
name|_initialize_m2_language
argument_list|()
expr_stmt|;
name|_initialize_pascal_language
argument_list|()
expr_stmt|;
name|_initialize_pascal_valprint
argument_list|()
expr_stmt|;
name|_initialize_scheme_language
argument_list|()
expr_stmt|;
name|_initialize_complaints
argument_list|()
expr_stmt|;
name|_initialize_typeprint
argument_list|()
expr_stmt|;
name|_initialize_cp_valprint
argument_list|()
expr_stmt|;
name|_initialize_f_valprint
argument_list|()
expr_stmt|;
name|_initialize_nlmread
argument_list|()
expr_stmt|;
name|_initialize_serial
argument_list|()
expr_stmt|;
name|_initialize_mdebugread
argument_list|()
expr_stmt|;
name|_initialize_user_regs
argument_list|()
expr_stmt|;
name|_initialize_frame
argument_list|()
expr_stmt|;
name|_initialize_frame_unwind
argument_list|()
expr_stmt|;
name|_initialize_frame_base
argument_list|()
expr_stmt|;
name|_initialize_gnu_v2_abi
argument_list|()
expr_stmt|;
name|_initialize_gnu_v3_abi
argument_list|()
expr_stmt|;
name|_initialize_hpacc_abi
argument_list|()
expr_stmt|;
name|_initialize_cp_abi
argument_list|()
expr_stmt|;
name|_initialize_cp_support
argument_list|()
expr_stmt|;
name|_initialize_cp_namespace
argument_list|()
expr_stmt|;
name|_initialize_reggroup
argument_list|()
expr_stmt|;
name|_initialize_inflow
argument_list|()
expr_stmt|;
name|_initialize_cli_dump
argument_list|()
expr_stmt|;
name|_initialize_cli_logging
argument_list|()
expr_stmt|;
name|_initialize_cli_interp
argument_list|()
expr_stmt|;
name|_initialize_mi_out
argument_list|()
expr_stmt|;
name|_initialize_mi_cmds
argument_list|()
expr_stmt|;
name|_initialize_mi_cmd_env
argument_list|()
expr_stmt|;
name|_initialize_mi_interp
argument_list|()
expr_stmt|;
name|_initialize_mi_main
argument_list|()
expr_stmt|;
name|_initialize_tui_hooks
argument_list|()
expr_stmt|;
name|_initialize_tui_interp
argument_list|()
expr_stmt|;
name|_initialize_tui_layout
argument_list|()
expr_stmt|;
name|_initialize_tui_out
argument_list|()
expr_stmt|;
name|_initialize_tui_regs
argument_list|()
expr_stmt|;
name|_initialize_tui_stack
argument_list|()
expr_stmt|;
name|_initialize_tui_win
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

