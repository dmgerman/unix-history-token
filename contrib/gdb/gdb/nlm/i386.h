begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register values.  All of these values *MUST* agree with tm.h */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|4
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|8
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|5
end_define

begin_comment
comment|/* Virtual frame pointer */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|16
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * 4)
end_define

begin_comment
comment|/* Total size of registers array */
end_comment

begin_define
define|#
directive|define
name|ExceptionPC
value|ExceptionEIP
end_define

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|1
end_define

begin_comment
comment|/* int 3 leaves PC pointing after insn */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0xcc}
end_define

begin_define
define|#
directive|define
name|BREAKPOINT_SIZE
value|(sizeof breakpoint_insn)
end_define

begin_define
define|#
directive|define
name|StackFrame
value|T_TSS_StackFrame
end_define

end_unit

