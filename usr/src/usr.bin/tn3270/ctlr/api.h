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

begin_comment
comment|/*  * The names which correspond to the above gate numbers.  */
end_comment

begin_define
define|#
directive|define
name|NAME_SESSMGR
value|"SESSMGR "
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
value|"COPY    "
end_define

begin_define
define|#
directive|define
name|NAME_OIAM
value|"OIAM    "
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

begin_escape
end_escape

begin_comment
comment|/*  * For each service, we define the assoicated parameter blocks.  */
end_comment

begin_comment
comment|/*  * Supervisor Services  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|gate_name
index|[
literal|8
index|]
decl_stmt|;
block|}
name|NameResolveParms
typedef|;
end_typedef

begin_comment
comment|/*  * Session Information Services  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|short_name
decl_stmt|,
name|type
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|,
name|long_name
index|[
literal|8
index|]
decl_stmt|;
block|}
name|NameArrayElement
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|length
decl_stmt|,
name|number_matching_session
decl_stmt|;
name|NameArrayElement
name|name_array_element
decl_stmt|;
comment|/* Variable number */
block|}
name|NameArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|option_code
decl_stmt|,
name|data_code
decl_stmt|;
name|NameArray
name|far
modifier|*
name|name_array
decl_stmt|;
name|char
name|long_name
index|[
literal|8
index|]
decl_stmt|;
block|}
name|QuerySessionIdParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|,
name|session_type
decl_stmt|,
name|session_characteristics
decl_stmt|,
name|rows
decl_stmt|,
name|columns
decl_stmt|;
name|char
name|far
modifier|*
name|presentation_space
decl_stmt|;
block|}
name|QuerySessionParmetersParms
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TYPE_WSCTL
value|0x01
end_define

begin_comment
comment|/* Work Station Control */
end_comment

begin_define
define|#
directive|define
name|TYPE_DFT
value|0x02
end_define

begin_comment
comment|/* DFT Host Session */
end_comment

begin_define
define|#
directive|define
name|TYPE_CUT
value|0x03
end_define

begin_comment
comment|/* CUT Host Session */
end_comment

begin_define
define|#
directive|define
name|TYPE_NOTEPAD
value|0x04
end_define

begin_comment
comment|/* Notepad Session */
end_comment

begin_define
define|#
directive|define
name|TYPE_PC
value|0x05
end_define

begin_comment
comment|/* Personal Computer Session */
end_comment

begin_define
define|#
directive|define
name|CHARACTERISTIC_EAB
value|0x80
end_define

begin_comment
comment|/* Extended Attribute Buffer */
end_comment

begin_define
define|#
directive|define
name|CHARACTERISTIC_PSS
value|0x40
end_define

begin_comment
comment|/* Program Symbols Supported */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|cursor_type
decl_stmt|,
name|row_address
decl_stmt|,
comment|/* from 0 */
name|column_address
decl_stmt|;
comment|/* from 0 */
block|}
name|QuerySessionCursorParms
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CURSOR_INHIBITED_AUTOSCROLL
value|0x10
end_define

begin_define
define|#
directive|define
name|CURSOR_INHIBITED
value|0x04
end_define

begin_define
define|#
directive|define
name|CURSOR_BLINKING
value|0x02
end_define

begin_define
define|#
directive|define
name|CURSOR_BOX
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|int
name|event_queue_id
decl_stmt|,
name|input_queue_id
decl_stmt|;
name|char
name|intercept_options
decl_stmt|,
name|first_connection_identifier
decl_stmt|;
block|}
name|ConnectToKeyboardParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|int
name|connector_task_id
decl_stmt|;
block|}
name|DisconnectFromKeyboardParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|scancode
decl_stmt|,
name|shift_state
decl_stmt|;
block|}
name|KeystrokeEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|length
decl_stmt|;
comment|/* Length (in bytes) of list */
name|KeystrokeEntry
name|keystrokes
decl_stmt|;
comment|/* Variable size */
block|}
name|KeystrokeList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|int
name|connectors_task_id
decl_stmt|;
name|char
name|options
decl_stmt|,
name|number_of_keys_sent
decl_stmt|;
union|union
block|{
name|KeystrokeEntry
name|keystroke_entry
decl_stmt|;
name|KeystrokeList
name|far
modifier|*
name|keystroke_list
decl_stmt|;
block|}
name|keystroke_specifier
union|;
block|}
name|WriteKeystrokeParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|int
name|connectors_task_id
decl_stmt|;
block|}
name|DisableInputParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DisableInputParms
name|EnableInputParms
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|char
name|far
modifier|*
name|buffer
decl_stmt|;
name|char
name|characteristics
decl_stmt|,
name|session_type
decl_stmt|;
name|int
name|begin
decl_stmt|;
comment|/* Offset within buffer */
block|}
name|BufferDescriptor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|;
name|BufferDescriptor
name|source
decl_stmt|;
name|int
name|source_end
decl_stmt|;
comment|/* Offset within source buffer */
name|BufferDescriptor
name|target
decl_stmt|;
name|char
name|copy_mode
decl_stmt|,
name|reserved
decl_stmt|;
block|}
name|CopyStringParms
typedef|;
end_typedef

