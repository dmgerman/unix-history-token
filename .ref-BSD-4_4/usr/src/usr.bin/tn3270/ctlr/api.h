begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)api.h	8.1 (Berkeley) 6/6/93  */
end_comment

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
value|1234
end_define

begin_define
define|#
directive|define
name|GATE_KEYBOARD
value|5678
end_define

begin_define
define|#
directive|define
name|GATE_COPY
value|9101
end_define

begin_define
define|#
directive|define
name|GATE_OIAM
value|1121
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_comment
comment|/*  * In unix, we offer a service to allow the application to keep from  * having to poll us constantly.  */
end_comment

begin_define
define|#
directive|define
name|PS_OR_OIA_MODIFIED
value|0x99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

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
name|QUERY_SESSION_PARAMETERS
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
name|unsigned
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

begin_define
define|#
directive|define
name|ID_OPTION_BY_NAME
value|0x01
end_define

begin_comment
comment|/* By short (or long) name */
end_comment

begin_define
define|#
directive|define
name|ID_OPTION_ALL
value|0x00
end_define

begin_comment
comment|/* All (of specified type */
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
name|short
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
name|short
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
name|unsigned
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
name|short
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
name|short
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
name|short
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
name|short
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
name|short
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
value|'\377'
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
value|((unsigned int)(((unsigned long)(x))>>16))
end_define

begin_define
define|#
directive|define
name|FP_OFF
parameter_list|(
name|y
parameter_list|)
value|((unsigned int)(((unsigned long)(y))&0xFFFF))
end_define

begin_comment
comment|/*  * Undo the preceeding.  */
end_comment

begin_define
define|#
directive|define
name|SEG_OFF_BACK
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<<16)|(y))
end_define

begin_comment
comment|/*  * Now, it is somewhat of a pain, but we need to keep  * 8086 conventions about which of the "highlow"'s map  * into which of the "words".  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* Get ENDIAN from machine/endian.h */
end_comment

begin_comment
comment|/* Determine endian'ess (if necessary) */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|ns32000
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax) || defined(ns32000) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
operator|||
name|defined
argument_list|(
name|gould
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|MIPSEB
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun) || defined(tahoe) || defined(ibm032) || defined(pyr) || defined(gould) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(BYTE_ORDER)&& defined(BIG_ENDIAN)) */
end_comment

begin_struct
struct|struct
name|highlow
block|{
name|unsigned
name|char
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|al
decl_stmt|,
name|ah
decl_stmt|,
name|bl
decl_stmt|,
name|bh
decl_stmt|,
name|cl
decl_stmt|,
name|ch
decl_stmt|,
name|dl
decl_stmt|,
name|dh
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == LITTLE_ENDIAN */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|ah
operator|,
name|al
operator|,
name|bh
operator|,
name|bl
operator|,
name|ch
operator|,
name|cl
operator|,
name|dh
operator|,
name|dl
expr_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|words
block|{
name|unsigned
name|short
name|ax
decl_stmt|,
name|bx
decl_stmt|,
name|cx
decl_stmt|,
name|dx
decl_stmt|;
name|unsigned
name|short
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
name|unsigned
name|short
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

