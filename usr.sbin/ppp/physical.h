begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Eivind Eklund<eivind@yes.no>  *    for Yes Interactive  *  * Copyright (C) 1998, Yes Interactive.  All rights reserved.  *  * Redistribution and use in any form is permitted.  Redistribution in  * source form should include the above copyright and this set of  * conditions, because large sections american law seems to have been  * created by a bunch of jerks on drugs that are now illegal, forcing  * me to include this copyright-stuff instead of placing this in the  * public domain.  The name of of 'Yes Interactive' or 'Eivind Eklund'  * may not be used to endorse or promote products derived from this  * software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|physical
block|{
name|struct
name|link
name|link
decl_stmt|;
name|struct
name|descriptor
name|desc
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* What sort of PHYS_* link are we ? */
name|struct
name|async
name|async
decl_stmt|;
comment|/* Our async state */
name|struct
name|hdlc
name|hdlc
decl_stmt|;
comment|/* Our hdlc state */
name|int
name|fd
decl_stmt|;
comment|/* File descriptor for this device */
name|int
name|mbits
decl_stmt|;
comment|/* Current DCD status */
name|unsigned
name|isatty
range|:
literal|1
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|out
decl_stmt|;
comment|/* mbuf that suffered a short write */
name|int
name|connect_count
decl_stmt|;
name|struct
name|datalink
modifier|*
name|dl
decl_stmt|;
comment|/* my owner */
struct|struct
block|{
name|char
name|full
index|[
literal|40
index|]
decl_stmt|;
name|char
modifier|*
name|base
decl_stmt|;
block|}
name|name
struct|;
name|unsigned
name|Utmp
range|:
literal|1
decl_stmt|;
comment|/* Are we in utmp ? */
name|pid_t
name|session_owner
decl_stmt|;
comment|/* HUP this when closing the link */
comment|/* XXX-ML Most of the below is device specific, and probably do not       belong in the generic physical struct. It comes from modem.c. */
struct|struct
block|{
name|unsigned
name|rts_cts
range|:
literal|1
decl_stmt|;
comment|/* Is rts/cts enabled? */
name|unsigned
name|parity
decl_stmt|;
comment|/* What parity is enabled? (TTY flags) */
name|unsigned
name|speed
decl_stmt|;
comment|/* Modem speed */
name|char
name|devlist
index|[
name|LINE_LEN
index|]
decl_stmt|;
comment|/* Comma-separated list of devices */
block|}
name|cfg
struct|;
name|struct
name|termios
name|ios
decl_stmt|;
comment|/* To be able to reset from raw mode */
name|struct
name|pppTimer
name|Timer
decl_stmt|;
comment|/* CD checks */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|field2phys
parameter_list|(
name|fp
parameter_list|,
name|name
parameter_list|)
define|\
value|((struct physical *)((char *)fp - (int)(&((struct physical *)0)->name)))
end_define

begin_define
define|#
directive|define
name|link2physical
parameter_list|(
name|l
parameter_list|)
define|\
value|((l)->type == PHYSICAL_LINK ? field2phys(l, link) : NULL)
end_define

begin_define
define|#
directive|define
name|descriptor2physical
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == PHYSICAL_DESCRIPTOR ? field2phys(d, desc) : NULL)
end_define

begin_function_decl
specifier|extern
name|int
name|physical_GetFD
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_IsSync
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|physical_GetDevice
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|physical_SetDeviceList
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_SetSpeed
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX-ML I'm not certain this is the right way to handle this, but we  * can solve that later.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|physical_SetSync
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Can this be set?  (Might not be a relevant attribute for this  * device, for instance)  */
end_comment

begin_function_decl
specifier|extern
name|int
name|physical_SetRtsCts
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|physical_Read
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|physical_Write
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_UpdateSet
parameter_list|(
name|struct
name|descriptor
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_IsSet
parameter_list|(
name|struct
name|descriptor
modifier|*
parameter_list|,
specifier|const
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|physical_Login
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|physical_Logout
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_RemoveFromSet
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|physical_SetMode
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|physical_DeleteQueue
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

