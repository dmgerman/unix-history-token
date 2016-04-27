begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_iocplmem.h - separate memory pool for IOCPL related objects  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  *  * --------------------------------------------------------------------  * Notes on the implementation:  *  * Implements a thin layer over Windows Memory pools  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_IOCPLMEM_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_IOCPLMEM_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
specifier|extern
name|void
name|IOCPLPoolInit
parameter_list|(
name|size_t
name|initSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IOCPLPoolDone
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__fastcall
name|IOCPLPoolAlloc
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__fastcall
name|IOCPLPoolMemDup
parameter_list|(
specifier|const
name|void
modifier|*
name|psrc
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fastcall
name|IOCPLPoolFree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(NTP_IOCPLMEM_H)*/
end_comment

end_unit

