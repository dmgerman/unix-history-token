begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************/
end_comment

begin_expr_stmt
name|Copyright
literal|1990
operator|,
literal|1992
name|Free
name|Software
name|Foundation
operator|,
name|Inc
operator|.
name|This
name|code
name|was
name|donated
name|by
name|Intel
name|Corp
operator|.
name|Intel
name|hereby
name|grants
name|you
name|permission
name|to
name|copy
operator|,
name|modify
operator|,
name|and
name|distribute
name|this
name|software
name|and
name|its
name|documentation
operator|.
name|Intel
name|grants
name|this
name|permission
name|provided
name|that
name|the
name|above
name|copyright
name|notice
name|appears
name|in
name|all
name|copies
name|and
name|that
name|both
name|the
name|copyright
name|notice
name|and
name|this
name|permission
name|notice
name|appear
name|in
name|supporting
name|documentation
operator|.
name|In
name|addition
operator|,
name|Intel
name|grants
name|this
name|permission
name|provided
name|that
name|you
name|prominently
name|mark
name|as
name|not
name|part
name|of
name|the
name|original
name|any
name|modifications
name|made
name|to
name|this
name|software
name|or
name|documentation
operator|,
name|and
name|that
name|the
name|name
name|of
name|Intel
name|Corporation
name|not
name|be
name|used
name|in
name|advertising
name|or
name|publicity
name|pertaining
name|to
name|distribution
name|of
name|the
name|software
name|or
name|the
name|documentation
name|without
name|specific
operator|,
name|written
name|prior
name|permission
operator|.
name|Intel
name|Corporation
name|does
name|not
name|warrant
operator|,
name|guarantee
name|or
name|make
name|any
name|representations
name|regarding
name|the
name|use
name|of
operator|,
name|or
name|the
name|results
name|of
name|the
name|use
name|of
operator|,
name|the
name|software
name|and
name|documentation
name|in
name|terms
name|of
name|correctness
operator|,
name|accuracy
operator|,
name|reliability
operator|,
name|currentness
operator|,
name|or
name|otherwise
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|and
name|you
name|rely
name|on
name|the
name|software
decl_stmt|,
name|documentation
name|and
name|results
name|solely
name|at
name|your
name|own
name|risk
operator|.
modifier|*
decl|/
end_decl_stmt

begin_comment
comment|/******************************************************************/
end_comment

begin_comment
comment|/******************************************************************  *  *   REASONS WHY NINDY CAN STOP EXECUTING AN APPLICATION PROGRAM  *  * When NINDY stops executing an application program that was running  * under remote host ("gdb") control, it signals the host by sending  * a single ^P.  The host can then query as to the reason for the halt.  * NINDY responds with two bytes of information.  *  * The first byte is a boolean flag that indicates whether or not  * the application has exited.  *  * If the flag is true, the second byte contains the exit code.  *  * If the flag is false, the second byte contains a "reason for  * stopping" code.  This file defines the possible values of that  * code.  *  * There are three categories of reasons why the halt may have occurred:  * faults, traces, and software interactions.  The first two categories  * are processor-dependent; the values of these codes are tightly coupled  * to the hardware and should not be changed without first examining  * src/nindy/common/fault.c.  The software interactions involve  * communication between NINDY and the host debugger;  their codes are  * arbitrary.  *  ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|FAULT_PARALLEL
value|0x00
end_define

begin_define
define|#
directive|define
name|FAULT_UNKNOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|FAULT_OPERATION
value|0x02
end_define

begin_define
define|#
directive|define
name|FAULT_ARITH
value|0x03
end_define

begin_define
define|#
directive|define
name|FAULT_FP
value|0x04
end_define

begin_define
define|#
directive|define
name|FAULT_CONSTR
value|0x05
end_define

begin_define
define|#
directive|define
name|FAULT_VM
value|0x06
end_define

begin_define
define|#
directive|define
name|FAULT_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|FAULT_MACHINE
value|0x08
end_define

begin_define
define|#
directive|define
name|FAULT_STRUCT
value|0x09
end_define

begin_define
define|#
directive|define
name|FAULT_TYPE
value|0x0a
end_define

begin_comment
comment|/* 0x0b reserved */
end_comment

begin_define
define|#
directive|define
name|FAULT_PROCESS
value|0x0c
end_define

begin_define
define|#
directive|define
name|FAULT_DESC
value|0x0d
end_define

begin_define
define|#
directive|define
name|FAULT_EVENT
value|0x0e
end_define

begin_comment
comment|/* 0x0f reserved */
end_comment

begin_define
define|#
directive|define
name|LAST_FAULT
value|0x0f
end_define

begin_define
define|#
directive|define
name|TRACE_STEP
value|0x10
end_define

begin_define
define|#
directive|define
name|TRACE_BRANCH
value|0x11
end_define

begin_define
define|#
directive|define
name|TRACE_CALL
value|0x12
end_define

begin_define
define|#
directive|define
name|TRACE_RET
value|0x13
end_define

begin_define
define|#
directive|define
name|TRACE_PRERET
value|0x14
end_define

begin_define
define|#
directive|define
name|TRACE_SVC
value|0x15
end_define

begin_define
define|#
directive|define
name|TRACE_BKPT
value|0x16
end_define

begin_define
define|#
directive|define
name|STOP_SRQ
value|0xfe
end_define

begin_comment
comment|/* Application program has service request to make of host */
end_comment

begin_define
define|#
directive|define
name|STOP_GDB_BPT
value|0xff
end_define

begin_comment
comment|/* Application program has reached breakpoint (fmark) set by host */
end_comment

end_unit

