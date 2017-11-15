begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 - 2010, Intel Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Original Module Name: ConsoleControl.h  * Abstract: Abstraction of a Text mode or GOP/UGA screen  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_CONS_CTL_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_CONS_CTL_H
end_define

begin_define
define|#
directive|define
name|EFI_CONSOLE_CONTROL_PROTOCOL_GUID
define|\
value|{ 0xf42f7782, 0x12e, 0x4c12, {0x99, 0x56, 0x49, 0xf9, 0x43, 0x4, 0xf7, 0x21} }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_CONSOLE_CONTROL_PROTOCOL
name|EFI_CONSOLE_CONTROL_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiConsoleControlScreenText
block|,
name|EfiConsoleControlScreenGraphics
block|,
name|EfiConsoleControlScreenMaxValue
block|}
name|EFI_CONSOLE_CONTROL_SCREEN_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONSOLE_CONTROL_PROTOCOL_GET_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_CONSOLE_CONTROL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_CONSOLE_CONTROL_SCREEN_MODE
modifier|*
name|Mode
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|GopUgaExists
parameter_list|,
name|OPTIONAL
name|OUT
name|BOOLEAN
modifier|*
name|StdInLocked
name|OPTIONAL
parameter_list|)
comment|/*++    Routine Description:     Return the current video mode information. Also returns info about existence     of Graphics Output devices or UGA Draw devices in system, and if the Std In     device is locked. All the arguments are optional and only returned if a non     NULL pointer is passed in.    Arguments:     This         - Protocol instance pointer.     Mode         - Are we in text of grahics mode.     GopUgaExists - TRUE if Console Spliter has found a GOP or UGA device     StdInLocked  - TRUE if StdIn device is keyboard locked    Returns:     EFI_SUCCESS     - Mode information returned.  --*/
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONSOLE_CONTROL_PROTOCOL_SET_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_CONSOLE_CONTROL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_CONSOLE_CONTROL_SCREEN_MODE
name|Mode
parameter_list|)
comment|/*++    Routine Description:     Set the current mode to either text or graphics. Graphics is     for Quiet Boot.    Arguments:     This  - Protocol instance pointer.     Mode  - Mode to set the    Returns:     EFI_SUCCESS     - Mode information returned.  --*/
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONSOLE_CONTROL_PROTOCOL_LOCK_STD_IN
function_decl|)
parameter_list|(
name|IN
name|EFI_CONSOLE_CONTROL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|Password
parameter_list|)
comment|/*++    Routine Description:     Lock Std In devices until Password is typed.    Arguments:     This     - Protocol instance pointer.     Password - Password needed to unlock screen. NULL means unlock keyboard    Returns:     EFI_SUCCESS      - Mode information returned.     EFI_DEVICE_ERROR - Std In not locked  --*/
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_CONSOLE_CONTROL_PROTOCOL
block|{
name|EFI_CONSOLE_CONTROL_PROTOCOL_GET_MODE
name|GetMode
decl_stmt|;
name|EFI_CONSOLE_CONTROL_PROTOCOL_SET_MODE
name|SetMode
decl_stmt|;
name|EFI_CONSOLE_CONTROL_PROTOCOL_LOCK_STD_IN
name|LockStdIn
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiConsoleControlProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

