begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)oia.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * This file describes the Operator Information Area in the 3270.  *  * Our OIA looks like that used by the 3270 PC and PC 3270 products.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_OIA
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|online_ownership
decl_stmt|,
name|character_selection
decl_stmt|,
name|shift_state
decl_stmt|,
name|pss_group_1
decl_stmt|,
name|highlight_group_1
decl_stmt|,
name|color_group_1
decl_stmt|,
name|insert
decl_stmt|,
name|input_inhibited
index|[
literal|5
index|]
decl_stmt|,
name|pss_group_2
decl_stmt|,
name|highlight_group_2
decl_stmt|,
name|color_group_2
decl_stmt|,
name|comm_error_reminder
decl_stmt|,
name|printer_status
decl_stmt|,
name|reserved_group_14
decl_stmt|,
name|reserved_group_15
decl_stmt|,
name|autokey_play_record_status
decl_stmt|,
name|autokey_abort_pause_status
decl_stmt|,
name|enlarge_state
decl_stmt|;
block|}
name|OIA
typedef|;
end_typedef

begin_comment
comment|/* Bits in online_ownership */
end_comment

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

begin_comment
comment|/* Bit in character_selection */
end_comment

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

begin_comment
comment|/* Bits in shift_state */
end_comment

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

begin_comment
comment|/* Bits in pss_group_1, highlight_group_1, and color_group_1 */
end_comment

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

begin_comment
comment|/* Bits in insert */
end_comment

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
name|OIA_NON_RESETTABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_SECURITY_KEY
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_MACHINE_CHECK
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_COMM_CHECK
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_PROGRAM_CHECK
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_RETRY
value|0x04
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_NOT_WORKING
value|0x02
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_VERY_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|OIA_DEVICE_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_TERMINAL_WAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_MINUS_SYMBOL
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_MINUS_FUNCTION
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_TOO_MUCH_ENTERED
value|0x08
end_define

begin_define
define|#
directive|define
name|OIA_NOT_ENOUGH_ENTERED
value|0x04
end_define

begin_define
define|#
directive|define
name|OIA_WRONG_NUMBER
value|0x02
end_define

begin_define
define|#
directive|define
name|OIA_NUMERIC_FIELD
value|0x01
end_define

begin_define
define|#
directive|define
name|OIA_OP_UNAUTHORIZED
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_OP_UNAUTHORIZED_MIN
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_INVALID_DEAD_KEY_COMBO
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_WRONG_PLACE
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_MESSAGE_PENDING
value|0x80
end_define

begin_define
define|#
directive|define
name|OIA_PARTITION_WAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|OIA_SYSTEM_WAIT
value|0x20
end_define

begin_define
define|#
directive|define
name|OIA_HARDWARE_MISMATCH
value|0x10
end_define

begin_define
define|#
directive|define
name|OIA_LOGICAL_TERM_NOT_CONF
value|0x08
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

begin_comment
comment|/* Bits in pss_group_2 */
end_comment

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

begin_comment
comment|/* Bits in highlight_group_2 and color_group_2 */
end_comment

begin_define
define|#
directive|define
name|OIA_SELECTED
value|0x80
end_define

begin_comment
comment|/* Bits in comm_error_reminder */
end_comment

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

begin_comment
comment|/* Bits in printer_status */
end_comment

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

begin_comment
comment|/* Bits in autokey_play_record_status */
end_comment

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

begin_comment
comment|/* Bits in autokey_abort_pause_status */
end_comment

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

begin_comment
comment|/* Bits in enlarge_state */
end_comment

begin_define
define|#
directive|define
name|OIA_WINDOW_IS_ENLARGED
value|0x80
end_define

begin_comment
comment|/* Define functions to set and read the oia */
end_comment

begin_define
define|#
directive|define
name|SetOiaOnlineA
parameter_list|(
name|oia
parameter_list|)
value|SetOiaMyJob((oia))
end_define

begin_comment
comment|/* Side-effect */
end_comment

