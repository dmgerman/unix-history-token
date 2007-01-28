begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Mathew Kanner  * Copyright (c) 1999 Seigo Tanimura  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Include file for the midi sequence driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SEQUENCER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SEQUENCER_H_
end_define

begin_define
define|#
directive|define
name|NSEQ_MAX
value|16
end_define

begin_comment
comment|/*  * many variables should be reduced to a range. Here define a macro  */
end_comment

begin_define
define|#
directive|define
name|RANGE
parameter_list|(
name|var
parameter_list|,
name|low
parameter_list|,
name|high
parameter_list|)
value|(var) = \ ((var)<(low)?(low) : (var)>(high)?(high) : (var))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|seq_timer
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_midi_seq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|seq_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SEQ_DEBUG
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|do {				\ 		if (seq_debug>= y) {	\ 			(x);		\ 		}			\ 	} while(0)
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_midi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|SYNTHPROP_MIDI
value|1
end_define

begin_define
define|#
directive|define
name|SYNTHPROP_SYNTH
value|2
end_define

begin_define
define|#
directive|define
name|SYNTHPROP_RX
value|4
end_define

begin_define
define|#
directive|define
name|SYNTHPROP_TX
value|8
end_define

begin_struct
struct|struct
name|_midi_cmdtab
block|{
name|int
name|cmd
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_midi_cmdtab
name|midi_cmdtab
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_seqevent
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_seqioctl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_timer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_seqcv
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_seqccmn
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|midi_cmdname
parameter_list|(
name|int
name|cmd
parameter_list|,
name|midi_cmdtab
modifier|*
name|tab
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|MORE
block|,
name|TIMERARMED
block|,
name|QUEUEFULL
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

