begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU GPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_FBSD_H
end_define

begin_comment
comment|/* Type of the third argument to the `ptrace' system call.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|caddr_t
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Override child_pid_to_exec_file in 'inftarg.c'.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PID_TO_EXEC_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_FBSD_H */
end_comment

end_unit