begin_define
define|#
directive|define
name|ResetOiaOnlineA
parameter_list|(
name|oia
parameter_list|)
end_define

begin_comment
unit|\
comment|/* Nothing defined for this */
end_comment

begin_define
define|#
directive|define
name|IsOiaReady3274
parameter_list|(
name|oia
parameter_list|)
value|((oia)->online_ownership&OIA_SUBSYSTEM_READY)
end_define

begin_define
define|#
directive|define
name|ResetOiaReady3274
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership&= ~OIA_SUBSYSTEM_READY
end_define

begin_define
define|#
directive|define
name|SetOiaReady3274
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership |= OIA_SUBSYSTEM_READY
end_define

begin_define
define|#
directive|define
name|IsOiaMyJob
parameter_list|(
name|oia
parameter_list|)
value|((oia)->online_ownership&OIA_LU_LU)
end_define

begin_define
define|#
directive|define
name|ResetOiaMyJob
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership&= ~OIA_LU_LU
end_define

begin_define
define|#
directive|define
name|SetOiaMyJob
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership |= OIA_LU_LU
end_define

begin_define
define|#
directive|define
name|IsOiaInsert
parameter_list|(
name|oia
parameter_list|)
value|((oia)->online_ownership&OIA_INSERT_MODE)
end_define

begin_define
define|#
directive|define
name|ResetOiaInsert
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership&= ~OIA_INSERT_MODE
end_define

begin_define
define|#
directive|define
name|SetOiaInsert
parameter_list|(
name|oia
parameter_list|)
value|(oia)->online_ownership |= OIA_INSERT_MODE
end_define

begin_define
define|#
directive|define
name|IsOiaSystemLocked
parameter_list|(
name|oia
parameter_list|)
value|((oia)->input_inhibited[3]&OIA_SYSTEM_WAIT)
end_define

begin_define
define|#
directive|define
name|ResetOiaSystemLocked
parameter_list|(
name|oia
parameter_list|)
define|\
value|(oia)->input_inhibited[3]&= ~OIA_SYSTEM_WAIT
end_define

begin_define
define|#
directive|define
name|SetOiaSystemLocked
parameter_list|(
name|oia
parameter_list|)
value|(oia)->input_inhibited[3] |= OIA_SYSTEM_WAIT
end_define

begin_define
define|#
directive|define
name|IsOiaTWait
parameter_list|(
name|oia
parameter_list|)
value|((oia)->input_inhibited[1]&OIA_TERMINAL_WAIT)
end_define

begin_define
define|#
directive|define
name|ResetOiaTWait
parameter_list|(
name|oia
parameter_list|)
value|(oia)->input_inhibited[1]&= ~OIA_TERMINAL_WAIT
end_define

begin_define
define|#
directive|define
name|SetOiaTWait
parameter_list|(
name|oia
parameter_list|)
value|(oia)->input_inhibited[1] |= OIA_TERMINAL_WAIT
end_define

begin_define
define|#
directive|define
name|IsOiaApiInhibit
parameter_list|(
name|oia
parameter_list|)
value|((oia)->input_inhibited[4]&   OIA_API_INHIBIT)
end_define

begin_define
define|#
directive|define
name|ResetOiaApiInhibit
parameter_list|(
name|oia
parameter_list|)
value|((oia)->input_inhibited[4]&= ~OIA_API_INHIBIT)
end_define

begin_define
define|#
directive|define
name|SetOiaApiInhibit
parameter_list|(
name|oia
parameter_list|)
value|((oia)->input_inhibited[4] |=  OIA_API_INHIBIT)
end_define

begin_comment
comment|/* A macro to let the world know that someone has modified the OIA. */
end_comment

begin_define
define|#
directive|define
name|SetOiaModified
parameter_list|()
value|oia_modified = 1
end_define

begin_define
define|#
directive|define
name|SetPsModified
parameter_list|()
value|ps_modified = 1
end_define

end_unit

