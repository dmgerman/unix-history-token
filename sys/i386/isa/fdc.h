begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from:	@(#)fd.c	7.4 (Berkeley) 5/25/91  *	$Id:$  *  */
end_comment

begin_comment
comment|/***********************************************************************\ * Per controller structure.						* \***********************************************************************/
end_comment

begin_struct
struct|struct
name|fdc_data
block|{
name|int
name|fdcu
decl_stmt|;
comment|/* our unit number */
name|int
name|baseport
decl_stmt|;
name|int
name|dmachan
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|FDC_ATTACHED
value|0x01
define|#
directive|define
name|FDC_HASFTAPE
value|0x02
define|#
directive|define
name|FDC_TAPE_BUSY
value|0x04
name|struct
name|fd_data
modifier|*
name|fd
decl_stmt|;
name|int
name|fdu
decl_stmt|;
comment|/* the active drive	*/
name|struct
name|buf
name|head
decl_stmt|;
comment|/* Head of buf chain      */
name|struct
name|buf
name|rhead
decl_stmt|;
comment|/* Raw head of buf chain  */
name|int
name|state
decl_stmt|;
name|int
name|retry
decl_stmt|;
name|int
name|status
index|[
literal|7
index|]
decl_stmt|;
comment|/* copy of the registers */
block|}
struct|;
end_struct

begin_comment
comment|/***********************************************************************\ * Throughout this file the following conventions will be used:		* * fd is a pointer to the fd_data struct for the drive in question	* * fdc is a pointer to the fdc_data struct for the controller		* * fdu is the floppy drive unit number					* * fdcu is the floppy controller unit number				* * fdsu is the floppy drive unit number on that controller. (sub-unit)	* \***********************************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|fdu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdcu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdsu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fd_data
modifier|*
name|fd_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fdc_data
modifier|*
name|fdc_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FDUNIT
parameter_list|(
name|s
parameter_list|)
value|(((s)>>6)&03)
end_define

begin_define
define|#
directive|define
name|FDTYPE
parameter_list|(
name|s
parameter_list|)
value|((s)&077)
end_define

end_unit

