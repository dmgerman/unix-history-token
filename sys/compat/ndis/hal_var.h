begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HAL_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_HAL_VAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|NDIS_BUS_SPACE_IO
value|AMD64_BUS_SPACE_IO
end_define

begin_define
define|#
directive|define
name|NDIS_BUS_SPACE_MEM
value|AMD64_BUS_SPACE_MEM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NDIS_BUS_SPACE_IO
value|I386_BUS_SPACE_IO
end_define

begin_define
define|#
directive|define
name|NDIS_BUS_SPACE_MEM
value|I386_BUS_SPACE_MEM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|image_patch_table
name|hal_functbl
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|hal_libinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hal_libfini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__fastcall
specifier|extern
name|uint8_t
name|KfAcquireSpinLock
argument_list|(
name|REGARGS1
argument_list|(
name|kspin_lock
operator|*
name|lock
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__fastcall
name|void
name|KfReleaseSpinLock
argument_list|(
name|REGARGS2
argument_list|(
argument|kspin_lock *lock
argument_list|,
argument|uint8_t newirql
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__fastcall
specifier|extern
name|uint8_t
name|KfRaiseIrql
argument_list|(
name|REGARGS1
argument_list|(
argument|uint8_t irql
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__fastcall
specifier|extern
name|void
name|KfLowerIrql
argument_list|(
name|REGARGS1
argument_list|(
argument|uint8_t oldirql
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|KeGetCurrentIrql
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HAL_VAR_H_ */
end_comment

end_unit

