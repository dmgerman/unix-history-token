begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc.     dbgRpcLib.h - header file for remote debugging via rpc */
end_comment

begin_comment
comment|/* modification history -------------------- 01b,04oct90,maf  added VX_BOOT_FILE_INQ. 01a,05jun90,llk  extracted from xdr_dbx.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCdbxRpcLibh
end_ifndef

begin_define
define|#
directive|define
name|INCdbxRpcLibh
value|1
end_define

begin_define
define|#
directive|define
name|PROCESS_START
value|50
end_define

begin_define
define|#
directive|define
name|PROCESS_WAIT
value|51
end_define

begin_define
define|#
directive|define
name|VX_STATE_INQ
value|60
end_define

begin_define
define|#
directive|define
name|VX_LOAD
value|61
end_define

begin_define
define|#
directive|define
name|VX_SYMBOL_INQ
value|62
end_define

begin_define
define|#
directive|define
name|VX_BREAK_ADD
value|63
end_define

begin_define
define|#
directive|define
name|VX_BREAK_DELETE
value|64
end_define

begin_define
define|#
directive|define
name|VX_FP_INQUIRE
value|65
end_define

begin_define
define|#
directive|define
name|VX_TASK_SUSPEND
value|66
end_define

begin_define
define|#
directive|define
name|VX_CALL_FUNC
value|67
end_define

begin_define
define|#
directive|define
name|VX_CONV_FROM_68881
value|68
end_define

begin_define
define|#
directive|define
name|VX_CONV_TO_68881
value|69
end_define

begin_define
define|#
directive|define
name|VX_BOOT_FILE_INQ
value|70
end_define

begin_define
define|#
directive|define
name|VX_SOURCE_STEP
value|71
end_define

begin_endif
endif|#
directive|endif
endif|INCdbxRpcLibh
end_endif

end_unit

