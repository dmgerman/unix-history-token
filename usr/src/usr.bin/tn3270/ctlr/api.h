begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file contains header information used by the PC API routines.  */
end_comment

begin_define
define|#
directive|define
name|API_INTERRUPT_NUMBER
value|0x7A
end_define

begin_comment
comment|/* API Interrupt Number */
end_comment

begin_comment
comment|/*  * Define the gate numbers.  These are returned via the Name Resolution  * service.  */
end_comment

begin_define
define|#
directive|define
name|GATE_SESSMGR
value|1
end_define

begin_define
define|#
directive|define
name|GATE_KEYBOARD
value|2
end_define

begin_define
define|#
directive|define
name|GATE_COPY
value|3
end_define

begin_define
define|#
directive|define
name|GATE_OIAM
value|4
end_define

begin_define
define|#
directive|define
name|NAME_SESSMGR
value|"SESSMGR"
end_define

begin_define
define|#
directive|define
name|NAME_KEYBOARD
value|"KEYBOARD"
end_define

begin_define
define|#
directive|define
name|NAME_COPY
value|"COPY"
end_define

begin_define
define|#
directive|define
name|NAME_OIAM
value|"OIAM"
end_define

begin_comment
comment|/*  * Name Resolution is specified in AH.  */
end_comment

begin_define
define|#
directive|define
name|NAME_RESOLUTION
value|0x81
end_define

begin_comment
comment|/*  * Codes specified in AL for various services.  */
end_comment

begin_define
define|#
directive|define
name|QUERY_SESSION_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|QUERY_SESSION_PARMS
value|0x02
end_define

begin_define
define|#
directive|define
name|QUERY_SESSION_CURSOR
value|0x0b
end_define

begin_define
define|#
directive|define
name|CONNECT_TO_KEYBOARD
value|0x01
end_define

begin_define
define|#
directive|define
name|DISCONNECT_FROM_KEYBOARD
value|0x02
end_define

begin_define
define|#
directive|define
name|WRITE_KEYSTROKE
value|0x04
end_define

begin_define
define|#
directive|define
name|DISABLE_INPUT
value|0x05
end_define

begin_define
define|#
directive|define
name|ENABLE_INPUT
value|0x06
end_define

begin_define
define|#
directive|define
name|COPY_STRING
value|0x01
end_define

begin_define
define|#
directive|define
name|READ_OIA_GROUP
value|0x02
end_define

end_unit

