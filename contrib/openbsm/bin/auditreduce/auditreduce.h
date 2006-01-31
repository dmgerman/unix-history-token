begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Apple Computer, Inc.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.   * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.   * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.   *   * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/auditreduce/auditreduce.h#4 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUDITREDUCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_AUDITREDUCE_H_
end_define

begin_define
define|#
directive|define
name|OPT_a
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OPT_b
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OPT_c
value|0x00000004
end_define

begin_define
define|#
directive|define
name|OPT_d
value|(OPT_a | OPT_b)
end_define

begin_define
define|#
directive|define
name|OPT_e
value|0x00000010
end_define

begin_define
define|#
directive|define
name|OPT_f
value|0x00000020
end_define

begin_define
define|#
directive|define
name|OPT_g
value|0x00000040
end_define

begin_define
define|#
directive|define
name|OPT_j
value|0x00000080
end_define

begin_define
define|#
directive|define
name|OPT_m
value|0x00000100
end_define

begin_define
define|#
directive|define
name|OPT_of
value|0x00000200
end_define

begin_define
define|#
directive|define
name|OPT_om
value|0x00000400
end_define

begin_define
define|#
directive|define
name|OPT_op
value|0x00000800
end_define

begin_define
define|#
directive|define
name|OPT_ose
value|0x00001000
end_define

begin_define
define|#
directive|define
name|OPT_osh
value|0x00002000
end_define

begin_define
define|#
directive|define
name|OPT_oso
value|0x00004000
end_define

begin_define
define|#
directive|define
name|OPT_r
value|0x00008000
end_define

begin_define
define|#
directive|define
name|OPT_u
value|0x00010000
end_define

begin_define
define|#
directive|define
name|OPT_A
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FILEOBJ
value|"file"
end_define

begin_define
define|#
directive|define
name|MSGQIDOBJ
value|"msgqid"
end_define

begin_define
define|#
directive|define
name|PIDOBJ
value|"pid"
end_define

begin_define
define|#
directive|define
name|SEMIDOBJ
value|"semid"
end_define

begin_define
define|#
directive|define
name|SHMIDOBJ
value|"shmid"
end_define

begin_define
define|#
directive|define
name|SOCKOBJ
value|"sock"
end_define

begin_define
define|#
directive|define
name|SETOPT
parameter_list|(
name|optmask
parameter_list|,
name|bit
parameter_list|)
value|(optmask |= bit)
end_define

begin_define
define|#
directive|define
name|ISOPTSET
parameter_list|(
name|optmask
parameter_list|,
name|bit
parameter_list|)
value|(optmask& bit)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AUDITREDUCE_H_ */
end_comment

end_unit

