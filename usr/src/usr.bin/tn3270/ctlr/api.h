begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file contains header information used by the PC API routines.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|far
end_define

begin_comment
comment|/* For 'far *' checks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MSDOS) */
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
name|QuerySessionParametersParms
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
name|connectors_task_id
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

begin_define
define|#
directive|define
name|OPTION_SINGLE_KEYSTROKE
value|0x20
end_define

begin_define
define|#
directive|define
name|OPTION_MULTIPLE_KEYSTROKES
value|0x30
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

begin_comment
comment|/* If the user wants all groups, we return API_OIA_BYTES_ALL_GROUPS bytes */
end_comment

begin_define
define|#
directive|define
name|API_OIA_ALL_GROUPS
value|0xFF
end_define

begin_define
define|#
directive|define
name|API_OIA_BYTES_ALL_GROUPS
value|22
end_define

begin_comment
comment|/* 22 bytes of data */
end_comment

begin_comment
comment|/* API_OIA_INPUT_INHIBITED is special.  It returns more than on byte of data */
end_comment

begin_define
define|#
directive|define
name|API_OIA_INPUT_INHIBITED
value|8
end_define

begin_define
define|#
directive|define
name|API_OIA_LAST_LEGAL_GROUP
value|18
end_define

begin_comment
comment|/* Highest legal number */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FP_SEG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(FP_SEG) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(MSDOS) */
end_comment

begin_comment
comment|/*  * These definitions are here to provide the descriptions of  * some registers which are, normally, defined in<dos.h> on  * a dos system.  */
end_comment

begin_define
define|#
directive|define
name|FP_SEG
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|FP_OFF
parameter_list|(
name|y
parameter_list|)
value|(y)
end_define

begin_struct
struct|struct
name|highlow
block|{
name|char
name|ah
decl_stmt|,
name|al
decl_stmt|,
name|bh
decl_stmt|,
name|bl
decl_stmt|,
name|ch
decl_stmt|,
name|cl
decl_stmt|,
name|dh
decl_stmt|,
name|dl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|words
block|{
name|int
name|ax
decl_stmt|,
name|bx
decl_stmt|,
name|cx
decl_stmt|,
name|dx
decl_stmt|,
name|si
decl_stmt|,
name|di
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|REGS
block|{
name|struct
name|highlow
name|h
decl_stmt|;
name|struct
name|words
name|x
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|SREGS
block|{
name|int
name|cs
decl_stmt|,
name|ds
decl_stmt|,
name|es
decl_stmt|,
name|ss
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MSDOS) (else section) */
end_comment

end_unit