begin_define
define|#
directive|define
name|COPY_MODE_7_COLOR
value|0x80
end_define

begin_comment
comment|/* Else 4 color mode */
end_comment

begin_define
define|#
directive|define
name|COPY_MODE_FIELD_ATTRIBUTES
value|0x40
end_define

begin_comment
comment|/* Else don't copy attributes */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|rc
decl_stmt|,
name|function_id
decl_stmt|,
name|session_id
decl_stmt|,
name|reserved
decl_stmt|;
name|char
name|far
modifier|*
name|oia_buffer
decl_stmt|;
name|char
name|oia_group_number
decl_stmt|;
block|}
name|ReadOiaGroupParms
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OIA_ALL_GROUPS
value|0xFF
end_define

begin_define
define|#
directive|define
name|OIA_ONLINE_OWNERSHIP
value|0x01
end_define

begin_define
define|#
directive|define
name|OIA_SETUP
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_TEST
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_SSCP_LU
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_LU_LU
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_UNOWNED
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_SUBSYSTEM_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|OIA_CHARACTER_SELECTION
value|0x02
end_define

begin_define
define|#
directive|define
name|OIA_EXTENDED_SELECT
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_APL
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_KANA
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_ALPHA
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_TEXT
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_SHIFT_STATE
value|0x03
end_define

begin_define
define|#
directive|define
name|OIA_NUMERIC
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_UPPER_SHIFT
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_PSS_GROUP_1
value|0x04
end_define

begin_define
define|#
directive|define
name|OIA_HIGHLIGHT_GROUP_1
value|0x05
end_define

begin_define
define|#
directive|define
name|OIA_COLOR_GROUP_1
value|0x06
end_define

begin_define
define|#
directive|define
name|OIA_SELECTABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_FIELD_INHERIT
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_INSERT
value|0x07
end_define

begin_define
define|#
directive|define
name|OIA_INSERT_MODE
value|0x80
end_define

begin_comment
comment|/* We define this to be a 'long' followed by a 'char' (5 bytes) */
end_comment

begin_define
define|#
directive|define
name|OIA_INPUT_INHIBITED
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_NON_RESETTABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OIA_SECURITY_KEY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|OIA_MACHINE_CHECK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|OIA_COMM_CHECK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|OIA_PROGRAM_CHECK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|OIA_RETRY
value|0x04000000
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_NOT_WORKING
value|0x02000000
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_VERY_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_BUSY
value|0x00800000
end_define

begin_define
define|#
directive|define
name|OIA_TERMINAL_WAIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|OIA_MINUS_SYMBOL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|OIA_MINUS_FUNCTION
value|0x00100000
end_define

begin_define
define|#
directive|define
name|OIA_TOO_MUCH_ENTERED
value|0x00080000
end_define

begin_define
define|#
directive|define
name|OIA_NOT_ENOUGH_ENTERED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|OIA_WRONG_NUMBER
value|0x00020000
end_define

begin_define
define|#
directive|define
name|OIA_NUMERIC_FIELD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|OIA_OP_UNAUTHORIZED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|OIA_OP_UNAUTHORIZED_MIN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|OIA_INVALID_DEAD_KEY_COMBO
value|0x00002000
end_define

begin_define
define|#
directive|define
name|OIA_WRONG_PLACE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|OIA_MESSAGE_PENDING
value|0x00000080
end_define

begin_define
define|#
directive|define
name|OIA_PARTITION_WAIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|OIA_SYSTEM_WAIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|OIA_HARDWARE_MISMATCH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|OIA_LOGICAL_TERM_NOT_CONF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|OIA_AUTOKEY_INHIBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_API_INHIBIT
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_PSS_GROUP_2
value|0x09
end_define

begin_define
define|#
directive|define
name|OIA_PS_SELECTED
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_PC_DISPLAY_DISABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_HIGHLIGHT_GROUP_2
value|0x0a
end_define

begin_define
define|#
directive|define
name|OIA_COLOR_GROUP_2
value|0x0b
end_define

begin_define
define|#
directive|define
name|OIA_SELECTED
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_COMMUNICATION_ERROR_REMINDER
value|0x0c
end_define

begin_define
define|#
directive|define
name|OIA_COMM_ERROR
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_RTM
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_PRINTER_STATUS
value|0x0d
end_define

begin_define
define|#
directive|define
name|OIA_PRINT_NOT_CUSTOM
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_PRINTER_MALFUNCTION
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_PRINTER_PRINTING
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_ASSIGN_PRINTER
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_WHAT_PRINTER
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_PRINTER_ASSIGNMENT
value|0x04
end_define

begin_define
define|#
directive|define
name|OIA_AUTOKEY_PLAY_RECORD_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_PLAY
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_RECORD
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_AUTOKEY_ABORT_PAUSE_STATUS
value|0x11
end_define

begin_define
define|#
directive|define
name|OIA_RECORDING_OVERFLOW
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_PAUSE
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_ENLARGE_STATE
value|0x12
end_define

begin_define
define|#
directive|define
name|OIA_WINDOW_IS_ENLARGED
value|0x80
end_define

end_unit

