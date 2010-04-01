begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: wstate.h,v 1.4 1997/09/18 13:05:51 torek Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_WSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_WSTATE_H_
end_define

begin_comment
comment|/*  * Window state register bits  *  * There really are no bits per se, just the two fields WSTATE.NORMAL  * and WSTATE.OTHER.  The rest is up to software.  *  * We use WSTATE_NORMAL to represent user mode or kernel mode saves  * (whichever is currently in effect) and WSTATE_OTHER to represent  * user mode saves (only).  *  * Note that locore.s assumes this same bit layout (since the translation  * from "bits" to "{spill,fill}_N_{normal,other}" is done in hardware).  */
end_comment

begin_define
define|#
directive|define
name|WSTATE_NORMAL_MASK
value|1
end_define

begin_comment
comment|/* wstate normal minus transition */
end_comment

begin_define
define|#
directive|define
name|WSTATE_OTHER_SHIFT
value|3
end_define

begin_comment
comment|/* for wstate other / user */
end_comment

begin_define
define|#
directive|define
name|WSTATE_OTHER_MASK
comment|/* wstate other minus nested */
define|\
value|(WSTATE_NORMAL_MASK<< WSTATE_OTHER_SHIFT)
end_define

begin_define
define|#
directive|define
name|WSTATE_KERNEL
value|0
end_define

begin_comment
comment|/* normal kernel wstate */
end_comment

begin_define
define|#
directive|define
name|WSTATE_USER_64
value|0
end_define

begin_comment
comment|/* normal 64bit user wstate */
end_comment

begin_define
define|#
directive|define
name|WSTATE_USER_32
value|1
end_define

begin_comment
comment|/* normal 32bit user wstate */
end_comment

begin_define
define|#
directive|define
name|WSTATE_TRANSITION
value|2
end_define

begin_comment
comment|/* if set, force user window */
end_comment

begin_define
define|#
directive|define
name|WSTATE_NESTED
comment|/* if set, spill must not fault */
define|\
value|(WSTATE_TRANSITION<< WSTATE_OTHER_SHIFT)
end_define

begin_comment
comment|/* Values used by the PROM and (Open)Solaris */
end_comment

begin_define
define|#
directive|define
name|WSTATE_PROM_KMIX
value|7
end_define

begin_define
define|#
directive|define
name|WSTATE_PROM_MASK
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_WSTATE_H_ */
end_comment

end_unit

