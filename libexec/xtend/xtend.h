begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1995 Eugene W. Stark  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Eugene W. Stark.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY EUGENE W. STARK (THE AUTHOR) ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Device capabilities  */
end_comment

begin_define
define|#
directive|define
name|ISLIGHT
value|1
end_define

begin_comment
comment|/* Is device a light? */
end_comment

begin_define
define|#
directive|define
name|CANQUERY
value|2
end_define

begin_comment
comment|/* Responds to status query */
end_comment

begin_comment
comment|/*  * Device status  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IDLE
block|,
name|SELECTED
block|,
name|DIMMING
block|,
name|BRIGHTENING
block|,
name|REQUESTED
block|,
name|HAILED
block|}
name|SELECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|devcap
decl_stmt|;
comment|/* device capabilities */
name|unsigned
name|int
name|changed
decl_stmt|;
comment|/* status changed since last checkpoint? */
name|time_t
name|lastchange
decl_stmt|;
comment|/* time status last changed */
name|SELECT
name|selected
decl_stmt|;
comment|/* select status of device */
name|unsigned
name|int
name|onoff
decl_stmt|;
comment|/* nonzero if on */
name|unsigned
name|int
name|brightness
decl_stmt|;
comment|/* value in range 0-15 */
block|}
name|STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|inuse
decl_stmt|;
comment|/* Is entry in use? */
name|FILE
modifier|*
name|user
decl_stmt|;
comment|/* Socket to notify user */
name|int
name|house
decl_stmt|;
comment|/* House code of device to monitor */
name|int
name|unit
decl_stmt|;
comment|/* Unit code of device to monitor */
block|}
name|MONENTRY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXMON
value|5
end_define

begin_comment
comment|/* Maximum number of monitor entries */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Log file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|User
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User connection */
end_comment

begin_decl_stmt
specifier|extern
name|STATUS
name|Status
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device status table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Status file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tw523
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tw523 controller */
end_comment

begin_decl_stmt
specifier|extern
name|MONENTRY
name|Monitor
index|[
name|MAXMON
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Monitor table */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|thedate
parameter_list|()
function_decl|;
end_function_decl

end_unit

