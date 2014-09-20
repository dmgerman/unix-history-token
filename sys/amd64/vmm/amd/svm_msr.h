begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Neel Natu (neel@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVM_MSR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVM_MSR_H_
end_define

begin_struct_decl
struct_decl|struct
name|svm_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|svm_msr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svm_msr_guest_init
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svm_msr_guest_enter
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svm_msr_guest_exit
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|svm_wrmsr
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|u_int
name|num
parameter_list|,
name|uint64_t
name|val
parameter_list|,
name|bool
modifier|*
name|retu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|svm_rdmsr
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|u_int
name|num
parameter_list|,
name|uint64_t
modifier|*
name|result
parameter_list|,
name|bool
modifier|*
name|retu
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVM_MSR_H_ */
end_comment

end_unit

